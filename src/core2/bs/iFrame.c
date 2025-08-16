#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"
#include "iFrame.h"

/* .bss */
u8 iFrameState;

/* .code */
void bsiFrame_setState(s32 state) {
    iFrameState = state;
}

s32 bsiFrame_getState(void) {
    return iFrameState;
}

void bsiFrame_reset(void) {
    iFrameState = 0;
    bsiFrame_setState(IFRAME_NONE);
    stateTimer_clear(STATE_TIMER_4_IFRAME);
}

void bsiFrame_start(void) {
    bsiFrame_startWithValue(0.6f);
}

void bsiFrame_startWithValue(f32 val) {
    stateTimer_set(STATE_TIMER_4_IFRAME, val);
    bsiFrame_setState(IFRAME_INVICIBLE);
}

void bsiFrame_update(void) {
    if (stateTimer_isDone(STATE_TIMER_4_IFRAME)) {
        bsiFrame_setState(IFRAME_NONE);
    }
}
