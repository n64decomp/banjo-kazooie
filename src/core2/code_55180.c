#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"


extern bool func_8024DB50(f32[3], f32);

void func_802DC208(Actor *this);

/* .data */
ActorInfo D_80367FE0 = {
    0x1F6, 0x1E6, 0,
    0, NULL,
    func_802DC208, func_80326224, func_80325340,
    3000, 0, 0.0f, 0
};

struct40s D_80368004 = {
    {{0.2f, 0.4f}, 
    {0.8f, 1.0f},
    {0.0f, 0.01f}, 
    {0.1f, 0.12f},
    0.0f, 0.7f},
    4.0f, 1.0f
};

/* .code */
void func_802DC110(f32 *position, enum asset_e sprite_id) {
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_NO_DEPTH);
    func_802EFC28(pCtrl, &D_80368004);
}

bool func_802DC188(void) {
    f32 sp1C[3];

    player_getVelocity(sp1C);
    if((sp1C[0] == 0.0) && (sp1C[1] == -1.0) && (sp1C[2] == 0.0)) {
        return FALSE;
    }
    return TRUE;
}


void func_802DC208(Actor *this) {
    f32 sp2C[3];
    enum asset_e phi_a1;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        actor_collisionOff(this);
        this->marker->propPtr->unk8_3 = TRUE;
    }
    if( func_8024DB50(this->position, 50.0f) 
        && func_802DC188() 
        && !(globalTimer_getTime() & 0x1F) 
        && randf() < 0.1
    ){
        switch((s32)this->yaw){
            case 0:
                phi_a1 = ASSET_710_SPRITE_SPARKLE_PURPLE;
                break;
            
            case 1:
                phi_a1 = ASSET_711_SPRITE_SPARKLE_DARK_BLUE;
                break;

            case 2:
                phi_a1 = 0x712;
                break;

            default:
                phi_a1 = ASSET_711_SPRITE_SPARKLE_DARK_BLUE;
                break;
        }
        sp2C[0] = this->position[0];
        sp2C[1] = this->position[1];
        sp2C[2] = this->position[2];
        func_802DC110(sp2C, phi_a1);
    }
}
