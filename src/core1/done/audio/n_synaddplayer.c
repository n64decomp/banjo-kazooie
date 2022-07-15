#include <ultra64.h>
#include "synthInternals.h"
#include "n_synth.h"


void n_alSynAddPlayer( ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->curSamples;

    client->next = n_syn->head;
    n_syn->head   = client;

    osSetIntMask(mask);
}

void n_alSynAddSndPlayer( ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->curSamples;

#if 1
    client->next = n_syn->head;
    n_syn->head   = client;
#endif

    if( !(n_syn->n_sndp) )
      n_syn->n_sndp = client;

    osSetIntMask(mask);
}

void n_alSynAddSeqPlayer(ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = n_syn->curSamples;
    client->next = n_syn->head;
    n_syn->head = client;
    if(n_syn->n_seqp1 == 0){
        n_syn->n_seqp1 = client;
    }
    else if(n_syn->n_seqp2 == 0){
        n_syn->n_seqp2 = client;
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
