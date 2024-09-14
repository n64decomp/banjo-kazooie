#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "core2/statetimer.h"
#include "core2/ba/physics.h"
#include <core1/viewport.h>


extern int func_80259254(f32 vec[3], f32 x, f32 z, f32 val);
extern f32 player_getYaw(void);

/* .bss */
u8 D_8037BF60;
u8 D_8037BF61;
u8 D_8037BF62;

/* .code */
s32 can_beak_barge(void){
    return ability_hasLearned(ABILITY_0_BARGE);
}

s32 can_beak_bomb(void){
    return ability_hasLearned(ABILITY_1_BEAK_BOMB);
}

s32 can_beak_bust(void){
    return ability_hasLearned(ABILITY_2_BEAK_BUSTER);
}

s32 can_control_camera(void){ 
    return ability_hasLearned(ABILITY_3_CAMERA_CONTROL);
}

s32 can_claw(void){ 
    return ability_hasLearned(ABILITY_4_CLAW_SWIPE);
}

s32 can_climb(void){ 
    return ability_hasLearned(ABILITY_5_CLIMB);
}

int can_dive(void){
    return ability_hasLearned(ABILITY_F_DIVE) 
        && !func_8029D66C() 
        && 100.0f < func_80294500() - func_80294438();
}

s32 can_egg(void){ 
    return ability_hasLearned(ABILITY_6_EGGS);
}

int can_feathery_flap(void){
    return miscFlag_isFalse(MISC_FLAG_12_HAS_FLAPPED) 
        && miscFlag_isFalse(MISC_FLAG_5_HAS_PECKED) 
        && ability_hasLearned(ABILITY_7_FEATHERY_FLAP);
}

s32 can_flap_flip(void){
    return ability_hasLearned(ABILITY_8_FLAP_FLIP);
}

s32 can_fly(void){
    return ability_hasLearned(ABILITY_9_FLIGHT);
}

s32 can_control_jump_height(void){
    return ability_hasLearned(ABILITY_A_HOLD_A_JUMP_HIGHER);
}

int can_peck(void){
    return miscFlag_isFalse(MISC_FLAG_5_HAS_PECKED)
        && miscFlag_isFalse(MISC_FLAG_12_HAS_FLAPPED)
        && ability_hasLearned(ABILITY_B_RATATAT_RAP);
}

int func_8028ABB8(void){
        if(miscFlag_isTrue(MISC_FLAG_14_LOSE_BOGGY_RACE) || miscFlag_isTrue(MISC_FLAG_19))
            return 0;
        if(bs_getState() == BS_56_RECOIL)
            return 0;
        return 1;
}

s32 can_roll(void){
    return ability_hasLearned(ABILITY_C_ROLL);
}

s32 can_shock_jump(void){
    return ability_hasLearned(ABILITY_D_SHOCK_JUMP);
}

s32 can_use_wading_boots(void){
    return ability_hasLearned(ABILITY_E_WADING_BOOTS);
}

s32 can_trot(void){
    return ability_hasLearned(ABILITY_10_TALON_TROT);
}

s32 func_8028AC98(void){
    return ability_hasLearned(ABILITY_10_TALON_TROT);
}

s32 can_wonderwing(void){
    return ability_hasLearned(ABILITY_12_WONDERWING);
}

int can_view_first_person(void){
    if( map_get() == MAP_27_FP_FREEZEEZY_PEAK && mapSpecificFlags_get(0xd)){
        return 0;
    }

    if(ncFirstPersonCamera_getState() == FIRSTPERSON_STATE_3_EXIT)
        return 0;

    if(!player_isStable() && !player_inWater())
        return 0;
    return 1;
}

int func_8028AD64(void){
    return bsant_inSet(bs_getState());
}

int func_8028AD8C(void){
    return bspumpkin_inSet(bs_getState());
}

int func_8028ADB4(void){
    return func_8032190C() && map_get() != MAP_1_SM_SPIRAL_MOUNTAIN;
}

int func_8028ADF0(void){
    return volatileFlag_get(VOLATILE_FLAG_9D_SANDCASTLE_WISHY_WASHY);
}

bool func_8028AE10(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp1C[3];
    f32 ideal_yaw;

    _player_getPosition(sp1C);
    ideal_yaw = yaw_getIdeal();
    sp2C = viewport_adjustAngleToRight(sp1C, 90.0f);
    sp28 = viewport_adjustAngleToRight(sp1C, 270.0f);
    if (sp28 < sp2C) {
        return (sp2C < ideal_yaw) || (ideal_yaw < sp28);
    }
    else{
        return (sp2C < ideal_yaw) && (ideal_yaw < sp28);
    }
}

