#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80240924(s32 arg0);

extern OSMesgQueue D_8027E120;
extern OSMesg D_8027E138;
extern OSMesgQueue D_8027E140;
extern OSMesg D_8027E158;
extern OSThread D_8027E160;

extern u8 D_8027EB10;

/* .code */
void func_802407C0(void){
    osCreateMesgQueue(&D_8027E120, &D_8027E138, 1);
    osCreateMesgQueue(&D_8027E140, &D_8027E158, 1);
    osCreateThread(&D_8027E160, 2, func_80240924, NULL,  &D_8027EB10, 10);
    osStartThread(&D_8027E160);
}

void func_80240844(void){
    osStopThread(&D_8027E160);
    osDestroyThread(&D_8027E160);
}

void func_80240874(void){
    if(func_8023E000() == 3){
        osSendMesg(&D_8027E120, NULL, OS_MESG_BLOCK);
    }
}

void func_802408B0(void){
    if(func_8023E000() == 3){
        osSendMesg(&D_8027E140, NULL, OS_MESG_BLOCK);
    }
}

void func_802408EC(OSPri pri){
    if(func_8023E000() == 3){
        osSetThreadPri(&D_8027E160, pri);
    }
}

void func_80240924(s32 arg0){
    int tmp_v0;
    do{
        osRecvMesg(&D_8027E120, NULL, OS_MESG_BLOCK);
        if(!D_8027E140.validCount){
            do{
                tmp_v0 = func_802E48D8();
            }while(!D_8027E140.validCount && tmp_v0);
        }
        osRecvMesg(&D_8027E140, NULL, OS_MESG_BLOCK);
    }while(1);
}
