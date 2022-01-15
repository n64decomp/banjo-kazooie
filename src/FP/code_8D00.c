#include <ultra64.h>
#include "functions.h"
#include "variables.h"
Actor *func_8038F0F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038F144(Actor *this);

/* .data */
extern ActorAnimationInfo D_803924A0[];

extern ActorInfo D_803924B0 = { 0x208, 0x33A, 0x47F, 
    0x1, D_803924A0,
    func_8038F144, func_80326224, func_8038F0F0,
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803924D4 = { 0x209, 0x33B, 0x480, 
    0x1, D_803924A0,
    func_8038F144, func_80326224, func_8038F0F0,
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803924F8 = { 0x20A, 0x33C, 0x481, 
    0x1, D_803924A0,
    func_8038F144, func_80326224, func_8038F0F0,
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8D00/func_8038F0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_8D00/func_8038F144.s")
