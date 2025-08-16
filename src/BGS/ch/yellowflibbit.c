#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[1];
    s16 unk4[3];
    s16 unkA[3];
    s16 unk10[3];
    u8 pad16[0x2];
    f32 unk18;
    f32 unk1C;
    f32 unk20[2];
    f32 unk28;
}ActorLocal_Yellow_Flibbit;

Actor *func_8038DE5C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx** vtx);
void BGS_func_8038E034(Actor *this);

/* .data */
ActorInfo BGS_D_80390AE0 = {
    MARKER_C5_FLIBBIT_YELLOW, ACTOR_137_FLIBBIT_YELLOW, ASSET_385_MODEL_FLIBBIT_YELLOW,
    0, NULL, 
    BGS_func_8038E034, NULL, func_8038DE5C,
    0, 0, 1.0f, 0
};
s32 D_80390B04[3] = {0xFF, 0xB3, 0};
f32 BGS_D_80390B10[3] = {0.0f, 0.0f, 0.0f};

/* .code */
void func_8038D1E0(Actor *this) {
    ParticleEmitter *temp_s0;

    temp_s0 = partEmitMgr_newEmitter(4U);
    particleEmitter_setSprite(temp_s0, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(temp_s0, 0.01f, 0.7f);
    particleEmitter_setStartingFrameRange(temp_s0, 0, 7);
    particleEmitter_setPosition(temp_s0, this->position);
    particleEmitter_setRGB(temp_s0, D_80390B04);
    particleEmitter_setStartingScaleRange(temp_s0, 1.0f, 1.5f);
    particleEmitter_setFinalScaleRange(temp_s0, 2.5f, 3.0f);
    particleEmitter_setParticleVelocityRange(temp_s0, -70.0f, 50.0f, -70.0f, 70.0f, 100.0f, 70.0f);
    particleEmitter_setParticleLifeTimeRange(temp_s0, 3.0f, 4.0f);
    particleEmitter_emitN(temp_s0, 4);
    sfx_playFadeShorthandDefault(SFX_30_MAGIC_POOF, 1.0f, 25000, this->position, 500, 2500);
}

s32 func_8038D2F4(Actor *this, f32 *arg1, bool arg2) {
    ActorLocal_Yellow_Flibbit *local;

    local = (ActorLocal_Yellow_Flibbit *)&this->local;
    local->unk1 = arg2;
    local->unk4[0] = (s16) this->position[0];\
    local->unk4[1] = (s16) this->position[1];\
    local->unk4[2] = (s16) this->position[2];

    local->unkA[0] = (s16) arg1[0];
    local->unkA[1] = (s16) arg1[1];
    local->unkA[2] = (s16) arg1[2];
    local->unkA[1] = (s16) (s32) mapModel_getFloorY(arg1);
    skeletalAnim_set(this->unk148, ASSET_DB_ANIM_FLIBBIT_HOP, 0.2f, (arg2) ? randf2(0.7f, 0.8f) : randf2(0.7f, 0.8f));
    skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    func_80324D54(0.2f, SFX_3F2_UNKNOWN, randf2(0.7f, 1.3f), randi2(25000, 27000), this->position, 500.0f, 2500.0f);
    return TRUE;
}

bool func_8038D468(Actor *this) {
    f32 player_position[3];
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp3C[3];
    f32 sp30[3];

    player_getPosition(player_position);
    func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp50, &sp4C, &sp48);
    if (func_80329210(this, &player_position)) {
        if ((-0.7 <= sp48) && (sp48 <= 0.7)) {
            sp3C[0] = player_position[0] - this->position[0];
            sp3C[1] = player_position[1] - this->position[1];
            sp3C[2] = player_position[2] - this->position[2];
            ml_vec3f_set_length(sp3C, 210.0f);
            sp30[0] = this->position[0] + sp3C[0];
            sp30[1] = this->position[1] + sp3C[1];
            sp30[2] = this->position[2] + sp3C[2];
            if (func_80329210(this, sp30)) {
                return func_8038D2F4(this, sp30, 1);
            }
        }
    }
    return FALSE;
}

