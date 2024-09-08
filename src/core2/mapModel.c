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
extern struct5Bs *func_8034A348(struct5Bs *this);

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
    {MAP_1_SM_SPIRAL_MOUNTAIN,               ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 1,  0,  1}, { -3, -4, -2}, 1.0f},
    {MAP_2_MM_MUMBOS_MOUNTAIN,               ASSET_14AA_MODEL_MM_MUMBOS_MOUNTAIN_OPA,       ASSET_14AB_MODEL_MM_MUMBOS_MOUNTAIN_XLU,      { 1,  0,  2}, { -2,  0, -2}, 1.0f},
    {MAP_5_TTC_BLUBBERS_SHIP,                ASSET_146F_MODEL_TTC_BLUBBERS_SHIP_OPA,        ASSET_1470_MODEL_TTC_BLUBBERS_SHIP_XLU,       { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6_TTC_NIPPERS_SHELL,                ASSET_146D_MODEL_TTC_NIPPERS_SHELL_OPA,        ASSET_146E_MODEL_TTC_NIPPERS_SHELL_XLU,       { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_7_TTC_TREASURE_TROVE_COVE,          ASSET_146B_MODEL_TTC_TREASURE_TROVE_COVE_OPA,  ASSET_146C_MODEL_TTC_TREASURE_TROVE_COVE_XLU, {11,  2, 12}, {-12, -4, -5}, 1.0f},
    {MAP_8F_TTC_SHARKFOOD_ISLAND,            ASSET_1473_MODEL_TTC_SHARKFOOD_ISLAND_OPA,     0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_A_TTC_SANDCASTLE,                   ASSET_1471_MODEL_TTC_SANDCASTLE_OPA,           ASSET_1472_MODEL_TTC_SANDCASTLE_XLU,          { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_B_CC_CLANKERS_CAVERN,               ASSET_14ED_MODEL_CC_CLANKERS_CAVERN_OPA,       ASSET_14EE_MODEL_CC_CLANKERS_CAVERN_XLU,      { 0,  0,  0}, {  0, -2, -1}, 1.0f},
    {MAP_C_MM_TICKERS_TOWER,                 ASSET_14AC_MODEL_SM_TICKERS_TOWER_OPA,         ASSET_14AD_MODEL_SM_TICKERS_TOWER_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,            ASSET_14D1_MODEL_BGS_BUBBLEGLOOP_SWAMP_OPA,    ASSET_14D2_MODEL_BGS_BUBBLEGLOOP_SWAMP_XLU,   { 0,  1,  1}, { -1, -1, -1}, 1.0f},
    {MAP_E_MM_MUMBOS_SKULL,                  ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_10_BGS_MR_VILE,                     ASSET_14D3_MODEL_BGS_MR_VILE_OPA,              0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_11_BGS_TIPTUP,                      ASSET_14D4_MODEL_BGS_TIPTUP_OPA,               ASSET_14D5_MODEL_BGS_TIPTUP_XLU,              { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_12_GV_GOBIS_VALLEY,                 ASSET_1474_MODEL_GV_GOBIS_VALLEY_OPA,          ASSET_1475_MODEL_GV_GOBIS_VALLEY_XLU,         { 4,  0,  4}, { -4, -4, -5}, 1.0f},
    {MAP_92_GV_SNS_CHAMBER,                  ASSET_147E_MODEL_GV_SNS_CHAMBER_OPA,           0,                                            { 0,  1,  0}, {  0, -1,  0}, 1.0f},
    {MAP_13_GV_MEMORY_GAME,                  ASSET_1476_MODEL_GV_MEMORY_GAME_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_14_GV_SANDYBUTTS_MAZE,              ASSET_1478_MODEL_GV_SANDYBUTTS_MAZE_OPA,       ASSET_1479_MODEL_GV_SANDYBUTTS_MAZE_XLU,      { 0,  0,  1}, {  0, -2,  0}, 1.0f},
    {MAP_15_GV_WATER_PYRAMID,                ASSET_147A_MODEL_GV_WATER_PYRAMIDS_OPA,        ASSET_147B_MODEL_GV_WATER_PYRAMIDS_XLU,       { 0,  1,  0}, {  0,  0, -1}, 1.0f},
    {MAP_16_GV_RUBEES_CHAMBER,               ASSET_147C_MODEL_GV_RUBEES_CHAMBER_OPA,        0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_1A_GV_INSIDE_JINXY,                 ASSET_147D_MODEL_GV_INSIDE_JINXY_OPA,          0,                                            { 0,  1,  1}, {  0,  0,  0}, 1.0f},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,         ASSET_147F_MODEL_MMM_MAD_MONSTER_MANSION_OPA,  ASSET_1480_MODEL_MMM_MAD_MONSTER_MANSION_XLU, { 2,  0,  2}, { -3,  1, -2}, 1.0f},
    {MAP_1C_MMM_CHURCH,                      ASSET_1486_MODEL_MMM_CHURCH_OPA,               ASSET_1487_MODEL_MMM_CHURCH_XLU,              { 0,  0,  0}, {  0, -1,  0}, 1.0f},
    {MAP_1D_MMM_CELLAR,                      ASSET_1482_MODEL_MMM_CELLAR_OPA,               ASSET_149B_MODEL_MMM_CELLAR_XLU,              { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_1E_CS_START_NINTENDO,               ASSET_149D_MODEL_CS_START_NINTENDO_OPA,        ASSET_14A1_MODEL_CS_START_NINTENDO_XLU,       { 0,  1,  0}, {  0, -1,  0}, 1.0f},
    {MAP_1F_CS_START_RAREWARE,               ASSET_149E_MODEL_CS_START_RAREWARE_OPA,        ASSET_14A0_MODEL_CS_START_RAREWARE_XLU,       {-1, -1,  1}, {  1,  1,  1}, 1.0f},
    {MAP_20_CS_END_NOT_100,                  ASSET_14A9_MODEL_CS_BEACH_OPA,                 ASSET_14A5_MODEL_CS_BEACH_XLU,                { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_21_CC_WITCH_SWITCH_ROOM,            ASSET_14EF_MODEL_CC_WITCH_SWITCH_ROOM_OPA,     0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_22_CC_INSIDE_CLANKER,               ASSET_14F0_MODEL_CC_INSIDE_CLANKER_OPA,        ASSET_14F1_MODEL_CC_INSIDE_CLANKER_XLU,       { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_23_CC_GOLDFEATHER_ROOM,             ASSET_14F2_MODEL_CC_GOLD_FEATHER_ROOM_OPA,     0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_24_MMM_TUMBLARS_SHED,               ASSET_1488_MODEL_MMM_TUMBLARS_SHED_OPA,        0,                                            { 0,  1,  0}, {  0, -1,  0}, 1.0f},
    {MAP_25_MMM_WELL,                        ASSET_1495_MODEL_MMM_WELL_OPA,                 ASSET_1496_MODEL_MMM_WELL_XLU,                { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_26_MMM_NAPPERS_ROOM,                ASSET_1485_MODEL_MMM_NAPPERS_ROOM_OPA,         ASSET_149A_MODEL_MMM_NAPPERS_ROOM_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_27_FP_FREEZEEZY_PEAK,               ASSET_14C8_MODEL_FP_FREEZEEZY_PEAK_OPA,        ASSET_14C9_MODEL_FP_FREEZEEZY_PEAK_XLU,       { 2,  0,  2}, { -1, -1, -2}, 1.0f},
    {MAP_28_MMM_EGG_ROOM,                    ASSET_1489_MODEL_MMM_EGG_ROOM_OPA,             ASSET_148A_MODEL_MMM_EGG_ROOM_XLU,            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_29_MMM_NOTE_ROOM,                   ASSET_148B_MODEL_MMM_NOTE_ROOM_OPA,            ASSET_148C_MODEL_MMM_NOTE_ROOM_XLU,           { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_2A_MMM_FEATHER_ROOM,                ASSET_148D_MODEL_MMM_FEATHER_ROOM_OPA,         ASSET_148E_MODEL_MMM_FEATHER_ROOM_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,          ASSET_1483_MODEL_MMM_SECRET_CHURCH_ROOM_OPA,   ASSET_1484_MODEL_MMM_SECRET_CHURCH_ROOM_XLU,  { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_2C_MMM_BATHROOM,                    ASSET_148F_MODEL_MMM_BATHROOM_OPA,             ASSET_1490_MODEL_MMM_BATHROOM_XLU,            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_2D_MMM_BEDROOM,                     ASSET_1491_MODEL_MMM_BEDROOM_OPA,              ASSET_1492_MODEL_MMM_BEDROOM_XLU,             { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_2E_MMM_HONEYCOMB_ROOM,              ASSET_1493_MODEL_MMM_HONEYCOMB_ROOM_OPA,       ASSET_1494_MODEL_MMM_HONEYCOMB_ROOM_XLU,      { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_2F_MMM_WATERDRAIN_BARREL,           ASSET_1481_MODEL_MMM_RAINBARREL_OPA,           ASSET_1497_MODEL_MMM_RAINBARREL_XLU,          { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_30_MMM_MUMBOS_SKULL,                ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_8D_MMM_INSIDE_LOGGO,                ASSET_1498_MODEL_MMM_INSIDE_LOGGO_OPA,         ASSET_1499_MODEL_MMM_INSIDE_LOGGO_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,            ASSET_14B0_MODEL_RBB_RUSTY_BUCKET_BAY_OPA,     ASSET_14B1_MODEL_RBB_RUSTY_BUCKET_BAY_XLU,    { 8,  0,  3}, { -2, -8, -7}, 1.0f},
    {MAP_8B_RBB_ANCHOR_ROOM,                 ASSET_14C5_MODEL_RBB_ANCHOR_ROOM_OPA,          ASSET_14C6_MODEL_RBB_ANCHOR_ROOM_XLU,         { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_34_RBB_ENGINE_ROOM,                 ASSET_14B2_MODEL_RBB_ENGINE_ROOM_OPA,          ASSET_14B3_MODEL_RBB_ENGINE_ROOM_XLU,         { 0,  0,  0}, {  0, -3,  0}, 1.0f},
    {MAP_35_RBB_WAREHOUSE,                   ASSET_14B4_MODEL_RBB_WAREHOUSE_OPA,            ASSET_14B5_MODEL_RBB_WAREHOUSE_XLU,           { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_36_RBB_BOATHOUSE,                   ASSET_14B6_MODEL_RBB_BOATHOUSE_OPA,            ASSET_14B7_MODEL_RBB_BOATHOUSE_XLU,           { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_37_RBB_CONTAINER_1,                 ASSET_14B8_MODEL_RBB_CONTAINER_1_OPA,          0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_38_RBB_CONTAINER_3,                 ASSET_14BA_MODEL_RBB_CONTAINER_3_OPA,          0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_39_RBB_CREW_CABIN,                  ASSET_14BD_MODEL_RBB_CREW_CABIN_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_3A_RBB_BOSS_BOOM_BOX,               ASSET_14BE_MODEL_RBB_BOSS_BOOM_BOX_OPA,        ASSET_14BF_MODEL_RBB_BOSS_BOOM_BOX_XLU,       { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_3B_RBB_STORAGE_ROOM,                ASSET_14C1_MODEL_RBB_STORAGE_ROOM_OPA,         ASSET_14C2_MODEL_RBB_STORAGE_ROOM_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_3C_RBB_KITCHEN,                     ASSET_14C3_MODEL_RBB_KITCHEN_OPA,              ASSET_14C4_MODEL_RBB_KITCHEN_XLU,             { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_3D_RBB_NAVIGATION_ROOM,             ASSET_14C0_MODEL_RBB_NAVIGATION_ROOM_OPA,      ASSET_14C7_MODEL_RBB_NAVIGATION_ROOM_XLU,     { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_3E_RBB_CONTAINER_2,                 ASSET_14B9_MODEL_RBB_CONTAINER_2_OPA,          0,                                            { 0,  0,  0}, {  0,  1,  0}, 1.0f},
    {MAP_3F_RBB_CAPTAINS_CABIN,              ASSET_14BB_MODEL_RBB_CAPTIANS_CABIN_OPA,       ASSET_14BC_MODEL_RBB_CAPTIANS_CABIN_XLU,      { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_40_CCW_HUB,                         ASSET_14D8_MODEL_CCW_HUB_OPA,                  ASSET_14E3_MODEL_CCW_HUB_XLU,                 { 0,  0,  0}, {  0, -3,  0}, 1.0f},
    {MAP_41_FP_BOGGYS_IGLOO,                 ASSET_14CA_MODEL_FP_BOGGYS_IGLOO_OPA,          ASSET_14CE_MODEL_FP_BOGGYS_IGLOO_XLU,         { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_7F_FP_WOZZAS_CAVE,                  ASSET_14CC_MODEL_FP_WOZZAS_CAVE_OPA,           ASSET_14CD_MODEL_FP_WOZZAS_CAVE_XLU,          { 0,  0,  0}, {  0, -1,  0}, 1.0f},
    {MAP_43_CCW_SPRING,                      ASSET_14D9_MODEL_CCW_SPRING_OPA,               ASSET_14E4_MODEL_CCW_SPRING_XLU,              { 1,  0,  1}, { -1, -5,  0}, 1.0f},
    {MAP_44_CCW_SUMMER,                      ASSET_14DA_MODEL_CCW_SUMMER_OPA,               ASSET_14E5_MODEL_CCW_SUMMER_XLU,              { 1,  0,  1}, { -1, -5,  0}, 1.0f},
    {MAP_45_CCW_AUTUMN,                      ASSET_14DB_MODEL_CCW_AUTUMN_OPA,               ASSET_14E6_MODEL_CCW_AUTUMN_XLU,              { 1,  0,  1}, { -1, -6,  0}, 1.0f},
    {MAP_46_CCW_WINTER,                      ASSET_14DC_MODEL_CCW_WINTER_OPA,               ASSET_14E7_MODEL_CCW_WINTER_XLU,              { 1,  0,  1}, { -1, -5,  0}, 1.0f},
    {MAP_47_BGS_MUMBOS_SKULL,                ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_48_FP_MUMBOS_SKULL,                 ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_4A_CCW_SPRING_MUMBOS_SKULL,         ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_4B_CCW_SUMMER_MUMBOS_SKULL,         ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_4C_CCW_AUTUMN_MUMBOS_SKULL,         ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_4D_CCW_WINTER_MUMBOS_SKULL,         ASSET_14AE_MODEL_MUMBOS_SKULL_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_53_FP_CHRISTMAS_TREE,               ASSET_14CB_MODEL_FP_XMAS_TREE_OPA,             0,                                            { 2,  1,  2}, { -2, -1, -2}, 1.0f},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,           ASSET_14DD_MODEL_CCW_ZUBBA_HIVE_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,           ASSET_14DD_MODEL_CCW_ZUBBA_HIVE_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,           ASSET_14DD_MODEL_CCW_ZUBBA_HIVE_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,        ASSET_14DE_MODEL_CCW_NABNUTS_HOUSE_OPA,        0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,        ASSET_14DE_MODEL_CCW_NABNUTS_HOUSE_OPA,        0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,        ASSET_14DE_MODEL_CCW_NABNUTS_HOUSE_OPA,        0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE,        ASSET_14DE_MODEL_CCW_NABNUTS_HOUSE_OPA,        0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_62_CCW_WINTER_HONEYCOMB_ROOM,       ASSET_14E0_MODEL_CCW_HONEYCOMB_ROOM_OPA,       0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, ASSET_14E1_MODEL_CCW_NABBUTS_STASH_OPA,        ASSET_14E2_MODEL_CCW_NABBUTS_STASH_XLU,       { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, ASSET_14E1_MODEL_CCW_NABBUTS_STASH_OPA,        ASSET_14E2_MODEL_CCW_NABBUTS_STASH_XLU,       { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_65_CCW_SPRING_WHIPCRACK_ROOM,       ASSET_14DF_MODEL_CCW_WHIPCRACK_ROOM_OPA,       0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,       ASSET_14DF_MODEL_CCW_WHIPCRACK_ROOM_OPA,       0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,       ASSET_14DF_MODEL_CCW_WHIPCRACK_ROOM_OPA,       0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_68_CCW_WINTER_WHIPCRACK_ROOM,       ASSET_14DF_MODEL_CCW_WHIPCRACK_ROOM_OPA,       0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_69_GL_MM_LOBBY,                     ASSET_14F3_MODEL_GL_MM_LOBBY_OPA,              ASSET_150B_MODEL_GL_MM_LOBBY_XLU,             { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6A_GL_TTC_AND_CC_PUZZLE,            ASSET_14F4_MODEL_GL_TTC_AND_CC_PUZZLE_OPA,     ASSET_150C_MODEL_GL_TTC_AND_CC_PUZZLE_XLU,    { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6B_GL_180_NOTE_DOOR,                ASSET_14F5_MODEL_GL_180_NOTE_DOOR_OPA,         ASSET_1510_MODEL_GL_180_NOTE_DOOR_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6C_GL_RED_CAULDRON_ROOM,            ASSET_14F6_MODEL_GL_RED_CAULDRON_ROOM_OPA,     ASSET_150D_MODEL_GL_RED_CAULDRON_ROOM_XLU,    { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6D_GL_TTC_LOBBY,                    ASSET_14F7_MODEL_GL_TTC_LOBBY_OPA,             ASSET_1512_MODEL_GL_TTC_LOBBY_XLU,            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6E_GL_GV_LOBBY,                     ASSET_14F8_MODEL_GL_GV_LOBBY_OPA,              ASSET_14A8_MODEL_GL_GV_LOBBY_XLU,             { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_6F_GL_FP_LOBBY,                     ASSET_14F9_MODEL_GL_FP_LOBBY_OPA,              ASSET_14FA_MODEL_GL_FP_LOBBY_XLU,             { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_74_GL_GV_PUZZLE,                    ASSET_14FD_MODEL_GL_GV_PUZZLE_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_70_GL_CC_LOBBY,                     ASSET_14FB_MODEL_GL_CC_LOBBY_OPA,              ASSET_1507_MODEL_GL_CC_LOBBY_XLU,             { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_75_GL_MMM_LOBBY,                    ASSET_14FE_MODEL_GL_MMM_LOBBY_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_7A_GL_CRYPT,                        ASSET_14FF_MODEL_GL_CRYPT_OPA,                 0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_71_GL_STATUE_ROOM,                  ASSET_1500_MODEL_GL_STATUE_ROOM_OPA,           ASSET_150E_MODEL_GL_STATUE_ROOM_XLU,          { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_72_GL_BGS_LOBBY,                    ASSET_1501_MODEL_GL_BGS_LOBBY_OPA,             ASSET_1511_MODEL_GL_BGS_LOBBY_XLU,            { 1,  0,  1}, {  0, -2, -1}, 1.0f},
    {MAP_76_GL_640_NOTE_DOOR,                ASSET_1502_MODEL_GL_640_NOTE_DOOR_OPA,         ASSET_1508_MODEL_GL_640_NOTE_DOOR_XLU,        { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_77_GL_RBB_LOBBY,                    ASSET_1503_MODEL_GL_RBB_LOBBY_OPA,             ASSET_1509_MODEL_GL_RBB_LOBBY_XLU,            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_78_GL_RBB_AND_MMM_PUZZLE,           ASSET_1504_MODEL_RBB_AND_MMM_PUZZLE_OPA,       ASSET_150A_MODEL_RBB_AND_MMM_PUZZLE_XLU,      { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_79_GL_CCW_LOBBY,                    ASSET_1505_MODEL_GL_CCW_LOBBY_OPA,             0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_80_GL_FF_ENTRANCE,                  ASSET_1506_MODEL_GL_FF_ENTRANCE_OPA,           ASSET_1514_MODEL_GL_FF_ENTRANCE_XLU,          { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_93_GL_DINGPOT,                      ASSET_150F_MODEL_CS_KLUNGOS_LAB_OPA,           ASSET_1513_MODEL_CS_KLUNGOS_LAB_XLU,          { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_90_GL_BATTLEMENTS,                  ASSET_14FC_MODEL_GL_BATTLEMENTS_OPA,           ASSET_1515_MODEL_GL_BATTLEMENTS_XLU,          { 6,  2,  7}, { -6, -3, -5}, 1.0f},
    {MAP_7B_CS_INTRO_GL_DINGPOT_1,           ASSET_150F_MODEL_CS_KLUNGOS_LAB_OPA,           0,                                            { 0,  0,  0}, {  0, -1,  0}, 1.6666666f},
    {MAP_7C_CS_INTRO_BANJOS_HOUSE_1,         ASSET_14A2_MODEL_CS_BANJOS_HOUSE_OPA,          0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.6666666f},
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,            ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 0,  0,  2}, {  0, -4, -2}, 1.0f},
    {MAP_7E_CS_SPIRAL_MOUNTAIN_2,            ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 0,  0,  2}, {  0, -4, -2}, 1.0f},
    {MAP_81_CS_INTRO_GL_DINGPOT_2,           ASSET_150F_MODEL_CS_KLUNGOS_LAB_OPA,           0,                                            { 0,  0,  0}, {  0, -1,  0}, 1.6666666f},
    {MAP_82_CS_ENTERING_GL_MACHINE_ROOM,     ASSET_150F_MODEL_CS_KLUNGOS_LAB_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_83_CS_GAME_OVER_MACHINE_ROOM,       ASSET_150F_MODEL_CS_KLUNGOS_LAB_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_84_CS_UNUSED_MACHINE_ROOM,          ASSET_150F_MODEL_CS_KLUNGOS_LAB_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,            ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,            ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 0,  0,  0}, {  0, -4,  0}, 1.0f},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,            ASSET_14A6_MODEL_CS_INTRO_SPIRAL_MOUNTAIN_OPA, 0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,            ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_94_CS_INTRO_SPIRAL_7,               ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA,       ASSET_14D0_MODEL_SM_SPIRAL_MOUNTAIN_XLU,      { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1,        ASSET_149F_MODEL_CS_END_SPIRAL_MOUNTAIN_OPA,   ASSET_14A3_MODEL_CS_END_SPIRAL_MOUNTAIN_XLU,  { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2,        ASSET_149F_MODEL_CS_END_SPIRAL_MOUNTAIN_OPA,   ASSET_14A3_MODEL_CS_END_SPIRAL_MOUNTAIN_XLU,  { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_95_CS_END_ALL_100,                  ASSET_14A9_MODEL_CS_BEACH_OPA,                 ASSET_14A5_MODEL_CS_BEACH_XLU,                { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,         ASSET_14A2_MODEL_CS_BANJOS_HOUSE_OPA,          ASSET_14A4_MODEL_CS_BANJOS_HOUSE_XLU,         { 0,  0,  0}, {  0,  0,  0}, 1.6666666f},
    {MAP_8A_CS_INTRO_BANJOS_HOUSE_3,         ASSET_14A2_MODEL_CS_BANJOS_HOUSE_OPA,          ASSET_14A4_MODEL_CS_BANJOS_HOUSE_XLU,         { 0,  0,  0}, {  0,  0,  0}, 1.6666666f},
    {MAP_96_CS_END_BEACH_1,                  ASSET_14A9_MODEL_CS_BEACH_OPA,                 ASSET_14A5_MODEL_CS_BEACH_XLU,                { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_97_CS_END_BEACH_2,                  ASSET_14A9_MODEL_CS_BEACH_OPA,                 ASSET_14A5_MODEL_CS_BEACH_XLU,                { 2,  0, -3}, {  4,  0, -1}, 1.0f},
    {MAP_91_FILE_SELECT,                     ASSET_14A2_MODEL_CS_BANJOS_HOUSE_OPA,          ASSET_14A4_MODEL_CS_BANJOS_HOUSE_XLU,         { 0,  0,  0}, {  0,  0,  0}, 1.6666666f},
    {MAP_8C_SM_BANJOS_HOUSE,                 ASSET_14A2_MODEL_CS_BANJOS_HOUSE_OPA,          ASSET_14A4_MODEL_CS_BANJOS_HOUSE_XLU,         { 0,  0,  0}, {  0,  0,  0}, 1.0f},
    {MAP_8E_GL_FURNACE_FUN,                  ASSET_14E8_MODEL_GL_FURNACE_FUN_OPA,           0,                                            { 0,  0,  0}, {  0,  0,  0}, 1.0f},
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

    if (func_80320708() && levelSpecificFlags_validateCRC2() && dummy_func_80320248()) {
        if (mapModel_getOpaModelId() == ASSET_14CF_MODEL_SM_SPIRAL_MOUNTAIN_OPA) {
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
            func_8033A45C(6, (func_8038EAE0(0xA) || fileProgressFlag_get(FILEPROG_E2_DOOR_OF_GRUNTY_OPEN) || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)));
            break;
        }
        func_8033A450(mapModel.unk24);
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        temp_a0 = mapModel.unk0;
        if (temp_a0 != 0) {
            modelRender_setAnimatedTexturesCacheId(temp_a0);
        }
        modelRender_setEnvColor(mapModel.env_red, mapModel.env_green, mapModel.env_blue, 0xFF);
        modelRender_draw(gfx, mtx, NULL, NULL, mapModel.description->scale, NULL, mapModel.model_bin_opa);
        if (!mapModel_has_xlu_bin()) {
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
            modelRender_setAnimatedTexturesCacheId(temp_a0);
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
    vtxList_getBounds_s32(model_getVtxList(mapModel.model_bin_opa), min, max);
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

    vtxList_getBounds_s32(model_getVtxList(mapModel.model_bin_opa), min, max);
    for(i = 0; i < 3; i++){
        min[i] *= mapModel.scale;
        max[i] *= mapModel.scale;
    }
}

void mapModel_getBounds(s32 min[3], s32 max[3]) {
    s32 i, j;
    s32 xlu_min[3];
    s32 xlu_max[3];

    vtxList_getBounds_s32(model_getVtxList(mapModel.model_bin_opa), min, max);
    for(i = 0; i < 3; i++){
        min[i] *= mapModel.scale;
        max[i] *= mapModel.scale;
    }

    if (mapModel.model_bin_xlu != NULL) {
        vtxList_getBounds_s32(model_getVtxList(mapModel.model_bin_xlu), xlu_min, xlu_max);
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

BKCollisionTri *func_80309B48(f32 arg0[3], f32 arg1[3], f32 arg2[3], s32 flagFilter) {
    BKCollisionTri *sp2C;
    BKCollisionTri *temp_v0;

    mapModel.unk20 = 0;
    if (mapModel.collision_xlu != NULL) {
        if ((flagFilter & 0x80001F00) == 0x80001F00) {
            sp2C = NULL;
        } else {
            sp2C = func_802E76B0(mapModel.collision_opa, model_getVtxList(mapModel.model_bin_opa), arg0, arg1, arg2, flagFilter);
        }
        temp_v0 = func_802E76B0(mapModel.collision_xlu, model_getVtxList(mapModel.model_bin_xlu), arg0, arg1, arg2, flagFilter);
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
        sp2C = func_802E76B0(mapModel.collision_opa, model_getVtxList(mapModel.model_bin_opa), arg0, arg1, arg2, flagFilter);
        if (sp2C != NULL) {
            mapModel.unk20 = (s32) mapModel.model_bin_opa;
        }
    }
    return sp2C;
}

BKCollisionTri *func_80309C74(f32 arg0[3], f32 arg1[3], f32 arg2[3], s32 flagFilter, BKModelBin **arg4) {
    BKCollisionTri *sp2C;
    BKCollisionTri *phi_v0;

    sp2C = func_802E76B0(mapModel.collision_opa, model_getVtxList(mapModel.model_bin_opa), arg0, arg1, arg2, flagFilter);
    if (sp2C != NULL) {
        *arg4 = mapModel.model_bin_opa;
    }
    if (mapModel.collision_xlu == NULL) {
        return sp2C;
    }

    phi_v0 = func_802E76B0(mapModel.collision_xlu, model_getVtxList(mapModel.model_bin_xlu), arg0, arg1, arg2, flagFilter);
    if (phi_v0 != 0) {
        *arg4 = mapModel.model_bin_xlu;
    }
    return (phi_v0 != NULL) ? phi_v0 : sp2C;
}

bool func_80309D58(f32 arg0[3], UNK_TYPE(s32) arg1) {
    BKModelUnk14List *temp_v0;

    temp_v0 = func_8033A12C(mapModel.model_bin_opa);
    if (temp_v0 != NULL) {
        return func_802EC394(temp_v0, NULL, NULL, 1.0f, NULL, arg0, arg1);
    }
    return 0;
}

UNK_TYPE(s32) func_80309DBC(f32 currentPosition[3], f32 next_position[3], f32 arg2, f32 arg3[3], s32 arg4, s32 arg5) {
    s32 sp34;
    s32 temp_v0_2;

    mapModel.unk20 = 0;
    sp34 = func_802E8E88(mapModel.collision_opa, model_getVtxList(mapModel.model_bin_opa), currentPosition, next_position, arg2, arg3, arg4, arg5);
    if (sp34 != 0) {
        mapModel.unk20 = (s32) mapModel.model_bin_opa;
    }
    if (mapModel.collision_xlu == 0) {
        return sp34;
    }
    temp_v0_2 = func_802E8E88(mapModel.collision_xlu, model_getVtxList(mapModel.model_bin_xlu), currentPosition, next_position, arg2, arg3, arg4, arg5);
    if (temp_v0_2 != 0) {
        mapModel.unk20 = (s32) mapModel.model_bin_xlu;
        return temp_v0_2;
    }
    return sp34;
}

UNK_TYPE(s32) func_80309EB0(f32 arg0[3], f32 arg1, f32 arg2[3], s32 arg3) {
    s32 sp24;
    s32 temp_v0_2;

    sp24 = func_802E92AC(mapModel.collision_opa, model_getVtxList(mapModel.model_bin_opa), arg0, arg1, arg2, arg3);
    if (mapModel.collision_xlu == 0) {
        return sp24;
    }
    temp_v0_2 = func_802E92AC(mapModel.collision_xlu, model_getVtxList(mapModel.model_bin_xlu), arg0, arg1, arg2, arg3);
    return (temp_v0_2 != 0) ? temp_v0_2 : sp24;
}

bool mapModel_has_xlu_bin(void) {
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
    mapModel.collision_opa = model_getCollisionList(mapModel.model_bin_opa);
    mapModel.unk20 = 0;
    if (mapModel.description->xlu_model_id != 0) {
        mapModel.model_bin_xlu = (BKModelBin *)assetcache_get(mapModel.description->xlu_model_id);
        mapModel.collision_xlu = model_getCollisionList(mapModel.model_bin_xlu);
    } else {
        mapModel.model_bin_xlu = NULL;
        mapModel.collision_xlu = NULL;
    }
    sp24 = func_8033A0B0(mapModel.model_bin_opa);
    if (sp24 != NULL) {
        mapModel.model_opa = func_8033F5F8(sp24, model_getVtxList(mapModel.model_bin_opa));
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
        mapModel.model_xlu = func_8033F5F8(sp24, model_getVtxList(mapModel.model_bin_xlu));
    } else {
        mapModel.model_xlu = 0;
    }
    if (mapModel.model_xlu != NULL) {
        func_8034C6DC(mapModel.model_xlu);
    }
    mapModel.unk24 = func_8034A2C8();
    func_80320B44(func_80309B48, func_80309DBC, func_80309EB0, func_80309794);

    if (( mapModel.model_bin_opa != NULL) && (model_getAnimTextureList( mapModel.model_bin_opa) != NULL)) {
        mapModel.unk0 = AnimTextureListCache_newList();
        AnimTextureListCache_at(mapModel.unk0, model_getAnimTextureList(mapModel.model_bin_opa));
    } else {
        mapModel.unk0 = NULL;
    }
    if ((mapModel.model_bin_xlu != NULL) && (model_getAnimTextureList(mapModel.model_bin_xlu) != 0)) {
        mapModel.unk4 = AnimTextureListCache_newList();
        AnimTextureListCache_at(mapModel.unk4, model_getAnimTextureList(mapModel.model_bin_xlu));
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
