#include <ultra64.h>
#include "functions.h"
#include "variables.h"



void func_8024BF94(s32 arg0);
void func_8024C2F8(void *);

typedef struct struct_1_s{
    OSMesgQueue *messageQueue;
    OSMesg message;
} struct1;

extern u32 D_80000300;

OSViMode D_80275C80 = {
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

OSViMode D_80275CD0 = {
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

// 42200000 3FAD097B 41F00000 457A0000
// C3A68832 DDC3A724 00000000 00000000


u32 D_80280720;
u32 D_80280724;
u32 D_80280728;
struct1 D_80280730[8];
OSMesgQueue D_80280770;
OSMesgQueue D_802807B0;
OSMesgQueue D_802807D0;
volatile s32 D_802808D8;
s32 D_802808DC;
OSThread D_802808E0;
u8 pad_80280970[0x520];


extern u8 D_803A5D00[2][0x1ECC0]; //framebuffer

void func_8024C428(void);

/* .code */
bool func_8024BD80(void){
    sizeof(OSThread);
    return NOT(D_80280720);
}

s32 func_8024BD94(void){
    return D_80280724;
}

s32 func_8024BDA0(void){
    return D_80280720;
}

void func_8024BDAC(OSMesgQueue *mq, OSMesg msg){
    s32 i;
    for(i = 0; i < 8; i++){
        if(D_80280730[i].messageQueue == NULL){
            D_80280730[i].messageQueue = mq;
            D_80280730[i].message = msg;
            return;
        }
    }

}

void func_8024BE30(void){
    extern s32 D_80280E90;
    s32 i;

    func_8024C428();
    osCreateViManager(0xfe);
    if(osTvType != OS_TV_NTSC)
        osViSetMode(&D_80275CD0); //PAL  
    else
        osViSetMode(&D_80275C80); //NTSC
        
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osViSwapBuffer(&D_803A5D00);
    osCreateMesgQueue(&D_80280770, (&D_80280770 + 1), 10);
    osCreateMesgQueue(&D_802807B0, (&D_802807B0 + 1), 1);
    osCreateMesgQueue(&D_802807D0, (&D_802807D0 + 1), 0x3C);
    osViSetEvent(&D_80280770,NULL,1);
    D_80280720 = 0;
    D_80280724 = 1;
    D_80280728 = 0;
    for(i = 0; i<8; i++){
        D_80280730[i].messageQueue = NULL;
    }
    D_802808D8 = 0;
    func_8024BF94(2);
    osCreateThread(&D_802808E0,0,func_8024C2F8,NULL,&D_80280E90,0x50);
    osStartThread(&D_802808E0);
}

void func_8024BF94(s32 arg0){
    D_802808DC = arg0;
}

s32 func_8024BFA0(void){
    return D_802808DC;
}

void func_8024BFAC(void){
    osSendMesg(&D_802807B0, 0, OS_MESG_NOBLOCK);
}

void func_8024BFD8(s32 arg0){
    static s32 D_80280E90;
    
    osSetThreadPri(NULL, 0x7f);
    defragManager_setPriority(0x1E);
    defragManager_80240874();
    if(arg0){
        osRecvMesg(&D_802807B0, NULL, OS_MESG_BLOCK);
    }

    while(D_802808D8 < func_8024BFA0() - D_80280E90){
        osRecvMesg(&D_802807D0, NULL, OS_MESG_BLOCK);
    }

    while(D_802807D0.validCount){
        osRecvMesg(&D_802807D0, NULL, OS_MESG_NOBLOCK);
    }
    
    osViSwapBuffer(D_803A5D00[D_80280720 = func_8024BD80()]);
    D_80280E90 = 0;
    while(!(osDpGetStatus() & 2) && osViGetCurrentFramebuffer() != osViGetNextFramebuffer()){
        osRecvMesg(&D_802807D0, NULL, OS_MESG_BLOCK);
        D_80280E90++;
    }//L8024C178
    D_80280724 = D_802808D8;
    D_802808D8 = 0;
    defragManager_802408B0();
    osSetThreadPri(NULL, 0x14);
    defragManager_setPriority(0xA);
}

void func_8024C1B4(void){
    func_8024BFD8(0);
    func_8025AFB8();
}

void func_8024C1DC(void){
    func_8024BFD8(1);
}

void func_8024C1FC(OSMesgQueue *mq, OSMesg msg){
    s32 i;
    for(i = 0; i < 8; i++){
        if(D_80280730[i].messageQueue == mq && D_80280730[i].message == msg){
            D_80280730[i].messageQueue = NULL;
            return;
        }
    }
}

void func_8024C2A0(s32 arg0) {
    D_80280720 = arg0;
    osViSwapBuffer(D_803A5D00[D_80280720]);
}

void func_8024C2F8(void *arg0){
    s32 i;
    OSMesg sp48;
    do{
        osRecvMesg(&D_80280770, &sp48, OS_MESG_BLOCK);
        func_80247380();
        D_802808D8++;
        if(D_802808D8 == 420){
            func_802485BC();
        }
        osSendMesg(&D_802807D0, NULL, OS_MESG_NOBLOCK);

        for(i = 0; i < 8; i++){
            if(D_80280730[i].messageQueue != NULL){
                osSendMesg(D_80280730[i].messageQueue, D_80280730[i].message, OS_MESG_NOBLOCK);
            }
        }
    }while(1);
}

void func_8024C408(s32 arg0){
    osViBlack(arg0);
}

void func_8024C428(void) {
    //zeros all both framebuffers
    func_80253034(&D_803A5D00, 0, (s32) ((f32)framebuffer_width*2*framebuffer_height*2));
    osWritebackDCache(&D_803A5D00, (s32) ((f32)framebuffer_width*2* framebuffer_height*2));
}

s32 func_8024C4E8(void){
    return D_802808D8;
}

void func_8024C4F8(s32 arg0){
    D_802808D8 = arg0;
}
