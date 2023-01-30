#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"

#define _HorzDist3v(v1, v2) ((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[2]-v2[2])*(v1[2]-v2[2]))
extern int func_8024549C(f32[3], f32);

typedef struct{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
}struct_core2_D2AB0;

void chdrips_update(Actor *this);

/* .data */
ActorInfo gChDripsInfo = {
    0x246, ACTOR_354_DRIPS, 0, 
    0, NULL, 
    chdrips_update, func_80326224, func_80325340,
    5000, 0, 0.0f, 0
}; 

s32 D_80372AE4[3] = {0xff, 0xff, 0xfe};

struct_core2_D2AB0 D_80372AF0 = {0.0f, 0.0f, 1.0f, 1.4f};

struct43s D_80372B00 = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}},
    {{0.0f, -650.0f, 0.0f}, {0.0f, -650.0f, 0.0f}},
    {{-400.0f, 0.0f, -400.0f}, {400.0f, 0.0f, 400.0f}}
};


/* .code */
void func_80359A40(f32 position[3], struct_core2_D2AB0 *arg1, s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setSprite(pCtrl, ASSET_70C_SPRITE_RIPPLE);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_3D_ROTATE);
    particleEmitter_setRGB(pCtrl, D_80372AE4);
    particleEmitter_setPosition(pCtrl, position);
    func_802EFB70(pCtrl, 0.1f, 0.1f);
    func_802EFB84(pCtrl, 1.0f, 1.4f);
    particleEmitter_setSpawnIntervalRange(pCtrl, arg1->unk0, arg1->unk4);
    particleEmitter_setParticleLifeTimeRange(pCtrl, arg1->unk8, arg1->unkC);
    particleEmitter_setFade(pCtrl, 0.0f, 0.5f);
    particleEmitter_emitN(pCtrl, cnt);
}

void __chdrips_particleCallback(struct31s *pCtrl, f32 position[3]){
    if(func_8024549C(position, 4.0f)){
        position[1] += 2.0f;
        func_80359A40(position, &D_80372AF0, 1);
        func_8030E878(SFX_413_WATER_RIPPLE, randf2(1.0f, 1.4f), 20000, position, 0.0f, 3500.0f);
    }
}

int __chdrips_playerWithinDist(Actor *this, s32 arg1){
    f32 sp1C[3];

    player_getPosition(sp1C);
    if(_HorzDist3v(this->position, sp1C) < arg1*arg1)
        return 1;
    return 0;
}

void chdrips_update(Actor *this){
    ParticleEmitter *pCtrl;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        actor_collisionOff(this);
        this->unk60 = this->yaw/360.0;
    }
    if(__chdrips_playerWithinDist(this, 5000) && randf() < this->unk60){
        pCtrl = partEmitMgr_newEmitter(1);
        particleEmitter_setModel(pCtrl, ASSET_8A0_SPRITE_WATER_DROP);
        particleEmitter_setPosition(pCtrl, this->position);
        particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80372B00);
        func_802EFA18(pCtrl, 1);
        particleEmitter_setParticleCallback(pCtrl, __chdrips_particleCallback);
        particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
        particleEmitter_setParticleLifeTimeRange(pCtrl, 7.0f, 7.0f);
        func_802EFB70(pCtrl, 0.1f, 0.1f);
        func_802EFB84(pCtrl, 0.1f, 0.1f);
        particleEmitter_emitN(pCtrl, 1);
    }
}  
