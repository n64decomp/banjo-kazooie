#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 transistion_timer;
    s32 raised_state;
}ActorLocal_chBuriedPyramid;

void chBuriedPyramid_update(Actor *this);
Actor *chBuriedPyramid_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chBuriedPyramid = { MARKER_1D4_SANDYBUTT_PYRAMID, ACTOR_31D_SANDYBUTT_PYRAMID, ASSET_56B_MODEL_SANDYBUTT_PYRAMID, 
    0, NULL,
    chBuriedPyramid_update, NULL, chBuriedPyramid_draw, 
    0, 0, 0.0f, 0
};

/* .code */
void __chBuriedPyramid_setState(Actor *this, s32 next_state){
    s32 sp1C;
    
    if(next_state == 2){
        sp1C = func_802F9AA8(SFX_3EC_CCW_DOOR_OPENING);
        func_802F9DB8(sp1C, 0.7f, 0.9f, 0.03f);
        func_802F9F80(sp1C, 0.3f, 2.4f, 0.3f);
        func_802FA060(sp1C, 32000, 32000, 0.0f);
    }
    this->state = next_state;
}

Actor *chBuriedPyramid_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_chBuriedPyramid *local = (ActorLocal_chBuriedPyramid *)&this->local;

    if(local->raised_state == 0){
        return func_80325340(this_marker, gfx, mtx, vtx);
    }
    else{
        return func_80325888(this_marker, gfx, mtx, vtx);
    }
}

void chBuriedPyramid_setRaisedAmount(ActorMarker *this_marker, s32 arg1){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_chBuriedPyramid *local = (ActorLocal_chBuriedPyramid *)&this->local;

    local->transistion_timer = 0.0f;
    local->raised_state = arg1; 
    __chBuriedPyramid_setState(this, 2);
}

void chBuriedPyramid_update(Actor *this){
    ActorLocal_chBuriedPyramid *local = (ActorLocal_chBuriedPyramid *)&this->local;
    f32 max;
    f32 min;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        local->raised_state = func_8031FF44(BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2);
        this->position_x = 67.0f;
        this->position_y = (local->raised_state/3.0)*1050.0 + 1375.0;
        this->position_z = 400.0f;
        __chBuriedPyramid_setState(this, 1);
    }//L8038FE48

    if(this->state == 2){
        local->transistion_timer += time_getDelta()/3.0f;
        if(1.0f < local->transistion_timer)
            local->transistion_timer = 1.0f;
        
        min = ((local->raised_state - 1)/3.0)*1050.0 + 1375.0;
        max = (local->raised_state/3.0)*1050.0 + 1375.0;
        this->position_y = local->transistion_timer*(max - min) + min;
        if(1.0f == local->transistion_timer)
            __chBuriedPyramid_setState(this, 1);
    }//L8038FF48
}
