#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *func_8032813C(enum actor_e, f32[3], s32);
extern void func_80325794(ActorMarker *marker);

Actor *func_802DCE00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DCF20(Actor *this);

/* .data */
ActorAnimationInfo D_80368150[] ={
    {0, 0.0f},
    {0x286, 1.1f},
    {0x287, 1.6f}
};
f32 D_80368168[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_80368174 = { 
    0x178, 0x1DF, 0x55D, 
    0x0, D_80368150,
    func_802DCF20, func_80326224, func_802DCE00,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE90;

/* .code */
Actor *func_802DCE00(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **vptr){
    Actor * actor;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    

    actor = marker_getActor(marker);
    func_8033A2D4(func_803253A0, actor);
    func_8033A2E8(func_80325794, marker);
    func_8024E258();
    {sp58[0] = 0.0f; sp58[1] = 0.0f; sp58[2] = 1312.5f;};
    {sp4C[0] = 0.0f; sp4C[1] = 0.0f; sp4C[2] = 0.0f;};
    func_8024CD88(sp58);
    func_8024CE18(sp4C);
    func_8024CFD4();
    func_8024C904(gdl, mptr);
    {sp40[0] = 0.0f; sp40[1] = 0.0f; sp40[2] = 0.0f;};
    {sp34[0] = 0.0f; sp34[1] = 165.0f; sp34[2] = 0.0f;};
    modelRender_draw(gdl, mptr, sp40, 0, 1.0f, sp34, func_80330B1C(marker));
    func_8024E2FC();
    func_8024C904(gdl, mptr);
    return actor;
}  

void func_802DCF10(Actor *this){
    D_8037DE90 = NULL;
}

void func_802DCF20(Actor *this) {
    if (!this->initialized) {
        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        func_80328B8C(this, 1, 0.0f, 1);
        actor_playAnimationOnce(this);
        func_803300D8(this->marker, func_802DCF10);
    }
    if (animctrl_isStopped(this->animctrl) != 0) {
        func_80328B8C(this, 2, 0.0f, 1);
        actor_loopAnimation(this);
    }
}

void func_802DCFC4(void){
    if(D_8037DE90 == NULL){
        D_8037DE90 = func_8032813C(0x1df, D_80368168, 0)->marker;
    }
}

void func_802DD008(s32 arg0, s32 arg1){
    if(D_8037DE90 == NULL){
        func_802C3BF8(func_802DCFC4);
    }
}

void func_802DD040(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = D_8037DE90;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}
