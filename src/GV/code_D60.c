#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80387408(Actor *this);
Actor *func_803872F0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_80390C80 = { 0xBC, 0x12E, 0x3E0, 
    0, NULL, 
    NULL, func_80387408, func_803872F0, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_803872F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_8038736C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_803873B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387408.s")

/* BREAK?? */
void func_80387FA0(Actor *this);
Actor *func_80387DB0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

ActorInfo D_80390CB0 = { 0xBF, 0x131, 0x3E0, 
    0x0, NULL, 
    NULL, func_80387FA0, func_80387DB0, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_803879AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_803879D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_D60/func_80387FA0.s")
