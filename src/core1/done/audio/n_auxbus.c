#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_synth.h"

Acmd *n_alAuxBusPull(s32 sampleOffset, Acmd *p) 
{
  Acmd        *ptr = p;
  N_ALAuxBus   *m = (N_ALAuxBus *)n_syn->synth.auxBus;
  N_PVoice    **sources = m->sources;
  s32         i;

#ifndef N_MICRO
  aClearBuffer(ptr++, AL_AUX_L_OUT, FIXED_SAMPLE<<1);
  aClearBuffer(ptr++, AL_AUX_R_OUT, FIXED_SAMPLE<<1);
#else
  aClearBuffer(ptr++, N_AL_AUX_L_OUT, N_AL_DIVIDED<<1);
#endif

  for (i = 0; i < m->sourceCount; i++)
    ptr = n_alEnvmixerPull(sources[i],sampleOffset,ptr);
  return ptr;
}
