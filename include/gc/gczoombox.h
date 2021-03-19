#ifndef GCZOOMBOX_H
#define GCZOOMBOX_H

#include <ultra64.h>

#include "structs.h"

typedef struct{
    u8  unk0[0x13A];
    u8  unk13A;
    u8  pad13B[0x2E];
    u16 text_alpha;
    u16 text_x_position;
    u16 text_y1_position;
    u16 text_y2_position;
    s32 x_position;
    s32 y_position;
    u8  pad174[0x34];
}gczoombox_t; //size 0x1A8


void gczoombox_free(gczoombox_t* this);

#endif
