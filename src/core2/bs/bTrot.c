#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"
#include "core2/statetimer.h"


/* .data */
f32 D_80364A90 = 30.0f;
f32 D_80364A94 = 700.0f;
f32 D_80364A98 = 80.0f;
f32 D_80364A9C = 1000.0f;
f32 D_80364AA0 = 300.0f;
f32 D_80364AA4 = 0.56f;
f32 D_80364AA8 = 0.34f;
f32 D_80364AAC = 0.51f;
f32 D_80364AB0 = 0.29f;
f32 D_80364AB4 = 0.8f;
f32 D_80364AB8 = 0.7f;
f32 D_80364ABC = 693.5f;
f32 D_80364AC0 = -1200.0f;

/* .bss */
f32 D_8037D3A0;
u8  D_8037D3A4;

void func_802A87C0(void){
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_8029C3E8(10.0f, 50.0f);
    else
        func_8029C22C();
}

void func_802A880C(s32 arg0){
    if(arg0)
        func_8030E58C(SFX_49_KAZOOIE_RA, 0.96f);
    else
        func_8030E58C(SFX_49_KAZOOIE_RA, 1.04f);
}

void func_802A8850(void){
    if( button_pressed(BUTTON_B) 
        && stateTimer_isActive(STATE_TIMER_3_TURBO_TALON)
        && func_80297A64() == 0.0f
    ){
        stateTimer_clear(STATE_TIMER_3_TURBO_TALON);
    }

}

f32 func_802A88B0(void){
    if(func_8028B128())
        return D_80364AA0;

    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return D_80364A9C;

    return D_80364A94;
}

f32 func_802A8900(void){

    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return D_80364A98;

    return D_80364A90;
}

f32 func_802A8934(void){
    if(func_8028B128())
        return D_80364AB8;

    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return D_80364AB0;

    return D_80364AA8;
}

f32 func_802A8984(void){
    if(func_8028B128())
        return D_80364AB4;

    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return D_80364AAC;

    return D_80364AA4;
}

void func_802A89D4(void){
    f32 sp24 = func_8029B30C();
    if(!func_8029B300()){
        func_80297970(0.0f);
    }
    else{
        func_80297970(ml_interpolate_f(sp24, func_802A8900(), func_802A88B0()));
    }

}

void func_802A8A40(void){
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    func_8029E064(1);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    miscflag_set(3);
    func_8029CF48(4,1,0.24f);
    baModel_setDirection(PLAYER_MODEL_DIR_KAZOOIE);
}

void func_802A8AD8(void){
    func_80299650(stateTimer_getPrevious(STATE_TIMER_3_TURBO_TALON), stateTimer_get(STATE_TIMER_3_TURBO_TALON));
    if(miscflag_isTrue(MISC_FLAG_10_TOUCHING_TURBO_TRAINERS) &&(bs_getState() != BS_17_BTROT_EXIT)){
        miscflag_clear(MISC_FLAG_10_TOUCHING_TURBO_TRAINERS);
        stateTimer_set(STATE_TIMER_3_TURBO_TALON, func_80294A40());
        func_803219F4(4);
    }

    if(stateTimer_isDone(STATE_TIMER_3_TURBO_TALON)){
        if(func_8029DFE0()){
            func_8029E0DC(0);
            if(miscflag_isFalse(MISC_FLAG_14_LOSE_BOGGY_RACE))
                func_8030E484(0x3eb);
            func_803219F4(1);
        }
    }else{
        func_8029E0DC(1);
    }
}

void func_802A8BB0(void){
    enum bs_e next_state = bs_getNextState();
    
    if(bsbtrot_inSet(next_state))
        return;
    
    baModel_setDirection(PLAYER_MODEL_DIR_BANJO);
    func_8029B0C0();
    func_8029E070(0);
    func_8029E064(0);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    miscflag_clear(3);
    if(next_state != BS_5A_LOADZONE)
        stateTimer_set(STATE_TIMER_3_TURBO_TALON, 0.0f);
    func_802A8AD8();
    func_80289F10(1);
    func_8029CF48(4, 0, 0.0f);


}

