#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


void chfirefx_update(Actor *this);

/* .data */
ActorInfo gChFireFxInfo = {
    MARKER_256_FIRE_FX, ACTOR_383_FIRE_FX, ASSET_526_SPRITE_FIRE, 
    0, NULL, 
    chfirefx_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
}; 

/* code */
void __chfirefx_spawnSmoke(f32 position[3], f32 scale){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setAlpha(pCtrl, 0x23);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setSpawnPositionRange(pCtrl, 0.0f, 110.0f*scale, 0.0f, 0.0f, 110.0f*scale, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 40.0f*scale, 0.0f, 0.0f, 90.0f*scale, 0.0f);
    particleEmitter_setStartingScaleRange(pCtrl, 2.6*scale, 3.2*scale);
    particleEmitter_setFinalScaleRange(pCtrl, 5.0*scale, 6.0*scale);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 4.0f, 7.0f);
    particleEmitter_setFade(pCtrl, 0.3f, 0.7f);
    particleEmitter_setDrawMode(pCtrl, 4);
    particleEmitter_emitN(pCtrl, 1);
}

void __chfirefx_spawnSpark(f32 position[3], f32 scale){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setSpawnPositionRange(pCtrl, 0.0f, 20.0f*scale, 0.0f, 0.0f, 20.0f*scale, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -30.0f*scale, 120.0f*scale, -30.0f*scale, 60.0f*scale, 360.0f*scale, 60.0f*scale);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -50.0f, 0.0f, 0.0f, -90.0f, 0.0f);
    particleEmitter_setStartingScaleRange(pCtrl, 0.1*scale, 0.2*scale);
    particleEmitter_setFinalScaleRange(pCtrl, 0.2*scale, 0.4*scale);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 0.9f, 1.3f);
    particleEmitter_setFade(pCtrl, 0.3f, 0.7f);
    particleEmitter_setDrawMode(pCtrl, 4);
    particleEmitter_emitN(pCtrl, 1);
}

void __chfirefx_hiss(ActorMarker *marker,ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_96_HOTSAND_EEL_HISS, 1.0f, 32000, actor->position, 1000, 2000);
}

void chfirefx_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOn(this);
        marker_setCollisionScripts(this->marker, __chfirefx_hiss, NULL, NULL);
        this->unk38_31 = (0.0f != this->yaw) ? 1 : 0;
        if(this->unkF4_8 != 0x32){
            this->unk1C[0] = 1.0f;
            this->unk44_31 = func_8030ED2C(SFX_128_FIRE_CRACKING, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 1.1f);
        }
        else{
            this->unk1C[0] = 0.0f;
        }
    }//L80359934
    if(subaddie_playerIsWithinSphere(this, 2000)){
        if( viewport_func_8024DB50(this->position, 50.0f) && this->unk38_31 ){
            if(!(globalTimer_getTime() & 3) && randf() < 0.1){
                __chfirefx_spawnSmoke(this->position, this->scale);
            } //L803599AC
            if(!(globalTimer_getTime() & 3) && randf() < 0.3){
                __chfirefx_spawnSpark(this->position, this->scale);
            }
        }//L803599F4
        if(0.0f != this->unk1C[0]){
            func_8030DB04(this->unk44_31, 7000, this->position, 300.0f, 800.0f);
            func_8030E2C4(this->unk44_31);
        }
    }//L80359A2C
}
