#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"
#include "iFrame.h"

/* .bss */
u8 iFrameState;

/* .code */
void baiFrame_setState(s32 state) {
    iFrameState = state;
}

s32 baiFrame_getState(void) {
    return iFrameState;
}

void baiFrame_reset(void) {
    iFrameState = 0;
    baiFrame_setState(IFRAME_NONE);
    stateTimer_clear(STATE_TIMER_4_IFRAME);
}

void baiFrame_start(void) {
    baiFrame_startWithValue(0.6f);
}

void baiFrame_startWithValue(f32 val) {
    stateTimer_set(STATE_TIMER_4_IFRAME, val);
    baiFrame_setState(IFRAME_INVICIBLE);
}

void baiFrame_update(void) {
    if (stateTimer_isDone(STATE_TIMER_4_IFRAME)) {
        baiFrame_setState(IFRAME_NONE);
    }
}
