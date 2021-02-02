#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f64 D_80278D50;
extern f64 D_80278D58;

void alSeqGetLoc(ALSeq *seq, ALSeqMarker *m){
    m->curPtr = seq->curPtr;
    m->lastStatus = seq->lastStatus;
    m->lastTicks = seq->lastTicks;
}

void alSeqSetLoc(ALSeq *seq, ALSeqMarker *m){
    seq->curPtr     = m->curPtr;
    seq->lastStatus = m->lastStatus;
    seq->lastTicks  = m->lastTicks;
}

s32 alSeqGetTicks(ALSeq *seq){
    return seq->lastTicks;
}

void read8(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/seq/readVarLen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/seq/alSeqNextEvent.s")

void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks)
{
    ALEvent     evt;
    u8          *savePtr, *lastPtr;
    s32         saveTicks, lastTicks;
    s16         saveStatus, lastStatus;
    
    /* does not check that ticks is within bounds */
    
    if (ticks == 0) { /* common case */
        m->curPtr     = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks  = 0;
	m->curTicks = 0;
        return;
    } else {
        savePtr     = seq->curPtr;
        saveStatus  = seq->lastStatus;
        saveTicks   = seq->lastTicks;

        seq->curPtr     = seq->trackStart;
        seq->lastStatus = 0;
        seq->lastTicks  = 0;

        do {
            lastPtr    = seq->curPtr;
            lastStatus = seq->lastStatus;
            lastTicks  = seq->lastTicks;
        
            alSeqNextEvent(seq, &evt);
            
            if (evt.type == AL_SEQ_END_EVT)
	    {
		lastPtr    = seq->curPtr;
		lastStatus = seq->lastStatus;
		lastTicks  = seq->lastTicks;
                break;
	    }
            
        } while (seq->lastTicks < ticks);

        m->curPtr     = lastPtr;
        m->lastStatus = lastStatus;
        m->lastTicks  = lastTicks;
	m->curTicks = seq->lastTicks;	/* Used by test loop condition. */
    
        seq->curPtr     = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks  = saveTicks;

    }    
}

u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo)
{
    return (u32)(((sec * D_80278D50) * seq->division) / tempo);
}

f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo)
{
    return ((f32) (((f32)(ticks) * (f32)(tempo)) /
                     ((f32)(seq->division) * D_80278D58)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/seq/__alSeqNextDelta.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/seq/read32.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/seq/read16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/seq/alSeqNew.s")

