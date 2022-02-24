#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038FC80;
extern f32 D_8038FC84;
extern f32 D_8038FC88;
extern f32 D_8038FC8C;
extern f32 D_8038FC90;
extern f32 D_8038FC94;
extern f32 D_8038FC98;
extern f32 D_8038FC9C;
extern f32 D_8038FCA0;
extern f32 D_8038FCA4;
extern f32 D_8038FCA8;
extern f32 D_8038FCAC;
extern f32 D_8038FCB0;

void func_8038B930(ActorMarker* marker, s32 arg1) {
    func_8038B95C(marker_getActor(marker), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_5540/func_8038B95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_5540/func_8038BB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_5540/func_8038BC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_5540/func_8038BC74.s")

void func_8038BFE0(ActorMarker* marker) {
    Actor* sp2C = marker_getActor(marker);
    func_8030E878(0x5D, randf2(1.0f, D_8038FC80), (u32) (s32) randf2(D_8038FC84, D_8038FC88), sp2C->position, 500.0f, D_8038FC8C);
}

void func_8038C064(ActorMarker* marker) {
    Actor* sp2C = marker_getActor(marker);
    func_8030E878(0x5E, randf2(1.0f, D_8038FC90), (u32) (s32) randf2(D_8038FC94, D_8038FC98), sp2C->position, 500.0f, D_8038FC9C);
}

void func_8038C0E8(ActorMarker* marker) {
    Actor* sp24 = marker_getActor(marker);
    f32 sp20 = randf2(D_8038FCA0, D_8038FCA4);

    func_8030E878(0x81, sp20, (u32) (s32) randf2(D_8038FCA8, D_8038FCAC), sp24->position, 500.0f, D_8038FCB0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_5540/func_8038C16C.s")

void func_8038C380(ActorMarker* marker, Gfx** graphics, Mtx** matrix, Vtx** vertex) {
    func_8033A45C(3, 0);
    func_8033A45C(4, 0);
    func_8033A45C(5, 0);
    func_8033A45C(6, 1);
    func_8033A45C(7, 0);
    func_8033A45C(8, 0);
    func_8033A45C(9, 0);
    func_8033A45C(0xA, 1);
    func_80325888(marker, graphics, matrix, vertex);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_5540/func_8038C41C.s")
