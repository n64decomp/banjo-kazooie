#ifndef __TIMED_FUNC_H__
#define __TIMED_FUNC_H__
#include <ultra64.h>

void timedFunc_set_0(f32 time, void(*funcPtr)(void));
void timedFunc_set_1(f32 time, void(*funcPtr)(s32), s32 arg0);
void timedFunc_set_2(f32 time, void(*funcPtr)(s32, s32), s32 arg0, s32 arg1);
void timedFunc_set_3(f32 time, void(*funcPtr)(s32, s32, s32), s32 arg0, s32 arg1, s32 arg2);
void timedFunc_set_4(f32 time, void(*funcPtr)(s32, s32, s32, s32), s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void timedFunc_set_5(f32 time, void(*funcPtr)(s32, s32, s32, s32, s32), s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void timedFunc_set_6(f32 time, void(*funcPtr)(s32, s32, s32, s32, s32, s32), s32* argPtr );
void timedJiggySpawn(f32 time, s32 jiggyId, f32 *position);

#endif
