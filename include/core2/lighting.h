#ifndef _LIGHTING_H_
#define _LIGHTING_H_
#include <ultratypes.h>

typedef struct { 
    f32 position[3];
    f32 positionCopy[3];
    f32 fade_radius_min_unscaled; // unk
    f32 fade_radius_max_unscaled; // unk
    f32 fade_radius_min; // result of unk18 / actor scale, some sort of distance
    f32 fade_radius_max; // result of unk1C / actor scale, some sort of distance (determines whether to modify rgb of vertex)
    s32 rgb[3];  // rgb
    u8 active; // some sort of flag
    u8 pad35[0x3];
} Lighting; //size 0x38

void lighting_free();
void lighting_init();
#endif
