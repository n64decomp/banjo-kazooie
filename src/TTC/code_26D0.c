#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"

extern ActorInfo D_8038C3D0;
extern ActorInfo D_8038C510;
extern ActorInfo D_8038C580;
extern ActorInfo D_8038C5E0;
extern ActorInfo D_8038C604;
extern ActorInfo D_8038C628;
extern ActorInfo D_8038C64C;
extern ActorInfo D_8038C670;
extern ActorInfo D_8038C694;
extern ActorInfo D_8038C6B8;
extern ActorInfo D_8038C6DC;
extern ActorInfo D_8038C718;
extern ActorInfo D_8038C790;
extern ActorInfo D_8038C7B4;
extern ActorInfo D_8038C7D8;
extern ActorInfo D_8038C8B0;
extern ActorInfo D_8038C8D4;
extern ActorInfo D_8038C8F8;
extern ActorInfo D_8038CCB0;

void func_80388AC0(void)
{
    spawnableActorList_add(&D_8038C5E0, actor_new, 0);
    spawnableActorList_add(&D_8038C604, actor_new, 0);
    spawnableActorList_add(&D_8038C580, actor_new, 0X4100168);
    spawnableActorList_add(&D_8038C510, actor_new, 0X4000101);
    spawnableActorList_add(&D_8038C718, actor_new, 0X188);
    spawnableActorList_add(&D_8038C790, actor_new, 0X148);
    spawnableActorList_add(&D_8038C7B4, actor_new, 0X148);
    spawnableActorList_add(&D_8038C7D8, actor_new, 0X148);
    spawnableActorList_add(&D_8038C8B0, actor_new, 0X400);
    spawnableActorList_add(&D_8038C8D4, actor_new, 0X400);
    spawnableActorList_add(&D_8038C8F8, actor_new, 0X400);
    spawnableActorList_add(&D_8038CCB0, actor_new, 0X2000048);
    spawnableActorList_add(&D_8038C628, actor_new, 0X8680);
    spawnableActorList_add(&D_8038C64C, actor_new, 0X400);
    spawnableActorList_add(&D_8038C670, actor_new, 0X20404);
    spawnableActorList_add(&D_8038C694, actor_new, 0X400);
    spawnableActorList_add(&D_8038C6B8, actor_new, 0X400);
    spawnableActorList_add(&D_8038C6DC, actor_new, 0X400);
    spawnableActorList_add(&D_8038C3D0, actor_new, 0X2000041);
}

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388D8C.s")
