#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void timed_exitStaticCamera(f32);
void chTiptup_setState(Actor *this, s32 arg1);

typedef struct{
    u32 unk0;
}Struct_BGS_2270_0s;

typedef struct ch_bgs_2270_s{
    u32 unk0;
    vector(Struct_BGS_2270_0s) *unk4; // vector?
    u8  unk8;
    u8  unk9;
    u8  round;
    u8  unkB;
    f32  animTimer;
} ActorLocal_Tiptup;

void chTiptup_update(Actor *this);
Actor *actor_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);

ActorInfo gChTiptup = {
    MARKER_19A_TIPTUP, ACTOR_27A_TIPTUP, ASSET_3F8_MODEL_TIPTUP,
    0, NULL,
    chTiptup_update, NULL, actor_draw,
    0, 0, 2.5f, 0
};

s16 chTiptupRepeatDialogs[] = {
    NULL,
    ASSET_C78_DIALOG_TIPTUP_LESSON_1_REPEAT,
    ASSET_C7A_DIALOG_TIPTUP_LESSON_2_REPEAT,
    ASSET_C7C_DIALOG_TIPTUP_LESSON_3_REPEAT
};

s16 chTiptupSuccessDialogs[] = {
    NULL,
    ASSET_C77_DIALOG_TIPTUP_LESSON_1_COMPLETE,
    ASSET_C79_DIALOG_TIPTUP_LESSON_2_COMPLETE,
    ASSET_C7B_DIALOG_TIPTUP_LESSON_3_COMPLETE
};

u8  chTiptupSequenceLength[] = {3, 3, 5, 7};
f32 chTiptupJiggyPosition[3] = {0.0f, 100.0f, -1020.0f};

enum chTiptupState {
    CH_TIPTUP_STATE_1_IDLE = 1,
    CH_TIPTUP_STATE_2_INSTRUCTIONS_DIALOG,
    CH_TIPTUP_STATE_3_FF_GIVE_SEQUENCE,
    CH_TIPTUP_STATE_4_AWAIT_SEQUENCE_COMPLETION,
    CH_TIPTUP_STATE_5_WIN_MINIGAME,
    CH_TIPTUP_STATE_6_AFTER_JIGGY_DIALOG
};

enum chTiptupSpecificFlag {
    CH_TIPTUP_SPECIFIC_FLAG_0_CHOIR_MEMBER_HIT_AFTER_JIGGY,
    CH_TIPTUP_SPECIFIC_FLAG_1_TIPTUP_MISS
};

enum TiptupRound {
    TIPTUP_ROUND_1,
    TIPTUP_ROUND_2,
    TIPTUP_ROUND_3,
    TIPTUP_ROUND_FF
};

#define TIPTUP_TIMER        30 // Seconds
#define FIRST_CHOIR_MEMBER   1
#define LAST_CHOIR_MEMBER    7

void chTiptup_minigameComplete(ActorMarker *this){
    chTiptup_setState(marker_getActor(this), CH_TIPTUP_STATE_6_AFTER_JIGGY_DIALOG);
}

void chTiptup_jiggySpawn(void){
    jiggy_spawn(JIGGY_27_BGS_TIPTUP, chTiptupJiggyPosition);
}

void chTiptup_activatePattern(ActorMarker *this, s32 arg1){
    Actor *thisActor;
    ActorLocal_Tiptup *actLocalPtr;
    Struct_BGS_2270_0s *tmpPtr;

    thisActor = marker_getActor(this);
    actLocalPtr = (ActorLocal_Tiptup *)&thisActor->local;
    actLocalPtr->unkB = arg1;
    if(arg1){
        tmpPtr = vector_pushBackNew(&actLocalPtr->unk4);
        tmpPtr->unk0 = arg1;
    }
}

void chTiptup_activateTimer(ActorMarker *this){
    Actor *thisActor;
    
    thisActor = marker_getActor(this);
    item_set(ITEM_6_HOURGLASS, 1);
    item_set(ITEM_0_HOURGLASS_TIMER, TIPTUP_TIMER * 60 - 1);
    chTiptup_setState(thisActor, CH_TIPTUP_STATE_5_WIN_MINIGAME);
}

void chTiptup_sfxCorrectHit(void){
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
}

void chTiptup_sfxIncorrectHit(void){
    coMusicPlayer_playMusic(COMUSIC_2C_BUZZER, 28000);
}

