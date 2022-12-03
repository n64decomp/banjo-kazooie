#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/modelRender.h"

extern UNK_TYPE(s32) func_802E8E88(BKCollisionList *, BKVertexList *, f32[3], f32[3], f32, f32[3], s32, s32);
extern UNK_TYPE(s32) func_802E92AC(BKCollisionList *, BKVertexList *, f32[3], f32, f32[3], s32);
extern s32 func_802EC394(BKModelUnk14List *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern void vtxList_getBounds_s32(BKVertexList *, s32[3], s32[3]);
extern void func_802F7BC0(Gfx **, Mtx **, Vtx **);
extern void func_8033A45C(s32, s32);


BKCollisionTri *func_80309B48(f32 arg0[3], f32 arg1[3], f32 arg2[3], s32 arg3) ;

typedef struct {
    s16 map_id; //enum map_e
    s16 opa_model_id; //enum asset_e level_model_id
    s16 xlu_model_id; //enum asset_e level2_model_id
    s16 unk6[3];
    s16 unkC[3];
    // u8 pad12[0x2];
    f32 scale;
}MapModelDescription;

/* .data */
MapModelDescription D_8036ABE0[] = {
    {MAP_1_SM_SPIRAL_MOUNTAIN,          0x14CF, 0x14D0,   {1, 0, 1},  {-3, -4, -2}, 1.0f},
    {MAP_2_MM_MUMBOS_MOUNTAIN,          0x14AA, 0x14AB,   {1, 0, 2},   {-2, 0, -2}, 1.0f},
    {MAP_5_TTC_BLUBBERS_SHIP,           0x146F, 0x1470,   {0, 0, 0},     {0, 0, 0}, 1.0f},
    {MAP_6_TTC_NIPPERS_SHELL,           0x146D, 0x146E,   {0, 0, 0},     {0, 0, 0}, 1.0f},
    {MAP_7_TTC_TREASURE_TROVE_COVE,     0x146B, 0x146C, {11, 2, 12}, {-12, -4, -5}, 1.0f},
    {MAP_8F_TTC_SHARKFOOD_ISLAND,       0x1473,      0,   {0, 0, 0},     {0, 0, 0}, 1.0f},
    {MAP_A_TTC_SANDCASTLE,              0x1471, 0x1472,   {0, 0, 0},     {0, 0, 0}, 1.0f},
    {MAP_B_CC_CLANKERS_CAVERN,          0x14ED, 0x14EE, {0, 0, 0}, {0, -2, -1}, 1.0f},
    {MAP_C_MM_TICKERS_TOWER,            0x14AC, 0x14AD, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,       0x14D1, 0x14D2, {0, 1, 1}, {-1, -1, -1}, 1.0f},
    {MAP_E_MM_MUMBOS_SKULL,             0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_10_BGS_MR_VILE,                0x14D3,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_11_BGS_TIPTUP,                 0x14D4, 0x14D5, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_12_GV_GOBIS_VALLEY,            0x1474, 0x1475, {4, 0, 4}, {-4, -4, -5}, 1.0f},
    {MAP_92_GV_SNS_CHAMBER,             0x147E,      0, {0, 1, 0}, {0, -1, 0}, 1.0f},
    {MAP_13_GV_MEMORY_GAME,             0x1476,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_14_GV_SANDYBUTTS_MAZE,         0x1478, 0x1479, {0, 0, 1}, {0, -2, 0}, 1.0f},
    {MAP_15_GV_WATER_PYRAMID,           0x147A, 0x147B, {0, 1, 0}, {0, 0, -1}, 1.0f},
    {MAP_16_GV_RUBEES_CHAMBER,          0x147C,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_1A_GV_INSIDE_JINXY,            0x147D,      0, {0, 1, 1}, {0, 0, 0}, 1.0f},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,    0x147F, 0x1480, {2, 0, 2}, {-3, 1, -2}, 1.0f},
    {MAP_1C_MMM_CHURCH,                 0x1486, 0x1487, {0, 0, 0}, {0, -1, 0}, 1.0f},
    {MAP_1D_MMM_CELLAR,                 0x1482, 0x149B, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_1E_CS_START_NINTENDO,          0x149D, 0x14A1, {0, 1, 0}, {0, -1, 0}, 1.0f},
    {MAP_1F_CS_START_RAREWARE,          0x149E, 0x14A0, {-1, -1, 1}, {1, 1, 1}, 1.0f},
    {MAP_20_CS_END_NOT_100,             0x14A9, 0x14A5, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_21_CC_WITCH_SWITCH_ROOM,       0x14EF,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_22_CC_INSIDE_CLANKER,          0x14F0, 0x14F1, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_23_CC_GOLDFEATHER_ROOM,        0x14F2,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_24_MMM_TUMBLARS_SHED,          0x1488,      0, {0, 1, 0}, {0, -1, 0}, 1.0f},
    {MAP_25_MMM_WELL,                   0x1495, 0x1496, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_26_MMM_NAPPERS_ROOM,           0x1485, 0x149A, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_27_FP_FREEZEEZY_PEAK,          0x14C8, 0x14C9, {2, 0, 2}, {-1, -1, -2}, 1.0f},
    {MAP_28_MMM_EGG_ROOM,               0x1489, 0x148A, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_29_MMM_NOTE_ROOM,              0x148B, 0x148C, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_2A_MMM_FEATHER_ROOM,           0x148D, 0x148E, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,     0x1483, 0x1484, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_2C_MMM_BATHROOM,               0x148F, 0x1490, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_2D_MMM_BEDROOM,                0x1491, 0x1492, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_2E_MMM_HONEYCOMB_ROOM,         0x1493, 0x1494, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_2F_MMM_WATERDRAIN_BARREL,      0x1481, 0x1497, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_30_MMM_MUMBOS_SKULL,           0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_8D_MMM_INSIDE_LOGGO,           0x1498, 0x1499, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,       0x14B0, 0x14B1, {8, 0, 3}, {-2, -8, -7}, 1.0f},
    {MAP_8B_RBB_ANCHOR_ROOM,            0x14C5, 0x14C6, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_34_RBB_ENGINE_ROOM,            0x14B2, 0x14B3, {0, 0, 0}, {0, -3, 0}, 1.0f},
    {MAP_35_RBB_WAREHOUSE,              0x14B4, 0x14B5, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_36_RBB_BOATHOUSE,              0x14B6, 0x14B7, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_37_RBB_CONTAINER_1,            0x14B8,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_38_RBB_CONTAINER_3,            0x14BA,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_39_RBB_CREW_CABIN,             0x14BD,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_3A_RBB_BOSS_BOOM_BOX,          0x14BE, 0x14BF, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_3B_RBB_STORAGE_ROOM,           0x14C1, 0x14C2, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_3C_RBB_KITCHEN,                0x14C3, 0x14C4, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_3D_RBB_NAVIGATION_ROOM,        0x14C0, 0x14C7, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_3E_RBB_CONTAINER_2,            0x14B9,      0, {0, 0, 0}, {0, 1, 0}, 1.0f},
    {MAP_3F_RBB_CAPTAINS_CABIN,         0x14BB, 0x14BC, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_40_CCW_HUB,                    0x14D8, 0x14E3, {0, 0, 0}, {0, -3, 0}, 1.0f},
    {MAP_41_FP_BOGGYS_IGLOO,            0x14CA, 0x14CE, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_7F_FP_WOZZAS_CAVE,             0x14CC, 0x14CD, {0, 0, 0}, {0, -1, 0}, 1.0f},
    {MAP_43_CCW_SPRING,                 0x14D9, 0x14E4, {1, 0, 1}, {-1, -5, 0}, 1.0f},
    {MAP_44_CCW_SUMMER,                 0x14DA, 0x14E5, {1, 0, 1}, {-1, -5, 0}, 1.0f},
    {MAP_45_CCW_AUTUMN,                 0x14DB, 0x14E6, {1, 0, 1}, {-1, -6, 0}, 1.0f},
    {MAP_46_CCW_WINTER,                 0x14DC, 0x14E7, {1, 0, 1}, {-1, -5, 0}, 1.0f},
    {MAP_47_BGS_MUMBOS_SKULL,           0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_48_FP_MUMBOS_SKULL,            0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_4A_CCW_SPRING_MUMBOS_SKULL,    0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_4B_CCW_SUMMER_MUMBOS_SKULL,    0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_4C_CCW_AUTUMN_MUMBOS_SKULL,    0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_4D_CCW_WINTER_MUMBOS_SKULL,    0x14AE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_53_FP_CHRISTMAS_TREE,          0x14CB,      0, {2, 1, 2}, {-2, -1, -2}, 1.0f},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,      0x14DD,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,      0x14DD,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,      0x14DD,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,   0x14DE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,   0x14DE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,   0x14DE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE,   0x14DE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_62_CCW_WINTER_HONEYCOMB_ROOM,  0x14E0,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, 0x14E1, 0x14E2, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, 0x14E1, 0x14E2, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_65_CCW_SPRING_WHIPCRACK_ROOM,  0x14DF,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,  0x14DF,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,  0x14DF,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_68_CCW_WINTER_WHIPCRACK_ROOM,  0x14DF,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_69_GL_MM_LOBBY,                0x14F3, 0x150B, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_6A_GL_TTC_AND_CC_PUZZLE,       0x14F4, 0x150C, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_6B_GL_180_NOTE_DOOR,           0x14F5, 0x1510, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_6C_GL_RED_CAULDRON_ROOM,       0x14F6, 0x150D, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_6D_GL_TTC_LOBBY,               0x14F7, 0x1512, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_6E_GL_GV_LOBBY,                0x14F8, 0x14A8, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_6F_GL_FP_LOBBY,                0x14F9, 0x14FA, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_74_GL_GV_PUZZLE,               0x14FD,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_70_GL_CC_LOBBY,                0x14FB, 0x1507, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_75_GL_MMM_LOBBY,               0x14FE,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_7A_GL_CRYPT,                   0x14FF,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_71_GL_STATUE_ROOM,             0x1500, 0x150E, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_72_GL_BGS_LOBBY,               0x1501, 0x1511, {1, 0, 1}, {0, -2, -1}, 1.0f},
    {MAP_76_GL_640_NOTE_DOOR,           0x1502, 0x1508, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_77_GL_RBB_LOBBY,               0x1503, 0x1509, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_78_GL_RBB_AND_MMM_PUZZLE,      0x1504, 0x150A, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_79_GL_CCW_LOBBY,               0x1505,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_80_GL_FF_ENTRANCE,             0x1506, 0x1514, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_93_GL_DINGPOT,                 0x150F, 0x1513, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_90_GL_BATTLEMENTS,             0x14FC, 0x1515, {6, 2, 7}, {-6, -3, -5}, 1.0f},
    {MAP_7B_CS_INTRO_GL_DINGPOT_1,      0x150F,      0, {0, 0, 0}, {0, -1, 0}, 1.6666666f},
    {MAP_7C_CS_INTRO_BANJOS_HOUSE_1,    0x14A2,      0, {0, 0, 0}, {0, 0, 0}, 1.6666666f},
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,       0x14CF, 0x14D0, {0, 0, 2}, {0, -4, -2}, 1.0f},
    {MAP_7E_CS_SPIRAL_MOUNTAIN_2,       0x14CF, 0x14D0, {0, 0, 2}, {0, -4, -2}, 1.0f},
    {MAP_81_CS_INTRO_GL_DINGPOT_2,      0x150F,      0, {0, 0, 0}, {0, -1, 0}, 1.6666666f},
    {MAP_82_CS_ENTERING_GL_MACHINE_ROOM, 0x150F,     0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_83_CS_GAME_OVER_MACHINE_ROOM,  0x150F,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_84_CS_UNUSED_MACHINE_ROOM,     0x150F,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,       0x14CF, 0x14D0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,       0x14CF, 0x14D0, {0, 0, 0}, {0, -4, 0}, 1.0f},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,       0x14A6,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,       0x14CF, 0x14D0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_94_CS_INTRO_SPIRAL_7,          0x14CF, 0x14D0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1,   0x149F, 0x14A3, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2,   0x149F, 0x14A3, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_95_CS_END_ALL_100,             0x14A9, 0x14A5, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,    0x14A2, 0x14A4, {0, 0, 0}, {0, 0, 0}, 1.6666666f},
    {MAP_8A_CS_INTRO_BANJOS_HOUSE_3,    0x14A2, 0x14A4, {0, 0, 0}, {0, 0, 0}, 1.6666666f},
    {MAP_96_CS_END_BEACH_1,             0x14A9, 0x14A5, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_97_CS_END_BEACH_2,             0x14A9, 0x14A5, {2, 0, -3}, {4, 0, -1}, 1.0f},
    {MAP_91_FILE_SELECT,                0x14A2, 0x14A4, {0, 0, 0}, {0, 0, 0}, 1.6666666f},
    {MAP_8C_SM_BANJOS_HOUSE,            0x14A2, 0x14A4, {0, 0, 0}, {0, 0, 0}, 1.0f},
    {MAP_8E_GL_FURNACE_FUN,             0x14E8,      0, {0, 0, 0}, {0, 0, 0}, 1.0f},
    0
};

