#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"


void func_8038F6A4(ActorMarker *);
void func_80326224(ActorMarker *);
void func_80325888(ActorMarker*, Gfx **, Mtx **);

ActorAnimationInfo D_80390C20[] = {
    {0, 0.0f},
    {0x101, 7.5f},
    {0x102, 1.75f},
    {0x107, 1.75f}
};

ActorInfo D_80390C40 = {0x6C, 0xE8, 0x3EE, 0x01, D_80390C20,
    func_8038F6A4, func_80326224, func_80325888,
    {0,0,0,0x80}, 0.0f, {0,0,0,0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F6A4.s")
