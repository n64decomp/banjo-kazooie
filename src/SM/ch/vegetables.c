#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 mapModel_getFloorY(f32*);
extern void spawnQueue_bundle_f32(s32, f32, f32, f32);
extern void timed_mapSpecificFlags_setTrue(f32 time, enum sm_specific_flags flag);
extern void subaddie_set_state_with_direction(Actor* , s32, f32, s32);

enum ch_vegetable_type {
    CH_VEGETABLE_1_TOPPER = 0x1,
    CH_VEGETABLE_2_BAWL,
    CH_VEGETABLE_3_COLLIWOBBLE
};

enum ch_vegetables_states {
    CH_VEGETABLES_STATE_1_UNKNOWN = 0x1,    //L803882B0
    CH_VEGETABLES_STATE_2_UNKNOWN,          //L803884E4
    CH_VEGETABLES_STATE_3_UNKNOWN,          //L80388BFC
    CH_VEGETABLES_STATE_4_UNKNOWN           //L8038839C
};

typedef struct ch_vegatable {
    TUPLE(f32, unk0);
    enum ch_vegetable_type vegetable_type;
    u32 unk10_12;
    u32 pad10_31;
    u32 pad10_8;
} sChVegetable;

static Actor* __chVegetables_draw(ActorMarker*, Gfx**, Mtx**, Vtx **);
static void __chVegetables_update(Actor*);

/* .data */
static ActorAnimationInfo sChCarrotAnimations[5] = {
    {NULL, NULL},
    {ASSET_223_ANIM_TOPPER_UNKNOWN, 1000000.0f},
    {ASSET_223_ANIM_TOPPER_UNKNOWN, 1.0f},
    {ASSET_224_ANIM_TOPPER_UNKNOWN, 0.75f},
    {ASSET_223_ANIM_TOPPER_UNKNOWN, 1.0f}
};

ActorInfo gChVegetablesTopperA = {
    MARKER_12A_TOPPER_THE_CARROT_A, ACTOR_166_TOPPER_THE_CARROT_A, ASSET_4ED_MODEL_TOPPER,
    1, sChCarrotAnimations, __chVegetables_update, actor_update_func_80326224, __chVegetables_draw,
    2000, 0, 1.0f, 0
};

ActorInfo gChVegetablesTopperB = {
    MARKER_1E6_TOPPER_THE_CARROT_B, ACTOR_TOPPER_THE_CARROT_B, ASSET_4ED_MODEL_TOPPER,
    1, sChCarrotAnimations, __chVegetables_update, actor_update_func_80326224, __chVegetables_draw,
    2000, 0, 1.0f, 0
};

static ActorAnimationInfo sChOnionAnimations[5] = {
    {NULL, NULL},
    {ASSET_226_ANIM_BAWL_UNKNOWN, 1000000.0f},
    {ASSET_226_ANIM_BAWL_UNKNOWN, 1.0f},
    {ASSET_227_ANIM_BAWL_UNKNOWN, 0.75f},
    {ASSET_226_ANIM_BAWL_UNKNOWN, 1.0f}
};

ActorInfo gChVegetablesBawlA = {
    MARKER_129_BAWL_THE_ONION_A, ACTOR_165_BAWL_THE_ONION_A, ASSET_4EF_MODEL_BAWL,
    1, sChOnionAnimations, __chVegetables_update, actor_update_func_80326224, __chVegetables_draw,
    0, 0, 1.0f, 0
};

ActorInfo gChVegetablesBawlB = {
    MARKER_1E7_BAWL_THE_ONION_B, ACTOR_BAWL_THE_ONION_B, ASSET_4EF_MODEL_BAWL,
    1, sChOnionAnimations, __chVegetables_update, actor_update_func_80326224, __chVegetables_draw,
    0, 0, 1.0f, 0
};

static ActorAnimationInfo sChCauliflowerAnimations[5] = {
    {NULL, NULL},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 10000000.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 1.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 10000000.0f},
    {ASSET_225_ANIM_COLLYWOBBLE_UNKNOWN, 1.0f}
};