/* .bss */
struct {
    void *unk0;
    void *unk4;
    BKCollisionList *collision_opa;
    BKCollisionList *collision_xlu;
    BKModel *model_opa;
    BKModel *model_xlu;
    BKModelBin *model_bin_opa;
    BKModelBin *model_bin_xlu;
    s32 unk20;
    struct5Bs *unk24;
    MapModelDescription *description;
    u8 env_red;
    u8 env_green;
    u8 env_blue;
    f32 scale;
}mapModel;

enum asset_e mapModel_getOpaModelId(void);

/* .code */
static MapModelDescription *_mapModel_mapIdToDescription(enum map_e map_id){
    MapModelDescription *i_ptr;

    for(i_ptr = D_8036ABE0; i_ptr->map_id != 0; i_ptr++){
        if(map_id == i_ptr->map_id){
            return i_ptr;
        }
    }
    return NULL;
}

f32 func_80308FDC(f32 arg0[3], u32 arg1) {
    s32 phi_s2;
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    s32 temp_s1;
    s32 phi_s1;

    sp64[0] = arg0[0];
    sp64[1] = arg0[1];
    sp64[2] = arg0[2];
    sp64[1] += 200.0f;

    sp58[0] = arg0[0];
    sp58[1] = arg0[1];
    sp58[2] = arg0[2];
    sp58[1] -= 2000.0f;
    if (func_80309B48(sp64, sp58, sp70, arg1)) {
        return sp58[1];
    }
    phi_s2 = 150;
    phi_s1 = 1000;
    do{
        sp64[0] = arg0[0];
        sp64[1] = arg0[1];
        sp64[2] = arg0[2];
        sp64[0] += randf2(-1.0f, 1.0f);
        sp64[1] += (f32) phi_s2;
        sp64[2] += randf2(-1.0f, 1.0f);
        sp58[0] = arg0[0];
        sp58[1] = arg0[1];
        sp58[2] = arg0[2];
        sp58[0] += randf2(-1.0f, 1.0f);
        sp58[1] -= (f32) phi_s1;
        sp58[2] += randf2(-1.0f, 1.0f);
        if (func_80309B48(&sp64, &sp58, &sp70, arg1)) {
            return sp58[1];
        }
        phi_s1 += 2000;
        phi_s2 += 300;
    }while(phi_s1!= 51000);
    return 0.0f;
}

