#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 actorId;
    f32 position[3];
    s16 mapSpecificFlag;
} Struct_ChWhistleSwitchInfo;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    Struct_ChWhistleSwitchInfo *whistleSwitchInfo;
    f32 unk8;
    BKVertexList *unkC;
} ActorLocal_RBB_47D0;

Actor *chRBBWhistleSwitch_draw(ActorMarker *marker, Gfx** gdl, Mtx** mptr, Vtx **arg3);
void chRBBWhistleSwitch_update(Actor *this);


/* .data */
Struct_ChWhistleSwitchInfo chWhistleSwitchTable[4] = {
    {ACTOR_1BF_WHISTLE_SWITCH_1, {-3950.0f, 690.0f, -350.0f}, RBB_MAIN_SPECIFIC_FLAG_1_WHISTLE_SWITCH_1},
    {ACTOR_1C0_WHISTLE_SWITCH_2, {-3950.0f, 690.0f, 0.0f},    RBB_MAIN_SPECIFIC_FLAG_2_WHISTLE_SWITCH_2},
    {ACTOR_1C1_WHISTLE_SWITCH_3, {-3950.0f, 690.0f, 350.0f},  RBB_MAIN_SPECIFIC_FLAG_3_WHISTLE_SWITCH_3},
    NULL
};

extern ActorInfo chRBBWhistleSwitch1 = {
    MARKER_195_WHISTLE_SWITCH_1, ACTOR_1BF_WHISTLE_SWITCH_1, ASSET_413_MODEL_WHISTLE_SWITCH_1,
    0x0, NULL,
    chRBBWhistleSwitch_update, NULL, chRBBWhistleSwitch_draw,
    0, 0, 0.0f, 0
};

extern ActorInfo chRBBWhistleSwitch2 = {
    MARKER_196_WHISTLE_SWITCH_2, ACTOR_1C0_WHISTLE_SWITCH_2, ASSET_414_MODEL_WHISTLE_SWITCH_2,
    0x0, NULL,
    chRBBWhistleSwitch_update, NULL, chRBBWhistleSwitch_draw,
    0, 0, 0.0f, 0
};

extern ActorInfo chRBBWhistleSwitch3 = {
    MARKER_197_WHISTLE_SWITCH_3, ACTOR_1C1_WHISTLE_SWITCH_3, ASSET_415_MODEL_WHISTLE_SWITCH_3,
    0x0, NULL,
    chRBBWhistleSwitch_update, NULL, chRBBWhistleSwitch_draw,
    0, 0, 0.0f, 0
};

s32 D_8039092C[3] = { 0, 0xFF, 0};
s32 D_80390938[3] = { 0xFF, 0, 0};

enum chrbbwhistleswitch_state_e {
    CH_RBB_WHISTLE_SWITCH_STATE_0_NOT_INIT,
    CH_RBB_WHISTLE_SWITCH_STATE_1_UNK,
    CH_RBB_WHISTLE_SWITCH_STATE_2_UNK
};

/* .code */
Struct_ChWhistleSwitchInfo *chWhistleSwitch_getInfoPointer(Actor *this){
    Struct_ChWhistleSwitchInfo *iPtr = chWhistleSwitchTable;
    while(iPtr->actorId != NULL){
        if(iPtr->actorId == this->modelCacheIndex)
            return iPtr;
        iPtr++;
    }
    return NULL;
}   

