#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f64 D_80392470;
extern f32 D_80392478;
extern f32 D_80392758[];
extern f32 D_80392768[];
extern f32 D_80392778[];
extern f32 D_80392798[];
extern ActorMarker *D_803927A4;
extern ActorMarker *D_803927A8;
extern u8 D_803927C4;
extern u8 D_803927C5;
extern u8 D_803927C7;
extern u8 D_803927C8;
extern u8 D_803927C9;
extern s32 D_80391524;
extern s32 D_80391530;
extern s32 D_8039153C;
extern s32 D_80391564;
extern s32 D_803915AC;
extern s32 D_803915B8;
extern s32 D_803915E8;
extern s32 D_80391618;
extern s32 D_80391648;
extern s32 D_80391678;
extern s32 D_803916F4;
extern s32 D_80391700;
extern s32 D_8039170C;
extern f32 D_803920C8;
extern f32 D_803920CC;
extern f32 D_803920D0;
extern f32 D_803920D4;
extern f32 D_803920D8;
extern f32 D_803920DC;
extern f32 D_803920E0;
extern f32 D_803920E4;
extern f32 D_803920E8;
extern f32 D_803920EC;
extern f32 D_803920F0;
extern f32 D_803920F4;

void func_80386570(ActorMarker *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Actor *temp_v0;
    ActorLocal_fight_180 *localActor;

    temp_v0 = marker_getActor(arg0);
    localActor = &temp_v0->fight_180;
    func_8033A45C(3, localActor->unkD);
    func_8033A45C(4, localActor->unkE);
    func_8033A45C(5, localActor->unkC);
    if (localActor->unk0 == 1) {
        func_8033A25C(0);
    }
    func_80325888(arg0, arg1, arg2, arg3);
}

void func_80386600(ActorMarker *arg0, s32 arg1) {
    marker_getActor(arg0)->fight_180.unkC = arg1;
}

void func_80386628(ActorMarker *arg0, s32 arg1) {
    Actor *temp_v0;

    temp_v0 = marker_getActor(arg0);
    temp_v0->fight_180.unkD = arg1;
    temp_v0->fight_180.unkE = arg1;
}

void func_8034DF30(s32, s32, s32, f32);

void func_80386654(f32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_8034C528(0x190); // TODO sizeof?
    if (temp_v0 != 0) {
        func_8034DF30(temp_v0, arg1, arg2, arg0);
    }
}

void func_8034DDF0(s32, s32*, s32*, f32, s32);

void func_80386698(f32 arg0) {
    s32 temp_v0;

    temp_v0 = func_8034C528(0x19A); // TODO sizeof?
    if (temp_v0 != 0) {
        func_8034DDF0(temp_v0, &D_80391524, &D_80391530, arg0, 1);
    }
}

void func_802EFE24(Actor *, f32, f32, f32, f32, f32, f32);

