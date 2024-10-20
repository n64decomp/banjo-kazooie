#include <ultra64.h>
#include "functions.h"
#include "variables.h"

static struct {
    u8 sound;
    f32 position[3];
} Me;

/* .code */
void func_803918C0(void){
    Actor *pntWozza;
    if(map_get() == MAP_7F_FP_WOZZAS_CAVE){
        Me.sound = func_8030ED2C(SFX_128_FIRE_CRACKING, 2);
        sfxsource_playSfxAtVolume(Me.sound, 1.0f);
        pntWozza  = actorArray_findActorFromActorId(0x353);
        if(pntWozza){
            Me.position[0] = pntWozza->position_x;
            Me.position[1] = pntWozza->position_y;
            Me.position[2] = pntWozza->position_z;
        }
        else{
            Me.position[0] = Me.position[1] = Me.position[2] = 0.0f;
        }
    }
}

void func_8039195C(void){
    if(Me.sound){
        sfxsource_freeSfxsourceByIndex(Me.sound);
        Me.sound = 0;
    }
}

void func_80391994(void){
    if(map_get() == MAP_7F_FP_WOZZAS_CAVE){
        func_8030DB04(Me.sound, 22000, Me.position, 400.0f, 1200.0f);
        func_8030E2C4(Me.sound);
    }
}
