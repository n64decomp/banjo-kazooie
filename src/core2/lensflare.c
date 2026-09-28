// lens flare

#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern bool player_isInFirstPersonView(f32, f32);

enum Lensflare
{
    LENSFLARE_0_STANDARD,
    LENSFLARE_1_TEST,
    // Goes unused, defaults to LENSFLARE_0_STANDARD instead?
    // See: lensflare_get_params
    LENSFLARE_2_INTRO_SCREEN
};

typedef struct
{
    // How much along the direction vector it is, with 1 being approximately the whole screen (?)
    f32 offsetFraction;
    s32 rgba[4];
    // Size of the shape itself
    f32 scale;
} Struct_core2_C97F0_2;

typedef struct
{
    u8 effectIdx;
    Struct_core2_C97F0_2 frames[15];
} Struct_core2_C97F0_1;

typedef struct
{
    s16 map;
    f32 origin[3];
    u8  effectIdx;
} Struct_core2_C97F0_0;

/* .data */
Struct_core2_C97F0_1 lensflare_params[] =
{
    /**
     * Used by Morten's test map. Looks like a very simple effect,
     * going through the primary colours and magenta, decreasing
     * linearly in size
     */
    {
        LENSFLARE_1_TEST,
        {
            /* One row for each circle/shape drawn by the lens flare */
            {0.01f, {0xFF, 0xFF, 0xFF, 0x80}, 1.0f,},
            {0.25f, {0xFF, 0x00, 0x00, 0x80}, 0.75f},
            {0.5f,  {0x00, 0xFF, 0x00, 0x80}, 0.5f},
            {0.75f, {0x00, 0x00, 0xFF, 0x80}, 0.25f},
            {1.0f,  {0xFF, 0x00, 0xFF, 0x80}, 0.1f},
            0
        }
    },
    {
        LENSFLARE_0_STANDARD,
        {
            {0.15f, {0xFF, 0xFF, 0xFF, 0x80}, 0.2f},
            {0.25f, {0xDC, 0xD2, 0xDC, 0xD2}, 0.35f},
            {0.32f, {0xFF, 0xFF, 0xFF, 0x5A}, 0.7f},
            {0.45f, {0xD2, 0xFF, 0xD7, 0x78}, 0.3f},
            {0.56f, {0xC8, 0xFF, 0xFF, 0x96}, 0.9f},
            {0.69f, {0xFF, 0xD2, 0xFF, 0x6E}, 0.45f},
            {0.78f, {0xDC, 0xFF, 0xFF, 0x73}, 0.28f}, 
            {0.84f, {0xFF, 0xE6, 0xFF, 0xC8}, 0.55f},
            {1.05f, {0xC8, 0xFF, 0xFF, 0x64}, 0.4f}, 
            {1.15f, {0xFF, 0xC8, 0xFF, 0x96}, 0.22f},
            0
        }
    },
    {
        LENSFLARE_2_INTRO_SCREEN,
        {
            {0.15f, {0xFF, 0x00, 0x00, 0xC8}, 0.2f}, 
            {0.25f, {0xDC, 0xD2, 0xDC, 0xD2}, 0.35f}, 
            {0.32f, {0xFF, 0xFF, 0xFF, 0xA0}, 0.7f}, 
            {0.45f, {0xD2, 0xF0, 0xBE, 0xDC}, 0.3f}, 
            {0.56f, {0xC8, 0xFF, 0xFF, 0xBE}, 0.9f}, 
            {0.69f, {0xFF, 0xD2, 0xFF, 0xA0}, 0.45f}, 
            {0.78f, {0xDC, 0xFF, 0xFF, 0x8C}, 0.28f}, 
            {0.84f, {0xFF, 0xE6, 0xFF, 0xFF}, 0.55f},
            {1.05f, {0xC8, 0xFF, 0xFF, 0xBE}, 0.4f}, 
            {1.15f, {0xFF, 0xC8, 0xFF, 0x96}, 0.22f}, 
            0
        }
    }
};

