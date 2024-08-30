#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 pad_803912C0[2];
u8 __propellorCtrlState;
f32 __propellorTimer;

void __propellorCtrl_setState(s32 arg0){
    f32* timerPtr = &__propellorTimer;
    
    *timerPtr = 0.0f;

    if(arg0 == 1) {
        *timerPtr = 6.5f;
    }

    if(arg0 == 2){
        item_set(ITEM_3_PROPELLOR_TIMER, 3900 - 1);
        item_set(ITEM_9_PROPELLOR, 1);
    }

    if(arg0 == 3 || arg0 == 4){
        levelSpecificFlags_set(0x27, FALSE);
        levelSpecificFlags_set(0x28, FALSE);
        item_set(ITEM_9_PROPELLOR,0);
        if(arg0 == 3 && !jiggyscore_isCollected(JIGGY_57_RBB_PROPELLOR)){
            timedFunc_set_1(0.5f, (GenFunction_1)func_802FAD64, 3);
            func_80324DBC(1.0f, 0xb9d, 4, NULL, NULL, NULL, NULL);
        }
        else{
            func_802FAD64(3);
        }
    }//L8038FED4
    __propellorCtrlState = arg0;
}

void rbb_propellorCtrl_stop(void){
    if(__propellorCtrlState == 2)
        __propellorCtrl_setState(4);
}

void rbb_propellorCtrl_reset(void){
    __propellorCtrlState = 0;
    __propellorCtrl_setState(0);
}

void rbb_propellorCtrl_start(void){
    if(__propellorCtrlState == 2)
        __propellorCtrl_setState(2);
}

void rbb_propellorCtrl_update(void){
    if( __propellorCtrlState == 0)
        if(levelSpecificFlags_get(0x27) && levelSpecificFlags_get(0x28))
            __propellorCtrl_setState(1);

    if(__propellorCtrlState == 1)
        if(ml_timer_update(&__propellorTimer,time_getDelta()))
            __propellorCtrl_setState(2);

    if(__propellorCtrlState == 2)
        if(item_getCount(ITEM_3_PROPELLOR_TIMER) == 0)
            __propellorCtrl_setState(3);

    if(__propellorCtrlState == 3)
        __propellorCtrl_setState(0);
}
