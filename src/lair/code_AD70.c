#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80394B78;

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_8039137C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_8039144C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_803915A4.s")

void func_803916BC(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = func_802F0BD0(cnt);
    particleEmitter_setSprite(pCtrl, ASSET_4A0_SPRITE_EXPLOSION);
    func_802EFA5C(pCtrl, 0.1f, 0.3f);
    func_802EFA70(pCtrl, 8);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 6);
    particleEmitter_setParticleFramerateRange(pCtrl, 5.0f, 8.0f);
    particleEmitter_setPosition(pCtrl, position);
    func_802EFB70(pCtrl, 2.0f, 2.0f);
    func_802EFB84(pCtrl, 4.0f, 4.0f);
    func_802EFEC0(pCtrl, 1.0f, 1.5f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80394B78);
    particleEmitter_emitN(pCtrl, cnt);
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_803917B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_803917DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_AD70/func_80391EA8.s")
