#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"
#include "core2/ba/anim.h"

#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

f32 func_80294438(void);
void func_80299B58(f32, f32);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);
void baanim_playForDuration_loop(s32, f32);

/* .data */
f32 D_80364CD0 =   710.0f;
f32 D_80364CD4 = -1350.0f;
f32 D_80364CD8 =     0.0f;
f32 D_80364CDC =   710.0f;
f32 D_80364CE0 = -1350.0f;
f32 D_80364CE4 =   610.0f;

/* .bss */
u8 D_8037D4C0;
u8 D_8037D4C1;
u8 D_8037D4C2;

/* .code */
void func_802B1100(void){
    func_80299B58(0.91f, 1.09f);
}

void bsjump_init(void){
    AnimCtrl *aCtrl =  baanim_getAnimCtrlPtr();
    enum bs_e sp30;

    D_8037D4C2 = miscFlag_isTrue(MISC_FLAG_2_ON_SPRING_PAD);
    sp30 = bs_getPrevState();
    if(bsclimb_inSet(sp30)){
        climbRelease();
    }

    if(sp30 == BS_11_BPECK){
        animctrl_setSubRange(aCtrl, 0.0f, 0.6667f);
        animctrl_setStart(aCtrl, 0.5042f);
        animctrl_setDuration(aCtrl, 8.0f);
        animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        D_8037D4C0 = 1;
    } 
    else {
        D_8037D4C1 = (sp30 == BS_2D_SWIM_IDLE) || (sp30 == BS_2E_SWIM);
        animctrl_reset(aCtrl);
        animctrl_setIndex(aCtrl, ASSET_8_ANIM_BSJUMP);
        animctrl_setDuration(aCtrl, 1.9f);
        animctrl_setTransitionDuration(aCtrl, 0.134f);
        animctrl_setStart(aCtrl, 0.3f);
        animctrl_setSubRange(aCtrl, 0.0f, 0.5042f);
        animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        animctrl_start(aCtrl, "bsjump.c", 0x95);
        func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
        if(func_8029B2E8() != 0.0f){
            yaw_setIdeal(func_8029B33C());
        }
        baphysics_set_target_yaw(yaw_getIdeal());
        func_802B6FA8();
        baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
        if(D_8037D4C1){
            baphysics_set_vertical_velocity(D_80364CE4);
        } else {
            baphysics_set_vertical_velocity(D_80364CD0);
        }
        baphysics_set_gravity(D_80364CD4);
        D_8037D4C0 = 0;
        if(D_8037D4C2){
            func_8030E6D4(SFX_33_BANJO_AHOO);
        } else{
            func_802B1100();
        }
    }//L802B1340
}

void bsjump_update(void){
    enum bs_e sp34 = 0;
    AnimCtrl *aCtrl =  baanim_getAnimCtrlPtr();
    f32 velocity[3];


    if(D_8037D4C2)
        func_8029C348();
    
    if(miscFlag_isTrue(MISC_FLAG_F)){
        baphysics_reset_horizontal_velocity();
    }else{
        func_802B6FA8();
    }

    baphysics_get_velocity(velocity);
    if((button_released(BUTTON_A) && 0.0f < velocity[1] && !D_8037D4C2) || !can_control_jump_height()){
        baphysics_reset_gravity();
    }

    switch(D_8037D4C0){
        case 0://L802B1428
            if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.6667);
                animctrl_setDuration(aCtrl, 4.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 1;
            }
            if(func_8028B254(0x82)){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.4f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 1://L802B14B4
            if( 500.0f < (player_getYPosition() - func_80294438())){
                sp34 = BS_2F_FALL;
            }
            if(D_8037D4C2){
                D_8037D4C2 = 0;
                sp34 = BS_BSHOCK_CHARGE;
            }
            if(func_8028B254(0x5A)){
                animctrl_setSubRange(aCtrl, 0.0, 1.0f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 2:
            break;
    }//L802B1548

    if(player_isFallTumbling())
        sp34 = BS_3D_FALL_TUMBLING;

    if(button_released(BUTTON_A))
        D_8037D4C2 = 0;

    if(should_feathery_flap())
        sp34 = BS_BFLAP;

    if(should_peck())
        sp34 = BS_11_BPECK;

    if(should_beak_bust())
        sp34 = BS_F_BBUSTER;

    if(player_isStable()){
        func_8029C5E8();
        sp34 = BS_20_LANDING;
    }

    if(velocity[1] < 0.0f && player_inWater())
        sp34 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp34);
}

void bsjump_end(void){
    if(ability_hasLearned(ABILITY_A_HOLD_A_JUMP_HIGHER))
        ability_use(0);

    if(bs_getNextState() != BS_11_BPECK)
        baphysics_reset_gravity();
}

void bsjump_fall_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    int sp20;

    if(miscFlag_isTrue(MISC_FLAG_7) && 700.0f < baphysics_get_vertical_velocity())
        baphysics_set_vertical_velocity(700.0f);

    sp20 = (bs_getPrevState() == BS_12_BFLIP)? 0 : 1;
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, sp20);
    animctrl_setIndex(aCtrl, ASSET_B0_ANIM_BSJUMP_FALL);
    animctrl_setTransitionDuration(aCtrl, 0.3f);
    animctrl_setDuration(aCtrl, 0.38f);
    animctrl_start(aCtrl, "bsjump.c", 0x188);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    D_8037D4C0 = 0;
}

