#include <ultra64.h>
#include "functions.h"
#include "variables.h"


//#pragma GLOBAL_ASM("asm/nonmatchings/core1/gu/translate/guTranslateF.s")
void guTranslateF(float mf[4][4], float x, float y, float z)
{
	guMtxIdentF(mf);

	mf[3][0] = x;
	mf[3][1] = y;
	mf[3][2] = z;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/gu/translate/guTranslate.s")
// void guTranslate(Mtx *m, float x, float y, float z)
// {
// 	float	mf[4][4];

// 	guTranslateF(mf, x, y, z);

// 	guMtxF2L(mf, m);
// }