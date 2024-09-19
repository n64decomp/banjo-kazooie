#include <ultra64.h>
#include "bool.h"

void coords_copy(s32 min_out[3], s32 max_out[3], s32 min_in[3], s32 max_in[3]) {
    int i;

    for (i = 0; i < 3; i++) {
        min_out[i] = min_in[i];
        max_out[i] = max_in[i];
    }
}

s32 coords_func_8033EAF8(s32 min[3], s32 max[3], f32 position[3], f32 direction[3]) {
    f32 corner[3];
    f32 dot_product;
    f32 result;
    s32 ix;
    s32 iy;
    s32 iz;

    result = 0.0f;

    for(ix = 0; ix < 2; ix++) {
        for (iy = 0; iy < 2; iy++) {
            for (iz = 0; iz < 2; iz++) {
                corner[0] = (ix ? min[0] : max[0]) - position[0];
                corner[1] = (iy ? min[1] : max[1]) - position[1];
                corner[2] = (iz ? min[2] : max[2]) - position[2];

                dot_product = (direction[0] * corner[0]) + (direction[1] * corner[1]) + (direction[2] * corner[2]);

                if (result < dot_product) {
                    result = dot_product;
                }
            }
        }
    }

    return (s32) result;
}

bool coords_isPointInside(s32 min[3], s32 max[3], s32 point[3]) {
    int i;

    for (i = 0; i < 3; i++) {
        if (min[i] >= point[i]) {
            return FALSE;
        }

        if (point[i] >= max[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

bool coords_isPointInsideWithOffset(s32 min[3], s32 max[3], s32 point[3], s32 offset) {
    int i;

    for (i = 0; i < 3; i++) {
        if (min[i] >= (point[i] + offset)) {
            return FALSE;
        }

        if ((point[i] - offset) >= max[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

void coords_scale(s32 min[3], s32 max[3], s32 ratio) {
    int i;

    for (i = 0; i < 3; i++) {
        min[i] = (min[i] >= 0) ? min[i] / ratio : min[i] / ratio - 1;
        max[i] = (max[i] >= 0) ? max[i] / ratio : max[i] / ratio - 1;
    }
}

void coords_translate(s32 min[3], s32 max[3], f32 translation[3]) {
    int i;

    for (i = 0; i < 3; i++) {
        min[i] += translation[i];
        max[i] += translation[i];
    }
}
