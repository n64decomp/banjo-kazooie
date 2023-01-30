#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 D_80368AA0[3] = {0xC8, 0xC8, 0xE6};

/* .bss */
u8 D_80380A00;


/* .code */
void func_802F1E80(void){
    func_802F1190(D_80380A00);
}

void func_802F1EA4(void){
    D_80380A00 = func_802F0F78(0x10);
}

ParticleEmitter *func_802F1EC8(f32 *position) {
    ParticleEmitter *p_emitter;

    p_emitter = func_802F0EF0(D_80380A00);
    particleEmitter_setPosition(p_emitter, position);
    particleEmitter_setSprite(p_emitter, ASSET_700_SPRITE_DUST);
    particleEmitter_setParticleVelocityRange(p_emitter, -10.0f, 10.0f, -10.0f, 10.0f, 240.0f, 10.0f);
    particleEmitter_setRGB(p_emitter, D_80368AA0);
    particleEmitter_setFade(p_emitter, 0.2f, 0.3f);
    func_802EFB70(p_emitter, 0.2f, 0.4f);
    func_802EFB84(p_emitter, 0.85f, 0.9f);
    particleEmitter_setParticleLifeTimeRange(p_emitter, 0.3f, 0.35f);
    return p_emitter;
}
