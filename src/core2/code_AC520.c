#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803334B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803335F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_8033361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803337C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_8033383C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333918.s")

extern struct {
    vector(struct22s) *unk0;
    u8 pad4[0x40];
    s32 unk44;
    void *unk48;
} D_80383570;

extern u8 D_803835B4;

void func_8033393C(void){
    D_80383570.unk0 = vla_new(sizeof(struct22s), 0x10);
    D_80383570.unk48 = &D_80383570.unk44;
}

void func_80333974(s32 index){
    struct22s *v0 = vla_at(D_80383570.unk0, index-1);
    v0->unk34 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803339A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80333D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803340A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803342AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803343AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803343D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_803343F8.s")

void func_80334428(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80334430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_8033443C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80334448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_8033451C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_80334524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AC520/func_8033452C.s")
