#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802F82F4(s32, f32, f32, f32, f32);

typedef struct {
    s16 startState;
    //u8 pad[0x2];
    bool (*shouldStartFunc)(Actor *); 
} Struct_Core2_D2180_0;

typedef struct {
    Struct_Core2_D2180_0 *unk0;
} ActorLocal_core2_D2180;

int weatherParticle_isAlwaysActive(Actor *);
int weatherParticle_shouldStartCCWHubLeafFalling(Actor *);
int weatherParticle_isAlwaysActive(Actor *);
int weatherParticle_shouldStartCCWHubRainFalling(Actor *);
int weatherParticle_isAlwaysActive(Actor *);
int weatherParticle_shouldStartCCWHubSnowFalling(Actor *);
void weatherParticle_update(Actor *this);
void func_80359424(Actor *this);
void func_80359454(Actor *this);

/* .data */
enum weatherParticle_state_enum {
    WEATHERPARTICLE_STATE_0_NOT_INIT,
    WEATHERPARTICLE_STATE_1_IDLE,
    WEATHERPARTICLE_STATE_2_LEAF_FALLING,
    WEATHERPARTICLE_STATE_3_RAINING,
    WEATHERPARTICLE_STATE_4_SNOWING
};

Struct_Core2_D2180_0 D_80372940[] = {
    {WEATHERPARTICLE_STATE_2_LEAF_FALLING, weatherParticle_isAlwaysActive},
    {WEATHERPARTICLE_STATE_2_LEAF_FALLING, weatherParticle_shouldStartCCWHubLeafFalling},
    {WEATHERPARTICLE_STATE_3_RAINING,      weatherParticle_isAlwaysActive},
    {WEATHERPARTICLE_STATE_3_RAINING,      weatherParticle_shouldStartCCWHubRainFalling},
    {WEATHERPARTICLE_STATE_4_SNOWING,      weatherParticle_isAlwaysActive},
    {WEATHERPARTICLE_STATE_4_SNOWING,      weatherParticle_shouldStartCCWHubSnowFalling}
};

ActorInfo leafEmitterCCWAutumn = {
    0x1C1, ACTOR_2AE_LEAF_EMITTER_CCW_AUTUMN, 0x0,
    0, NULL,
    weatherParticle_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo leafEmitterCCWHub = {
    0x1C1, ACTOR_2AF_LEAF_EMITTER_CCW_HUB, 0x0,
    0, NULL,
    weatherParticle_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo rainEmitterCCWSpring = {
    0x1C1, ACTOR_2B0_RAIN_EMITTER_CCW_SPRING, 0x0,
    0, NULL,
    weatherParticle_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo rainEmitterCCWHub = {
    0x1C1, ACTOR_2B1_RAIN_EMITTER_CCW_HUB, 0x0,
    0, NULL,
    weatherParticle_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo snowEmitterCCWWinter = {
    0x1C1, ACTOR_2B2_SNOW_EMITTER_CCW_WINTER, 0x0,
    0, NULL,
    weatherParticle_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo snowEmitterCCWHub = {
    0x1C1, ACTOR_2B3_SNOW_EMITTER_CCW_HUB, 0x0,
    0, NULL,
    weatherParticle_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo D_80372A48 = {
    0x1C1, ACTOR_316_UNKNOWN, 0x0,
    0, NULL,
    func_80359424, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo D_80372A6C = {
    0x1C1, ACTOR_317_UNKNOWN, 0x0,
    0, NULL,
    func_80359454, NULL, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
bool weatherParticle_isAlwaysActive(Actor *this){
    return TRUE;
}

// Player's Z Position
bool weatherParticle_shouldStartCCWHubLeafFalling(Actor *this){
    f32 plyr_pos[3];
    
    player_getPosition(plyr_pos);
    return (plyr_pos[2] < -1700.0f);
}

bool weatherParticle_shouldStartCCWHubRainFalling(Actor *this){
    f32 plyr_pos[3];
    
    player_getPosition(plyr_pos);
    return (1700.0f < plyr_pos[2]);
}

bool weatherParticle_shouldStartCCWHubSnowFalling(Actor *this){
    f32 plyr_pos[3];
    
    player_getPosition(plyr_pos);
    return (1700.0f < plyr_pos[0]);
}

void weatherParticle_setState(Actor *this, s32 next_state){
    ActorLocal_core2_D2180 * local = (ActorLocal_core2_D2180 *) &this->local;
    s32 sp20;

    if(next_state == WEATHERPARTICLE_STATE_2_LEAF_FALLING)
        func_802F8C90(func_802F7C38());
    
    if(this->state == WEATHERPARTICLE_STATE_2_LEAF_FALLING)
        func_802F8CB0(func_802F7C38());

    if(next_state == WEATHERPARTICLE_STATE_3_RAINING){
        sp20 = func_802F7C7C();
        func_802F8338(sp20);
        if(local->unk0->shouldStartFunc == weatherParticle_isAlwaysActive)
            func_802F82F4(sp20, 5.0f, 30.0f, 5.0f, 30.0f);
    }

    if(this->state == WEATHERPARTICLE_STATE_3_RAINING)
        func_802F8358(func_802F7C7C());

    if(next_state == WEATHERPARTICLE_STATE_4_SNOWING){
        func_802F7CC0();
        func_802F90F4();
    }
    if(this->state == WEATHERPARTICLE_STATE_4_SNOWING){
        func_802F7CC0();
        func_802F9114();
    }

    this->state = next_state;
}

void weatherParticle_update(Actor *this){
    ActorLocal_core2_D2180 * local = (ActorLocal_core2_D2180 *) &this->local;
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->unk0 = D_80372940 + (this->modelCacheIndex - ACTOR_2AE_LEAF_EMITTER_CCW_AUTUMN);
        weatherParticle_setState(this, WEATHERPARTICLE_STATE_1_IDLE);
    }
    if(this->state == WEATHERPARTICLE_STATE_1_IDLE){
        if(local->unk0->shouldStartFunc(this)){
            weatherParticle_setState(this, local->unk0->startState);
        }
    }
    if(this->state != WEATHERPARTICLE_STATE_1_IDLE){
        if(!local->unk0->shouldStartFunc(this)){
            weatherParticle_setState(this, WEATHERPARTICLE_STATE_1_IDLE);
        }
    }
}

void func_80359424(Actor *this){
    if(func_803292E0(this))
        func_802F7D44();
}

void func_80359454(Actor *this){
    if(func_803292E0(this))
        func_802F7DE4();
}
