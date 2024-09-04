#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"
#include "core2/statetimer.h"
#include "core2/ba/physics.h"

extern f32 func_8029B2E8(void);
void yaw_setVelocityBounded(f32, f32);

void animctrl_start(AnimCtrl *, char*, s32);

void func_802900B4(void);
void rumbleManager_80250D94(f32, f32, f32);

/* .data */
u8 D_80364D20[] = {
    0x8 | 0x1,
    0x8 | 0x2,
    0x8 | 0x4,
    0x10,
    0x8 | 0x1,
    0x8 | 0x1,
    0x8 | 0x2,
    0x8 | 0x1,
    0x20,
    0x8 | 0x1,
    0x8 | 0x2,
    0x8 | 0x4,
    0x10,
    0x8 | 0x1,
    0x8 | 0x1,
    0x8 | 0x2,
    0x8 | 0x1,
    0x10,
    0x8 | 0x1,
    0x8 | 0x2,
    0x20
};

//.bss
s32 D_8037D540;
u8  D_8037D544;

u32 func_802B4870(u32 arg0){
    if(++arg0 > 0x14)
        arg0 = 0;
    return arg0;
}

s32 func_802B488C(s32 arg0){
    s32 retVal = arg0;
    switch(func_8029B300()){
        case 1: //L802B48CC
            retVal = BS_WALK_CREEP;
            break;
        case 2: //L802B48D4
            retVal = BS_2_WALK_SLOW;
            break;
        case 3: //L802B48D4
            retVal = BS_WALK;
            break;
        case 4: //L802B48D4
            retVal = BS_4_WALK_FAST;
            break;
    }
    if(button_held(BUTTON_Z))
        retVal = BS_CROUCH;

    if(button_pressed(BUTTON_B) && can_claw())
        retVal = BS_CLAW;

    if(button_pressed(BUTTON_A))
        retVal = func_8029C780();

    if(func_80294F78())
        retVal = badrone_look();

    if(player_isSliding())
        retVal = BS_SLIDE;

    retVal = func_8029CA94(retVal);

    if(player_inWater())
        retVal = BS_2D_SWIM_IDLE;
    
    return retVal;
}

