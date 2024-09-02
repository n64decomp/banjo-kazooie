#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_C9E70.h"

extern void func_8030DBFC(u32, f32, f32, f32);
extern bool func_80309DBC(f32[3], f32[3], f32, f32 sp54[3], s32, s32);
extern void fileProgressFlag_set(s32, bool);
extern void sfxsource_set_fade_distances(u8, f32, f32);
extern void sfxsource_set_position(u8, f32[3]);
extern void func_8030E2C4(u8);
extern void sfxsource_setSampleRate(u8, s32);
extern void ml_vec3f_normalize(f32[3]);

typedef struct{
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
}Struct_core2_47BD0_0;

typedef struct{
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    Struct_core2_47BD0_0 *unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
    BKModelBin *unk20;
    s32 unk24;
}ActorLocal_core2_47BD0;

/* .h */
void chBeeSwarm_update(Actor *this);
Actor *chBeeSwarm_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);


/* .data */
ActorInfo D_80367310 = {
    MARKER_217_BEE_SWARM, ACTOR_34D_BEE_SWARM, ASSET_49E_SPRITE_BEE_SWARM, 
    1, NULL, 
    chBeeSwarm_update, NULL, chBeeSwarm_draw,
    0, 0, 1.0f, 0
}; 

extern s32 D_8037DCBC;

/* .code */
void func_802CEB60(Actor *this){
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *)&this->local;
    if(this->unk16C_4){
        if(local->unk8 != NULL){
            local->unk8 = (Struct_core2_47BD0_0 *)defrag(local->unk8);
        }
    }
}

void chBeeSwarm_802CEBA8(Actor *this){
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *)&this->local;
    this->unk100 = NULL;
    
    free(local->unk8);
    local->unk8 = NULL;
    
    assetcache_release(local->unk20);
    local->unk20 = NULL;

    D_8037DCBC = 0;
}

Actor *chBeeSwarm_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_core2_47BD0 *local;
    BKModelBin *phi_fp;
    s32 phi_s2;
    f32 sp8C[3];
    f32 sp80[3];
    Struct_core2_47BD0_0 *phi_s0;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_47BD0 *)&this->local;
    phi_fp = func_80330B1C(marker);
    for(phi_s2 = 0, phi_s0 = local->unk8; phi_s2 < local->unk0; phi_s2++){
        sp80[0] = 0.0f;
        sp80[1] = phi_s0->unk24[1] - 90.0f;
        sp80[2] = 0.0f;

        sp8C[0] = this->position[0] + phi_s0->unk0[0];
        sp8C[1] = this->position[1] + phi_s0->unk0[1];
        sp8C[2] = this->position[2] + phi_s0->unk0[2];

        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        modelRender_setAlpha(0xFF);
        modelRender_draw(gfx, mtx, sp8C, sp80, 0.25f, NULL, phi_fp);
        local->unk5 |= func_8033A170();
        if(phi_s2 < 10){
            sp8C[1] = local->unk18 + 6.0f;
            modelRender_setAlpha(0xC0);
            modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
            modelRender_draw(gfx, mtx, sp8C, sp80, 0.1f, NULL, local->unk20);
            local->unk5 |= func_8033A170();
        }
        phi_s0++;
    }
    return this;
}

void func_802CEDE4(f32 target_position[3], f32 p_ctrl[3], f32 distance, f32 *arg3, f32 arg4, f32 arg5){
    s32 phi_s1;

    phi_s1 = 0;
    do{
        p_ctrl[0] = randf2(-distance, distance);
        p_ctrl[1] = randf2(-distance, distance);
        p_ctrl[2] = randf2(-distance, distance);
        phi_s1++;
    }while(phi_s1 < 10 &&  ml_distance_vec3f(target_position, p_ctrl) < distance);
    *arg3 =  randf2(arg4, arg5);
}

void func_802CEEA4(Actor *this, Struct_core2_47BD0_0 *arg1) {
    u32 temp_t6;
    s32 phi_t0;
    s32 phi_t1;
    s32 phi_v0;
    s32 phi_v0_2;

    phi_t0 = (this->state == 4) ? 50
           : (this->state == 3) ? 100 
           : 150;
    phi_t1 = (this->state == 1) ? 100 : 200;
    phi_v0 = (this->state == 1) ? 200 : 400;
    func_802CEDE4(arg1->unk0, arg1->unk18, (f32) phi_t0, &arg1->unk24[2], (f32) phi_t1, (f32) phi_v0);
}


