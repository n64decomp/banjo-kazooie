#include <ultra64.h>
#include <n_libaudio.h>
#include <PRinternal/macros.h>
#include <PRinternal/viint.h>
#include "core1/core1.h"

#define UNKFLAG1_AUDIO_TASK     0x04
#define UNKFLAG1_GFX_TASK       0x08
#define UNKFLAG1_NO_TASK        0x10
#define UNKFLAG1_TASK_YIELDED   0x20

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

static s32 sUnkCounter1 = 0; // Unused counter, probably for debugging
static s32 sUnkCounter2 = 0; // Unused counter, probably for debugging
static s32 sUnkCounter3 = 0; // Unused counter, probably for debugging
static s32 sUnkCounter4 = 0; // Unused counter, probably for debugging

static u64 sYieldData[OS_YIELD_DATA_SIZE / sizeof(u64)];
static u8 pad[0x20];
static OSMesgQueue sThread5MesgQueue;
static OSMesg      sThread5MesgBuffer[20];
static OSMesgQueue sThread5SyncMesgQueue;
static OSMesg      sThread5SyncMesgBufer[10];
static struct ucode_task_data_s *sActiveAudioTaskDataPtr;
static s32 sSyncCounter;
static bool sTask7Handled;
static s32 sUnkFlag2_Saved;
static s32 sUnkFlag2;
static s32 sUnkFlag1;
static s32 sUnkFlag1_Saved;
static s32 sGfxTaskYielded;
static STACK(sThread5Stack, 2048);
static OSThread sThread5;
static struct ucode_task_data_s *sGfxTaskDataList[20];
static volatile s32 sSelectedGfxTaskDataID;
static volatile s32 sActiveGfxTaskDataID;
static struct ucode_task_data_s *sAudioTaskDataList[20];
static volatile s32 sSelectedAudioTaskDataID;
static volatile s32 sActiveAudioTaskDataID;
static void *sCurrentFramebuffer;
static OSTimer sAudioTimer;
static OSTimer sControllerTimer;
static bool sEnableControllerTimer;

void thread5_startNextAudioTask(void);

void thread5_sendTaskToQueue(OSMesg msg) {
    static bool clear_freeze = TRUE;
    
    osSendMesg(&sThread5MesgQueue, msg, OS_MESG_BLOCK);
    
    if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_SYNC) {
        sUnkCounter2 = 30;
        if (clear_freeze) {
            osDpSetStatus(DPC_CLR_FREEZE);
            clear_freeze = FALSE;
        }
        osRecvMesg(&sThread5SyncMesgQueue, NULL, OS_MESG_BLOCK);
        sUnkCounter2 = 0;
    }
}

void thread5_insertAudioTaskData(struct ucode_task_data_s *task_data) {
    s32 new_id = (sSelectedAudioTaskDataID + 1) % 20;
    if (sActiveAudioTaskDataID != new_id) {
        sAudioTaskDataList[sSelectedAudioTaskDataID] = task_data;
        sSelectedAudioTaskDataID = new_id;
    }
}

void thread5_insertGfxTaskData(struct ucode_task_data_s *task_data) {
    s32 new_id = (sSelectedGfxTaskDataID + 1) % 20;
    if (sActiveGfxTaskDataID != new_id) {
        sGfxTaskDataList[sSelectedGfxTaskDataID] = task_data;
        sSelectedGfxTaskDataID = new_id;
    }
}

void thread5_startAudioTask(struct ucode_task_data_s *task_data) {
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
    sUnkFlag1 = UNKFLAG1_AUDIO_TASK;
}

