#ifndef __N_AUDIO_INT__
#define __N_AUDIO_INT__
#include <ultra64.h>
#include <n_libaudio.h>
#include "synthInternals.h"

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
    ALLink                 node;
    struct N_ALVoice_s    *vvoice;
    N_ALLoadFilter decoder;
    N_ALResampler resampler;
    N_ALEnvMixer envmixer;
    ALParam		*ctrlList;
    ALParam		*ctrlTail;
    s32          motion;
    s32          offset;
}N_PVoice;

typedef struct audio_0_struct{
    N_ALSynth synth;
    ALPlayer *unk5C;
    ALPlayer *unk60;
    ALPlayer *unk64;
    ALPlayer *unk68;
    ALPlayer *unk6C;
    ALPlayer *unk70;
} AL0s; //modified ALSynth?

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
