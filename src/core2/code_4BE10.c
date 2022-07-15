#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D2DA0(Actor *this);

/* .data */
extern ActorInfo D_803675F0 = {
    0x16, 0x6A, 0x0,
    0x1, NULL, 
    func_802D2DA0, func_80326244, func_80325340, 
    0, 0, 0.0f, 0
};

extern struct31s D_80367624;
extern struct42s D_8036764C;


/* .code */
void func_802D2DA0(Actor *this) {
    ParticleEmitter *pCtrl;
    f32 sp70[3];
    s32 phi_s6;
    s32 i;

    if (this->state == 2) {
        if (--this->unk38_31 == 0) {
            marker_despawn(this->marker);
        }
        pCtrl = partEmitList_pushNew((s32) this->unk60);
        for(phi_s6 = 0; phi_s6 < (s32)this->unk60; phi_s6++){
            for(i = 0; i < 3; i++){
                sp70[i] = this->position[i] + randf()*2*this->unkF4_8 - ((i == 1)? 0: this->unkF4_8);
            }

            particleEmitter_setSprite(pCtrl, ASSET_710_SPRITE_SPARKLE_PURPLE);
            particleEmitter_setStartingFrameRange(pCtrl, 0, 0);
            particleEmitter_setPosition(pCtrl, sp70);
            particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8036764C);
            func_802EFB98(pCtrl, &D_80367624);
            particleEmitter_setSpawnInterval(pCtrl, 1.0f);
        }
    }
}
