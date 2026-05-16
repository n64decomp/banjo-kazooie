#include <ultra64.h>

/*

result
1.0|         ,----.
   |        / |   |\
   |       /  |   | \
0.0|______/   |   |  \_____ position
          |   |   |   |
         [2] [3] [0] [1]    curve_values

*/

f32 core2_C3A40_getIntensity(f32 curve_values[4], f32 position) {
    if (curve_values[1] <= position) {
        return 0.0f;
    }

    if (curve_values[0] <= position) {
        return (curve_values[1] - position) / (curve_values[1] - curve_values[0]);
    }

    if (curve_values[3] <= position) {
        return 1.0f;
    }

    if (curve_values[2] <= position) {
        return (position - curve_values[2]) / (curve_values[3] - curve_values[2]);
    }
    
    return 0.0f;
}


void core2_C3A40_getDefaultValues(f32 dst[4]) {
    dst[1] = 10000.0f;
    dst[0] = 4000.0f;
    dst[3] = 2000.0f;
    dst[2] = -500.0f;
}
