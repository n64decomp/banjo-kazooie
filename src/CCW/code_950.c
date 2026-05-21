#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030DBFC(u8, f32, f32, f32);

typedef struct{
    u8 sfxsourceIdx;
    //u8 pad1[3];
    ActorMarker *honeyLumpMarker;
    f32 distanceToPlayer[3];
    f32 unk14;
    f32 unk18; // time related
}ActorLocal_CCW_950;

void chZubba_update(Actor *this);

/* .data */
ActorInfo chZubba = {
    MARKER_1AE_ZUBBA, ACTOR_29B_ZUBBA, ASSET_446_MODEL_ZUBBA,
    0x0, NULL,
    chZubba_update, NULL, actor_draw,
    0, 0, 1.0f, 0
};

enum chzubba_state_e {
    CH_ZUBBA_STATE_0_NOT_INIT,
    CH_ZUBBA_STATE_1_NON_AGRO_FLYING,
    CH_ZUBBA_STATE_2_ATTACK,
    CH_ZUBBA_STATE_3_HIT_PLAYER,
    CH_ZUBBA_STATE_4_DIE,
    CH_ZUBBA_STATE_5_SPLAT,
    CH_ZUBBA_STATE_6_DIE_DESPAWN,
    CH_ZUBBA_STATE_7_FIGHT_COMPLETE_DESPAWN
};

