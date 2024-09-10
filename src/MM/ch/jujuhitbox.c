/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void func_80388DFC(ActorMarker *, s32);
s32  func_80329784(Actor *);
void func_80353580(ActorMarker *);

typedef struct juju_hitbox_s{
    u8      pad0[0x4];
    s32     unk4;
    ActorMarker *unk8[4];
    f32     unk18;
}ActorLocal_JujuHitbox;

/* public functions */
void    func_80388E20(Actor *this);
Actor*  func_80388DC0(ActorMarker *, Gfx **, Mtx**, Vtx **);
void    func_80388DE8(Actor* this, s32 slave_id, Actor *slavePtr);

/* .data */
ActorInfo chjujuhitboxInfo = { MARKER_67_JUJU, ACTOR_11_JUJU_CTRL, 0, 
    3, NULL,
    func_80388E20, func_80326224, func_80388DC0,
    0, 0, 0.0f, 0
};

int func_80388B30(Actor *this, float arg1){
    f32 yaw;

    yaw = this->yaw - func_80329784(this);

    if(180.0f <= yaw){
        yaw -= 360.0f;
    }
    else if(yaw < -180.0f){
        yaw += 360.0f;
    }

    if (yaw < 0.0f){
        yaw = -yaw;
    }

    if (yaw < arg1){
        return 1;
    }
    return 0;
}

void func_80388BEC(NodeProp *node, ActorMarker *marker){
    f32 distance_to_closest_actor;
    Actor *closest_actor;
    Actor *temp_v0;
    f32 position[3];
    

    position[0] = (f32)node->x;
    position[1] = (f32)node->y;
    position[2] = (f32)node->z;

    closest_actor = actorArray_findClosestActorFromActorId(position, 0x11, -1, &distance_to_closest_actor);

    if( closest_actor != NULL
        && !( distance_to_closest_actor > 500.0f )
        && (closest_actor->state ==3)
    ){
        temp_v0 = marker_getActor(((ActorLocal_JujuHitbox *)&closest_actor->local)->unk8[((ActorLocal_JujuHitbox *)&closest_actor->local)->unk4]);

        if(temp_v0 != NULL){
            if(func_80388B30(temp_v0, 90.0f)){
                closest_actor->state = 1;
                ((ActorLocal_JujuHitbox *)&closest_actor->local)->unk4++;
                func_803892A8(((ActorLocal_JujuHitbox *)&closest_actor->local)->unk8);
                func_80353580(marker);
                __spawnQueue_add_4((GenFunction_4)func_802C4140, 0x58, *(s32 *)&position[0], *(s32 *)&position[1], *(s32 *)&position[2]);
            }
        }
    }
}

void func_80388D14(Actor *this){
    ActorLocal_JujuHitbox *jujuCtlPtr;

    jujuCtlPtr = (ActorLocal_JujuHitbox *)&this->local;
    func_8030E878(0x3F6, jujuCtlPtr->unk18, 20000, this->position, 300.0f, 2000.0f);
}

void func_80388D60(Actor *this){
    ActorLocal_JujuHitbox *jujuCtlPtr;

    jujuCtlPtr = (ActorLocal_JujuHitbox *)&this->local;
    if(!func_8038941C(jujuCtlPtr->unk8)){
        jujuCtlPtr->unk18 *= 1.05;
    }
    this->state = 3;
}

Actor*  func_80388DC0(ActorMarker *this, Gfx **dl, Mtx**mPtr, Vtx **arg3){
    return marker_getActor(this);
}

void    func_80388DE8(Actor *this, s32 child_id, Actor *childPtr){
    ActorLocal_JujuHitbox *jujuCtlPtr;

    jujuCtlPtr = (ActorLocal_JujuHitbox *)&this->local;
    jujuCtlPtr->unk8[child_id] = childPtr->marker;
}

void func_80388DFC(ActorMarker *arg0, s32 arg1){
    func_803890A0(arg0, arg1);

    if(arg0 && arg1); //for args to save
}

void func_80388E20(Actor *this){
    ActorLocal_JujuHitbox *jujuCtlPtr;
    s32 i;

    jujuCtlPtr = (ActorLocal_JujuHitbox *)&this->local;
    if(!this->initialized){
        this->initialized = TRUE;
        this->unk138_24 = 0;
        jujuCtlPtr->unk18 = 0.5f;
    }
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        __spawnQueue_add_2((GenFunction_2)func_80388DFC,this->marker, jujuCtlPtr->unk4);
        func_80388D14(this);
    }else{
        if( func_80329530(this, 0xfa) 
            && !func_80329530(this, 0x50)
            && !func_8028ECAC()
        ){
            if( !this->unk138_24 ){
                if(func_80311480(ASSET_B44_TEXT_JUJU_MEET, 0, 0, 0, NULL, NULL)){
                    this->unk138_24 = 1;
                }
            }
        }

        if(this->state == 1){
            if(func_8038948C(jujuCtlPtr->unk8)){
                func_80388D60(this);
            }
            if(func_8038941C(jujuCtlPtr->unk8)){
                marker_despawn(this->marker);
                for(i = 0; i < 4; i++){
                    marker_despawn(jujuCtlPtr->unk8[i]);
                }
                return;
            }
        }
        else{
            func_80389514(jujuCtlPtr->unk8);
        }
        
        if(mapSpecificFlags_get(0x9)){
            func_80388D14(this);
            mapSpecificFlags_set(0x9, 0);
        }
    }
}
