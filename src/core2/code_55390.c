#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void actor_postdrawMethod(ActorMarker *);

Actor *func_802DC320(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DC45C(Actor *this);

/* .data */
f32 D_80368040[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_8036804C = {
    MARKER_174_GAME_OVER, ACTOR_1DB_GAME_OVER, ASSET_54C_MODEL_GAME_OVER, 
    0x1, NULL, 
    func_802DC45C, func_80326224, func_802DC320,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE40;

/* .code */
Actor *func_802DC320(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 vp_position[3];
    f32 vp_rotation[3];
    f32 model_position[3];
    f32 sp34[3];

    this = marker_getActor(marker);
    modelRender_preDraw( (GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)marker);
    func_8024E258();
    vp_position[0] = 0.0f;
    vp_position[1] = 0.0f;
    vp_position[2] = 937.5f;
    vp_rotation[0] = 0.0f;
    vp_rotation[1] = 0.0f;
    vp_rotation[2] = 0.0f;
    viewport_set_position_vec3f(vp_position);
    viewport_set_rotation_vec3f(vp_rotation);
    viewport_update();
    func_8024C904(gfx, mtx);
    model_position[0] = 0.0f;
    model_position[1] = 0.0f;
    model_position[2] = 0.0f;
    sp34[0] = 0.0f;
    sp34[1] = 137.5f;
    sp34[2] = 0.0f;
    modelRender_draw(gfx, mtx, model_position, NULL, 1.0f, sp34, marker_loadModelBin(marker));
    func_8024E2FC();
    func_8024C904(gfx, mtx);
    return this;
}


void func_802DC430(Actor * this){
    D_8037DE40 = NULL;
    func_8025A7DC(COMUSIC_31_GAME_OVER);
}

void func_802DC45C(Actor *this){
    if(!this->initialized){

        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        func_803262E4(this);
        actor_collisionOff(this);
        marker_setFreeMethod(this->marker, func_802DC430);
    }
}

void func_802DC4C4(void) {
    Actor *actor;
    if (D_8037DE40 == 0) {
        actor = spawn_actor_f32(ACTOR_1DB_GAME_OVER, D_80368040, 0);
        D_8037DE40 = actor->marker;
        func_8025A58C(0, 5000);
        func_8025AB00();
        func_8025A6EC(COMUSIC_31_GAME_OVER, -1);
    }
}

void func_802DC528(NodeProp *arg0, ActorMarker *arg1){
    if(D_8037DE40 == NULL){
        __spawnQueue_add_0(func_802DC4C4);
    }
}

void func_802DC560(s32 arg0, s32 arg1){
    if(D_8037DE40 != NULL){
        comusic_8025AB44(COMUSIC_31_GAME_OVER, 0, 200);
        func_8025AABC(COMUSIC_31_GAME_OVER);
        func_80326310(marker_getActor(D_8037DE40));
    }
}

void func_802DC5B8(void){
    if(D_8037DE40 != NULL){
        func_802DC45C(marker_getActor(D_8037DE40));
        func_80326894(marker_getActor(D_8037DE40));
    }
}

void func_802DC604(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(D_8037DE40 != NULL){
        func_802DC320(D_8037DE40, gfx, mtx, vtx);
    }
}
