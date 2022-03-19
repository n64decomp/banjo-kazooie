#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EFF5C(ParticleEmitter*, f32, f32, f32);
extern void func_802EFF7C(ParticleEmitter*, f32, f32, f32);
extern void func_802EFF9C(ParticleEmitter*, f32);
extern void func_802F9E44(s32, f32, f32, f32, f32);

/* .data */
extern struct31s D_8038D350;
extern struct31s D_8038D378;
extern struct31s D_8038D3A0;
extern struct31s D_8038D3C8;
extern struct31s D_8038D3F0;
extern struct31s D_8038D418;
extern struct31s D_8038D440;
extern struct42s D_8038D470;
extern s32 D_8038D4A0[3];
extern struct31s D_8038D4AC;
extern struct42s D_8038D4DC;
extern struct31s D_8038D50C;
extern struct31s D_8038D534;
extern struct31s D_8038D55C;
extern s32 D_8038D584[3];
extern struct31s D_8038D590;
extern struct42s D_8038D5C0;
extern struct31s D_8038D5F0;
extern struct31s D_8038D618;
extern struct31s D_8038D640;
extern struct42s D_8038D670;
extern s32 D_8038D6A0[3];
extern struct31s D_8038D6AC;
extern struct42s D_8038D6DC;
extern struct31s D_8038D70C;
extern struct42s D_8038D73C;
extern s32 D_8038D76C[3];
extern struct31s D_8038D778;
extern struct42s D_8038D7A8;
extern struct31s D_8038D7D8;
extern struct42s D_8038D808;
extern s32 D_8038D838[3];
extern struct31s D_8038D844;
extern struct42s D_8038D874;
extern struct31s D_8038D8A4;
extern struct42s D_8038D8D4;

/* .rodata */
extern f32 D_8038E950;
extern f32 D_8038E954;

/* .code */
void func_803863F0(void){
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

void func_80386A00(void){
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

void func_80386AC8(ActorMarker *arg0) {
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386C34.s")
#else
void func_80386C34(ActorMarker *arg0) {
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
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, D_8038E950, 0.0f, 0.0f, D_8038E950, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -50.0f, 600.0f, -50.0f, 50.0f, 600.0f, 50.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D378);
    particleEmitter_emitN(pCtrl, 15);
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80386DA0.s")
#else
void func_80386DA0(ActorMarker *arg0) {
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
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -50.0f, D_8038E954, -50.0f, 50.0f, D_8038E954, 50.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFB98(pCtrl, &D_8038D3A0);
    particleEmitter_emitN(pCtrl, 1);
}
#endif

void func_80386EF8(ActorMarker *arg0) {
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

void func_8038702C(ActorMarker *arg0) {
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

void func_80387170(ActorMarker *arg0) {
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

void func_803872B4(ActorMarker *arg0) {
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

void func_80387364(ActorMarker *arg0) {
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

void func_80387424(ActorMarker *arg0) {
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

void func_80387560(ActorMarker *arg0) {
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

void func_80387680(ActorMarker *arg0) {
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

void func_803877A0(ActorMarker *arg0) {
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

void func_803878A4(ActorMarker *arg0) {
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

void func_803879E0(ActorMarker *arg0) {
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

void func_80387B58(ActorMarker *arg0) {
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

void func_80387C64(ActorMarker *arg0) {
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

void func_80387D88(ActorMarker *arg0) {
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

void func_80387E9C(ActorMarker *arg0) {
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

void func_80387FC0(ActorMarker *arg0) {
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

void func_803880C8(ActorMarker *arg0) {
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

void func_803881CC(ActorMarker *arg0) {
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
        particleEmitter_setPosition(pCtrl, &sp34);
        particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038D8D4);
        func_802EFB98(pCtrl, &D_8038D8A4);
        particleEmitter_emitN(pCtrl, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803882D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038837C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803883AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803884DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803887A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803889CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80388F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803890CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038933C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803894E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803895CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803896C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_803898C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_80389EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A9A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038A9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AA64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AB60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038AF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038B9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BBF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038BF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C0DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C35C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cutscenes/code_0/func_8038C454.s")
