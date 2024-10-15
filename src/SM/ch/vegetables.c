#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
f32 mapModel_getFloorY(f32 *);
void spawnQueue_bundle_f32(s32, f32, f32, f32);
void timed_mapSpecificFlags_setTrue(f32, s32);
void subaddie_set_state_with_direction(Actor *, s32, f32, s32);

/* typedefs and declarations */
enum chVegetables_state_e {
    VEGETABLES_STATE_1_UNKNOWN = 1,
    VEGETABLES_STATE_2_UNKNOWN,
    VEGETABLES_STATE_3_UNKNOWN,
    VEGETABLES_STATE_4_UNKNOWN
};

typedef struct ch_vegetable {
    TUPLE(f32, unk0);
    s32 vegetable_id;
    u32 pad10_31: 19;
    u32 unk10_12: 4;
    u32 pad10_8: 9;
} ChVeg;

/* public functions */
Actor *chVegetablesDraw(ActorMarker *, Gfx **, Mtx **, Vtx **);
void chVegetablesUpdate(Actor *);

/* .data */
ActorAnimationInfo chTopperAnimations[5] = {
    {NULL,                          0.0f},
    {ASSET_223_ANIM_TOPPER_UNKNOWN, 1000000.0f},
    {ASSET_223_ANIM_TOPPER_UNKNOWN, 1.0f},
    {ASSET_224_ANIM_TOPPER_UNKNOWN, 0.75f},
    {ASSET_223_ANIM_TOPPER_UNKNOWN, 1.0f}
};

ActorInfo D_8038AC78 = {
    MARKER_12A_TOPPER_A, ACTOR_166_TOPPER_A, ASSET_4ED_MODEL_TOPPER,
    1, chTopperAnimations,
    chVegetablesUpdate, actor_update_func_80326224, chVegetablesDraw,
    2000, 0, 1.0f, 0
};

ActorInfo D_8038AC9C = {
    MARKER_1E6_TOPPER_B, ACTOR_TOPPER_B, ASSET_4ED_MODEL_TOPPER,
    1, chTopperAnimations,
    chVegetablesUpdate, actor_update_func_80326224, chVegetablesDraw,
    2000, 0, 1.0f, 0
};

ActorAnimationInfo chBawlAnimations[5] = {
    {NULL,                        0.0f},
    {ASSET_226_ANIM_BAWL_UNKNOWN, 1000000.0f},
    {ASSET_226_ANIM_BAWL_UNKNOWN, 1.0f},
    {ASSET_227_ANIM_BAWL_UNKNOWN, 0.75f},
    {ASSET_226_ANIM_BAWL_UNKNOWN, 1.0f}
};

ActorInfo D_8038ACE8 = {
    MARKER_129_BAWL_A, ACTOR_165_BAWL_A, ASSET_4EF_MODEL_BAWL,
    1, chBawlAnimations,
    chVegetablesUpdate, actor_update_func_80326224, chVegetablesDraw,
    0, 0, 1.0f, 0
};

ActorInfo D_8038AD0C = {
    MARKER_1E7_BAWL_B, ACTOR_BAWL_B, ASSET_4EF_MODEL_BAWL,
    1, chBawlAnimations,
    chVegetablesUpdate, actor_update_func_80326224, chVegetablesDraw,
    0, 0, 1.0f, 0
};

ActorAnimationInfo chCollywobbleAnimations[5] = {
    {NULL,                               0.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 10000000.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 1.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 10000000.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 1.0f}
};

ActorInfo D_8038AD58 = {
    MARKER_128_COLLYWOBBLE_A, ACTOR_164_COLLYWOBBLE_A, ASSET_4EE_MODEL_COLLYWOBBLE,
    1, chCollywobbleAnimations,
    chVegetablesUpdate, actor_update_func_80326224, chVegetablesDraw,
    0, 0, 2.0f, 0
};

ActorInfo D_8038AD7C = {
    MARKER_1E8_COLLYWOBBLE_B, ACTOR_COLLYWOBBLE_B, ASSET_4EE_MODEL_COLLYWOBBLE,
    1, chCollywobbleAnimations,
    chVegetablesUpdate, actor_update_func_80326224, chVegetablesDraw,
    0, 0, 2.0f, 0
};

s32 D_8038ADA0[3] = {0xFF, 0xFF, 0xFF};

