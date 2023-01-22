#include <ultra64.h>
#include "n_synth.h"


int
  n_alEnvmixerParam(N_PVoice *filter, s32 paramID, void *param)
{
  N_PVoice	*e =  filter;
  
  switch (paramID) {
  case (AL_FILTER_ADD_UPDATE):
    if (e->em_ctrlTail) {
      e->em_ctrlTail->next = (ALParam *)param;
    } else {
      e->em_ctrlList = (ALParam *)param;
    }            
    e->em_ctrlTail = (ALParam *)param;
    break;
  case (AL_FILTER_RESET):
    e->em_first = 1;
    e->em_motion = AL_STOPPED;
    e->em_volume = 1;
    e->rs_delta  = 0.0;
    e->rs_first  = 1;
    e->rs_upitch = 0;
    n_alLoadParam(e, AL_FILTER_RESET, param);
    break;
  case (AL_FILTER_START):
    e->em_motion = AL_PLAYING;
    break;
  default:
#if 1
    n_alLoadParam(e, paramID, param);
#else
    n_alResampleParam(e, paramID, param);
#endif
    break;
  }
  return 0;
}
