#include <ultra64.h>
#include "functions.h"
#include "variables.h"
void func_8034DE60(s32, f32, f32, f32, s32);

void func_8038D280(ActorMarker *arg0) {
    Actor *sp1C = marker_getActor(arg0);
    Actor *temp_v0 = spawn_child_actor(0x3A1, &sp1C);

    temp_v0->unkF4_8 = sp1C->unkF4_8;
    temp_v0->position_y = temp_v0->position_y + 172.0f;
    sp1C->unk100 = temp_v0->marker;
}

s32 D_803919B4[3];
struct31s D_803919C0;

void func_8038D2EC(f32 (*arg0)[3], s32 arg1) {
    struct30s *temp_v0 = func_802F0BD0(arg1);
    
    func_802EF950(temp_v0, 0x70E);
    func_802EFFA8(temp_v0, &D_803919B4);
    func_802EFA90(temp_v0, 0, 7);
    func_802EFB54(temp_v0, arg0);
    func_802EFB1C(temp_v0, -90.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    func_802EFED4(temp_v0, -170.0f, 0.0f, -170.0f, 170.0f, 100.0f, 170.0f);
    func_802EFB98(temp_v0, &D_803919C0);
    func_802EF5C8(temp_v0, arg1);
}

void func_8034DE60(s32, f32, f32, f32, s32);

void func_8038D3DC(Actor* this, s32 arg1, f32 arg2, f32 arg3, f32 arg4){
    s32 tmp = func_8034C2C4(this->marker, arg1);
    
    if(tmp){
        func_8034DE60(tmp, arg2, arg3, arg4, 1);
    }
}

extern f32 D_80392530;
extern f32 D_80392534;

void func_8038D3DC(Actor *, s32, f32, f32, f32);
void func_80324D54(f32, u32, f32, u32, f32 *, f32, f32);

void func_8038D428(ActorMarker *arg0, s32 arg1) {
    Actor *temp_v0;
    Actor *s0;

    temp_v0 = marker_getActor(arg0);
    if (temp_v0->state != 3) {
        func_8025A70C(SFX_DING_B);
        temp_v0->unk38_31++;
        if (temp_v0->unk38_31 >= 3) {
            func_80328A84(temp_v0, 3);
            func_8038DE98(temp_v0->unk100);
            func_8038D3DC(temp_v0, 0x19A, -100.0f, 0.0f, D_80392530);
            func_80324D54(D_80392534, 0x90, 1.0f, 0x7D00, &temp_v0->position_x, 1000.0f, 2000.0f);
        }
    }
}

void func_8038D510(Actor *arg0) {
    ActorLocal_fight_6E90 *sp18 = &arg0->fight_6E90;

    if ((u8)arg0->unk44_31 != 0) {
        func_8030DA44(arg0->unk44_31);
        arg0->unk44_31 = 0;
    }
    if (sp18->unk0 != 0) {
        func_8030DA44(sp18->unk0);
        sp18->unk0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_6E90/func_8038D568.s")