int func_802A8C60(void){
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return 0;

    return button_released(BUTTON_Z);
}

void _bsbtrot_802A8C98(AnimCtrl *aCtrl, enum asset_e arg1){
    if(animctrl_getIndex(aCtrl) != arg1){
        animctrl_setIndex(aCtrl, arg1);
        func_8028774C(aCtrl, animctrl_getAnimTimer(aCtrl));
        func_802875AC(aCtrl, "bsbtrot.c", 0x12e);

    }
}

enum asset_e func_802A8D00(enum asset_e arg0, enum asset_e arg1){
    if(stateTimer_isDone(STATE_TIMER_3_TURBO_TALON))
        return arg0;
    else
        return arg1;
}

enum bs_e func_802A8D34(enum bs_e arg0){
    if(miscflag_isTrue(0xf))
        return arg0;
    
    if(miscflag_isTrue(MISC_FLAG_1_ON_FLIGHT_PAD)) 
        return BS_23_FLY_ENTER;

    return BS_8_BTROT_JUMP; 
}

enum bs_e func_802A8D84(enum bs_e arg0){
    if( func_8029B300(arg0) > 0)
        arg0 = BS_16_BTROT_WALK;

    if(func_80294F78())
        arg0 = func_802926C0();

    if(func_8028B094())
        arg0 = BS_71_BTROT_FALL;

    if(func_802A8C60())
        arg0 = BS_17_BTROT_EXIT;

    if(button_pressed(BUTTON_A))
        arg0 = func_802A8D34(arg0);

    if(player_shouldSlideTrot())
        arg0 = BS_45_BTROT_SLIDE;

    if(player_inWater())
        arg0 = BS_2D_SWIM_IDLE;

    return arg0;
}

void bsbtrot_enter_init(void){
    func_802A8AD8();
    func_8028A274(ASSET_16_ANIM_BSBTROT_ENTER, 1.0f);
    func_8029C7F4(1,1,2,2);
    func_80297970(0.0f);
    func_802A8A40();
    func_80299BD4();
    func_802952A8(0,0);
}

void bsbtrot_enter_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    func_802952A8(0,1);
    func_80299628(1);
    if(animctrl_isStopped(aCtrl))
        next_state = BS_15_BTROT_IDLE;

    if(0.5 <  animctrl_getAnimTimer(aCtrl))
        next_state = func_802A8D84(next_state);

    bs_setState(next_state);

}

void bsbtrot_enter_end(void){
    func_802952A8(0,1);
    func_802A8BB0();
}

void bsbtrot_stand_init(void){
    func_8028A010(ASSET_26_ANIM_BSBTROT_IDLE, 1.2f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    func_802A8A40();
}

void bsbtrot_stand_update(void){
    enum bs_e next_state = 0;;
    func_802A8850();
    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();
    func_80299628(1);
    next_state = func_802A8D84(next_state);
    next_state = func_8029CA94(next_state);
    bs_setState(next_state);

}

void bsbtrot_stand_end(void){
    func_802A8BB0();
}

enum asset_e func_802A9030(void){
    return func_802A8D00(ASSET_15_ANIM_BSBTROT_WALK, ASSET_44_ANIM_BSBTROT_TURBO_WALK);
}

void func_802A9054(void){
    f32 tmp = 1.0f;
    func_80289EC8(func_802A8900(), func_802A88B0(), func_802A8984(), func_802A8934());
    if(func_8028B394()){
        tmp = ml_map_f(func_80297AF0(), 0.0f, 1.0f, 0.6f, 0.9f);
        func_80289EF8(tmp);
    }
    else{
        func_80289EF8(tmp);
    }
}

void bsbtrot_walk_init(void){
    func_8028A010(func_802A9030(), 0.53f);
    func_8029C7F4(2,1,1,2);
    func_802A8A40();
    func_802A9054();
}

void bsbtrot_walk_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    func_802A8850();
    func_802A9054();
    func_802A8AD8();
    _bsbtrot_802A8C98(aCtrl, func_802A9030());
    func_80299628(1);
    func_802A89D4();
    if(animctrl_isAt(aCtrl, 0.2781f))
        func_802A880C(1);

    func_8029AD28(0.2781f, 4);
    if(animctrl_isAt(aCtrl, 0.7781f))
        func_802A880C(0);

    func_8029AD28(0.7781f, 3);
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON)){
        func_802A87C0();
    }
    else{
        if(animctrl_isAt(aCtrl, 0.2115f) || animctrl_isAt(aCtrl, 0.7115f))
            func_802A87C0();
    }
    if(!func_8029B300() && func_80297C04(1.0f))
        sp1C = BS_15_BTROT_IDLE;

    if(func_8028B094())
        sp1C = BS_71_BTROT_FALL;

    if(func_802A8C60())
        sp1C = BS_17_BTROT_EXIT;

    if(button_pressed(BUTTON_A))
        sp1C = func_802A8D34(sp1C);

    if(player_shouldSlideTrot())
        sp1C = BS_45_BTROT_SLIDE;

    if(player_inWater())
        sp1C = BS_2D_SWIM_IDLE;

    sp1C = func_8029CA94(sp1C);
    bs_setState(sp1C);
}

