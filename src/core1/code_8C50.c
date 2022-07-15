#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern s32 D_80000300;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
}Struct_Core1_8C50_s;

void func_80247224(void);

#define CORE1_8C50_EVENT_DP 4
#define CORE1_8C50_EVENT_SP 6
#define CORE1_8C50_EVENT_AUDIO_TIMER 8
#define CORE1_8C50_EVENT_FAULT 10
#define CORE1_8C50_EVENT_PRENMI 11
#define CORE1_8C50_EVENT_CONT_TIMER 13

/* .data */
extern u64 D_80272590[]; // ucode
extern u64 D_802731F0[];
extern u64 D_80274620[];
extern OSTask D_80275910;
extern OSTask D_80275950;
extern s32 D_80275990;
extern s32 D_80275994;
extern s32 D_80275998;
extern s32 D_8027599C;
extern s32 D_802759A0;
// static s32 D_802759A4;
extern OSViMode D_802759A8;
extern OSViMode D_802759F8;
extern u64 D_80278E80[]; //ucode_data
extern u64 D_80279130[];
extern u64 D_80279930[];


/* .bss */
s32 D_8027EF40;
u8 D_8027EF44[0xC20];
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
u8 pad_8027FC28[0x7F8];
OSThread D_80280428;
Struct_Core1_8C50_s * D_802805D8[20];
volatile s32 D_80280628;
volatile s32 D_8028062C;
Struct_Core1_8C50_s * D_80280630[20];
volatile s32 D_80280680;
volatile s32 D_80280684;
s32 D_80280688;
OSTimer D_80280690; //audio_timer
OSTimer D_802806B0; //controller_timer
s32 D_802806D0;

/* .code */
void func_80246670(OSMesg arg0){
    sizeof(OSThread);
    osSendMesg(&D_8027FB60, arg0, 1);
    if((s32) arg0 == 3 ){
        D_80275994 = 0x1e;
        if(D_802759A0){
            osDpSetStatus(DPC_CLR_FREEZE);
            D_802759A0 = 0;
        }
        osRecvMesg(&D_8027FBC8, NULL, 1);
        D_80275994 = 0;
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
    s32 tmp = (D_80280628 + 1) % 0x14;
    if(D_8028062C != tmp){
        D_802805D8[D_80280628] = arg0;
        D_80280628 = tmp;
    }
}

void func_80246794(Struct_Core1_8C50_s * arg0){
    func_80255D0C(&D_80275910.t.ucode_boot, &D_80275910.t.ucode_boot_size);
    D_80275910.t.ucode = D_80272590;
    D_80275910.t.ucode_data = D_80278E80;
    D_80275910.t.data_ptr = (void*) arg0->unk8;
    D_80275910.t.data_size = (arg0->unkC - arg0->unk8) >> 3 << 3;
    osWritebackDCache(D_80275910.t.data_ptr , D_80275910.t.data_size);
    osWritebackDCache(&D_80275910, sizeof(OSTask));
    D_8027FC08 = arg0;
    osSpTaskLoad(&D_80275910);
    osSpTaskStartGo(&D_80275910);
    D_8027FC1C = 4;
}

void func_80246844(Struct_Core1_8C50_s * arg0){
    func_80255D0C(&D_80275950.t.ucode_boot, &D_80275950.t.ucode_boot_size);
    D_80275950.t.ucode = D_802731F0;
    D_80275950.t.ucode_data = D_80279130;
    D_80275950.t.data_ptr = (void*) arg0->unk8;
    D_80275950.t.data_size = (arg0->unkC - arg0->unk8) >> 3 << 3;
    osWritebackDCache(D_80275950.t.data_ptr , D_80275950.t.data_size);
    osWritebackDCache(&D_80275950, sizeof(OSTask));
    osSpTaskLoad(&D_80275950);
    osSpTaskStartGo(&D_80275950);
    D_8027FC1C = arg0->unk4 | 0x8;
    D_8027FC18 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_8027FC14 = D_8027FC18;
        D_80275998 = 0x1e;
    }
}

