#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8 unk0;
    u8 pad1[3];
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
}ActorLocal_MoleHill;

Actor *func_802DA560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DA740(Actor *this);

/*.data */
ActorAnimationInfo D_80367E00[] = {
    {0x000, 0.0f}, 
    {0x13D, 2000000000.0f},
    {0x13D, 4.5f}, 
    {0x13C, 1.7f}
};

ActorInfo D_80367E20= {
    0xB8, ACTOR_12C_MOLEHILL, ASSET_388_MODEL_MOLEHILL, 
    0, D_80367E00, 
    func_802DA740, func_80326224, func_802DA560,
    {0,0,0,0}, 0.0f, {0,0,0,0}
}; 

struct31s D_80367E44 = {
    {0.05f, 0.1f},
    {0.0f,  0.0f},
    {0.0f,  0.01f}, 
    {4.0f,  4.0f},
    0.0f,
    0.3f 
};

/* .code */
Actor *func_802DA560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = marker_getActor(marker);
    ActorLocal_MoleHill * local = (ActorLocal_MoleHill *) &actor->local;
    if(actor->unk16C_4){
        actor = func_80325888(marker, gfx, mtx, vtx);
        func_8034A174(actor->marker->unk44, 5, actor->velocity);
        func_8034A174(actor->marker->unk44, 6, actor->unk1C);
        func_8034A174(actor->marker->unk44, 7, local->unk4);
        func_8034A174(actor->marker->unk44, 8, local->unk10);
        func_8034A174(actor->marker->unk44, 9, local->unk1C);
        local->unk0 = 1;
    }
    return actor;
}

void func_802DA634(ParticleEmitter *pCtrl, f32 arg1[3], s32 cnt){
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -600.0f, 0.0f, 0.0f, -600.0f, 0.0f);
    particleEmitter_setModel(pCtrl, 0x344);
    particleEmitter_setPosition(pCtrl, arg1);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -150.0f, 150.0f, -150.0f, 150.0f, 360.0f, 150.0f);
    func_802EFB98(pCtrl, &D_80367E44);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_802DA740(Actor *this){
    ActorLocal_MoleHill * local = (ActorLocal_MoleHill *) &this->local;

    this->marker->propPtr->unk8_3 = TRUE;
    this->marker->collidable = FALSE;
    if(!this->unk16C_4){
        local->unk0 = 0;
        this->unk16C_4 = 1;
    }
    switch(this->state){
        case 1:
            break;
        case 2: //L802DA7C4
            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 1, 0.0001f, 1);
            }
            else{
                if(local->unk0 && actor_animationIsAt(this, 0.05f)){
                    func_802DA634(func_802F0BD0(6), this->velocity, 6);
                }
            }
            break;
        case 3: //L802DA838
            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 1, 0.0001f, 1);
            }
            else if(local->unk0){ 
                if(actor_animationIsAt(this, 0.3f)){
                    func_802DA634(func_802F0BD0(6), this->velocity, 6);
                }
                else if(actor_animationIsAt(this, 0.4f)){
                    func_802DA634(func_802F0BD0(4), this->unk1C, 4);
                }
                else if(actor_animationIsAt(this, 0.45f)){
                    func_802DA634(func_802F0BD0(4), local->unk4, 4);
                }
                else if(actor_animationIsAt(this, 0.5f)){
                    func_802DA634(func_802F0BD0(4), local->unk10, 4);
                }
                else if(actor_animationIsAt(this, 0.55f)){
                    func_802DA634(func_802F0BD0(4), local->unk1C, 4);
                }
            }
            break;
    }//L802DA984
}
