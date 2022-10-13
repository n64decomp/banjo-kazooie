#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "n_libaudio.h"


extern N_ALSynth *D_80276E80;
extern N_ALSynth *D_80276E84;

void n_alInit(N_ALGlobals *g, ALSynConfig *config)
{
    if (D_80276E80 != NULL)
        return;

    D_80276E80 = &g->drvr;

    if (D_80276E84 != NULL)
        return;

    D_80276E84 = &g->drvr;

    n_alSynNew(config);
}

void n_alClose(N_ALGlobals *glob)
{
    if (D_80276E80)
    {
        n_alSynDelete();

        D_80276E80 = NULL;
        D_80276E84 = NULL;
    }
}
