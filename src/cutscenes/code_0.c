#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_80288D08(s32, f32, void(*)(void));
extern void func_80288D40(s32, f32, void(*)(s32), s32);
extern void func_80288D84(s32, f32, void(*)(s32,s32), s32, s32);
extern void func_80288EB0(s32, f32, s32, f32, f32);
extern void func_80288EF8(s32, f32, s32, f32);
extern void func_80288F38(s32, f32, s32, f32);
extern void func_80288E68(s32, f32, s32, f32, f32);
extern void func_80288F78(s32, f32, u32);
extern void func_80288FA8(s32, f32, s32);
extern void func_80288FD8(s32, f32, u32);
extern void func_80289090(s32, f32, u32, f32);
extern void func_802EFF5C(ParticleEmitter*, f32, f32, f32);
extern void func_802EFF7C(ParticleEmitter*, f32, f32, f32);
extern void func_802EFF9C(ParticleEmitter*, f32);
extern void func_802F9E44(s32, f32, f32, f32, f32);
extern void func_80361C24(s32, f32, s32, s32);
extern void func_80361C64(s32, f32, s32, s32, s32);
extern void func_80361CF4(s32, f32, s32, f32);
extern void func_80361D7C(s32, f32, s32, s32, u32);
extern void func_80361CAC(s32, f32, s32, f32);
/* .code */
void cutscenes_func_803863F0(void){
    func_8025A2D8();
}

void func_80386410(void){
    func_8025A2FC(0, 0x96);
}

void func_80386434(void){
    comusic_8025AB44(COMUSIC_43_ENTER_LEVEL_GLITTER, 0, 300);
}

void func_8038645C(void){
    comusic_8025AB44(COMUSIC_32_STARTUP_LOGO_SCENE, 25000, 2000);
}

void func_80386484(void){
    comusic_8025AB44(COMUSIC_32_STARTUP_LOGO_SCENE, 0, 2000);
}

void func_803864AC(void){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_93_MICROWAVE);
    func_802F9F80(sp1C, 0.3f, 2.3f, 0.7f);
    func_802FA060(sp1C, 20000, 20000, 0.0f);
}

void func_80386504(void){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_134_FREEZING_SHIVER);
    func_802F9F80(sp1C, 0.05f, 4.0f, 0.95f);
    func_802FA060(sp1C, 15000, 15000, 0.0f);
    func_802F9DB8(sp1C, 1.2f, 1.2f, 0.0f);
}

void func_80386578(s32 arg0){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_134_FREEZING_SHIVER);
    func_802F9F80(sp1C, 0.1f, 3.5f, 0.95f);
    func_802FA060(sp1C, 8000, 8000, 0.0f);
    func_802F9DB8(sp1C, 1.1f, 1.2f, 0.01f);
}

void func_803865F0(void){
    s32 sp1C;
    
    sp1C = func_802F9AA8(SFX_B0_SIZZLING_NOISE);
    func_802F9F80(sp1C, 0.05f, 0.8f, 0.95f);
    func_802FA060(sp1C, 20000, 20000, 0.0f);
    func_802F9DB8(sp1C, 1.0f, 1.0f, 0.0f);
}

void func_80386668(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_141_MECHANICAL_WINCH);
    func_802F9F80(indx, 0.25f, 20.8f, 0.95f);
    func_802FA060(indx, 28000, 28000, 0.0f);
    func_802F9E44(indx, 0.0f, 5.0f, 0.2f, 0.5f);
}

void func_803866E0(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_141_MECHANICAL_WINCH);
    func_802F9F80(indx, 0.25f, 14.0f, 0.85f);
    func_802FA060(indx, 20000, 20000, 0.0f);
    func_802F9E44(indx, 0.0f, 14.0f, 0.2f, 0.2f);
}

void func_80386750(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_141_MECHANICAL_WINCH);
    func_802F9F48(indx, 1);
    func_802F9F80(indx, 0.25f, 5.5f, 0.8f);
    func_802FA060(indx, 15000, 15000, 0.0f);
    func_802F9E44(indx, 0.0f, 4.0f, 0.2f, 0.6f);
}

void func_803867D0(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_17A_SHIPHORN);
    func_802F9F48(indx, 1);
    func_802F9F80(indx, 0.25f, 5.5f, 0.8f);
    func_802FA060(indx, 18000, 18000, 0.0f);
    func_802F9E44(indx, 0.0f, 5.5f, 0.5f, 1.4f);
}

void func_8038684C(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_41A_UNKNOWN);
    func_802F9F80(indx, 0.25f, 4.0f, 0.5f);
    func_802FA060(indx, 15000, 15000, 0.0f);
    func_802F9E44(indx, 0.0f, 14.0f, 1.0f, 0.1f);
}

void func_803868B8(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_41A_UNKNOWN);
    func_802F9F80(indx, 0.25f, 2.0f, 0.5f);
    func_802FA060(indx, 15000, 15000, 0.0f);
    func_802F9E44(indx, 0.0f, 3.0f, 1.0f, 0.1f);
}

void func_80386924(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_191_STATIC);
    func_802F9F80(indx, 0.3f, 5.0f, 1.5f);
    func_802FA060(indx, 12000, 12000, 0.0f);
    func_802F9DB8(indx, 1.0f, 1.1f, 0.04f);
}

void func_80386990(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_191_STATIC);
    func_802F9F80(indx, 0.3f, 4.0f, 0.5f);
    func_802FA060(indx, 15000, 15000, 0.0f);
    func_802F9DB8(indx, 0.6f, 0.7f, 0.04f);
}

void cutscenes_func_80386A00(void){
    s32 indx;
    
    indx = func_802F9AA8(SFX_191_STATIC);
    func_802F9F80(indx, 0.3f, 4.0f, 0.5f);
    func_802FA060(indx, 15000, 15000, 0.0f);
    func_802F9DB8(indx, 1.0f, 1.1f, 0.04f);
    func_802F9E44(indx, 1.0f, 4.0f, 1.1f, 0.6f);
}

void func_80386A90(s32 marker, s32 duration) {
    Actor * actor = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    f32 duration_f = reinterpret_cast(f32, duration);
    animctrl_setTransitionDuration(actor->animctrl, duration_f);
}

void func_80386AC8(s32 arg0) {
    static struct31s D_8038D350 = {{2.2f, 2.8f}, {6.3f, 9.4f}, {0.0f, 0.05f}, {10.0f, 10.0f}, 0.2f, 0.9f};
    Actor *actor;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    actor = marker_getActor(reinterpret_cast(ActorMarker *, arg0));
    pCtrl = partEmitList_pushNew(10);
    func_8034A174((struct5Bs *)actor->marker->unk44, 0xA, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setModel(pCtrl, 0x47B);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -350.0f, -400.0f, -350.0f, 350.0f, 450.0f, 350.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1100.0f, 0.0f, 0.0f, -1100.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -50.0f, 600.0f, -50.0f, 50.0f, 600.0f, 50.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D350);
    particleEmitter_emitN(pCtrl, 10);
}

