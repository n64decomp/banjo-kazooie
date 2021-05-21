#ifndef __TIMED_FUNC_H__
#define __TIMED_FUNC_H__
#include <ultra64.h>

typedef void (* TFQM0)(void);
typedef void (* TFQM1)(s32);
typedef void (* TFQM2)(s32, s32);
typedef void (* TFQM3)(s32, s32, s32);
typedef void (* TFQM4)(s32, s32, s32, s32);
typedef void (* TFQM5)(s32, s32, s32, s32, s32);
typedef void (* TFQM6)(void *);

void timedFunc_set_0(f32 time, TFQM0 funcPtr);
void timedFunc_set_1(f32 time, TFQM1 funcPtr, s32 arg0);
void timedFunc_set_2(f32 time, TFQM2 funcPtr, s32 arg0, s32 arg1);
void timedFunc_set_3(f32 time, TFQM3 funcPtr, s32 arg0, s32 arg1, s32 arg2);
void timedFunc_set_4(f32 time, TFQM4 funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void timedFunc_set_5(f32 time, TFQM5 funcPtr, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void timedFunc_set_6(f32 time, TFQM6 funcPtr, void* argPtr );
void timedJiggySpawn(f32 time, s32 jiggyId, f32 *position);

#endif
