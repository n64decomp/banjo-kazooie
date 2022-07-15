#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 unk0;
    s32 unk4;
}ActorLocal_GV_9860;

void func_8038FD8C(Actor *this);
Actor *func_8038FCF4(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo D_80391620 = { MARKER_1D4_SANDYBUTT_PYRAMID, ACTOR_31D_SANDYBUTT_PYRAMID, ASSET_56B_MODEL_SANDYBUTT_PYRAMID, 
    0, NULL,
    func_8038FD8C, NULL, func_8038FCF4, 
    0, 0, 0.0f, 0
};

/* .code */
void func_8038FC50(Actor *this, s32 next_state){
    s32 sp1C;
    
    if(next_state == 2){
        sp1C = func_802F9AA8(SFX_3EC_CCW_DOOR_OPENING);
        func_802F9DB8(sp1C, 0.7f, 0.9f, 0.03f);
        func_802F9F80(sp1C, 0.3f, 2.4f, 0.3f);
        func_802FA060(sp1C, 32000, 32000, 0.0f);
    }
    this->state = next_state;
}

Actor *func_8038FCF4(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_GV_9860 *local = (ActorLocal_GV_9860 *)&this->local;

    if(local->unk4 == 0){
        return func_80325340(this_marker, gfx, mtx, vtx);
    }
    else{
        return func_80325888(this_marker, gfx, mtx, vtx);
    }
}

void func_8038FD50(ActorMarker *this_marker, s32 arg1){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_GV_9860 *local = (ActorLocal_GV_9860 *)&this->local;

    local->unk0 = 0.0f;
    local->unk4 = arg1; 
    func_8038FC50(this, 2);
}

void func_8038FD8C(Actor *this){
    ActorLocal_GV_9860 *local = (ActorLocal_GV_9860 *)&this->local;
    f32 tmp_f2;
    f32 tmp_f0;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        local->unk4 = func_8031FF44(BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2);
        this->position_x = 67.0f;
        this->position_y = (local->unk4/3.0)*1050.0 + 1375.0;
        this->position_z = 400.0f;
        func_8038FC50(this, 1);
    }//L8038FE48

    if(this->state == 2){
        local->unk0 += time_getDelta()/3.0f;
        if(1.0f < local->unk0)
            local->unk0 = 1.0f;
        
        tmp_f0 = ((local->unk4 - 1)/3.0)*1050.0 + 1375.0;
        tmp_f2 = (local->unk4/3.0)*1050.0 + 1375.0;
        this->position_y = local->unk0*(tmp_f2 - tmp_f0) + tmp_f0;
        if(1.0f == local->unk0)
            func_8038FC50(this, 1);
    }//L8038FF48
}
