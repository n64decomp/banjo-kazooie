#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8024A840(s32 arg0, s32 arg1, s32 arg2);
void func_8024A85C(s32 arg0);

extern s16 D_80275BCC;

extern s32 D_802806E0;
extern s32 D_802806E4;
extern s32 D_802806E8;
extern s32 D_802806EC;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024776C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802478C0.s")

void func_8024792C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802479E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247F24.s")

void func_80247F9C(s32 arg0){
    func_80247D80(D_80275BCC, arg0, 2);
    func_802484D0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024824C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802483B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802483D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802484D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024856C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802485BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802485C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802485D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802499BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802499D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802499E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249DE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A3C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A770.s")

void func_8024A810(void){
    func_8024A840(0, 0x80, 0);
    func_8024A85C(0);
}

void func_8024A840(s32 arg0, s32 arg1, s32 arg2){
    D_802806E0 = arg0;
    D_802806E4 = arg1;
    D_802806E8 = arg2;
}

void func_8024A85C(s32 arg0){
    D_802806EC = arg0;
}

s32 func_8024A868(void){
    return D_802806EC;
}
