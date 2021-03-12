#include <ultra64.h>
#include "n_synth.h"

#define ADPCMFBYTES      9

int
n_alLoadParam(N_PVoice *v, s32 paramID, void *param)
{
    ALLoadFilter *a = (ALLoadFilter *) v;
    
    switch (paramID) {
        case (AL_FILTER_SET_WAVETABLE):
            v->decoder.table = (ALWaveTable *) param;
            v->decoder.memin = (s32) v->decoder.table->base;
            v->decoder.sample = 0;
            switch (v->decoder.table->type){
                case (AL_ADPCM_WAVE):

                    /*
                     * Set up the correct handler
                     */
                    
                    /*
                     * Make sure the table length is an integer number of
                     * frames
                     */
                    v->decoder.table->len = ADPCMFBYTES *
                        ((s32) (v->decoder.table->len/ADPCMFBYTES));
                    
                    v->decoder.bookSize = 2*v->decoder.table->waveInfo.adpcmWave.book->order*
                    v->decoder.table->waveInfo.adpcmWave.book->npredictors*ADPCMVSIZE;
                    if (v->decoder.table->waveInfo.adpcmWave.loop) {
                        v->decoder.loop.start = v->decoder.table->waveInfo.adpcmWave.loop->start;
                        v->decoder.loop.end = v->decoder.table->waveInfo.adpcmWave.loop->end;
                        v->decoder.loop.count = v->decoder.table->waveInfo.adpcmWave.loop->count;
                        alCopy(v->decoder.table->waveInfo.adpcmWave.loop->state,
                               v->decoder.lstate, sizeof(ADPCM_STATE));
                    } else {
                        v->decoder.loop.start = v->decoder.loop.end = v->decoder.loop.count = 0;
                    }
                    break;
                    
                case (AL_RAW16_WAVE):
                    //f->handler = alRaw16Pull;
                    if (v->decoder.table->waveInfo.rawWave.loop) {
                        v->decoder.loop.start = v->decoder.table->waveInfo.rawWave.loop->start;
                        v->decoder.loop.end = v->decoder.table->waveInfo.rawWave.loop->end;
                        v->decoder.loop.count = v->decoder.table->waveInfo.rawWave.loop->count;
                    } else {
                        v->decoder.loop.start = v->decoder.loop.end = v->decoder.loop.count = 0;
                    }
                    break;
                    
                default:
                    break;

            }
            break;
            
        case (AL_FILTER_RESET):
            v->decoder.lastsam = 0;
            v->decoder.first   = 1;
            v->decoder.sample = 0;
	    
	    /* sct 2/14/96 - Check table since it is initialized to null and */
	    /* Get loop info according to table type. */
	    if (v->decoder.table)
	    {
		v->decoder.memin  = (s32) v->decoder.table->base;
		if (v->decoder.table->type == AL_ADPCM_WAVE)
		{
		    if (v->decoder.table->waveInfo.adpcmWave.loop)
			v->decoder.loop.count = v->decoder.table->waveInfo.adpcmWave.loop->count;
		}
		else if (v->decoder.table->type == AL_RAW16_WAVE)
		{
		    if (v->decoder.table->waveInfo.rawWave.loop)
			v->decoder.loop.count = v->decoder.table->waveInfo.rawWave.loop->count;
		}
	    }
	    
            break;
            
        default:
            break;
    }
}