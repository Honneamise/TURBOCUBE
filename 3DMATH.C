#include "HEADERS.H"

/**********/
Vec3 Vec3Init(float x, float y, float z)
{
	Vec3 v=calloc(3,sizeof(float));
	v[0] = x;
	v[1] = y;
	v[2] = z;
	return v;
}

/**********/
void Vec3Copy(Vec3 src, Vec3 dst)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
}

/**********/
Mat4 Mat4Init()
{
	Mat4 m = calloc(16,sizeof(float));
	return m;
}

/**********/
Mat4 Mat4InitPerspective(float znear, float zfar, float fov, float ratio)
{
	float fovrad = 1.0f/(float)tan(fov * 0.5f / 180.0f * (float)M_PI);
	
	Mat4 m = Mat4Init();
	m[0]  = ratio*fovrad;
	m[5]  = fovrad;
	m[10] = zfar/(zfar-znear);
	m[11] = 1.0f;
	m[14] = (-zfar*znear)/(zfar-znear);
	return m;
}

/**********/
void Vec3xMat4(Vec3 in, Mat4 m, Vec3 out)
{
	float w = 0.0f;

	out[0] = in[0] * m[0] + in[1] * m[4] + in[2] * m[8] + m[12];
	out[1] = in[0] * m[1] + in[1] * m[5] + in[2] * m[9] + m[13];
	out[2] = in[0] * m[2] + in[1] * m[6] + in[2] * m[10] + m[14];
	w      = in[0] * m[3] + in[1] * m[7] + in[2] * m[11] + m[15];

	if(w!=0.0f)
	{
		out[0] /= w;
		out[1] /= w;
		out[2] /= w;
	}
}