void mapModel_opa_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 temp_a0;

    if (func_80320708() && levelSpecificFlags_validateCRC2() && func_80320248()) {
        if (mapModel_getOpaModelId() == ASSET_14CF_MODEL_SM_OPA) {
            func_8033A45C(1, 0);
            func_8033A45C(2, 1);
        }
        switch (map_get()) {                          /* irregular */
        case MAP_88_CS_SPIRAL_MOUNTAIN_6:
            if (mapSpecificFlags_get(0) != 0) {
                func_8033A45C(1, 1);
                func_8033A45C(2, 0);
            }
            break;

        case MAP_12_GV_GOBIS_VALLEY:
            func_8033A45C(1, levelSpecificFlags_get(6) ? 1 : 0);
            func_8033A45C(2, jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID) ? 0 : 1);
            func_8033A45C(5, jiggyscore_isCollected(JIGGY_42_GV_WATER_PYRAMID) ? 1 : 0);
            break;

        case MAP_14_GV_SANDYBUTTS_MAZE:
            func_8033A45C(5, (func_8028ECAC() == 4) ? 1 : 0);
            break;

        case MAP_E_MM_MUMBOS_SKULL:
            func_8033A45C(1, 1);
            func_8033A45C(5, 1);
            break;

        case MAP_47_BGS_MUMBOS_SKULL:
            func_8033A45C(1, 2);
            func_8033A45C(5, 2);
            break;

        case MAP_48_FP_MUMBOS_SKULL:
            func_8033A45C(1, 3);
            func_8033A45C(5, 3);
            break;

        case MAP_30_MMM_MUMBOS_SKULL:
            func_8033A45C(1, 4);
            func_8033A45C(5, 4);
            break;
            
        case MAP_4A_CCW_SPRING_MUMBOS_SKULL:
            func_8033A45C(1, 5);
            func_8033A45C(5, 5);
            break;
        case MAP_4B_CCW_SUMMER_MUMBOS_SKULL:
            func_8033A45C(1, 6);
            func_8033A45C(5, 6);
            break;
        case MAP_4C_CCW_AUTUMN_MUMBOS_SKULL:
            func_8033A45C(1, 7);
            func_8033A45C(5, 7);
            break;
        case MAP_4D_CCW_WINTER_MUMBOS_SKULL:
            func_8033A45C(1, 8);
            func_8033A45C(5, 8);
            break;
        case MAP_5E_CCW_SPRING_NABNUTS_HOUSE:
        case MAP_5F_CCW_SUMMER_NABNUTS_HOUSE:
        case MAP_60_CCW_AUTUMN_NABNUTS_HOUSE:
            func_8033A45C(1, 1);
            func_8033A45C(2, 0);
            break;
        case MAP_61_CCW_WINTER_NABNUTS_HOUSE:
            func_8033A45C(1, 0);
            func_8033A45C(2, 1);
            break;
        case MAP_1D_MMM_CELLAR:
            func_8033A45C(1, actorArray_findActorFromActorId(0x191) ?  0 : 1);
            break;
        case MAP_7C_CS_INTRO_BANJOS_HOUSE_1:
        case MAP_89_CS_INTRO_BANJOS_HOUSE_2:
        case MAP_8A_CS_INTRO_BANJOS_HOUSE_3:
        case MAP_8C_SM_BANJOS_HOUSE:
        case MAP_91_FILE_SELECT:
            func_8033A45C(5, 1);
            break;
        case MAP_7B_CS_INTRO_GL_DINGPOT_1:
        case MAP_81_CS_INTRO_GL_DINGPOT_2:
            func_8033A45C(4, 0);
            func_8033A45C(5, 0);
            func_8033A45C(6, 0);
            break;
        case MAP_82_CS_ENTERING_GL_MACHINE_ROOM:
        case MAP_83_CS_GAME_OVER_MACHINE_ROOM:
        case MAP_84_CS_UNUSED_MACHINE_ROOM:
            func_8033A45C(4, 1);
            func_8033A45C(5, 1);
            func_8033A45C(6, 1);
            break;
        case MAP_93_GL_DINGPOT:
            func_8033A45C(4, 1);
            func_8033A45C(5, 1);
            func_8033A45C(6, (func_8038EAE0(0xA) || func_8031FF1C(0xE2) || func_803203FC(0xC1)));
            break;
        }
        func_8033A450(mapModel.unk24);
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        temp_a0 = mapModel.unk0;
        if (temp_a0 != 0) {
            func_8033A494(temp_a0);
        }
        modelRender_setEnvColor(mapModel.env_red, mapModel.env_green, mapModel.env_blue, 0xFF);
        modelRender_draw(gfx, mtx, NULL, NULL, mapModel.description->scale, NULL, mapModel.model_bin_opa);
        if (!func_80309F78()) {
            func_802F7BC0(gfx, mtx, vtx);
        }
    }
}

