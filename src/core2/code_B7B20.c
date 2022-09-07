#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8033EAB0(s32 arg0[3], s32 arg1[3], s32 arg2[3], s32 arg3[3]) {
    s32 i;
    for(i = 0; i < 3; i++){
        arg0[i] = arg2[i];
        arg1[i] = arg3[i];
    }
}

s32 func_8033EAF8(s32 arg0[3], s32 arg1[3], f32 arg2[3], f32 arg3[3]) {
    f32 sp14[3];
    f32 temp_f2;
    f32 var_f0;
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    var_f0 = 0.0f;
    for(var_v0 = 0; var_v0 < 2; var_v0++){
        for(var_v1 = 0; var_v1 < 2; var_v1++){
            for(var_a0 = 0; var_a0 < 2; var_a0++){
                sp14[0] = (f32)((var_v0) ? arg0[0] : arg1[0]) - arg2[0];
                sp14[1] = (f32)((var_v1) ? arg0[1] : arg1[1]) - arg2[1];
                sp14[2] = (f32)((var_a0) ? arg0[2] : arg1[2]) - arg2[2];
                temp_f2 = (arg3[0] * sp14[0]) + (arg3[1] * sp14[1]) + (arg3[2] * sp14[2]);
                if (var_f0 < temp_f2) {
                    var_f0 = temp_f2;
                }
            }
        }
    }
    return (s32) var_f0;
}

bool func_8033EC10(s32 arg0[3], s32 arg1[3], s32 arg2[3]) {
    s32 i;
    for(i = 0; i < 3; i++){
        if (arg0[i] >= arg2[i]) {
            return FALSE;
        }
        if (arg2[i] >= arg1[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

bool func_8033EC70(s32 arg0[3], s32 arg1[3], s32 arg2[3], s32 arg3) {
    s32 i;
    for(i = 0; i < 3; i++){
        if (arg0[i] >= (arg2[i] + arg3)) {
            return FALSE;
        }
        if ((arg2[i] - arg3) >= arg1[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_8033ECD8(s32 arg0[3], s32 arg1[3], s32 arg2) {
    s32 i;
    for(i = 0; i < 3; i++){
        arg0[i] = (arg0[i] >= 0) ? arg0[i]/ arg2 : arg0[i]/ arg2 - 1;
        arg1[i] = (arg1[i] >= 0) ? arg1[i]/ arg2 : arg1[i]/ arg2 - 1;
    }
}

void func_8033EDF0(s32 arg0[3], s32 arg1[3], f32 arg2[3]) {
    s32 i;
    for(i = 0; i < 3; i++){
        arg0[i] += arg2[i];
        arg1[i] += arg2[i];
    }
}
