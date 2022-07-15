#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80245980.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_802464B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80246510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80246570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_802465D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7F60/func_80246624.s")
