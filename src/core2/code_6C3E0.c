#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_8024549C(f32[3], f32);
extern void func_802EFAB0(ParticleEmitter *, s32, f32);
extern ParticleEmitter *func_802F3670(s16[3], f32, enum asset_e);
extern void func_802F0EAC(ParticleEmitter *, f32);

typedef struct {
    f32 unk0[2];
    f32 unk8;
    f32 unkC[2];
    f32 unk14[2];
    u8  unk1C[3];
    // u8 pad1F[1];
}Struct_Core2_6C3E0;

/* .data */
extern Struct_Core2_6C3E0 D_80368B30[];
extern struct42s D_80368BD0;
extern struct42s D_80368C00;
extern struct42s D_80368C30;
extern struct42s D_80368C60;
extern struct42s D_80368C90;
extern struct42s D_80368CC0;
extern struct42s D_80368CF0;
extern struct42s D_80368D20;
extern struct42s D_80368D50;

/* .rodata */
extern f32 D_803771F0;
extern f32 D_803771F4;
extern f32 D_803771F8;
extern f32 D_803771FC;
extern f32 D_80377200;
extern f32 D_80377204;

/* .bss */
u8 D_80380A60;

/* .code */
bool func_802F3370(f32 arg0[3], s32 *arg1, bool arg2){
    f32 sp1C;

    *arg1 = 0;
    if(arg2){
        arg0[1] += 1.0f;
    } else {
        arg2 = func_8024549C(arg0, 20.0f);
        if(!arg2){
            return FALSE;
        }
    }
    
    if(func_80245524(arg0, arg2, arg1, &sp1C)){
        arg0[1] = sp1C;
    }
    return TRUE;
}

ParticleEmitter *func_802F3404(s32 arg0, f32 arg1[3], bool arg2){
    s32 sp44;
    f32 sp38[3];
    ParticleEmitter *p_emitter;
    s32 sp28[3];
    Struct_Core2_6C3E0 *var_s0;

    ml_vec3f_copy(sp38, arg1);
    if(!func_802F3370(sp38, &sp44, arg2)){
        return NULL;
    }
    sp38[1] += 3.0f;
    p_emitter = func_802F0EF0(D_80380A60);
    particleEmitter_setSprite(p_emitter, ASSET_70C_SPRITE_RIPPLE);
    func_802EFA70(p_emitter, 1);
    if(sp44){
        func_802EFAB0(p_emitter, sp44, sp38[1]);
    }
    else{
        func_802EFAB0(p_emitter, 0, 0.0f);
    }
    var_s0 = &D_80368B30[arg0];
    sp28[0] = (s32) var_s0->unk1C[0];
    sp28[1] = (s32) var_s0->unk1C[1];
    sp28[2] = (s32) var_s0->unk1C[2];
    func_802EFA5C(p_emitter, 0.0f, var_s0->unk8);
    particleEmitter_setPosition(p_emitter, sp38);
    func_802EFFA8(p_emitter, sp28);
    func_802EFB70(p_emitter, var_s0->unkC[0], var_s0->unkC[1]);
    func_802EFB84(p_emitter, var_s0->unk14[0], var_s0->unk14[1]);
    func_802EFEC0(p_emitter, var_s0->unk0[0], var_s0->unk0[1]);
    func_802EFF50(p_emitter, 100.0f);
    return p_emitter;
}

void func_802F3554(s32 arg0, f32 arg1[3]){
    ParticleEmitter *p_emitter = func_802F3404(arg0, arg1, 0);
    if(p_emitter != NULL){
        particleEmitter_emitN(p_emitter, 1);
    }
}

void func_802F3584(s32 arg0, f32 arg1[3], s32 arg2){
    ParticleEmitter *p_emitter = func_802F3404(arg0, arg1, arg2);
    if(p_emitter != NULL){
        particleEmitter_emitN(p_emitter, 1);
    }
}

void func_802F35B4(void){
    func_802F1190(D_80380A60);
}

void func_802F35D8(void){
    D_80380A60 = func_802F0F78(0x19);
}