void mapModel_xlu_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 temp_a0;

    if (mapModel.model_bin_xlu != NULL) {
        if (map_get() == MAP_1D_MMM_CELLAR) {
            func_8033A45C(1, (actorArray_findActorFromActorId(0x191) != NULL) ? 0 : 1);
        }
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        temp_a0 = mapModel.unk4;
        if (temp_a0 != 0) {
            func_8033A494(temp_a0);
        }
        modelRender_setEnvColor(mapModel.env_red, mapModel.env_green, mapModel.env_blue, 0xFF);
        modelRender_draw(gfx, mtx, NULL, NULL, mapModel.description->scale, NULL, mapModel.model_bin_xlu);
        func_802F7BC0(gfx, mtx, vtx);
    }
}

void func_80309704(s32 arg0, s32 arg1, s32 arg2){}

s32 func_80309714(void){
    return mapModel.collision_opa->unk12;
}

f32 func_80309724(f32 arg0[3]){
    return func_80308FDC(arg0, 0x1e0000);
}

BKModel *mapModel_getModel(s32 arg0){
    return (arg0) ? mapModel.model_xlu : mapModel.model_opa;
}

BKModelBin *mapModel_getModelBin(s32 arg0){
    if(arg0 == 0)
        return mapModel.model_bin_opa;
    if(arg0 == 1)
        return mapModel.model_bin_xlu;
    return 0;
}