void func_80386C34(s32 arg0) {
    static struct31s D_8038D378 = {{3.0f, 6.0f}, {6.3f, 9.4f}, {0.0f, 0.05f}, {10.0f, 10.0f}, 0.0f, 0.9f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(15);
    func_8034A174((struct5Bs *)sp44->marker->unk44, 0xA, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setModel(pCtrl, 0x47B);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -350.0f, -400.0f, -350.0f, 350.0f, 450.0f, 350.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1100.0f, 0.0f, 0.0f, -1100.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -50.0f, 600.0f, -50.0f, 50.0f, 600.0f, 50.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D378);
    particleEmitter_emitN(pCtrl, 15);
}

void func_80386DA0(s32 arg0) {
    static struct31s D_8038D3A0 = {{10.0f, 10.0f}, {100.0f, 100.0f}, {0.0f, 0.05f}, {10.0f, 10.0f}, 0.3f, 0.9f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(1);
    func_8034A174((struct5Bs *) (struct5Bs *)sp44->marker->unk44, 0xA, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setModel(pCtrl, 0x47B);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -700.0f, 0.0f, 0.0f, -700.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -50.0f, 1500.0f, -50.0f, 50.0f, 1500.0f, 50.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D3A0);
    particleEmitter_emitN(pCtrl, 1);
}

void func_80386EF8(s32 arg0) {
    static struct31s D_8038D3C8 = {{0.05f, 0.1f}, {0.0f, 0.0f}, {0.0f, 0.05f}, {4.0f, 4.0f}, 0.0f, 0.3f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(8U);
    func_8034A174((struct5Bs *)sp44->marker->unk44, 5, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setModel(pCtrl, 0x344);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -150.0f, 150.0f, -150.0f, 150.0f, 360.0f, 150.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -600.0f, 0.0f, 0.0f, -600.0f, 0.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D3C8);
    particleEmitter_emitN(pCtrl, 8);
}

void func_8038702C(s32 arg0) {
    static struct31s D_8038D3F0 = {{0.2f, 0.25f}, {0.35f, 0.4f}, {0.0f, 0.05f}, {4.0f, 4.0f}, 0.0f, 0.8f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(8U);
    particleEmitter_setSprite(pCtrl, 0x712);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_8034A174((struct5Bs *)sp44->marker->unk44, 5, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -250.0f, 250.0f, -250.0f, 250.0f, 360.0f, 250.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    func_802EF9F8(pCtrl, 0.4f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D3F0);
    particleEmitter_emitN(pCtrl, 8);
}

void func_80387170(s32 arg0) {
    static struct31s D_8038D418 ={{0.2f, 0.25f}, {0.35f, 0.4f}, {0.0f, 0.05f}, {4.0f, 4.0f}, 0.0f, 0.8f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(8);
    particleEmitter_setSprite(pCtrl, 0x712);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_8034A174((struct5Bs *)sp44->marker->unk44, 6, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -250.0f, 250.0f, -250.0f, 250.0f, 360.0f, 250.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    func_802EF9F8(pCtrl, 0.4f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D418);
    particleEmitter_emitN(pCtrl, 8);
}

void func_803872B4(s32 arg0) {
    static struct40s D_8038D440 = {{{1.8f, 1.8f}, {3.3f, 3.8f}, {0.0f, 0.01f}, {9.0f, 9.5f}, 0.1f, 0.4f}, 4.0f, 4.0f};
    static struct42s D_8038D470 = {
        {{  40.0f,  5.0f,  -40.0f}, { 40.0f, 10.0f, -40.0f}}, 
        {{-150.0f, 50.0f, -150.0f}, {150.0f, 50.0f, 150.0f}} 
    };
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(4);
    particleEmitter_setSprite(pCtrl, 0x70D);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EF9E4(pCtrl, 0x82);
    func_8034A174((struct5Bs *)sp44->marker->unk44, 7, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D470);
    func_802EFB98(pCtrl, &D_8038D440);
    particleEmitter_emitN(pCtrl, 4);
}

void func_80387364(s32 arg0) {
    static s32 D_8038D4A0[3] = {0xA, 0xFF, 0xA};
    static struct40s D_8038D4AC = {{{2.8f, 2.8f}, {3.5f, 3.9f}, {0.0f, 0.01f}, {9.0f, 9.5f}, 0.2f, 0.8f}, 4.0f, 1.0f};
    static struct42s D_8038D4DC = {
        {{-40.0f, -30.0f, -40.0f}, {40.0f,  30.0f, 40.0f}}, 
        {{-50.0f,   0.0f, -50.0f}, {50.0f, 100.0f, 50.0f}}
    };
    Actor *sp34;
    ParticleEmitter *pCtrl;
    f32 sp24[3];

    sp34 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, 0x70D);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_8038D4A0);
    func_802EF9E4(pCtrl, 0x82);
    func_8034A174((struct5Bs *) sp34->marker->unk44, 8, sp24);
    particleEmitter_setPosition(pCtrl, sp24);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D4DC);
    func_802EFB98(pCtrl, &D_8038D4AC);
    particleEmitter_emitN(pCtrl, 1);
}

void func_80387424(s32 arg0) {
    static struct31s D_8038D50C = {{0.06f, 0.07f}, {0.07f, 0.07f}, {0.0f, 0.8f}, {1.0f, 1.1f}, 0.0f, 0.4f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(8);
    particleEmitter_setSprite(pCtrl, 0x713);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EF9E4(pCtrl, 0x64);
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -30.0f, 130.0f, -30.0f, 130.0f, 45.0f, 30.0f);
    func_802EFB98(pCtrl, &D_8038D50C);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -300.0f, 0.0f, 0.0f, -300.0f, 0.0f);
    particleEmitter_emitN(pCtrl, 8);
}

void cutscenes_func_80387560(s32 arg0) {
    static struct31s D_8038D534 = {{0.15f, 0.15f}, {0.15f, 0.15f}, {0.0f, 0.8f}, {1.0f, 1.1f}, 0.0f, 0.4f};
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(11);
    particleEmitter_setModel(pCtrl, 0x478);
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -30.0f, 130.0f, -30.0f, 130.0f, 45.0f, 30.0f);
    func_802EFB98(pCtrl, &D_8038D534);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -500.0f, 0.0f, 0.0f, -500.0f, 0.0f);
    particleEmitter_emitN(pCtrl, 11);
}

void func_80387680(s32 arg0) {
    static struct31s D_8038D55C = {{0.03f, 0.03f}, {0.03f, 0.03f}, {0.0f, 0.8f}, {1.0f, 1.1f}, 0.0f, 0.4f}; 
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(11);
    particleEmitter_setSprite(pCtrl, 0x70B);
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -30.0f, 130.0f, -30.0f, 130.0f, 45.0f, 30.0f);
    func_802EFB98(pCtrl, &D_8038D55C);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -500.0f, 0.0f, 0.0f, -500.0f, 0.0f);
    particleEmitter_emitN(pCtrl, 11);
}

void func_803877A0(s32 arg0) {
    static s32 D_8038D584[3] = {0xFF, 0xFF, 0xFF};
    static struct40s D_8038D590 = {{{0.15f, 0.15f}, {0.4f, 0.4f}, {0.0f, 0.01f}, {4.0f, 4.5f}, 0.2f, 0.8f}, 4.0f, 1.0f};
    static struct42s D_8038D5C0 = {
        {{-20.0f, 100.0f, -20.0f}, {20.0f, 150.0f, 20.0f}},
        {{  0.0f,   0.0f,   0.0f}, { 0.0f,   0.0f,  0.0f}} 
    };
    Actor *sp34;
    ParticleEmitter *pCtrl;
    f32 sp24[3];

    sp34 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, 0x475);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_8038D584);
    func_802EF9E4(pCtrl, 0xFF);
    func_802EFF5C(pCtrl, 0.1f, 0.2f, 0.0f);
    func_802EFF7C(pCtrl, 0.0f, 0.25f, 0.0f);
    func_802EFF9C(pCtrl, 0.5f);
    func_8034A174((struct5Bs *) sp34->marker->unk44, 6, sp24);
    particleEmitter_setPosition(pCtrl, sp24);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D5C0);
    func_802EFB98(pCtrl, &D_8038D590);
    particleEmitter_emitN(pCtrl, 1);
}

