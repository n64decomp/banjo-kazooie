#include <ultra64.h>
#include "functions.h"
#include "variables.h"


n_alSynSetPriority(ALVoice *voice, s16 priority){
    voice->priority = priority;
}