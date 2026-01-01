#include <ultra64.h>
#include "n_synth.h"

Acmd *n_alSavePull( s32 sampleOffset, Acmd *p) 
{
    Acmd        *ptr = p;

    ptr = n_alMainBusPull(sampleOffset, ptr);
    
#ifndef N_MICRO
    aSetBuffer (ptr++, 0, 0, 0, FIXED_SAMPLE<<1);
    aInterleave(ptr++, AL_MAIN_L_OUT, AL_MAIN_R_OUT);
    aSetBuffer (ptr++, 0, 0, 0, FIXED_SAMPLE<<2);
    aSaveBuffer(ptr++, n_syn->sv_dramout);
#else
#include "n_save_add01.c_"
#endif
    return ptr;
}
