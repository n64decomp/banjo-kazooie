#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/abilityprogress.h"

#include "core2/ba/model.h"
#include "core2/ba/anim.h"

#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

f32 func_80294438(void);
void basfx_playJumpSfx(f32, f32);
f32 bastick_distance(void);
f32 bastick_getAngleRelativeToBanjo(void);
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
    basfx_playJumpSfx(0.91f, 1.09f);
}

void bsjump_init(void){
    AnimCtrl *aCtrl =  baanim_getAnimCtrlPtr();
    enum bs_e sp30;

    D_8037D4C2 = baflag_isTrue(BA_FLAG_2_ON_SPRING_PAD);
    sp30 = bs_getPrevState();
    if(bsclimb_inSet(sp30)){
        climbRelease();
    }

    if(sp30 == BS_11_BPECK){
        anctrl_setSubRange(aCtrl, 0.0f, 0.6667f);
        anctrl_setStart(aCtrl, 0.5042f);
        anctrl_setDuration(aCtrl, 8.0f);
        anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        D_8037D4C0 = 1;
    } 
    else {
        D_8037D4C1 = (sp30 == BS_2D_SWIM_IDLE) || (sp30 == BS_2E_SWIM);
        anctrl_reset(aCtrl);
        anctrl_setIndex(aCtrl, ASSET_8_ANIM_BSJUMP);
        anctrl_setDuration(aCtrl, 1.9f);
        anctrl_setTransitionDuration(aCtrl, 0.134f);
        anctrl_setStart(aCtrl, 0.3f);
        anctrl_setSubRange(aCtrl, 0.0f, 0.5042f);
        anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
        anctrl_start(aCtrl, "bsjump.c", 0x95);
        func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
        if(bastick_distance() != 0.0f){
            yaw_setIdeal(bastick_getAngleRelativeToBanjo());
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
    
    if(baflag_isTrue(BA_FLAG_F)){
        baphysics_reset_horizontal_velocity();
    }else{
        func_802B6FA8();
    }

    baphysics_get_velocity(velocity);
    if((bakey_released(BUTTON_A) && 0.0f < velocity[1] && !D_8037D4C2) || !can_control_jump_height()){
        baphysics_reset_gravity();
    }

    switch(D_8037D4C0){
        case 0://L802B1428
            if(anctrl_isStopped(aCtrl)){
                anctrl_setSubRange(aCtrl, 0.0f, 0.6667);
                anctrl_setDuration(aCtrl, 4.0f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 1;
            }
            if(func_8028B254(0x82)){
                anctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                anctrl_setDuration(aCtrl, 1.4f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
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
                anctrl_setSubRange(aCtrl, 0.0, 1.0f);
                anctrl_setDuration(aCtrl, 2.0f);
                anctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                D_8037D4C0 = 2;
            }
            break;
        case 2:
            break;
    }//L802B1548

    if(player_isFallTumbling())
        sp34 = BS_3D_FALL_TUMBLING;

    if(bakey_released(BUTTON_A))
        D_8037D4C2 = 0;

    if(bainput_should_feathery_flap())
        sp34 = BS_BFLAP;

    if(bainput_should_peck())
        sp34 = BS_11_BPECK;

    if(bainput_should_beak_bust())
        sp34 = BS_F_BBUSTER;

    if(player_isStable()){
        func_8029C5E8();
        sp34 = BS_20_LANDING;
    }

    if(velocity[1] < 0.0f && player_inWater())
        sp34 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp34);
}

void bsjump_end(void) {
    if (ability_hasLearned(ABILITY_A_HOLD_A_JUMP_HIGHER)) {
        ability_use(ABILITY_USED_JUMP);
    }

    if (bs_getNextState() != BS_11_BPECK) {
        baphysics_reset_gravity();
    }
}

void bsjump_fall_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    int sp20;

    if(baflag_isTrue(BA_FLAG_7_TOUCHING_JIGGY) && 700.0f < baphysics_get_vertical_velocity())
        baphysics_set_vertical_velocity(700.0f);

    sp20 = (bs_getPrevState() == BS_12_BFLIP)? 0 : 1;
    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, sp20);
    anctrl_setIndex(aCtrl, ASSET_B0_ANIM_BSJUMP_FALL);
    anctrl_setTransitionDuration(aCtrl, 0.3f);
    anctrl_setDuration(aCtrl, 0.38f);
    anctrl_start(aCtrl, "bsjump.c", 0x188);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    D_8037D4C0 = 0;
}

void bsjump_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    f32 player_velocity[3];

    if(baflag_isTrue(BA_FLAG_F))
        baphysics_reset_horizontal_velocity();
    else
        func_802B6FA8();

    baphysics_get_velocity(player_velocity);

    switch(D_8037D4C0){
        case 0://L802B17B8
            if(func_8028B254(0x5a)){
                anctrl_reset(aCtrl);
                anctrl_setIndex(aCtrl, ASSET_8_ANIM_BSJUMP);
                anctrl_setStart(aCtrl, 0.6667f);
                anctrl_setDuration(aCtrl, 2.0f);
                anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                anctrl_start(aCtrl, "bsjump.c", 0x1b5);
                D_8037D4C0 = 1;
            }
            break;
        case 1:
            break;
    }//L802B1824
    if(baflag_isFalse(BA_FLAG_F)){
        if(player_isFallTumbling())
            sp2C = BS_3D_FALL_TUMBLING;

        if(bainput_should_feathery_flap() && baflag_isFalse(BA_FLAG_5_HAS_PECKED))
            sp2C = BS_BFLAP;

        if(bainput_should_peck())
            sp2C = BS_11_BPECK;
        
        if(bainput_should_beak_bust())
            sp2C = BS_F_BBUSTER;
        
        if(player_inWater())
            sp2C = BS_4C_LANDING_IN_WATER;
    }
    else if(player_inWater()){
        func_8029CCC4();
        if(baflag_isTrue(BA_FLAG_6) || baflag_isTrue(BA_FLAG_14_LOSE_BOGGY_RACE)){
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
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_8_ANIM_BSJUMP);
    anctrl_setDuration(anim_ctrl, 1.9f);
    anctrl_setTransitionDuration(anim_ctrl, 0.134f);
    anctrl_setStart(anim_ctrl, 0.3f);
    anctrl_setSubRange(anim_ctrl, 0.0f, 0.5042f);
    anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
    anctrl_start(anim_ctrl, "bsjump.c", 0x201);
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
        if (anctrl_isStopped(anim_ctrl)) {
            anctrl_setSubRange(anim_ctrl, 0.0f, 0.6667f);
            anctrl_setDuration(anim_ctrl, 4.0f);
            anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 1;
        }
        if (func_8028B254(130)) {
            anctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            anctrl_setDuration(anim_ctrl, 1.4f);
            anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
            D_8037D4C0 = 2;
        }
        break;
    case 1:
        if (func_8028B254(90)) {
            anctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            anctrl_setDuration(anim_ctrl, 2.0f);
            anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
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
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, smooth_transition);
    anctrl_setIndex(anim_ctrl, ASSET_8_ANIM_BSJUMP);
    anctrl_setTransitionDuration(anim_ctrl, 0.3f);
    anctrl_setDuration(anim_ctrl, 1.9f);
    anctrl_setStart(anim_ctrl, 0.6667f);
    anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_STOPPED);
    anctrl_start(anim_ctrl, "bsjump.c", 0x298);
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
            anctrl_setSubRange(anim_ctrl, 0.0f, 1.0f);
            anctrl_setDuration(anim_ctrl, 2.0f);
            anctrl_setPlaybackType(anim_ctrl, ANIMCTRL_ONCE);
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
        basfx_80299CF4(SFX_52_BANJO_YAH_OH, 1.0f, 22000);
    }else{
        batimer_set(0, 0.0f);
        batimer_set(1, 0.01f);
    }
    D_8037D4C0 = 0;
}

void bsjump_tumble_update(void){
    enum bs_e sp1C = 0;
    if(batimer_decrement(1))
        basfx_80299CF4(SFX_63_BANJO_UWAAAAOOH, 1.0f, 32000);
    
    batimer_decrement(0);
    func_802B6FA8();
    if(batimer_isZero(1)){
        pitch_setIdeal(pitch_getIdeal() + 20.0f);
    }
    if(batimer_isNonzero(0)){
        if(bainput_should_feathery_flap())
            sp1C = BS_BFLAP;

        if(bainput_should_peck())
            sp1C = BS_11_BPECK;

        if(bainput_should_beak_bust())
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
    basfx_80299E6C();
}
