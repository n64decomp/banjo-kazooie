#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "n_libaudio.h"


extern N_ALSynth *D_80276E80;
extern N_ALSynth *D_80276E84;

void func_8025C2E0(s32 a0)
{
    if (D_80276E80)
    {
        func_8025F610();

        D_80276E80 = NULL;
        D_80276E84 = NULL;
    }
}

void func_8025C320(N_ALSynth *synth, ALSynConfig *config)
{
    if (D_80276E80 != NULL)
        return;

    D_80276E80 = synth;

    if (D_80276E84 != NULL)
        return;

    D_80276E84 = synth;

    n_alSynNew(config);
}