// All "sunny" maps. Makes sense for a lens flare effect
Struct_core2_C97F0_0 lensflare_definitions[] =
{
    {MAP_95_CS_END_ALL_100,         {  48.0f,  10.0f,  -51.0f},      LENSFLARE_0_STANDARD}, 
    {MAP_20_CS_END_NOT_100,         {  48.0f,  10.0f,  -51.0f},      LENSFLARE_0_STANDARD},
    {MAP_96_CS_END_BEACH_1,         {  48.0f,  10.0f,  -51.0f},      LENSFLARE_0_STANDARD},
    {MAP_97_CS_END_BEACH_2,         {  48.0f,  10.0f,  -51.0f},      LENSFLARE_0_STANDARD},
    {MAP_7_TTC_TREASURE_TROVE_COVE, {  52.0f,  24.0f,  -21.0f},      LENSFLARE_0_STANDARD},
    {MAP_12_GV_GOBIS_VALLEY,        {-358.74f, 90.8f,  306.8f},      LENSFLARE_0_STANDARD},
    {MAP_1F_CS_START_RAREWARE,      { -61.8f,  -3.64f, -42.921f},    LENSFLARE_2_INTRO_SCREEN},
    {MAP_4_STUB_TEST_MB,            {   0.0f,  24.0f,  -21.0f},      LENSFLARE_1_TEST},
    0
};

s32 D_803725A8[4] = {0, 0, 0, 0};

/* .bss */
struct
{
    Struct_core2_C97F0_1 *params;
    Struct_core2_C97F0_0 *definition;
    void *asset;
} sLensflareData;
struct
{
    u8 toDraw;
    u8 unk1;
} D_8038617C;

/* .code */
Struct_core2_C97F0_1 *lensflare_get_params(s32 arg0)
{
    Struct_core2_C97F0_1 *e;

    /**
     * For whatever reason, reading effect 0 breaks the loop, effectively
     * forcing any effects after it (LENSFLARE_2_INTRO_SCREEN) to use
     * effect 0 instead.
     */
    for (e = lensflare_params; e->effectIdx != LENSFLARE_0_STANDARD; e++)
        if (arg0 == e->effectIdx)
            return e;

    return e;
}

Struct_core2_C97F0_0 *lensflare_get_definition(enum map_e map_id)
{
    Struct_core2_C97F0_0 *e;

    for (e = lensflare_definitions; e->map != MAP_0_NIL; e++)
        if (map_id == e->map)
            return e;

    return NULL;
}

