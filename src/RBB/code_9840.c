#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chRBBSpinningPipeSfxCtrl_update(Actor *this);

/* typedefs and declarations */
typedef struct {
    s32 unk0;
    s16 *actorId;
    ActorMarker *marker;
}ActorLocal_RBB_9840;

/*
These objects only exist in RBB's engine room.
As the spinning pipes rotate, these controllers
create sound effects based off of the rotation speed.
*/

/* .data */
s16 chRBBSpinningPipeSfxCtrlPipeActors[2] = {
    ACTOR_177_RBB_SPINNING_SINGLE_PIPE_1,
    ACTOR_17F_RBB_SPINNING_DOUBLE_PIPE_1
};

ActorInfo chRBBSpinningSinglePipeSfxCtrl = {
    MARKER_1D2_SPINNING_SINGLE_PIPE_SFX_CTRL, ACTOR_31B_SPINNING_SINGLE_PIPE_SFX_CTRL, 0x0,
    0x0, NULL,
    chRBBSpinningPipeSfxCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

ActorInfo chRBBSpinningDoublePipeSfxCtrl = {
    MARKER_1D3_DOUBLE_SINGLE_PIPE_SFX_CTRL, ACTOR_31C_DOUBLE_SINGLE_PIPE_SFX_CTRL, 0x0,
    0x0, NULL,
    chRBBSpinningPipeSfxCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

enum chrbbspinningdoublepipesfxctrl_state_e {
    CH_RBB_SPINNING_PIPE_SFX_CTRL_STATE_0_NOT_INIT,
    CH_RBB_SPINNING_PIPE_SFX_CTRL_STATE_1_INIT
};

/*.code */
// set state
void chRBBSpinningPipeSfxCtrl_setState(Actor *this, s32 next_state){
    this->state = next_state;
}

// update
void chRBBSpinningPipeSfxCtrl_update(Actor *this){
    ActorLocal_RBB_9840 *local = (ActorLocal_RBB_9840 *)&this->local;
    f32 sp20;
    f32 tmp_f2;
    s32 tmp_a1;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        actor_collisionOff(this);
        local->actorId = chRBBSpinningPipeSfxCtrlPipeActors + (this->marker->id - 0x1D2);
        local->marker = NULL;
        
        local->unk0 = func_802F9AA8(0x400);
        func_802F9DB8(local->unk0, 1.0f, 1.0f, 0.0f);
        func_802F9EC4(local->unk0, &this->position, 500, 1000);
        func_802F9F80(local->unk0, 0.0f, 8999999488.0f, 0.0f);
        func_802FA060(local->unk0, 22000, 22000, 0.0f);
        chRBBSpinningPipeSfxCtrl_setState(this, CH_RBB_SPINNING_PIPE_SFX_CTRL_STATE_1_INIT);
    }
    else{//L8038FD34
        if(local->marker == NULL)
            local->marker = actorArray_findActorFromActorId(*local->actorId)->marker;
        sp20 = func_8038A6B8(local->marker);
        tmp_f2 = 1.5 * sp20 + 0.5;
        func_802F9DB8(local->unk0, tmp_f2, tmp_f2, 0.0f);
        tmp_a1 = (s32) (sp20 * 32000.0f);
        func_802FA060(local->unk0, tmp_a1, tmp_a1, 0.0f);
    }
}
