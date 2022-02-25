#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80388434(Actor *this);
Actor *func_80387EB0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);


/* .data */
extern ActorAnimationInfo D_8038C540[];

extern ActorInfo D_8038C580 = { 
    MARKER_A5_NIPPER, ACTOR_117_NIPPER, ASSET_3D5_MODEL_NIPPER,
    0x1, D_8038C540,
    func_80388434, func_80326224, func_80387EB0,
    { 0x0, 0x0}, 0x299, 10.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80387DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80387EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80387F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80387FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80387FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80388088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_8038812C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80388178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_803882E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80388344.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_803883C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80388434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_19D0/func_80388A44.s")
