#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80328B8C(Actor *, s32, f32, s32);
extern void func_803253A0(Actor *);
extern void func_80325794(ActorMarker *);
extern Actor *func_8032813C(enum actor_e id, f32[3], s32);


Actor *func_802DCB50(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DCC90(Actor *this);


/* .data */
ActorAnimationInfo D_80368100[] = {
    {0, 0.0f},
    {0x284, 1.6f},
    {0x285, 1.6f}
};

f32 D_80368118[3] = {0.0f, 0.0f, 0.0f};

ActorInfo D_80368124 = { 
    0x177, 0x1DE, 0x55C, 
    0x0, D_80368100,
    func_802DCC90, func_80326224, func_802DCB50,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE80;
bool D_8037DE84;

/* .code */
Actor *func_802DCB50(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **vptr){
    Actor * actor;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    

    actor = marker_getActor(marker);
    if(D_8037DE84)
        return actor;

    modelRender_preDraw((GenMethod_1)func_803253A0, (s32)actor);
    modelRender_postDraw((GenMethod_1)func_80325794, (s32)marker);
    func_8024E258();
    {sp58[0] = 0.0f; sp58[1] = 0.0f; sp58[2] = 1312.5f;};
    {sp4C[0] = 0.0f; sp4C[1] = 0.0f; sp4C[2] = 0.0f;};
    func_8024CD88(sp58);
    func_8024CE18(sp4C);
    func_8024CFD4();
    func_8024C904(gdl, mptr);
    {sp40[0] = 0.0f; sp40[1] = 0.0f; sp40[2] = 0.0f;};
    {sp34[0] = 0.0f; sp34[1] = 400.0f; sp34[2] = 0.0f;};
    modelRender_draw(gdl, mptr, sp40, 0, 1.0f, sp34, func_80330B1C(marker));
    func_8024E2FC();
    func_8024C904(gdl, mptr);
    return actor;
}  

void func_802DCC78(ActorMarker *this){
    D_8037DE80 = 0;
    D_8037DE84 = 0;
}

void func_802DCC90(Actor *this){
    if(!this->initialized){
        this->initialized = 1;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        func_80328B8C(this, 1, 0.0f, 1);
        actor_playAnimationOnce(this);
        func_803300D8(this->marker, func_802DCC78);
    }

    if(animctrl_isStopped(this->animctrl)){
        func_80328B8C(this, 2, 0.0f, 1);
        actor_loopAnimation(this);
    }
}

void func_802DCD34(void){
    if(D_8037DE80 == NULL){
        D_8037DE80 = func_8032813C(0x1de, D_80368118, 0)->marker;
    }
}

void func_802DCD78(s32 arg0, s32 arg1){
    if(D_8037DE80 == NULL){
        __spawnQueue_add_0(func_802DCD34);
    }
}

void func_802DCDB0(void){
    D_8037DE84 = TRUE;
}

void func_802DCDC0(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = D_8037DE80;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}
