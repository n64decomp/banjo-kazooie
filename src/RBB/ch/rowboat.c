#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    f32 unk0;
    f32 playerInfluencedRotationDelta[3]; // something about rotation
    f32 position[3];
    f32 rotation[3];
    f32 timeDelta;
    f32 creakingSFXTimer;
}ActorLocal_RBB_7FD0;

void chRowboat_update(Actor *this);

/* .data */
ActorInfo chRowboat = {
    MARKER_1AB_ROWBOAT, ACTOR_297_ROWBOAT, ASSET_43C_MODEL_ROWBOAT,
    0x0, NULL,
    chRowboat_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};


/* .code */
void func_8038E3C0(Actor *this, s32 arg1){
    this->state = arg1;
}

void chRowboat_update(Actor *this){
    f32 rotation_delta[3];
    f32 position_delta[3];
    ActorLocal_RBB_7FD0 *local = (ActorLocal_RBB_7FD0 *) &this->local;
    int rotation_parameter;
    f32 time_delta = time_getDelta();
    f32 new_rotation[3];
    f32 player_position[3];
    
    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        local->unk0 = randf2(80.0f, 100.0f);
        local->timeDelta = 0.0f;
        local->creakingSFXTimer = 0.5f;
        this->position_y -= 10.0f;
        local->playerInfluencedRotationDelta[0] = 0.0f;
        local->playerInfluencedRotationDelta[1] = 0.0f;
        local->playerInfluencedRotationDelta[2] = 0.0f;
        local->position[0] = this->position_x;
        local->position[1] = this->position_y;
        local->position[2] = this->position_z;
        local->rotation[0] = this->pitch;
        local->rotation[1] = this->yaw;
        local->rotation[2] = this->roll;
        func_8038E3C0(this, 1);
    }//L8038E4C8

    if(ml_timer_update(&local->creakingSFXTimer, time_delta)){
        local->creakingSFXTimer = randf2(3.5f, 5.5f);
        func_8030E878(SFX_69_WHIPCRACK_CREAKING, randf2(1.1f, 1.2f), 22000, this->position, 500.0f, 1500.0f);
    }//L8038E544

    if(func_8032DCAC() == (int)this->marker && func_8028F20C()){
        player_getPosition(player_position);
        if(player_position[0] < this->position_x - 10.0f && local->playerInfluencedRotationDelta[2] < 3.0f)
            local->playerInfluencedRotationDelta[2] += 5.0f * time_delta;

        if(this->position_x + 10.0f < player_position[0] && -3.0f < local->playerInfluencedRotationDelta[2])
            local->playerInfluencedRotationDelta[2] -= 5.0f * time_delta;

        if(this->position_z + 10.0f < player_position[2] &&  local->playerInfluencedRotationDelta[0] < 5.0f)
            local->playerInfluencedRotationDelta[0] += 5.0f * time_delta;
        
        if(player_position[2] < this->position_z - 10.0f &&  -5.0f < local->playerInfluencedRotationDelta[0])
            local->playerInfluencedRotationDelta[0] -= 5.0f * time_delta;
    }
    else{ 
        for(rotation_parameter = 0; rotation_parameter < 3; rotation_parameter++){
            if(0.0f < local->playerInfluencedRotationDelta[rotation_parameter]){
                local->playerInfluencedRotationDelta[rotation_parameter] -= 2.5 * time_delta;
                if(local->playerInfluencedRotationDelta[rotation_parameter] < 0.0f)
                    local->playerInfluencedRotationDelta[rotation_parameter] = 0.0f;
            } else if(local->playerInfluencedRotationDelta[rotation_parameter] < 0.0f) { //L8038E710
                local->playerInfluencedRotationDelta[rotation_parameter] += 2.5 * time_delta;
                if(0.0f < local->playerInfluencedRotationDelta[rotation_parameter])
                    local->playerInfluencedRotationDelta[rotation_parameter] = 0.0f;
            }//L8038E74C
        }
    }//L8038E754

    local->timeDelta += time_delta;

    position_delta[0] = 0.0f;
    position_delta[1] = 5.0f * sinf((((local->timeDelta * 0.8) * local->unk0) / 180.0) * BAD_PI);
    position_delta[2] = 0.0f;

    rotation_delta[0] = 4.5 * cosf(((local->timeDelta * local->unk0) / 180.0) * BAD_PI);
    rotation_delta[1] = 1.5 * sinf((((local->timeDelta * 0.9) * local->unk0) / 180.0) * BAD_PI);
    rotation_delta[2] = 0.0f;

    this->position_x = local->position[0] + position_delta[0];
    this->position_y = local->position[1] + position_delta[1];
    this->position_z = local->position[2] + position_delta[2];

    new_rotation[0] = local->rotation[0] + rotation_delta[0];
    new_rotation[1] = local->rotation[1] + rotation_delta[1];
    new_rotation[2] = local->rotation[2] + rotation_delta[2];

    this->pitch = new_rotation[0] + local->playerInfluencedRotationDelta[0];
    this->yaw = new_rotation[1] + local->playerInfluencedRotationDelta[1];
    this->roll = new_rotation[2] + local->playerInfluencedRotationDelta[2];
}
