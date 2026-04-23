#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
extern void actor_predrawMethod(Actor *);
extern void actor_postdrawMethod(ActorMarker *);
extern f32 randf (void);
extern BKModelBin *chMrVileMinigame_getGrumblieModel(ActorMarker *marker);

enum chyumblie_state_e{
    YUMBLIE_STATE_1_UNDER_GROUND = 1,
    YUMBLIE_STATE_2_APPEAR,
    YUMBLIE_STATE_3_ABOVE_GROUND,
    YUMBLIE_STATE_4_DISAPPEAR,
    YUMBLIE_STATE_5_BEING_EATEN
};

typedef struct chyumblie_s{
    f32 animTimer;
    u8  isGrumblie;
    u8  pad7[3];
    f32 waitTimer;
    ActorMarker *game_marker;
} ActorLocal_Yumblie;

void chYumblie_setState(Actor*, enum chyumblie_state_e);
void chYumblie_update(Actor *);
Actor *chYumblie_draw(ActorMarker *this, Gfx **gfx, Mtx** mtx, Vtx **vtx);

/* .data */
ActorInfo gChYumblie = {
    MARKER_C7_YUMBLIE, ACTOR_139_YUMBLIE, ASSET_3F6_MODEL_YUMBLIE,
    0x00, NULL,
    chYumblie_update, NULL, chYumblie_draw,
    0, 0, 0.0f, 0
};

/* .code */
bool chYumblie_isGrumblie(Actor *this){
    ActorLocal_Yumblie *local;
    s32 dialog_index;

    local = (ActorLocal_Yumblie *)&this->local;
    dialog_index = chMrVileMinigame_getDialogIndex(local->game_marker);

    if ((dialog_index == 1) || (dialog_index == 4)) {
        return FALSE;
    }

    if ((dialog_index == 2) || (dialog_index == 5)) {
        return BOOL(0.7 <= randf());
    }

    return BOOL(randf() >= 0.5);
}