void func_802CEF54(Actor *this, f32 arg1[3], f32 arg2){
    f32 sp34[3];
    s32 phi_v1;
    s32 phi_v0;

    sp34[0] = this->position[0] - arg1[0];
    sp34[1] = this->position[1] - arg1[1];
    sp34[2] = this->position[2] - arg1[2];

    phi_v1 = (this->state == 5) ? 200 : 50;
    phi_v0 = (this->state == 5) ? 200 : 100;
    func_802CEDE4(sp34, this->unk1C, arg2, &this->unk28, (f32) phi_v1, (f32) phi_v0);
    this->unk1C[0] = this->unk1C[0] + arg1[0];
    this->unk1C[1] = this->unk1C[1] + arg1[1];
    this->unk1C[2] = this->unk1C[2] + arg1[2];
}

void chBeeSwarm_802CF040(Actor *this) {
    Struct_core2_47BD0_0 *phi_s0;
    s32 phi_s1;
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    local->unk8 = (Struct_core2_47BD0_0 *) malloc(local->unk0 * sizeof(Struct_core2_47BD0_0));
    
    for(phi_s1 = 0, phi_s0 = local->unk8; phi_s1 < local->unk0; phi_s1++){
        phi_s0->unk0[0] = randf2(-150.0f, 150.0f);
        phi_s0->unk0[1] = randf2(-150.0f, 150.0f);
        phi_s0->unk0[2] = randf2(-150.0f, 150.0f);
        phi_s0->unkC[0] = phi_s0->unkC[1] = phi_s0->unkC[2] = 0.0f;
        phi_s0->unk24[0] = phi_s0->unk24[1] = phi_s0->unk24[2] = 0.0f;
        func_802CEEA4(this, phi_s0);
        phi_s0++;
    }
    this->velocity[0] = 0.0f;
    this->velocity[1] = 1.0f;
    this->velocity[2] = 0.0f;
    func_802CEF54(this, local->unkC, 100.0f);
}

void chBeeSwarm_802CF174(f32 arg0[3], f32 arg1, f32 arg2) {
    f32 temp_f0;

    if (arg1 != 0.0f) {
        temp_f0 = arg2 / arg1;
        arg0[0] *= temp_f0;
        arg0[1] *= temp_f0;
        arg0[2] *= temp_f0;
    }
}

void chBeeSwarm_802CF1C8(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3, f32 arg4, f32 *arg5, f32 arg6[3]) {
    f32 sp4C;
    f32 temp_f12;
    f32 sp3C[3];


    sp4C = time_getDelta();
    arg6[0] = arg0[0] - arg1[0];
    arg6[1] = arg0[1] - arg1[1];
    arg6[2] = arg0[2] - arg1[2];
    temp_f12 = gu_sqrtf(arg6[0]*arg6[0] + arg6[1]*arg6[1] + arg6[2]*arg6[2]);
    if (temp_f12 < (2 * arg4)) {
        chBeeSwarm_802CF174(arg6, temp_f12, 8 * arg3);
    } else {
        chBeeSwarm_802CF174(arg6, temp_f12, 2 * arg3);
    }
    arg1[0] += (arg2[0] * sp4C) + (arg6[0] * sp4C * sp4C);
    arg1[1] += (arg2[1] * sp4C) + (arg6[1] * sp4C * sp4C);
    arg1[2] += (arg2[2] * sp4C) + (arg6[2] * sp4C * sp4C);

    arg2[0] += arg6[0] * sp4C;
    arg2[1] += arg6[1] * sp4C;
    arg2[2] += arg6[2] * sp4C;
    temp_f12 = gu_sqrtf(arg2[0]*arg2[0] + arg2[1]*arg2[1] + arg2[2]*arg2[2]);
    if (arg3 < temp_f12) {
        chBeeSwarm_802CF174(arg2, temp_f12, arg3);
    }
    if (arg5 != 0) {
        sp3C[0] = sp3C[1] = sp3C[2] = 0.0f;
        func_8025727C(arg2[0], arg2[1], arg2[2], sp3C[0], sp3C[1], sp3C[2], arg5, arg5 + 1);
    }
}

