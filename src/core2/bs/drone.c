#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

#include "core2/ba/drone.h"

typedef struct{
    u8 type;
    bsState behavior;
} struct_drone;

struct_drone D_80364B30[] = {
    {BA_DRONE_GOTO,         {bsDroneGoTo_init, bsDroneGoTo_update, bsDroneGoTo_end, NULL}},
    {BA_DRONE_LOOK,         {bsDroneLook_init, bsDroneLook_update, bsDroneLook_end, func_80296608}},
    // {BA_DRONE_UNKNOWN_3, {NULL, NULL, NULL, NULL}}, //unused drone type?
    {BA_DRONE_TRANSFORM,    {bsdronexform_init, bsdronexform_update, bsdronexform_end, bsdronexform_interrupt}},
    {BA_DRONE_ENTER,        {bsDroneEnter_init, bsDroneEnter_update, bsDroneEnter_end, NULL}},
    {BA_DRONE_VANISH,       {bsDroneVanish_init, bsDroneVanish_update, bsDroneVanish_end, NULL}},
    {0}
};



static int __bsdrone_getIndex(void){
    int i;
    int val = badrone_get_type();
    for(i = 0; D_80364B30[i].type != 0; i++){
        if(val == D_80364B30[i].type)
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
