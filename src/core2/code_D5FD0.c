#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802DB548(s32, s32);

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC_31:3;
    u32 unkC_28:1;
    u32 padC_27:28;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s16 unk2A;
    f32 unk2C;
    void (*unk30)(ActorMarker *, s32);
    void (*unk34)(ActorMarker *, s32);
    u8 pad38[4];
    f32 unk3C;
}ActorLocal_core2_D5FD0;

void func_8035D058(Actor *this);

/* .data */
ActorAnimationInfo D_80372DA0[] = {
    {0, 0.0f},
    {0x1D6,      4.0f},
    {0x1D6,      0.7f},
    {0x1D8,      0.7f},
    {0x1D7,      0.9f},
    {0x1D9,      0.7f},
    {0x1D6,      1.5f},
    {0x1D8,      0.5f},
    {0x1D6,      1.5f},
    {0x1D6, 100000.0f},
    {0x1D6, 100000.0f}
};

ActorInfo D_80372DF8 = {
    MARKER_21A_SEAMAN_GRUBLIN, ACTOR_350_SEAMAN_GRUBLIN, ASSET_49D_MODEL_SEAMAN_GRUBLIN,
    0x1, D_80372DA0, 
    func_8035D058, func_80326224, actor_draw, 
    2500, 0, 1.0f, 0
};

/* .code */
void func_8035CF60(ActorMarker * marker, s32 arg1) {
    Actor *actor;

    actor = marker_getActor(marker);
    func_80328B8C(actor, 5, 0.0f, 1);
    actor_playAnimationOnce(actor);
    FUNC_8030E8B4(SFX_C2_GRUBLIN_EGH, 1.0f, 32000, actor->position, 1250, 2500);
    actor_collisionOff(actor);
}

void func_8035CFC4(Actor *this) {
    ActorLocal_core2_D5FD0 *local;

    local = (ActorLocal_core2_D5FD0 *)&this->local;
    local->unk0 = 4.0f;
    local->unk4 = 8.0f;

    local->unk8 = 6;
    local->unk9 = 0xA;
    local->unkA = 0xE;
    local->unkB = 9;
    local->unkC_31 = 1;
    local->unk10 = 0x11A;
    local->unk12 = 25000;
    local->unk14 = 1.0f;
    local->unkC_28 = TRUE;
    local->unk30 = func_802DB548;
    local->unk34 = func_8035CF60;
    local->unk3C = 1.5f;
}

void func_8035D058(Actor *this) {
    if (!this->unk16C_4) {
        func_8035CFC4(this);
    }
    func_802DB5A0(this);
    if (this->state == 5) {
        if (actor_animationIsAt(this, 0.18f) != 0) {
            FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 1.0f, 28000, this->position, 0x4E2, 0x9C4);
        }
        if (actor_animationIsAt(this, 0.7f) != 0) {
            FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 28000, this->position, 0x4E2, 0x9C4);

        }
    }
}
