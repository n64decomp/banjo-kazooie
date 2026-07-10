#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern void actor_postdrawMethod(ActorMarker *);

Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void gcBanjoKazooieSign_update(Actor *this);

/* .data */
f32 gcBanjoKazooieSignPosition[3] = {0.0f, 0.0f, 0.0f};

ActorInfo gcBanjoKazooieSign = { 
    MARKER_175_BANJO_KAZOOIE_SIGN, ACTOR_1DC_BANJO_KAZOOIE_SIGN, ASSET_54D_MODEL_BANJO_KAZOOIE_SIGN, 
    0x1, NULL, 
    gcBanjoKazooieSign_update, actor_update_func_80326224, func_802DC7E0, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *gcBanjoKazooieSignMarker;

/* .code */
Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    this = marker_getActor(marker);
    modelRender_setPreDrawCallback( (GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_setPostDrawCallback((GenFunction_1)actor_postdrawMethod, (s32)marker);
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

void gcBanjoKazooieSign_free(Actor *this){
    gcBanjoKazooieSignMarker = NULL;
}

void gcBanjoKazooieSign_update(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        marker_setFreeMethod(this->marker, gcBanjoKazooieSign_free);
    }
}

void gcBanjoKazooieSign_spawn(void) {
    Actor *actor;
    if (gcBanjoKazooieSignMarker == NULL) {
        actor = actor_spawnWithYaw_f32(ACTOR_1DC_BANJO_KAZOOIE_SIGN, gcBanjoKazooieSignPosition, 0);
        gcBanjoKazooieSignMarker = actor->marker;
    }
}

void func_802DC9A4(s32 arg0, s32 arg1){
    if(gcBanjoKazooieSignMarker == NULL){
        __spawnQueue_add_0(gcBanjoKazooieSign_spawn);
    }
}

void func_802DC9DC(s32 arg0, s32 arg1){
    if(gcBanjoKazooieSignMarker != NULL){
        func_80326310(marker_getActor(gcBanjoKazooieSignMarker));
    }
}
