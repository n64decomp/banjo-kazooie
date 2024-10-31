#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"

int ability_hasLearned(s32);

extern s32 D_80275650;


extern ActorInfo D_8038AB00;
extern ActorInfo D_8038ABF0;
extern ActorInfo gChAttackTutorial;
extern ActorInfo gChVegetablesTopperA;
extern ActorInfo gChVegetablesBawlA;
extern ActorInfo gChVegetablesCollywobbleA;
extern ActorInfo gChVegetablesTopperB;
extern ActorInfo gChVegetablesBawlB;
extern ActorInfo gChVegetablesCollywobbleB;
extern ActorInfo gChBottles;
extern ActorInfo gChJumpTutorial;
extern ActorInfo D_8038B0E0;
extern ActorInfo D_8038B008; //chBanjosBed
extern ActorInfo D_8038B044; //chBanjosChair
extern ActorInfo D_8038B080; //chBanjosStove
extern ActorInfo D_8038AB24;

extern u32 D_803FFE00[4];

/* .data */
s32 D_8038AAE0 = 0x000FE2C1; //compiled SM_code_crc_1
s32 D_8038AAE4 = 0x8C0992D1; //compiled SM_code_crc_2
union {
    u8 byte[4];
    s32 word;
} D_8038AAE8 = {0x00, 0x01, 0xEB, 0x56}; //compiled SM_data_crc_1 (with this disabled out)
s32 D_8038AAEC = 0;

/* .bss */
struct {
    s32 unk0; //calculated SM_code_crc1
    s32 unk4; //calculated SM_code_crc2
    s32 unk8; //calculated SM_data_crc1
    s32 unkC; //calculated SM_data_crc2
} D_8038B320;


/* .code */
//dynamically gets learned ability bitfield address
u32 *func_803864E0(void){
    s16 *addr;
    addr = (s16*)ability_hasLearned;
    return (u32 *)((addr[1] << 0x10) + addr[3]);
}

void func_803864FC(enum ability_e arg0){
    u32 *addr;
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO){
        addr = func_803864E0();
        *addr = 1 << arg0;
    }
}

void func_80386540(void){
    u32 *sp2C;
    s32 sp28;
    u32 *addr;
    u32 sp20;
    sp2C = func_803864E0();
    sp28 = *sp2C;
    *sp2C = 0;
    if(ability_hasLearned(ABILITY_1_BEAK_BOMB)){
        addr = (u32*)ability_hasLearned;
        addr[2] = 0x03E00008; //jr $ra
        addr[3] = 0x00001025; //or $v0, $zero, $zero
        osWritebackDCache(addr, 0x10);
        osInvalICache(addr, 0x10);
    }

    *sp2C = sp28;
    osPiReadIo(0x574, &sp20);
    if((sp20 = (sp20 & 0xffff)) !=  0x6c07)
        func_803864FC(ABILITY_A_HOLD_A_JUMP_HIGHER);

    if(!SM_CRCs_are_valid())
        func_803864FC(ABILITY_10_TALON_TROT);
    

    if(!func_803866CC())
        func_803864FC(ABILITY_C_ROLL);
}

void func_80386614(u8 *arg0, u8 *arg1, s32 *arg2, s32 *arg3){
    s32 temp_v0 = 0;
    s32 temp_v1 = -1;
    s32 i;
    s32 val;
    u8* iPtr;

    iPtr = arg0;
    
    for(i = (arg1 - arg0); i > 0 ; i--){
        val = *(iPtr++);
        temp_v0 += val;
        temp_v1 ^= val << (temp_v0 & 0x17);
    }

    if(arg1); //make $a1 not used in loop

    *arg2 = temp_v0;
    *arg3 = temp_v1;
}

extern u8 crc_ROM_START[];

int func_803866CC(void){
    u32 sp24;

    if( (osPiReadIo((u32)crc_ROM_START + 8, &sp24), sp24 == D_803FFE00[0])
        && (osPiReadIo((u32)crc_ROM_START + 12, &sp24), sp24 == D_803FFE00[1])
        && (osPiReadIo((u32)crc_ROM_START + 16, &sp24), sp24 == D_803FFE00[2])
        && (osPiReadIo((u32)crc_ROM_START + 20, &sp24), sp24 == D_803FFE00[3])
    ){
        return 1;
    }
    return 0;
}

bool SM_CRCs_are_valid(void){
    if( D_8038B320.unk0 == D_8038AAE0
        && D_8038B320.unk4 == D_8038AAE4 
        && D_8038B320.unkC == D_80275650 
        && D_8038B320.unk8 == D_8038AAE8.word + D_8038AAE8.byte[0] + D_8038AAE8.byte[1] + D_8038AAE8.byte[2] + D_8038AAE8.byte[3]
    ){
        return TRUE;
    }
    return FALSE;
}

void SM_func_80386810(void)
{
    spawnableActorList_add(&D_8038AB00,  actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_8038ABF0,  actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&gChAttackTutorial,  actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gChVegetablesTopperA,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesBawlA,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesCollywobbleA,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_21 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesTopperB,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesBawlB,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesCollywobbleB,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_21 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChBottles,  actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&gChJumpTutorial,  actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038B0E0,  actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038B008,  actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038B044,  actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038B080,  actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038AB24,  actor_new, ACTOR_FLAG_UNKNOWN_10);
}
