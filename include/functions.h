#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ultra64.h>

#include "structs.h"
#include "string.h"
#include "gcbound.h"
#include "gczoombox.h"

extern f32 fabsf(f32);
#pragma intrinsic (fabsf)

void func_80241304(Mtx *m, float x, float y, float z);

void _guMtxIdentF_80245D44(float mf[4][4]); //static should NOT be here

void * malloc(s32 size);
void free(void*);
void* realloc(void* ptr, s32 size);

float gu_sqrtf(float val);

#endif
