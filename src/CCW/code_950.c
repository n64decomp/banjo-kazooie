#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030DBFC(u8, f32, f32, f32);

typedef struct{
    u8 unk0;
    //u8 pad1[3];
    ActorMarker *unk4;
    f32 unk8[3];
    f32 unk14;
    f32 unk18;
}ActorLocal_CCW_950;

void chwasp_update(Actor *this);

/* .data */
extern ActorInfo D_8038EBD0 = { MARKER_1AE_ZUBBA, ACTOR_29B_ZUBBA, ASSET_446_MODEL_ZUBBA, 0x0, NULL, chwasp_update, NULL, func_80325888, 0, 0, 1.0f, 0};

/* .code */
void chwasp_setState(Actor *this, s32 next_state) {
    ActorLocal_CCW_950 *local;
    f32 sp50[3];
    f32 sp44[3];

    local = (ActorLocal_CCW_950 *)&this->local;
    local->unk18 = 0.0f;
    if (next_state == 1) {
        local->unk18 = 800.0f;
        func_80335924(this->unk148, ASSET_16F_ANIM_ZUBBA_FLY_MOVE, 0.0f, 0.65f);
    }
    if (next_state == 2) {
        func_80335924(this->unk148, ASSET_170_ANIM_ZUBBA_FLY_IDLE, 0.1f, 0.65f);
        player_getPosition(sp50);
        sp50[1] += 50.0f;
        local->unk8[0] = sp50[0] - this->position[0];
        local->unk8[1] = sp50[1] - this->position[1];
        local->unk8[2] = sp50[2] - this->position[2];
        ml_vec3f_normalize(local->unk8);
        if ((local->unk8[0] == 0.0f) && (local->unk8[1] == 0.0f) && (local->unk8[2] == 0.0f)) {
            local->unk8[1] = -1.0f;
        }
    }
    if (next_state == 3) {
        FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200, this->position, 500, 3000);
        func_80324D54(randf2(0.1f, 0.4f), 0x3FC, randf2(0.95f, 1.1f), 32000, this->position, 500.0f, 3000.0f);
        actor_collisionOff(this);
    }
    if (next_state == 4) {
        func_80335924(this->unk148, ASSET_171_ANIM_ZUBBA_DIE, 0.1f, 0.2f);
        FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200, this->position, 500, 3000);
        func_80324D54(0.1f, 0x66, randf2(1.6f, 1.7f), 32000, this->position, 500.0f, 3000.0f);
        func_803867C8(local->unk4);
        actor_collisionOff(this);
        player_getPosition(sp44);
        sp44[1] += 50.0f;
        local->unk8[0] = this->position[0] - sp44[0];
        local->unk8[1] = this->position[1] - sp44[1];
        local->unk8[2] = this->position[2] - sp44[2];
        ml_vec3f_normalize(local->unk8);
        if ((local->unk8[0] == 0.0f) && (local->unk8[1] == 0.0f) && (local->unk8[2] == 0.0f)) {
            local->unk8[1] = -1.0f;
        }
    }
    if (next_state == 5) {
        func_8030E878(SFX_A_BANJO_LANDING_05, randf2(0.85f, 0.95f), 18000, this->position, 500.0f, 3000.0f);
        func_80335924(this->unk148, ASSET_172_ANIM_ZUBBA_LAND, 0.0f, 1.0f);
        func_80335A8C(this->unk148, 2);
    }
    if (next_state == 6) {
        marker_despawn(this->marker);
    }
    if (next_state == 7) {
        func_80386814(local->unk4);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}


void func_80387124(ActorMarker* marker, ActorMarker *other_marker) {
    chwasp_setState(marker_getActor(marker), 3);
}

void func_80387150(ActorMarker* marker, ActorMarker *other_marker) {
    chwasp_setState(marker_getActor(marker), 4);
}

void func_8038717C(Actor *this){
    ActorLocal_CCW_950 *local;

    local = (ActorLocal_CCW_950 *)&this->local;
    func_8030DA44(local->unk0);
}

