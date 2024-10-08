#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"

extern s32 spriteGetFrameCount(BKSprite *);
extern void func_80344720(s32 SpriteGfx, s32 frame, s32, f32[3], f32[3], f32[3], Gfx **, Mtx **);
extern void func_80344424(s32 SpriteGfx, s32 frame, s32, f32[3], f32[3], f32, Gfx **, Mtx **);

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

ParticleEmitter **partEmitMgr = NULL; //particlePtrArrayPtr
s32 partEmitMgrLength = 0; //particlePtrArraySize

//particle
typedef struct particle{
    f32 acceleration[3];
    f32 fade;
    f32 frame; //frame
    f32 framerate; //framerate
    f32 position[3];
    f32 rotation[3];
    f32 scale; //size
    f32 initialSize_34; //initial_size
    f32 finalSizeDiff; //delta_size
    f32 angluar_velocity[3];
    f32 age_48;
    f32 lifetime_4C;
    f32 velocity_50[3];
    u8 unk5C;
    //u8 pad5D[3];
} Particle;

/* .bss */
f32 particleSfxTimer;
u8 partEmitMgrEnable;

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
    particle->acceleration[0] = randf2(this->particleAccerationRange_4C_min_x, this->particleAccerationRange_4C_max_x);
    particle->acceleration[1] = randf2(this->particleAccerationRange_4C_min_y, this->particleAccerationRange_4C_max_y);
    particle->acceleration[2] = randf2(this->particleAccerationRange_4C_min_z, this->particleAccerationRange_4C_max_z);
    particle->unk5C = this->unk64;
    
    particle->fade = (0.0f == this->fade_in) ? 1.0f : 0; 
    particle->frame = randf2((f32)this->particleStartingFrameRange_84_min, (f32)this->particleStartingFrameRange_84_max);
    particle->framerate = randf2(this->particleFramerateRange_8C_min, this->particleFramerateRange_8C_max);

    particle->position[0] = this->postion_28[0];
    particle->position[1] = this->postion_28[1];
    particle->position[2] = this->postion_28[2];

    particle->position[0] = particle->position[0] + randf2(this->particleSpawnPositionRange_94_min_x, this->particleSpawnPositionRange_94_max_x);
    particle->position[1] = particle->position[1] + randf2(this->particleSpawnPositionRange_94_min_y, this->particleSpawnPositionRange_94_max_y);
    particle->position[2] = particle->position[2] + randf2(this->particleSpawnPositionRange_94_min_z, this->particleSpawnPositionRange_94_max_z);

    particle->initialSize_34 = particle->scale = randf2(this->particleStartingScaleRange_AC_min, this->particleStartingScaleRange_AC_max);
    if(0.0f == this->particleFinalScaleRange_B4_min && 0.0f == this->particleFinalScaleRange_B4_max)
        particle->finalSizeDiff = 0.0f;
    else
        particle->finalSizeDiff = randf2(this->particleFinalScaleRange_B4_min, this->particleFinalScaleRange_B4_max)- particle->initialSize_34;

    particle->rotation[2] = 0.0f;
    particle->rotation[1] = 0.0f;
    particle->rotation[0] = 0.0f;

    particle->angluar_velocity[0] = randf2(this->unkBC[0], this->unkC8[0]);
    particle->angluar_velocity[1] = randf2(this->unkBC[1], this->unkC8[1]);
    particle->angluar_velocity[2] = randf2(this->unkBC[2], this->unkC8[2]);
    
    particle->age_48 = 0.0f;
    particle->lifetime_4C = randf2(this->particleLifeTimeRange[0], this->particleLifeTimeRange[1]) + 0.001;
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

void func_802EED1C(ParticleEmitter *this, f32 age, f32 arg2[3]){
    int i;
    f32 tmp_f22;
    f32 tmp_f0;

    tmp_f22 = this->unk108*0.5;
    for(i = 0; i < 3; i++){
        if(this->unk118[i] != 0.0f){
            tmp_f0 = ml_remainder_f(this->unk10C[i] + age, this->unk108);
            tmp_f0 = mlAbsF(tmp_f0 - tmp_f22);
            tmp_f0 = ml_map_f(tmp_f0, 0.0f, tmp_f22, 1.0 - this->unk118[i], this->unk118[i] + 1.0);
            arg2[i] *= tmp_f0;
        }
    }
}