void func_803878A4(s32 arg0) {
    static struct31s D_8038D5F0 = {{1.6f, 1.6f}, {1.6f, 1.6f}, {0.0f, 0.05f}, {4.0f, 4.0f}, 0.0f, 0.3f}; 
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(1);
    func_8034A174((struct5Bs *) sp44->marker->unk44, 8, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setModel(pCtrl, 0x47A);
    func_802EFE24(pCtrl, -10.0f, -10.0f, -10.0f, 10.0f, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1000.0f, 0.0f, 0.0f, -1000.0f, 0.0f);
    func_802EF9F8(pCtrl, 0.3f);
    func_802EFA18(pCtrl, 3);
    func_802EFA70(pCtrl, 2);
    func_802EFB98(pCtrl, &D_8038D5F0);
    func_802EF9EC(pCtrl, 0x21, 0x3A98);
    particleEmitter_emitN(pCtrl, 1);
}

void cutscenes_func_803879E0(s32 arg0) {
    static struct31s D_8038D618 = {{1.6f, 1.6f}, {1.6f, 1.6f}, {0.0f, 3.0f}, {4.0f, 4.0f}, 0.0f, 0.3f}; 
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(2);
    func_8034A174((struct5Bs *) sp44->marker->unk44, 8, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setModel(pCtrl, 0x47A);
    func_802EFE24(pCtrl, -10.0f, -10.0f, -10.0f, 10.0f, 10.0f, 10.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -40.0f, 0.0f, -40.0f, 40.0f, 20.0f, 40.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1000.0f, 0.0f, 0.0f, -1000.0f, 0.0f);
    func_802EF9F8(pCtrl, 0.3f);
    func_802EFA18(pCtrl, 3);
    func_802EFA70(pCtrl, 2);
    func_802EFB98(pCtrl, &D_8038D618);
    func_802EF9EC(pCtrl, 0x21, 0x3A98);
    particleEmitter_emitN(pCtrl, 2);
}

void func_80387B58(s32 arg0) {
    static struct40s D_8038D640 = {{{0.5f, 0.8f}, {3.2f, 3.8f}, {0.0f, 0.3f}, {0.5f, 0.6f}, 0.2f, 0.8f}, 4.0f, 4.0f };
    static struct42s D_8038D670 = {
        {{  0.0f, 100.0f,   0.0f}, { 0.0f, 100.0f,  0.0f}}, 
        {{-20.0f, -20.0f, -20.0f}, {20.0f,  20.0f, 20.0f}} 
    };
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, 0x702);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EF9E4(pCtrl, 0x3C);
    func_802EFE24(pCtrl, -60.0f, -60.0f, -60.0f, 60.0f, 60.0f, 60.0f);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -290.0f, 0.0f, 0.0f, -290.0f, 0.0f);
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    particleEmitter_setPosition(pCtrl, sp34);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D670);
    func_802EFB98(pCtrl, &D_8038D640);
    particleEmitter_emitN(pCtrl, 1);
}

void func_80387C64(s32 arg0) {
    static s32 D_8038D6A0[3] = {0x3C, 0x3C, 0xFF};
    static struct40s D_8038D6AC = {
        {{0.5f, 0.6f}, {1.4f, 1.6f}, {0.0f, 0.2f}, {0.9f, 1.2f}, 0.2f, 0.8f}, 4.0f, 4.0f
    };
    static struct42s D_8038D6DC ={
        {{ 0.0f,  0.0f,  0.0f}, {0.0f, 0.0f, 0.0f}},
        {{-5.0f, -5.0f, -5.0f}, {5.0f, 5.0f, 5.0f}}
    }; 
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    if (func_802582EC(sp34) == 0) {
        pCtrl = partEmitList_pushNew(1);
        particleEmitter_setSprite(pCtrl, 0x70D);
        particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
        func_802EFFA8(pCtrl, D_8038D6A0);
        func_802EF9E4(pCtrl, 0x64);
        func_802EFE24(pCtrl, -60.0f, -60.0f, -60.0f, 60.0f, 60.0f, 60.0f);
        particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -30.0f, 0.0f, 0.0f, -30.0f, 0.0f);
        particleEmitter_setPosition(pCtrl, sp34);
        particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D6DC);
        func_802EFB98(pCtrl, &D_8038D6AC);
        particleEmitter_emitN(pCtrl, 1);
    }
}

void func_80387D88(s32 arg0) {
    static struct40s D_8038D70C = {{{0.2f, 0.2f}, {0.3f, 0.3f}, {0.0f, 0.2f}, {0.7f, 0.9f}, 0.2f, 0.8f}, 4.0f, 4.0f};
    static struct42s D_8038D73C = {
        {{-800.0f, -800.0f, -800.0f}, {800.0f, 800.0f, 800.0f}},
        {{ -25.0f,  -25.0f,  -25.0f}, { 25.0f,  25.0f,  25.0f}} 
    };
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    if (func_802582EC(sp34) == 0) {
        pCtrl = partEmitList_pushNew(25);
        particleEmitter_setSprite(pCtrl, 0x713);
        particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
        func_802EF9E4(pCtrl, 0xFF);
        func_802EFE24(pCtrl, -60.0f, -60.0f, -60.0f, 60.0f, 60.0f, 60.0f);
        particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -30.0f, 0.0f, 0.0f, -30.0f, 0.0f);
        particleEmitter_setPosition(pCtrl, sp34);
        particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D73C);
        func_802EFB98(pCtrl, &D_8038D70C);
        particleEmitter_emitN(pCtrl, 25);
    }
}

void func_80387E9C(s32 arg0) {
    static s32 D_8038D76C[3] = {0x32, 0xFF, 0x46};
    static struct40s D_8038D778 ={{{0.2f, 0.2f}, {3.3f, 3.3f}, {0.0f, 0.2f}, {0.6f, 0.7f}, 0.1f, 0.9f}, 4.0f, 4.0f};
    static struct42s D_8038D7A8 = {
        {{0,0,0}, {0,0,0}},
        {{0,0,0}, {0,0,0}}
    };
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    if (func_802582EC(sp34) == 0) {
        pCtrl = partEmitList_pushNew(1);
        particleEmitter_setSprite(pCtrl, 0x70D);
        particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
        func_802EF9E4(pCtrl, 0xC8);
        func_802EFFA8(pCtrl, D_8038D76C);
        func_802EFE24(pCtrl, -60.0f, -60.0f, -60.0f, 60.0f, 60.0f, 60.0f);
        particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -30.0f, 0.0f, 0.0f, -30.0f, 0.0f);
        particleEmitter_setPosition(pCtrl, sp34);
        particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D7A8);
        func_802EFB98(pCtrl, &D_8038D778);
        particleEmitter_emitN(pCtrl, 1);
    }
}

void func_80387FC0(s32 arg0) {
    static struct40s D_8038D7D8 = {{{0.4f, 0.4f}, {3.7f, 3.8f}, {0.0f, 0.03f}, {0.6f, 0.6f}, 0.1f, 0.8f}, 4.0f, 4.0f};
    static struct42s D_8038D808 = {
        {{0,0,0}, {0,0,0}},
        {{0,0,0}, {0,0,0}}
    };

    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    if (func_802582EC(sp34) == 0) {
        pCtrl = partEmitList_pushNew(1);
        particleEmitter_setSprite(pCtrl, 0x70D);
        particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
        func_802EF9E4(pCtrl, 0x64);
        func_802EFE24(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, 200.0f, 0.0f, 0.0f, 200.0f, 0.0f);
        particleEmitter_setPosition(pCtrl, sp34);
        particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D808);
        func_802EFB98(pCtrl, &D_8038D7D8);
        particleEmitter_emitN(pCtrl, 1);
    }
}

