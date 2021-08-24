#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"


extern int func_80259254(f32 vec[3], f32 x, f32 z, f32 val);
extern s32 carriedObject_actorID;
extern u8 D_8037BF60;
extern u8 D_8037BF61;
extern u8 D_8037BF62;
extern ActorMarker *D_8037BF70;



s32 can_beak_barge(void){
    return func_802957D8(ABILITY_0_BARGE);
}

s32 func_8028A980(void){
    return func_802957D8(ABILITY_3_BEAK_BOMB);
}

s32 can_beak_bust(void){
    return func_802957D8(ABILITY_2_BEAK_BUSTER);
}

s32 func_8028A9C0(void){ 
    return func_802957D8(ABILITY_3_CAMERA_CONTROL);
}

s32 can_claw(void){ 
    return func_802957D8(ABILITY_4_BEAR_PUNCH);
}

s32 func_8028AA00(void){ 
    return func_802957D8(ABILITY_5_CLIMB);
}

int func_8028AA20(void){
    return func_802957D8(ABILITY_F_DIVE) 
        && !func_8029D66C() 
        && 100.0f < func_80294500() - func_80294438();
}

s32 can_egg(void){ 
    return func_802957D8(ABILITY_6_EGGS);
}

int can_flap(void){
    return func_802933D0(0x12) 
        && func_802933D0(0x5) 
        && func_802957D8(ABILITY_7_FLAP);
}

s32 can_flip(void){
    return func_802957D8(ABILITY_8_FLIP);
}

s32 func_8028AB28(void){
    return func_802957D8(ABILITY_9_FLY);
}

s32 func_8028AB48(void){
    return func_802957D8(ABILITY_A_HOLD_A_JUMP_HIGHER);
}

int can_peck(void){
    return func_802933D0(0x5)
        && func_802933D0(0x12)
        && func_802957D8(ABILITY_B_RATATAT_RAP);
}

int func_8028ABB8(void){
        if(func_802933C0(0x14) || func_802933C0(0x19))
            return 0;
        if(bs_getState() == BS_56_RECOIL)
            return 0;
        return 1;
}

s32 func_8028AC18(void){
    return func_802957D8(ABILITY_C_ROLL);
}

s32 func_8028AC38(void){
    return func_802957D8(ABILITY_D_SHOCK_JUMP);
}

s32 func_8028AC58(void){
    return func_802957D8(ABILITY_E_WADING_BOOTS);
}

s32 can_trot(void){
    return func_802957D8(ABILITY_10_TALON_TROT);
}

s32 func_8028AC98(void){
    return func_802957D8(ABILITY_10_TALON_TROT);
}

s32 can_wonderwing(void){
    return func_802957D8(ABILTIY_12_WONDERWING);
}

int func_8028ACD8(void){
    if( func_803348C0() == MAP_27_FP_FREEZEEZY_PEAK && mapSpecificFlags_get(0xd)){
        return 0;
    }

    if(func_802C2B00() == 3)
        return 0;

    if(!func_8028B2E8() && !player_inWater())
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
    return func_8032190C() && func_803348C0() != 1;
}

int func_8028ADF0(void){
    return func_803203FC(0x9d);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AED4.s")

int func_8028B094(void){
    return (60.0f < player_getYPosition() - func_80294438());
}

int func_8028B0E0(f32 arg0[3], f32 arg1){
    f32 sp1C[3];
    _player_getPosition(sp1C);
    return func_80259254(sp1C, arg0[0], arg0[2], arg1);
}

s32 func_8028B120(void){return 0;}

int func_8028B128(void){
    return func_802933C0(0x13);
}

int func_8028B148(void){
    return level_get() == LEVEL_9_RUSTY_BUCKET_BAY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B16C.s")

int player_shouldSlideTrot(void){
    return func_80291698(6)
        || (1.0 == get_slope_timer() && func_80294610(0x40));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B2E8.s")

int player_isSliding(void){
    return func_80291698(5) 
        || 1.0 == get_slope_timer();
}

int func_8028B394(void){
    return func_8029CF20(4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B470.s")

int func_8028B4C4(void){
    return 135.0f < mlAbsF(mlDiffDegF(yaw_getIdeal(), yaw_get()));
}

int player_inWater(void){
    return D_8037BF61;
}

int func_8028B528(void){
    return D_8037BF62;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B59C.s")

void func_8028B6FC(void){
    D_8037BF60 = 1;
    D_8037BF61 = 0;
    D_8037BF62 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B7F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B8DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BA00.s")

void func_8035644C(s32);

void func_8028BA2C(s32 arg0) {
    if (func_802FADD4(0x1B) == 0) {
        func_80345F24(item_note);
    } else {
        func_803463F4(item_note, 1);
    }
    if (item_getCount(item_note) < 100) {
        func_8025A6EC(SFX_NOTE_COLLECTED, 0x3E80);
        timedFunc_set_1(0.75f, func_8035644C, 3);
    }
    func_802F379C(arg0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D2E4.s")

ActorMarker *player_getMarker(void){ //player_getMarker
    return D_8037BF70;
}

void func_8028D5DC(void){ //player_collisionOff
    D_8037BF70->collidable = 0;
}

void func_8028D5F4(void){ //player_collisionOn
    D_8037BF70->collidable = 1;
}

s32 func_8028D60C(void){ //player_isCollidable
    return (D_8037BF70->collidable)? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D64C.s")

void carriedObject_setActorID(s32 arg0){
    carriedObject_actorID = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D664.s")

s32 carriedObject_getActorID(void){
    return carriedObject_actorID;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D7B8.s")
