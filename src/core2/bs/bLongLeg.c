#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/model.h"
#include "core2/statetimer.h"


/* .data */
const f32 D_80364A40 = 80.0f;
const f32 D_80364A44 = 500.0f;
const f32 D_80364A48 = 1.0f;
const f32 D_80364A4C = 0.8f;
const f32 D_80364A50 = 400.0f;
const f32 D_80364A54 = -800.0f;

/* .bss */
f32 D_8037D350;
f32 D_8037D354;
f32 D_8037D358;
f32 D_8037D35C;
u8 D_8037D360;
u8 D_8037D361;

/* .code */
int func_802A51D0(void){
    if(func_8029D66C())
        return 0;
    return player_inWater();
}

void func_802A5208(int arg0){
    if(arg0)
        func_8030E5F4(SFX_49_KAZOOIE_RA, 0.88f);
    else
        func_8030E5F4(SFX_49_KAZOOIE_RA, 0.96f);
}

void func_802A524C(void){
    f32 sp1C = func_8029B30C();
    if(!func_8029B300())
        func_80297970(0.0f);
    else
        func_80297970(ml_interpolate_f(sp1C, D_80364A40, D_80364A44));
}

int bslongleg_inSet(s32 move_indx){
    return (move_indx == BS_26_LONGLEG_IDLE)
    || (move_indx == BS_LONGLEG_WALK)
    || (move_indx == BS_LONGLEG_JUMP)
    || (move_indx == BS_LONGLEG_EXIT)
    || (move_indx == BS_LONGLEG_SLIDE)
    || (move_indx == BS_9B_LONGLEG_DRONE)
    || (move_indx == BS_62_LONGLEG_LOCKED);
}

void func_802A531C(void){
    func_80299650(stateTimer_getPrevious(STATE_TIMER_2_LONGLEG), stateTimer_get(STATE_TIMER_2_LONGLEG));
    if(stateTimer_isAt(STATE_TIMER_2_LONGLEG, 0.01f))
        func_8030E484(SFX_3EB_UNKNOWN);
}

void func_802A5374(void){
    baModel_80292078(1, -50.0f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    func_8029E064(1);
    func_8029E0F4(1);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    miscflag_set(3);
}

void func_802A5404(void){
    if(bslongleg_inSet(bs_getNextState()))
        return;
    
    baModel_80292078(1,0);
    func_8029B0C0();
    func_8029E070(0);
    func_8029E064(0);
    func_8029E0F4(0);
    baModel_setDirection(PLAYER_MODEL_DIR_BANJO);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    stateTimer_clear(STATE_TIMER_2_LONGLEG);
    func_803219F4(1);
    miscflag_clear(3);
    func_8029E180(4, 0.5f);
    func_802A531C();
}

void __bsblongleg_enterFromTrot(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_40_ANIM_BSLONGLEG_ENTER_FROM_BTROT);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsblongleg.c", 0xe1);
    stateTimer_set(STATE_TIMER_2_LONGLEG, D_8037D35C);
    func_803219F4(2);
    func_8030E2C4(D_8037D361);
    D_8037D360 = 1;
}

void __bsblongleg_enter(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_16_ANIM_BSBTROT_ENTER);
    animctrl_setDuration(aCtrl, 0.5f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsblongleg.c", 0xf6);
    D_8037D360 = 0;
}

void bsblongleg_enter_init(void){
    D_8037D361 = func_8030D90C();
    sfxsource_setSfxId(D_8037D361, SFX_2C_PULLING_NOISE);
    func_8030E04C(D_8037D361, 0.8f, 1.9f, 1.2f);
    miscflag_clear(MISC_FLAG_E_TOUCHING_WADING_BOOTS);
    if(bsbtrot_inSet(bs_getPrevState()))
        __bsblongleg_enterFromTrot();
    else
        __bsblongleg_enter();
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_802A5374();
    func_80299BD4();
}

void bsblongleg_enter_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    func_802A531C();
    func_80299594(1, 0.5f);
    switch(D_8037D360){
        case 0:
            if(animctrl_isStopped(aCtrl))
                __bsblongleg_enterFromTrot();
            break;
        case 1:
            if(animctrl_isStopped(aCtrl))
                next_state = BS_26_LONGLEG_IDLE;
            break;
    }
    bs_setState(next_state);
}

void bsblongleg_enter_end(void){
    func_802A5404();
    func_8030DA44(D_8037D361);
}