void thread5_startF3DEXTask(struct ucode_task_data_s *task_data) {
    ucode_getPtrAndSize((void **) &sGfxTask.t.ucode_boot, &sGfxTask.t.ucode_boot_size);
    sGfxTask.t.ucode = (u64 *) gspF3DEX_fifoTextStart;
    sGfxTask.t.ucode_data = (u64 *) gspF3DEX_fifoDataStart;
    sGfxTask.t.data_ptr = task_data->data_ptr;
    sGfxTask.t.data_size = (task_data->data_ptr_end - task_data->data_ptr) << 3;
    osWritebackDCache(sGfxTask.t.data_ptr , sGfxTask.t.data_size);
    osWritebackDCache(&sGfxTask, sizeof(OSTask));
    osSpTaskLoad(&sGfxTask);
    osSpTaskStartGo(&sGfxTask);
    sUnkFlag1 = task_data->unk4 | UNKFLAG1_GFX_TASK;
    sUnkFlag2 = task_data->unk4 | 0x1;
    if (!(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        sUnkFlag2_Saved = sUnkFlag2;
        sUnkCounter3 = 30;
    }
}

void thread5_startL3DEXTask(struct ucode_task_data_s *task_data) {
    ucode_getPtrAndSize((void **) &sGfxTask.t.ucode_boot, &sGfxTask.t.ucode_boot_size);
    sGfxTask.t.ucode = (u64 *) gspL3DEX_fifoTextStart;
    sGfxTask.t.ucode_data = (u64 *) gspL3DEX_fifoDataStart;
    sGfxTask.t.data_ptr = task_data->data_ptr;
    sGfxTask.t.data_size = (task_data->data_ptr_end - task_data->data_ptr) << 3;
    osWritebackDCache(sGfxTask.t.data_ptr , sGfxTask.t.data_size);
    osWritebackDCache(&sGfxTask, sizeof(OSTask));
    osSpTaskLoad(&sGfxTask);
    osSpTaskStartGo(&sGfxTask);
    sUnkFlag1 = task_data->unk4 | UNKFLAG1_GFX_TASK;
    sUnkFlag2 = task_data->unk4 | 0x1;
    if (!(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        sUnkFlag2_Saved = sUnkFlag2;
        sUnkCounter3 = 30;
    }
}

void thread5_startGfxTask(struct ucode_task_data_s *task_data) {
    switch (task_data->task_type) {
        case 1:
           thread5_startF3DEXTask(task_data);
            break;

        case 2:
           thread5_startL3DEXTask(task_data);
            break;
    }
}

void thread5_handleAudioTaskMesg(struct ucode_task_data_s *task_data) {
   thread5_insertAudioTaskData(task_data);
}

void thread5_handleF3DEXTaskMesg(struct ucode_task_data_s *task_data) {
   thread5_insertGfxTaskData(task_data);
    if (sUnkFlag1 == UNKFLAG1_NO_TASK && !sTask7Handled) {
       thread5_startF3DEXTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 20;
    }
}

void thread5_handleL3DEXTaskMesg(struct ucode_task_data_s *task_data) {
   thread5_insertGfxTaskData(task_data);
    if (sUnkFlag1 == UNKFLAG1_NO_TASK && !sTask7Handled) {
       thread5_startL3DEXTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 20;
    }
}

void thread5_handleSyncEvent(void) {
    if ((sUnkFlag1 == UNKFLAG1_NO_TASK) && (sUnkFlag2_Saved == 2) && (sActiveGfxTaskDataID == sSelectedGfxTaskDataID) && !(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        osSendMesg(&sThread5SyncMesgQueue, NULL, OS_MESG_NOBLOCK);
    } else {
        sSyncCounter++;
    }
}

void thread5_handleDPEvent(void) {
    if (sUnkFlag2_Saved & 0x40000000) {
        osDpSetStatus(DPC_SET_FREEZE);
        sCurrentFramebuffer = osViGetCurrentFramebuffer();
        viMgr_func_8024BFAC();
    }
    sUnkFlag2_Saved = sUnkFlag2 = 2;
    sUnkCounter3 = 0;
    if ((sUnkFlag1 == UNKFLAG1_NO_TASK) && (sActiveGfxTaskDataID != sSelectedGfxTaskDataID) && !sTask7Handled) {
       thread5_startGfxTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 20;
    }
    else{
        if ((sSyncCounter != 0) && (sActiveGfxTaskDataID == sSelectedGfxTaskDataID) && !(osDpGetStatus() & DPC_STATUS_FREEZE)) {
            osSendMesg(&sThread5SyncMesgQueue, NULL, OS_MESG_NOBLOCK);
            sSyncCounter--;
        }
    }
}

void thread5_handleVIRetraceEvent(void) {
    static s32 audiotimer_trigger = 0;
    s32 sp2C = (sSyncCounter != 0) && (sActiveGfxTaskDataID == sSelectedGfxTaskDataID) && (sUnkFlag2 == 2) && (sUnkFlag1 == UNKFLAG1_NO_TASK);
    volatile bool unk_flag = FALSE;

    if (osViGetCurrentFramebuffer() != sCurrentFramebuffer || sp2C) {
        if (osDpGetStatus() & DPC_STATUS_FREEZE) {
            osDpSetStatus(DPC_CLR_FREEZE);

            sUnkFlag2_Saved = sUnkFlag2;
            dummy_func_8025AFB8();

            if (sUnkFlag2_Saved & 0x01) {
                sUnkCounter3 = 30;
            }
        }

        if (sp2C) {
            osSendMesg(&sThread5SyncMesgQueue, NULL, OS_MESG_NOBLOCK);
            sSyncCounter--;
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
            unk_flag = TRUE;
        }
    }

    sTask7Handled = FALSE;

    if ((++audiotimer_trigger & 1) == 0) {
        osStopTimer(&sAudioTimer);
        osSetTimer(&sAudioTimer, OS_NSEC_TO_CYCLES(5973334LL), 0, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_AUDIO_TIMER);
    }

    if (sEnableControllerTimer) {
        osStopTimer(&sControllerTimer);
#if VERSION == VERSION_USA_1_0
        osSetTimer(&sControllerTimer, ((osClockRate / 60)* 2) / 3, 0, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_CONT_TIMER);
#elif VERSION == VERSION_PAL
        osSetTimer(&sControllerTimer, ((osClockRate / 60.0)* 2) / 3, 0, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_CONT_TIMER);
#endif
    }
}

void thread5_handleSPEvent(void) {
    struct ucode_task_data_s *active_audio_task;
    s32 temp_v1 = sUnkFlag1;
    
    if (sUnkFlag1 == UNKFLAG1_TASK_YIELDED) {
        active_audio_task = sAudioTaskDataList[sActiveAudioTaskDataID];
        sActiveAudioTaskDataID = (sActiveAudioTaskDataID + 1) % 20;
        sGfxTaskYielded = osSpTaskYielded(&sGfxTask) == OS_TASK_YIELDED;
       thread5_startAudioTask(active_audio_task);
        sUnkCounter4 = 0;
        return;
    }

    if (sUnkFlag1 == UNKFLAG1_AUDIO_TASK) {
        osSendMesg(sActiveAudioTaskDataPtr->unk10, (OSMesg) sActiveAudioTaskDataPtr->unk14, OS_MESG_NOBLOCK);
    }

    if ((sUnkFlag1 == UNKFLAG1_AUDIO_TASK) && sGfxTaskYielded) {
        osSpTaskLoad(&sGfxTask);
        osSpTaskStartGo(&sGfxTask);
        sUnkFlag1 = sUnkFlag1_Saved;
        sGfxTaskYielded = FALSE;
        return;
    }

    sUnkFlag1 = UNKFLAG1_NO_TASK;
    if ((sActiveGfxTaskDataID != sSelectedGfxTaskDataID) && (!sTask7Handled)) {
       thread5_startGfxTask(sGfxTaskDataList[sActiveGfxTaskDataID]);
        sActiveGfxTaskDataID = (sActiveGfxTaskDataID + 1) % 20;
        return;
    }
    
    if ((sSyncCounter != 0) && (sUnkFlag2_Saved == 2) && !(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        osSendMesg(&sThread5SyncMesgQueue, NULL, OS_MESG_NOBLOCK);
        sSyncCounter--;
    }
}

void thread5_handleTask7Mesg(struct ucode_task_data_s *task_data) {
    sTask7Handled = TRUE;
}

void thread5_handleAudioTimerEvent(void) {
    osSendMesg(audioManager_getFrameMesgQueue(), NULL, OS_MESG_NOBLOCK);
   thread5_startNextAudioTask();
}

void thread5_startNextAudioTask(void) {
    struct ucode_task_data_s *ptr;

    if ((sUnkFlag1 == UNKFLAG1_NO_TASK) && (sActiveAudioTaskDataID != sSelectedAudioTaskDataID)) {
        ptr = sAudioTaskDataList[sActiveAudioTaskDataID];
        sActiveAudioTaskDataID = (sActiveAudioTaskDataID + 1) % 20;
       thread5_startAudioTask(ptr);
    }
    else if ((sUnkFlag1 & UNKFLAG1_GFX_TASK) && (sActiveAudioTaskDataID != sSelectedAudioTaskDataID)) {
        osSpTaskYield();
        sUnkFlag1_Saved = sUnkFlag1;
        sUnkFlag1 = UNKFLAG1_TASK_YIELDED;
        sUnkCounter4 = 30;
    }
}

void thread5_stub(void) {}

void thread5_handlePreNMIEvent(void) {
    static OSViMode osViModeMpalLpn1 = { /* from vimodempallpn1.c */
        OS_VI_MPAL_LPN1, /* type */
        { 
            // comRegs
            VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_ANTIALIAS_MODE_2 |
                VI_CTRL_PIXEL_ADV_3, // ctrl
            WIDTH(320),              // width
            BURST(57, 30, 5, 70),    // burst
            VSYNC(525),              // vSync
            HSYNC(3089, 4),          // hSync
            LEAP(3097, 3098),        // leap
            HSTART(108, 748),        // hStart
            0,                       // xScale - modified by BK
            VCURRENT(0),             // vCurrent
        },
        { // fldRegs
            {
                // [0]
                ORIGIN(640),        // origin
                SCALE(1, 0),        // yScale
                HSTART(37, 511),    // vStart
                BURST(4, 2, 14, 0), // vBurst
                VINTR(2),           // vIntr
            },
            {
                // [1]
                ORIGIN(640),        // origin
                SCALE(1, 0),        // yScale
                HSTART(37, 511),    // vStart
                BURST(4, 2, 14, 0), // vBurst
                VINTR(2),           // vIntr
            }
        }
    };
    static OSViMode osViModeNtscLpn1 = { /* from vimodentsclpn1.c */
        OS_VI_NTSC_LPN1, // type
        { 
            // comRegs
            VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_ANTIALIAS_MODE_2 |
                VI_CTRL_PIXEL_ADV_3, // ctrl
            WIDTH(320),              // width
            BURST(57, 34, 5, 62),    // burst
            VSYNC(525),              // vSync
            HSYNC(3093, 0),          // hSync
            LEAP(3093, 3093),        // leap
            HSTART(108, 748),        // hStart
            0,                       // xScale - modified by BK
            VCURRENT(0),             // vCurrent
        },
        { // fldRegs
            {
                // [0]
                ORIGIN(640),        // origin
                SCALE(1, 0),        // yScale
                HSTART(37, 511),    // vStart
                BURST(4, 2, 14, 0), // vBurst
                VINTR(2),           // vIntr
            },
            {
                // [1]
                ORIGIN(640),        // origin
                SCALE(1, 0),        // yScale
                HSTART(37, 511),    // vStart
                BURST(4, 2, 14, 0), // vBurst
                VINTR(2),           // vIntr
            }
        }
    };
#if VERSION == VERSION_PAL
    static OSViMode osViModePalLpn1 = { /* from vimodepallpn1.c.c */
        OS_VI_PAL_LPN1, // type
        { 
            // comRegs
            VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_ANTIALIAS_MODE_2 |
                VI_CTRL_PIXEL_ADV_3, // ctrl
            WIDTH(320),              // width
            BURST(58, 35, 4, 64),    // burst - modified by BK
            VSYNC(625),              // vSync
            HSYNC(3177, 21),         // hSync - modified by BK
            LEAP(3183, 3182),        // leap - modified by BK
            HSTART(128, 768),        // hStart
            0,                       // xScale - modified by BK
            VCURRENT(0),             // vCurrent
        },
        { // fldRegs
            {
                // [0]
                ORIGIN(640),         // origin
                SCALE(1, 0),         // yScale
                HSTART(95, 569),     // vStart
                BURST(107, 2, 9, 0), // vBurst
                VINTR(2),            // vIntr
            },
            {
                // [1]
                ORIGIN(640),         // origin
                SCALE(1, 0),         // yScale
                HSTART(95, 569),     // vStart
                BURST(107, 2, 9, 0), // vBurst
                VINTR(2),            // vIntr
            } 
        }
    };
#endif
    static bool mode_set;

    if (!mode_set) {
        mode_set = TRUE;
#if VERSION == VERSION_USA_1_0
        if (osTvType != OS_TV_NTSC) {
            osViSetMode(&osViModeMpalLpn1);
        } else {
            osViSetMode(&osViModeNtscLpn1);
        }
#elif VERSION == VERSION_PAL
        osViSetMode(&osViModePalLpn1);
#endif
        baMotor_80250FC0();

        while (TRUE) {
            osDpSetStatus(DPC_STATUS_FLUSH);
        };
    }
}

void thread5_checkAndExecutePreNMI(void) {
    if (!(___osGetSR() & SR_IBIT5)) {
       thread5_handlePreNMIEvent();
    }
}

void thread5_entry(void *arg) {
    OSMesg msg = NULL;

    while (TRUE) {
        osRecvMesg(&sThread5MesgQueue, &msg, OS_MESG_BLOCK);
        thread5_checkAndExecutePreNMI();

        if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_SYNC) {
           thread5_handleSyncEvent();
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_VI_RETRACE) {
           thread5_handleVIRetraceEvent();
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_DP) {
           thread5_handleDPEvent();
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_SP) {
           thread5_handleSPEvent();
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_AUDIO_TIMER) {
           thread5_handleAudioTimerEvent();
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_FAULT) {
            while (TRUE);
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_PRENMI) {
           thread5_handlePreNMIEvent();
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_DEBUG) {
            /* nothing */
        }
        else if (msg == (OSMesg) THREAD5_MESSAGE_EVENT_CONT_TIMER) {
            pfsManager_getStartReadData();
        }
        else if (msg >= (OSMesg) 100) { // Messages that don't contain an Event ID, but a pointer to a task structure, from thread5_sendTaskToQueue
            if (((struct ucode_task_data_s *) msg)->task_type == UCODE_TASK_TYPE_AUDIO) {
               thread5_handleAudioTaskMesg((struct ucode_task_data_s *) msg);
            }
            else if (((struct ucode_task_data_s *) msg)->task_type == UCODE_TASK_TYPE_F3DEX) {
               thread5_handleF3DEXTaskMesg((struct ucode_task_data_s *) msg);
            }
            else if (((struct ucode_task_data_s *) msg)->task_type == UCODE_TASK_TYPE_L3DEX) {
               thread5_handleL3DEXTaskMesg((struct ucode_task_data_s *) msg);
            }
            else if (((struct ucode_task_data_s *) msg)->task_type == UCODE_TASK_TYPE_FRAMEBUFFER_CHANGED) {
               thread5_handleTask7Mesg((struct ucode_task_data_s *) msg);
            }
        }
    };
}

void thread5_create(void) {
    u8 *yield_data_ptr;

    osCreateMesgQueue(&sThread5MesgQueue, sThread5MesgBuffer, 20);
    osCreateMesgQueue(&sThread5SyncMesgQueue, sThread5SyncMesgBufer, 10);
    osSetEventMesg(OS_EVENT_DP, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_DP);
    osSetEventMesg(OS_EVENT_SP, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_SP);
    osSetEventMesg(OS_EVENT_FAULT, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_FAULT);
    osSetEventMesg(OS_EVENT_PRENMI, &sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_PRENMI);
    viMgr_registerSignalMesg(&sThread5MesgQueue, (OSMesg) THREAD5_MESSAGE_EVENT_VI_RETRACE);
    sSyncCounter = 0;
    sTask7Handled = FALSE;
    sUnkFlag2_Saved = sUnkFlag2 = 2;
    sUnkFlag1 = sUnkFlag1_Saved = UNKFLAG1_NO_TASK;
    sGfxTaskYielded = FALSE;
    sActiveGfxTaskDataID = 0;
    sSelectedGfxTaskDataID = 0;
    sActiveAudioTaskDataID = 0;
    sSelectedAudioTaskDataID = 0;

    for (yield_data_ptr = (u8 *) sYieldData; (u32) yield_data_ptr % 0x10; yield_data_ptr++);
    sGfxTask.t.yield_data_ptr = (u64 *) yield_data_ptr;

    osCreateThread(&sThread5, THREAD5_ID,thread5_entry, NULL, STACK_START(sThread5Stack), THREAD5_PRI);
    osStartThread(&sThread5);
}

void thread5_enableControllerTimer(void) {
    sEnableControllerTimer = TRUE;
}

void thread5_finishDList(Gfx **gfx) {
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}

s32thread5_getUnkFlag1(void) {
    return sUnkFlag1;
}

OSMesgQueue *__thread5_getMessageQueue(void) {
    return &sThread5MesgQueue;
}

OSThread *__thread5_getThreadObject(void) {
    return &sThread5;
}
