#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void actor_setOpacity(Actor*,s32);
extern void func_8035644C(u32);

bool chCollectible_collectItem(Actor*, enum file_progress_e, enum asset_e, enum comusic_e, enum item_e, f32);
Actor *chCollectible_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void chCollectible_update(Actor *this);

/* .data */
extern ActorInfo D_80367D00 = {
    MARKER_60_BLUE_EGG_COLLECTIBLE, ACTOR_52_BLUE_EGG, ASSET_36D_SPRITE_BLUE_EGG,
    0, NULL, 
    chCollectible_update, func_80326224, chCollectible_draw, 
    0, 0, 0.7f, 0
};

extern ActorInfo D_80367D24 = {
    MARKER_B5_RED_FEATHER_COLLECTIBLE, ACTOR_129_RED_FEATHER, ASSET_580_SPRITE_RED_FEATHER,
    0, NULL, 
    chCollectible_update, func_80326224, chCollectible_draw, 
    0, 0, 0.5f, 0
};

extern ActorInfo D_80367D48 = {
    MARKER_1E5_GOLD_FEATHER_COLLECTIBLE, ACTOR_370_GOLD_FEATHER, ASSET_6D1_SPRITE_GOLDFEATHTER,
    0, NULL, 
    chCollectible_update, func_80326224, chCollectible_draw, 
    0, 0, 0.5f, 0
};

/* .code */
void chCollectible_setState(Actor *arg0, s32 next_state){
    switch(next_state){
        default:
            break;
        case 1:
            arg0->unk28 = 0.0f; 
            //fall-through
        case 3:
            actor_collisionOff(arg0);
            break;
        case 2:
            actor_collisionOn(arg0);
            break;
    }
    subaddie_set_state(arg0, next_state);
}

void func_802D8C98(Actor *this, s32 arg1) {
    s32 phi_v0;

    switch (this->marker->unk14_20)
    {
    case MARKER_60_BLUE_EGG_COLLECTIBLE:
        phi_v0 = TRUE;
        break;

    case MARKER_B5_RED_FEATHER_COLLECTIBLE:
        phi_v0 = (arg1 == 1) || (arg1 == 2) || (arg1 == 3);
        break;

    case MARKER_1E5_GOLD_FEATHER_COLLECTIBLE:
        phi_v0 = TRUE;
        break;

    default:
        phi_v0 = FALSE;
        break;
    }

    this->unk10_12 = arg1;
    chCollectible_setState(this, (phi_v0 ) ? 2 : 3);
}

bool chCollectible_collectItem(Actor* actor, enum file_progress_e arg1, enum asset_e dialogId, enum comusic_e sfxId, enum item_e itemId, f32 arg5){
    func_8025A6EC(sfxId,32000);
    timedFunc_set_1(0.75f, (GenFunction_1)func_8035644C, arg1);
    if(!func_802FADD4(0x1b)){
        item_inc(itemId);
    } else {
        item_adjustByDiffWithoutHud(itemId,1);   
    }

    if(!actor || !actor->unk38_0)
        return TRUE;
            
    actor->unk60 = arg5;
    chCollectible_setState(actor, 1);
    return FALSE;
}

s32 chCollectible_collectEgg(ActorProp *arg0){
    Actor *actPtr = NULL;
    if(arg0 != NULL){
        fxSparkle_blueEgg(&arg0->x);
        if(arg0->unk8_0)
            actPtr = marker_getActor(arg0->marker);
    }
    chCollectible_collectItem(actPtr, FILEPROG_5_BLUE_EGG_TEXT, 0xD9E, COMUSIC_C_EGG_COLLECTED, 0xD, 2.0f);
}

void chCollectible_collectRedFeather(ActorProp *arg0){
    Actor *actPtr = NULL;
    fxSparkle_redFeather(&arg0->x);
    if(arg0->unk8_0)
        actPtr = marker_getActor(arg0->marker);
    chCollectible_collectItem(actPtr, FILEPROG_6_RED_FEATHER_TEXT, 0xD9F, COMUSIC_B_RED_FEATHER_COLLECTED, 0xF, 4.0f);
}

void chCollectible_collectGoldFeather(ActorProp *arg0){
    Actor *actPtr = NULL;
    fxSparkle_goldFeather(&arg0->x);
    if(arg0->unk8_0)
        actPtr = marker_getActor(arg0->marker);
    chCollectible_collectItem(actPtr, FILEPROG_7_GOLD_FEATHER_TEXT, 0xDA0, COMUSIC_14_GOLD_FEATHER_COLLECTED, ITEM_10_GOLD_FEATHER, 6.0f);
}

Actor *chCollectible_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    Actor *thisActor = marker_getActor(this);

    if(thisActor->unk28 != 0.0f){
        if(thisActor->unk38_0){
            func_80344C2C(1);
            if(thisActor->unk28 == 255.0f){
                func_803262B8(thisActor);
            } else{
                actor_setOpacity(thisActor, thisActor->unk28);
            }
        }
        return func_80325934(this, gdl, mptr, arg3);
    }
    return thisActor;
}

void chCollectible_update(Actor *this) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    u32 temp_v0;

    if (!this->initialized) {
        if (this->marker->unk14_20 != 0x60) {
            func_8032AA58(this, 0.56f);
        }
        this->unk10_12 = -1;
        this->unk38_0 = (map_get() == MAP_90_GL_BATTLEMENTS);
        this->unk28 = this->unk38_0 ? 0.0f: 255.0f;
        this->initialized = TRUE;
    }
    if(!this->unk38_0)
        return;

    if (func_80320424(0x23, 3) != this->unk10_12) {
        func_802D8C98(this, func_80320424(0x23, 3));
    }

    switch (this->state) {
    case 1:
        if (this->unk60 > 0.0) {
            this->unk60 -= time_getDelta();
        } else {
            chCollectible_setState(this, 2);
        }
        /* fallthrough */
    case 3:
        if (this->unk28 > 0) {
            this->unk28 = MAX(this->unk28 - 8, 0);
        }
        break;
    case 2:
        if (this->unk28 < 255) {
            this->unk28 = MIN(this->unk28 + 8, 255);
        }
        break;
    }
}
