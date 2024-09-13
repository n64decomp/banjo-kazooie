#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *spawn_actor_f32(enum actor_e, f32[3], s32);
extern void actor_postdrawMethod(ActorMarker *marker);

Actor *chOverlayNoController_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chOverlayNoController_update(Actor *this);

/* .data */
ActorAnimationInfo D_80368150[] ={
    {0, 0.0f},
    {0x286, 1.1f},
    {0x287, 1.6f}
};
f32 D_80368168[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_80368174 = { 
    MARKER_178_NO_CONTROLLER_OVERLAY, ACTOR_1DF_NO_CONTROLLER_OVERLAY, ASSET_55D_MODEL_NO_CONTROLLER_OVERLAY, 
    0x0, D_80368150,
    chOverlayNoController_update, func_80326224, chOverlayNoController_draw,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *chOverlayNoController_marker;

/* .code */
Actor *chOverlayNoController_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **vptr){
    Actor * actor;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    

    actor = marker_getActor(marker);
    modelRender_preDraw((GenFunction_1)actor_predrawMethod,  (s32)actor);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)marker);
    func_8024E258();
    {sp58[0] = 0.0f; sp58[1] = 0.0f; sp58[2] = 1312.5f;};
    {sp4C[0] = 0.0f; sp4C[1] = 0.0f; sp4C[2] = 0.0f;};
    viewport_set_position_vec3f(sp58);
    viewport_set_rotation_vec3f(sp4C);
    viewport_update();
    func_8024C904(gdl, mptr);
    {sp40[0] = 0.0f; sp40[1] = 0.0f; sp40[2] = 0.0f;};
    {sp34[0] = 0.0f; sp34[1] = 165.0f; sp34[2] = 0.0f;};
    modelRender_draw(gdl, mptr, sp40, 0, 1.0f, sp34, marker_loadModelBin(marker));
    func_8024E2FC();
    func_8024C904(gdl, mptr);
    return actor;
}  

void chOverlayNoController_freeMethod(Actor *this){
    chOverlayNoController_marker = NULL;
}

void chOverlayNoController_update(Actor *this) {
    if (!this->initialized) {
        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        subaddie_set_state_with_direction(this, 1, 0.0f, 1);
        actor_playAnimationOnce(this);
        marker_setFreeMethod(this->marker, chOverlayNoController_freeMethod);
    }
    if (animctrl_isStopped(this->animctrl) != 0) {
        subaddie_set_state_with_direction(this, 2, 0.0f, 1);
        actor_loopAnimation(this);
    }
}

void __chOverlayNoController_spawn(void){
    if(chOverlayNoController_marker == NULL){
        chOverlayNoController_marker = spawn_actor_f32(ACTOR_1DF_NO_CONTROLLER_OVERLAY, D_80368168, 0)->marker;
    }
}

void chOverlayNoController_spawn(s32 arg0, s32 arg1){
    if(chOverlayNoController_marker == NULL){
        __spawnQueue_add_0(__chOverlayNoController_spawn);
    }
}

void chOverlayNoController_func_802DD040(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = chOverlayNoController_marker;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}
