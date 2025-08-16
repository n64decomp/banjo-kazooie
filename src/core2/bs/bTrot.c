#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"
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
    if( bakey_pressed(BUTTON_B) 
        && stateTimer_isActive(STATE_TIMER_3_TURBO_TALON)
        && baphysics_get_target_horizontal_velocity() == 0.0f
    ){
        stateTimer_clear(STATE_TIMER_3_TURBO_TALON);
    }

}

f32 func_802A88B0(void){
    if(player_isOnDangerousGround())
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
    if(player_isOnDangerousGround())
        return D_80364AB8;

    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return D_80364AB0;

    return D_80364AA8;
}

f32 func_802A8984(void){
    if(player_isOnDangerousGround())
        return D_80364AB4;

    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return D_80364AAC;

    return D_80364AA4;
}

void func_802A89D4(void){
    f32 sp24 = bastick_getZonePosition();
    if(!bastick_getZone()){
        baphysics_set_target_horizontal_velocity(0.0f);
    }
    else{
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp24, func_802A8900(), func_802A88B0()));
    }

}

void func_802A8A40(void){
    bastick_setZoneMax(0, 0.03f);
    bastick_setZoneMax(1, 1.0f);
    func_8029E070(1);
    func_8029E064(1);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    baflag_set(BA_FLAG_3);
    func_8029CF48(4,1,0.24f);
    baModel_setDirection(PLAYER_MODEL_DIR_KAZOOIE);
}

