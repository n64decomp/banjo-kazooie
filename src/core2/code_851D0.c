#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 *D_80382450;
extern void *D_80382454;

extern u8 D_803A5D00[2][0x1ecc0];

/* .code */
void func_8030C160(void){
    func_8024F150();
}

void func_8030C180(void){
    func_8024F180();
}

void func_8030C1A0(void){
    if(D_80382454 == NULL){
        D_80382454 = D_80382450 = malloc(0xA040);

        while((s32)D_80382450 & 0x3F){
            D_80382450++;
        }
    }
}

void func_8030C204(void){
    if(D_80382454){
        free(D_80382454);
        D_80382454 = NULL;
    }

    switch(getGameMode()){
        case GAME_MODE_8_BOTTLES_BONUS:
            func_802DEA8C(0, 0);
            break;
        case GAME_MODE_A_SNS_PICTURE:
            func_802DF11C(0, 0);
            break;
    }
}

void func_8030C27C(void){
    switch(getGameMode()){
        case GAME_MODE_8_BOTTLES_BONUS:
            func_802DEA18(0, 0);
            break;
        case GAME_MODE_A_SNS_PICTURE:
            func_802DF090(0, 0);
            break;

    }
}

void func_8030C2D4(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    func_80254348();
    func_80253640(gdl, D_803A5D00[func_8024BDA0()]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_851D0/func_8030C33C.s")

s32 func_8030C704(void){
    return D_80382450;
}

void func_8030C710(void){
    func_802542F4(0, 0xA0, 0, 0x80);
}
