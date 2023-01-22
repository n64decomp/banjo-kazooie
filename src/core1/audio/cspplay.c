#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void alCSPPlay(ALCSPlayer *seqp)
{
    ALEvent evt;
    
    evt.type = AL_SEQP_PLAY_EVT;                    
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
