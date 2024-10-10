#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void actor_postdrawMethod(ActorMarker *);

void func_802DF2C4(Actor *this);

/* .data */
f32 D_80368360[3] = {0.0f, 0.0f, 0.0f};
s32 D_8036836C[4] = {0x60, 0x60, 0x60, 0xFF};
s32 D_8036837C[4] = {0xFF, 0xFF, 0xFF, 0xFF};
ActorInfo D_8036838C = { 
    0x17B, 0x2B5, 0x472,
    0, NULL, 
    func_802DF2C4, actor_update_func_80326224, func_80325340, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037E000;
s32 D_8037E008[20];

/* .code */
Actor *func_802DF160(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    void *sp38;

    this = marker_getActor(D_8037E000);
    sp38 = func_8030C704();
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    gDPSetTextureFilter((*gfx)++, G_TF_POINT);
    gSPSegment((*gfx)++, 0x04, osVirtualToPhysical(sp38));
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)D_8037E000);
    modelRender_draw(gfx, mtx, &D_80368360, NULL, 1.0f, NULL, marker_loadModelBin(D_8037E000));
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    return this;
}

void func_802DF270(void){
    Actor *this;
    if(D_8037E000 == NULL){
        this = actor_spawnWithYaw_f32(0x2B5, D_80368360, 0);
        D_8037E000 = this->marker;
    }
}

void func_802DF2B4(Actor *this){
    D_8037E000 = NULL;
}

void func_802DF2C4(Actor *this) {
    s32 temp_fp;
    s32 i;
    s32 prev_val;
    s32 temp_v0;
    s32 val;


    temp_fp = chBottlesBonusCursor_func_802E06B4() - 0x15;
    if (!this->initialized) {
        this->initialized = TRUE;
        actor_collisionOff(this);
        for(i = 0; i < 20; i++){
            func_8034DFB0(func_8034C2C4(this->marker, i + 0x190), D_8036837C, D_8036836C, 0.0f);
        }
        marker_setFreeMethod(this->marker, func_802DF2B4);
    }
    for( i = 0; i < 20; i++){
        prev_val = D_8037E008[i];
        temp_v0 = func_8034C2C4(this->marker, i + 0x190);
        D_8037E008[i] = BOOL(i == temp_fp);
        if (prev_val != D_8037E008[i] ) {
            val = D_8037E008[i];
            switch(val){
                case TRUE: 
                    func_8034DFB0(temp_v0, D_8036836C, D_8036837C, 0.05f);
                    break;

                case FALSE:
                    func_8034DFB0(temp_v0, D_8036837C, D_8036836C, 0.2f);
                    break;
            }
        }//L802DF418
    }
}