void func_802A8AD8(void){
    basfx_updateClockSfxSource(stateTimer_getPrevious(STATE_TIMER_3_TURBO_TALON), stateTimer_get(STATE_TIMER_3_TURBO_TALON));
    if(baflag_isTrue(BA_FLAG_10_TOUCHING_TURBO_TRAINERS) &&(bs_getState() != BS_17_BTROT_EXIT)){
        baflag_clear(BA_FLAG_10_TOUCHING_TURBO_TRAINERS);
        stateTimer_set(STATE_TIMER_3_TURBO_TALON, get_turbo_duration());
        func_803219F4(4);
    }

    if(stateTimer_isDone(STATE_TIMER_3_TURBO_TALON)){
        if(func_8029DFE0()){
            func_8029E0DC(0);
            if(baflag_isFalse(BA_FLAG_14_LOSE_BOGGY_RACE))
                sfxsource_playHighPriority(0x3eb);
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
    bastick_resetZones();
    func_8029E070(0);
    func_8029E064(0);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    baflag_clear(BA_FLAG_3);
    if(next_state != BS_5A_LOADZONE)
        stateTimer_set(STATE_TIMER_3_TURBO_TALON, 0.0f);
    func_802A8AD8();
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    func_8029CF48(4, 0, 0.0f);


}

int func_802A8C60(void){
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        return 0;

    return bakey_released(BUTTON_Z);
}

void _bsbtrot_802A8C98(AnimCtrl *aCtrl, enum asset_e arg1){
    if(anctrl_getIndex(aCtrl) != arg1){
        anctrl_setIndex(aCtrl, arg1);
        anctrl_setStart(aCtrl, anctrl_getAnimTimer(aCtrl));
        anctrl_start(aCtrl, "bsbtrot.c", 0x12e);

    }
}

enum asset_e func_802A8D00(enum asset_e arg0, enum asset_e arg1){
    if(stateTimer_isDone(STATE_TIMER_3_TURBO_TALON))
        return arg0;
    else
        return arg1;
}

enum bs_e func_802A8D34(enum bs_e arg0){
    if(baflag_isTrue(BA_FLAG_F))
        return arg0;
    
    if(baflag_isTrue(BA_FLAG_1_ON_FLIGHT_PAD)) 
        return BS_23_FLY_ENTER;

    return BS_8_BTROT_JUMP; 
}

enum bs_e func_802A8D84(enum bs_e arg0){
    if( bastick_getZone(arg0) > 0)
        arg0 = BS_16_BTROT_WALK;

    if(bainput_should_look_first_person_camera())
        arg0 = badrone_look();

    if(player_shouldFall())
        arg0 = BS_71_BTROT_FALL;

    if(func_802A8C60())
        arg0 = BS_17_BTROT_EXIT;

    if(bakey_pressed(BUTTON_A))
        arg0 = func_802A8D34(arg0);

    if(player_shouldSlideTrot())
        arg0 = BS_45_BTROT_SLIDE;

    if(player_inWater())
        arg0 = BS_2D_SWIM_IDLE;

    return arg0;
}

void bsbtrot_enter_init(void){
    func_802A8AD8();
    baanim_playForDuration_onceSmooth(ASSET_16_ANIM_BSBTROT_ENTER, 1.0f);
    func_8029C7F4(1,1,2, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802A8A40();
    basfx_80299BD4();
    bainput_enable(0,0);
}

void bsbtrot_enter_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    bainput_enable(0,1);
    func_80299628(1);
    if(anctrl_isStopped(aCtrl))
        next_state = BS_15_BTROT_IDLE;

    if(0.5 <  anctrl_getAnimTimer(aCtrl))
        next_state = func_802A8D84(next_state);

    bs_setState(next_state);

}

void bsbtrot_enter_end(void){
    bainput_enable(0,1);
    func_802A8BB0();
}

void bsbtrot_stand_init(void){
    baanim_playForDuration_loopSmooth(ASSET_26_ANIM_BSBTROT_IDLE, 1.2f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
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
    baanim_setVelocityMapRanges(func_802A8900(), func_802A88B0(), func_802A8984(), func_802A8934());
    if(func_8028B394()){
        tmp = ml_map_f(baphysics_get_horizontal_velocity_percentage(), 0.0f, 1.0f, 0.6f, 0.9f);
        baanim_scaleDuration(tmp);
    }
    else{
        baanim_scaleDuration(tmp);
    }
}

void bsbtrot_walk_init(void){
    baanim_playForDuration_loopSmooth(func_802A9030(), 0.53f);
    func_8029C7F4(2,1,1, BA_PHYSICS_NORMAL);
    func_802A8A40();
    func_802A9054();
}

void bsbtrot_walk_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();

    func_802A8850();
    func_802A9054();
    func_802A8AD8();
    _bsbtrot_802A8C98(aCtrl, func_802A9030());
    func_80299628(1);
    func_802A89D4();
    if(anctrl_isAt(aCtrl, 0.2781f))
        func_802A880C(1);

    func_8029AD28(0.2781f, 4);
    if(anctrl_isAt(aCtrl, 0.7781f))
        func_802A880C(0);

    func_8029AD28(0.7781f, 3);
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON)){
        func_802A87C0();
    }
    else{
        if(anctrl_isAt(aCtrl, 0.2115f) || anctrl_isAt(aCtrl, 0.7115f))
            func_802A87C0();
    }
    if(!bastick_getZone() && baphysics_is_slower_than(1.0f))
        sp1C = BS_15_BTROT_IDLE;

    if(player_shouldFall())
        sp1C = BS_71_BTROT_FALL;

    if(func_802A8C60())
        sp1C = BS_17_BTROT_EXIT;

    if(bakey_pressed(BUTTON_A))
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
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();

    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_27_ANIM_BSBTROR_JUMP);
    anctrl_setDuration(aCtrl, 1.4f);
    anctrl_setTransitionDuration(aCtrl, 0.1f);
    anctrl_setStart(aCtrl, 0.2f);
    anctrl_setSubRange(aCtrl, 0.0f,  0.4002f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsbtrot.c", 0x272);
    func_802A8A40();
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(3);
    baphysics_set_type(BA_PHYSICS_AIRBORN);
    if(bastick_distance() != 0.0f)
        yaw_setIdeal(bastick_getAngleRelativeToBanjo());

    baphysics_set_target_yaw(yaw_getIdeal());
    func_802A89D4();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364ABC);
    baphysics_set_gravity(D_80364AC0);
    sfxsource_playHighPriority(SFX_48_KAZOOIE_RUUH);
    D_8037D3A4 = 0;
}

