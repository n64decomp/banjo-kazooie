#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "2.0L/PR/sched.h"
#include "n_libaudio.h"

extern void n_alInit(N_ALGlobals *, ALSynConfig *);

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

typedef struct struct_core1_1D00_5_s{
    struct struct_core1_1D00_5_s * next;
    u8 type;
    // u8 pad5[1];
    u16 unk6;
    u16 unk8;
    union{
        struct{u8 unk0; u8 unk1;}type1;
        struct{f32 unk0;}type80;
    }unkC;
}OscState;

void audioManager_create(void);
void audioManager_handle(void *);
// void func_802403B8(void);
void audioManager_handleDoneMsg(AudioInfo *info);
void *func_802403B8(void *state);
void func_802403F0(void);
void audioManager_startThread(void);


s32 D_80275770 = 0;
s32 D_80275774 = 0;
u8  D_80275778 = 0;
s32 D_8027577C[] = {
    6,      /* number of sections in this effect */
    0x1900, /* total allocated memory */
    /* SECTION 1 */
    0,      /* input */
    0xA0,   /* output */
    900,    /* fbcoef */
    -900,   /* ffcoef */
    500,    /* out gain */
    0x0,    /* no chorus rate */
    0x0,    /* no chorus delay */
    0x0,    /* no low-pass filter */
    /* SECTION 2 */
    0xA0,   /* input */
    0x140,  /* output */
    900,    /* fbcoef */
    -900,   /* ffcoef */
    500,    /* out gain */
    0x0,    /* no chorus rate */
    0x0,    /* no chorus delay */
    0x2500, /* low-pass filter */
    /* SECTION 3 */
    0x320,   /* input */
    0xA00,   /* output */
    13000,   /* fbcoef */
    -13000,  /* ffcoef */
    0xE03,   /* out gain */
    0x0,     /* no chorus rate */
    0x0,     /* no chorus delay */
    0x3000,  /* low-pass filter */
    /* SECTION 4 */
    0xC80,   /* input */
    0x15E0,  /* output */
    13000,   /* fbcoef */
    -13000,  /* ffcoef */
    0xE03,   /* out gain */
    0x0,     /* no chorus rate */
    0x0,     /* no chorus delay */
    0x3500,  /* low-pass filter */
    /* SECTION 5 */
    0xD20,   /* input */
    0x12C0,  /* output */
    0x2000,  /* fbcoef */
    -0x2000, /* ffcoef */
    0x0,     /* no out gain */
    0x0,     /* no chorus rate */
    0x0,     /* no chorus delay */
    0x4000,  /* low-pass filter */
    /* SECTION 6 */
    0x0,     /* input */
    0x1720,  /* output */
    11000,  /* fbcoef */
    -11000, /* ffcoef */
    0x0,     /* no out gain */
    0x17C,   /* chorus rate */
    0xA,     /* chorus delay */
    0x4500   /* low-pass filter */
};

Struct_1D00_2 *D_80275844 = NULL;
AudioInfo *D_80275848 = NULL;
// extern int D_8027584C;//static int D_8027584C = 0;

extern s32 osViClock; //0x80277128

extern f32 D_80277620;
extern f64 D_80277628;
extern f64 D_80277630;
extern f32 D_80277638;

struct {
    Acmd* ACMDList[2];
    AudioInfo *audioInfo[3];
    OSThread thread;
    OSMesgQueue audioFrameMsgQ;
    OSMesg audioFrameMsgBuf[8];
    OSMesgQueue audioReplyMsgQ;
    OSMesg audioReplyMsgBuf[8];
} audioManager;
u8 pad_8027C178[0xE78];
ALHeap D_8027CFF0;
u8 * D_8027D000;
s32  D_8027D004;
OSMesgQueue D_8027D008;
OSMesg D_8027D020[50];
OSIoMesg D_8027D0E8;
Struct_core1_1D00_4 D_8027D100[50];
struct {
    u8 unk0;
    Struct_1D00_3 *unk4;
    Struct_1D00_3 *unk8;
    u8 padC[0x4];
}  D_8027D5B0;
Struct_1D00_3 D_8027D5C0[90];
s32 D_8027DCC8;
s32 D_8027DCCC;
s32 D_8027DCD0;
N_ALGlobals D_8027DCD8;
ALSynConfig D_8027DD50;
s32 D_8027DD74;
s32 D_8027DD78;
s32 D_8027DD7C;
s32 D_8027DD80; 
OscState *freeOscStateList;
OscState oscStates[48];


