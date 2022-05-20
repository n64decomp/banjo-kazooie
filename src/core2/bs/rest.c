#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802B3A50(void) {
    f32 sp34;
    f32 plyr_pos[3];
    f32 sp1C[3];

    if (func_80298850()) {
        _player_getPosition(plyr_pos);
        if (func_80298800(sp1C) && func_80257F18(plyr_pos, sp1C, &sp34)) {
            yaw_setIdeal(sp34);
        }
    }
}

void func_802B3AAC(enum asset_e anim_id, f32 anim_duration) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = _player_getAnimCtrlPtr();
    if (anim_id == 0x14A) {
        func_8029E070(1);
        switch (animctrl_getIndex(_player_getAnimCtrlPtr())) {
        case 0x14A:
            func_8028A010(anim_id, anim_duration);
            break;
        case 0x167:
            animctrl_reset(anim_ctrl);
            animctrl_setIndex(anim_ctrl, 0x167);
            animctrl_setDuration(anim_ctrl, 0.4f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            break;
        default:
            func_8028A180(0x167, 0.5f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            break;
        }
    } else {
        func_8028A010(anim_id, anim_duration);
    }
    func_8029C7F4(1, 1, 3, 2);
    func_80297970(0.0f);
    func_802B3A50();
}


bool func_802B3BB0(void) {
    AnimCtrl *anim_ctrl;
    bool sp20;

    anim_ctrl = _player_getAnimCtrlPtr();
    func_802B3A50();
    sp20 = FALSE;
    switch(animctrl_getIndex(anim_ctrl)){
        case 0x167:
            if (baanim_isStopped() != 0) {
                if (animctrl_isPlayedForwards(anim_ctrl) != 0) {
                    func_8028A010(0x14A, 11.4f);
                } else if (func_80298850() == 0) {
                    sp20 = TRUE;
                }
            }
            break;
        case 0x14A:
            if (func_80298850() == 0) {
                animctrl_reset(anim_ctrl);
                animctrl_setDirection(anim_ctrl, 0);
                animctrl_setIndex(anim_ctrl, 0x167);
                func_8028774C(anim_ctrl, 1.0f);
                animctrl_setDuration(anim_ctrl, 0.5f);
                animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
                _func_802875AC(anim_ctrl, "bsrest.c", 0xA3);
            }
            break;
        default:
            if (func_80298850() == 0) {
                sp20 = TRUE;
            }
            break;
    }
    return sp20;
}

void func_802B3CCC(void){ 
    func_8029E070(0);
}

void func_802B3CEC(void){ 
    enum asset_e anim_id;
    f32 anim_duration;
    
    func_8029BE10(&anim_id, &anim_duration);
    func_802B3AAC(anim_id, anim_duration);
}

void func_802B3D1C(void) {
    enum bs_e next_state;

    next_state = 0;
    if (player_inWater() != 0) {
        next_state = BS_77;
    }
    if (func_802B3BB0() != 0) {
        next_state = func_8029BF78();
    }
    bs_setState(next_state);
}

void func_802B3D6C(void){ 
    func_802B3CCC();
}

void func_802B3D8C(void){ 
    enum asset_e anim_id;
    f32 anim_duration;
    
    func_8029BF00(&anim_id, &anim_duration);
    func_802B3AAC(anim_id, anim_duration);
}


void func_802B3DBC(void) {
    enum bs_e next_state;

    next_state = 0;
    if (player_inWater() != 0) {
        next_state = BS_77;
    }
    if (func_802B3BB0() != 0) {
        next_state = func_8029BF78();
    }
    bs_setState(next_state);
}


void func_802B3E0C(void){ 
    func_802B3CCC();
}

void func_802B3E2C(void){ 
    enum asset_e anim_id;
    f32 anim_duration;
    
    func_8029BE88(&anim_id, &anim_duration);
    func_802B3AAC(anim_id, anim_duration);
    func_8029C674();
}

void func_802B3E64(void) {
    s32 next_state;

    next_state = 0;
    func_8029C6D0();
    if (player_inWater()) {
        next_state = BS_77;
    }
    if (func_802B3BB0()) {
        next_state = func_8029BF78();
    }
    if (map_get() == MAP_27_FP_FREEZEEZY_PEAK && func_802933C0(0x14)) {
        next_state = func_8029CA94(next_state);
    }
    bs_setState(next_state);
}


void func_802B3EF4(void){
    func_802B3CCC();
    func_8029C748();
}
