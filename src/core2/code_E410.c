#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u32 D_8037C310[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_802953A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_80295448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_8029551C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_80295530.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/button_pressed.s")
int button_pressed(s32 button_indx){
    return D_8037C310[button_indx] == 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_80295560.s")

u32 button_held(s32 button_indx){
    return D_8037C310[button_indx];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_80295590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_802955A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E410/func_802955BC.s")
