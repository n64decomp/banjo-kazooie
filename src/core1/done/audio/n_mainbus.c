#include <ultra64.h>
#include "n_synth.h"

Acmd *n_alMainBusPull( s32 sampleOffset, Acmd *p) 
{
  Acmd        *ptr = p;
  
#ifndef N_MICRO
  aClearBuffer(ptr++, AL_MAIN_L_OUT, FIXED_SAMPLE<<1);
  aClearBuffer(ptr++, AL_MAIN_R_OUT, FIXED_SAMPLE<<1);
#else
  aClearBuffer(ptr++, N_AL_MAIN_L_OUT, N_AL_DIVIDED<<1);
#endif

  ptr = (n_syn->synth.mainBus->filter.handler)(sampleOffset,ptr);

#ifndef N_MICRO
  aSetBuffer(ptr++, 0, 0, 0, FIXED_SAMPLE<<1);
  aMix(ptr++, 0, 0x7fff, AL_AUX_L_OUT, AL_MAIN_L_OUT);
  aMix(ptr++, 0, 0x7fff, AL_AUX_R_OUT, AL_MAIN_R_OUT);
#else
  aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
  aMix(ptr++, 0, 0x7fff, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);
#endif
  
  return ptr;
}

