#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_80325794(ActorMarker *);

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
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    this = marker_getActor(marker);
    modelRender_preDraw( (GenMethod_1)func_803253A0, (s32)this);
    modelRender_postDraw((GenMethod_1)func_80325794, (s32)marker);
    func_8024E258();
    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 937.5f;
    sp4C[0] = 0.0f;
    sp4C[1] = 0.0f;
    sp4C[2] = 0.0f;
    func_8024CD88(sp58);
    func_8024CE18(sp4C);
    func_8024CFD4();
    func_8024C904(gfx, mtx);
    sp40[0] = 0.0f;
    sp40[1] = 0.0f;
    sp40[2] = 0.0f;
    sp34[0] = 0.0f;
    sp34[1] = 137.5f;
    sp34[2] = 0.0f;
    modelRender_draw(gfx, mtx, sp40, NULL, 1.0f, sp34, func_80330B1C(marker));
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
        func_803300D8(this->marker, func_802DC430);
    }
}

void func_802DC4C4(void) {
    Actor *actor;
    if (D_8037DE40 == 0) {
        actor = func_8032813C(ACTOR_1DB_GAME_OVER, D_80368040, 0);
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
