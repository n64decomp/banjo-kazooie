#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorProp *func_80320EB0(ActorMarker *, f32, s32);

Actor *chTwinklyMuncher_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chTwinklyMuncher_update(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392390[] ={
    {0, 0.0f},
    {ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR, 10000000.0f},
    {ASSET_1B0_ANIM_TWINKLY_MUNCHER_DIE,    1.0f},
    {ASSET_1B1_ANIM_TWINKLY_MUNCHER_IDLE,   1.0f},
    {ASSET_1B2_ANIM_TWINKLY_MUNCHER_ATTACK, 1.0f},
    {ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR, 0.667f},
    {ASSET_1B1_ANIM_TWINKLY_MUNCHER_IDLE,   1.0f},
    {ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR, 0.667f}
};

extern ActorInfo gChTwinklyMuncher = { MARKER_205_TWINKLY_MUNCHER, ACTOR_337_TWINKLY_MUNCHER, ASSET_496_MODEL_TWINKLY_MUNCHER, 
    0x1, D_80392390,
    chTwinklyMuncher_update, actor_update_func_80326224, chTwinklyMuncher_draw,
    2500, 0, 1.0f, 0
};

/* .code */
Actor *chTwinklyMuncher_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->state == 1)
        return this;
    return actor_draw(marker, gfx, mtx, vtx);
}

