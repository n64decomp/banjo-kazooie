#include <ultra64.h>
#include "n_synth.h"

#define ADPCMFBYTES      9

int
n_alLoadParam(N_PVoice *v, s32 paramID, void *param)
{
    ALLoadFilter *a = (ALLoadFilter *) v;
    
    switch (paramID) {
        case (AL_FILTER_SET_WAVETABLE):
            v->dc_table = (ALWaveTable *) param;
            v->dc_memin = (s32) v->dc_table->base;
            v->dc_sample = 0;
            switch (v->dc_table->type){
                case (AL_ADPCM_WAVE):

                    /*
                     * Set up the correct handler
                     */
                    
                    /*
                     * Make sure the table length is an integer number of
                     * frames
                     */
                    v->dc_table->len = ADPCMFBYTES *
                        ((s32) (v->dc_table->len/ADPCMFBYTES));
                    
                    v->dc_bookSize = 2*v->dc_table->waveInfo.adpcmWave.book->order*
                    v->dc_table->waveInfo.adpcmWave.book->npredictors*ADPCMVSIZE;
                    if (v->dc_table->waveInfo.adpcmWave.loop) {
                        v->dc_loop.start = v->dc_table->waveInfo.adpcmWave.loop->start;
                        v->dc_loop.end = v->dc_table->waveInfo.adpcmWave.loop->end;
                        v->dc_loop.count = v->dc_table->waveInfo.adpcmWave.loop->count;
                        alCopy(v->dc_table->waveInfo.adpcmWave.loop->state,
                               v->dc_lstate, sizeof(ADPCM_STATE));
                    } else {
                        v->dc_loop.start = v->dc_loop.end = v->dc_loop.count = 0;
                    }
                    break;
                    
                case (AL_RAW16_WAVE):
                    //f->handler = alRaw16Pull;
                    if (v->dc_table->waveInfo.rawWave.loop) {
                        v->dc_loop.start = v->dc_table->waveInfo.rawWave.loop->start;
                        v->dc_loop.end = v->dc_table->waveInfo.rawWave.loop->end;
                        v->dc_loop.count = v->dc_table->waveInfo.rawWave.loop->count;
                    } else {
                        v->dc_loop.start = v->dc_loop.end = v->dc_loop.count = 0;
                    }
                    break;
                    
                default:
                    break;

            }
            break;
            
        case (AL_FILTER_RESET):
            v->dc_lastsam = 0;
            v->dc_first   = 1;
            v->dc_sample = 0;
	    
	    /* sct 2/14/96 - Check table since it is initialized to null and */
	    /* Get loop info according to table type. */
	    if (v->dc_table)
	    {
		v->dc_memin  = (s32) v->dc_table->base;
		if (v->dc_table->type == AL_ADPCM_WAVE)
		{
		    if (v->dc_table->waveInfo.adpcmWave.loop)
			v->dc_loop.count = v->dc_table->waveInfo.adpcmWave.loop->count;
		}
		else if (v->dc_table->type == AL_RAW16_WAVE)
		{
		    if (v->dc_table->waveInfo.rawWave.loop)
			v->dc_loop.count = v->dc_table->waveInfo.rawWave.loop->count;
		}
	    }
	    
            break;
            
        default:
            break;
    }
}