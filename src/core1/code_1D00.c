#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "version.h"
#include "PR/sched.h"
#include "n_libaudio.h"

#define DMA_BLOCK_SIZE VER_SELECT(0x200, 0x270, 0x200, 0x200)
#define AUDIO_HEAP_SIZE VER_SELECT(0x21000, 0x23A00, 0x21000, 0x21000)
#define AUDIOMANAGER_THREAD_STACK_SIZE 3704
#define NUM_SAMPLES 184 // n_audio has fixed sample count of 184
#define NUM_OSC_STATES 48
#define NUM_AUDIO_CMDS_PER_SECOND 150000

struct audio_info_mesg_data_s {
    s16 unk0;
    struct audio_info_s *audio_info_ptr;
};

typedef struct audio_info_s {
	s16 *data;          /* Output data pointer */
	s16 frame_samples;  /* number of samples synthesized in this frame */
    struct audio_info_mesg_data_s reply_mesg_data;
} AudioInfo;

struct dma_state_data_s {
    ALLink link;
    u32 unk8; // device address
    u32 unkC;
    void *heap;
};

typedef struct osc_state_s {
    struct osc_state_s *next;
    u8 type;
    u16 unk6; // current value
    u16 unk8; // max value
    union {
        struct { u8 unk0; u8 unk1; } type1;
        struct { f32 cents; } type80;
    } unkC;
} OscState;

void audioManager_create(void);
void audioManagerThread_entry(void *arg);
void audioManager_handleDoneMsg(AudioInfo *info);
ALDMAproc audioManager_DMAInitProc(void *state);
void audioManager_func_802403F0(void);
void audioManager_startThread(void);


s32 D_80275770 = 0;
bool sAudioManagerThreadStarted = FALSE;
u8  D_80275778 = 0;

