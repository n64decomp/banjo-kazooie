#include <ultra64.h>
#include "n_libaudio.h"
#include "n_synth.h"


#define RANGE 2.0
extern ALGlobals *alGlobals;

#ifdef AUD_PROFILE
extern u32 cnt_index, reverb_num, reverb_cnt, reverb_max, reverb_min, lastCnt[];
extern u32 load_num, load_cnt, load_max, load_min, save_num, save_cnt, save_max, save_min;
#endif

/*
 * macros
 */
#define SWAP(in, out)	\
{			\
     s16 t = out;	\
     out = in;		\
     in = t;		\
}

#define N_REVERB_OUTCOUNT 0xb8

Acmd *_n_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, Acmd *p); //_loadOutputBuffer
Acmd *_n_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p); //_loadBuffer
Acmd *__n_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, Acmd *p); //__saveBuffer
Acmd *__n_filterBuffer(ALLowPass *lp, s32 buff, Acmd *p); //__filterBuffer
f32  _doModFunc(ALDelay *d, s32 count);

// static s32 L_INC[] = { L0_INC, L1_INC, L2_INC };

/***********************************************************************
 * Reverb filter public interfaces
 ***********************************************************************/
Acmd *n_alFxPull(void) 
{
    ALFx	*r = (ALFx *)n_syn->auxBus->fx;
    ALFilter    *source = r->filter.source;
    s16		i, buff1, buff2, input, output;
    s16		*in_ptr, *out_ptr, gain, *prev_out_ptr = 0;
    ALDelay	*d, *pd;
    Acmd        *ptr;
    
    

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif
    
    // assert(source);
    ptr = n_alAuxBusPull();
    /*
     * pull channels going into this effect first
     */
    // ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);

    input  = N_AL_AUX_L_OUT;
    output = N_AL_AUX_R_OUT;
    buff1  = N_AL_TEMP_0;
    buff2  = N_AL_TEMP_1;
    
    // aSetBuffer(ptr++, 0, 0, 0, outCount<<1);  /* set the buffer size */
    aMix(ptr++, 0, 0xda83, N_AL_AUX_L_OUT, input); /* .707L = L - .293L */
    aMix(ptr++, 0, 0x5a82, N_AL_AUX_R_OUT, input); /* mix the AuxL and AuxR into the AuxL */
    /* and write the mixed value to the delay line at r->input */
    ptr = __n_saveBuffer(r, r->input, input, ptr);

    aClearBuffer(ptr++, output, N_REVERB_OUTCOUNT << 1); /* clear the AL_AUX_R_OUT */
    

    for (i = 0; i < r->section_count; i++) {
	d  = &r->delay[i];  /* get the ALDelay structure */
	in_ptr  = &r->input[-d->input];
	out_ptr = &r->input[-d->output];
	
	if (in_ptr == prev_out_ptr) {
	    SWAP(buff1, buff2);
	} else {  /* load data at in_ptr into buff1 */
	    ptr = _n_loadBuffer(r, in_ptr, buff1, N_REVERB_OUTCOUNT, ptr);
	}
	ptr = _n_loadOutputBuffer(r, d, buff2, ptr);

	if (d->ffcoef) {
	    aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
	    if (!d->rs && !d->lp) {
		ptr = __n_saveBuffer(r, out_ptr, buff2, ptr);
	    }
	}
	
	if (d->fbcoef) {
	    aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
	    ptr = __n_saveBuffer(r, in_ptr, buff1, ptr);
	}

	if (d->lp)
	    ptr = __n_filterBuffer(d->lp, buff2, ptr);

	if (!d->rs)
	    ptr = __n_saveBuffer(r, out_ptr, buff2, ptr);
	
	if (d->gain)
	    aMix(ptr++, 0, (u16)d->gain, buff2, output);
	
	prev_out_ptr = &r->input[d->output];
    }

    /*
     * bump the master delay line input pointer
     * modulo the length
     */
    r->input += N_REVERB_OUTCOUNT;
    if (r->input > &r->base[r->length])
	r->input -= r->length;

    /*
     * output already in AL_AUX_R_OUT
     *      just copy to AL_AUX_L_OUT
     */
    aDMEMMove(ptr++, output, N_AL_AUX_L_OUT, N_REVERB_OUTCOUNT<<1);

#ifdef AUD_PROFILE
    PROFILE_AUD(reverb_num, reverb_cnt, reverb_max, reverb_min);
#endif
    return ptr;
}


