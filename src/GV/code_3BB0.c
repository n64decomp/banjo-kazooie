#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_8024DB50(f32[3], f32);

void func_8038A084(Actor *this);

/* .data */
ActorInfo D_80390F40 = { 0x24F, 0x37C, 0x0, 
    0, NULL, 
    func_8038A084, func_80326224, func_80325340, 
    { 0x7, 0xD0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

struct40s D_80390F64 = {
    {   {2.5f, 2.8f},
        {4.0f, 5.0f},
        {0.0f, 0.01f},
        {2.0f, 2.5f},
        0.1f, 0.4f
    },
    4.0f,
    1.0f
};

s32 D_80390F94[3] = {0xFF, 0xFF, 0x9B};

/* .code */
void func_80389FA0(f32 position[3]){
    ParticleEmitter *pCtrl = func_802F0BD0(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80390F94);
    func_802EF9E4(pCtrl, 100);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange( pCtrl, 
        -700.0f, 0.0f, -700.0f, 
         700.0f, 0.0f,  700.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        0.0f, 40.0f, 0.0f,
        0.0f, 90.0f, 0.0f
    );
    func_802EFC28(pCtrl, &D_80390F64);
}

void func_8038A084(Actor *this){
    if(this->unkF4_8 == 6 && !this->unk16C_4){
        this->unk16C_4 = TRUE;
        if( jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID) && this->yaw == 1.0f){
            this->unk38_31 = TRUE;
        }
    }

    if(this->unkF4_8 == 6
        && func_8024DB50(this->position, 50.0f)
        && !this->unk38_31
        && randf() < 0.2
    ){
        func_80389FA0(this->position);
    }
}
