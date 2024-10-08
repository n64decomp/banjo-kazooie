#include <ultra64.h>
#include "core1/core1.h"

extern f32 gu_sqrtf(f32);

static void __guMtxF2L(float mf[4][4], Mtx *m)
{
    int	i, j;
    int	e1,e2;
    int	*ai,*af;


    ai=(int *) &m->m[0][0];
    af=(int *) &m->m[2][0];

    for (i=0; i<4; i++)
    for (j=0; j<2; j++) {
        e1=FTOFIX32(mf[i][j*2]);
        e2=FTOFIX32(mf[i][j*2+1]);
        *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff);
        *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
    }
}

static void _guMtxIdentF(float mf[4][4])
{
    int	i, j;

    for (i=0; i<4; i++)
    for (j=0; j<4; j++)
        if (i == j) mf[i][j] = 1.0;
        else mf[i][j] = 0.0;
}

void guScaleF(float mf[4][4], float x, float y, float z)
{
    _guMtxIdentF(mf);

    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;
    mf[3][3] = 1;
}

void guLookAtReflectF(float mf[4][4], LookAt *l, 
		      float xEye, float yEye, float zEye,
		      float xAt,  float yAt,  float zAt,
		      float xUp,  float yUp,  float zUp)
{
	float	len, xLook, yLook, zLook, xRight, yRight, zRight;

	guMtxIdentF(mf);

	xLook = xAt - xEye;
	yLook = yAt - yEye;
	zLook = zAt - zEye;

	/* Negate because positive Z is behind us: */
	len = -1.0 / gu_sqrtf (xLook*xLook + yLook*yLook + zLook*zLook);
	xLook *= len;
	yLook *= len;
	zLook *= len;

	/* Right = Up x Look */

	xRight = yUp * zLook - zUp * yLook;
	yRight = zUp * xLook - xUp * zLook;
	zRight = xUp * yLook - yUp * xLook;
	len = 1.0 / gu_sqrtf (xRight*xRight + yRight*yRight + zRight*zRight);
	xRight *= len;
	yRight *= len;
	zRight *= len;

	/* Up = Look x Right */

	xUp = yLook * zRight - zLook * yRight;
	yUp = zLook * xRight - xLook * zRight;
	zUp = xLook * yRight - yLook * xRight;
	len = 1.0 / gu_sqrtf (xUp*xUp + yUp*yUp + zUp*zUp);
	xUp *= len;
	yUp *= len;
	zUp *= len;

	/* reflectance vectors = Up and Right */

	l->l[0].l.dir[0] = FTOFRAC8(xRight);
	l->l[0].l.dir[1] = FTOFRAC8(yRight);
	l->l[0].l.dir[2] = FTOFRAC8(zRight);
	l->l[1].l.dir[0] = FTOFRAC8(xUp);
	l->l[1].l.dir[1] = FTOFRAC8(yUp);
	l->l[1].l.dir[2] = FTOFRAC8(zUp);
	l->l[0].l.col[0] = 0x00;
	l->l[0].l.col[1] = 0x00;
	l->l[0].l.col[2] = 0x00;
	l->l[0].l.pad1 = 0x00;
	l->l[0].l.colc[0] = 0x00;
	l->l[0].l.colc[1] = 0x00;
	l->l[0].l.colc[2] = 0x00;
	l->l[0].l.pad2 = 0x00;
	l->l[1].l.col[0] = 0x00;
	l->l[1].l.col[1] = 0x80;
	l->l[1].l.col[2] = 0x00;
	l->l[1].l.pad1 = 0x00;
	l->l[1].l.colc[0] = 0x00;
	l->l[1].l.colc[1] = 0x80;
	l->l[1].l.colc[2] = 0x00;
	l->l[1].l.pad2 = 0x00;

	mf[0][0] = xRight;
	mf[1][0] = yRight;
	mf[2][0] = zRight;
	mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

	mf[0][1] = xUp;
	mf[1][1] = yUp;
	mf[2][1] = zUp;
	mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

	mf[0][2] = xLook;
	mf[1][2] = yLook;
	mf[2][2] = zLook;
	mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

	mf[0][3] = 0;
	mf[1][3] = 0;
	mf[2][3] = 0;
	mf[3][3] = 1;
}

void guLookAtReflect (Mtx *m, LookAt *l, float xEye, float yEye, float zEye,
	       float xAt,  float yAt,  float zAt,
	       float xUp,  float yUp,  float zUp)
{
	float	mf[4][4];

	guLookAtReflectF(mf, l, xEye, yEye, zEye, xAt, yAt, zAt,
			 xUp, yUp, zUp);

	guMtxF2L(mf, m);
}

void guScale(Mtx *m, float x, float y, float z)
{
    float	mf[4][4];

    guScaleF(mf, x, y, z);
    __guMtxF2L(mf, m);
}

void guRotateRPYF(f32 mf[4][4], f32 r, f32 p, f32 h) {
    static f32 dtor = 3.1415926 / 180.0;
    s32 pad;
    f32 sinp, sinh, sinr;
    f32 cosp, cosh, cosr;

    r *= dtor;
    p *= dtor;
    h *= dtor;
    sinr = sinf(r);
    cosr = cosf(r);
    sinp = sinf(p);
    cosp = cosf(p);
    sinh = sinf(h);
    cosh = cosf(h);
    guMtxIdentF(mf);
    mf[0][0] = cosp * cosh;
    mf[0][1] = cosp * sinh;
    mf[0][2] = -sinp;

    mf[1][0] = (sinr*sinp*cosh - cosr*sinh);
    mf[1][1] = (sinr*sinp*sinh + cosr*cosh);
    mf[1][2] = (sinr*cosp);


    mf[2][0] = (cosr*sinp*cosh + sinr*sinh);
    mf[2][1] = (cosr*sinp*sinh - sinr*cosh);
    mf[2][2] = (cosr*cosp);
}