void chTwinklyMuncher_setSpawnState(Actor *this){
    actor_collisionOn(this);
    subaddie_set_state_with_direction(this, 2, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void chTwinklyMuncher_setPostFirstAttackState(Actor *this){
    subaddie_set_state_with_direction(this, 3, 0.03f, 1);
    actor_loopAnimation(this);
}

void chTwinklyMuncher_setFirstAttackState(Actor *this){
    subaddie_set_state_with_direction(this, 4, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void chTwinklyMuncher_setDespawnState(Actor *this){
    actor_collisionOff(this);
    subaddie_set_state_with_direction(this, 5, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void chTwinklyMuncher_hit(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if(this->state != 1 && this->state != 5){
        chTwinklyMuncher_setDespawnState(this);
        sfx_playFadeShorthandDefault(SFX_87_TANKTUP_OOOHW, 1.6f, 32000, this->position, 1250, 2500);
        sfx_playFadeShorthandDefault(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 26000, this->position, 1250, 2500);
    }
}

Actor *func_8038DF34(Actor *this){
    ActorProp *prop;
    Actor *other;
    s32 marker_id;
    f32 sp18[3];

    func_8034A174(this->marker->unk44, 5, sp18);
    this->marker->unk38[0] = sp18[0] - this->position[0];
    this->marker->unk38[1] = sp18[1] - this->position[1];
    this->marker->unk38[2] = sp18[2] - this->position[2];
    prop = func_80320EB0(this->marker, 75.0f, 1);

    if(prop && prop->is_actor){
        other = marker_getActor(prop->marker);
        marker_id = other->marker->id;
        if( marker_id == MARKER_200_TWINKLY_BLUE
            || marker_id == MARKER_201_TWINKLY_GREEN 
            || marker_id == MARKER_202_TWINKLY_ORANGE
            || marker_id == MARKER_203_TWINKLY_RED
        ){
            return other;
        }
    }
    return NULL;
}

void chTwinklyMuncher_failMinigameExit(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    timed_exitStaticCamera(0.5f);
    subaddie_set_state_with_direction(this, 7, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void chTwinklyMuncher_update(Actor *this){
    s32 sp3C;
    Actor *sp38;
    f32 sp34 = time_getDelta();

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chTwinklyMuncher_hit, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        anctrl_setAnimTimer(this->anctrl, 0.99999f);
        this->lifetime_value = 0.0f;
        if(this->actorTypeSpecificField == 1){
            chTwinklyMuncher_setSpawnState(this);
        }
        if(this->actorTypeSpecificField == 2){
            if(volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) && gcparade_8031B4F4() == -2){
                chTwinklyMuncher_setSpawnState(this);
            }
            else{
                marker_despawn(this->marker);
                return;
            }
        }
    }//L8038E180
    if(this->partnerActor){
        sp38 = marker_getActor(this->partnerActor);
        if(sp38->unk1C[1] == 1.0f){
            if(this->actorTypeSpecificField == 1 && !fileProgressFlag_get(FILEPROG_13_COMPLETED_TWINKLIES_MINIGAME)){
                if(this->state != 6 && this->state != 7 && 0.0f == this->velocity[0]){
                    timed_setStaticCameraToNode(0.5f, 0xd);
                    gcdialog_showDialog(ASSET_C15_DIALOG_TWINKLIE_MINIGAME_MISS, 0x2b, this->position, this->marker, chTwinklyMuncher_failMinigameExit, NULL);
                    this->velocity[0] = 1.0f;
                    subaddie_set_state_with_direction(this, 6, 0.03f, 1);
                    actor_loopAnimation(this);
                }
            }
            else{//L8038E274
                if(this->state == 1){
                    marker_despawn(this->marker);
                }
                else if( this->state != 1 && this->state != 5){
                    chTwinklyMuncher_setDespawnState(this);
                }
            }
        }
    }//L8038E2B4

    switch(this->state){
        case 1: //L8038E2DC
            this->marker->propPtr->unk8_3 = FALSE;
            anctrl_setAnimTimer(this->anctrl, 0.99f);
            if(this->lifetime_value < 5.0){
                this->lifetime_value += sp34;
            }
            else{
                if(10.0 <= this->lifetime_value || randf() < this->lifetime_value/10.0){
                    if(!func_8038DF34(this)){
                        this->lifetime_value = 0.0f;
                        chTwinklyMuncher_setSpawnState(this);
                        break;
                    }
                }
                this->lifetime_value += sp34;
            }
            break;

        case 2: //L8038E3C0
            this->marker->propPtr->unk8_3 = TRUE;
            sp38 = func_8038DF34(this);
            if(sp38){
                chTwinklyMuncher_setFirstAttackState(this);
                this->unk38_31 = sp38->marker->id;
                break;
            }
            
            if(actor_animationIsAt(this, 0.15f))
                sfx_playFadeShorthandDefault(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1250, 2500);

            if(actor_animationIsAt(this, 0.35f))
                sfx_playFadeShorthandDefault(SFX_C4_TWINKLY_MUNCHER_GRR, 1.2f, 32000, this->position, 1250, 2500);

            if(actor_animationIsAt(this, 0.97f))
                chTwinklyMuncher_setPostFirstAttackState(this);
            break;

        case 3: //L8038E498
            this->marker->propPtr->unk8_3 = TRUE;
            sp38 = func_8038DF34(this);
            if(sp38){
                chTwinklyMuncher_setFirstAttackState(this);
                this->unk38_31 = sp38->marker->id;
            }
            break;

        case 4: //L8038E4F0
            this->marker->propPtr->unk8_3 = TRUE;
            sp38 = func_8038DF34(this);
            if(sp38 && sp38->marker->id == this->unk38_31){
                if(actor_animationIsAt(this, 0.23)){
                    chTwinkly_decideShatterColor(sp38->position, sp38->marker->id);
                    sfx_playFadeShorthandDefault(SFX_110_TWINKLY_DEATH, 1.0f, 32000, this->position, 1250, 2500);
                    sfx_playFadeShorthandDefault(SFX_27_JINJO_HI, 1.6f, 32000, this->position, 1250, 2500);
                    func_80324D54(0.35f, SFX_110_TWINKLY_DEATH, 1.0f, 32000, this->position, 1250.0f, 2500.0f);
                    marker_despawn(sp38->marker);
                    if( !mapSpecificFlags_get(FP_SPECIFIC_FLAG_A_FIRST_TWINKLY_EATEN) && gcdialog_showDialog(ASSET_C16_DIALOG_TWINKLIE_MINIGAME_EATEN, 0, NULL, NULL, NULL, NULL)){
                        mapSpecificFlags_set(FP_SPECIFIC_FLAG_A_FIRST_TWINKLY_EATEN, TRUE);
                    }
                }
            }//L8038E620
            if(actor_animationIsAt(this, 0.97f)){
                chTwinklyMuncher_setPostFirstAttackState(this);
            }
            break;

        case 5: //L8038E644
            this->marker->propPtr->unk8_3 = TRUE;
            if(actor_animationIsAt(this, 0.97f)){
                subaddie_set_state_with_direction(this, 1, 0.97f, 0);
                actor_playAnimationOnce(this);
                this->lifetime_value = 0.0f;
            }
            break;

        case 6: //L8038E698
            this->marker->propPtr->unk8_3 = FALSE;
            this->yaw_ideal = (f32)func_80329784(this);
            func_80328FB0(this, 12.0f);
            break;

        case 7: //L8038E6D4
            this->marker->propPtr->unk8_3 = FALSE;
            if(actor_animationIsAt(this, 0.97f)){
                marker_despawn(this->marker);
            }
            break;
    }
}
