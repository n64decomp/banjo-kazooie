#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "version.h"

#define VIMANAGER_THREAD_STACK_SIZE 0x400

// Used in US 1.0 NTSC 
static OSViMode sViMode_US10_NTSC = {
    OS_VI_NTSC_LPN1,
    {
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
        292,          /* width*/
        0x3E52239,    /* burst*/
        0x20D,        /* vSync*/
        0xC15,        /* hSync*/
        0xC150C15,    /* leap */
        0x8C02D5,     /* hstart */
        0x200,        /* xScale */
        0x0,          /* vCurrent */
    },
    {
        {0x248, 0x400, 0x3D01E8, 0xE0204, 2},
        {0x248, 0x400, 0x3D01E8, 0xE0204, 2},
    }
};

// Used in US 1.0 MPAL (N64 SDK says: "mainly brazil")
static OSViMode sViMode_US10_MPAL = {
    OS_VI_MPAL_LPN1,
    {
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200,       /*ctrl*/
        292,          /* width*/
        0x4651E39,    /* burst*/
        0x20D,        /* vSync*/
        0x40C11,      /* hSync*/
        0xC190C1A,    /* leap */
        0x8C02D5,     /* hstart */
        0x200,        /* xScale */
        0x0,          /* vCurrent */
    },
    {
        {0x248, 0x400, 0x3D01E8, 0xE0204, 2},
        {0x248, 0x400, 0x3D01E8, 0xE0204, 2},
    }
};

#if VERSION == VERSION_PAL
// Used in PAL
static OSViMode sViMode_PAL = {
    OS_VI_PAL_LPN1,
    {
        VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | VI_CTRL_DIVOT_ON | 0x3100,       /*ctrl*/
        292,          /* width*/
        0x404233A,    /* burst*/
        0x271,        /* vSync*/
        0x150C69,     /* hSync*/
        0xC6F0C6E,    /* leap */
        0x9802E1,     /* hstart */
        0x200,        /* xScale */
        0x0,          /* vCurrent */
    },
    {
        {0x248, 0x350, 0x48024C, 0x9026B, 2},
        {0x248, 0x350, 0x48024C, 0x9026B, 2},
    }
};
#endif

// 42200000 3FAD097B 41F00000 457A0000
// C3A68832 DDC3A724 00000000 00000000

static u32 sActiveFramebuffer;
u32 D_80280724;
u32 D_80280728;
struct1 D_80280730[8];
static OSMesgQueue sMesgQueue1;
static OSMesg sMesgBuffer1[10];
static OSMesgQueue sMesgQueue2;
static OSMesg sMesgBuffer2[1];
static OSMesgQueue sMesgQueue3;
static OSMesg sMesgBuffer3[FRAMERATE];
volatile s32 D_802808D8;
s32 D_802808DC;
static OSThread sViManagerThread;
static u8 sViManagerThreadStack[VIMANAGER_THREAD_STACK_SIZE];

u32 getOtherFramebuffer(void) {
    return NOT(sActiveFramebuffer);
}

s32 viMgr_func_8024BD94(void){
    return D_80280724;
}

s32 getActiveFramebuffer(void){
    return sActiveFramebuffer;
}

void viMgr_func_8024BDAC(OSMesgQueue *mq, OSMesg msg){
    s32 i;
    for(i = 0; i < 8; i++){
        if(D_80280730[i].messageQueue == NULL){
            D_80280730[i].messageQueue = mq;
            D_80280730[i].message = msg;
            return;
        }
    }

}

void viMgr_init(void) {
    s32 i;

    viMgr_clearFramebuffers();

    osCreateViManager(OS_PRIORITY_VIMGR);
#if VERSION == VERSION_USA_1_0
    if(osTvType != OS_TV_NTSC)
        osViSetMode(&sViMode_US10_MPAL);
    else
        osViSetMode(&sViMode_US10_NTSC);
#elif VERSION == VERSION_PAL
        osViSetMode(&sViMode_PAL);
#endif

    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osViSwapBuffer(&gFramebuffers[0]);

    osCreateMesgQueue(&sMesgQueue1, sMesgBuffer1, 10);
    osCreateMesgQueue(&sMesgQueue2, sMesgBuffer2, 1);
    osCreateMesgQueue(&sMesgQueue3, sMesgBuffer3, FRAMERATE);
    osViSetEvent(&sMesgQueue1, NULL, 1);

    sActiveFramebuffer = 0;
    D_80280724 = 1;
    D_80280728 = 0;

    for (i = 0; i < 8; i++) {
        D_80280730[i].messageQueue = NULL;
    }

    D_802808D8 = 0;
    viMgr_func_8024BF94(2);

    osCreateThread(&sViManagerThread, 0, viMgr_entry, NULL, sViManagerThreadStack + VIMANAGER_THREAD_STACK_SIZE, 80);
    osStartThread(&sViManagerThread);
}

