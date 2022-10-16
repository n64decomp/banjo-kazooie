#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80275908;

s32 func_80245980(f32 arg0){
	return arg0*65536.0f;
}

void func_802459A0(float mf[4][4], Mtx *m)
{
	int	i, j;
	int	e1,e2;
	int	*ai,*af;


	ai=(int *) &m->m[0][0];
	af=(int *) &m->m[2][0];

	for (i=0; i<4; i++)
	for (j=0; j<2; j++) {
		e1=func_80245980(mf[i][j*2]);
		e2=func_80245980(mf[i][j*2+1]);
		*(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff);
		*(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
	}
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245A7C.s")

void func_80245BE4(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    s32 i, j;

    _guMtxIdentF_80245D44(mf);
    mf[0][0] = (2 * arg5) / (arg2 - arg1);
    mf[1][1] = (2 * arg5) / (arg4 - arg3);
    mf[2][0] = (arg2 + arg1) / (arg2 - arg1);
    mf[2][1] = (arg4 + arg3) / (arg4 - arg3);
    mf[2][2] = -(arg6 + arg5) / (arg6 - arg5);
    mf[2][3] = -1.0f;
    mf[3][2] = (-2 * arg6 * arg5) / (arg6 - arg5);
    mf[3][3] = 0.0f;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			mf[i][j] *= arg7;
		}
	}
}

void _guMtxIdentF_80245D44(float mf[4][4]) //static
{
	int	i, j;

	for (i=0; i<4; i++)
	for (j=0; j<4; j++)
		if (i == j) mf[i][j] = 1.0;
		else mf[i][j] = 0.0;
}

void func_80245DCC(f32 lmf[4][4], f32 rmf[4][4], f32 dst[4][4]) {
	s32 i, j, k;
    f32 sp1C[4][4];

	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			sp1C[i][j] = 0.0f;
			for(k = 0; k < 4; k++){
				sp1C[i][j] += lmf[i][k]*rmf[k][j];
			}
		}
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			dst[i][j] = sp1C[i][j];
		}
	}
}

void func_80245F34(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 inv_len;

    inv_len = 1.0f / gu_sqrtf((*arg0 * *arg0) + (*arg1 * *arg1) + (*arg2 * *arg2));
    *arg0 *= inv_len;
    *arg1 *= inv_len;
    *arg2 *= inv_len;
}

#ifndef NONMATCHING
void func_80245FB8(f32 mf[4][4], u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245FB8.s")
#else
void func_80245FB8(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale)
{
	float	cot;
    f32 tmp;
	int	i, j;

    near = (near < 1) ? 1 : near;
    far = (far < near + 100) ? near + 100 : far;
    tmp = ((2 * near * far) / (near - far));
    if( ( tmp*scale >  32767) || (tmp*scale < -32767)) {
        tmp = ((tmp*scale > 32767) ?  32767.0f :   -32767.0f);
        near = (-(tmp/scale) * far) / ((2 * far) - (tmp/scale));
    }

	guMtxIdentF(mf);
	fovy *= 3.1415926 / 180.0;
	cot = cosf (fovy/2) / sinf (fovy/2);
	mf[0][0] = cot / aspect;
	mf[1][1] = cot;
	mf[2][2] = (near + far) / (near - far);
	mf[2][3] = -1;
	mf[3][2] = ((2 * near * far) / (near - far));
	mf[3][3] = 0;

	for (i=0; i<4; i++)
	    for (j=0; j<4; j++)
			mf[i][j] *= scale;

	if (perspNorm != (u16 *) NULL) {
	    if ((near + far)<=2.0) {
		*perspNorm = (u16) 0xFFFF;
	    } else  {
		*perspNorm = (u16) ((2.0*65536.0)/(near + far));
		if (*perspNorm<=0) 
		    *perspNorm = (u16) 0x0001;
	    }
	}
}
#endif

void guPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 sp28[4][4];

    func_80245FB8(sp28, perspNorm, fovy, aspect, near, far, scale);
    func_802459A0(sp28, m);
}

void func_8024632C(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    volatile f32 sp24;

    func_80245F34(&arg2, &arg3, &arg4);
    arg1 *= D_80275908;
    sp34 = sinf(arg1);
    sp30 = cosf(arg1);
    sp2C = arg2 * arg3 * (1.0f - sp30);
    sp28 = arg3 * arg4 * (1.0f - sp30);
    sp24 = (arg4 * arg2 * (1.0f - sp30));
    _guMtxIdentF_80245D44(mf);
    mf[0][0] = ((1.0f - (arg2 * arg2)) * sp30) + (arg2 * arg2);
    mf[2][1] = (sp28 - (arg2 * sp34));
    mf[1][2] = ((arg2 * sp34) + sp28);

    mf[1][1] = (((1.0f - (arg3 * arg3)) * sp30) + (arg3 * arg3));
    mf[2][0] = ((arg3 * sp34) + sp24);
    mf[0][2] = (sp24 - (arg3 * sp34));
	
    mf[2][2] = (((1.0f - (arg4 * arg4)) * sp30) + (arg4 * arg4));
    mf[1][0] = (sp2C - (arg4 * sp34));
    mf[0][1] = (arg4 * sp34) + sp2C;
}

void func_802464B0(f32 mf[4][4], f32 arg1){
	f32 c, s;
	arg1 *= D_80275908;
	_guMtxIdentF_80245D44(mf);
	c = cosf(arg1);
	mf[1][1] = c;
	mf[2][2] = c;
	s = sinf(arg1);
	mf[1][2] = s;
	mf[2][1] = -s;
}

void func_80246510(f32 mf[4][4], f32 arg1){
	f32 c, s;
	arg1 *= D_80275908;
	_guMtxIdentF_80245D44(mf);
	c = cosf(arg1);
	mf[0][0] = c;
	mf[2][2] = c;
	s = sinf(arg1);
	mf[2][0] = s;
	mf[0][2] = -s;
}

void func_80246570(f32 mf[4][4], f32 arg1){
	f32 c, s;
	arg1 *= D_80275908;
	_guMtxIdentF_80245D44(mf);
	c = cosf(arg1);
	mf[0][0] = c;
	mf[1][1] = c;
	s = sinf(arg1);
	mf[0][1] = s;
	mf[1][0] = -s;
}

void func_802465D0(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3){
	_guMtxIdentF_80245D44(mf);
	mf[0][0] = arg1;
	mf[1][1] = arg2;
	mf[2][2] = arg3;
	mf[3][3] = 1.0f;
}

void func_80246624(f32 mf[4][4], f32 arg1, f32 arg2, f32 arg3){
	_guMtxIdentF_80245D44(mf);
	mf[3][0] = arg1;
	mf[3][1] = arg2;
	mf[3][2] = arg3;
}
