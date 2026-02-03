#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"

void defragThread_entry(void *arg);

static OSMesgQueue sDefragThreadResumeSyncQueue;
static OSMesg      sDefragThreadResumeSyncMesg;
static OSMesgQueue sDefragThreadPauseSyncQueue;
static OSMesg      sDefragThreadPauseSyncMesg;
static OSThread    sDefragThread;
static u8          sDefragThreadStack[DEFRAGMANAGER_THREAD_STACK_SIZE];

/* .code */
void defragManager_init(void){
    osCreateMesgQueue(&sDefragThreadResumeSyncQueue, &sDefragThreadResumeSyncMesg, 1);
    osCreateMesgQueue(&sDefragThreadPauseSyncQueue, &sDefragThreadPauseSyncMesg, 1);
    osCreateThread(&sDefragThread, DEFRAGMANAGER_THREAD_ID, defragThread_entry, NULL, sDefragThreadStack + DEFRAGMANAGER_THREAD_STACK_SIZE, 10);
    osStartThread(&sDefragThread);
}

void defragManager_free(void){
    osStopThread(&sDefragThread);
    osDestroyThread(&sDefragThread);
}

void defragManager_resume(void){
    if(func_8023E000() == 3){
        osSendMesg(&sDefragThreadResumeSyncQueue, NULL, OS_MESG_BLOCK);
    }
}

void defragManager_pause(void){
    if(func_8023E000() == 3){
        osSendMesg(&sDefragThreadPauseSyncQueue, NULL, OS_MESG_BLOCK);
    }
}

void defragManager_setPriority(OSPri pri){
    if(func_8023E000() == 3){
        osSetThreadPri(&sDefragThread, pri);
    }
}

static void defragThread_entry(void *arg) {
    int defrag_flag;
    do{
        osRecvMesg(&sDefragThreadResumeSyncQueue, NULL, OS_MESG_BLOCK);
        if(!sDefragThreadPauseSyncQueue.validCount){
            do{
                defrag_flag = game_defrag();
            }while(!sDefragThreadPauseSyncQueue.validCount && defrag_flag);
        }
        osRecvMesg(&sDefragThreadPauseSyncQueue, NULL, OS_MESG_BLOCK);
    }while(TRUE);
}
