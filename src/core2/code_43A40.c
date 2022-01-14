#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802CA9D0(Actor *this);
void func_802CAA44(Actor *this);
void func_802CAB70(Actor *this);

/* .data */
extern ActorInfo D_80366F20 = { 
    0x0D4, ACTOR_B_SHOCKSPRING_PAD, ASSET_489_MODEL_SHOCKSPRING_PAD, 
    0, NULL, 
    func_802CA9D0, func_80326224, func_80325888,
    {0,0}, 0, 0.0f, {0,0,0,0}
};

extern ActorInfo D_80366F44 = { 
    0x045, ACTOR_E4_FLIGHT_PAD, ASSET_48A_MODEL_FLIGHT_PAD, 
    0, NULL, 
    func_802CAA44, func_80326224, func_80325888,
    {0,0}, 0, 0.0f, {0,0,0,0}
};

extern ActorInfo D_80366F68 = { 
    0x261, ACTOR_39F_FIGHT_FLIGHT_PAD, ASSET_48A_MODEL_FLIGHT_PAD, 
    0, NULL, 
    func_802CAB70, func_80326224, func_80325888,
    {0,0}, 0, 0.0f, {0,0,0,0}
};


extern struct31s D_80366F8C = {
    {0.4f, 0.4f}, 
    {0.0f, 0.0f}, 
    {0.0f, 0.01f}, 
    {3.0f, 3.0f}, 
    0.0f, 0.35f 
};


extern struct43s D_80366FB4 = {
    {{-360.0f, 360.0f}, {-360.0, 360.0f}, {660.0f, 360.0f}}, 
    {{0.0f, -1200.0f, 0.0f}, {0.0f, -1200.0f, 0.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 40.0f, 0.0f}}
};

/* .code */
void func_802CA9D0(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    if(func_803203FC(UNKFLAGS1_86_SANDCASTLE_SHOCKSPRING_JUMP_UNLOCKED)){
        ability_unlock(ABILITY_D_SHOCK_JUMP);
    }

    if(ability_isUnlocked(ABILITY_D_SHOCK_JUMP)){
        actor_setOpacity(this, 0xff);
    }
    else{
        actor_setOpacity(this, 0x5a);
    }
}

void func_802CAA44(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    if(func_803203FC(UNKFLAGS1_8A_SANDCASTLE_FLIGHT_UNLOCKED)){
        ability_unlock(ABILITY_9_FLY);
    }

    if(ability_isUnlocked(ABILITY_9_FLY)){
        actor_setOpacity(this, 0xff);
    }
    else{
        actor_setOpacity(this, 0x5a);
    }

    if(map_get() == MAP_12_GV_GOBIS_VALLEY){
        this->unk6C = 352.0f;
        this->pitch = 352.0f;
        this->yaw_moving = 90.0f;
        this->yaw = 90.0f;
    }
}

void func_802CAAF0(f32 position[3]){
    ParticleEmitter *pCtrl = func_802F0BD0(0x18);
    particleEmitter_setSprite(pCtrl, ASSET_715_SPRITE_SPARKLE_RED);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80366FB4);
    func_802EFB98(pCtrl, &D_80366F8C);
    func_802EFA78(pCtrl, 1);
    particleEmitter_emitN(pCtrl, 0x18);
}

void func_802CAB70(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        func_802CAAF0(this->position);
        FUNC_8030E8B4(SFX_113_PAD_APPEARS, 1000, 0x3ff, this->position, 5000, 12000);
    }
    this->marker->propPtr->unk8_3 = TRUE;
    this->alpha_124_19 = MIN(this->alpha_124_19 + this->unk38_31, 0xFF);
    actor_setOpacity(this, this->alpha_124_19);
        
}
