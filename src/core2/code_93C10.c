#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct{
    u8 pad0[3];
    s8 unk3;
    u8 pad4[8];
    struct1Cs *unkC;
}D_803830F0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031ABA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031ABF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031AC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031AD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B030.s")

void func_8031B070(s32 arg0){
    struct1Cs *v0 = D_803830F0.unkC;
    print_bold_overlapping(v0->x, D_803830F0.unk3, -1.2f, v0->string);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B0B0.s")

void func_8031B2F0(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B4F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B554.s")
