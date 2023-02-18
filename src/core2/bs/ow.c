#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802B37DC(void);

/* .bss */
u8  D_8037D4D0;

void func_802B1FD0(s32 arg0){}

void bsow_init(void){
    AnimCtrl *plyr_mvmnt;

    plyr_mvmnt = baanim_getAnimCtrlPtr();
    animctrl_reset(plyr_mvmnt);
    animctrl_setSmoothTransition(plyr_mvmnt, 0);
    animctrl_setSubRange(plyr_mvmnt, 0.0f, 0.534399986267f);
    animctrl_setIndex(plyr_mvmnt, ASSET_4D_ANIM_BSOW);
    animctrl_setDuration(plyr_mvmnt, 1.70000004768f);
    animctrl_setPlaybackType(plyr_mvmnt,  ANIMCTRL_ONCE);
    animctrl_start(plyr_mvmnt, "bsow.c", 0x50);
    func_80299BFC(1.0f);
    func_802B360C();
    baMarker_collisionOff();
    func_80292E48();
    D_8037D4D0 = 0;
    func_802B1FD0(1);
}

void bsow_update(void) {
    s32 sp1C = 0;
    u8 temp_v0;

    sp1C = 0;
    func_802B37DC();
    switch(D_8037D4D0){
        case 0:
            if (func_8028B254(0x5A) != 0) {
                baanim_setEnd(1.0f);
                D_8037D4D0 = 1;
            }
            break;
        case 1:
            break;
    }

    if (baanim_isAt(0.3f) != 0) {
        func_80292EA4();
    }
    if (func_8028B424() != 0) {
        sp1C = BS_3D_FALL_TUMBLING;
    }
    if (func_8028B2E8() != 0) {
        sp1C = BS_2_WALK_SLOW;
    }
    if ((player_inWater() != 0) && (_get_vertVelocity() <= 0.0f)) {
        sp1C = BS_4C_LANDING_IN_WATER;
    }

    bs_setState(sp1C);
}

void bsow_end(void){
    func_802B35DC();
    func_802B1FD0(0);
    func_80297CA8();
    gravity_reset();
    baMarker_collisionOn();
    func_80292EA4();
}