void viMgr_func_8024BF94(s32 arg0){
    D_802808DC = arg0;
}

s32 viMgr_func_8024BFA0(void){
    return D_802808DC;
}

void viMgr_func_8024BFAC(void){
    osSendMesg(&sMesgQueue2, 0, OS_MESG_NOBLOCK);
}

void viMgr_func_8024BFD8(s32 arg0){
    static s32 D_80280E90;
    
    osSetThreadPri(NULL, 0x7f);
    defragManager_setPriority(0x1E);
    defragManager_80240874();
    if(arg0){
        osRecvMesg(&sMesgQueue2, NULL, OS_MESG_BLOCK);
    }

    while(D_802808D8 < viMgr_func_8024BFA0() - D_80280E90){
        osRecvMesg(&sMesgQueue3, NULL, OS_MESG_BLOCK);
    }

    while(sMesgQueue3.validCount){
        osRecvMesg(&sMesgQueue3, NULL, OS_MESG_NOBLOCK);
    }
    
    osViSwapBuffer(gFramebuffers[sActiveFramebuffer = getOtherFramebuffer()]);
    D_80280E90 = 0;
    while(!(osDpGetStatus() & 2) && osViGetCurrentFramebuffer() != osViGetNextFramebuffer()){
        osRecvMesg(&sMesgQueue3, NULL, OS_MESG_BLOCK);
        D_80280E90++;
    }//L8024C178
    D_80280724 = D_802808D8;
    D_802808D8 = 0;
    defragManager_802408B0();
    osSetThreadPri(NULL, 0x14);
    defragManager_setPriority(0xA);
}

void viMgr_func_8024C1B4(void){
    viMgr_func_8024BFD8(0);
    dummy_func_8025AFB8();
}

void viMgr_func_8024C1DC(void){
    viMgr_func_8024BFD8(1);
}

void viMgr_func_8024C1FC(OSMesgQueue *mq, OSMesg msg) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_80280730[i].messageQueue == mq && D_80280730[i].message == msg) {
            D_80280730[i].messageQueue = NULL;
            return;
        }
    }
}

void viMgr_setActiveFramebuffer(s32 fb_idx) {
    sActiveFramebuffer = fb_idx;
    osViSwapBuffer(gFramebuffers[sActiveFramebuffer]);
}

void viMgr_entry(void *arg0){
    s32 i;
    OSMesg sp48;
    do{
        osRecvMesg(&sMesgQueue1, &sp48, OS_MESG_BLOCK);
        func_80247380();
        D_802808D8++;
        if(D_802808D8 == 420){
#if VERSION == VERSION_USA_1_0
            gcdebugText_isThreadLocked();
#endif
        }
        osSendMesg(&sMesgQueue3, NULL, OS_MESG_NOBLOCK);

        for(i = 0; i < 8; i++){
            if(D_80280730[i].messageQueue != NULL){
                osSendMesg(D_80280730[i].messageQueue, D_80280730[i].message, OS_MESG_NOBLOCK);
            }
        }
    }while(1);
}

void viMgr_setScreenBlack(s32 active) {
    osViBlack(active);
}

void viMgr_clearFramebuffers(void) {
    func_80253034(&gFramebuffers, 0, (s32) ((f32)gFramebufferWidth*2*gFramebufferHeight*2)); // TODO: This function does not exist in source code, why does it work?
    osWritebackDCache(&gFramebuffers, (s32) ((f32)gFramebufferWidth*2*gFramebufferHeight*2));
}

s32 viMgr_func_8024C4E8(void) {
    return D_802808D8;
}

void viMgr_func_8024C4F8(s32 arg0) {
    D_802808D8 = arg0;
}
