#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_80260860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_802609E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_80260BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/n_alEnvmixerPull.s")

void __postNextSeqEvent(ALSeqPlayer *seqp) 
{
    ALEvent     evt;
    s32		deltaTicks;
    ALSeq       *seq = seqp->target;

    /* sct 1/5/96 - Do nothing if we're not playing or don't have a target sequence. */
    if ((seqp->state != AL_PLAYING) || (seq == NULL))
	return;

    /* Get the next event time in ticks. */
    /* If false is returned, then there is no next delta (ie. end of sequence reached). */
    if (!__alSeqNextDelta(seq, &deltaTicks))
	return;

    /* Handle loops. */
    if (seqp->loopCount)
    {
        /* Assume that the loop end falls on a MIDI event. Delta time
           will be correct even if we loop */
        if (alSeqGetTicks(seq) + deltaTicks >= seqp->loopEnd->curTicks)
	{
	    alSeqSetLoc(seq, seqp->loopStart);            

	    if (seqp->loopCount != -1)
		seqp->loopCount--;
	}
    }    

    evt.type = AL_SEQ_REF_EVT;
    //alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);

}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__setInstChanState.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_80261348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__initFromBank.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_80261490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__vsDelta.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__vsVol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__seqpReleaseVoice.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__voiceNeedsNoteKill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__unmapVoice.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_802617A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__vsPan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__lookupVoice.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__mapVoice.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__lookupSoundQuick.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_80261A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_802623F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_802623FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__seqpStopOsc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/__initChanState.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_22E40/func_80262BFC.s")
