#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80369914;
extern s32 D_8038158C[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FCFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FD050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_75E90/func_802FD064.s")

int func_802FD2D4(void){
    if(!D_80369914)
        return 0;
    return func_802FDD0C(D_8038158C[D_80369914]) == 0x1A;
}
