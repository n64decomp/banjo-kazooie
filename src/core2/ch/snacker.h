#ifndef __BANJO_KAZOOIE_CORE2_CH_SNACKER_H__
#define __BANJO_KAZOOIE_CORE2_CH_SNACKER_H__

#include "prop.h" // for ActorInfo
#include "../snackerctl.h" //for SnackerCtlState

extern ActorInfo gChSnacker;

void chSnacker_initialize(void);
void chsnacker_setControlState(SnackerCtlState nextState);

#endif // __BANJO_KAZOOIE_CORE2_CH_SNACKER_H__
