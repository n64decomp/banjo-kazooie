#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern s32 carriedObject_actorID;
extern ActorMarker *D_8037BF70;


s32 can_beak_barge(void){ //beak_barge_unlocked
    return func_802957D8(ABILITY_BARGE);
}

s32 func_8028A980(void){ //beak_bomb_unlocked
    return func_802957D8(ABILITY_BEAK_BOMB);
}

s32 can_beak_bust(void){ //beak_buster_unlocked
    return func_802957D8(ABILITY_BEAK_BUSTER);
}

s32 func_8028A9C0(void){ 
    return func_802957D8(ABILITY_CAMERA_CONTROL);
}

s32 can_claw(void){ 
    return func_802957D8(ABILITY_BEAR_PUNCH);
}

s32 func_8028AA00(void){ 
    return func_802957D8(ABILITY_CLIMB);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AA20.s")

s32 can_egg(void){ 
    return func_802957D8(ABILITY_EGGS);
}

int can_flap(void){
    return func_802933D0(0x12) 
        && func_802933D0(0x5) 
        && func_802957D8(ABILITY_FLAP);
}

s32 can_flip(void){
    return func_802957D8(ABILITY_FLIP);
}

s32 func_8028AB28(void){
    return func_802957D8(ABILITY_FLY);
}

s32 func_8028AB48(void){
    return func_802957D8(ABILITY_HOLD_A_JUMP_HIGHER);
}

int can_peck(void){
    return func_802933D0(0x5)
        && func_802933D0(0x12)
        && func_802957D8(ABILITY_RATATAT_RAP);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028ABB8.s")

s32 func_8028AC18(void){
    return func_802957D8(ABILITY_ROLL);
}

s32 func_8028AC38(void){
    return func_802957D8(ABILITY_SHOCK_JUMP);
}

s32 func_8028AC58(void){
    return func_802957D8(ABILITY_WADING_BOOTS);
}

s32 can_trot(void){
    return func_802957D8(ABILITY_TALON_TROT);
}

s32 func_8028AC98(void){
    return func_802957D8(ABILITY_TALON_TROT);
}

s32 can_wonderwing(void){
    return func_802957D8(ABILTIY_WONDERWING);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028ACD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AD64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028ADB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028ADF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B0E0.s")

s32 func_8028B120(void){return 0;}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B148.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/player_inWater.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B59C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B6FC.s")

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
