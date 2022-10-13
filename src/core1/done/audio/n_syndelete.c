#include <ultra64.h>
#include "n_synth.h"


void n_alSynDelete(void){
    n_syn->head = NULL;
    n_syn->n_seqp1 = NULL;
    n_syn->n_seqp2 = NULL;
    n_syn->unk5C = NULL;
    n_syn->unk60 = NULL;
    n_syn->unk64 = NULL;
    n_syn->unk68 = NULL;
    n_syn->unk6C = NULL;
    n_syn->unk70 = NULL;
    n_syn->n_sndp = NULL;
}
