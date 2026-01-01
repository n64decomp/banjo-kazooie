#include <ultra64.h>
#include "n_synth.h"
#include "functions.h"
#include "variables.h"
#include "assert.h"

#ifdef AUD_PROFILE
extern u32 cnt_index, env_num, env_cnt, env_max, env_min, lastCnt[];
extern u32 rate_num, rate_cnt, rate_max, rate_min;
extern u32 vol_num, vol_cnt, vol_max, vol_min;
#endif

#define EQPOWER_LENGTH 128
static s16 eqpower[ EQPOWER_LENGTH ] = {
    32767,  32764,  32757,  32744,  32727,  32704,
    32677,  32644,  32607,  32564,  32517,  32464,
    32407,  32344,  32277,  32205,  32127,  32045,
    31958,  31866,  31770,  31668,  31561,  31450,
    31334,  31213,  31087,  30957,  30822,  30682,
    30537,  30388,  30234,  30075,  29912,  29744,
    29572,  29395,  29214,  29028,  28838,  28643,
    28444,  28241,  28033,  27821,  27605,  27385,
    27160,  26931,  26698,  26461,  26220,  25975,
    25726,  25473,  25216,  24956,  24691,  24423,
    24151,  23875,  23596,  23313,  23026,  22736,
    22442,  22145,  21845,  21541,  21234,  20924,
    20610,  20294,  19974,  19651,  19325,  18997,
    18665,  18331,  17993,  17653,  17310,  16965,
    16617,  16266,  15913,  15558,  15200,  14840,
    14477,  14113,  13746,  13377,  13006,  12633,
    12258,  11881,  11503,  11122,  10740,  10357,
    9971,   9584,   9196,   8806,   8415,   8023,
    7630,   7235,   6839,   6442,   6044,   5646,
    5246,   4845,   4444,   4042,   3640,   3237,
    2833,   2429,   2025,   1620,   1216,    810,
    405,      0
};

extern	f64	__pow(f64, f64);

/*
 * prototypes for private enveloper functions
 */
static  Acmd *__n_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount, Acmd *p) ; //__n_pullSubFrame
static  s16 __n_getRate(f64 vol, f64 tgt, s32 count, u16* ratel); //_getRate

static  s16 __n_getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel);

/***********************************************************************
 * Enveloper filter public interfaces
 ***********************************************************************/
