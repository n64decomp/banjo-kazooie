#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
}ActorLocal_CCW_5540;

void func_8038B95C(Actor *this, s32 next_state);
Actor *func_8038BB1C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038BC74(Actor *this);

/* .data */
extern f32 D_8038F350[3];
extern ActorInfo D_8038F35C = { 0x1BB, 0x2A8, 0x502, 0x0, NULL, func_8038BC74, func_8038BC74, func_8038BB1C, 0, 0, 1.2f, 0};

/* .code */
void func_8038B930(ActorMarker* marker, s32 next_state) {
    func_8038B95C(marker_getActor(marker), next_state);
}

void func_8038B95C(Actor *this, s32 next_state) {

    if (next_state == 1) {
        func_80335924(this->unk148, 0x22C, 0.2f, 10.6f);
    }

    if (next_state == 2) {
        timedFunc_set_2(1.0f, (TFQM2)func_8038B930, (s32)this->marker, 3);
    }

    if (next_state == 3) {
        this->marker->propPtr->unk8_3 = FALSE;
        func_80335924(this->unk148, 0x22D, 0.2f, 3.13f);
        func_80335A8C(this->unk148, 2);
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.0f, 0xB);
        func_80311480(0xCCC, 0x20, this->position, NULL, NULL, NULL);
    }

    if (next_state == 4) {
        func_80335924(this->unk148, 0x22E, 0.2f, 3.53f);
        func_80335A8C(this->unk148, 1);
        func_802C8F70(this->yaw - 40.0f);
        jiggySpawn(JIGGY_4A_CCW_NABNUT, this->position);
    }

    if (next_state == 5) {
        func_80335924(this->unk148, 0x22F, 0.2f, 0.34f);
    }

    if (next_state == 6) {
        func_80324E38(0.0f, 0);
        func_80324E88(0.0f);
        marker_despawn(this->marker);
    }

    this->state = next_state;
}

Actor *func_8038BB1C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
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
        temp_f2 = func_80335684(this->unk148);
        if ((0.116 <= temp_f2) && (temp_f2 <= 0.32)) {
            sp24 = this->unk130;
            this->unk130 = NULL;
            func_8033A45C(1, 4);
            out = func_80325888(marker, gfx, mtx, vtx);
            out->unk130 = sp24;
            return out;
        }
    }
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_8038BC50(f32 dst[3]){
    dst[0] = D_8038F350[0];
    dst[1] = D_8038F350[1];
    dst[2] = D_8038F350[2];
}

void func_8038BC74(Actor *this) {
    ActorLocal_CCW_5540 *local;
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    local = (ActorLocal_CCW_5540 *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        D_8038F350[0] = this->position[0];
        D_8038F350[1] = this->position[1];
        D_8038F350[2] = this->position[2];
        if (this->state == 0) {
            this->unk138_24 = FALSE;
            local->unk0 = NULL;
        }
        func_8038B95C(this, 1);
        if(jiggyscore_isSpawned(JIGGY_4A_CCW_NABNUT)) {
            marker_despawn(this->marker);
        }
        return;
    }

    if (this->state == 1) {
        player_getPosition(sp30);
        if (!this->unk138_24 && (ml_vec3f_distance(this->position, sp30) < 400.0f)) {
            this->unk138_24 = TRUE;
            func_80311480(0xCCA, 0xE, this->position, NULL, NULL, NULL);
        }
        if (item_getCount(ITEM_23_ACORNS) > 0) {
            func_80258A4C(this->position, this->yaw - 90.0f, sp30, &sp2C, &sp28, &sp24);
            this->yaw += sp24 * 10.0f;
        }
        if (this->unk138_24 && !func_803114B0()) {
            func_8028F364(this->position, 500.0f, 200.0f, 0x2A9, &this);
            if ((func_8028E8C0() == 0x2A9) && (ml_vec3f_distance(this->position, sp30) < 300.0f) && func_8028FC34()) {
                func_8028FA54(D_8038F350);
                local->unk0++;
                if (local->unk0 == 6) {
                    func_8038B95C(this, 2);
                } else if (item_getCount(ITEM_23_ACORNS) == 1) {
                    func_80311480(0xCCB, 0x20, this->position, NULL, NULL, NULL);
                }
            }
        }
    }
    if ((this->state == 3) && (func_80335794(this->unk148) > 0)) {
        func_8038B95C(this, 4);
    }
    if ((this->state == 4) && (func_80335794(this->unk148) > 0)) {
        func_8038B95C(this, 5);
    }
    if (this->state == 5) {
        func_80326224(this);
        func_8028FC8C(this->position);
        if (0.99 < this->unk48) {
            func_8038B95C(this, 6);
        }
    }
    func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
}
