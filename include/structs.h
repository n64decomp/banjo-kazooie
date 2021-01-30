#ifndef STRUCTS_H
#define STRUCTS_H

#include <ultra64.h>



typedef struct struct_0_s{ //floor
    void *  model;
    u16     vtx1;
    u16     vtx2;
    u16     vtx3;
    u8      padA[0x6];
    s16     unk10[6];
    f32     unk1C;
    f32     unk20;
    f32     unk24;
    f32     unk28;
    f32     unk2C;
    f32     unk30;
    f32     normX;
    f32     normY;
    f32     normZ;
    f32     posX; //40
    f32     posY; //44
    f32     posZ; //48
    u32     unk4C;
    s16     unk50;
    s16     unk52;
    u32     unk54;
    u8      unk58;
    u8      unk59;
    u8      unk5A;
    u8      unk5B;
    u8      unk5C;
    u8      unk5D;
    u8      unk5E;
    u8      unk5F;
} struct0;

#endif
