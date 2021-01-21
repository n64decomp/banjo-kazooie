#ifndef GCBOUND_H
#define GCBOUND_H
#include <ultra64.h>

#include "structs.h"


void gcbound_draw(Gfx **dl);
void gcbound_alpha(s32 a);
void gcbound_color(u8 r, u8 g, u8 b);
void gcbound_reset(void);
#endif