ActorInfo gChVegetablesCollywobbleA = {
    MARKER_128_COLLYWOBBLE_THE_CAULIFLOWER_A, ACTOR_164_COLLYWOBBLE_THE_CAULIFLOWER_A, ASSET_4EE_MODEL_COLLYWOBBLE,
    1, sChCauliflowerAnimations, __chVegetables_update, actor_update_func_80326224, __chVegetables_draw,
    0, 0, 2.0f, 0
};

ActorInfo gChVegetablesCollywobbleB = {
    MARKER_1E8_COLLYWOBBLE_THE_CAULIFLOWER_B, ACTOR_COLLYWOBBLE_B, ASSET_4EE_MODEL_COLLYWOBBLE,
    1, sChCauliflowerAnimations, __chVegetables_update, actor_update_func_80326224, __chVegetables_draw,
    0, 0, 2.0f, 0
};

static s32 sChVegetablesParticleRGB[3] = {0xFF, 0xFF, 0xFF}; 

static ParticleScaleAndLifetimeRanges sD_8038ADAC = {
    {0.1f, 0.5f}, 
    {1.5f, 3.0f}, 
    {0.0f, 0.01f}, 
    {1.0f, 1.5f}, 
    0.0f, 0.01f,
};

static ParticleSettingsVelocityPosition sD_8038ADD4 = {
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}},
    {{-40.0f, -40.0f, -40.0f}, {40.0f, 40.0f, 40.0f}}
};

static ParticleScaleAndLifetimeRanges sD_8038AE04 = {
    {0.5f, 0.75f},
    {0.4f, 0.6f}, 
    {0.0f, 0.01f},
    {4.0f, 4.0f}, 
    0.0f, 0.2f
};

static ParticleSettingsVelocityAccelerationPosition sD_8038AE2C = {
    {{-100.0f, 200.0f, -100.0f}, {100.0f, 400.0f, 100.0f}}, 
    {{0.0f, -600.0f, 0.0f}, {0.0f, -600.0f, 0.0f}}, 
    {{-80.0f, -80.0f, -80.0f}, {80.0f, 80.0f, 80.0f}}
};

static ParticleScaleAndLifetimeRanges sD_8038AE74 = {
    {1.0f, 1.0f}, 
    {1.0f, 1.0f}, 
    {0.0f, 0.01f}, 
    {2.0f, 2.0f}, 
    0.0f, 0.5f
};

static ParticleSettingsVelocityAccelerationPosition sD_8038AE9C = {
    {{-100.0f, 400.0f, -100.0f}, {100.0f, 600.0f, 100.0f}}, 
    {{0.0f, -600.0f, 0.0f}, {0.0f, -600.0f, 0.0f}}, 
    {{-20.0f, -20.0f, -20.0f}, {20.0f, 20.0f, 20.0f}}
};

static ParticleScaleAndLifetimeRanges sD_8038AEE4 = {
    {0.6f, 0.8f}, 
    {0.5f, 0.7f}, 
    {0.0f, 0.01f}, 
    {4.0f, 4.0f}, 
    0.0f, 0.5f
};

static ParticleSettingsVelocityAccelerationPosition sD_8038AF0C = {
    {{-200.0f, 200.0f, -200.0f}, {200.0f, 600.0f, 200.0f}}, 
    {{0.0f, -900.0f, 0.0f}, {0.0f, -900.0f, 0.0f}}, 
    {{-100.0f, -100.0f, -100.0f}, {100.0f, 100.0f, 100.0f}}, 
};

/* .code */
static void __chVegetables_setSpriteDustParticles(ParticleEmitter *emitter, f32 *position, s32 emit_count) {
    s32 sp24[3] = sChVegetablesParticleRGB;
    particleEmitter_setRGB(emitter, sp24);
    particleEmitter_setSprite(emitter, ASSET_700_SPRITE_DUST);
    particleEmitter_setStartingFrameRange(emitter, 0, 7);
    particleEmitter_setPosition(emitter, position);
    particleEmitter_setScaleAndLifetimeRanges(emitter, &sD_8038ADAC);
    particleEmitter_setPositionAndVelocityRanges(emitter, &sD_8038ADD4);
    particleEmitter_emitN(emitter, emit_count);
}

