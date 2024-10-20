#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct {
    u8 sfxsourceIdx;
    f32 unk4[3];
} D_803935E0;

/* .code */
void func_803918C0(void){
    Actor *actor;
    if(map_get() == MAP_7F_FP_WOZZAS_CAVE){
        D_803935E0.sfxsourceIdx = func_8030ED2C(SFX_128_FIRE_CRACKING, 2);
        sfxsource_playSfxAtVolume(D_803935E0.sfxsourceIdx, 1.0f);
        actor  = actorArray_findActorFromActorId(0x353);
        if(actor){
            D_803935E0.unk4[0] = actor->position_x;
            D_803935E0.unk4[1] = actor->position_y;
            D_803935E0.unk4[2] = actor->position_z;
        }
        else{
            D_803935E0.unk4[0] = D_803935E0.unk4[1] = D_803935E0.unk4[2] = 0.0f;
        }
    }
}

void func_8039195C(void){
    if(D_803935E0.sfxsourceIdx){
        sfxsource_freeSfxsourceByIndex(D_803935E0.sfxsourceIdx);
        D_803935E0.sfxsourceIdx = 0;
    }
}

void func_80391994(void){
    if(map_get() == MAP_7F_FP_WOZZAS_CAVE){
        func_8030DB04(D_803935E0.sfxsourceIdx, 22000, D_803935E0.unk4, 400.0f, 1200.0f);
        func_8030E2C4(D_803935E0.sfxsourceIdx);
    }
}
