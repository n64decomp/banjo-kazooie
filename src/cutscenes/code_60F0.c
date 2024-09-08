#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

extern void func_802E07E0(Actor *);
extern Actor* func_802E0738(ActorMarker *, Gfx **, Mtx**, Vtx **);

extern ActorInfo D_80366CD0;
extern ActorInfo D_8038E718;
extern ActorInfo D_8038E7A0;
extern ActorInfo D_8038E8A8;


/* .data */
ActorInfo D_8038DC90 = 
{
    0x017, 0x08E, 0x355, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 5.0f, 0
};

ActorInfo D_8038DCB4 = 
{
    0x01A, 0x091, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DCD8 = 
{
    0x019, 0x090, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DCFC = 
{
    0x018, 0x08F, 0x3B1, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 5.0f, 0
};

ActorInfo D_8038DD20 = 
{
    0x01B, 0x092, 0x35A, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 3.0f, 0
};

ActorInfo D_8038DD44 = 
{
    0x01C, 0x093, 0x3A6, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DD68 = 
{
    0x01D, 0x094, 0x3A7, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DD8C = 
{
    0x01E, 0x095, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DDB0 = 
{
    0x01F, 0x096, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DDD4 = 
{
    0x020, 0x097, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DDF8 = 
{
    0x021, 0x098, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DE1C = 
{
    0x022, 0x099, 0x3AA, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DE40 = 
{
    0x023, 0x09A, 0x3AB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DE64 = 
{
    0x024, 0x09B, 0x354, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 3.0f, 0
};

ActorInfo D_8038DE88 = 
{
    0x025, 0x09C, 0x369, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.4f, 0
};

ActorInfo D_8038DEAC = 
{
    0x026, 0x09D, 0x353, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 4.0f, 0
};

ActorInfo D_8038DED0 = 
{
    0x027, 0x09E, 0x53D, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DEF4 = 
{
    0x06F, 0x09F, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DF18 = 
{
    0x070, 0x0A0, 0x34D, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DF3C = 
{
    0x071, 0x0A1, 0x3AC, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DF60 = 
{
    0x073, 0x0A3, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DF84 = 
{
    0x074, 0x0A4, 0x433, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DFA8 = 
{
    0x075, 0x0A5, 0x3ED, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038DFCC = 
{
    0x076, 0x0A6, 0x398, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.5f, 0
};

ActorInfo D_8038DFF0 = 
{
    0x077, 0x0A7, 0x473, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E014 = 
{
    0x078, 0x0A8, 0x474, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E038 = 
{
    0x079, 0x0A9, 0x454, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E05C = 
{
    0x07A, 0x0AA, 0x453, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E080 = 
{
    0x07B, 0x0AB, 0x452, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E0A4 = 
{
    0x07C, 0x0AC, 0x451, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E0C8 = 
{
    0x07D, 0x0AD, 0x3CA, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E0EC = 
{
    0x07E, 0x0AE, 0x450, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E110 = 
{
    0x07F, 0x0AF, 0x44F, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E134 = 
{
    0x080, 0x0B0, 0x387, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E158 = 
{
    0x081, 0x0B1, 0x388, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E17C = 
{
    0x082, 0x0B2, 0x347, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E1A0 = 
{
    0x084, 0x0B4, 0x35B, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E1C4 = 
{
    0x085, 0x0B5, 0x456, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E1E8 = 
{
    0x086, 0x0B6, 0x457, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E20C = 
{
    0x087, 0x0B7, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E230 = 
{
    0x088, 0x0B8, 0x458, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E254 = 
{
    0x089, 0x0B9, 0x459, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E278 = 
{
    0x08A, 0x0BA, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E29C = 
{
    0x08B, 0x0BB, 0x45B, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E2C0 = 
{
    0x08E, 0x0BE, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E2E4 = 
{
    0x08F, 0x0BF, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E308 = 
{
    0x090, 0x0C0, 0x460, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E32C = 
{
    0x091, 0x0C1, 0x467, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E350 = 
{
    0x092, 0x0C2, 0x468, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E374 = 
{
    0x093, 0x0C3, 0x469, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E398 = 
{
    0x136, 0x2ED, 0x340, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E3BC = 
{
    0x137, 0x2EE, 0x46A, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E3E0 = 
{
    0x138, 0x2EF, 0x35B, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E404 = 
{
    0x139, 0x2F0, 0x341, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E428 = 
{
    0x13A, 0x2F1, 0x46B, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E44C = 
{
    0x13B, 0x2F2, 0x340, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E470 = 
{
    0x13C, 0x2F3, 0x46D, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E494 = 
{
    0x143, 0x2FA, 0x46A, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E4B8 = 
{
    0x144, 0x2FB, 0x532, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E4DC = 
{
    0x145, 0x2FC, 0x3C6, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E500 = 
{
    0x146, 0x2FD, 0x3B0, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E524 = 
{
    0x147, 0x2FE, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E548 = 
{
    0x148, 0x2FF, 0x461, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E56C = 
{
    0x149, 0x300, 0x479, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E590 = 
{
    0x14A, 0x301, 0x370, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E5B4 = 
{
    0x14B, 0x302, 0x47B, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E5D8 = 
{
    0x14C, 0x303, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E5FC = 
{
    0x14D, 0x304, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E620 = 
{
    0x14E, 0x305, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E644 = 
{
    0x14F, 0x306, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E668 = 
{
    0x150, 0x307, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E68C = 
{
    0x151, 0x308, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E6B0 = 
{
    0x152, 0x309, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};

ActorInfo D_8038E6D4 = 
{
    0x153, 0x30A, 0x3BB, 
    1, NULL, 
    NULL, func_802E07E0, func_802E0738, 
    0, 0, 0.0f, 0
};


void cutscene_func_8038C4E0(void){
    spawnableActorList_add(&D_8038DC90, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038DCFC, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038DCD8, actor_new, ACTOR_FLAG_UNKNOWN_13);
    spawnableActorList_add(&D_8038DCB4, actor_new, ACTOR_FLAG_UNKNOWN_13);
    spawnableActorList_add(&D_8038DD20, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038DD44, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038DD68, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038DD8C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DDB0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DDD4, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DDF8, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DE1C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DE40, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DE64, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DE88, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DEAC, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DED0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038DEF4, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DF18, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DF3C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DF60, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_13);
    spawnableActorList_add(&D_8038DF84, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DFA8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038DFCC, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038DFF0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E014, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E038, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038E05C, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038E080, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038E0A4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E0C8, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E0EC, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E110, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_13);
    spawnableActorList_add(&D_8038E134, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E158, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038E17C, actor_new, ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_8038E1A0, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E1C4, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038E1E8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E20C, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E230, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038E254, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&D_8038E278, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E29C, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E2C0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E2E4, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E308, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E32C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E350, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E374, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E398, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_8038E3BC, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E3E0, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E404, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038E428, actor_new, ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_8038E44C, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038E470, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E494, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E4B8, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038E4DC, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038E500, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E524, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038E548, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E56C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E590, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E5B4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E5D8, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E5FC, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E620, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E644, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E668, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E68C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E6B0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E6D4, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80366CD0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038E718, actor_new, ACTOR_FLAG_UNKNOWN_1);
    spawnableActorList_add(&D_8038E7A0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038E8A8, actor_new, ACTOR_FLAG_UNKNOWN_1);
}
