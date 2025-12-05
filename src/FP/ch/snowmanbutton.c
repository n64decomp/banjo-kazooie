#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80386B80(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void FP_func_80386CF8(Actor *this);

/* .data */
ActorAnimationInfo FP_D_80391A90[] ={
    {0, 0.0},
    {ASSET_143_ANIM_SNOWMAN_BUTTON, 800000.0f},
    {ASSET_143_ANIM_SNOWMAN_BUTTON, 0.5f},
    {ASSET_143_ANIM_SNOWMAN_BUTTON, 800000.0f}
};

ActorInfo gSnowmanButton = { 
    MARKER_B9_FP_SNOWMAN_BUTTON, ACTOR_116_FP_SNOWMAN_BUTTON, ASSET_421_MODEL_FP_SNOWMAN_BUTTON, 
    0x1, FP_D_80391A90, 
    FP_func_80386CF8, actor_update_func_80326224, func_80386B80, 
    0, 0x800, 0.0f, 0
};

ParticleScaleAndLifetimeRanges D_80391AD4 = {
    {0.4f, 0.6f}, 
    {1.8f, 3.6f}, 
    {0.0f, 0.01f}, 
    {0.5f, 1.4f},
    0.0f, 0.01f, 
};

ParticleSettingsVelocityAccelerationPosition D_80391AFC = {
    {{-300.0f, 350.0f, -300.0f}, {300.0f, 800.0f, 300.0f}},
    {{0.0f, -800.0f, 0.0f}, {0.0f, -800.0f, 0.0f}},
    {{-50.0f, -50.0f, -50.0f}, {50.0f, 50.0f, 50.0f}}
};

s32 D_80391B44[3] = {225, 225, 245};

/* .code  */
Actor *func_80386B80(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(1, this->state == 3);
    func_8033A45C(2, func_8033A0F0(1) ^ 1);
    return actor_draw(marker, gfx, mtx, vtx);

}

void FP_func_80386BEC(Actor *this){
    f32 plyr_pos[3];
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(12);
    
    player_getPosition(plyr_pos);
    subaddie_set_state_with_direction(this, 2, 0.01f, 1);
    actor_collisionOff(this);
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
    FUNC_8030E624(SFX_90_SWITCH_PRESS, 1.0f, 32000);
    maSnowButton_decRemaining();
    particleEmitter_setRGB(pCtrl, D_80391B44);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setPosition(pCtrl, plyr_pos);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80391AFC);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_80391AD4);
    particleEmitter_emitN(pCtrl, 12);
}

void func_80386CB8(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    
    if(this->state == 1)
        FP_func_80386BEC(this);
    
}

void FP_func_80386CF8(Actor *this){
    marker_setCollisionScripts(this->marker, NULL, NULL, func_80386CB8);
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOn(this);
    
    if(!this->initialized){
        this->initialized = TRUE;
        this->pitch += (f32)(this->actorTypeSpecificField - 1);
    }
    
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(this->state == 3){
            maSnowButton_decRemaining();
        }
    }

    switch(this->state){
        case 1:
            break;
        case 2:
            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, 3, 0.99f, 0);
            }
            break;
        case 3:
            break;
    }
}
