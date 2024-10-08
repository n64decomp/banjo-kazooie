#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"

extern void func_802D3D54(Actor *);
extern void func_802D3D74(Actor *);
extern void func_80325F84(Actor *);


extern ActorInfo D_8038EB50;
extern ActorInfo D_8038EB74;
extern ActorInfo D_8038EBA0;
extern ActorInfo D_8038EBD0;
extern ActorInfo D_8038EC14;
extern ActorInfo D_8038EC70;
extern ActorInfo D_8038ECA0;
extern ActorInfo D_8038ECE8;
extern ActorInfo D_8038EE70;
extern ActorInfo D_8038F130;
extern ActorInfo chCaterpillar;
extern ActorInfo D_8038F190;
extern ActorInfo D_8038F230;
extern ActorInfo D_8038F6F0;
extern ActorInfo D_8038ED50;
extern ActorInfo D_8038ED98;
extern ActorInfo D_8038EDE0;
extern ActorInfo D_8038EE28;
extern ActorInfo D_8038ED74;
extern ActorInfo D_8038EDBC;
extern ActorInfo D_8038EE04;
extern ActorInfo D_8038EE4C;
extern ActorInfo D_8038F270;
extern ActorInfo D_8038F300;
extern ActorInfo D_8038F35C;
extern ActorInfo D_8038F380;
extern ActorInfo D_8038F3A4;
extern ActorInfo D_8038F3C8;
extern ActorInfo D_8038F3EC;
extern ActorInfo D_8038F410;
extern ActorInfo D_8038F434;
extern ActorInfo D_8038F460;
extern ActorInfo D_8038F4A8;
extern ActorInfo D_8038F4D0;
extern ActorInfo D_8038F614;
extern ActorInfo D_8038F640;
extern ActorInfo D_8038F908;
extern ActorInfo D_8038F8C0;
extern ActorInfo D_8038F720;
extern ActorInfo D_8038F744;
extern ActorInfo D_8038F768;
extern ActorInfo D_8038F78C;
extern ActorInfo chGrublinHood;
extern ActorInfo gChVacationTextTrigger;
extern ActorInfo D_8038F7D4;
extern ActorInfo D_8038F7B0;
extern ActorInfo D_8038F888;
extern ActorInfo D_8038F7F8;
extern ActorInfo D_8038F81C;
extern ActorInfo D_8038F840;
extern ActorInfo D_8038F864;

void CCW_func_8038DB0C(Actor *this);
void func_8038DAB0(Actor *this);

/* .data */
ActorInfo D_8038F720 = { 0x239, 0x25F, 0x4FC, 0x1, NULL, func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F744 = { 0x236, 0x260, 0x4F9, 0x1, NULL, func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F768 = { 0x237, 0x261, 0x4FA, 0x1, NULL, func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F78C = { 0x238, 0x262, 0x4FB, 0x1, NULL, func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F7B0 = { 0x243, 0x2E6, 0x533, 0x1, NULL, func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F7D4 = { 0x263, 0x2E7, 0x518, 0x1, NULL, func_8038DAB0, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F7F8 = { 0x21E, 0x233, 0x3B3, 0x1, NULL, func_802D3D74, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F81C = { 0x26B, 0x2DE, 0x531, 0x1, NULL, CCW_func_8038DB0C, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F840 = { 0x26C, 0x2DD, 0x53E, 0x1, NULL, CCW_func_8038DB0C, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F864 = { 0x26D, 0x2DC, 0x53F, 0x1, NULL, CCW_func_8038DB0C, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_8038F888 = { 0x1CC, 0x318, 0x0,   0x0, NULL, func_80325F84, NULL, func_80325340, 0, 0, 0.0f, 0};


/* .code */
void func_8038DAB0(Actor *this){
    if(!this->initialized){
        func_802D3CE8(this);
        this->initialized = TRUE;

        if (levelSpecificFlags_get(LEVEL_FLAG_38_CCW_UNKNOWN)) {
            marker_despawn(this->marker);
        }
    }
}

void CCW_func_8038DB0C(Actor *this){
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
        this->position_x = 325.8f;
        this->position_y = 600.0f;
        this->position_z = 0.0f;
    }
}

void CCW_func_8038DB6C(void)
{
    spawnableActorList_add(&D_8038EB50, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_8038EB74, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_8038EBA0, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038EBD0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_8038EC14, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038EC70, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_8038ECA0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_8038ECE8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_8038EE70, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F130, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chCaterpillar, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F190, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_8038F230, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F6F0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038ED50, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038ED98, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038EDE0, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038EE28, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038ED74, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038EDBC, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038EE04, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038EE4C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038F270, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F300, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F35C, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F380, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_8038F3A4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F3C8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F3EC, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_8038F410, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F434, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F460, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F4A8, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F4D0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F614, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_8038F640, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_8038F908, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038F8C0, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038F720, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038F744, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038F768, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038F78C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chGrublinHood, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVacationTextTrigger, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038F7D4, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038F7B0, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038F888, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_8038F7F8, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038F81C, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038F840, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038F864, actor_new, ACTOR_FLAG_UNKNOWN_10);
}
