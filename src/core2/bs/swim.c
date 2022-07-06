#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80295328(s32, f32);

bool func_802B5724(enum bs_e state_id);

/* .data */
f32 D_80364D40 = 30.0f;
f32 D_80364D44 = 300.0f;
f32 D_80364D48 = 1.2f;
f32 D_80364D4C = 0.7f;
s16 D_80364D50[10] = {
    0x57,
    0x57,
    0x57,
    0x58,
    0x57,
    0x58,
    0x57,
    0x57,
    0x58,
    0x58
};

/* .bss */
u32 D_8037D550;

/* .code */
void func_802B5480(void) {
    f32 sp2C[3];
    ParticleEmitter *sp28;

    if (func_80294574()) {
        if (randf() > 0.5) {
            func_8029223C(sp2C);
        } else {
            func_80292260(sp2C);
        }
        sp28 = func_8029B950(&sp2C, 0.0f);
        particleEmitter_setParticleVelocityRange(sp28, -60.0f, -100.0f, -60.0f, 60.0f, 0.0f, 60.0f);
        particleEmitter_emitN(sp28, 1);
    }
}

void func_802B5538(AnimCtrl *arg0) {
    enum asset_e sp24;

    sp24 = D_80364D50[D_8037D550];
    if (animctrl_getIndex(arg0) != sp24) {
        func_8028774C(arg0, animctrl_getAnimTimer(arg0));
        animctrl_setIndex(arg0, sp24);
        _func_802875AC(arg0, "bsswim.c", 0x79);
    }
    D_8037D550++;
    if (D_8037D550 >= 10) {
        D_8037D550 = 0;
    }
}

void func_802B55DC(void) {
    f32 sp1C;

    sp1C = func_8029B30C();
    if (func_8029B300() == 0) {
        func_80297970(0.0f);
        return;
    }
    func_80297970(func_80257C48(sp1C, D_80364D40, D_80364D44));
}