void __particleEmitter_drawOnPass(ParticleEmitter *this, Gfx **gfx, Mtx **mtx, Vtx **vtx, u32 draw_pass){
    f32 position[3];
    f32 flat_rotation[3];
    f32 scale[3];
    Particle *iPtr;

    if(reinterpret_cast(u32, draw_pass) != (this->draw_mode & 0x4) != 0)
        return;

    if(this->model_20 != NULL){
        for(iPtr = this->pList_start_124; iPtr < this->pList_end_128; iPtr++){
            position[0] = iPtr->position[0] + this->unk4[0];
            position[1] = iPtr->position[1] + this->unk4[1];
            position[2] = iPtr->position[2] + this->unk4[2];
            if( 0.0f != this->fade_in || 1.0 != this->fade_out || this->alpha != 0xff ){
                modelRender_setAlpha((s32) (iPtr->fade*this->alpha));
            }//L802EEF5C
            modelRender_setDepthMode((this->draw_mode & PART_EMIT_NO_DEPTH)? MODEL_RENDER_DEPTH_NONE : MODEL_RENDER_DEPTH_FULL);
            modelRender_draw(gfx, mtx, position, iPtr->rotation, iPtr->scale, NULL, this->model_20);
        }
        return;
    }
    
    if(this->unk34){//L802EEFC4
        if( this->rgb[0] != 0xff 
            || this->rgb[1] != 0xff 
            || this->rgb[2] != 0xff 
            || this->alpha != 0xff 
        ){
            func_803382E4((this->draw_mode & PART_EMIT_NO_DEPTH)? 9: 0xf);
            func_80338338(this->rgb[0], this->rgb[1], this->rgb[2]);
            func_803382B4(
                (this->rgb[0] < 8)? 0 : this->rgb[0] - 8,
                (this->rgb[1] < 8)? 0 : this->rgb[1] - 8,
                (this->rgb[2] < 8)? 0 : this->rgb[2] - 8,
                (this->draw_mode & PART_EMIT_NO_OPA)? 0xff : this->alpha
            );
            func_80338370();
            func_80335D30(gfx);
        }
        else if(this->draw_mode & PART_EMIT_NO_DEPTH){//L802EF0C0
            gSPDisplayList((*gfx)++, D_80368978);
        }
        else{//L802EF0EC
            gSPDisplayList((*gfx)++, D_80368940);
        }//L802EF10C
        flat_rotation[0] = 90.0f;
        flat_rotation[1] = 0.0f;
        flat_rotation[2] = 0.0f;
        for(iPtr = this->pList_start_124; iPtr < this->pList_end_128; iPtr++){
            gDPSetPrimColor((*gfx)++, 0, 0, this->rgb[0], this->rgb[1], this->rgb[2], iPtr->fade*this->alpha);
            position[0] = iPtr->position[0] + this->unk4[0];
            position[1] = iPtr->position[1] + this->unk4[1];
            position[2] = iPtr->position[2] + this->unk4[2];

            scale[0] = iPtr->scale;
            scale[1] = iPtr->scale;
            scale[2] = iPtr->scale;
            if(0.0f != this->unk108){
                func_802EED1C(this, iPtr->age_48, scale);
            }
            func_80344C2C(this->unk0_16);
            if(this->draw_mode & PART_EMIT_ROTATABLE){
                func_80344720(this->unk34, (s32)iPtr->frame, 0, position, flat_rotation, scale, gfx, mtx);
            }//L802EF2F8
            else{
                func_80344424(this->unk34, (s32)iPtr->frame, 0, position, scale, iPtr->rotation[2], gfx, mtx);
            }//L802EF324
        }//L802EF338
        if( this->rgb[0] != 0xff || this->rgb[1] != 0xff || this->rgb[2] != 0xff || this->alpha != 0xff 
        ){
            func_8033687C(gfx);
        }
    }
}

void particleEmitter_draw(ParticleEmitter *this, Gfx **gdl, Mtx **mPtr, Vtx **vPtr){
    __particleEmitter_drawOnPass(this, gdl, mPtr, vPtr, 4);
    __particleEmitter_drawOnPass(this, gdl, mPtr, vPtr, 0);
}

