#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 returned_acorn_count;
}ActorLocal_ChAutumnNabnutPosition;

void chAutumnOutsideNabnut_setState(Actor *this, s32 next_state);
Actor *__chAutumnOutsideNabnut_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chAutumnOutsideNabnut_update(Actor *this);

enum chautumnoutdoornabnut_state_e{
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_0_NOT_INIT,
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_1_SAD,
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_2_WAIT,
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_3_BACKFLIP,
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_4_THANK_PLAYER,
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_5_EXIT,
    CH_AUTUMN_OUTDOOR_NABNUT_STATE_6_DESPAWN
};

/* .data */
f32 chAutumnOutdoorNabnutPosition[3] = {0.0f, 0.0f, 0.0f}; // updates on init

#define AUTUMN_NABNUT_ACORN_COUNT     6

ActorInfo chAutumnOutdoorNabnut = {
    MARKER_1BB_NABNUT, ACTOR_2A8_NABNUT, ASSET_502_MODEL_NABNUT,
    0x0, NULL, 
    chAutumnOutsideNabnut_update, chAutumnOutsideNabnut_update, __chAutumnOutsideNabnut_draw,
    0, 0, 1.2f, 0
};

/* .code */
void __chAutumnOutsideNabnut_setStateMethod(ActorMarker* marker, s32 next_state) {
    chAutumnOutsideNabnut_setState(marker_getActor(marker), next_state);
}

