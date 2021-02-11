#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"



void   func_80326224(Actor *);
Actor* func_80325888(ActorMarker *, Gfx **, Mtx**, u32);


void func_8038F6A4(Actor *);
void func_8038FBF8(Actor *);

/* .data */
//padding indicates seperate headers for each part ??
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
u8 pad_80390C6C[0xC] = {0};


ActorAnimationInfo D_80390C70[3] = {
    {0, 0.0f},
    {0x103, 8000000.0f},
    {0x103, 0.75f}
};

ActorInfo D_80390C88 = {0x6D, 0xE9, 0x3EF, 0x01, D_80390C70,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};
u8 pad_80390CCC[4] = {0};

ActorAnimationInfo D_80390CB0[3] = {
    {0, 0.0f},
    {0x104, 8000000.0f},
    {0x104, 0.75f}
};

ActorInfo D_80390CC8 = {0x6D, 0xEA, 0x3F0, 0x01, D_80390CB0,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};
u8 pad_80390CEC[4] = {0};

ActorAnimationInfo D_80390CF0[3] = {
    {0, 0.0f},
    {0x105, 8000000.0f},
    {0x105, 0.75f}
};

ActorInfo D_80390D08 = {0x6D, 0xEB, 0x3F1, 0x01, D_80390CF0,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};
u8 pad_80390C2C[4] = {0};

ActorAnimationInfo D_80390C30[3] = {
    {0, 0.0f},
    {0x106, 8000000.0f},
    {0x106, 0.75f}
};

ActorInfo D_80390D48 = {0x6D, 0xEC, 0x3F2, 0x01, D_80390C30,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038FB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038FB84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038FBF8.s")
