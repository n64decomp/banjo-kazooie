#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80291930(s32);

int func_802918F0(void){
    return func_802933C0(0x15);
}

void func_80291910(void){
    func_80291930(0);
}

void func_80291930(s32 arg0){
    if(!func_802918F0()){
        func_802933E8(0x15);
        if(arg0){
            func_8029E3C0(5, 2.0f);
            func_8029C984();
            bs_setState(BS_5A_LOADZONE);
            func_802921C8(0);
            func_802978DC(7);
            func_8029151C(6);
        }
    }
}

void func_802919A0(void){
    if(func_802918F0() && func_8029E1A8(5)){
        func_8029B890();
        func_80291930(0);
    }
}