bool func_8038D5A8(Actor *this) {
    f32 sp64[3];
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    ActorLocal_Yellow_Flibbit *local;
    f32 sp3C[3];

    local = (ActorLocal_Yellow_Flibbit *)&this->local;
    sp64[0] = (f32) local->unk10[0];
    sp64[1] = (f32) local->unk10[1];
    sp64[2] = (f32) local->unk10[2];
    func_80258A4C(this->position, this->yaw - 90.0f, sp64, &sp60, &sp5C, &sp58);
    if ((-0.9 <= sp58) && (sp58 <= 0.9)) {
        if (252.0 < sp60) {
            sp4C[0] = sp64[0] - this->position[0];
            sp4C[1] = sp64[1] - this->position[1];
            sp4C[2] = sp64[2] - this->position[2];
            ml_vec3f_set_length(sp4C, 210.0f);
            sp3C[0] = this->position[0] + sp4C[0];
            sp3C[1] = this->position[1] + sp4C[1];
            sp3C[2] = this->position[2] + sp4C[2];
        } else {
            sp3C[0] = (f32) local->unk10[0];
            sp3C[1] = (f32) local->unk10[1];
            sp3C[2] = (f32) local->unk10[2];
        }
        if (func_80329210(this, sp3C) != 0) {
            return func_8038D2F4(this, sp3C, 0);
        }
    }
    return FALSE;
}

s32 func_8038D768(Actor *this) {
    f32 player_position[3];
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    s32 var_s1;
    f32 sp68[3];
    f32 var_f2;

    player_getPosition(player_position);
    func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp80, &sp7C, &sp78);
    for(var_s1 = 0; var_s1 != 10; var_s1++){
        if (var_s1 < 5) {
            if (sp78 > 0.0f) {
                var_f2 = randf2(10.0f, 90.0f) + this->yaw;
            } else {
                var_f2 = randf2(-90.0f, -10.0f) + this->yaw;
            }
        } else {
            var_f2 = randf2(-110.0f, 110.0f) + this->yaw;
        }
        func_80256E24(sp68, 0.0f, var_f2, 0.0f, 0.0f, 210.0f);
        sp68[0] = this->position[0] + sp68[0];
        sp68[1] = this->position[1] + sp68[1];
        sp68[2] = this->position[2] + sp68[2];
        if (func_80329210(this, sp68)) {
            return func_8038D2F4(this, sp68, 0);
        }
    }
    return FALSE;
}

bool func_8038D930(Actor *this) {
    f32 player_position[3];
    s32 var_v1;

    player_getPosition(player_position);
    if (func_80329210(this, &player_position)) {
        var_v1 = func_8038D468(this);
        if (var_v1 == 0) {
            if (randf() > 0.5) {
                return FALSE;
            }
        }
    }
    else{
        var_v1 = func_8038D5A8(this);
    }

    if (var_v1 == 0) {
        var_v1 = func_8038D768(this);
    }
    return var_v1;
}

void func_8038D9D0(Actor *this, s32 next_state) {
    ActorLocal_Yellow_Flibbit *local;

    local = (ActorLocal_Yellow_Flibbit *)&this->local;
    local->unk1 = 0;
    local->unk1C = 0.0f;
    local->unk28 = 0.0f;
    if (next_state == 1) {
        if (this->state != 0) {
            func_8038CEB8();
            func_8038D1E0(this);
        }
        actor_collisionOff(this);
    }
    if (next_state == 2) {
        func_8038CE88();
        func_8038D1E0(this);
        local->unk1C = 0.5f;
    }
    if (next_state == 3) {
        skeletalAnim_set(this->unk148, ASSET_FA_ANIM_FLIBBIT_IDLE, 0.2f, randf2(1.0f, 2.0f));
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 0.9));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        actor_collisionOn(this);
        this->position[0] = (f32) local->unk10[0];
        this->position[1] = (f32) local->unk10[1];
        this->position[2] = (f32) local->unk10[2];
        local->unk28 = randf2(1.0f, 3.0f);
    }
    if (next_state == 5) {
        if (mapSpecificFlags_get(0x10)) {
            func_8038D9D0(this, 4);
            return;
        }
        if (!func_8038D930(this)){
            if ((this->state != 6)) {
                func_8038D9D0(this, 6);
            }
            return;
        }
    }
    if (next_state == 6) {
        skeletalAnim_set(this->unk148, ASSET_FB_ANIM_FLIBBIT_TURN, 0.2f, 1.0f);
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 1.0f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        local->unk28 = randf2(1.0f, 3.0f);
    }
    if (next_state == 7) {
        skeletalAnim_set(this->unk148, ASSET_FA_ANIM_FLIBBIT_IDLE, 0.2f, randf2(1.0f, 2.0f));
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 0.9));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        this->position[1] = mapModel_getFloorY(this->position);
        local->unk1C = 1.0f;
    }
    if (next_state == 8) {
        sfx_playFadeShorthandDefault(SFX_8E_GRUNTLING_DAMAGE, 1.5f, 32200, this->position, 500, 2500);
        skeletalAnim_set(this->unk148, ASSET_288_ANIM_FLIBBIT_OW, 0.1f, 0.65f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        this->position[1] = mapModel_getFloorY(this->position);
        local->unk1C = 1.0f;
    }
    if (next_state == 9) {
        skeletalAnim_set(this->unk148, ASSET_112_ANIM_FLIBBIT_DIE, 0.2f, 0.4f);
        sfx_playFadeShorthandDefault(SFX_115_BUZZBOMB_DEATH, 1.0f, 32200, this->position, 500, 2500);
        this->marker->collidable = FALSE;
        this->unk10_1 = FALSE;
        func_8038CEA0();
        local->unk18 = 1000.0f;
    }
    if (next_state == 0xA) {
        skeletalAnim_set(this->unk148, ASSET_113_ANIM_FLIBBIT_DEAD, 0.2f, 1.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        sfx_playFadeShorthandDefault(SFX_2F_ORANGE_SPLAT, 0.8f, 32200, this->position, 500, 2500);
    }
    if (next_state == 0xB) {
        func_80326310(this);
    }
    this->state = next_state;
}

void func_8038DD9C(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < 9){
        func_8038D9D0(this, 7);
    }
}

