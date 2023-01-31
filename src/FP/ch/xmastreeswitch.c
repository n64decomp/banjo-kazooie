#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038E720(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038E940(Actor *this);

/* .data */
ActorAnimationInfo D_80392400[] = {
    {0x000, 0.f},
    {0x143, 1e+08f},
    {0x1EF, 0.6f},
    {0x143, 1.0f},
};

ActorInfo D_80392420 = { 0x206, 0x338, 0x486, 
    0x1, D_80392400, 
    func_8038E940, func_80326224, func_8038E720, 
    4500, 0, 0.0f, 0
};

/* .code */
Actor *func_8038E720(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(1, 0);
    func_8033A45C(2, 1);
    return func_80325888(marker, gfx, mtx, vtx);
}


void func_8038E774(Actor *this){
    func_80328B8C(this, 2, 0.05f, 1);
    actor_playAnimationOnce(this);
    this->marker->collidable = TRUE;
    this->unk38_31 = 0;
}

void func_8038E7CC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    
    if(this->state == 2){
        this->unk38_31++;
        if(this->unk38_31 < 4){
            func_8025A6EC(COMUSIC_2B_DING_B, 28000);
        }
    }
}

void func_8038E840(f32 position[3], s32 cnt, enum asset_e sprite_id){
    static struct31s D_80392444 = {{0.4f, 0.6f}, {0.8f, 1.8f}, {0.0f, 0.01f}, {0.5f, 1.4f}, 0.0f, 0.01f};
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -100.0f, -80.0f, -70.0f,
         100.0f, 100.0f,  70.0f
    );
    particleEmitter_setParticleAccelerationRange(pCtrl, 
        0.0f, -200.0f, 0.0f,
        0.0f, -200.0f, 0.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -200.0f, -100.0f, -200.0f,
         200.0f,  300.0f,  200.0f
    );
    func_802EFB98(pCtrl, &D_80392444);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038E940(Actor *this){
    if(jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE) || levelSpecificFlags_get(0x29)){
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->collidable = FALSE;
        func_80328B8C(this, 3, 0.95f, 0);
        return;
    }//L8038E9B8

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->collidable = FALSE;
        marker_setCollisionScripts(this->marker, NULL, func_8038E7CC, NULL);
        func_80328B8C(this, 1, 0.05f, 1);
        this->unk38_31 = 0;
        this->unk60 = 0.0f;
    }//L8038EA3C

    this->unk58_0 = (this->state == 1) ? FALSE : TRUE;
    
    switch(this->state){
        case 1: //L8038EA98
            if(func_8031FF1C(BKPROG_13) && !mapSpecificFlags_get(2))
                func_8038E774(this);
            break;
        case 2: //L8038EAC8
            if(actor_animationIsAt(this, 0.2f))
                func_8038E840(this->position, 0x20, ASSET_717_SPRITE_SPARKLE_YELLOW_2);
            
            if(this->unk38_31 < 3)
                break;

            func_80328B8C(this, 3, 0.05f, 1);
            actor_playAnimationOnce(this);
            FUNC_8030E624(SFX_416, 0.8f, 32000);
            this->marker->collidable = FALSE;
            this->unk60 = 0.0f;
            break;
        case 3: //L8038EB44
            if(this->unk60 == 0.0f && actor_animationIsAt(this, 0.95f)){
                this->unk60 = 1.0f;
                mapSpecificFlags_set(2, TRUE);
                break;
            }

            if(this->unk60 != 0.0f && !mapSpecificFlags_get(2)){
                func_8038E774(this);
            }
            break;
    }//L8038EBC0
}