void lensflare_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx)
{
    f32 spDC[3];
    f32 spD0[3];
    f32 spC4[3];
    f32 spB8[3];
    Struct_core2_C97F0_0 *definition;
    Struct_core2_C97F0_1 *params;
    f32 var_f22;
    s32 i;
    f32 sp9C[3];
    f32 sp90[3];
    s32 sp80[4];

    params = sLensflareData.params;
    if (params)
        ;

    definition = sLensflareData.definition;
    if (definition && D_8038617C.toDraw)
    {
        viewport_getPosition_vec3f(spDC);
        viewport_getRotation_vec3f(spD0);
        sp9C[0] = definition->origin[0];
        sp9C[1] = definition->origin[1];
        sp9C[2] = definition->origin[2];
        ml_vec3f_yaw_rotate_copy(sp9C, sp9C, -spD0[1]);
        ml_vec3f_pitch_rotate_copy(sp9C, sp9C, -spD0[0]);

        if (!(((1.2 * (f32)gFramebufferWidth) / 2) < sp9C[0]) && !(sp9C[0] < ((-1.2 * (f32)gFramebufferWidth) / 2)))
        {
            if (!(((1.2 * (f32)gFramebufferHeight) / 2) < sp9C[1]) && !(sp9C[1] < ((-1.2 * (f32)gFramebufferHeight) / 2)))
            {
                sp90[0] = -sp9C[0];
                sp90[1] = -sp9C[1];
                sp90[2] =  sp9C[2];
                ml_vec3f_pitch_rotate_copy(sp90, sp90, spD0[0]);
                ml_vec3f_yaw_rotate_copy(sp90, sp90, spD0[1]);
                var_f22 = 1.0f - (((sp9C[0] * sp9C[0]) + (sp9C[1] * sp9C[1])) / ((f32)gFramebufferHeight * (f32)gFramebufferHeight));

                if (var_f22 < 0.0f)
                    var_f22 = 0.0f;

                if (var_f22 > 1.0f)
                    var_f22 = 1.0f;

                spC4[0] = sp90[0] - definition->origin[0];
                spC4[1] = sp90[1] - definition->origin[1];
                spC4[2] = sp90[2] - definition->origin[2];

                for (i = 0; params->frames[i].offsetFraction != 0.0f; i++)
                {
                    spB8[0] = (spDC[0] + definition->origin[0]) + (params->frames[i].offsetFraction * spC4[0]);
                    spB8[1] = (spDC[1] + definition->origin[1]) + (params->frames[i].offsetFraction * spC4[1]);
                    spB8[2] = (spDC[2] + definition->origin[2]) + (params->frames[i].offsetFraction * spC4[2]);
                    sp80[0] = params->frames[i].rgba[0];
                    sp80[1] = params->frames[i].rgba[1];
                    sp80[2] = params->frames[i].rgba[2];
                    sp80[3] = params->frames[i].rgba[3];
                    sp80[3] *= var_f22;
                    modelRender_setPrimAndEnvColors(sp80, D_803725A8);
                    modelRender_draw(gfx, mtx, spB8, spD0, params->frames[i].scale * 0.25, NULL, sLensflareData.asset);
                }
            }
        }
    }
}

void lensflare_free(void)
{
    if (sLensflareData.definition != NULL)
        assetcache_release(sLensflareData.asset);
}

void lensflare_init(void)
{
    sLensflareData.definition = lensflare_get_definition(gsworld_getMap());
    if (sLensflareData.definition != NULL)
    {
        sLensflareData.params = lensflare_get_params(sLensflareData.definition->effectIdx);
        sLensflareData.asset = assetcache_get(0x882);
        ml_vec3f_set_length(sLensflareData.definition->origin, (2*(f32)gFramebufferWidth) / 2);
        D_8038617C.toDraw = TRUE;
        D_8038617C.unk1 = 0;
    }
}

void lensflare_update(void)
{
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    s32 var_v0;

    if (sLensflareData.definition)
    {
        viewport_getPosition_vec3f(sp54);
        sp48[0] = sLensflareData.definition->origin[0];
        sp48[1] = sLensflareData.definition->origin[1];
        sp48[2] = sLensflareData.definition->origin[2];
        ml_vec3f_set_length(sp48, 1000);
        sp30[0] = sp54[0] + (sp48[0] * D_8038617C.unk1);
        sp30[1] = sp54[1] + (sp48[1] * D_8038617C.unk1);
        sp30[2] = sp54[2] + (sp48[2] * D_8038617C.unk1);
        sp24[0] = sp30[0] + sp48[0];
        sp24[1] = sp30[1] + sp48[1];
        sp24[2] = sp30[2] + sp48[2];

        if (player_isInFirstPersonView(sp48[1], sp48[2]))
            var_v0 = func_80320B98(&sp30, &sp24, &sp3C, 0x01000000);
        else
            var_v0 = mapModel_intersectLine(&sp30, &sp24, &sp3C, 0x01000000);

        if (var_v0)
        {
            D_8038617C.toDraw = FALSE;
            D_8038617C.unk1 = 0;
        }
        else
        {
            D_8038617C.unk1++;

            if (D_8038617C.unk1 >= 0xB)
            {
                D_8038617C.toDraw = TRUE;
                D_8038617C.unk1 = 0;
            }
        }
    }
}
