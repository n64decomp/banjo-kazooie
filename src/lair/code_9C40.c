#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803902B8(Actor *this);
Actor *func_80390030(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_80394860[];
extern ActorInfo D_80394870 = { 0x16D, 0x1D5, 0x54F, 0x1, D_80394860, func_803902B8, func_80326224, func_80390030, { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80394894 = { 0x16E, 0x1D6, 0x54F, 0x1, D_80394860, func_803902B8, func_80326224, func_80390030, { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803948B8 = { 0x16F, 0x1D7, 0x54F, 0x1, D_80394860, func_803902B8, func_80326224, func_80390030, { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_80390030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_80390084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_803900DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_803900EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_80390158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_80390174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_8039024C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_80390298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_9C40/func_803902B8.s")
