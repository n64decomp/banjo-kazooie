#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"



typedef struct{
    ActorMarker *jiggyMarker;
    s32 spawnedZubbaCount;
    s32 zubbasDefeated;
    f32 unkC; // time related
}ActorLocal_CCW_160;

void chZubbaFight_setState(Actor *this, s32 next_state);
void chZubbaFight_update(Actor *this);

/* .data */
ActorInfo chZubbaHoneyLump = {
    MARKER_1AD_ZUBBA_HONEY_LUMP, ACTOR_299_ZUBBA_HONEY_LUMP, ASSET_443_MODEL_ZUBBA_HONEY_LUMP,
    0x0, NULL,
    chZubbaFight_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chZubbaFight_State_e {
    CH_ZUBBA_FIGHT_STATE_0_NOT_INIT,
    CH_ZUBBA_FIGHT_STATE_1_IDLE,
    CH_ZUBBA_FIGHT_STATE_2_DIALOG,
    CH_ZUBBA_FIGHT_STATE_3_FIGHT,
    CH_ZUBBA_FIGHT_STATE_4_FIGHT_COMPLETE
};

#define NUM_OF_ZUBBAS_TO_DEFEAT    10

/* .code */
void chZubbaFight_jiggy(ActorMarker *marker){
    Actor *this;
    ActorLocal_CCW_160 *local;


    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;
    this->unk124_11 = 2;
    this->alpha_124_19 = 0xFF;
    if (local->jiggyMarker != NULL) {
        actor_collisionOn(marker_getActor(local->jiggyMarker));
    }
    coMusicPlayer_playMusic(COMUSIC_3D_JIGGY_SPAWN, 28000);
}

void chZubbaFight_startFightDialog(ActorMarker* marker, enum asset_e text_id, s32 arg2) {
    chZubbaFight_setState(marker_getActor(marker), CH_ZUBBA_FIGHT_STATE_3_FIGHT);
}

void chZubbaFight_setState(Actor *this, s32 next_state) {
    ActorLocal_CCW_160 *local;

    local = (ActorLocal_CCW_160 *)&this->local;
    local->unkC = 0.0f;
    if (next_state == CH_ZUBBA_FIGHT_STATE_2_DIALOG) {
        if (!volatileFlag_getAndSet(VOLATILE_FLAG_B5, 1)) {
            gcdialog_showDialog(
                VER_SELECT(ASSET_CE2_DIALOG_ZUBBA_MEET_SUMMER, 0x09F7, 0, 0), 4, NULL, this->marker, chZubbaFight_startFightDialog, NULL);
        } else {
            gcdialog_showDialog(VER_SELECT(ASSET_CE3_DIALOG_ZUBBA_RETURN, 0x09F8, 0, 0), 4, NULL, NULL, NULL, NULL);
            chZubbaFight_setState(this, CH_ZUBBA_FIGHT_STATE_3_FIGHT);
            return;
        }
    }

    if (next_state == CH_ZUBBA_FIGHT_STATE_3_FIGHT) {
        local->unkC = 0.1f;
        func_8025A58C(0, 4000);
        coMusicPlayer_playMusic(COMUSIC_4B_CCW_ZUBBA_FIGHT, 30000);
    }

    if (next_state == CH_ZUBBA_FIGHT_STATE_4_FIGHT_COMPLETE) {
        if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
            item_set(ITEM_6_HOURGLASS, FALSE);
            volatileFlag_set(VOLATILE_FLAG_3, 0);
            volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 1);
        } else {
            gcdialog_showDialog(VER_SELECT(ASSET_CE4_DIALOG_ZUBBA_COMPLETE, 0x09F9, 0, 0), 4, NULL, NULL, NULL, NULL);
            func_8025A58C(-1, 400);
            comusic_8025AB44(COMUSIC_4B_CCW_ZUBBA_FIGHT, 0, 400);
            func_8025AABC(COMUSIC_4B_CCW_ZUBBA_FIGHT);
            coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(2.0f, 4);
            timedFunc_set_1(2.0f, (GenFunction_1)chZubbaFight_jiggy, (s32) this->marker);
            timed_exitStaticCamera(4.0f);
            func_80324E38(4.0f, 0);
        }
    }
    this->state = next_state;
}

void chZubbaFight_zubbaKilled(ActorMarker *marker){
    Actor *this;
    ActorLocal_CCW_160 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;
    local->zubbasDefeated++;
    local->spawnedZubbaCount--;
    if(local->zubbasDefeated == NUM_OF_ZUBBAS_TO_DEFEAT){
        chZubbaFight_setState(this, CH_ZUBBA_FIGHT_STATE_4_FIGHT_COMPLETE);
    }
}

void chZubbaFight_zubbaDisappear(ActorMarker *marker){
    Actor *this;
    ActorLocal_CCW_160 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;
    local->spawnedZubbaCount--;
}

void chZubbaFight_zubbaScore(ActorMarker *marker, s32 *score, s32 *total){
    Actor *this;
    ActorLocal_CCW_160 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;

    *score = local->zubbasDefeated;
    *total = NUM_OF_ZUBBAS_TO_DEFEAT;
}

