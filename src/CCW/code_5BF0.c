#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);

Actor *func_8038C380(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
void func_8038C41C(Actor *this);

/* .data */
ActorInfo D_8038F380 = { 0x1C6, 0x310, 0x501, 0x0, NULL, func_8038C41C, NULL, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038F3A4 = { 0x1C7, 0x311, 0x462, 0x0, NULL, func_8038C41C, NULL, func_8038C380, 0, 0, 0.0f, 0};
ActorInfo D_8038F3C8 = { 0x1C8, 0x312, 0x463, 0x0, NULL, func_8038C41C, NULL, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038F3EC = { 0x1C9, 0x313, 0x464, 0x0, NULL, func_8038C41C, NULL, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038F410 = { 0x1CA, 0x314, 0x502, 0x0, NULL, func_8038C41C, NULL, actor_draw, 0, 0, 2.0f, 0};
ActorInfo D_8038F434 = { 0x1CB, 0x315, 0x48D, 0x0, NULL, func_8038C41C, NULL, func_8038C380, 0, 0, 0.0f, 0};

/* .code */
void func_8038BFE0(ActorMarker* marker) {
    Actor* sp2C = marker_getActor(marker);
    func_8030E878(SFX_5D_BANJO_RAAOWW, randf2(1.0f, 1.1f), (s32)randf2(21000.0f, 22000.0f), sp2C->position, 500.0f, 2500.0f);
}

void func_8038C064(ActorMarker* marker) {
    Actor* sp2C = marker_getActor(marker);
    func_8030E878(SFX_5E_BANJO_PHEWWW, randf2(1.0f, 1.1f), (s32)randf2(21000.0f, 22000.0f), sp2C->position, 500.0f, 2500.0f);
}

void func_8038C0E8(ActorMarker* marker) {
    Actor* sp24 = marker_getActor(marker);
    f32 sp20 = randf2(0.9f, 1.1f);

    func_8030E878(SFX_81_UUU, sp20, (s32)randf2(10000.0f, 31000.0f), sp24->position, 500.0f, 2500.0f);
}

void CCW_func_8038C16C(Actor *this, s32 next_state) {
    Actor *other;

    if (next_state == 1) {
        this->position[1] -= 300.0f;
    }

    if (this->state == 1) {
        this->position[1] += 300.0f;
    }

    if (next_state == 2) {
        if (this->marker->id == 0x1CA) {
            skeletalAnim_set(this->unk148, 0x22E, 0.2f, 3.53f);
            skeletalAnim_setCallback_1(this->unk148, 0.1f, func_8038C0E8, this->marker);
        }
        if (this->marker->id == 0x1C7) {
            skeletalAnim_set(this->unk148, 0x230, 0.2f, 4.0f);
        }
        if (this->marker->id == 0x1CB) {
            skeletalAnim_set(this->unk148, 0x1A2, 0.2f, 4.0f);
            skeletalAnim_setCallback_1(this->unk148, 0.3f, func_8038BFE0, this->marker);
            skeletalAnim_setCallback_1(this->unk148, 0.65f, func_8038C064, this->marker);
        }
        if (this->marker->id == 0x1C8) {
            skeletalAnim_set(this->unk148, 0x231, 0.2f, 4.0f);
        }
        if ((this->marker->id == 0x1C7) || (this->marker->id == 0x1CB) || (this->marker->id == 0x1C8)) {
            other = actorArray_findActorFromActorId(0x313);
            if (other != 0) {
                this->position[0] = other->position[0];
                this->position[1] = other->position[1];
                this->position[2] = other->position[2];
                this->pitch = other->pitch;
                this->yaw = other->yaw;
                this->roll = other->roll;
            }
        }
    }
    this->state = next_state;
}

Actor *func_8038C380(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx) {
    func_8033A45C(3, 0);
    func_8033A45C(4, 0);
    func_8033A45C(5, 0);
    func_8033A45C(6, 1);
    func_8033A45C(7, 0);
    func_8033A45C(8, 0);
    func_8033A45C(9, 0);
    func_8033A45C(0xA, 1);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8038C41C(Actor *this) {
    f32 sp2C[3];

    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        return;
    }

    if (this->state == 0) {
        if( map_get() == MAP_60_CCW_AUTUMN_NABNUTS_HOUSE
            && !jiggyscore_isSpawned(JIGGY_4A_CCW_NABNUT) 
            && (this->marker->id == 0x1C6 || this->marker->id == 0x1CA)
        ){
            CCW_func_8038C16C(this, 1);
        } else {
            CCW_func_8038C16C(this, 2);
        }
    }

    if ((this->marker->id == 0x1CA) && (this->state != 1)) {
        func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
    }

    if ((this->marker->id == 0x1CB) && (this->state == 2)) {
        player_getPosition(sp2C);
        if (!this->has_met_before && (ml_vec3f_distance(this->position, sp2C) < 400.0f)) {
            this->has_met_before = TRUE;
            gcdialog_showText(0xCCD, 0, NULL, NULL, NULL, NULL);
        }
    }
}

