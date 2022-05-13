#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80299248(f32);
void func_802991A8(s32);

f32 D_8037C690; //yaw
f32 D_8037C694; //yaw_ideal
s32 D_8037C698; //yaw_update_type
f32 D_8037C69C; //yaw_update2_angular_velocity
f32 D_8037C6A0; //yaw_update3_angular_velocity_limit
f32 D_8037C6A4; //yaw_update3_angular_velocity_percentage

void func_80298D70(f32 arg0) {
    f32 sp24;
    f32 sp20;

    arg0 *= time_getDelta();
    sp24 = D_8037C694 - D_8037C690;
    if (mlAbsF(sp24) > 180.0f) {
        sp24 += (sp24 < 0.0f) ? 360.0 : -360.0;
    }

    sp20 = (mlAbsF(sp24) > 180.0f) ? arg0 : ((sp24 < 0.0f)? -arg0: arg0);
    
    if(mlAbsF(sp20) <= mlAbsF(sp24))
        D_8037C690 += sp20;
    else
        D_8037C690 = D_8037C694;

    if (D_8037C690 < 360.0) {
        if (D_8037C690 < 0.0) {
            D_8037C690 = (f32) (D_8037C690 + 360.0);
        }
    } else {
        D_8037C690 = (f32) (D_8037C690 - 360.0);
    }
}

static void func_80298F14(f32 limit, f32 step_percent){
        f32 diff;
        f32 val;
        f32 tick = time_getDelta();
        f32 max;
        
        max = limit*tick;
        diff = D_8037C694 - D_8037C690;
        if(180.0f < mlAbsF(diff)){
            diff += (diff < 0.0f)? 360.0: -360.0;
        }

        val = diff * step_percent * tick;
        val = (val < 0) ? mlClamp_f(val, -max, -0.1f) : mlClamp_f(val, 0.1f, max);

        D_8037C690 =( mlAbsF(val) <= mlAbsF(diff)) ?  D_8037C690 + val : D_8037C694;

        if(D_8037C690 < 360.0){
            if(D_8037C690 < 0.0)
                D_8037C690 += 360.0;
        }
        else 
            D_8037C690 -= 360.0;
}

void func_802990B4(void){
    D_8037C690 = 0.0f;
    D_8037C694 = 0.0f;
    func_80299234(700.0f, 7.5f);
    func_80299248(360.0f);
    D_8037C698 = 0;
    func_802991A8(1);
}

void func_80299118(void){
    switch(D_8037C698){
        case 0:
            break;
        case 1:
            func_80298F14(700.0f, 7.5f);
            break;
        case 2:
            func_80298D70(D_8037C69C);
            break;
        case 3:
            func_80298F14(D_8037C6A0, D_8037C6A4);
            break;
    }
}

void func_802991A8(s32 arg0){
    D_8037C698 = arg0;
}

void yaw_setIdeal(f32 arg0){
    D_8037C694 = mlNormalizeAngle(arg0);
}

void func_802991D8(f32 arg0){
    D_8037C690 = mlNormalizeAngle(arg0);
}

void yaw_applyIdeal(void){
    D_8037C690 = D_8037C694;
}

s32 func_80299210(void){
    return D_8037C698;
}

f32 yaw_get(void){
    return D_8037C690;
}

f32 yaw_getIdeal(void){
    return D_8037C694;
}

void func_80299234(f32 arg0, f32 arg1){
    D_8037C6A0 = arg0;
    D_8037C6A4 = arg1;
}

void func_80299248(f32 arg0){
    D_8037C69C = arg0;
}

void func_80299254(f32 arg0){
    f32 diff = D_8037C694 - D_8037C690;
    if(180.0f < mlAbsF(diff)){
        diff += (diff < 0.0f)? 360.0: -360.0;
    }

    D_8037C69C = mlAbsF(diff/arg0);
}