void bsbtrot_walk_end(void){
    func_802A8BB0();
}

void func_802A9320(void){}

void bsbtrot_jump_init(void){
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_27_ANIM_BSBTROR_JUMP);
    animctrl_setDuration(aCtrl, 1.4f);
    animctrl_setTransitionDuration(aCtrl, 0.1f);
    func_8028774C(aCtrl, 0.2f);
    animctrl_setSubRange(aCtrl, 0.0f,  0.4002f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsbtrot.c", 0x272);
    func_802A8A40();
    func_80289F10(1);
    yaw_setUpdateState(1);
    func_8029957C(3);
    func_802978DC(6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());

    func_8029797C(yaw_getIdeal());
    func_802A89D4();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364ABC);
    gravity_set(D_80364AC0);
    func_8030E484(SFX_48_KAZOOIE_RUUH);
    D_8037D3A4 = 0;
}

void bsbtrot_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];
    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();

    if(miscflag_isTrue(0xF))
        func_802978A4();
    else
        func_802A89D4();

    _get_velocity(sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        gravity_reset();
    
    switch(D_8037D3A4){
        case 0://L802A9530
            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.4653f);
                animctrl_setDuration(aCtrl, 10.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 1;
            }
            break;
        case 1://L802A9578
            if(func_8028B254(0x8C)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.7328f);
                animctrl_setDuration(aCtrl, 1.4f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 2;
            }
            break;
        case 2://L802A95C4
            func_80299628(1);
            if(func_8028B2E8()){
                func_8029C5E8();
                animctrl_setSubRange(aCtrl, 0.0f, 0.8798f);
                animctrl_setDuration(aCtrl, 0.9f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                func_8029957C(1);
                D_8037D3A4 = 3;
                if(220.0f < func_80297A64())
                    func_80299AAC();
                func_8029C22C();
            }
            break;
        case 3://L802A9660
            if(220.0f < func_80297A64())
                func_80299AAC();
            func_802A9320();
            func_80299628(1);
            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.8898f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 4;
            }
            func_8029C22C();
            break;
        case 4://L802A96F0
            if(220.0f < func_80297A64())
                func_80299AAC();
            
            func_802A9320();
            func_80299628(1);
            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.2f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 5;
            }
            func_8029C22C();
            break;
        case 5://L802A9780
            if(220.0f < func_80297A64())
                func_80299AAC();
            func_802A9320();
            func_80299628(1);
            if(animctrl_isStopped(aCtrl))
                sp2C = BS_15_BTROT_IDLE;
            break;
    }//LL802A97D0

    if(should_peck())
        sp2C = BS_11_BPECK;

    if(func_8028B424())
        sp2C = BS_3D_FALL_TUMBLING;

    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;
    
    if(func_8028B2E8()){
        if(button_pressed(BUTTON_A))
            sp2C = func_802A8D34(sp2C);
        
        if(player_shouldSlideTrot())
            sp2C = BS_45_BTROT_SLIDE;
    }

    bs_setState(sp2C);
}

