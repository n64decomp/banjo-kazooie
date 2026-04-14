#include <ultra64.h>
#include <PRinternal/macros.h>
#include <PRinternal/viint.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "version.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u64 *data_ptr;
    u64 *data_ptr_end;
}Struct_Core1_8C50_s;

void func_80247224(void);

#define CORE1_8C50_EVENT_3 3
#define RESETTHREAD_MESSAGE_EVENT_DP 4
#define CORE1_8C50_EVENT_5 5
#define RESETTHREAD_MESSAGE_EVENT_SP 6
#define CORE1_8C50_EVENT_AUDIO_TIMER 8
#define RESETTHREAD_MESSAGE_EVENT_FAULT 10
#define RESETTHREAD_MESSAGE_EVENT_PRENMI 11
#define CORE1_8C50_EVENT_CONT_TIMER 13

extern u8 n_aspMainTextStart[];
extern u8 gSPF3DEX_fifoTextStart[];
extern u8 gSPL3DEX_fifoTextStart[];

extern u8 n_aspMainDataStart[];
extern u8 gSPF3DEX_fifoDataStart[];
extern u8 gSPL3DEX_fifoDataStart[];

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

s32 D_80275990 = 0;
s32 D_80275994 = 0;
s32 D_80275998 = 0;
s32 D_8027599C = 0;

u64 sYieldData[OS_YIELD_DATA_SIZE / sizeof(u64)];
static u8 pad[0x20]; // 8027FB40
OSMesgQueue D_8027FB60;
OSMesg      D_8027FB78[20];
OSMesgQueue D_8027FBC8;
OSMesg      D_8027FBE0[10];
Struct_Core1_8C50_s *D_8027FC08;
s32 D_8027FC0C;
bool D_8027FC10;
s32 D_8027FC14;
s32 D_8027FC18;
s32 D_8027FC1C;
s32 D_8027FC20;
s32 D_8027FC24;
STACK(sResetThreadStack, 2048);
OSThread sResetThread;
Struct_Core1_8C50_s * D_802805D8[20];
volatile s32 D_80280628;
volatile s32 D_8028062C;
Struct_Core1_8C50_s * D_80280630[20];
volatile s32 D_80280680;
volatile s32 D_80280684;
void* sCurrentFramebuffer;
OSTimer D_80280690; //audio_timer
OSTimer D_802806B0; //controller_timer
s32 D_802806D0;

void func_80246670(OSMesg mesg) {
    static bool D_802759A0 = TRUE;
    
    osSendMesg(&D_8027FB60, mesg, OS_MESG_BLOCK);
    if (mesg == (OSMesg) CORE1_8C50_EVENT_3) {
        D_80275994 = 30;
        if (D_802759A0) {
            osDpSetStatus(DPC_CLR_FREEZE);
            D_802759A0 = FALSE;
        }
        osRecvMesg(&D_8027FBC8, NULL, OS_MESG_BLOCK);
        D_80275994 = FALSE;
    }
}

void func_802466F4(OSMesg arg0){
    s32 tmp = (D_80280680 + 1) % 0x14;
    if(D_80280684 != tmp){
        D_80280630[D_80280680] = arg0;
        D_80280680 = tmp;
    }
}

void func_80246744(OSMesg arg0){
    s32 tmp = (D_80280628 + 1) % 20;
    if(D_8028062C != tmp){
        D_802805D8[D_80280628] = arg0;
        D_80280628 = tmp;
    }
}

void resetThread_startAudioTask(Struct_Core1_8C50_s * arg0) {
    ucode_getPtrAndSize(&sAudTask.t.ucode_boot, &sAudTask.t.ucode_boot_size);
    sAudTask.t.ucode = n_aspMainTextStart;
    sAudTask.t.ucode_data = n_aspMainDataStart;
    sAudTask.t.data_ptr = (void*) arg0->data_ptr;
    sAudTask.t.data_size = (arg0->data_ptr_end - arg0->data_ptr) << 3;
    osWritebackDCache(sAudTask.t.data_ptr , sAudTask.t.data_size);
    osWritebackDCache(&sAudTask, sizeof(OSTask));
    D_8027FC08 = arg0;
    osSpTaskLoad(&sAudTask);
    osSpTaskStartGo(&sAudTask);
    D_8027FC1C = 4;
}

