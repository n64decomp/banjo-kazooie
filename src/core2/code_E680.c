#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 D_8037C3A0;
s32 D_8037C3A4;

void ability_use(s32 arg0){
    s32 sp2C;
    s32 sp28;

    sp2C = 0;
    sp28 = 1;

    if(D_8037C3A4 & (1 << arg0))
        return;

    switch(arg0){
        case 0x0://L80295660 //jump
            mapSpecificFlags_set(8, TRUE);
            sp28 = 1;
            break;
        case 0x1://L80295674 //flap
            mapSpecificFlags_set(9, TRUE);
            sp28 = 1;
            break;
        case 0x2://L80295688 //bust
            mapSpecificFlags_set(0xa, TRUE);
            sp28 = 1;
            break;
        case 0x3://L8029569C //
            if(map_get() == MAP_1_SM_SPIRAL_MOUNTAIN){
                sp2C = 0xDFC;
            }
            break;
        case 0x4://L802956B8 //
            if(map_get() == MAP_1_SM_SPIRAL_MOUNTAIN){
                sp2C = 0xE02;
            }
            break;
        case 0x5://L802956D4 //barge
            if(map_get() == MAP_1_SM_SPIRAL_MOUNTAIN){
                sp2C = 0xE05;
            }
            break;
        case 0x6://L802956F0 //slide
            sp28 = 0;
            if(!ability_isUnlocked(ABILITY_10_TALON_TROT)){
                if(map_get() == MAP_2_MM_MUMBOS_MOUNTAIN){
                    sp2C = 0xB4D;
                }
                else
                    return;
            }
            else{
                D_8037C3A4 |= (1 << arg0);
            }
            break;
        case 0x8://L80295738 //fly
            sp2C = 0xA26;
            break;
        case 0x7://L80295740 //egg
        case 0x9://L80295740 //shock
            break;
    }//L80295744
    if(sp28)
        func_8025A70C(COMUSIC_2B_DING_B);
    
    if(sp2C)
        func_80311480(sp2C, 4, NULL, NULL, NULL, 0);
    
    D_8037C3A4 |= (1 << arg0);
}

int ability_hasUsed(enum ability_e move){
    return (1 << move) & D_8037C3A4;
}

void ability_setHasUsed(enum ability_e move){
    D_8037C3A4 |= (1 << move); 
}

int ability_hasLearned(enum ability_e move){
    return (1 << move) & D_8037C3A0;
}

s32 ability_getAllLearned(void){
    return D_8037C3A0;
}

void ability_debug(void){}

void ability_clearAll(void){
    D_8037C3A0 = 0;
    D_8037C3A4 = 0;
}

void func_80295818(s32 move, s32 val){
    if(val){
        D_8037C3A0 |= (1 << move); 
    }else{
        D_8037C3A0 &= ~(1 << move); 
    }
}

void ability_setAllLearned(s32 val){
    D_8037C3A0 = val;
}

void ability_setAllUsed(s32 val){
    D_8037C3A4 = val;
}

void ability_getSizeAndPtr(s32 *size, u8 **addr){
    *size = 8;
    *addr = &D_8037C3A0;
}