void func_803880C8(s32 arg0) {
    static s32 D_8038D838[3] = {0xFF, 0xFF, 0XFF};
    static struct40s D_8038D844 = {{{0.15f, 0.15f}, {0.4f, 0.4f}, {0.0f, 0.01f}, {4.0f, 4.5f}, 0.2f, 0.8f}, 4.0f, 1.0f}; 
    static struct42s D_8038D874 = {
        {{-20.0f, 70.0f, -20.0f}, {20.0f, 100.0f, 20.0f}},
        {{  0.0f,  0.0f,   0.0f}, { 0.0f,   0.0f,  0.0f}} 
    };
    Actor *sp34;
    ParticleEmitter *pCtrl;
    f32 sp24[3];

    sp34 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, 0x47C);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_8038D838);
    func_802EF9E4(pCtrl, 0x82);
    func_802EFF5C(pCtrl, 0.1f, 0.2f, 0);
    func_802EFF7C(pCtrl, 0, 0.25f, 0);
    func_802EFF9C(pCtrl, 0.5f);
    func_8034A174((struct5Bs *) sp34->marker->unk44, 5, sp24);
    particleEmitter_setPosition(pCtrl, sp24);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D874);
    func_802EFB98(pCtrl, &D_8038D844);
    particleEmitter_emitN(pCtrl, 1);
}

void func_803881CC(s32 arg0) {
    static struct40s D_8038D8A4 = {{{0.6f, 0.6f}, {3.0f, 3.4f}, {0.0f, 0.03f}, {1.0f, 1.3f}, 0.1f, 0.6f}, 4.0f, 4.0f}; 
    static struct42s D_8038D8D4 = {
        {{  0.0f,   0.0f, -200.0f}, { 0.0f,  0.0f, -370.0f}}, /* position*/
        {{-40.0f, -40.0f,  -40.0f}, {40.0f, 40.0f,   40.0f}} /* velocity*/
    };
    Actor *sp44;
    ParticleEmitter *pCtrl;
    f32 sp34[3];

    sp44 = marker_getActor(reinterpret_cast(ActorMarker *,arg0));
    func_8034A174((struct5Bs *) sp44->marker->unk44, 5, sp34);
    if (func_802582EC(sp34) == 0) {
        pCtrl = partEmitList_pushNew(2);
        particleEmitter_setSprite(pCtrl, 0x70D);
        particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
        func_802EF9E4(pCtrl, 0x50);
        func_802EFE24(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, 100.0f, 0.0f, 0.0f, 300.0f, 0.0f);
        particleEmitter_setPosition(pCtrl, sp34);
        particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D8D4);
        func_802EFB98(pCtrl, &D_8038D8A4);
        particleEmitter_emitN(pCtrl, 2);
    }
}

void func_803882D4(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.0952f, 0xAD8075U);
    func_80288F78(arg0, 0.5279f, 0xAD8C94U);
    func_8028913C(arg0, 1);
    func_80288F78(arg0, 0.55f, 0xC580FAU);
    func_80288F78(arg0, 0.8658f, 0xCCD9FAU);
    func_80288F78(arg0, 0.9485f, 0x2F8CC3U);
}

void func_8038837C(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.03f, 0x012A8CFAU);
}

void cutscenes_func_803883AC(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.0282f, 0x012A8CFAU);
    func_80288F78(arg0, 0.6107f, 0x207375U);
    func_80288F78(arg0, 0.6107f, 0xF9534EU);
    func_80288F78(arg0, 0.6664f, 0x208075U);
    func_80288F78(arg0, 0.6664f, 0xF9594EU);
    func_80288F78(arg0, 0.7421f, 0x207975U);
    func_80288F78(arg0, 0.7421f, 0xF9554EU);
    func_80288F78(arg0, 0.9772f, 0x2794EU);
}

void func_80388490(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.025f, 0x69936U);
    func_80288F78(arg0, 0.52f, 0x67336U);
}

void func_803884DC(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 4, 0);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.01f, func_8038684C);
    func_8028913C(arg0, 7);
    func_80288EB0(arg0, 0.02f, 0, 35.0f, 0.8f);
    func_8028913C(arg0, 7);
    func_80288D40(arg0, 0.02f, func_80386C34, arg1);
    func_8028913C(arg0, 0xB);
    func_80288D40(arg0, 0.5f, func_80386AC8, arg1);
    func_8028913C(arg0, 0xB);
    func_80288D40(arg0, 0.7f, func_80386DA0, arg1);
    func_8028913C(arg0, 5);
    func_80288F78(arg0, 0.149f, 0x017C80FA);
    func_8028913C(arg0, 0xB);
    func_80288F78(arg0, 0.2f, 0x017D80FA);
}

void cutscenes_func_80388660(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 4, 0);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.01f, func_803868B8);
    func_8028913C(arg0, 1);
    func_80288F78(arg0, 0.149f, 0x017C80FAU);
    func_80288F78(arg0, 0.79f, 0x280C3U);
}

void func_80388734(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 4, 0);
}

void func_803887A0(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 3, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 4, 1);
}

void func_80388814(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 4, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.001f, arg1, 5, 1);
    func_80288F78(arg0, 0.016f, 0x87955U);
    func_80288F78(arg0, 0.18f, 0x88C55U);
    func_80288F78(arg0, 0.34f, 0x88055U);
    func_80288F78(arg0, 0.498f, 0x88655U);
    func_80288F78(arg0, 0.68f, 0x88C55U);
    func_80288F78(arg0, 0.831f, 0x87955U);
}

void func_80388920(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.021f, arg1, 4, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.021f, arg1, 5, 1);
    func_80288F78(arg0, 0.49f, 0x8D93EU);
    func_80288F78(arg0, 0.99f, 0x8C03EU);
}

void func_803889CC(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.05f, arg1, 4, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.05f, arg1, 5, 1);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.05f, func_80386504);
}

void func_80388A6C(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.02f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.02f, arg1, 5, 2);
    func_80361D7C(arg0, 0.13f, arg1, 5, 0x4CA675U);
    func_80361D7C(arg0, 0.48f, arg1, 5, 0x4CA675U);
    func_80361D7C(arg0, 0.57f, arg1, 5, 0x4CA675U);
}

void func_80388B58(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.021f, arg1, 4, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.021f, arg1, 5, 1);
}

void func_80388BCC(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.021f, arg1, 4, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.021f, arg1, 5, 1);
}

void func_80388C40(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.151f, 0x5D59C3U);
    func_80288F78(arg0, 0.5662f, 0x5E59C3U);
    func_80288D40(arg0, 0.56f, func_803880C8, arg1);
    func_80288D40(arg0, 0.71f, func_803880C8, arg1);
    func_80288D40(arg0, 0.86f, func_803880C8, arg1);
}

void func_80388CE4(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.16f, 0x01054CC3U);
    func_80288F78(arg0, 0.7496f, 0x01054CC3U);
}

void func_80388D30(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.0257f, 0x6B40FFU);
    func_80288F78(arg0, 0.6287f, 0x6C80FAU);
    func_80288F78(arg0, 0.7126f, 0x3F9965U);
    func_80288F78(arg0, 0.77f, 0x409965U);
    func_80288F78(arg0, 0.8079f, 0x3F9965U);
    func_80288F78(arg0, 0.9142f, 0x409965U);
}

void func_80388DE4(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.0145f, 0x6B73FFU);
    func_80288F78(arg0, 0.6245f, 0x6C80FAU);
}

void func_80388E30(s32 arg0, s32 arg1) {
    f32 sp2C;

    sp2C = 0.8f;
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 0);
    func_8028913C(arg0, 1);
    func_80288D84(arg0, 0.01f, func_80386A90, arg1, reinterpret_cast(s32, sp2C));
}

void func_80388EE0(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 0);
    func_80288F78(arg0, 0.1667f, 0xC680FFU);
    func_80288F78(arg0, 0.4114f, 0x2C80FFU);
    func_80288F78(arg0, 0.8132f, 0xC580FFU);
}

void func_80388F9C(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 0);
    func_80361D7C(arg0, 0.2452f, arg1, 5, 0x6F804EU);
    func_80361D7C(arg0, 0.2858f, arg1, 5, 0x6F804EU);
    func_80361D7C(arg0, 0.4616f, arg1, 5, 0x6F804EU);
    func_80361D7C(arg0, 0.4826f, arg1, 5, 0x6F804EU);
    func_80361D7C(arg0, 0.7155f, arg1, 5, 0x6F804EU);
    func_80361D7C(arg0, 0.7384f, arg1, 5, 0x6F804EU);
}

