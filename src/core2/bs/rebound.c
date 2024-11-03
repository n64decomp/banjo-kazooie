#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

extern f32 func_80296548(void);
extern f32 func_8029653C(void);
extern f32 func_8029B56C(f32, f32, f32, f32);

/* .bss */
s32 D_8037D500;
f32 D_8037D504;

/* .code */
void func_802B35D0(s32 arg0){
    D_8037D500 = arg0;
}

void func_802B35DC(void) {
    if (D_8037D500 == 1) {
        baphysics_set_velocity(0);
    }
}

void func_802B360C(void) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s32 sp1C;

    sp1C = func_80296560();
    func_80294980(sp38);
    _player_getPosition(sp2C);
    func_80257F18(sp38, sp2C, &sp28);
    if ((sp1C == 0xE) || (sp1C == 0x10)) {
        func_802B35D0(1);
        func_8029C7F4(1, 1, 2, BA_PHYSICS_UNK1);
        yaw_setIdeal(mlNormalizeAngle(sp28));
        baphysics_set_gravity(func_80296548());
        sp20 = func_8029653C();
        sp24 = func_8029B56C(sp2C[1], sp38[1], sp20, baphysics_get_gravity());
        ml_vec3f_diff_copy(sp44, sp38, sp2C);
        D_8037D504 = sp24;
        sp44[0] /= sp24;
        sp44[1] /= sp24;
        sp44[2] /= sp24;
        sp44[1] = sp20;
        baphysics_set_velocity(sp44);
        batimer_set(6, sp24);
    } else {
        func_802B35D0(0);
        func_80298760(sp1C);
        yaw_setIdeal(mlNormalizeAngle(sp28 + 180.0f));
        baphysics_set_target_horizontal_velocity(func_802987D4());
        baphysics_set_target_yaw(sp28);
        baphysics_set_horizontal_velocity(sp28, baphysics_get_target_horizontal_velocity());
        baphysics_set_vertical_velocity(func_802987C4());
        baphysics_set_gravity(func_802987E4());
        func_8029C7F4(1, 1, 2, BA_PHYSICS_LOCKED_ROTATION);
        if (func_802987B4() == 2) {
            baphysics_set_type(BA_PHYSICS_AIRBORN);
        }
    }
    yaw_applyIdeal();
}

void func_802B37DC(void) {
    f32 velocity[3];

    if (D_8037D500 != 0) {
        if ((D_8037D500 == 1) && batimer_decrement(6)) {
            baphysics_get_velocity(velocity);
            velocity[0] = 0.0f;
            velocity[2] = 0.0f;
            baphysics_set_velocity(velocity);
            baphysics_set_target_horizontal_velocity(0.0f);
        }
    } else if (func_802987B4() == 2) {
        func_802B6FA8();
    }
}

void func_802B3868(void) {
    AnimCtrl *anim_ctrl;
    f32 sp20;

    anim_ctrl = baanim_getAnimCtrlPtr();
    func_802B360C();
    if (D_8037D500 == 0) {
        sp20 = 1.4f;
    } else {
        sp20 = D_8037D504 + 0.5;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setSubRange(anim_ctrl, 0.0f, 0.5823f);
    anctrl_setIndex(anim_ctrl, ASSET_F_ANIM_BSREBOUND);
    anctrl_setDuration(anim_ctrl, sp20);
    anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    anctrl_start(anim_ctrl, "bsrebound.c", 0xC6);
    func_8030E58C(SFX_56_BANJO_HUI, 1.0f);
    batimer_set(0, 1.5f);
    baMarker_collisionOff();
}


void func_802B3954(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if (batimer_decrement(0) && map_get() == MAP_93_GL_DINGPOT) {
        baMarker_collisionOn();
    }
    func_802B37DC();
    if (player_isStable()) {
        next_state = BS_20_LANDING;
    }
    if (player_isFallTumbling() && D_8037D500 == 0) {
        next_state = BS_3D_FALL_TUMBLING;
    }
    if (anctrl_isStopped(anim_ctrl) && player_shouldFall() && (D_8037D500 == 0)) {
        next_state = BS_2F_FALL;
    }
    bs_setState(next_state);
}


void func_802B3A20(void) {
    func_802B35DC();
    baphysics_reset_gravity();
    baMarker_collisionOn();
}