void func_803866E4(s32 arg0, s32 arg1, s32 arg2) {
    Actor *temp_s0;
    Actor *temp_v0;

    temp_v0 = func_802F0BD0(arg2);
    temp_s0 = temp_v0;
    func_802EFAC8(temp_v0, arg1);
    func_802EFB54(temp_s0, arg0);
    func_802EFE24(temp_s0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFD7C(temp_s0, &D_80391564);
    func_802EFB98(temp_s0, &D_8039153C);
    func_802EFA78(temp_s0, 1);
    func_802EF5C8(temp_s0, arg2);
}

void func_802EFD00(s32, s32*);
void func_802EFE5C(Actor *, f32, f32);
void func_802EFEC0(Actor *, f32, f32);
void func_802EFA5C(Actor *, f32, f32);

void func_8038679C(f32 *arg0, s32 arg1, f32 *arg2) {
    Actor *temp_s0;
    Actor *temp_v0;

    temp_v0 = func_802F0BD0(arg1);
    temp_s0 = temp_v0;
    func_802EF950(temp_v0, 0x70E);
    func_802EFFA8(temp_s0, &D_803915AC);
    func_802EFA90(temp_s0, 0, 7);
    func_802EFB54(temp_s0, arg0);
    func_802EFD00(temp_s0, &D_803915B8);
    func_802EFB70(temp_s0, arg2[0], arg2[1]);
    func_802EFB84(temp_s0, arg2[2], arg2[3]);
    func_802EFE5C(temp_s0, 0.0f, 0.01f);
    func_802EFEC0(temp_s0, 2.8f, 3.2f);
    func_802EFA5C(temp_s0, 0.3f, 0.4f);
    func_802EFA78(temp_s0, 1);
    func_802EF5C8(temp_s0, arg1);
}

void func_803868A0(f32 *arg0, s32 arg1) {
    Actor *temp_s0;
    Actor *temp_v0;

    temp_v0 = func_802F0BD0(1);
    temp_s0 = temp_v0;
    func_802EF950(temp_v0, 0x45A);
    func_802EFA90(temp_s0, 2, 2);
    func_802EFFA8(temp_s0, arg1);
    func_802EFB54(temp_s0, arg0);
    func_802EFA78(temp_s0, 1);
    func_802EFD00(temp_s0, &D_80391618);
    func_802EFC28(temp_s0, &D_803915E8);
}

void func_80386934(f32 *arg0, s32 arg1) {
    Actor * temp_s0;
    Actor * temp_v0;

    temp_v0 = func_802F0BD0(1);
    temp_s0 = temp_v0;
    func_802EF950(temp_v0, arg1);
    func_802EFA90(temp_s0, 1, 6);
    func_802EFB54(temp_s0, arg0);
    func_802EFA78(temp_s0, 1);
    func_802EFD7C(temp_s0, &D_80391678);
    func_802EFC28(temp_s0, &D_80391648);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_803869BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80386B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80386BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80386C68.s")

void func_8025727C(f32, f32, f32, f32, f32, f32, f32*, f32*);

void func_80256900(f32 *, f32 *, f32, Actor *);

void func_80386CF8(Actor *actor) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    sp28[0] = actor->position[0];
    sp28[1] = actor->position[1];
    sp28[2] = actor->position[2];
    sp28[1] += 220.0f;
    sp34[1] = 0.0f;
    sp34[0] = 0.0f;
    sp34[2] = 1000.0f;
    func_80256900(sp34, sp34, actor->yaw, actor);
    sp4C[0] = sp28[0] + sp34[0];
    sp4C[1] = sp28[1] + sp34[1];
    sp4C[2] = sp28[2] + sp34[2];
    func_8025727C(sp28[0], sp28[1], sp28[2], sp4C[0], sp4C[1], sp4C[2], &sp40[0], &sp40[1]);
    sp40[0] = 360.0f - sp40[0];
    sp40[2] = 0.0f;
    func_802BAE6C(sp4C, sp40);
}

void func_802C8F70(f32);
s32 func_803297C8(Actor*, s32*);

void func_80386DE4(ActorMarker *arg0) {
    Actor *actor;

    actor = marker_getActor(arg0);
    func_802C8F70(func_803297C8(actor, &D_803916F4));
    func_802C937C(0x14, &actor->position_x);
}

void func_80386E34(void) {
    marker_despawn(D_803927A8);
    D_803927A8 = NULL;
}

Actor *func_8032813C();

void func_80386E5C(ActorMarker *arg0);

// void func_80386E5C(s32 arg0) {
//     s16 *temp_v1;
//     Actor *temp_v0;

//     temp_v0 = func_8032813C(0x39F, &D_80391700, D_8039170C);
//     temp_v1 = temp_v0->unk124;
//     temp_v0->unk124 = (u32) (((u32) ((temp_v1 >> 0xC) << 0x18) >> 0xC) ^ temp_v1);
//     temp_v0->unk38 = (u16) ((temp_v0->unk38 & 0x3F) | 0x180);
//     D_803927A8 = (s32) temp_v0->unk0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80386E5C.s")

void func_8030E878(s32, f32, s32, f32*, f32, f32);
void func_803900DC(ActorMarker *, f32 *, f32, f32);

void func_80386EC0(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x38A, D_80392758, 0)->marker;
    func_8030E878(0x147, randf2(D_803920C8, D_803920CC), 0x7D00, D_80392758, D_803920D0, D_803920D4);
    func_803900DC(marker, D_80392758, D_80392768[1], D_80392768[2]);
}

void func_802C3C88(void (* arg0)(ActorMarker*), s32 arg1);

// void func_80386F5C(s32 arg0, f32 *arg1, f32 arg2, f32 arg3) {
//     arg1[1] = (f32) (arg1[1] + 100.0f);
//     D_80392758[0] = (f32) arg1[0];
//     D_80392758[1] = (f32) arg1[1];
//     D_80392758[2] = (f32) arg1[2];
//     D_80392768[1] = arg2;
//     D_80392768[2] = arg3;
//     func_802C3C88(func_80386EC0, arg0);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80386F5C.s")

void func_80386FD8(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x389, D_80392758, 0)->marker;
    func_8030E878(0x146, randf2(D_803920D8, D_803920DC), 0x7D00, D_80392758, D_803920E0, D_803920E4);
    func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387074(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x3AA, D_80392758, 0)->marker;
    func_8030E878(0x146, randf2(D_803920E8, D_803920EC), 0x7D00, D_80392758, D_803920F0, D_803920F4);
    func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387110.s")

