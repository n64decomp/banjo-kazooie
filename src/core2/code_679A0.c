#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_8024DB50(f32 (*)[3], f32);
extern s32 spriteGetFrameCount(BKSprite *);
extern void func_80344720(s32 SpriteGfx, s32 frame, s32, f32[3], f32[3], f32[3], Gfx **, Mtx **);
extern void func_80344424(s32 SpriteGfx, s32 frame, s32, f32[3], f32[3], f32, Gfx **, Mtx **);


void func_802EF9E4(ParticleEmitter *this, s32 arg1);
void func_802EF9EC(ParticleEmitter *this, s32 arg1, s32 arg2);
void func_802EFA04(ParticleEmitter *, f32);
void particleEmitter_setParticleCallback(ParticleEmitter *this, void (*arg1)(ParticleEmitter *this, f32 pos[3]));
void func_802EFA20(ParticleEmitter *, f32, f32);
void func_802EFA34(ParticleEmitter *, f32);
void func_802EFA40(ParticleEmitter *, f32 (*)[3]);
void func_802EFA78(ParticleEmitter *this, s32 arg1);
void func_802EFF5C(ParticleEmitter *, f32, f32, f32);
void func_802EFF7C(ParticleEmitter *, f32, f32, f32);
void func_802EFF9C(ParticleEmitter *, f32);
void partEmitList_remove(ParticleEmitter *this);


Gfx D_80368940[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
    gsSPEndDisplayList()
};

Gfx D_80368978[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList()
};

ParticleEmitter **D_803689B0 = NULL; //particlePtrArrayPtr
s32 D_803689B4 = 0;                  //particlePtrArraySize
s32 D_803689B8[3] = {0xAF, 0x87, 0};

/* .bss */
f32 D_80380920;
u8 D_80380924;

/* .code */
void func_802EE930(ParticleEmitter *this){
    func_8033B388(&this->sprite_1C, &this->unk34);
    if(this->model_20)
        func_8033BD20(&this->model_20);
}

int func_802EE974(ParticleEmitter *this, f32 (*arg1)[3], f32 (*arg2)[3], f32 (*arg3)[3], s32 arg4){
    if(-100000.0 == this->unk74 && 100000.0 == this->unk78){
        return func_80309B48(arg1, arg2, arg3, 0);
    }

    if(100000.0 != this->unk78 && this->unk78 < (*arg2)[1]){
        (*arg2)[1] = this->unk78;
        (*arg3)[2] = 0.0f;
        (*arg3)[0] = 0.0f;
        (*arg3)[1] = -1.0f;
        return 1;
    }
    
    if(this->unk74 != -100000.0  && (*arg2)[1] < this->unk74){
        (*arg2)[1] = this->unk74;
        (*arg3)[2] = 0.0f;
        (*arg3)[0] = 0.0f;
        (*arg3)[1] = 1.0f;
        return 1;
    }
    
    return 0;
}

void __particleEmitter_initParticle(ParticleEmitter *this, Particle *particle){
    particle->unk0[0] = randf2(this->particleAccerationRange_4C_min_x, this->particleAccerationRange_4C_max_x);
    particle->unk0[1] = randf2(this->particleAccerationRange_4C_min_y, this->particleAccerationRange_4C_max_y);
    particle->unk0[2] = randf2(this->particleAccerationRange_4C_min_z, this->particleAccerationRange_4C_max_z);
    particle->unk5C = this->unk64;
    
    particle->unkC = (0.0f == this->unk10) ? 1.0f : 0; 
    particle->frame_10 = randf2((f32)this->particleStartingFrameRange_84_min, (f32)this->particleStartingFrameRange_84_max);
    particle->framerate_14 = randf2(this->particleFramerateRange_8C_min, this->particleFramerateRange_8C_max);

    particle->position_18[0] = this->postion_28[0];
    particle->position_18[1] = this->postion_28[1];
    particle->position_18[2] = this->postion_28[2];

    particle->position_18[0] = particle->position_18[0] + randf2(this->particleSpawnPositionRange_94_min_x, this->particleSpawnPositionRange_94_max_x);
    particle->position_18[1] = particle->position_18[1] + randf2(this->particleSpawnPositionRange_94_min_y, this->particleSpawnPositionRange_94_max_y);
    particle->position_18[2] = particle->position_18[2] + randf2(this->particleSpawnPositionRange_94_min_z, this->particleSpawnPositionRange_94_max_z);

    particle->initialSize_34 = particle->size_30 = randf2(this->particleStartingScaleRange_AC_min, this->particleStartingScaleRange_AC_max);
    if(0.0f == this->particleFinalScaleRange_B4_min && 0.0f == this->particleFinalScaleRange_B4_max)
        particle->finalSizeDiff = 0.0f;
    else
        particle->finalSizeDiff = randf2(this->particleFinalScaleRange_B4_min, this->particleFinalScaleRange_B4_max)- particle->initialSize_34;

    particle->unk24[2] = 0.0f;
    particle->unk24[1] = 0.0f;
    particle->unk24[0] = 0.0f;

    particle->unk3C[0] = randf2(this->unkBC[0], this->unkC8[0]);
    particle->unk3C[1] = randf2(this->unkBC[1], this->unkC8[1]);
    particle->unk3C[2] = randf2(this->unkBC[2], this->unkC8[2]);
    
    particle->age_48 = 0.0f;
    particle->lifetime_4C = randf2(this->unkDC[0], this->unkDC[1]) + 0.001;
    if(!this->sphericalParticleVelocity_48){
        particle->velocity_50[0] = randf2(this->particleVelocityRange_E4.cartisian_min_x, this->particleVelocityRange_E4.cartisian_max_x);
        particle->velocity_50[1] = randf2(this->particleVelocityRange_E4.cartisian_min_y, this->particleVelocityRange_E4.cartisian_max_y);
        particle->velocity_50[2] = randf2(this->particleVelocityRange_E4.cartisian_min_z, this->particleVelocityRange_E4.cartisian_max_z);
    }
    else{
        func_80256E24(particle->velocity_50, 
            mlNormalizeAngle(randf2(this->particleVelocityRange_E4.spherical.pitch_min, this->particleVelocityRange_E4.spherical.pitch_max)),
            mlNormalizeAngle(randf2(this->particleVelocityRange_E4.spherical.yaw_min, this->particleVelocityRange_E4.spherical.yaw_max)),
            0.0f,
            0.0f,
            randf2(this->particleVelocityRange_E4.spherical.radius_min, this->particleVelocityRange_E4.spherical.radius_max)
        );
    }
}

