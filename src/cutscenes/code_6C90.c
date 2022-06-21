#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    ParticleEmitter *unk0;
}ActorLocal_cutscenes_6C90;

void func_8038D218(Actor *);
Actor* func_8038D13C(ActorMarker *, Gfx **, Mtx**, Vtx **);

/* .data */
ActorAnimationInfo D_8038E890[] ={
    {0x000, 0.0f},
    {0x1F6, 10000.0f},
    {0x1F6, 5.0f},
};

ActorInfo D_8038E8A8 = {
    0x212, 0x342, 0x45F,
    1, D_8038E890,
    func_8038D218, func_80326224, func_8038D13C,
    3000, 0, 0.0f, 0
};

s32 D_8038E8CC[3] = {0xff, 0xff, 0xff};

struct31s D_8038E8D8 = {
    {0.6f, 0.6f},
    {0.9f, 0.9f},
    {0.0f, 0.01f},
    {2.0f, 2.0f},
    0.05f, 0.9f
};

struct41s D_8038E900 = {
    { {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}},
    { {0.0f, -30.0f, 0.0f}, {0.0f, -30.0f, 0.0f}}
};

/*.code */
void func_8038D080(ParticleEmitter *pCtrl){
    particleEmitter_setSprite(pCtrl, ASSET_702_SPRITE_UNKNOWN);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 5);
    func_802EFFA8(pCtrl, D_8038E8CC);
    func_802EF9E4(pCtrl, 60);
    func_802EFE24(pCtrl, -600.0f, -600.0f,-600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038E900);
    func_802EFB98(pCtrl, &D_8038E8D8);
    func_802EFA70(pCtrl, 4);
    func_802F0D54(pCtrl);
}

Actor* func_8038D13C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = func_80325888(marker, gfx, mtx, vtx);
    ActorLocal_cutscenes_6C90 *local = (ActorLocal_cutscenes_6C90 *)&actor->local;
    f32 sp3C[3];
    int i;
    
    if(marker->unk14_21 && actor->state == 2){
        for(i = 5; i < 0x6; i++){
            if(randf() < 0.8){
                func_8034A174(func_80329934(), i, sp3C);
                particleEmitter_setPosition(local->unk0, sp3C);
                particleEmitter_emitN(local->unk0, 1);
            }
        }
    }
    return actor;
}

void func_8038D218(Actor *this){
    f32 sp24 = time_getDelta();
    ActorLocal_cutscenes_6C90 *local = (ActorLocal_cutscenes_6C90 *)&this->local;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        animctrl_setSmoothTransition(this->animctrl, 0);
        this->unk60 = this->yaw/4;
        local->unk0 = partEmitList_pushNew(0x100);
        func_8038D080(local->unk0);
    }

    switch(this->state){
        case 1:
            this->unk60 = MAX(0.0, this->unk60 - sp24);
            if(0.0f == this->unk60){
                func_80328AC8(this, 2);
                actor_playAnimationOnce(this);
            }
            break;
        case 2://L8038CDA4
            if(actor_animationIsAt(this, 0.999f)){
                marker_despawn(this->marker);
            }
            break;
    }
}
