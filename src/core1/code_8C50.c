#include <ultra64.h>
#include "n_libaudio.h"
#include <PRinternal/macros.h>
#include <PRinternal/viint.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "version.h"

void func_80247224(void);

#define CORE1_8C50_EVENT_3 3
#define RESETTHREAD_MESSAGE_EVENT_DP 4
#define RESETTHREAD_MESSAGE_FROM_VIMGR 5
#define RESETTHREAD_MESSAGE_EVENT_SP 6
#define RESETTHREAD_MESSAGE_EVENT_AUDIO_TIMER 8
#define RESETTHREAD_MESSAGE_EVENT_FAULT 10
#define RESETTHREAD_MESSAGE_EVENT_PRENMI 11
#define RESETTHREAD_MESSAGE_EVENT_CONT_TIMER 13

static OSTask sAudTask = {
    M_AUDTASK,                /* type */
    0,                        /* flags */
    NULL, 0,                  /* ucode_boot */
    NULL, SP_UCODE_SIZE,      /* ucode */
    NULL, SP_UCODE_DATA_SIZE, /* ucode_data */
    NULL, 0,                  /* dram_stack */
    NULL, NULL,               /* output_buff */
    NULL, 0,                  /* data */
    NULL, 0,                  /* yield_data */
};

static OSTask sGfxTask = {
    M_GFXTASK,                                              /* type */
    0,                                                      /* flags */
    NULL, 0,                                                /* ucode_boot */
    NULL, SP_UCODE_SIZE,                                    /* ucode */
    NULL, SP_UCODE_DATA_SIZE,                               /* ucode_data */
    (u64 *) PHYS_TO_K0(0x400), SP_DRAM_STACK_SIZE8,         /* dram_stack */
    (u64 *) PHYS_TO_K0(0x800), (u64 *) PHYS_TO_K0(0xE800),  /* output_buff */
    NULL, 0,                                                /* data */
    NULL, OS_YIELD_DATA_SIZE,                               /* yield_data */
};

static s32 sUnkCounter1 = 0; // Counters are set to 30 at different places and decremented in resetThread_handleMesg5, but they do nothing when reaching 0
static s32 sUnkCounter2 = 0; // Counters are set to 30 at different places and decremented in resetThread_handleMesg5, but they do nothing when reaching 0
static s32 sUnkCounter3 = 0; // Counters are set to 30 at different places and decremented in resetThread_handleMesg5, but they do nothing when reaching 0
static s32 sUnkCounter4 = 0; // Counters are set to 30 at different places and decremented in resetThread_handleMesg5, but they do nothing when reaching 0

u64 sYieldData[OS_YIELD_DATA_SIZE / sizeof(u64)];
static u8 pad[0x20]; // 8027FB40

OSMesgQueue sResetThreadMesgQueue;
OSMesg      sResetThreadMesgBuffer[20];
OSMesgQueue sResetThreadSyncMesgQueue;
OSMesg      sResetThreadSyncMesgBufer[10];

struct ucode_task_data_s *sActiveAudioTaskDataPtr;

s32 sUnkCounter5;
bool sTask7Handled;
s32 sUnkFlag2_Saved;
s32 sUnkFlag2;
s32 sUnkFlag1;
s32 sUnkFlag1_Saved;
s32 sGfxTaskYielded;

STACK(sResetThreadStack, 2048);
OSThread sResetThread;

struct ucode_task_data_s *sGfxTaskDataList[20];
volatile s32 sSelectedGfxTaskDataID;
volatile s32 sActiveGfxTaskDataID;

struct ucode_task_data_s *sAudioTaskDataList[20];
volatile s32 sSelectedAudioTaskDataID;
volatile s32 sActiveAudioTaskDataID;

void *sCurrentFramebuffer;

OSTimer sAudioTimer;
OSTimer sControllerTimer;
bool sEnableControllerTimer;

void resetThread_sendTaskToQueue(OSMesg mesg) {
    static bool clear_freeze = TRUE;
    
    osSendMesg(&sResetThreadMesgQueue, mesg, OS_MESG_BLOCK);
    
    if (mesg == (OSMesg) CORE1_8C50_EVENT_3) {
        sUnkCounter2 = 30;
        if (clear_freeze) {
            osDpSetStatus(DPC_CLR_FREEZE);
            clear_freeze = FALSE;
        }
        osRecvMesg(&sResetThreadSyncMesgQueue, NULL, OS_MESG_BLOCK);
        sUnkCounter2 = 0;
    }
}

