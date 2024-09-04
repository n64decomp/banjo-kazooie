#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"

extern ActorInfo D_80390804;
extern ActorInfo D_80390690;
extern ActorInfo D_803906F8;
extern ActorInfo D_8039071C;
extern ActorInfo D_80390740;
extern ActorInfo D_80390764;
extern ActorInfo D_80390788;
extern ActorInfo D_80390B68;
extern ActorInfo D_80390C40;
extern ActorInfo D_80390C88;
extern ActorInfo D_80390CC8;
extern ActorInfo D_80390D08;
extern ActorInfo D_80390D48;
extern ActorInfo chFrogMinigame;
extern ActorInfo BGS_D_80390AE0;
extern ActorInfo D_80390960;
extern ActorInfo D_80390A40;
extern ActorInfo D_80390A70;
extern ActorInfo D_80390830;
extern ActorInfo D_80390880;
extern ActorInfo D_803908A4;
extern ActorInfo D_803908C8;
extern ActorInfo D_803908EC;
extern ActorInfo D_80390910;
extern ActorInfo D_80390934;
extern ActorInfo D_80390DA8;
extern ActorInfo D_80390D70;
extern ActorInfo D_80390BD8;
extern ActorInfo D_80390BFC;

void BGS_func_8038F1E0(void){//bgs_updateSpawnableActors
    spawnableActorList_add(&D_80390804, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);//croctus
    spawnableActorList_add(&D_80390690, actor_new, ACTOR_FLAG_UNKNOWN_25 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_0); //flibbit
    spawnableActorList_add(&D_803906F8, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_largest
    spawnableActorList_add(&D_8039071C, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_large
    spawnableActorList_add(&D_80390740, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_medium
    spawnableActorList_add(&D_80390764, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_small
    spawnableActorList_add(&D_80390788, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_smallest
    spawnableActorList_add(&D_80390B68, actor_new, ACTOR_FLAG_NONE); //mudhut_top
    spawnableActorList_add(&D_80390C40, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_3);//tanktup
    spawnableActorList_add(&D_80390C88, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&D_80390CC8, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&D_80390D08, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&D_80390D48, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&chFrogMinigame, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_0);
    spawnableActorList_add(&BGS_D_80390AE0, actor_new, ACTOR_FLAG_UNKNOWN_25 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_0); //yellow_flibbit
    spawnableActorList_add(&D_80390960, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80390A40, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7); //yumblie
    spawnableActorList_add(&D_80390A70, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_1); //mr. vile
    spawnableActorList_add(&D_80390830, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup
    spawnableActorList_add(&D_80390880, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&D_803908A4, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&D_803908C8, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&D_803908EC, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&D_80390910, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&D_80390934, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&D_80390DA8, actor_new, ACTOR_FLAG_UNKNOWN_14); //leafboat
    spawnableActorList_add(&D_80390D70, actor_new, ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7); //bigAlligator
    spawnableActorList_add(&D_80390BD8, actor_new, ACTOR_FLAG_UNKNOWN_3); //green_jiggy_switch
    spawnableActorList_add(&D_80390BFC, actor_new, ACTOR_FLAG_UNKNOWN_3); //green_jiggy_switch
}


