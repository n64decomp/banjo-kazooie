#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct chpinkegg_s{
    u32 unk0;
    u32 unk4;
} ActorLocal_PinkEgg;

void chpinkegg_draw(ActorMarker *this, Gfx ** gdl, Mtx** mptr, u32 arg3);
void chpinkegg_collision(ActorMarker *this, ActorMarker *other_marker);
void chpinkegg_update(Actor *this);

u32 D_803906C0 = 0x5B;
enum actor_e D_803906C4[5] = {0xED, 0xEE, 0xEF, 0xF0, 0x00};
ActorAnimationInfo D_803906D8[4] = {
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0x10B, 2.0f}
};

ActorInfo D_803906F8 = {0x6E, 0x5B, 0x380, 0x01, D_803906D8,
    chpinkegg_update, func_80326224, chpinkegg_draw,
    0, 0x2CC, 6.0f, 0
};

ActorInfo D_8039071C = {0xD6, 0xED, 0x381, 0x01, D_803906D8,
    chpinkegg_update, func_80326224, chpinkegg_draw,
    0, 0x2CC, 5.0f, 0
};

ActorInfo D_80390740 = {0xD7, 0xEE, 0x382, 0x01, D_803906D8,
    chpinkegg_update, func_80326224, chpinkegg_draw,
    0, 0x2CC, 4.0f, 0
};

ActorInfo D_80390764 = {0xD8, 0xEF, 0x383, 0x01, D_803906D8,
    chpinkegg_update, func_80326224, chpinkegg_draw,
    0, 0x2CC, 3.0f, 0
};

ActorInfo D_80390788 = {0xD9, 0xF0, 0x384, 0x01, D_803906D8,
    chpinkegg_update, func_80326224, chpinkegg_draw,
    0, 0x2CC, 2.0f, 0
};

/* .code */
void chpinkegg_spawn_next(ActorMarker * arg0, u32 arg1){
    ActorLocal_PinkEgg *local;
    Actor *actorPtr;
    Actor *unkActor;
    actorPtr = marker_getActor(arg0);
    local = (ActorLocal_PinkEgg *)&actorPtr->local;
    unkActor = spawn_child_actor( D_803906C4[arg1], &actorPtr);

    ((ActorLocal_PinkEgg *) &unkActor->local)->unk0 = arg1 + 1;
    ((ActorLocal_PinkEgg *) &unkActor->local)->unk4 = 5;
    unkActor->marker->collidable = 0;
    
}

void chpinkegg_draw(ActorMarker *this, Gfx ** gdl, Mtx** mptr, u32 arg3){
    u32 sp18;
    u32 t7;

    t7 = marker_getActor(this)->state == 3;
    func_8033A45C(1, (sp18 = t7) ^ 1);
    func_8033A45C(2, sp18);
    func_80325888(this, gdl, mptr, arg3);
}


void chpinkegg_collision(ActorMarker *this, ActorMarker *other_marker){
    Actor *thisActor;
    ActorLocal_PinkEgg *tmp;
    
    thisActor = marker_getActor(this);
    this->propPtr->unk8_3 = 0;
    func_8030E510(SFX_AA_BGS_EGG_BREAKING_1, 28000);
    func_80328A84(thisActor, 3);
    actor_playAnimationOnce(thisActor);
    this->collidable = 0;
    thisActor->unk124_6 = 0;
    if(D_803906C4[(tmp = (ActorLocal_PinkEgg *) &thisActor->local)->unk0] != 0){
        func_802C3D3C(chpinkegg_spawn_next, thisActor->marker, tmp->unk0);
    } else {
        jiggySpawn(JIGGY_21_BGS_PINKEGG, thisActor->position);
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    }
}

void chpinkegg_update(Actor *this){
    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, NULL, chpinkegg_collision);
        this->initialized = 1;
    }

    switch(this->state){
        case 1:
            if(!((ActorLocal_PinkEgg *) &this->local)->unk4){
                this->marker->collidable = 1;
                func_80328A84(this,2);
                
            }else{
                ((ActorLocal_PinkEgg *) &this->local)->unk4--;
            }
            break;
        case 3:
            if(animctrl_isStopped(this->animctrl)){
                func_80326310(this);
                if(this->alpha_124_19 < 0x60){
                    this->unk124_9 = 0x2;
                }
            }
            break;
    }
}
