#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

extern ActorInfo maClankersScrew;
extern ActorInfo maClankerKey;
extern ActorInfo chClankerTokenToothExt;
extern ActorInfo chClankerJiggyToothExt;
extern ActorInfo chClankerTokenToothInt;
extern ActorInfo chClankerJiggyToothInt;
extern ActorInfo chSawblade1;
extern ActorInfo chSawblade2;
extern ActorInfo chSawblade3;
extern ActorInfo chSawblade4;
extern ActorInfo chSawblade5;
extern ActorInfo chSawblade6;
extern ActorInfo chSawblade7;
extern ActorInfo chSawblade8;
extern ActorInfo chSawblade9;
extern ActorInfo chSawblade10;
extern ActorInfo chSawblade11;
extern ActorInfo chSawblade12;
extern ActorInfo chCCGrate1;
extern ActorInfo chCCGrate2;
extern ActorInfo chCCGrate3;

/* .code */
void CC_func_80387DA0(void)
{
    spawnableActorList_add(&maClankersScrew, actor_new, ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&chCCGrate1, actor_new, ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&chCCGrate2, actor_new, ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&chCCGrate3, actor_new, ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&maClankerKey, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chClankerTokenToothExt, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chClankerJiggyToothExt, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chClankerTokenToothInt, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chClankerJiggyToothInt, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chSawblade1, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade2, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade3, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade4, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade5, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade6, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade7, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade8, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade9, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade10, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade11, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chSawblade12, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
}
