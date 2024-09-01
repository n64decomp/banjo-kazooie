/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

#include "prop.h"

extern ActorInfo chhutInfo;
extern ActorInfo chchimpystump;
extern ActorInfo chgrublinInfo;
extern ActorInfo chcongaInfo;
extern ActorInfo chorangeInfo;
extern ActorInfo chjujuhitboxInfo;
extern ActorInfo chjujuInfo;
extern ActorInfo chorangepadInfo;
extern ActorInfo chlmonkeyInfo;

void MM_func_803888B0(void){
    spawnableActorList_add( &chhutInfo,          actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add( &chchimpystump,      actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add( &chgrublinInfo,      actor_new, ACTOR_FLAG_UNKNOWN_25 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_0);
    spawnableActorList_add( &chcongaInfo,        actor_new, ACTOR_FLAG_UNKNOWN_25 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_5);
    spawnableActorList_add( &chorangeInfo,       actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add( &chjujuhitboxInfo,   actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add( &chjujuInfo,         actor_new, ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add( &chorangepadInfo,    actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add( &chlmonkeyInfo,      actor_new, ACTOR_FLAG_UNKNOWN_8);
}