void bsjump_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 player_velocity[3];

    if(miscFlag_isTrue(MISC_FLAG_F))
        baphysics_reset_horizontal_velocity();
    else
        func_802B6FA8();

    baphysics_get_velocity(player_velocity);

    switch(D_8037D4C0){
        case 0://L802B17B8
            if(func_8028B254(0x5a)){
                animctrl_reset(aCtrl);
                animctrl_setIndex(aCtrl, ASSET_8_ANIM_BSJUMP);
                animctrl_setStart(aCtrl, 0.6667f);
                animctrl_setDuration(aCtrl, 2.0f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                animctrl_start(aCtrl, "bsjump.c", 0x1b5);
                D_8037D4C0 = 1;
            }
            break;
        case 1:
            break;
    }//L802B1824
    if(miscFlag_isFalse(MISC_FLAG_F)){
        if(player_isFallTumbling())
            sp2C = BS_3D_FALL_TUMBLING;

        if(should_feathery_flap() && miscFlag_isFalse(MISC_FLAG_5_HAS_PECKED))
            sp2C = BS_BFLAP;

        if(should_peck())
            sp2C = BS_11_BPECK;
        
        if(should_beak_bust())
            sp2C = BS_F_BBUSTER;
        
        if(player_inWater())
            sp2C = BS_4C_LANDING_IN_WATER;
    }
    else if(player_inWater()){
        func_8029CCC4();
        if(miscFlag_isTrue(MISC_FLAG_6) || miscFlag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE)){
            sp2C = BS_D_TIMEOUT;
        }

    }//L802B18E8

    if(player_isStable()){
        func_8029C5E8();
        sp2C = BS_20_LANDING;
    }

    bs_setState(sp2C);
}

void bsjump_fall_end(void){}