void chZubbaFight_update(Actor *this) {
    ActorLocal_CCW_160 *local;
    f32 time_delta;
    Actor *jiggy_actor;
    f32 sp78[3];
    f32 sp6C[3];
    s32 pad68;
    f32 player_position_1[3];
    s32 phi_s0;
    f32 sp4C[3];
    f32 player_position_2[3];
    s32 phi_v0;
    f32 tmp;

    time_delta = time_getDelta();
    local = (ActorLocal_CCW_160 *)&this->local;
    if(!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        reinterpret_cast(s32, local->jiggyMarker) = 1;
        local->spawnedZubbaCount = 0;
        local->zubbasDefeated = 0;
        local->unkC = 0.0f;
        if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
            this->position_y -= 300.0f;
        }
        chZubbaFight_setState(this, CH_ZUBBA_FIGHT_STATE_1_IDLE);
        return;
    }
    if ((s32)local->jiggyMarker == 1) {
        jiggy_actor = actorArray_findActorFromActorId(ACTOR_46_JIGGY);
        if(volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
            local->jiggyMarker = NULL;
            if (jiggy_actor != NULL) {
                actor_collisionOff(jiggy_actor);
                jiggy_actor->position[1] -= 300.0f;
            }
        } else if (jiggy_actor != NULL) {
            local->jiggyMarker = jiggy_actor->marker;
            actor_collisionOff(jiggy_actor);
            if (jiggyscore_isCollected(JIGGY_4C_CCW_ZUBBAS) != 0) {
                marker_despawn(local->jiggyMarker);
                marker_despawn(this->marker);
            }
        } else {
            marker_despawn(this->marker);
        }
        return;
    }
    
    if (local->jiggyMarker != NULL) {
        jiggy_actor = marker_getActor(local->jiggyMarker);
        viewport_getPosition_vec3f(sp78);
        sp6C[0] = this->position[0] - sp78[0];
        sp6C[1] = this->position[1] - sp78[1];
        sp6C[2] = this->position[2] - sp78[2];
        sp6C[1] = 0.0f;
        ml_vec3f_set_length(sp6C, 20.0f);
        jiggy_actor->position[0] = this->position[0] + sp6C[0];
        jiggy_actor->position[1] = this->position[1] + sp6C[1];
        jiggy_actor->position[2] = this->position[2] + sp6C[2];
    }
    if (ml_timer_update(&local->unkC, time_delta)) {
        if ((local->spawnedZubbaCount < 3) && ((local->zubbasDefeated + local->spawnedZubbaCount) < 10)) {
            player_getPosition(player_position_1);
            for(phi_s0 = 0; phi_s0 < 20; phi_s0++){
                sp4C[0] = randf2(-500.0f, 500.0f);
                sp4C[1] = -100.0f;
                sp4C[2] = randf2(-500.0f, 900.0f);

                if(ml_vec3f_distance(this->position, sp4C) < 400.0f)
                    continue;
                
                tmp = ml_vec3f_distance(player_position_1, sp4C);
                phi_v0 = (phi_s0 < 0xA) ?  500 : 200;
                if(tmp < (f32) phi_v0)
                    continue;

                if(viewport_isPointOutsideFrustum_3f(sp4C[0], 0.0f, sp4C[2]))
                    break;

            }
            __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_29B_ZUBBA, reinterpret_cast(s32, sp4C[0]), reinterpret_cast(s32, sp4C[1]), reinterpret_cast(s32, sp4C[2]));
            local->spawnedZubbaCount++;
        }
        local->unkC = randf2(0.5 - ((local->zubbasDefeated / 10) * 0.4), 1.0 - ((local->zubbasDefeated / 10) * 0.8));
    }
    if (this->state == CH_ZUBBA_FIGHT_STATE_1_IDLE) {
        if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)
            && volatileFlag_get(VOLATILE_FLAG_3))
        {
            item_set(ITEM_6_HOURGLASS, 1);
            item_set(ITEM_0_HOURGLASS_TIMER, VER_SELECT(1800, 1500, 1, 1) - 1);
            chZubbaFight_setState(this, CH_ZUBBA_FIGHT_STATE_3_FIGHT);
        } else if ((local->jiggyMarker != NULL) && (gsworld_getMap() == MAP_5A_CCW_SUMMER_ZUBBA_HIVE)) {
            player_getPosition(player_position_2);
            if ((ml_vec3f_distance(this->position, player_position_2) < 300.0f)
                && (player_getTransformation() == TRANSFORM_1_BANJO))
            {
                chZubbaFight_setState(this, CH_ZUBBA_FIGHT_STATE_2_DIALOG);
            }
        }
    }
    if ((this->state == CH_ZUBBA_FIGHT_STATE_3_FIGHT)
        && volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)
        && item_empty(ITEM_0_HOURGLASS_TIMER))
    {
        item_set(ITEM_6_HOURGLASS, 0);
        volatileFlag_set(VOLATILE_FLAG_3, 0);
        volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 0);
    }
}