void func_803890CC(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, reinterpret_cast(s32, arg1), 3, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_80361D7C(arg0, 0.08f, arg1, 5, 0x6DB375U);
    func_80288D40(arg0, 0.08f, cutscenes_func_80387560, arg1);
    func_80361D7C(arg0, 0.2f, arg1, 5, 0x6DB375U);
    func_80288D40(arg0, 0.2f, cutscenes_func_80387560, arg1);
    func_80361D7C(arg0, 0.3f, arg1, 5, 0x6DB375U);
    func_80288D40(arg0, 0.3f, cutscenes_func_80387560, arg1);
}

void cutscenes_func_80389204(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, reinterpret_cast(s32, arg1), 3, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_80361D7C(arg0, 0.08f, arg1, 5, 0x6DB34EU);
    func_80288D40(arg0, 0.08f, func_80387680, arg1);
    func_80361D7C(arg0, 0.2f, arg1, 5, 0x6DB34EU);
    func_80288D40(arg0, 0.2f, func_80387680, arg1);
    func_80361D7C(arg0, 0.3f, arg1, 5, 0x6DB34EU);
    func_80288D40(arg0, 0.3f, func_80387680, arg1);
}

void func_8038933C(s32 arg0, s32 arg1) {
    func_80288FD8(arg0, 0.1f, 0xA60000U);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 2, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 1);
    func_80361D7C(arg0, 0.3f, arg1, 5, 0xB4B3EAU);
    func_80361D7C(arg0, 0.6f, arg1, 5, 0x1F809CU);
    func_80361D7C(arg0, 0.65f, arg1, 5, 0x98A675U);
    func_80361D7C(arg0, 0.81f, arg1, 5, 0x98A675U);
    func_80361D7C(arg0, 0.93f, arg1, 5, 0x98A675U);
    func_80288FA8(arg0, 0.99f, 0xA6);
}

void func_80389498(s32 arg0, s32 arg1) {
    func_80288D40(arg0, 0.06f, func_80386EF8, reinterpret_cast(s32, arg1));
    func_80288F78(arg0, 0.06f, 0x03F9B3FAU);
}

void func_803894E8(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.1961f, 0x98A6A4U);
    func_80288F78(arg0, 0.2914f, 0x98A6A4U);
    func_80288F78(arg0, 0.3741f, 0x98A6A4U);
    func_80288F78(arg0, 0.4627f, 0x98A6A4U);
    func_80288F78(arg0, 0.5551f, 0x98A6A4U);
    func_80288F78(arg0, 0.6374f, 0x98A6A4U);
    func_80288F78(arg0, 0.7178f, 0x98A6A4U);
    func_80288F78(arg0, 0.8202f, 0x98A6A4U);
    func_80288F78(arg0, 0.9137f, 0x98A6A4U);
}

void func_803895CC(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.204f, 0x98A6A4U);
    func_80288F78(arg0, 0.304f, 0x98A6A4U);
    func_80288F78(arg0, 0.3977f, 0x98A6A4U);
    func_80288F78(arg0, 0.5139f, 0x98A6A4U);
    func_80288F78(arg0, 0.6923f, 0x98A6A4U);
    func_80288F78(arg0, 0.9106f, 0x8B80FAU);
    func_80288F78(arg0, 0.9109f, 0x8B80FAU);
}

void func_80389698(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.0221f, 0x4480FAU);
}

void func_803896C8(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.001f, reinterpret_cast(s32, arg1), 1, 1);
    func_80361C64(arg0, 0.023f, arg1, 6, 1);
    func_80361C64(arg0, 0.023f, arg1, 5, 0);
    func_80361C64(arg0, 0.023f, arg1, 7, 0);
    func_80288EB0(arg0, 0.035f, 0, 30.0f, 0.4f);
    func_80361C64(arg0, 0.3f, arg1, 7, 1);
    func_80361C24(arg0, 0.31f, arg1, 6);
    func_80288EB0(arg0, 0.3209f, 0, 30.0f, 0.4f);
    func_80361C64(arg0, 0.66f, arg1, 5, 1);
    func_80288D40(arg0, 0.66f, func_80387E9C, arg1);
    func_80288F78(arg0, 0.66f, 0x3080FAU);
    func_80361C24(arg0, 0.65f, arg1, 7);
}

void cutscenes_func_80389850(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.36f, arg1, 7, 0);
    func_80361C64(arg0, 0.618f, arg1, 7, 1);
    func_80361C64(arg0, 0.696f, arg1, 5, 1);
}

void cutscenes_func_803898C8(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.03f, reinterpret_cast(s32, arg1), 7, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.03f, arg1, 5, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.03f, arg1, 4, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.03f, arg1, 6, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.03f, arg1, 8, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.1f, arg1, 9, 1);
    func_80288F78(arg0, 0.08f, 0x6080C3U);
    func_80288F78(arg0, 0.35f, 0x280D2U);
    func_80288D40(arg0, 0.45f, func_803877A0, arg1);
    func_80288F78(arg0, 0.45f, 0x03ED8027U);
    func_80288D40(arg0, 0.55f, func_803877A0, arg1);
    func_80288F78(arg0, 0.55f, 0x03ED8027U);
    func_80288D40(arg0, 0.65f, func_803877A0, arg1);
    func_80288F78(arg0, 0.65f, 0x03ED8027U);
    func_80288D40(arg0, 0.75f, func_803877A0, arg1);
    func_80288F78(arg0, 0.75f, 0x03ED8027U);
}

void func_80389AD0(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.03f, arg1, 7, 0);
    func_80361C64(arg0, 0.03f, arg1, 5, 0);
    func_80361C64(arg0, 0.03f, arg1, 4, 0);
    func_80361C64(arg0, 0.03f, arg1, 6, 0);
    func_80361C64(arg0, 0.03f, arg1, 8, 0);
}

void func_80389B84(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.001f, 0x1F73D2U);
    func_80288D40(arg0, 0.001f, func_80387D88, arg1);
    func_80288F78(arg0, 0.001f, 0x8299D2U);
    func_80288F78(arg0, 0.003f, 0x66CCFAU);
    func_80288EB0(arg0, 0.001f, 2, 50.0f, 0.5f);
}

void func_80389C30(s32 arg0, s32 arg1) {
    func_80288D40(arg0, 0.1f, func_80387C64, reinterpret_cast(s32, arg1));
    func_80288D40(arg0, 0.2f, func_80387C64, arg1);
    func_80288D40(arg0, 0.3f, func_80387C64, arg1);
    func_80288D40(arg0, 0.4f, func_80387C64, arg1);
    func_80288D40(arg0, 0.5f, func_80387C64, arg1);
    func_80288D40(arg0, 0.6f, func_80387C64, arg1);
    func_80288D40(arg0, 0.7f, func_80387C64, arg1);
    func_80288D40(arg0, 0.8f, func_80387C64, arg1);
    func_80288D40(arg0, 0.9f, func_80387C64, arg1);
}

void func_80389D34(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.02f, arg1, 1, 0);
}

void func_80389D78(s32 arg0, s32 arg1) {
    func_80288D08(arg0, 0.01f, func_803864AC);
    func_80288D08(arg0, 0.0f, func_803865F0);
    func_80288F78(arg0, 0.9f, 0x7F80EAU);
    func_80288EB0(arg0, 0.9f, 0, 5.0f, 0.8f);
}

void func_80389DFC(s32 arg0, s32 arg1) {
    func_80288D08(arg0, 0.01f, func_803864AC);
    func_80288D08(arg0, 0.01f, func_803865F0);
    func_80288D40(arg0, 0.8f, func_803872B4, arg1);
    func_80288F78(arg0, 0.9f, 0x7F80EAU);
    func_80288EB0(arg0, 0.9f, 0, 5.0f, 0.8f);
}