void func_802EED1C(ParticleEmitter *this, f32 arg1, f32 arg2[3]){
    int i;
    f32 tmp_f22;
    f32 tmp_f0;

    tmp_f22 = this->unk108*0.5;
    for(i = 0; i < 3; i++){
        if(this->unk118[i] != 0.0f){
            tmp_f0 = func_802588B0(this->unk10C[i] + arg1, this->unk108);
            tmp_f0 = mlAbsF(tmp_f0 - tmp_f22);
            tmp_f0 = ml_map_f(tmp_f0, 0.0f, tmp_f22, 1.0 - this->unk118[i], this->unk118[i] + 1.0);
            arg2[i] *= tmp_f0;
        }
    }
}

void func_802EEE3C(ParticleEmitter *this, Gfx **gfx, Mtx **mtx, Vtx **vtx, u32 arg4){
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    Particle *iPtr;

    if(reinterpret_cast(u32, arg4) != (this->unk18 & 0x4) != 0)
        return;

    if(this->model_20 != NULL){
        for(iPtr = this->pList_start_124; iPtr < this->pList_end_128; iPtr++){
            sp8C[0] = iPtr->position_18[0] + this->unk4[0];
            sp8C[1] = iPtr->position_18[1] + this->unk4[1];
            sp8C[2] = iPtr->position_18[2] + this->unk4[2];
            if( 0.0f != this->unk10 || 1.0 != this->unk14 || this->unk49 != 0xff ){
                modelRender_setAlpha((s32) (iPtr->unkC*this->unk49));
            }//L802EEF5C
            // tmp_a3 = (this->unk18 & 0x10)?0:1;
            modelRender_setDepthMode((this->unk18 & 0x10)?0:1);
            modelRender_draw(gfx, mtx, sp8C, iPtr->unk24, iPtr->size_30, NULL, this->model_20);
        }
        return;
    }
    
    if(this->unk34){//L802EEFC4
        if( this->unk3C[0] != 0xff 
            || this->unk3C[1] != 0xff 
            || this->unk3C[2] != 0xff 
            || this->unk49 != 0xff 
        ){
            func_803382E4((this->unk18 & 0x10)? 9: 0xf);
            func_80338338(this->unk3C[0], this->unk3C[1], this->unk3C[2]);
            func_803382B4(
                (this->unk3C[0] < 8)? 0 : this->unk3C[0] - 8,
                (this->unk3C[1] < 8)? 0 : this->unk3C[1] - 8,
                (this->unk3C[2] < 8)? 0 : this->unk3C[2] - 8,
                (this->unk18 & 0x20)? 0xff : this->unk49
            );
            func_80338370();
            func_80335D30(gfx);
        }
        else if(this->unk18 & 0x10){//L802EF0C0
            gSPDisplayList((*gfx)++, D_80368978);
        }
        else{//L802EF0EC
            gSPDisplayList((*gfx)++, D_80368940);
        }//L802EF10C
        sp80[0] = 90.0f;
        sp80[1] = 0.0f;
        sp80[2] = 0.0f;
        for(iPtr = this->pList_start_124; iPtr < this->pList_end_128; iPtr++){
            gDPSetPrimColor((*gfx)++, 0, 0, this->unk3C[0], this->unk3C[1], this->unk3C[2], iPtr->unkC*this->unk49);
            sp8C[0] = iPtr->position_18[0] + this->unk4[0];
            sp8C[1] = iPtr->position_18[1] + this->unk4[1];
            sp8C[2] = iPtr->position_18[2] + this->unk4[2];

            sp74[0] = iPtr->size_30;
            sp74[1] = iPtr->size_30;
            sp74[2] = iPtr->size_30;
            if(0.0f != this->unk108){
                func_802EED1C(this, iPtr->age_48, sp74);
            }
            func_80344C2C(this->unk0_16);
            if(this->unk18 & 1){
                func_80344720(this->unk34, (s32)iPtr->frame_10, 0, sp8C, sp80, sp74, gfx, mtx);
            }//L802EF2F8
            else{
                func_80344424(this->unk34, (s32)iPtr->frame_10, 0, sp8C, sp74, iPtr->unk24[2], gfx, mtx);
            }//L802EF324
        }//L802EF338
        if( this->unk3C[0] != 0xff || this->unk3C[1] != 0xff || this->unk3C[2] != 0xff || this->unk49 != 0xff 
        ){
            func_8033687C(gfx);
        }
    }
}

