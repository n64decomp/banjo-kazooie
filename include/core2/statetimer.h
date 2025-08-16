#ifndef _STATE_TIMER_
#define _STATE_TIMER_

#include <ultra64.h>
#include "structs.h"

enum state_timer_e{
    STATE_TIMER_0_UNKNOWN,
    STATE_TIMER_1_THROW = 1,
    STATE_TIMER_2_LONGLEG,
    STATE_TIMER_3_TURBO_TALON,
    STATE_TIMER_4_IFRAME,
    STATE_TIMER_5_UNKNOWN, //slide timer
    STATE_TIMER_6_UNKNOWN  //trot slide timer
};

f32 stateTimer_get(enum state_timer_e timer_id);
f32 stateTimer_getPrevious(enum state_timer_e timer_id);
bool stateTimer_isActive(enum state_timer_e timer_id);
bool stateTimer_isDone(enum state_timer_e timer_id);
bool stateTimer_isAt(enum state_timer_e timer_id, f32 value);
void stateTimer_free(void);
void stateTimer_init(void);
void stateTimer_clear(enum state_timer_e timer_id);
void stateTimer_set(enum state_timer_e timer_id, f32 value);
void stateTimer_update(void);
#endif
