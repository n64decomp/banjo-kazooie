#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"

extern bool func_8024549C(f32[3], f32);
extern void func_802EFAB0(ParticleEmitter *, s32, f32);
extern void func_802F0EAC(ParticleEmitter *, f32);
extern ParticleEmitter *func_802F0EF0(u8);

typedef union range_f32_u {
    f32 raw[2];
    struct {
        f32 min;
        f32 max;
    };
}Range_f32;

typedef struct {
    struct {f32 min; f32 max;} lifetime;
    f32 fade_out;
    f32 unkC[2];
    f32 unk14[2];
    struct {u8 r; u8 g; u8 b;}  color;
    u8  uid;
}Struct_Core2_6C3E0;

/* .data */
Struct_Core2_6C3E0 D_80368B30[] = {
    {{0.7f, 0.9f}, 0.5f, {0.1f, 0.1f}, { 0.4f,  0.6f}, {0xFF, 0xFF, 0xFE}, 0},
    {{0.8f, 1.2f}, 0.5f, {0.1f, 0.1f}, { 0.9f,  1.8f}, {0xFF, 0xFF, 0xFE}, 1},
    {{0.8f, 1.0f}, 0.5f, {0.1f, 0.1f}, { 0.6f,  1.0f}, {0xFF, 0xFF, 0xFE}, 2},
    {{0.7f, 0.7f}, 0.5f, {0.4f, 0.4f}, { 1.8f,  1.9f}, {0xFF, 0xFF, 0xFE}, 3},
    {{1.5f, 1.5f}, 0.5f, {0.1f, 0.1f}, {12.0f, 12.0f}, {0xFF, 0xFF, 0xFE}, 4}
};

/* .bss */
u8 D_80380A60;

/* .code */
bool __fxRipple_802F3370(f32 position[3], s32 *arg1, bool arg2){
    f32 sp1C;

    *arg1 = 0;
    if(arg2){
        position[1] += 1.0f;
    } else {
        arg2 = func_8024549C(position, 20.0f);
        if(!arg2){
            return FALSE;
        }
    }
    
    if(func_80245524(position, arg2, arg1, &sp1C)){
        position[1] = sp1C;
    }
    return TRUE;
}

ParticleEmitter *__fxRipple_create(s32 arg0, f32 position[3], bool arg2){
    s32 sp44;
    f32 spawn_position[3];
    ParticleEmitter *p_emitter;
    s32 rgb[3];
    Struct_Core2_6C3E0 *var_s0;

    ml_vec3f_copy(spawn_position, position);
    if(!__fxRipple_802F3370(spawn_position, &sp44, arg2)){
        return NULL;
    }
    spawn_position[1] += 3.0f;
    p_emitter = func_802F0EF0(D_80380A60);
    particleEmitter_setSprite(p_emitter, ASSET_70C_SPRITE_RIPPLE);
    particleEmitter_setDrawMode(p_emitter, PART_EMIT_ROTATABLE);
    if(sp44){
        func_802EFAB0(p_emitter, sp44, spawn_position[1]);
    }
    else{
        func_802EFAB0(p_emitter, 0, 0.0f);
    }
    var_s0 = &D_80368B30[arg0];
    rgb[0] = (s32) var_s0->color.r;
    rgb[1] = (s32) var_s0->color.g;
    rgb[2] = (s32) var_s0->color.b;
    particleEmitter_setFade(p_emitter, 0.0f, var_s0->fade_out);
    particleEmitter_setPosition(p_emitter, spawn_position);
    particleEmitter_setRGB(p_emitter, rgb);
    particleEmitter_setStartingScaleRange(p_emitter, var_s0->unkC[0], var_s0->unkC[1]);
    particleEmitter_setFinalScaleRange(p_emitter, var_s0->unk14[0], var_s0->unk14[1]);
    particleEmitter_setParticleLifeTimeRange(p_emitter, var_s0->lifetime.min, var_s0->lifetime.max);
    func_802EFF50(p_emitter, 100.0f);
    return p_emitter;
}

void fxRipple_802F3554(s32 arg0, f32 position[3]){
    ParticleEmitter *p_emitter = __fxRipple_create(arg0, position, 0);
    if(p_emitter != NULL){
        particleEmitter_emitN(p_emitter, 1);
    }
}

void fxRipple_802F3584(s32 arg0, f32 position[3], s32 arg2){
    ParticleEmitter *p_emitter = __fxRipple_create(arg0, position, arg2);
    if(p_emitter != NULL){
        particleEmitter_emitN(p_emitter, 1);
    }
}

void fxRipple_free(void){
    func_802F1190(D_80380A60);
}

void fxRipple_init(void){
    D_80380A60 = func_802F0F78(0x19);
}

ParticleEmitter *fxRipple_802F35FC(s32 arg0, f32 position[3]){
    return __fxRipple_create(arg0, position, 0);
}

ParticleEmitter *fxRipple_802F361C(s32 arg0, f32 position[3], s32 arg2){
    return __fxRipple_create(arg0, position, arg2);
}

void fxRipple_802F363C(f32 arg0){
    func_802F0EAC(func_802F0EF0(D_80380A60), arg0);
}

