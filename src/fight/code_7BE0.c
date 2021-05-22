#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038DFD0(ActorMarker *arg0) {
    Actor *sp1C;
    Actor *temp_v0;

    sp1C = marker_getActor(arg0);
    temp_v0 = spawn_child_actor(0x3A1, &sp1C);
    temp_v0->unkF4_8 = sp1C->unkF4_8;
    temp_v0->position_y = temp_v0->position_y + 155.0f;
    sp1C->unk100 = temp_v0->marker;
}

extern s32 D_80391A64;
extern s32 D_80391A98;
extern s32 D_80391A70;
extern u32 D_80391B48;
extern u32 D_80391B54;
extern u32 D_80391B94;
extern u32 D_80391B84;

void func_80386654(f32, void *, void *);
void func_8038E03C(f32*, u32);

void func_8038E03C(f32 *arg0, u32 arg1) {
    Actor *temp_v0 = func_802F0BD0(arg1);

    func_802EF950(temp_v0, 0x70E);
    func_802EFFA8(temp_v0, &D_80391A64);
    func_802EFA90(temp_v0, 0, 7);
    func_802EFB54(temp_v0, arg0);
    func_802EFD00(temp_v0, &D_80391A98);
    func_802EFB98(temp_v0, &D_80391A70);
    func_802EF5C8(temp_v0, arg1);
}

void func_8034DE60(s32, f32, f32, f32, s32);

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
    func_802C3F04(&func_802C4140, 0x3AD, *(u32 *)(&sp24->unk1C), *(u32 *)(&sp24->unk20), *(u32 *)(&sp24->unk24));
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

void func_8038EB90(ActorMarker *arg0, f32 *arg1) {
    Actor *temp_v0;

    temp_v0 = marker_getActor(arg0);
    temp_v0->position_x = arg1[0];
    temp_v0->position_y = arg1[1];
    temp_v0->position_z = arg1[2];
    temp_v0->position_y = temp_v0->position_y + 210.0f;
}

void func_8038EBE0(f32 *arg0, u32 arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg8) {
    Actor *temp_v0 = func_802F0BD0(arg1);

    func_802EF950(temp_v0, arg2);
    func_802EFA90(temp_v0, 1, 6);
    func_802EFB54(temp_v0, arg0);
    func_802EFB1C(temp_v0, arg3[0], arg3[1], arg3[2], arg3[3], arg3[4], arg3[5]);
    func_802EF9AC(temp_v0, arg4[0], arg4[1], arg4[2], arg4[3], arg4[4], arg4[5]);
    func_802EFED4(temp_v0, arg5[0], arg5[1], arg5[2], arg5[3], arg5[4], arg5[5]);
    func_802EFE24(temp_v0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB70(temp_v0, arg6[0], arg6[1]);
    func_802EFB84(temp_v0, arg6[2], arg6[3]);
    func_802EF9F8(temp_v0, 0.5f);
    func_802EFA18(temp_v0, 3);
    func_802EFE5C(temp_v0, arg7[0], arg7[1]);
    func_802EFEC0(temp_v0, arg7[2], arg7[3]);
    func_802EFA5C(temp_v0, arg8[0], arg8[1]);
    func_802EFA78(temp_v0, 1);
    func_802EFA70(temp_v0, 4);
    func_802EF5C8(temp_v0, arg1);
}

void func_8038ED9C(f32 *arg0, u32 arg1, s32 arg2, s32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7) {
    Actor *temp_v0 = func_802F0BD0(arg2);

    func_802EF950(temp_v0, arg1);
    func_802EFA90(temp_v0, arg3[0], arg3[1]);
    func_802EFA9C(temp_v0, 8.0f, 8.0f);
    func_802EFB54(temp_v0, arg0);
    func_802EFB1C(temp_v0, arg4[0], arg4[1], arg4[2], arg4[3], arg4[4], arg4[5]);
    func_802EFED4(temp_v0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EFB70(temp_v0, arg5[0], arg5[1]);
    func_802EFB84(temp_v0, arg5[2], arg5[3]);
    func_802EFE5C(temp_v0, arg6[0], arg6[1]);
    func_802EFEC0(temp_v0, arg6[2], arg6[3]);
    func_802EFA5C(temp_v0, arg7[0], arg7[1]);
    func_802EFA70(temp_v0, 0x10);
    func_802EFA78(temp_v0, 1);
    func_802EF5C8(temp_v0, arg2);
}

void func_8038EEFC(f32 *arg0, u32 arg1, f32 *arg2) {
    Actor *temp_v0 = func_802F0BD0(arg1);

    func_802EF950(temp_v0, 0x70E);
    func_802EFFA8(temp_v0, &D_80391B48);
    func_802EF9E4(temp_v0, 0xEB);
    func_802EFA90(temp_v0, 0, 7);
    func_802EFB54(temp_v0, arg0);
    func_802EFD00(temp_v0, &D_80391B54);
    func_802EFB70(temp_v0, 0.1f, 0.2f);
    func_802EFB84(temp_v0, 3.6f, 4.6f);
    func_802EFE5C(temp_v0, arg2[0], arg2[1]);
    func_802EFEC0(temp_v0, arg2[2], arg2[3]);
    func_802EFA5C(temp_v0, 0.05f, 0.1f);
    func_802EFA70(temp_v0, 0x10);
    func_802EFA78(temp_v0, 1);
    func_802EF5C8(temp_v0, arg1);
}

void func_8038F01C(void) {
    func_80386654(1.0f, &D_80391B94, &D_80391B84);
}

void func_8038F050(void) {
    func_80386654(1.0f, &D_80391B84, &D_80391B94);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7BE0/func_8038F084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7BE0/func_8038F3B4.s")

s32 func_8038F5BC(f32 *arg0, f32 arg1) {
    if (((arg0[0] * arg0[0]) + (arg0[2] * arg0[2])) < arg1) {
        return 1;
    }
    return 0;
}

void func_8038F5F8(s32 arg0) {
    func_80324D2C(0.0f, SFX_ENTER_MAP_GLITTER);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7BE0/func_8038F620.s")

void func_8038FB84(ActorMarker *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    Actor *temp_v0 = marker_getActor(arg0);

    temp_v0->position_x = arg1[0];
    temp_v0->position_y = arg1[1];
    temp_v0->position_z = arg1[2];
    temp_v0->velocity_x = arg2[0];
    temp_v0->velocity_y = arg2[1];
    temp_v0->velocity_z = arg2[2];
    temp_v0->unk1C = arg3[0];
    temp_v0->unk20 = arg3[1];
    temp_v0->unk24 = arg3[2];
}

extern u8 D_803928E0;
extern u8 D_803928E1;
extern u8 D_803928E2;
extern u8 D_803928E3;
extern u8 D_803928E4;
extern u8 D_803928E5;

void func_8038FC00(void) {
    D_803928E0 = (u8)0;
    D_803928E1 = (u8)0;
    D_803928E2 = (u8)0;
    D_803928E3 = (u8)0;
    D_803928E4 = (u8)0;
}

void func_8038FC2C(s32 arg0) {
    D_803928E5 = arg0;
}
