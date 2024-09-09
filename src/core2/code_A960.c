#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

void codeA960_forceLoadzone(s32);

int isLoadzoneFlagSet(void){
    return miscFlag_isTrue(MISC_FLAG_15_LOADZONE);
}

void func_80291910(void){
    codeA960_forceLoadzone(0);
}

void codeA960_forceLoadzone(s32 arg0){
    if(!isLoadzoneFlagSet()){
        miscFlag_set(MISC_FLAG_15_LOADZONE);
        if(arg0){
            func_8029E3C0(5, 2.0f);
            func_8029C984();
            bs_setState(BS_5A_LOADZONE);
            baModel_setVisible(FALSE);
            baphysics_set_type(BA_PHYSICS_FREEZE);
            func_8029151C(6);
        }
    }
}

void func_802919A0(void){
    if(isLoadzoneFlagSet() && func_8029E1A8(5)){
        func_8029B890();
        codeA960_forceLoadzone(0);
    }
}
