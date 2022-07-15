#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80296548(void);
extern f32 func_8029653C(void);
extern f32 func_80297A4C(void);
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
        func_80297A0C(0);
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
        func_8029C7F4(1, 1, 2, 1);
        yaw_setIdeal(mlNormalizeAngle(sp28));
        gravity_set(func_80296548());
        sp20 = func_8029653C();
        sp24 = func_8029B56C(sp2C[1], sp38[1], sp20, func_80297A4C());
        ml_vec3f_diff_copy(sp44, sp38, sp2C);
        D_8037D504 = sp24;
        sp44[0] /= sp24;
        sp44[1] /= sp24;
        sp44[2] /= sp24;
        sp44[1] = sp20;
        func_80297A0C(sp44);
        func_8029E3C0(6, sp24);
    } else {
        func_802B35D0(0);
        func_80298760(sp1C);
        yaw_setIdeal(mlNormalizeAngle(sp28 + 180.0f));
        func_80297970(func_802987D4());
        func_8029797C(sp28);
        func_802979AC(sp28, func_80297A64());
        player_setYVelocity(func_802987C4());
        gravity_set(func_802987E4());
        func_8029C7F4(1, 1, 2, 3);
        if (func_802987B4() == 2) {
            func_802978DC(6);
        }
    }
    yaw_applyIdeal();
}

void func_802B37DC(void) {
    f32 velocity[3];

    if (D_8037D500 != 0) {
        if ((D_8037D500 == 1) && func_8029E1A8(6)) {
            _get_velocity(velocity);
            velocity[0] = 0.0f;
            velocity[2] = 0.0f;
            func_80297A0C(velocity);
            func_80297970(0.0f);
        }
    } else if (func_802987B4() == 2) {
        func_802B6FA8();
    }
}

void func_802B3868(void) {
    AnimCtrl *anim_ctrl;
    f32 sp20;

    anim_ctrl = _player_getAnimCtrlPtr();
    func_802B360C();
    if (D_8037D500 == 0) {
        sp20 = 1.4f;
    } else {
        sp20 = D_8037D504 + 0.5;
    }
    animctrl_reset(anim_ctrl);
    animctrl_setSmoothTransition(anim_ctrl, 0);
    animctrl_setSubRange(anim_ctrl, 0.0f, 0.5823f);
    animctrl_setIndex(anim_ctrl, 0xF);
    animctrl_setDuration(anim_ctrl, sp20);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    _func_802875AC(anim_ctrl, "bsrebound.c", 0xC6);
    func_8030E58C(SFX_56_BANJO_HUI, 1.0f);
    func_8029E3C0(0, 1.5f);
    func_8028D5DC();
}


void func_802B3954(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = _player_getAnimCtrlPtr();
    if (func_8029E1A8(0) && map_get() == MAP_93_GL_DINGPOT) {
        func_8028D5F4();
    }
    func_802B37DC();
    if (func_8028B2E8()) {
        next_state = BS_20_LANDING;
    }
    if (func_8028B424() && D_8037D500 == 0) {
        next_state = BS_3D_FALL_TUMBLING;
    }
    if (animctrl_isStopped(anim_ctrl) && func_8028B094() && (D_8037D500 == 0)) {
        next_state = BS_2F_FALL;
    }
    bs_setState(next_state);
}


void func_802B3A20(void) {
    func_802B35DC();
    gravity_reset();
    func_8028D5F4();
}
