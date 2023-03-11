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

s32 func_8033EAF8(s32 min_coord[3], s32 max_coord[3], f32 position[3], f32 arg3[3]) {
    f32 dCorner[3];
    f32 dot_product;
    f32 max;
    s32 ix;
    s32 iy;
    s32 iz;

    max = 0.0f;
    for(ix = 0; ix < 2; ix++){
        for(iy = 0; iy < 2; iy++){
            for(iz = 0; iz < 2; iz++){
                dCorner[0] = ((ix) ? min_coord[0] : max_coord[0]) - position[0];
                dCorner[1] = ((iy) ? min_coord[1] : max_coord[1]) - position[1];
                dCorner[2] = ((iz) ? min_coord[2] : max_coord[2]) - position[2];
                dot_product = (arg3[0] * dCorner[0]) + (arg3[1] * dCorner[1]) + (arg3[2] * dCorner[2]);
                if (max < dot_product) {
                    max = dot_product;
                }
            }
        }
    }
    return (s32) max;
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
