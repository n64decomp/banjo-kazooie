#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"


/* .data */
s16 D_80368930[3] = {
    ASSET_700_SPRITE_DUST,
    ASSET_702_SPRITE_UNKNOWN,
    ASSET_70D_SPRITE_SMOKE_1
};

/* .bss */
u8 D_80380910[3];

/* .code */
s32 func_802EE5E0(s32 arg0){
    return arg0;
}

void func_802EE5E8(ParticleEmitter *this){
    return;
}

bool func_802EE5F0(s32 arg0){
    return (arg0 < 3) ? !particleEmitter_isDone(func_802F0EF0(D_80380910[arg0])) : FALSE;
}

void func_802EE63C(void) {
    s32 i;

    for(i = 0; i < 3; i++){
        D_80380910[i] = func_802F0F78(0x20);
    }
}

void func_802EE684(void) {
    s32 i;

    for(i = 0; i < 3; i++){
        func_802F1190(D_80380910[i]);
    }
}

void func_802EE6CC(f32 position[3], f32 velocity[3], s32 color[4], s32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 pad54;
    s32 pad50;
    s32 pad4C;
    f32 sp40[3];
    s32 sp3C;
    ParticleEmitter *p_ctrl;

    sp3C = 0x28;
    p_ctrl = func_802F0EF0(D_80380910[arg8]);
    particleEmitter_setSprite(p_ctrl, D_80368930[arg8]);
    particleEmitter_setFade(p_ctrl, 0.075f, 0.4f);
    particleEmitter_setPosition(p_ctrl, position);
    particleEmitter_setSpawnIntervalRange(p_ctrl, 0.0f, 0.0f);
    particleEmitter_func_802EFA78(p_ctrl, 1);
    if (velocity != NULL) {
        ml_vec3f_scale_copy(sp40, velocity, 30.0f);
    } else {
        sp40[0] = sp40[1] = sp40[2] = 0.0f;
    }

    if (arg5 != 0.0) {
        sp40[1] += arg5 / arg4;
    }
    particleEmitter_setParticleVelocityRange(p_ctrl, sp40[0], sp40[1], sp40[2], sp40[0], sp40[1], sp40[2]);
    if (color != NULL) {
        particleEmitter_setRGB(p_ctrl, color);
        particleEmitter_setAlpha(p_ctrl, color[3]);
    }
    if (arg3 == 0) {
        sp3C = PART_EMIT_NO_OPA | PART_EMIT_NO_DEPTH | PART_EMIT_NO_LOOP;
    }
    particleEmitter_setDrawMode(p_ctrl, sp3C);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, arg4, arg4);
    particleEmitter_setStartingScaleRange(p_ctrl, arg6 / 175.0, arg6 / 175.0);
    particleEmitter_setFinalScaleRange(p_ctrl, (arg6 + arg7) / 175.0, (arg6 + arg7) / 175.0);
    if (arg8 == 0) {
        particleEmitter_setParticleFramerateRange(p_ctrl, (15.0 / arg4), (15.0 / arg4));
    } else {
        particleEmitter_setStartingFrameRange(p_ctrl, 0, 0xC);
    }
    particleEmitter_emitN(p_ctrl, 1);
}
