#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 func_8024DB50(f32[3], f32);

void func_80390EB0(Actor *this);

/* .data */
extern ActorInfo D_80392840 = { MARKER_245_XMAS_TREE_EGG_TOLL, ACTOR_353_XMAS_TREE_EGG_TOLL, ASSET_402_MODEL_EGG_TOLL,
    0x0, NULL,
    func_80390EB0, func_80326224, func_80325340,
    2000, 0, 0.0f, 0
};
struct40s D_80392864;
s32 D_80392894[3];
struct40s D_803928A0;
s32 D_803928D0[3];

/* .code */
void func_80390C70(f32 position[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80392894);
    func_802EF9E4(pCtrl, 0x41);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -40.0f, 110.0f, -40.0f,
         40.0f, 110.0f,  40.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        0.0f, 40.0f, 0.0f,
        0.0f, 90.0f, 0.0f
    );
    func_802EFC28(pCtrl, &D_80392864);
}

void func_80390D58(f32 position[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_803928D0);
    func_802EF9E4(pCtrl, 0xFF);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -40.0f, 50.0,-40.0f,
         40.0f, 70.0, 40.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -40.0f, 120.0,-40.0f,
         40.0f, 180.0, 40.0f
    );
    particleEmitter_setParticleAccelerationRange(pCtrl, 
        0.0f,  -60.0f, 0.0f,
        0.0f, -100.0f, 0.0f
    );
    func_802EFC28(pCtrl, &D_803928A0);
}

void func_80390E78(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    FUNC_8030E8B4(SFX_96_HOTSAND_EEL_HISS, 1.0f, 32000, this->position, 1000, 2000);
}

void func_80390EB0(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        actor_collisionOn(this);
        marker_setCollisionScripts(this->marker, func_80390E78, NULL, NULL);
    }

    if(func_8024DB50(this->position, 150.0f) || func_80329530(this, 1200))
    {
        if( !(func_8023DB5C() & 3) && randf() < 0.2){
            func_80390C70(this->position);
        }

        if( !(func_8023DB5C() & 3) && randf() < 0.7){
            func_80390D58(this->position);
        }
    }
}
