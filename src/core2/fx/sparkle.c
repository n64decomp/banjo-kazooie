#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/particle.h"

extern ParticleEmitter *func_802F3E98(f32 pos[3], enum asset_e sprite_id);

ParticleEmitter *__fxSparkle_create(s16 position[3], f32 height, enum asset_e sprite_id){
    f32 position_f[3];

    position_f[0] = (f32)position[0];
    position_f[1] = (f32)position[1];
    position_f[2] = (f32)position[2];
    position[1] += height;

    return func_802F3E98(position, sprite_id);
}

void fxSparkle_emptyHoneycomb(s16 position[3]){
    static struct42s D_80368BD0 = {
        {{-100.0f, 100.0f, -100.0f}, { 100.0f, 250.0f,  100.0f}}, 
        {{ -10.0f,  10.0f,  -10.0f}, {  10.0f,  10.0f,   10.0f}}
    };

    ParticleEmitter *p_emitter = __fxSparkle_create(position, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368BD0);
    func_802EFB70(p_emitter, 0.32f, 0.32f);
    particleEmitter_emitN(p_emitter, 10);
}

void fxSparkle_honeycomb(s16 position[3]){
    static struct42s D_80368C00 = {
        {{-100.0f, 100.0f, -100.0f}, { 100.0f, 250.0f,  100.0f}}, 
        {{ -10.0f,  10.0f,  -10.0f}, {  10.0f,  10.0f,   10.0f}} 
    };

    ParticleEmitter *p_emitter = __fxSparkle_create(position, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C00);
    func_802EFB70(p_emitter, 0.32f, 0.32f);
    particleEmitter_emitN(p_emitter, 7);
}

void fxSparkle_musicNote(s16 position[3]){
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 7.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -70.0f, 100.0f, -70.0f,
        70.0f, 250.0f, 70.0f
    );
    particleEmitter_emitN(p_emitter, 5);
}

void fxSparkle_blueEgg(s16 position[3]){
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 7.0f, ASSET_716_SPRITE_SPARKLE_WHITE);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -70.0f, 100.0f, -70.0f,
        70.0f, 250.0f, 70.0f
    );
    particleEmitter_emitN(p_emitter, 5);
}

void fxSparkle_giantBlueEgg(s16 position[3]){
    static struct42s D_80368C30 = {
        {{-200.0f, 100.0f, -200.0f}, { 200.0f, 350.0f,  200.0f}}, /*position*/
        {{ -30.0f, 100.0f,  -30.0f}, {  30.0f, 100.0f,   30.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 25.0f, ASSET_716_SPRITE_SPARKLE_WHITE);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C30);
    func_802EFB70(p_emitter, 0.5f, 0.5f);
    particleEmitter_emitN(p_emitter, 12);
    particleEmitter_setParticleLifeTimeRange(p_emitter, 1.5f, 1.5f);
}

void fxSparkle_redFeather(s16 position[3]){
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 12.0f, ASSET_715_SPRITE_SPARKLE_RED);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -75.0f, 100.0f, -75.0f,
        75.0f, 250.0f, 75.0f
    );
    func_802EFB70(p_emitter, 0.3f, 0.3f);
    particleEmitter_emitN(p_emitter, 5);
}

void fxSparkle_giantRedFeather(s16 position[3]){
    static struct42s D_80368C60 = {
        {{-125.0f, 100.0f, -125.0f}, { 125.0f, 250.0f,  125.0f}}, /*position*/
        {{ -15.0f, 100.0f,  -15.0f}, {  15.0f, 100.0f,   15.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 40.0f, ASSET_715_SPRITE_SPARKLE_RED);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C60);
    func_802EFB70(p_emitter, 0.5f, 0.5f);
    particleEmitter_emitN(p_emitter, 10);
}

void fxSparkle_goldFeather(s16 position[3]){
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 7.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setParticleVelocityRange(p_emitter, 
        -75.0f, 100.0f, -75.0f,
        75.0f, 250.0f, 75.0f
    );
    func_802EFB70(p_emitter, 0.3f, 0.3f);
    particleEmitter_emitN(p_emitter, 5);
}

void fxSparkle_giantGoldFeather(s16 position[3]){
    static struct42s D_80368C90 = {
        {{-125.0f, 100.0f, -125.0f}, { 125.0f, 250.0f,  125.0f}}, /*position*/
        {{ -15.0f, 100.0f,  -15.0f}, {  15.0f, 100.0f,   15.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 40.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368C90);
    func_802EFB70(p_emitter, 0.5f, 0.5f);
    particleEmitter_emitN(p_emitter, 10);
}

void fxSparkle_mumboToken(s16 position[3]){
    static struct42s D_80368CC0 = {
        {{-100.0f, 100.0f, -100.0f}, { 100.0f, 250.0f,  100.0f}}, /*position*/
        {{ -15.0f,  15.0f,  -15.0f}, {  15.0f,  15.0f,   15.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 10.0f, ASSET_718_SPRITE_SPARKLE_WHITE_2);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368CC0);
    func_802EFB70(p_emitter, 0.4f, 0.4f);
    particleEmitter_emitN(p_emitter, 7);
    particleEmitter_setParticleLifeTimeRange(p_emitter, 1.5f, 1.5f);
}

void fxSparkle_extraLife(s16 position[3]){
    static struct42s D_80368CF0 = {
        {{ -75.0f, 100.0f,  -75.0f}, {  75.0f, 250.0f,   75.0f}}, /*position*/
        {{  -8.0f,   5.0f,   -8.0f}, {  -5.0f,  35.0f,    8.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368CF0);
    func_802EFB70(p_emitter, 0.27f, 0.27f);
    particleEmitter_emitN(p_emitter, 5);
}

void fxSparkle_brentilda(s16 position[3]){
    static struct42s D_80368D20 = {
        {{   0.0f,   0.0f,    0.0f}, {   0.0f,   0.0f,    0.0f}}, /*position*/
        {{ -15.0f, -15.0f,  -15.0f}, {  15.0f,  15.0f,   15.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368D20);
    func_802EFB70(p_emitter, 0.25f, 0.3f);
    particleEmitter_emitN(p_emitter, 1);
}

void fxSparkle_chTreasure(s16 position[3]){
    static struct42s D_80368D50 = {
        {{   0.0f,   0.0f,    0.0f}, {   0.0f,   0.0f,    0.0f}}, /*position*/
        {{ -25.0f,  -5.0f,  -25.0f}, {  25.0f,   5.0f,   25.0f}}  /*velocity*/
    };
    ParticleEmitter *p_emitter = __fxSparkle_create(position, 10.0f, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setPositionAndVelocityRanges(p_emitter, &D_80368D50);
    func_802EFB70(p_emitter, 0.45f, 0.6f);
    particleEmitter_setParticleLifeTimeRange(p_emitter, 0.5f, 0.8f);
    particleEmitter_emitN(p_emitter, 3);
}

void fxSparkle_free(void){
    func_802F3E50();
}

void fxSparkle_init(void){
    func_802F3E74();
}
