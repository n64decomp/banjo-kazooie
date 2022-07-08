#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"

int ability_hasLearned(s32);

extern s32 D_80275650;


extern ActorInfo D_8038AB00;
extern ActorInfo D_8038ABF0;
extern ActorInfo D_8038AC20; //chAttackTutorial
extern ActorInfo D_8038AC78; //chCarrot Slave?
extern ActorInfo D_8038ACE8; //ch onion A
extern ActorInfo D_8038AD58; //ch cauliflower A
extern ActorInfo D_8038AC9C; //chCarrot FreeRange?
extern ActorInfo D_8038AD0C; //ch onion B
extern ActorInfo D_8038AD7C; //ch cauliflower B
extern ActorInfo D_8038AF90; //D_8038AF90 bottles
extern ActorInfo D_8038B0B0; //chJumpTutorial code_4070
extern ActorInfo D_8038B0E0;
extern ActorInfo D_8038B008; //chBanjosBed
extern ActorInfo D_8038B044; //chBanjosChair
extern ActorInfo D_8038B080; //chBanjosStove
extern ActorInfo D_8038AB24;

/* .data */
s32 D_8038AAE0 = 0x000FE2C1; //SM_code_crc_1
s32 D_8038AAE4 = 0x8C0992D1; //SM_code_crc_2
union {
    u8 byte[4];
    s32 word;
} D_8038AAE8 = {0x00, 0x01, 0xEB, 0x56}; //SM_data_crc_1
s32 D_8038AAEC = 0;

extern struct 
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} D_8038B320;

extern u32 D_803FFE00;
extern u32 D_803FFE04;
extern u32 D_803FFE08;
extern u32 D_803FFE0C;

u32 *func_803864E0(void){
    s16 *addr;
    addr = (s16*)ability_hasLearned;
    return (u32 *)((addr[1] << 0x10) + addr[3]);
}

void func_803864FC(s32 arg0){
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
        func_803864FC(0xa);

    if(!func_80386780())
        func_803864FC(0x10);
    

    if(!func_803866CC())
        func_803864FC(0xC);
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

extern s32 D_00005E70;

int func_803866CC(void){
    u32 sp24;

    if( (osPiReadIo((u32)&D_00005E70 + 8, &sp24), sp24 == D_803FFE00)
        && (osPiReadIo((u32)&D_00005E70 + 12, &sp24), sp24 == D_803FFE04)
        && (osPiReadIo((u32)&D_00005E70 + 16, &sp24), sp24 == D_803FFE08)
        && (osPiReadIo((u32)&D_00005E70 + 20, &sp24), sp24 == D_803FFE0C)
    ){
        return 1;
    }
    return 0;
}

int func_80386780(void){
    if( D_8038B320.unk0 == D_8038AAE0
        && D_8038B320.unk4 == D_8038AAE4 
        && D_8038B320.unkC == D_80275650 
        && D_8038B320.unk8 == D_8038AAE8.word + D_8038AAE8.byte[0] + D_8038AAE8.byte[1] + D_8038AAE8.byte[2] + D_8038AAE8.byte[3]
    ){
        return 1;
    }
    return 0;
}

void func_80386810(void)
{
    spawnableActorList_add(&D_8038AB00,  actor_new, 0X2000180);
    spawnableActorList_add(&D_8038ABF0,  actor_new, 0X80);
    spawnableActorList_add(&D_8038AC20,  actor_new, 0);
    spawnableActorList_add(&D_8038AC78,  actor_new, 0X2000121);
    spawnableActorList_add(&D_8038ACE8,  actor_new, 0X2000121);
    spawnableActorList_add(&D_8038AD58,  actor_new, 0X2200121);
    spawnableActorList_add(&D_8038AC9C,  actor_new, 0X2000121);
    spawnableActorList_add(&D_8038AD0C,  actor_new, 0X2000121);
    spawnableActorList_add(&D_8038AD7C,  actor_new, 0X2200121);
    spawnableActorList_add(&D_8038AF90,  actor_new, 0X100);
    spawnableActorList_add(&D_8038B0B0,  actor_new, 0);
    spawnableActorList_add(&D_8038B0E0,  actor_new, 0);
    spawnableActorList_add(&D_8038B008,  actor_new, 0X6C8);
    spawnableActorList_add(&D_8038B044,  actor_new, 0X6C8);
    spawnableActorList_add(&D_8038B080,  actor_new, 0X6C8);
    spawnableActorList_add(&D_8038AB24,  actor_new, 0X400);
}