ParticleScaleAndLifetimeRanges D_8038ADAC = {
    {0.1f, 0.5f},
    {1.5f, 3.0f},
    {0.0f, 0.01f},
    {1.0f, 1.5f},
    0.0f, 0.01f,
};

ParticleSettingsVelocityPosition D_8038ADD4 = {
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}},
    {{-40.0f,  -40.0f,  -40.0f},  {40.0f,  40.0f,  40.0f}}
};

ParticleScaleAndLifetimeRanges D_8038AE04 = {
    {0.5f, 0.75f},
    {0.4f, 0.6f},
    {0.0f, 0.01f},
    {4.0f, 4.0f},
    0.0f, 0.2f
};

ParticleSettingsVelocityAccelerationPosition D_8038AE2C = {
    {{-100.0f, 200.0f,  -100.0f}, {100.0f, 400.0f,  100.0f}},
    {{0.0f,    -600.0f, 0.0f},    {0.0f,   -600.0f, 0.0f}},
    {{-80.0f,  -80.0f,  -80.0f},  {80.0f,  80.0f,   80.0f}}
};

ParticleScaleAndLifetimeRanges D_8038AE74 = {
    {1.0f, 1.0f},
    {1.0f, 1.0f},
    {0.0f, 0.01f},
    {2.0f, 2.0f},
    0.0f, 0.5f
};

ParticleSettingsVelocityAccelerationPosition D_8038AE9C = {
    {{-100.0f, 400.0f,  -100.0f}, {100.0f, 600.0f,  100.0f}},
    {{0.0f,    -600.0f, 0.0f},    {0.0f,   -600.0f, 0.0f}},
    {{-20.0f,  -20.0f,  -20.0f},  {20.0f,  20.0f,   20.0f}}
};

ParticleScaleAndLifetimeRanges D_8038AEE4 = {
    {0.6f, 0.8f},
    {0.5f, 0.7f},
    {0.0f, 0.01f},
    {4.0f, 4.0f},
    0.0f, 0.5f
};

ParticleSettingsVelocityAccelerationPosition D_8038AF0C = {
    {{-200.0f,  200.0f, -200.0f}, {200.0f,  600.0f, 200.0f}},
    {{   0.0f, -900.0f,    0.0f}, {  0.0f, -900.0f,   0.0f}},
    {{-100.0f, -100.0f, -100.0f}, {100.0f,  100.0f, 100.0f}},
};

/* .code */
void __chVegetables_emitDust(ParticleEmitter *pCtrl, f32 *pos, s32 n) {
    s32 sp24[3] = D_8038ADA0;
    particleEmitter_setRGB(pCtrl, sp24);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8038ADAC);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038ADD4);
    particleEmitter_emitN(pCtrl, n);
}

void func_803879B8(ParticleEmitter *pCtrl, f32 *pos, s32 n, enum asset_e model_id) {
    particleEmitter_func_802EF9F8(pCtrl, 0.6f);
    particleEmitter_func_802EFA18(pCtrl, 2);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8038AE04);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8038AE2C);
    particleEmitter_emitN(pCtrl, n);
}

void func_80387A80(ParticleEmitter *pCtrl, f32 *pos, s32 n, enum asset_e model_id) {
    particleEmitter_func_802EF9F8(pCtrl, 0.6f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8038AE74);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8038AE9C);
    particleEmitter_emitN(pCtrl, n);
}

void func_80387B48(ParticleEmitter *pCtrl, f32 pos[3], s32 n, enum asset_e model_id) {
    particleEmitter_func_802EF9F8(pCtrl, 0.7f);
    particleEmitter_func_802EFA18(pCtrl, 4);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_setAngularVelocityRange(pCtrl, 150.0f, -300.0f, -300.0f, 300.0f, 300.0f, -150.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 8000);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8038AEE4);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8038AF0C);
    particleEmitter_emitN(pCtrl, n);
}

