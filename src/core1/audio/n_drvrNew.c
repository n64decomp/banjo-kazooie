#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_synth.h"

/*
 * WARNING: THE FOLLOWING CONSTANT MUST BE KEPT IN SYNC
 * WITH SCALING IN MICROCODE!!!
 */
#define	SCALE 16384

/*
 * the following arrays contain default parameters for
 * a few hopefully useful effects.
 */
#define ms *(((s32)((f32)44.1))&~0x7)
 
s32 SMALLROOM_PARAMS_N[26] = {
    /* sections	   length */
          3,        100 ms,
                                      /*       chorus  chorus   filter
       input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
           0,   54 ms,  9830,  -9830,      0,      0,      0,      0,
       19 ms,   38 ms,  3276,  -3276, 0x3fff,      0,      0,      0,
           0,   60 ms,  5000,      0,      0,      0,      0, 0x5000
};

s32 BIGROOM_PARAMS_N[34] = {
    /* sections	   length */
          4,        100 ms,
                                      /*       chorus  chorus   filter
       input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
           0,   66 ms,  9830,  -9830,      0,      0,      0,      0,
       22 ms,   54 ms,  3276,  -3276, 0x3fff,      0,      0,      0,
       66 ms,   91 ms,  3276,  -3276, 0x3fff,      0,      0,      0,
           0,   94 ms,  8000,      0,      0,      0,      0, 0x5000
};

s32 ECHO_PARAMS_N[10] = {
    /* sections	   length */
          1,       200 ms,
                                      /*       chorus  chorus   filter
       input  output  fbcoef  ffcoef   gain     rate   depth     coef   */
           0,  179 ms, 12000,      0, 0x7fff,      0,      0,      0
};

s32 CHORUS_PARAMS_N[10] = {
    /* sections	   length */
          1,        20 ms,
                                      /*       chorus  chorus   filter
       input  output  fbcoef  ffcoef   gain     rate   depth     coef   */
	  0,   5 ms, 0x4000,      0,  0x7fff,   7600,   700,      0
};

s32 FLANGE_PARAMS_N[10] = {
    /* sections	   length */
          1,        20 ms,
                                      /*       chorus  chorus   filter
       input  output  fbcoef  ffcoef   gain     rate   depth     coef   */
	   0,   5 ms,      0, 0x5fff, 0x7fff,    380,   500,      0
};

s32 NULL_PARAMS_N[10] = {
    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void n_alFxNew(ALFx **fx_ar, ALSynConfig *c, ALHeap *hp)
{
    u16		i, j, k;
    s32		*param = 0;
    ALDelay	*d;
    ALFx *r;

    *fx_ar = r = (ALFx *)alHeapAlloc(hp, 1, sizeof(ALFx));

    switch (c->fxType) {
      case AL_FX_SMALLROOM:	param = SMALLROOM_PARAMS_N;	break;
      case AL_FX_BIGROOM:	param = BIGROOM_PARAMS_N;	break;
      case AL_FX_ECHO:		param = ECHO_PARAMS_N;		break;
      case AL_FX_CHORUS:	param = CHORUS_PARAMS_N;	break;
      case AL_FX_FLANGE:	param = FLANGE_PARAMS_N;	break;
      case AL_FX_CUSTOM:	param = c->params;		break;
      default:			param = NULL_PARAMS_N;		break;
    }


    j = 0;
    
    r->section_count = param[j++];
    r->length 	     = param[j++];

    r->delay = alHeapAlloc(hp, r->section_count, sizeof(ALDelay));
    r->base = alHeapAlloc(hp, r->length, sizeof(s16));
    r->input = r->base;

    for ( k=0; k < r->length; k++)
	r->base[k] = 0;

    for ( i=0; i<r->section_count; i++ ){
	d = &r->delay[i];
	d->input  = param[j++];
	d->output = param[j++];
	d->fbcoef = param[j++];
	d->ffcoef = param[j++];
	d->gain   = param[j++];

	if (param[j]) {
#define RANGE 2.0
/*	    d->rsinc     = ((f32) param[j++])/0xffffff; */
	    d->rsinc = ((((f32)param[j++])/1000) * RANGE)/c->outputRate;

	    /*
	     * the following constant is derived from:
	     *
	     *		ratio = 2^(cents/1200)
	     *
	     * and therefore for hundredths of a cent
	     *			           x
	     *		ln(ratio) = ---------------
	     *			    (120,000)/ln(2)
	     * where
	     *		120,000/ln(2) = 173123.40...
	     */
#define CONVERT 173123.404906676
#define LENGTH	(d->output - d->input)
	    d->rsgain 	 = (((f32) param[j++])/CONVERT) * LENGTH;
	    d->rsval	 = 1.0;
	    d->rsdelta	 = 0.0;
	    d->rs 	 = alHeapAlloc(hp, 1, sizeof(ALResampler));
	    d->rs->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
	    d->rs->delta = 0.0;
	    d->rs->first = 1;
	} else {
	    d->rs = 0;
	    j++;
	    j++;
	}

	if (param[j]) {
	    d->lp = alHeapAlloc(hp, 1, sizeof(ALLowPass));
	    d->lp->fstate = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));
	    d->lp->fc = param[j++];
	    _init_lpfilter(d->lp);
	} else {
	    d->lp = 0;
	    j++;
	}
    }
}

void alN_PVoiceNew(N_PVoice *mv, ALDMANew dmaNew, ALHeap *hp)
{
  mv->dc_state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
  mv->dc_lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
  mv->dc_dma = dmaNew(&mv->dc_dmaState);
  mv->dc_lastsam = 0;
  mv->dc_first = 1;
  mv->dc_memin = 0;

  mv->rs_state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
  mv->rs_delta  = 0.0;
  mv->rs_first  = 1;
  mv->rs_ratio = 1.0;
  mv->rs_upitch = 0;

  mv->em_state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
  mv->em_first = 1;
  mv->em_motion = AL_STOPPED;
  mv->em_volume = 1;
  mv->em_ltgt = 1;
  mv->em_rtgt = 1;
  mv->em_cvolL = 1;
  mv->em_cvolR = 1;
  mv->em_dryamt = 0;
  mv->em_wetamt = 0;
  mv->em_lratm = 1;
  mv->em_lratl = 0;
  mv->em_lratm = 1;
  mv->em_lratl = 0;
  mv->em_delta = 0;
  mv->em_segEnd = 0;
  mv->em_pan = 0;
  mv->em_ctrlList = 0;
  mv->em_ctrlTail = 0;
}