bool func_8028AED4(f32 arg0[3], f32 arg1) {
    f32 sp2C[3];
    f32 sp28;
    u16 sp26;
    u16 sp24;
    s32 temp_v1;
    s32 phi_a0;

    _player_getPosition(sp2C);
    func_80257F18(arg0, sp2C, &sp28);
    sp26 = (u16) (sp28 * 182.044444);
    sp24 = (u16) (player_getYaw() * 182.044444);
    sp26 = (u16)((sp26 - sp24));
    temp_v1 = 0x8000 - sp26;
    phi_a0 = (temp_v1 >= 0) ? temp_v1 : -temp_v1;
    return (phi_a0 < arg1 * 182.044444);
}

int func_8028B094(void){
    return (60.0f < player_getYPosition() - func_80294438());
}

int player_isInHorizontalRadius(f32 arg0[3], f32 arg1){
    f32 sp1C[3];
    _player_getPosition(sp1C);
    return func_80259254(sp1C, arg0[0], arg0[2], arg1);
}

s32 func_8028B120(void){return 0;}

int func_8028B128(void){
    return miscFlag_isTrue(MISC_FLAG_13);
}

bool player_isInRBB(void){
    return level_get() == LEVEL_9_RUSTY_BUCKET_BAY;
}

bool player_isInVerticalRange(f32 position[3], f32 range) {
    f32 plyr_pos[3];

    _player_getPosition(plyr_pos);
    return (((position[1] - range) <= plyr_pos[1]) && (plyr_pos[1] <= (position[1] + range)));
}

int player_shouldSlideTrot(void){
    return stateTimer_isActive(STATE_TIMER_6_UNKNOWN)
        || (1.0 == get_slope_timer() && func_80294610(0x40));
}

bool func_8028B254(s32 arg0) {
    return (player_isStable() || (baphysics_get_vertical_velocity() < 0.0f && (player_getYPosition() - func_80294438()) < (f32) arg0));
}

int player_isStable(void){
    return D_8037BF60 && baphysics_get_vertical_velocity() < 0.0f;
}

int player_isSliding(void){
    return stateTimer_isActive(STATE_TIMER_5_UNKNOWN) 
        || 1.0 == get_slope_timer();
}

int func_8028B394(void){
    return func_8029CF20(4);
}

bool func_8028B3B4(void) {
    bool sp1C;
    bool sp18;

    sp1C = func_80294610(0x10) && miscFlag_isFalse(MISC_FLAG_3);
    sp18 = func_80294610(0x40) && miscFlag_isFalse(MISC_FLAG_4);
    if(sp1C || sp18)
        return TRUE;
    return FALSE;
}

bool player_isFallTumbling(void){
    s32 sp1C;

    if (player_isStable()) {
        return FALSE;
    }
    if (!bafalldamage_get_damage(&sp1C)) {
        return FALSE;
    }
    return TRUE;
}

bool func_8028B470(void){
    bool out;
    switch(bs_getState()){
        case BS_2B_DIVE_IDLE:
        case BS_2C_DIVE_B:
        case BS_2D_SWIM_IDLE:
        case BS_2E_SWIM:
        case BS_30_DIVE_ENTER:
        case BS_39_DIVE_A:
        case BS_4C_LANDING_IN_WATER:
            out = TRUE;
            break;
        default:
            out = FALSE;
    }
    return out;
}

int func_8028B4C4(void){
    return 135.0f < mlAbsF(mlDiffDegF(yaw_getIdeal(), yaw_get()));
}

int player_inWater(void){
    return D_8037BF61;
}

int func_8028B528(void){
    return D_8037BF62;
}

void func_8028B534(void){
    s32 sp1C = func_8028ECAC();
    if(player_inWater()){
        D_8037BF62 = 1;
    }
    else{
        if(player_isStable() || sp1C == BSGROUP_A_FLYING || sp1C == BSGROUP_5_CLIMB){
            D_8037BF62 = 0;
        }
    }
}

void func_8028B59C(void) {
    s32 sp24;

    sp24 = D_8037BF61;
    if (D_8037BF61) {
        D_8037BF61 = (func_80294554() && player_getYPosition() < ((func_80294500() - 50.0f) + 2.0f));
    } else {
        D_8037BF61 = (func_80294554() && player_getYPosition() < ((func_80294500() - 50.0f) - 2.0f));
    }
    if (map_get() == MAP_6_TTC_NIPPERS_SHELL) {
        D_8037BF61 = FALSE;
    }
    if (!sp24 && D_8037BF61 && (baphysics_get_vertical_velocity() < -40.0)) {
        func_8029C0D0();
        func_8030E58C(0xF, 0.7f);
    }
}


void func_8028B6FC(void){
    D_8037BF60 = 1;
    D_8037BF61 = 0;
    D_8037BF62 = 0;
}

void func_8028B71C(void){
    func_8028B59C();
    D_8037BF60 = func_80294548();
    func_8028B534();
}