void func_802EF3A8(ParticleEmitter *this, Gfx **gdl, Mtx **mPtr, Vtx **vPtr){
    func_802EEE3C(this, gdl, mPtr, vPtr, 4);
    func_802EEE3C(this, gdl, mPtr, vPtr, 0);
}

void func_802EF3F4(ParticleEmitter *this, f32 position_min[3], f32 position_max[3], s32 count){
    for(count; count > 0; count--){
        if(this->pList_end_128 < this->pList_capacity_12C){
            __particleEmitter_initParticle(this, this->pList_end_128);
            this->pList_end_128->position_18[0] = randf2(position_min[0], position_max[0]);
            this->pList_end_128->position_18[1] = randf2(position_min[1], position_max[1]);
            this->pList_end_128->position_18[2] = randf2(position_min[2], position_max[2]);
            this->pList_end_128++;
        }
    }
}

void func_802EF4AC(ParticleEmitter *this, f32 arg1[3], f32 arg2[3], s32 arg3) {
    f32 sp3C[3];
    f32 temp_f0;
    s32 temp_s4;
    s32 i;

    arg3 -= 1;
    sp3C[0] = arg2[0] - arg1[0];\
    sp3C[1] = arg2[1] - arg1[1];\
    sp3C[2] = arg2[2] - arg1[2];
    for(i = 0; i <= arg3; i++){
        if (this->pList_end_128 < this->pList_capacity_12C) {
            __particleEmitter_initParticle(this, this->pList_end_128);
            this->pList_end_128->position_18[0] = arg1[0] + sp3C[0]*((f32)i / arg3);
            this->pList_end_128->position_18[1] = arg1[1] + sp3C[1]*((f32)i / arg3);
            this->pList_end_128->position_18[2] = arg1[2] + sp3C[2]*((f32)i / arg3);
            this->pList_end_128++;
        }
    }
}

//particleEmitter_emitN
void particleEmitter_emitN(ParticleEmitter *this, int n){
    for(n; n > 0; n--){
        if(this->pList_end_128 < this->pList_capacity_12C){
            __particleEmitter_initParticle(this, this->pList_end_128++);
        }
    }
}

//particleEmitter_particleListLength
int func_802EF628(ParticleEmitter *this){
    return (u32)(this->pList_end_128 - this->pList_start_124);
}

//particleEmitter_isDone
int func_802EF648(ParticleEmitter *this){
    return (u32)(this->pList_end_128 - this->pList_start_124) < 1 
           && this->doneSpawning_0_23 == 1;
}

//particleEmitter_free
void func_802EF684(ParticleEmitter *this){
    func_802EE930(this);
    free(this);
}

