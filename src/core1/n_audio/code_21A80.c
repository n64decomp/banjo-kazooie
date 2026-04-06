#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_synth.h"

u8 func_8025F4A0(N_ALCSPlayer *seqp, u8 chan)
{
    return seqp->chanState[chan].unkA;
}
