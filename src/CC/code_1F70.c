#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_803884A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388518.s")

extern f32 D_80389C00[];
extern s32 D_80389FD4;

void func_80388664(void) {
    jiggySpawn(JIGGY_CC_CLANKER_RAISED, D_80389C00);
}

void func_80324E88(f32);
void func_80324DBC(f32, s32, s32, f32 *, ActorMarker *, void(*)(void), s32);

void func_8038868C(void) {
    func_80324E38(0, 3);
    func_80324E60(0, 0);
    func_80324E60(5.5f, 1);
    func_80324E60(7.0f, 2);
    func_80324E60(12.5f, 3);
    timedFunc_set_0(13.0f, &func_80388664);
    func_80324E60(16.0f, 1);
    if (jiggyscore_isCollected(0x17) == 0) {
        func_80324DBC(18.0f, 0xD2C, 4, NULL, NULL, NULL, 0);
    }
    func_80324E88(18.0f);
    func_80324E38(18.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388760.s")

void func_80388B4C(s32 arg0) {
    func_8034A174(D_80389FD4, 5, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388C50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80388F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_803894A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80389520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_8038954C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_1F70/func_80389594.s")
