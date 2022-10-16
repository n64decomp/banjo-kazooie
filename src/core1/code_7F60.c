#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80275908;

s32 func_80245980(f32 arg0){
	return arg0*65536.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_802459A0.s")
// void func_802459A0(void *arg0, s32 *arg1) {
//     s32 *var_s3;
//     s32 *var_s4;
//     s32 temp_s2;
//     s32 temp_v0;
//     s32 var_s1;
//     s32 var_s7;
//     void *var_fp;
//     void *var_s0;

//     var_s3 = arg1;
//     var_s4 = arg1 + 0x20;
//     var_s7 = 0;
//     var_fp = arg0;
//     do {
//         var_s1 = 0;
//         var_s0 = var_fp;
// loop_2:
//         temp_s2 = func_80245980(var_s0->unk0);
//         temp_v0 = func_80245980(var_s0->unk4);
//         var_s1 += 8;
//         *var_s3 = (temp_s2 & 0xFFFF0000) | ((temp_v0 >> 0x10) & 0xFFFF);
//         var_s0 += 8;
//         var_s3 += 4;
//         *var_s4 = ((temp_s2 << 0x10) & 0xFFFF0000) | (temp_v0 & 0xFFFF);
//         var_s4 += 4;
//         if (var_s1 != 0x10) {
//             goto loop_2;
//         }
//         var_s7 += 1;
//         var_fp += 0x10;
//     } while (var_s7 != 4);
// }


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

// 		v0[i] = ((a0 << 0) & 0xffff0000) | ((a1 >> 16) & 0xffff);
// 		v1[i] = ((a0 << 16) & 0xffff0000) | ((a1 >> 0) & 0xffff);
// 	}
// }

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
