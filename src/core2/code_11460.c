#include <ultra64.h>
#include "functions.h"
#include "variables.h"

static f32 sPlayerPosition[3];
static f32 D_8037C5B0[3]; //player_ideal position?
static f32 sPlayerPositionOffset[3];

void playerPosition_init(void) {
    ml_vec3f_clear(sPlayerPositionOffset);
    ml_vec3f_clear(sPlayerPosition);
    ml_vec3f_clear(D_8037C5B0);
}

void playerPosition_func_8029842C(void) {
    ml_vec3f_copy(D_8037C5B0, sPlayerPosition);
    ml_vec3f_clear(sPlayerPositionOffset);
}

void playerPosition_func_80298464(f32 position[3]) {
    ml_vec3f_copy(sPlayerPosition, position);
    ml_vec3f_copy(D_8037C5B0, position);
}

void playerPosition_set(f32 position[3]) {
    ml_vec3f_copy(sPlayerPosition, position);
}

void playerPosition_setY(f32 value) {
    sPlayerPosition[1] = value;
}

void playerPosition_get(f32 position[3]) {
    ml_vec3f_copy(position, sPlayerPosition);
}

f32 playerPosition_getY(void) {
    return sPlayerPosition[1];
}

void playerPosition_func_80298504(f32 arg0[3]) {
    ml_vec3f_copy(arg0, D_8037C5B0);
}

void playerPosition_addY(f32 value) {
    sPlayerPosition[1] += value;
}

void playerPosition_getOffset(f32 offset[3]) {
    ml_vec3f_copy(offset, sPlayerPositionOffset);
}

void playerPosition_setOffset(f32 offset[3]) {
    ml_vec3f_copy(sPlayerPositionOffset, offset);
}

void playerPosition_applyOffset(void) {
    sPlayerPosition[0] += sPlayerPositionOffset[0];
    sPlayerPosition[1] += sPlayerPositionOffset[1];
    sPlayerPosition[2] += sPlayerPositionOffset[2];
    ml_vec3f_clear(sPlayerPositionOffset);
}
