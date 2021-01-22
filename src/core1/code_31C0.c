#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80240BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80240C30.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80240E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_8024128C.s")


void guScale(Mtx *m, float x, float y, float z)
{
	float	mf[4][4];

	guScaleF(mf, x, y, z);
	_guMtxF2L(mf, m);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80241348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80241490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80241928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802424D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80242BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80243070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_8024324C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802432F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80243F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80243FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_8024431C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802444C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802445AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802445C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802449C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_802449E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_31C0/func_80244A98.s")
