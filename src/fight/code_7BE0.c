#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8034DE60(s32, f32, f32, f32, s32);
void func_80386654(f32 arg0, f32 (*arg1)[4], f32 (*arg2)[4]);

/* .data */

extern s32 D_80391A64[3];
extern struct42s D_80391A98;
extern struct31s D_80391A70;

extern ActorInfo D_80391AD0;


/* .code */ 
void func_8038DFD0(ActorMarker *arg0) {
    Actor *sp1C;
    Actor *temp_v0;

    sp1C = marker_getActor(arg0);
    temp_v0 = spawn_child_actor(0x3A1, &sp1C);
    temp_v0->unkF4_8 = sp1C->unkF4_8;
    temp_v0->position_y = temp_v0->position_y + 155.0f;
    sp1C->unk100 = temp_v0->marker;
}

void func_8038E03C(f32 (*arg0)[3], u32 arg1) {
    struct30s *temp_v0 = func_802F0BD0(arg1);

    func_802EF950(temp_v0, 0x70E);
    func_802EFFA8(temp_v0, &D_80391A64);
    func_802EFA90(temp_v0, 0, 7);
    func_802EFB54(temp_v0, arg0);
    func_802EFD00(temp_v0, &D_80391A98);
    func_802EFB98(temp_v0, &D_80391A70);
    func_802EF5C8(temp_v0, arg1);
}

void func_8038E0D4(Actor *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_v0 = func_8034C2C4(arg0->marker, arg1);

    if (temp_v0) {
        func_8034DE60(temp_v0, arg2, arg3, arg4, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7BE0/func_8038E120.s")

void func_8038E260(ActorMarker *arg0) {
    Actor *sp24 = marker_getActor(arg0);

    func_802BB3DC(0, 18.0f, 0.92f);
    func_802C3F04(&func_802C4140, 0x3AD, *(u32 *)(&sp24->unk1C_x), *(u32 *)(&sp24->unk1C_y), *(u32 *)(&sp24->unk1C_z));
    func_8038E03C(&sp24->unk1C, 0x10);
}

void func_8038E2CC(ActorMarker *arg0) {
    func_8032BB88(marker_getActor(arg0), -1, 0x7FFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7BE0/func_8038E2FC.s")

void func_8038E780(ActorMarker *arg0, s32 arg1) {
    Actor *sp1C;
    ActorLocal_fight_7BE0 *sp18;

    sp1C = marker_getActor(arg0);
    sp18 = &sp1C->fight_7BE0;
    sp1C->fight_7BE0.unk0 = 0xFF;
    sp1C->fight_7BE0.unk4 = 0;
    if (func_8030E3FC(sp1C->fight_7BE0.unk10) == 0) {
        func_8030E2C4(sp18->unk10);
    }
    if (func_8030E3FC(sp1C->unk44_31) == 0) {
        func_8030E2C4(sp1C->unk44_31);
    }
}

void func_8038E7EC(Actor *arg0) {
    ActorLocal_fight_7BE0 *temp_v0 = &arg0->fight_7BE0;

    if ((u8)arg0->unk44_31) {
        func_8030DA44(arg0->unk44_31);
        arg0->unk44_31 = 0;
    }
    if (temp_v0->unk10 != 0) {
        func_8030DA44(temp_v0->unk10);
        temp_v0->unk10 = (u8)0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7BE0/func_8038E844.s")