void __chVegetables_dieActor(Actor *this) {
    ChVeg *local = (ChVeg *) &this->local;
    f32 pos[3];

    FUNC_8030E8B4(SFX_111_WHIPCRACK_DEATH, 1.0f, 32000, this->position, 1000, 2000);

    if (local->vegetable_id == VEGETABLE_3_COLLY_WOBBLE) {
        pos[0] = this->position_x;
        pos[1] = this->position_y;
        pos[2] = this->position_z;
        pos[1] += 50.0f;

        func_80387B48(partEmitMgr_newEmitter(12), pos, 0xC, ASSET_4F4_MODEL_UNKNOWN);
        func_803879B8(partEmitMgr_newEmitter(4), pos, 0x4, ASSET_4F2_MODEL_UNKNOWN);
        func_803879B8(partEmitMgr_newEmitter(4), pos, 0x4, ASSET_4F3_MODEL_UNKNOWN);

        pos[1] += 50.0f;
        __chVegetables_emitDust(partEmitMgr_newEmitter(8), pos, 8);
    }//L80387D18

    if (this->unk38_31) {
        this->position_y += 100.0f;
        func_802CA1CC(HONEYCOMB_17_SM_COLIWOBBLE);
        __spawnQueue_add_4((GenFunction_4) spawnQueue_bundle_f32, BUNDLE_1F_SM_EMPTY_HONEYCOMB, reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, this->position_y), reinterpret_cast(s32, this->position_z));
    }//L80387D64

    timed_mapSpecificFlags_setTrue(1.5f, SM_SPECIFIC_FLAG_7);
    actor_collisionOff(this);

    if (local->vegetable_id != VEGETABLE_3_COLLY_WOBBLE) {
        subaddie_set_state_with_direction(this, VEGETABLES_STATE_3_UNKNOWN, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
    else {
        marker_despawn(this->marker);
    }
}

void __chVegetables_die(ActorMarker *marker, ActorMarker *other_marker) {
    __chVegetables_dieActor(marker_getActor(marker));
}

Actor *chVegetablesDraw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **arg3) {
    Actor *actor = marker_getActor(marker);

    if (actor->has_met_before) {
        func_8033A470(3, 7);
    }
    else {
        func_8033A45C(3, 0);
    }

    return actor_draw(marker, gdl, mptr, arg3);
}

void func_80387E64(Actor *this) {
    ChVeg *local = (ChVeg *) &this->local;

    this->unk1C_x = randf2(-50.0f, 50.0f);
    this->unk1C_y = randf2(-50.0f, 50.0f);
    this->unk1C_z = randf2(-50.0f, 50.0f);

    this->unk1C_x = local->unk0_x + this->unk1C_x;
    this->unk1C_y = local->unk0_y + this->unk1C_y;
    this->unk1C_z = local->unk0_z + this->unk1C_z;
}

void func_80387F00(Actor *this) {
    ChVeg *local = (ChVeg *) &this->local;

    this->position_y += mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) ? 120.0 : 180.0;

    local->unk0_x = this->position_x;
    local->unk0_y = this->position_y;
    local->unk0_z = this->position_z;

    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;

    func_80387E64(this);
}

int func_80387FA8(Actor *this, ChVeg *local, s32 yaw, s32 arg3) {
    f32 sp24[3];
    f32 sp18[3];

    sp18[0] = arg3;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;

    ml_vec3f_yaw_rotate_copy(sp18, sp18, yaw - 90.0);

    sp24[0] = sp18[0] + local->unk0_x;
    sp24[1] = sp18[1] + local->unk0_y;
    sp24[2] = sp18[2] + local->unk0_z;

    if (func_80307258(sp24, this->unk10_25 - 1, this->unk10_18 - 1) == -1) {
        return 0;
    }
    else {
        return 1;
    }
}

