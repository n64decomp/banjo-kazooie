#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>

void func_80390EB0(Actor *this);

/* .data */
ActorInfo FP_D_80392840 = { MARKER_245_XMAS_TREE_EGG_TOLL, ACTOR_353_XMAS_TREE_EGG_TOLL, ASSET_402_MODEL_EGG_TOLL,
    0x0, NULL,
    func_80390EB0, func_80326224, func_80325340,
    2000, 0, 0.0f, 0
};

/* .code */
void func_80390C70(f32 position[3]){
    static struct40s FP_D_80392864 = {{{1.7f, 2.0f}, {2.4f, 2.7f}, {0.0f, 0.01f}, {4.0f, 7.0f}, 0.3f, 0.7f}, 4.0f, 1.0f};
    static s32 D_80392894[3] = {0xFF, 0XFF, 0xFF};
    
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80392894);
    particleEmitter_setAlpha(pCtrl, 0x41);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -40.0f, 110.0f, -40.0f,
         40.0f, 110.0f,  40.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        0.0f, 40.0f, 0.0f,
        0.0f, 90.0f, 0.0f
    );
    func_802EFC28(pCtrl, &FP_D_80392864);
}

void func_80390D58(f32 position[3]){
    static struct40s D_803928A0 = {{{0.05f, 0.1f}, {0.1f, 0.2f}, {0.0f, 0.01f}, {0.9f, 1.3f}, 0.3f, 0.7f}, 4.0f, 1.0f};
    static s32 D_803928D0[3] = {0xFF, 0xFF, 0xFF};

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_803928D0);
    particleEmitter_setAlpha(pCtrl, 0xFF);
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

    if(viewport_func_8024DB50(this->position, 150.0f) || func_80329530(this, 1200))
    {
        if( !(globalTimer_getTime() & 3) && randf() < 0.2){
            func_80390C70(this->position);
        }

        if( !(globalTimer_getTime() & 3) && randf() < 0.7){
            func_80390D58(this->position);
        }
    }
}
