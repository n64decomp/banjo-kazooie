#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8034A754(f32, f32);
void func_80354030(f32*, f32);
void func_8028A274(s32, f32);

f32  func_8029B2E8(void);
void func_802991B4(f32);
f32 func_8029B33C(void);
void func_8029797C(f32);
f32 func_80299228(void);
void func_80297970(f32);
void func_80297BEC(f32);

extern  u8 D_8037D2C0;

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

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/beeFly/func_802A0590.s")
void func_802A0590(void){
    func_802A0340();
    func_8028A274(0x1df, 1.5f);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f){
        func_802991B4(func_8029B33C());
    }
    func_8029797C(func_80299228());
    func_80297970(0.0f);
    func_80297BEC(-1200.0f);
    D_8037D2C0 = 0;
}

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
