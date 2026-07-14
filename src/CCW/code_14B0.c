#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030DBFC(u8, f32, f32, f32);
extern void sfxsource_setSampleRate(u8, s32);

typedef struct{
    s16 map;
    u8  mapFlag;
    u8  jiggyId;
    s16 textId;
} Zubba_Docile_Dialog;

typedef struct {
    u8 sfxsourceIdx;
    // u8 pad1[3];
    Zubba_Docile_Dialog *dialog;
    f32 unk8; // random value?
    f32 targetPosition[3];
    f32 unk18[3]; // some kind of position?
} ActorLocal_ZubbaDocile;

void chZubbaDocile_update(Actor *this);

/* .data */
Zubba_Docile_Dialog chZubbaDocileDialog[] = {
    {
        MAP_5B_CCW_SPRING_ZUBBA_HIVE,
        CCW_ZUBBA_SPECIFIC_FLAG_7_SPRING_DIALOG,
        JIGGY_4C_CCW_ZUBBAS,
        VER_SELECT(ASSET_CE1_DIALOG_ZUBBA_MEET_SPRING, 0x09F6, 0, 0)
    },
    {
        MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,
        CCW_ZUBBA_SPECIFIC_FLAG_8_AUTUMN_DIALOG,
        NULL,
        VER_SELECT(ASSET_CE5_DIALOG_ZUBBA_MEET_FALL, 0x09FA, 0, 0)
    },
    NULL
};

ActorInfo chZubbaDocile = {
    MARKER_1AF_ZUBBA_DOCILE, ACTOR_29C_ZUBBA_DOCILE, ASSET_446_MODEL_ZUBBA,
    0x0, NULL,
    chZubbaDocile_update, NULL, actor_draw,
    0, 0, 1.0f, 0
};

enum chzubbadocile_state_e {
    CH_ZUBBA_DOCILE_STATE_0_NOT_INIT,
    CH_ZUBBA_DOCILE_STATE_1_DOCILE
};

/* .code */
void chZubbaDocile_setState(Actor *this, s32 next_state) {
    ActorLocal_ZubbaDocile *local = (ActorLocal_ZubbaDocile *)&this->local;
    int i;

    if (next_state == CH_ZUBBA_DOCILE_STATE_1_DOCILE) {
        if (skeletalAnim_getAnimId(this->unk148) != ASSET_16F_ANIM_ZUBBA_FLY_MOVE) {
            skeletalAnim_set(this->unk148, ASSET_16F_ANIM_ZUBBA_FLY_MOVE, 0.1f, 0.65f);
        }
        for(i = 0; i < 10; i++){
            local->targetPosition[0] = randf2(-500.0f, 500.0f);
            local->targetPosition[1] = randf2(400.0f, 900.0f);
            local->targetPosition[2] = randf2(-400.0f, 700.0f);
            if(ml_vec3f_distance(this->position, local->targetPosition) > 800.0f)
                break;
        }
        local->unk8 = randf2(500.0f, 1000.0f);
    }
    this->state = next_state;
}

void chZubbaDocile_free(Actor *this){
    ActorLocal_ZubbaDocile *local = (ActorLocal_ZubbaDocile *)&this->local;
    sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
}

void chZubbaDocile_update(Actor *this) {
    ActorLocal_ZubbaDocile *local;
    f32 time_delta;
    f32 distance[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;
    f32 player_position[3];

    local = (ActorLocal_ZubbaDocile *)&this->local;
    time_delta = time_getDelta();
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = chZubbaDocile_free;
        local->dialog = &chZubbaDocileDialog[0];
        while((local->dialog->map != NULL) && (gsworld_getMap() != local->dialog->map)) {
            local->dialog++;
        }
        local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        local->unk18[0] = local->unk18[1] = local->unk18[2] = 0.0f;
        sfxsource_setSfxId(local->sfxsourceIdx, SFX_3FA_HONEYCOMB_TALKING);
        sfxSource_setunk43_7ByIndex(local->sfxsourceIdx, 2);
        sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.9f);
        sfxsource_setSampleRate(local->sfxsourceIdx, 0);
        chZubbaDocile_setState(this, CH_ZUBBA_DOCILE_STATE_1_DOCILE);
        return;
    }

    if (this->state == CH_ZUBBA_DOCILE_STATE_1_DOCILE) {
        distance[0] = local->targetPosition[0] - this->position[0];
        distance[1] = local->targetPosition[1] - this->position[1];
        distance[2] = local->targetPosition[2] - this->position[2];
        if (ml_vec3f_distance(this->position, local->targetPosition) < 500.0f) {
            ml_vec3f_set_length(distance, local->unk8 * 8.0f);
        } else {
            ml_vec3f_set_length(distance, local->unk8 * 2);
        }
        this->position[0] += (local->unk18[0] * time_delta) + (distance[0] * time_delta * time_delta);
        this->position[1] += (local->unk18[1] * time_delta) + (distance[1] * time_delta * time_delta);
        this->position[2] += (local->unk18[2] * time_delta) + (distance[2] * time_delta * time_delta);
        local->unk18[0] += distance[0] * time_delta;
        local->unk18[1] += distance[1] * time_delta;
        local->unk18[2] += distance[2] * time_delta;
        if (local->unk8 < LENGTH_VEC3F(local->unk18)) {
            ml_vec3f_set_length(local->unk18, local->unk8);
        }
        func_80258A4C(
            this->position, this->yaw - 90.0f, local->targetPosition,
            &horizontal_distance, &distance_in_front, &side_angle_radian);
        this->yaw += 140.0f * side_angle_radian * time_delta;
        if (ml_vec3f_distance(this->position, local->targetPosition) < 100.0f) {
            chZubbaDocile_setState(this, CH_ZUBBA_DOCILE_STATE_1_DOCILE);
        }
    }

    if(this->position[0]);

    func_8030DBFC(local->sfxsourceIdx, 0.8f, 0.9f, 0.05f);
    sfxsource_set_fade_distances(local->sfxsourceIdx, 500.0f, 1500.0f);
    sfxsource_set_position(local->sfxsourceIdx, this->position);
    sfxSource_func_8030E2C4(local->sfxsourceIdx);
    sfxsource_setSampleRate(local->sfxsourceIdx, 2000.0f + 8000.0f * (LENGTH_VEC3F(local->unk18) / local->unk8));
    if (!mapSpecificFlags_get(local->dialog->mapFlag)) {
        player_getPosition(player_position);
        if (player_position[2] > -600.0f) {
            if (!local->dialog->jiggyId
                || !jiggyscore_isCollected(local->dialog->jiggyId))
            {
                gcdialog_showDialog(local->dialog->textId, 4, NULL, NULL, NULL, NULL);
                mapSpecificFlags_set(local->dialog->mapFlag, TRUE);
            }
        }
    }
}
