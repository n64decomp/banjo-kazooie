#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
int func_80353064(f32*, f32);
void  func_802BB3DC(s32, f32, f32);

typedef struct{
    s32     unk0;
    s32     unk4;
    TUPLE(f32, unk8);
    f32     unk14;
    s32     unk18;
}ActorLocal_Juju_2;

/* public functions */
void    func_80389598(Actor *this);
Actor*  func_80389014(ActorMarker *, Gfx **, Mtx**, Vtx** );

/* .bss */
u8 MM_pad_80389C80[0x10];
s32 MM_D_80389C90;

/* .data */
ActorInfo chjujuInfo = { MARKER_67_JUJU, ACTOR_59_JUJU, ASSET_2E6_MODEL_JUJU, 
    0, NULL,
    func_80389598, func_80326224, func_80389014,
    0, 0, 0.0f, 0
};

void func_80388FD0(Actor *this, f32 *arg1, f32 *arg2, s32 arg3){
    ActorLocal_Juju_2 *local;

    local = (ActorLocal_Juju_2 *)&this->local;
    local->unk0 = arg3;
    local->unk14 = 1.0f;

    this->position_x = arg1[0];
    this->position_y = arg1[1];
    this->position_z = arg1[2];
    
    local->unk8_x = arg2[0];
    local->unk8_y = arg2[1];
    local->unk8_z = arg2[2];
}

Actor*  func_80389014(ActorMarker *this, Gfx **dl, Mtx **mPtr, Vtx **arg2){
    f32 sp34[3];
    Actor * actorPtr;
    ActorLocal_Juju_2 *jujuPtr;

    actorPtr = marker_getActorAndRotation(this, sp34);
    jujuPtr = (ActorLocal_Juju_2 *)&actorPtr->local;
    if(jujuPtr->unk0 != 2){
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(dl, mPtr, actorPtr->position, sp34, jujuPtr->unk14, NULL, func_80330B1C(this));
    }
    return actorPtr;
}

void func_803890A0(ActorMarker *arg0, s32 arg1){
    int s1;
    Actor* actorPtr = marker_getActor(arg0);
    f32 sp5C[3];
    s32 i;
    Actor* jujuPtr;

    sp5C[0] = actorPtr->position_x;
    sp5C[1] = actorPtr->position_y;
    sp5C[2] = actorPtr->position_z;
    for(i = 0; i < 4; i++){
        jujuPtr = func_8032813C(ACTOR_59_JUJU, actorPtr->position, actorPtr->yaw);
        jujuPtr->marker->collidable = 0;
        actorPtr = marker_getActor(arg0);
        func_80388DE8(actorPtr, i, jujuPtr);
        s1 = (i >= arg1);
        func_80388FD0(jujuPtr, sp5C, actorPtr->position, (s1)? 1 : 2);
        if(s1){
            sp5C[1] += 250.0f;
        }
        if(i == arg1){
            ((ActorLocal_Juju_2 *)&jujuPtr->local)->unk18 = 1;
        }
    }
}

void func_803891E8(s32 x, s32 y, s32 z, s32 yaw){
    f32 sp1C[3];
    sp1C[0] = x;
    sp1C[1] = y + 0x14;
    sp1C[2] = z;
    jiggy_spawn(JIGGY_4_MM_JUJU, sp1C);
}

void func_80389244(s32 x, s32 y, s32 z, s32 yaw){
    __spawnQueue_add_4((GenFunction_4)func_803891E8, x, y, z, yaw);
    func_802BB3DC(0, 10.0f, 0.8f);
    gcpausemenu_80314AC8(1);
}

