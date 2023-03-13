#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 player_getYaw();
AnimCtrl *player_getAnimCtrlPtr(void);

Actor *__chJigsawDance_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void __chJigsawDance_update(Actor * this);

/* .data */
ActorAnimationInfo chJigsawDanceAnimations[] = {
    {0x00, 0.0f},
    {0x00, 2.0f},
    {ASSET_76_ANIM_JIGSAWDANCE_HOLD, 1.5f},
    {ASSET_76_ANIM_JIGSAWDANCE_HOLD, 1.5f},
    {ASSET_30_ANIM_JIGSAWDANCE_DANCE, 5.0f},
    {0x00, 2.0f}
};

ActorInfo chJigsawDance = {MARKER_68_JIGSAW_DANCE, ACTOR_5A_JIGSAW_DANCE, ASSET_35E_MODEL_JIGSAW_DANCE, 
    1, chJigsawDanceAnimations, 
    __chJigsawDance_update, func_80326224, __chJigsawDance_draw,
    0, 0, 0.0f, 0
}; 


/* .code */
Actor *__chJigsawDance_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    Actor *thisActor = marker_getActor(this);

    if(!thisActor->initialized){
        thisActor->initialized = 1;
        return thisActor;
    }
    else{
        return actor_draw(this, gdl, mptr, arg3);
    }
}

void __chJigsawDance_update(Actor * this){
    AnimCtrl *plyrMvmt;

    this->marker->collidable = 0;
    switch(this->state){
        case 1:
            break;
        case 2:
            player_getPosition(this->position);
            this->yaw = player_getYaw();
            plyrMvmt = player_getAnimCtrlPtr();
            animctrl_setSmoothTransition(this->animctrl, 0);
            animctrl_setIndex(this->animctrl, animctrl_getIndex(plyrMvmt));
            animctrl_setStart(this->animctrl,animctrl_getAnimTimer(plyrMvmt));
            animctrl_setDuration(this->animctrl, 1000.0f);
            animctrl_start(this->animctrl, "chjigsawdance.c", 0x59);
            break;
        case 3:
            plyrMvmt = player_getAnimCtrlPtr();
            animctrl_setSmoothTransition(this->animctrl, 0);
            animctrl_setStart(this->animctrl,animctrl_getAnimTimer(plyrMvmt));
            animctrl_setDuration(this->animctrl, 1000.0f);
            animctrl_start(this->animctrl, "chjigsawdance.c", 0x62);
            break;
        case 4:
            player_getPosition(this->position);
            this->yaw = player_getYaw();
            plyrMvmt = player_getAnimCtrlPtr();
            animctrl_setSmoothTransition(this->animctrl, 0);
            animctrl_setStart(this->animctrl,animctrl_getAnimTimer(plyrMvmt));
            animctrl_setDuration(this->animctrl, 1000.0f);
            animctrl_start(this->animctrl, "chjigsawdance.c", 0x6e);
            break;
        case 5:
            this->marker->propPtr->unk8_4 = 0;
            break;
    }
}

void chJigsawDance_setState(Actor * this, u32 arg1){
    switch(arg1){
        case 3:
            if(this->state == 1){
                func_80328A84(this, 2);
                animctrl_setPlaybackType(this->animctrl,  ANIMCTRL_ONCE);
            }
            break;
        case 2:
            func_80328A84(this, 3);
            break;
        case 1:
            func_80328A84(this, 4);
            break;
        case 4:
            player_getPosition(this->position);
            this->yaw = player_getYaw();
            animctrl_setSmoothTransition(this->animctrl, 0);
            animctrl_setStart(this->animctrl, animctrl_getAnimTimer(player_getAnimCtrlPtr()));
            animctrl_setDuration(this->animctrl, 1000.0f);
            animctrl_start(this->animctrl, "chjigsawdance.c", 0x97);
            break;
        case 5:
            func_80328A84(this, 5);
            this->marker->propPtr->unk8_4 = 0;
            break;
    }
}
