#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/gu/rotate/guRotateF.s")
//guRotateF
// void guRotateF(float mf[4][4], float a, float x, float y, float z)
// {
//     float	sine;
// 	float	cosine;
// 	float	ab, bc, ca, t;

//     D_80285900 = D_80278CE0; //move to top: static float D_80285900 = D_80278CE0;
	
// 	guNormalize(&x, &y, &z);
// 	a *= D_80285900;
// 	sine = func_80263FF0(a);
// 	cosine = func_80265360(a);
// 	t = (1-cosine);
// 	ab = x*y*t;
// 	bc = y*z*t;
// 	ca = z*x*t;

// 	guMtxIdentF(mf);

// 	t = x*x;
// 	mf[0][0] = t+cosine*(1-t);
// 	mf[2][1] = bc-x*sine;
// 	mf[1][2] = bc+x*sine;

// 	t = y*y;
// 	mf[1][1] = t+cosine*(1-t);
// 	mf[2][0] = ca+y*sine;
// 	mf[0][2] = ca-y*sine;

// 	t = z*z;
// 	mf[2][2] = t+cosine*(1-t);
// 	mf[1][0] = ab-z*sine;
// 	mf[0][1] = ab+z*sine;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/gu/rotate/guRotate.s")
// void guRotate(Mtx *m, float a, float x, float y, float z)
// {
// 	float	mf[4][4];

// 	guRotateF(mf, a, x, y, z);
// 	guMtxF2L(mf, m);
// }