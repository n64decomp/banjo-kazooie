/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
    spawnableActorList_add( &chhutInfo,          actor_new,     0X400);
    spawnableActorList_add( &chchimpystump,      actor_new,       0x0);
    spawnableActorList_add( &chgrublinInfo,      actor_new, 0X2000121);
    spawnableActorList_add( &chcongaInfo,        actor_new, 0X2000160);
    spawnableActorList_add( &chorangeInfo,       actor_new,       0x0);
    spawnableActorList_add( &chjujuhitboxInfo,   actor_new,       0x0);
    spawnableActorList_add( &chjujuInfo,         actor_new,    0X4004);
    spawnableActorList_add( &chorangepadInfo,    actor_new,      0X40);
    spawnableActorList_add( &chlmonkeyInfo,      actor_new,     0X100);
}
