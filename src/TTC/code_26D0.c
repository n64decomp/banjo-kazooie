#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "SnS.h"

extern ActorInfo chClam;
extern ActorInfo TTC_D_8038C510;
extern ActorInfo D_8038C580;
extern ActorInfo D_8038C5E0;
extern ActorInfo D_8038C604;
extern ActorInfo D_8038C628;
extern ActorInfo D_8038C64C;
extern ActorInfo D_8038C670;
extern ActorInfo D_8038C694;
extern ActorInfo D_8038C6B8;
extern ActorInfo D_8038C6DC;
extern ActorInfo D_8038C718;
extern ActorInfo D_8038C790;
extern ActorInfo D_8038C7B4;
extern ActorInfo D_8038C7D8;
extern ActorInfo D_8038C8B0;
extern ActorInfo D_8038C8D4;
extern ActorInfo D_8038C8F8;
extern ActorInfo gChTreasureInfo;

void TTC_func_80388C78(Actor *this);
void func_80388CB8(Actor *this);
void func_80388D34(Actor *this);
void func_802D3D54(Actor *this);
void func_80388D8C(Actor *this);

/* .data */
ActorInfo D_8038C5E0 = {
     0xA1, 0x10E, 0x3D2,
     0x1, NULL, 
     func_802D3D54, func_80326224, actor_drawFullDepth,
     0, 0, 0.0f, 0
};

ActorInfo D_8038C604 = {
     MARKER_EA_LIGHTHOUSE_DOOR, ACTOR_13E_LIGHTHOUSE_DOOR, ASSET_3D6_MODEL_LIGHTHOUSE_DOOR,
     0x1, NULL, 
     func_802D3D54, func_80326224, actor_drawFullDepth,
     0, 0, 0.0f, 0
};

ActorInfo D_8038C628 = {
    MARKER_167_SHARKFOOD_ISLAND, ACTOR_25C_SHARKFOOD_ISLAND, ASSET_50A_MODEL_SHARKFOOD_ISLAND,
    0x1, NULL, 
    func_80388D8C, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038C64C = {
    0x267, 0x2E2, 0x3BD,
    0x1, NULL, 
    func_80388D34, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038C670 = {
    0x26A, 0x2DF, 0x3BE,
    0x1, NULL, 
    TTC_func_80388C78, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038C694 = {
    0x268, 0x2E0, 0x3B6,
    0x1, NULL, 
    TTC_func_80388C78, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038C6B8 = {
    0x269, 0x2E1, 0x3B7,
    0x1, NULL, 
    TTC_func_80388C78, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038C6DC = {
    MARKER_1D5_PALM_TREE, ACTOR_31E_PALM_TREE, ASSET_3A9_MODEL_PALM_TREE,
    0x1, NULL, 
    func_80388CB8, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

/* .code */
void TTC_func_80388AC0(void)
{
    spawnableActorList_add(&D_8038C5E0, actor_new, 0);
    spawnableActorList_add(&D_8038C604, actor_new, 0);
    spawnableActorList_add(&D_8038C580, actor_new, 0X4100168);
    spawnableActorList_add(&TTC_D_8038C510, actor_new, 0X4000101);
    spawnableActorList_add(&D_8038C718, actor_new, 0X188);
    spawnableActorList_add(&D_8038C790, actor_new, 0X148);
    spawnableActorList_add(&D_8038C7B4, actor_new, 0X148);
    spawnableActorList_add(&D_8038C7D8, actor_new, 0X148);
    spawnableActorList_add(&D_8038C8B0, actor_new, 0X400);
    spawnableActorList_add(&D_8038C8D4, actor_new, 0X400);
    spawnableActorList_add(&D_8038C8F8, actor_new, 0X400);
    spawnableActorList_add(&gChTreasureInfo, actor_new, 0X2000048);
    spawnableActorList_add(&D_8038C628, actor_new, 0X8680);
    spawnableActorList_add(&D_8038C64C, actor_new, 0X400);
    spawnableActorList_add(&D_8038C670, actor_new, 0X20404);
    spawnableActorList_add(&D_8038C694, actor_new, 0X400);
    spawnableActorList_add(&D_8038C6B8, actor_new, 0X400);
    spawnableActorList_add(&D_8038C6DC, actor_new, 0X400);
    spawnableActorList_add(&chClam, actor_new, 0X2000041);
}

void TTC_func_80388C78(Actor *this){
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
    }
}

void func_80388CB8(Actor *this){
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
        this->scale = 2.55f;
    }
}

void func_80388D04(s32 arg0){
    ActorMarker *marker = reinterpret_cast(ActorMarker *, arg0);
    Actor *this = marker_getActor(marker);
    spawn_child_actor(0x2df, &this);
}

void func_80388D34(Actor *this){
    TTC_func_80388C78(this);
    if(!this->unk16C_4){
        __spawnQueue_add_1((GenFunction_1)func_80388D04, (s32)this->marker);
        this->unk16C_4 = TRUE;
    }
}

void func_80388D8C(Actor *this){
    f32 sp1C[3];

    if(!this->initialized){
        func_802D3CE8(this);
        this->initialized = TRUE;
        this->position_x = 0.412*(8831.0f - this->position_x) + this->position_x;
        this->position_z = 0.412*(13535.0f - this->position_z) + this->position_z;
        this->yaw = 199.0f;
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(sns_get_item_state(SNS_ITEM_EGG_PINK, TRUE)){
            this->position_y = 700.0f;
        }
        else{
            this->position_y = -1000.0f;
        }
    }//L80388E7C

    if(this->position_y == 700.0f){
        player_getPosition(sp1C);
        if( 695.0f <= sp1C[1] && sp1C[1] < 1000.0f
            && (sp1C[0] - 5542.0f)*(sp1C[0] - 5542.0f) + (sp1C[2] - 8687.0f)*(sp1C[2] - 8687.0f) < 96100.0f
            && (sp1C[0] - 6837.0f)*(sp1C[0] - 6837.0f) + (sp1C[2] - 12714.0f)*(sp1C[2] - 12714.0f) < 17640000.0f
        ){
            func_8031D04C(0x8f, 1);
        }
    }
}
