#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_8037C3A0;
extern s32 D_8037C3A4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E680/func_80295610.s")

s32 func_802957A0(s32 move){
    return (1 << move) & D_8037C3A4;
}

void ability_setHasUsed(s32 move){
    D_8037C3A4 |= (1 << move); 
}

s32 func_802957D8(s32 move){
    return (1 << move) & D_8037C3A0;
}

s32 func_802957F0(void){
    return D_8037C3A0;
}

void func_802957FC(void){}

void func_80295804(void){
    D_8037C3A0 = 0;
    D_8037C3A4 = 0;
}

void func_80295818(s32 move, s32 val){
    if(val){
        D_8037C3A0 |= (1 << move); 
    }else{
        D_8037C3A0 &= ~(1 << move); 
    }
}

void func_80295864(s32 val){
    D_8037C3A0 = val;
}

void func_80295870(s32 val){
    D_8037C3A4 = val;
}

void func_8029587C(s32 *size, void **addr){
    *size = 8;
    *addr = &D_8037C3A0;
}