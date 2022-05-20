#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
s32 D_8037D560;

/* .code */
void func_802B5FD0(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = _player_getAnimCtrlPtr();
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, 0x69);
    animctrl_setDuration(anim_ctrl, 1.8f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
    _func_802875AC(anim_ctrl, "bssurf.c", 0x33);
    func_8029C7F4(1, 1, 3, 2);
    func_80297970(0.0f);
    D_8037D560 = 1;
}

void func_802B6064(void) {
    enum bs_e next_state;

    next_state = 0;
    if (button_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (D_8037D560 == 0) {
        next_state = BS_1_IDLE;
    }
    D_8037D560 = 0;
    if (func_802933C0(6)) {
        next_state = BS_53_TIMEOUT;
    }
    bs_setState(next_state);
}

void func_802B60D0(void){}

void func_802B60D8(void) {
    if (bs_getInterruptType() == 0xD) {
        D_8037D560 = 1;
        func_8029A86C(2);
        return;
    }
    func_80296608();
}
