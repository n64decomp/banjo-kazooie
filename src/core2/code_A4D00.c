#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"


extern s32  func_80320DB0(f32[3], f32, f32[3], u32);
extern f32  func_8033229C(ActorMarker *marker);

/* .bss */
s32 D_803833D0;
f32 D_803833D8[3];

/* .code */
bool func_8032BC90(Actor *actor, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp44[3];
    bool sp40;
    s32 phi_v0;
    f32 sp30[3];

    sp40 = actor->marker->propPtr->unk8_3;
    func_8028E964(sp30);

    actor->marker->propPtr->unk8_3 = 0;
    phi_v0 = func_80320B98(&sp30, actor->position, &sp44, actor->unk154);
    if (phi_v0 == 0) {
        phi_v0 = func_80320DB0(actor->position, func_8033229C(actor->marker), &sp44, actor->unk154);
    }

    actor->marker->propPtr->unk8_3 = sp40;
    return (phi_v0)? 1 : 0;
}

void func_8032BD64(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_803833D8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032BD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CA80.s")
