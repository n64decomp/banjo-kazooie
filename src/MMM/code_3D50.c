#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .rodata */
extern f32 D_8038C470 = 0.3f;
extern f32 D_8038C474 = 0.3f;
extern f32 D_8038C478 = 0.3f;

/* .bss */
extern u8 D_8038C518;

/* .code */
void func_8038A140(UNK_TYPE(s32) arg0) {
    if (arg0 == 2) {
        func_80324E38(D_8038C470, 3);
        timed_setCameraToNode(D_8038C474, 1);
        timedFunc_set_2(D_8038C478, mapSpecificFlags_set, 3, 1);
        func_80324E38(3.0f, 0);
        func_80324E88(3.0f);
        timedFunc_set_1(3.0f, func_8038A140, 3);
    }
    if (arg0 == 3) {
        if (D_8038C518 == 1) {
            mapSpecificFlags_set(3, 1);
        }
        item_set(ITEM_0_HOURGLASS_TIMER, 75*60 - 1);
        item_set(6, 1);
    }
    if (D_8038C518 == 3) {
        item_set(6, 0);
        mapSpecificFlags_set(4, 1);
    }
    if (arg0 == 4) {
        func_8028F66C(0xF);
    }
    D_8038C518 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A26C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A58C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A964.s")

void func_8038A994() {
    func_8038A140(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038A9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038AA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3D50/func_8038AA44.s")