void func_802B1928(void) {
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    climbRelease();
    animctrl_reset(anim_ctrl);
    animctrl_setIndex(anim_ctrl, ASSET_8_ANIM_BSJUMP);
    animctrl_setDuration(anim_ctrl, 1.9f);
    animctrl_setTransitionDuration(anim_ctrl, 0.134f);
    animctrl_setStart(anim_ctrl, 0.3f);
    animctrl_setSubRange(anim_ctrl, 0.0f, 0.5042f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    animctrl_start(anim_ctrl, "bsjump.c", 0x201);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(3);
    baphysics_set_type(BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_target_yaw(yaw_getIdeal());
    baphysics_set_target_horizontal_velocity(60.0f);
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_80364CDC);
    baphysics_set_gravity(D_80364CE0);
    func_80294378(6);
    D_8037D4C0 = 0;
    func_802B1100();
}

void func_802B1A54(void) {
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    baphysics_get_velocity(velocity);
    if (velocity[1] < 0.0f) {
        func_80294378(1);
    }
    switch (D_8037D4C0) {
    case 0:
        if (animctrl_isStopped(anim_ctrl)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 0.6667f);
            animctrl_setDuration(anim_ctrl, 4.0f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 1;
        }
        if (func_8028B254(130)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 1.4f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 2;
        }
        break;
    case 1:
        if (func_8028B254(90)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 2.0f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 2;
        }
        break;
    case 2:
        break;
    }
    if (player_isStable()) {
        func_8029C5E8();
        next_state = BS_20_LANDING;
    }
    bs_setState(next_state);
}

void func_802B1BCC(void){
    func_80294378(1);
    baphysics_reset_gravity();
}

void func_802B1BF4(void) {
    AnimCtrl *anim_ctrl;
    bool smooth_transition;

    anim_ctrl = baanim_getAnimCtrlPtr();
    smooth_transition = TRUE;
    if(bs_getPrevState() == BS_12_BFLIP){
        smooth_transition = FALSE;
    }
    animctrl_reset(anim_ctrl);
    animctrl_setSmoothTransition(anim_ctrl, smooth_transition);
    animctrl_setIndex(anim_ctrl, ASSET_8_ANIM_BSJUMP);
    animctrl_setTransitionDuration(anim_ctrl, 0.3f);
    animctrl_setDuration(anim_ctrl, 1.9f);
    animctrl_setStart(anim_ctrl, 0.6667f);
    animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_STOPPED);
    animctrl_start(anim_ctrl, "bsjump.c", 0x298);
    yaw_setIdeal(func_8029B41C());
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(1);
    func_8029957C(3);
    baphysics_set_type(BA_PHYSICS_AIRBORN);
    baphysics_set_target_horizontal_velocity(0.0f);
    baphysics_set_velocity(0);
    D_8037D4C0 = 0;
    baMarker_collisionOff();
}

void func_802B1CF8(void) {
    enum bs_e next_state;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    baphysics_get_velocity(velocity);
    switch (D_8037D4C0) {
    case 0:
        if (func_8028B254(90)) {
            animctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            animctrl_setDuration(anim_ctrl, 2.0f);
            animctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 1;
        }
        break;
    case 1:
        break;
    }
    if (player_isStable() != 0) {
        next_state = 1;
    }
    bs_setState(next_state);
}

void func_802B1DA4(void){
    baMarker_collisionOn();
}

bool bsjump_jumpingFromWater(void){
    return D_8037D4C1;
}

void bsjump_tumble_init(void){
    baanim_playForDuration_loop(ASSET_68_ANIM_BSJUMP_TUMBLE, 0.35f);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    baModel_setYDisplacement(60.0f);
    if(bafalldamage_get_state() == 1){
        batimer_set(0, 0.5f);
        batimer_set(1, 0.41f);
        func_80299CF4(SFX_52_BANJO_YAH_OH, 1.0f, 22000);
    }else{
        batimer_set(0, 0.0f);
        batimer_set(1, 0.01f);
    }
    D_8037D4C0 = 0;
}

void bsjump_tumble_update(void){
    enum bs_e sp1C = 0;
    if(batimer_decrement(1))
        func_80299CF4(SFX_63_BANJO_UWAAAAOOH, 1.0f, 32000);
    
    batimer_decrement(0);
    func_802B6FA8();
    if(batimer_isZero(1)){
        pitch_setIdeal(pitch_getIdeal() + 20.0f);
    }
    if(batimer_isNonzero(0)){
        if(should_feathery_flap())
            sp1C = BS_BFLAP;

        if(should_peck())
            sp1C = BS_11_BPECK;

        if(should_beak_bust())
            sp1C = BS_F_BBUSTER;
    }//L802B1F2C

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    if(player_isStable())
        sp1C = BS_SPLAT;

    bs_setState(sp1C);
}

void bsjump_tumble_end(void){
    enum bs_e next_state = bs_getNextState();
    if( next_state == BS_F_BBUSTER
        || next_state == BS_BFLAP
        || next_state == BS_11_BPECK
    ){
        bafalldamage_set_state(3);
    }
    func_8029CB84();
    baModel_setYDisplacement(0.0f);
    func_80299E6C();
}