void chBeeSwarm_802CF434(Actor *this) {
    ActorLocal_core2_47BD0 *local;
    Struct_core2_47BD0_0 *phi_s0;
    s32 phi_s2;
    f32 *temp_s1;
    s32 temp_s2;
    f32 sp58;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    for(phi_s2 = 0, phi_s0 = local->unk8; phi_s2 < local->unk0; phi_s2++){
        chBeeSwarm_802CF1C8(phi_s0->unk18, phi_s0->unk0, phi_s0->unkC, phi_s0->unk24[2], 150.0f, phi_s0->unk24, &sp58);
        if (ml_distance_vec3f(phi_s0->unk0, phi_s0->unk18) < 50.0f) {
            func_802CEEA4(this, phi_s0);
        }
        phi_s0++;
    }
}

void chBeeSwarm_802CF518(Actor *this) {
    if( func_803292E0(this) 
        && func_80329530(this, 900) 
        && player_getWaterState() == BSWATERGROUP_0_NONE 
        && player_getTransformation() != TRANSFORM_6_BEE
    ) {
        subaddie_set_state(this, 3);
    }
}

void chBeeSwarm_802CF57C(Actor *this) {
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    if (!func_803292E0(this) || !func_80329530(this, 900) || player_getWaterState() != BSWATERGROUP_0_NONE) {
        subaddie_set_state(this, 5);
        func_802CEF54(this, local->unkC, 100.0f);
    }
}

bool chBeeSwarm_802CF5E4(Actor *this){
    ActorLocal_core2_47BD0 *local;
    ActorMarker *other;
    bool out = 1;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    out = (this->unk100 != NULL) ? out = local->unk24 != this->unk100->unk5C
        : 1;
    return out;
}

void chBeeSwarm_802CF610(Actor *this, ParticleEmitter *p_ctrl, f32 position[3]) {
    func_8030E6A4(SFX_66_BIRD_AUUGHH, randf2(1.75f, 1.85f), 15000);
    particleEmitter_setPosition(p_ctrl, position);
    particleEmitter_setDrawMode(p_ctrl, 2);
    func_802EF9F8(p_ctrl, 0.5f);
    func_802EFA18(p_ctrl, 3);
    func_802EFA20(p_ctrl, 0.8f, 1.0f);
    particleEmitter_setSfx(p_ctrl, SFX_1F_HITTING_AN_ENEMY_3, 10000);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 2.0f, 2.5f);
    particleEmitter_setFade(p_ctrl, 0.0f, 0.65f);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl,this->marker->modelId);
    func_802EFB70(p_ctrl, 0.25f, 0.25f);
    particleEmitter_setAngularVelocityRange(p_ctrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -300.0f, 750.0f, -300.0f, 300.0f, 900.0f, 300.0f);
    particleEmitter_emitN(p_ctrl, 1);
}

void chBeeSwarm_802CF7CC(Actor *this) {
    if (D_8037DCBC == 0) {
        this->unk44_31 = func_8030D90C();
        sfxsource_setSfxId(this->unk44_31, SFX_3FA_HONEYCOMB_TALKING);
        func_8030DD14(this->unk44_31, 2);
        func_8030DD90(this->unk44_31, 2);
        D_8037DCBC = 1;
    }
}