s32 func_80309794(void){
    return mapModel.unk20;
}

struct5Bs *func_803097A0(void){
    return mapModel.unk24;
}


void mapModel_getCubeBounds(s32 min[3], s32 max[3]) {
    vtxList_getBounds_s32(func_8033A148(mapModel.model_bin_opa), min, max);
    func_8033ECD8(min, max, 1000);
    min[0] = min[0] + mapModel.description->unk6[0];
    min[1] = min[1] + mapModel.description->unk6[1];
    min[2] = min[2] + mapModel.description->unk6[2];
    max[0] = max[0] + mapModel.description->unkC[0];
    max[1] = max[1] + mapModel.description->unkC[1];
    max[2] = max[2] + mapModel.description->unkC[2];
}

void mapModel_getOpaBounds(s32 min[3], s32 max[3]) {
    s32 i;

    vtxList_getBounds_s32(func_8033A148(mapModel.model_bin_opa), min, max);
    for(i = 0; i < 3; i++){
        min[i] *= mapModel.scale;
        max[i] *= mapModel.scale;
    }
}

void mapModel_getBounds(s32 min[3], s32 max[3]) {
    s32 i, j;
    s32 xlu_min[3];
    s32 xlu_max[3];

    vtxList_getBounds_s32(func_8033A148(mapModel.model_bin_opa), min, max);
    for(i = 0; i < 3; i++){
        min[i] *= mapModel.scale;
        max[i] *= mapModel.scale;
    }

    if (mapModel.model_bin_xlu != NULL) {
        vtxList_getBounds_s32(func_8033A148(mapModel.model_bin_xlu), xlu_min, xlu_max);
        for(j = 0; j < 3; j++){
            if(xlu_min[j] < min[j]){
                min[j] = xlu_min[j];
            }
            if(max[j] < xlu_max[j]){
                max[j] = xlu_max[j];
            }
        }

    }
}