static void __chVegetables_setParticlesForModel(ParticleEmitter *emitter, f32 *position, s32 emit_count, enum asset_e model_id) {
    particleEmitter_func_802EF9F8(emitter, 0.6f);
    particleEmitter_func_802EFA18(emitter, 2);
    particleEmitter_setModel(emitter, model_id);
    particleEmitter_setPosition(emitter, position);
    particleEmitter_setDrawMode(emitter, 2);
    particleEmitter_setAngularVelocityRange(emitter, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setScaleAndLifetimeRanges(emitter, &sD_8038AE04);
    particleEmitter_setVelocityAccelerationAndPositionRanges(emitter, &sD_8038AE2C);
    particleEmitter_emitN(emitter, emit_count);
}

static void __chVegetables_setParticlesForModel2(ParticleEmitter *emitter, f32 *position, s32 emit_count, enum asset_e model_id) {
    particleEmitter_func_802EF9F8(emitter, 0.6f);
    particleEmitter_func_802EFA18(emitter, 3);
    particleEmitter_setModel(emitter, model_id);
    particleEmitter_setPosition(emitter, position);
    particleEmitter_setDrawMode(emitter, 2);
    particleEmitter_setAngularVelocityRange(emitter, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setScaleAndLifetimeRanges(emitter, &sD_8038AE74);
    particleEmitter_setVelocityAccelerationAndPositionRanges(emitter, &sD_8038AE9C);
    particleEmitter_emitN(emitter, emit_count);
}

static void __chVegetables_setParticlesForHittingEnemyModel(ParticleEmitter *emitter, f32 position[3], s32 emit_count, enum asset_e model_id) {
    particleEmitter_func_802EF9F8(emitter, 0.7f);
    particleEmitter_func_802EFA18(emitter, 4);
    particleEmitter_setModel(emitter, model_id);
    particleEmitter_setPosition(emitter, position);
    particleEmitter_setDrawMode(emitter, 2);
    particleEmitter_setAngularVelocityRange(emitter, 150.0f, -300.0f, -300.0f, 300.0f, 300.0f, -150.0f);
    particleEmitter_setSfx(emitter, SFX_1F_HITTING_AN_ENEMY_3, 8000);
    particleEmitter_setScaleAndLifetimeRanges(emitter, &sD_8038AEE4);
    particleEmitter_setVelocityAccelerationAndPositionRanges(emitter, &sD_8038AF0C);
    particleEmitter_emitN(emitter, emit_count);
}

static void __chVegetables_vegetableDeathParticles(Actor* this) {
    sChVegetable* local = (sChVegetable*)&this->local;
    f32 particles_position[3];

    FUNC_8030E8B4(SFX_111_WHIPCRACK_DEATH, 1.0f, 32000, this->position, 1000, 2000);
    if (local->vegetable_type == CH_VEGETABLE_3_COLLIWOBBLE) {
        particles_position[0] = this->position_x;
        particles_position[1] = this->position_y;
        particles_position[2] = this->position_z;
        particles_position[1] += 50.0f;
        __chVegetables_setParticlesForHittingEnemyModel(partEmitMgr_newEmitter(0xC), particles_position, 0xC, ASSET_4F4_MODEL_COLLIWOBBLE_STEM_DEATH);
        __chVegetables_setParticlesForModel(partEmitMgr_newEmitter(4), particles_position, 0x4, ASSET_4F2_MODEL_COLLIWOBBLE_LARGE_DEATH);
        __chVegetables_setParticlesForModel(partEmitMgr_newEmitter(4), particles_position, 0x4, ASSET_4F3_MODEL_COLLIWOBBLE_SMALL_DEATH);
        particles_position[1] += 50.0f;
        __chVegetables_setSpriteDustParticles(partEmitMgr_newEmitter(8), particles_position, 8);
    }

    if (this->unk38_31) {
        this->position_y += 100.0f;
        func_802CA1CC(HONEYCOMB_17_SM_COLLIWOBBLE);
        __spawnQueue_add_4((GenFunction_4) spawnQueue_bundle_f32, BUNDLE_1F_SM_EMPTY_HONEYCOMB, reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, this->position_y), reinterpret_cast(s32, this->position_z));
    }

    timed_mapSpecificFlags_setTrue(1.5f, SM_SPECIFIC_FLAG_7);
    actor_collisionOff(this);
    if (local->vegetable_type != CH_VEGETABLE_3_COLLIWOBBLE) {
        subaddie_set_state_with_direction(this, CH_VEGETABLES_STATE_3_UNKNOWN, 0.0f, 1);
        actor_playAnimationOnce(this);
    } else {
        marker_despawn(this->marker);
    }
}

static void __chVegetables_vegetableMarkerDeathParticles(ActorMarker* marker, ActorMarker* other_marker) {
    __chVegetables_vegetableDeathParticles(marker_getActor(marker));
}

static Actor* __chVegetables_draw(ActorMarker* marker, Gfx **gdl, Mtx **mptr, Vtx **arg3) {
    Actor* actor = marker_getActor(marker);

    if (actor->has_met_before)
        func_8033A470(3, 7);
    else
        func_8033A45C(3, 0);

    return actor_draw(marker, gdl, mptr, arg3);
}

static void __chVegetables_moveVegetable(Actor* this) {
    sChVegetable* local = (sChVegetable*)&this->local;

    this->unk1C_x = randf2(-50.0f, 50.0f);
    this->unk1C_y = randf2(-50.0f, 50.0f);
    this->unk1C_z = randf2(-50.0f, 50.0f);

    this->unk1C_x = local->unk0_x + this->unk1C_x;
    this->unk1C_y = local->unk0_y + this->unk1C_y;
    this->unk1C_z = local->unk0_z + this->unk1C_z;
}

static void __chVegetables_elevateAndMoveVegetable(Actor* this) {
    sChVegetable* local = (sChVegetable*)&this->local;
    
    this->position_y += (
        mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) ||
        volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)
    ) ? 120.0 : 180.0;
    local->unk0_x = this->position_x;
    local->unk0_y = this->position_y;
    local->unk0_z = this->position_z;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    __chVegetables_moveVegetable(this);
}

