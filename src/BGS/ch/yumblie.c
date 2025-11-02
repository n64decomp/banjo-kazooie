#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
extern void actor_predrawMethod(Actor *);
extern void actor_postdrawMethod(ActorMarker *);
extern f32 randf (void);
extern BKModelBin *chvilegame_get_grumblie_model(ActorMarker *marker);

enum chyumblie_state_e{
    YUMBLIE_STATE_1_UNDER_GROUND = 1,
    YUMBLIE_STATE_2_APPEAR,
    YUMBLIE_STATE_3_ABOVE_GROUND,
    YUMBLIE_STATE_4_DISAPPEAR,
    YUMBLIE_STATE_5_BEING_EATEN
};

typedef struct chyumblie_s{
    f32 unk0;
    u8  unk4;
    u8  pad7[3];
    f32 unk8; //wait_timer
    ActorMarker *game_marker;
} ActorLocal_Yumblie;

void chYumblie_setState(Actor*, enum chyumblie_state_e);
void chYumblie_update(Actor *);
Actor *chYumblie_draw(ActorMarker *this, Gfx **gfx, Mtx** mtx, Vtx **vtx);

/* .data */
ActorInfo gChYumblie = {MARKER_C7_YUMBLIE, ACTOR_139_YUMBLIE, ASSET_3F6_MODEL_YUMBLIE, 0x00, NULL,
    chYumblie_update, NULL, chYumblie_draw,
    0, 0, 0.0f, 0
};

/* .code */
bool func_8038B160(Actor *this){
    ActorLocal_Yumblie *local;
    s32 temp_v0;

    local = (ActorLocal_Yumblie *)&this->local;
    temp_v0 = func_8038A9E0(local->game_marker);

    if ((temp_v0 == 1) || (temp_v0 == 4)) {
        return FALSE;
    }

    if ((temp_v0 == 2) || (temp_v0 == 5)) {
        return BOOL(0.7 <= randf());
    }

    return BOOL(randf() >= 0.5);
}

