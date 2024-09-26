#include <ultra64.h>
#include "bool.h"

void coords_copy(s32 min_out[3], s32 max_out[3], s32 min_in[3], s32 max_in[3]);
s32 coords_func_8033EAF8(s32 min[3], s32 max[3], f32 position[3], f32 direction[3]);
bool coords_isPointInside(s32 min[3], s32 max[3], s32 point[3]);
bool coords_isPointInsideWithOffset(s32 min[3], s32 max[3], s32 point[3], s32 offset);
void coords_scale(s32 min[3], s32 max[3], s32 ratio);
void coords_translate(s32 min[3], s32 max[3], f32 translation[3]);