// determine some kind of position logic
static bool __chVegetables_func_80387FA8(Actor* this, sChVegetable* local, s32 yaw, s32 arg3) {
    f32 sp24[3];
    f32 sp18[3];
    
    sp18[0] = arg3;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    ml_vec3f_yaw_rotate_copy(sp18, sp18, yaw - 90.0);

    sp24[0] = sp18[0] + local->unk0_x;
    sp24[1] = sp18[1] + local->unk0_y;
    sp24[2] = sp18[2] + local->unk0_z;

    if (func_80307258(sp24, this->unk10_25 - 1, this->unk10_18 - 1) == -1)
        return FALSE;
    else
        return TRUE;
}

static void __chVegetables_update(Actor* this) {
    f32 temp_velZ;
    f32 temp_velX;
    f32 temp_f0;
    f32 sp78;
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    sChVegetable* local = (sChVegetable*)&this->local; //sp38
    f32 sp30;

    if (!this->initialized) {
        switch(this->marker->id) {
            default:
                local->vegetable_type = CH_VEGETABLE_3_COLLIWOBBLE;
                break;

            case MARKER_12A_TOPPER_THE_CARROT_A:
            case MARKER_1E6_TOPPER_THE_CARROT_B:
                local->vegetable_type = CH_VEGETABLE_1_TOPPER;
                break;

            case MARKER_129_BAWL_THE_ONION_A:
            case MARKER_1E7_BAWL_THE_ONION_B:
                local->vegetable_type = CH_VEGETABLE_2_BAWL;
                break;
        }

        actor_collisionOff(this);
        marker_setCollisionScripts(this->marker, NULL, NULL, __chVegetables_vegetableMarkerDeathParticles);
        this->unk1C_x = this->position_x;
        this->unk1C_y = this->position_y;
        this->unk1C_z = this->position_z;
        this->position_y -= 200.f;

        // set temp_velX/Z to > 5
        do{
            temp_velX = randf2(-10.0f, 10.0f);
            temp_f0 = (0.0f <= temp_velX) ? temp_velX : -temp_velX;
        } while (temp_f0 < 5.0);

        do{
            temp_velZ = randf2(-10.0f, 10.0f);
            temp_f0 = (0.0f <= temp_velZ) ? temp_velZ : -temp_velZ;
        } while(temp_f0 < 5.0);

        this->velocity_x = temp_velX;
        this->velocity_y = (local->vegetable_type == CH_VEGETABLE_3_COLLIWOBBLE) ? 90.0f : 70.0f;
        this->velocity_z = temp_velZ;
        this->has_met_before = TRUE;
        this->unk138_23 = 0;
        this->unk38_0 = 0;
        this->initialized = TRUE;
        this->scale = 0.5;
    }

    switch (this->state)
    {
    case CH_VEGETABLES_STATE_1_UNKNOWN: 
        if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) || this->unk10_12) {
            if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {
                this->unk1C_y += (local->vegetable_type == CH_VEGETABLE_3_COLLIWOBBLE) ? 120.0 : 0.0;
            } else {
                this->unk1C_y += (local->vegetable_type == CH_VEGETABLE_3_COLLIWOBBLE) ? 270.0 : 85.0;
            }
            subaddie_set_state(this, CH_VEGETABLES_STATE_4_UNKNOWN);
        }
        break;
    case CH_VEGETABLES_STATE_4_UNKNOWN: 
        this->position_x = this->velocity_x + this->position_x;
        this->position_y = this->velocity_y + this->position_y;
        this->position_z = this->velocity_z + this->position_z;
        this->velocity_y -= 5.0f;
        this->scale = MIN(this->scale + 0.05, 1.0);
        if (this->velocity_y < 0.0f && this->position_y < this->unk1C_y) {
            this->position_y = mapModel_getFloorY(this->position);
            if (local->vegetable_type == CH_VEGETABLE_3_COLLIWOBBLE)
                __chVegetables_elevateAndMoveVegetable(this);

            actor_collisionOn(this);
            subaddie_set_state(this, CH_VEGETABLES_STATE_2_UNKNOWN);
        }

        if (!this->unk138_23) {
            if (0.0f < this->position_y) {
                FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1000, 2000);
                this->unk138_23 = 1;
                this->scale = 1.0f;
            }
        }

        break;
    case CH_VEGETABLES_STATE_2_UNKNOWN: 
        if (this->unk38_0) {
            if (func_80329480(this)) {
                this->unk38_0 = 0;
            }
        } else {
            if (local->vegetable_type == CH_VEGETABLE_1_TOPPER) {
                this->actor_specific_1_f = 3.0f;
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {//L80388554
                    if (!func_80329030(this, 0) && func_80329480(this)) {
                        func_80328CEC(this, (s32)this->yaw, 0x78, 0xb4);
                        this->unk38_0 = 1;
                    }
                    if (func_803292E0(this)) {
                        this->yaw_ideal = func_80329784(this);
                    }
                    else {
                        if (randf() < 0.02) {
                            func_80328CEC(this, (s32)this->yaw, 0x1E, 0x5A);
                        }
                    }
                }
                else {
                    this->yaw_ideal = func_80329784(this);
                }
            }
            else if (local->vegetable_type == CH_VEGETABLE_2_BAWL) {
                this->actor_specific_1_f = 4.0f;
                if (!func_80329030(this, 0) && func_80329480(this)) {
                    func_80328CEC(this, (s32)this->yaw, 0x78, 0xB4);
                    this->unk38_0 = 1;
                }
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) && func_803292E0(this))) {
                    this->yaw_ideal = func_80329784(this);
                } else {
                    if (randf() < 0.02) {
                        func_80328CEC(this, (s32)this->yaw, 0x1E, 0x5A);
                    }
                }
            } else {
                sp78 = time_getDelta();
                sp6C[0] = this->unk1C_x - this->position_x;
                sp6C[1] = this->unk1C_y - this->position_y;
                sp6C[2] = this->unk1C_z - this->position_z;
                if (LENGTH_VEC3F(sp6C) < 40.0f) {
                    ml_vec3f_set_length(sp6C, 400.0f);
                }
                else {
                    ml_vec3f_set_length(sp6C, 100.0f);
                }
                this->position_x += this->velocity_x*sp78 + sp6C[0]*sp78*sp78;
                this->position_y += this->velocity_y*sp78 + sp6C[1]*sp78*sp78;
                this->position_z += this->velocity_z*sp78 + sp6C[2]*sp78*sp78;
                this->velocity_x += sp6C[0]*sp78;
                this->velocity_y += sp6C[1]*sp78;
                this->velocity_z += sp6C[2]*sp78;
                if (gu_sqrtf(this->velocity_z*this->velocity_z + (this->velocity_x*this->velocity_x + this->velocity_y*this->velocity_y)) > 50.0f) {
                    ml_vec3f_set_length(this->velocity, 50.0f);
                }
                if (ml_vec3f_distance(this->position, this->unk1C) < 20.0f) {
                    __chVegetables_moveVegetable(this);
                }
                this->actor_specific_1_f = 5.0f;
                if (mapSpecificFlags_get(SM_SPECIFIC_FLAG_C) || (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))) { //L8038892C
                    if (!__chVegetables_func_80387FA8(this, local, (s32)this->yaw, (s32)this->actor_specific_1_f)) {
                        if (func_80329480(this)) {
                            func_80328CEC(this, (s32)this->yaw, 0x78, 0xb4);
                            this->unk38_0 = 1;
                        }
                    } else {
                        this->position_x -= local->unk0_x;
                        this->position_y -= local->unk0_y; 
                        this->position_z -= local->unk0_z; 
                        this->unk1C_x -= local->unk0_x;
                        this->unk1C_y -= local->unk0_y;
                        this->unk1C_z -= local->unk0_z;
                        TUPLE_ASSIGN(sp60, this->actor_specific_1_f, 0.0f, 0.0f);
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
                    }
                    if (func_803292E0(this)) {
                        this->yaw_ideal = func_80329784(this);
                    } else {
                        if (randf() < 0.01) {
                            func_80328CEC(this, (s32)this->yaw, 0x1e, 0x5A);
                        }
                    }
                } else {
                    this->yaw_ideal = func_80329784(this);
                }

            }
        }
        func_80328FB0(this, 2.0f);
        
        if (local->vegetable_type != CH_VEGETABLE_3_COLLIWOBBLE && actor_animationIsAt(this, 0.3f))
            FUNC_8030E8B4(SFX_3F2_UNKNOWN, 1.0f, 22000, this->position, 1000, 2000);
        
        if (local->vegetable_type == CH_VEGETABLE_3_COLLIWOBBLE && actor_animationIsAt(this, 0.4f))
            FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 0.9f, 8000, this->position, 1000, 2000);

        break;
    case CH_VEGETABLES_STATE_3_UNKNOWN: 
        if (actor_animationIsAt(this, (local->vegetable_type == CH_VEGETABLE_2_BAWL) ? 0.4 : 0.05)) {
            sp54[0] = this->position_x;
            sp54[1] = this->position_y;
            sp54[2] = this->position_z;
            if (local->vegetable_type == CH_VEGETABLE_1_TOPPER)
                sp54[1] += 150.0f;
            this->has_met_before = FALSE;
            __chVegetables_setParticlesForModel2(partEmitMgr_newEmitter(3), sp54, 3, (local->vegetable_type == CH_VEGETABLE_1_TOPPER) ? ASSET_4F0_MODEL_TOPPER_UNKNOWN: ASSET_4F1_MODEL_BAWL_OR_COLLIWOBBLE_UNKNOWN);
        }
        
        if (actor_animationIsAt(this, 0.75f))
            func_80326310(this);
        break;
    }
}