/* .code */
f32 _depth2Cents(u8 depth)
{
	f32 x = 1.03099298f;
	f32 cents = 1.0f;

	while (depth) {
		if (depth & 1) {
			cents *= x;
		}

		x *= x;
		depth >>= 1;
	}

	return cents;
}

ALMicroTime initOsc(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay, u8 arg6)
{
	OscState *state;
	ALMicroTime result = 0;

	if (freeOscStateList != NULL) {
		state = freeOscStateList;
		freeOscStateList = freeOscStateList->next;
		state->type = oscType;
		*oscState = state;
		result = oscDelay << 14;

		switch (oscType) {
		case 1:
			state->unk8 = 0;
			state->unk6 = 259 - oscRate;
			state->unkC.type1.unk0 = oscDepth >> 1;
			state->unkC.type1.unk1 = 127 - state->unkC.type1.unk0;
			*initVal = state->unkC.type1.unk1;
			break;
		case 0x80:
			state->unkC.type80.unk0 = _depth2Cents(oscDepth);
			state->unk8 = 0;
			state->unk6 = 259 - oscRate;
			*initVal = 1.0f;
			break;
		default:
			break;
		}
	}

	return result;
}

ALMicroTime updateOsc(void *oscState, f32 *updateVal)
{
	f32 sp2c;
	OscState *state = oscState;
	ALMicroTime result = AL_USEC_PER_FRAME;

	switch (state->type) {
	case 0x01:
		state->unk8++;

		if (state->unk8 >= state->unk6) {
			state->unk8 = 0;
		}

		sp2c = (f32)state->unk8 / (f32)state->unk6;
		sp2c = sinf(sp2c * BAD_TAU);
		sp2c = sp2c * state->unkC.type1.unk0;
		*updateVal = state->unkC.type1.unk1 + sp2c;
		break;

	case 0x80:
        state->unk8++;

		if (state->unk8 >= state->unk6) {
			state->unk8 = 0;
		}

		sp2c = (f32)state->unk8 / (f32)state->unk6;
		sp2c = sinf(sp2c * BAD_TAU) * state->unkC.type80.unk0;
		*updateVal = alCents2Ratio(sp2c);
		break;
	default:
		break;
	}

	return result;
}

void stopOsc(OscState *oscState){
    oscState->next = freeOscStateList;
    freeOscStateList = oscState;
}

void func_8023FA64(ALSeqpConfig *arg0) {
	OscState *item;
    s32 i;

    freeOscStateList =  &oscStates[0];
	item = &oscStates[0];
    for(i = 0; i< 0x2F; i++){
        item->next = &oscStates[i+1];
		item = item->next;
    }
    item->next = NULL;
    arg0->initOsc   = initOsc;
    arg0->updateOsc = updateOsc;
    arg0->stopOsc   = stopOsc;
}

void audioManager_init(void){
    D_8027D000 = (u8 *) malloc(0x21000);
    bzero(D_8027D000, 0x21000);
    alHeapInit(&D_8027CFF0, D_8027D000, 0x21000);
    if(osTvType != OS_TV_NTSC)
        osViClock = 0x2e6025c;
    audioManager_create();
    sfxInstruments_init();
    musicInstruments_init();
    audioManager_startThread();
}

