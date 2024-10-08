#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#define DEFRAG_THREAD_STACK_SIZE 0x800

void defragThread_entry(void *arg);

OSMesgQueue D_8027E120;
OSMesg      D_8027E138;
OSMesgQueue D_8027E140;
OSMesg      D_8027E158;
OSThread    sDefragThread;
u8          sDefragThreadStack[0x800];

/* .code */
void defragManager_init(void){
    osCreateMesgQueue(&D_8027E120, &D_8027E138, 1);
    osCreateMesgQueue(&D_8027E140, &D_8027E158, 1);
    osCreateThread(&sDefragThread, 2, defragThread_entry, NULL, sDefragThreadStack + DEFRAG_THREAD_STACK_SIZE, 10);
    osStartThread(&sDefragThread);
}

void defragManager_free(void){
    osStopThread(&sDefragThread);
    osDestroyThread(&sDefragThread);
}

void defragManager_80240874(void){
    if(func_8023E000() == 3){
        osSendMesg(&D_8027E120, NULL, OS_MESG_BLOCK);
    }
}

void defragManager_802408B0(void){
    if(func_8023E000() == 3){
        osSendMesg(&D_8027E140, NULL, OS_MESG_BLOCK);
    }
}

void defragManager_setPriority(OSPri pri){
    if(func_8023E000() == 3){
        osSetThreadPri(&sDefragThread, pri);
    }
}

void defragThread_entry(void *arg) {
    int tmp_v0;
    do{
        osRecvMesg(&D_8027E120, NULL, OS_MESG_BLOCK);
        if(!D_8027E140.validCount){
            do{
                tmp_v0 = game_defrag();
            }while(!D_8027E140.validCount && tmp_v0);
        }
        osRecvMesg(&D_8027E140, NULL, OS_MESG_BLOCK);
    }while(1);
}
