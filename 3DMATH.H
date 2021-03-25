typedef float *Vec3;
typedef float *Mat4;

Vec3 Vec3Init(float x, float y, float z);
void Vec3Copy(Vec3 src, Vec3 dst);

Mat4 Mat4Init();

Mat4 Mat4InitPerspective(float znear, float zfar, float fov, float ratio);

void Vec3xMat4(Vec3 in, Mat4 m, Vec3 out);