void func_8038DDDC(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < 9){
        func_8038D9D0(this, 8);
    }
}

void func_8038DE1C(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < 9){
        func_8038D9D0(this, 9);
    }
}

Actor *func_8038DE5C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_Yellow_Flibbit *local;
    s32 var_s0;
    f32 var_f2;
    f32 sp7C[3];
    BoneTransformList *temp_a0_2;

    this = marker_getActor(marker);
    local = (ActorLocal_Yellow_Flibbit *)&this->local;
    if (this->state < 3) {
        return this;
    }
    if (local->unk0 && ((this->state == 3) || (this->state == 6))) {
        temp_a0_2 = skeletalAnim_getBoneTransformList(this->unk148);
        for(var_s0 = 0; var_s0 < 2; var_s0++){
            if (0.1 <= local->unk20[var_s0]) {
                var_f2 = (f32) ((local->unk20[var_s0] - 0.1) / 0.1);
            } else if (local->unk20[var_s0] >= 0.0f) {
                var_f2 = (f32) (1.0 - (local->unk20[var_s0] / 0.1));
            } else {
                var_f2 = 1.0f;
            }
            sp7C[0] = 1.0f;
            sp7C[1] = var_f2 * 0.99 + 0.01;
            sp7C[2] = 1.0f;
            boneTransformList_setBoneScale(temp_a0_2, (var_s0 != 0) ? 0x2D : 0x2E, sp7C);
        };
    }
    actor_draw(marker, gfx, mtx, vtx);
    local->unk0 = marker->unk14_21;
    return this;
}

