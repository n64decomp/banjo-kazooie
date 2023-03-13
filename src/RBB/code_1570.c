#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"




/* typedefs and declarations */
void func_803881E8(Actor *this, s32 arg1);
void RBB_func_803882F4(Actor *this);

/* .data */
ActorInfo D_80390270 = {
    0x184, 0x174, 0x402, 0x0, NULL,
    RBB_func_803882F4, NULL, func_80325340,
    0, 0, 0.0f, 0
};

s32 D_80390294[4] = { 0xff, 0, 0, 0xff};
s32 D_803902A4[4] = { 0x76, 0, 0, 0xff};
s32 D_803902B4[4] = { 0x76, 0, 0, 0xff};
s32 D_803902C4[4] = { 0xff, 0, 0, 0xff};


f32 D_803902D4[3] = {4500.0f, 0.0f, 500.0f};
f32 D_803902E0[3] = {4500.0f, 0.0f, 500.0f}; 
f32 D_803902EC[3] = {4000.0f, -600.0f, 0.0f};
f32 D_803902F8[3] = {4500.0f, 0.0f, 500.0f};
struct31s D_80390304 = {
    { 5.0f, 5.0f},
    { 5.0f, 5.0f},
    { 0.0f, 0.01f},
    { 3.0f, 5.0f},
    0.0f, 
    0.1f
};

f32 D_8039032C[3] = {3700.0f, -300.0f, -300.0f};  
f32 D_80390338[3] = {4500.0f, 100.0f, 400.0f}; 
struct41s D_80390344= {
    {{-700.0f, 200.0f, -700.0f}, {700.0f, 500.0f, 700.0f}}, 
    {{ 0.0f, -800.0f, 0.0f}, { 0.0f, -800.0f, 0.0f}}
};

/*.code */
void RBB_func_80387960(f32 arg0){
    f32 sp34[3]; 
    void * temp_v0;
    f32 sp24[3];
    
    sp34[0] = sp34[1] = sp34[2] =0.0f;
    sp24[0] = 0.0f;
    sp24[1] = 0.0f;
    sp24[2] = -40.0f;
    
    if(temp_v0 = func_8034C528(0x19e)){
        func_8034DDF0(temp_v0, &sp34, &sp24, arg0, 1);
    }
    if(temp_v0 = func_8034C528(0x19f)){
        func_8034DDF0(temp_v0, &sp34, &sp24, arg0, 1);
    }
}

void func_803879F0(void){
    s32 temp_v0 = func_8034C528(0x19b);
    f32 sp30[3];
    f32 sp24[3];
    if(temp_v0){
        TUPLE_ASSIGN(sp30, 0.0f, 0.0f, 0.0f);
        TUPLE_ASSIGN(sp24, 0.0f, -1000.0f, 0.0f);
        func_8034DC08(temp_v0, &sp30, &sp24, 1.5f, 1);
    }
}

void func_80387A54(void){
    s32 temp_v0 = func_8034C528(0x19b);
    f32 sp30[3];
    f32 sp24[3];
    if(temp_v0){
        TUPLE_ASSIGN(sp30, 0.0f, -1000.0f, 0.0f);
        TUPLE_ASSIGN(sp24, 0.0f, -2000.0f, 0.0f);
        func_8034DDF0(temp_v0, &sp30, &sp24, 1.0f, 1);
    }
}

void func_80387AC0(void){
    s32 temp_v0 = func_8034C528(0x19b);
    f32 sp30[3];
    f32 sp24[3];
    if(temp_v0){
        TUPLE_ASSIGN(sp30, 0.0f, 0.0f, 0.0f);
        TUPLE_ASSIGN(sp24, 0.0f, -2000.0f, 0.0f);
        func_8034DDF0(temp_v0, &sp30, &sp24, 0.0f, 1);
    }
}

void func_80387B24(void){
    s32 temp_v0 = func_8034C528(0x1a0);
    f32 sp30[3];
    f32 sp24[3];
    if(temp_v0){
        TUPLE_ASSIGN(sp30, 0.0f, 0.0f, 0.0f);
        TUPLE_ASSIGN(sp24, 0.0f, -500.0f, 0.0f);
        func_8034DDF0(temp_v0, &sp30, &sp24, 0.1f, 1);
    }
}

void func_80387B8C(s32 arg0, s32 arg1){
    s32 v0 = func_8034C528(arg0);
    if(v0){
        func_8034DFB0(v0, &D_80390294, &D_803902A4, (f64)arg1/1000.0);
    }
}

void func_80387BEC(s32 arg0, s32 arg1){
    s32 v0;
    func_8030E6D4(SFX_90_SWITCH_PRESS);
    if(v0 = func_8034C528(arg0)){
        func_8034DFB0(v0, &D_803902B4, &D_803902C4, (f64)arg1/1000.0);
    }
}