void bsbtrot_jump_end(void){
    gravity_reset();
    func_802A8BB0();
}

void bsbtrot_exit_init(void){
    func_8028A274(ASSET_7_ANIM_BSBTROT_EXIT, 0.6f);
    func_80289F10(1);
    func_80297970(0.0f);
}

void bsbtrot_exit_update(void){
    enum bs_e sp1C = 0;
    if(animctrl_isStopped(_player_getAnimCtrlPtr()))
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

void bsbtrot_exit_end(void){
    func_802A8BB0();
}

void bsbtrot_slide_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_27_ANIM_BSBTROR_JUMP);
    func_8028774C(aCtrl, 0.069f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    func_802875AC(aCtrl, "bsbtrot.c", 0x382);
    func_802A8A40();
    func_8029C7F4(1,1,3,3);
    func_8029797C(yaw_getIdeal());
    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_8029E070(1);
    func_8029E064(1);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80297970(0.0f);
    func_80299AAC();
    D_8037D3A0 = 1.0f;
}

void bsbtrot_slide_update(void){
    enum bs_e sp3C = 0;
    f32 sp30[3];
    f32 sp2C;

    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();
    func_80299AAC();
    D_8037D3A0 = ml_max_f(D_8037D3A0-time_getDelta(), 0.0f);
    if(player_shouldSlideTrot()){
        func_80294480(sp30);
        func_8025801C(sp30, &sp2C);
        func_80299628(1);
        func_80297970(ml_map_f(pitch_getIdeal(), 20.0f, 60.0f, 550.0f, 700.0f));
        func_8029797C(sp2C);
        func_8029C22C();
    }else{
        sp3C = BS_15_BTROT_IDLE;
    }
    if(player_inWater())
        sp3C = BS_2D_SWIM_IDLE;

    if(D_8037D3A0 == 0.0f && button_pressed(BUTTON_A) && func_8028B2E8())
        sp3C = func_802A8D34(sp3C);
    

    bs_setState(sp3C);
}

void bsbtrot_slide_end(void){
    func_802A8BB0();
}

int bsbtrot_inSet(s32 move_indx){
    return (move_indx == BS_15_BTROT_IDLE)
    || (move_indx == BS_16_BTROT_WALK)
    || (move_indx == BS_8_BTROT_JUMP)
    || (move_indx == BS_17_BTROT_EXIT)
    || (move_indx == BS_45_BTROT_SLIDE)
    || (move_indx == BS_14_BTROT_ENTER)
    || (move_indx == 0x79)
    || (move_indx == BS_BTROT_OW)
    || (move_indx == BS_71_BTROT_FALL)
    || (move_indx == 0x9a);
}

void bsbtrot_fall_init(void){
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ASSET_27_ANIM_BSBTROR_JUMP);
    animctrl_setDuration(aCtrl, 1.4f);
    func_8028774C(aCtrl, 0.4653f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    func_802875AC(aCtrl, "bsbtrot.c", 0x400);
    func_802A8A40();
    func_8029C7F4(1,1,3,6);
    func_8029797C(yaw_getIdeal());
    func_802A89D4();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    D_8037D3A4 = 0;
}

