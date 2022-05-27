#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "2.0L/PR/sched.h"
#include "n_libaudio.h"

extern void func_8025C320(s32, ALSynConfig *);

typedef struct AudioInfo_s {
	short         *data;          /* Output data pointer */
	short         frameSamples;   /* # of samples synthesized in this frame */
	u8            pad4[2];
    s16           unk8;
	u8            padA[2];
    struct AudioInfo_s    *unkC;
} AudioInfo;

typedef struct Struct_1D00_1_s{
    void *unk0;
    u8 pad4[4];
    s16 unk8;
    u8 pada[2];
    struct Struct_1D00_1_s *unkC;
} Struct_1D00_1;

typedef struct {
    u8 pad0[4];
    AudioInfo *unk4;
} Struct_1D00_2;

typedef struct Struct_1D00_3_s{
    ALLink  unk0;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} Struct_1D00_3;

typedef struct{
    u8 pad0[0x18];
}Struct_core1_1D00_4;

void func_8023FBB8(void);
void func_8023FE80(void *);
// void func_802403B8(void);
void func_802401C4(AudioInfo *info);
void *func_802403B8(void *state);
void func_802403F0(void);
void func_80240570(void);



extern s32 D_80000300;
extern s32 osViClock;
extern s32 D_80275770;
extern s32 D_80275774;
extern u8  D_80275778;
extern s32 D_8027577C;
extern Struct_1D00_2 *D_80275844;
extern AudioInfo *D_80275848;
extern int D_8027584C;
extern f32 D_80277638;

extern struct {
    Acmd* unk0[2];
    AudioInfo *unk8[3];
} D_8027BF40;
extern OSThread D_8027BF58;
extern OSMesgQueue D_8027C108;
extern OSMesg D_8027C120;
extern OSMesgQueue D_8027C140;
extern OSMesg D_8027C158;
extern ALHeap D_8027CFF0;
extern u8 * D_8027D000;
extern OSMesgQueue D_8027D008;
extern OSMesg D_8027D020;
extern OSIoMesg D_8027D0E8;
extern Struct_core1_1D00_4 D_8027D100[];
extern struct {
    u8 unk0;
    Struct_1D00_3 *unk4;
    Struct_1D00_3 *unk8;
    u8 padC[0x4];
}  D_8027D5B0;
extern Struct_1D00_3 D_8027D5C0[];
extern s32 D_8027DCC8;
extern s32 D_8027DCCC;
extern s32 D_8027DCD0;
extern s32 D_8027DCD8;
extern ALSynConfig D_8027DD50;
extern s32 D_8027DD74;
extern s32 D_8027DD78;
extern s32 D_8027DD7C;
extern s32 D_8027DD80;


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_8023F720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_8023F770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_8023F88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_8023FA4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_8023FA64.s")
// void func_8023FA64(ALSeqpConfig *arg0){

// }

void func_8023FB1C(void){
    D_8027D000 = (u8 *) malloc(0x21000);
    bzero(D_8027D000, 0x21000);
    alHeapInit(&D_8027CFF0, D_8027D000, 0x21000);
    if(D_80000300 != 1)
        osViClock = 0x2e6025c;
    func_8023FBB8();
    func_80335220();
    func_8024F4E0();
    func_80240570();
}

//amgrCreate
void func_8023FBB8(void) {
    int i;

    osCreateMesgQueue(&D_8027D008, &D_8027D020, 0x32);
    osCreateMesgQueue(&D_8027C140, &D_8027C158, 8);
    osCreateMesgQueue(&D_8027C108, &D_8027C120, 8);
    D_8027DD74 = (s32)D_80277638;
    if ((f32) D_8027DD74 < D_80277638) {
        D_8027DD74++;
    }
    D_8027DD74 = ((D_8027DD74 / 0xB8) * 0xB8) + 0xB8;
    D_8027DD78 = D_8027DD74 - 0xB8;
    D_8027DD7C = D_8027DD74;
    D_8027DD50.maxVVoices = 0x18;
    D_8027DD50.maxPVoices = 0x18;
    D_8027DD50.maxUpdates = 0x80;
    D_8027DD50.dmaproc = (void*)func_802403B8;
    D_8027DD50.fxType = 6;
    D_8027DD50.params = (void*) &D_8027577C;
    D_8027DD50.heap = &D_8027CFF0;
    D_8027DD50.outputRate = osAiSetFrequency(22000);
    func_8025C320(&D_8027DCD8, &D_8027DD50);
    D_8027D5C0[0].unk0.prev = NULL;
    D_8027D5C0[0].unk0.next = NULL;
    for(i = 0; i < 89; i++){
        alLink((ALLink *)&D_8027D5C0[i+1], (ALLink *)&D_8027D5C0[i]);
        D_8027D5C0[i].unk10 = alHeapDBAlloc(0, 0, D_8027DD50.heap, 1, 0x200);
    }
    D_8027D5C0[i].unk10 = alHeapDBAlloc(0, 0, D_8027DD50.heap, 1, 0x200);

    for(i = 0; i < 2; i++){
        D_8027BF40.unk0[i] = malloc(0x4E20);
    }
    D_8027DD80 = 0x9C4;
    for(i = 0; i < 3; i++){
        D_8027BF40.unk8[i] = alHeapDBAlloc(0, 0, D_8027DD50.heap, 1, 0x10);
        D_8027BF40.unk8[i]->unk8 = 0;
        D_8027BF40.unk8[i]->unkC = D_8027BF40.unk8[i];
        D_8027BF40.unk8[i]->data = malloc(D_8027DD7C * 4);
    }
    osCreateThread(&D_8027BF58, 4, &func_8023FE80, 0, &D_8027CFF0, 0x32);
}

