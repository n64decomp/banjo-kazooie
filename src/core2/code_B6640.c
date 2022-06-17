#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8033D5D0(f32 arg0[3], f32 arg1[3], f32 margin, f32 min[3], f32 max[3]) {
    s32 i;

    i = 0;
    for(i = 0; i < 3; i++){
        if (arg0[i] < arg1[i]) {
            min[i] = arg0[i];
            max[i] = arg1[i];
        } else {
            min[i] = arg1[i];
            max[i] = arg0[i];
        }
        min[i] -= margin;
        max[i] += margin;
    }
}
