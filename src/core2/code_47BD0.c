#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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

void func_802CF83C(Actor *this);
Actor *func_802CEBFC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

extern f32 D_803765E4;

extern s32 D_8037DCBC;

/* .data */
extern ActorInfo D_80367310 = {0x217, ACTOR_34D_BEE_SWARM, 0x49E, 
    1, NULL, 
    func_802CF83C, NULL, func_802CEBFC,
    0, 0, 1.0f, 0
}; 

/* .rodata */
extern f32 D_803765E0;

/* .bss */
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

void func_802CEBA8(Actor *this){
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *)&this->local;
    this->unk100 = NULL;
    
    free(local->unk8);
    local->unk8 = NULL;
    
    assetcache_release(local->unk20);
    local->unk20 = NULL;

    D_8037DCBC = 0;
}

#ifndef NONMATCHING //requires .rodata defined
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CEBFC.s")
#else
Actor *func_802CEBFC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
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
        sp80[1] = phi_s0->unk28 - 90.0f;
        sp80[2] = 0.0f;

        sp8C[0] = this->position[0] + phi_s0->unk0[0];
        sp8C[1] = this->position[1] + phi_s0->unk0[1];
        sp8C[2] = this->position[2] + phi_s0->unk0[2];

        set_model_render_mode(2);
        func_8033A410(0xFF);
        func_803391A4(gfx, mtx, sp8C, sp80, 0.25f, NULL, phi_fp);
        local->unk5 |= func_8033A170();
        if(phi_s2 < 10){
            sp8C[1] = local->unk18 + 6.0f;
            func_8033A410(0xC0);
            set_model_render_mode(2);
            func_803391A4(gfx, mtx, sp8C, sp80, 0.1f, NULL, local->unk20);
            local->unk5 |= func_8033A170();
        }
        phi_s0++;
    }
    return this;
}
#endif

