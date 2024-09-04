#ifndef __BANJO_KAZOOIE_CORE2_SNACKER_CTL_H__
#define __BANJO_KAZOOIE_CORE2_SNACKER_CTL_H__

typedef enum {
    SNACKER_CTL_STATE_0_INACTIVE,
    SNACKER_CTL_STATE_1_RBB,
    SNACKER_CTL_STATE_2_TTC
} SnackerCtlState;

void snackerctl_reset(void);
void snackerctl_update(void);
SnackerCtlState snackerctl_get_state(void);

#endif // __BANJO_KAZOOIE_CORE2_SNACKER_CTL_H__