void BGS_func_8038E034(Actor *this) {
    f32 spB4[3];
    f32 spA8[3];
    f32 spA4;
    ActorLocal_Yellow_Flibbit *local = (ActorLocal_Yellow_Flibbit *)&this->local;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp7C[3];
    f32 temp_f12;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp60[3];
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp48[3];

    sp9C = time_getDelta();
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, &func_8038DD9C, &func_8038DDDC, &func_8038DE1C);
        local->unk2 = 0U;
        local->unk20[0] = randf2(-2.0f, -1.0f);
        local->unk20[1] = randf2(-2.0f, -1.0f);
        local->unk10[0] = (s16) (s32) this->position[0];
        local->unk10[1] = (s16) (s32) this->position[1];
        local->unk10[2] = (s16) (s32) this->position[2];
        func_8038D9D0(this, 1);
        if (jiggyscore_isSpawned(JIGGY_24_BGS_FLIBBITS) != 0) {
            marker_despawn(this->marker);
        }
        return;
    } 
    if (!local->unk2) {
        local->unk2 = TRUE;
        BGS_func_8038CED0();
    }
    player_getPosition(spB4);
    spA8[0] = spB4[0] - this->position[0];
    spA8[1] = spB4[1] - this->position[1];
    spA8[2] = spB4[2] - this->position[2];
    spA4 = LENGTH_VEC3F(spA8);
    if (ml_timer_update(&local->unk28, sp9C) != 0) {
        func_8030E878(0x3F0, randf2(0.9f, 1.1f), randi2(12000, 19000), this->position, 500.0f, 2500.0f);
        local->unk28 = randf2(1.0f, 6.0f);
    }
    local->unk20[0] += sp9C;
    local->unk20[0] = (0.2 < (f64) local->unk20[0]) ? randf2(-3.0f, -1.0f) : local->unk20[0];

        local->unk20[1] += sp9C;
    local->unk20[1] = (0.2 < (f64) local->unk20[1]) ? randf2(-3.0f, -1.0f) : local->unk20[1];

    if(this->state == 1){
        if(mapSpecificFlags_getClear(0x12)){
            func_8038D9D0(this, 2);
            return;
        }

        if(spA4 < 2000.0f){
            func_80258A4C(this->position, this->yaw - 90.0f, spB4, &sp98, &sp94, &sp90);
            this->yaw += (sp90*90.0f) *sp9C; 
        }
    }

    if(this->state == 2){
        if(ml_timer_update(&local->unk1C, sp9C)){
            func_8038D9D0(this, 3);
        }
    }

    if(this->state == 3){
         if (func_80329210(this, spB4)) {
                func_8038D9D0(this, 5);
            } else {
                func_8038D9D0(this, 1);
            }
    }


    if(this->state == 4){
        if(!mapSpecificFlags_get(0x10))
            func_8038D9D0(this, 5);
    }

    if (this->state == 5) {
        skeletalAnim_getProgressRange(this->unk148, &sp8C, &sp88);
        if (sp8C < 0.8 && 0.8 <= sp88) {
            func_8030E878(SFX_8_BANJO_LANDING_04, randf2(0.8f, 0.9f), randi2(0x61A8, 0x6978), this->position, 100.0f, 1500.0f);
        }
        if (skeletalAnim_getLoopCount(this->unk148) > 0) {
            sp7C[0] = (f32) local->unk10[0];
            sp7C[1] = (f32) local->unk10[1];
            sp7C[2] = (f32) local->unk10[2];
            if (ml_vec3f_distance(this->position, sp7C) < 30.0f) {
                func_8038D9D0(this, 1);
            } else {
                func_8038D9D0(this, 5);
            }
        } else {

            if ((0.2 <= sp88) && (sp88 <= 0.8)) {
                temp_f12 = ((sp88 - 0.2) / 0.60000000000000009);
                this->position_x = local->unk4[0] + (local->unkA[0] - local->unk4[0])*temp_f12;
                this->position_y = local->unk4[1] + (local->unkA[1] - local->unk4[1])*temp_f12;
                this->position_z = local->unk4[2] + (local->unkA[2] - local->unk4[2])*temp_f12;

                if (local->unk1 != 0) {
                    if (sp88 <= 0.5) {
                        this->position[1] = (f32) ((f64) this->position[1] + ((sp88 / 0.5) * 70.0));
                    } else {
                        this->position[1] = (f32) ((f64) this->position[1] + ((1.0 - ((sp88 - 0.5) / 0.5)) * 70.0));
                    }
                }
                sp60[0] = (f32) (local->unkA[0] - local->unk4[0]);
                sp60[1] = (f32) (local->unkA[1] - local->unk4[1]);
                sp60[2] = (f32) (local->unkA[2] - local->unk4[2]);
                func_80258A4C(BGS_D_80390B10, this->yaw - 90.0f, sp60, &sp74, &sp70, &sp6C);
                this->yaw += sp6C * 220.0f * sp9C;
            }
        }
    }

    if (this->state == 6) {
        func_80258A4C(this->position, this->yaw - 90.0f, spB4, &sp5C, &sp58, &sp54);
        this->yaw += sp54 * 90.0f * sp9C;
        if ((-0.4 <= sp54) && (sp54 <= 0.4) && ((f64) randf() > 0.5)) {
            func_8038D9D0(this, 5);
        }
        if ((sp58 < 0.0f) && (randf() > 0.5)) {
            func_8038D9D0(this, 5);
        }
    }

    if(this->state == 7 || this->state == 8){
        if(ml_timer_update(&local->unk1C, sp9C)){
            func_8038D9D0(this, 6);
        }
    }

    if(this->state == 9){
        sp48[0] = this->position[0] - spB4[0];
        sp48[1] = this->position[1] - spB4[1];
        sp48[2] = this->position[2] - spB4[2];
        sp48[1] = 0.0f;
        ml_vec3f_set_length(sp48, 400.0f * sp9C);

        this->position[0] = this->position[0] + sp48[0];
        this->position[1] = this->position[1] + sp48[1];
        this->position[2] = this->position[2] + sp48[2];

        this->position_y += local->unk18*sp9C;
        local->unk18 -= 3000.0f*sp9C;
        if(this->position_y  < mapModel_getFloorY(this->position)){
            this->position_y  = mapModel_getFloorY(this->position);
            func_8038D9D0(this, 10);
        }
    }

    if(this->state == 10){
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            func_8038D9D0(this, 11);
        }
    }
}
