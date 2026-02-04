#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
    u8  unk30;
} ActorLocal_Wozza;

Actor *chWozza_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chWozza_update(Actor *this);

/* .data */
ActorAnimationInfo chWozzaAnimations[] ={
    {0x000, 0.0f},
    {0x1AC, 3.8f},
    {0x1AC, 3.8f},
    {0x1AE, 0.55f},
    {0x1AE, 0.55f},
    {0x1B3, 0.6f},
    {0x1B4, 0.8f},
    {0x1AE, 0.55f},
    {0x1AD, 4.4f},
    {0x1B5, 1.2f},
    {0x221, 5.0f},
    {0x1AE, 0.55f},
    {0x1AE, 0.55f}
};

ActorInfo gChWozza = { MARKER_20B_WOZZA, ACTOR_1F3_WOZZA, ASSET_494_MODEL_WOZZA, 
    0x1, chWozzaAnimations,
    chWozza_update, actor_update_func_80326224, chWozza_draw,
    0, 0, 1.6f, 0
};

f32 D_803925AC[3] = {-4026.0f, 800.0f, -4097.0f};

/* .code */
Actor *chWozza_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(maSlalom_isActive() || this->unk38_31)
        return this;
    
    return actor_draw(marker, gfx, mtx, vtx);
}

void chWozza_caveEntranceCollision(void){
    Struct70s *v0 = func_8034C528(0x191);
    if(v0 != NULL){
        subaddie_positionMoveVertical(&v0->type_6D, 0.0f, -500.0f, 0.2f, 1);
    }
}

void chWozza_retreatToCave(Actor *this){
    subaddie_set_state_with_direction(this, 3, 0.02f, 1);
    actor_loopAnimation(this);
}

void chWozza_enterCaveFinal(Actor *this){
    subaddie_set_state_with_direction(this, 11, 0.02f, 1);
    actor_loopAnimation(this);
    chWozza_caveEntranceCollision();
}

void chWozza_textCallback(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    switch(text_id){
        case ASSET_C1B_DIALOG_WOZZA_MEET_AS_BEAR:
            timed_exitStaticCamera(0.0f);
            break;

        case ASSET_C1C_DIALOG_WOZZA_MEET_AS_WALRUS:
            timed_exitStaticCamera(0.0f);
            chWozza_enterCaveFinal(this);
            break;
    }
}

void chWozza_setCompletion(void){
    mapSpecificFlags_set(FP_SPECIFIC_FLAG_8_WOZZA_MET_WALRUS, 1);
}

void chWozza_checkCompletion(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    if(arg2 == 1){
        chWozza_setCompletion();
    }
}

void chWozza_delayedRetreatToCave(ActorMarker *marker){
    Actor *actor  = marker_getActor(marker);
    chWozza_retreatToCave(actor);
}

void chWozza_returnFromCave(Actor *this){
    subaddie_set_state_with_direction(this, 1, 0.02f, 1);
    actor_loopAnimation(this);
}

void chWozza_firstContact(Actor *this){
    if(!mapSpecificFlags_get(FP_SPECIFIC_FLAG_7_WOZZA_FIRST_CONTACT) && player_movementGroup() != BSGROUP_A_FLYING && subaddie_playerIsWithinSphereAndActive(this, 1000) ){
        mapSpecificFlags_set(FP_SPECIFIC_FLAG_7_WOZZA_FIRST_CONTACT, TRUE);
        subaddie_set_state(this, 2);
        actor_loopAnimation(this);
        timed_setStaticCameraToNode(0.0f, 0x2e);
        func_80324DBC(0.0f, ASSET_C1B_DIALOG_WOZZA_MEET_AS_BEAR, 0x2a, this->position, this->marker, chWozza_textCallback, NULL);
        timedFunc_set_1(2.5f, (GenFunction_1)chWozza_delayedRetreatToCave, (s32)this->marker);
    }
    else{
        chWozza_retreatToCave(this);
    }
}

void chWozza_retreatToCaveMovement(Actor *this){
    subaddie_set_state_with_direction(this, 4, 0.02f, 1);
    actor_loopAnimation(this);
}

void chWozza_checkForPlayer(Actor *this){
    subaddie_set_state_with_direction(this, 7, 0.02f, 1);
    actor_loopAnimation(this);
}

