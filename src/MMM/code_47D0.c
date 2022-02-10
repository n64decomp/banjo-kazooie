#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038ABC0(s32 arg0) {
    if (getGameMode() != 7) {
        func_80295864(func_802957F0() & ~arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AC40.s")

void func_8038AD10(s32 arg0, s32 arg1, s32 arg2) {
    func_8035179C(arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AD38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038ADF0.s")

void func_8038AF0C(s32 arg0, s32 arg1, s32 arg2) {
    mapSpecificFlags_set(1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038AF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B3F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B630.s")

void func_8038B6D4(f32* arg0) {
    *arg0 = 1.0f;
    func_8038B6FC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_47D0/func_8038B790.s")
