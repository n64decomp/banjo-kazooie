#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"

extern ActorInfo gChCroctus;
extern ActorInfo gChFlibbit;
extern ActorInfo gChPinkEggLargest;
extern ActorInfo gChPinkEggLarge;
extern ActorInfo gChPinkEggMedium;
extern ActorInfo gChPinkEggSmall;
extern ActorInfo gChPinkEggSmallest;
extern ActorInfo gChMudHut;
extern ActorInfo gChTanktup;
extern ActorInfo gChTanktupLegFrontLeft;
extern ActorInfo gChTanktupLegBackLeft;
extern ActorInfo gChTanktupLegFrontRight;
extern ActorInfo gChTanktupLegBackRight;
extern ActorInfo gChFrogMinigame;
extern ActorInfo gChYellowFlibbit;
extern ActorInfo gChVileGame;
extern ActorInfo gChYumblie;
extern ActorInfo gChVile;
extern ActorInfo gChTiptup;
extern ActorInfo gChChoirTurtleYellow;
extern ActorInfo gChChoirTurtleCyan;
extern ActorInfo gChChoirTurtleBlue;
extern ActorInfo gChChoirTurtleRed;
extern ActorInfo gChChoirTurtlePink;
extern ActorInfo gChChoirTurtlePurple;
extern ActorInfo gChLeafBoat;
extern ActorInfo gChLargeCrocodile;
extern ActorInfo gChLongSwampSwitch;
extern ActorInfo gChShortSwampSwitch;

void BGS_func_8038F1E0(void){//bgs_updateSpawnableActors
    spawnableActorList_add(&gChCroctus, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);//croctus
    spawnableActorList_add(&gChFlibbit, actor_new, ACTOR_FLAG_UNKNOWN_25 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_0); //flibbit
    spawnableActorList_add(&gChPinkEggLargest, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_largest
    spawnableActorList_add(&gChPinkEggLarge, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_large
    spawnableActorList_add(&gChPinkEggMedium, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_medium
    spawnableActorList_add(&gChPinkEggSmall, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_small
    spawnableActorList_add(&gChPinkEggSmallest, actor_new, ACTOR_FLAG_UNKNOWN_10); //pink_egg_smallest
    spawnableActorList_add(&gChMudHut, actor_new, ACTOR_FLAG_NONE); //mudhut_top
    spawnableActorList_add(&gChTanktup, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_3);//tanktup
    spawnableActorList_add(&gChTanktupLegFrontLeft, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&gChTanktupLegBackLeft, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&gChTanktupLegFrontRight, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&gChTanktupLegBackRight, actor_new, ACTOR_FLAG_UNKNOWN_26 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_2);//tanktup_leg
    spawnableActorList_add(&gChFrogMinigame, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_0);
    spawnableActorList_add(&gChYellowFlibbit, actor_new, ACTOR_FLAG_UNKNOWN_25 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_0); //yellow_flibbit
    spawnableActorList_add(&gChVileGame, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gChYumblie, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7); //yumblie
    spawnableActorList_add(&gChVile, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_1); //mr. vile
    spawnableActorList_add(&gChTiptup, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup
    spawnableActorList_add(&gChChoirTurtleYellow, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&gChChoirTurtleCyan, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&gChChoirTurtleBlue, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&gChChoirTurtleRed, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&gChChoirTurtlePink, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&gChChoirTurtlePurple, actor_new, ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_3 ); //tiptup_chiorMember
    spawnableActorList_add(&gChLeafBoat, actor_new, ACTOR_FLAG_UNKNOWN_14); //leafboat
    spawnableActorList_add(&gChLargeCrocodile, actor_new, ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_7); //bigAlligator
    spawnableActorList_add(&gChLongSwampSwitch, actor_new, ACTOR_FLAG_UNKNOWN_3); //green_jiggy_switch
    spawnableActorList_add(&gChShortSwampSwitch, actor_new, ACTOR_FLAG_UNKNOWN_3); //green_jiggy_switch
}


