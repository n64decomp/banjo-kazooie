#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802D6B10(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D6B68(Actor *this);

/* .data */
extern ActorAnimationInfo D_80367A00[];
extern ActorInfo D_80367A20 = {
    MARKER_11_WADING_BOOTS, ACTOR_65_WADING_BOOTS, ASSET_366_MODEL_WADING_BOOTS, 
    0x0, D_80367A00, 
    func_802D6B68, func_80326224, func_802D6B10, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4FB80/func_802D6B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4FB80/func_802D6B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4FB80/func_802D6E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4FB80/func_802D6E4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4FB80/func_802D6E54.s")
