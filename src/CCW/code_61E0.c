#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorMarker *func_8028E86C(void);

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18;
}ActorLocal_CCW_61E0;

void func_8038C7A8(Actor *this);

/* .data */
ActorInfo D_8038F460 = { 0x1BC, 0x2A9, 0x48E, 0x0, NULL, func_8038C7A8, NULL, func_80325888, 0, 0, 0.8f, 0};

/* .code */
void CCW_func_8038C5D0(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);
    func_8030E878(SFX_3F2_UNKNOWN, randf2(0.95f, 1.05f), 26000, actor->position, 500.0f, 1000.0f);
}

void CCW_func_8038C638(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);
    func_8030E878(SFX_5_BANJO_LANDING_01, randf2(0.95f, 1.05f), 22000, actor->position, 500.0f, 1000.0f);
}

void CCW_func_8038C6A0(Actor *this, s32 next_state) {
    ActorLocal_CCW_61E0 *local;

    local = (ActorLocal_CCW_61E0 *)&this->local;
    if (next_state == 1) {
        func_80335924(this->unk148, 0x25B, 0.0f, 1.0f);
        func_80335800(this->unk148, 0.5f, CCW_func_8038C5D0, this->marker);
        func_80335800(this->unk148, 0.7f, CCW_func_8038C638, this->marker);
    }
    if (next_state == 3) {
        local->unk0[0] = this->position[0];
        local->unk0[1] = this->position[1];
        local->unk0[2] = this->position[2];
        func_8038BC50(local->unkC);
        local->unk18 = 0.0f;
    }
    if (next_state == 4) {
        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
        marker_despawn(this->marker);
    }
    if (next_state == 5) {
        marker_despawn(this->marker);
    }
    this->state = next_state;
}


void func_8038C7A8(Actor *this) {
    bool sp4C;
    ActorLocal_CCW_61E0 *local;
    f32 sp44;
    f32 sp38[3];

    local = (ActorLocal_CCW_61E0 *)&this->local;
    sp44 = time_getDelta();
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        return;
    }

    sp4C = (func_8028E86C() == this->marker);
    if (this->state == 0) {
        CCW_func_8038C6A0(this, sp4C ? 2 : 1);
    }

    if (this->state == 1) {
        player_getPosition(sp38);
        if (ml_distance_vec3f(this->position, sp38) < 50.0f) {
            func_8028F030(0x2A9);
            FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 25000, this->position, 500, 2500);
            CCW_func_8038C6A0(this, 5);
        }
    }
    if (this->state == 2) {
        if (this->unk138_21) {
            func_8028F010(0x2A9);
            CCW_func_8038C6A0(this, 3);
        } else if (!sp4C) {
            func_8028F050(0x2A9);
            CCW_func_8038C6A0(this, 5);
        }
    }
    if (this->state == 3) {
        local->unk18 += 3.3333333333333333 * sp44;
        local->unk18 = (local->unk18 > 1.0) ? 1.0 : local->unk18;
        ml_interpolate_vec3f(this->position, local->unk0, local->unkC, local->unk18);
        this->position[1] += 50.0f * sinf(local->unk18 * BAD_PI);
        if (local->unk18 == 1.0) {
            CCW_func_8038C6A0(this, 4);
        }
    }
}
