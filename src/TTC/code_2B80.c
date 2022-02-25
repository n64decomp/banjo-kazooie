#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80388FBC(Actor *this);

/* .data */
extern ActorAnimationInfo D_8038C700[];

extern ActorInfo D_8038C718 = { 
    MARKER_33_LEAKY,  ACTOR_1E_LEAKY, ASSET_51A_MODEL_LEAKY,
    0x1, D_8038C700,
    func_80388FBC, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_2B80/func_80388F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_2B80/func_80388F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_2B80/func_80388FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_2B80/func_80389288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_2B80/func_80389364.s")
