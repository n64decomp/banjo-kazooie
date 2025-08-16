#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chShockJump_update(Actor *this);
void chFlightPad_update(Actor *this);
void chFightFlightPad_update(Actor *this);

/* .data */
extern ActorInfo chShockJump = { 
    0x0D4, ACTOR_B_SHOCKSPRING_PAD, ASSET_489_MODEL_SHOCKSPRING_PAD, 
    0, NULL, 
    chShockJump_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

extern ActorInfo chFlightPad = { 
    MARKER_45_FLIGHT_PAD, ACTOR_E4_FLIGHT_PAD, ASSET_48A_MODEL_FLIGHT_PAD, 
    0, NULL, 
    chFlightPad_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

extern ActorInfo chFightFlightPad = { 
    MARKER_261_FIGHT_FLIGHT_PAD, ACTOR_39F_FIGHT_FLIGHT_PAD, ASSET_48A_MODEL_FLIGHT_PAD, 
    0, NULL, 
    chFightFlightPad_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};


extern ParticleScaleAndLifetimeRanges chFightFlightPad_D_80366F8C = {
    {0.4f, 0.4f}, 
    {0.0f, 0.0f}, 
    {0.0f, 0.01f}, 
    {3.0f, 3.0f}, 
    0.0f, 0.35f 
};


extern ParticleSettingsVelocityAccelerationPosition chFightFlightPad_D_80366FB4 = {
    {{-360.0f, 360.0f, -360.0}, {360.0f, 660.0f, 360.0f}}, 
    {{0.0f, -1200.0f, 0.0f}, {0.0f, -1200.0f, 0.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 40.0f, 0.0f}}
};

/* .code */
void chShockJump_update(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    if(volatileFlag_get(VOLATILE_FLAG_86_SANDCASTLE_SHOCKSPRING_JUMP_UNLOCKED)){
        ability_unlock(ABILITY_D_SHOCK_JUMP);
    }

    if(ability_isUnlocked(ABILITY_D_SHOCK_JUMP)){
        actor_setOpacity(this, 0xff);
    }
    else{
        actor_setOpacity(this, 0x5a);
    }
}

void chFlightPad_update(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    if(volatileFlag_get(VOLATILE_FLAG_8A_SANDCASTLE_FLIGHT_UNLOCKED)){
        ability_unlock(ABILITY_9_FLIGHT);
    }

    if(ability_isUnlocked(ABILITY_9_FLIGHT)){
        actor_setOpacity(this, 0xff);
    }
    else{
        actor_setOpacity(this, 0x5a);
    }

    if(map_get() == MAP_12_GV_GOBIS_VALLEY){
        this->unk6C = 352.0f;
        this->pitch = 352.0f;
        this->yaw_ideal = 90.0f;
        this->yaw = 90.0f;
    }
}

void chFightFlightPad_emitSparklesAtPosition(f32 position[3]){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0x18);
    particleEmitter_setSprite(pCtrl, ASSET_715_SPRITE_SPARKLE_RED);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &chFightFlightPad_D_80366FB4);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &chFightFlightPad_D_80366F8C);
    particleEmitter_func_802EFA78(pCtrl, 1);
    particleEmitter_emitN(pCtrl, 0x18);
}

void chFightFlightPad_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        chFightFlightPad_emitSparklesAtPosition(this->position);
        sfx_playFadeShorthandDefault(SFX_113_PAD_APPEARS, 1.0f, 32000, this->position, 5000, 12000);
    }
    this->marker->propPtr->unk8_3 = TRUE;
    this->alpha_124_19 = MIN(this->alpha_124_19 + this->unk38_31, 0xFF);
    actor_setOpacity(this, this->alpha_124_19);
        
}