void resetThread_startF3DEXTask(Struct_Core1_8C50_s * arg0) {
    ucode_getPtrAndSize(&sGfxTask.t.ucode_boot, &sGfxTask.t.ucode_boot_size);
    sGfxTask.t.ucode = gSPF3DEX_fifoTextStart;
    sGfxTask.t.ucode_data = gSPF3DEX_fifoDataStart;
    sGfxTask.t.data_ptr = (void*) arg0->data_ptr;
    sGfxTask.t.data_size = (arg0->data_ptr_end - arg0->data_ptr) << 3;
    osWritebackDCache(sGfxTask.t.data_ptr , sGfxTask.t.data_size);
    osWritebackDCache(&sGfxTask, sizeof(OSTask));
    osSpTaskLoad(&sGfxTask);
    osSpTaskStartGo(&sGfxTask);
    D_8027FC1C = arg0->unk4 | 0x8;
    D_8027FC18 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_8027FC14 = D_8027FC18;
        D_80275998 = 0x1e;
    }
}

void resetThread_startL3DEXTask(Struct_Core1_8C50_s * arg0) {
    ucode_getPtrAndSize(&sGfxTask.t.ucode_boot, &sGfxTask.t.ucode_boot_size);
    sGfxTask.t.ucode = gSPL3DEX_fifoTextStart;
    sGfxTask.t.ucode_data = gSPL3DEX_fifoDataStart;
    sGfxTask.t.data_ptr = (void*) arg0->data_ptr;
    sGfxTask.t.data_size = (arg0->data_ptr_end - arg0->data_ptr) << 3;
    osWritebackDCache(sGfxTask.t.data_ptr , sGfxTask.t.data_size);
    osWritebackDCache(&sGfxTask, sizeof(OSTask));
    osSpTaskLoad(&sGfxTask);
    osSpTaskStartGo(&sGfxTask);
    D_8027FC1C = arg0->unk4 | 0x8;
    D_8027FC18 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_8027FC14 = D_8027FC18;
        D_80275998 = 0x1e;
    }
}

void resetThread_startGfxTask(Struct_Core1_8C50_s *arg0) {
    switch(arg0->unk0){
        case 1:
            resetThread_startF3DEXTask(arg0);
            break;

        case 2:
            resetThread_startL3DEXTask(arg0);
            break;
    }
}

void func_80246A64(OSMesg msg){
    func_802466F4(msg);
}