void func_80387110(ActorMarker *, f32*, f32, s32);

void func_803872F8(Actor *arg0) {
    f32 vec[3];

    func_8034A174(arg0->marker->unk44, 0xA, vec);
    func_80387110(arg0->marker, vec, 3.0f, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387340.s")

s32 actor_animationIsAt(Actor *, f32);

void func_803873DC(Actor *actor, s32 arg1, s32 arg2) {
    f32 vec[3];
    ActorMarker *marker;

    if (actor_animationIsAt(actor, 0.5f) != 0) {
        marker = actor->marker;
        if (marker->unk14_21) {
            func_8034A174(marker->unk44, 6, vec);
        } else {
            vec[0] = actor->position[0];
            vec[1] = actor->position[1];
            vec[2] = actor->position[2];
        }
        func_80386F5C(actor->marker, vec, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387470.s")

void func_8038770C(Actor *actor) {
    actor->fight_180.pad1 = 0;
    actor->fight_180.pad2 = 0;
    actor->fight_180.pad3 = 0;
    actor->fight_180.pad4 = 0;
    actor->fight_180.pad6 = 0;
    actor->fight_180.padA = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387728.s")

void func_80387ACC(Actor *arg0, s32 arg1) {
    func_80328CA8(arg0, 0);
    func_80328FF0(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387E1C.s")

extern f32 D_803927D0[][3];

void func_80387F70(Actor *actor, f32 *arg1, f32 arg2) {
    ActorLocal_fight_180 *temp_v0 = &actor->fight_180;
    f32 vec[3];
    f32 playerPos[3];

    player_getPosition(&playerPos);
    vec[0] = D_803927D0[temp_v0->pad5][0] - playerPos[0];
    vec[1] = D_803927D0[temp_v0->pad5][1] - playerPos[1];
    vec[2] = D_803927D0[temp_v0->pad5][2] - playerPos[2];
    func_80256450(vec);
    arg1[0] = D_803927D0[temp_v0->pad5][0] + (arg2 * vec[0]);
    arg1[1] = D_803927D0[temp_v0->pad5][1] + (arg2 * vec[1]);
    arg1[2] = D_803927D0[temp_v0->pad5][2] + (arg2 * vec[2]);
}

void func_803880A0(Actor *actor, f32 arg1) {
    actor->velocity[2] = arg1;
    actor->velocity[1] = 0.0f;
    actor->velocity[0] = 0.0f;
    func_80256900(actor->velocity, actor->velocity, actor->yaw, actor);
}

void func_803880E0(ActorMarker *arg0, s32 arg1, s32 arg2) {
    func_80388184(marker_getActor(arg0), 0xC);
}

void func_80388110(ActorMarker *arg0, s32 arg1, s32 arg2) {
    Actor *actor;
    ActorLocal_fight_180 *actorLocal;

    actor = marker_getActor(arg0);
    actorLocal = &actor->fight_180;
    func_802BAE4C();
    func_80311480(randi2(0, 5) + 0x1101, 4, 0, actor->marker, func_803880E0, 0);
    actorLocal->pad9 = (u8)1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80388184.s")

void func_8038856C(Actor *actor, f32 *arg1) {
    f32 vec[3];
    ActorMarker *marker;

    marker = actor->marker;
    if (marker->unk14_21) {
        func_8034A174(marker->unk44, 7, vec);
    } else {
        vec[0] = actor->position[0];
        vec[1] = actor->position[1];
        vec[2] = actor->position[2];
    }
    func_8038679C(vec, 2, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_803885DC.s")

s32 func_8038871C(Actor *arg0, f32 arg1, f32 arg2) {
    if (arg0->position[1] + arg2 > arg1) {
        arg0->position[1] = arg1;
        return 1;
    }
    else
    {
        arg0->position[1] = arg0->position[1] + arg2;
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80388758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_803891E4.s")

void func_80389358(s32 arg0, s32 arg1, s32 arg2) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_80386E5C, *arg0ptr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038938C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80389720.s")

void func_80389720();

void func_803898A4(s32 arg0) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_80389720, *arg0ptr);
}

void func_803898D0(ActorMarker *marker) {
    Actor *actor;

    actor = marker_getActor(marker);
    actor->unk100 = spawn_child_actor(0x3AB, &actor)->marker;
    D_803927C5 = (u8)1;
}

void func_80389918(s32 arg0) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_803898D0, *arg0ptr);
}

void func_80324E38(f32, s32);

void func_80389944(ActorMarker *marker, s32 arg1, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(marker);
    func_802BAE4C();
    func_80324E38(0, 0);
    func_80387728(actor->marker, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038998C.s")

void func_80389B44(s32 arg0) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_80386DE4, *arg0ptr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80389B70.s")

void func_80389F54(void) {
    func_80320004(0xD2, 1);
    D_803927C4 = (u8)0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80389F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038A4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038A5F4.s")

void func_80328B8C(Actor *, s32, f32, s32);

void func_8038AC50(ActorMarker *arg0) {
    func_80328B8C(marker_getActor(arg0), 0x24, 0.0001f, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038AC88.s")

void func_8038AF84(ActorMarker *arg0) {
    func_8038AC88(marker_getActor(arg0), 0x29);
}

void func_8038AFB0(void) {
    func_802E4078(0x87, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038AFD8.s")

void func_80324E88(f32);

void func_8038B730(ActorMarker *arg0, s32 arg1, s32 arg2) {
    Actor *sp1C;

    sp1C = marker_getActor(arg0);
    func_802BE720();
    func_80324E88(0);
    func_8028F784(0);
    func_80387728(sp1C->marker, 1);
}

void func_8038B780(ActorMarker *arg0) {
    Actor *sp24;

    sp24 = marker_getActor(arg0);
    if (!func_8031FF1C(0xCF)) {
        sp24 = sp24;
        func_80320004(0xCF, 1);
        func_80311480(0x10E7, 0x2A, &sp24->position_x, sp24->marker, &func_8038B730, 0);
        return;
    }
    sp24 = sp24;
    func_80311480(randi2(0, 5) + 0x10E8, 0x2B, &sp24->position_x, sp24->marker, &func_8038B730, 0);
}

void func_8038B82C(s32 arg0) { }

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038B834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038B9AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038BB8C.s")

void func_8038BCB8(ActorMarker *arg0) {
    Actor *sp1C;

    sp1C = marker_getActor(arg0);
    D_803927A4 = spawn_child_actor(0x3AF, &sp1C)->marker;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038BCF0.s")

void func_8038C0DC(f32 *arg0) {
    arg0[0] = D_80392798[0];
    arg0[1] = D_80392798[1];
    arg0[2] = D_80392798[2];
}

void func_8038C100() {
    D_803927C5 = 0;
}

void func_8038C10C(s32 arg0) {
    func_8038AC88(marker_getActor((ActorMarker*)arg0), 0x28);
}

void func_8038C138() {
    D_803927C7 = 1;
}

Actor *func_80326EEC(s32);
f32 func_80391234();
f32 func_8038DFA0();
void func_80324E88(f32);
f32 func_80391240();

void func_80324E60(f32, s32);

// Very minor stack diff
// void func_8038C148(void) {
//     Actor *temp_v0;
//     ActorLocal_fight_180 *temp_t6;
//     f32 temp_f12;
//     f32 sp40;
//     f32 temp_f20;
//     s32 phi_s0;
//     f32 new_var;
//     f32 temp_f12_2;

//     temp_v0 = func_80326EEC(0x38B);
//     temp_t6 = &temp_v0->fight_180;
//     new_var = func_8038DFA0();
//     temp_f20 = new_var + func_80391234();
//     sp40 = func_80391240();
//     phi_s0 = 0x14;
//     func_80320004(0xFC, 1);
//     if (temp_t6->pad7 != 0) {
//         phi_s0 = 0x23;
//     }
//     func_8038AC88(temp_v0, 0x27);
//     temp_t6->pad8 = (u8)1;
//     func_80324E38(0, 1);
//     func_80324E60(0, phi_s0);
//     func_80324E88(temp_f20);
//     timedFunc_set_0(temp_f20 * D_80392470, &func_8038C138);
//     func_80324E60(temp_f20, phi_s0 + 1);
//     temp_f12 = temp_f20 + sp40;
//     func_80324E88(temp_f12);
//     timedFunc_set_1(temp_f12, func_8038C10C, (s32)temp_v0->marker);
//     func_80324E60(temp_f12, phi_s0 + 2);
//     temp_f12_2 = temp_f12 + D_80392478;
//     func_80324E88(temp_f12_2);
//     func_80324E60(temp_f12_2, phi_s0 + 3);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038C148.s")

void func_8038C27C(s32 arg0) {
    D_803927C4 = arg0;
}

f32 func_8038C288() {
    return 3.0f;
}

s32 func_8038C298() {
    return D_803927C7;
}

s32 func_8038C2A4() {
    return D_803927C8;
}

s32 func_8038C2B0() {
    return D_803927C9;
}
