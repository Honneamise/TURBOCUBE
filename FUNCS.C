#include "HEADERS.H"

/**********/
void setupgraph(int *w, int *h)
{
	int gd = VGA;
	int gm = VGAHI;

	initgraph(&gd, &gm, "C:\\TC");

	*w=getmaxx()+1;
	*h=getmaxy()+1;
}

/**********/
void drawquad(Vec3 v0, Vec3 v1, Vec3 v2, Vec3 v3)
{
	line(v0[0],v0[1],v1[0],v1[1]);
	line(v1[0],v1[1],v2[0],v2[1]);
	line(v2[0],v2[1],v3[0],v3[1]);
	line(v3[0],v3[1],v0[0],v0[1]);
}