void chRBBWhistleSwitch_setState(Actor *this, s32 new_state){
    ActorLocal_RBB_47D0 *local = (ActorLocal_RBB_47D0 *)&this->local;
    Actor *whistle_ctrl;
    local->unk8 = 0.0f;
    if(new_state == CH_RBB_WHISTLE_SWITCH_STATE_2_UNK){
        func_8030E6D4(SFX_90_SWITCH_PRESS);
        local->unkC = vtxList_clone(modelbin_getVtxList(marker_loadModelBin(this->marker)));
        
        mapSpecificFlags_set(local->whistleSwitchInfo->mapSpecificFlag, TRUE);
        this->position_y -= 30.0f;
        local->unk8 = 1.0f;
        whistle_ctrl = actorArray_findActorFromActorId(ACTOR_1C5_WHISTLE_CTRL);
        if(whistle_ctrl){
            local->unk0 = chWhistleCtrl_newEvent(whistle_ctrl, this->modelCacheIndex - ACTOR_1BE_RBB_GREY_PROPELLOR_SWITCH, this);
        }
    }//L8038ACD0

    if(this->state == CH_RBB_WHISTLE_SWITCH_STATE_2_UNK){
        this->position_x = local->whistleSwitchInfo->position[0];
        this->position_y = local->whistleSwitchInfo->position[1];
        this->position_z = local->whistleSwitchInfo->position[2];
        vtxList_free(local->unkC);
    }
    this->state = new_state;
}

void chRBBWhistleSwitch_press(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1)
        chRBBWhistleSwitch_setState(actor, 2);
}

void chRBBWhistleSwitch_free(Actor *this){
    chRBBWhistleSwitch_setState(this, CH_RBB_WHISTLE_SWITCH_STATE_0_NOT_INIT);
}

Actor *chRBBWhistleSwitch_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    Actor * actor = marker_getActor(marker);
    ActorLocal_RBB_47D0 *local = (ActorLocal_RBB_47D0 *)&actor->local;
    BKModelBin *temp_v0;
    f32 pad0;
    s32 *sp1C;

    if(actor->state == 0)
        return actor;
    
    if( actor->state == 2 
        && local->unk0 != 0
    ){
        temp_v0 = marker_loadModelBin(marker);
        sp1C = (local->unk0 == 2) ? D_80390938 : D_8039092C;
        vtxList_tintColorsFrom(local->unkC, sp1C, 
            (local->whistleSwitchInfo->position[1] - actor->position_y) / 30.0,
            modelbin_getVtxList(temp_v0)
        );
        modelRender_setVertexList(local->unkC);
    }
    return actor_draw(marker, gdl, mptr, arg3);
}

void chRBBWhistleSwitch_update(Actor *this){
    ActorLocal_RBB_47D0 *local = (ActorLocal_RBB_47D0 *)&this->local;
    f32 time_delta = time_getDelta();
    s32 y_position;
    
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = 1;
        this->marker->actorFreeFunc = chRBBWhistleSwitch_free;
        marker_setCollisionScripts(this->marker, NULL, chRBBWhistleSwitch_press, NULL);
        local->whistleSwitchInfo = chWhistleSwitch_getInfoPointer(this);
        mapSpecificFlags_set(local->whistleSwitchInfo->mapSpecificFlag, FALSE);
        this->position_x = local->whistleSwitchInfo->position[0];
        this->position_y = local->whistleSwitchInfo->position[1];
        this->position_z = local->whistleSwitchInfo->position[2];
        this->yaw = -90.0f;
        chRBBWhistleSwitch_setState(this, CH_RBB_WHISTLE_SWITCH_STATE_1_UNK);
    }//L8038AF88

    if(ml_timer_update(&local->unk8, time_delta))
        chRBBWhistleSwitch_setState(this, CH_RBB_WHISTLE_SWITCH_STATE_1_UNK);

    if(this->state == CH_RBB_WHISTLE_SWITCH_STATE_2_UNK){
        y_position = (s32)this->position_y;
        if(this->position_y < local->whistleSwitchInfo->position[1])
            this->position_y += 60.0f * time_delta;
        
        if( y_position <  local->whistleSwitchInfo->position[1] - 15.0f
            && local->whistleSwitchInfo->position[1] - 15.0f <= this->position_y
        ){
            mapSpecificFlags_set(local->whistleSwitchInfo->mapSpecificFlag, FALSE);
        }
    }//L8038B044
}