void cutscenes_func_80389EA8(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.023f, arg1, 1, 1);
    func_8028913C(arg0, 2);
    func_80288EF8(arg0, 0.6f, 0, 0.1f);
    func_8028913C(arg0, 2);
    func_80288E68(arg0, 0.6f, 0, 8.0f, 8.0f);
    func_80289090(arg0, 0.2f, 0xFF0000U, 0.4f);
    func_80289090(arg0, 0.2f, 0xFF00U, 0.4f);
    func_80289090(arg0, 0.2f, 0xFFU, 0.4f);
    func_80289090(arg0, 0.2f, 0xFFFFFFU, 0.4f);
    func_80288D40(arg0, 0.4f, func_8038702C, arg1);
    func_80288D40(arg0, 0.4f, func_80387170, arg1);
    func_8028913C(arg0, 5);
    func_80288F38(arg0, 0.95f, 0, 0.8f);
}

void func_8038A018(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.023f, arg1, 1, 0);
}

void func_8038A05C(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.02f, arg1, 1, 0);
}

void cutscenes_func_8038A0A0(s32 arg0, s32 arg1) {
    func_80288D08(arg0, 0.01f, func_803864AC);
    func_80288D08(arg0, 0.0f, func_803865F0);
    func_80288F78(arg0, 0.8f, 0xB1C075U);
    func_80288F78(arg0, 0.95f, 0xB1B375U);
    func_80288F78(arg0, 0.97f, 0x7F80EAU);
    func_80288EB0(arg0, 0.97f, 0, 5.0f, 0.8f);
}

void func_8038A15C(s32 arg0, s32 arg1) {
    func_80288D08(arg0, 0.01f, func_803864AC);
    func_80288D08(arg0, 0.01f, func_803865F0);
    func_80288D40(arg0, 0.01f, func_80387364, arg1);
    func_80288D40(arg0, 0.15f, func_80387364, arg1);
    func_80288D40(arg0, 0.3f, func_80387364, arg1);
    func_80288D40(arg0, 0.5f, func_80387364, arg1);
    func_80288F78(arg0, 0.97f, 0x7F80EAU);
    func_80288EB0(arg0, 0.97f, 0, 5.0f, 0.8f);
}

void func_8038A254(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.001f, arg1, 1, 1);
    func_80288D40(arg0, 0.4f, func_8038702C, arg1);
    func_80288D40(arg0, 0.4f, func_80387170, arg1);
    func_8028913C(arg0, 3);
    func_80288F78(arg0, 0.5f, 0x041B809CU);
}

void cutscenes_func_8038A2F0(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.023f, arg1, 1, 0);
}

void func_8038A334(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 1, 0);
    func_80288EB0(arg0, 0.1f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.1f, 0x9880C3U);
    func_80288EB0(arg0, 0.13f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.13f, 0x9880C3U);
    func_80288EB0(arg0, 0.35f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.35f, 0x9880C3U);
    func_80288EB0(arg0, 0.39f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.391f, 0x9880C3U);
    func_80288EB0(arg0, 0.43f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.43f, 0x9880C3U);
    func_80288EB0(arg0, 0.46f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.46f, 0x9880C3U);
    func_80288EB0(arg0, 0.7f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.7f, 0x9880C3U);
    func_80288EB0(arg0, 0.78f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.78f, 0x9880C3U);
    func_80288EB0(arg0, 0.93f, 0, 3.0f, 0.8f);
    func_80288F78(arg0, 0.93f, 0x9880C3U);
}

void cutscenes_func_8038A54C(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.23f, 0x013973A4U);
    func_80288F78(arg0, 0.36f, 0x01398CA4U);
    func_80288D08(arg0, 0.53f, func_80386668);
    func_80288F78(arg0, 0.53f, 0x013980A4U);
}

void func_8038A5C8(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.0511f, 0x6594EU);
    func_80288F78(arg0, 0.53f, 0x6804EU);
    func_8028913C(arg0, 1);
    func_80288F78(arg0, 0.6636f, 0xFA4C7DU);
    func_8028913C(arg0, 8);
    func_80288F78(arg0, 0.6636f, 0xFA4C7DU);
    func_8028913C(arg0, 0xF);
    func_80288F78(arg0, 0.6636f, 0xFA4C7DU);
    func_8028913C(arg0, 0x17);
    func_80288F78(arg0, 0.6636f, 0xFA4C7DU);
    func_8028913C(arg0, 0x1F);
    func_80288F78(arg0, 0.6636f, 0xFA4C7DU);
}

void func_8038A6D0(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 3);
    func_80288F78(arg0, 0.05f, 0xFA4C7DU);
    func_8028913C(arg0, 0xA);
    func_80288F78(arg0, 0.05f, 0xFA467DU);
}

void func_8038A734(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.18f, 0xD3595DU);
    func_80288F78(arg0, 0.31f, 0xD3605DU);
    func_80288F78(arg0, 0.49f, 0xD3595DU);
    func_80288F78(arg0, 0.65f, 0xD3605DU);
    func_80288F78(arg0, 0.83f, 0xD3595DU);
    func_80288F78(arg0, 0.99f, 0xD3605DU);
}

void func_8038A7E8(s32 arg0, s32 arg1) {
    func_80288D08(arg0, 0.01f, func_803866E0);
    func_80288F78(arg0, 0.23f, 0x013973A4U);
    func_80288F78(arg0, 0.36f, 0x01398CA4U);
    func_80288F78(arg0, 0.53f, 0x013980A4U);
}

void cutscenes_func_8038A864(s32 arg0, s32 arg1) {
    func_80361CF4(arg0, 0.001f, arg1, 0.7f);
    func_8028913C(arg0, 2);
    func_80288D40(arg0, 0.7f, func_80386578, arg1);
    func_8028913C(arg0, 2);
    func_80288F78(arg0, 0.7f, 0x0416736DU);
    func_8028913C(arg0, 3);
    func_80288F78(arg0, 0.6f, 0x0416736DU);
    func_8028913C(arg0, 4);
    func_80288F78(arg0, 0.6f, 0x0416736DU);
    func_80361CAC(arg0, 0.6f, arg1, 0.7f);
}

void func_8038A954(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.53f, 0x6995DU);
    func_80288F78(arg0, 0.99f, 0x6B35DU);
}

void func_8038A9A0(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.377f, 0x014280FAU);
}

void func_8038A9D0(s32 arg0, s32 arg1) {
    func_80288EB0(arg0, 0.001f, 0, 6.0f, 0.4f);
    func_80288F78(arg0, 0.001f, 0x9880B3U);
    func_80288EB0(arg0, 0.5069f, 0, 6.0f, 0.4f);
    func_80288F78(arg0, 0.5069f, 0x988CB3U);
}

void func_8038AA64(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.05f, 0xFB999CU);
    func_80288F78(arg0, 0.12f, 0x2809CU);
    func_80288F78(arg0, 0.33f, 0x2869CU);
    func_80288F78(arg0, 0.65f, 0xFB939CU);
    func_80288F78(arg0, 0.75f, 0x2799CU);
}

void func_8038AAFC(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.28f, 0x908CFAU);
    func_80288D08(arg0, 0.4f, func_80386750);
    func_80288D08(arg0, 0.4f, func_803867D0);
}

void cutscenes_func_8038AB60(s32 arg0, s32 arg1) {
    func_80361D7C(arg0, 0.21f, reinterpret_cast(s32, arg1), 5, 0x96804EU);
    func_80361D7C(arg0, 0.43f, arg1, 5, 0x96864EU);
    func_80361D7C(arg0, 0.65f, arg1, 5, 0x96884EU);
    func_80361D7C(arg0, 0.8f, arg1, 5, 0x012D889CU);
    func_80288D40(arg0, 0.98f, func_80387424, arg1);
    func_80361D7C(arg0, 0.99f, arg1, 5, 0x9680C3U);
}