void func_8024692C(Struct_Core1_8C50_s * arg0){
    func_80255D0C(&D_80275950.t.ucode_boot, &D_80275950.t.ucode_boot_size);
    D_80275950.t.ucode = D_80274620;
    D_80275950.t.ucode_data = D_80279930;
    D_80275950.t.data_ptr = (void*) arg0->unk8;
    D_80275950.t.data_size = (arg0->unkC - arg0->unk8) >> 3 << 3;
    osWritebackDCache(D_80275950.t.data_ptr , D_80275950.t.data_size);
    osWritebackDCache(&D_80275950, sizeof(OSTask));
    osSpTaskLoad(&D_80275950);
    osSpTaskStartGo(&D_80275950);
    D_8027FC1C = arg0->unk4 | 0x8;
    D_8027FC18 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_8027FC14 = D_8027FC18;
        D_80275998 = 0x1e;
    }
}

void func_80246A14(Struct_Core1_8C50_s *arg0){
    switch(arg0->unk0){
        case 1:
            func_80246844(arg0);
            break;

        case 2:
            func_8024692C(arg0);
            break;
    }
}

void func_80246A64(OSMesg msg){
    func_802466F4(msg);
}

void func_80246A84(OSMesg msg){
    func_80246744(msg);
    if(D_8027FC1C == 0x10 && !D_8027FC10){
        func_80246844(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 0x14;
    }
}

void func_80246B0C(OSMesg msg){
    func_80246744(msg);
    if(D_8027FC1C == 0x10 && !D_8027FC10){
        func_8024692C(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 0x14;
    }
}

void func_80246B94(void){
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

void func_80246C2C(void){
    if((D_8027FC14 << 1) < 0){
        osDpSetStatus(DPC_SET_FREEZE);
        D_80280688 = osViGetCurrFrameBuffer();
        func_8024BFAC();
    }
    D_8027FC14 = D_8027FC18 = 2;
    D_80275998 = 0;
    if(D_8027FC1C == 0x10 && D_8028062C != D_80280628 && !D_8027FC10){
        func_80246A14(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1) % 0x14;
    }
    else{
        if(D_8027FC0C && D_8028062C == D_80280628 && !(osDpGetStatus() & DPC_STATUS_FREEZE)){
            osSendMesg(&D_8027FBC8, NULL, 0);
            D_8027FC0C--;
        }
    }
}

#ifndef NONMATCHING //MATCHES but requires .data defined for local static variable
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246D78.s")
#else
static s32 D_802759A4;
void func_80246D78(void){
    s32 sp2C = (D_8027FC0C != 0) && (D_8028062C == D_80280628) && (D_8027FC18 == 2) && (D_8027FC1C == 0x10);
    volatile s32 sp30;

    sp30 = FALSE;
    if( osViGetCurrFrameBuffer() != D_80280688 || sp2C){
        if(osDpGetStatus() & DPC_STATUS_FREEZE){
            osDpSetStatus(DPC_CLR_FREEZE);

            D_8027FC14 = D_8027FC18;
            func_8025AFB8();

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
        osSetTimer(&D_802806B0, ((osClockRate / 60)* 2) / 3, 0, &D_8027FB60, CORE1_8C50_EVENT_CONT_TIMER);
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247000.s")

void func_802471D8(OSMesg arg0){
    D_8027FC10 = TRUE;
}

void func_802471EC(void){
    osSendMesg(amgr_getFrameMesgQueue(), NULL, OS_MESG_NOBLOCK);
    func_80247224();
}

void func_80247224(void){
    Struct_Core1_8C50_s *ptr;
    if((D_8027FC1C == 0x10) && (D_80280684 != D_80280680)){
        ptr = D_80280630[D_80280684];
        D_80280684 = (D_80280684 + 1) % 0x14;
        func_80246794(ptr);
    } else if((D_8027FC1C & 0x8) && (D_80280684 != D_80280680)){
        osSpTaskYield();
        D_8027FC20 = D_8027FC1C;
        D_8027FC1C = 0x20;
        D_8027599C = 0x1E;
    }
}

void func_80247304(void){};

void func_8024730C(void){
    static s32 D_802806D4;

    if(!D_802806D4){
        D_802806D4 = TRUE;
        if(D_80000300 != TRUE){
            osViSetMode(&D_802759A8);
        } else {
            osViSetMode(&D_802759F8);
        }
        func_80250FC0(); //stop controller motors
        do{ 
            osDpSetStatus(DPC_STATUS_FLUSH);
        }while(1);
    }
}

void func_80247380(void){
    if(!(___osGetSR() & SR_IBIT5)){
        func_8024730C();
    }
}

void func_802473B4(void *arg0){
    OSMesg msg = NULL;
    do{
        osRecvMesg(&D_8027FB60, &msg, OS_MESG_BLOCK);
        func_80247380();
        if((s32)msg == 3){ func_80246B94(); }
        else if((u32)msg == 5)  { func_80246D78(); }
        else if((u32)msg == CORE1_8C50_EVENT_DP)          { func_80246C2C(); }
        else if((u32)msg == CORE1_8C50_EVENT_SP)          { func_80247000(); }
        else if((u32)msg == CORE1_8C50_EVENT_AUDIO_TIMER) { func_802471EC(); }
        else if((u32)msg == CORE1_8C50_EVENT_FAULT)       { do{}while(1); }
        else if((u32)msg == CORE1_8C50_EVENT_PRENMI)      { func_8024730C(); }
        else if((u32)msg == 12) {  }
        else if((u32)msg == CORE1_8C50_EVENT_CONT_TIMER)  { func_8024F1B0(); }
        else if((u32)msg >= 100) {
            if(*(u32*)msg == 0){ func_80246A64(msg); }
            else if(*(u32*)msg == 1){ func_80246A84(msg); }
            else if(*(u32*)msg == 2){ func_80246B0C(msg); }
            else if(*(u32*)msg == 7){ func_802471D8(msg); }
        }
    }while(1);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247560.s")
#else
void func_80247560(void){
    u32 tmp_v0;
    osCreateMesgQueue(&D_8027FB60, &D_8027FB78, 20);
    osCreateMesgQueue(&D_8027FBC8, &D_8027FBE0, 10);
    osSetEventMesg(OS_EVENT_DP, &D_8027FB60, CORE1_8C50_EVENT_DP);
    osSetEventMesg(OS_EVENT_SP, &D_8027FB60, CORE1_8C50_EVENT_SP);
    osSetEventMesg(OS_EVENT_FAULT, &D_8027FB60, CORE1_8C50_EVENT_FAULT);
    osSetEventMesg(OS_EVENT_PRENMI, &D_8027FB60, CORE1_8C50_EVENT_PRENMI);
    func_8024BDAC(&D_8027FB60, 5);
    D_8027FC0C = 0;
    D_8027FC10 = 0;
    D_8027FC14 = D_8027FC18 = 2;
    D_8027FC1C = D_8027FC20 = 0x10;
    D_8027FC24 = 0;
    D_80280628 = D_8028062C = 0;
    D_80280680 = D_80280684 = 0;
    for(tmp_v0 = &D_8027EF40; tmp_v0 & 0xF; tmp_v0++){}
    D_80275950.yield_data_size = tmp_v0;
    osCreateThread(&D_80280428, 5, func_802473B4, NULL, &D_80280428, 60);
    osStartThread(&D_80280428);
}
#endif

void func_802476DC(void){
    D_802806D0 = 1;
}

void func_802476EC(Gfx **gfx){
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}

s32 func_80247720(void){
    return D_8027FC1C;
}

OSMesgQueue *func_8024772C(void){
    return &D_8027FB60;
}

OSThread *func_80247738(void){
    return &D_80280428;
}
