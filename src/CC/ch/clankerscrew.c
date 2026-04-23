#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    f32 upperIdleTimer;
    f32 lowerIdleTimer;
    f32 timeDelta;
    u8  isIdle;
} maClankersScrewActor;

void func_803864D4(Actor *this);

/* .data */
ActorInfo maClankersScrew = {
    MARKER_4B_CC_SCREW, ACTOR_43_CLACKER_SCREW, ASSET_890_MODEL_SCREW,
    0, NULL, 
    func_803864D4, actor_update_func_80326224 , actor_draw,  
    0, 0, 0.0f, 0
};

enum maClankerScrewStates_e{
    CC_SCREW_STATE_1_LOWER_IDLE = 1,
    CC_SCREW_STATE_2_MOVING_UP,
    CC_SCREW_STATE_3_UPPER_IDLE,
    CC_SCREW_STATE_4_MOVING_DOWN
};

/* .code */
void maClankersScrew_setNextState(Actor *this, s32 next_state){
    maClankersScrewActor * local = (maClankersScrewActor *)this->local;
    if(this->state == CC_SCREW_STATE_4_MOVING_DOWN){
        maClanker_playScrewNoise(0);
    }
    this->state = next_state;
    local->isIdle = 1;
    local->upperIdleTimer = 0.0f;
    local->lowerIdleTimer = 0.0f;
    local->timeDelta = 0.0f;
    if(CC_SCREW_STATE_1_LOWER_IDLE == this->state){
        local->lowerIdleTimer = 2.0f;
    }
    if(this->state == CC_SCREW_STATE_2_MOVING_UP){
        maClanker_playScrewNoise(1);
    }
    if(this->state == CC_SCREW_STATE_3_UPPER_IDLE){
        local->upperIdleTimer = 1.0f;
    }

}

void func_803864D4(Actor *this){
    ActorMarker *marker = this->marker;//sp5C;
    maClankersScrewActor * local = (maClankersScrewActor *)this->local;
    f32 lower_position[3];
    f32 upper_position[3];
    f32 time_delta = time_getDelta();
    f32 position_diff[3];
    f32 local_time_delta;
    f32 sin_result;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker->propPtr->unk8_3 = 1;
        maClankersScrew_setNextState(this, CC_SCREW_STATE_1_LOWER_IDLE);
    }//L80386530

    func_80388B4C(&lower_position);
    TUPLE_ASSIGN(upper_position, 2640.0f, 5695.0f, -10.0f);
    local->timeDelta += time_delta;
    if(ml_timer_update(&local->lowerIdleTimer, time_delta)){
        position_diff[0] = lower_position[0] - upper_position[0];
        position_diff[1] = 0.0f;
        position_diff[2] = lower_position[2] - upper_position[2];
        if(!CC_func_80388CA0()){
            local->lowerIdleTimer = 2.0f;
        }
        else if(60.0f < LENGTH_VEC3F(position_diff)){
            local->lowerIdleTimer = 0.05f;
        }
        else{
            maClankersScrew_setNextState(this, CC_SCREW_STATE_2_MOVING_UP);
        }
    }//L80386634

    if(ml_timer_update(&local->upperIdleTimer, time_delta)){
        maClankersScrew_setNextState(this, CC_SCREW_STATE_4_MOVING_DOWN);
    }
    
    if((this->state == CC_SCREW_STATE_2_MOVING_UP) && (1.0 <= local->timeDelta)){
            maClankersScrew_setNextState(this, CC_SCREW_STATE_3_UPPER_IDLE);
    }//L803866B4

    if((this->state == CC_SCREW_STATE_4_MOVING_DOWN) && (1.0 <= local->timeDelta)){
            maClankersScrew_setNextState(this, CC_SCREW_STATE_1_LOWER_IDLE);
    }//L80386714

    if(this->state == CC_SCREW_STATE_1_LOWER_IDLE){
        this->position[0] = lower_position[0];
        this->position[1] = lower_position[1];
        this->position[2] = lower_position[2];
    }
    else if(this->state == CC_SCREW_STATE_2_MOVING_UP)
    {//L80386734
        local_time_delta = local->timeDelta/1.0;
        if(local->isIdle && 0.6 < local_time_delta){
            sfx_playFadeShorthandDefault(SFX_91_METALLIC_SOUND, 1.0, 32000, this->position, 100, 6000);
            local->isIdle = 0;
        }//L80386798
        sin_result = sinf(((local_time_delta*90.0)/180.0)*BAD_PI);
        this->position_x = lower_position[0] + (upper_position[0] - lower_position[0])*sin_result;
        this->position_y = lower_position[1] + (upper_position[1] - lower_position[1])*sin_result;
        this->position_z = lower_position[2] + (upper_position[2] - lower_position[2])*sin_result;
    }//L80386818
    else if(this->state == CC_SCREW_STATE_3_UPPER_IDLE){
        this->position[0] = upper_position[0];
        this->position[1] = upper_position[1];
        this->position[2] = upper_position[2];
    }
    else if(this->state == CC_SCREW_STATE_4_MOVING_DOWN){
        local_time_delta = 1 - local->timeDelta/1.0;
        if(local->isIdle && local_time_delta < 0.1){
            local->isIdle = 0;
        }//L8038688C
        sin_result = sinf(((local_time_delta*90.0)/180.0)*BAD_PI);
        this->position_x = lower_position[0] + (upper_position[0] - lower_position[0])*sin_result;
        this->position_y = lower_position[1] + (upper_position[1] - lower_position[1])*sin_result;
        this->position_z = lower_position[2] + (upper_position[2] - lower_position[2])*sin_result;
    }//L80386904
}
