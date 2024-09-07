#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "fight.h"

u8 pad_fight_80392740[0x10];

void fight_func_803863F0(void)
{
    spawnableActorList_add(&chSpellFireball, actor_new, 0X108444);
    spawnableActorList_add(&chGreenBlast, actor_new, 0X108444);
    spawnableActorList_add(&chFinalBoss, actor_new, 0X300468);
    spawnableActorList_add(&chBossJinjoOrange, actor_new, 0X8464);
    spawnableActorList_add(&chBossJinjoGreen, actor_new, 0X8464);
    spawnableActorList_add(&chBossJinjoPink, actor_new, 0X8464);
    spawnableActorList_add(&chBossJinjoYellow, actor_new, 0X8464);
    spawnableActorList_add(&chStoneJinjo, actor_new, 0X20004);
    spawnableActorList_add(&chBossJinjoBase, actor_new, 0X800100C);
    spawnableActorList_add(&chJinjonatorBase, actor_new, 0X8009404);
    spawnableActorList_add(&chSpellGreen, actor_new, 0X108444);
    spawnableActorList_add(&chSpellBarrier, actor_new, 0X101404);
    spawnableActorList_add(&chFightFlightPad, actor_new, 0X100404);
    spawnableActorList_add(&chJinjonator, actor_new, 0X9464);
    spawnableActorList_add(&chBossShadow, actor_new, 0X100404);
}