f32 func_80309B24(f32 arg0[3]){
    return func_80308FDC(arg0, 0xf800ff0f);
}

BKCollisionTri *func_80309B48(f32 arg0[3], f32 arg1[3], f32 arg2[3], s32 arg3) {
    BKCollisionTri *sp2C;
    BKCollisionTri *temp_v0;

    mapModel.unk20 = 0;
    if (mapModel.collision_xlu != NULL) {
        if ((arg3 & 0x80001F00) == 0x80001F00) {
            sp2C = NULL;
        } else {
            sp2C = func_802E76B0(mapModel.collision_opa, func_8033A148(mapModel.model_bin_opa), arg0, arg1, arg2, arg3);
        }
        temp_v0 = func_802E76B0(mapModel.collision_xlu, func_8033A148(mapModel.model_bin_xlu), arg0, arg1, arg2, arg3);
        if (temp_v0 != NULL) {
            mapModel.unk20 = (s32) mapModel.model_bin_xlu;
            return temp_v0;
        }
        if (sp2C != NULL) {
            mapModel.unk20 = (s32) mapModel.model_bin_opa;
        }
        return sp2C;
    }
    else{
        sp2C = func_802E76B0(mapModel.collision_opa, func_8033A148(mapModel.model_bin_opa), arg0, arg1, arg2, arg3);
        if (sp2C != NULL) {
            mapModel.unk20 = (s32) mapModel.model_bin_opa;
        }
    }
    return sp2C;
}