void chTiptup_textEvent(ActorMarker *this, enum asset_e text_id, s32 arg2){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    switch(text_id){
        case ASSET_C72_DIALOG_TIPTUP_MEET_1:
        case ASSET_C74_DIALOG_TIPTUP_MEET_3:
            chTiptup_setState(thisActor, CH_TIPTUP_STATE_3_FF_GIVE_SEQUENCE);
            break;
        case ASSET_C78_DIALOG_TIPTUP_LESSON_1_REPEAT:
        case ASSET_C7A_DIALOG_TIPTUP_LESSON_2_REPEAT:
        case ASSET_C7C_DIALOG_TIPTUP_LESSON_3_REPEAT:
            chTiptup_setState(thisActor, CH_TIPTUP_STATE_4_AWAIT_SEQUENCE_COMPLETION);
            break;
        case ASSET_C77_DIALOG_TIPTUP_LESSON_1_COMPLETE:
        case ASSET_C79_DIALOG_TIPTUP_LESSON_2_COMPLETE:
            func_80324E38(0.0f, 0);
            chTiptup_setState(thisActor, CH_TIPTUP_STATE_3_FF_GIVE_SEQUENCE);
            break;
        case ASSET_C7B_DIALOG_TIPTUP_LESSON_3_COMPLETE:
            timedFunc_set_0(0.0f, chTiptup_jiggySpawn);
            timed_exitStaticCamera(2.5f);
            func_80324E38(2.5f, 0);
            break;
    }
}

void chTiptup_correctHit(ActorMarker *this){
    Actor *thisActor;
    ActorLocal_Tiptup *unqPtr;
    s32 sp1C;

    thisActor = marker_getActor(this);
    unqPtr = (ActorLocal_Tiptup *)&thisActor->local;
    sp1C = vector_size(unqPtr->unk4);
    chTiptup_sfxCorrectHit();
    if(sp1C != ++unqPtr->unk0)
        return;

    if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
        item_set(ITEM_6_HOURGLASS, 0);
        volatileFlag_set(VOLATILE_FLAG_3, 0);
        volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 1);
    }
    else{
        chTiptup_minigameComplete(thisActor->marker);
    }
}

void chTiptup_setState(Actor *this, s32 next_state){
    ActorLocal_Tiptup *unqPtr;
    f32 sp54;
    f32 sequence_time;
    s32 current_member_index;
    s32 j;
    s32 prev_member;
    s32 rand2;
    Struct_BGS_2270_0s *s1;

    unqPtr = (ActorLocal_Tiptup *)&this->local;
    this->state = next_state;
    unqPtr->animTimer = 0.0f;
    if(this->state == CH_TIPTUP_STATE_1_IDLE){
        skeletalAnim_set(this->unk148, ASSET_12B_ANIM_TIPTUP_IDLE, 1.0f, 9.0f);
        unqPtr->animTimer = randf2(5.0f, 15.0f);
    }
    if(this->state == CH_TIPTUP_STATE_2_INSTRUCTIONS_DIALOG){
        skeletalAnim_set(this->unk148, ASSET_12B_ANIM_TIPTUP_IDLE, 1.0f, 9.0f);
        unqPtr->animTimer = randf2(5.0f, 15.0f);

        if (!this->has_met_before) {
            this->has_met_before = TRUE;

            if (unqPtr->round == TIPTUP_ROUND_1) {
                gcdialog_showDialog(
                    ASSET_C72_DIALOG_TIPTUP_MEET_1,
                    0xe,
                    this->position,
                    this->marker,
                    chTiptup_textEvent,
                    0);
            }
            else {
                gcdialog_showDialog(
                    ASSET_C74_DIALOG_TIPTUP_MEET_3,
                    0xf,
                    this->position,
                    this->marker,
                    chTiptup_textEvent,
                    0);
            }
        }
        else {
            gcdialog_showDialog(
                chTiptupRepeatDialogs[unqPtr->round],
                0xf,
                this->position,
                this->marker,
                chTiptup_textEvent,
                0);
        }
    }
    if(this->state == CH_TIPTUP_STATE_3_FF_GIVE_SEQUENCE){
        unqPtr->unk0 = 0;
        vector_clear(unqPtr->unk4);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.5f, 0);
        sequence_time = 0.5f;
        current_member_index = 0;
        prev_member = 0;

        for(; current_member_index < chTiptupSequenceLength[unqPtr->round]; current_member_index++){
            sequence_time += randf2(1.0f, 1.5f);
             // while loop prevents same choir member in a row
            while((rand2 = randi2(FIRST_CHOIR_MEMBER, LAST_CHOIR_MEMBER)) == prev_member);
            timedFunc_set_2(
                sequence_time,
                (GenFunction_2) chTiptup_activatePattern,
                reinterpret_cast(s32, this->marker),
                rand2);
            timedFunc_set_2(
                sequence_time + 0.1,
                (GenFunction_2)chTiptup_activatePattern,
                reinterpret_cast(s32, this->marker),
                0);
            prev_member = rand2;
        }//L80388B7C
        
        timed_exitStaticCamera(sequence_time += 2.5);
        if(!unqPtr->round && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            func_80324DBC(
                sequence_time + 0.5,
                ASSET_C73_DIALOG_TIPTUP_MEET_2,
                0xe,
                this->position,
                this->marker,
                chTiptup_textEvent,
                0);
            unqPtr->round = TIPTUP_ROUND_2;
        }
        func_80324E38(sp54 = sequence_time + 0.6, 0);
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            timedFunc_set_1(
                sp54,
                (GenFunction_1)chTiptup_activateTimer,
                reinterpret_cast(s32, this->marker));
        }else{
            this->state = CH_TIPTUP_STATE_5_WIN_MINIGAME;
        }
        mapSpecificFlags_set(CH_TIPTUP_SPECIFIC_FLAG_0_CHOIR_MEMBER_HIT_AFTER_JIGGY, 0);
    }//L80388C6C
    if(this->state == CH_TIPTUP_STATE_4_AWAIT_SEQUENCE_COMPLETION){
        
         unqPtr->unk0 = 0;
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.5f, 0);
        sequence_time = 0.5f;
        for(j = 0; j < vector_size(unqPtr->unk4); j++){
            s1 = (Struct_BGS_2270_0s *)vector_at(unqPtr->unk4,j);
            sequence_time += randf2(1.0f, 1.5f);
            timedFunc_set_2(
                sequence_time,
                (GenFunction_2)chTiptup_activatePattern,
                reinterpret_cast(s32, this->marker),
                s1->unk0);
            timedFunc_set_2(
                sequence_time + 0.1,
                (GenFunction_2)chTiptup_activatePattern,
                reinterpret_cast(s32, this->marker),
                0);
        }
        timed_exitStaticCamera(sequence_time += 2.5);
        func_80324E38(sequence_time + 0.6, 0);
        vector_clear(unqPtr->unk4);
        this->state = CH_TIPTUP_STATE_5_WIN_MINIGAME;
    }//L80388D8C
    if(this->state == CH_TIPTUP_STATE_6_AFTER_JIGGY_DIALOG){
        if(unqPtr->round == TIPTUP_ROUND_FF){
            coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
        }
        func_80324E38(0.5f, 3);
        timed_setStaticCameraToNode(1.5f, 1);
        func_80324DBC(
            2.0f,
            chTiptupSuccessDialogs[unqPtr->round++],
            0xF,
            this->position,
            this->marker,
            chTiptup_textEvent,
            0);
    }
}