void chVegetablesUpdate(Actor *this) {
    f32 temp_velZ;
    f32 temp_velX;
    f32 temp_f0;
    f32 tick;
    f32 sp6C[3];
    f32 sp60[3];
    f32 position[3];
    ChVeg *local = (ChVeg *) &this->local; //sp38
    f32 unused;

    if (!this->initialized) {
        switch (this->marker->id) {
            default:
                local->vegetable_id = VEGETABLE_3_COLLY_WOBBLE; //cauliflower
                break;

            case MARKER_12A_TOPPER_A: //L803880F0
            case MARKER_1E6_TOPPER_B: //L803880F0
                local->vegetable_id = VEGETABLE_1_TOPPER; //carrot
                break;

            case MARKER_129_BAWL_A: //L80388100
            case MARKER_1E7_BAWL_B: //L80388100
                local->vegetable_id = VEGETABLE_2_BAWL; //onion
                break;
        }

        actor_collisionOff(this);
        marker_setCollisionScripts(this->marker, NULL, NULL, __chVegetables_die);

        this->unk1C_x = this->position_x;
        this->unk1C_y = this->position_y;
        this->unk1C_z = this->position_z;
        this->position_y -= 200.f;

        do {//L80388154
            temp_velX = randf2(-10.0f, 10.0f);
            temp_f0 = 0.0f <= temp_velX ? temp_velX : -temp_velX;
        } while (temp_f0 < 5.0);

        do {//L803881AC
            temp_velZ = randf2(-10.0f, 10.0f);
            temp_f0 = 0.0f <= temp_velZ ? temp_velZ : -temp_velZ;
        } while (temp_f0 < 5.0);

        this->velocity_x = temp_velX;
        this->velocity_y = local->vegetable_id == VEGETABLE_3_COLLY_WOBBLE ? 90.0f : 70.0f;
        this->velocity_z = temp_velZ;

        this->has_met_before = TRUE;
        this->unk138_23 = 0;
        this->unk38_0 = 0;
        this->initialized = TRUE;
        this->scale = 0.5;
    }//L80388278

    switch (this->state) {
        case VEGETABLES_STATE_1_UNKNOWN: //L803882B0
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(
                VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) || this->unk10_12) {//L803882E4
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) { //L8038830C
                    this->unk1C_y += local->vegetable_id == VEGETABLE_3_COLLY_WOBBLE ? 120.0 : 0.0;
                }
                else {//L80388350
                    this->unk1C_y += local->vegetable_id == VEGETABLE_3_COLLY_WOBBLE ? 270.0 : 85.0;
                }
                //L80388384
                subaddie_set_state(this, VEGETABLES_STATE_4_UNKNOWN);
            }
            break;

        case VEGETABLES_STATE_4_UNKNOWN: //L8038839C
            this->position_x = this->velocity_x + this->position_x;
            this->position_y = this->velocity_y + this->position_y;
            this->position_z = this->velocity_z + this->position_z;

            this->velocity_y -= 5.0f;
            this->scale = MIN(this->scale + 0.05, 1.0);

            if (this->velocity_y < 0.0f && this->position_y < this->unk1C_y) {
                this->position_y = mapModel_getFloorY(this->position);

                if (local->vegetable_id == VEGETABLE_3_COLLY_WOBBLE) {
                    func_80387F00(this);
                }

                actor_collisionOn(this);
                subaddie_set_state(this, VEGETABLES_STATE_2_UNKNOWN);
            }//L80388494

            if (!this->unk138_23) {
                if (0.0f < this->position_y) {
                    FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1000, 2000);
                    this->unk138_23 = 1;
                    this->scale = 1.0f;
                }
            }
            break;

        case VEGETABLES_STATE_2_UNKNOWN: //L803884E4
            if (this->unk38_0) {
                if (func_80329480(this)) {
                    this->unk38_0 = 0;
                }
            }
            else {//L80388520
                if (local->vegetable_id == VEGETABLE_1_TOPPER) {
                    this->actor_specific_1_f = 3.0f;

                    if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {//L80388554
                        if (!func_80329030(this, 0) && func_80329480(this)) {
                            func_80328CEC(this, (s32) this->yaw, 0x78, 0xb4);
                            this->unk38_0 = 1;
                        }//L803885A0

                        if (func_803292E0(this)) {
                            this->yaw_ideal = func_80329784(this);
                        }//L803885CC
                        else if (randf() < 0.02) {
                            func_80328CEC(this, (s32) this->yaw, 0x1E, 0x5A);
                        }//L80388B68
                    }
                    else {//L80388618
                        this->yaw_ideal = func_80329784(this);
                    }
                }
                else if (local->vegetable_id == VEGETABLE_2_BAWL) {//L80388634
                    this->actor_specific_1_f = 4.0f;

                    if (!func_80329030(this, 0) && func_80329480(this)) {
                        func_80328CEC(this, (s32) this->yaw, 0x78, 0xB4);
                        this->unk38_0 = 1;
                    }//L80388698

                    if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) && func_803292E0(
                        this))) {
                        this->yaw_ideal = func_80329784(this);
                    }//L803886E4
                    else if (randf() < 0.02) {//D_8038B1D0){
                        func_80328CEC(this, (s32) this->yaw, 0x1E, 0x5A);
                    }
                }
                else {//L80388730
                    tick = time_getDelta();

                    sp6C[0] = this->unk1C_x - this->position_x;
                    sp6C[1] = this->unk1C_y - this->position_y;
                    sp6C[2] = this->unk1C_z - this->position_z;

                    if (LENGTH_VEC3F(sp6C) < 40.0f) {
                        ml_vec3f_set_length(sp6C, 400.0f);
                    }
                    else {
                        ml_vec3f_set_length(sp6C, 100.0f);
                    }

                    this->position_x += this->velocity_x * tick + sp6C[0] * tick * tick;
                    this->position_y += this->velocity_y * tick + sp6C[1] * tick * tick;
                    this->position_z += this->velocity_z * tick + sp6C[2] * tick * tick;

                    this->velocity_x += sp6C[0] * tick;
                    this->velocity_y += sp6C[1] * tick;
                    this->velocity_z += sp6C[2] * tick;

                    if (gu_sqrtf(SQ(this->velocity_z) + (SQ(this->velocity_x) + SQ(this->velocity_y))) > 50.0f) {
                        ml_vec3f_set_length(this->velocity, 50.0f);
                    }

                    if (ml_distance_vec3f(this->position, this->unk1C) < 20.0f) {
                        func_80387E64(this);
                    }

                    this->actor_specific_1_f = 5.0f;

                    if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))) { //L8038892C
                        if (!func_80387FA8(this, local, (s32) this->yaw, (s32) this->actor_specific_1_f)) {
                            if (func_80329480(this)) {
                                func_80328CEC(this, (s32) this->yaw, 0x78, 0xb4);
                                this->unk38_0 = 1;
                            }//L80388994
                        }
                        else { //L803889A0
                            this->position_x -= local->unk0_x;
                            this->position_y -= local->unk0_y;
                            this->position_z -= local->unk0_z;

                            this->unk1C_x -= local->unk0_x;
                            this->unk1C_y -= local->unk0_y;
                            this->unk1C_z -= local->unk0_z;

                            TUPLE_ASSIGN(sp60, this->actor_specific_1_f, 0.0f, 0.0f)
                            ml_vec3f_yaw_rotate_copy(sp60, sp60, this->yaw - 90.0);

                            local->unk0_x = sp60[0] + local->unk0_x;
                            local->unk0_y = sp60[1] + local->unk0_y;
                            local->unk0_z = sp60[2] + local->unk0_z;

                            this->position_x = local->unk0_x + this->position_x;
                            this->position_y = local->unk0_y + this->position_y;
                            this->position_z = local->unk0_z + this->position_z;

                            this->unk1C_x = local->unk0_x + this->unk1C_x;
                            this->unk1C_y = local->unk0_y + this->unk1C_y;
                            this->unk1C_z = local->unk0_z + this->unk1C_z;
                        }//L80388AD8

                        if (func_803292E0(this)) {
                            this->yaw_ideal = func_80329784(this);
                        }//L80388B04
                        else if (randf() < 0.01) {
                            func_80328CEC(this, (s32) this->yaw, 0x1e, 0x5A);
                        }
                    }
                    else { //L80388B50
                        this->yaw_ideal = func_80329784(this);
                    }
                }
            }//L80388B68

            func_80328FB0(this, 2.0f);

            if (local->vegetable_id != VEGETABLE_3_COLLY_WOBBLE && actor_animationIsAt(this, 0.3f)) {
                FUNC_8030E8B4(SFX_3F2_UNKNOWN, 1.0f, 22000, this->position, 1000, 2000);
            }

            if (local->vegetable_id == VEGETABLE_3_COLLY_WOBBLE && actor_animationIsAt(this, 0.4f)) {
                FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 0.9f, 8000, this->position, 1000, 2000);
            }
            break;

        case VEGETABLES_STATE_3_UNKNOWN: //L80388BFC
            if (actor_animationIsAt(this, local->vegetable_id == VEGETABLE_2_BAWL ? 0.4 : 0.05)) {
                position[0] = this->position_x;
                position[1] = this->position_y;
                position[2] = this->position_z;

                if (local->vegetable_id == VEGETABLE_1_TOPPER) {
                    position[1] += 150.0f;
                }

                this->has_met_before = FALSE;
                func_80387A80(partEmitMgr_newEmitter(3), position, 3,
                              local->vegetable_id == VEGETABLE_1_TOPPER ? ASSET_4F0_MODEL_UNKNOWN : ASSET_4F1_MODEL_UNKNOWN);
            }//L80388CC4

            if (actor_animationIsAt(this, 0.75f)) {
                func_80326310(this);
            }
            break;
    }//L80388CE0
}//*/
