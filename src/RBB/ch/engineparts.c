#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef ABS
#define	ABS(d)		((d) >= 0) ? (d) : -(d)
#endif

/* typedefs and declarations */
typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    s16 unk18;
    s16 unk1A;
}Struct_RBB_40F0;

typedef struct {
    s32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
}ActorLocal_RBB_40F0;

void chRBBSpinningPipe_update(Actor *this);

/* .data */
Struct_RBB_40F0 D_80390760[4] = {
    {{ 1600.0f, 641.5f, -2700.0f}, {0.0f, 0.0f, 500.0f}, 0x27, 0},
    {{-1600.0f, 641.5f, -2700.0f}, {0.0f, 0.0f, 500.0f}, 0x28, 0},
    {{  300.0f, 641.5f,  -400.0f}, {-500.0f, 0.0f, 0.0f}, 0x27, 1},
    {{ -300.0f, 641.5f,  -400.0f}, {-500.0f, 0.0f, 0.0f}, 0x28, 1},
};

ActorInfo chRBBSpinningSinglePipe1 = {
    MARKER_187_RBB_SPINNING_SINGLE_PIPE_1, ACTOR_177_RBB_SPINNING_SINGLE_PIPE_1, ASSET_406_MODEL_RBB_SPINNING_SINGLE_PIPE, 0x0, NULL,
    chRBBSpinningPipe_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBSpinningSinglePipe2 = {
    MARKER_18E_RBB_SPINNING_SINGLE_PIPE_2, ACTOR_17E_RBB_SPINNING_SINGLE_PIPE_2, ASSET_406_MODEL_RBB_SPINNING_SINGLE_PIPE,
    0x0, NULL,
    chRBBSpinningPipe_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBSpinningDoublePipe1 = {
    MARKER_18F_RBB_SPINNING_DOUBLE_PIPE_1, ACTOR_17F_RBB_SPINNING_DOUBLE_PIPE_1, ASSET_407_MODEL_RBB_SPINNING_DOUBLEE_PIPE_RIGHT,
    0x0, NULL,
    chRBBSpinningPipe_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBSpinningDoublePipe2 = {
    MARKER_190_RBB_SPINNING_DOUBLE_PIPE_2, ACTOR_180_RBB_SPINNING_DOUBLE_PIPE_2, ASSET_408_MODEL_RBB_SPINNING_DOUBLEE_PIPE_LEFT,
    0x0, NULL,
    chRBBSpinningPipe_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

f32 D_80390860[3] = {1.0f, 0.5f, 0.5f};

enum chrbbspinningpipe_state_e {
    CH_RBB_SPINNING_PIPE_STATE_0_NOT_INIT,
    CH_RBB_SPINNING_PIPE_STATE_1_UNK,
    CH_RBB_SPINNING_PIPE_STATE_2_UNK,
    CH_RBB_SPINNING_PIPE_STATE_3_UNK
};

/* .code */
f32 func_8038A4E0(void) {
    return D_80390860[2 * levelSpecificFlags_get(LEVEL_FLAG_27_RBB_UNKNOWN) + levelSpecificFlags_get(LEVEL_FLAG_28_RBB_UNKNOWN)];
}

void chRBBSpinningPipe_setState(Actor *this, s32 next_state){
    ActorLocal_RBB_40F0 *local = (ActorLocal_RBB_40F0 *)&this->local;

    local->unk1C = 0.0f;

    if(next_state == CH_RBB_SPINNING_PIPE_STATE_1_UNK){
        if(D_80390760[local->unk0].unk1A){
            chRBBSpinningPipe_setState(this, CH_RBB_SPINNING_PIPE_STATE_2_UNK);
            return;
        }
        local->unk10[0] = D_80390760[local->unk0].unkC[0] * func_8038A4E0();
        local->unk10[1] = D_80390760[local->unk0].unkC[1] * func_8038A4E0();
        local->unk10[2] = D_80390760[local->unk0].unkC[2] * func_8038A4E0();
    }
    

    if(next_state == CH_RBB_SPINNING_PIPE_STATE_2_UNK){
        local->unk10[0] = D_80390760[local->unk0].unkC[0] * func_8038A4E0();
        local->unk10[1] = D_80390760[local->unk0].unkC[1] * func_8038A4E0();
        local->unk10[2] = D_80390760[local->unk0].unkC[2] * func_8038A4E0();
    }

    if(next_state == CH_RBB_SPINNING_PIPE_STATE_3_UNK){
        local->unk10[2] = 0.0f;
        local->unk10[1] = 0.0f;
        local->unk10[0] = 0.0f;
    }
    this->state = next_state;
}

f32 func_8038A6B8(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_40F0 *local = (ActorLocal_RBB_40F0 *)&actor->local;
    int i;
    f32 f12 = 0;

    for(i = 0; i < 3; i++){
        f12 += ABS(local->unk4[i]);
    }
    return f12 / 500.0f;
}

void chRBBSpinningPipe_update(Actor *this){
    ActorLocal_RBB_40F0 *local = (ActorLocal_RBB_40F0 *)&this->local;
    int i;
    f32 time_delta = time_getDelta();
    

    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        actor_collisionOff(this);
        local->unk0 = 0;
        local->unk0 = (this->modelCacheIndex == ACTOR_17E_RBB_SPINNING_SINGLE_PIPE_2) ? 1: local->unk0;
        local->unk0 = (this->modelCacheIndex == ACTOR_17F_RBB_SPINNING_DOUBLE_PIPE_1) ? 2: local->unk0;
        local->unk0 = (this->modelCacheIndex == ACTOR_180_RBB_SPINNING_DOUBLE_PIPE_2) ? 3: local->unk0;

        this->position_x = D_80390760[local->unk0].unk0[0];
        this->position_y = D_80390760[local->unk0].unk0[1];
        this->position_z = D_80390760[local->unk0].unk0[2];
        chRBBSpinningPipe_setState(this, CH_RBB_SPINNING_PIPE_STATE_1_UNK);
    }//L8038A884

    this->pitch += local->unk4[0] * time_delta;
    this->yaw += local->unk4[1] * time_delta;
    this->roll += local->unk4[2] * time_delta;

    for(i = 0; i < 3; i++){//L8038A8D4
        if(local->unk10[i] < local->unk4[i]){
            local->unk4[i] -= 75.0f * time_delta;
            local->unk4[i] = MAX(local->unk10[i], local->unk4[i]);
        }//L8038A924
        else if(local->unk4[i] < local->unk10[i]){
            local->unk4[i] += 75.0f * time_delta;
            local->unk4[i] = MIN(local->unk10[i], local->unk4[i]);
        }
    }

    if(this->state == CH_RBB_SPINNING_PIPE_STATE_1_UNK){
        local->unk10[0] = D_80390760[local->unk0].unkC[0] * func_8038A4E0();
        local->unk10[1] = D_80390760[local->unk0].unkC[1] * func_8038A4E0();
        local->unk10[2] = D_80390760[local->unk0].unkC[2] * func_8038A4E0();
    }
    
    if(this->state == CH_RBB_SPINNING_PIPE_STATE_2_UNK){
        if(0.0f < local->unk1C){
            if(ml_timer_update(&local->unk1C, time_delta)){
                chRBBSpinningPipe_setState(this, CH_RBB_SPINNING_PIPE_STATE_3_UNK);
            }//L8038AA8C
        }else{
            if( local->unk4[0] == local->unk10[0]
                && local->unk4[1] == local->unk10[1]
                && local->unk4[2] == local->unk10[2]
            ){
                local->unk1C = 1.0f;
            }
        }
    }//L8038AB04
    
    if(this->state == CH_RBB_SPINNING_PIPE_STATE_3_UNK){
        if(0.0f < local->unk1C){
            if(ml_timer_update(&local->unk1C, time_delta)){
                chRBBSpinningPipe_setState(this, CH_RBB_SPINNING_PIPE_STATE_2_UNK);
            }//L8038AA8C
        }else{
            if( local->unk4[0] == local->unk10[0]
                && local->unk4[1] == local->unk10[1]
                && local->unk4[2] == local->unk10[2]
            ){
                local->unk1C = 1.0f;
            }
        }
    }
}