void resetThread_insertAudioTaskData(struct ucode_task_data_s *task_data) {
    s32 new_id = (sSelectedAudioTaskDataID + 1) % 20;
    if (sActiveAudioTaskDataID != new_id) {
        sAudioTaskDataList[sSelectedAudioTaskDataID] = task_data;
        sSelectedAudioTaskDataID = new_id;
    }
}

void resetThread_insertGfxTaskData(struct ucode_task_data_s *task_data) {
    s32 new_id = (sSelectedGfxTaskDataID + 1) % 20;
    if (sActiveGfxTaskDataID != new_id) {
        sGfxTaskDataList[sSelectedGfxTaskDataID] = task_data;
        sSelectedGfxTaskDataID = new_id;
    }
}

void resetThread_startAudioTask(struct ucode_task_data_s *task_data) {
    ucode_getPtrAndSize((void **) &sAudTask.t.ucode_boot, &sAudTask.t.ucode_boot_size);
    sAudTask.t.ucode = (u64 *) n_aspMainTextStart;
    sAudTask.t.ucode_data = (u64 *) n_aspMainDataStart;
    sAudTask.t.data_ptr = task_data->data_ptr;
    sAudTask.t.data_size = (task_data->data_ptr_end - task_data->data_ptr) << 3;
    osWritebackDCache(sAudTask.t.data_ptr , sAudTask.t.data_size);
    osWritebackDCache(&sAudTask, sizeof(OSTask));
    sActiveAudioTaskDataPtr = task_data;
    osSpTaskLoad(&sAudTask);
    osSpTaskStartGo(&sAudTask);
    sUnkFlag1 = 4;
}

void resetThread_startF3DEXTask(struct ucode_task_data_s *task_data) {
    ucode_getPtrAndSize((void **) &sGfxTask.t.ucode_boot, &sGfxTask.t.ucode_boot_size);
    sGfxTask.t.ucode = (u64 *) gspF3DEX_fifoTextStart;
    sGfxTask.t.ucode_data = (u64 *) gspF3DEX_fifoDataStart;
    sGfxTask.t.data_ptr = task_data->data_ptr;
    sGfxTask.t.data_size = (task_data->data_ptr_end - task_data->data_ptr) << 3;
    osWritebackDCache(sGfxTask.t.data_ptr , sGfxTask.t.data_size);
    osWritebackDCache(&sGfxTask, sizeof(OSTask));
    osSpTaskLoad(&sGfxTask);
    osSpTaskStartGo(&sGfxTask);
    sUnkFlag1 = task_data->unk4 | 0x8;
    sUnkFlag2 = task_data->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        sUnkFlag2_Saved = sUnkFlag2;
        sUnkCounter3 = 30;
    }
}

void resetThread_startL3DEXTask(struct ucode_task_data_s *task_data) {
    ucode_getPtrAndSize((void **) &sGfxTask.t.ucode_boot, &sGfxTask.t.ucode_boot_size);
    sGfxTask.t.ucode = (u64 *) gspL3DEX_fifoTextStart;
    sGfxTask.t.ucode_data = (u64 *) gspL3DEX_fifoDataStart;
    sGfxTask.t.data_ptr = task_data->data_ptr;
    sGfxTask.t.data_size = (task_data->data_ptr_end - task_data->data_ptr) << 3;
    osWritebackDCache(sGfxTask.t.data_ptr , sGfxTask.t.data_size);
    osWritebackDCache(&sGfxTask, sizeof(OSTask));
    osSpTaskLoad(&sGfxTask);
    osSpTaskStartGo(&sGfxTask);
    sUnkFlag1 = task_data->unk4 | 0x8;
    sUnkFlag2 = task_data->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        sUnkFlag2_Saved = sUnkFlag2;
        sUnkCounter3 = 30;
    }
}

void resetThread_startGfxTask(struct ucode_task_data_s *task_data) {
    switch (task_data->task_type) {
        case 1:
            resetThread_startF3DEXTask(task_data);
            break;

        case 2:
            resetThread_startL3DEXTask(task_data);
            break;
    }
}

void resetThread_handleAudioTaskMesg(struct ucode_task_data_s *task_data) {
    resetThread_insertAudioTaskData(task_data);
}