void particleEmitter_emitInVolume(ParticleEmitter *this, f32 position_min[3], f32 position_max[3], s32 count){
    for(count; count > 0; count--){
        if(this->pList_end_128 < this->pList_capacity_12C){
            __particleEmitter_initParticle(this, this->pList_end_128);
            this->pList_end_128->position[0] = randf2(position_min[0], position_max[0]);
            this->pList_end_128->position[1] = randf2(position_min[1], position_max[1]);
            this->pList_end_128->position[2] = randf2(position_min[2], position_max[2]);
            this->pList_end_128++;
        }
    }
}

void particleEmitter_emitUniformLine(ParticleEmitter *this, f32 start[3], f32 end[3], s32 count) {
    f32 d_position[3];
    f32 temp_f0;
    s32 temp_s4;
    s32 i;

    count -= 1;
    d_position[0] = end[0] - start[0];\
    d_position[1] = end[1] - start[1];\
    d_position[2] = end[2] - start[2];
    for(i = 0; i <= count; i++){
        if (this->pList_end_128 < this->pList_capacity_12C) {
            __particleEmitter_initParticle(this, this->pList_end_128);
            this->pList_end_128->position[0] = start[0] + d_position[0]*((f32)i / count);
            this->pList_end_128->position[1] = start[1] + d_position[1]*((f32)i / count);
            this->pList_end_128->position[2] = start[2] + d_position[2]*((f32)i / count);
            this->pList_end_128++;
        }
    }
}

void particleEmitter_emitN(ParticleEmitter *this, int n){
    for(n; n > 0; n--){
        if(this->pList_end_128 < this->pList_capacity_12C){
            __particleEmitter_initParticle(this, this->pList_end_128++);
        }
    }
}

int particleEmitter_getParticleCount(ParticleEmitter *this){
    return (u32)(this->pList_end_128 - this->pList_start_124);
}

int particleEmitter_isDone(ParticleEmitter *this){
    return (u32)(this->pList_end_128 - this->pList_start_124) < 1 
           && this->doneSpawning_0_23 == TRUE;
}

void particleEmitter_free(ParticleEmitter *this){
    func_802EE930(this);
    free(this);
}