/*
 * This routine gets called by alSynSetFXParam. No checking takes place to 
 * verify the validity of the paramID or the param value. input and output 
 * values must be 8 byte aligned, so round down any param passed. 
 */
s32 n_alFxParamHdl(void *filter, s32 paramID, void *param)
{
    ALFx   *f = (ALFx *) filter;    
    s32    p = (paramID - 2) % 8; 
    s32    s = (paramID - 2) / 8;
    s32    val = *(s32*)param;

#define INPUT_PARAM         0
#define OUTPUT_PARAM        1
#define FBCOEF_PARAM        2
#define FFCOEF_PARAM        3
#define GAIN_PARAM          4
#define CHORUSRATE_PARAM    5
#define CHORUSDEPTH_PARAM   6
#define LPFILT_PARAM        7

    switch(p)
    {
        case INPUT_PARAM:
            f->delay[s].input = (u32)val & 0xFFFFFFF8;
            break;
        case OUTPUT_PARAM:
            f->delay[s].output = (u32)val & 0xFFFFFFF8;
            break;
        case FFCOEF_PARAM:
            f->delay[s].ffcoef = (s16)val;
            break;
        case FBCOEF_PARAM:
            f->delay[s].fbcoef = (s16)val;
            break;
        case GAIN_PARAM:
            f->delay[s].gain = (s16)val;
            break;
        case CHORUSRATE_PARAM:
            /* f->delay[s].rsinc = ((f32)val)/0xffffff; */
            f->delay[s].rsinc = ((((f32)val)/1000) * RANGE)/n_syn->outputRate; 
            break;

/*
 * the following constant is derived from:
 *
 *      ratio = 2^(cents/1200)
 *
 * and therefore for hundredths of a cent
 *                     x
 *      ln(ratio) = ---------------
 *              (120,000)/ln(2)
 * where
 *      120,000/ln(2) = 173123.40...
 */
#define CONVERT 173123.404906676
#define LENGTH  (f->delay[s].output - f->delay[s].input)

        case CHORUSDEPTH_PARAM:
            /*f->delay[s].rsgain = (((f32)val) / CONVERT) * LENGTH; */
            f->delay[s].rsgain = (((f32)val) / CONVERT) * LENGTH;
            break;
        case LPFILT_PARAM:
            if(f->delay[s].lp)
            {
                f->delay[s].lp->fc = (s16)val;
                _init_lpfilter(f->delay[s].lp);
            }
            break;
    }
    return 0;
}

Acmd *_n_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, Acmd *p)
{
    Acmd        *ptr = p;
    s32         ratio, count, rbuff = N_AL_TEMP_2;
    s16         *out_ptr;
    f32         fincount, fratio, delta;
    s32         ramalign = 0, length;
    s32         inCount = 0xb8;
    s8          tmp;
    static f32  val=0.0, lastval=-10.0;
    static f32  blob=0;
/*
 * The following section implements the chorus resampling. Modulate where you pull
 * the samples from, since you need varying amounts of samples.
 */
    if (d->rs) {
        length = d->output - d->input;
        delta = _doModFunc(d, inCount); /* get the number of samples to modulate by */
        /*
         * find ratio of delta to delay length and quantize
         *  to same resolution as resampler
         */
        delta /= length;  /* convert delta from number of samples to a pitch ratio */
        delta = (s32)(delta * UNITY_PITCH); /* quantize to value microcode will use */
        delta = delta / UNITY_PITCH;
        fratio = 1.0 - delta;  /* pitch ratio needs to be centered around 1, not zero */
      
        /* d->rs->delta is the difference between the fractional and integer value
         * of the samples needed. fratio * incount + rs->delta gives the number of samples 
         * needed for this frame.
         */
        fincount = d->rs->delta + (fratio * (f32)inCount);
        count = (s32) fincount; /* quantize to s32 */
        d->rs->delta = fincount - (f32)count; /* calculate the round off and store */

        /*
         * d->rsdelta is amount the out_ptr has deviated from its starting position. 
         * You calc the out_ptr by taking d->output - d->rsdelta, and then using the 
         * negative of that as an index into the delay buffer. loadBuffer that uses this
         * value then bumps it up if it is below the  delay buffer.
         */ 
        out_ptr = &r->input[-(d->output - d->rsdelta)];
        ramalign = (((s32)out_ptr & 0x7) >> 1); /* calculate the number of samples needed 
                                               to align the buffer*/
#ifdef _DEBUG
#if 0
        if(length > 0) {
            if (length - d->rsdelta > (s32)r->length) {
                __osError(ERR_ALMODDELAYOVERFLOW, 1, length - d->rsdelta - r->length);
            }
        }
        else if(length < 0) {
            if ((-length) - d->rsdelta > (s32)r->length) {
                __osError(ERR_ALMODDELAYOVERFLOW, 1, (-length) - d->rsdelta - r->length);
            }
        }
#endif
#endif
        /* load the rbuff with samples, note that there will be ramalign worth of
         *  samples at the begining which you don't care about. */
        ptr = _n_loadBuffer(r, out_ptr - ramalign, rbuff, count + ramalign, ptr);

        /* convert fratio to 16 bit fraction for microcode use */ 
        ratio = (s32)(fratio * UNITY_PITCH);
        /* set the buffers, and do the resample */
        // aSetBuffer(ptr++, 0, rbuff + (ramalign<<1), buff, inCount<<1);
        tmp = (buff>>8);
        n_aResample(ptr++, osVirtualToPhysical(d->rs->state), d->rs->first, ratio, rbuff + (ramalign<<1), tmp);
      
        d->rs->first = 0; /* turn off first time flag */
        d->rsdelta += count - inCount; /* add the number of samples to d->rsdelta */
    } else {
        out_ptr = &r->input[-d->output];
        ptr = _n_loadBuffer(r, out_ptr, buff, inCount, ptr);
    }

    return ptr;
}
/* 
 * This routine is for loading data from the delay line buff. If the
 * address of curr_ptr < r->base, it will force it to be within r->base
 * space, If the load goes past the end of r->base it will wrap around.
 * Cause count bytes of data at curr_ptr (within the delay line) to be
 * loaded into buff. (Buff is a dmem buffer)
 */