void resetThread_handleF3DEXTaskMesg(struct ucode_task_data_s *task_data) {
    resetThread_insertGfxTaskData(task_data);
    if(sUnkFlag1 == 0x10 && !sTask7Handled){
        resetThread_startF3DEXTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 0x14;
    }
}

void resetThread_handleL3DEXTaskMesg(struct ucode_task_data_s *task_data) {
    resetThread_insertGfxTaskData(task_data);
    if(sUnkFlag1 == 0x10 && !sTask7Handled){
        resetThread_startL3DEXTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 0x14;
    }
}

void resetThread_handleMesg3(void){
    if( sUnkFlag1 == 0x10 
        && sUnkFlag2_Saved == 2 
        && sActiveGfxTaskDataID == sSelectedGfxTaskDataID
        && !(osDpGetStatus() & DPC_STATUS_FREEZE)
    ){
        osSendMesg(&sResetThreadSyncMesgQueue, NULL, OS_MESG_NOBLOCK);
    }
    else{
        sUnkCounter5++;
    }
}

void resetThread_handleDPEvent(void){
    if((sUnkFlag2_Saved << 1) < 0){
        osDpSetStatus(DPC_SET_FREEZE);
        sCurrentFramebuffer = osViGetCurrentFramebuffer();
        viMgr_func_8024BFAC();
    }
    sUnkFlag2_Saved = sUnkFlag2 = 2;
    sUnkCounter3 = 0;
    if(sUnkFlag1 == 0x10 && sActiveGfxTaskDataID != sSelectedGfxTaskDataID && !sTask7Handled){
        resetThread_startGfxTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 0x14;
    }
    else{
        if(sUnkCounter5 && sActiveGfxTaskDataID == sSelectedGfxTaskDataID && !(osDpGetStatus() & DPC_STATUS_FREEZE)){
            osSendMesg(&sResetThreadSyncMesgQueue, NULL, OS_MESG_NOBLOCK);
            sUnkCounter5--;
        }
    }
}

void resetThread_handleMesg5(void){
    static s32 audiotimer_trigger = 0;
    s32 sp2C = (sUnkCounter5 != 0) && (sActiveGfxTaskDataID == sSelectedGfxTaskDataID) && (sUnkFlag2 == 2) && (sUnkFlag1 == 0x10);
    volatile bool sp30;

    sp30 = FALSE;

    if (osViGetCurrentFramebuffer() != sCurrentFramebuffer || sp2C) {
        if (osDpGetStatus() & DPC_STATUS_FREEZE) {
            osDpSetStatus(DPC_CLR_FREEZE);

            sUnkFlag2_Saved = sUnkFlag2;
            dummy_func_8025AFB8();

            if (sUnkFlag2_Saved & 1) {
                sUnkCounter3 = 30;
            }
        }

        if (sp2C) {
            osSendMesg(&sResetThreadSyncMesgQueue, NULL, OS_MESG_NOBLOCK);
            sUnkCounter5--;
        }
    }

    sUnkCounter1 = 0;

    if (sUnkCounter2 != 0) {
        sUnkCounter2--;
    }

    if (sUnkCounter4 != 0) {
        sUnkCounter4--;
    }

    if (sUnkCounter3 != 0) {
        sUnkCounter3--;
        if (sUnkCounter3 == 0) {
            sp30 = TRUE;
        }
    }

    sTask7Handled = FALSE;

    audiotimer_trigger++;
    if ((audiotimer_trigger & 1) == 0) {
        osStopTimer(&sAudioTimer);
        osSetTimer(&sAudioTimer, 280000, 0, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_AUDIO_TIMER);
    }

    if (sEnableControllerTimer) {
        osStopTimer(&sControllerTimer);
#if VERSION == VERSION_USA_1_0
        osSetTimer(&sControllerTimer, ((osClockRate / 60)* 2) / 3, 0, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_CONT_TIMER);
#elif VERSION == VERSION_PAL
        osSetTimer(&sControllerTimer, ((osClockRate / 60.0)* 2) / 3, 0, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_CONT_TIMER);
#endif
    }
}

