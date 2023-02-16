#include "core2/statetimer.h"
extern f32 time_getDelta(void);

typedef struct{
    f32 now;
    f32 previous;
}StateTimer;

/* .bss */
StateTimer stateTimerList[8];

/* .code */
f32 stateTimer_get(enum state_timer_e timer_id){
    return stateTimerList[timer_id].now;
}

f32 stateTimer_getPrevious(enum state_timer_e timer_id){
    return stateTimerList[timer_id].previous;
}

bool stateTimer_isActive(enum state_timer_e timer_id){
    return stateTimerList[timer_id].now != 0.0f;
}

bool stateTimer_isDone(enum state_timer_e timer_id){
    return stateTimerList[timer_id].now == 0.0f;
}

bool stateTimer_isAt(enum state_timer_e timer_id, f32 value){
    return (stateTimerList[timer_id].now < value) && (value <= stateTimerList[timer_id].previous);
}

void stateTimer_free(void){}

void stateTimer_init(void){
    int i;
    for(i = 0; i < 7; i++){
        stateTimerList[i].now = 0.0f;
        stateTimerList[i].previous = 0.0f;
    }
}

void stateTimer_clear(enum state_timer_e timer_id){
    stateTimer_set(timer_id, 0.0f);
}

void stateTimer_set(enum state_timer_e timer_id, f32 arg1){
    stateTimerList[timer_id].now = arg1;
    stateTimerList[timer_id].previous = arg1;
}

void stateTimer_update(void){
    int i;
    f32 delta = time_getDelta();
    for(i = 0; i < 7; i++){
        stateTimerList[i].previous = stateTimerList[i].now;
        if(0.0f != stateTimerList[i].previous){
            stateTimerList[i].now -= delta;
            if(stateTimerList[i].now < 0.0f){
                stateTimerList[i].now = 0.0f;
            }
        }
    }
}