void func_803892A8(ActorMarker **ptr){
    s32 i;
    s32 j;
    s32 s2;
    s32 s6;
    Actor *actorPtr;
    ActorLocal_Juju_2 *jujuPtr;

    for(i = 0; i < 4; i++){
        actorPtr = marker_getActor(ptr[i]);
        jujuPtr = (ActorLocal_Juju_2 *)&actorPtr->local;
        if(jujuPtr->unk0 != 2){
            jujuPtr->unk0 = 5;
            jujuPtr->unk4 = 0xC;
            func_8030E484(0x3f6);
            if(i == 3){
                gcpausemenu_80314AC8(0);
                timedFunc_set_4(1.25f, func_80389244, jujuPtr->unk8_x, jujuPtr->unk8_y, jujuPtr->unk8_z, actorPtr->yaw);
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x6d60);
            }
            else{//L80389384
                func_8025A6EC(COMUSIC_2B_DING_B, 0x7fff);
            }
            for(s2 = 3, j = i + 1; j < 4; s2+=5, j++){
                actorPtr = marker_getActor(ptr[j]);
                jujuPtr = (ActorLocal_Juju_2 *)&actorPtr->local;
                if(j == i+1){
                    jujuPtr->unk18 = 1;
                }
                jujuPtr->unk4 = s2;
                jujuPtr->unk0 = 3;

            }
            return;
        }
    }
}

int func_8038941C(ActorMarker **ptr){
    s32 i;
    ActorLocal_Juju_2 *jujuPtr;

    for(i = 0; i < 4; i++){
        jujuPtr = (ActorLocal_Juju_2 *)&marker_getActor(ptr[i])->local;
        if(jujuPtr->unk0 != 2)
            return 0;
    }
    return 1;
}

int func_8038948C(ActorMarker **ptr){
    s32 i;
    ActorLocal_Juju_2 *jujuPtr;

    for(i = 0; i < 4; i++){
        jujuPtr = (ActorLocal_Juju_2 *)&marker_getActor(ptr[i])->local;
        if(jujuPtr->unk0 != 1 && jujuPtr->unk0 != 2)
            return 0;
    }
    return 1;
}

void func_80389514(ActorMarker **ptr){
    s32 i;
    MM_D_80389C90 = 0;
    for(i = 0; i < 4; i++){
        if(((ActorLocal_Juju_2 *)&marker_getActor(ptr[i])->local)->unk0 != 2){
            MM_D_80389C90++;
        };
    }
}

void    func_80389598(Actor *this){
    ActorLocal_Juju_2 *jujuPtr = (ActorLocal_Juju_2 *)&this->local;
    s32 sp38 = 0;
    f32 sp34;
    f32 sp28[3];
    
    this->marker->propPtr->unk8_3 = (jujuPtr->unk0 != 2) && (jujuPtr->unk0 != 5);

    switch(jujuPtr->unk0){
        case 1: //L80389624
            sp34 = this->yaw;
            this->yaw += ((0xb - MM_D_80389C90*2)*time_getDelta()*60.0f)/2;
            if(360.0f < this->yaw){
                sp38 = 1;
                this->yaw -= 360.0f;
            }//L803896B4
            if(jujuPtr->unk18){ 
                if(sp38 || (sp34 < 180.0f && 180.0f <= this->yaw)){
                    mapSpecificFlags_set(9,1);
                }
            }
            break;
        case 3: //L80389700
            if(--jujuPtr->unk4 == 0){
                jujuPtr->unk0 = 4;
                jujuPtr->unk8_y = this->position_y - 250.0f;
            }
            break;
        case 5: //L80389738
            jujuPtr->unk4--;
            jujuPtr->unk14 *= 0.85;
            {sp28[0] = 100.0f;
            sp28[1] = 0.0f;
            sp28[2] = 0.0f;}
            ml_vec3f_yaw_rotate_copy(sp28, sp28, this->yaw + 90.0);
            this->position_x += sp28[0];
            this->position_y += sp28[1];
            this->position_z += sp28[2];
            if(!jujuPtr->unk4){
                jujuPtr->unk0 = 2;
            }
            break;
        case 4: //L803897F8
            this->position_y -= 25.0;
            if(jujuPtr->unk8_y == this->position_y){
                jujuPtr->unk0 = 1;
                func_8030E484(SFX_3_DULL_CANNON_SHOT);
                func_802BB3DC(0, 10.0f, 0.8f);
                if(jujuPtr->unk18)
                    func_80353064(this->position, 24.0f);
            }
            break;
        
    }//L8038987C
}

