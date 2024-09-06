#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern ActorInfo chFightFlightPad;
extern ActorInfo chFinalBoss;
extern ActorInfo chBossJinjoOrange;
extern ActorInfo chBossJinjoGreen;
extern ActorInfo chBossJinjoPink;
extern ActorInfo chBossJinjoYellow;
extern ActorInfo chBossJinjoBase;
extern ActorInfo chStoneJinjo;
extern ActorInfo chJinjonatorBase;
extern ActorInfo chSpellBarrier;
extern ActorInfo chSpellFireball;
extern ActorInfo chSpellGreen;
extern ActorInfo chSpriteSmokeGreen2;
extern ActorInfo chJinjonator;
extern ActorInfo chBossShadow;

/* .bss */
u8 pad_fight_80392740[0x10];

void fight_func_803863F0(void)
{
    spawnableActorList_add(&chSpellFireball, actor_new, 0X108444);
    spawnableActorList_add(&chSpriteSmokeGreen2, actor_new, 0X108444);
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
