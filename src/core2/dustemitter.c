#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/particle.h"
#include "core2/particleemittermanager.h"
#include "core2/dustemitter.h"

s16 emitterAssets[EMITTER_COUNT] = {
    ASSET_700_SPRITE_DUST,
    ASSET_702_SPRITE_UNKNOWN,
    ASSET_70D_SPRITE_SMOKE_1
};

u8 emitterIndexes[EMITTER_COUNT];

s32 dustEmitter_returnGiven(s32 value) {
    return value;
}

void dustEmitter_empty(s32 arg0) {
    return;
}

bool dustEmitter_isActive(s32 index) {
    return (index < EMITTER_COUNT) ? !particleEmitter_isDone(pem_getEmitterByIndex(emitterIndexes[index])) : FALSE;
}

void dustEmitter_init(void) {
    s32 i;

    for (i = 0; i < EMITTER_COUNT; i++) {
        emitterIndexes[i] = pem_newEmitter(EMITTER_CAPACITY);
    }
}

void dustEmitter_free(void) {
    s32 i;

    for (i = 0; i < EMITTER_COUNT; i++) {
        pem_free(emitterIndexes[i]);
    }
}

void dustEmitter_emit(f32 position[3], f32 velocity[3], s32 color[4], bool useDefaultDrawMode, f32 lifetime,
    f32 additionalYVelocity, s32 startingScale, s32 finalScale, enum dust_emitter_type_e type) {

    s32 _1;
    s32 _2;
    s32 _3;
    f32 velocity_range[3];
    s32 draw_mode;
    ParticleEmitter *emitter;

    draw_mode = 0x28;
    emitter = pem_getEmitterByIndex(emitterIndexes[type]);
    particleEmitter_setSprite(emitter, emitterAssets[type]);
    particleEmitter_setFade(emitter, 0.075f, 0.4f);
    particleEmitter_setPosition(emitter, position);
    particleEmitter_setSpawnIntervalRange(emitter, 0.0f, 0.0f);
    particleEmitter_func_802EFA78(emitter, 1);

    if (velocity != NULL) {
        ml_vec3f_scale_copy(velocity_range, velocity, 30.0f);
    } else {
        velocity_range[0] = velocity_range[1] = velocity_range[2] = 0.0f;
    }

    if (additionalYVelocity != 0.0) {
        velocity_range[1] += additionalYVelocity / lifetime;
    }

    particleEmitter_setParticleVelocityRange(emitter,
        velocity_range[0], velocity_range[1], velocity_range[2],  // x, y, z min
        velocity_range[0], velocity_range[1], velocity_range[2]); // x, y, z max

    if (color != NULL) {
        particleEmitter_setRGB(emitter, color);
        particleEmitter_setAlpha(emitter, color[3]);
    }

    if (useDefaultDrawMode == FALSE) {
        draw_mode = PART_EMIT_NO_OPA | PART_EMIT_NO_DEPTH | PART_EMIT_NO_LOOP;
    }

    particleEmitter_setDrawMode(emitter, draw_mode);
    particleEmitter_setParticleLifeTimeRange(emitter, lifetime, lifetime);
    particleEmitter_setStartingScaleRange(emitter, startingScale / 175.0, startingScale / 175.0);
    particleEmitter_setFinalScaleRange(emitter, (startingScale + finalScale) / 175.0, (startingScale + finalScale) / 175.0);

    if (type == DUST_EMITTER_TYPE_DUST) {
        particleEmitter_setParticleFramerateRange(emitter, (15.0 / lifetime), (15.0 / lifetime));
    } else {
        particleEmitter_setStartingFrameRange(emitter, 0, 0xC);
    }

    particleEmitter_emitN(emitter, 1);
}
