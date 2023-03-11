#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80328B8C(Actor *, s32, f32, s32);
extern void func_803253A0(Actor *);
extern void func_80325794(ActorMarker *);
extern Actor *func_8032813C(enum actor_e id, f32[3], s32);


Actor *chOverlayPressStart_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chOverlayPressStart_update(Actor *this);


/* .data */
ActorAnimationInfo D_80368100[] = {
    {0, 0.0f},
    {0x284, 1.6f},
    {0x285, 1.6f}
};

f32 D_80368118[3] = {0.0f, 0.0f, 0.0f};

ActorInfo D_80368124 = { 
    MARKER_177_PRESS_START_OVERLAY, ACTOR_1DE_PRESS_START_OVERLAY, ASSET_55C_MODEL_PRESS_START_OVERLAY, 
    0x0, D_80368100,
    chOverlayPressStart_update, func_80326224, chOverlayPressStart_draw,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE80;
bool D_8037DE84;

/* .code */
Actor *chOverlayPressStart_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, Vtx **vptr){
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
    viewport_setPosition(sp58);
    viewport_setRotation(sp4C);
    viewport_update();
    func_8024C904(gdl, mptr);
    {sp40[0] = 0.0f; sp40[1] = 0.0f; sp40[2] = 0.0f;};
    {sp34[0] = 0.0f; sp34[1] = 400.0f; sp34[2] = 0.0f;};
    modelRender_draw(gdl, mptr, sp40, 0, 1.0f, sp34, func_80330B1C(marker));
    func_8024E2FC();
    func_8024C904(gdl, mptr);
    return actor;
}  

void chOverlayPressStart_func_802DCC78(ActorMarker *this){
    D_8037DE80 = 0;
    D_8037DE84 = 0;
}

void chOverlayPressStart_update(Actor *this){
    if(!this->initialized){
        this->initialized = 1;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        func_80328B8C(this, 1, 0.0f, 1);
        actor_playAnimationOnce(this);
        marker_setFreeMethod(this->marker, chOverlayPressStart_func_802DCC78);
    }

    if(animctrl_isStopped(this->animctrl)){
        func_80328B8C(this, 2, 0.0f, 1);
        actor_loopAnimation(this);
    }
}

void __chOverlayPressStart_spawn(void){
    if(D_8037DE80 == NULL){
        D_8037DE80 = func_8032813C(ACTOR_1DE_PRESS_START_OVERLAY, D_80368118, 0)->marker;
    }
}

void chOverlayPressStart_spawn(s32 arg0, s32 arg1){
    if(D_8037DE80 == NULL){
        __spawnQueue_add_0(__chOverlayPressStart_spawn);
    }
}

void chOverlayPressStart_func_802DCDB0(void){
    D_8037DE84 = TRUE;
}

void chOverlayPressStart_func_802DCDC0(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = D_8037DE80;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}
