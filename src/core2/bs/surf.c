#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

/* .bss */
s32 D_8037D560;

/* .code */
void func_802B5FD0(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_69_ANIM_BSSURF);
    anctrl_setDuration(anim_ctrl, 1.8f);
    anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
    anctrl_start(anim_ctrl, "bssurf.c", 0x33);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    D_8037D560 = 1;
}

void func_802B6064(void) {
    enum bs_e next_state;

    next_state = 0;
    if (bakey_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (D_8037D560 == 0) {
        next_state = BS_1_IDLE;
    }
    D_8037D560 = 0;
    if (baflag_isTrue(BA_FLAG_6)) {
        next_state = BS_53_TIMEOUT;
    }
    bs_setState(next_state);
}

void func_802B60D0(void){}

void func_802B60D8(void) {
    if (bs_getInterruptType() == BS_INTR_D_SURF) {
        D_8037D560 = 1;
        func_8029A86C(2);
        return;
    }
    func_80296608();
}
