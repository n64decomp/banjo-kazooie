#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80275908;

s32 func_80245980(f32 arg0){
	return arg0*65536.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_802459A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245A7C.s")
// void func_80245A7C(Mtx *m0, Mtx *m1){
// 	u32 *v0 = &m1->m[0][0];
// 	u32 *v1 = &m1->m[2][0];
// 	f32 *a2 = &m0->m[0][0];
// 	s32 a0;
// 	s32 a1;
// 	int i;

// 	for(i = 0; i < 8; i++){
// 		a0 = a2[2*i]*65536.0f;
// 		a1 = a2[2*i+1]*65536.0f;

// 		v0[i] = (a0 & 0xffff0000) | ((a1 >> 16) & 0xffff);
// 		v1[i] = ((a0 << 16) & 0xffff0000) | (a1 & 0xffff);
// 	}
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245BE4.s")

void _guMtxIdentF_80245D44(float mf[4][4]) //static
{
	int	i, j;

	for (i=0; i<4; i++)
	for (j=0; j<4; j++)
		if (i == j) mf[i][j] = 1.0;
		else mf[i][j] = 0.0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/guPerspective.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_8024632C.s")

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
