#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "SnS.h"
#include "actor.h"

extern ActorInfo gChClam;
extern ActorInfo gChBlubber;
extern ActorInfo gChNipper;
extern ActorInfo gBlubberShipTopHatch;
extern ActorInfo gLighthouseDoor;
extern ActorInfo gSharkfoodIsland;
extern ActorInfo gLighthouseA;
extern ActorInfo gLighthouseB;
extern ActorInfo gStairs1;
extern ActorInfo gStairs2;
extern ActorInfo gPalmTree;
extern ActorInfo gChLeaky;
extern ActorInfo gChLockupSlow;
extern ActorInfo gChLockupMedium;
extern ActorInfo gChLockupFast;
extern ActorInfo gChTreasurehuntRedArrow;
extern ActorInfo gChTreasurehuntRedQuestionMark;
extern ActorInfo gChTreasurehuntRedX;
extern ActorInfo gChTreasure;

void code26D0_genericUpdateFunc(Actor *this);
void code26D0_palmTreeUpdateFunc(Actor *this);
void code26D0_lighthouseAUpdateFunc(Actor *this);
void func_802D3D54(Actor *this);
void code26D0_sharkfoodIslandUpdateFunc(Actor *this);

/* .data */
ActorInfo gBlubberShipTopHatch = {
     MARKER_A1_BLUBBER_SHIP_TOP_HATCH, ACTOR_10E_BLUBBER_SHIP_TOP_HATCH, ASSET_3D2_MODEL_BLUBBER_SHIP_TOP_HATCH,
     0x1, NULL, 
     func_802D3D54, func_80326224, actor_drawFullDepth,
     0, 0, 0.0f, 0
};

ActorInfo gLighthouseDoor = {
     MARKER_EA_LIGHTHOUSE_DOOR, ACTOR_13E_LIGHTHOUSE_DOOR, ASSET_3D6_MODEL_LIGHTHOUSE_DOOR,
     0x1, NULL, 
     func_802D3D54, func_80326224, actor_drawFullDepth,
     0, 0, 0.0f, 0
};

ActorInfo gSharkfoodIsland = {
    MARKER_167_SHARKFOOD_ISLAND, ACTOR_25C_SHARKFOOD_ISLAND, ASSET_50A_MODEL_SHARKFOOD_ISLAND,
    0x1, NULL, 
    code26D0_sharkfoodIslandUpdateFunc, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo gLighthouseA = {
    MARKER_267_LIGHTHOUSE_A, ACTOR_2E2_LIGHTHOUSE_A, ASSET_3BD_MODEL_LIGHTHOUSE_A,
    0x1, NULL, 
    code26D0_lighthouseAUpdateFunc, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo gLighthouseB = {
    MARKER_26A_LIGHTHOUSE_B, ACTOR_2DF_LIGHTHOUSE_B, ASSET_3BE_MODEL_LIGHTHOUSE_B,
    0x1, NULL, 
    code26D0_genericUpdateFunc, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo gStairs1 = {
    MARKER_268_STAIRS_1, ACTOR_2E0_TTC_STAIRS_1, ASSET_3B6_MODEL_TTC_STAIRS_1,
    0x1, NULL, 
    code26D0_genericUpdateFunc, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo gStairs2 = {
    MARKER_269_STAIRS_2, ACTOR_2E1_TTC_STAIRS_2, ASSET_3B7_MODEL_TTC_STAIRS_1,
    0x1, NULL, 
    code26D0_genericUpdateFunc, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo gPalmTree = {
    MARKER_1D5_PALM_TREE, ACTOR_31E_PALM_TREE, ASSET_3A9_MODEL_PALM_TREE,
    0x1, NULL, 
    code26D0_palmTreeUpdateFunc, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

/* .code */
void TTC_resetSpawnableActors(void)
{
    spawnableActorList_add(&gBlubberShipTopHatch, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gLighthouseDoor, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gChNipper, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_26);
    spawnableActorList_add(&gChBlubber, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_26);
    spawnableActorList_add(&gChLeaky, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&gChLockupSlow, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&gChLockupMedium, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&gChLockupFast, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&gChTreasurehuntRedArrow, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gChTreasurehuntRedQuestionMark, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gChTreasurehuntRedX, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gChTreasure, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gSharkfoodIsland, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&gLighthouseA, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gLighthouseB, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&gStairs1, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gStairs2, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gPalmTree, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gChClam, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_25);
}

void code26D0_genericUpdateFunc(Actor *this){
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
    }
}

void code26D0_palmTreeUpdateFunc(Actor *this){
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
        this->scale = 2.55f;
    }
}

void code26D0_spawnLighthouseB(s32 arg0){
    ActorMarker *marker = reinterpret_cast(ActorMarker *, arg0);
    Actor *this = marker_getActor(marker);
    spawn_child_actor(ACTOR_2DF_LIGHTHOUSE_B, &this);
}

void code26D0_lighthouseAUpdateFunc(Actor *this){
    code26D0_genericUpdateFunc(this);
    if(!this->volatile_initialized){
        __spawnQueue_add_1((GenFunction_1)code26D0_spawnLighthouseB, (s32)this->marker);
        this->volatile_initialized = TRUE;
    }
}

void code26D0_sharkfoodIslandUpdateFunc(Actor *this){
    f32 player_position[3];

    if(!this->initialized){
        func_802D3CE8(this);
        this->initialized = TRUE;
        this->position_x = 0.412*(8831.0f - this->position_x) + this->position_x;
        this->position_z = 0.412*(13535.0f - this->position_z) + this->position_z;
        this->yaw = 199.0f;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(sns_get_item_state(SNS_ITEM_EGG_PINK, TRUE)){
            this->position_y = 700.0f;
        }
        else{
            this->position_y = -1000.0f;
        }
    }//L80388E7C

    if(this->position_y == 700.0f){
        player_getPosition(player_position);
        if( 695.0f <= player_position[1] && player_position[1] < 1000.0f
            && (player_position[0] - 5542.0f)*(player_position[0] - 5542.0f) + (player_position[2] - 8687.0f)*(player_position[2] - 8687.0f) < 96100.0f
            && (player_position[0] - 6837.0f)*(player_position[0] - 6837.0f) + (player_position[2] - 12714.0f)*(player_position[2] - 12714.0f) < 17640000.0f
        ){
            func_8031D04C(MAP_8F_TTC_SHARKFOOD_ISLAND, 1);
        }
    }
}
