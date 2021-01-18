#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ultra64.h>

#include "structs.h"

extern f32 fabsf(f32);
#pragma intrinsic (fabsf)

void func_80240DF8(float *mf, float x, float y, float z);
void func_80241304(Mtx *m, float x, float y, float z);
#endif