void bsstand_init(void){
    if(bsclimb_inSet(bs_getPrevState()))
        climbRelease();

    baanim_playForDuration_once(ASSET_6F_ANIM_BSSTAND_IDLE, 5.5f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802900B4();
    D_8037D540 = 0;
    D_8037D544 = 0;
}

void func_802B4A10(AnimCtrl *arg0){
    if(animctrl_isAt(arg0, 0.2057f)){ //(30/145)
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 1.8f, 16000);
        rumbleManager_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4A54

    if(animctrl_isAt(arg0, 0.2057f)) //(30/145)
        func_80292E48();
    //L802B4A78

    if(animctrl_isAt(arg0, 0.2555f)){ //(37/145)
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 1.8f, 16000);
        rumbleManager_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4AB0

    if(animctrl_isAt(arg0, 0.2896f)){ //(42/145)
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 1.8f, 16000);
        rumbleManager_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4AEC

    if(animctrl_isAt(arg0, 0.3f)){ //(43.5/145)?
        FUNC_8030E624(SFX_62_BANJO_ERGHH, 1.0f, 28000);
    }//L802B4B0C

    if(animctrl_isAt(arg0, 0.3607f)){
        func_80292EA4();
    }//L802B4B30

    if(animctrl_isAt(arg0, 0.4183f)){
        func_8030E58C(SFX_3F1_UNKNOWN, 1.6f);
    }//L802B4B50

    if(animctrl_isAt(arg0, 0.455f)){
        func_8030E58C(SFX_3F1_UNKNOWN, 1.45f);
    }//L802B4B74

    if(animctrl_isAt(arg0, 0.49f)){
        func_8030E58C(SFX_3F1_UNKNOWN, 1.4f);
    }//L802B4B98

    if(animctrl_isAt(arg0, 0.5397f)){
        func_802900D8();
    }//L802B4BBC

    if(animctrl_isAt(arg0, 0.6619f)){
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 1.8f, 16000);
        rumbleManager_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4BF4

    if(animctrl_isAt(arg0, 0.6688f))
        func_80292E48();
    //L802B4C18

    if(animctrl_isAt(arg0, 0.6964f)){
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 1.8f, 16000);
        rumbleManager_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4C50

    if(animctrl_isAt(arg0, 0.7747f))
        func_80292EA4();
    //L802B4C74

    if(animctrl_isAt(arg0, 0.7822f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 14000);
    }//L802B4C90

    if(animctrl_isAt(arg0, 0.8322f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 14000);
    }//L802B4CB0

    if(animctrl_isAt(arg0, 0.8669f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 14000);
    }//L802B4CD0

    if(animctrl_isAt(arg0, 0.9048f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 14000);
    }//L802B4CF0

    if(animctrl_isAt(arg0, 0.9649f)){
        func_802900D8();
    }//L802B4CF0
}

void bsstand_update(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 sp1C;
    s32 sp18;

    anim_ctrl = baanim_getAnimCtrlPtr();
    if ((func_8029B300() == 0) && (func_8029B2E8() > 0.0f)) {
        D_8037D544 = 1;
        yaw_setUpdateState(3);
        yaw_setVelocityBounded(200.0f, 14.0f);
    } else {
        if (D_8037D544 != 0) {
            yaw_setIdeal(yaw_get());
        }
        D_8037D544 = 0;
        yaw_setUpdateState(1);
    }
    next_state = func_802B488C(0);
    sp18 = D_80364D20[D_8037D540];
    if (sp18 & 8) {
        if (sp18 & 4) {
            if (animctrl_isAt(anim_ctrl, 0.0909f)) func_80299BD4();
            if (animctrl_isAt(anim_ctrl, 0.0909f)) func_8029E070(1);
            if (animctrl_isAt(anim_ctrl, 0.6818f)) func_8029E070(0);
        }//L802B4E70
        if (sp18 & 2) {
            if (animctrl_isAt(anim_ctrl, 0.7727f)) func_8029E070(1);
            if (animctrl_isAt(anim_ctrl, 0.9999f)) func_8029E070(0);
        }//L802B50E4
    } else if (sp18 & 0x20) {
        if (animctrl_getIndex(anim_ctrl) == ASSET_95_ANIM_BSSTAND_KAZOOIE_PECK) {
            func_802B4A10(anim_ctrl);
            if (animctrl_isAt(anim_ctrl, 0.37f)) {
                animctrl_reset(anim_ctrl);
                animctrl_setTransitionDuration(anim_ctrl, 0.1f);
                animctrl_setIndex(anim_ctrl, ASSET_F6_ANIM_BSSTAND_PULL_KAZOOIE);
                animctrl_setDuration(anim_ctrl, 5.0f);
                animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
                animctrl_start(anim_ctrl, "bsstand.c", 0x170);
            }
        } else {
            if (animctrl_isAt(anim_ctrl, 0.069f))  func_80299D2C(SFX_4B_GULPING, 1.4f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.1677f)) func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.0f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.2441f)) func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.03f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.3141f)) func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.06f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.3859f)) func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.5f, 0x7D00);
            if (animctrl_isAt(anim_ctrl, 0.414f))  func_80299CF4(SFX_2D_KABOING, 1.0f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.55f))   func_80299CF4(SFX_A3_BANJO_DOUBLE_COUGH, 1.0f, 0x6D60);
            if (animctrl_isAt(anim_ctrl, 0.6187f)) func_80299D2C(SFX_A0_COUGHING, 1.7f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.7108f)) func_80299D2C(SFX_A0_COUGHING, 1.6f, 0x4650);
            if (animctrl_isAt(anim_ctrl, 0.7927f)) func_80299D2C(SFX_A0_COUGHING, 1.5f, 0x4650);
        }
    } else /*L802B50D4*/if ((sp18 & 0x10) != 0) {
        func_802B4A10(anim_ctrl);
    }
    if (animctrl_isAt(anim_ctrl, 0.9999f) != 0) {
        D_8037D540 = func_802B4870(D_8037D540);
        sp18 = D_80364D20[D_8037D540];
        if (sp18 & 0x10) {
            baanim_playForDuration_once(ASSET_95_ANIM_BSSTAND_KAZOOIE_PECK, 5.5f);
            animctrl_start(anim_ctrl, "bsstand.c", 0x1AB);
            func_8029E070(1);
            func_802900FC();
        } else if (sp18 & 0x20) {
            baanim_playForDuration_once(ASSET_95_ANIM_BSSTAND_KAZOOIE_PECK, 5.5f);
            func_8029E070(1);
            func_802900FC();
        } else if (sp18 & 8) {
            if (animctrl_getIndex(anim_ctrl) == ASSET_6F_ANIM_BSSTAND_IDLE) {
                sp1C = animctrl_getAnimTimer(anim_ctrl);
            } else {
                sp1C = 0.0f;
                func_802900B4();
            }
            animctrl_reset(anim_ctrl);
            animctrl_setIndex(anim_ctrl, ASSET_6F_ANIM_BSSTAND_IDLE);
            animctrl_setDuration(anim_ctrl, 5.5f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_LOOP);
            animctrl_setStart(anim_ctrl, sp1C);
            animctrl_start(anim_ctrl, "bsstand.c", 0x1C3);
            func_8029E070(0);
        }
    }
    if (func_8028B094() != 0) {
        next_state = BS_2F_FALL;
    }
    bs_setState(next_state);
}

void bsstand_end(void){
    func_8029E070(0);
    func_802900FC();
    func_80292EA4();
}

//bsStand_Land_init
void bsstand_landing_init(void){
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
}

//bsStand_Land_update
void bsstand_landing_update(void){
    s32 sp1C = 0;
    AnimCtrl * sp18 = baanim_getAnimCtrlPtr();

    if(animctrl_getIndex(sp18) == ASSET_D2_ANIM_BSSPLAT){
        if(animctrl_isAt(sp18, 0.8264f)){
            func_80299CF4(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 0x36b0);
        }

        //L802B52F8
        if(animctrl_isAt(sp18, 0.8864f)){
            func_80299CF4(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 0x36b0);
        }
    }
    //L802B531C
    if(animctrl_isStopped(sp18))
        sp1C = BS_1_IDLE;

    bs_setState(func_802B488C(sp1C));
}


///BREAK???
void func_802B5350(void){
    s32 sp1C = bs_getInterruptType();
    if(sp1C == BS_INTR_D_SURF){
        bs_setState(0x52);
    }
    if(sp1C == 0x7){
        if(bsStoredState_getTransformation() != TRANSFORM_1_BANJO)
            func_8029A86C(1);
        else{
            bacarry_set_marker(baMarker_8028D688());
            bs_setState(BS_3A_CARRY_IDLE);
        }
    }
    else if(sp1C == 0x12){//L802B53D0
        func_8029A86C(1);
        if( bsStoredState_getTransformation() == TRANSFORM_1_BANJO && !miscflag_isTrue(0xF) && stateTimer_isDone(STATE_TIMER_0_UNKNOWN)){
            func_8028DE6C(baMarker_getCarriedObjectActorId());
            func_8029A86C(2);
        }
    }
    else if(sp1C == 0x8){//L802B5438
        func_8029A86C(2);
        bs_setState(BS_3C_TALK);
    }else{
        bacarry_reset_marker();
        func_80296608();
    }
}
