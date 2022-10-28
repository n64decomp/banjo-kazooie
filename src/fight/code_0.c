#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
extern ActorInfo D_80366F68;

extern ActorInfo fight_D_80391500;
extern ActorInfo D_80391840;
extern ActorInfo D_80391864;
extern ActorInfo D_80391888;
extern ActorInfo D_803918AC;
extern ActorInfo D_80391990;
extern ActorInfo fight_D_80391A10;
extern ActorInfo fight_D_80391A40;
extern ActorInfo D_80391AD0;
extern ActorInfo fight_D_80391B00;
extern ActorInfo D_80391B24;
extern ActorInfo D_80391DC0;
extern ActorInfo D_80392018;
extern ActorInfo D_80392090;

/* .bss */
u8 pad_80392750[0x10];

void fight_func_803863F0(void)
{
    spawnableActorList_add(&fight_D_80391B00, actor_new, 0X108444);
    spawnableActorList_add(&D_80391DC0, actor_new, 0X108444);
    spawnableActorList_add(&fight_D_80391500, actor_new, 0X300468);
    spawnableActorList_add(&D_80391840, actor_new, 0X8464);
    spawnableActorList_add(&D_80391864, actor_new, 0X8464);
    spawnableActorList_add(&D_80391888, actor_new, 0X8464);
    spawnableActorList_add(&D_803918AC, actor_new, 0X8464);
    spawnableActorList_add(&fight_D_80391A10, actor_new, 0X20004);
    spawnableActorList_add(&D_80391990, actor_new, 0X800100C);
    spawnableActorList_add(&fight_D_80391A40, actor_new, 0X8009404);
    spawnableActorList_add(&D_80391B24, actor_new, 0X108444);
    spawnableActorList_add(&D_80391AD0, actor_new, 0X101404);
    spawnableActorList_add(&D_80366F68, actor_new, 0X100404);
    spawnableActorList_add(&D_80392018, actor_new, 0X9464);
    spawnableActorList_add(&D_80392090, actor_new, 0X100404);
}
