#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803908F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80390BDC(Actor *this);

/* .data */
ActorInfo D_80392730 = { 0x210, 0x340, 0x4D2,
    0x0, NULL,
    func_80390BDC, actor_update_func_80326224, func_803908F0,
    0, 0, 1.0f, 0
};

/* .code */
Actor *func_803908F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->unk38_31 != 0) return this;
    
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_80390944(f32 position[3], s32 cnt, enum asset_e model_id){
    static ParticleScaleAndLifetimeRanges D_80392754 = {{0.2f, 0.4f}, {-1.0f, -1.0f}, {0.0f, 0.02f}, {2.2f, 2.2f}, 0.0f, 0.3f};
    static ParticleSettingsVelocityAccelerationPosition D_8039277C = {
        {{-300.0f,   350.0f, -300.0f}, {300.0f,   600.0f, 300.0f}}, /*position*/
        {{   0.0f, -1000.0f,    0.0f}, {  0.0f, -1000.0f,   0.0f}}, /*velocitcy*/
        {{-100.0f,     0.0f, -100.0f}, {100.0f,   200.0f, 100.0f}}  /*acceleration*/
    };
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8039277C);
    particleEmitter_setAngularVelocityRange(pCtrl,
        100.0f, 100.0f, 100.0f, 
        250.0f, 250.0f, 250.0f
    );
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_80392754);
    particleEmitter_func_802EF9F8(pCtrl, 0.6f);
    particleEmitter_func_802EFA18(pCtrl, 0);
    particleEmitter_func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setSfx(pCtrl, SFX_7B_ICE_BREAKING_1, 8000);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_80390A30(f32 position[3], s32 cnt, enum asset_e sprite_id){
    static ParticleScaleAndLifetimeRanges D_803927C4 = {{0.6f, 0.8f}, {1.0f, 1.4f}, {0.0f, 0.01f}, {1.2f, 1.8f}, 0.0f, 0.01f};
    static ParticleSettingsVelocityAccelerationPosition D_803927EC = {
        {{-200.0f,   0.0f, -200.0f}, {200.0f, 200.0f, 200.0f}}, /*position*/
        {{   0.0f, -10.0f,    0.0f}, {  0.0f, -10.0f,   0.0f}}, /*velocitcy*/
        {{ -50.0f,   0.0f,  -50.0f}, { 50.0f, 200.0f,  50.0f}}  /*acceleration*/
    };
    static s32 D_80392834[3] = {0xDC, 0xDC, 0xE6};
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setRGB(pCtrl, D_80392834);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_803927EC);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_803927C4);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_80390ABC(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    func_80390944(this->position, 0xA, 0x4D3);
    func_80390A30(this->position, 6, ASSET_700_SPRITE_DUST);
    func_8030E6D4(SFX_B6_GLASS_BREAKING_1);
    coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    this->unk38_31 = 1;
}

void func_80390B2C(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    func_803228D8();
    transitionToMap(MAP_27_FP_FREEZEEZY_PEAK, 0xd, 0);
    marker_despawn(this->marker);
}

void func_80390B70(Actor *this){
    func_80324E38(0.0f, 3);
    timed_setStaticCameraToNode(0.0f, 0);
    timedFunc_set_1(0.6f, (GenFunction_1)func_80390ABC, reinterpret_cast(s32, this->marker));
    timedFunc_set_1(2.5f, (GenFunction_1)func_80390B2C, reinterpret_cast(s32, this->marker));
}

void func_80390BDC(Actor *this) {
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;

        if (jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE)) {
            marker_despawn(this->marker);
        }
        else if (levelSpecificFlags_get(LEVEL_FLAG_29_FP_UNKNOWN)) {
            func_80390B70(this);
        }
    }
}