void func_8023FE80(void *arg0) {
    s32 phi_s1;

    phi_s1 = 1;
    while(1){
        osRecvMesg(&D_8027C108, NULL, 1);
        if (func_8023FFE4(D_8027BF40.unk8[D_8027DCC8 % 3], D_80275848)){
            if(phi_s1 == 0){
                osRecvMesg(&D_8027C140, &D_80275844, 1);
                func_802401C4(D_80275844->unk4);
                D_80275848 = D_80275844->unk4;
            }else{
                phi_s1 += -1;
            }
        }
    }
}

void func_8023FFAC(void){
    D_80275770 = osAiGetLength()/4;
}

void func_8023FFD4(s32 arg0, s32 arg1, s32 arg2){
    return;
}

//amgrHandleFrameMsg
int func_8023FFE4(AudioInfo *arg0, AudioInfo *arg1){
    u32 sp3C;
    Acmd *sp38;
    s32 sp34;
    s32 sp30 = 0;
    f32 pad;

    sp3C = osVirtualToPhysical(arg0->data);
    func_802403F0();
    func_8023FFAC();
    if(arg1){
        sp30 = osAiSetNextBuf(arg1->data, arg1->frameSamples*4);
    }//L8024003C
    if(sp30 == -1){
        func_80247F24(2, 0x7d2);
        func_80247F9C(arg1->frameSamples);
        func_80247F9C(arg0->frameSamples);
        func_802483D8();

    }

    if((D_80275770 >= 0x139)  & !D_80275778){
        arg0->frameSamples = D_8027DD78;
        D_80275778 = 2;
    }
    else{
        arg0->frameSamples = D_8027DD74;
        if(D_80275778)
            D_80275778--;
    }

    if(arg0->frameSamples < D_8027DD78){
        arg0->frameSamples = D_8027DD78;
    }

    sp38 = n_alAudioFrame(D_8027BF40.unk0[D_8027DCD0], &sp34, sp3C, arg0->frameSamples);

    if(D_8027DD80 < sp34){
        func_80247F24(2, 0x7d0);
        func_80247F9C(sp34);
        func_80247F9C(D_8027DD80);
        func_802483D8();
    }

    if(sp34 == 0){
        return 0;
    }else{
        func_802535A8(D_8027BF40.unk0[D_8027DCD0], sp38, &D_8027C140, &arg0->unk8);
        func_80250650();
        D_8027DCD0 ^= 1;
        return 1;
    }
}


#ifndef NONMATCHING //requires .data defined
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_802401C4.s")
#else
//void amgrHandleDoneMsg(AudioInfo *info) from PD repo
void func_802401C4(AudioInfo *info)
{   
    static int D_8027584C = 0;
	if (osAiGetLength() >> 2 == 0 && D_8027584C == FALSE) {
		D_8027584C = FALSE;
	}
}
#endif

