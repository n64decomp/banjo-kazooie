#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038FC30;
extern f32 D_8038FC34;
extern f32 D_8038FC38;
extern f32 D_8038FC3C;

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_50D0/func_8038B4C0.s")

void func_8038B58C(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);
    
    func_8030E878(0x81, randf2(1.0f, D_8038FC30), (u32) (s32) randf2(D_8038FC34, 32000.0f), actor->position, 500.0f, D_8038FC38);
}

void func_8038B610(ActorMarker* marker) {
    Actor* actor;
    s32 temp_s0;
    f32 sp24;
    s32 sp20;

    actor = marker_getActor(marker);
    temp_s0 = func_802F9AA8(0x12B);
    sp24 = randf2(1.0f, 1.0f);
    sp20 = randf2(D_8038FC3C, 32000.0f);
    func_802F9DB8(temp_s0, sp24, sp24, 0.0f);
    func_802F9EC4(temp_s0, actor->position, 0xC8, 0x7D0);
    func_802F9F80(temp_s0, 0.05f, 0.2f, 0.3f);
    func_802FA060(temp_s0, sp20, sp20, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_50D0/func_8038B6DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_50D0/func_8038B814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_50D0/func_8038B87C.s")
