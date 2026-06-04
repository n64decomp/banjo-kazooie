#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    f32 unk0;
    ActorMarker *jinjoMarker;
    f32 position[3];
    f32 rotation[3];
    s32 unk20;
    f32 timer[3];
} ActorLocal_7B20;

void chBellBuoy_update(Actor* this);


/* .data */
ActorInfo chBellBuoy = {
    MARKER_1AA_BELL_BUOY, ACTOR_296_BELL_BUOY, ASSET_43B_MODEL_BELL_BUOY,
    0x0, NULL,
    chBellBuoy_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chbellbuoy_state_e {
    CH_BELL_BUOY_STATE_0_NOT_INIT,
    CH_BELL_BUOY_STATE_1_INIT
};

/*.code */
void chBellBuoy_setState(Actor *this, int next_state){
    if(next_state == CH_BELL_BUOY_STATE_1_INIT){
        skeletalAnim_set(this->unk148, ASSET_16A_ANIM_BELL_BUOY, 0, 1.2f);
    }
    this->state = next_state;
}

void chBellBuoy_update(Actor* this){
    f32 rotation_delta[3];
    f32 position_delta[3];
    f32 sp6C;
    f32 time_delta = time_getDelta();
    f32 new_rotation[3];
    f32 distance;
    ActorLocal_7B20 *local = (ActorLocal_7B20 *)&this->local;
    Actor* jinjo;
    int actor_id;
    
    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        local->unk0 = randf2(80.0f, 100.0f);
        local->jinjoMarker = NULL;
        local->unk20 = 0;
        local->timer[0] = 0.0f;
        local->timer[1] = 1.0f;
        local->timer[2] = 0.5f;
        local->position[0] = this->position_x;
        local->position[1] = this->position_y;
        local->position[2] = this->position_z;
        local->rotation[0] = this->pitch;
        local->rotation[1] = this->yaw;
        local->rotation[2] = this->roll;
        chBellBuoy_setState(this, CH_BELL_BUOY_STATE_1_INIT);
    }//L8038E050

    if(++local->unk20 == 2){
        // Actor 0x5E through 0x62 are Jinjos
        for(actor_id = 0x5E; actor_id < 0x63; actor_id++){
            
            jinjo = actorArray_findClosestActorFromActorId(this->position, actor_id, -1, &distance);
            if(distance < 300.0f){
                local->jinjoMarker = jinjo->marker;
                jinjo->position_x = this->position_x;
                jinjo->position_y = this->position_y;
                jinjo->position_z = this->position_z;
                break;
            }
        }
    }

    if(ml_timer_update(&local->timer[1], time_delta)){
        local->timer[1] = randf2(1.5f, 2.5f);
        sfx_playFadeShorthandDefault(SFX_40E_UNKNOWN, 1.5f, 20000, this->position, 500, 1500);
    }//L8038E118

    if(ml_timer_update(&local->timer[2], time_delta)){
        local->timer[2] = randf2(3.5f, 5.5f);
        func_8030E878(SFX_69_WHIPCRACK_CREAKING, randf2(1.1f, 1.2f), 22000, this->position, 500.0f, 1500.0f);
    }//L8038E184

    local->timer[0] += time_delta;
    position_delta[0] = 0.0f;
    position_delta[1] = sinf((local->timer[0] * local->unk0) / 180.0 * BAD_PI) * 10.0f;
    position_delta[2] = 0.0f;

    rotation_delta[0] = cosf((local->timer[0] * local->unk0) / 180.0 * BAD_PI) * 7.5;
    rotation_delta[1] = sinf((local->timer[0] * local->unk0) / 180.0 * BAD_PI) * 3.0;
    rotation_delta[2] = 0.0f;

    this->position_x = local->position[0] + position_delta[0];
    this->position_y = local->position[1] + position_delta[1];
    this->position_z = local->position[2] + position_delta[2];

    new_rotation[0] = local->rotation[0] + rotation_delta[0];
    new_rotation[1] = local->rotation[1] + rotation_delta[1];
    new_rotation[2] = local->rotation[2] + rotation_delta[2];

    this->pitch = new_rotation[0];
    this->yaw = new_rotation[1];
    this->roll = new_rotation[2];

    if(local->jinjoMarker){
        jinjo = marker_getActor(local->jinjoMarker);
        // State 7-9 Are Collecting Jinjo States
        if(!(jinjo->state < 7)){
            local->jinjoMarker = NULL;
        }else{
            jinjo->pitch = new_rotation[0];
            jinjo->roll = new_rotation[2];
            TUPLE_ASSIGN(new_rotation, 0.0f, 48.0f, 0.0f);
            ml_vec3f_pitch_rotate_copy(new_rotation, new_rotation, this->pitch);
            ml_vec3f_yaw_rotate_copy(new_rotation, new_rotation, this->yaw);
        
            jinjo->position_x = new_rotation[0] + this->position_x;
            jinjo->position_y = new_rotation[1] + this->position_y;
            jinjo->position_z = new_rotation[2] + this->position_z;
        }
    }//L8038E39C
}
