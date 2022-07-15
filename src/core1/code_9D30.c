#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8024A840(s32 arg0, s32 arg1, s32 arg2);
void func_8024A85C(s32 arg0);

extern s16 D_80275BBC;


extern s16 D_80275BC4;

extern s16 D_80275BCC;
extern s16 D_80275BD0;
extern s16 D_80275BD4;

/* .bss */
s32 D_802806E0;
s32 D_802806E4;
s32 D_802806E8;
s32 D_802806EC;

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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248330.s")
#else
void func_80248330(u8 *arg0){
    s32 i;
    s32 val;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    for(i = 0; arg0[i] != 0; i++){
        func_8024824C(arg0[i]);
        func_80247CEC(D_80275BCC, arg0[i], 2);
    }
    func_80248520();
}
#endif

void func_802483B8(void){
    D_80275BD0 = 1;
    do{}while(1);
}

void func_802483D8(void){
    s32 i;
    D_80275BD0 = 1;
    for(i = 30000000; i != 0; i--){}
    D_80275BD0 = 0;
}

void func_80248404(s32 arg0){
    s32 i;

    D_80275BD0 = 1;
    while(arg0 != 0){
        for(i = 30000000; i != 0; i--){}
        arg0--;
    }
    D_80275BD0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802484D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024856C.s")

s32 func_802485BC(void){
    return D_80275BD0;
}

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
