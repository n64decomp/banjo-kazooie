#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"
#include "core2/ba/anim.h"

extern void baanim_playForDuration_loop(s32, f32);
extern void func_8029AD68(f32, s32);

/* .data */
f32 D_80364CF0 = 30.0f;
f32 D_80364CF4 = 500.0f;
f32 D_80364CF8 = 0.44f;
f32 D_80364CFC = 0.2f;
f32 D_80364D00 = 693.5f;
f32 D_80364D04 = -1200.0f;
u8  D_80364D08 = 0;
s16 D_80364D0C[] = {
    SFX_54_BANJO_HOO_1,
    SFX_55_BANJO_HOO_2,
    SFX_56_BANJO_HUI
}; //enum sfx_e

/* .bss */
u8  D_8037D4E0;
s32 D_8037D4E4;
f32 D_8037D4E8[3];
f32 D_8037D4F4;

/* .code */
void func_802B21D0(void) {
    func_8030EB00(D_80364D0C[D_80364D08], 1.35f, 1.45f);
    D_80364D08++;
    if (D_80364D08 >= 3) {
        D_80364D08 = 0;
    }
}


void func_802B223C(void) {
    f32 sp1C;

    sp1C = func_8029B30C();
    if (func_8029B300() == 0) {
        func_80297970(0.0f);
        return;
    }
    func_80297970(ml_interpolate_f(sp1C, D_80364CF0, D_80364CF4));
}

void func_802B229C(void) {
    if (!bspumpkin_inSet(bs_getNextState())) {
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        miscflag_clear(3);
        miscflag_clear(4);
        func_80293D74();
    }
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
}

int bspumpkin_inSet(s32 move_indx){
    return (move_indx == BS_48_PUMPKIN_IDLE)
    || (move_indx == BS_49_PUMPKIN_WALK)
    || (move_indx == BS_4A_PUMPKIN_JUMP)
    || (move_indx == BS_4B_PUMPKIN_FALL)
    || (move_indx == BS_4D_PUMPKIN_OW)
    || (move_indx == BS_4E_PUMPKIN_DIE)
    || (move_indx == BS_8F_PUMPKIN_LOCKED)
    || (move_indx == BS_93_PUMPKIN_DRONE);
}

void bspumpkin_idle_init(void) {
    baanim_playForDuration_loop(ASSET_A0_ANIM_BSPUMPKIN_WALK, 0.8f);
    func_8029C7F4(1, 1, 1, 2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80293D48(50.0f, 25.0f);
    miscflag_set(3);
    miscflag_set(4);
    func_802900B4();
}

void bspumpkin_idle_update(void) {
    s32 next_state;

    next_state = 0;
    if (func_8028B094()) {
        next_state = BS_4B_PUMPKIN_FALL;
    }
    if (func_80294F78()) {
        next_state = func_802926C0();
    }
    if (func_8029B300() > 0) {
        next_state = BS_49_PUMPKIN_WALK;
    }
    if (button_pressed(BUTTON_A)) {
        next_state = BS_4A_PUMPKIN_JUMP;
    }
    bs_setState(next_state);
}


void bspumpkin_idle_end(void){
    func_802B229C();
    func_802900FC();
}

void bspumpkin_walk_init(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, ASSET_A0_ANIM_BSPUMPKIN_WALK);
    animctrl_setDuration(anim_ctrl, 0.8f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
    animctrl_start(anim_ctrl, "bspumpkin.c", 0x11D);
    func_8029C7F4(2, 1, 1, 2);
    baanim_setVelocityMapRanges(D_80364CF0, D_80364CF4, D_80364CF8, D_80364CFC);
    func_802900B4();
}


void bspumpkin_walk_update(void) {
    s32 next_state;

    next_state = 0;
    func_802B223C();
    func_8029AD68(0.3f, 4);
    if ((func_8029B300() == 0) && func_80297C04(1.0f)) {
        next_state = BS_48_PUMPKIN_IDLE;
    }
    if (func_8028B094()) {
        next_state = BS_4B_PUMPKIN_FALL;
    }
    if (button_pressed(BUTTON_A)) {
        next_state = BS_4A_PUMPKIN_JUMP;
    }
    bs_setState(next_state);
}

void bspumpkin_walk_end(void){
    func_802B229C();
    func_802900FC();
}

void bspumpkin_jump_init(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, ASSET_A1_ANIM_BSPUMPKIN_JUMP);
    animctrl_setSubRange(anim_ctrl, 0.0f, 0.3941f);
    animctrl_setDuration(anim_ctrl, 1.2f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    animctrl_start(anim_ctrl, "bspumpkin.c", 0x16C);
    func_8029C7F4(1, 1, 3, 6);
    if (func_8029B2E8() != 0.0f) {
        yaw_setIdeal(func_8029B33C());
    }
    func_8029797C(yaw_getIdeal());
    func_802B223C();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364D00);
    gravity_set(D_80364D04);
    func_802B21D0();
    D_8037D4E0 = 0;
}

