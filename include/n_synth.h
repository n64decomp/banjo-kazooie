#ifndef __N_AUDIO_INT__
#define __N_AUDIO_INT__
#include <ultra64.h>
#include <n_libaudio.h>
#include "synthInternals.h"
#include <n_abi.h>

#define SAMPLES               184
#define SAMPLE184(delta)      (((delta) + (SAMPLES / 2)) / SAMPLES) * SAMPLES
#define FIXED_SAMPLE          SAMPLES

#define N_AL_DECODER_IN	        0
#define	N_AL_RESAMPLER_OUT	0
#define N_AL_TEMP_0	        0
#define	N_AL_DECODER_OUT        368
#define	N_AL_TEMP_1	        368
#define	N_AL_TEMP_2	        736
#define	N_AL_MAIN_L_OUT	        1248
#define	N_AL_MAIN_R_OUT	        1616
#define	N_AL_AUX_L_OUT	        1984
#define	N_AL_AUX_R_OUT	        2352

#define N_AL_DIVIDED            368

typedef struct N_ALLoadFilter_s{
    //ALFilter                    filter;
    ADPCM_STATE                 *state; //0xC
    ADPCM_STATE                 *lstate; //0x10
    ALRawLoop                   loop; //0x14
    struct ALWaveTable_s        *table; //0x20
    s32                         bookSize;
    ALDMAproc                   dma;
    void                        *dmaState;
    s32                         sample;
    s32                         lastsam;
    s32                         first;
    s32                         memin; 
} N_ALLoadFilter;

typedef struct N_ALResampler_s {
    //ALFilter            filter;
    RESAMPLE_STATE      *state;
    f32                 ratio;
    s32			upitch;
    f32		        delta;
    s32			first;
} N_ALResampler;

typedef struct N_ALEnvMixer_s {
    ENVMIX_STATE    *state;
    s16         pan;
    s16         volume;
    s16         cvolL;
    s16         cvolR;
    s16         dryamt;
    s16         wetamt;
    u16         lratl;
    s16         lratm;
    s16         ltgt;
    u16         rratl;
    s16         rratm;
    s16         rtgt;
    s32         delta;
    s32         segEnd;
    s32         first;
} N_ALEnvMixer;


typedef struct N_PVoice_s {
    ALLink               node;
    struct N_ALVoice_s    *vvoice;
/** ALLoadFilter *********************************/
    ADPCM_STATE                 *dc_state;
    ADPCM_STATE                 *dc_lstate;
    ALRawLoop                   dc_loop;
    struct ALWaveTable_s        *dc_table;
    s32                         dc_bookSize;
    ALDMAproc                   dc_dma;
    void                        *dc_dmaState;
    s32                         dc_sample;
    s32                         dc_lastsam;
    s32                         dc_first;
    s32                         dc_memin; 
/** ALResampler *********************************/
    RESAMPLE_STATE      *rs_state;
    f32                 rs_ratio;
    s32			rs_upitch;
    f32		        rs_delta;
    s32			rs_first;
/** ALEnvMixer *********************************/
    ENVMIX_STATE	*em_state;
    s16		        em_pan;
    s16		        em_volume;
    s16		        em_cvolL;
    s16		        em_cvolR;
    s16		        em_dryamt;
    s16		        em_wetamt;
    u16                 em_lratl;
    s16                 em_lratm;
    s16                 em_ltgt;
    u16                 em_rratl;
    s16                 em_rratm;
    s16                 em_rtgt;
    s32                 em_delta;
    s32                 em_segEnd;
    s32			em_first;
    ALParam		*em_ctrlList;
    ALParam		*em_ctrlTail;
    s32                 em_motion;
    s32                 offset;
} N_PVoice;

typedef struct audio_0_struct{
    N_ALSynth synth;
    ALPlayer *unk5C;
    ALPlayer *unk60;
    ALPlayer *unk64;
    ALPlayer *unk68;
    ALPlayer *unk6C;
    ALPlayer *unk70;
} AL0s; //modified ALSynth?

#define N_AL_MAX_RSP_SAMPLES      184


typedef Acmd *(*N_ALCmdHandler)(s32, Acmd *);

typedef struct N_ALFilter_s {
    struct N_ALFilter_s   *source;
    N_ALCmdHandler        handler;
    ALSetParam          setParam;
    s16                 inp;
    s16                 outp;
    s32                 type;
} N_ALFilter;


typedef struct N_ALMainBus_s {
    N_ALFilter           filter;
} N_ALMainBus;

typedef struct N_ALAuxBus_s {
    ALFilter            filter;
    s32                 sourceCount;
    s32                 maxSources;
    N_PVoice           **sources;
    ALFx                *fx;
    ALFx		*fx_array[AL_MAX_AUX_BUS_SOURCES];
} N_ALAuxBus;

extern AL0s *n_syn;

/*
 * prototypes for private driver functions
 */
ALParam         *__n_allocParam(void);
void            __n_freeParam(ALParam *param);
void            _n_freePVoice(N_PVoice *pvoice);
void            _n_collectPVoices();

s32             _n_timeToSamples(s32 micros);
ALMicroTime     _n_samplesToTime(s32 samples);

int n_alEnvmixerResampleParam(N_PVoice *v, s32 paramId, void* param);
//n_alLoadParam
int n_alLoadParam(N_PVoice *v, s32 paramId, void* param);
#endif