void bsblongleg_stand_enter(void){
    func_8028A010(ASSET_41_ANIM_BSLONGLEG_IDLE, 1.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    baModel_setDirection(PLAYER_MODEL_DIR_KAZOOIE);
    func_802A5374();
}

void bsblongleg_stand_update(void){
    enum bs_e next_state = 0;
    func_802A531C();
    func_80299594(1, 0.5f);
    if(func_80294F78())
        next_state = func_802926C0();

    if(button_pressed(BUTTON_B))
        stateTimer_clear(STATE_TIMER_2_LONGLEG);
    
    if(func_8029B300() > 0)
        next_state = BS_LONGLEG_WALK;
    
    if(player_shouldSlideTrot())
        next_state = BS_LONGLEG_SLIDE;
    
    if(button_pressed(BUTTON_A) && func_8028B2E8())
        next_state = BS_LONGLEG_JUMP;

    if(stateTimer_isDone(STATE_TIMER_2_LONGLEG))
        next_state = BS_LONGLEG_EXIT;

    if(func_802A51D0())
        next_state = BS_4C_LANDING_IN_WATER;

    bs_setState(next_state);

}

void bsblongleg_stand_end(void){
    func_802A5404();
}

void bsblongleg_walk_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_42_ANIM_BSLONGLEG_WALK);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
    func_802875AC(aCtrl, "bsblongleg.c", 0x1a1);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364A40, D_80364A44, D_80364A48, D_80364A4C);
}

void bsblongleg_walk_update(void){
    enum bs_e next_state = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    func_802A531C();
    func_80299594(1, 0.5f);
    func_8029AD28(0.47f, 4);
    func_8029AD28(0.97f, 3);
    if(animctrl_isAt(aCtrl, 0.7781f))
        func_802A5208(0);

    if(animctrl_isAt(aCtrl, 0.2781f))
        func_802A5208(1);
    
    func_802A524C();
    if(button_pressed(BUTTON_B) && func_80297A64() == 0.0f)
        stateTimer_clear(STATE_TIMER_2_LONGLEG);

    if(!func_8029B300() && func_80297C04(1.0f))
        next_state = BS_26_LONGLEG_IDLE;

    if(player_shouldSlideTrot())
        next_state = BS_LONGLEG_SLIDE;

    if(button_pressed(BUTTON_A) && func_8028B2E8())
        next_state = BS_LONGLEG_JUMP;

    if(stateTimer_isDone(STATE_TIMER_2_LONGLEG))
        next_state = BS_LONGLEG_EXIT;

    if(func_802A51D0())
        next_state = BS_4C_LANDING_IN_WATER;

    bs_setState(next_state);
}

void bsblongleg_walk_end(void){
    func_802A5404();
}

void func_802A5AB0(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setDirection(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_40_ANIM_BSLONGLEG_ENTER_FROM_BTROT);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsblongleg.c", 0x200);
    D_8037D360 = 0;
}

void func_802A5B34(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ASSET_7_ANIM_BSBTROT_EXIT);
    animctrl_setDuration(aCtrl, 0.6f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsblongleg.c", 0x210);
    D_8037D360 = 1;
}

void bsblongleg_exit_init(void){
    func_802A5AB0();
    func_80289F10(1);
    func_8029957C(2);
    func_80297970(0.0f);
    D_8037D361 = func_8030D90C();
    sfxsource_setSfxId(D_8037D361, SFX_2C_PULLING_NOISE);
    func_8030E04C(D_8037D361, 1.4f, 0.4f, -1.2f);
}

void bsblongleg_exit_update(void){
    enum bs_e next_state = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    func_802A531C();
    func_80299628(1);
    switch(D_8037D360){
        case 0://L802A5C7C
            if(animctrl_isAt(aCtrl, 0.68f))
                func_8030E2C4(D_8037D361);
            
            if(animctrl_isStopped(aCtrl))
                func_802A5B34();

            break;
        case 1://L802A5CB4
            if(animctrl_isStopped(aCtrl))
                next_state = BS_1_IDLE;
            break;
    }

    if(func_802A51D0())
        next_state = BS_4C_LANDING_IN_WATER;
    
    bs_setState(next_state);
    
}

void bsblongleg_exit_end(void){
    func_8030DA44(D_8037D361);
    func_802A5404();
}

void bsblongleg_jump_init(void){
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    D_8037D350 = 0.14f;
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_3D_ANIM_BSLONGLEG_JUMP);
    animctrl_setTransitionDuration(aCtrl, 0.134f);
    animctrl_setDuration(aCtrl, 1.0f);
    func_8028774C(aCtrl, D_8037D350);
    animctrl_setSubRange(aCtrl, 0.0f, 0.42f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsblongleg.c", 0x27F);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    func_8029797C(yaw_getIdeal());
    func_802A524C();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364A50);
    gravity_set(D_80364A54);
    func_8030E58C(SFX_48_KAZOOIE_RUUH, 0.9f);
    D_8037D360 = 0;
}

