#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038FF60(void){}

void func_8038FF68(void){
    
    if(gsworld_get_map() != MAP_12_GV_GOBIS_VALLEY) return;

    if(jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID)){
        func_8034DE60(&func_8034C528(0x190)->type_6D, 0.0f, 270.0f, 0.0f, 1);
    }
    else{
        func_8034E71C(&func_8034C5AC(0x130)->type_73, -1500, 0.0f);
    }
}

void func_8038FFF4(void){}
