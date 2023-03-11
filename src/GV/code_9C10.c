#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8 GV_D_80391AD0;

/* .code */
void func_80390000(s32 arg0){
    Struct73s *tmp_v0;
    Struct6Ds *tmp_v0_2;

    GV_D_80391AD0 = arg0;
    if(GV_D_80391AD0 == 1){
        ncStaticCamera_setToNode(0x14);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(4.0f, 0x15);
        func_80324E38(8.0f, 0);
        
        tmp_v0 = func_8034C5AC(0x130);
        if(tmp_v0){
            func_8034E71C(tmp_v0, -1000, 0.0f);
            func_8034E71C(tmp_v0, 0, 10.0f);
        }
        
        tmp_v0_2 = func_8034C528(0x190);
        if(tmp_v0_2){
            func_8034DE60(tmp_v0_2, 0.0f, 270.0f, 0.0f, 1);
        }
    }//L803900AC

    if(GV_D_80391AD0 == 2){
        levelSpecificFlags_set(6, FALSE);
        func_803228D8();
        func_802E4078(MAP_15_GV_WATER_PYRAMID, 1, 0);
    }
}

void func_803900F8(void){}

void func_80390100(void){
    GV_D_80391AD0 = 0;
    if(levelSpecificFlags_get(6)){
        func_80390000(1);
    }
}

void func_80390138(void){
    if(GV_D_80391AD0 && func_80334904() == 2){
        if(GV_D_80391AD0 == 1 && timedFuncQueue_is_empty()){
            func_80390000(2);
        }
    }
}
