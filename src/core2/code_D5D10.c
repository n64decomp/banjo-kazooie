#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802DB4E0(s32, s32);
extern void func_802DABA0(ParticleEmitter *pCtrl, f32 position[3], f32 scale, enum asset_e model_id);

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
    void (*unk30)(s32, s32);
    void (*unk34)(s32, s32);
}ActorLocal_Skeleton;

void chskeleton_update(Actor *this);

/* .data */
ActorAnimationInfo D_80372D20[] = {
    {0, 0.0f}, 
    {0x1E4, 4.0f},
    {0x1E4, 0.7f}, 
    {0x1E6, 0.7f},
    {0x1E5, 0.9f}, 
    {0x1E7, 0.7f},
    {0x1E4, 1.5f}, 
    {0x1E6, 0.5f},
    {0x1E4, 1.5f}, 
    {0x1E7, 1.5f},
    {0x1E8, 2.2f}
};

ActorInfo D_80372D78 = { 
    MARKER_218_LIMBO, ACTOR_34E_LIMBO, ASSET_4CC_MODEL_LIMBO, 
    0x1, D_80372D20, 
    chskeleton_update, func_80326224, func_80325888, 
    2500, 0, 1.0f, 0
};

/* .code */
void func_8035CCA0(ParticleEmitter *pCtrl, Actor *this, enum asset_e model_id) {
    func_802DABA0(pCtrl, this->position, this->scale, model_id);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(pCtrl, 4);
}


void chskeleton_despawn(ActorMarker *marker, s32 arg1) {
    Actor *this;

    this = marker_getActor(marker);
    func_802DAC84(partEmitMgr_newEmitter(2), this, ASSET_4CE_MODEL_LIMBO_LEG);
    func_802DAD08(partEmitMgr_newEmitter(1), this, ASSET_4CF_MODEL_LIMBO_HEAD);
    func_802DAD8C(partEmitMgr_newEmitter(2), this, ASSET_4CD_MODEL_LIMBO_ARM);
    func_8035CCA0(partEmitMgr_newEmitter(4), this, ASSET_4D0_MODEL_LIMBO_BONE);
    FUNC_8030E8B4(SFX_119_FISH_DEATH, 1.0f, 32000, this->position, 1250, 2500);
    __spawnQueue_add_4((GenMethod_4)func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    marker_despawn(marker);
}

static void _chskeleton_init(Actor *this) {
    ActorLocal_Skeleton *local;

    local = (ActorLocal_Skeleton *)&this->local;

    local->unk0 = 3.0f;
    local->unk4 = 6.0f;
    local->unk8 = 4;
    local->unk9 = 8;
    local->unkA = 0xA;
    local->unkB = 7;
    local->unkC_31 = 1;
    local->unk10 = 0x10C;
    local->unk12 = 20000;
    local->unk14 = 1.7f;
    local->unk18 = 0.2f;
    local->unk1C = 0x117;
    local->unk1E = 32000;
    local->unk20 = 1.0f;
    local->unk24 = 0.35f;
    local->unk28 = 0x118;
    local->unk2A = 32000;
    local->unk2C = 1.0f;
    local->unkC_28 = TRUE;
    local->unk30 = func_802DB4E0;
    local->unk34 = chskeleton_despawn;

}

void chskeleton_update(Actor *this){
    if(!this->unk16C_4){
        _chskeleton_init(this);
    }
    func_802DB5A0(this);
}
