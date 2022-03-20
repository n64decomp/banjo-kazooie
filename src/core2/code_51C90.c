#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void actor_setOpacity(Actor*,s32);
extern void func_8035644C(u32);

bool func_802D8D48(Actor*, u32, enum asset_e, enum comusic_e, enum item_e, f32);
Actor *func_802D8F50(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D9018(Actor *this);

/* .data */
extern ActorInfo D_80367D00 = {
    0x60, 0x52, 0x36D,
    0, NULL, 
    func_802D9018, func_80326224, func_802D8F50, 
    { 0x0, 0x0}, 0, 0.7f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367D24 = {
    0xB5, 0x129, 0x580,
    0, NULL, 
    func_802D9018, func_80326224, func_802D8F50, 
    { 0x0, 0x0}, 0, 0.5f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80367D48 = {
    0x1E5, 0x370, 0x6D1,
    0, NULL, 
    func_802D9018, func_80326224, func_802D8F50, 
    { 0x0, 0x0}, 0, 0.5f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_802D8C20(Actor *arg0, u32 arg1){
    switch(arg1){
        default:
            break;
        case 1:
            arg0->unk28 = 0.0f; 
            //fall-through
        case 3:
            actor_collisionOff(arg0);
            break;
        case 2:
            actor_collisionOn(arg0);
            break;
    }
    func_80328A84(arg0, arg1);
}

void func_802D8C98(Actor *this, s32 arg1) {
    s32 phi_v0;

    switch (this->marker->unk14_20)
    {
    case 0x60:
        phi_v0 = TRUE;
        break;

    case 0xB5:
        phi_v0 = (arg1 == 1) || (arg1 == 2) || (arg1 == 3);
        break;

    case 0x1e5:
        phi_v0 = TRUE;
        break;

    default:
        phi_v0 = FALSE;
        break;
    }

    this->unk10_12 = arg1;
    func_802D8C20(this, (phi_v0 ) ? 2 : 3);
}

//collectItem
bool func_802D8D48(Actor* actor, u32 arg1, enum asset_e dialogId, enum comusic_e sfxId, enum item_e itemId, f32 arg5){
    func_8025A6EC(sfxId,32000);
    timedFunc_set_1(0.75f, func_8035644C, arg1);
    if(!func_802FADD4(0x1b)){
        item_inc(itemId);
    } else {
        func_803463F4(itemId,1);   
    }

    if(!actor || !actor->unk38_0)
        return TRUE;
            
    actor->unk60 = arg5;
    func_802D8C20(actor, 1);
    return FALSE;
}

//egg_collision
s32 func_802D8DF0(ActorProp *arg0){
    Actor *actPtr = NULL;
    if(arg0 != NULL){
        func_802F3808(&arg0->x);
        if(arg0->unk8_0)
            actPtr = marker_getActor(arg0->marker);
    }
    func_802D8D48(actPtr, 5, 0xD9E, COMUSIC_C_EGG_COLLECTED, 0xD, 2.0f);
}

//readFeather_collision
void func_802D8E68(ActorProp *arg0){
    Actor *actPtr = NULL;
    func_802F38F0(&arg0->x);
    if(arg0->unk8_0)
        actPtr = marker_getActor(arg0->marker);
    func_802D8D48(actPtr, 6, 0xD9F, COMUSIC_B_RED_FEATHER_COLLECTED, 0xF, 4.0f);
}

//goldFeather_collision
void func_802D8EDC(ActorProp *arg0){
    Actor *actPtr = NULL;
    func_802F39D8(&arg0->x);
    if(arg0->unk8_0)
        actPtr = marker_getActor(arg0->marker);
    func_802D8D48(actPtr, 7, 0xDA0, COMUSIC_14_GOLD_FEATHER_COLLECTED, ITEM_10_GOLD_FEATHER, 6.0f);
}

Actor *func_802D8F50(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3){
    Actor *thisActor = marker_getActor(this);

    if(thisActor->unk28 != 0.0f){
        if(thisActor->unk38_0){
            func_80344C2C(1);
            if(thisActor->unk28 == 255.0f){
                func_803262B8(thisActor);
            } else{
                actor_setOpacity(thisActor, thisActor->unk28);
            }
        }
        return func_80325934(this, gdl, mptr, arg3);
    }
    return thisActor;
}

void func_802D9018(Actor *this) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    u32 temp_v0;

    if (!this->initialized) {
        if (this->marker->unk14_20 != 0x60) {
            func_8032AA58(this, 0.56f);
        }
        this->unk10_12 = -1;
        this->unk38_0 = (map_get() == MAP_90_GL_BATTLEMENTS);
        this->unk28 = this->unk38_0 ? 0.0f: 255.0f;
        this->initialized = TRUE;
    }
    if(!this->unk38_0)
        return;

    if (func_80320424(0x23, 3) != this->unk10_12) {
        func_802D8C98(this, func_80320424(0x23, 3));
    }

    switch (this->state) {
    case 1:
        if (this->unk60 > 0.0) {
            this->unk60 -= time_getDelta();
        } else {
            func_802D8C20(this, 2);
        }
        /* fallthrough */
    case 3:
        if (this->unk28 > 0) {
            this->unk28 = MAX(this->unk28 - 8, 0);
        }
        break;
    case 2:
        if (this->unk28 < 255) {
            this->unk28 = MIN(this->unk28 + 8, 255);
        }
        break;
    }
}
