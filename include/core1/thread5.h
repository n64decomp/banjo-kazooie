#ifndef BANJO_KAZOOIE_CORE1_THREAD5_H
#define BANJO_KAZOOIE_CORE1_THREAD5_H

#include <ultra64.h>

#define THREAD5_ID 5
#define THREAD5_PRI 60

#define THREAD5_MESSAGE_EVENT_SYNC 3
#define THREAD5_MESSAGE_EVENT_DP 4
#define THREAD5_MESSAGE_EVENT_VI_RETRACE 5
#define THREAD5_MESSAGE_EVENT_SP 6
#define THREAD5_MESSAGE_EVENT_AUDIO_TIMER 8
#define THREAD5_MESSAGE_EVENT_FAULT 10
#define THREAD5_MESSAGE_EVENT_PRENMI 11
#define THREAD5_MESSAGE_EVENT_DEBUG 12
#define THREAD5_MESSAGE_EVENT_CONT_TIMER 13

void thread5_sendTaskToQueue(OSMesg msg);
void thread5_checkAndExecutePreNMI(void);
void thread5_create(void);
void thread5_enableControllerTimer(void);
void thread5_finishDList(Gfx **gfx);

#endif
