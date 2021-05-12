#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8025901C(f32, f32 *, f32 *, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_802992F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_8029932C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_80299338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_802993C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_8029957C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_80299588.s")

void func_80299594(s32 arg0, f32 arg1){
    f32 sp2C[3];
    f32 sp20[3];
    func_80294480(sp2C);
    if(arg0){
        func_8025901C(mlNormalizeAngle(yaw_get() + 180.0f), sp2C, sp20, arg1);
    } else {
        func_8025901C(yaw_get(), sp2C, sp20, arg1);
    }
    pitch_setIdeal(sp20[0]);
    roll_setIdeal(sp20[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12360/func_80299628.s")
