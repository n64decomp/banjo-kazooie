#include <ultra64.h>
#include "functions.h"
#include "variables.h"


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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE6CC.s")
