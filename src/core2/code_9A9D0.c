#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/statetimer.h"
extern f32 player_stateTimer_get(enum state_timer_e);

void func_803219F4(s32 arg0);

/* .bss */
u8  D_80383310;
s32 D_80383314;

/* .code */
s32 func_80321960(void){
    return D_80383310;
}

void func_8032196C(void){
     if( D_80383310 != 3 && D_80383310 != 5 ){
        func_8025A904();
    }
}

void func_803219A8(void){
    if( D_80383310 != 3 && D_80383310 != 5 ){
        D_80383310 = 0;
        func_803219F4(1);
        D_80383314 = COMUSIC_57_TURBO_TRAINERS;
    }
}

void func_803219F4(s32 arg0){
    switch(D_80383310){
        case 2: //L80321A30
            func_8025A55C(-1, 4000, 7);
            func_8024BD08(1);
            comusic_8025AB44(COMUSIC_58_WADING_BOOTS, 0, 4000);
            func_8025AABC(COMUSIC_58_WADING_BOOTS);
            break;
        case 4: //L80321A6C
            func_8024BD08(1);
            if(D_80383314 == COMUSIC_57_TURBO_TRAINERS){
                func_8025A55C(-1, 4000, 7);
            }
            comusic_8025AB44(D_80383314, 0, 4000);
            func_8025AABC(D_80383314);
            break;
        case 3: //L80321AC0
            func_8025A55C(-1, 4000, 7);
            func_8024BD08(1);
            comusic_8025AB44(COMUSIC_95_BBONUS_A, 0, 4000);
            func_8025AABC(COMUSIC_95_BBONUS_A);
            break;
        case 1: //L80321AF8
        case 5: //L80321AF8
            break;
    }
    D_80383310 = arg0;

    switch(D_80383310){
        case 2: //L80321B28
            func_8024BD08(0);
            func_8025A55C(0, 4000, 7);
            func_8025A6EC(COMUSIC_58_WADING_BOOTS, -1);
            func_8025A8B8(COMUSIC_58_WADING_BOOTS, 1);
            break;
        case 4: //L80321B60
            if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
                D_80383314 = COMUSIC_8A_GETTING_TURBO_TRAINERS;
            }
            else{
                D_80383314 = COMUSIC_57_TURBO_TRAINERS;
            }
            func_8024BD08(0);
            if(D_80383314 == COMUSIC_57_TURBO_TRAINERS){
                func_8025A55C(0, 4000, 7);
            }
            func_8025A6EC(D_80383314, -1);
            func_8025A8B8(D_80383314, 1);
            break;
        case 3: //L80321BDC
            func_803228D8();
            func_8024BD08(0);
            func_8025A55C(0, 4000, 7);
            func_8025A6EC(COMUSIC_95_BBONUS_A, -1);
            func_8025A8B8(COMUSIC_95_BBONUS_A, 1);
            break;
        case 5: //L80321C1C
            func_803228D8();
            break;
        case 1: //L80321C24
            break;
    }
}

void func_80321C34(void){
    if( D_80383310 == 4
        && player_stateTimer_get(STATE_TIMER_3_TURBO_TALON) == 0.0f
    ){
        func_803219F4(1);
    }
}