void chYumblie_setState(Actor* this, enum chyumblie_state_e next_state){
    ActorLocal_Yumblie *local;
    local = (ActorLocal_Yumblie *)&this->local;
    local->waitTimer = 0;
    if(next_state == YUMBLIE_STATE_1_UNDER_GROUND){
        local->waitTimer = randf2(1.0f, 10.0f);
    }
     
    if(next_state == YUMBLIE_STATE_2_APPEAR){
        this->yaw = randf2(0.0f, 360.0f);
        local->isGrumblie = chYumblie_isGrumblie(this);
        chMrVileMinigame_newPiece(local->game_marker, this->marker, this->position, local->isGrumblie);
        skeletalAnim_set(this->unk148, (local->isGrumblie)? ASSET_128_ANIM_GRUMBLIE_APPEAR : ASSET_125_ANIM_YUMBLIE_APPEAR, 0.0f, 1.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if(next_state == YUMBLIE_STATE_3_ABOVE_GROUND){
        local->waitTimer = randf2(5.0f, 10.0f);
        skeletalAnim_set(this->unk148, (local->isGrumblie)? ASSET_12A_ANIM_GRUMBLIE_IDLE : ASSET_127_ANIM_YUMBLIE_IDLE, 0.1f, randf2(0.5f, 1.0f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        if(local->isGrumblie){
            gcsfx_playWithPitch(SFX_C4_TWINKLY_MUNCHER_GRR, randf2(1.0f, 1.2), 30000);
        }else{
            func_8030E878(SFX_C3_HEGH, randf2(1.0f, 1.2), 30000, this->position, 500.0f, 3000.0f);
        }
    }
    
    if(next_state == YUMBLIE_STATE_4_DISAPPEAR){
        chMrVileMinigame_removePiece(local->game_marker, this->marker);
        skeletalAnim_set(this->unk148, (local->isGrumblie)? ASSET_129_ANIM_GRUMBLIE_HIDE : ASSET_126_ANIM_YUMBLIE_HIDE, 0.1f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if(next_state == YUMBLIE_STATE_5_BEING_EATEN){
        local->waitTimer = randf2(10.0f, 20.0f);
        chMrVileMinigame_removePiece(local->game_marker, this->marker);
        func_8030E878((local->isGrumblie)? SFX_C4_TWINKLY_MUNCHER_GRR: SFX_C3_HEGH, 1.4f, 32000, this->position, 500.0f, 3000.0f);
    }
    this->state = next_state;
}

bool chyumblie_is_edible(ActorMarker * arg0){
    volatile Actor* actPtr;

    actPtr = marker_getActor(arg0);
    return (actPtr->state >= YUMBLIE_STATE_2_APPEAR) && (actPtr->state < YUMBLIE_STATE_5_BEING_EATEN);
}

Actor *chYumblie_draw(ActorMarker *this, Gfx **gfx, Mtx** mtx, Vtx **vtx){
    Actor *thisActor;
    ActorLocal_Yumblie *local;
    f32 actor_position[3];
    f32 actor_rotation[3];
    
    thisActor = marker_getActor(this);
    local = (ActorLocal_Yumblie *)&thisActor->local;
    if ( thisActor->state < YUMBLIE_STATE_2_APPEAR || thisActor->state > YUMBLIE_STATE_4_DISAPPEAR){
        thisActor->marker->unk14_21 = 0;
        return thisActor;
    }

    modelRender_preDraw((GenFunction_1) actor_predrawMethod, (s32)thisActor);
    modelRender_postDraw((GenFunction_1) actor_postdrawMethod, (s32)this);
    actor_position[0] = thisActor->position_x;
    actor_position[1] = thisActor->position_y + local->animTimer * 75.0f;
    actor_position[2] = thisActor->position_z;
    actor_rotation[0] = thisActor->pitch;
    actor_rotation[1] = thisActor->yaw;
    actor_rotation[2] = thisActor->roll;
    if(local->isGrumblie && local->game_marker){
        modelRender_draw(gfx, mtx, actor_position, actor_rotation, 1.0f, NULL, chMrVileMinigame_getGrumblieModel(local->game_marker));
    }
    else{
        modelRender_draw(gfx, mtx, actor_position, actor_rotation, 1.0f, NULL, marker_loadModelBin(this));
    }
    return thisActor;
}

bool func_8038B684(ActorMarker * arg0){
    Actor* actPtr = marker_getActor(arg0);

    if( actPtr->state < YUMBLIE_STATE_5_BEING_EATEN){
        chYumblie_setState(actPtr, YUMBLIE_STATE_5_BEING_EATEN);
        return TRUE;
    }

    return FALSE;
}

void chYumblie_update(Actor *this){
    ActorLocal_Yumblie *local;
    f32 anim_progress;
    f32 time_delta;
    f32 sp48;
    s32 pad44;
    f32 former_timer;

    local = (ActorLocal_Yumblie *)&this->local;
    time_delta = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->animTimer = 0.0f;
        local->isGrumblie = 0;
        local->game_marker = NULL;
        chYumblie_setState(this, YUMBLIE_STATE_1_UNDER_GROUND);
        return;
    }

    if(local->game_marker == NULL){
        local->game_marker = actorArray_findClosestActorFromActorId(this->position, ACTOR_138_VILE_GAME_CTRL, -1, &sp48)->marker;
    }
    anim_progress = skeletalAnim_getProgress(this->unk148);
    if(this->state == YUMBLIE_STATE_1_UNDER_GROUND){
        if(ml_timer_update(&local->waitTimer, time_delta)){
            if(mapSpecificFlags_get(BGS_SPECIFIC_FLAG_6_MR_VILE)
                && (12 > chMrVileMinigame_getPieceCount(local->game_marker)))
            {
                chYumblie_setState(this, YUMBLIE_STATE_2_APPEAR);
            }
            else{
                chYumblie_setState(this, YUMBLIE_STATE_1_UNDER_GROUND);
            }
        }
    }
    if(this->state == YUMBLIE_STATE_2_APPEAR){
        former_timer = local->animTimer;
        if(local->isGrumblie){
            if(anim_progress <= 0.3){
                local->animTimer = anim_progress / 0.3;
            }
        }else{
            if(anim_progress <= 0.6){
                local->animTimer = anim_progress / 0.6;
            }
        }

        if((former_timer < 0.5) && (0.5 <= local->animTimer)){
            func_8030E878(SFX_C5_TWINKLY_POP, randf2(1.0f, 1.2f), 30000, this->position, 500.0f, 3000.0f);
        }

        if( 0 < skeletalAnim_getLoopCount(this->unk148)){
            local->animTimer = 1.0f;
            chYumblie_setState(this, YUMBLIE_STATE_3_ABOVE_GROUND);
        }

    }
    if(this->state == YUMBLIE_STATE_3_ABOVE_GROUND){
        if( ml_timer_update(&local->waitTimer, time_delta) || !mapSpecificFlags_get(BGS_SPECIFIC_FLAG_6_MR_VILE) ){
            chYumblie_setState(this, YUMBLIE_STATE_4_DISAPPEAR);
        }
    }

    if(this->state == YUMBLIE_STATE_4_DISAPPEAR){
        if(anim_progress >= 0.25)
            local->animTimer -= 2.0f * (f64)time_delta;
        
        if(0.0f >= local->animTimer){
            local->animTimer = 0.0f;
            chYumblie_setState(this, YUMBLIE_STATE_1_UNDER_GROUND);
        }   
    }

    if(this->state == YUMBLIE_STATE_5_BEING_EATEN){
        if( ml_timer_update(&local->waitTimer, time_delta)){
            chYumblie_setState(this, YUMBLIE_STATE_1_UNDER_GROUND);
        }
    }
}