void chWozza_facePlayer(Actor *this, f32 arg1){
    this->yaw_ideal = subaddie_getYawToPlayer(this);
    subaddie_turnToYaw(this, arg1);
}

bool chWozza_retreatToCaveAnimation(Actor *this, f32 arg1[3], f32 arg2, f32 arg3, s32 arg4){
    f32 sp24;

    sp24 = anctrl_getAnimTimer(this->anctrl);
    this->yaw_ideal = (f32) subaddie_getYawToPosition(this, arg1);
    subaddie_turnToYaw(this, arg3);
    if(actor_animationIsAt(this, 0.9f)){
        sfx_playFadeShorthandDefault(SFX_3F2_BOING, 0.8f, 24000, this->position, 500, 2000);
    }
    this->actor_specific_1_f = (1.0f- sp24)*arg2;
    func_80329054(this, 2);
    if(ml_vec3f_distance(this->position, arg1) <= arg4)
        return TRUE;
    return FALSE;

}

bool chWozza_rotate(Actor *this, f32 arg1[3], f32 arg2){
    s32 dTheta;

    subaddie_set_ideal_yaw(this, subaddie_getYawToPosition(this, arg1));
    subaddie_turnToYaw(this, arg2);
    dTheta = this->yaw - this->yaw_ideal;
    if(-arg2 <= dTheta && dTheta <= arg2){
        return TRUE;
    }
    return FALSE;
}

void chWozza_spawnJiggy(ActorMarker *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    Actor *jiggy = spawn_child_actor(ACTOR_1F4_WOZZAS_JIGGY, &this);
    s32 pad;
    
    jiggy->yaw = this->yaw;
    this->partnerActor = jiggy->marker;
    jiggy->partnerActor = this->marker;
}

