#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "animation.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"

void baanim_setDurationRange(f32, f32);
void func_802927E0(f32, f32);
f32 bastick_distance(void);
void func_8029AD28(f32, s32);
void baanim_scaleDuration(f32);
f32 bastick_getZonePosition(void);
void func_80299594(s32, f32);

// .data
f32 bsWalkMinCreepVelocity = 30.0f;//creep_min
f32 bsWalkCreepSlowWalkVelocityThreshold = 80.0f;//creep_max/slow_walk_min
f32 bsWalkSlowWalkWalkVelocityThreshold = 150.0f;//slow_walk_max/walk_min
f32 bsWalkWalkFastWalkVelocityThreshold = 225.0f;//walk_max/walk_fast_min
f32 bsWalkMaxFastWalkVelocity = 500.0f;//walk_fast_max
f32 bsWalkMinMudVelocity = 30.0f; //mud_min
f32 bsWalkMaxMudVelocity = 150.0f; //mud_max
f32 bsWalkSkidVelocity = 125.0f; 
f32 bsWalkSlowestSlowWalkDuration = 1.3f; //walk_slow
f32 bsWalkFastestSlowWalkDuration = 0.6f;
f32 bsWalkSlowestCreepDuration = 1.8f; //creep
f32 bsWalkFastestCreepDuration = 1.2f;
f32 bsWalkSlowestWalkDuration = 0.92f; //walk
f32 bsWalkFastestWalkDuration = 0.58f;
f32 bsWalkSlowestFastWalkDuration = 0.54f; //walk_fast
f32 bsWalkFastestFastWalkDuration = 0.44f;
f32 bsWalkSlowestMudDuration = 1.2f; //mud
f32 bsWalkFastestMudDuration = 0.9f;

// .bss (?)
f32 D_8037D5B0;

/*.code*/
void func_802B6D00(void){
    f32 sp1C;
    s32 sp18;

    sp1C = bastick_getZonePosition();
    sp18 = bastick_getZone();
    if(player_isOnDangerousGround()){
        if(sp18 == 0){
            baphysics_set_target_horizontal_velocity(0.0f);
        }else{//L802B6D48
            baphysics_set_target_horizontal_velocity(ml_interpolate_f(bastick_distance(), bsWalkMinMudVelocity, bsWalkMaxMudVelocity));
        }
    }
    else{//L802B6D78
        switch(sp18){
            case 0://802B6D98
                baphysics_set_target_horizontal_velocity(0.0f);
                break;
            case 1://802B6DAC
                baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsWalkMinCreepVelocity, bsWalkCreepSlowWalkVelocityThreshold));
                break;
            case 2://802B6DD0
                baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsWalkCreepSlowWalkVelocityThreshold, bsWalkSlowWalkWalkVelocityThreshold));
                break;
            case 3://802B6DF4
                baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsWalkSlowWalkWalkVelocityThreshold, bsWalkWalkFastWalkVelocityThreshold));
                break;
            case 4://802B6E18
                baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1C, bsWalkWalkFastWalkVelocityThreshold, bsWalkMaxFastWalkVelocity));
                break;
        }
    }//L802B6E34
}

void func_802B6E44(void){
    if(func_8028B394()){
        baanim_scaleDuration(ml_map_f(baphysics_get_horizontal_velocity_percentage(), 0.0f, 1.0f, 0.5f, 0.9f));
    }else{
        baanim_scaleDuration(1.0f);
    }

}

void func_802B6EB0(f32 arg0){
    D_8037D5B0 = arg0;
}

void func_802B6EBC(void){
   D_8037D5B0 = ml_max_f(0.0f, D_8037D5B0 - time_getDelta());
}

int func_802B6EF4(void){
    return D_8037D5B0 == 0.0f;
}

s32 func_802B6F20(s32 arg0){
    if(bakey_pressed(BUTTON_B)){
        if( bsWalkWalkFastWalkVelocityThreshold < baphysics_get_target_horizontal_velocity()){
            if(can_roll())
                arg0 = BS_ROLL;
        }else{//L802B6F74
            if(can_claw())
                arg0 = BS_CLAW;
        }
    }
    return arg0;
}