BKCollisionTri *func_80309C74(f32 arg0[3], f32 arg1[3], f32 arg2[3], s32 arg3, BKModelBin **arg4) {
    BKCollisionTri *sp2C;
    BKCollisionTri *phi_v0;

    sp2C = func_802E76B0(mapModel.collision_opa, func_8033A148(mapModel.model_bin_opa), arg0, arg1, arg2, arg3);
    if (sp2C != NULL) {
        *arg4 = mapModel.model_bin_opa;
    }
    if (mapModel.collision_xlu == NULL) {
        return sp2C;
    }

    phi_v0 = func_802E76B0(mapModel.collision_xlu, func_8033A148(mapModel.model_bin_xlu), arg0, arg1, arg2, arg3);
    if (phi_v0 != 0) {
        *arg4 = mapModel.model_bin_xlu;
    }
    return (phi_v0 != NULL) ? phi_v0 : sp2C;
}

UNK_TYPE(s32) func_80309D58(UNK_TYPE(s32) arg0, UNK_TYPE(s32) arg1) {
    BKMeshList *temp_v0;

    temp_v0 = func_8033A12C(mapModel.model_bin_opa);
    if (temp_v0 != NULL) {
        return func_802EC394(temp_v0, 0, 0, 1.0f, 0, arg0, arg1);
    }
    return 0;
}

UNK_TYPE(s32) func_80309DBC(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4, s32 arg5) {
    s32 sp34;
    s32 temp_v0_2;

    mapModel.unk20 = 0;
    sp34 = func_802E8E88(mapModel.collision_opa, func_8033A148(mapModel.model_bin_opa), arg0, arg1, arg2, arg3, arg4, arg5);
    if (sp34 != 0) {
        mapModel.unk20 = (s32) mapModel.model_bin_opa;
    }
    if (mapModel.collision_xlu == 0) {
        return sp34;
    }
    temp_v0_2 = func_802E8E88(mapModel.collision_xlu, func_8033A148(mapModel.model_bin_xlu), arg0, arg1, arg2, arg3, arg4, arg5);
    if (temp_v0_2 != 0) {
        mapModel.unk20 = (s32) mapModel.model_bin_xlu;
        return temp_v0_2;
    }
    return sp34;
}

UNK_TYPE(s32) func_80309EB0(f32 arg0[3], f32 arg1, f32 arg2[3], s32 arg3) {
    s32 sp24;
    s32 temp_v0_2;

    sp24 = func_802E92AC(mapModel.collision_opa, func_8033A148(mapModel.model_bin_opa), arg0, arg1, arg2, arg3);
    if (mapModel.collision_xlu == 0) {
        return sp24;
    }
    temp_v0_2 = func_802E92AC(mapModel.collision_xlu, func_8033A148(mapModel.model_bin_xlu), arg0, arg1, arg2, arg3);
    return (temp_v0_2 != 0) ? temp_v0_2 : sp24;
}

