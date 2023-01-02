#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void points_to_boundingBoxWithMargin(f32 p1[3], f32 p2[3], f32 margin, f32 min[3], f32 max[3]) {
    s32 i;

    i = 0;
    for(i = 0; i < 3; i++){
        if (p1[i] < p2[i]) {
            min[i] = p1[i];
            max[i] = p2[i];
        } else {
            min[i] = p2[i];
            max[i] = p1[i];
        }
        min[i] -= margin;
        max[i] += margin;
    }
}