void chBeeSwarm_update(Actor *this) {
    Actor *beehive;
    ActorLocal_core2_47BD0 *local = (ActorLocal_core2_47BD0 *)&this->local;
    f32 spB4[3];
    f32 distance_to_home;
    f32 dt;
    f32 spA0[3];
    f32 position[3];
    f32 next_position[3];
    f32 sp7C[3];
    s32 sp78;
    f32 temp_f0;
    f32 sp68[3];
    
    dt = time_getDelta();
    sp78 = 0;
    if (!this->initialized) {
        this->initialized = TRUE;
        beehive = actorArray_findClosestActorFromActorId(this->position, ACTOR_12_BEEHIVE, -1, &distance_to_home);
        this->unk100 = (beehive != NULL) ? beehive->marker : NULL;
        if(500.0f < distance_to_home){
            this->unk100 = NULL;
        }
        sp78 = 1;
        local->unk18 = (f32) this->position[1];
        
        local->unkC[0] = ((this->unk100) ? beehive->position : this->position)[0];
        local->unkC[1] = ((this->unk100) ? beehive->position : this->position)[1];
        local->unkC[2] = ((this->unk100) ? beehive->position : this->position)[2];

        local->unkC[1] += 250.0f;
        local->unk0 = this->unkF4_8;
        this->position[0] = local->unkC[0];
        this->position[1] = local->unkC[1];
        this->position[2] = local->unkC[2];
        
        position[0] = this->position[0];
        position[1] = this->position[1];
        position[2] = this->position[2];
        
        next_position[0] = this->position[0];
        next_position[1] = this->position[1];
        next_position[2] = this->position[2];
        
        position[1] += 50.0f;
        next_position[1] -= 500.0f;
        if (func_80309B48(position, next_position, sp7C, 0x5E0000)) {
            local->unk18 = next_position[1];
        }
    }
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        marker_setFreeMethod(this->marker, chBeeSwarm_802CEBA8);
        actor_collisionOff(this);
        local->unk20 = assetcache_get(ASSET_3BF_MODEL_PLAYER_SHADOW);
        if (sp78 == 0) {
            beehive = actorArray_findClosestActorFromActorId(this->position, ACTOR_12_BEEHIVE, -1, &distance_to_home);
            if (beehive != NULL) {
                this->unk100 = beehive->marker;
            } else {
                this->unk100 = NULL;
            }
            if (distance_to_home > 500.0f) {
                this->unk100 = NULL;
            }
        }
         local->unk24 = (this->unk100 != NULL) ? this->unk100->unk5C : 0;
        local->unk5 = 1;
        if (this->unk100 != NULL) {
            fileProgressFlag_set(FILEPROG_D_BEEHIVE_TEXT, TRUE);
        }
        subaddie_set_state(this, (this->unk100 != NULL) ? 1 : 2);
        this->unk60 = 0.0f;
        chBeeSwarm_802CF040(this);
        this->unk38_0 = func_803203FC(1) | func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE);
    }

    if (!subaddie_playerIsWithinSphere(this, 0xFA0)) 
        return;
    if (!subaddie_playerIsWithinSphere(this, 0x5DC)) {
        if ((u8)this->unk44_31 != 0) {
            func_8030DA44(this->unk44_31);
            this->unk44_31 = 0;
            D_8037DCBC = 0;
        }
    }
    if (map_get() == MAP_27_FP_FREEZEEZY_PEAK) {
        if (func_8038BFA0()) {
            this->unk58_0 = FALSE;
            return;
        }
        this->unk58_0 = TRUE;
    }
    position[0] = this->position[0];
    position[1] = this->position[1];
    position[2] = this->position[2];
    next_position[0] = this->position[0] + (this->velocity[0] * dt);
    next_position[1] = this->position[1] + (this->velocity[1] * dt);
    next_position[2] = this->position[2] + (this->velocity[2] * dt);
    if (this->state != 7) {
        if (func_80309DBC(position, next_position, 75.0f, sp7C, 3, 0)) {
            ml_vec3f_normalize(sp7C);
            temp_f0 = (this->velocity[0]*sp7C[0] + this->velocity[1]*sp7C[1] + this->velocity[2]*sp7C[2]) * -1.5;
            this->velocity[0] = this->velocity[0] + (sp7C[0] * temp_f0);
            this->velocity[1] = this->velocity[1] + (sp7C[1] * temp_f0);
            this->velocity[2] = this->velocity[2] + (sp7C[2] * temp_f0);
            this->unk1C[0] = this->position[0] + sp7C[0] * 37.5;
            this->unk1C[1] = this->position[1] + sp7C[1] * 37.5;
            this->unk1C[2] = this->position[2] + sp7C[2] * 37.5;
            if (this->state != 6) {
                local->unk6 = this->state;
                subaddie_set_state(this, 6);
            }
        }
        chBeeSwarm_802CF1C8(this->unk1C, this->position, this->velocity, this->unk28, 100.0f, 0, &spA0);
    }
    if (map_get() == MAP_78_GL_RBB_AND_MMM_PUZZLE) {
        if (this->unk38_31++ == 0x1E) {
            this->unk38_31 = 0;
            next_position[0] = this->position[0];
            next_position[1] = this->position[1];
            next_position[2] = this->position[2];
            position[1] += 1000.0f;
            next_position[1] -= 1000.0f;
            if (func_80309B48(position, next_position, sp7C, 0xF800FF0F)) {
                local->unk1C = next_position[1];
            } else {
                local->unk1C = -16000.0f;
            }
            if ((this->position[1] - 100.0f) < local->unk1C) {
                if (this->state != 7) {
                    local->unk7 = this->state;
                    local->unk4 = local->unk0;
                    subaddie_set_state(this, 7);
                }
            }
        }
    }
    func_8028E9C4(5, spB4);
    switch (this->state) {
    case 1:
        if (!fileProgressFlag_get(FILEPROG_8F_MET_BEE_INFESTED_BEEHIVE) && subaddie_playerIsWithinCylinder(this, 250, 300) 
            && ((func_8028ECAC() == 0) || (func_8028ECAC() == BSGROUP_8_TROT)) 
            && (player_getTransformation() == TRANSFORM_1_BANJO) 
            && (func_80311480(0xDA6, 0, NULL, NULL, NULL, NULL) != 0)
        ) {
            fileProgressFlag_set(FILEPROG_8F_MET_BEE_INFESTED_BEEHIVE, TRUE);
        }
        if (chBeeSwarm_802CF5E4(this)) {
            subaddie_set_state(this, 2U);
        }
        if (ml_distance_vec3f(this->position, this->unk1C) < 50.0f) {
            func_802CEF54(this, local->unkC, 100.0f);
        }
        break;
    case 2:
        if (ml_distance_vec3f(this->position, this->unk1C) < 50.0f) {
            func_802CEF54(this, local->unkC, 100.0f);
        }
        chBeeSwarm_802CF518(this);
        break;
    case 3:
        this->unk1C[0] = spB4[0];
        this->unk1C[1] = spB4[1];
        this->unk1C[2] = spB4[2];
        this->unk1C[1] += 50.0f;
        this->unk28 = 400.0f;
        if (ml_distance_vec3f(this->position, this->unk1C) < 100.0f) {
            func_802CEF54(this, spB4, 50.0f);
            subaddie_set_state(this, 4);
        }
        chBeeSwarm_802CF57C(this);
        break;
    case 4:
        spB4[1] += 50.0f;
        this->unk60 += dt;
        if ((this->unk60 - 0.5 > 0.0) && (local->unk0 > 0) && (func_8028ECAC() != 3)) {
            func_8028F504(0xD);
            this->unk60 -= 0.5;
        }
        if ((this->unk60 > 0.2) && (func_8028ECAC() == 3)) {
            if (local->unk0-- > 0) {
                sp68[0] = local->unk8[local->unk0].unk0[0] + this->position[0];
                sp68[1] = local->unk8[local->unk0].unk0[1] + this->position[1];
                sp68[2] = local->unk8[local->unk0].unk0[2] + this->position[2];
                chBeeSwarm_802CF610(this, partEmitMgr_newEmitter(1), sp68);
                this->unk60 -= 0.2;
            }
        }
        if (local->unk0 == 0) {
            marker_despawn(this->marker);
        }
        if (ml_distance_vec3f(this->position, this->unk1C) < 50.0f) {
            func_802CEF54(this, (s32 *) spB4, 50.0f);
        }
        if (ml_distance_vec3f(this->position, spB4) > 100.0f) {
            subaddie_set_state(this, 3);
        }
        chBeeSwarm_802CF57C(this);
        break;
    case 5:
        if (ml_distance_vec3f(this->position, this->unk1C) < 50.0f) {
            subaddie_set_state(this, 2);
        }
        chBeeSwarm_802CF518(this);
        break;
    case 6:
        if (ml_distance_vec3f(this->position, this->unk1C) < 50.0f) {
            subaddie_set_state(this, local->unk6);
        }
        break;
    case 7:
        if (this->position[1] - 100.0f < local->unk1C) {
            if (local->unk0 > 0) {
                local->unk0--;
            }
        }
        if (local->unk1C < this->position[1] - 100.0f) {
            if (local->unk0 < local->unk4) {
                local->unk0++;
            } else {
                subaddie_set_state(this, local->unk7);
            }
        }
        break;
    }
    if (local->unk5) {
        chBeeSwarm_802CF434(this);
    }
    local->unk5 = 0;
    if ((local->unk0 > 0) && func_80329530(this, 1500) && !this->unk38_0) {
        if (this->unk44_31 == 0) {
            chBeeSwarm_802CF7CC(this);
        }
        if (this->unk44_31 != 0) {
            func_8030DBFC(this->unk44_31, 
                ((this->state == 3) || (this->state == 4)) ? 1.0 : 0.8, 
                ((this->state == 3) || (this->state == 4)) ? 1.1 : 0.9, 
                0.05f
            );
            sfxsource_set_fade_distances(this->unk44_31, 500.0f, 1500.0f);
            sfxsource_set_position(this->unk44_31, this->position);
            func_8030E2C4(this->unk44_31);
            sfxsource_setSampleRate(this->unk44_31, (s32)(((gu_sqrtf(this->velocity[0]*this->velocity[0] + this->velocity[1]*this->velocity[1] + this->velocity[2]*this->velocity[2])/ this->unk28) * 8000.0f) + 2000.0f));
        }
    }
}
