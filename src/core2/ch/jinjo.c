#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void subaddie_set_state_with_direction(Actor *, s32, f32 , s32);
extern f32 func_80309B24(f32*);
extern void func_80329904(ActorMarker*, s32, f32*);
extern void func_8032BB88(Actor *, s32, s32);

void chJinjo_update(Actor *this);

/* .data */
ActorAnimationInfo chJinjoAnimations[] = {
    {0, 0.0f},
    {ASSET_2D_ANIM_JINJO_IDLE, 1000000.0f},
    {ASSET_2D_ANIM_JINJO_IDLE, 1.5f},
    {ASSET_2F_ANIM_JINJO_HELP, 1.5f},
    {ASSET_31_ANIM_JINJO_JUMP, 0.75f},
    {ASSET_2D_ANIM_JINJO_IDLE, 1000000.0f},
    {ASSET_31_ANIM_JINJO_JUMP, 0.4f},
    {ASSET_130_ANIM_JINJO_FLY_START, 1.75f},
    {ASSET_131_ANIM_JINJO_FLY_END, 2.13333f},
    {ASSET_31_ANIM_JINJO_JUMP, 0.75f}
};

ActorInfo chJinjoBlue   = { MARKER_5A_JINJO_BLUE,   ACTOR_60_JINJO_BLUE,   ASSET_3C0_MODEL_JINJO_BLUE,   0x1, chJinjoAnimations, chJinjo_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoGreen  = { MARKER_5B_JINJO_GREEN,  ACTOR_62_JINJO_GREEN,  ASSET_3C2_MODEL_JINJO_GREEN,  0x1, chJinjoAnimations, chJinjo_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoYellow = { MARKER_5E_JINJO_YELLOW, ACTOR_5E_JINJO_YELLOW, ASSET_3BB_MODEL_JINJO_YELLOW, 0x1, chJinjoAnimations, chJinjo_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoPink   = { MARKER_5D_JINJO_PINK,   ACTOR_61_JINJO_PINK,   ASSET_3C1_MODEL_JINJO_PINK,   0x1, chJinjoAnimations, chJinjo_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoOrange = { MARKER_5C_JINJO_ORANGE, ACTOR_5F_JINJO_ORANGE, ASSET_3BC_MODEL_JINJO_ORANGE, 0x1, chJinjoAnimations, chJinjo_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};

enum chjinjo_state_e {
    CH_JINJO_STATE_0_NOT_INIT,
    CH_JINJO_STATE_1_IDLE,
    CH_JINJO_STATE_2_ONE_HAND_WAVE,
    CH_JINJO_STATE_3_TWO_HAND_WAVE,
    CH_JINJO_STATE_4_JUMPING_WAVE,
    CH_JINJO_STATE_5_UNK,
    CH_JINJO_STATE_6_COLLECTED,
    CH_JINJO_STATE_7_FLY_START,
    CH_JINJO_STATE_8_FLY_END,
    CH_JINJO_STATE_9_UNK
};

/*.code */
enum asset_e __chJinjo_getMeetDialogId(enum marker_e marker_id){
    switch(marker_id){
        case MARKER_5A_JINJO_BLUE:   return VER_SELECT(ASSET_D98_DIALOG_JINJO_MEET_BLUE, 0x0A16, 0, 0);
        case MARKER_5B_JINJO_GREEN:  return VER_SELECT(ASSET_D99_DIALOG_JINJO_MEET_GREEN, 0x0A17, 0, 0);
        case MARKER_5C_JINJO_ORANGE: return VER_SELECT(ASSET_D9B_DIALOG_JINJO_MEET_ORANGE, 0x0A19, 0, 0);
        case MARKER_5D_JINJO_PINK:   return VER_SELECT(ASSET_D9A_DIALOG_JINJO_MEET_PINK, 0x0A18, 0, 0);
        case MARKER_5E_JINJO_YELLOW: return VER_SELECT(ASSET_D97_DIALOG_JINJO_MEET_YELLOW, 0x0A15, 0, 0);
    }
    return 0;
}

void __chJinjo_collected(ActorMarker *this, ActorMarker *other){
    Actor *actorPtr = marker_getActor(this);
    ActorLocal_Jinjo *localPtr = &actorPtr->jinjo;

    if(actorPtr->state < CH_JINJO_STATE_5_UNK){
        if(!fileProgressFlag_get(FILEPROG_E_JINJO_TEXT)){
            gcdialog_showDialog(__chJinjo_getMeetDialogId(actorPtr->marker->id), 4, 0, 0, 0, 0);
            fileProgressFlag_set(FILEPROG_E_JINJO_TEXT, 1);
        }
        subaddie_set_state_with_direction(actorPtr, CH_JINJO_STATE_6_COLLECTED, 0.0f , -1);
        /*
        If multiple Jinjos of a color are collected, it overflows into the next Jinjo.
        Example, two Green Jinjos -> Orange Jinjo collected & no Green Jinjo collected
        */
        if(item_adjustByDiffWithHud(ITEM_12_JINJOS, 1 << (this->id + 6) ) == 0x1f)
            localPtr->unk4 = 1;
        actor_loopAnimation(actorPtr);
        this->collidable = FALSE;
    }
}

void __chJinjo_802CDC9C(Actor *this, s16 arg1){
    f32 tmpf; 

    tmpf = this->yaw;
    tmpf -= time_getDelta() * arg1 / 45.0;
    
    if(tmpf >= 360.0f)
        tmpf -= 360.0f;
    else if (tmpf < 0.0f)
        tmpf += 360.0f;

    this->yaw = tmpf;
}

void __chJinjo_free(Actor * this){
    ActorLocal_Jinjo *localPtr = &this->jinjo;
    if(localPtr->unkC != 0){
        func_802F9D38(localPtr->unkC);
        localPtr->unkC = 0;
    }
}

void chJinjo_update(Actor * this){
    f32 sp7C[3];
    f32 player_velocity[3];
    f32 sp6C;
    f32 sp68; //unused??
    s16 sp66;
    s16 sp64;
    s32 is_within_jinjos_vision;
    // f32 sp5C;
    ActorLocal_Jinjo *local; //= &this->jinjo; //sp34
    f32 time_delta = time_getDelta();
    s32 i;
    int is_flying_start;
    f32 *this_position;
    
    //f32 sp4C; //unused
    f32 jiggy_position[3];
    //s32 sp3C;
    //s32 sp38;
    
    f32 tmp_f0;
    
    
    local = &this->jinjo;
    if(!this->initialized){
        this->initialized = TRUE;
        local->unk0 = 1;
        local->unk4 = 0;
        local->unk8 = (this->position_y < func_80309B24(this->position));
        this->marker->collisionFunc = __chJinjo_collected;
        marker_setFreeMethod(this->marker, __chJinjo_free);
        if(volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){
            marker_despawn(this->marker);
        }
    }//L802CDE24
    this_position = this->position;
    func_8028E964(sp7C);
    func_80257F18(this_position, sp7C, &sp6C);
    sp64 = (this->yaw * 182.04444);
    // sp66 = sp64 - (s32)(sp6C*182.04444);
    sp66 = (s32) (sp6C * 182.04444);
    sp66 = sp64 - sp66;
    is_within_jinjos_vision = func_8028AED4(this_position, 55.0f);

    switch(this->state){
        case CH_JINJO_STATE_1_IDLE:
            if(randf() < 0.015){
                if(is_within_jinjos_vision){
                    subaddie_set_state_with_direction(this, CH_JINJO_STATE_3_TWO_HAND_WAVE, 0.0f, -1);
                }else{
                    subaddie_set_state_with_direction(this, CH_JINJO_STATE_2_ONE_HAND_WAVE, 0.0f, -1);
                }
                actor_playAnimationOnce(this);
            }//L802CDF24
            break;

        case CH_JINJO_STATE_2_ONE_HAND_WAVE: /* 46FA0 802CDF30 3C053F7D */
        case CH_JINJO_STATE_3_TWO_HAND_WAVE:
            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, CH_JINJO_STATE_1_IDLE, 0.0f, -1);
            }
            break;
        
        case CH_JINJO_STATE_4_JUMPING_WAVE: /* 46FD8 802CDF68 3C053F7D */
            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, CH_JINJO_STATE_1_IDLE, 0.0f, -1);
            }else{//L802CDF9C
                tmp_f0 = this->yaw;
                if(sp66 >= 0){
                    tmp_f0 -= 80.0f * time_delta;
                }
                else{//L802CDFBC
                    tmp_f0 += 80.0f * time_delta;
                }//L802CDFD0
                if(tmp_f0 >= 360.0f)
                    tmp_f0 -= 360.0f;
                else if(tmp_f0 < 0.0f)
                    tmp_f0 += 360.0f;

                this->yaw = tmp_f0;
            }//L802CE018
            break;
        case CH_JINJO_STATE_6_COLLECTED:/* 47094 802CE024 02002025 */
            __chJinjo_802CDC9C(this, sp66);
            if(actor_animationIsAt(this, 0.0f) && --(local->unk0) == 0){
                subaddie_set_state_with_direction(this, CH_JINJO_STATE_7_FLY_START, 0.0f, -1);
                actor_playAnimationOnce(this);
                if(local->unk4){
                    jiggy_position[0] = this->position_x;
                    jiggy_position[1] = this->position_y;
                    jiggy_position[2] = this->position_z;
                    jiggy_position[1] += 50.0f;
                    jiggy_spawn(10 * level_get() - 9, jiggy_position);
                }//L802CE0CC
                core1_ce60_incOrDecCounter(FALSE);
                func_8032BB88(this, 0, 4000);
                if(local->unk4){
                    coMusicPlayer_playMusic(COMUSIC_30_5TH_JINJO_COLLECTED, 28000);
                }else{
                    coMusicPlayer_playMusic(COMUSIC_A_JINJO_COLLECTED, 28000);
                }
            }//L802CE114
            break;

        case CH_JINJO_STATE_7_FLY_START:
        case CH_JINJO_STATE_8_FLY_END:
            is_flying_start = this->state == CH_JINJO_STATE_7_FLY_START;
            if(!is_flying_start || 0.1 < anctrl_getAnimTimer(this->anctrl)){//L802CE158
                player_getVelocity(player_velocity);
                player_velocity[0] *= time_delta * 6.0f;\
                player_velocity[1] *= time_delta * 6.0f;\
                player_velocity[2] *= time_delta * 6.0f;
                player_velocity[0] = player_velocity[0] + sp7C[0];\
                player_velocity[1] = player_velocity[1] + sp7C[1];\
                player_velocity[2] = player_velocity[2] + sp7C[2];
                player_velocity[0] -=  this->position_x;\
                player_velocity[1] -=  this->position_y;\
                player_velocity[2] -=  this->position_z;
                player_velocity[0] *= time_delta * 3.0f;
                player_velocity[1] *= time_delta * 3.0f;
                player_velocity[2] *= time_delta * 3.0f;
                this->position_x = this->position_x + player_velocity[0];
                this->position_y = this->position_y + player_velocity[1];
                this->position_z = this->position_z + player_velocity[2];
                if(is_flying_start || anctrl_getAnimTimer(this->anctrl) < 0.8){
                    for(i = 0; i < 4; i++){
                        if(randf() < 0.3){
                            commonParticle_add(this->marker, i + 5, func_80329904);
                            commonParticle_new(8, this->marker->unk14_21);
                        } //L802CE2C4
                    }
                }//L802CE2D0
            }

            if(is_flying_start){ 
                if(anctrl_getAnimTimer(this->anctrl) < 0.2)
                    __chJinjo_802CDC9C(this, sp66);

                if(actor_animationIsAt(this, 0.1f)){
                    local->unkC = func_802F9AA8(SFX_18_BIGBUTT_SLIDE);
                    func_802F9EC4(local->unkC, this_position, 500, 2000);
                    func_802F9F80(local->unkC, 0.0f, 9e+09, 0.0f);
                    func_802FA0B0(local->unkC, 0);
                    coMusicPlayer_playMusic(COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7FFF);
                    func_8025AABC(COMUSIC_43_ENTER_LEVEL_GLITTER);
                    func_8030E9C4(SFX_C7_SHWOOP, 0.8f, 0x7FFF, this_position, 300.0f, 2000.0f);
                }//L802CE3C4

                if(actor_animationIsAt(this, 0.434f)){
                    func_8030E9C4(SFX_C7_SHWOOP, 0.9f, 0x7fff, this_position, 300.0f, 2000.0f);
                }//L802CE408
                
                if(actor_animationIsAt(this, 0.811f)){
                    func_8030E9C4(SFX_C7_SHWOOP, 1.0f, 0x7fff, this_position, 300.0f, 2000.0f);
                }

            }else{//L802CE450
                if(actor_animationIsAt(this, 0.214f)){
                    func_8030E9C4(SFX_C7_SHWOOP, 1.1f, 0x7fff, this_position, 300.0f, 2000.0f);
                }//L802CE490

                if(actor_animationIsAt(this, 0.55f)){
                    func_8030E9C4(SFX_53_BANJO_HUIII, 1.5f, 0x7fff, this_position, 300.0f, 2000.0f);
                }//L802CE4D0

                if(actor_animationIsAt(this, 0.75f)){ 
                    func_80326310(this);
                    if(local->unk4 == 0){
                        func_8032BB88(this, -1, 4000);
                        core1_ce60_incOrDecCounter(TRUE);
                    }
                }//L802CE518

                if(actor_animationIsAt(this, 0.85f)){ 
                    if(local->unkC){
                        func_802F9D38(local->unkC);
                        local->unkC = 0;
                    }
                    func_8030E4E4(SFX_19_BANJO_LANDING_08);
                    func_8025A7DC(COMUSIC_43_ENTER_LEVEL_GLITTER);
                }//L802CE558

                if(local->unk4 && actor_animationIsAt(this, 0.95f)){
                    func_8032BB88(this, -1, 4000);
                    core1_ce60_incOrDecCounter(TRUE);
                }
            }//L802CE598

            if(is_flying_start){
                if(actor_animationIsAt(this, 0.96f) || actor_animationIsAt(this, 0.99f)){
                    subaddie_set_state_with_direction(this, CH_JINJO_STATE_8_FLY_END, 0.0f, -1);
                    actor_playAnimationOnce(this);
                }
            }
            break;
    }//L802CE5F0
    if(this->state < CH_JINJO_STATE_4_JUMPING_WAVE
        && !(((sp66 >= 0)? sp66: -sp66) <= 0x1000))
    {
        subaddie_set_state_with_direction(this, CH_JINJO_STATE_4_JUMPING_WAVE, 0.0f, -1);
        actor_playAnimationOnce(this);
    }//L802CE630

    if(!gcdialog_hasCurrentTextId()){
        switch(chJinjoAnimations[this->state].index){
            case ASSET_31_ANIM_JINJO_JUMP: 
                if(actor_animationIsAt(this, 0.6f)){
                    if(local->unk8){
                        func_8030E988(SFX_8_BANJO_LANDING_04, 1.8f, 18000, this_position, 120.0f, 1200.0f);
                    }else{
                        sfx_playFadeShorthandDefault(SFX_8_BANJO_LANDING_04, 1.8f, 18000, this_position, 120, 1200);
                    }
                }
                break;
            case ASSET_2D_ANIM_JINJO_IDLE: //L802CE6F4
                if(actor_animationIsAt(this, 0.2f)){
                    if(local->unk8){
                        func_8030E988(SFX_17_JINJO_WHISTLE, 1.0f, 22000, this_position, 120.0f, 1200.0f);
                    }else{
                        sfx_playFadeShorthandDefault(SFX_17_JINJO_WHISTLE, 1.0f, 22000, this_position, 120, 1200);
                    }
                }
                break;
            case ASSET_2F_ANIM_JINJO_HELP: //L802CE760
                if(actor_animationIsAt(this, 0.2f)){
                    if(local->unk8){
                        func_8030E988(SFX_27_JINJO_HI, 1.0f, 22000, this_position, 120.0f, 1200.0f);
                    }else{
                        sfx_playFadeShorthandDefault(SFX_27_JINJO_HI, 1.0f, 22000, this_position, 120, 1200);
                    }
                }
                break;
            default: //L802CE7C8
                break;
        }
    }//L802CE7CC
}
