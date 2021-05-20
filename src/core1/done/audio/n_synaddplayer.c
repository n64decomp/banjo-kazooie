#include <ultra64.h>
#include "synthInternals.h"
#include "n_synth.h"

extern AL0s *n_syn;

void n_alSynAddPlayer( ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->synth.curSamples;

    client->next = n_syn->synth.head;
    n_syn->synth.head   = client;

    osSetIntMask(mask);
}

void n_alSynAddSndPlayer( ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->synth.curSamples;

#if 1
    client->next = n_syn->synth.head;
    n_syn->synth.head   = client;
#endif

    if( !(n_syn->synth.n_sndp) )
      n_syn->synth.n_sndp = client;

    osSetIntMask(mask);
}

void n_alSynAddSeqPlayer(ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->synth.curSamples;
    client->next = n_syn->synth.head;
    n_syn->synth.head = client;
    if(n_syn->synth.n_seqp1 == 0){
        n_syn->synth.n_seqp1 = client;
    }
    else if(n_syn->synth.n_seqp2 == 0){
        n_syn->synth.n_seqp2 = client;
    }
    else if(n_syn->unk5C == 0){
        n_syn->unk5C = client;
    }
    else if(n_syn->unk60 == 0){
        n_syn->unk60 = client;
    }
    else if(n_syn->unk64 == 0){
        n_syn->unk64 = client;
    }
    else if(n_syn->unk68 == 0){
        n_syn->unk68 = client;
    }
    else if(n_syn->unk6C == 0){
        n_syn->unk6C = client;
    }
    else if(n_syn->unk70 == 0){
        n_syn->unk70 = client;
    }

    osSetIntMask(mask);
}
