#include <ultra64.h>
#include "n_synth.h"

#ifdef AUD_PROFILE
extern u32 cnt_index, resampler_num, resampler_cnt, resampler_max, resampler_min, lastCnt[];
#endif

/***********************************************************************
 * Resampler filter public interfaces
 ***********************************************************************/
Acmd *n_alResamplePull(N_PVoice *e, s16 *outp, Acmd *p) 
{
    Acmd        *ptr = p;
    s16         inp;
    s32         inCount;
    s32		incr;
    f32         finCount;
    
#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

#ifndef N_MICRO
    inp = AL_DECODER_OUT;
#else
    inp = N_AL_DECODER_OUT;
#endif
    
    /*
     * check if resampler is required
     */
    if (e->rs_upitch) {

	ptr = n_alAdpcmPull(e, &inp, FIXED_SAMPLE, p);
	aDMEMMove(ptr++, inp, *outp , FIXED_SAMPLE<<1);

    } else {

        /*
	 * clip to maximum allowable pitch
	 * FIXME: should we check for some minimum as well?
	 */
	if (e->rs_ratio > MAX_RATIO) e->rs_ratio = MAX_RATIO;

	/*
	 * quantize the pitch
	 */
	e->rs_ratio = (s32)(e->rs_ratio * UNITY_PITCH);
	e->rs_ratio = e->rs_ratio / UNITY_PITCH;

	/*
	 * determine how many samples to generate
	 */
	finCount = e->rs_delta + (e->rs_ratio * (f32)FIXED_SAMPLE);
	inCount = (s32) finCount;
	e->rs_delta = finCount - (f32)inCount;

	/*
	 * ask all filters upstream from us to build their command
	 * lists.
	 */
	ptr = n_alAdpcmPull(e, &inp, inCount, p);

	/*
	 * construct our portion of the command list
	 */
	incr = (s32)(e->rs_ratio * UNITY_PITCH);
#ifndef N_MICRO
	aSetBuffer(ptr++, 0, inp , *outp,  FIXED_SAMPLE<<1);
	aResample(ptr++, e->rs_first, incr, osVirtualToPhysical(e->rs_state));
#else
#include "n_resample_add01.c_"
#endif
	e->rs_first = 0;
    }
    
#ifdef AUD_PROFILE
    PROFILE_AUD(resampler_num, resampler_cnt, resampler_max, resampler_min);
#endif
    return ptr;
}

s32 n_alResampleParam(N_PVoice *filter, s32 paramID, void *param)
{
    N_PVoice   *r = filter;
    union {
        f32             f;
        s32             i;
    } data;
    
    switch (paramID) {
#if 0
        case (AL_FILTER_RESET):
            r->rs_delta  = 0.0;
            r->rs_first  = 1;
            r->rs_upitch = 0;
	    n_alLoadParam(filter, AL_FILTER_RESET, 0);
            break;
        case (AL_FILTER_START):
	    n_alLoadParam(filter, AL_FILTER_START, 0);
            break;
        case (AL_FILTER_SET_PITCH):
            data.i = (s32) param;
            r->rs_ratio = data.f;
            break;
	case (AL_FILTER_SET_UNITY_PITCH):
	    r->rs_upitch = 1;
            break;
#endif            
        default:
	    n_alLoadParam(filter,  paramID, param);
            break;
    }
    return 0;
}

