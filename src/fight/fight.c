#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "fight.h"
#include "actor.h"

u8 sFightPadding[0x10];

void fight_addSpawnableActors(void)
{
    spawnableActorList_add(&chSpellFireball, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20);
    spawnableActorList_add(&chGreenBlast, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20);
    spawnableActorList_add(&chFinalBoss, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_21);
    spawnableActorList_add(&chBossJinjoOrange, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chBossJinjoGreen, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chBossJinjoPink, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chBossJinjoYellow, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chStoneJinjo, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&chBossJinjoBase, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_27);
    spawnableActorList_add(&chJinjonatorBase, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_27);
    spawnableActorList_add(&chSpellGreen, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20);
    spawnableActorList_add(&chSpellBarrier, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_20);
    spawnableActorList_add(&chFightFlightPad, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_20);
    spawnableActorList_add(&chJinjonator, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chBossShadow, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_20);
}
