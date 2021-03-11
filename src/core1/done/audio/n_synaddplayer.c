#include <ultra64.h>
#include "synthInternals.h"
#include "n_al.h"

extern AL0s *D_80276E84;

void n_alSynAddPlayer(ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = D_80276E84->synth.curSamples;
    client->next = D_80276E84->synth.head;
    D_80276E84->synth.head = client;
    if(D_80276E84->synth.n_seqp1 == 0){
        D_80276E84->synth.n_seqp1 = client;
    }
    else if(D_80276E84->synth.n_seqp2 == 0){
        D_80276E84->synth.n_seqp2 = client;
    }
    else if(D_80276E84->unk5C == 0){
        D_80276E84->unk5C = client;
    }
    else if(D_80276E84->unk60 == 0){
        D_80276E84->unk60 = client;
    }
    else if(D_80276E84->unk64 == 0){
        D_80276E84->unk64 = client;
    }
    else if(D_80276E84->unk68 == 0){
        D_80276E84->unk68 = client;
    }
    else if(D_80276E84->unk6C == 0){
        D_80276E84->unk6C = client;
    }
    else if(D_80276E84->unk70 == 0){
        D_80276E84->unk70 = client;
    }

    osSetIntMask(mask);
}