bool func_80309F78(void) {
    return (mapModel.model_bin_opa != NULL) && (mapModel.model_bin_xlu != NULL);
}

bool func_80309FA4(enum map_e map_id){
    MapModelDescription *i_ptr;

    for(i_ptr = D_8036ABE0; i_ptr->map_id != 0; i_ptr++){
        if(map_id == i_ptr->map_id){
            return TRUE;
        }
    }
    return FALSE;
}

void mapModel_free(void){
    assetcache_release(mapModel.model_bin_opa);

    if(mapModel.model_bin_xlu)
        assetcache_release(mapModel.model_bin_xlu);
    
    if(mapModel.model_opa)
        model_free(mapModel.model_opa);

    if(mapModel.model_xlu)
        model_free(mapModel.model_xlu);

    func_8034A2A8(mapModel.unk24);
}

enum asset_e mapModel_getOpaModelId(void){
    return mapModel.description->opa_model_id;
}

void func_8030A078(void) {
    BKMeshList *sp24;
    MapModelDescription *description;

    mapModel.env_blue = 0xFF;
    mapModel.env_green = 0xFF;
    mapModel.env_red = 0xFF;

    description = _mapModel_mapIdToDescription(map_get());;
    mapModel.description = description;
    mapModel.scale = (f32) description->scale;
    mapModel.model_bin_opa = (BKModelBin *)assetcache_get(mapModel.description->opa_model_id);
    mapModel.collision_opa = func_8033A084(mapModel.model_bin_opa);
    mapModel.unk20 = 0;
    if (mapModel.description->xlu_model_id != 0) {
        mapModel.model_bin_xlu = (BKModelBin *)assetcache_get(mapModel.description->xlu_model_id);
        mapModel.collision_xlu = func_8033A084(mapModel.model_bin_xlu);
    } else {
        mapModel.model_bin_xlu = NULL;
        mapModel.collision_xlu = NULL;
    }
    sp24 = func_8033A0B0(mapModel.model_bin_opa);
    if (sp24 != NULL) {
        mapModel.model_opa = func_8033F5F8(sp24, func_8033A148(mapModel.model_bin_opa));
    } else {
        mapModel.model_opa = NULL;
    }
    if (mapModel.model_opa != NULL) {
        func_8034C6DC(mapModel.model_opa);
    }

    if (mapModel.model_bin_xlu != NULL) {
        sp24 = func_8033A0B0(mapModel.model_bin_xlu);
    }
    else{
        sp24 = NULL;
    }
    
    if (sp24 != NULL) {
        mapModel.model_xlu = func_8033F5F8(sp24, func_8033A148(mapModel.model_bin_xlu));
    } else {
        mapModel.model_xlu = 0;
    }
    if (mapModel.model_xlu != NULL) {
        func_8034C6DC(mapModel.model_xlu);
    }
    mapModel.unk24 = func_8034A2C8();
    func_80320B44(func_80309B48, func_80309DBC, func_80309EB0, func_80309794);

    if (( mapModel.model_bin_opa != NULL) && (func_8033A110( mapModel.model_bin_opa) != NULL)) {
        mapModel.unk0 = func_80349C3C();
        func_80349D00(mapModel.unk0, func_8033A110(mapModel.model_bin_opa));
    } else {
        mapModel.unk0 = NULL;
    }
    if ((mapModel.model_bin_xlu != NULL) && (func_8033A110(mapModel.model_bin_xlu) != 0)) {
        mapModel.unk4 = func_80349C3C();
        func_80349D00(mapModel.unk4, func_8033A110(mapModel.model_bin_xlu));
    }
    else{
        mapModel.unk4 = NULL;
    }
}

void mapModel_setEnvColor(s32 r, s32 g, s32 b){
    mapModel.env_red = r;
    mapModel.env_green = g;
    mapModel.env_blue = b;
}

void mapModel_defrag(void){
    if(mapModel.unk24 != NULL){
        mapModel.unk24 = func_8034A348(mapModel.unk24);
    }
}
