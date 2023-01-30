#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void __defrag_thread(s32 arg0);

OSMesgQueue D_8027E120;
OSMesg      D_8027E138;
OSMesgQueue D_8027E140;
OSMesg      D_8027E158;
OSThread    defragThread;
u8          defragStack[0x800];

/* .code */
void defragManager_init(void){
    osCreateMesgQueue(&D_8027E120, &D_8027E138, 1);
    osCreateMesgQueue(&D_8027E140, &D_8027E158, 1);
    osCreateThread(&defragThread, 2, __defrag_thread, NULL,  &defragStack[0x800], 10);
    osStartThread(&defragThread);
}

void defragManager_free(void){
    osStopThread(&defragThread);
    osDestroyThread(&defragThread);
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
        osSetThreadPri(&defragThread, pri);
    }
}

void __defrag_thread(s32 arg0){
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
