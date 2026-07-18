#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chRubee_update(Actor *this);

/* .data */
ActorAnimationInfo chRubeeAnimations[] = {
    {0x00, 0.0f},
    {ASSET_DF_ANIM_RUBEE_PET_TOOTS, 4.5f},
    {ASSET_E3_ANIM_RUBEE_IDLE, 2.0f},
    {ASSET_E4_ANIM_RUBEE_PLAY, 1.95f},
    {ASSET_CE_ANIM_RUBEE_STOP_PLAYING, 2.4f},
    {ASSET_DF_ANIM_RUBEE_PET_TOOTS, 4.5f}
};

ActorInfo chRubee = {
    MARKER_A9_RUBEE, ACTOR_11B_RUBEE, ASSET_3DD_MODEL_RUBEE, 
    0x2, chRubeeAnimations,
    chRubee_update, actor_update_func_80326224, actor_draw,
    2500, 0, 1.6f, 0
};

enum chrubee_state_e {
    CH_RUBEE_STATE_0_NOT_INIT,
    CH_RUBEE_STATE_1_IDLE,
    CH_RUBEE_STATE_2_IDLE,
    CH_RUBEE_STATE_3_PLAYING_SONG,
    CH_RUBEE_STATE_4_UNK,
    CH_RUBEE_STATE_5_UNK
};

/* .code */
void func_80389A20(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    func_8038E18C();
    subaddie_set_state_with_direction(this, CH_RUBEE_STATE_3_PLAYING_SONG, 0.0f, 1);
}

void func_80389A60(Actor *this){
    gcdialog_showDialog(VER_SELECT(ASSET_A70_DIALOG_RUBEE_HELPED, 0x92C, 0, 0), 4, NULL, this->marker, func_80389A20, NULL);
    this->has_met_before = TRUE;
    subaddie_set_state(this, CH_RUBEE_STATE_5_UNK);
}

void func_80389ABC(Actor *this){
    if(this->unk138_23){
        func_80389A20(this->marker, VER_SELECT(ASSET_A70_DIALOG_RUBEE_HELPED, 0x92C, 0, 0), -1);
    }
    else{
        this->unk138_23 = TRUE;
        mapSpecificFlags_set(2, TRUE);
        func_80389A60(this);
    }
}

void chRubee_update(Actor *this){
    if(!this->volatile_initialized){
        this->lifetime_value = (f32) rubeeEggPot_getEggGoal();
        this->has_met_before = jiggyscore_isCollected(JIGGY_43_GV_HISTUP) || mapSpecificFlags_get(0);
        this->unk138_23 = jiggyscore_isCollected(JIGGY_43_GV_HISTUP) || mapSpecificFlags_get(2);
        this->volatile_initialized = TRUE;
    }

    if(!this->initialized){
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }

    anctrl_setTransitionDuration(this->anctrl, 0.15f);

    if(this->state == CH_RUBEE_STATE_1_IDLE
        || this->state == CH_RUBEE_STATE_2_IDLE)
    {
        if(! this->has_met_before
            && subaddie_playerIsWithinSphereAndActive(this, 250)
            && !subaddie_playerIsWithinSphereAndActive(this, 0x50))
        {
            gcdialog_showDialog(VER_SELECT(ASSET_A6F_DIALOG_RUBEE_MEET, 0x92B, 0, 0), 0xE, this->position, NULL, NULL, NULL);
            this->has_met_before = TRUE;
            mapSpecificFlags_set(0, TRUE);
        }
    }

    switch(this->state){
        case CH_RUBEE_STATE_1_IDLE://L80389CC4
            if(this->lifetime_value <= (f32)func_8038E178()){
                func_80389ABC(this);
            }
            else if(actor_animationIsAt(this, 0.99f)){
                subaddie_maybe_set_state(this, CH_RUBEE_STATE_2_IDLE, 0.9f);
            }

            if( actor_animationIsAt(this, 0.42f)
                || actor_animationIsAt(this, 0.46f)
                || actor_animationIsAt(this, 0.51f)
                || actor_animationIsAt(this, 0.57f)
            ){
                sfx_playFadeShorthandDefault(SFX_8_BANJO_LANDING_04, 3.802f, 8000, this->position, 1500, 4500);
            }

            if( actor_animationIsAt(this, 0.4f)){
                func_803865E8();
            }
            break;

        case CH_RUBEE_STATE_2_IDLE: //L80389DB0
            if(this->lifetime_value <= (f32)func_8038E178()){
                func_80389ABC(this);
            }
            else if(actor_animationIsAt(this, 0.99f)){
                subaddie_maybe_set_state(this, CH_RUBEE_STATE_1_IDLE, 0.4f);
            }
            break;
        case CH_RUBEE_STATE_3_PLAYING_SONG: //L80389E14
            if( actor_animationIsAt(this, 0.2f)){
                func_8025A58C(500, 400);
                coMusicPlayer_playMusic(COMUSIC_27_GV_RUBEES_SONG, 28000);
            }

            if( actor_animationIsAt(this, 0.99f)){
                subaddie_set_state(this, CH_RUBEE_STATE_4_UNK);
            }
            break; 
        case CH_RUBEE_STATE_4_UNK: //L80389E64
            if(!func_8038E178())
                subaddie_set_state(this, CH_RUBEE_STATE_2_IDLE);
            break; 
    }//L80389E80
}