void chwasp_update(Actor *this) {
    ActorLocal_CCW_950 *local;
    f32 sp68;
    Actor *other;
    s32 sp60;
    s32 sp5C;
    f32 sp50[3];
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 temp_f0;
    f32 pad;


    sp68 = time_getDelta();
    local = (ActorLocal_CCW_950 *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->unk30 = func_8038717C;
        local->unk0 = func_8030D90C();
        local->unk4 = 0;
        local->unk14 = 1000.0f;
        sfxsource_setSfxId(local->unk0, 0x3FA);
        func_8030DD14(local->unk0, 2);
        func_8030DBB4(local->unk0, 0.9f);
        sfxsource_setSampleRate(local->unk0, 0);
        marker_setCollisionScripts(this->marker, func_80387124, NULL, func_80387150);
        chwasp_setState(this, 1);
        return;
    }
    if(local->unk4 == NULL) {
        other = func_80326EEC(0x299);
        if (other == NULL) {
            marker_despawn(this->marker);
            return;
        }
        local->unk4 = other->marker;
        func_80386840(local->unk4, &sp60, &sp5C);
        local->unk14 = (((f32)sp60 /(f32)sp5C) * 1000.0f) + 1000.0f;
    }

    if (this->state == 1) {
        temp_f0 = this->position[1];
        this->position[0] += 0.1 * sp68;
        this->position[1] += local->unk18 * sp68;
        if ((temp_f0 < 0.0f) && (this->position[1] >= 0.0f)) {
            func_8030E878(SFX_A_BANJO_LANDING_05, randf2(1.0f, 1.1f), 18000, this->position, 500.0f, 3000.0f);
        }
        player_getPosition(sp50);
        func_80258A4C(this->position, this->yaw - 90.0f, sp50, &sp4C, &sp48, &sp44);
        this->yaw += 360.0f * sp44 * sp68;
        if (this->position[1] > 150.0f) {
            local->unk18 -= 2000.0f * sp68;
            if (local->unk18 < 0.0f) {
                chwasp_setState(this, 2);
            }
        }
    }

    if (this->state == 2) {
        if (local->unk18 < local->unk14) {
            local->unk18 += (4.0f * local->unk14 * sp68);
        }
        this->position[0] += local->unk8[0] * local->unk18 * sp68;
        this->position[1] += local->unk8[1] * local->unk18 * sp68;
        this->position[2] += local->unk8[2] * local->unk18 * sp68;
        if( (this->position[0] < -1500.0f) || (1500.0f < this->position[0])
            || (this->position[1] < -100.0f)  || (1300.0f < this->position[1])
            || (this->position[2] < -1200.0f) || (this->position[2] > 2000.0f)
        ){
            chwasp_setState(this, 7);
        }
    }

    if (this->state == 3) {
        this->position[1] += local->unk18 * sp68;
        if (local->unk18 < local->unk14) {
            local->unk18 += 2000.0f * sp68;
        }

        if( (this->position[0] < -1500.0f) || (1500.0f < this->position[0]) 
            || (this->position[1] < -100.0f) || (1300.0f < this->position[1]) 
            || (this->position[2] < -1200.0f) || (this->position[2] > 2000.0f)
        ) {
            chwasp_setState(this, 7);
        }
    }

    if (this->state == 4) {
        this->position[0] += local->unk8[0] * 1000.0f * sp68;
        this->position[1] -= local->unk18 * sp68;
        this->position[2] += local->unk8[2] * 1000.0f * sp68;
        if (local->unk18 < local->unk14) {
            local->unk18 += (1000.0f * sp68);
        }
        if (this->position[1] <= 0.0f) {
            this->position[1] = 0.0f;
            chwasp_setState(this, 5);
        }
    }

    if (this->state == 5) {
        this->position[1] -= 300.0f * sp68;
        if (this->position[1] < -200.0f) {
            chwasp_setState(this, 6);
        }
    }

    if(this->state);
    if (this->state == 2) {
        func_8030DBFC(local->unk0, 1.0f, 1.1f, 0.05f);
    } else {
        func_8030DBFC(local->unk0, 0.8f, 0.9f, 0.05f);
    }
    func_8030DEB4(local->unk0, 500.0f, 1500.0f);
    func_8030DF68(local->unk0, this->position);
    func_8030E2C4(local->unk0);
    sfxsource_setSampleRate(local->unk0, (s32) ((local->unk18 / local->unk14) * 10000.0f));
}
