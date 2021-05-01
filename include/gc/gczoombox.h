#ifndef GCZOOMBOX_H
#define GCZOOMBOX_H

#include <ultra64.h>

#include "structs.h"



typedef struct {
    u8 unk0[0x30]; //string1
    u8 unk30[0x30]; //string2
    struct {
        u8 pad0[0x30];
    } unk60;
    struct {
        u8 pad0[0x20];
    } unk90;
     struct {
        u8 pad0[0x40];
    } unkB0;
    void *unkF0;
    AnimCtrl *unkF4;
    struct19s *unkF8;
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    u8  unk108[5];  //sfx_ids
    u8  pad10D[3];
    f32  unk110[5]; //sfx_???
    s16 unk124[5];  //sfx_???
    s16 unk12E;
    void (*unk130)(s32, s32);
    u8  unk134;
    u8  unk135;
    u8  portrait_id; //0x136
    u8  unk137;
    u8  unk138;
    u8  unk139;
    u8  unk13A;
    u8  unk13B;     //sfx_count
    struct16s unk13C[2];
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 pad15F[0x1];
    s32 unk160;
    s16 unk164;
    s16 unk166; //top_transparency???
    s16 unk168; //rgb???
    s16 unk16A; //x_pos
    s16 unk16C; //y1_pos
    s16 unk16E; //y2_pos
    s16 unk170;
    u16 unk172;
    u16 unk174;
    s8  unk176;
    s8  unk177;
    s8  unk178;
    s8  unk179;
    u8  pad17A[0x2];
    f32 unk17C;
    u8  unk180;
    u8  unk181;
    u8  pad182[0x3];
    u8 unk185;
    s8 unk186;
    u8 unk187;
    u8 unk188;
    u8 unk189;
    u8 unk18A;
    u8 unk18B;      //next_sfx
    f32 unk18C;
    u8 pad190[0x4];
    f32 unk194;
    f32 unk198;
    f32 unk19C;
    f32 unk1A0;
    u32 unk1A4_31:1;
    u32 unk1A4_30:1;
    u32 unk1A4_29:1;
    u32 unk1A4_28:1;
    u32 unk1A4_27:1;
    u32 unk1A4_26:1;
    u32 unk1A4_25:1;
    u32 unk1A4_24:1;
    u32 unk1A4_23:1;
    u32 pad1A4_22:1;
    u32 unk1A4_21:1;
    u32 unk1A4_20:1;
    u32 unk1A4_19:1;
    u32 unk1A4_18:1;
    u32 unk1A4_17:1;
    u32 unk1A4_16:1;
    u32 unk1A4_15:1;
    u32 unk1A4_14:1;
    u32 unk1A4_13:1;
    u32 pad1A4_12:1;
    u32 unk1A4_11:1;
    u32 pad1A4_10:11;
}gczoombox_t; //size 0x1A8

void gczoombox_draw(gczoombox_t *this, Gfx **gdl, Mtx ** mptr, void *vptr);
void gczoombox_free(gczoombox_t* this);
gczoombox_t *gczoombox_new(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(s32, s32));

#endif
