#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern int func_8024549C(f32 [3], f32);

#define _HorzDist3v(v1, v2) ((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[2]-v2[2])*(v1[2]-v2[2]))


typedef struct{
    ParticleEmitter *unk0;
}ActorLocal_Core2_53C10;

void func_802DC018(Actor *this);

/* .data */
ActorInfo D_80367F30= {
    0x1F5, 0x1E5, 0, 
    0, NULL, 
    func_802DC018, func_80326224, func_80325340,
    0, 0, 0.0f, 0
}; 

s32 D_80367F54[3] = {0xff, 0xff, 0xff};
struct40s D_80367F60 = {
    { {0.1f, 0.5f}, {1.0f, 1.5f}, {0.0f, 0.01f}, {0.5f, 1.4f}, 
      0.0f, 0.01f
    }, 
    4, 1
};

struct43s D_80367F90 ={
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}},
    {{0.0f, -650.0f, 0.0f}, {0.0f, -650.0f, 0.0f}},
    {{-200.0f, 0.0f, -200.0f}, {200.0f, 0.0f, 200.0f}}
};

/* .code */
void func_802DBCE0(ParticleEmitter *pCtrl, f32 arg1[3]){
    ParticleEmitter *other = partEmitMgr_newEmitter(1);
    if(func_8024549C(arg1, 4.0f)){
        arg1[1] += 2.0f;
        particleEmitter_setSprite(other, ASSET_70C_SPRITE_RIPPLE);
        particleEmitter_setDrawMode(other, 1);
        particleEmitter_setPosition(other, arg1);
        particleEmitter_setStartingScaleRange(other, 0.1f, 0.1f);
        particleEmitter_setFinalScaleRange(other, 1.0f, 1.4f);
        particleEmitter_setParticleLifeTimeRange(other, 1.0f, 1.4f);
        particleEmitter_setFade(other, 0.0f, 0.5f);
        particleEmitter_emitN(other, 1);
        func_8030E878(SFX_413_WATER_RIPPLE, randf2(1.0f, 1.4f), 0x4e20, arg1, 0.0f, 3500.0f);
    }
    else{//L802DBDF4
        particleEmitter_setSprite(other, ASSET_700_SPRITE_DUST);
        particleEmitter_setStartingFrameRange(other, 0, 7);
        particleEmitter_setRGB(other, D_80367F54);
        particleEmitter_setPosition(other, arg1);
        particleEmitter_setParticleVelocityRange(other, -230.0f, 30.0f, -230.0f, 230.0f, 110.0f, 230.0f);
        func_802EFC28(other, &D_80367F60);
        FUNC_8030E8B4(SFX_7_BANJO_LANDING_03, 1.0f, 22000, arg1, 1500, 4500);
    }//L802DBE8C
}

void func_802DBE9C(Actor *this, ParticleEmitter *pCtrl){
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80367F90);
    particleEmitter_setModel(pCtrl, 0x344);
    particleEmitter_setPosition(pCtrl, this->position);
    particleEmitter_setDrawMode(pCtrl, 4);
    particleEmitter_setAngularVelocityRange(pCtrl, -450.0f, -450.0f, -450.0f, 450.0f, 450.0f, 450.0f);
    func_802EFA18(pCtrl, 1);
    particleEmitter_setParticleCallback(pCtrl, func_802DBCE0);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 7.0f, 7.0f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.3f);
    particleEmitter_manualFree(pCtrl);
}

int func_802DBF94(Actor *this, s32 arg1){
    f32 sp1C[3];

    player_getPosition(sp1C);
    if(_HorzDist3v(this->position, sp1C) < arg1*arg1)
        return 1;
    return 0;
}

void func_802DC018(Actor *this){
    ActorLocal_Core2_53C10 *local = (ActorLocal_Core2_53C10 *) &this->local;
    f32 tmp_f0;

    if(!this->unk16C_4){
        actor_collisionOff(this);
        local->unk0 = partEmitMgr_newEmitter(16);
        func_802DBE9C(this, local->unk0);
        this->unk16C_4 = TRUE;
    }
    if(func_802DBF94(this, 600) && randf() < 0.2){
        tmp_f0 = randf2(0.01f, 0.06f);
        particleEmitter_setStartingScaleRange(local->unk0, tmp_f0, tmp_f0);
        particleEmitter_setFinalScaleRange(local->unk0, tmp_f0, tmp_f0);
        particleEmitter_emitN(local->unk0, 1);
    }//L802DC0F4
}
