#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 returned_acorn_count;
}ActorLocal_CCW_5540;

void chnabnut_setState(Actor *this, s32 next_state);
Actor *chnabnut_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chnabnut_update(Actor *this);

enum nabnut_state_e{
    NABNUT_STATE_1_SAD = 1,
    NABNUT_STATE_2_WAIT,
    NABNUT_STATE_3_BACKFLIP,
    NABNUT_STATE_4_THANK_PLAYER,
    NABNUT_STATE_5_EXIT,
    NABNUT_STATE_6_DESPAWN
};

/* .data */
f32 D_8038F350[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_8038F35C = {
    MARKER_1BB_NABNUT, ACTOR_2A8_NABNUT, ASSET_502_MODEL_NABNUT,
    0x0, NULL, 
    chnabnut_update, chnabnut_update, chnabnut_draw,
    0, 0, 1.2f, 0
};

/* .code */
void __chnabnut_setState_method(ActorMarker* marker, s32 next_state) {
    chnabnut_setState(marker_getActor(marker), next_state);
}

void chnabnut_setState(Actor *this, s32 next_state) {

    if (next_state == NABNUT_STATE_1_SAD) {
        skeletalAnim_set(this->unk148, ASSET_22C_ANIM_NABNUT_CRY, 0.2f, 10.6f);
    }

    if (next_state == NABNUT_STATE_2_WAIT) {
        timedFunc_set_2(1.0f, (GenFunction_2)__chnabnut_setState_method, (s32)this->marker, NABNUT_STATE_3_BACKFLIP);
    }

    if (next_state == NABNUT_STATE_3_BACKFLIP) {
        this->marker->propPtr->unk8_3 = FALSE;
        skeletalAnim_set(this->unk148, ASSET_22D_ANIM_NABNUT_BACKFLIP, 0.2f, 3.13f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0xB);
        gcdialog_showText(0xCCC, 0x20, this->position, NULL, NULL, NULL);
    }

    if (next_state == NABNUT_STATE_4_THANK_PLAYER) {
        skeletalAnim_set(this->unk148, ASSET_22E_ANIM_NABNUT_STAND, 0.2f, 3.53f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        func_802C8F70(this->yaw - 40.0f);
        jiggy_spawn(JIGGY_4A_CCW_NABNUT, this->position);
    }

    if (next_state == NABNUT_STATE_5_EXIT) {
        skeletalAnim_set(this->unk148, ASSET_22F_ANIM_NABNUT_RUN, 0.2f, 0.34f);
    }

    if (next_state == NABNUT_STATE_6_DESPAWN) {
        func_80324E38(0.0f, 0);
        timed_exitStaticCamera(0.0f);
        marker_despawn(this->marker);
    }

    this->state = next_state;
}

Actor *chnabnut_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
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
    if (this->state == 1) {
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

void func_8038BC50(f32 dst[3]){
    dst[0] = D_8038F350[0];
    dst[1] = D_8038F350[1];
    dst[2] = D_8038F350[2];
}

void chnabnut_update(Actor *this) {
    ActorLocal_CCW_5540 *local;
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    local = (ActorLocal_CCW_5540 *)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        D_8038F350[0] = this->position[0];
        D_8038F350[1] = this->position[1];
        D_8038F350[2] = this->position[2];
        if (this->state == 0) {
            this->is_first_encounter = FALSE;
            local->returned_acorn_count = NULL;
        }
        chnabnut_setState(this, 1);
        if(jiggyscore_isSpawned(JIGGY_4A_CCW_NABNUT)) {
            marker_despawn(this->marker);
        }
        return;
    }

    if (this->state == NABNUT_STATE_1_SAD) {
        player_getPosition(sp30);
        if (!this->is_first_encounter && (ml_distance_vec3f(this->position, sp30) < 400.0f)) {
            this->is_first_encounter = TRUE;
            gcdialog_showText(0xCCA, 0xE, this->position, NULL, NULL, NULL);
        }
        if (item_getCount(ITEM_23_ACORNS) > 0) {
            func_80258A4C(this->position, this->yaw - 90.0f, sp30, &sp2C, &sp28, &sp24);
            this->yaw += sp24 * 10.0f;
        }
        if (this->is_first_encounter && !func_803114B0()) {
            func_8028F364(this->position, 500.0f, 200.0f, ACTOR_2A9_ACORN, &this);
            if ((carriedObj_getActorId() == ACTOR_2A9_ACORN) && (ml_distance_vec3f(this->position, sp30) < 300.0f) && player_throwCarriedObject()) {
                func_8028FA54(D_8038F350);
                local->returned_acorn_count++;
                if (local->returned_acorn_count == 6) {
                    chnabnut_setState(this, NABNUT_STATE_2_WAIT);
                } else if (item_getCount(ITEM_23_ACORNS) == 1) {
                    gcdialog_showText(0xCCB, 0x20, this->position, NULL, NULL, NULL);
                }
            }
        }
    }
    if ((this->state == NABNUT_STATE_3_BACKFLIP) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
        chnabnut_setState(this, NABNUT_STATE_4_THANK_PLAYER);
    }
    if ((this->state == NABNUT_STATE_4_THANK_PLAYER) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
        chnabnut_setState(this, NABNUT_STATE_5_EXIT);
    }
    if (this->state == NABNUT_STATE_5_EXIT) {
        func_80326224(this);
        func_8028FC8C(this->position);
        if (0.99 < this->unk48) {
            chnabnut_setState(this, NABNUT_STATE_6_DESPAWN);
        }
    }
    func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
}
