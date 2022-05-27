/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void func_80388DFC(ActorMarker *, s32);
s32  func_80329784(Actor *);
void func_80353580(void *);

typedef struct juju_hitbox_s{
    u8      pad0[0x4];
    s32     unk4;
    ActorMarker *unk8[4];
    f32     unk18;
}ActorLocal_JujuHitbox;

/* public functions */
void    func_80388E20(Actor *this);
Actor*  func_80388DC0(ActorMarker *, Gfx **, Mtx**, u32);
void    func_80388DE8(Actor* this, s32 slave_id, Actor *slavePtr);

/* .data */
ActorInfo chjujuhitboxInfo = { MARKER_67_JUJU, ACTOR_11_JUJU_CTRL, 0, 
    3, NULL,
    func_80388E20, func_80326224, func_80388DC0,
    {0,0}, 0, 0.0f, {0,0,0,0}
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

void func_80388BEC(s16 *arg0, void *arg1){
    f32 sp34;
    Actor *sp30;
    Actor *temp_v0;
    f32 sp20[3];
    

    sp20[0] = (f32)arg0[0];
    sp20[1] = (f32)arg0[1];
    sp20[2] = (f32)arg0[2];
    sp30 = func_80326D68(&sp20, 0x11, -1, &sp34);
    if( sp30 != NULL
        && !( sp34 > 500.0f )
        && (sp30->state ==3)
    ){
        temp_v0 = marker_getActor(((ActorLocal_JujuHitbox *)&sp30->local)->unk8[((ActorLocal_JujuHitbox *)&sp30->local)->unk4]);
        if(temp_v0 != NULL){
            if(func_80388B30(temp_v0, 90.0f)){
                sp30->state = 1;
                ((ActorLocal_JujuHitbox *)&sp30->local)->unk4++;
                func_803892A8(((ActorLocal_JujuHitbox *)&sp30->local)->unk8);
                func_80353580(arg1);
                func_802C3F04(func_802C4140, 0x58, *(s32 *)&sp20[0], *(s32 *)&sp20[1], *(s32 *)&sp20[2]);
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

Actor*  func_80388DC0(ActorMarker *this, Gfx **dl, Mtx**mPtr, u32 arg3){
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
        this->initialized = 1;
        this->unk138_24 = 0;
        jujuCtlPtr->unk18 = 0.5f;
    }
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_802C3D3C(func_80388DFC,this->marker, jujuCtlPtr->unk4);
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
