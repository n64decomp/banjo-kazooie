#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* BREAK?? */
void func_80387FA0(Actor *this);
Actor *func_80387DB0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

ActorInfo D_80390CB0 = { MARKER_BF_GOBI_2, ACTOR_131_GOBI_2, ASSET_3E0_MODEL_GOBI, 
    0x0, NULL, 
    NULL, func_80387FA0, func_80387DB0, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_803879AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_803879D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1570/func_80387FA0.s")
