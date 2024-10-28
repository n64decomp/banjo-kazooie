#ifndef __BA_TIMER_H__
#define __BA_TIMER_H__

#include <ultra64.h>

void batimer_incrementBy(s32 id, f32 inc_value_sec);
int batimer_decrement(s32 id);
void batimer_increment(s32 id);
f32 batimer_get(s32 id);
int batimer_isAt(s32 id, f32 value_sec);
int batimer_isLessThan(s32 id, f32 value_sec);
int batimer_isGreaterThan(s32 id, f32 value_sec);
int batimer_isNonzero(s32 id);
int batimer_isZero(s32 id);
void batimer_set(s32 id, f32 value_sec);
#endif
