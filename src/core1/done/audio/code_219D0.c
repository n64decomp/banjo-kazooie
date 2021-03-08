#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8025F3F0(ALCSPlayer *seqp, f32 arg1, f32 arg2)
{
    ALEvent evt;
    
    evt.type = AL_UNK18_EVT; //event type not listed;
    evt.msg.unk18.unk0 = arg1;
    evt.msg.unk18.unk4 = arg2;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}