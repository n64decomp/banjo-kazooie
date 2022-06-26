#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f64 D_80277640;

u8 D_8027EB10[0x200]; // Size based on the previous symbol's address
OSThread D_8027ED10;


void func_80240C30(void*);

void func_80240BE0(void){
    osCreateThread(&D_8027ED10, 1, func_80240C30, NULL, &D_8027EB10[0x200], 0);
    osStartThread(&D_8027ED10);
}

void func_80240754(void);
void func_8023E018(void);
OSThread *func_8023E060(void);

void func_80240C30(void *arg)
{
    func_80240754();
    func_8023E018();
    osStartThread(func_8023E060());
    while (1);
}

static void _guMtxF2L(float mf[4][4], Mtx *m)
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

void func_80240E4C(f32 mf[4][4], LookAt *l, float xEye, float yEye, float zEye, 
            float xAt, float yAt, float zAt, 
            float xUp,  float yUp,  float zUp);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80240E4C.s")

void func_8024128C (Mtx *m, LookAt *l, float xEye, float yEye, float zEye,
	       float xAt,  float yAt,  float zAt,
	       float xUp,  float yUp,  float zUp)
{
	float	mf[4][4];

	func_80240E4C(mf, l, xEye, yEye, zEye, xAt, yAt, zAt,
			 xUp, yUp, zUp);

	guMtxF2L(mf, m);
}

void guScale(Mtx *m, float x, float y, float z)
{
    float	mf[4][4];

    guScaleF(mf, x, y, z);
    _guMtxF2L(mf, m);
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