void bsbtrot_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];
    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();

    if(miscflag_isTrue(0xf))
        func_802978A4();
    else
        func_802A89D4();

    _get_velocity(sp1C);
    switch (D_8037D3A4){
    case 0://L802A9D90
        if(func_8028B254(0x8C)){
            animctrl_setSubRange(aCtrl, 0.0f, 0.7328f);
            animctrl_setDuration(aCtrl, 1.4f);
            animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            D_8037D3A4 = 1;
        }
        break;
    case 1://L802A9DDC
        func_80299628(1);
        if(func_8028B2E8()){
            func_8029C5E8();
            animctrl_setSubRange(aCtrl, 0.0f, 0.8798f);
            animctrl_setDuration(aCtrl, 0.9f);
            animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            func_8029957C(1);
            if(220.0f < func_80297A64()){
                func_80299AAC();
            }
            func_8029C22C();
            D_8037D3A4 = 2;
        }
        break;
    case 2://L802A9E78
        if(220.0f < func_80297A64())
            func_80299AAC();
        
        func_802A9320();
        func_80299628(1);
        if(animctrl_isStopped(aCtrl)){
            animctrl_setSubRange(aCtrl, 0.0f, 0.8898f);
            animctrl_setDuration(aCtrl, 2.0f);
            animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            D_8037D3A4 = 3;
        }
        func_8029C22C();
        break;
    case 3://L802A9F08
        if(220.0f < func_80297A64())
            func_80299AAC();

        func_802A9320();
        func_80299628(1);
        if(animctrl_isStopped(aCtrl)){
            animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
            animctrl_setDuration(aCtrl, 1.2f);
            animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            D_8037D3A4 = 4;
        }
        func_8029C22C();
        break;
    case 4://802A9F98
        if(220.0f < func_80297A64())
            func_80299AAC();
        
        func_802A9320();
        func_80299628(1);
        if(animctrl_isStopped(aCtrl))
            sp2C = BS_15_BTROT_IDLE;
        break;
    }//LL802A9FE8

    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;
    
    if(func_8028B424())
        sp2C = BS_3D_FALL_TUMBLING;

    if(func_8028B2E8()){
        if(button_pressed(BUTTON_A))
            sp2C = func_802A8D34(sp2C);

        if(player_shouldSlideTrot())
            sp2C = BS_45_BTROT_SLIDE;
    }

    bs_setState(sp2C);
}

void bsbtrot_fall_end(void){
    func_802A8BB0();
}

void bsbtrot_unk79_init(void){
    func_8028A010(ASSET_26_ANIM_BSBTROT_IDLE, 1.2f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_802A8A40();
    baModel_setDirection(PLAYER_MODEL_DIR_KAZOOIE);
    func_8029C674();
}

void bsbtrot_unk79_update(void){
    enum bs_e sp1C = 0;
    func_8029C6D0();
    func_802A8AD8();
    func_80299628(1);
    if(!func_80298850())
        sp1C = BS_15_BTROT_IDLE;
    bs_setState(sp1C);
}

void bsbtrot_unk79_end(void){
    func_8029C748();
    func_802A8BB0();
}

void bsbtrot_ow_init(void){
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_802A8A40();
    func_80298760(func_80296560());
    func_8028A274(ASSET_66_ANIM_BSBTROT_OW, 1.1f);
    func_80299BFC(1.0f);
    _player_getPosition(sp30);
    func_80294980(sp24);
    func_80257F18(sp24, sp30, &sp3C);
    yaw_setIdeal(mlNormalizeAngle(sp3C + 180.0f));\
    yaw_applyIdeal();
    func_80297970(func_802987D4());
    func_8029797C(sp3C);
    func_802979AC(sp3C, func_80297A64());
    func_8029C7F4(1,1,2,3);
    if(func_802987B4() == 2)
        func_802978DC(6);
    player_setYVelocity(func_802987C4());
    gravity_set(func_802987E4());
    baMarker_collisionOff();
    func_80292E48();
}

void bsbtrot_ow_update(void){
    enum bs_e sp1C = 0;
    if(func_802987B4() == 2)
        func_802B6FA8();

    if(baanim_isAt(0.3f))
        func_80292EA4();

    if(func_8028B424())
        sp1C = BS_3D_FALL_TUMBLING;

    if(func_8028B2E8() && baanim_isStopped())
        sp1C = BS_15_BTROT_IDLE;

    if(animctrl_isStopped(_player_getAnimCtrlPtr()) && player_inWater())
        sp1C = BS_2D_SWIM_IDLE;

    bs_setState(sp1C);
}

void bsbtrot_ow_end(void){
    func_80297CA8();
    gravity_reset();
    baMarker_collisionOn();
    func_80292EA4();
    func_802A8BB0();
}

void bsbtrot_drone_init(void){
    func_802A8AD8();
    func_802A8A40();
    bsdrone_init();
}

void bsbtrot_drone_update(void){
    bsdrone_update();
    func_802A8AD8();
}

void bsbtrot_drone_end(void){
    bsdrone_end();
    func_802A8BB0();
}