void bsbtrot_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];
    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();

    if(baflag_isTrue(BA_FLAG_F))
        baphysics_reset_horizontal_velocity();
    else
        func_802A89D4();

    baphysics_get_velocity(sp1C);
    if(bakey_released(BUTTON_A) && 0.0f < sp1C[1])
        baphysics_reset_gravity();
    
    switch(D_8037D3A4){
        case 0://L802A9530
            if(anctrl_isStopped(aCtrl)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.4653f);
                anctrl_setDuration(aCtrl, 10.0f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 1;
            }
            break;
        case 1://L802A9578
            if(func_8028B254(0x8C)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.7328f);
                anctrl_setDuration(aCtrl, 1.4f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 2;
            }
            break;
        case 2://L802A95C4
            func_80299628(1);
            if(player_isStable()){
                func_8029C5E8();
                anctrl_setSubRange(aCtrl, 0.0f, 0.8798f);
                anctrl_setDuration(aCtrl, 0.9f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                func_8029957C(1);
                D_8037D3A4 = 3;
                if(220.0f < baphysics_get_target_horizontal_velocity())
                    basfx_80299AAC();
                func_8029C22C();
            }
            break;
        case 3://L802A9660
            if(220.0f < baphysics_get_target_horizontal_velocity())
                basfx_80299AAC();
            func_802A9320();
            func_80299628(1);
            if(anctrl_isStopped(aCtrl)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.8898f);
                anctrl_setDuration(aCtrl, 2.0f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 4;
            }
            func_8029C22C();
            break;
        case 4://L802A96F0
            if(220.0f < baphysics_get_target_horizontal_velocity())
                basfx_80299AAC();
            
            func_802A9320();
            func_80299628(1);
            if(anctrl_isStopped(aCtrl)){
                anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                anctrl_setDuration(aCtrl, 1.2f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D3A4 = 5;
            }
            func_8029C22C();
            break;
        case 5://L802A9780
            if(220.0f < baphysics_get_target_horizontal_velocity())
                basfx_80299AAC();
            func_802A9320();
            func_80299628(1);
            if(anctrl_isStopped(aCtrl))
                sp2C = BS_15_BTROT_IDLE;
            break;
    }//LL802A97D0

    if(bainput_should_peck())
        sp2C = BS_11_BPECK;

    if(player_isFallTumbling())
        sp2C = BS_3D_FALL_TUMBLING;

    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;
    
    if(player_isStable()){
        if(bakey_pressed(BUTTON_A))
            sp2C = func_802A8D34(sp2C);
        
        if(player_shouldSlideTrot())
            sp2C = BS_45_BTROT_SLIDE;
    }

    bs_setState(sp2C);
}

void bsbtrot_jump_end(void){
    baphysics_reset_gravity();
    func_802A8BB0();
}

void bsbtrot_exit_init(void){
    baanim_playForDuration_onceSmooth(ASSET_7_ANIM_BSBTROT_EXIT, 0.6f);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
}

void bsbtrot_exit_update(void){
    enum bs_e sp1C = 0;
    if(anctrl_isStopped(baanim_getAnimCtrlPtr()))
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

void bsbtrot_exit_end(void){
    func_802A8BB0();
}

void bsbtrot_slide_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_27_ANIM_BSBTROR_JUMP);
    anctrl_setStart(aCtrl, 0.069f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    anctrl_start(aCtrl, "bsbtrot.c", 0x382);
    func_802A8A40();
    func_8029C7F4(1,1,3, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    func_8029E070(1);
    func_8029E064(1);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(0.0f);
    basfx_80299AAC();
    D_8037D3A0 = 1.0f;
}

void bsbtrot_slide_update(void){
    enum bs_e sp3C = 0;
    f32 sp30[3];
    f32 sp2C;

    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();
    basfx_80299AAC();
    D_8037D3A0 = ml_max_f(D_8037D3A0-time_getDelta(), 0.0f);
    if(player_shouldSlideTrot()){
        func_80294480(sp30);
        func_8025801C(sp30, &sp2C);
        func_80299628(1);
        baphysics_set_target_horizontal_velocity(ml_map_f(pitch_getIdeal(), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(sp2C);
        func_8029C22C();
    }else{
        sp3C = BS_15_BTROT_IDLE;
    }
    if(player_inWater())
        sp3C = BS_2D_SWIM_IDLE;

    if(D_8037D3A0 == 0.0f && bakey_pressed(BUTTON_A) && player_isStable())
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
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_27_ANIM_BSBTROR_JUMP);
    anctrl_setDuration(aCtrl, 1.4f);
    anctrl_setStart(aCtrl, 0.4653f);
    anctrl_setPlaybackType(aCtrl,  ANIMCTRL_STOPPED);
    anctrl_start(aCtrl, "bsbtrot.c", 0x400);
    func_802A8A40();
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802A89D4();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    D_8037D3A4 = 0;
}

void bsbtrot_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 sp1C[3];
    func_802A8AD8();
    if(stateTimer_isActive(STATE_TIMER_3_TURBO_TALON))
        func_802A87C0();

    if(baflag_isTrue(BA_FLAG_F))
        baphysics_reset_horizontal_velocity();
    else
        func_802A89D4();

    baphysics_get_velocity(sp1C);
    switch (D_8037D3A4){
    case 0://L802A9D90
        if(func_8028B254(0x8C)){
            anctrl_setSubRange(aCtrl, 0.0f, 0.7328f);
            anctrl_setDuration(aCtrl, 1.4f);
            anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            D_8037D3A4 = 1;
        }
        break;
    case 1://L802A9DDC
        func_80299628(1);
        if(player_isStable()){
            func_8029C5E8();
            anctrl_setSubRange(aCtrl, 0.0f, 0.8798f);
            anctrl_setDuration(aCtrl, 0.9f);
            anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            func_8029957C(1);
            if(220.0f < baphysics_get_target_horizontal_velocity()){
                basfx_80299AAC();
            }
            func_8029C22C();
            D_8037D3A4 = 2;
        }
        break;
    case 2://L802A9E78
        if(220.0f < baphysics_get_target_horizontal_velocity())
            basfx_80299AAC();
        
        func_802A9320();
        func_80299628(1);
        if(anctrl_isStopped(aCtrl)){
            anctrl_setSubRange(aCtrl, 0.0f, 0.8898f);
            anctrl_setDuration(aCtrl, 2.0f);
            anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            D_8037D3A4 = 3;
        }
        func_8029C22C();
        break;
    case 3://L802A9F08
        if(220.0f < baphysics_get_target_horizontal_velocity())
            basfx_80299AAC();

        func_802A9320();
        func_80299628(1);
        if(anctrl_isStopped(aCtrl)){
            anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
            anctrl_setDuration(aCtrl, 1.2f);
            anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
            D_8037D3A4 = 4;
        }
        func_8029C22C();
        break;
    case 4://802A9F98
        if(220.0f < baphysics_get_target_horizontal_velocity())
            basfx_80299AAC();
        
        func_802A9320();
        func_80299628(1);
        if(anctrl_isStopped(aCtrl))
            sp2C = BS_15_BTROT_IDLE;
        break;
    }//LL802A9FE8

    if(player_inWater())
        sp2C = BS_4C_LANDING_IN_WATER;
    
    if(player_isFallTumbling())
        sp2C = BS_3D_FALL_TUMBLING;

    if(player_isStable()){
        if(bakey_pressed(BUTTON_A))
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
    baanim_playForDuration_loopSmooth(ASSET_26_ANIM_BSBTROT_IDLE, 1.2f);
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
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
    baanim_playForDuration_onceSmooth(ASSET_66_ANIM_BSBTROT_OW, 1.1f);
    basfx_playOwSfx(1.0f);
    _player_getPosition(sp30);
    func_80294980(sp24);
    func_80257F18(sp24, sp30, &sp3C);
    yaw_setIdeal(mlNormalizeAngle(sp3C + 180.0f));\
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(func_802987D4());
    baphysics_set_target_yaw(sp3C);
    baphysics_set_horizontal_velocity(sp3C, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    if(func_802987B4() == 2)
        baphysics_set_type(BA_PHYSICS_AIRBORN);
    baphysics_set_vertical_velocity(func_802987C4());
    baphysics_set_gravity(func_802987E4());
    baMarker_collisionOff();
    baeyes_close();
}

void bsbtrot_ow_update(void){
    enum bs_e sp1C = 0;
    if(func_802987B4() == 2)
        func_802B6FA8();

    if(baanim_isAt(0.3f))
        baeyes_open();

    if(player_isFallTumbling())
        sp1C = BS_3D_FALL_TUMBLING;

    if(player_isStable() && baanim_isStopped())
        sp1C = BS_15_BTROT_IDLE;

    if(anctrl_isStopped(baanim_getAnimCtrlPtr()) && player_inWater())
        sp1C = BS_2D_SWIM_IDLE;

    bs_setState(sp1C);
}

void bsbtrot_ow_end(void){
    bsiFrame_start();
    baphysics_reset_gravity();
    baMarker_collisionOn();
    baeyes_open();
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
