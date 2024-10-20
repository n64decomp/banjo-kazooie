#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

typedef struct{
    u8 map_id;
    u8 rgb[3];
    u8 alpha;
}Struct_core2_37E50_0;

Struct_core2_37E50_0 D_80365D60[] ={
    {MAP_3_UNUSED,                {0x00, 0xD0, 0xBF}, 0x50},
    {MAP_B_CC_CLANKERS_CAVERN,    {0x78, 0x6D, 0x39}, 0x50},
    {MAP_22_CC_INSIDE_CLANKER,    {0x78, 0x6D, 0x39}, 0x50},
    {MAP_31_RBB_RUSTY_BUCKET_BAY, {0x32, 0x32, 0x32}, 0xA0},
    {MAP_8B_RBB_ANCHOR_ROOM,      {0x32, 0x32, 0x32}, 0xA0},
    {MAP_35_RBB_WAREHOUSE,        {0x32, 0x32, 0x32}, 0xA0},
    {0x00,                        {0x34, 0x6E, 0xEF}, 0x5A}
};

/* .bss */
struct {
    Struct_core2_37E50_0 *unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
}D_8037DA80;

/* .code */
Struct_core2_37E50_0 *func_802BEDE0(enum map_e map_id){
    u8 *temp_v1;
    u8 temp_v0;
    u8 phi_v0;
    u8 *phi_v1;
    u8 *phi_v1_2;
    Struct_core2_37E50_0 *iPtr;

    phi_v1 = &D_80365D60;
    phi_v1_2 = &D_80365D60;
    for(iPtr = D_80365D60; iPtr->map_id != 0; iPtr++){
        if(map_id == iPtr->map_id){
            return iPtr;
        }
    }
    return iPtr;
}

void func_802BEE2C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 sp44;
    s32 i;
    f32 phi_f2;
    s32 sp30[3];

    if (!D_8037DA80.unkC)
        return;

    phi_f2 = (3000.0f < D_8037DA80.unk4) ? 1.0f : D_8037DA80.unk4 / 3000.0f;
    for(i = 0; i < 3; i++){
        sp30[i] = D_8037DA80.unk0->rgb[i] + phi_f2 * 0.4*(-D_8037DA80.unk0->rgb[i]);
    }
    sp44 = D_8037DA80.unk0->alpha * phi_f2 + D_8037DA80.unk0->alpha;
    gcbound_reset();
    gcbound_alpha(sp44);
    gcbound_color(sp30[0], sp30[1], sp30[2]);
    gcbound_draw(gfx);
}

bool func_802BEF58(void){
    return D_8037DA80.unk8;
}

bool func_802BEF64(void){
    return D_8037DA80.unkC;
}

void func_802BEF70(void){}

void func_802BEF78(void){
    D_8037DA80.unk0 = func_802BEDE0(map_get());
    D_8037DA80.unk8 = 0;
    D_8037DA80.unkC = 0;
}

void func_802BEFB0(void) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    Struct5Es *temp_v0;

    if (level_get() == LEVEL_D_CUTSCENE) {
        D_8037DA80.unk8 = 0;
        D_8037DA80.unkC = 0;
        return;
    }
    D_8037DA80.unk10 += time_getDelta();
    viewport_getPosition_vec3f(sp30);
    sp24[0] = sp30[0];
    sp24[1] = sp30[1] + 10000.0f;
    sp24[2] = sp30[2];
    D_8037DA80.unkC = (func_80309B48(sp30, sp24, sp3C, 0xF800FF0F) != NULL);
    if (D_8037DA80.unkC) {
        D_8037DA80.unk8 = 1;
        D_8037DA80.unk4 = sp24[1] - sp30[1];
        return;
    }
    sp24[0] = sp30[0];
    sp24[1] = sp30[1] - 200.0f;
    sp24[2] = sp30[2];
    temp_v0 = func_80309B48(sp30, sp24, sp3C, 0xF800FF0F);
    D_8037DA80.unk8 = (temp_v0 != NULL) && (temp_v0->unk8 & 0x1E0000);
}