s32 sEffectsChain[] = {
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

struct audio_info_mesg_data_s *D_80275844 = NULL;
AudioInfo *sPrevFinishedAudioInfo = NULL;

extern s32 osViClock;

struct {
    Acmd *ACMDList[2];
    AudioInfo *audio_info[3];
    OSThread thread;
    OSMesgQueue audioFrameMsgQ;
    OSMesg audioFrameMsgBuf[8];
    OSMesgQueue audioReplyMsgQ;
    OSMesg audioReplyMsgBuf[8];
    u8 thread_stack[AUDIOMANAGER_THREAD_STACK_SIZE];
} audioManager;
ALHeap sALHeapInfo;
u8 *sALHeapBuffer;
s32 pad_8027D004;
OSMesgQueue audioDMANotifyMsgQ;
OSMesg audioDMANotifyMsgBuf[3000 / FRAMERATE];
OSIoMesg sExtraDMAMesg;
OSIoMesg sDMAMesgBlocks[3000 / FRAMERATE];
struct {
    u8 initialized;
    struct dma_state_data_s *unk4;
    struct dma_state_data_s *unk8;
} sDMAState;
struct dma_state_data_s sDMAStateData[90];
s32 sAudioInfoID;
s32 sNumDMATransfers; // DMA IO Message blocks index
s32 sCmdBufferIndex;
N_ALGlobals sn_alGlobals;
ALSynConfig sn_alConfig;
s32 sFrameSize;
s32 sMinFrameSize;
s32 sMaxFrameSize;
s32 sNumAudioCmdsPerFrame; 
OscState *freeOscStateList;
OscState oscStates[NUM_OSC_STATES];

f32 depth2Cents(u8 depth) {
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

ALMicroTime initOsc(void **oscState, f32 *initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay) {
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
                state->unkC.type80.cents = depth2Cents(oscDepth);
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

ALMicroTime updateOsc(void *oscState, f32 *updateVal) {
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
            sp2c = sinf(sp2c * BAD_TAU) * state->unkC.type80.cents;
            *updateVal = alCents2Ratio(sp2c);
            break;
        default:
            break;
	}

	return result;
}

void stopOsc(OscState *oscState) {
    oscState->next = freeOscStateList;
    freeOscStateList = oscState;
}

void audioManager_setupSeqp(ALSeqpConfig *config) {
	OscState *item;
    int i;

    freeOscStateList = &oscStates[0];
	item = &oscStates[0];
    for (i = 0; i < NUM_OSC_STATES - 1; i++) {
        item->next = &oscStates[i + 1];
		item = item->next;
    }
    item->next = NULL;

    config->initOsc = initOsc;
    config->updateOsc = updateOsc;
    config->stopOsc = stopOsc;
}

void audioManager_init(void) {
    sALHeapBuffer = malloc(AUDIO_HEAP_SIZE);
    bzero(sALHeapBuffer, AUDIO_HEAP_SIZE);
    alHeapInit(&sALHeapInfo, sALHeapBuffer, AUDIO_HEAP_SIZE);
#if VERSION == VERSION_USA_1_0
    if (osTvType != OS_TV_NTSC)
        osViClock = VI_MPAL_CLOCK;
#elif VERSION == VERSION_PAL
    osViClock = VI_PAL_CLOCK;
#endif
    audioManager_create();
    sfxInstruments_init();
    musicInstruments_init();
    audioManager_startThread();
}

void audioManager_create(void) {
    int i;
    f32 fsize;

    osCreateMesgQueue(&audioDMANotifyMsgQ, audioDMANotifyMsgBuf, 3000 / FRAMERATE);
    osCreateMesgQueue(&audioManager.audioReplyMsgQ, audioManager.audioReplyMsgBuf, 8);
    osCreateMesgQueue(&audioManager.audioFrameMsgQ, audioManager.audioFrameMsgBuf, 8);

    fsize = 44000.0f / FRAMERATE;
    sFrameSize = fsize;
    if (sFrameSize < fsize) {
        sFrameSize++;
    }
    sFrameSize = ((sFrameSize / NUM_SAMPLES) + 1) * NUM_SAMPLES;
    sMinFrameSize = sFrameSize - NUM_SAMPLES;
    sMaxFrameSize = sFrameSize;

    sn_alConfig.maxVVoices = 24;
    sn_alConfig.maxPVoices = 24;
    sn_alConfig.maxUpdates = 128;
    sn_alConfig.dmaproc = audioManager_DMAInitProc;
    sn_alConfig.fxType = AL_FX_CUSTOM;
    sn_alConfig.params = sEffectsChain;
    sn_alConfig.heap = &sALHeapInfo;
    sn_alConfig.outputRate = osAiSetFrequency(22000);
    n_alInit(&sn_alGlobals, &sn_alConfig);

    sDMAStateData[0].link.prev = NULL;
    sDMAStateData[0].link.next = NULL;

    for (i = 0; i < 89; i++) {
        alLink(&sDMAStateData[i + 1].link, &sDMAStateData[i].link);
        sDMAStateData[i].heap = alHeapDBAlloc(0, 0, sn_alConfig.heap, 1, DMA_BLOCK_SIZE);
    }

    sDMAStateData[i].heap = alHeapDBAlloc(0, 0, sn_alConfig.heap, 1, DMA_BLOCK_SIZE);

    for (i = 0; i < 2; i++) {
        audioManager.ACMDList[i] = malloc(NUM_AUDIO_CMDS_PER_SECOND * sizeof(Acmd) / FRAMERATE);
    }

    sNumAudioCmdsPerFrame = NUM_AUDIO_CMDS_PER_SECOND / FRAMERATE;

    for (i = 0; i < 3; i++) {
        audioManager.audio_info[i] = alHeapDBAlloc(0, 0, sn_alConfig.heap, 1, sizeof(AudioInfo));
        audioManager.audio_info[i]->reply_mesg_data.unk0 = 0;
        audioManager.audio_info[i]->reply_mesg_data.audio_info_ptr = audioManager.audio_info[i];
        audioManager.audio_info[i]->data = malloc(4 * sMaxFrameSize);
    }

    osCreateThread(&audioManager.thread, 4, &audioManagerThread_entry, 0, audioManager.thread_stack + AUDIOMANAGER_THREAD_STACK_SIZE, 50);
}

void audioManagerThread_entry(void *arg) {
    s32 skip_handle_done_mesg = 1;

    while (TRUE) {
        osRecvMesg(&audioManager.audioFrameMsgQ, NULL, OS_MESG_BLOCK);
        if (audioManager_handleFrameMsg(audioManager.audio_info[sAudioInfoID % 3], sPrevFinishedAudioInfo)) {
            if (skip_handle_done_mesg == 0) {
                osRecvMesg(&audioManager.audioReplyMsgQ, (OSMesg) &D_80275844, OS_MESG_BLOCK);
                audioManager_handleDoneMsg(D_80275844->audio_info_ptr);
                sPrevFinishedAudioInfo = D_80275844->audio_info_ptr;
            } else {
                skip_handle_done_mesg--;
            }
        }
    }
}

void audioManager_func_8023FFAC(void) {
    D_80275770 = osAiGetLength() / 4;
}

void audioManager_func_8023FFD4(s32 arg0, s32 arg1, s32 arg2) {}

bool audioManager_handleFrameMsg(AudioInfo *info, AudioInfo *prev_info){
    s16 *outbuffer;
    Acmd *command_list_end;
    s32 command_list_len;
    s32 ret;
    f32 pad;

#if VERSION == VERSION_USA_1_0
    ret = 0;
#endif

    outbuffer = (s16 *) osVirtualToPhysical(info->data);
    audioManager_func_802403F0();
    audioManager_func_8023FFAC();
    if (prev_info) {
        ret = osAiSetNextBuffer(prev_info->data, 4 * prev_info->frame_samples);
    }

#if VERSION == VERSION_USA_1_0
    if (ret == -1) {
        gcdebugText_showLargeValue(2, 2002);
        gcdebugText_showValue(prev_info->frame_samples);
        gcdebugText_showValue(info->frame_samples);
        gcdebugText_pauseThread();
    }    
#endif

    if ((D_80275770 > 312) & !D_80275778) {
        info->frame_samples = sMinFrameSize;
        D_80275778 = 2;
    } else {
        info->frame_samples = sFrameSize;
        if (D_80275778)
            D_80275778--;
    }

    if (info->frame_samples < sMinFrameSize) {
        info->frame_samples = sMinFrameSize;
    }

    command_list_end = n_alAudioFrame(audioManager.ACMDList[sCmdBufferIndex], &command_list_len, outbuffer, info->frame_samples);

#if VERSION == VERSION_USA_1_0
    if (sNumAudioCmdsPerFrame < command_list_len) {
        gcdebugText_showLargeValue(2, 2000);
        gcdebugText_showValue(command_list_len);
        gcdebugText_showValue(sNumAudioCmdsPerFrame);
        gcdebugText_pauseThread();
    }
#endif

    if (command_list_len == 0) {
        return FALSE;
    } else {
        core1_15B30_addAudioTaskData(audioManager.ACMDList[sCmdBufferIndex], command_list_end, &audioManager.audioReplyMsgQ, (OSMesg) &info->reply_mesg_data);
        func_80250650();
        sCmdBufferIndex ^= 1;
        return TRUE;
    }
}

void audioManager_handleDoneMsg(AudioInfo *info) {   
    static bool debug_var = TRUE;

	if ((osAiGetLength() / 4) == 0 && (!debug_var)) {
		debug_var = FALSE;
	}
}

s32 func_80240204(s32 addr, s32 len, void *state) {
    void *dest_vaddr;
    s32 dev_addr_low_bit;
    s32 dev_addr_end;
    struct dma_state_data_s *phi_s0, *phi_v0, *sp30;

#if VERSION == VERSION_PAL
    phi_v0 = sDMAState.unk4;
#endif
    sp30 = NULL;

#if VERSION == VERSION_USA_1_0
    for (phi_s0 = sDMAState.unk4; phi_s0 != NULL; phi_s0 = (struct dma_state_data_s *) phi_s0->link.next) {
#elif VERSION == VERSION_PAL
    for (phi_s0 = phi_v0; phi_s0 != NULL; phi_s0 = (struct dma_state_data_s *) phi_s0->link.next) {
#endif
        dev_addr_end = phi_s0->unk8 + DMA_BLOCK_SIZE;

        if (phi_s0->unk8 > addr) {
            break;
        }
        
        sp30 = phi_s0;

        if ((addr + len) <= dev_addr_end) {
            phi_s0->unkC = sAudioInfoID;
#if VERSION == VERSION_USA_1_0
            return osVirtualToPhysical((u8 *) phi_s0->heap + (addr - phi_s0->unk8));
#elif VERSION == VERSION_PAL
            dev_addr_low_bit = (s32) (u8 *) phi_s0->heap + (addr - phi_s0->unk8);
            return osVirtualToPhysical((void *) dev_addr_low_bit);
#endif
        }
    }

    phi_s0 = sDMAState.unk8;
    if (phi_s0 == NULL) {
#if VERSION == VERSION_USA_1_0
        gcdebugText_showLargeValue(2, 2001);
        gcdebugText_pauseThread();
        return osVirtualToPhysical(sDMAState.unk4);
#elif VERSION == VERSION_PAL
        return osVirtualToPhysical(phi_v0);
#endif
    }

    sDMAState.unk8 = (struct dma_state_data_s *) phi_s0->link.next;
    alUnlink(&phi_s0->link);

    if (sp30 != NULL) {
        alLink(&phi_s0->link, &sp30->link);
    } else {
        phi_v0 = sDMAState.unk4;
        if (phi_v0 != NULL) {
            sDMAState.unk4 = phi_s0;
            phi_s0->link.next = (ALLink *) phi_v0;
            phi_s0->link.prev = NULL;
            phi_v0->link.prev = (ALLink *) phi_s0;
        } else {
            sDMAState.unk4 = phi_s0;
            phi_s0->link.next = NULL;
            phi_s0->link.prev = NULL;
        }
    }

    dest_vaddr = phi_s0->heap;
    dev_addr_low_bit = addr & 1;
    addr -= dev_addr_low_bit;
    phi_s0->unk8 = addr;
    phi_s0->unkC = sAudioInfoID;
    osPiStartDma(&sDMAMesgBlocks[sNumDMATransfers++], OS_MESG_PRI_HIGH, OS_READ, addr, dest_vaddr, DMA_BLOCK_SIZE, &audioDMANotifyMsgQ);
    return osVirtualToPhysical(dest_vaddr) + dev_addr_low_bit;
}

ALDMAproc audioManager_DMAInitProc(void *state) {
    if (!sDMAState.initialized) {
        sDMAState.unk4 = NULL;
        sDMAState.unk8 = sDMAStateData;
        sDMAState.initialized = TRUE;
    }
    *(void **)state = (void *) &sDMAState;
    return func_80240204;
}

void audioManager_func_802403F0(void) {
    u32 i;
    OSMesg temp_mesg = NULL;
    struct dma_state_data_s *phi_s1;
    struct dma_state_data_s *phi_s0_2;

    for (i = 0; i < sNumDMATransfers; i++) {
#if VERSION == VERSION_USA_1_0
        if (osRecvMesg(&audioDMANotifyMsgQ, &temp_mesg, OS_MESG_NOBLOCK) == -1) {
            gcdebugText_showLargeValue(2, 2005);
            gcdebugText_showValue(sNumDMATransfers);
            gcdebugText_showValue(i);
            gcdebugText_pauseThread();
        }
#else
        osRecvMesg(&audioDMANotifyMsgQ, &temp_mesg, OS_MESG_NOBLOCK);
#endif
    }

    phi_s0_2 = sDMAState.unk4;

    while (phi_s0_2 != NULL) {
        phi_s1 = (struct dma_state_data_s *) phi_s0_2->link.next;
        if (phi_s0_2->unkC + 1 < sAudioInfoID) {
            if (phi_s0_2 == sDMAState.unk4) {
                sDMAState.unk4 = (struct dma_state_data_s *)phi_s0_2->link.next;
            }
            alUnlink(&phi_s0_2->link);
            if (sDMAState.unk8 != NULL) {
                alLink(&phi_s0_2->link, &sDMAState.unk8->link);
            } else {
                sDMAState.unk8 = phi_s0_2;
                phi_s0_2->link.next = NULL;
                phi_s0_2->link.prev = NULL;
            }
        }
        phi_s0_2 = phi_s1;
    }

    sNumDMATransfers = 0;
    sAudioInfoID++;
}

#if VERSION == VERSION_PAL
OSThread *audioManager_getThread_PAL(void) {
    return &audioManager.thread;
}
#endif

void audioManager_stopThread(void) {
    if (sAudioManagerThreadStarted) {
        sAudioManagerThreadStarted = FALSE;
        osStopThread(&audioManager.thread);
    }
}

void audioManager_startThread(void) {
    if (!sAudioManagerThreadStarted) {
        sAudioManagerThreadStarted = TRUE;
        osStartThread(&audioManager.thread);
    }
}

OSThread *audioManager_getThread(void) {
    return &audioManager.thread;
}

ALHeap *audioManager_getALHeapInfo(void) {
    return &sALHeapInfo;
}

OSMesgQueue *audioManager_getDMANotifyMesgQueue(void) {
    return &audioDMANotifyMsgQ;
}

OSIoMesg *audioManager_getExtraDMAMesg(void) {
    return &sExtraDMAMesg;
}

OSMesgQueue *audioManager_getFrameMesgQueue(void) {
    return &audioManager.audioFrameMsgQ;
}
