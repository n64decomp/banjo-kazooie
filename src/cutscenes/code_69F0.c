#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    ParticleEmitter *unk0;
    ParticleEmitter *unk4;
} ActorLocal_cutscenes_69F0;

extern void func_8038CF50(Actor *this);

/* .data */
ActorInfo D_8038E7A0 = {
    0x211, 0x341, 0x45D,
    1, NULL,
    NULL, func_8038CF50, func_80325888,
    {0, 0}, 0xA000, 0.0f, {0, 0, 0, 0}
};

s32 D_8038E7C4[3] = {0xFF, 0xFF, 0xFF};

struct31s D_8038E7D0 = {
    {0.7f, 0.9f},
    {0.4f, 0.5f},
    {0.0f, 0.01f},
    {0.4f, 0.7f},
    0.15f, 0.3f
};

struct42s D_8038E7F8 ={
    { {-10.0f, -10.0f}, {-10.0f, 10.0f}, {10.0f, 10.0f} },
    { {0.0f, 30.0f, 0.0f}, {0.0f, 30.0f, 0.0f} }
};

s32 D_8038E828[3] = {0xFF, 0xFF, 0xFF};

struct31s D_8038E834 = {
    {0.05f, 0.1f},
    {0.1f, 0.2f},
    {0.0f, 0.01f},
    {1.4f, 1.5f},
    0.01f, 0.3f
};

struct42s D_8038E85C ={
    { {-5.0f, -5.0f}, {-5.0f, 5.0f}, {5.0f, 5.0f} },
    { {0.0f, 30.0f, 0.0f}, {0.0f, 30.0f, 0.0f} }
};


/* .code */
void func_8038CDE0(ParticleEmitter *pCtrl){
    particleEmitter_setSprite(pCtrl, ASSET_45A_SPRITE_GREEN_GLOW);
    func_802EFFA8(pCtrl, D_8038E7C4);
    func_802EF9E4(pCtrl, 0xff);
    func_802EFE24(pCtrl, -600.0f, -600.0f,-600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038E7F8);
    func_802EFB98(pCtrl, &D_8038E7D0);
    func_802EFA78(pCtrl, 1);
    func_802EFA70(pCtrl, 4);
    func_802F0D54(pCtrl);
}

void func_8038CE98(ParticleEmitter *pCtrl){
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    func_802EFFA8(pCtrl, D_8038E828);
    func_802EF9E4(pCtrl, 0xff);
    func_802EFE24(pCtrl, -600.0f, -600.0f,-600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038E85C);
    func_802EFB98(pCtrl, &D_8038E834);
    func_802EFA78(pCtrl, 1);
    func_802EFA70(pCtrl, 4);
    func_802F0D54(pCtrl);
}

extern void func_8038CF50(Actor *this){
    ActorLocal_cutscenes_69F0 *local  = (ActorLocal_cutscenes_69F0 *) &this->local;
    f32 sp40[3];
    int i;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        local->unk0 = func_802F0BD0(6);
        local->unk4 = func_802F0BD0(6);

        func_8038CDE0(local->unk0);
        func_8038CE98(local->unk4);
    }//L8038CFBC

    func_80343DEC(this);

    if(this->marker->unk14_21){
        for(i = 5; i < 6; i++){
            if(randf() < 0.4){
                func_8034A174(this->marker->unk44, i, sp40);
                particleEmitter_setPosition(local->unk0, sp40);
                particleEmitter_emitN(local->unk0, 1);
                
                particleEmitter_setPosition(local->unk4, sp40);
                particleEmitter_emitN(local->unk4, 1);

            }
        }
    }//L8038D05C
}

