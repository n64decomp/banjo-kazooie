#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80333334(enum jiggy_e arg0);

typedef struct {
    f32 position[3];//position
    u8  level_flag;
    u8  jiggy_id;
    s16 open_model;
    s16 closed_model;
    //u8  pad12[0x2];
    f32 jiggy_position[3];
} Struct_CC_1120_0;

typedef struct {
    Struct_CC_1120_0 *unk0;
} ActorLocal_CC_1120;

void chTooth_update(Actor *);

/* .data */
Struct_CC_1120_0 D_80389B50[] = {
    { { 522.9976f, 1135.8192f, 5503.4833f}, 0,             0x00, ASSET_891_MODEL_CLANKER_TOKEN_TOOTH_OPEN, ASSET_892_MODEL_CLANKER_TOKEN_TOOTH_CLOSED, { 540.0f, 1627.0f, 6641.0f}},
    { {-713.4896f, 1135.8192f, 5152.913f}, 1, JIGGY_1B_CC_TOOTH, ASSET_893_MODEL_CLANKER_JIGGY_TOOTH_OPEN, ASSET_894_MODEL_CLANKER_JIGGY_TOOTH_CLOSED, {-700.0f, 1536.0f, 6268.0f}}
};

ActorInfo D_80389B90 = {
    0x4E, ACTOR_101_CLANKER_TOKEN_TOOTH, ASSET_891_MODEL_CLANKER_TOKEN_TOOTH_OPEN, 
    0, NULL, 
    chTooth_update, func_80326224, func_80325888, 
    {0, 0, 0, 0}, 0.0f, {0, 0, 0, 0}
};

ActorInfo D_80389BB4 = {
    0x4F, ACTOR_102_CLANKER_JIGGY_TOOTH, ASSET_893_MODEL_CLANKER_JIGGY_TOOTH_OPEN, 
    0, NULL, 
    chTooth_update, func_80326224, func_80325888, 
    {0, 0, 0, 0}, 0.0f, {0, 0, 0, 0}
};

/* .rodata */
extern f32 D_80389F10;
extern f32 D_80389F14;
// 45A8C000 44B7C000

/* .code */
extern void __chTooth_setState(Actor *this, s32 next_state){
    ActorMarker *marker = this->marker;
    ActorLocal_CC_1120 * local = (ActorLocal_CC_1120 *) &this->local;
    this->state = next_state;

    if(next_state == 2){
        marker->modelId = local->unk0->open_model;
    }
    if(next_state == 1){
        marker->modelId = local->unk0->closed_model;
    }
}

extern void chTooth_update(Actor * this){
    ActorMarker *marker = this->marker;
    ActorLocal_CC_1120 * local = (ActorLocal_CC_1120 *) &this->local;
    f32 sp24[3];

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker->propPtr->unk8_3 = 1;
        local->unk0 = &D_80389B50[(this->modelCacheIndex == ACTOR_101_CLANKER_TOKEN_TOOTH) ? 0 : 1];
        this->position[0] = local->unk0->position[0];
        this->position[1] = local->unk0->position[1];
        this->position[2] = local->unk0->position[2];

        this->position[0] *= 1.25;
        this->position[1] *= 1.25;
        this->position[2] *= 1.25;
    }//L80387660
    if(this->state == 0){
        if(levelSpecificFlags_get(local->unk0->level_flag)){
            __chTooth_setState(this, 2);
        }
        else{
            __chTooth_setState(this, 1);
        }
    }
    else if(this->state == 2){//L803876B4
        if(local->unk0->jiggy_id && !jiggyscore_80320F7C(local->unk0->jiggy_id)){
            player_getPosition(sp24);
            if(sp24[0] < 0.0f && 5400.0f < sp24[2]){
                func_80333334(local->unk0->jiggy_id);
                jiggySpawn(local->unk0->jiggy_id, local->unk0->jiggy_position);
            }
            else{//L8038774C
                sp24[0] = local->unk0->jiggy_position[0];
                sp24[1] = local->unk0->jiggy_position[1];
                sp24[2] = local->unk0->jiggy_position[2];

                sp24[1] = 1470.0f;
                func_80333388(local->unk0->jiggy_id);
                func_803331D8(local->unk0->jiggy_id, sp24);
            }
        }
    }
}
