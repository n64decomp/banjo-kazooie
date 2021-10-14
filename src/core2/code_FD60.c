#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
extern f32 D_80364440; //defaultGravity

/* .rodata */

/* .bss */
extern f32 D_8037C4B8[3]; //velocity?

extern f32 D_8037C4E8; //gravity



#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80296CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802971DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802972AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_8029737C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_8029740C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802974A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802976C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802976E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802978A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802978DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_8029797C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/player_setYVelocity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_802979AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297A7C.s")

void _get_velocity(f32 (*dst)[3]){
    ml_vec3f_copy(dst, &D_8037C4B8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297B64.s")

void gravity_reset(void){
    gravity_set(D_80364440);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297BC4.s")

void gravity_set(f32 arg0){
    D_8037C4E8 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_FD60/func_80297C48.s")
