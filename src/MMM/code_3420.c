#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_8038C4FC;
extern f32 D_8038C1E0;
extern f32 D_8038C450;

void func_80389810(s32 arg0, s32 arg1, s32 arg2) {
    switch (D_8038C4FC) {                              /* irregular */
    case 2:
        func_80389A0C(3);
        return;
    case 4:
        func_80389A0C(1);
        return;
    case 5:
        func_80389A0C(3);
        return;
    case 6:
        func_80389A0C(7);
        return;
    }
}

void func_803898A0() {
    jiggySpawn(0x60U, &D_8038C1E0);
}

void func_803898C8() {
    func_8025A58C(0, 0x1C2);
}

void func_803898EC() {
    func_8025A58C(-1, 0x12C);
}

void func_80389910() {
    func_80311480(0xAD5, 0xE, NULL, NULL, func_80389810, NULL);
    timedFunc_set_2(0.0f, func_8025A6EC, 0x2D, 0x7FFF);
    timed_setCameraToNode(2.0f, 0);
    timedFunc_set_0(D_8038C450, func_803898A0);
    timedFunc_set_0(6.0f, func_803898EC);
    func_80324E88(6.0f);
    func_80324E38(6.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_803899BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389BCC.s")

void func_80389CD8() {

}

void func_80389CE0() {

}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389FC0.s")
