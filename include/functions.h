#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ultra64.h>

#include "enums.h"
#include "structs.h"
#include "string.h"
#include "gcbound.h"
#include "gczoombox.h"

#include "prop.h"

extern f32 fabsf(f32);
#pragma intrinsic (fabsf)

void func_80241304(Mtx *m, float x, float y, float z);

void _guMtxIdentF_80245D44(float mf[4][4]); //static should NOT be here

void * malloc(s32 size);
void free(void*);
void* realloc(void* ptr, s32 size);

float mlNormalizeAngle(float);

void func_80258C48(f32 *arg0, f32 *arg1, f32 *arg2);
void func_80258C7C(f32 *arg0, f32 arg1);
void mlScale(f32 *, f32 *, f32);


float gu_sqrtf(float val);

void func_802876CC(Movement *, f32,f32);
void func_8028768C(Movement *, f32);
s32  func_80289FE8(f32);
void func_8028A37C(f32);

ActorMarker *func_8028D5D0(void);

enum transformation func_8028E7CC(void);

void func_8028E7EC(f32 *arg0);

void banjo_getRotation(f32 *dst);

void func_80291A60(s32 arg0, f32* arg1);

void banjo_getPosition(f32 *dst);

f32 banjo_getPitch(void);

void func_80297970(f32);

f32  func_80297AAC(void);

void func_80298220(f32 *arg0);

void func_802991B4(f32);

void func_80299BFC(f32);

f32 banjo_getRoll(void);

f32 banjo_getYaw(void);

void *assetcache_get(s32 arg0);

void func_803272F8(s32 *, s32, ActorInfo*, u32);

f32 func_8033DD9C(void);

#endif
