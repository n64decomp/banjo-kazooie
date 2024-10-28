#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */

struct {
    f32 value[0x8];
    f32 last[0x8];
} s_batimer;

/* .code*/
void batimer_incrementBy(s32 id, f32 inc_value_sec){
    s_batimer.last[id] = s_batimer.value[id];
    s_batimer.value[id] += inc_value_sec;
}

int batimer_decrement(s32 id){
    s_batimer.last[id] = s_batimer.value[id];
    if(0.0f == s_batimer.value[id]){
        return 0;
    }
    s_batimer.value[id] = ml_max_f(0.0f, s_batimer.value[id] - time_getDelta());
    return s_batimer.value[id] == 0.0f;
}

void batimer_increment(s32 id){
    s_batimer.last[id] = s_batimer.value[id];
    s_batimer.value[id] += time_getDelta();
}

f32 batimer_get(s32 id){
    return s_batimer.value[id];
}

int batimer_isAt(s32 id, f32 value_sec){
    return s_batimer.last[id] <= value_sec 
        && value_sec < s_batimer.value[id];
}

int batimer_isLessThan(s32 id, f32 value_sec){
    return s_batimer.value[id] < value_sec;
}

int batimer_isGreaterThan(s32 id, f32 value_sec){
    return value_sec < s_batimer.value[id];
}

int batimer_isNonzero(s32 id){
    return (0.0 != s_batimer.value[id]);
}

int batimer_isZero(s32 id){
    return (0.0 == s_batimer.value[id]);
}

void batimer_set(s32 id, f32 value_sec){
    s_batimer.last[id] = value_sec;
    s_batimer.value[id] = value_sec;
}
