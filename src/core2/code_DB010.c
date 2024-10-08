#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


extern void func_802EFF5C(ParticleEmitter *, f32, f32, f32);
extern void func_802EFF7C(ParticleEmitter *, f32, f32, f32);
extern void func_802EFF9C(ParticleEmitter *, f32);

void func_80363310(Actor *this);
void func_80363330(Actor *this);

//this may be the inner structs of a prop(?)
typedef struct{
    s16 x;
    s16 y;
    s16 z;
    u16 unk8_7:9;
    u16 pad8_6:7;
}struct_core2_DB010;

/* .data */
ActorInfo D_803732E0 = {
    0x1F7, 0x1E7, 0, 
    0, NULL, 
    func_80363310, func_80363330, func_80325340,
    0, 0, 0.0f, 0
}; 

/* .code */
void func_80361FA0(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373304 = {{{0.4f, 1.4f}, {0.0f, 0.0f}, {0.0f, 0.01f}, {4.0f, 4.0f}, 0.5f, 0.7f}, 4.0f, 15.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373334 = {
        {{-250.0f,   600.0f, -250.0f}, { 350.0f,   960.0f,  350.0f}}, 
        {{   0.0f, -1200.0f,    0.0f}, {   0.0f, -1200.0f,    0.0f}}, 
        {{ -60.0f,   -30.0f,  -60.0f}, {  60.0f,    30.0f,   60.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(15);

    particleEmitter_setModel(pCtrl, 0x441);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setAngularVelocityRange(pCtrl, -200.0f, 200.0f, -200.0f, 200.0f, 200.0f, 200.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.01f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setSfx(pCtrl, SFX_2F_ORANGE_SPLAT, 16000);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373334);
    func_802EFC28(pCtrl, &D_80373304);
    FUNC_8030E624(SFX_7C_CHEBOOF, 0.6f, 29000);
}

void func_80362084(f32 position[3]) {
    static s32 D_8037337C[3] = {50, 255, 50};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373388 = {{{0.3f, 0.03f}, {0.5f, 0.5f}, {0.0f, 0.01f}, {1.5f, 2.0f}, 0.06f, 0.7f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityPosition D_803733B8 = {
       {{ -5.0f, 100.0f,  -5.0f}, {  5.0f, 100.0f,   5.0f}}, 
       {{-60.0f,   0.0f, -60.0f}, { 60.0f,   5.0f,  60.0f}}
    };

    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(1U);
    particleEmitter_setSprite(pCtrl, 0x702);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 5);
    particleEmitter_setRGB(pCtrl, D_8037337C);
    particleEmitter_setAlpha(pCtrl, 0xA0);
    particleEmitter_setPosition(pCtrl, position);
    func_802EFF5C(pCtrl, 0.1f, 0.2f, 0.0f);
    func_802EFF7C(pCtrl, 0.0f, 0.25f, 0.0f);
    func_802EFF9C(pCtrl, 0.5f);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_803733B8);
    func_802EFC28(pCtrl, &D_80373388);
}


void func_8036215C(f32 arg0[3]) {
    static s32 D_803733E8[3] = {0xb4, 0xe6, 0xff};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803733F4 = {{{1.0f, 1.8f}, {2.2f, 2.7f}, {0.0f, 0.01f}, {0.8f, 1.2f}, 0.41f, 0.73f}, 4.0f, 15.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373424 = {
        {{-300.0f,   600.0f, -300.0f}, { 300.0f,  1000.0f,  300.0f}}, 
        {{   0.0f, -1200.0f,    0.0f}, {   0.0f, -1600.0f,    0.0f}}, 
        {{ -10.0f,     0.0f,  -10.0f}, {  10.0f,     0.0f,   10.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xFU);

    particleEmitter_setSprite(pCtrl, 0x700);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 4);
    particleEmitter_setRGB(pCtrl, D_803733E8);
    particleEmitter_setAlpha(pCtrl, 0x28);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373424);
    func_802EFC28(pCtrl, &D_803733F4);
}

void func_803621F0(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_8037346C = {{{0.3f, 0.4f}, {0.5f, 0.5f}, {0.0f, 0.01f}, {0.8f, 1.2f}, 0.91f, 0.99f}, 4.0f, 18.0f};
    static ParticleSettingsVelocityAccelerationPosition D_8037349C = {
        {{-200.0f,   900.0f, -200.0f}, { 200.0f,  1400.0f,  200.0f}}, 
        {{   0.0f, -1800.0f,    0.0f}, {   0.0f, -2400.0f,    0.0f}}, 
        {{ -10.0f,   -20.0f,  -10.0f}, {  10.0f,   -20.0f,   10.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0x12U);

    particleEmitter_setSprite(pCtrl, 0x702);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 5);
    particleEmitter_setAlpha(pCtrl, 0xD2);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8037349C);
    func_802EFC28(pCtrl, &D_8037346C);
}

void func_80362274(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803734E4 = {{{3.2f, 3.4f}, {0.0f, 0.0f}, {0.0f, 0.01f}, {2.0f, 2.0f}, 0.0f, 0.3f}, 4.0f, 15.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373514 = {
        {{-950.0f,   800.0f, -250.0f}, {-550.0f,  1360.0f,   50.0f}}, 
        {{-700.0f, -1700.0f,    0.0f}, {-900.0f, -1700.0f,    0.0f}}, 
        {{ -60.0f,     0.0f,  -60.0f}, {  60.0f,    30.0f,   60.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xFU);
    
    particleEmitter_setModel(pCtrl, 0x89B);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setAngularVelocityRange(pCtrl, -400.0f, -200.0f, -400.0f, 400.0f, -400.0f, 400.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.01f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373514);
    func_802EFC28(pCtrl, &D_803734E4);
}

void func_8036233C(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_8037355C = {{{3.0f, 3.4f}, {0.0f, 0.0f}, {0.0f, 0.01f}, {4.0f, 4.0f}, 0.0f, 0.3f}, 4.0f, 15.0f};
    static ParticleSettingsVelocityAccelerationPosition D_8037358C = {
        {{-450.0f,   600.0f, -50.0f}, {-150.0f,  1100.0f,  50.0f}}, 
        {{-700.0f, -1700.0f,   0.0f}, {-800.0f, -1700.0f,   0.0f}}, 
        {{ -60.0f,     0.0f, -60.0f}, {  60.0f,    30.0f,  60.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xFU);
    
    particleEmitter_setModel(pCtrl, 0x89A);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setAngularVelocityRange(pCtrl, -200.0f, 200.0f, -200.0f, 200.0f, 200.0f, 200.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.01f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8037358C);
    func_802EFC28(pCtrl, &D_8037355C);
}

void func_80362404(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803735D4 = {{{1.1f, 1.1f}, {4.3f, 4.3f}, {0.0f, 0.05f}, {0.3f, 0.5f}, 0.06f, 0.3f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityPosition D_80373604 = {
        {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}},
        {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1U);

    particleEmitter_setSprite(pCtrl, 0x6DD);
    particleEmitter_setStartingFrameRange(pCtrl, 2, 2);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_80373604);
    func_802EFC28(pCtrl, &D_803735D4);
}

void func_8036247C(f32 arg0[3]) {
    static s32 D_80373634[3] = {0xA, 0xFF, 0xA};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373640 = {{{2.0f, 2.0f}, {3.0f, 3.5f}, {0.0f, 0.01f}, {2.0f, 2.5f}, 0.1f, 0.4}, 4.0f, 1.0f};
    static ParticleSettingsVelocityPosition D_80373670 = {
        {{   0.0f, 40.0f,    0.0f}, {   0.0f, 90.0f,    0.0f}}, 
        {{-400.0f,  0.0f, -400.0f}, { 400.0f,  0.0f,  400.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1U);

    particleEmitter_setSprite(pCtrl, 0x70D);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, &D_80373634);
    particleEmitter_setAlpha(pCtrl, 0x64);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_80373670);
    func_802EFC28(pCtrl, &D_80373640);
}

void func_80362510(Actor *actor) {
    static s32 D_803736A0[3] = {0xFF, 0xFF, 0xFF};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803736AC = {{{0.01f, 0.01f}, {1.5f, 1.6f}, {0.05f, 0.7f}, {0.7f, 1.3f}, 0.1f, 0.8f}, 4.0f, 25.0f};

    ParticleEmitter *pCtrl;
    f32 sp30[3];

    pCtrl = partEmitMgr_newEmitter(0x19U);
    particleEmitter_setSprite(pCtrl, 0x70D);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 5);
    particleEmitter_setRGB(pCtrl, D_803736A0);
    particleEmitter_setAlpha(pCtrl, 0x1E);
    particleEmitter_setPosition(pCtrl, actor->position);
    particleEmitter_setSpawnPositionRange(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    sp30[0] = 1000.0f;
    sp30[1] = 100.0f;
    sp30[2] = 0.0f;
    ml_vec3f_roll_rotate_copy(sp30, sp30, actor->roll);
    ml_vec3f_yaw_rotate_copy(sp30, sp30, actor->yaw);
    particleEmitter_setParticleVelocityRange(pCtrl, 
        sp30[0] * 0.01, sp30[1] * 0.01, sp30[2] * 0.01, 
        sp30[0] * 0.4, sp30[1] * 0.4, sp30[2] * 0.4
    );
    func_802EFC28(pCtrl, &D_803736AC);
}


void func_80362680(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803736DC = {{{0.7f, 0.9f}, {0.4f, 0.5}, {0.0f, 0.01f}, {0.8f, 1.0f}, 0.15f, 0.3f}, 0.0f, 1.0f};
    static ParticleSettingsVelocityPosition D_8037370C = {
        {{-10.0f, -10.0f, -10.0f}, { 10.0f,  10.0f,  10.0f}}, 
        {{  0.0f,  30.0f,   0.0f}, {  0.0f,  30.0f,   0.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1U);

    particleEmitter_setSprite(pCtrl, 0x45A);
    particleEmitter_setStartingFrameRange(pCtrl, 2, 2);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8037370C);
    func_802EFC28(pCtrl, &D_803736DC);
}

void func_803626F8(f32 arg0[3]) {
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_8037373C = {{{0.05f, 0.1f}, {0.1f, 0.2f}, {0.0f, 0.01f}, {1.4f, 1.5f}, 0.01f, 0.7f}, 0.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_8037376C = {
        {{ -5.0f,  -5.0f,  -5.0f}, {  5.0f,   5.0f,   5.0f}}, 
        {{  0.0f, -50.0f,   0.0f}, {  0.0f, -90.0f,   0.0f}}, 
        {{-30.0f,  30.0f, -30.0f}, { 30.0f,  60.0f,  30.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1U);

    particleEmitter_setSprite(pCtrl, 0x713);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8037376C);
    func_802EFC28(pCtrl, &D_8037373C);
}


void func_80362770(f32 arg0[3]) {
    static s32 D_803737B4[3] = {0xFF, 0xFF, 00};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803737C0 = {{{0.1f, 0.3f}, {0.6f, 0.7f}, {0.0f, 0.01f}, {0.3f, 0.4f}, 0.01f, 0.3f}, 4.0f, 16.0f};
    static ParticleSettingsVelocityPosition D_803737F0 = {
        {{-600.0f, -600.0f, -600.0f}, { 600.0f,  600.0f,  600.0f}}, 
        {{   0.0f,   30.0f,    0.0f}, {   0.0f,   30.0f,    0.0f}},
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0x10U);

    particleEmitter_setSprite(pCtrl, 0x714);
    particleEmitter_setStartingFrameRange(pCtrl, 7, 8);
    particleEmitter_setRGB(pCtrl, &D_803737B4);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_803737F0);
    func_802EFC28(pCtrl, &D_803737C0);
}

void func_803627F8(f32 arg0[3]){
    static s32 D_80373820[3] = {130, 155, 40};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_8037382C = {{{3.3f, 3.3f}, {4.5f, 4.7f}, {0.0f, 0.01f}, {1.8f, 3.2f}, 0.31f, 0.73f}, 4.0f, 11.0f};
    static ParticleSettingsVelocityAccelerationPosition D_8037385C = {
        {{-200.0f,  120.0f, -200.0f}, { 200.0f,  130.0f,  200.0f}}, 
        {{   0.0f, -100.0f,    0.0f}, {   0.0f, -100.0f,    0.0f}}, 
        {{ -30.0f,    0.0f,  -30.0f}, {  30.0f,    0.0f,   30.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(11);
    
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373820);
    particleEmitter_setAlpha(pCtrl, 120);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8037385C);
    func_802EFC28(pCtrl, &D_8037382C);
}

void func_8036288C(f32 arg0[3]){
    static s32 D_803738A4[3] = {91, 142, 0};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803738B0 = {{{0.2f, 0.9f}, {0.4f, 0.9f}, {0.0f, 0.01f}, {1.8f, 4.2f}, 0.31f, 0.73f}, 4.0f, 13.0f};
    static ParticleSettingsVelocityAccelerationPosition D_803738E0 = {
        {{-400.0f,   520.0f, -400.0f}, { 400.0f,   750.0f,  400.0f}}, 
        {{   0.0f, -1200.0f,    0.0f}, {   0.0f, -1600.0f,    0.0f}}, 
        {{ -30.0f,     0.0f,  -30.0f}, {  30.0f,     0.0f,   30.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xd);

    particleEmitter_setSprite(pCtrl, ASSET_702_SPRITE_UNKNOWN);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 4);
    particleEmitter_setRGB(pCtrl, D_803738A4);
    particleEmitter_setAlpha(pCtrl, 255);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_803738E0);
    func_802EFC28(pCtrl, &D_803738B0);
}

void func_80362920(f32 arg0[3]){
    static s32 D_80373928[3] = {0, 255, 0};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373934 = {{{1.4f, 1.9f}, {2.4f, 2.9f}, {0.0f, 3.2f}, {8.8f, 9.2f}, 0.31f, 0.73f}, 4.0f, 13.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373964 = {
        {{-60.0f, 100.0f, -60.0f}, { 60.0f, 170.0f,  60.0f}}, 
        {{  0.0f,   0.0f,   0.0f}, {  0.0f,   0.0f,   0.0f}}, 
        {{-30.0f,   0.0f, -30.0f}, { 30.0f,   0.0f,  30.0f}}
    };
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xd);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373928);
    particleEmitter_setAlpha(pCtrl, 60);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373964);
    func_802EFC28(pCtrl, &D_80373934);
}

void func_803629B4(f32 arg0[3]){
    static s32 D_803739AC[3] = {255, 255, 255};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_803739B8 = {{{0.2f, 0.9f}, {0.3f, 0.4f}, {0.0f, 0.2f}, {1.0f, 1.2f}, 0.31f, 0.73f}, 4.0f, 13.0f};
    static ParticleSettingsVelocityAccelerationPosition D_803739E8 = {
        {{-600.0f,  0.0f, -600.0f}, { 600.0f,  0.0f,  600.0f}}, 
        {{   0.0f,  0.0f,    0.0f}, {   0.0f,  0.0f,    0.0f}}, 
        {{   0.0f, 40.0f,    0.0f}, {   0.0f, 40.0f,    0.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xd);
    
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_803739AC);
    particleEmitter_setAlpha(pCtrl, 255);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_803739E8);
    func_802EFC28(pCtrl, &D_803739B8);
}

void func_80362A48(f32 arg0[3]){
    static s32 D_80373A30[3] = {255, 255, 255};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373A3C = {{{1.5f, 1.6f}, {2.5f, 2.9f}, {0.0f, 0.01f}, {2.0f, 2.5f}, 0.1f, 0.4f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373A6C = {
        {{ 0.0f, 40.0f,  0.0f}, { 0.0f, 90.0f,  0.0f}}, 
        {{ 0.0f,  0.0f,  0.0f}, { 0.0f,  0.0f,  0.0f}}, 
        {{-5.0f,  0.0f, -5.0f}, { 5.0f,  0.0f,  5.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373A30);
    particleEmitter_setAlpha(pCtrl, 40);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373A6C);
    func_802EFC28(pCtrl, &D_80373A3C);
}

void func_80362ADC(f32 arg0[3]){
    static s32 D_80373AB4[3] = {30, 30, 30};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373AC0 = {{{3.0f, 3.4f}, {3.9f, 4.1f}, {0.0f, 0.01f}, {2.0f, 2.5f}, 0.3f, 0.5f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373AF0 = {
        {{100.0f, 40.0f, 100.0f}, {100.0f, 90.0f, 100.0f}}, 
        {{  0.0f,  0.0f,   0.0f}, {  0.0f,  0.0f,   0.0f}}, 
        {{ -5.0f,  0.0f,  -5.0f}, {  5.0f,  0.0f,   5.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373AB4);
    particleEmitter_setAlpha(pCtrl, 40);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373AF0);
    func_802EFC28(pCtrl, &D_80373AC0);
}

void func_80362B70(f32 arg0[3]){
    static s32 D_80373B38[3] = {130, 130, 130};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373B44 = {{{2.0f, 2.4f}, {3.9f, 4.1f}, {0.0f, 0.01f}, {2.0f, 2.5f}, 0.2f, 0.7f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373B74 = {
        {{100.0f, 40.0f, 100.0f}, {100.0f, 90.0f, 100.0f}}, 
        {{  0.0f,  0.0f,   0.0f}, {  0.0f,  0.0f,   0.0f}}, 
        {{ -5.0f,  0.0f,  -5.0f}, {  5.0f,  0.0f,   5.0f}}
    };
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373B38);
    particleEmitter_setAlpha(pCtrl, 110);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373B74);
    func_802EFC28(pCtrl, &D_80373B44);
}

void func_80362C04(f32 arg0[3]){
    static s32 D_80373BBC[3] = {0xff, 0xff, 0xff};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373BC8 = {{{0.5f, 0.6f}, {1.5f, 1.9f}, {0.0f, 0.01f}, {4.0f, 4.5f}, 0.1f, 0.8f,}, 0.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373BF8 = {
        {{ 0.0f, 40.0f,  0.0f}, { 0.0f, 90.0f,  0.0f}}, 
        {{ 0.0f,  0.0f,  0.0f}, { 0.0f,  0.0f,  0.0f}}, 
        {{-5.0f,  0.0f, -5.0f}, { 5.0f,  0.0f,  5.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373BBC);
    particleEmitter_setAlpha(pCtrl, 40);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373BF8);
    func_802EFC28(pCtrl, &D_80373BC8);
}

void func_80362C98(f32 arg0[3]){
    static s32 D_80373C40[3] = {160, 170, 170};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373C4C = {{{2.5f, 2.6f}, {3.5f, 3.9f}, {0.0f, 0.01f}, {0.3f, 0.5f}, 0.1f, 0.8f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373C7C = {
        {{-60.0f, -60.0f, -60.0f}, { 60.0f,  60.0f,  60.0f}}, 
        {{  0.0f,   0.0f,   0.0f}, {  0.0f,   0.0f,   0.0f}}, 
        {{-50.0f, -50.0f, -50.0f}, { 50.0f,  50.0f,  50.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);

    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setRGB(pCtrl, D_80373C40);
    particleEmitter_setAlpha(pCtrl, 140);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373C7C);
    func_802EFC28(pCtrl, &D_80373C4C);
}

void func_80362D2C(f32 arg0[3]){
    static s32 D_80373CC4[] = {90, 90, 90};
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373CD0 = {{{1.5f, 1.6f}, {2.5f, 2.9f}, {0.0f, 0.01f}, {0.3f, 0.5f}, 0.1f, 0.8f}, 4.0f, 1.0f};
    static ParticleSettingsVelocityAccelerationPosition D_80373D00 = {
        {{-60.0f, -60.0f, -60.0f}, {60.0f, 60.0f, 60.0f}},
        {{  0.0f,   0.0f,   0.0f}, { 0.0f,  0.0f,  0.0f}},
        {{-50.0f, -50.0f, -50.0f}, {50.0f, 50.0f, 50.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);

    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 4, 6);
    particleEmitter_setRGB(pCtrl, D_80373CC4);
    particleEmitter_setAlpha(pCtrl, 140);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373D00);
    func_802EFC28(pCtrl, &D_80373CD0);
}

void func_80362DC0(f32 arg0[3]){
    static ParticleSettingsScaleAndLifetimeDrawModeEmitCount D_80373D48 = {{ {1.8f, 3.5f}, {1.8f, 3.5f}, {0.0f, 0.01f}, {5.0f, 5.0f}, 0.0f, 0.9f}, 4.0f, 15.0f };
    static ParticleSettingsVelocityAccelerationPosition D_80373D78 = {
        {{-450.0f, 700.0f, -450.0f}, {450.0f, 1100.0f, 450.0f}},
        {{   0.0f, -900.0f,    0.0f}, {  0.0f, -900.0f,   0.0f}},
        {{-150.0f, -100.0f, -150.0f}, {150.0f,    5.0f, 150.0f}}
    };

    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(0xF);
    particleEmitter_setModel(pCtrl, ASSET_47B_MODEL_ROCK);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setAngularVelocityRange(pCtrl, -200.0f, 200.0f, -200.0f, 200.0f, 200.0f, 200.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.4f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setDrawMode(pCtrl, 2);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_80373D78);
    func_802EFC28(pCtrl, &D_80373D48);
}

void func_80362E94(Actor *this){
    f32 tick = time_getDelta();

    switch(this->unkF4_8){
        case 0x3: //L80362ED8
            if(viewport_func_8024DB50(this->position, 50.0f) && randf() < 0.2){
                func_80362084(this->position);
            }
            break;
        case 0xa: //L80362F24
            if(viewport_func_8024DB50(this->position, 50.0f) && randf() < 0.1){
                func_8036247C(this->position);
            }
            break;
        case 0xc: //L80362F70
            if(viewport_func_8024DB50(this->position, 50.0f)){
                if(randf() < 0.4)
                    func_80362680(this->position);
                if(randf() < 0.8)
                    func_803626F8(this->position);
            }
            break;
        case 0x10://L80362FE8
            if(viewport_func_8024DB50(this->position, 50.0f) && randf() < 0.1){
                func_80362A48(this->position);
            }
            break;
        case 0x11://L80363034
            if(viewport_func_8024DB50(this->position, 50.0f) && randf() < 0.06){
                func_80362ADC(this->position);
            }
            break;
        case 0x12://L80363080
            if(viewport_func_8024DB50(this->position, 50.0f) && randf() < 0.06){
                func_80362C04(this->position);
            }
            break;
        case 0x13://L803630CC
            if(viewport_func_8024DB50(this->position, 50.0f) && randf() < 0.4){
                func_80362B70(this->position);
            }
            break;
        case 0x14://L80363118
            if(viewport_func_8024DB50(this->position, 300.0f)){
                if(randf() < 0.01)
                    func_80362C98(this->position);
                func_80362D2C(this->position);
            }
            break;
        default: //L8036316C
            if(!this->volatile_initialized){
                this->volatile_initialized = TRUE;
                this->lifetime_value = this->scale*10.0;
            }

            this->lifetime_value = MAX(0.0, this->lifetime_value - tick);
            if(0.0f == this->lifetime_value){
                switch(this->unkF4_8){
                    case 2: //L8036325C
                        func_80361FA0(this->position);
                        break;
                    case 7: //L8036326C
                        func_8036215C(this->position);
                        func_803621F0(this->position);
                        break;
                    case 8: //L80363288
                        func_80362274(this->position);
                        func_8036233C(this->position);
                        break;
                    case 0x2A: //L803632A4
                        func_80362510(this);
                        break;
                    case 0x2B: //L803632B4
                        func_803627F8(this->position);
                        func_8036288C(this->position);
                        func_803629B4(this->position);
                        break;
                    case 0x2C: //L803632D8
                        func_80362920(this->position);
                        break;
                    case 0x2D: //L803632E8
                        func_80362DC0(this->position);
                        break;
                }
                marker_despawn(this->marker);
            }
            break;
    }
}

void func_80363310(Actor *this){
    func_80362E94(this);
}

void func_80363330(Actor *this){
    func_80343DEC(this);
    func_80362E94(this);
    if(this->unk48 == 1.0)
        marker_despawn(this->marker);
}

void func_80363388(struct_core2_DB010 *arg0, s32 arg1){
    f32 sp2C[3];
    s32 sp20[3];
    s32 tmp_v0 = func_80330F94(arg0, sp20);
    sp2C[0] = (f32)sp20[0];
    sp2C[1] = (f32)sp20[1];
    sp2C[2] = (f32)sp20[2];
    switch(tmp_v0){
        case 0x29: //L803633F0
            func_80362770(sp2C);
            break;
        case 0x34: //L80363400
            func_80361FA0(sp2C);
            break;
        case 0x35: //L80363410
            func_80362274(sp2C);
            func_8036233C(sp2C);
            break;
        case 0x36: //L80363428
            func_80362404(sp2C);
            break;
        case 0x2A: 
            //case used to force switch to have proper functions
            // could be any unused value(s) between (0x29 and 0x36)
            break;
    }
}
