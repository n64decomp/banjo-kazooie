#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern s32 carriedObject_actorID;
extern ActorMarker *D_8037BF70;
enum moves_e{
    move_beak_barge,
    move_beak_bomb,
    move_beak_buster,
    move_camera_control,
    move_bear_punch,
    move_climb,
    move_eggs,
    move_feathery_flap,
    move_flip_flap,
    move_flight,
    move_variable_jump,
    move_ratatat_rap,
    move_roll,
    move_shock_jump,
    move_wading_boots,
    move_dive,
    move_talon_trot,
    move_turbo_talon_trot,
    move_wonderwing,
    move_1st_note_door
};

s32 func_8028A960(void){ //beak_barge_unlocked
    return func_802957D8(move_beak_barge);
}

s32 func_8028A980(void){ //beak_bomb_unlocked
    return func_802957D8(move_beak_bomb);
}

s32 func_8028A9A0(void){ //beak_buster_unlocked
    return func_802957D8(move_beak_buster);
}

s32 func_8028A9C0(void){ 
    return func_802957D8(move_camera_control);
}

s32 func_8028A9E0(void){ 
    return func_802957D8(move_bear_punch);
}

s32 func_8028AA00(void){ 
    return func_802957D8(move_climb);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AA20.s")

s32 func_8028AA98(void){ 
    return func_802957D8(move_eggs);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AAB8.s")

s32 func_8028AB08(void){
    return func_802957D8(move_flip_flap);
}

s32 func_8028AB28(void){
    return func_802957D8(move_flight);
}

s32 func_8028AB48(void){
    return func_802957D8(move_variable_jump);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028AB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028ABB8.s")

s32 func_8028AC18(void){
    return func_802957D8(move_roll);
}

s32 func_8028AC38(void){
    return func_802957D8(move_shock_jump);
}

s32 func_8028AC58(void){
    return func_802957D8(move_wading_boots);
}

s32 func_8028AC78(void){
    return func_802957D8(move_talon_trot);
}

s32 func_8028AC98(void){
    return func_802957D8(move_talon_trot);
}

s32 func_8028ACB8(void){
    return func_802957D8(move_wonderwing);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028B51C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028BCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39D0/func_8028D2E4.s")

ActorMarker *func_8028D5D0(void){ //banjo_getMarker
    return D_8037BF70;
}

void func_8028D5DC(void){ //banjo_collisionOff
    D_8037BF70->collidable = 0;
}

void func_8028D5F4(void){ //banjo_collisionOn
    D_8037BF70->collidable = 1;
}

s32 func_8028D60C(void){ //banjo_isCollidable
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
