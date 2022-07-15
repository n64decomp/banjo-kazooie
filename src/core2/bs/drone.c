#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

typedef struct{
    u8 unk0;
    bsState behavior;
} struct_drone;

struct_drone D_80364B30[] = {
    {01, {func_802AEDE8, func_802AEE48, func_802AEE9C, NULL}},
    {02, {func_802AEEF4, func_802AEFB0, func_802AF164, func_80296608}},
    {04, {bsdronexform_init, bsdronexform_update, bsdronexform_end, bsdronexform_interrupt}},
    {05, {func_802AE9C8, func_802AEA2C, func_802AEB24, NULL}},
    {06, {func_802AF604, func_802AF668, func_802AF768, NULL}},
    {0}
};



static int __bsdrone_getIndex(void){
    int i;
    int val = func_802925EC();
    for(i = 0; D_80364B30[i].unk0 != 0; i++){
        if(val == D_80364B30[i].unk0)
            return i;
    }
    return 0;
}

void bsdrone_init(void){
    D_80364B30[__bsdrone_getIndex()].behavior.init_func();
}

void bsdrone_update(void){
    D_80364B30[__bsdrone_getIndex()].behavior.update_func();
}

void bsdrone_end(void){
    D_80364B30[__bsdrone_getIndex()].behavior.end_func();
}

void bsdrone_interrupt(void){
    void (* tmp)(void) = D_80364B30[__bsdrone_getIndex()].behavior.interrupt_func;
    if(tmp){
        tmp();
    }
}
