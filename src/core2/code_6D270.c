#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern func_802EFAB0(ParticleEmitter *, s32, f32);

ParticleEmitter *func_802F4274(f32 arg0[3]);

/* .data */
extern s32 D_80368DE0[3];

/* .bss */
extern u8 D_80380AA0;

/* .code */
void func_802F4200(f32 arg0[3]){
    particleEmitter_emitN(func_802F4274(arg0), 1);
}

void func_802F422C(void){
    func_802F1190(D_80380AA0);
}

void func_802F4250(void){
    D_80380AA0 = func_802F0F78(3);
}

ParticleEmitter *func_802F4274(f32 arg0[3]) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;
    ParticleEmitter *temp_v0;
    s32 sp20;

    ml_vec3f_copy(sp2C, arg0);
    func_8024559C(sp2C, &sp20, &sp28);
    sp2C[1] = sp28 + 14.0f;
    func_8024C5CC(sp38);
    sp44[0] = sp38[0] - sp2C[0];
    sp44[2] = sp38[2] - sp2C[2];
    sp44[1] = 0.0f;
    ml_vec3f_set_length_copy(sp44, sp44, 20.0f);
    sp2C[0] += sp44[0];
    sp2C[1] += sp44[1];
    sp2C[2] += sp44[2];
    temp_v0 = func_802F0EF0(D_80380AA0);
    if (sp20 != 0) {
        func_802EFAB0(temp_v0, sp20, sp2C[1]);
    }
    particleEmitter_setSprite(temp_v0, 0x42A);
    func_802EF9E4(temp_v0, 0xFF);
    func_802EFA5C(temp_v0, 0, 0.78f);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 0);
    particleEmitter_setParticleFramerateRange(temp_v0, 25.7142868f, 25.7142868f);
    func_802EFEC0(temp_v0, 0.7f, 0.7f);
    particleEmitter_setPosition(temp_v0, sp2C);
    func_802EFFA8(temp_v0, D_80368DE0);
    func_802EFB70(temp_v0, 0.8, 0.8);
    func_802EFB84(temp_v0, 0.8, 0.8);
    return temp_v0;
}

