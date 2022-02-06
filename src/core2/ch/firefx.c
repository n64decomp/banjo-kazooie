#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int  func_8024DB50(f32 arg0[3], f32 arg1);

void chfirefx_update(Actor *this);

/* .data */
ActorInfo gChFireFxInfo = {
    0x256, ACTOR_383_FIRE_FX, ASSET_526_SPRITE_FIRE, 
    0, NULL, 
    chfirefx_update, func_80326224, func_80325888,
    {0,0}, 0, 0.0f, {0,0,0,0}
}; 

/* code */
void __chfirefx_spawnSmoke(f32 position[3], f32 scale){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EF9E4(pCtrl, 0x23);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, 0.0f, 110.0f*scale, 0.0f, 0.0f, 110.0f*scale, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 40.0f*scale, 0.0f, 0.0f, 90.0f*scale, 0.0f);
    func_802EFB70(pCtrl, 2.6*scale, 3.2*scale);
    func_802EFB84(pCtrl, 5.0*scale, 6.0*scale);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 4.0f, 7.0f);
    func_802EFA5C(pCtrl, 0.3f, 0.7f);
    func_802EFA70(pCtrl, 4);
    particleEmitter_emitN(pCtrl, 1);
}

void __chfirefx_spawnSpark(f32 position[3], f32 scale){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, 0.0f, 20.0f*scale, 0.0f, 0.0f, 20.0f*scale, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -30.0f*scale, 120.0f*scale, -30.0f*scale, 60.0f*scale, 360.0f*scale, 60.0f*scale);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -50.0f, 0.0f, 0.0f, -90.0f, 0.0f);
    func_802EFB70(pCtrl, 0.1*scale, 0.2*scale);
    func_802EFB84(pCtrl, 0.2*scale, 0.4*scale);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 0.9f, 1.3f);
    func_802EFA5C(pCtrl, 0.3f, 0.7f);
    func_802EFA70(pCtrl, 4);
    particleEmitter_emitN(pCtrl, 1);
}

void __chfirefx_hiss(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_96_HOTSAND_EEL_HISS, 1000, 0x3ff, actor->position, 1000, 2000);
}

void chfirefx_update(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOn(this);
        func_803300A8(this->marker, __chfirefx_hiss, NULL, NULL);
        this->unk38_31 = (0.0f != this->yaw) ? 1 : 0;
        if(this->unkF4_8 != 0x32){
            this->unk1C[0] = 1.0f;
            this->unk44_31 = func_8030ED2C(SFX_128_FIRE_CRACKING, 2);
            func_8030DBB4(this->unk44_31, 1.1f);
        }
        else{
            this->unk1C[0] = 0.0f;
        }
    }//L80359934
    if(actor_playerIsWithinDist(this, 2000)){
        if( func_8024DB50(this->position, 50.0f) && this->unk38_31 ){
            if(!(func_8023DB5C() & 3) && randf() < 0.1){
                __chfirefx_spawnSmoke(this->position, this->scale);
            } //L803599AC
            if(!(func_8023DB5C() & 3) && randf() < 0.3){
                __chfirefx_spawnSpark(this->position, this->scale);
            }
        }//L803599F4
        if(0.0f != this->unk1C[0]){
            func_8030DB04(this->unk44_31, 7000, this->position, 300.0f, 800.0f);
            func_8030E2C4(this->unk44_31);
        }
    }//L80359A2C
}
