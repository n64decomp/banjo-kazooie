#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
struct43s  D_803637A0 = {
    {{-200.0f, 200.0f}, {-200.0f, 200.0f}, {400.0f, 200.0f}},
    {{0.0f, -800.0, 0.0f}, {0.0f, -800.0f, 0.0f}},
    {{-10.0f, -10.0f, -10.0f}, {10.0f, 10.0f, 10.0f}}
};

/* .bss */
ParticleEmitter *D_8037C180;

/*.code */
void func_80292AE0(Gfx **gPtr, Mtx **mPtr, Vtx **vPtr){
    func_802EF3A8(D_8037C180, gPtr, mPtr, vPtr);
}

void func_80292B18(void){
    func_802EF684(D_8037C180);
}

void func_80292B3C(void){
    D_8037C180 = particleEmitter_new(0x14);
    particleEmitter_setModel(D_8037C180, 0x360);
    func_802EF9F8(D_8037C180, 0.6f);
    func_802EFA18(D_8037C180, 0);
    func_802EFB70(D_8037C180, 0.8f, 1.0f);
    func_802EFE24(D_8037C180, 400.0f, 400.0f, 400.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setSpawnIntervalRange(D_8037C180, 0.0f, 0.01f);
    func_802EFEC0(D_8037C180, 1.5f, 1.5f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(D_8037C180, &D_803637A0);
}

void func_80292C1C(void){
    particleEmitter_update(D_8037C180);
}

void func_80292C40(f32 arg0[3]){
    particleEmitter_setPosition(D_8037C180, arg0);
    particleEmitter_emitN(D_8037C180, 5);
}

void func_80292C78(void){
    if(D_8037C180 != NULL){
        D_8037C180 = func_802F0D74(D_8037C180);
    }
}
