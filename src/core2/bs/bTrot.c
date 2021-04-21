#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A87C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A880C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A88B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A89D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A90F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A914C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A988C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A98C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9B78.s")

int bsbtrot_inSet(s32 move_indx){
    return (move_indx == BS_BTROT_IDLE)
    || (move_indx == BS_BTROT_WALK)
    || (move_indx == BS_BTROT_JUMP)
    || (move_indx == BS_BTROT_EXIT)
    || (move_indx == 0x45)
    || (move_indx == BS_BTROT_ENTER)
    || (move_indx == 0x79)
    || (move_indx == 0x7b)
    || (move_indx == 0x71)
    || (move_indx == 0x9a);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA0E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA27C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA3D0.s")
