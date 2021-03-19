#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803885D0(Actor *);
Actor *func_80325888(ActorMarker *, Gfx **, Mtx**, u32);

ActorAnimationInfo chlmonkeyAnimations[5] = {
    {0, 0.0f},
    {0x5C, 2.3f},
    {0x5B, 0.67f},
    {0x5D, 0.5f},
    {0x5C, 2.3f}
};

ActorInfo chlmonkeyInfo = { 0xA, actor_chimpy, model_chimpy, 1, chlmonkeyAnimations,
    NULL, func_803885D0, func_80325888,
    {0x09,0xC4,0,0}, 0.8f, {0,0,0,0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/lmonkey/func_80388300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/lmonkey/func_803883AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/lmonkey/func_803884C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/lmonkey/func_80388514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/lmonkey/func_803885D0.s")