void func_802CEDE4(f32 arg0[3], f32 p_ctrl[3], f32 arg2, f32 *arg3, f32 arg4, f32 arg5){
    s32 phi_s1;

    phi_s1 = 0;
    do{
        p_ctrl[0] = randf2(-arg2, arg2);
        p_ctrl[1] = randf2(-arg2, arg2);
        p_ctrl[2] = randf2(-arg2, arg2);
        phi_s1++;
    }while(phi_s1 < 10 &&  ml_vec3f_distance(arg0, p_ctrl) < arg2);
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

void func_802CF040(Actor *this) {
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

void func_802CF174(f32 arg0[3], f32 arg1, f32 arg2) {
    f32 temp_f0;

    if (arg1 != 0.0f) {
        temp_f0 = arg2 / arg1;
        arg0[0] *= temp_f0;
        arg0[1] *= temp_f0;
        arg0[2] *= temp_f0;
    }
}

void func_802CF1C8(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3, f32 arg4, f32 *arg5, f32 arg6[3]) {
    f32 sp4C;
    f32 temp_f12;
    f32 sp3C[3];


    sp4C = time_getDelta();
    arg6[0] = arg0[0] - arg1[0];
    arg6[1] = arg0[1] - arg1[1];
    arg6[2] = arg0[2] - arg1[2];
    temp_f12 = gu_sqrtf(arg6[0]*arg6[0] + arg6[1]*arg6[1] + arg6[2]*arg6[2]);
    if (temp_f12 < (2 * arg4)) {
        func_802CF174(arg6, temp_f12, 8 * arg3);
    } else {
        func_802CF174(arg6, temp_f12, 2 * arg3);
    }
    arg1[0] += (arg2[0] * sp4C) + (arg6[0] * sp4C * sp4C);
    arg1[1] += (arg2[1] * sp4C) + (arg6[1] * sp4C * sp4C);
    arg1[2] += (arg2[2] * sp4C) + (arg6[2] * sp4C * sp4C);

    arg2[0] += arg6[0] * sp4C;
    arg2[1] += arg6[1] * sp4C;
    arg2[2] += arg6[2] * sp4C;
    temp_f12 = gu_sqrtf(arg2[0]*arg2[0] + arg2[1]*arg2[1] + arg2[2]*arg2[2]);
    if (arg3 < temp_f12) {
        func_802CF174(arg2, temp_f12, arg3);
    }
    if (arg5 != 0) {
        sp3C[0] = sp3C[1] = sp3C[2] = 0.0f;
        func_8025727C(arg2[0], arg2[1], arg2[2], sp3C[0], sp3C[1], sp3C[2], arg5, arg5 + 1);
    }
}

void func_802CF434(Actor *this) {
    ActorLocal_core2_47BD0 *local;
    Struct_core2_47BD0_0 *phi_s0;
    s32 phi_s2;
    f32 *temp_s1;
    s32 temp_s2;
    f32 sp58;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    for(phi_s2 = 0, phi_s0 = local->unk8; phi_s2 < local->unk0; phi_s2++){
        func_802CF1C8(phi_s0->unk18, phi_s0->unk0, phi_s0->unkC, phi_s0->unk24[2], 150.0f, phi_s0->unk24, &sp58);
        if (ml_vec3f_distance(phi_s0->unk0, phi_s0->unk18) < 50.0f) {
            func_802CEEA4(this, phi_s0);
        }
        phi_s0++;
    }
}

void func_802CF518(Actor *this) {
    if( func_803292E0(this) 
        && func_80329530(this, 900) 
        && !func_8028EE84() 
        && player_getTransformation() != TRANSFORM_6_BEE
    ) {
        func_80328A84(this, 3);
    }
}

void func_802CF57C(Actor *this) {
    ActorLocal_core2_47BD0 *local;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    if (!func_803292E0(this) || !func_80329530(this, 900) || func_8028EE84()) {
        func_80328A84(this, 5);
        func_802CEF54(this, local->unkC, 100.0f);
    }
}

bool func_802CF5E4(Actor *this){
    ActorLocal_core2_47BD0 *local;
    ActorMarker *other;
    bool out = 1;

    local = (ActorLocal_core2_47BD0 *) &this->local;
    out = (this->unk100 != NULL) ? out = local->unk24 != this->unk100->unk5C
        : 1;
    return out;
}

void func_802CF610(Actor *this, ParticleEmitter *p_ctrl, f32 position[3]) {
    func_8030E6A4(SFX_66_BIRD_AUUGHH, randf2(1.75f, D_803765E4), 15000);
    // func_8030E6A4(SFX_66_BIRD_AUUGHH, randf2(1.75f, 1.85f), 15000);
    particleEmitter_setPosition(p_ctrl, position);
    func_802EFA70(p_ctrl, 2);
    func_802EF9F8(p_ctrl, 0.5f);
    func_802EFA18(p_ctrl, 3);
    func_802EFA20(p_ctrl, 0.8f, 1.0f);
    func_802EF9EC(p_ctrl, 0x1F, 10000);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.01f);
    func_802EFEC0(p_ctrl, 2.0f, 2.5f);
    func_802EFA5C(p_ctrl, 0.0f, 0.65f);
    particleEmitter_setParticleAccelerationRange(p_ctrl, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    particleEmitter_setModel(p_ctrl,this->marker->modelId);
    func_802EFB70(p_ctrl, 0.25f, 0.25f);
    func_802EFE24(p_ctrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(p_ctrl, -300.0f, 750.0f, -300.0f, 300.0f, 900.0f, 300.0f);
    particleEmitter_emitN(p_ctrl, 1);
}

void func_802CF7CC(Actor *this) {
    if (D_8037DCBC == 0) {
        this->unk44_31 = func_8030D90C();
        func_8030DA80(this->unk44_31, 0x3FA);
        func_8030DD14(this->unk44_31, 2);
        func_8030DD90(this->unk44_31, 2);
        D_8037DCBC = 1;
    }
}

#ifndef NONMATCHING
void func_802CF83C(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47BD0/func_802CF83C.s")
#else
extern f64 D_803765E8;
extern f64 D_80376620;
extern f64 D_80376628;
extern f64 D_80376630;
extern s32 D_8037DCBC;

void func_802CF83C(Actor *this) {
    f32 spB4[3];
    f32 spB0;
    f32 spAC;
    f32 spA0[3];
    f32 sp94[3];
    f32 sp88[3];
    f32 sp7C[3];
    s32 sp78;
    f32 *sp64;
    f32 *sp44;
    f32 *sp40;
    Actor *beehive;
    ActorMarker *temp_v0_3;
    f32 *temp_a0;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f8;
    f64 temp_f2;
    s16 temp_t7;
    u32 temp_t0;
    u32 temp_t1;
    u32 temp_t2;
    u32 temp_t3;
    u8 temp_a0_2;
    ActorLocal_core2_47BD0 *local;
    u32 phi_a1;
    f64 phi_f2;
    f64 phi_f0;

    local = (ActorLocal_core2_47BD0 *)&this->local;
    spAC = time_getDelta();
    sp78 = 0;
    if (!this->initialized) {
        this->initialized = TRUE;
        beehive = func_80326D68(this->position, ACTOR_12_BEEHIVE, -1, &spB0);
        if (beehive != NULL) {
            this->unk100 = beehive->marker;
        } else {
            this->unk100 = NULL;
        }
        if (spB0 > 500.0f) {
            this->unk100 = NULL;
        }
        sp78 = 1;
        local->unk18 = this->position[1];
        local->unkC[0] = ((this->unk100) ? beehive->position : this->position)[0];\
        local->unkC[1] = ((this->unk100) ? beehive->position : this->position)[1];\
        local->unkC[2] = ((this->unk100) ? beehive->position : this->position)[2];

        local->unkC[1] += 250.0f;
        local->unk0 = this->unkF4_8;
        this->position[0] = local->unkC[0];
        this->position[1] = local->unkC[1];
        this->position[2] = local->unkC[2];
        sp94[0] = this->position[0]; sp94[1] = this->position[1]; sp94[2] = this->position[2];
        sp94[1] += 50.0f;
        sp88[0] = this->position[0]; sp88[1] = this->position[1]; sp88[2] = this->position[2];
        sp88[1] -= 500.0f;
        if (func_80309B48(sp94, sp88, sp7C, 0x5E0000)) {
            local->unk18 = sp88[1];
        }
    }

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        func_803300D8(this->marker, func_802CEBA8);
        actor_collisionOff(this);
        local->unk20 = assetcache_get(0x3BF);
        if (sp78 == 0) {
            beehive = func_80326D68(this->position, ACTOR_12_BEEHIVE, -1, &spB0);
            if (beehive != NULL) {
                this->unk100 = beehive->marker;
            } else {
                this->unk100 = NULL;
            }
            if (spB0 > 500.0f) {
                this->unk100 = NULL;
            }
        }
        temp_v0_3 = this->unk100;
        if (temp_v0_3 != NULL) {
            local->unk24 = temp_v0_3->unk5C;
        } else {
            local->unk24 = NULL;
        }
        local->unk5 = 1;
        if (this->unk100 != NULL) {
            func_80320004(BKPROG_D_BEEHIVE_TEXT, TRUE);
        }
        phi_a1 = 2U;
        if (this->unk100 != NULL) {
            phi_a1 = 1U;
        }
        func_80328A84(this, phi_a1);
        this->unk60 = 0.0f;
        func_802CF040(this);
        this->unk38_0 = func_803203FC(1) | func_803203FC(0x1F);
    }

    if (actor_playerIsWithinDist(this, 0xFA0)) {
        if (!actor_playerIsWithinDist(this, 0x5DC) == 0) {
            if (this->unk44_31 != 0) {
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
block_40:
        sp94[0] = this->position[0];
        sp94[1] = this->position[1];
        sp94[2] = this->position[2];
        sp88[0] = (this->velocity[0] * spAC) + this->position[0];
        sp88[1] = (this->velocity[1] * spAC) + this->position[1];
        sp88[2] = (this->velocity[2] * spAC) + this->position[2];
        if (this->state != 7) {
            if (func_80309DBC(sp94, sp88, 75.0f, sp7C, 3, 0)) {
                ml_vec3f_normalize(&sp7C);
                temp_f0 = (this->velocity[0]*sp7C[0] + this->velocity[1]*sp7C[1] + this->velocity[2]*sp7C[2]) * -1.5;
                this->velocity[0] += (sp7C[0] * temp_f0);
                this->velocity[1] += (sp7C[1] * temp_f0);
                this->velocity[2] += (sp7C[2] * temp_f0);
                this->unk1C[0] = sp7C[0] * D_803765E8 + this->position[0];
                this->unk1C[1] = sp7C[1] * D_803765E8 + this->position[1];
                this->unk1C[2] = sp7C[2] * D_803765E8 + this->position[2];
                if (this->state != 6) {
                    local->unk6 = this->state;
                    func_80328A84(this, 6);
                }
            }
            func_802CF1C8(this->unk1C, this->position, this->velocity, this->unk28, 100.0f, 0, &spA0);
        }
        if (map_get() == MAP_78_GL_RBB_AND_MMM_PUZZLE) {
            if (this->unk38_31++ == 0x1E) {
                this->unk38_31 = 0;
                sp88[0] = this->position[0];
                sp88[1] = this->position[1];
                sp88[2] = this->position[2];
                sp94[1] += 1000.0f;
                sp88[1] -= 1000.0f;
                if (func_80309B48(sp94, sp88, sp7C, 0xF800FF0F)) {
                    local->unk1C = sp88[1];
                } else {
                    local->unk1C = -16000.0f;
                }
                if ((this->position[1] - 100.0f) < local->unk1C) {
                    if (this->state != 7) {
                        local->unk7 = this->state;
                        local->unk4 = local->unk0;
                        func_80328A84(this, 7);
                    }
                }
            }
        }
        func_8028E9C4(5, &spB4);
        switch(this->state){
            case 1:
                if( !func_8031FF1C(0x8F) 
                    && func_803296B8(this, 0xFA, 0x12C) 
                    && ((func_8028ECAC() == 0) || (func_8028ECAC() == 8)) 
                    && (player_getTransformation() == TRANSFORM_1_BANJO) 
                    && func_80311480(0xDA6, 0, NULL, NULL, NULL, NULL) 
                ) {
                    func_80320004(0x8F, TRUE);
                }
                if (func_802CF5E4(this)) {
                    func_80328A84(this, 2);
                }
                if (ml_vec3f_distance(this->position, this->unk1C) < 50.0f) {
                    func_802CEF54(this, local->unkC, 100.0f);
                }
                break;
        }
        if (local->unk5) {
            func_802CF434(this);
        }
        local->unk5 = FALSE;

        if( (local->unk0 > 0) 
            && func_80329530(this, 0x5DC)  && !this->unk38_0
        ) {
            if (!this->unk44_31) {
                func_802CF7CC(this);
            }
            if (this->unk44_31) {
                if ((this->state == 3) || (this->state == 4)) {
                    phi_f2 = 0.0;
                } else {
                    phi_f2 = D_80376620;
                }
                if ((this->state == 3) || (this->state == 4)) {
                    phi_f0 = D_80376628;
                } else {
                    phi_f0 = D_80376630;
                }
                func_8030DBFC(this->unk44_31, phi_f2, phi_f0, 0.05f);
                func_8030DEB4(this->unk44_31, 500.0f, 1500.0f);
                func_8030DF68(this->unk44_31, this->position);
                func_8030E2C4(this->unk44_31);
                func_8030DABC(this->unk44_31, ((gu_sqrtf(this->velocity[0]*this->velocity[0] + this->velocity[1]*this->velocity[1] + this->velocity[2]*this->velocity[2])/ this->unk28) * 8000.0f) + 2000.0f);
            }
        }
    }
}
#endif