void chAutumnOutsideNabnut_setState(Actor *this, s32 next_state) {

    if (next_state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_1_SAD) {
        skeletalAnim_set(this->unk148, ASSET_22C_ANIM_NABNUT_CRY, 0.2f, 10.6f);
    }

    if (next_state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_2_WAIT) {
        timedFunc_set_2(
            1.0f,
            (GenFunction_2)__chAutumnOutsideNabnut_setStateMethod,
            (s32)this->marker,
            CH_AUTUMN_OUTDOOR_NABNUT_STATE_3_BACKFLIP);
    }

    if (next_state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_3_BACKFLIP) {
        this->marker->propPtr->unk8_3 = FALSE;
        skeletalAnim_set(this->unk148, ASSET_22D_ANIM_NABNUT_BACKFLIP, 0.2f, 3.13f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0xB);
        gcdialog_showDialog(
            ASSET_CCC_DIALOG_NABNUT_ACORN_COMPLETE,
            0x20, this->position,
            NULL, NULL, NULL);
    }

    if (next_state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_4_THANK_PLAYER) {
        skeletalAnim_set(this->unk148, ASSET_22E_ANIM_NABNUT_STAND, 0.2f, 3.53f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        bundle_setYaw(this->yaw - 40.0f);
        jiggy_spawn(JIGGY_4A_CCW_NABNUT, this->position);
    }

    if (next_state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_5_EXIT) {
        skeletalAnim_set(this->unk148, ASSET_22F_ANIM_NABNUT_RUN, 0.2f, 0.34f);
    }

    if (next_state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_6_DESPAWN) {
        func_80324E38(0.0f, 0);
        timed_exitStaticCamera(0.0f);
        marker_despawn(this->marker);
    }

    this->state = next_state;
}

Actor *__chAutumnOutsideNabnut_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    Actor *out;
    void *sp24;
    f32 temp_f2;

    this = marker_getActor(marker);
    func_8033A45C(3, 0);
    func_8033A45C(4, 0);
    func_8033A45C(5, 1);
    func_8033A45C(6, 0);
    func_8033A45C(7, 1);
    func_8033A45C(8, 1);
    func_8033A45C(9, 0);
    func_8033A45C(0xA, 1);
    if (this->state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_1_SAD) {
        temp_f2 = skeletalAnim_getProgress(this->unk148);
        if ((0.116 <= temp_f2) && (temp_f2 <= 0.32)) {
            sp24 = this->unk130;
            this->unk130 = NULL;
            func_8033A45C(1, 4);
            out = actor_draw(marker, gfx, mtx, vtx);
            out->unk130 = sp24;
            return out;
        }
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

void chAutumnOutsideNabnut_getPosition(f32 dst[3]){
    dst[0] = chAutumnOutdoorNabnutPosition[0];
    dst[1] = chAutumnOutdoorNabnutPosition[1];
    dst[2] = chAutumnOutdoorNabnutPosition[2];
}

void chAutumnOutsideNabnut_update(Actor *this) {
    ActorLocal_ChAutumnNabnutPosition *local;
    f32 player_position[3];
    f32 horizontal_distance;
    f32 distance_in_front;
    f32 side_angle_radian;

    local = (ActorLocal_ChAutumnNabnutPosition *)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        chAutumnOutdoorNabnutPosition[0] = this->position[0];
        chAutumnOutdoorNabnutPosition[1] = this->position[1];
        chAutumnOutdoorNabnutPosition[2] = this->position[2];
        if (this->state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_0_NOT_INIT) {
            this->has_met_before = FALSE;
            local->returned_acorn_count = 0;
        }
        chAutumnOutsideNabnut_setState(this, CH_AUTUMN_OUTDOOR_NABNUT_STATE_1_SAD);
        if(jiggyscore_isSpawned(JIGGY_4A_CCW_NABNUT)) {
            marker_despawn(this->marker);
        }
        return;
    }

    if (this->state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_1_SAD) {
        player_getPosition(player_position);
        if (!this->has_met_before
            && (ml_vec3f_distance(this->position, player_position) < 400.0f))
        {
            this->has_met_before = TRUE;
            gcdialog_showDialog(
                ASSET_CCA_DIALOG_NABNUT_MEET_FALL,
                0xE, this->position,
                NULL, NULL, NULL);
        }
        if (item_getCount(ITEM_23_ACORNS) > 0) {
            func_80258A4C(
                this->position,
                this->yaw - 90.0f,
                player_position,
                &horizontal_distance,
                &distance_in_front,
                &side_angle_radian);
            this->yaw += side_angle_radian * 10.0f;
        }
        if (this->has_met_before && !gcdialog_hasCurrentTextId()) {
            player_setCarryObjectPoseInCylinder(this->position, 500.0f, 200.0f, ACTOR_2A9_ACORN, &this);
            if ((carriedObj_getActorId() == ACTOR_2A9_ACORN)
                && (ml_vec3f_distance(this->position, player_position) < 300.0f)
                && player_throwCarriedObject())
            {
                player_setThrowTargetPosition(chAutumnOutdoorNabnutPosition);
                local->returned_acorn_count++;
                if (local->returned_acorn_count == AUTUMN_NABNUT_ACORN_COUNT) {
                    chAutumnOutsideNabnut_setState(this, CH_AUTUMN_OUTDOOR_NABNUT_STATE_2_WAIT);
                } else if (item_getCount(ITEM_23_ACORNS) == 1) {
                    gcdialog_showDialog(
                        ASSET_CCB_DIALOG_NABNUT_ACORN_CHECK,
                        0x20, this->position,
                        NULL, NULL, NULL);
                }
            }
        }
    }
    if ((this->state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_3_BACKFLIP)
        && (skeletalAnim_getLoopCount(this->unk148) > 0))
    {
        chAutumnOutsideNabnut_setState(this, CH_AUTUMN_OUTDOOR_NABNUT_STATE_4_THANK_PLAYER);
    }
    if ((this->state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_4_THANK_PLAYER)
        && (skeletalAnim_getLoopCount(this->unk148) > 0))
    {
        chAutumnOutsideNabnut_setState(this, CH_AUTUMN_OUTDOOR_NABNUT_STATE_5_EXIT);
    }
    if (this->state == CH_AUTUMN_OUTDOOR_NABNUT_STATE_5_EXIT) {
        actor_update_func_80326224(this);
        func_8028FC8C(this->position);
        if (0.99 < this->unk48) {
            chAutumnOutsideNabnut_setState(this, CH_AUTUMN_OUTDOOR_NABNUT_STATE_6_DESPAWN);
        }
    }
    func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
}
