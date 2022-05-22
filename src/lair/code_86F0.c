#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038F924(Actor *this);

/* .data */
extern ActorInfo D_803947B0 = { 0x1EB, 0x3B7, 0x48B, 0x1, NULL, func_8038F924, func_80326224, func_80325888, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803947D4 = { 0x1EB, 0x3BC, 0x538, 0x1, NULL, func_8038F924, func_80326224, func_80325888, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EB58.s")

s32 func_8038EB84(Actor *this){
    return this->unkF4_8 + 0x1B;
}

void func_8038EB94(void){
    func_802FAFD4(ITEM_14_HEALTH, 0x417);
    func_802FAFC0(ITEM_14_HEALTH, COMUSIC_2B_DING_B);
    func_80320004(BKPROG_B9_DOUBLE_HEALTH, TRUE);
    func_80347958();
    func_803463D4(ITEM_14_HEALTH, 0);
    func_80314AC8(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038ECA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038ECFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038ED10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038ED88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EDBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EF58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038EFD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F0C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F0EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_86F0/func_8038F924.s")
