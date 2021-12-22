#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80388DC8(Actor *this);
Actor *func_80388C64(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_80390D60 = { 0xBE, 0x130, 0x3E4, 
    0, NULL, 
    func_80388DC8, func_80326224, func_80388C64, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2730/func_80388B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2730/func_80388C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2730/func_80388C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2730/func_80388D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2730/func_80388D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_2730/func_80388DC8.s")
