#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038AE2C(Actor *this);
Actor *func_8038B898(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80393520[];
extern ActorInfo D_80393560 = { 0x231, 0x23B, 0x4DF, 0x1, D_80393520, func_8038AE2C, func_80326224, func_8038B898, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80393584 = { 0x244, 0x2DB, 0x450, 0x1, D_80393520, func_8038AE2C, func_80326224, func_8038B898, { 0x0, 0x0}, 0, 3.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A6DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A6EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038A96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038AB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038AC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038ADC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038ADF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038AE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_42A0/func_8038B898.s")
