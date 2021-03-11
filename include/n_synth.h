#ifndef __N_AUDIO_INT__
#define __N_AUDIO_INT__
#include <ultra64.h>
#include <n_libaudio.h>
#include "synthInternals.h"

typedef struct N_PVoice_s {
    // ALLink               node;
    // struct ALVoice_s    *vvoice;
    // ALFilter            *channelKnob;
    // ALLoadFilter        decoder;
    // ALResampler         resampler;
    // ALEnvMixer          envmixer;
    // s32                 offset;

    ALLink                 node;
    u8                     pad8[0x80];
    s32                    offset;
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

extern AL0s *D_80276E84;

/*
 * prototypes for private driver functions
 */
ALParam         *__n_allocParam(void);
void            __n_freeParam(ALParam *param);
void            _n_freePVoice(N_PVoice *pvoice);
void            _n_collectPVoices();

s32             _n_timeToSamples(s32 micros);
ALMicroTime     _n_samplesToTime(s32 samples);



#endif