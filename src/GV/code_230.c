#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803868C0(Actor *this);
Actor *func_80386E70(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80390C3C[];
extern ActorInfo D_80390C5C = { MARKER_F4_ANCIENT_ONE, ACTOR_147_ANCIENT_ONE, ASSET_3E8_MODEL_ANCIENT_ONE, 
    0x1, D_80390C3C, 
    func_803868C0, func_80326224, func_80386E70, 
    { 0x0, 0x0, 0x1, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_80386620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_8038678C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_803867CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_803867F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_80386850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_803868C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_80386E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_230/func_80387118.s")
