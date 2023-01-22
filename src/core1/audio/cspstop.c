#include <ultra64.h>


void alCSPStop(ALCSPlayer *seqp)
{
    ALEvent     evt;

    evt.type = AL_SEQP_STOPPING_EVT;                    
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
