#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

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

    anim_ctrl = baanim_getAnimCtrlPtr();
    if (anim_id == ASSET_14A_ANIM_BSREST_LISTEN) {
        func_8029E070(1);
        switch (animctrl_getIndex(baanim_getAnimCtrlPtr())) {
        case ASSET_14A_ANIM_BSREST_LISTEN:
            baanim_playForDuration_loopSmooth(anim_id, anim_duration);
            break;
        case ASSET_167_ANIM_BSREST_MOVE:
            animctrl_reset(anim_ctrl);
            animctrl_setIndex(anim_ctrl, ASSET_167_ANIM_BSREST_MOVE);
            animctrl_setDuration(anim_ctrl, 0.4f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            break;
        default:
            baanim_playForDuration_once(ASSET_167_ANIM_BSREST_MOVE, 0.5f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            break;
        }
    } else {
        baanim_playForDuration_loopSmooth(anim_id, anim_duration);
    }
    func_8029C7F4(1, 1, 3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802B3A50();
}


bool func_802B3BB0(void) {
    AnimCtrl *anim_ctrl;
    bool sp20;

    anim_ctrl = baanim_getAnimCtrlPtr();
    func_802B3A50();
    sp20 = FALSE;
    switch(animctrl_getIndex(anim_ctrl)){
        case ASSET_167_ANIM_BSREST_MOVE:
            if (baanim_isStopped() != 0) {
                if (animctrl_isPlayedForwards(anim_ctrl) != 0) {
                    baanim_playForDuration_loopSmooth(ASSET_14A_ANIM_BSREST_LISTEN, 11.4f);
                } else if (func_80298850() == 0) {
                    sp20 = TRUE;
                }
            }
            break;
        case ASSET_14A_ANIM_BSREST_LISTEN:
            if (func_80298850() == 0) {
                animctrl_reset(anim_ctrl);
                animctrl_setDirection(anim_ctrl, 0);
                animctrl_setIndex(anim_ctrl, 0x167);
                animctrl_setStart(anim_ctrl, 1.0f);
                animctrl_setDuration(anim_ctrl, 0.5f);
                animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
                animctrl_start(anim_ctrl, "bsrest.c", 0xA3);
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
        next_state = BS_77_SWIM_LOCKED;
    }
    if (func_802B3BB0() != 0) {
        next_state = bs_getIdleState();
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
        next_state = BS_77_SWIM_LOCKED;
    }
    if (func_802B3BB0() != 0) {
        next_state = bs_getIdleState();
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
        next_state = BS_77_SWIM_LOCKED;
    }
    if (func_802B3BB0()) {
        next_state = bs_getIdleState();
    }
    if (map_get() == MAP_27_FP_FREEZEEZY_PEAK && miscFlag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)) {
        next_state = func_8029CA94(next_state);
    }
    bs_setState(next_state);
}


void func_802B3EF4(void){
    func_802B3CCC();
    func_8029C748();
}
