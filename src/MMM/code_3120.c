#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038C440;
extern u8 D_8038C4E0;
extern u8 D_8038C4E1;
extern u8 D_8038C4E2;

s32 func_80389510() {
    return D_8038C4E1 == 1;
}

u8 func_80389524() {
    return D_8038C4E0;
}

u8 func_80389530() {
    return D_8038C4E2;
}

void func_8038953C() {
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3120/func_80389544.s")

void func_803895B0(s32 arg0) {
    if (arg0 != 0) {
        D_8038C4E1 = 1;
        return;
    }
    D_8038C4E1 = 2;
}

void func_803895D8(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xAD7) {
        timed_playSfx(D_8038C440, 0x3F5, 1.0f, 0x7530);
        func_80324E88(1.5f);
        func_80324E38(1.5f, 0);
        return;
    }
    D_8038C4E0 = 1;
    func_80324E88(1.5f);
    func_80324E38(1.5f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3120/func_8038966C.s")