void func_8038AC54(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 7, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 9, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 8, 1);
    func_80361D7C(arg0, 0.06f, arg1, 5, 0x03EA809CU);
    func_80361D7C(arg0, 0.12f, arg1, 5, 0x4E9E9CU);
    func_80361D7C(arg0, 0.24f, arg1, 5, 0x019080C3U);
    func_80361D7C(arg0, 0.32f, arg1, 5, 0x019088C3U);
    func_80361D7C(arg0, 0.36f, arg1, 5, 0x01908CC3U);
    func_80361D7C(arg0, 0.44f, arg1, 5, 0x4C809CU);
    func_80361D7C(arg0, 0.44f, arg1, 5, 0x9780EAU);
    func_80361D7C(arg0, 0.47f, arg1, 5, 0x4C809CU);
    func_80361D7C(arg0, 0.55f, arg1, 5, 0x019080C3U);
    func_80361D7C(arg0, 0.6f, arg1, 5, 0x4C809CU);
    func_80361D7C(arg0, 0.62f, arg1, 5, 0x019088C3U);
    func_80361D7C(arg0, 0.65f, arg1, 5, 0x4C809CU);
}

void func_8038AF5C(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 8, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 7, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 9, 0);
}

void func_8038B098(s32 arg0, s32 arg1) {
    f32 sp34 = 0.8f;
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, reinterpret_cast(s32, arg1), 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 7, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 9, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 8, 1);
    func_8028913C(arg0, 1);
    func_80288D84(arg0, 0.01f, func_80386A90, arg1, reinterpret_cast(s32, sp34));
}

void func_8038B214(s32 arg0, s32 arg1) {
    func_80288FD8(arg0, 0.03f, 0xA40000U);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 7, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 9, 1);
    func_80288F78(arg0, 0.21f, 0x3780C3U);
    func_80288F78(arg0, 0.04f, 0x018F80FAU);
    func_80288EB0(arg0, 0.59f, 0, 10.0f, 0.95f);
    func_80288F78(arg0, 0.59f, 0x1180C3U);
    func_80288F78(arg0, 0.59f, 0xD80C3U);
    func_80288F78(arg0, 0.6f, 0x3680C3U);
    func_80288FA8(arg0, 0.99f, 0xA4);
}

void func_8038B404(s32 arg0, s32 arg1) {
    func_80288FD8(arg0, 0.03f, 0xA70000U);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 7, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.01f, arg1, 9, 1);
    func_80361D7C(arg0, 0.4f, arg1, 5, 0x218CFAU);
    func_80361D7C(arg0, 0.49f, arg1, 5, 0x2193FAU);
    func_80361D7C(arg0, 0.58f, arg1, 5, 0x2195FAU);
    func_80361D7C(arg0, 0.66f, arg1, 5, 0x6280FAU);
    func_80288FA8(arg0, 0.73f, 0xA7);
    func_80288FD8(arg0, 0.73f, 0x570000U);
}

void func_8038B5FC(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 3, 0);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 4, 2);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 5, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 6, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 7, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 9, 1);
    func_8028913C(arg0, 1);
    func_80361C64(arg0, 0.0f, arg1, 8, 1);
}

void func_8038B744(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 0);
    func_80361C64(arg0, 0.01f, arg1, 4, 0);
    func_80361C64(arg0, 0.01f, arg1, 5, 0);
}

void func_8038B7B4(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 0);
    func_80361C64(arg0, 0.01f, arg1, 4, 0);
    func_80361C64(arg0, 0.01f, arg1, 5, 0);
    func_80288FD8(arg0, 0.03f, 0xA50000);
    func_80288EF8(arg0, 0.07f, 2, 5.0f);
    func_80288F78(arg0, 0.1f, 0x013159EAU);
    func_80288F38(arg0, 0.51f, 2, 0.8f);
    func_80288F78(arg0, 0.97f, 0x1F809CU);
    func_80288FA8(arg0, 0.99f, 0xA5);
}


void func_8038B8B8(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 0);
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_80288F78(arg0, 0.09f, 0x288075U);
    func_80288F78(arg0, 0.12f, 0x288075U);
    func_80288F78(arg0, 0.15f, 0x287975U);
    func_80288F78(arg0, 0.18f, 0x287975U);
    func_80288D40(arg0, 0.4f, func_803878A4, arg1);
}

void func_8038B9B4(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, reinterpret_cast(s32, arg1), 6, 0);
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_80288F78(arg0, 0.068f, 0x6180C3U);
    func_80288F78(arg0, 0.66f, 0x1F8075U);
    func_80288EB0(arg0, 0.66f, 0, 20.0f, 0.8f);
    func_80288D40(arg0, 0.7f, func_803878A4, arg1);
    func_80288F78(arg0, 0.76f, 0x1F8075U);
    func_80288D40(arg0, 0.77f, cutscenes_func_803879E0, arg1);
    func_80288D40(arg0, 0.86f, cutscenes_func_803879E0, arg1);
    func_80288EB0(arg0, 0.86f, 0, 20.0f, 0.9f);
    func_80288D40(arg0, 0.96f, cutscenes_func_803879E0, arg1);
}


void func_8038BB30(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 0);
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_80288F78(arg0, 0.3f, 0x698075U);
    func_80288F78(arg0, 0.6f, 0x698675U);
    func_80288F78(arg0, 0.94f, 0x697975U);
}

void func_8038BBF8(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_80288F78(arg0, 0.5f, 0x21809CU);
    func_80288EB0(arg0, 0.5f, 0, 5.0f, 0.9f);
    func_80288F78(arg0, 0.56f, 0x21839CU);
    func_80288EB0(arg0, 0.56f, 0, 5.0f, 0.9f);
    func_80288F78(arg0, 0.65f, 0x217C9CU);
    func_80288EB0(arg0, 0.65f, 0, 5.0f, 0.9f);
    func_80288F78(arg0, 0.76f, 0xD3739CU);
    func_80288F78(arg0, 0.83f, 0xD3799CU);
    func_80288F78(arg0, 0.9f, 0xD3669CU);
}

void func_8038BD2C(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 0);
    func_80361C64(arg0, 0.01f, arg1, 4, 0);
    func_80361C64(arg0, 0.01f, arg1, 5, 0);
}

void func_8038BD9C(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_80361C64(arg0, 0.01f, arg1, 5, 1);
    func_80288F78(arg0, 0.85f, 0x666C3U);
}

void func_8038BE30(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 6, 1);
    func_80288F78(arg0, 0.32f, 0x03F280C3U);
    func_80288F78(arg0, 0.4f, 0x1F8055U);
    func_80288F78(arg0, 0.44f, 0x03F280C3U);
    func_80288F78(arg0, 0.5f, 0x1F8655U);
    func_80288F78(arg0, 0.54f, 0x03F280C3U);
    func_80288F78(arg0, 0.6f, 0x1F7955U);
    func_80288F78(arg0, 0.82f, 0x280FAU);
    func_80288F78(arg0, 0.87f, 0x7805DU);
    func_80288F78(arg0, 0.92f, 0x7865DU);
    func_80288F78(arg0, 0.96f, 0x7805DU);
}

void func_8038BF5C(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, reinterpret_cast(s32, arg1), 4, 1);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.05f, func_80386924);
    func_80288D40(arg0, 0.05f, func_80387B58, arg1);
    func_80288D40(arg0, 0.15f, func_80387B58, arg1);
    func_80288D40(arg0, 0.25f, func_80387B58, arg1);
    func_80288D40(arg0, 0.35f, func_80387B58, arg1);
    func_80288D40(arg0, 0.45f, func_80387B58, arg1);
    func_80288D40(arg0, 0.55f, func_80387B58, arg1);
    func_80288D40(arg0, 0.65f, func_80387B58, arg1);
    func_80288D40(arg0, 0.75f, func_80387B58, arg1);
    func_80288D40(arg0, 0.85f, func_80387B58, arg1);
    func_80288D40(arg0, 0.95f, func_80387B58, arg1);
    func_8028913C(arg0, 0x14);
    func_80288D08(arg0, 0.05f, cutscenes_func_80386A00);
}