void chWozza_update(Actor *this){
    ActorLocal_Wozza * local = (ActorLocal_Wozza *)&this->local;

    if(volatileFlag_get(VOLATILE_FLAG_C4_WOZZA_HIDE_IN_SNS_PARADE)){
        if(!this->volatile_initialized){
            this->volatile_initialized = TRUE;
            this->marker->propPtr->unk8_3 = FALSE;
            actor_collisionOff(this);
            this->unk58_0 = FALSE;
            chWozza_caveEntranceCollision();
        }
        return;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        if(jiggyscore_isCollected(JIGGY_32_FP_WOZZA)){
            chWozza_caveEntranceCollision();
            marker_despawn(this->marker);
            return;
        }

        if (levelSpecificFlags_get(LEVEL_FLAG_26_FP_WALRUS_JIGGY_DROPPED)) {
            this->unk38_31 = TRUE;
            chWozza_caveEntranceCollision();
        }
        else{//L8038F8A0
            nodeProp_findPositionFromActorId(0x359, local->unk24);
            nodeProp_findPositionFromActorId(0x35A, local->unk0);
            nodeProp_findPositionFromActorId(0x35B, local->unkC);
            nodeProp_findPositionFromActorId(0x35C, local->unk18);
            this->position[0] = local->unkC[0];\
            this->position[1] = local->unkC[1];\
            this->position[2] = local->unkC[2];
            __spawnQueue_add_1((GenFunction_1)chWozza_spawnJiggy, reinterpret_cast(s32, this->marker));
            local->unk30 = FALSE;
        }
    }//L8038F910

    if(maSlalom_isActive() || this->unk38_31 || !subaddie_playerIsWithinSphere(this, 3000)){
        actor_collisionOff(this);
        return;
    }

    actor_collisionOn(this);
    switch(this->state){
        case 1: //L8038F984
            if(player_movementGroup() == BSGROUP_A_FLYING){
                chWozza_firstContact(this);
                break;
            }
            
            if(subaddie_playerIsWithinSphereAndActive(this, 1300) && player_getTransformation() == TRANSFORM_4_WALRUS){
                subaddie_set_state_with_direction(this, 8, 0.02f, 1);
                actor_loopAnimation(this);
                break;
            }

            if(subaddie_playerIsWithinSphereAndActive(this, 1000) && !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)){
                chWozza_firstContact(this);
                break;
            }

            chWozza_facePlayer(this, 1.0f);
            if( actor_animationIsAt(this, 0.38f) || actor_animationIsAt(this, 0.7f)){
                if(randf() < 0.4)
                    anctrl_setDirection(this->anctrl, anctrl_isPlayedForwards(this->anctrl) ^ 1);
            }
            break;

        case 3: //L8038FA9C
            if(chWozza_retreatToCaveAnimation(this, local->unk24, 30.0f, 12.0f, 0x3C))
                chWozza_retreatToCaveMovement(this);
            break;

        case 4: //L8038FAD0
            if(!subaddie_playerIsWithinSphereAndActive(this, 2000) && player_movementGroup() != BSGROUP_A_FLYING){
                chWozza_checkForPlayer(this);
                break;
            }

            if(chWozza_retreatToCaveAnimation(this, local->unk0, 30.0f, 12.0f, 0x3C)){
                subaddie_set_state_with_direction(this, 5, 0.02f, 1);
                actor_playAnimationOnce(this);
            }
            break;

        case 5: //L8038FB50
            chWozza_rotate(this, local->unk18, 1.0f);
            if(0.97 < anctrl_getAnimTimer(this->anctrl)){
                subaddie_set_state_with_direction(this, 6, 0.02f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 6: //L8038FBA8
            chWozza_rotate(this, local->unk18, 1.0f);
            if( subaddie_playerIsWithinSphereAndActive(this, 1700) ) break;
            if( player_movementGroup() == BSGROUP_A_FLYING )    break;
            
            chWozza_checkForPlayer(this);

            if(!local->unk30){
                if(gcdialog_showDialog(ASSET_C1D_DIALOG_WOZZA_RETURN, 0x20, NULL, NULL, NULL, NULL)){
                    local->unk30 =  TRUE;
                }
            }
            break;

        case 7: //L8038FC30
            if(!chWozza_rotate(this, local->unkC, 4.5f)) 
                break;

            if(subaddie_playerIsWithinSphereAndActive(this, 1000) || player_movementGroup() == BSGROUP_A_FLYING){
                chWozza_retreatToCaveMovement(this);
                break;
            }

            if(chWozza_retreatToCaveAnimation(this, local->unkC, 30.0f, 12.0f, 0x3C)){
                chWozza_returnFromCave(this);
            }
            break;

        case 8: //L8038FCB0
            if(player_getTransformation() != TRANSFORM_4_WALRUS){
                chWozza_returnFromCave(this);
                break;
            }

            if(subaddie_playerIsWithinSphereAndActive(this, 500) && !this->has_met_before){
                if(gcdialog_showDialog(ASSET_C1C_DIALOG_WOZZA_MEET_AS_WALRUS, 0xAA, this->position, this->marker, chWozza_textCallback, chWozza_checkCompletion)){
                    timed_setStaticCameraToNode(0.0f, 0x2E);
                    this->has_met_before = TRUE;
                }
                break;
            }//L8038FD40

            if(mapSpecificFlags_get(FP_SPECIFIC_FLAG_8_WOZZA_MET_WALRUS)){
                if(chWozza_rotate(this, D_803925AC, 9.0f)){
                    subaddie_set_state_with_direction(this, 9, 0.02f, 1);
                    actor_playAnimationOnce(this);
                }
                break;
            }

            chWozza_facePlayer(this, 2.0f);

            if(!gcdialog_hasCurrentTextId()){
                if( actor_animationIsAt(this, 0.02f)
                    || actor_animationIsAt(this, 0.14f)
                    || actor_animationIsAt(this, 0.28f)
                    || actor_animationIsAt(this, 0.42f)
                ){
                    sfx_playFadeShorthandDefault(SFX_88_WOZZA_NOISE, 1.0f, 32000, this->position, 500, 2000);
                }
            }
            break;

        case 9: //L8038FE14
            chWozza_rotate(this, D_803925AC, 9.0f);
            if(0.97 < anctrl_getAnimTimer(this->anctrl)){
                subaddie_set_state_with_direction(this, 10, 0.02f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 10: //L8038FE70
            chWozza_facePlayer(this, 9.0f);
            break;

        case 11: //L8038FE84
            if(chWozza_retreatToCaveAnimation(this, local->unk24, 30.0f, 12.0f, 0x3C)){
                subaddie_set_state(this, 12);
            }
            break;

        case 12: //L8038FEB8
            if(chWozza_retreatToCaveAnimation(this, local->unk18, 30.0f, 12.0f, 0x3C)){
                this->unk38_31 = TRUE;
            }
            break;
    }//L8038FEEC
}
