#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80388028(Actor *this);
Actor *func_80387AA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_8038BAD0 = { 0x254, 0x381, 0x521, 
    0x0, NULL,
    func_80388028, NULL, func_80387AA0,
    { 0x0, 0x0}, 0x0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387DF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80388028.s")
