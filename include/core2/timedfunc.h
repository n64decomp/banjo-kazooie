#ifndef __TIMED_FUNC_H__
#define __TIMED_FUNC_H__
#include <ultra64.h>

#include "generic.h"

#define reinterpret_cast(type, var) (*((type *)&var))


void timedFunc_set_0(f32 time, GenMethod_0 funcPtr);
void timedFunc_set_1(f32 time, GenMethod_1 funcPtr, s32 arg0);
void timedFunc_set_2(f32 time, GenMethod_2 funcPtr, s32 arg0, s32 arg1);
void timedFunc_set_3(f32 time, GenMethod_3 funcPtr, s32 arg0, s32 arg1, s32 arg2);
void timedFunc_set_4(f32 time, GenMethod_4 funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void timedFunc_set_5(f32 time, GenMethod_5 funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void timedFunc_set_6(f32 time, GenMethod_6 funcPtr, void* argPtr );
void timedJiggySpawn(f32 time, s32 jiggyId, f32 *position);

#endif
