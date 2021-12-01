#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80379170;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C3A40/func_8034A9D0.s")

void func_8034AA70(f32 arg0[4]){
    arg0[1] = D_80379170;
    arg0[0] = 4000.0f;
    arg0[3] = 2000.0f;
    arg0[2] = -500.0f;
}