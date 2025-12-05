#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ParticleEmitter *pem_getEmitterByIndex(u8);

/* .bss */
u8 D_80380A80;

/* .code */
void func_802F3E50(void){
    pem_free(D_80380A80);
}

void func_802F3E74(void){
    D_80380A80 = pem_newEmitter(0xF);
}

ParticleEmitter *func_802F3E98(f32 pos[3], enum asset_e sprite_id){
    ParticleEmitter *this;
    this = pem_getEmitterByIndex(D_80380A80);

    particleEmitter_setSprite(this, sprite_id);
    particleEmitter_setAccelerationRange(this,
        0.0f, -250.0f, 0.0f,
        0.0f, -250.0f, 0.0f
    );
    particleEmitter_setFade(this, 0.4f, 0.8f);
    particleEmitter_setPosition(this, pos);
    particleEmitter_setStartingScaleRange(this, 0.22f, 0.22f);
    particleEmitter_setFinalScaleRange(this, 0.03f, 0.03f);
    particleEmitter_setAngularVelocityRange(this, 
        0.0f, 0.0f, 200.0f, 
        0.0f, 0.0f, 240.0f
    );
    particleEmitter_setParticleLifeTimeRange(this, 0.7f, 0.7f);
    func_802EFF50(this, 1.0f);
    return this;
}
