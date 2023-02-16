#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"

/* .bss */
u8 D_8037C530;

/* .code */
void func_80297C60(s32 arg0){
    D_8037C530 = arg0;
}

s32 func_80297C6C(void){
    return D_8037C530;
}

void func_80297C78(void){
    D_8037C530 = 0;
    func_80297C60(1);
    stateTimer_clear(STATE_TIMER_4_UNKNOWN);
}

void func_80297CA8(void){
    func_80297CCC(0.6f);
}

void func_80297CCC(f32 value){
    stateTimer_set(STATE_TIMER_4_UNKNOWN, value);
    func_80297C60(3);
}

void func_80297CF8(void){
    if(stateTimer_isDone(STATE_TIMER_4_UNKNOWN)){
        func_80297C60(1);
    }
}