void audioManager_create(void) {
    int i;
    f32 var_f0;

    osCreateMesgQueue(&D_8027D008, D_8027D020, 50);
    osCreateMesgQueue(&audioManager.audioReplyMsgQ, audioManager.audioReplyMsgBuf, 8); //audioReplyMesgQueue
    osCreateMesgQueue(&audioManager.audioFrameMsgQ, audioManager.audioFrameMsgBuf, 8);
    var_f0 = 733.333313f;
    D_8027DD74 = (s32)var_f0;
    if ((f32) D_8027DD74 < var_f0) {
        D_8027DD74++;
    }
    D_8027DD74 = ((D_8027DD74 / 0xB8) * 0xB8) + 0xB8;
    D_8027DD78 = D_8027DD74 - 0xB8;
    D_8027DD7C = D_8027DD74;
    D_8027DD50.maxVVoices = 0x18;
    D_8027DD50.maxPVoices = 0x18;
    D_8027DD50.maxUpdates = 0x80;
    D_8027DD50.dmaproc = (void*)func_802403B8;
    D_8027DD50.fxType = AL_FX_CUSTOM;
    D_8027DD50.params = (void*) &D_8027577C;
    D_8027DD50.heap = &D_8027CFF0;
    D_8027DD50.outputRate = osAiSetFrequency(22000);
    n_alInit(&D_8027DCD8, &D_8027DD50);
    D_8027D5C0[0].unk0.prev = NULL;
    D_8027D5C0[0].unk0.next = NULL;
    for(i = 0; i < 89; i++){
        alLink((ALLink *)&D_8027D5C0[i+1], (ALLink *)&D_8027D5C0[i]);
        D_8027D5C0[i].unk10 = alHeapDBAlloc(0, 0, D_8027DD50.heap, 1, 0x200);
    }
    D_8027D5C0[i].unk10 = alHeapDBAlloc(0, 0, D_8027DD50.heap, 1, 0x200);

    for(i = 0; i < 2; i++){
        audioManager.ACMDList[i] = malloc(20000);
    }
    D_8027DD80 = 2500;
    for(i = 0; i < 3; i++){
        audioManager.audioInfo[i] = alHeapDBAlloc(0, 0, D_8027DD50.heap, 1, 0x10);
        audioManager.audioInfo[i]->unk8 = 0;
        audioManager.audioInfo[i]->unkC = audioManager.audioInfo[i];
        audioManager.audioInfo[i]->data = malloc(D_8027DD7C * 4);
    }
    osCreateThread(&audioManager.thread, 4, &audioManager_handle, 0, &D_8027CFF0, 0x32);
}

