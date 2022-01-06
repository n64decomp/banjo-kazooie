#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_803454D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_803458E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345C78.s")

void func_80345CD4(f32 arg0[4], f32 arg1[4]){
    mlMtxIdent();
    mlMtxRotRoll(arg1[2]);
    mlMtxRotYaw(arg1[1]);
    mlMtxRotPitch(arg1[0]);
    func_80345A44(arg0, func_80251488());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345D30.s")
