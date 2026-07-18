#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"
#include "checksums.h"

int ability_hasLearned(s32);



extern ActorInfo gQuarrie;
extern ActorInfo gCodeBF0;
extern ActorInfo gChAttackTutorial;
extern ActorInfo gChVegetablesTopperA;
extern ActorInfo gChVegetablesBawlA;
extern ActorInfo gChVegetablesCollywobbleA;
extern ActorInfo gChVegetablesTopperB;
extern ActorInfo gChVegetablesBawlB;
extern ActorInfo gChVegetablesCollywobbleB;
extern ActorInfo gChBottles;
extern ActorInfo gChJumpTutorial;
extern ActorInfo gSmBridgeChecksumTrigger;
extern ActorInfo gBanjosBed;
extern ActorInfo gBanjosChair;
extern ActorInfo gBanjosStove;
extern ActorInfo gRockTrappingGrunty;

s32 D_8038AAE0 = VER_SELECT(0x000FE2C1, 0x00109339, 0, 0); // SM_TEXT_CRC1
s32 D_8038AAE4 = VER_SELECT(0x8C0992D1, 0xC3A58E96, 0, 0); // SM_TEXT_CRC2
s32 D_8038AAE8 = VER_SELECT(0x0001EB56, 0x00020B4D, 0, 0); // SM_DATA_CRC1
s32 D_8038AAEC = 0;


/* .code */
static u32 *__codeF0_getLearnedAbilitiesAddress(){
    s16 *addr;
    addr = (s16*)ability_hasLearned;
    return (u32 *)((addr[1] << 0x10) + addr[3]);
}

static void __codeF0_learnAbility(enum ability_e ability){
    u32 *addr;
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO){
        addr = __codeF0_getLearnedAbilitiesAddress();
        *addr = 1 << ability;
    }
}

void codeF0_breakAbilitiesIfChecksumsFail(){
#if ANTI_TAMPER
    u32 *learned_abilities_address;
    s32 sp28;
    u32 *addr;
    u32 rom_data;

    learned_abilities_address = __codeF0_getLearnedAbilitiesAddress();
    sp28 = *learned_abilities_address;
    *learned_abilities_address = 0;
    if(ability_hasLearned(ABILITY_1_BEAK_BOMB)){
        addr = (u32*)ability_hasLearned;
        addr[2] = 0x03E00008; //jr $ra
        addr[3] = 0x00001025; //or $v0, $zero, $zero
        osWritebackDCache(addr, 0x10);
        osInvalICache(addr, 0x10);
    }

    *learned_abilities_address = sp28;

    osPiReadIo(0x574, &rom_data);
    if((rom_data = (rom_data & 0xffff)) != 0x6c07)
        __codeF0_learnAbility(ABILITY_A_HOLD_A_JUMP_HIGHER);

    if(!__codeF0_areCrcsValid())
        __codeF0_learnAbility(ABILITY_10_TALON_TROT);

    if(!__codeF0_areRomCrcsCorrect())
        __codeF0_learnAbility(ABILITY_C_ROLL);
#endif
}

void __codeF0_pad_func_80386614(u8 *arg0, u8 *arg1, s32 *arg2, s32 *arg3){
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

#if ANTI_TAMPER
static bool __codeF0_areRomCrcsCorrect(){
    u32 sp24;

    if( (osPiReadIo((u32)crc_ROM_START + CRC_CORE1_TEXT_CHECKSUM1, &sp24), sp24 == gChecksumsCore1.text_checksum1)
        && (osPiReadIo((u32)crc_ROM_START + CRC_CORE1_TEXT_CHECKSUM2, &sp24), sp24 == gChecksumsCore1.text_checksum2)
        && (osPiReadIo((u32)crc_ROM_START + CRC_CORE1_DATA_CHECKSUM1, &sp24), sp24 == gChecksumsCore1.data_checksum1)
        && (osPiReadIo((u32)crc_ROM_START + CRC_CORE1_DATA_CHECKSUM2, &sp24), sp24 == gChecksumsCore1.data_checksum2)
    ){
        return TRUE;
    }

    return FALSE;
}

static bool __codeF0_areCrcsValid(){
    if( gChecksumsSM.text_checksum1 == D_8038AAE0
        && gChecksumsSM.text_checksum2 == D_8038AAE4 
        && gChecksumsSM.data_checksum2 == D_80275650 
        && gChecksumsSM.data_checksum1 == D_8038AAE8 + ((u8 *) &D_8038AAE8)[0] + ((u8 *) &D_8038AAE8)[1] + ((u8 *) &D_8038AAE8)[2] + ((u8 *) &D_8038AAE8)[3]
    ){
        return TRUE;
    }
    return FALSE;
}
#endif

void SM_resetSpawnableActors()
{
    spawnableActorList_add(&gQuarrie,  actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gCodeBF0,  actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&gChAttackTutorial,  actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gChVegetablesTopperA,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesBawlA,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesCollywobbleA,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_21 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesTopperB,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesBawlB,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVegetablesCollywobbleB,  actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_21 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChBottles,  actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&gChJumpTutorial,  actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gSmBridgeChecksumTrigger ,  actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gBanjosBed,  actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gBanjosChair,  actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gBanjosStove,  actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&gRockTrappingGrunty,  actor_new, ACTOR_FLAG_UNKNOWN_10);
}
