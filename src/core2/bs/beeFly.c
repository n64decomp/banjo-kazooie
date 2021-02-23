#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8034A754(f32, f32);
void func_80354030(f32*, f32);


//#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A04F0.s")
void func_802A04F0(void){
    f32 plyrPos[3]; //sp1C

    player_getPosition(plyrPos);
    plyrPos[0] += func_8034A754(-30.0f, 30.0f);
    plyrPos[1] += 30.0f + func_8034A754(0.0f, 30.0f);
    plyrPos[2] += func_8034A754(-30.0f, 30.0f);
    func_803541C0(3);
    func_803541CC(0x50);
    func_80354030(plyrPos, 0.5f);

}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A077C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A07F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A09A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0F78.s")
