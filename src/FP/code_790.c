#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80386B80(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80386CF8(Actor *this);

/* .data */
ActorAnimationInfo D_80391A90[] ={
    {0, 0.0},
    {ASSET_143_ANIM_SNOWMAN_BUTTON, 800000.0f},
    {ASSET_143_ANIM_SNOWMAN_BUTTON, 0.5f},
    {ASSET_143_ANIM_SNOWMAN_BUTTON, 800000.0f}
};

ActorInfo D_80391AB0 = { 
    MARKER_B9_FP_SNOWMAN_BUTTON, ACTOR_116_FP_SNOWMAN_BUTTON, ASSET_421_MODEL_FP_SNOWMAN_BUTTON, 
    0x1, D_80391A90, 
    func_80386CF8, func_80326224, func_80386B80, 
    0, 0x800, 0.0f, 0
};

struct31s D_80391AD4 = {
    {0.4f, 0.6f}, 
    {1.8f, 3.6f}, 
    {0.0f, 0.01f}, 
    {0.5f, 1.4f},
    0.0f, 0.01f, 
};

struct43s D_80391AFC = {
    {{-300.0f, 350.0f}, {-300.0f, 300.0f}, {800.0f, 300.0f}},
    {{0.0f, -800.0f, 0.0f}, {0.0f, -800.0f, 0.0f}},
    {{-50.0f, -50.0f, -50.0f}, {50.0f, 50.0f, 50.0f}}
};

s32 D_80391B44[3] = {225, 225, 245};

/* .code  */
Actor *func_80386B80(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(1, this->state == 3);
    func_8033A45C(2, func_8033A0F0(1) ^ 1);
    return func_80325888(marker, gfx, mtx, vtx);

}

void func_80386BEC(Actor *this){
    f32 plyr_pos[3];
    ParticleEmitter *pCtrl = partEmitList_pushNew(12);
    
    player_getPosition(plyr_pos);
    func_80328B8C(this, 2, 0.01f, 1);
    actor_collisionOff(this);
    func_8025A6EC(COMUSIC_2B_DING_B, 28000);
    FUNC_8030E624(SFX_90_SWITCH_PRESS, 1.0f, 32000);
    func_8038AB40();
    func_802EFFA8(pCtrl, D_80391B44);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setPosition(pCtrl, plyr_pos);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80391AFC);
    func_802EFB98(pCtrl, &D_80391AD4);
    particleEmitter_emitN(pCtrl, 12);
}

void func_80386CB8(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    
    if(this->state == 1)
        func_80386BEC(this);
    
}

void func_80386CF8(Actor *this){
    marker_setCollisionScripts(this->marker, NULL, NULL, func_80386CB8);
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOn(this);
    
    if(!this->initialized){
        this->initialized = TRUE;
        this->pitch += (f32)(this->unkF4_8 - 1);
    }
    
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(this->state == 3){
            func_8038AB40();
        }
    }

    switch(this->state){
        case 1:
            break;
        case 2:
            if(actor_animationIsAt(this, 0.99f)){
                func_80328B8C(this, 3, 0.99f, 0);
            }
            break;
        case 3:
            break;
    }
}
