#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80293350(void);

f32 D_8037C1B0[3];
u8  D_8037C1BC;
s32 D_8037C1C0[2];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_802927E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_802929F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80292EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80293070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_802930C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80293190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_802931DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_802931F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80293234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B850/func_80293240.s")

void func_80293284(f32 arg0[3]){
    ml_vec3f_copy(D_8037C1B0, arg0);
}

void func_802932AC(void){
    _player_getPosition(D_8037C1B0);
    D_8037C1BC = 0;
    func_80293240(1);
    D_8037C1C0[0] = 0;
    D_8037C1C0[1] = 0;
}

void func_802932EC(void){
    s32 sp1C;
    sp1C = func_8028ECAC();
    if(func_8028B2E8() || func_8028EE84() || sp1C == 0xA){
        func_80293350();
        func_80293240(1);
    }
    func_80293190();
}

void func_80293350(void){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    func_80293284(sp1C);
}