void func_80246A84(OSMesg msg){
    func_80246744(msg);
    if(D_8027FC1C == 0x10 && !D_8027FC10){
        resetThread_startF3DEXTask(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 0x14;
    }
}

void func_80246B0C(OSMesg msg){
    func_80246744(msg);
    if(D_8027FC1C == 0x10 && !D_8027FC10){
        resetThread_startL3DEXTask(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 0x14;
    }
}

void resetThread_handleMesg3(void){
    if( D_8027FC1C == 0x10 
        && D_8027FC14 == 2 
        && D_8028062C == D_80280628
        && !(osDpGetStatus() & DPC_STATUS_FREEZE)
    ){
        osSendMesg(&D_8027FBC8, NULL, OS_MESG_NOBLOCK);
    }
    else{
        D_8027FC0C++;
    }
}

void resetThread_handleDPEvent(void){
    if((D_8027FC14 << 1) < 0){
        osDpSetStatus(DPC_SET_FREEZE);
        sCurrentFramebuffer = osViGetCurrentFramebuffer();
        viMgr_func_8024BFAC();
    }
    D_8027FC14 = D_8027FC18 = 2;
    D_80275998 = 0;
    if(D_8027FC1C == 0x10 && D_8028062C != D_80280628 && !D_8027FC10){
        resetThread_startGfxTask(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 0x14;
    }
    else{
        if(D_8027FC0C && D_8028062C == D_80280628 && !(osDpGetStatus() & DPC_STATUS_FREEZE)){
            osSendMesg(&D_8027FBC8, NULL, 0);
            D_8027FC0C--;
        }
    }
}

void resetThread_handleMesg5(void){
    static s32 D_802759A4 = 0;
    s32 sp2C = (D_8027FC0C != 0) && (D_8028062C == D_80280628) && (D_8027FC18 == 2) && (D_8027FC1C == 0x10);
    volatile s32 sp30;

    sp30 = FALSE;
    if( osViGetCurrentFramebuffer() != sCurrentFramebuffer || sp2C){
        if(osDpGetStatus() & DPC_STATUS_FREEZE){
            osDpSetStatus(DPC_CLR_FREEZE);

            D_8027FC14 = D_8027FC18;
            dummy_func_8025AFB8();

            if(D_8027FC14 & 1){
                D_80275998 = 0x1E;
            }
        }

        if(sp2C){
            osSendMesg(&D_8027FBC8, NULL, OS_MESG_NOBLOCK);
            D_8027FC0C--;
        }
    }

    D_80275990 = 0;

    if(D_80275994 != 0){
        D_80275994--;
    }

    if(D_8027599C != 0){
        D_8027599C--;
    }

    if(D_80275998 != 0){
        D_80275998--;
        if(D_80275998 == 0){
            sp30 = TRUE;
        }
    }
    D_8027FC10 = 0;
    D_802759A4++;
    if(!(D_802759A4 & 1)){
        osStopTimer(&D_80280690);
        osSetTimer(&D_80280690, 280000, 0, &D_8027FB60, CORE1_8C50_EVENT_AUDIO_TIMER);
    }

    if(D_802806D0){
        osStopTimer(&D_802806B0);
#if VERSION == VERSION_USA_1_0
        osSetTimer(&D_802806B0, ((osClockRate / 60)* 2) / 3, 0, &D_8027FB60, CORE1_8C50_EVENT_CONT_TIMER);
#elif VERSION == VERSION_PAL
        osSetTimer(&D_802806B0, ((osClockRate / 60.0)* 2) / 3, 0, &D_8027FB60, CORE1_8C50_EVENT_CONT_TIMER);
#endif
    }
}

void resetThread_handleSPEvent(void) {
    Struct_Core1_8C50_s *sp1C;
    s32 temp_v1;
    Struct_Core1_8C50_s *temp_v0;

    temp_v1 = D_8027FC1C;
    if (D_8027FC1C == 0x20) {
        sp1C = D_80280630[D_80280684];
        D_80280684 = (D_80280684 + 1) % 20;
        D_8027FC24 = (osSpTaskYielded(&sGfxTask) == 1);
        resetThread_startAudioTask(sp1C);
        D_8027599C = 0;
        return;
    }

    if (D_8027FC1C == 4) {
        osSendMesg(D_8027FC08[1].unk0, D_8027FC08[1].unk4, 0);
    }

    if ((D_8027FC1C == 4) && (D_8027FC24 != 0)) {
        osSpTaskLoad(&sGfxTask);
        osSpTaskStartGo(&sGfxTask);
        D_8027FC1C = D_8027FC20;
        D_8027FC24 = 0;
        return;
    }

    D_8027FC1C = 0x10;
    if ((D_8028062C != D_80280628) && (D_8027FC10 == 0)) {
        resetThread_startGfxTask(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 20;
        return;
    }
    
    if ((D_8027FC0C != 0) && (D_8027FC14 == 2) && !(osDpGetStatus() & 2)) {
        osSendMesg(&D_8027FBC8, NULL, 0);
        D_8027FC0C -= 1;
    }
}

void func_802471D8(OSMesg arg0){
    D_8027FC10 = TRUE;
}

void resetThread_handleAudioTimerEvent(void){
    osSendMesg(audioManager_getFrameMesgQueue(), NULL, OS_MESG_NOBLOCK);
    func_80247224();
}

void func_80247224(void){
    Struct_Core1_8C50_s *ptr;
    if((D_8027FC1C == 0x10) && (D_80280684 != D_80280680)){
        ptr = D_80280630[D_80280684];
        D_80280684 = (D_80280684 + 1) % 0x14;
        resetThread_startAudioTask(ptr);
    }
    else if((D_8027FC1C & 0x8) && (D_80280684 != D_80280680)){
        osSpTaskYield();
        D_8027FC20 = D_8027FC1C;
        D_8027FC1C = 0x20;
        D_8027599C = 0x1E;
    }
}

void func_80247304(void){}

void resetThread_handlePreNMIEvent(void){
    static OSViMode D_802759A8 = {
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
    static OSViMode D_802759F8 = {
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
    static OSViMode D_80275A48 = {
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
            osViSetMode(&D_802759A8);
        } else {
            osViSetMode(&D_802759F8);
        }
#elif VERSION == VERSION_PAL
        // if(&D_802759A8){}
        osViSetMode(&D_80275A48);
#endif
        baMotor_80250FC0(); //stop controller motors
        do{ 
            osDpSetStatus(DPC_STATUS_FLUSH);
        }while(1);
    }
}

void func_80247380(void){
    if(!(___osGetSR() & SR_IBIT5)){
        resetThread_handlePreNMIEvent();
    }
}

void resetThread_entry(void *arg) {
    OSMesg msg = NULL;

    while (1) {
        osRecvMesg(&D_8027FB60, &msg, OS_MESG_BLOCK);
        func_80247380();

        if (msg == (OSMesg) 3) {
            resetThread_handleMesg3();
        }
        else if (msg == (OSMesg) 5) {
            resetThread_handleMesg5();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_DP) {
            resetThread_handleDPEvent();
        }
        else if (msg == (OSMesg) RESETTHREAD_MESSAGE_EVENT_SP) {
            resetThread_handleSPEvent();
        }
        else if (msg == (OSMesg) CORE1_8C50_EVENT_AUDIO_TIMER) {
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
        else if (msg == (OSMesg) CORE1_8C50_EVENT_CONT_TIMER) {
            pfsManager_getStartReadData();
        }
        else if (msg >= (OSMesg) 100) {
            if (*(u32 *)msg == 0) {
                func_80246A64(msg);
            }
            else if (*(u32 *)msg == 1) {
                func_80246A84(msg);
            }
            else if (*(u32 *)msg == 2) {
                func_80246B0C(msg);
            }
            else if (*(u32* )msg == 7) {
                func_802471D8(msg);
            }
        }
    };
}

void resetThread_create(void) {
    u64 *yield_ptr;
    osCreateMesgQueue(&D_8027FB60, D_8027FB78, 20);
    osCreateMesgQueue(&D_8027FBC8, D_8027FBE0, 10);
    osSetEventMesg(OS_EVENT_DP, &D_8027FB60, (OSMesg) RESETTHREAD_MESSAGE_EVENT_DP);
    osSetEventMesg(OS_EVENT_SP, &D_8027FB60, (OSMesg) RESETTHREAD_MESSAGE_EVENT_SP);
    osSetEventMesg(OS_EVENT_FAULT, &D_8027FB60, (OSMesg) RESETTHREAD_MESSAGE_EVENT_FAULT);
    osSetEventMesg(OS_EVENT_PRENMI, &D_8027FB60, (OSMesg) RESETTHREAD_MESSAGE_EVENT_PRENMI);
    viMgr_func_8024BDAC(&D_8027FB60, (OSMesg) 5);
    D_8027FC0C = 0;
    D_8027FC10 = 0;
    D_8027FC14 = D_8027FC18 = 2;
    D_8027FC1C = D_8027FC20 = 0x10;
    D_8027FC24 = 0;
    D_8028062C = 0;
    D_80280628 = 0;
    D_80280684 = 0;
    D_80280680 = 0;

    for (yield_ptr = sYieldData; (u32) yield_ptr % 0x10; yield_ptr = (u8 *) yield_ptr + 1);
    sGfxTask.t.yield_data_ptr = yield_ptr;

    osCreateThread(&sResetThread, 5, resetThread_entry, NULL, STACK_START(sResetThreadStack), 60);
    osStartThread(&sResetThread);
}

void func_802476DC(void){
    D_802806D0 = 1;
}

void resetThread_finishDList(Gfx **gfx) {
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}

s32 func_80247720(void){
    return D_8027FC1C;
}

OSMesgQueue *func_8024772C(void){
    return &D_8027FB60;
}

OSThread *resetThread_getThreadObject(void) {
    return &sResetThread;
}
