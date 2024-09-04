#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

extern ActorInfo D_80389AA0;
extern ActorInfo D_80389AD0;
extern ActorInfo D_80389B00;
extern ActorInfo D_80389B24;
extern ActorInfo D_80389B90;
extern ActorInfo D_80389BB4;
extern ActorInfo D_80389C90;
extern ActorInfo D_80389CB4;
extern ActorInfo D_80389CD8;
extern ActorInfo D_80389CFC;
extern ActorInfo D_80389D20;
extern ActorInfo D_80389D44;
extern ActorInfo D_80389D68;
extern ActorInfo D_80389D8C;
extern ActorInfo D_80389DB0;
extern ActorInfo D_80389DD4;
extern ActorInfo D_80389DF8;
extern ActorInfo D_80389E1C;
extern ActorInfo D_80389E44;
extern ActorInfo D_80389E68;
extern ActorInfo D_80389E8C;

/* .code */
void CC_func_80387DA0(void)
{
    spawnableActorList_add(&D_80389AA0, actor_new, ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&D_80389E44, actor_new, ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&D_80389E68, actor_new, ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&D_80389E8C, actor_new, ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_7 );
    spawnableActorList_add(&D_80389AD0, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80389B00, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80389B24, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80389B90, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80389BB4, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80389C90, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389CB4, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389CD8, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389CFC, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389D20, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389D44, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389D68, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389D8C, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389DB0, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389DD4, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389DF8, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_80389E1C, actor_new, ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_3);
}