Acmd *n_alEnvmixerPull(void *filter, s32 sampleOffset,  Acmd *p) 
{
    Acmd        *ptr = p;
    N_PVoice	*e = (N_PVoice *)filter;
    s16         inp;
    s32         lastOffset;
    s32         thisOffset = sampleOffset;
    s32         samples;
    s16         loutp = 0;
    s32         fVol;
    int         count = 0xb8;
    s32         outCount = count;
    ALParam     *thisParam;
    
#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

    /*
     * Force the input to be the resampler output
     */
    inp = AL_RESAMPLER_OUT;

    while (e->em_ctrlList != 0) {
            
        lastOffset = thisOffset;
        thisOffset = ((e->em_ctrlList->delta + 0x5C)/count)*count;
        samples    = thisOffset - lastOffset;
        if (samples > outCount)
            break;
        
        if(samples < 0){
            samples = 0;
        }

        
        switch (e->em_ctrlList->type) {
          case (AL_FILTER_START_VOICE_ALT):
              {                  
                  ALStartParamAlt *param = (ALStartParamAlt *)e->em_ctrlList;
                  
                  if (param->unity) {
                      e->rs_upitch = 1;
                  }
                  n_alLoadParam(e, AL_FILTER_SET_WAVETABLE, param->wave);
                  
                  e->em_motion = 1;
                  e->em_first  = 1;

                  e->em_delta  = 0;
                  e->em_segEnd = ((param->samples + 0x5C)/count)*count;
                  fVol = (param->volume + param->volume)/2;
                  e->em_volume = fVol;
                  e->em_pan    = param->pan;
                  e->em_dryamt = eqpower[param->fxMix];
                  e->em_wetamt = eqpower[EQPOWER_LENGTH - param->fxMix - 1];
                  
                  if (param->samples) {
                      e->em_cvolL  = 1;
                      e->em_cvolR  = 1;
                  } else {
                      /*
                       * Attack time is zero. Simply set the
                       * volume. We don't want an attack segment.
                       */
                      e->em_cvolL = (e->em_volume * eqpower[e->em_pan]) >> 15;
                      e->em_cvolR = (e->em_volume *
                                  eqpower[EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
                  }

                  e->rs_ratio = param->pitch;                  
              }
              
              break;
                
          case (AL_FILTER_SET_FXAMT):
          case (AL_FILTER_SET_PAN):
          case (AL_FILTER_SET_VOLUME):
	      ptr = __n_pullSubFrame(e, &inp, &loutp, samples, ptr);
            
              if (e->em_delta >= e->em_segEnd){
                  /*
                   * We should have reached our target, calculate
                   * target in case e->segEnd was 0
                   */
                  e->em_ltgt = (e->em_volume * eqpower[e->em_pan]) >> 15;
                  e->em_rtgt = (e->em_volume *
                             eqpower[EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
                  e->em_delta = e->em_segEnd;   /* To prevent overflow */
                  e->em_cvolL = e->em_ltgt;
                  e->em_cvolR = e->em_rtgt;
              } else {
                  /* 
                   * Estimate the current volume
                   */
                  e->em_cvolL = __n_getVol(e->em_cvolL, e->em_delta, e->em_lratm, e->em_lratl);
                  e->em_cvolR = __n_getVol(e->em_cvolR, e->em_delta, e->em_rratm, e->em_rratl);
              }
    
              /*
               * We can't have volume of zero, because the envelope
               * would never go anywhere from there
               */
              if( e->em_cvolL == 0 ) e->em_cvolL = 1;
              if( e->em_cvolR == 0 ) e->em_cvolR = 1;

              if (e->em_ctrlList->type == AL_FILTER_SET_PAN)

                  /*
                   * This should result in a change to the current
                   * segment rate and target
                   */
                  e->em_pan = (s16) e->em_ctrlList->data.i;

              if (e->em_ctrlList->type == AL_FILTER_SET_VOLUME){
                s32 Vol;
                  /*
                   * Switching to a new segment
                   */
                  e->em_delta = 0;
                
                  /*
                   * Map volume non-linearly to give something close to
                   * loudness
                   */
                  Vol = e->em_ctrlList->data.i;
                  Vol+= Vol;
                  Vol /= 2;
                  e->em_volume = Vol;

                  e->em_segEnd = ((e->em_ctrlList->moredata.i + 0x5C)/count)*count;

              }
            
              if (e->em_ctrlList->type == AL_FILTER_SET_FXAMT){
                  e->em_dryamt = eqpower[e->em_ctrlList->data.i];
                  e->em_wetamt = eqpower[EQPOWER_LENGTH - e->em_ctrlList->data.i - 1];
              }
            
              /*
               * Force a volume update
               */
              e->em_first = 1;
              break;

          case (AL_FILTER_START_VOICE):
              {
                  ALStartParam *p = (ALStartParam *)e->em_ctrlList;
                  
                  /*
                   * Changing to PLAYING (since the previous state was
                   * persumable STOPPED, we'll just bump the output
                   * pointer rather than pull a subframe of zeros).
                   */
                    if (p->unity) {
                        e->rs_upitch = 1;
                    }
                  
                n_alLoadParam(e, AL_FILTER_SET_WAVETABLE, p->wave);
                e->em_motion = 1;
              }
              break;
              
            case (AL_FILTER_STOP_VOICE):
            {
                  /*
                   * Changing to STOPPED and reset the filter
                   */
                ptr = __n_pullSubFrame(e, &inp, &loutp, samples,  ptr);
                 n_alEnvmixerParam(e, 4, 0);
            }
            break;

            
            case (AL_FILTER_FREE_VOICE):
                {                  
                  ALFreeParam *param = (ALFreeParam *)e->em_ctrlList;
                  ((N_PVoice *)(param->pvoice))->offset = 0;
                  _n_freePVoice((PVoice *)param->pvoice);
                }
                break;
            
            case 7:
                ptr = __n_pullSubFrame(e, &inp, &loutp, samples, ptr);
                e->rs_ratio = e->em_ctrlList->data.f;
                break;
            
            case 8:
                ptr = __n_pullSubFrame(e, &inp, &loutp, samples, ptr);
                e->rs_upitch = 1;
                break;
                    
            case (AL_FILTER_SET_WAVETABLE):
                ptr = __n_pullSubFrame(e, &inp, &loutp, samples, ptr);
                n_alLoadParam(e, AL_FILTER_SET_WAVETABLE, e->em_ctrlList->data.i);
                break;
            
            default:
              /*
               * Pull the reuired number of samples and then pass the message
               * on down the chain
               */
	            ptr = __n_pullSubFrame(e, &inp, &loutp, samples, ptr);
               n_alEnvmixerParam(e, e->em_ctrlList->type, e->em_ctrlList->data.i);
              break;
        }
        loutp  += (samples<<1);
        outCount -= samples;

        /*
         * put the param record back on the free list
         */
        thisParam = e->em_ctrlList;
        e->em_ctrlList = e->em_ctrlList->next;
        if (e->em_ctrlList == 0)
            e->em_ctrlTail = 0;
        
        __n_freeParam(thisParam);
        
    }
    
    ptr = __n_pullSubFrame(e, &inp, &loutp, outCount, ptr);

    /*
     * Prevent overflow in e->delta
     */
    if (e->em_delta > e->em_segEnd)
        e->em_delta = e->em_segEnd;

#ifdef AUD_PROFILE
    PROFILE_AUD(env_num, env_cnt, env_max, env_min);
#endif
    return ptr;
}

static
Acmd* __n_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount, Acmd *p) 
{
    Acmd        *ptr = p;
    N_PVoice	*e = (N_PVoice *)filter;
    s32 sp68 = 0xb8;
    
    /* filter must be playing and request non-zero output samples to pull. */
    if (e->em_motion != AL_PLAYING || !outCount)
        return ptr;

    /*
     * ask all filters upstream from us to build their command
     * lists.
     */
    ptr = n_alResamplePull(e, inp, ptr);
    
    /*
     * construct our portion of the command list
     */
    if (e->em_first){
	    e->em_first = 0;

        /*
         * Calculate derived parameters
         */
        e->em_ltgt = (e->em_volume * eqpower[e->em_pan]) >> 15;
        e->em_lratm = __n_getRate(e->em_cvolL, e->em_ltgt,
                            e->em_segEnd, &(e->em_lratl));
        e->em_rtgt = (e->em_volume *
                   eqpower[EQPOWER_LENGTH - e->em_pan - 1]) >> 15;
        e->em_rratm = __n_getRate(e->em_cvolR, e->em_rtgt, e->em_segEnd,
                            &(e->em_rratl));
    
	n_aSetVolume(ptr++, A_RATE, e->em_ltgt, e->em_lratm, e->em_lratl);\
    n_aSetVolume(ptr++, A_LEFT | A_VOL, e->em_cvolL, e->em_dryamt, e->em_wetamt);\
    n_aSetVolume(ptr++, A_RIGHT | A_VOL, e->em_rtgt, e->em_rratm, e->em_rratl);\
	n_aEnvMixer(ptr++, A_INIT | A_NOAUX, e->em_cvolR, osVirtualToPhysical(e->em_state));
    }
    else
	n_aEnvMixer(ptr++, A_CONTINUE | A_NOAUX, 0, osVirtualToPhysical(e->em_state));
        

    /*
     * bump the input buffer pointer
     */

    *inp += sp68 * 2;
    e->em_delta += sp68;

    return ptr;
}

#define EXP_MASK  0x7f800000
#define MANT_MASK 0x807fffff

/*
    __n_getRate()  --  This function determines how to go from the
		    current volume level (vol) to the target
		    volume level (tgt) in some number of steps
		    (count).  Two values are returned that are
		    used as multipliers to incrementally scale
		    the volume.  Some tricky math is used and
		    is explained below.
		    RWW 28jun95
*/

static
s16 __n_getRate(f64 vol, f64 tgt, s32 count, u16* ratel)
{
	s16 s;
	s16 tmp;
	f64 invn;
	f64 a;
	f64 f;

	if (count == 0) {
		if (tgt >= vol) {
			*ratel = 0xffff;
			return 0x7fff;
		} else {
			*ratel = -0;
			return 0;
		}
	}

	invn = 1.0 / count;

	if (tgt < 1.0) {
		tgt = 1.0;
	}

	if (vol <= 0.0) {
		vol = 1.0;
	}

	a = (tgt - vol) * invn * 8.0;
	s = a;

	f = a - s;
	s--;
	f += 1.0;

	tmp = f;
	s += tmp;
	f -= tmp;

	*ratel = 65535.0 * f;

	return s;


}

static
s16 __n_getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel)
{
    s32 r;
    s32 m;
    s32 l;

    samples >>= 3;
    if (samples == 0) {
        return (s16) ivol;
    }
    m = ((ratel * samples));
    m >>= 0x10;
    m += (ratem * samples);
    ivol += m;
    return (s16) ivol;
}
