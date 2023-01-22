#include <ultra64.h>

void alCSPSetSeq(ALCSPlayer *seqp, ALCSeq *seq)
{
    ALEvent evt;

    evt.type = AL_SEQP_SEQ_EVT;
    evt.msg.spseq.seq = seq;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