/* .code */
void chZubba_setState(Actor *this, s32 next_state) {
    ActorLocal_CCW_950 *local;
    f32 player_position_1[3];
    f32 player_position_2[3];

    local = (ActorLocal_CCW_950 *)&this->local;
    local->unk18 = 0.0f;
    if (next_state == CH_ZUBBA_STATE_1_NON_AGRO_FLYING) {
        local->unk18 = 800.0f;
        skeletalAnim_set(this->unk148, ASSET_16F_ANIM_ZUBBA_FLY_MOVE, 0.0f, 0.65f);
    }
    if (next_state == CH_ZUBBA_STATE_2_ATTACK) {
        skeletalAnim_set(this->unk148, ASSET_170_ANIM_ZUBBA_FLY_IDLE, 0.1f, 0.65f);
        player_getPosition(player_position_1);
        player_position_1[1] += 50.0f;
        local->distanceToPlayer[0] = player_position_1[0] - this->position[0];
        local->distanceToPlayer[1] = player_position_1[1] - this->position[1];
        local->distanceToPlayer[2] = player_position_1[2] - this->position[2];
        ml_vec3f_normalize(local->distanceToPlayer);
        if ((local->distanceToPlayer[0] == 0.0f)
            && (local->distanceToPlayer[1] == 0.0f)
            && (local->distanceToPlayer[2] == 0.0f))
        {
            local->distanceToPlayer[1] = -1.0f;
        }
    }
    if (next_state == CH_ZUBBA_STATE_3_HIT_PLAYER) {
        sfx_playFadeShorthandDefault(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200, this->position, 500, 3000);
        func_80324D54(randf2(0.1f, 0.4f), SFX_3FC_ZUBBA_UNK, randf2(0.95f, 1.1f), 32000, this->position, 500.0f, 3000.0f);
        actor_collisionOff(this);
    }
    if (next_state == CH_ZUBBA_STATE_4_DIE) {
        skeletalAnim_set(this->unk148, ASSET_171_ANIM_ZUBBA_DIE, 0.1f, 0.2f);
        sfx_playFadeShorthandDefault(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200, this->position, 500, 3000);
        func_80324D54(0.1f, 0x66, randf2(1.6f, 1.7f), 32000, this->position, 500.0f, 3000.0f);
        chZubbaFight_zubbaKilled(local->honeyLumpMarker);
        actor_collisionOff(this);
        player_getPosition(player_position_2);
        player_position_2[1] += 50.0f;
        local->distanceToPlayer[0] = this->position[0] - player_position_2[0];
        local->distanceToPlayer[1] = this->position[1] - player_position_2[1];
        local->distanceToPlayer[2] = this->position[2] - player_position_2[2];
        ml_vec3f_normalize(local->distanceToPlayer);
        if ((local->distanceToPlayer[0] == 0.0f)
            && (local->distanceToPlayer[1] == 0.0f)
            && (local->distanceToPlayer[2] == 0.0f))
        {
            local->distanceToPlayer[1] = -1.0f;
        }
    }
    if (next_state == CH_ZUBBA_STATE_5_SPLAT) {
        func_8030E878(SFX_A_BANJO_LANDING_05, randf2(0.85f, 0.95f), 18000, this->position, 500.0f, 3000.0f);
        skeletalAnim_set(this->unk148, ASSET_172_ANIM_ZUBBA_LAND, 0.0f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
    if (next_state == CH_ZUBBA_STATE_6_DIE_DESPAWN) {
        marker_despawn(this->marker);
    }
    if (next_state == CH_ZUBBA_STATE_7_FIGHT_COMPLETE_DESPAWN) {
        chZubbaFight_zubbaDisappear(local->honeyLumpMarker);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}


void chZubba_hitPlayer(ActorMarker* marker, ActorMarker *other_marker) {
    chZubba_setState(marker_getActor(marker), CH_ZUBBA_STATE_3_HIT_PLAYER);
}

void chZubba_die(ActorMarker* marker, ActorMarker *other_marker) {
    chZubba_setState(marker_getActor(marker), CH_ZUBBA_STATE_4_DIE);
}

void chZubba_freeSfx(Actor *this){
    ActorLocal_CCW_950 *local;

    local = (ActorLocal_CCW_950 *)&this->local;
    sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
}

void chZubba_update(Actor *this) {
    ActorLocal_CCW_950 *local;
    f32 time_delta;
    Actor *honey_lump_actor;
    s32 zubbas_defeated;
    s32 zubbas_to_defeat;
    f32 player_position[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;
    f32 temp_f0;
    f32 pad;


    time_delta = time_getDelta();
    local = (ActorLocal_CCW_950 *)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = chZubba_freeSfx;
        local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        local->honeyLumpMarker = 0;
        local->unk14 = 1000.0f;
        sfxsource_setSfxId(local->sfxsourceIdx, SFX_3FA_HONEYCOMB_TALKING);
        sfxSource_setunk43_7ByIndex(local->sfxsourceIdx, 2);
        sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.9f);
        sfxsource_setSampleRate(local->sfxsourceIdx, 0);
        marker_setCollisionScripts(this->marker, chZubba_hitPlayer, NULL, chZubba_die);
        chZubba_setState(this, CH_ZUBBA_STATE_1_NON_AGRO_FLYING);
        return;
    }
    if(local->honeyLumpMarker == NULL) {
        honey_lump_actor = actorArray_findActorFromActorId(ACTOR_299_ZUBBA_HONEY_LUMP);
        if (honey_lump_actor == NULL) {
            marker_despawn(this->marker);
            return;
        }
        local->honeyLumpMarker = honey_lump_actor->marker;
        chZubbaFight_zubbaScore(local->honeyLumpMarker, &zubbas_defeated, &zubbas_to_defeat);
        local->unk14 = (((f32)zubbas_defeated /(f32)zubbas_to_defeat) * 1000.0f) + 1000.0f;
    }

    if (this->state == CH_ZUBBA_STATE_1_NON_AGRO_FLYING) {
        temp_f0 = this->position[1];
        this->position[0] += 0.1 * time_delta;
        this->position[1] += local->unk18 * time_delta;
        if ((temp_f0 < 0.0f) && (this->position[1] >= 0.0f)) {
            func_8030E878(SFX_A_BANJO_LANDING_05, randf2(1.0f, 1.1f), 18000, this->position, 500.0f, 3000.0f);
        }
        player_getPosition(player_position);
        func_80258A4C(
            this->position, this->yaw - 90.0f, player_position,
            &horizontal_distance, &distance_in_front, &side_angle_radian);
        this->yaw += 360.0f * side_angle_radian * time_delta;
        if (this->position[1] > 150.0f) {
            local->unk18 -= 2000.0f * time_delta;
            if (local->unk18 < 0.0f) {
                chZubba_setState(this, CH_ZUBBA_STATE_2_ATTACK);
            }
        }
    }

    if (this->state == CH_ZUBBA_STATE_2_ATTACK) {
        if (local->unk18 < local->unk14) {
            local->unk18 += (4.0f * local->unk14 * time_delta);
        }
        this->position[0] += local->distanceToPlayer[0] * local->unk18 * time_delta;
        this->position[1] += local->distanceToPlayer[1] * local->unk18 * time_delta;
        this->position[2] += local->distanceToPlayer[2] * local->unk18 * time_delta;
        if( (this->position[0] < -1500.0f) || (1500.0f < this->position[0])
            || (this->position[1] < -100.0f)  || (1300.0f < this->position[1])
            || (this->position[2] < -1200.0f) || (this->position[2] > 2000.0f)
        ){
            chZubba_setState(this, CH_ZUBBA_STATE_7_FIGHT_COMPLETE_DESPAWN);
        }
    }

    if (this->state == CH_ZUBBA_STATE_3_HIT_PLAYER) {
        this->position[1] += local->unk18 * time_delta;
        if (local->unk18 < local->unk14) {
            local->unk18 += 2000.0f * time_delta;
        }

        if( (this->position[0] < -1500.0f) || (1500.0f < this->position[0]) 
            || (this->position[1] < -100.0f) || (1300.0f < this->position[1]) 
            || (this->position[2] < -1200.0f) || (this->position[2] > 2000.0f)
        ) {
            chZubba_setState(this, CH_ZUBBA_STATE_7_FIGHT_COMPLETE_DESPAWN);
        }
    }

    if (this->state == CH_ZUBBA_STATE_4_DIE) {
        this->position[0] += local->distanceToPlayer[0] * 1000.0f * time_delta;
        this->position[1] -= local->unk18 * time_delta;
        this->position[2] += local->distanceToPlayer[2] * 1000.0f * time_delta;
        if (local->unk18 < local->unk14) {
            local->unk18 += (1000.0f * time_delta);
        }
        if (this->position[1] <= 0.0f) {
            this->position[1] = 0.0f;
            chZubba_setState(this, CH_ZUBBA_STATE_5_SPLAT);
        }
    }

    if (this->state == CH_ZUBBA_STATE_5_SPLAT) {
        this->position[1] -= 300.0f * time_delta;
        if (this->position[1] < -200.0f) {
            chZubba_setState(this, CH_ZUBBA_STATE_6_DIE_DESPAWN);
        }
    }

    if(this->state);
    if (this->state == CH_ZUBBA_STATE_2_ATTACK) {
        func_8030DBFC(local->sfxsourceIdx, 1.0f, 1.1f, 0.05f);
    } else {
        func_8030DBFC(local->sfxsourceIdx, 0.8f, 0.9f, 0.05f);
    }
    sfxsource_set_fade_distances(local->sfxsourceIdx, 500.0f, 1500.0f);
    sfxsource_set_position(local->sfxsourceIdx, this->position);
    sfxSource_func_8030E2C4(local->sfxsourceIdx);
    sfxsource_setSampleRate(local->sfxsourceIdx, (s32) ((local->unk18 / local->unk14) * 10000.0f));
}
