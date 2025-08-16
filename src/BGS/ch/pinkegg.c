#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct chpinkegg_s{
    u32 unk0;
    u32 unk4;
} ActorLocal_PinkEgg;

Actor *chPinkEgg_draw(ActorMarker *this, Gfx ** gdl, Mtx** mptr, Vtx **vtx);
void chPinkEgg_collision(ActorMarker *this, ActorMarker *other_marker);
void chPinkEgg_update(Actor *this);

u32 D_803906C0 = 0x5B;
enum actor_e D_803906C4[5] = {
    ACTOR_ED_PINK_EGG_LARGE,
    ACTOR_EE_PINK_EGG_MEDIUM,
    ACTOR_EF_PINK_EGG_SMALL,
    ACTOR_F0_PINK_EGG_SMALLEST,
    0x00
};

ActorAnimationInfo chPinkEggAnimations[4] = {
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f},
    {0x10B, 2.0f}
};

ActorInfo chPinkEggLargest = {MARKER_6E_PINK_EGG_LARGEST, ACTOR_5B_PINK_EGG_LARGEST, ASSET_380_MODEL_PINK_EGG_LARGEST, 0x01, chPinkEggAnimations,
    chPinkEgg_update, actor_update_func_80326224, chPinkEgg_draw,
    0, 0x2CC, 6.0f, 0
};

ActorInfo chPinkEggLarge = {MARKER_D6_PINK_EGG_LARGE, ACTOR_ED_PINK_EGG_LARGE, ASSET_381_MODEL_PINK_EGG_LARGE, 0x01, chPinkEggAnimations,
    chPinkEgg_update, actor_update_func_80326224, chPinkEgg_draw,
    0, 0x2CC, 5.0f, 0
};

ActorInfo chPinkEggMedium = {MARKER_D7_PINK_EGG_MEDIUM, ACTOR_EE_PINK_EGG_MEDIUM, ASSET_382_MODEL_PINK_EGG_MEDIUM, 0x01, chPinkEggAnimations,
    chPinkEgg_update, actor_update_func_80326224, chPinkEgg_draw,
    0, 0x2CC, 4.0f, 0
};

ActorInfo chPinkEggSmall = {MARKER_D8_PINK_EGG_SMALL, ACTOR_EF_PINK_EGG_SMALL, ASSET_383_MODEL_PINK_EGG_SMALL, 0x01, chPinkEggAnimations,
    chPinkEgg_update, actor_update_func_80326224, chPinkEgg_draw,
    0, 0x2CC, 3.0f, 0
};

ActorInfo chPinkEggSmallest = {MARKER_D9_PINK_EGG_SMALLEST, ACTOR_F0_PINK_EGG_SMALLEST, ASSET_384_MODEL_PINK_EGG_SMALLEST, 0x01, chPinkEggAnimations,
    chPinkEgg_update, actor_update_func_80326224, chPinkEgg_draw,
    0, 0x2CC, 2.0f, 0
};

/* .code */
void chPinkEgg_spawnNext(ActorMarker * arg0, u32 arg1){
    ActorLocal_PinkEgg *local;
    Actor *actorPtr;
    Actor *unkActor;
    actorPtr = marker_getActor(arg0);
    local = (ActorLocal_PinkEgg *)&actorPtr->local;
    unkActor = spawn_child_actor( D_803906C4[arg1], &actorPtr);

    ((ActorLocal_PinkEgg *) &unkActor->local)->unk0 = arg1 + 1;
    ((ActorLocal_PinkEgg *) &unkActor->local)->unk4 = 5;
    unkActor->marker->collidable = FALSE;
    
}

Actor *chPinkEgg_draw(ActorMarker *this, Gfx ** gdl, Mtx** mptr, Vtx **arg3){
    u32 sp18;
    u32 t7;

    t7 = marker_getActor(this)->state == 3;
    func_8033A45C(1, NOT(sp18 = t7));
    func_8033A45C(2, sp18);
    return actor_draw(this, gdl, mptr, arg3);
}


void chPinkEgg_collision(ActorMarker *this, ActorMarker *other_marker){
    Actor *thisActor;
    ActorLocal_PinkEgg *tmp;
    
    thisActor = marker_getActor(this);
    this->propPtr->unk8_3 = 0;
    gcsfx_playAtSampleRate(SFX_AA_BGS_EGG_BREAKING_1, 28000);
    subaddie_set_state(thisActor, 3);
    actor_playAnimationOnce(thisActor);
    this->collidable = FALSE;
    thisActor->unk124_6 = 0;
    if(D_803906C4[(tmp = (ActorLocal_PinkEgg *) &thisActor->local)->unk0] != 0){
        __spawnQueue_add_2(chPinkEgg_spawnNext, thisActor->marker, tmp->unk0);
    } else {
        jiggy_spawn(JIGGY_21_BGS_PINKEGG, thisActor->position);
        coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    }
}

void chPinkEgg_update(Actor *this){
    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, NULL, chPinkEgg_collision);
        this->initialized = TRUE;
    }

    switch(this->state){
        case 1:
            if(!((ActorLocal_PinkEgg *) &this->local)->unk4){
                this->marker->collidable = TRUE;
                subaddie_set_state(this,2);
                
            }else{
                ((ActorLocal_PinkEgg *) &this->local)->unk4--;
            }
            break;
        case 3:
            if(anctrl_isStopped(this->anctrl)){
                func_80326310(this);
                if(this->alpha_124_19 < 0x60){
                    this->depth_mode = 0x2;
                }
            }
            break;
    }
}
