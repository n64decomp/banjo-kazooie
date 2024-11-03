#ifndef _LIGHTING_H_
#define _LIGHTING_H_
#include <ultratypes.h>

typedef struct { 
    f32 position[3];
    f32 positionCopy[3];
    f32 unk18; // unk
    f32 unk1C; // unk
    f32 unk20; // result of unk18 / actor scale, some sort of distance
    f32 unk24; // result of unk1C / actor scale, some sort of distance (determines whether to modify rgb of vertex)
    s32 rgb[3];  // rgb
    u8 unk34; // some sort of flag
    u8 pad35[0x3];
} Lighting; //size 0x38

void lighting_free();
void lighting_init();
#endif
