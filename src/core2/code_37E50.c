#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

/* colour of the full-screen tint drawn while the camera is underwater */
typedef struct{
    u8 map_id;
    u8 rgb[3];
    u8 alpha;
}UnderwaterTint;

/* per-map tints; the last entry (map 0) is the default */
UnderwaterTint sCore2_37E50UnderwaterTints[] ={
    {MAP_3_STUB_TEST_TEMPLE,      {0x00, 0xD0, 0xBF}, 0x50},
    {MAP_B_CC_CLANKERS_CAVERN,    {0x78, 0x6D, 0x39}, 0x50},
    {MAP_22_CC_INSIDE_CLANKER,    {0x78, 0x6D, 0x39}, 0x50},
    {MAP_31_RBB_RUSTY_BUCKET_BAY, {0x32, 0x32, 0x32}, 0xA0},
    {MAP_8B_RBB_ANCHOR_ROOM,      {0x32, 0x32, 0x32}, 0xA0},
    {MAP_35_RBB_WAREHOUSE,        {0x32, 0x32, 0x32}, 0xA0},
    {0x00,                        {0x34, 0x6E, 0xEF}, 0x5A}
};

/* .bss */
struct {
    UnderwaterTint *tint;
    f32 depth;              // distance from the camera up to the water surface
    s32 camera_near_water;  // camera underwater, or less than 200 units above a water surface
    s32 camera_underwater;
    f32 timer_sec;          // counts up every frame outside cutscenes; never reset or read
}sCore2_37E50Underwater;

/* .code */
UnderwaterTint *core2_37E50_getUnderwaterTint(enum map_e map_id){
    u8 *temp_v1;
    u8 temp_v0;
    u8 phi_v0;
    u8 *phi_v1;
    u8 *phi_v1_2;
    UnderwaterTint *iPtr;

    phi_v1 = &sCore2_37E50UnderwaterTints;
    phi_v1_2 = &sCore2_37E50UnderwaterTints;
    for(iPtr = sCore2_37E50UnderwaterTints; iPtr->map_id != 0; iPtr++){
        if(map_id == iPtr->map_id){
            return iPtr;
        }
    }
    return iPtr;
}

/* draws the underwater tint, darker the deeper the camera is (up to 3000 units) */
void core2_37E50_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 sp44;
    s32 i;
    f32 phi_f2;
    s32 sp30[3];

    if (!sCore2_37E50Underwater.camera_underwater)
        return;

    phi_f2 = (3000.0f < sCore2_37E50Underwater.depth) ? 1.0f : sCore2_37E50Underwater.depth / 3000.0f;
    for(i = 0; i < 3; i++){
        sp30[i] = sCore2_37E50Underwater.tint->rgb[i] + phi_f2 * 0.4*(-sCore2_37E50Underwater.tint->rgb[i]);
    }
    sp44 = sCore2_37E50Underwater.tint->alpha * phi_f2 + sCore2_37E50Underwater.tint->alpha;
    gcbound_reset();
    gcbound_alpha(sp44);
    gcbound_color(sp30[0], sp30[1], sp30[2]);
    gcbound_draw(gfx);
}

bool core2_37E50_isCameraNearWater(void){
    return sCore2_37E50Underwater.camera_near_water;
}

bool core2_37E50_isCameraUnderwater(void){
    return sCore2_37E50Underwater.camera_underwater;
}

void func_802BEF70(void){}

void core2_37E50_reset(void){
    sCore2_37E50Underwater.tint = core2_37E50_getUnderwaterTint(gsworld_getMap());
    sCore2_37E50Underwater.camera_near_water = 0;
    sCore2_37E50Underwater.camera_underwater = 0;
}

/* casts a ray 10000 units up from the camera; with the 0xF800FF0F filter only the translucent
 * model is tested and surfaces with a footstep type are skipped (see mapModel_getWaterSurfaceY),
 * so a hit means the camera is underwater */
void core2_37E50_update(void) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    Struct5Es *temp_v0;

    if (level_get() == LEVEL_D_CUTSCENE) {
        sCore2_37E50Underwater.camera_near_water = 0;
        sCore2_37E50Underwater.camera_underwater = 0;
        return;
    }
    sCore2_37E50Underwater.timer_sec += time_getDelta();
    viewport_getPosition_vec3f(sp30);
    sp24[0] = sp30[0];
    sp24[1] = sp30[1] + 10000.0f;
    sp24[2] = sp30[2];
    sCore2_37E50Underwater.camera_underwater = (mapModel_intersectLine(sp30, sp24, sp3C, 0xF800FF0F) != NULL);
    if (sCore2_37E50Underwater.camera_underwater) {
        sCore2_37E50Underwater.camera_near_water = 1;
        sCore2_37E50Underwater.depth = sp24[1] - sp30[1];
        return;
    }
    sp24[0] = sp30[0];
    sp24[1] = sp30[1] - 200.0f;
    sp24[2] = sp30[2];
    temp_v0 = mapModel_intersectLine(sp30, sp24, sp3C, 0xF800FF0F);
    sCore2_37E50Underwater.camera_near_water = (temp_v0 != NULL) && (temp_v0->unk8 & 0x1E0000);
}
