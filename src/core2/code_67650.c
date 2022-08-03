#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
s16 D_80368930[3] = {
    ASSET_700_SPRITE_DUST,
    ASSET_702_SPRITE_UNKNOWN,
    ASSET_70D_SPRITE_SMOKE_1
};

/* .bss */
u8 D_80380910[3];

/* .code */
s32 func_802EE5E0(s32 arg0){
    return arg0;
}

void func_802EE5E8(ParticleEmitter *this){
    return;
}

bool func_802EE5F0(s32 arg0){
    return (arg0 < 3) ? !func_802EF648(func_802F0EF0(D_80380910[arg0])) : FALSE;
}

void func_802EE63C(void) {
    s32 i;

    for(i = 0; i < 3; i++){
        D_80380910[i] = func_802F0F78(0x20);
    }
}

void func_802EE684(void) {
    s32 i;

    for(i = 0; i < 3; i++){
        func_802F1190(D_80380910[i]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE6CC.s")