void bsblongleg_jump_update(void){
    enum bs_e sp44 = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    f32 sp34[3];
    f32 sp30;

    func_802A531C();
    func_802A524C();
    _get_velocity(&sp34);
    if(button_released(BUTTON_A) && 0.0f < sp34[1])
        gravity_reset();

    sp30 = player_getYPosition() - func_80294438();
    switch(D_8037D360){
        case 0://L802A5F24
            if((sp34[1] < 100.0f) || sp30 < 10.0f)
                animctrl_setDuration(aCtrl, 0.4f);

            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.5282f);
                animctrl_setDuration(aCtrl, 4.5f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D360 = 1;
            }
            break;
        case 1://L802A5FA8
            if((0.4 < animctrl_getAnimTimer(aCtrl)) && sp30  < 70.0f){
                D_8037D350 = animctrl_getAnimTimer(aCtrl);
                D_8037D354 = sp30;
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
                D_8037D360 = 2;
            }
            break;
        case 2://L802A6020
            animctrl_setAnimTimer(aCtrl, ml_map_f(sp30, D_8037D354, 1.0f, D_8037D350, 0.6703f));
            func_80299594(1, 0.5f);
            if(func_8028B2E8()){
                func_8029C5E8();
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.3f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D360 = 3;
            }
            break;
        case 3://L802A60AC
            func_80299594(1, 0.5f);
            if(animctrl_isStopped(aCtrl))
                sp44 = BS_26_LONGLEG_IDLE;

            if(button_pressed(BUTTON_A))
                sp44 = BS_LONGLEG_JUMP;

            if(stateTimer_isDone(STATE_TIMER_2_LONGLEG))
                sp44 = BS_LONGLEG_EXIT;

            break;
    }//L802A60F0


    if(func_802A51D0())
        sp44 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp44);
}

void bsblongleg_jump_end(void){
    gravity_reset();
    func_802A5404();
}

void bsblongleg_slide_init(void){
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_3D_ANIM_BSLONGLEG_JUMP);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    func_8028774C(aCtrl, 0.0865f);
    func_802875AC(aCtrl, "bsblongleg.c", 0x339);
    func_8029C7F4(1,1,3,3);
    func_8029797C(yaw_getIdeal());
    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_8029E070(1);
    func_8029E064(1);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80297970(0.0f);
    func_80299AAC();
    D_8037D358 = 1.0f;
}

void bsblongleg_slide_update(void){
    enum bs_e sp3C = 0;
    f32 sp30[3];
    f32 sp2C;

    func_802A531C();
    func_80299AAC();
    D_8037D358 = ml_max_f(D_8037D358 - time_getDelta(), 0.0f);

    if(player_isSliding()){
        func_80294480(sp30);
        func_8025801C(sp30, &sp2C);
        func_80299594(1, 0.5f);
        func_80297970(ml_map_f(pitch_getIdeal(), 20.0f, 60.0f, 550.0f, 700.0f));
        func_8029797C(sp2C);
        func_8029C22C();
    }else{//L802A6304
        sp3C = BS_26_LONGLEG_IDLE;
    }

    if(D_8037D358 == 0.0f && button_pressed(BUTTON_A))
        sp3C = BS_LONGLEG_JUMP;

    if(func_802A51D0())
        sp3C = BS_4C_LANDING_IN_WATER;

    bs_setState(sp3C);
}

void bsblongleg_slide_end(void){
    func_802A5404();
}

void func_802A6388(f32 arg0){
    D_8037D35C = arg0;
}

void func_802A6394(void){
    func_8028A010(ASSET_41_ANIM_BSLONGLEG_IDLE, 1.0f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_802A5374();
    baModel_setDirection(PLAYER_MODEL_DIR_KAZOOIE);
    func_8029C674();
}

void func_802A63F0(void){
    enum bs_e next_state = 0;
    func_802A531C();
    func_8029C6D0();
    func_80299628(1);
    
    if(func_80298850() == 0)
        next_state = BS_26_LONGLEG_IDLE;
    
    if(func_802A51D0())
        next_state = BS_4C_LANDING_IN_WATER;

    bs_setState(next_state);
}

void func_802A6450(void){
    func_8029C748();
    func_802A5404();
}

void bsblongleg_drone_init(void){
    func_802A5374();
    bsdrone_init();
}

void bsblongleg_drone_update(void){
    func_802A531C();
    bsdrone_update();
    if(stateTimer_isDone(STATE_TIMER_2_LONGLEG))
        bs_setState(BS_LONGLEG_EXIT);
}

void bsblongleg_drone_end(void){
    bsdrone_end();
    func_802A5404();
}

