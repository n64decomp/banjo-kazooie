#include <ultra64.h>
#include "functions.h"
#include "variables.h"


int func_80294F00(void){
    return button_pressed(BUTTON_B) && func_8028A960();
}

int func_80294F3C(void){
    return button_pressed(BUTTON_Z) && func_8028A9A0();
}

int func_80294F78(void){
    return button_pressed(BUTTON_C_UP) && func_8028ACD8();
}

int func_80294FB4(void){
    return button_pressed(BUTTON_C_LEFT) && func_802951FC(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_80294FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_8029502C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_80295068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_802950A4.s")

int func_802950E0(void){
    return button_pressed(BUTTON_A) && func_8028AAB8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_8029511C.s")

int func_80295158(void){
    return button_pressed(BUTTON_B) && func_8028AB68();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_80295194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_802951FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_80295214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_80295250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_8029528C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_802952A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_802952F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_80295328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_DF70/func_8029533C.s")
