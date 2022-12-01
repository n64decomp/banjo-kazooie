#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8024CE60(f32, f32);

typedef struct {
    s16 model_id;
    // u8 pad2[0x2];
    f32 scale;
    f32 rotation_speed;
}SkyInfo;

typedef struct {
    s16 map;
    // u8 pad2[2];
    SkyInfo sky_list[3];
}MapSkyInfo;

/* .data */
MapSkyInfo D_8036BD40[] = {
    {MAP_94_CS_INTRO_SPIRAL_7,        {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2, {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1, {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_95_CS_END_ALL_100,           {{ASSET_7CD_MODEL_SKYBOX_BEACH_ENDING,  1.0f, 0.0f}}},
    {MAP_20_CS_END_NOT_100,           {{ASSET_7CD_MODEL_SKYBOX_BEACH_ENDING,  1.0f, 0.0f}}},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,  {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_8C_SM_BANJOS_HOUSE,          {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_96_CS_END_BEACH_1,           {{ASSET_7CD_MODEL_SKYBOX_BEACH_ENDING,  1.0f, 0.0f}}},
    {MAP_97_CS_END_BEACH_2,           {{ASSET_7CD_MODEL_SKYBOX_BEACH_ENDING,  1.0f, 0.0f}}},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,     {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,     {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,     {{ASSET_7CC_MODEL_SKYBOX_GRUNTYS_FALL,  1.0f, 0.0f}}},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,     {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}}, 
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,     {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_75_GL_MMM_LOBBY,             {{ASSET_7CB_MODEL_CLOUDS_LAIR_MMM,  1.0f, 0.5f}, {ASSET_7CA_MODEL_SKYBOX_LAIR_MMM, 1.0f, 6.0f}}},
    {MAP_1F_CS_START_RAREWARE,        {{ASSET_7C9_MODEL_SKYBOX_INTRO_N64,  1.0f, 0.0f}}},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   {{ASSET_7BF_MODEL_SKYBOX_TTC,  1.0f, 0.0f}, {ASSET_7C0_MODEL_CLOUDS_TTC,  2.0f, 0.5f}}},
    {MAP_12_GV_GOBIS_VALLEY,          {{ASSET_7C1_MODEL_SKYBOX_GV,  1.0f, 0.0f}, {0x000,  1.0f, 1.0f}}},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,  {{ASSET_7C2_MODEL_SKYBOX_MMM,  1.0f, 0.0f}, {ASSET_7C3_MODEL_SKYBOX_MMM,  1.0f, 0.0f}}},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        {{ASSET_7BD_MODEL_SKYBOX_MM,  1.0f, 0.0f}, {ASSET_7BE_MODEL_CLOUDS_MM,  1.0f, 1.0f}}},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     {{ASSET_7C5_MODEL_SKYBOX_RBB,  1.0f, 0.0f}}},
    {MAP_1_SM_SPIRAL_MOUNTAIN,        {{ASSET_7C4_MODEL_SKYBOX_SM,  1.0f, 0.0f}}},
    {MAP_3_UNUSED,                    {{ASSET_7BF_MODEL_SKYBOX_TTC,  1.0f, 0.0f}, {ASSET_7C0_MODEL_CLOUDS_TTC,  2.0f, 0.5f}}},
    {MAP_27_FP_FREEZEEZY_PEAK,        {{ASSET_7C6_MODEL_SKYBOX_FP,  1.0f, 1.0f}, {ASSET_7C7_MODEL_CLOUDS_FP_A,  1.0f, 1.5f}, {ASSET_7C8_MODEL_CLOUDS_FP_B,  1.0f, 3.0f}}},
    {MAP_C_MM_TICKERS_TOWER,          {{ASSET_7BD_MODEL_SKYBOX_MM,  1.0f, 0.5f}}},
    0
};

/* .bss */
struct  
{
    MapSkyInfo *sky_info;
    BKModel *model[3];
    BKModelBin *model_bins[3];
    f32 timer;
}gcSky;

/* .code */
MapSkyInfo * sky_getMapSkyInfo(enum map_e map_id){
    MapSkyInfo * v1 = D_8036BD40;
    while(v1->map){
        if(map_id == v1->map){
            return v1;
        }
        v1++;
    }
    return v1;
}

void sky_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    int i;
    f32 position[3];
    f32 rotation[3];
    BKModelBin *iAsset;

    func_8024CE60(5.0f, 15000.0f);
    if(gcSky.model_bins[0]){
        func_80254084(gfx, 0, 0, (s32)(f32) framebuffer_width, (s32)(f32)framebuffer_height,0, 0, 0); //fill screen with black
        func_8024C904(gfx, mtx);
        func_8024C5CC(position);
        for(i = 0; i < 3; i++){
            iAsset = gcSky.model_bins[i];
            if(iAsset){
                rotation[0] = 0.0f;
                rotation[1] = gcSky.sky_info->sky_list[i].rotation_speed * gcSky.timer;
                rotation[2] = 0.0f;
                modelRender_draw(gfx, mtx, position, rotation, gcSky.sky_info->sky_list[i].scale, NULL, iAsset);
            }
        }
    }
    else{//L8030B200
        func_80254084(gfx, 0, 0, (s32)(f32) framebuffer_width, (s32)(f32)framebuffer_height, 0, 0, 0);
    }//L8030B254
}

void sky_free(void){
    int i;

    for(i = 0; i < 3; i++){
        if(gcSky.model[i]){
            model_free(gcSky.model[i]);
        }

        if(gcSky.model_bins[i]){
            assetcache_release(gcSky.model_bins[i]);
        }
    }
}

void sky_reset(void){
    int i;

    gcSky.sky_info = sky_getMapSkyInfo(map_get());
    for(i = 0; i< 3; i++){
        gcSky.model[i] = NULL;
        gcSky.model_bins[i] = NULL;
        if(gcSky.sky_info->sky_list[i].model_id){
            gcSky.model_bins[i] = assetcache_get(gcSky.sky_info->sky_list[i].model_id);
            if(func_8033A0B0(gcSky.model_bins[i])){
                gcSky.model[i] = func_8033F5F8(func_8033A0B0(gcSky.model_bins[i]), func_8033A148( gcSky.model_bins[i]));
                func_8034C6DC(gcSky.model[i]);
            }
        }
    }
    gcSky.timer = 0.0f;
}

void sky_update(void){
    gcSky.timer += time_getDelta();
}