void bspumpkin_jump_update(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 sp1C[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_802B223C();
    _get_velocity(sp1C);
    if (button_released(BUTTON_A) && sp1C[1] > 0.0f) {
        gravity_reset();
    }
    switch (D_8037D4E0) {
    case 0:
        if (_get_vertVelocity() < 0.0f) {
            if (func_8028B254(130)) {
                func_80292E48();
                animctrl_setDuration(anim_ctrl, 0.7f);
                animctrl_setSubRange(anim_ctrl, 0.0f, 0.8059f);
                animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
                D_8037D4E0 = 2;
            } else {
                animctrl_setSubRange(anim_ctrl, 0.0f, 0.662f);
                animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
                D_8037D4E0 = 1;
            }
        }
        break;
    case 1:
        if (func_8028B254(130)) {
            func_80292E48();
            animctrl_setSubRange(anim_ctrl, 0.0f, 0.8059f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4E0 = 2;
        }
        break;
    case 2:
        if (func_8028B2E8()) {
            func_8029AE48();
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 1.2f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4E0 = 3;
        }
        break;
    case 3:
        if (animctrl_isStopped(anim_ctrl)) {
            func_80292EA4();
            func_80297970(0.0f);
            next_state = BS_48_PUMPKIN_IDLE;
        }
        break;
    }
    if (func_8028B2E8()) {
        if (func_8029B300() > 0) {
            next_state = BS_49_PUMPKIN_WALK;
        }
        if (button_pressed(BUTTON_A)) {
            next_state = BS_4A_PUMPKIN_JUMP;
        }
    }
    bs_setState(next_state);
}

void bspumpkin_jump_end(void){
    func_80292EA4();
    gravity_reset();
    func_802B229C();
}

void bspumpkin_fall_init(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    D_8037D4E4 = 0;
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, ASSET_A1_ANIM_BSPUMPKIN_JUMP);
    animctrl_setStart(anim_ctrl, 0.662f);
    animctrl_setDuration(anim_ctrl, 0.7f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_STOPPED);
    animctrl_start(anim_ctrl, "bspumpkin.c", 0x1F1);
    func_8029C7F4(1, 1, 3, 6);
    D_8037D4E0 = 0;
}


void bspumpkin_fall_update(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 sp1C[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if (D_8037D4E4) {
        func_802B223C();
    }
    _get_velocity(sp1C);
    switch (D_8037D4E0) {
    case 0:
        if (func_8028B254(130)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 0.8059f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4E0 = 1;
        }
        break;
    case 1:
        if (func_8028B2E8()) {
            func_8029AE48();
            func_80297970(0.0f);
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 1.2f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4E0 = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_8028B2E8() && ((func_8029B300() > 0) || (D_8037D4E0 == 2 && animctrl_isStopped(anim_ctrl)))) {
        if (miscflag_isTrue(0x19)) {
            next_state = func_80292738();
        } else {
            next_state = BS_48_PUMPKIN_IDLE;
        }
    }
    bs_setState(next_state);
}

void bspumpkin_fall_end(void){
    func_802B229C();
}

void func_802B2BF0(void) {
    func_8029656C(D_8037D4E8);
    func_8028FAB0(D_8037D4E8);
    baanim_playForDuration_loop(ASSET_A0_ANIM_BSPUMPKIN_WALK, 0.8f);
    func_8029C7F4(1, 1, 2, 7);
    func_80294378(6);
    func_8029E3C0(0, 0.0f);
}

void func_802B2C58(void) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp28[3];

    func_8029E22C(0);
    sp34 = func_8029E270(0);
    sp38 = yaw_getIdeal();
    sp3C = ml_map_f(sp34, 0.0f, 2.3f, 0.0f, 45.0f);
    yaw_setIdeal(mlNormalizeAngle(sp38 + sp3C));
    yaw_applyIdeal();
    baModel_setScale(ml_map_f(sp34, 0.0f, 2.3f, 1.0f, 0.3f));
    ml_vec3f_copy(sp28, D_8037D4E8);
    sp28[1] = ml_map_f(sp34, 0.0f, 2.3f, D_8037D4E8[1], D_8037D4E8[1] - 50.0);
    func_8028FAB0(sp28);
}

void func_802B2D50(void) {
    func_80294378(1);
    baModel_setScale(1.0f);
}

void __bspumpkin_bounce_init(s32 arg0) {
    AnimCtrl *anim_ctrl;
    f32 sp38;
    f32 plyr_pos[3];
    f32 sp20[3];

    anim_ctrl = baanim_getAnimCtrlPtr();
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, ASSET_236_ANIM_BSPUMPKIN_REBOUND);
    animctrl_setDuration(anim_ctrl, 1.3f);
    animctrl_setSubRange(anim_ctrl, 0.0f, 0.45f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    animctrl_start(anim_ctrl, "bspumpkin.c", 0x2AB);
    if (arg0 == 1) {
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    } else {
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    }
    _player_getPosition(plyr_pos);
    func_80294980(sp20);
    func_80257F18(sp20, plyr_pos, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    func_80297970(200.0f);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1, 1, 2, 3);
    player_setYVelocity(510.0f);
    gravity_set(-1200.0f);
    baMarker_collisionOff();
    func_80292E48();
    D_8037D4E0 = 0;
}

void __bspumpkin_bounce_update(void) {
    s32 next_state;

    next_state = 0;
    if (baanim_isAt(0.61f)) {
        func_80292EA4();
    }
    switch (D_8037D4E0) {
    case 0:
        if (func_8028B254(90)) {
            baanim_setEndAndDuration(1.0f, 0.5f);
            func_8029AE48();
            D_8037D4E0 = 1;
        }
        break;
    case 1:
        if (baanim_isStopped()) {
            next_state = BS_48_PUMPKIN_IDLE;
        }
        break;
    }
    bs_setState(next_state);
}

void __bspumpkin_bounce_end(void) {
    func_80297CA8();
    gravity_reset();
    baMarker_collisionOn();
    func_80292EA4();
    func_802B229C();
}

void __bspumpkin_ow_init(void){
    __bspumpkin_bounce_init(1);
}

void __bspumpkin_ow_update(void){
    __bspumpkin_bounce_update();
}

void __bspumpkin_ow_end(void){
    __bspumpkin_bounce_end();
}

void bspumpkin_rebound_init(void){
    __bspumpkin_bounce_init(2);
}

void bspumpkin_rebound_update(void){
    __bspumpkin_bounce_update();
}

void bspumpkin_rebound_end(void){
    __bspumpkin_bounce_end();
}

void bspumpkin_die_init(void) {
    AnimCtrl *anim_ctrl;
    f32 sp38;
    f32 plyr_pos[3];
    f32 sp20[3];

    anim_ctrl = baanim_getAnimCtrlPtr();
    func_8029B930();
    animctrl_reset(anim_ctrl);
    animctrl_setSmoothTransition(anim_ctrl, 0);
    animctrl_setIndex(anim_ctrl, ASSET_188_ANIM_BSPUMPKIN_DIE);
    animctrl_setSubRange(anim_ctrl, 0.0f, 0.1439f);
    animctrl_setDuration(anim_ctrl, 3.5f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    animctrl_start(anim_ctrl, "bspumpkin.c", 0x32E);
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    _player_getPosition(plyr_pos);
    func_80294980(sp20);
    func_80257F18(sp20, plyr_pos, &sp38);
    D_8037D4F4 = 250.0f;
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    func_80297970(D_8037D4F4);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1, 1, 2, 3);
    player_setYVelocity(510.0f);
    gravity_set(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_802914CC(0xD);
    func_802BF2C0(30.0f);
    func_8029C984();
    baMarker_collisionOff();
    func_80292E48();
    func_8029E3C0(1, 2.9f);
    D_8037D4E0 = 0;
}

void bspumpkin_die_update(void){
    func_80297970(D_8037D4F4);
    func_80299628(0);
    switch(D_8037D4E0){
    case 0://L802B3284
        if(func_8028B254(90)) {
            baanim_setEnd(0.1571f);
            D_8037D4E0 = 1;
        }
        break;

    case 1://L802B32AC
        if(func_8028B2E8()) {
            func_8029AE48();
            FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
            FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
            baanim_setEndAndDuration(0.2f, 2.9f);
            D_8037D4E0 = 2;
        }
        break;

    case 2://L802B3300
        if(baanim_isStopped()) {
            player_setYVelocity(400.0f);
            baanim_setEnd(0.355f);
            D_8037D4E0 = 3;
        }
        break;

    case 3://L802B3338
        D_8037D4F4 = ml_max_f(0.0f, D_8037D4F4 - 10.0f);
        if (func_8028B254(90)) {
            baanim_setEnd(0.36f);
            D_8037D4E0 = 4;
        }
        break;

    case 4://L802B3384
        D_8037D4F4 = ml_max_f(0.0f, D_8037D4F4 - 10.0f);
        if (func_8028B2E8()) {
            func_8029AE48();
            FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
            FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
            baanim_setEnd(1.0f);
            D_8037D4E0 = 5;
        }
        break;

    case 5://L802B33F4
        D_8037D4F4 = ml_max_f(0.0f, D_8037D4F4 - 10.0f);
        break;

    }
    if (func_8029E1A8(1) != 0) {
        func_8029B890();
    }
    bs_setState(0);
}

void bspumpkin_die_end(void) {
    func_802B229C();
    func_8024BD08(0);
    gravity_reset();
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80292EA4();
    func_80291548();
}

void func_802B34A0(void) {
    baanim_playForDuration_loopSmooth(0xA0, 0.8f);
    func_8029C7F4(1, 1, 3, 2);
    func_80297970(0.0f);
    func_8029C674();
    func_802B3A50();
}

void func_802B34F8(void) {
    s32 next_state;

    next_state = 0;
    func_802B3A50();
    func_8029C6D0();
    if (func_80298850() == 0) {
        next_state = BS_48_PUMPKIN_IDLE;
    }
    bs_setState(next_state);
}

void func_802B353C(void) {
    func_8029C748();
    func_802B229C();
}

void bspumpkin_drone_init(void){
    bsdrone_init();
}

void bspumpkin_drone_update(void){
    bsdrone_update();
}

void bspumpkin_drone_end(void){
    bsdrone_end();
    func_802B229C();
}
