#include "HEADERS.H"

/**********/
void main()
{
	char str[256] = {0};
	int w,h = 0;

	float ratio = 0.0f;
	float angle = 0.0f;

	Vec3 v0 = Vec3Init( 0.0f, 0.0f, 0.0f);
	Vec3 v1 = Vec3Init( 0.0f, 1.0f, 0.0f);
	Vec3 v2 = Vec3Init( 1.0f, 1.0f, 0.0f);
	Vec3 v3 = Vec3Init( 1.0f, 0.0f, 0.0f);
	Vec3 v4 = Vec3Init( 0.0f, 0.0f, 1.0f);
	Vec3 v5 = Vec3Init( 0.0f, 1.0f, 1.0f);
	Vec3 v6 = Vec3Init( 1.0f, 1.0f, 1.0f);
	Vec3 v7 = Vec3Init( 1.0f, 0.0f, 1.0f);

	Vec3 t0 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t1 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t2 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t3 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t4 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t5 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t6 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 t7 = Vec3Init(0.0f,0.0f,0.0f);

	Vec3 vr0 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr1 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr2 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr3 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr4 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr5 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr6 = Vec3Init(0.0f,0.0f,0.0f);
	Vec3 vr7 = Vec3Init(0.0f,0.0f,0.0f);

	Mat4 proj = NULL;
	Mat4 matz = Mat4Init();
	Mat4 matx = Mat4Init();

	/**/
	setupgraph(&w,&h);
	sprintf(str,"w:%d h:%d",w,h);

	ratio = (float)h/(float)w;
	proj=Mat4InitPerspective(0.1f,1000.0f,90.0f,ratio);

	while(!kbhit())
	{
		setcolor(GREEN);
		angle += 0.1f;

		matz[0] = (float)cos(angle);
		matz[1] = (float)sin(angle);
		matz[4] = -(float)sin(angle);
		matz[5] = (float)cos(angle);
		matz[10] = 1.0f;
		matz[15] = 1.0f;

		matx[0] = 1.0f;
		matx[5] = (float)cos(angle * 0.5f);
		matx[6] = (float)sin(angle * 0.5f);
		matx[9] = -(float)sin(angle * 0.5f);
		matx[10] = (float)cos(angle * 0.5f);
		matx[15] = 1.0f;

		Vec3Copy(v0,t0);
		Vec3Copy(v1,t1);
		Vec3Copy(v2,t2);
		Vec3Copy(v3,t3);
		Vec3Copy(v4,t4);
		Vec3Copy(v5,t5);
		Vec3Copy(v6,t6);
		Vec3Copy(v7,t7);

		Vec3xMat4(t0,matz,vr0);
		Vec3xMat4(t1,matz,vr1);
		Vec3xMat4(t2,matz,vr2);
		Vec3xMat4(t3,matz,vr3);
		Vec3xMat4(t4,matz,vr4);
		Vec3xMat4(t5,matz,vr5);
		Vec3xMat4(t6,matz,vr6);
		Vec3xMat4(t7,matz,vr7);

		Vec3xMat4(vr0,matx,t0);
		Vec3xMat4(vr1,matx,t1);
		Vec3xMat4(vr2,matx,t2);
		Vec3xMat4(vr3,matx,t3);
		Vec3xMat4(vr4,matx,t4);
		Vec3xMat4(vr5,matx,t5);
		Vec3xMat4(vr6,matx,t6);
		Vec3xMat4(vr7,matx,t7);

		t0[2] += 3.0f;
		t1[2] += 3.0f;
		t2[2] += 3.0f;
		t3[2] += 3.0f;
		t4[2] += 3.0f;
		t5[2] += 3.0f;
		t6[2] += 3.0f;
		t7[2] += 3.0f;

		Vec3xMat4(t0,proj,vr0);
		Vec3xMat4(t1,proj,vr1);
		Vec3xMat4(t2,proj,vr2);
		Vec3xMat4(t3,proj,vr3);
		Vec3xMat4(t4,proj,vr4);
		Vec3xMat4(t5,proj,vr5);
		Vec3xMat4(t6,proj,vr6);
		Vec3xMat4(t7,proj,vr7);

		vr0[0] += 1.0f; vr0[1] += 1.0f;
		vr1[0] += 1.0f; vr1[1] += 1.0f;
		vr2[0] += 1.0f; vr2[1] += 1.0f;
		vr3[0] += 1.0f; vr3[1] += 1.0f;
		vr4[0] += 1.0f; vr4[1] += 1.0f;
		vr5[0] += 1.0f; vr5[1] += 1.0f;
		vr6[0] += 1.0f; vr6[1] += 1.0f;
		vr7[0] += 1.0f; vr7[1] += 1.0f;

		vr0[0] *= 0.5f * (float)w; vr0[1] *= 0.5f * (float)h;
		vr1[0] *= 0.5f * (float)w; vr1[1] *= 0.5f * (float)h;
		vr2[0] *= 0.5f * (float)w; vr2[1] *= 0.5f * (float)h;
		vr3[0] *= 0.5f * (float)w; vr3[1] *= 0.5f * (float)h;
		vr4[0] *= 0.5f * (float)w; vr4[1] *= 0.5f * (float)h;
		vr5[0] *= 0.5f * (float)w; vr5[1] *= 0.5f * (float)h;
		vr6[0] *= 0.5f * (float)w; vr6[1] *= 0.5f * (float)h;
		vr7[0] *= 0.5f * (float)w; vr7[1] *= 0.5f * (float)h;

		drawquad(vr0,vr1,vr2,vr3);/*front*/
		drawquad(vr4,vr5,vr6,vr7);/*back*/
		drawquad(vr0,vr1,vr5,vr4);/*left*/
		drawquad(vr3,vr2,vr6,vr7);/*right*/
		drawquad(vr1,vr5,vr6,vr2);/*top*/
		drawquad(vr0,vr4,vr7,vr3);/*bot*/

		outtext(str);

		delay(50);

		cleardevice();
	}

	closegraph();

	free(v0);
	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(v5);
	free(v6);
	free(v7);

	free(t0);
	free(t1);
	free(t2);
	free(t3);
	free(t4);
	free(t5);
	free(t6);
	free(t7);

	free(vr0);
	free(vr1);
	free(vr2);
	free(vr3);
	free(vr4);
	free(vr5);
	free(vr6);
	free(vr7);

	free(matz);
	free(matx);
	free(proj);

}