void func_802B563C(void) {
    if (level_get() == LEVEL_9_RUSTY_BUCKET_BAY) {
        func_8035644C(0xAB);
    } else if (map_get() == MAP_46_CCW_WINTER) {
        func_8035644C(0xDD);
    }
    gravity_set(100.0f);
    func_80297BF8(133.33f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_80294378(3);
}


void func_802B56D4(void) {
    if (!func_802B5724(bs_getNextState())) {
        func_80297B94();
        gravity_reset();
        func_8029B0C0();
        func_80294378(1);
    }
}

bool func_802B5724(enum bs_e state_id){
    return state_id == BS_2D_SWIM_IDLE
        || state_id == BS_2E_SWIM
        || state_id == BS_4C_LANDING_IN_WATER
        || state_id == BS_77
        || state_id == BS_96_SWIM_LOCKED
        ;
}

void func_802B5774(void) {
    AnimCtrl *anim_ctrl;
    s32 prev_state;
    f32 transition_duration;

    anim_ctrl = _player_getAnimCtrlPtr();
    prev_state = bs_getPrevState();
    if (prev_state == BS_4C_LANDING_IN_WATER) {
        transition_duration = 0.8f;
    } else {
        transition_duration = 0.5f;
    }
    if (func_802A7508(prev_state) != 0) {
        if (prev_state == BS_54_SWIM_DIE) {
            func_80299CF4(SFX_AF_BANJO_CATCHING_BREATH, 1.0f, 30000);
        } else {
            func_80299CF4(SFX_AF_BANJO_CATCHING_BREATH, 1.0f, (s32) ml_map_f(item_getCount(ITEM_17_AIR), 3600.0f, 0.0f, 8000.0f, 30000.0f));
        }
        func_80295328(4, 0.7f);
    }
    if ((animctrl_getIndex(anim_ctrl) == 0x57) && (prev_state != BS_4C_LANDING_IN_WATER)) {
        animctrl_setSmoothTransition(anim_ctrl, 0);
        animctrl_setIndex(anim_ctrl, 0x57);
        animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        animctrl_setDuration(anim_ctrl, 1.2f);
    } else {
        animctrl_reset(anim_ctrl);
        animctrl_setTransitionDuration(anim_ctrl, transition_duration);
        animctrl_setIndex(anim_ctrl, 0x57);
        animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        func_8028774C(anim_ctrl, 0.3f);
        animctrl_setDuration(anim_ctrl, 1.2f);
        func_802875AC(anim_ctrl, "bsswim.c", 0xFD);
    }
    func_8029C7F4(1, 3, 3, 2);
    func_80299234(500.0f, 5.0f);
    func_80297970(0.0f);
    func_802B563C();
    D_8037D550 = 0;
}

void func_802B5950(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;

    next_state = 0;
    anim_ctrl = _player_getAnimCtrlPtr();
    if ((func_8023DB4C(7) == 0) && ((f64) randf() < 0.5)) {
        func_8029C304(1);
    }
    if ((func_8023DB4C(7) == 0) && ((f64) randf() < 0.5)) {
        func_802B5480();
    }
    if (animctrl_isAt(anim_ctrl, 0.01f) != 0) {
        func_8030EC20(SFX_DC_IDLE_PADDLING, 0.85f, 1.15f, 0x3E80U, 0x3E80U);
    }
    if (animctrl_isAt(anim_ctrl, 0.4348f) != 0) {
        func_802B5538(anim_ctrl);
    }
    if (func_8029B300() == 1) {
        next_state = BS_2E_SWIM;
    }
    if (!player_inWater()) {
        next_state = BS_1_IDLE;
    }
    if (func_80294F78()) {
        next_state = func_802926C0();
    }
    if (should_dive()) {
        next_state = BS_30_DIVE_ENTER;
    }
    if (func_80294524() && button_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (func_802933C0(6) || func_802933C0(0x14)) {
        next_state = BS_D_TIMEOUT;
    }
    bs_setState(next_state);
}

void func_802B5AF8(void){
    func_802B56D4();
}

void func_802B5B18(void) {
    AnimCtrl *anim_ctrl;
    f32 anim_duration;

    anim_ctrl = _player_getAnimCtrlPtr();
    if (bs_getPrevState() == BS_4C_LANDING_IN_WATER) {
        anim_duration = 0.8f;
    } else {
        anim_duration = 0.4f;
    }
    if (animctrl_getIndex(anim_ctrl) != 0x39) {
        animctrl_reset(anim_ctrl);
        animctrl_setIndex(anim_ctrl, 0x39);
        animctrl_setTransitionDuration(anim_ctrl, anim_duration);
        func_8028774C(anim_ctrl, 0.8f);
        animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
        func_802875AC(anim_ctrl, "bsswim.c", 0x164);
    }
    func_80289F10(2);
    func_80289EA8(0.3f, 1.5f);
    func_80289EC8(D_80364D40, D_80364D44, D_80364D48, D_80364D4C);
    func_802991A8(3);
    func_80299234(500.0f, 5.0f);
    func_8029957C(1);
    func_802978DC(2);
}

void func_802B5C40(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 sp1C[3];

    next_state = 0;
    anim_ctrl =_player_getAnimCtrlPtr();
    if (animctrl_isAt(anim_ctrl, 0.38f)) {
        func_8029C4E4(1);
    }
    if (animctrl_isAt(anim_ctrl, 0.88f)) {
        func_8029C4E4(0);
    }
    if (animctrl_isAt(anim_ctrl, 0.2f)) {
        func_8030EB88(SFX_12_WATER_PADDLING_1, 0.9f, 1.1f);
    }
    if (animctrl_isAt(anim_ctrl, 0.7f)) {
        func_8030EB88(SFX_12_WATER_PADDLING_1, 0.9f, 1.1f);
    }
    func_802B55DC();
    if (func_8029B300() == 0) {
        next_state = BS_2D_SWIM_IDLE;
    }
    if (player_inWater() == 0) {
        next_state = BS_1_IDLE;
    }
    if ((func_80294530() != 0) && (can_dive() != 0)) {
        func_802944D0(sp1C);
        if (sp1C[1] < -0.7) {
            if ((func_80294500() - player_getYPosition()) > 90.0f) {
                next_state = BS_30_DIVE_ENTER;
            }
        }
    }
    if (should_dive() != 0) {
        next_state = BS_30_DIVE_ENTER;
    }
    if (func_80294524() && button_pressed(BUTTON_A)) {
        next_state = BS_5_JUMP;
    }
    if (func_802933C0(6) || func_802933C0(0x14)) {
        next_state = BS_D_TIMEOUT;
    }
    bs_setState(next_state);
}

void func_802B5E10(void){
    func_802B56D4();
}

void func_802B5E30(void) {
    f32 sp34;
    f32 plyr_pos[3];
    f32 sp1C[3];

    if (func_80298850() != 0) {
        _player_getPosition(plyr_pos);
        if (func_80298800(sp1C) && func_80257F18(plyr_pos, sp1C, &sp34)) {
            yaw_setIdeal(sp34);
        }
    }
}

void func_802B5E8C(void) {
    func_8028A010(0x57, 1.2f);
    func_8029C7F4(1, 3, 3, 2);
    func_80299234(500.0f, 5.0f);
    func_80297970(0.0f);
    func_802B563C();
    func_802B5E30();
}

void func_802B5EFC(void) {
    enum bs_e next_state;

    next_state = 0;
    if (func_80298850() == 0) {
        next_state = BS_2D_SWIM_IDLE;
    }
    func_802B5E30();
    bs_setState(next_state);
}

void func_802B5F38(void){
    func_802B56D4();
}

void func_802B5F58(void){
    func_802B563C();
    bsdrone_init();
}

void func_802B5F80(void){
    bsdrone_update();
}

void func_802B5FA0(void){
    bsdrone_end();
    func_802B56D4();
}
