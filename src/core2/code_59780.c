#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern void func_802C71F0(Actor *);
extern void actor_postdrawMethod(ActorMarker *);

Actor *func_802E0738(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802E07E0(Actor *this);
void chFireSparkle_update(Actor *this);

/* .data */
ActorAnimationInfo chFireSparkleAnimations[] = {
    {0, 0.0f},
    {ASSET_98_ANIM_FIRE_SPARKLE, 1.2f}
};

ActorInfo chFireSparkle = {
    MARKER_72_FIRE_SPARKLE, ACTOR_A2_FIRE_SPARKLE, ASSET_3AD_FIRE_SPARKLE, 
    0x1, chFireSparkleAnimations,
    chFireSparkle_update, actor_update_func_80326224, actor_draw, 
    0, 0, 0.0f, 0
};

ActorInfo chBanjoCurtains = {
    MARKER_8C_BANJOS_CURTAINS, ACTOR_BC_BANJOS_CURTAINS, ASSET_45C_MODEL_BANJOS_CURTAINS,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo chBanjoHouseDoor = {
    MARKER_8D_BANJOS_HOUSE_DOOR, ACTOR_BD_BANJOS_HOUSE_DOOR, ASSET_45E_MODEL_BANJOS_HOUSE_DOOR,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo chFishbowl = {
    MARKER_13D_FISHBOWL, ACTOR_2F4_FISHBOWL, ASSET_46E_MODEL_FISHBOWL,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo chCuckooClock = {
    MARKER_13E_CUCKOO_CLOCK, ACTOR_2F5_CUCKOO_CLOCK, ASSET_46F_MODEL_CUCKOO_CLOCK,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_80368504 = {
    0x13F, 0x2F6, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_80368528 = {
    0x140, 0x2F7, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8036854C = {
    0x141, 0x2F8, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_80368570 = {
    0x142, 0x2F9, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

/* .code */
void func_802E0710(Actor *this){
    actor_predrawMethod(this);
    func_80361E9C(this);
}

Actor *func_802E0738(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 rotation[3];
    Actor *this;

    this = marker_getActorAndRotation(marker, &rotation);
    modelRender_setPreDrawCallback( (GenFunction_1)func_802E0710, (s32)this);
    modelRender_setPostDrawCallback((GenFunction_1)actor_postdrawMethod, (s32)marker);
    modelRender_draw(gfx, mtx, this->position, rotation, this->scale, NULL, marker_loadModelBin(marker));
    return this;
}


void func_802E07C0(Actor *this){
    func_80361DC4(this);
}

void func_802E07E0(Actor *this) {
    s32 sp24;

    switch(this->marker->modelId){
        default: 
            sp24 = 0; 
            break;

        case ASSET_451_MODEL_GRUNTILDA: 
        case ASSET_458_MODEL_BANJO_TOP_SLEEPING: 
        case ASSET_532_MODEL_BANJO_KAZOOIE_CUTSCENES: 
            sp24 = 1; 
            break;
    }

    if(!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        if (sp24) {
            func_802C7318(this);
        }
        func_80361E10(this);
        this->marker->actorFreeFunc = func_802E07C0;
    }

    func_80326244(this);
    if (this->unk48 == 1.0) {
        marker_despawn(this->marker);
        return;
    }
    if (sp24) {
        this->unk130 = func_802C71F0;
        func_802C7478(this);
    }
    func_80361EE0(this);
}

void chFireSparkle_update(Actor *this) {
    f32 rotation[3];

    this->marker->collidable = FALSE;
    anctrl_setDuration(this->anctrl, this->unk5C);
    anctrl_setPlaybackType(this->anctrl, ANIMCTRL_ONCE);
    if (actor_animationIsAt(this, 0.99f) != 0) {
        marker_despawn(this->marker);
    }
    viewport_getRotation_vec3f(rotation);
    this->yaw = rotation[1];
}