f32 func_802B6F9C(void){
    return bsWalkMaxFastWalkVelocity;
}

void func_802B6FA8(void){
    func_802B6D00();
}

void bswalk_creep_init(void){
    AnimCtrl * anim_ctrl = baanim_getAnimCtrlPtr();
    f32 start_position;

    if(bs_getPrevState() == BS_2_WALK_SLOW){
        start_position = anim_getTimer(anctrl_getAnimPtr(anim_ctrl));
    }else{
        start_position = 0.0f;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_2_ANIM_BSWALK_CREEP);
    anctrl_setDuration(anim_ctrl, 0.43f);
    anctrl_setStart(anim_ctrl, start_position);
    anctrl_setPlaybackType(anim_ctrl,  ANIMCTRL_LOOP);
    anctrl_start(anim_ctrl, "bswalk.c", 0xe4);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(bsWalkMinCreepVelocity, bsWalkCreepSlowWalkVelocityThreshold, bsWalkSlowestCreepDuration, bsWalkFastestCreepDuration);
}

void bswalk_creep_update(void){
    s32 next_state = 0;
    func_802B6E44();
    if(bastick_distance() == 0.0f){
        yaw_setIdeal(yaw_get());
    }

    func_8029AD28(0.47f, 4);
    func_8029AD28(0.97f, 3);
    func_802B6D00();
    switch(bastick_getZone()){
        case 0://L802B7160
            if(baphysics_is_slower_than(1.0f))
                next_state = BS_1_IDLE;
            break;
        case 2://L802B7180
            next_state = BS_2_WALK_SLOW;
            break;
        case 3://L802B7188
            next_state = BS_WALK;
            break;
        case 4:
            next_state = BS_4_WALK_FAST;
            break;
    }//L802B7194
    if(player_isOnDangerousGround())
        next_state = BS_WALK_MUD;

    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(player_shouldFall())
        next_state = BS_2F_FALL;

    if(bakey_held(BUTTON_Z))
        next_state = BS_CROUCH;

    next_state = func_802B6F20(next_state);

    if(bakey_pressed(BUTTON_A))
        next_state = bs_getTypeOfJump();

    if(player_isSliding())
        next_state = BS_SLIDE;
    
    next_state = func_8029CA94(next_state);

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void bswalk_slow_init(void){
    AnimCtrl * anim_ctrl = baanim_getAnimCtrlPtr();
    f32 start_position;

    if(bs_getPrevState() == 3){
        start_position = anim_getTimer(anctrl_getAnimPtr(anim_ctrl));
    }else{
        start_position = 0.0f;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_3_ANIM_BSWALK);
    anctrl_setDuration(anim_ctrl, 0.43f);
    anctrl_setStart(anim_ctrl, start_position);
    anctrl_setPlaybackType(anim_ctrl,  ANIMCTRL_LOOP);
    anctrl_start(anim_ctrl, "bswalk.c", 0x168);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(bsWalkCreepSlowWalkVelocityThreshold, bsWalkSlowWalkWalkVelocityThreshold, bsWalkSlowestSlowWalkDuration, bsWalkFastestSlowWalkDuration);
}

void bswalk_slow_upate(void){
    s32 next_state = 0;
    func_802B6E44();
    if(bastick_distance() == 0.0f){
        yaw_setIdeal(yaw_get());
    }

    func_8029AD28(0.4f, 4);
    func_8029AD28(0.9f, 3);
    func_802B6D00();
    switch(bastick_getZone()){
        case 0://L802B7160
            if(baphysics_is_slower_than(3.0f))
                next_state = BS_1_IDLE;
            break;
        case 1://L802B7180
            next_state = BS_WALK_CREEP;
            break;
        case 3://L802B7188
            next_state = BS_WALK;
            break;
        case 4:
            next_state = BS_4_WALK_FAST;
            break;
    }//L802B7194
    if(player_isOnDangerousGround())
        next_state = BS_WALK_MUD;

    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(player_shouldFall())
        next_state = BS_2F_FALL;

    if(bakey_held(BUTTON_Z))
        next_state = BS_CROUCH;

    next_state = func_802B6F20(next_state);

    if(bakey_pressed(BUTTON_A))
        next_state = bs_getTypeOfJump();

    if(player_isSliding())
        next_state = BS_SLIDE;
    
    next_state = func_8029CA94(next_state);

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void bswalk_init(void){
    AnimCtrl * anim_ctrl = baanim_getAnimCtrlPtr();
    f32 start_position = 0.0f;

    switch(bs_getPrevState()){
        default:
            start_position = 0.0f;
            break;
        case 2://slowwalk
        case 4://fastwalk
            start_position = anim_getTimer(anctrl_getAnimPtr(anim_ctrl));
            break;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_C_ANIM_BSWALK_RUN);
    anctrl_setDuration(anim_ctrl, 0.66f);
    anctrl_setTransitionDuration(anim_ctrl, 0.14f);
    anctrl_setStart(anim_ctrl, start_position);
    anctrl_setPlaybackType(anim_ctrl,  ANIMCTRL_LOOP);
    anctrl_start(anim_ctrl, "bswalk.c", 0x1ed);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(bsWalkSlowWalkWalkVelocityThreshold, bsWalkWalkFastWalkVelocityThreshold, bsWalkSlowestWalkDuration, bsWalkFastestWalkDuration);
    func_802B6EB0(0.3f);
}

void bswalk_update(void){
    s32 next_state = 0;
    func_802B6E44();
    func_8029AD28(0.4f, 4);
    func_8029AD28(0.9f, 3);
    func_802B6EBC();
    func_802B6D00();
    switch(bastick_getZone()){
        case 0:
        case 1:
        case 2:
            if(baphysics_is_slower_than(bsWalkSlowWalkWalkVelocityThreshold) && func_802B6EF4())
                next_state = BS_2_WALK_SLOW;
            break;
        case 4:
            next_state = BS_4_WALK_FAST;
            break;
    }//L802B76B8
    if(player_isOnDangerousGround())
        next_state = BS_WALK_MUD;

    if(func_8028B4C4() && bsWalkSkidVelocity < baphysics_get_horizontal_velocity()){
        next_state = BS_SKID;
    }

    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(player_shouldFall())
        next_state = BS_2F_FALL;

    if(bakey_held(BUTTON_Z))
        next_state = BS_CROUCH;

    next_state = func_802B6F20(next_state);

    if(bakey_pressed(BUTTON_A))
        next_state = bs_getTypeOfJump();

    if(player_isSliding())
        next_state = BS_SLIDE;
    
    next_state = func_8029CA94(next_state);

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void bswalk_fast_init(void){
    AnimCtrl * anim_ctrl = baanim_getAnimCtrlPtr();
    f32 sp28 = 0.0f;
    int sp24 = 1;
    
    switch(bs_getPrevState()){
        case 1:
        case 2://L802B780C
            if(baphysics_get_horizontal_velocity() < 200.0f){
                func_802927E0(0.0f, 0.0f);
            }
            break;
        case 0xc: //L802B7844
            sp24 = 0;
            break;
        case 3:
            sp28 = anim_getTimer(anctrl_getAnimPtr(anim_ctrl));

            break;
    }
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, sp24);
    anctrl_setIndex(anim_ctrl, ASSET_C_ANIM_BSWALK_RUN);
    anctrl_setDuration(anim_ctrl, 0.66f);
    anctrl_setTransitionDuration(anim_ctrl, 0.1f);
    anctrl_setStart(anim_ctrl, sp28);
    anctrl_setPlaybackType(anim_ctrl,  ANIMCTRL_LOOP);
    anctrl_start(anim_ctrl, "bswalk.c", 0x27d);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(bsWalkWalkFastWalkVelocityThreshold, bsWalkMaxFastWalkVelocity, bsWalkSlowestFastWalkDuration, bsWalkFastestFastWalkDuration);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_802B6EB0(0.3f);
    
}

void bswalk_fast_update(void){
    s32 next_state = 0;
    func_802B6E44();
    func_80299594(0, 0.5f);
    func_8029AD28(0.4f, 4);
    func_8029AD28(0.9f, 3);
    func_802B6EBC();
    func_802B6D00();
    switch(bastick_getZone()){
        case 0://L802B79EC
            if(baphysics_is_slower_than(18.0f))
                next_state = BS_1_IDLE;

            if(bainput_should_look_first_person_camera())
                next_state = badrone_look();
            
            break;
        case 1:
        case 2://L802B7A28
            if(baphysics_is_slower_than(bsWalkSlowWalkWalkVelocityThreshold))
                next_state = BS_2_WALK_SLOW;

            if(bainput_should_look_first_person_camera())
                next_state = badrone_look();

            break;
        case 3://L802B7A60
            if(baphysics_is_slower_than(bsWalkWalkFastWalkVelocityThreshold) && func_802B6EF4())
                next_state = BS_WALK;

            if(bainput_should_look_first_person_camera())
                next_state = badrone_look();
            break;
    }//L802B7AA4
    if(player_isOnDangerousGround())
        next_state = BS_WALK_MUD;

    if(func_8028B4C4() && bsWalkSkidVelocity < baphysics_get_horizontal_velocity()){
        next_state = BS_SKID;
    }

    if(player_shouldFall())
        next_state = BS_2F_FALL;

    if(bakey_held(BUTTON_Z))
        next_state = BS_CROUCH;

    next_state = func_802B6F20(next_state);

    if(bakey_pressed(BUTTON_A))
        next_state = bs_getTypeOfJump();

    if(player_isSliding())
        next_state = BS_SLIDE;
    
    next_state = func_8029CA94(next_state);

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void bswalk_fast_end(void){
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
}

void bswalk_mud_init(void){
    baanim_playForDuration_loopSmooth(ASSET_B_ANIM_BSWALK_MUD, 0.43f);
    func_8029C7F4(BAANIM_UPDATE_2_SCALE_HORZ,1,1, BA_PHYSICS_NORMAL);
    baanim_setDurationRange(0.3f, 1.5f);
    baanim_setVelocityMapRanges(bsWalkMinMudVelocity, bsWalkMaxMudVelocity, bsWalkSlowestMudDuration, bsWalkFastestMudDuration);
}

void bswalk_mud_update(void){
    s32 next_state = 0;
    func_802B6E44();
    func_8029AD28(0.4f, 4);
    func_8029AD28(0.9f, 3);
    func_802B6D00();
    if(!player_isOnDangerousGround())
        next_state = BS_2_WALK_SLOW;

    if(!bastick_getZone())
        next_state = BS_1_IDLE;

    if(bainput_should_look_first_person_camera())
        next_state = badrone_look();

    if(player_shouldFall())
        next_state = BS_2F_FALL;

    if(bakey_held(BUTTON_Z))
        next_state = BS_CROUCH;

    next_state = func_802B6F20(next_state);

    if(bakey_pressed(BUTTON_A))
        next_state = bs_getTypeOfJump();

    if(player_isSliding())
        next_state = BS_SLIDE;
    
    next_state = func_8029CA94(next_state);

    if(player_inWater())
        next_state = BS_2D_SWIM_IDLE;

    bs_setState(next_state);
}

void bswalk_drone_init(void){
    bsdrone_init();
    if(baanim_isAnimID(3)){
        baanim_setUpdateType(BAANIM_UPDATE_2_SCALE_HORZ);
        baanim_setDurationRange(0.3f, 1.5f);
        baanim_setVelocityMapRanges(bsWalkCreepSlowWalkVelocityThreshold, bsWalkSlowWalkWalkVelocityThreshold, bsWalkSlowestSlowWalkDuration, bsWalkFastestSlowWalkDuration);
    }
}

void bswalk_drone_update(void){
    bsdrone_update();
}

void bswalk_drone_end(void){
    bsdrone_end();
}
