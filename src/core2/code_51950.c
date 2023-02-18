#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 player_getYaw(void);

void func_802D88E0(Actor *this);

/* .data */
ActorInfo D_80367C90 = {
    0x100, 0x1FF, 0x580,
    0x0, NULL,
    func_802D88E0, func_80326224, func_80325934, 
    0, 0, 0.0f, 0
};

ActorInfo D_80367CB4 = {
    0x101, 0x200, 0x6D1,
    0x0, NULL,
    func_802D88E0, func_80326224, func_80325934, 
    0, 0, 0.0f, 0
};

struct31s D_80367CD8 = {
    {0.24f, 0.2f},
    {0.01f, 0.01f},
    {0.0f, 0.0f},
    {0.25f, 0.25f},
    0.0f,
    0.3f
};

/* .code */
void func_802D88E0(Actor *this) {
    int i;
    s32 temp_f10;
    f32 sp5C[3];
    ParticleEmitter *pCtrl;

    actor_collisionOff(this);
    func_80329054(this, 3);

    if (this->unk1C[1] > -100.0f) {
        this->unk1C[1] -= 3.5;
    }

    if (this->position_y > -16000.0f) {
        this->position_y += this->unk1C[1];
    }
    if (this->unk60 > 0.5) {
        pCtrl = partEmitMgr_newEmitter(1U);
        for(i = 0; i < 3; i++){
            sp5C[i] = this->position[i] + (randf()*2)*25 - ((i == 1) ? 0 : 25);
        }
        particleEmitter_setPosition(pCtrl, sp5C);
        particleEmitter_setSprite(pCtrl, (this->modelCacheIndex == 0x1FF) ? ASSET_715_SPRITE_SPARKLE_RED : ASSET_713_SPRITE_SPARKLE_YELLOW);
        particleEmitter_setStartingFrameRange(pCtrl, 0, 0);
        func_802EFB98(pCtrl, &D_80367CD8);
        func_802EFF50(pCtrl, 1.0f);
        particleEmitter_setSpawnInterval(pCtrl, 0.25f);
    }
    this->unk60 -= time_getDelta();
    if (this->unk60 < 0.0f) {
        marker_despawn(this->marker);
        return;
    }

    temp_f10 = (s32) ml_map_f(this->unk60, 0.0f, 0.3f, 0.0f, 255.0f);
    actor_setOpacity(this, temp_f10);
    if (temp_f10 == 0) {
        marker_despawn(this->marker);
    }
}

void func_802D8B20(enum actor_e actor_id){
    Actor *feather;
    f32 plyr_pos[3];
    s32 temp_v0;
    f32 temp2;

    player_getPosition(plyr_pos);
    temp2 = player_getYaw();
    temp_v0 = (randf() > 0.5) ? 0x1E : -0x1E;
    feather = func_8032813C(actor_id, plyr_pos, (s32) (temp2 + temp_v0));
    func_8032AA58(feather, 0.45f);
    feather->unk28 = 22.0f;
    feather->unk1C[1] = 48.0f;
    feather->unk60 = 1.2f;
}

void func_802D8BE4(bool gold_feather){
    __spawnQueue_add_1((GenMethod_1)func_802D8B20, (!gold_feather) ? 0x1FF : 0x200);
}
