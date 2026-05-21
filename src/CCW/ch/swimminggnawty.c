#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ParticleEmitter *func_802EDD8C(f32[3], f32, f32);

typedef struct{
    s16 map_id;
    s16 despawnIfJiggyCollected;
    s16 dialog;
} CH_GNAWTY_SWIMMING_DIALOG;

typedef struct{
    CH_GNAWTY_SWIMMING_DIALOG *dialog;
    f32 unk4[3];
} ActorLocal_CCW_6620;

Actor *chGnawtySwimming_draw(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chGnawtySwimming_update(Actor *this);

/* .data */
CH_GNAWTY_SWIMMING_DIALOG chGnawtySwimmingDialogs[] ={
    {MAP_43_CCW_SPRING, FALSE, ASSET_CCE_DIALOG_GNAWTY_MEET_SPRING},
    {MAP_45_CCW_AUTUMN,  TRUE, ASSET_CD1_DIALOG_GNAWTY_MEET_FALL_OUTSIDE},
    {MAP_46_CCW_WINTER,  TRUE, ASSET_CD3_DIALOG_GNAWTY_MEET_WINTER_OUTSIDE},
    NULL
};

enum chGnawtySwimming_State_e {
    CH_GNAWTY_SWIMMING_STATE_0_NOT_INIT,
    CH_GNAWTY_SWIMMING_STATE_1_SWIMMING
};

ActorInfo chGnawtySwimming = { 
    MARKER_1BD_GNAWTY_SWIMMING, ACTOR_2AA_GNAWTY_SWIMMING, ASSET_48F_MODEL_GNAWTY,
    0x0, NULL,
    chGnawtySwimming_update, NULL, chGnawtySwimming_draw,
    0, 0, 2.2f, 0
};

/* .code */
void chGnawtySwimming_emitParticles(ActorMarker *marker) {
    Actor *this;
    ActorLocal_CCW_6620 *local;
    ParticleEmitter *pCtrl;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_6620 *)&this->local;

    if (this->marker->unk14_21) {
        if (0.65 < (f64) randf()) {
            pCtrl = func_802EDD8C(local->unk4, 0.0f, this->position[1] + 500.0f);
            particleEmitter_setStartingScaleRange(pCtrl, 0.04f, 0.05f);
            particleEmitter_setFinalScaleRange(pCtrl, 0.18f, 0.2f);
            particleEmitter_setSpawnPositionRange(pCtrl, -10.0f, 0.0f, -10.0f, 10.0f, 20.0f, 10.0f);
            particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 31.0f, 0.0f, 0.0f, 37.0f, 0.0f);
            particleEmitter_emitN(pCtrl, 1);
        }
    }
}

void chGnawtySwimming_setState(Actor *this, s32 next_state) {
    int i;

    if (next_state == CH_GNAWTY_SWIMMING_STATE_1_SWIMMING) {
        skeletalAnim_set(this->unk148, 0x289, 0.2f, 1.1f);
        for(i = 0; i < 10; i++){
            skeletalAnim_setCallback_1(this->unk148, randf(), (GenFunction_1)chGnawtySwimming_emitParticles, (s32)this->marker);
        }
    }
    this->state = next_state;
}


Actor *chGnawtySwimming_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_CCW_6620 *local;

    this = actor_draw(marker, gfx, mtx, vtx);
    local = (ActorLocal_CCW_6620 *)&this->local;
    if (this->marker->unk14_21) {
        vec3fArray_get_vec3f(func_80329934(), 5, local->unk4);
    }
    return this;
}

void chGnawtySwimming_update(Actor *this) {
    ActorLocal_CCW_6620 *local;
    f32 player_pos_1[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;
    f32 player_pos_2[3];

    local = (ActorLocal_CCW_6620 *)&this->local;
    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        local->dialog = &chGnawtySwimmingDialogs[0];
        while(local->dialog->map_id != 0 && gsworld_getMap() != local->dialog->map_id){
            local->dialog++;
        }
        chGnawtySwimming_setState(this, CH_GNAWTY_SWIMMING_STATE_1_SWIMMING);

        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
            levelSpecificFlags_set(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED, TRUE);
        }

        if ((local->dialog->despawnIfJiggyCollected != FALSE)
            && levelSpecificFlags_get(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED))
        {
            marker_despawn(this->marker);
        }

        return;
    } 

    if (this->state == CH_GNAWTY_SWIMMING_STATE_1_SWIMMING && this->marker->unk14_21) {
        player_getPosition(player_pos_1);
        func_80258A4C(
            this->position, this->yaw - 90.0f, player_pos_1,
            &horizontal_distance, &distance_in_front, &side_angle_radian);
        if (horizontal_distance > 100.0f) {
            this->yaw += 30.0f * side_angle_radian;
        }
    }
    if (!this->has_met_before) {
        player_getPosition(player_pos_2);
        if (ml_vec3f_distance(this->position, player_pos_2) < 900.0f) {
            if (local->dialog->map_id != MAP_46_CCW_WINTER
                || func_8028F2FC())
            {
                gcdialog_showDialog(local->dialog->dialog, 4, NULL, NULL, NULL, NULL);
                this->has_met_before = TRUE;
            }
        }
    }
}
