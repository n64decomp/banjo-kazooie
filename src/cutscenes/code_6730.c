#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    ParticleEmitter *unk0;
}ActorLocal_cutscenes_6730;

void func_8038CCA8(Actor *);
Actor* func_8038CBCC(ActorMarker *, Gfx **, Mtx**, Vtx **);

/* .data */
extern ActorAnimationInfo D_8038E700[] ={
    {0x000, 0.0f},
    {0x168, 10000.0f},
    {0x168, 3.0f}
};

extern ActorInfo D_8038E718 = {
    0x1F8, 0x1E8, 0x439,
    1, D_8038E700,
    func_8038CCA8, func_80326224, func_8038CBCC,
    0, 0, 0.0f, 0
};

extern s32 D_8038E73C[3] = {0xff, 0xff, 0xff};

extern struct31s D_8038E748 = {
    {0.1f, 0.3f},
    {0.0f, 0.0f},
    {0.0f, 0.01f},
    {1.4f, 1.5f},
    0.05f, 0.9f
};

extern struct41s D_8038E770 ={
    { {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f} },
    { {0.0f, -200.0f, 0.0f}, {0.0f, -200.0f, 0.0f} }
};

/* .code */
void func_8038CB20(ParticleEmitter *pCtrl){
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    func_802EFFA8(pCtrl, D_8038E73C);
    func_802EF9E4(pCtrl, 230);
    func_802EFE24(pCtrl, -600.0f, -600.0f,-600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038E770);
    func_802EFB98(pCtrl, &D_8038E748);
    func_802EFA70(pCtrl, 4);
    func_802F0D54(pCtrl);
}

Actor* func_8038CBCC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = func_80325888(marker, gfx, mtx, vtx);
    ActorLocal_cutscenes_6730 *local = (ActorLocal_cutscenes_6730 *)&actor->local;
    f32 sp3C[3];
    int i;
    
    if(marker->unk14_21 && actor->state == 2){
        for(i = 5; i < 0xF; i++){
            if(randf() < 0.8){
                func_8034A174(func_80329934(), i, sp3C);
                particleEmitter_setPosition(local->unk0, sp3C);
                particleEmitter_emitN(local->unk0, 1);
            }
        }
    }
    return actor;
}

void func_8038CCA8(Actor *this){
    f32 sp24 = time_getDelta();
    ActorLocal_cutscenes_6730 *local = (ActorLocal_cutscenes_6730 *)&this->local;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        animctrl_setSmoothTransition(this->animctrl, 0);
        this->unk60 = this->yaw/4;
        local->unk0 = partEmitList_pushNew(0xA0);
        func_8038CB20(local->unk0);
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
