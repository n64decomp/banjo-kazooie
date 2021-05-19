#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80285900;

f32 sinf(f32);
f32 func_80265360(f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core1/gu/rotate/guRotateF.s")
// MATCHING but need to resolve core1 data section for static D_80285900
// void guRotateF(float mf[4][4], float a, float x, float y, float z)
// {
//     static f32 D_80285900 = 3.1415926 / 180.0;
//     float	sine;
// 	float	cosine;
// 	float	ab, bc, ca, t;
    
	
// 	guNormalize(&x, &y, &z);
// 	a *= D_80285900;
// 	sine = sinf(a);
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
// MATCHING with -O3, need to resolve data section
// void guRotate(Mtx *m, float a, float x, float y, float z)
// {
// 	float	mf[4][4];

// 	guRotateF(mf, a, x, y, z);
// 	guMtxF2L(mf, m);
// }