ParticleEmitter * particleEmitter_new(u32 capacity){
    ParticleEmitter *this = malloc(capacity*sizeof(Particle) + sizeof(ParticleEmitter));
    f32 sp40[3];
    
    this->auto_free = 0;
    this->doneSpawning_0_23 = 1;
    this->draw_mode = 0;
    this->sprite_1C = NULL;
    this->unk0_16 = 0;
    this->model_20 = NULL;
    this->unk34 = 0;
    this->assetId_0_15 = 0;
    this->rgb[0] = 0xff;
    this->rgb[1] = 0xff;
    this->rgb[2] = 0xff;
    this->particleSpawnTimer_24 = 0.0f;
    this->spawnIntervalTimer_38 = 0.0f;
    sp40[0] = sp40[1] = sp40[2] = 0.0f;
    
    func_802EFA40(this, &sp40);
    particleEmitter_setFade(this, 0.0f, 1.0f);
    particleEmitter_setDrawMode(this, 0);
    particleEmitter_setPosition(this, sp40);
    particleEmitter_setAccelerationRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setAlpha(this, 0xff);
    particleEmitter_setSpawnPositionRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setSfx(this, 0, 0);
    particleEmitter_func_802EF9F8(this, 0.9f);
    func_802EFA04(this, -100000.0f);
    func_802EFA34(this, 100000.0f);
    particleEmitter_setParticleCallback(this, 0);
    particleEmitter_func_802EFA18(this, 0);
    func_802EFA20(this, 1.0f, 1.0f);
    particleEmitter_setStartingFrameRange(this, 0, 0);
    particleEmitter_setParticleFramerateRange(this, 0.0f, 0.0f);
    particleEmitter_setStartingScaleRange(this, 1.0f, 1.0f);
    particleEmitter_setFinalScaleRange(this, 0.0f, 0.0f);
    particleEmitter_setAngularVelocityRange(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setSpawnIntervalRange(this, 0.0f, 5.0f);
    particleEmitter_setParticleLifeTimeRange(this, 0.0f, 5.0f);
    func_802EFF5C(this, 0.0f, 0.0f, 0.0f);
    func_802EFF7C(this, 0.0f, 0.0f, 0.0f);
    func_802EFF9C(this, 0.0f);
    func_802EFF50(this, 0.0f);
    this->unk100 = 0;
    this->unk104 = 0;
    this->pList_start_124 = (Particle *)(this + 1);
    this->pList_end_128 = (Particle *)(this + 1);
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

void particleEmitter_setAccelerationRange(ParticleEmitter *this, f32 min_x, f32 min_y, f32 min_z, f32 max_x, f32 max_y, f32 max_z){
    this->particleAccerationRange_4C_min_x = min_x;
    this->particleAccerationRange_4C_min_y = min_y;
    this->particleAccerationRange_4C_min_z = min_z;
    this->particleAccerationRange_4C_max_x = max_x;
    this->particleAccerationRange_4C_max_y = max_y;
    this->particleAccerationRange_4C_max_z = max_z;
}

void particleEmitter_setAlpha(ParticleEmitter *this, s32 arg1){
    this->alpha = arg1;
}

void particleEmitter_setSfx(ParticleEmitter *this, enum sfx_e sfx_id, s32 arg2){
    this->sfx_id = sfx_id;
    this->unk7C = arg2;
}

void particleEmitter_func_802EF9F8(ParticleEmitter *this, f32 arg1){
    this->unk68 = arg1;
}

void func_802EFA04(ParticleEmitter *this, f32 arg1){
    this->unk74 = arg1;
}

void particleEmitter_setParticleCallback(ParticleEmitter *this, void (*arg1)(ParticleEmitter *this, f32 pos[3])){
    this->particleCallback_80 = arg1;
}

void particleEmitter_func_802EFA18(ParticleEmitter *this, s32 arg1){
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

void particleEmitter_setFade(ParticleEmitter *this, f32 fade_in, f32 fade_out){
    this->fade_in = fade_in;
    this->fade_out = fade_out;
}

void particleEmitter_setDrawMode(ParticleEmitter *this, s32 arg1){
    this->draw_mode = arg1;
}

void particleEmitter_func_802EFA78(ParticleEmitter *this, s32 arg1){
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

void particleEmitter_setSpawnPositionRange(ParticleEmitter *this, f32 min_x, f32 min_y, f32 min_z, f32 max_x, f32 max_y, f32 max_z){
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

void particleEmitter_setStartingScaleRange(ParticleEmitter * this, f32 min, f32 max){
    this->particleStartingScaleRange_AC_min = min;
    this->particleStartingScaleRange_AC_max = max;
}

void particleEmitter_setFinalScaleRange(ParticleEmitter * this, f32 min, f32 max){
    this->particleFinalScaleRange_B4_min = min;
    this->particleFinalScaleRange_B4_max = max;
}

void particleEmitter_setScaleAndLifetimeRanges(ParticleEmitter *this, ParticleScaleAndLifetimeRanges *settings) {
    this->particleStartingScaleRange_AC_min = settings->unk0[0];
    this->particleStartingScaleRange_AC_max = settings->unk0[1];

    if(-1.0f != settings->unk8[0]){
        this->particleFinalScaleRange_B4_min = settings->unk8[0];
        this->particleFinalScaleRange_B4_max = settings->unk8[1];
    }

    particleEmitter_setSpawnIntervalRange(this, settings->unk10[0], settings->unk10[1]);

    this->particleLifeTimeRange[0] = settings->unk18[0];
    this->particleLifeTimeRange[1] = settings->unk18[1];

    this->fade_in = settings->unk20;
    this->fade_out = settings->unk24;
}

void func_802EFC28(ParticleEmitter *this, ParticleSettingsScaleAndLifetimeDrawModeEmitCount *settings) {
    particleEmitter_setScaleAndLifetimeRanges(this, &settings->scale_and_lifetime);
    particleEmitter_setDrawMode(this, (s32)settings->drawmode);
    particleEmitter_emitN(this, (s32)settings->count);
}

void particleEmitter_setVelocityAndAccelerationRanges(ParticleEmitter *this, ParticleSettingsVelocityAcceleration *settings) {
    particleEmitter_setParticleVelocityRange(this, 
        settings->velocity.min[0], settings->velocity.min[1], settings->velocity.min[2],
        settings->velocity.max[0], settings->velocity.max[1], settings->velocity.max[2]
    );

    particleEmitter_setAccelerationRange(this, 
        settings->acceleration.min[0], settings->acceleration.min[1], settings->acceleration.min[2], 
        settings->acceleration.max[0], settings->acceleration.max[1], settings->acceleration.max[2]
    );
}

void particleEmitter_setPositionAndVelocityRanges(ParticleEmitter *this, ParticleSettingsVelocityPosition *settings) {
    particleEmitter_setParticleVelocityRange(this, 
        settings->velocity.min[0], settings->velocity.min[1], settings->velocity.min[2],
        settings->velocity.max[0], settings->velocity.max[1], settings->velocity.max[2]
    );

    particleEmitter_setSpawnPositionRange( this, 
        settings->spawn_position.min[0], settings->spawn_position.min[1], settings->spawn_position.min[2],
        settings->spawn_position.max[0], settings->spawn_position.max[1], settings->spawn_position.max[2]
    );
}

void particleEmitter_setVelocityAccelerationAndPositionRanges(ParticleEmitter *this, ParticleSettingsVelocityAccelerationPosition *settings) {
    particleEmitter_setParticleVelocityRange(this, 
        settings->velocity.min[0], settings->velocity.min[1], settings->velocity.min[2],
        settings->velocity.max[0], settings->velocity.max[1], settings->velocity.max[2]
    );

    particleEmitter_setAccelerationRange(this, 
        settings->acceleration.min[0], settings->acceleration.min[1], settings->acceleration.min[2], 
        settings->acceleration.max[0], settings->acceleration.max[1], settings->acceleration.max[2]
    );

    particleEmitter_setSpawnPositionRange( this, 
        settings->spawn_position.min[0], settings->spawn_position.min[1], settings->spawn_position.min[2], 
        settings->spawn_position.max[0], settings->spawn_position.max[1], settings->spawn_position.max[2]
    );
}

void particleEmitter_setAngularVelocityRange(ParticleEmitter *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
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

void particleEmitter_setParticleLifeTimeRange(ParticleEmitter *this, f32 min, f32 max){
    this->particleLifeTimeRange[0] = min;
    this->particleLifeTimeRange[1] = max;
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

void particleEmitter_setRGB(ParticleEmitter *this, s32 arg1[3]){
    this->rgb[0] = arg1[0];
    this->rgb[1] = arg1[1];
    this->rgb[2] = arg1[2];
}

void particleEmitter_setSpawnInterval(ParticleEmitter *this, f32 arg1){
    this->doneSpawning_0_23 = FALSE;
    this->spawnIntervalTimer_38 = arg1;
}

void func_802EFFDC(ParticleEmitter *this){
    return;
}

void particleEmitter_update(ParticleEmitter *this){
    Particle *particle;
    f32 tick = time_getDelta();
    f32 temp_f0;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp68;
    
    if(partEmitMgrEnable){
        for(particle = this->pList_start_124; particle < this->pList_end_128;){//L802F005C
            particle->age_48 += tick;
            if(particle->lifetime_4C <= particle->age_48){
                memcpy(particle, --this->pList_end_128, sizeof(Particle));
            }else{//L802F00A0
                temp_f0 = particle->age_48/particle->lifetime_4C;
                if(temp_f0 < this->fade_in)
                    particle->fade = temp_f0/this->fade_in;
                else if(temp_f0 <= this->fade_out)
                    particle->fade = 1.0f;
                else{
                    particle->fade = 1.0f - ((temp_f0 - this->fade_out)/(1.0f - this->fade_out)); 
                }//L802F00F0
                particle->scale = particle->initialSize_34 + temp_f0*particle->finalSizeDiff;
                
                if(this->sprite_1C){
                    particle->frame += particle->framerate*tick;
                    if(!((s32)particle->frame < spriteGetFrameCount(this->sprite_1C))){
                        if(this->draw_mode & PART_EMIT_NO_LOOP){
                            particle->frame = spriteGetFrameCount(this->sprite_1C) - 1;
                        }else{
                            particle->frame = 0.0f;
                        }
                    }
                }//L802F0180

                particle->position[0] += particle->velocity_50[0]*tick;
                particle->position[1] += particle->velocity_50[1]*tick;
                particle->position[2] += particle->velocity_50[2]*tick;

                particle->rotation[0] += particle->angluar_velocity[0]*tick;
                particle->rotation[1] += particle->angluar_velocity[1]*tick;
                particle->rotation[2] += particle->angluar_velocity[2]*tick;

                particle->velocity_50[0] = particle->velocity_50[0] + particle->acceleration[0]*tick;
                particle->velocity_50[1] = particle->velocity_50[1] + particle->acceleration[1]*tick;
                particle->velocity_50[2] = particle->velocity_50[2] + particle->acceleration[2]*tick;

                if(this->unk100){
                    particle->position[1] = func_8034E698(this->unk100) + this->unk104;
                }//L802F0254

                if( 0.0f != this->unkFC 
                    && !viewport_func_8024DB50(&particle->position, this->unkFC)
                ){
                    memcpy(particle, --this->pList_end_128, sizeof(Particle));
                }
                else{//L802F029C
                    if(particle->unk5C > 0){
                        sp6C[0] = particle->position[0];
                        sp6C[1] = particle->position[1] + 50.0f;
                        sp6C[2] = particle->position[2];
                        if(func_802EE974(this, &sp6C, &particle->position, &sp78, 0)){
                            if(this->sfx_id){
                                sp68 = mlAbsF(particle->velocity_50[1])/10.0;
                                if(1.0f < sp68){
                                    sp68 = 1.0f;
                                }//L802F0324
                                if(particleSfxTimer == 0.0f){
                                    func_8030E6A4(this->sfx_id, randf2(this->unk6C, this->unk70), (s32)((f32)this->unk7C*sp68));
                                    particleSfxTimer = 0.25f;
                                }
                            }//L802F0384
                            particle->position[1] += 2.0f;
                            particle->velocity_50[1] = mlAbsF(particle->velocity_50[1]) * this->unk68;
                            if((this->draw_mode & 0x2) == 0){
                                particle->initialSize_34 *= this->unk68;
                                particle->finalSizeDiff *= this->unk68;
                            }//L802F03DC

                            particle->angluar_velocity[0] *= this->unk68;
                            particle->angluar_velocity[1] *= this->unk68;
                            particle->angluar_velocity[2] *= this->unk68;
                            if(--particle->unk5C == 0){
                                if(this->particleCallback_80)
                                    this->particleCallback_80(this, particle->position);
                                memcpy(particle, --this->pList_end_128, sizeof(Particle));
                                continue;
                            }
                        }
                    }
                    particle++;
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
    static s32 D_803689B8[3] = {0xAF, 0x87, 0};
    particleEmitter_setSprite(this, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(this, D_803689B8);
    particleEmitter_setFade(this, 0.0f, 0.1f);
    particleEmitter_setStartingFrameRange(this, 0, 7);
    particleEmitter_setSpawnPositionRange(this, -80.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    particleEmitter_setPosition(this, arg1);
    particleEmitter_setStartingScaleRange(this, 1.0f, 1.0f);
    particleEmitter_setFinalScaleRange(this, 2.0f, 3.0f);
    particleEmitter_setSpawnIntervalRange(this, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(this, 3.0f, 4.0f);
    particleEmitter_setParticleVelocityRange(this, -200.0f, 0.0f, -200.0f, 200.0f, 100.0f, 200.0f);
}

void func_802F066C(ParticleEmitter *this, f32 position[3]){
    particleEmitter_setAccelerationRange(this, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    particleEmitter_func_802EF9F8(this, 0.6f);
    particleEmitter_func_802EFA18(this, 3);
    particleEmitter_setModel(this, ASSET_896_MODEL_GOLD_ROCK);
    particleEmitter_setSpawnPositionRange(this,
        -120.0f, -60.0f, -120.0f,
        120.0f, 60.0f, 120.0f
    );
    particleEmitter_setPosition(this, position);
    particleEmitter_setStartingScaleRange(this, 0.2f, 0.3f);
    particleEmitter_setAngularVelocityRange(this, 
        -300.0f, -300.0f, -300.0f,
        300.0f, 300.0f, 300.0f
    );
    particleEmitter_setSpawnIntervalRange(this, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(this, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(this, 
        -500.0f, 150.0f, 
        -500.0f, 500.0f,
         400.0f, 500.0f
    );
}

void partEmitMgr_init(void){
    partEmitMgr = (ParticleEmitter **) malloc(0);
    partEmitMgrLength = 0;
}

void partEmitMgr_free(void){
    int i;
    for(i = 0; i < partEmitMgrLength; i++){
        particleEmitter_free(partEmitMgr[i]);
    }
    free(partEmitMgr);
    partEmitMgr = NULL;
    partEmitMgrLength = 0;
}

void func_802F0898(void){
    return;
}

void partEmitMgr_update(void){
    int i;
    ParticleEmitter *iPtr;

    particleSfxTimer = MAX(0.0, particleSfxTimer - time_getDelta());
    if(partEmitMgr){
        for(i = 0; i < partEmitMgrLength; i++){
            iPtr = partEmitMgr[i];
            particleEmitter_update(iPtr);
            if( iPtr->auto_free
                && iPtr->doneSpawning_0_23 == TRUE
                && iPtr->pList_end_128 == iPtr->pList_start_124
            ){
                iPtr->dead = TRUE;
            }
            else{
                iPtr->dead = FALSE;
            }
        }//L802F09C0
        for(i = 0; i < partEmitMgrLength;){
            if(partEmitMgr[i]->dead){
                partEmitMgr_freeEmitter(partEmitMgr[i]);
            }
            else{
                i++;
            }
        }
    }//L802F0A14
}

void partEmitMgr_drawPass0(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < partEmitMgrLength; i++){
        __particleEmitter_drawOnPass(partEmitMgr[i], gdl, mptr, vptr, 4);
    }
}

void partEmitMgr_drawPass1(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < partEmitMgrLength; i++){
        __particleEmitter_drawOnPass(partEmitMgr[i], gdl, mptr, vptr, 0);
    }
}

void partEmitMgr_draw(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    partEmitMgr_drawPass0(gdl, mptr, vptr);
    partEmitMgr_drawPass1(gdl, mptr, vptr);
}

ParticleEmitter *partEmitMgr_newEmitter(u32 cnt){
    partEmitMgr = realloc(partEmitMgr, (++partEmitMgrLength)*4);
    partEmitMgr[partEmitMgrLength - 1] = particleEmitter_new(cnt);
    partEmitMgr[partEmitMgrLength - 1]->auto_free = TRUE;
    return partEmitMgr[partEmitMgrLength - 1];
}


void partEmitMgr_freeEmitter(ParticleEmitter *this){
    int i = 0;
    while(this != partEmitMgr[i] && i < partEmitMgrLength){i++;}
    if(i == partEmitMgrLength)
        return;

    particleEmitter_free(this);
    partEmitMgr[i] = partEmitMgr[partEmitMgrLength - 1];
    partEmitMgrLength--;
    partEmitMgr = realloc(partEmitMgr, partEmitMgrLength*sizeof(ParticleEmitter *));
}

void particleEmitter_manualFree(ParticleEmitter *this){
    this->auto_free = FALSE;
}

void particleEmitter_autoFree(ParticleEmitter *this){
    this->auto_free = TRUE;
}

ParticleEmitter * partEmitMgr_defragEmitter(ParticleEmitter *this){
    int i;
    s32 a3;

    if(this){
        a3 = (s32)this;
        i = 0;
        while(partEmitMgr[i] != this && i < partEmitMgrLength){
            i++;
        }
        this = (ParticleEmitter *)defrag(this);
        this->pList_start_124 = (Particle *)((s32)this + (u32)((s32)this->pList_start_124 - a3));
        this->pList_end_128 = (Particle *)((s32)this + (u32)((s32)this->pList_end_128 - a3));
        this->pList_capacity_12C = (Particle *)((s32)this + (u32)((s32)this->pList_capacity_12C - a3));
        if(i < partEmitMgrLength){
            partEmitMgr[i] = this;
        }

    }//L802F0E44
    return this;
}

void partEmitMgr_defrag(void){
    partEmitMgr = (ParticleEmitter **)defrag(partEmitMgr);
}

void func_802F0E80(void* arg0, s32 arg1){
    partEmitMgrEnable = BOOL(arg1 == 2);
}

void func_802F0EAC(ParticleEmitter *this, f32 arg1){
    Particle *iPtr;
    this->postion_28[1] = arg1;
    for(iPtr = this->pList_start_124; iPtr < this->pList_end_128; iPtr++)
        iPtr->position[1] = arg1;
    
}
