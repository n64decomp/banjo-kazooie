#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>

extern void actor_postdrawMethod(ActorMarker *);

Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DC900(Actor *this);

/* .data */
f32 D_803680A0[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_803680AC = { 
    0x175, 0x1DC, 0x54D, 
    0x1, NULL, 
    func_802DC900, func_80326224, func_802DC7E0, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE60;

/* .code */
Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    this = marker_getActor(marker);
    modelRender_preDraw( (GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)marker);
    viewport_backupState();
    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 860.0f;
    sp4C[0] = 0.0f;
    sp4C[1] = 0.0f;
    sp4C[2] = 0.0f;
    viewport_setPosition_vec3f(sp58);
    viewport_setRotation_vec3f(sp4C);
    viewport_update();
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
    sp40[0] = 0.0f;
    sp40[1] = 0.0f;
    sp40[2] = 0.0f;
    sp34[0] = 0.0f;
    sp34[1] = -87.0f;
    sp34[2] = 0.0f;
    modelRender_draw(gfx, mtx, sp40, NULL, 1.0f, sp34, marker_loadModelBin(marker));
    viewport_restoreState();
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
    return this;
}

void func_802DC8F0(Actor *this){
    D_8037DE60 = NULL;
}

void func_802DC900(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        marker_setFreeMethod(this->marker, func_802DC8F0);
    }
}

void func_802DC960(void) {
    Actor *actor;
    if (D_8037DE60 == 0) {
        actor = actor_spawnWithYaw_f32(0x1DC, D_803680A0, 0);
        D_8037DE60 = actor->marker;
    }
}

void func_802DC9A4(s32 arg0, s32 arg1){
    if(D_8037DE60 == NULL){
        __spawnQueue_add_0(func_802DC960);
    }
}

void func_802DC9DC(s32 arg0, s32 arg1){
    if(D_8037DE60 != NULL){
        func_80326310(marker_getActor(D_8037DE60));
    }
}
