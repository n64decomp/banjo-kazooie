#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_80388718(Actor *this);
Actor *func_8038863C(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_80390D00 = { 0xC3, 0x135, 0x3E0, 
    0, NULL, 
    NULL, func_80388718, func_8038863C, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_80388270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_80388298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_803882F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_80388434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_8038863C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_803886A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_80388718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_1E80/func_803888C0.s")
