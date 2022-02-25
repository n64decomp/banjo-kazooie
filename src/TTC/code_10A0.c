#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803878CC(Actor *this);
void func_80387CF4(Actor *this);
Actor *func_80387D6C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_8038C4E0[];

extern ActorInfo D_8038C510 = { 
    MARKER_A3_BLUBBER, ACTOR_115_BLUBBER, ASSET_370_MODEL_BLUBBER,
    0x1, D_8038C4E0, 
    func_803878CC, func_80387CF4, func_80387D6C, 
    { 0x0, 0x0}, 0x399, 1.8f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_803875D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_8038771C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_803878CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_10A0/func_80387D6C.s")
