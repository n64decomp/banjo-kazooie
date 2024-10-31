#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

void func_802B37DC(void);

/* .bss */
u8  D_8037D4D0;

void func_802B1FD0(s32 arg0){}

void bsow_init(void){
    AnimCtrl *plyr_mvmnt;

    plyr_mvmnt = baanim_getAnimCtrlPtr();
    anctrl_reset(plyr_mvmnt);
    anctrl_setSmoothTransition(plyr_mvmnt, 0);
    anctrl_setSubRange(plyr_mvmnt, 0.0f, 0.534399986267f);
    anctrl_setIndex(plyr_mvmnt, ASSET_4D_ANIM_BSOW);
    anctrl_setDuration(plyr_mvmnt, 1.70000004768f);
    anctrl_setPlaybackType(plyr_mvmnt,  ANIMCTRL_ONCE);
    anctrl_start(plyr_mvmnt, "bsow.c", 0x50);
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
    if (player_isFallTumbling() != 0) {
        sp1C = BS_3D_FALL_TUMBLING;
    }
    if (player_isStable() != 0) {
        sp1C = BS_2_WALK_SLOW;
    }
    if ((player_inWater() != 0) && (baphysics_get_vertical_velocity() <= 0.0f)) {
        sp1C = BS_4C_LANDING_IN_WATER;
    }

    bs_setState(sp1C);
}

void bsow_end(void){
    func_802B35DC();
    func_802B1FD0(0);
    func_80297CA8();
    baphysics_reset_gravity();
    baMarker_collisionOn();
    func_80292EA4();
}
