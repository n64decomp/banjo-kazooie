#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038A948(Actor *this);
void func_8038A9C0(Actor *this);
Actor *func_8038A7A0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80391000[];
extern ActorInfo D_80391010 = { 0xA7, 0x119, 0x3DC, 
    0x1, D_80391000, 
    func_8038A948, func_8038A9C0, func_8038A7A0, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_43B0/func_8038A7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_43B0/func_8038A860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_43B0/func_8038A8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_43B0/func_8038A948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_43B0/func_8038A9C0.s")