void func_80387C5C(void){
    ParticleEmitter *actor;

    func_802BB3DC(0, 60.0f, 0.9f);
    actor = partEmitMgr_newEmitter(1);
    particleEmitter_setSprite(actor, ASSET_4A0_SPRITE_EXPLOSION);
    particleEmitter_setFade(actor, 0.1f, 0.2f);
    particleEmitter_setDrawMode(actor, PART_EMIT_NO_LOOP);
    particleEmitter_setStartingFrameRange(actor, 0, 0);
    particleEmitter_setParticleFramerateRange(actor, 4.0f, 4.0f);
    func_802EFB70(actor, 10.0f, 10.0f);
    func_802EFB84(actor, 15.0f, 20.0f);
    particleEmitter_setParticleLifeTimeRange(actor, 4.0f, 4.0f);
    particleEmitter_setParticleVelocityRange(actor, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_emitInVolume(actor, &D_803902D4, &D_803902E0, 1);
}

void func_80387D80(void){
    ParticleEmitter *actor = partEmitMgr_newEmitter(3);
    particleEmitter_setSprite(actor, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setStartingFrameRange(actor, 0, 7);
    func_802EFB98(actor, &D_80390304);
    particleEmitter_setParticleVelocityRange(actor, 0.0f, 100.0f, 0.0f, 0.0f, 200.0f ,0.0f);
    particleEmitter_emitInVolume(actor, &D_803902EC, &D_803902F8, 3);
}

void func_80387E20(void){
    ParticleEmitter *actor = partEmitMgr_newEmitter(0x19);
    func_802EF9F8(actor, 0.6f);
    func_802EFA18(actor, 3);
    particleEmitter_setModel(actor, 0x427);
    func_802EFB70(actor, 0.05f, 0.4f);
    particleEmitter_setAngularVelocityRange(actor, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setSpawnIntervalRange(actor, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(actor, 10.0f, 10.0f);
    particleEmitter_setVelocityAndAccelerationRanges(actor, &D_80390344);
    particleEmitter_emitInVolume(actor, &D_8039032C, &D_80390338, 0x19);
}

void RBB_func_80387F18(ActorMarker *marker, s32 arg1){
    func_803881E8(marker_getActor(marker), arg1);
}

void RBB_func_80387F44(void){
    rumbleManager_80250E94(0.5f, 1.0f, 1.5f, 0.0f, 1.0f, 1.5f);
}

void func_80387F88(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);

    timedFunc_set_0(0.0f, func_80387C5C);
    timed_playSfx(0.1f, SFX_1B_EXPLOSION_1, 1.0f, 22000);
    timed_playSfx(0.1f, SFX_1B_EXPLOSION_1, 1.0f, 22000);
    timedFunc_set_0(0.3f, func_80387E20);
    timedFunc_set_0(0.5f, func_80387A54);
    timedFunc_set_0(0.4f, func_80387B24);
    timed_playSfx(0.41f, SFX_1B_EXPLOSION_1, 0.8f, 22000);
    timed_playSfx(0.41f, SFX_1B_EXPLOSION_1, 0.8f, 22000);
    timedFunc_set_0(0.55f, func_80387D80);
    timed_playSfx(0.71f, SFX_1B_EXPLOSION_1, 0.6f, 22000);
    timed_playSfx(0.71f, SFX_1B_EXPLOSION_1, 0.6f, 22000);
    timedFunc_set_0(0.8f, func_80387D80);
    timed_playSfx(1.0f, SFX_1A_BIG_THINGS_FALL_OVER, 1.0f, 22000);
    timed_playSfx(2.0f, SFX_1A_BIG_THINGS_FALL_OVER, 0.8f, 22000);
    timed_playSfx(3.0f, SFX_1A_BIG_THINGS_FALL_OVER, 0.6f, 22000);
    timed_exitStaticCamera(4.0f);
    func_80324E38(4.0f, 0);
    timedFunc_set_2(4.0f, (GenFunction_2) RBB_func_80387F18, (s32) actor->marker, 3);
}

void func_80388154(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    func_803879F0();
    timedFunc_set_0(0.0f, (GenFunction_0) RBB_func_80387F44);
    timed_playSfx(0.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 0x7fc6);
    timedFunc_set_2(1.2f, (GenFunction_2) func_80387B8C, 0x19f, 0);
    timed_setStaticCameraToNode(1.2f, 8);
    timedFunc_set_1(1.5f, (GenFunction_1) func_80387F88, (s32) actor->marker);
}

void func_803881E8(Actor *this, s32 arg1){
    this->state = arg1;
    if(this->state == 2){
        RBB_func_80387960(0.05f);
        timedFunc_set_2(0.05f, (GenFunction_2)func_80387BEC, 0x19f, 0x1f4);
        timedFunc_set_2(0.1f, (GenFunction_2)func_8025A6EC, COMUSIC_2B_DING_B, 28000);
        func_80324E38(0.2f, 3);
        timed_setStaticCameraToNode(1.1f, 7);
        timedFunc_set_1(1.6f, (GenFunction_1)func_80388154, (s32)this->marker);
        levelSpecificFlags_set(0x2D, 1);
    }
}

void func_803882B4(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1)
        func_803881E8(actor, 2);
}

void RBB_func_803882F4(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        if(levelSpecificFlags_get(0x2d)){
            func_80387AC0();
            RBB_func_80387960(0.0f);
            func_80387B24();
            func_803881E8(this, 3);
        }else{
            marker_setCollisionScripts(this->marker, NULL, func_803882B4, NULL);
            func_8032AA58(this, 1.1f);
            func_803881E8(this, 1);
        }
    }
}