Acmd *_n_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd    *ptr = p;
    s32     after_end, before_end;
    s16     *updated_ptr, *delay_end;

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

    delay_end = &r->base[r->length];

#ifdef _DEBUG
    if(curr_ptr > delay_end)
        __osError(ERR_ALMODDELAYOVERFLOW, 1, delay_end - curr_ptr);
#endif

    if (curr_ptr < r->base)
    curr_ptr += r->length;
    updated_ptr = curr_ptr + count;
    
    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;
        
        n_aLoadBuffer(ptr++, before_end << 1, buff, osVirtualToPhysical(curr_ptr));
        n_aLoadBuffer(ptr++, after_end<<1, buff + (before_end<<1), osVirtualToPhysical(r->base));
    } else {
        n_aLoadBuffer(ptr++, count<<1, buff, osVirtualToPhysical(curr_ptr));
    }

#ifdef AUD_PROFILE
    PROFILE_AUD(load_num, load_cnt, load_max, load_min);
#endif
    return ptr;

}

/*
 * This routine is for writing data to the delay line buff. If the
 * address of curr_ptr < r->base, it will force it to be within r->base
 * space. If the write goes past the end of r->base, it will wrap around
 * Cause count bytes of data at buff to be written to delay line, curr_ptr.
 */
Acmd *__n_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, Acmd *p)
{
    Acmd    *ptr = p;
    s32     after_end, before_end;
    s16     *updated_ptr, *delay_end;

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

    delay_end = &r->base[r->length];
    if (curr_ptr < r->base)      /* probably just security */
        curr_ptr += r->length;   /* shouldn't occur */
    updated_ptr = curr_ptr + 0xb8;

    if (updated_ptr > delay_end) { /* if the data wraps past end of r->base */
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        n_aSaveBuffer(ptr++, before_end<<1, buff, osVirtualToPhysical(curr_ptr));
        n_aSaveBuffer(ptr++, after_end<<1, buff+(before_end<<1), osVirtualToPhysical(r->base));
    } else {
        n_aSaveBuffer(ptr++, 0xb8 << 1, buff, osVirtualToPhysical(curr_ptr));
    }

#ifdef AUD_PROFILE
    PROFILE_AUD(save_num, save_cnt, save_max, save_min);
#endif
    return ptr;

}

Acmd *__n_filterBuffer(ALLowPass *lp, s32 buff, Acmd *p)
{
    Acmd* ptr = p;
    s8 t8;

    n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
    t8 = buff>>8;
    n_aPoleFilter(ptr++, lp->first, lp->fgain, t8, osVirtualToPhysical(lp->fstate));
    lp->first = 0;

    return ptr;
}