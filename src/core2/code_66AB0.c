#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EFA34(ParticleEmitter *, f32);
extern void func_802EFF5C(ParticleEmitter *, f32, f32, f32);
extern void func_802EFF7C(ParticleEmitter *, f32, f32, f32);
extern void func_802EFF9C(ParticleEmitter *, f32);

/* .data */
extern s32 D_80368850[3];

/* .bss */
extern u8 D_803808F0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDA94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDC18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDC64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDCDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_66AB0/func_802EDD00.s")

void func_802EDD20(void){
    func_802F1190(D_803808F0);
}

void func_802EDD44(void){
    D_803808F0 = func_802F0F78(0x1e);
}

void func_802EDD68(ParticleEmitter *caller, f32 pos[3]){
    func_802F3554(0, pos);
}

ParticleEmitter *func_802EDD8C(f32 pos[3], f32 xz_range, f32 arg2){
    ParticleEmitter *pCtrl = func_802F0EF0(D_803808F0);
    particleEmitter_setSprite(pCtrl, ASSET_70A_SPRITE_BUBBLE_1);
    func_802EFA70(pCtrl, 4);
    func_802EF9E4(pCtrl, 0xff);
    particleEmitter_setParticleAccelerationRange( pCtrl,
        0.0f, 150.0f, 0.0f,
        0.0f, 150.0f, 0.0f
    );
    func_802EFA18(pCtrl, 1);
    func_802EFA34(pCtrl, arg2);
    particleEmitter_setParticleCallback(pCtrl, func_802EDD68);
    func_802EFA5C(pCtrl, 0.0f, 0.8f);
    func_802EFEC0(pCtrl, 4.0f, 4.0f);
    particleEmitter_setParticleSpawnPositionRange( pCtrl,
        -xz_range, 0.0f, -xz_range,
        xz_range, 0.0f, xz_range
    );
    particleEmitter_setPosition(pCtrl, pos);
    func_802EFFA8(pCtrl, D_80368850);
    func_802EFB70(pCtrl, 0.05f, 0.09f);
    func_802EFB84(pCtrl, 0.05f, 0.09f);
    func_802EFF50(pCtrl, 10.0f);
    func_802EFF5C(pCtrl, 0.25f, 0.25f, 0.0f);
    func_802EFF7C(pCtrl, 0.0f, 0.1f, 0.0f);
    func_802EFF9C(pCtrl, 0.2f);

    return pCtrl;
}
