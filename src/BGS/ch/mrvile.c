#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"


void func_8038C48C(void *);
void func_8038C1B4(ActorMarker*, Gfx **, Mtx **);

ActorInfo D_80390A70 = {0xC8, 0x13A, 0x373, 0x00, NULL,
    func_8038C48C, NULL, func_8038C1B4,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

f32 D_80390A94[7] = {0.0f, 0.8f, 0.9f, 1.0f, 0.9f, 0.95f, 1.0f};

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038B9F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BD84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C0C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C1B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C3DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C48C.s")