void chTiptup_bouncePlayerOff(ActorMarker *arg0, ActorMarker *arg1){
    func_8028F428(2, arg0);
}

s32 chTiptup_getUnkB(ActorMarker *this){
    Actor *ptr;
    ActorLocal_Tiptup *local;

    ptr = marker_getActor(this);
    local = (ActorLocal_Tiptup *)&ptr->local;
    return local->unkB;
}

void chTiptup_choirHitReaction(ActorMarker *this, s32 arg1){
    Actor * thisActor;
    ActorLocal_Tiptup *unqPtr;
    Struct_BGS_2270_0s * tmp;

    thisActor = marker_getActor(this);
    unqPtr = (ActorLocal_Tiptup *)&thisActor->local;
    if((s32)unqPtr->unk0 >= (s32) vector_size(unqPtr->unk4)){
        if(!mapSpecificFlags_get(CH_TIPTUP_SPECIFIC_FLAG_0_CHOIR_MEMBER_HIT_AFTER_JIGGY)
            && gcdialog_showDialog(ASSET_C76_DIALOG_CHOIR_MEMBER_HIT_AFTER_JIGGY, 0, 0, 0, 0, 0))
        {
            mapSpecificFlags_set(CH_TIPTUP_SPECIFIC_FLAG_0_CHOIR_MEMBER_HIT_AFTER_JIGGY, 1);
        }
    }else{
        tmp = (Struct_BGS_2270_0s *)vector_at(unqPtr->unk4, unqPtr->unk0);
        if(arg1 == tmp->unk0){
            timedFunc_set_1(0.5f, (GenFunction_1)chTiptup_correctHit, reinterpret_cast(s32, thisActor->marker));
        }
        else{
            func_8028F55C(1, thisActor->marker);
            timedFunc_set_0(0.5f, chTiptup_sfxIncorrectHit);
            if(!mapSpecificFlags_get(CH_TIPTUP_SPECIFIC_FLAG_1_TIPTUP_MISS)
                && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)
                && gcdialog_showDialog(ASSET_C75_DIALOG_TIPTUP_MISS, 0, NULL, NULL, NULL, NULL))
            {
                mapSpecificFlags_set(CH_TIPTUP_SPECIFIC_FLAG_1_TIPTUP_MISS, TRUE);
            }
        }
    }
}

