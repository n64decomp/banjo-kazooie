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
ParticleEmitter *gEggShatter_controller;

/*.code */
void eggShatter_draw(Gfx **gPtr, Mtx **mPtr, Vtx **vPtr){
    func_802EF3A8(gEggShatter_controller, gPtr, mPtr, vPtr);
}

void eggShatter_free(void){
    func_802EF684(gEggShatter_controller);
}

void eggShatter_init(void){
    gEggShatter_controller = particleEmitter_new(20);
    particleEmitter_setModel(gEggShatter_controller, 0x360);
    func_802EF9F8(gEggShatter_controller, 0.6f);
    func_802EFA18(gEggShatter_controller, 0);
    func_802EFB70(gEggShatter_controller, 0.8f, 1.0f);
    func_802EFE24(gEggShatter_controller, 400.0f, 400.0f, 400.0f, 800.0f, 800.0f, 800.0f);
    particleEmitter_setSpawnIntervalRange(gEggShatter_controller, 0.0f, 0.01f);
    func_802EFEC0(gEggShatter_controller, 1.5f, 1.5f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(gEggShatter_controller, &D_803637A0);
}

void eggShatter_update(void){
    particleEmitter_update(gEggShatter_controller);
}

void eggShatter_new(f32 position[3]){
    particleEmitter_setPosition(gEggShatter_controller, position);
    particleEmitter_emitN(gEggShatter_controller, 5);
}

void eggShatter_defrag(void){
    if(gEggShatter_controller != NULL){
        gEggShatter_controller = func_802F0D74(gEggShatter_controller);
    }
}
