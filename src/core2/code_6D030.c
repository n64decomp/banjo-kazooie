#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EFA04(ParticleEmitter *, f32);

ParticleEmitter *func_802F4094(f32 pos[3], f32 arg1);

/* .data */
s32 D_80368DD0[3] = {0xff, 0xff, 0xfe};

/* .bss */
u8 D_80380A90;

/* .code */
void func_802F3FC0(ParticleEmitter *this, f32 pos[3]){
    func_802F3554(0, pos);
}

void func_802F3FE4(f32 pos[3]){
    ParticleEmitter *pCtrl;
    pCtrl = func_802F4094(pos, 20.0f);
    particleEmitter_setParticleVelocityRange(pCtrl,
        -180.0f, 400.0f, -180.0f,
        180.0f, 700.0f, 180.0f
    );
    particleEmitter_emitN(pCtrl, 20);
}

void func_802F404C(void){
    func_802F1190(D_80380A90);
}

void func_802F4070(void){
    D_80380A90 = func_802F0F78(0x1e);
}

ParticleEmitter *func_802F4094(f32 pos[3], f32 arg1){
    ParticleEmitter *pCtrl;

    pCtrl = func_802F0EF0(D_80380A90);
    particleEmitter_setSprite(pCtrl, ASSET_70B_SPRITE_BUBBLE_2);
    func_802EF9E4(pCtrl, 180);
    particleEmitter_setParticleAccelerationRange(pCtrl,
        0.0f, -1300.0f, 0.0f,
        0.0f, -1300.0f, 0.0f
    );
    func_802EFA18(pCtrl, 1);
    func_802EFA04(pCtrl, pos[1]);
    particleEmitter_setParticleCallback(pCtrl, func_802F3FC0);
    func_802EFA5C(pCtrl, 0.0f, 0.8f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -arg1, 0.0f, -arg1,
        arg1, 0.0f, arg1
    );
    particleEmitter_setPosition(pCtrl, pos);
    func_802EFFA8(pCtrl, D_80368DD0);
    func_802EFB70(pCtrl, 0.02f, 0.04f);
    func_802EFB84(pCtrl, 0.01f, 0.01f);
    func_802EFEC0(pCtrl, 2.0f, 2.0f);
    func_802EFF50(pCtrl, 10.0f);
    return pCtrl;
}
