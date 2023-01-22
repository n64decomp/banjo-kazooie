#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 alCSPGetTempo(ALCSPlayer *seqp){
    if(seqp->target == NULL)
        return 0;
    return seqp->uspt / seqp->target->qnpt;
}

