#include <ultra64.h>
#include "functions.h"
#include "variables.h"
struct{
    u8 pad0[0x4];
    s32 unk4;
    u8 unk8;
    u8 pad9[3]; //not needed
    void *unkC;
    f32 rotation;
} D_80382430;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BDAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BE3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BEA4.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BEDC.s")
void func_8030BEDC(void){
    D_80382430.unk4 = 0;
    D_80382430.unk8 = 0;
    D_80382430.unkC = NULL;
    D_80382430.rotation = 0.0f;
    func_8030B498(0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BF1C.s")
