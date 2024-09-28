#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8030DE44(u8, s32, f32);

struct {
    ParticleEmitter *unk0;
    u8 unk4;
    u8 sfxsourceIdx;
    u8 pad6[2];
}D_803720A0 = {NULL, 0, 0};

extern f32 D_803792F0;

void func_8034F6F0(Gfx **gdl, Mtx **mptr, s32 vptr){
    if(D_803720A0.unk0){
        particleEmitter_draw(D_803720A0.unk0, gdl, mptr, vptr);
    }
}

void func_8034F734(void){
    if(D_803720A0.unk0){
        func_8030DA44(D_803720A0.sfxsourceIdx);
        particleEmitter_free(D_803720A0.unk0);
    }
}

void func_8034F774(void){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    int s0;
    int s1;

    s0 = nodeProp_findPositionFromActorId(0x2F, &sp38);
    s1 = nodeProp_findPositionFromActorId(0x30, &sp2C);
    if( !s0 || !s1){
        D_803720A0.unk0 = NULL;
    }else{
        D_803720A0.unk0 = particleEmitter_new(10);
        particleEmitter_setSprite(D_803720A0.unk0, ASSET_70E_SPRITE_SMOKE_2);
        particleEmitter_setStartingFrameRange(D_803720A0.unk0, 0, 4);
        particleEmitter_setParticleFramerateRange(D_803720A0.unk0, 15.0f, 30.0f);
        particleEmitter_setSpawnIntervalRange(D_803720A0.unk0, 0.0f, 1.0f);
        particleEmitter_setParticleLifeTimeRange(D_803720A0.unk0, 216000.0f, 216000.0f);
        particleEmitter_setStartingScaleRange(D_803720A0.unk0, 1.8f, 2.2f);
        particleEmitter_emitUniformLine(D_803720A0.unk0, &sp38, &sp2C, 10);
        particleEmitter_setSpawnInterval(D_803720A0.unk0, 0.0f);
        D_803720A0.sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();

        sp44[0] = (sp38[0] + sp2C[0])/2;
        sp44[1] = (sp38[1] + sp2C[1])/2;
        sp44[2] = (sp38[2] + sp2C[2])/2;
        sfxsource_setSfxId(D_803720A0.sfxsourceIdx, 0x3EC);
        func_8030DD14(D_803720A0.sfxsourceIdx, 3);
        func_8030DFF0(D_803720A0.sfxsourceIdx, 1);
        sfxsource_set_position(D_803720A0.sfxsourceIdx, sp44);
        sfxsource_set_fade_distances(D_803720A0.sfxsourceIdx, 400.0f, 3200.0f);
        func_8030DE44(D_803720A0.sfxsourceIdx, 2, 0.5f);
        func_8030E2C4(D_803720A0.sfxsourceIdx);
    }
}

void func_8034F918(void){
    if(D_803720A0.unk0)
       particleEmitter_update(D_803720A0.unk0);
}