#ifndef NONMATCHING
s32 func_80240204(s32 addr, s32 len, void *state);
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D00/func_80240204.s")
#else
s32 func_80240204(s32 addr, s32 len, void *state){
    void *sp44;
    s32 sp40;
    Struct_1D00_3 *sp30;
    Struct_1D00_3 *temp_s0;
    ALLink *temp_s0_2;
    Struct_1D00_3 *temp_s0_3;
    Struct_1D00_3 *temp_v0_2;
    s32 temp_t4;
    s32 temp_v0_3;
    s32 temp_v1;
    u32 temp_a3;
    u32 temp_v0;
    void *temp_t0;
    Struct_1D00_3 *phi_s0;
    Struct_1D00_3 *phi_a2;

    phi_s0 = D_8027D5B0.unk4;
    sp30 = NULL;
    while (temp_s0 != NULL) {
        temp_v0 = phi_s0->unk8;
        if (addr >= temp_v0) {
            sp30 = phi_s0;
            if ((temp_v0 + 0x200) >= (addr + len)) {
                phi_s0->unkC = (s32) D_8027DCC8;
                return osVirtualToPhysical((phi_s0->unk10 + addr) - temp_v0);
            }
            phi_s0 = phi_s0->unk0.next;
        }
    }
    temp_s0_3 = D_8027D5B0.unk8;
    if (temp_s0_3 == NULL) {
        func_80247F24(2, 0x7D1, sp30, addr);
        func_802483D8();
        return osVirtualToPhysical(D_8027D5B0.unk4);
    }
    D_8027D5B0.unk8 = temp_s0_3->unk0.next;
    alUnlink(temp_s0_3);
    if (sp30 != NULL) {
        alLink(temp_s0_3, sp30);
    } else {
        temp_v0_2 = D_8027D5B0.unk4;
        if (temp_v0_2 != NULL) {
            D_8027D5B0.unk4 = temp_s0_3;
            temp_s0_3->unk0.next = (ALLink *)temp_v0_2;
            temp_s0_3->unk0.prev = NULL;
            temp_v0_2->unk0.prev = (ALLink *)temp_s0_3;
        } else {
            D_8027D5B0.unk4 = temp_s0_3;
            temp_s0_3->unk0.next = NULL;
            temp_s0_3->unk0.prev = NULL;
        }
    }
    sp40 = addr & 1;
    sp44 = temp_s0_3->unk10;
    sp40 = temp_v0_3;
    temp_s0_3->unk8 = addr - sp40;
    temp_s0_3->unkC = (s32) D_8027DCC8;
    osPiStartDma(&D_8027D100[D_8027DCCC++], 1, 0, temp_a3, sp44, 0x200U, &D_8027D008);
    return osVirtualToPhysical(sp44) + sp40;
}
#endif

void *func_802403B8(void *state) {
    if (D_8027D5B0.unk0 == 0) {
        D_8027D5B0.unk4 = NULL;
        D_8027D5B0.unk8 = &D_8027D5C0;
        D_8027D5B0.unk0 = 1;
    }
    *(void **)state = &D_8027D5B0;
    return &func_80240204;
}

void func_802403F0(void) {
    u32 phi_s0;
    OSMesg sp40;
    Struct_1D00_3 *phi_s1;
    Struct_1D00_3 *phi_s0_2;

    sp40 = NULL;
    for(phi_s0 = 0; phi_s0 < D_8027DCCC; phi_s0++){
        if (osRecvMesg(&D_8027D008, &sp40, 0) == -1) {
            func_80247F24(2, 0x7D5);
            func_80247F9C(D_8027DCCC);
            func_80247F9C(phi_s0);
            func_802483D8();
        }
    }
    phi_s0_2 = D_8027D5B0.unk4;
    while(phi_s0_2 != NULL){
        phi_s1 = (Struct_1D00_3 *)phi_s0_2->unk0.next;
        if (phi_s0_2->unkC + 1 < D_8027DCC8) {
            if (phi_s0_2 == D_8027D5B0.unk4) {
                D_8027D5B0.unk4 = phi_s0_2->unk0.next;
            }
            alUnlink(phi_s0_2);
            if (D_8027D5B0.unk8 != NULL) {
                alLink(&phi_s0_2->unk0, &D_8027D5B0.unk8->unk0);
            } else {
                D_8027D5B0.unk8 = phi_s0_2;
                phi_s0_2->unk0.next = NULL;
                phi_s0_2->unk0.prev = NULL;
            }
        }
        phi_s0_2 = phi_s1;
    }
    D_8027DCCC = 0;
    D_8027DCC8 += 1;
}

// amgrStopThread
void func_80240538(void){
    if(D_80275774){
        D_80275774 = 0;
        osStopThread(&D_8027BF58);
    }
}

// amgrStartThread
void func_80240570(void){
    if(D_80275774 == 0){
        D_80275774 = 1;
        osStartThread(&D_8027BF58);
    }
}

OSThread * func_802405AC(void){
    return &D_8027BF58;
}

ALHeap * func_802405B8(void){
    return &D_8027CFF0;
}

OSMesgQueue * func_802405C4(void){
    return &D_8027D008;
}

OSIoMesg * func_802405D0(void){
    return &D_8027D0E8;
}

OSMesgQueue * func_802405DC(void){
    return &D_8027C108;
}