ParticleEmitter * particleEmitter_new(u32 capacity){
    ParticleEmitter *this = malloc(capacity*sizeof(Particle) + sizeof(ParticleEmitter));
    f32 sp40[3];
    
    this->unk0_0 = 0;
    this->doneSpawning_0_23 = 1;
    this->unk18 = 0;
    this->sprite_1C = NULL;
    this->unk0_16 = 0;
    this->model_20 = NULL;
    this->unk34 = 0;
    this->assetId_0_15 = 0;
    this->unk3C[0] = 0xff;
    this->unk3C[1] = 0xff;
    this->unk3C[2] = 0xff;
    this->particleSpawnTimer_24 = 0.0f;
    this->spawnIntervalTimer_38 = 0.0f;
    sp40[0] = sp40[1] = sp40[2] = 0.0f;
    
    func_802EFA40(this, &sp40);
    func_802EFA5C(this, 0.0f, 1.0f);
    func_802EFA70(this, 0);
    particleEmitter_setPosition(this, sp40);
    particleEmitter_setParticleAccelerationRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EF9E4(this, 0xff);
    particleEmitter_setParticleSpawnPositionRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EF9EC(this, 0, 0);
    func_802EF9F8(this, 0.9f);
    func_802EFA04(this, -100000.0f);
    func_802EFA34(this, 100000.0f);
    particleEmitter_setParticleCallback(this, 0);
    func_802EFA18(this, 0);
    func_802EFA20(this, 1.0f, 1.0f);
    particleEmitter_setStartingFrameRange(this, 0, 0);
    particleEmitter_setParticleFramerateRange(this, 0.0f, 0.0f);
    func_802EFB70(this, 1.0f, 1.0f);
    func_802EFB84(this, 0.0f, 0.0f);
    func_802EFE24(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setSpawnIntervalRange(this, 0.0f, 5.0f);
    func_802EFEC0(this, 0.0f, 5.0f);
    func_802EFF5C(this, 0.0f, 0.0f, 0.0f);
    func_802EFF7C(this, 0.0f, 0.0f, 0.0f);
    func_802EFF9C(this, 0.0f);
    func_802EFF50(this, 0.0f);
    this->unk100 = 0;
    this->unk104 = 0;
    this->pList_start_124 = &this->data[0];
    this->pList_end_128 = &this->data[0];
    this->pList_capacity_12C = &this->pList_start_124[capacity];
    return this;
}

void particleEmitter_setSprite(ParticleEmitter *this, enum asset_e sprite_id){
    if(sprite_id != this->assetId_0_15){
        this->assetId_0_15 = sprite_id;
        func_802EE930(this);
        this->sprite_1C = func_8033B6C4(sprite_id, &this->unk34);
    }
}

void particleEmitter_setParticleAccelerationRange(ParticleEmitter *this, f32 min_x, f32 min_y, f32 min_z, f32 max_x, f32 max_y, f32 max_z){
    this->particleAccerationRange_4C_min_x = min_x;
    this->particleAccerationRange_4C_min_y = min_y;
    this->particleAccerationRange_4C_min_z = min_z;
    this->particleAccerationRange_4C_max_x = max_x;
    this->particleAccerationRange_4C_max_y = max_y;
    this->particleAccerationRange_4C_max_z = max_z;
}

void func_802EF9E4(ParticleEmitter *this, s32 arg1){
    this->unk49 = arg1;
}

void func_802EF9EC(ParticleEmitter *this, s32 arg1, s32 arg2){
    this->unk66 = arg1;
    this->unk7C = arg2;
}

void func_802EF9F8(ParticleEmitter *this, f32 arg1){
    this->unk68 = arg1;
}

void func_802EFA04(ParticleEmitter *this, f32 arg1){
    this->unk74 = arg1;
}

void particleEmitter_setParticleCallback(ParticleEmitter *this, void (*arg1)(ParticleEmitter *this, f32 pos[3])){
    this->particleCallback_80 = arg1;
}

void func_802EFA18(ParticleEmitter *this, s32 arg1){
    this->unk64 = arg1;
}

void func_802EFA20(ParticleEmitter *this, f32 arg1, f32 arg2){
    this->unk6C = arg1;
    this->unk70 = arg2;
}

void func_802EFA34(ParticleEmitter *this, f32 arg1){
    this->unk78 = arg1;
}

void func_802EFA40(ParticleEmitter *this, f32 (*arg1)[3]){
    this->unk4[0] = (*arg1)[0];
    this->unk4[1] = (*arg1)[1];
    this->unk4[2] = (*arg1)[2];
}

void func_802EFA5C(ParticleEmitter *this, f32 arg1, f32 arg2){
    this->unk10 = arg1;
    this->unk14 = arg2;
}

void func_802EFA70(ParticleEmitter *this, s32 arg1){
    this->unk18 = arg1;
}

void func_802EFA78(ParticleEmitter *this, s32 arg1){
    this->unk0_16 = arg1;
}

void particleEmitter_setStartingFrameRange(ParticleEmitter *this, s32 arg1, s32 arg2){
    this->particleStartingFrameRange_84_min = arg1;
    this->particleStartingFrameRange_84_max = arg2;
}

void particleEmitter_setParticleFramerateRange(ParticleEmitter *this, f32 arg1, f32 arg2){
    this->particleFramerateRange_8C_min = arg1;
    this->particleFramerateRange_8C_max = arg2;
}

void func_802EFAB0(ParticleEmitter *this, s32 arg1, f32 arg2){
    this->unk100 = arg1;
    this->unk104 = (s16) arg2;
}

//
void particleEmitter_setModel(ParticleEmitter *this, enum asset_e model_id){
    if(this->assetId_0_15 != model_id){
        this->assetId_0_15 = model_id;
        func_802EE930(this);
        this->model_20 = assetcache_get(model_id);
    }
}

void particleEmitter_setParticleSpawnPositionRange(ParticleEmitter *this, f32 min_x, f32 min_y, f32 min_z, f32 max_x, f32 max_y, f32 max_z){
    this->particleSpawnPositionRange_94_min_x = min_x;
    this->particleSpawnPositionRange_94_min_y = min_y;
    this->particleSpawnPositionRange_94_min_z = min_z;
    this->particleSpawnPositionRange_94_max_x = max_x;
    this->particleSpawnPositionRange_94_max_y = max_y;
    this->particleSpawnPositionRange_94_max_z = max_z;
}

void particleEmitter_setPosition(ParticleEmitter * this, f32 position[3]){
    this->postion_28[0] = position[0];
    this->postion_28[1] = position[1];
    this->postion_28[2] = position[2];
}

void func_802EFB70(ParticleEmitter * this, f32 min, f32 max){
    this->particleStartingScaleRange_AC_min = min;
    this->particleStartingScaleRange_AC_max = max;
}

void func_802EFB84(ParticleEmitter * this, f32 min, f32 max){
    this->particleFinalScaleRange_B4_min = min;
    this->particleFinalScaleRange_B4_max = max;
}

void func_802EFB98(ParticleEmitter *this, struct31s *arg1){
    this->particleStartingScaleRange_AC_min = arg1->unk0[0];
    this->particleStartingScaleRange_AC_max = arg1->unk0[1];
    if(-1.0f != arg1->unk8[0]){
        this->particleFinalScaleRange_B4_min = arg1->unk8[0];
        this->particleFinalScaleRange_B4_max = arg1->unk8[1];
    }
    particleEmitter_setSpawnIntervalRange(this, arg1->unk10[0], arg1->unk10[1]);
    this->unkDC[0] = arg1->unk18[0];
    this->unkDC[1] = arg1->unk18[1];
    this->unk10 = arg1->unk20;
    this->unk14 = arg1->unk24;
}

void func_802EFC28(ParticleEmitter *this, struct40s *arg1){
    func_802EFB98(this, &arg1->unk0);
    func_802EFA70(this, (s32)arg1->unk28);
    particleEmitter_emitN(this, (s32)arg1->unk2C);
}

void particleEmitter_setVelocityAndAccelerationRanges(ParticleEmitter *this, struct41s *arg1){
    particleEmitter_setParticleVelocityRange(this, 
        arg1->unk0.unk0[0], arg1->unk0.unk0[1], arg1->unk0.unk0[2],
        arg1->unk0.unkC[0], arg1->unk0.unkC[1], arg1->unk0.unkC[2]
    );
    particleEmitter_setParticleAccelerationRange(this, 
        arg1->unk18.unk0[0], arg1->unk18.unk0[1], arg1->unk18.unk0[2], 
        arg1->unk18.unkC[0], arg1->unk18.unkC[1], arg1->unk18.unkC[2]
    );
}

void particleEmitter_setPositionAndVelocityRanges(ParticleEmitter *this, struct42s *arg1){
    particleEmitter_setParticleVelocityRange(this, 
        arg1->unk0.unk0[0], arg1->unk0.unk0[1], arg1->unk0.unk0[2],
        arg1->unk0.unkC[0], arg1->unk0.unkC[1], arg1->unk0.unkC[2]
    );

    particleEmitter_setParticleSpawnPositionRange( this, 
        arg1->unk18.unk0[0], arg1->unk18.unk0[1], arg1->unk18.unk0[2], 
        arg1->unk18.unkC[0], arg1->unk18.unkC[1], arg1->unk18.unkC[2]
    );
}

void particleEmitter_setPositionVelocityAndAccelerationRanges(ParticleEmitter *this, struct43s* arg1){
    particleEmitter_setParticleVelocityRange(this, 
        arg1->unk0.unk0[0], arg1->unk0.unk0[1], arg1->unk0.unk0[2],
        arg1->unk0.unkC[0], arg1->unk0.unkC[1], arg1->unk0.unkC[2]
    );
    particleEmitter_setParticleAccelerationRange(this, 
        arg1->unk18.unk0[0], arg1->unk18.unk0[1], arg1->unk18.unk0[2], 
        arg1->unk18.unkC[0], arg1->unk18.unkC[1], arg1->unk18.unkC[2]
    );
    particleEmitter_setParticleSpawnPositionRange( this, 
        arg1->unk30.unk0[0], arg1->unk30.unk0[1], arg1->unk30.unk0[2], 
        arg1->unk30.unkC[0], arg1->unk30.unkC[1], arg1->unk30.unkC[2]
    );
}

void func_802EFE24(ParticleEmitter *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    this->unkBC[0] = arg1;
    this->unkBC[1] = arg2;
    this->unkBC[2] = arg3;
    this->unkC8[0] = arg4;
    this->unkC8[1] = arg5;
    this->unkC8[2] = arg6;
}

void particleEmitter_setSpawnIntervalRange(ParticleEmitter *this, f32 min, f32 max){
    this->spawnIntervalRange_D4_min = min;
    this->spawnIntervalRange_D4_max = max;
    if(0.0f == this->particleSpawnTimer_24 || max < this->particleSpawnTimer_24)
        this->particleSpawnTimer_24 = randf2(this->spawnIntervalRange_D4_min, this->spawnIntervalRange_D4_max);
}

void func_802EFEC0(ParticleEmitter *this, f32 arg1, f32 arg2){
    this->unkDC[0] = arg1;
    this->unkDC[1] = arg2;
}

void particleEmitter_setParticleVelocityRange(ParticleEmitter *this, f32 x_min, f32 x_max, f32 y_min, f32 y_max, f32 z_min, f32 z_max){
    this->sphericalParticleVelocity_48 = FALSE;
    this->particleVelocityRange_E4.cartisian_min_x = x_min;
    this->particleVelocityRange_E4.cartisian_min_y = x_max;
    this->particleVelocityRange_E4.cartisian_min_z = y_min;
    this->particleVelocityRange_E4.cartisian_max_x = y_max;
    this->particleVelocityRange_E4.cartisian_max_y = z_min;
    this->particleVelocityRange_E4.cartisian_max_z = z_max;
}

void particleEmitter_setSphericalParticleVelocityRange(ParticleEmitter *this, f32 pitch_min, f32 yaw_min, f32 radial_min, f32 pitch_max, f32 yaw_max, f32 radial_max){
    this->sphericalParticleVelocity_48 = TRUE;
    this->particleVelocityRange_E4.spherical.yaw_min = yaw_min;
    this->particleVelocityRange_E4.spherical.yaw_max = yaw_max;
    this->particleVelocityRange_E4.spherical.pitch_min = pitch_min;
    this->particleVelocityRange_E4.spherical.pitch_max = pitch_max;
    this->particleVelocityRange_E4.spherical.radius_min = radial_min;
    this->particleVelocityRange_E4.spherical.radius_max = radial_max;
}

void func_802EFF50(ParticleEmitter *this, f32 arg1){
    this->unkFC = arg1;
}

void func_802EFF5C(ParticleEmitter *this, f32 arg1, f32 arg2, f32 arg3){
    this->unk118[0] = arg1;
    this->unk118[1] = arg2;
    this->unk118[2] = arg3;
}

void func_802EFF7C(ParticleEmitter *this, f32 arg1, f32 arg2, f32 arg3){
    this->unk10C[0] = arg1;
    this->unk10C[1] = arg2;
    this->unk10C[2] = arg3;
}

void func_802EFF9C(ParticleEmitter *this, f32 arg1){
    this->unk108 = arg1;
}

void func_802EFFA8(ParticleEmitter *this, s32 arg1[3]){
    this->unk3C[0] = arg1[0];
    this->unk3C[1] = arg1[1];
    this->unk3C[2] = arg1[2];
}

void particleEmitter_setSpawnInterval(ParticleEmitter *this, f32 arg1){
    this->doneSpawning_0_23 = FALSE;
    this->spawnIntervalTimer_38 = arg1;
}

void func_802EFFDC(ParticleEmitter *this){
    return;
}

void particleEmitter_update(ParticleEmitter *this){
    Particle *iPtr;
    f32 tick = time_getDelta();
    f32 temp_f0;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp68;
    
    if(D_80380924){
        for(iPtr = this->pList_start_124; iPtr < this->pList_end_128;){//L802F005C
            iPtr->age_48 += tick;
            if(iPtr->lifetime_4C <= iPtr->age_48){
                memcpy(iPtr, --this->pList_end_128, sizeof(Particle));
            }else{//L802F00A0
                temp_f0 = iPtr->age_48/iPtr->lifetime_4C;
                if(temp_f0 < this->unk10)
                    iPtr->unkC = temp_f0/this->unk10;
                else if(temp_f0 <= this->unk14)
                    iPtr->unkC = 1.0f;
                else{
                    iPtr->unkC = 1.0f - ((temp_f0 - this->unk14)/(1.0f - this->unk14)); 
                }//L802F00F0
                iPtr->size_30 = iPtr->initialSize_34 + temp_f0*iPtr->finalSizeDiff;
                
                if(this->sprite_1C){
                    iPtr->frame_10 += iPtr->framerate_14*tick;
                    if(!((s32)iPtr->frame_10 < spriteGetFrameCount(this->sprite_1C))){
                        if(this->unk18 & 8){
                            iPtr->frame_10 = spriteGetFrameCount(this->sprite_1C) - 1;
                        }else{
                            iPtr->frame_10 = 0.0f;
                        }
                    }
                }//L802F0180

                iPtr->position_18[0] += iPtr->velocity_50[0]*tick;
                iPtr->position_18[1] += iPtr->velocity_50[1]*tick;
                iPtr->position_18[2] += iPtr->velocity_50[2]*tick;

                iPtr->unk24[0] += iPtr->unk3C[0]*tick;
                iPtr->unk24[1] += iPtr->unk3C[1]*tick;
                iPtr->unk24[2] += iPtr->unk3C[2]*tick;

                iPtr->velocity_50[0] = iPtr->velocity_50[0] + iPtr->unk0[0]*tick;
                iPtr->velocity_50[1] = iPtr->velocity_50[1] + iPtr->unk0[1]*tick;
                iPtr->velocity_50[2] = iPtr->velocity_50[2] + iPtr->unk0[2]*tick;

                if(this->unk100){
                    iPtr->position_18[1] = func_8034E698(this->unk100) + this->unk104;
                }//L802F0254

                if( 0.0f != this->unkFC 
                    && !func_8024DB50(&iPtr->position_18, this->unkFC)
                ){
                    memcpy(iPtr, --this->pList_end_128, sizeof(Particle));
                }
                else{//L802F029C
                    if(iPtr->unk5C > 0){
                        sp6C[0] = iPtr->position_18[0];
                        sp6C[1] = iPtr->position_18[1] + 50.0f;
                        sp6C[2] = iPtr->position_18[2];
                        if(func_802EE974(this, &sp6C, &iPtr->position_18, &sp78, 0)){
                            if(this->unk66){
                                sp68 = mlAbsF(iPtr->velocity_50[1])/10.0;
                                if(1.0f < sp68){
                                    sp68 = 1.0f;
                                }//L802F0324
                                if(D_80380920 == 0.0f){
                                    func_8030E6A4(this->unk66, randf2(this->unk6C, this->unk70), (s32)((f32)this->unk7C*sp68));
                                    D_80380920 = 0.25f;
                                }
                            }//L802F0384
                            iPtr->position_18[1] += 2.0f;
                            iPtr->velocity_50[1] = mlAbsF(iPtr->velocity_50[1]) * this->unk68;
                            if((this->unk18 & 0x2) == 0){
                                iPtr->initialSize_34 *= this->unk68;
                                iPtr->finalSizeDiff *= this->unk68;
                            }//L802F03DC

                            iPtr->unk3C[0] *= this->unk68;
                            iPtr->unk3C[1] *= this->unk68;
                            iPtr->unk3C[2] *= this->unk68;
                            if(--iPtr->unk5C == 0){
                                if(this->particleCallback_80)
                                    this->particleCallback_80(this, iPtr->position_18);
                                memcpy(iPtr, --this->pList_end_128, sizeof(Particle));
                                continue;
                            }
                        }
                    }
                    iPtr++;
                }
            }//L802F045C
        }//L802F0468
        if(0.0f < this->spawnIntervalTimer_38){ //if exactly 0.0f (no update)
            this->spawnIntervalTimer_38 -= tick;
            if(this->spawnIntervalTimer_38 <= 0.0f) //only can stop spawning 
                this->doneSpawning_0_23 = TRUE;
        }

        if(this->doneSpawning_0_23 != TRUE){
            this->particleSpawnTimer_24 -= tick;
            if(this->particleSpawnTimer_24 <= 0.0f){
                this->particleSpawnTimer_24 = randf2(this->spawnIntervalRange_D4_min, this->spawnIntervalRange_D4_max);
                if(this->pList_end_128 < this->pList_capacity_12C)
                    __particleEmitter_initParticle(this, this->pList_end_128++);
            }
        }
    }//L802F0514
}

void func_802F053C(ParticleEmitter *this, f32 arg1[3]){
    particleEmitter_setSprite(this, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFFA8(this, D_803689B8);
    func_802EFA5C(this, 0.0f, 0.1f);
    particleEmitter_setStartingFrameRange(this, 0, 7);
    particleEmitter_setParticleSpawnPositionRange(this, -80.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    particleEmitter_setPosition(this, arg1);
    func_802EFB70(this, 1.0f, 1.0f);
    func_802EFB84(this, 2.0f, 3.0f);
    particleEmitter_setSpawnIntervalRange(this, 0.0f, 0.01f);
    func_802EFEC0(this, 3.0f, 4.0f);
    particleEmitter_setParticleVelocityRange(this, -200.0f, 0.0f, -200.0f, 200.0f, 100.0f, 200.0f);
}

void func_802F066C(ParticleEmitter *this, f32 arg1[3]){
    particleEmitter_setParticleAccelerationRange(this, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    func_802EF9F8(this, 0.6f);
    func_802EFA18(this, 3);
    particleEmitter_setModel(this, ASSET_896_MODEL_GOLD_ROCK);
    particleEmitter_setParticleSpawnPositionRange(this,
        -120.0f, -60.0f, -120.0f,
        120.0f, 60.0f, 120.0f
    );
    particleEmitter_setPosition(this, arg1);
    func_802EFB70(this, 0.2f, 0.3f);
    func_802EFE24(this, 
        -300.0f, -300.0f, -300.0f,
        300.0f, 300.0f, 300.0f
    );
    particleEmitter_setSpawnIntervalRange(this, 0.0f, 0.01f);
    func_802EFEC0(this, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(this, 
        -500.0f, 150.0f, 
        -500.0f, 500.0f,
         400.0f, 500.0f
    );
}

void func_802F07D8(void){
    D_803689B0 = (ParticleEmitter **) malloc(0);
    D_803689B4 = 0;
}

void func_802F0804(void){
    int i;
    for(i = 0; i < D_803689B4; i++){
        func_802EF684(D_803689B0[i]);
    }
    free(D_803689B0);
    D_803689B0 = NULL;
    D_803689B4 = 0;
}

void func_802F0898(void){
    return;
}

void func_802F08A0(void){
    int i;
    ParticleEmitter *iPtr;

    D_80380920 = MAX(0.0, D_80380920 - time_getDelta());
    if(D_803689B0){
        for(i = 0; i < D_803689B4; i++){
            iPtr = D_803689B0[i];
            particleEmitter_update(iPtr);
            if( iPtr->unk0_0
                && iPtr->doneSpawning_0_23 == TRUE
                && iPtr->pList_end_128 == iPtr->pList_start_124
            ){
                iPtr->unk0_1 = TRUE;
            }
            else{
                iPtr->unk0_1 = FALSE;
            }
        }//L802F09C0
        for(i = 0; i < D_803689B4;){
            if(D_803689B0[i]->unk0_1){
                partEmitList_remove(D_803689B0[i]);
            }
            else{
                i++;
            }
        }
    }//L802F0A14
}

void func_802F0A34(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < D_803689B4; i++){
        func_802EEE3C(D_803689B0[i], gdl, mptr, vptr, 4);
    }
}

void func_802F0AE8(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < D_803689B4; i++){
        func_802EEE3C(D_803689B0[i], gdl, mptr, vptr, 0);
    }
}

void func_802F0B98(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    func_802F0A34(gdl, mptr, vptr);
    func_802F0AE8(gdl, mptr, vptr);
}

ParticleEmitter *partEmitList_pushNew(u32 cnt){
    D_803689B0 = realloc(D_803689B0, (++D_803689B4)*4);
    D_803689B0[D_803689B4 - 1] = particleEmitter_new(cnt);
    D_803689B0[D_803689B4 - 1]->unk0_0 = TRUE;
    return D_803689B0[D_803689B4 - 1];
}


void partEmitList_remove(ParticleEmitter *this){
    int i = 0;
    while(this != D_803689B0[i] && i < D_803689B4){i++;}
    if(i == D_803689B4)
        return;

    func_802EF684(this);
    D_803689B0[i] = D_803689B0[D_803689B4 - 1];
    D_803689B4--;
    D_803689B0 = realloc(D_803689B0, D_803689B4*sizeof(ParticleEmitter *));
}

void func_802F0D54(ParticleEmitter *this){
    this->unk0_0 = FALSE;
}

void func_802F0D64(ParticleEmitter *this){
    this->unk0_0 = TRUE;
}

ParticleEmitter * func_802F0D74(ParticleEmitter *this){
    int i;
    s32 a3;

    if(this){
        a3 = (s32)this;
        i = 0;
        while(D_803689B0[i] != this && i < D_803689B4){
            i++;
        }
        this = (ParticleEmitter *)defrag(this);
        this->pList_start_124 = (Particle *)((s32)this + (u32)((s32)this->pList_start_124 - a3));
        this->pList_end_128 = (Particle *)((s32)this + (u32)((s32)this->pList_end_128 - a3));
        this->pList_capacity_12C = (Particle *)((s32)this + (u32)((s32)this->pList_capacity_12C - a3));
        if(i < D_803689B4){
            D_803689B0[i] = this;
        }

    }//L802F0E44
    return this;
}

void func_802F0E58(void){
    D_803689B0 = (ParticleEmitter **)defrag(D_803689B0);
}

void func_802F0E80(void* arg0, s32 arg1){
    D_80380924 = (arg1 == 2) ? 1 : 0;
}

void func_802F0EAC(ParticleEmitter *this, f32 arg1){
    Particle *iPtr;
    this->postion_28[1] = arg1;
    for(iPtr = this->pList_start_124; iPtr < this->pList_end_128; iPtr++)
        iPtr->position_18[1] = arg1;
    
}
