#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038EC94;

void func_80387F10() {
    jiggySpawn(0x4DU, &D_8038EC94);
}

void func_80387F38(ActorMarker* marker, s32 arg1) {
    func_80387F64(marker_getActor(marker), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80387F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388260.s")

void func_80388278(s32 arg0, s32 arg1) {
    func_8025A6EC(COMUSIC_2B_DING_B, 0x6D60);
}

void func_803882A4(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    
    if (map_get() == MAP_43_CCW_SPRING && actor->state == 1) {
        func_80387F64(actor, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803882F4.s")

void func_803883F4() {
    Actor* actor = func_80326EEC(0x29D);
    if (actor && actor->state == 1) {
        func_80387F64(actor, 2);
    }
}

s32 func_80388438() {
    Actor* actor = func_80326EEC(0x29D);
    if (actor && actor->state == 2) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803885F8.s")

void func_80388660(ActorMarker* marker, s32 arg1) {
    func_8038868C(marker_getActor(marker), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_8038868C.s")

void func_8038894C(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        actor_collisionOff(actor);
        timedFunc_set_2(0.5f, func_80388660, actor->marker, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803889AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80388FD4.s")

void func_803891B0(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    actor->unk44_31 = func_8030ED2C(SFX_3EC_CCW_DOOR_OPENING, 3);
    func_8030DD90(actor->unk44_31, 0);
    func_8030DABC(actor->unk44_31, 0x2AF8);
    func_8030DBB4(actor->unk44_31, 0.3f);
    func_8030E2C4(actor->unk44_31);
}

void func_8038921C(void* marker) {
    Actor* actor = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    func_8030E394(actor->unk44_31);
    func_8030DA44(actor->unk44_31);
    actor->unk44_31 = 0U;
    func_8030E624(0x7FF8686CU);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80389268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80389440.s")

void func_8038950C(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        func_80389440(actor, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_8038954C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803895F4.s")

void func_80389700(s32 arg0, s32 arg1, s32 arg2) {
    func_80324E88(0.5f);
    func_80324E38(0.5f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80389740.s")

void func_80389798() {
    func_8030E6D4(SFX_EYRIE_MAMA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_803897B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80389B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80389BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_1B20/func_80389BFC.s")