void cutscenes_func_8038C0DC(s32 arg0, s32 arg1) {
    func_80361C64(arg0, 0.01f, arg1, 4, 1);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.02f, func_80386990);
    func_80288F78(arg0, 0.25f, 0x8C80C3U);
    func_80288F78(arg0, 0.66f, 0x8C86C3U);
}


void cutscenes_func_8038C16C(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.2f, 0x17808CU);
}

void func_8038C19C(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.02f, cutscenes_func_803863F0);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.97f, func_80386410);
}

void func_8038C200(s32 arg0, s32 arg1) {
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.02f, func_8038645C);
    func_8028913C(arg0, 1);
    func_80288D08(arg0, 0.97f, func_80386484);
}


void func_8038C264(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.2f, 0x98808CU);
    func_80288F78(arg0, 0.27f, 0x98868CU);
    func_80288F78(arg0, 0.5f, 0x98798CU);
    func_80288F78(arg0, 0.65f, 0x98868CU);
    func_80288F78(arg0, 0.9f, 0x98808CU);
    func_80288F78(arg0, 0.95f, 0x98798CU);
}


void func_8038C314(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.14f, 0x3F803EU);
    func_80288F78(arg0, 0.75f, 0x40803EU);
}


void func_8038C35C(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.09f, 0xD0668CU);
    func_80288F78(arg0, 0.25f, 0xD0338CU);
    func_80288F78(arg0, 0.84f, 0x3F868CU);
}

void func_8038C3BC(s32 arg0, s32 arg1) {
    func_80288FD8(arg0, 0.01f, 0x430000);
    func_80288D08(arg0, 0.4f, func_80386434);
}

void func_8038C404(s32 arg0, s32 arg1) {
    func_80288F78(arg0, 0.74f, 0x1580FAU);
    func_80288D40(arg0, 0.74f, func_80387FC0, arg1);
}

void cutscenes_func_8038C454(s32 arg0, s32 arg1) {
    func_80288D40(arg0, 0.2f, func_803881CC, arg1);
    func_80288F78(arg0, 0.2f, 0x1E808CU);
    func_80288D40(arg0, 0.3f, func_803881CC, arg1);
    func_80288D40(arg0, 0.35f, func_803881CC, arg1);
}

/* .h */

Struct63s D_8038D904[] = {
    {0x1BE, func_803882D4}, 
    {0x1BF, func_8038837C}, 
    {0x1BD, cutscenes_func_803883AC}, 
    {0x1C0, func_80388490}, 
    {0x204, func_803884DC}, 
    {0x20B, cutscenes_func_80388660}, 
    {0x207, func_80388734}, 
    {0x1C5, func_803887A0}, 
    0
};

Struct63s D_8038D94C[] = {
    {0x1C7, func_80388C40}, 
    {0x1C8, func_80388CE4}, 
    0
};

Struct63s D_8038D964[] = {
    {0x2B8, func_80388A6C}, 
    {0x085, func_80388B58}, 
    {0x1D0, func_80388814}, 
    {0x093, func_80388920}, 
    {0x1D5, func_803889CC}, 
    0
};

Struct63s D_8038D994[] = {
    {0x1B8, func_80388D30}, 
    {0x1C2, func_80388DE4}, 
    0
};

Struct63s D_8038D9AC[] = {
    {0x1F8, func_80388E30}, 
    {0x13A, func_80388EE0}, 
    {0x13B, func_80388F9C}, 
    {0x296, func_803890CC}, 
    {0x2B2, cutscenes_func_80389204}, 
    {0x299, func_8038933C}, 
    0 
};

Struct63s D_8038D9E4[] = {
    {0x13D, func_80389498}, 
    0 
};

Struct63s D_8038D9F4[] = {
    {0x1D3, func_803894E8}, 
    {0x1D4, func_803895CC}, 
    {0x1CB, func_80389698}, 
    0 
};

Struct63s D_8038DA14[] = {
    {0x079, func_803896C8}, 
    {0x084, cutscenes_func_80389850}, 
    0 
};

Struct63s D_8038DA2C[] = {
    {0x163, func_80389B84}, 
    {0x0F9, func_80389C30}, 
    0 
};

Struct63s D_8038DA44[] = {
    {0x200, func_80389D34}, 
    {0x1FF, func_80389D78}, 
    {0x1FE, func_80389DFC}, 
    {0x20C, cutscenes_func_80389EA8}, 
    {0x1C1, func_8038A018}, 
    0 
};

Struct63s D_8038DA74[] = {
    {0x1D5, func_80388BCC}, 
    0 
};

Struct63s D_8038DA84[] = {
    {0x202, cutscenes_func_8038A54C}, 
    {0x201, func_8038A5C8}, 
    {0x2B6, func_8038A734}, 
    {0x2B7, func_8038A6D0}, 
    0 
};

Struct63s D_8038DAAC[] = {
    {0x202, func_8038A7E8}, 
    0 
};

Struct63s D_8038DABC[] = {
    {0x202, cutscenes_func_8038A864}, 
    0 
};

Struct63s D_8038DACC[] = {
    {0x200, func_8038A05C}, 
    {0x1FF, cutscenes_func_8038A0A0}, 
    {0x1FE, func_8038A15C}, 
    {0x20C, func_8038A254}, 
    {0x1C1, cutscenes_func_8038A2F0}, 
    {0x210, func_8038A334}, 
    0 
};

Struct63s D_8038DB04[] = {
    {0x1FA, func_8038A954}, 
    {0x1FB, func_8038A9A0}, 
    0 
};

Struct63s D_8038DB1C[] = {
    {0x1FC, func_8038A9D0}, 
    {0x1FD, func_8038AA64}, 
    0 
};

Struct63s D_8038DB34[] = {
    {0x20E, func_8038AAFC}, 
    0 
};

Struct63s D_8038DB44[] = {
    {0x292, cutscenes_func_8038AB60}, 
    0 
};

Struct63s D_8038DB54[] = {
    {0x293, func_8038AC54}, 
    {0x29A, func_8038B098}, 
    {0x295, func_8038B214}, 
    {0x29B, func_8038B404}, 
    {0x00C, func_8038AF5C}, 
    {0x2BA, func_8038B5FC}, 
    0 
};

Struct63s D_8038DB8C[] = {
    {0x291, func_8038B744}, 
    {0x294, func_8038B7B4}, 
    {0x2AE, func_8038B8B8}, 
    {0x2B1, func_8038B9B4}, 
    {0x2B0, func_8038BB30}, 
    {0x2B3, func_8038BBF8}, 
    {0x2B5, func_8038BE30}, 
    {0x2BB, func_8038BD2C}, 
    {0x2BC, func_8038BD9C}, 
    0 
};

Struct63s D_8038DBDC[] = {
    {0x297, cutscenes_func_803898C8}, 
    {0x298, func_80389AD0}, 
    0 
};


Struct63s D_8038DBF4[] = {
    {0x29E, func_8038BF5C}, 
    {0x29F, cutscenes_func_8038C0DC}, 
    0 
};


Struct63s D_8038DC0C[] = {
    {0x29C, cutscenes_func_8038C16C}, 
    {0x200, func_8038C19C}, 
    {0x295, func_8038C200}, 
    0 
};

Struct63s D_8038DC2C[] = {
    {0x2B9, func_8038C264}, 
    0 
};

Struct63s D_8038DC3C[] = {
    {0x08C, func_8038C3BC}, 
    0 
};

Struct63s D_8038DC4C[] = {
    {0x08F, func_8038C314}, 
    {0x090, func_8038C35C}, 
    0 
};

Struct63s D_8038DC64[] = {
    {0x07A, func_8038C404}, 
    0 
};

Struct63s D_8038DC74[] = {
    {0x2A0, cutscenes_func_8038C454}, 
    0 
};
