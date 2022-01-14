#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802CA320(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802CA498(Actor *this);
Actor *func_802CA7BC(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802CA92C(Actor *this);

/* .data */
extern ActorAnimationInfo D_80366EA0[];
extern ActorInfo D_80366EC0 = { MARKER_38_TURBO_TALON_TRAINERS, ACTOR_2C_TURBO_TALON_TRAINERS, ASSET_367_MODEL_TURBO_TALON_TRAINERS, 0x0, D_80366EA0, func_802CA498, func_80326224, func_802CA320, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
//BREAK???

extern ActorInfo D_80366EF0 = { 0x32, 0x17, 0x3BF, 0x1, 0x0, func_802CA92C, func_80326224, func_802CA7BC, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA748.s")

//BREAK???

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA7BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_43390/func_802CA92C.s")