void resetThread_handleSPEvent(void) {
    struct ucode_task_data_s *active_audio_task;
    s32 temp_v1;

    temp_v1 = sUnkFlag1;
    if (sUnkFlag1 == 0x20) {
        active_audio_task = sAudioTaskDataList[sActiveAudioTaskDataID];
        sActiveAudioTaskDataID = (sActiveAudioTaskDataID + 1) % 20;
        sGfxTaskYielded = osSpTaskYielded(&sGfxTask) == OS_TASK_YIELDED;
        resetThread_startAudioTask(active_audio_task);
        sUnkCounter4 = 0;
        return;
    }

    if (sUnkFlag1 == 4) {
        osSendMesg(sActiveAudioTaskDataPtr->unk10, (OSMesg) sActiveAudioTaskDataPtr->unk14, OS_MESG_NOBLOCK);
    }

    if ((sUnkFlag1 == 4) && sGfxTaskYielded) {
        osSpTaskLoad(&sGfxTask);
        osSpTaskStartGo(&sGfxTask);
        sUnkFlag1 = sUnkFlag1_Saved;
        sGfxTaskYielded = FALSE;
        return;
    }

    sUnkFlag1 = 0x10;
    if ((sActiveGfxTaskDataID != sSelectedGfxTaskDataID) && (!sTask7Handled)) {
        resetThread_startGfxTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 20;
        return;
    }
    
    if ((sUnkCounter5 != 0) && (sUnkFlag2_Saved == 2) && !(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        osSendMesg(&sResetThreadSyncMesgQueue, NULL, OS_MESG_NOBLOCK);
        sUnkCounter5--;
    }
}

void resetThread_handleTask7Mesg(struct ucode_task_data_s *task_data) {
    sTask7Handled = TRUE;
}

void resetThread_handleAudioTimerEvent(void){
    osSendMesg(audioManager_getFrameMesgQueue(), NULL, OS_MESG_NOBLOCK);
    func_80247224();
}

void func_80247224(void){
    struct ucode_task_data_s *ptr;
    if((sUnkFlag1 == 0x10) && (sActiveAudioTaskDataID != sSelectedAudioTaskDataID)){
        ptr = sAudioTaskDataList[sActiveAudioTaskDataID];
        sActiveAudioTaskDataID = (sActiveAudioTaskDataID + 1) % 0x14;
        resetThread_startAudioTask(ptr);
    }
    else if((sUnkFlag1 & 0x8) && (sActiveAudioTaskDataID != sSelectedAudioTaskDataID)){
        osSpTaskYield();
        sUnkFlag1_Saved = sUnkFlag1;
        sUnkFlag1 = 0x20;
        sUnkCounter4 = 30;
    }
}

void resetThread_stub(void) {}

void resetThread_handlePreNMIEvent(void){
    static OSViMode vimode_mpal_lpn1 = {
        OS_VI_MPAL_LPN1, /* type */
        { 
          VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
          320,          /*width*/
          0x4651E39,    /*burst*/
          0x20D,        /*vSync*/
          0x40C11,      /* hSync*/
          0xC190C1A,    /* leap*/
          0x6C02EC,     /* hStart*/
          0, /* xScale*/
          0, /* vCurrent*/
        },
        {
            {640, 1024, 0x2501FF, 0xE0204, 2},
            {640, 1024, 0x2501FF, 0xE0204, 2}
        }
    };
    static OSViMode vimode_ntsc_lpn1 = {
        OS_VI_NTSC_LPN1, /* type */
        { 
          VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
          320,          /*width*/
          0x3E52239,    /*burst*/
          0x20D,        /*vSync*/
          0xC15,        /* hSync*/
          0xC150C15,    /* leap*/
          0x6C02EC,     /* hStart*/
          0, /* xScale*/
          0, /* vCurrent*/
        },
        {
            {0x280, 1024, 0x2501FF, 0xE0204, 2},
            {640, 1024, 0x2501FF, 0xE0204, 2}
        }
    };
#if VERSION == VERSION_PAL
    static OSViMode vimode_pal_lpn1 = {
        OS_VI_PAL_LPN1, /* type */
        { 
          VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
          320,          /*width*/
          0x404233A,    /*burst*/
          0x271,        /*vSync*/
          0x150C69,        /* hSync*/
          0xC6F0C6E,    /* leap*/
          0x800300,     /* hStart*/
          0, /* xScale*/
          0, /* vCurrent*/
        },
        {
            {640, 1024, 0x5F0239, 0x9026B, 2},
            {640, 1024, 0x5F0239, 0x9026B, 2}
        }
    };
#endif
    static bool mode_set;

    if (!mode_set) {
        mode_set = TRUE;
#if VERSION == VERSION_USA_1_0
        if (osTvType != OS_TV_NTSC) {
            osViSetMode(&vimode_mpal_lpn1);
        } else {
            osViSetMode(&vimode_ntsc_lpn1);
        }
#elif VERSION == VERSION_PAL
        // if(&D_802759A8){}
        osViSetMode(&vimode_pal_lpn1);
#endif
        baMotor_80250FC0();
        do{ 
            osDpSetStatus(DPC_STATUS_FLUSH);
        }while(1);
    }
}

void resetThread_checkAndExecutePreNMI(void) {
    if (!(___osGetSR() & SR_IBIT5)) {
        resetThread_handlePreNMIEvent();
    }
}

void resetThread_entry(void *arg) {
    OSMesg msg = NULL;

    while (1) {
        osRecvMesg(&sResetThreadMesgQueue, &msg, OS_MESG_BLOCK);
        resetThread_checkAndExecutePreNMI();

        if (msg == (OSMesg) 3) {
            resetThread_handleMesg3();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_FROM_VIMGR) {
            resetThread_handleMesg5();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_DP) {
            resetThread_handleDPEvent();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_SP) {
            resetThread_handleSPEvent();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_AUDIO_TIMER) {
            resetThread_handleAudioTimerEvent();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_FAULT) {
            while (1);
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_PRENMI) {
            resetThread_handlePreNMIEvent();
        }
        else if (msg == (OSMesg) 12) {
            /* nothing */
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_CONT_TIMER) {
            pfsManager_getStartReadData();
        }
        else if (msg >= (OSMesg) 100) { // Messages that don't contain an Event ID, but a pointer to a task structure, from resetThread_sendTaskToQueue
            if (((struct ucode_task_data_s *) msg)->task_type == 0) {
                resetThread_handleAudioTaskMesg((struct ucode_task_data_s *) msg);
            }
            else if (((struct ucode_task_data_s *) msg)->task_type == 1) {
                resetThread_handleF3DEXTaskMesg((struct ucode_task_data_s *) msg);
            }
            else if (((struct ucode_task_data_s *) msg)->task_type == 2) {
                resetThread_handleL3DEXTaskMesg((struct ucode_task_data_s *) msg);
            }
            else if (((struct ucode_task_data_s *) msg)->task_type == 7) {
                resetThread_handleTask7Mesg((struct ucode_task_data_s *) msg);
            }
        }
    };
}

void resetThread_create(void) {
    u8 *yield_ptr;

    osCreateMesgQueue(&sResetThreadMesgQueue, sResetThreadMesgBuffer, 20);
    osCreateMesgQueue(&sResetThreadSyncMesgQueue, sResetThreadSyncMesgBufer, 10);
    osSetEventMesg(OS_EVENT_DP, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_DP);
    osSetEventMesg(OS_EVENT_SP, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_SP);
    osSetEventMesg(OS_EVENT_FAULT, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_FAULT);
    osSetEventMesg(OS_EVENT_PRENMI, &sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_EVENT_PRENMI);
    viMgr_registerSignalMesg(&sResetThreadMesgQueue, (OSMesg) RESETTHREAD_MESSAGE_FROM_VIMGR);
    sUnkCounter5 = 0;
    sTask7Handled = FALSE;
    sUnkFlag2_Saved = sUnkFlag2 = 2;
    sUnkFlag1 = sUnkFlag1_Saved = 0x10;
    sGfxTaskYielded = FALSE;
    sActiveGfxTaskDataID = 0;
    sSelectedGfxTaskDataID = 0;
    sActiveAudioTaskDataID = 0;
    sSelectedAudioTaskDataID = 0;

    for (yield_ptr = (u8 *) sYieldData; (u32) yield_ptr % 0x10; yield_ptr++);
    sGfxTask.t.yield_data_ptr = (u64 *) yield_ptr;

    osCreateThread(&sResetThread, 5, resetThread_entry, NULL, STACK_START(sResetThreadStack), 60);
    osStartThread(&sResetThread);
}

void resetThread_enableControllerTimer(void) {
    sEnableControllerTimer = TRUE;
}

void resetThread_finishDList(Gfx **gfx) {
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}

s32 func_80247720(void){
    return sUnkFlag1;
}

OSMesgQueue *resetThread_getMessageQueue(void) {
    return &sResetThreadMesgQueue;
}

OSThread *resetThread_getThreadObject(void) {
    return &sResetThread;
}
