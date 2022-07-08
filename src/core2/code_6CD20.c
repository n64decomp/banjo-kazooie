#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
s16 D_80368D80[] = {
    ASSET_715_SPRITE_SPARKLE_RED,
    ASSET_716_SPRITE_SPARKLE_WHITE,
    ASSET_719_SPRITE_SPARKLE_GREEN_2,
};

struct43s  D_80368D88 = {
    {{-300.0f, -300.0f, -300.0f}, {300.0f, 300.0f, 300.0f}},
    {{0.0f, -100.0f, 0.0f}, {0.0f, -100.0f, 0.0f}},
    {{-25.0f, -25.0f, -25.0f}, {25.0f, 25.0f, 25.0f}}
};

/* .bss */
extern u8 D_80380A70;

/* .code */
void func_802F3CB0(void){
    func_802F1190(D_80380A70);
}

void func_802F3CD4(void){
    D_80380A70 = func_802F0F78(0xC);
}

void func_802F3CF8(f32 arg0[3], s32 arg1, s32 arg2){
    ParticleEmitter *pCtrl;
    if(arg2 < 3){
        pCtrl = func_802F0EF0(D_80380A70);
        particleEmitter_setSprite(pCtrl, D_80368D80[arg2]);
        func_802EFA5C(pCtrl, 0.4f, 0.8f);
        particleEmitter_setPosition(pCtrl, arg0);
        func_802EFE24(pCtrl, 
            0.0f, 0.0f, 200.0f,
            0.0f, 0.0f, 240.0f
        );
        func_802EFF50(pCtrl, 1.0f);
        func_802EFA5C(pCtrl, 0.1f, 0.5f);
        func_802EFB70(pCtrl, 0.1f, 0.2f);
        func_802EFB84(pCtrl, 0.4f, 0.5f);
        func_802EFEC0(pCtrl, 0.75f, 0.75f);
        particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80368D88);
        if(arg1 == 0){
            func_802EFA70(pCtrl, 16);
        }
        particleEmitter_emitN(pCtrl, 12);
    }
}
