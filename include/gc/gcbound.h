#ifndef GCBOUND_H
#define GCBOUND_H
#include <ultra64.h>

#include "structs.h"


void gcbound_draw(Gfx **dl);
void gcbound_alpha(s32 a);
void gcbound_color(s32 r, s32 g, s32 b);
void gcbound_reset(void);
#endif
