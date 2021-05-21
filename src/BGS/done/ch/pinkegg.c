#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void  func_80326224(Actor *);
void  actor_playAnimationOnce(Actor *);
void chPinkEggDraw(ActorMarker *this, Gfx ** gdl, Mtx** mptr, u32 arg3);
void  func_80387AB0(ActorMarker *this, u32 arg1);
void func_80387B80(Actor *this);

u32 D_803906C0 = 0x5B;
u32 D_803906C4[5] = {0xED, 0xEE, 0xEF, 0xF0, 0x00};
ActorAnimationInfo D_803906D8[4] = {
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0x10B, 2.0f}
};

ActorInfo D_803906F8 = {0x6E, 0x5B, 0x380, 0x01, D_803906D8,
    func_80387B80, func_80326224, chPinkEggDraw,
    {0,0,2,0xCC}, 6.0f, {0,0,0,0}
};

ActorInfo D_8039071C = {0xD6, 0xED, 0x381, 0x01, D_803906D8,
    func_80387B80, func_80326224, chPinkEggDraw,
    {0,0,2,0xCC}, 5.0f, {0,0,0,0}
};

ActorInfo D_80390740 = {0xD7, 0xEE, 0x382, 0x01, D_803906D8,
    func_80387B80, func_80326224, chPinkEggDraw,
    {0,0,2,0xCC}, 4.0f, {0,0,0,0}
};

ActorInfo D_80390764 = {0xD8, 0xEF, 0x383, 0x01, D_803906D8,
    func_80387B80, func_80326224, chPinkEggDraw,
    {0,0,2,0xCC}, 3.0f, {0,0,0,0}
};

ActorInfo D_80390788 = {0xD9, 0xF0, 0x384, 0x01, D_803906D8,
    func_80387B80, func_80326224, chPinkEggDraw,
    {0,0,2,0xCC}, 2.0f, {0,0,0,0}
};

//pinkEgg_spawnNextEgg
void chPinkEggSpawnNext(ActorMarker * arg0, u32 arg1){
    u32   tmp;
    Actor *actorPtr;
    Actor *unkActor;
    actorPtr = marker_getActor(arg0);
    unkActor = func_8032818C( D_803906C4[arg1], &actorPtr);

    unkActor->pinkEgg.unk0 = arg1 + 1;
    unkActor->pinkEgg.unk4 = 5;
    unkActor->marker->collidable = 0;
    
}

//pinkEggDraw
void chPinkEggDraw(ActorMarker *this, Gfx ** gdl, Mtx** mptr, u32 arg3){
    u32 sp18;
    u32 t7;

    t7 = marker_getActor(this)->unk10_31 == 3;
    func_8033A45C(1, (sp18 = t7) ^ 1);
    func_8033A45C(2, sp18);
    func_80325888(this, gdl, mptr, arg3);
}


void func_80387AB0(ActorMarker *this, u32 arg1){
    Actor *thisActor;
    ActorLocal_PinkEgg *tmp;
    
    thisActor = marker_getActor(this);
    this->propPtr->unk8_3 = 0;
    func_8030E510(0xAA, 28000);
    func_80328A84(thisActor, 3);
    actor_playAnimationOnce(thisActor);
    this->collidable = 0;
    thisActor->unk124_6 = 0;
    if(D_803906C4[(tmp = &thisActor->pinkEgg)->unk0]){
        // !!! thisActor->unk7C loading into a2 too soon 
        func_802C3D3C(chPinkEggSpawnNext, thisActor->marker, tmp->unk0);
    } else {
        jiggySpawn(jiggy_bgs_pinkegg, thisActor->position);
        func_8025A6EC(JINGLE_PUZZLE_SOLVED_FANFARE, 28000);
    }
}

//pinkEggUpdate?
void func_80387B80(Actor *this){
    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 1;
        func_803300A8(this->marker, NULL, NULL, func_80387AB0);
        this->initialized = 1;
    }

    switch(this->unk10_31){
        case 1:
            if(!this->pinkEgg.unk4){
                this->marker->collidable = 1;
                func_80328A84(this,2);
                
            }else{
                this->pinkEgg.unk4--;
            }
            break;
        case 3:
            if(animctrl_isStopped(this->animctrl)){
                func_80326310(this);
                if(this->unk124_19 < 0x60){
                    this->unk124_9 = 0x2;
                }
            }
            break;
    }
}