void chYumblie_setState(Actor* this, enum chyumblie_state_e next_state){

    ActorLocal_Yumblie *s0;
    s0 = (ActorLocal_Yumblie *)&this->local;
    s0->unk8 = 0;
    if(next_state == 1){
        s0->unk8 = randf2(1.0f, 10.0f);
    }
     
    if(next_state == 2){
        this->yaw = randf2(0.0f, 360.0f);
        s0->unk4 = func_8038B160(this);
        chvilegame_new_piece(s0->game_marker, this->marker, this->position, s0->unk4);
        skeletalAnim_set(this->unk148, (s0->unk4)? ASSET_128_ANIM_GRUMBLIE_APPEAR : ASSET_125_ANIM_YUMBLIE_APPEAR, 0.0f, 1.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if(next_state == 3){
        s0->unk8 = randf2(5.0f, 10.0f);
        skeletalAnim_set(this->unk148, (s0->unk4)? ASSET_12A_ANIM_GRUMBLIE_IDLE : ASSET_127_ANIM_YUMBLIE_IDLE, 0.1f, randf2(0.5f, 1.0f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        if(s0->unk4){
            gcsfx_playWithPitch(SFX_C4_TWINKLY_MUNCHER_GRR,randf2(1.0f, 1.2), 30000);
        }else{
            func_8030E878(SFX_C3_HEGH,randf2(1.0f, 1.2), 30000, this->position, 500.0f, 3000.0f);
        }
    }
    
    if(next_state == 4){
        chvilegame_remove_piece(s0->game_marker, this->marker);
        skeletalAnim_set(this->unk148, (s0->unk4)? ASSET_129_ANIM_GRUMBLIE_HIDE : ASSET_126_ANIM_YUMBLIE_HIDE, 0.1f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if(next_state == 5){
        s0->unk8 = randf2(10.0f, 20.0f);
        chvilegame_remove_piece(s0->game_marker, this->marker);
        func_8030E878((s0->unk4)? SFX_C4_TWINKLY_MUNCHER_GRR: SFX_C3_HEGH, 1.4f, 32000, this->position, 500.0f, 3000.0f);
    }
    this->state = next_state;
}

bool chyumblie_is_edible(ActorMarker * arg0){
    volatile Actor* actPtr;

    actPtr = marker_getActor(arg0);
    return (actPtr->state >= 2) && (actPtr->state < 5);
}

Actor *chYumblie_draw(ActorMarker *this, Gfx **gfx, Mtx** mtx, Vtx **vtx){
    Actor *thisActor;
    ActorLocal_Yumblie *sp40;
    f32 sp44[3];
    f32 sp38[3];
    
    thisActor = marker_getActor(this);
    sp40 = (ActorLocal_Yumblie *)&thisActor->local;
    if ( thisActor->state < 2 || thisActor->state > 4){
        thisActor->marker->unk14_21 = 0;
        return thisActor;
    }

    modelRender_preDraw((GenFunction_1) actor_predrawMethod, (s32)thisActor);
    modelRender_postDraw((GenFunction_1) actor_postdrawMethod, (s32)this);
    sp44[0] = thisActor->position_x;
    sp44[1] = thisActor->position_y + sp40->unk0*75.0f;
    sp44[2] = thisActor->position_z;
    sp38[0] = thisActor->pitch;
    sp38[1] = thisActor->yaw;
    sp38[2] = thisActor->roll;
    if(sp40->unk4 && sp40->game_marker){
        modelRender_draw(gfx, mtx, sp44, sp38, 1.0f, NULL, chvilegame_get_grumblie_model(sp40->game_marker));
    }
    else{
        modelRender_draw(gfx, mtx, sp44, sp38, 1.0f, NULL, marker_loadModelBin(this));
    }
    return thisActor;
}

bool func_8038B684(ActorMarker * arg0){
    Actor* actPtr = marker_getActor(arg0);

    if( actPtr->state < 5){
        chYumblie_setState(actPtr, YUMBLIE_STATE_5_BEING_EATEN);
        return TRUE;
    }

    return FALSE;
}

void chYumblie_update(Actor *this){
    ActorLocal_Yumblie *s0;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    s32 pad44;
    f32 tmp;

    s0 = (ActorLocal_Yumblie *)&this->local;
    sp4C = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        s0->unk0 = 0.0f;
        s0->unk4 = 0;
        s0->game_marker = NULL;
        chYumblie_setState(this, YUMBLIE_STATE_1_UNDER_GROUND);
        return;
    }

    if(s0->game_marker == NULL){
        s0->game_marker = actorArray_findClosestActorFromActorId(this->position, ACTOR_138_VILE_GAME_CTRL, -1, &sp48)->marker;
    }
    sp50 = skeletalAnim_getProgress(this->unk148);
    if(this->state == YUMBLIE_STATE_1_UNDER_GROUND){
        if(ml_timer_update(&s0->unk8, sp4C)){
            if(mapSpecificFlags_get(6) && (12 > chvilegame_get_piece_count(s0->game_marker))){
                chYumblie_setState(this, YUMBLIE_STATE_2_APPEAR);
            }
            else{
                chYumblie_setState(this, YUMBLIE_STATE_1_UNDER_GROUND);
            }
        }
    }
    if(this->state == YUMBLIE_STATE_2_APPEAR){
        tmp = s0->unk0;
        if(s0->unk4){
            if(sp50 <= 0.3){
                s0->unk0 = sp50/0.3;
            }
        }else{
            if(sp50 <= 0.6){
                s0->unk0 = sp50/0.6;
            }
        }

        if((tmp < 0.5) && (0.5 <= s0->unk0)){
            func_8030E878(SFX_C5_TWINKLY_POP, randf2(1.0f, 1.2f), 30000, this->position, 500.0f, 3000.0f);
        }

        if( 0 < skeletalAnim_getLoopCount(this->unk148)){
            s0->unk0 = 1.0f;
            chYumblie_setState(this,YUMBLIE_STATE_3_ABOVE_GROUND);
        }

    }
    if(this->state == YUMBLIE_STATE_3_ABOVE_GROUND){
        if( ml_timer_update(&s0->unk8,sp4C) || !mapSpecificFlags_get(6) ){
            chYumblie_setState(this,YUMBLIE_STATE_4_DISAPPEAR);
        }
    }

    if(this->state == YUMBLIE_STATE_4_DISAPPEAR){
        if(sp50 >= 0.25 )
            s0->unk0 -= 2.0f*(f64)sp4C;
        
        if(0.0f >= s0->unk0){
            s0->unk0 = 0.0f;
            chYumblie_setState(this,YUMBLIE_STATE_1_UNDER_GROUND);
        }   
    }

    if(this->state == YUMBLIE_STATE_5_BEING_EATEN){
        if( ml_timer_update(&s0->unk8,sp4C)){
            chYumblie_setState(this,YUMBLIE_STATE_1_UNDER_GROUND);
        }
    }
}