void chTiptup_setMinigameProgress(Actor *this){
    ActorLocal_Tiptup *local;

    local = (ActorLocal_Tiptup *)&this->local;
    fileProgressFlag_setN(FILEPROG_0_TIPTUP_MINIGAME_PROGRESS, local->round, 2);
    vector_free(local->unk4);
}

void func_80388FFC(ActorMarker *this, s32 *arg1, f32* arg2){
    Actor *thisActor;
    ActorLocal_Tiptup *localPtr;

    thisActor = marker_getActor(this);
    localPtr = (ActorLocal_Tiptup *)&thisActor->local;
    
    *arg2 = 0.52 + (f64)localPtr->unk9 * 0.12;
    localPtr->unk9++;
    *arg1 = localPtr->unk9;
}

void chTiptup_update(Actor *this){
    f32 player_position[3];
    ActorLocal_Tiptup *unqPtr;
    f32 time_delta;
    f32 sp38; // unused
    f32 sp34; // unused
    f32 sp30; // something about yaw

    unqPtr = (ActorLocal_Tiptup *)&this->local;
    time_delta = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = chTiptup_setMinigameProgress;
        marker_setCollisionScripts(this->marker, chTiptup_bouncePlayerOff, NULL, NULL);
        
        unqPtr->unk0 = 0;
        unqPtr->unk4 = vector_new(sizeof(Struct_BGS_2270_0s), 8);
        unqPtr->unk8 = 0;
        unqPtr->unk9 = 0;
        unqPtr->round = fileProgressFlag_getN(FILEPROG_0_TIPTUP_MINIGAME_PROGRESS, 2);
        unqPtr->unkB = 0;
        unqPtr->animTimer = 0.0f;
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            unqPtr->round = TIPTUP_ROUND_FF;
            this->position_y = this->position_y - 300.0f;
        }
        chTiptup_setState(this, CH_TIPTUP_STATE_1_IDLE);
        if(jiggyscore_isSpawned(JIGGY_27_BGS_TIPTUP)
            && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)
            && !volatileFlag_get(VOLATILE_FLAG_1))
        {
            marker_despawn(this->marker);
        }
    }
    else{
        player_getPosition(player_position);
        if(skeletalAnim_getAnimId(this->unk148) == ASSET_12C_ANIM_TIPTUP_TAPPING
            && skeletalAnim_getLoopCount(this->unk148) > 0)
        {
            skeletalAnim_set(this->unk148, ASSET_12B_ANIM_TIPTUP_IDLE, 1.0f, 9.0f);
            unqPtr->animTimer = randf2(5.0f, 15.0f);
        }
        if(ml_timer_update(&unqPtr->animTimer, time_delta)){
            skeletalAnim_set(this->unk148, ASSET_12C_ANIM_TIPTUP_TAPPING, 1.0f, 4.0f);
        }
        func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp38, &sp34, &sp30);
        this->yaw = this->yaw + 5.0f * sp30;
        if(this->state == CH_TIPTUP_STATE_1_IDLE){
            if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
                if(volatileFlag_get(VOLATILE_FLAG_3)){
                    func_80324E38(0.0f, 0);
                    chTiptup_setState(this, CH_TIPTUP_STATE_3_FF_GIVE_SEQUENCE);
                }
            }
            else{
                if(ml_vec3f_distance(this->position, player_position) < 300.0f
                    && player_getTransformation() == TRANSFORM_1_BANJO
                    && !jiggyscore_isSpawned(JIGGY_27_BGS_TIPTUP))
                {
                    chTiptup_setState(this, CH_TIPTUP_STATE_2_INSTRUCTIONS_DIALOG);
                }
            }
        }
        if(this->state == CH_TIPTUP_STATE_5_WIN_MINIGAME){
            if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
                if(item_empty(ITEM_0_HOURGLASS_TIMER)){
                    item_set(ITEM_6_HOURGLASS, 1);
                    volatileFlag_set(VOLATILE_FLAG_3, 0);
                    volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 0);
                }
            } //L80389370
            else{
                if(ml_vec3f_distance(this->position, player_position) >= 300.0f)
                    chTiptup_setState(this, CH_TIPTUP_STATE_1_IDLE);
            }
        }//L803893A0
        if(this->state == CH_TIPTUP_STATE_6_AFTER_JIGGY_DIALOG){
            if(ml_vec3f_distance(this->position, player_position) < 300.0f && !unqPtr->unk8){
                unqPtr->unk8 = 1;
                gcdialog_showDialog(ASSET_C7D_DIALOG_TIPTUP_MEET_AFTER_JIGGY, 4, 0, 0, 0, 0);
            }
        }
    }
}