ParticleEmitter *func_802F35FC(s32 arg0, f32 arg1[3]){
    return func_802F3404(arg0, arg1, 0);
}

ParticleEmitter *func_802F361C(s32 arg0, f32 arg1[3], s32 arg2){
    return func_802F3404(arg0, arg1, arg2);
}

void func_802F363C(f32 arg0){
    func_802F0EAC(func_802F0EF0(D_80380A60), arg0);
}

ParticleEmitter *func_802F3670(s16 arg0[3], f32 arg1, enum asset_e sprite_id){
    f32 sp1C[3];

    sp1C[0] = (f32)arg0[0];
    sp1C[1] = (f32)arg0[1];
    sp1C[2] = (f32)arg0[2];
    sp1C[1] += arg1;

    return func_802F3E98(sp1C, sprite_id);
}

void func_802F36DC(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368BD0);
    func_802EFB70(p_emitter, D_803771F0, D_803771F0);
    particleEmitter_emitN(p_emitter, 10);
}

void func_802F373C(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C00);
    func_802EFB70(p_emitter, D_803771F4, D_803771F4);
    particleEmitter_emitN(p_emitter, 7);
}

void func_802F379C(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 7.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -70.0f, 100.0f, -70.0f,
        70.0f, 250.0f, 70.0f
    );
    particleEmitter_emitN(p_emitter, 5);
}

void func_802F3808(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 7.0f, ASSET_716_SPRITE_SPARKLE_WHITE);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -70.0f, 100.0f, -70.0f,
        70.0f, 250.0f, 70.0f
    );
    particleEmitter_emitN(p_emitter, 5);
}

void func_802F3874(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 25.0f, ASSET_716_SPRITE_SPARKLE_WHITE);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C30);
    func_802EFB70(p_emitter, 0.5f, 0.5f);
    particleEmitter_emitN(p_emitter, 12);
    func_802EFEC0(p_emitter, 1.5f, 1.5f);
}

void func_802F38F0(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 12.0f, ASSET_715_SPRITE_SPARKLE_RED);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -75.0f, 100.0f, -75.0f,
        75.0f, 250.0f, 75.0f
    );
    func_802EFB70(p_emitter, D_803771F8, D_803771F8);
    particleEmitter_emitN(p_emitter, 5);
}

void func_802F3978(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 40.0f, ASSET_715_SPRITE_SPARKLE_RED);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C60);
    func_802EFB70(p_emitter, 0.5f, 0.5f);
    particleEmitter_emitN(p_emitter, 10);
}

void func_802F39D8(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 7.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -75.0f, 100.0f, -75.0f,
        75.0f, 250.0f, 75.0f
    );
    func_802EFB70(p_emitter, D_803771FC, D_803771FC);
    particleEmitter_emitN(p_emitter, 5);
}

void func_802F3A60(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 40.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C90);
    func_802EFB70(p_emitter, 0.5f, 0.5f);
    particleEmitter_emitN(p_emitter, 10);
}

void func_802F3AC0(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 10.0f, ASSET_718_SPRITE_SPARKLE_WHITE_2);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368CC0);
    func_802EFB70(p_emitter, D_80377200, D_80377200);
    particleEmitter_emitN(p_emitter, 7);
    func_802EFEC0(p_emitter, 1.5f, 1.5f);
}

void func_802F3B3C(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368CF0);
    func_802EFB70(p_emitter, D_80377204, D_80377204);
    particleEmitter_emitN(p_emitter, 5);
}

void func_802F3B9C(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368D20);
    func_802EFB70(p_emitter, 0.25f, 0.3f);
    particleEmitter_emitN(p_emitter, 1);
}

void func_802F3BF4(s16 arg0[3]){
    ParticleEmitter *p_emitter = func_802F3670(arg0, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368D50);
    func_802EFB70(p_emitter, 0.45f, 0.6f);
    func_802EFEC0(p_emitter, 0.5f, 0.8f);
    particleEmitter_emitN(p_emitter, 3);
}

void func_802F3C64(void){
    func_802F3E50();
}

void func_802F3C84(void){
    func_802F3E74();
}