void audioManager_handle(void *arg0) {
    s32 phi_s1;

    phi_s1 = 1;
    while(1){
        osRecvMesg(&audioManager.audioFrameMsgQ, NULL, OS_MESG_BLOCK);
        if (audioManager_handleFrameMsg(audioManager.audioInfo[D_8027DCC8 % 3], D_80275848)){
            if(phi_s1 == 0){
                osRecvMesg(&audioManager.audioReplyMsgQ, &D_80275844, OS_MESG_BLOCK);
                audioManager_handleDoneMsg(D_80275844->unk4);
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

bool audioManager_handleFrameMsg(AudioInfo *info, AudioInfo *prev_info){
    s16 *outbuffer;
    Acmd *sp38;
    s32 sp34;
    s32 sp30 = 0;
    f32 pad;

    outbuffer = (s16 *)osVirtualToPhysical(info->data);
    func_802403F0();
    func_8023FFAC();
    if(prev_info){
        sp30 = osAiSetNextBuffer(prev_info->data, prev_info->frameSamples*4);
    }//L8024003C
    if(sp30 == -1){
        func_80247F24(2, 0x7d2);
        func_80247F9C(prev_info->frameSamples);
        func_80247F9C(info->frameSamples);
        func_802483D8();

    }

    if((D_80275770 >= 0x139)  & !D_80275778){
        info->frameSamples = D_8027DD78;
        D_80275778 = 2;
    }
    else{
        info->frameSamples = D_8027DD74;
        if(D_80275778)
            D_80275778--;
    }

    if(info->frameSamples < D_8027DD78){
        info->frameSamples = D_8027DD78;
    }

    sp38 = n_alAudioFrame(audioManager.ACMDList[D_8027DCD0], &sp34, outbuffer, info->frameSamples);

    if(D_8027DD80 < sp34){
        func_80247F24(2, 2000);
        func_80247F9C(sp34);
        func_80247F9C(D_8027DD80);
        func_802483D8();
    }

    if(sp34 == 0){
        return 0;
    }else{
        func_802535A8(audioManager.ACMDList[D_8027DCD0], sp38, &audioManager.audioReplyMsgQ, &info->unk8);
        func_80250650();
        D_8027DCD0 ^= 1;
        return 1;
    }
}

void audioManager_handleDoneMsg(AudioInfo *info)
{   
    static int D_8027584C = TRUE;
	if (osAiGetLength() >> 2 == 0 && D_8027584C == FALSE) {
		D_8027584C = FALSE;
	}
}

s32 func_80240204(s32 addr, s32 len, void *state){
    void *sp44;
    s32 sp40;
    Struct_1D00_3 *phi_s0;
    Struct_1D00_3 *phi_v0;
    s32 new_var;
    Struct_1D00_3 *sp30;

    phi_s0 = D_8027D5B0.unk4;
    sp30 = NULL;
    while (phi_s0 != NULL ) {
        new_var = (phi_s0->unk8 + 0x200);
        if ((phi_s0->unk8 > addr)) break;
        
        sp30 = phi_s0;
        if ((addr + len) <= new_var) {
            phi_s0->unkC = (s32) D_8027DCC8;
            return osVirtualToPhysical(phi_s0->unk10 + (addr - phi_s0->unk8));
        }
        phi_s0 = phi_s0->unk0.next;

    }
    phi_s0 = D_8027D5B0.unk8;
    if (phi_s0 == NULL) {
        func_80247F24(2, 0x7D1);
        func_802483D8();
        return osVirtualToPhysical(D_8027D5B0.unk4);
    }
    D_8027D5B0.unk8 = phi_s0->unk0.next;
    alUnlink(phi_s0);
    if (sp30 != NULL) {
        alLink(phi_s0, sp30);
    } else {
        phi_v0 = D_8027D5B0.unk4;
        if (phi_v0 != NULL) {
            D_8027D5B0.unk4 = phi_s0;
            phi_s0->unk0.next = (ALLink *)phi_v0;
            phi_s0->unk0.prev = NULL;
            phi_v0->unk0.prev = (ALLink *)phi_s0;
        } else {
            D_8027D5B0.unk4 = phi_s0;
            phi_s0->unk0.next = NULL;
            phi_s0->unk0.prev = NULL;
        }
    }
    sp44 = phi_s0->unk10;
    sp40 = addr & 1;
    addr -= sp40;
    phi_s0->unk8 = addr;
    phi_s0->unkC = (s32) D_8027DCC8;
    osPiStartDma(&D_8027D100[D_8027DCCC++], 1, 0, addr, sp44, 0x200U, &D_8027D008);
    return osVirtualToPhysical(sp44) + sp40;
}

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

void audioManager_stopThread(void){
    if(D_80275774){
        D_80275774 = 0;
        osStopThread(&audioManager.thread);
    }
}

void audioManager_startThread(void){
    if(D_80275774 == 0){
        D_80275774 = 1;
        osStartThread(&audioManager.thread);
    }
}

OSThread * audioManager_getThread(void){
    return &audioManager.thread;
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

OSMesgQueue * audioManager_getFrameMesgQueue(void){
    return &audioManager.audioFrameMsgQ;
}
