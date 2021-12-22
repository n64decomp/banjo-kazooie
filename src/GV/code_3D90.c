#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038A314(Actor *this);
void func_8038A31C(Actor *this);
Actor *func_8038A180(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80390FA0[];
extern ActorInfo D_80390FD0 = { 0xB0, 0x123, 0x3DC, 
    0x1, D_80390FA0, 
    func_8038A314, func_8038A31C, func_8038A180, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3D90/func_8038A180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3D90/func_8038A264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3D90/func_8038A2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3D90/func_8038A314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_3D90/func_8038A31C.s")
