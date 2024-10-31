#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s16 level_id;
    s16 map_id;
    s16 exit_id;
}Struct_core2_83D70_1;

typedef struct map_info{
    s16 map_id;
    s16 level_id;
    char* name;
}MapInfo;

/* .data */
MapInfo D_8036B810[0x9B] ={
    {0x0000, 0, "(gcSectionMin)"},
    {MAP_1_SM_SPIRAL_MOUNTAIN,          LEVEL_B_SPIRAL_MOUNTAIN,        "Training - Spiral Mountain"},
    {MAP_2_MM_MUMBOS_MOUNTAIN,          LEVEL_1_MUMBOS_MOUNTAIN,        "Jungle"},
    {MAP_5_TTC_BLUBBERS_SHIP,           LEVEL_2_TREASURE_TROVE_COVE,    "Beach - Pirate Ship Hold"},
    {MAP_6_TTC_NIPPERS_SHELL,           LEVEL_2_TREASURE_TROVE_COVE,    "Beach - Crab Shell"},
    {MAP_7_TTC_TREASURE_TROVE_COVE,     LEVEL_2_TREASURE_TROVE_COVE,    "Beach"},
    {MAP_8F_TTC_SHARKFOOD_ISLAND,       LEVEL_2_TREASURE_TROVE_COVE,    "Beach - Sea Castle"},
    {MAP_A_TTC_SANDCASTLE,              LEVEL_2_TREASURE_TROVE_COVE,    "Beach - Sand Castle"},
    {MAP_B_CC_CLANKERS_CAVERN,          LEVEL_3_CLANKERS_CAVERN,        "Whale"},
    {MAP_C_MM_TICKERS_TOWER,            LEVEL_1_MUMBOS_MOUNTAIN,        "Jungle - Termite Hill"},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,       LEVEL_4_BUBBLEGLOOP_SWAMP,      "Swamp"},
    {MAP_E_MM_MUMBOS_SKULL,             LEVEL_1_MUMBOS_MOUNTAIN,        "Jungle - Shamen Hut"},
    {MAP_10_BGS_MR_VILE,                LEVEL_4_BUBBLEGLOOP_SWAMP,      "Swamp - Crocodile Head"},
    {MAP_11_BGS_TIPTUP,                 LEVEL_4_BUBBLEGLOOP_SWAMP,      "Swamp - Turtle"},
    {MAP_12_GV_GOBIS_VALLEY,            LEVEL_7_GOBIS_VALLEY,           "Desert"},
    {MAP_13_GV_MEMORY_GAME,             LEVEL_7_GOBIS_VALLEY,           "Desert - Pyramid 1 (Match the pairs)"},
    {MAP_14_GV_SANDYBUTTS_MAZE,         LEVEL_7_GOBIS_VALLEY,           "Desert - Pyramid 2 (Maze)"},
    {MAP_15_GV_WATER_PYRAMID,           LEVEL_7_GOBIS_VALLEY,           "Desert - Pyramid 3 (Water)"},
    {MAP_16_GV_RUBEES_CHAMBER,          LEVEL_7_GOBIS_VALLEY,           "Desert - Pyramid 4 (Snake)"},
    {MAP_1A_GV_INSIDE_JINXY,            LEVEL_7_GOBIS_VALLEY,           "Desert - Sphinx"},
    {MAP_92_GV_SNS_CHAMBER,             LEVEL_7_GOBIS_VALLEY,           "Desert - Secret Chamber"},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,    LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House"},
    {MAP_1C_MMM_CHURCH,                 LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Organ"},
    {MAP_1D_MMM_CELLAR,                 LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Cellar"},
    {MAP_1E_CS_START_NINTENDO,          LEVEL_D_CUTSCENE,               "Intro - Start - Nintendo"},
    {MAP_1F_CS_START_RAREWARE,          LEVEL_D_CUTSCENE,               "Intro - Start - Rareware"},
    {MAP_20_CS_END_NOT_100,             LEVEL_D_CUTSCENE,               "Intro - End Scene 2 : Not 100 "},
    {MAP_7B_CS_INTRO_GL_DINGPOT_1,      LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 1 - Scene 1"},
    {MAP_81_CS_INTRO_GL_DINGPOT_2,      LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 2"},
    {MAP_82_CS_ENTERING_GL_MACHINE_ROOM,LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 3 - Machine 1"},
    {MAP_83_CS_GAME_OVER_MACHINE_ROOM,  LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 4 - Game Over"},
    {MAP_84_CS_UNUSED_MACHINE_ROOM,     LEVEL_D_CUTSCENE,               "Intro - Grunties Lair 5"},
    {MAP_7C_CS_INTRO_BANJOS_HOUSE_1,    LEVEL_D_CUTSCENE,               "Intro - Inside Banjo's Cave 1 - Scenes 3,7"},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,    LEVEL_D_CUTSCENE,               "Intro - Inside Banjo's Cave 2"},
    {MAP_8A_CS_INTRO_BANJOS_HOUSE_3,    LEVEL_D_CUTSCENE,               "Intro - Inside Banjo's Cave 3"},
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'A' - Scenes 2,4"},
    {MAP_7E_CS_SPIRAL_MOUNTAIN_2,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'B' - Scenes 5,6"},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'C'"},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'D'"},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'E'"},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,       LEVEL_D_CUTSCENE,               "Intro - Spiral 'F'"},
    {MAP_94_CS_INTRO_SPIRAL_7,          LEVEL_D_CUTSCENE,               "Intro - Spiral 'G'"},
    {MAP_95_CS_END_ALL_100,             LEVEL_D_CUTSCENE,               "Intro - End Scene 3 : All 100"},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1,   LEVEL_D_CUTSCENE,               "Intro - Grunty Threat 1"},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2,   LEVEL_D_CUTSCENE,               "Intro - Grunty Threat 2"},
    {MAP_96_CS_END_BEACH_1,             LEVEL_D_CUTSCENE,               "Intro - End Scene"},
    {MAP_97_CS_END_BEACH_2,             LEVEL_D_CUTSCENE,               "Intro - End Scene 4"},
    {MAP_21_CC_WITCH_SWITCH_ROOM,       LEVEL_3_CLANKERS_CAVERN,        "Whale - Inside A"},
    {MAP_22_CC_INSIDE_CLANKER,          LEVEL_3_CLANKERS_CAVERN,        "Whale - Inside B"},
    {MAP_23_CC_GOLDFEATHER_ROOM,        LEVEL_3_CLANKERS_CAVERN,        "Whale - Inside C"},
    {MAP_24_MMM_TUMBLARS_SHED,          LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Ouija Board"},
    {MAP_25_MMM_WELL,                   LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Well"},
    {MAP_26_MMM_NAPPERS_ROOM,           LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Dining Room"},
    {MAP_28_MMM_EGG_ROOM,               LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Room 1"},
    {MAP_29_MMM_NOTE_ROOM,              LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Room 2"},
    {MAP_2A_MMM_FEATHER_ROOM,           LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Room 3 : Fireplace"},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,     LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Church"},
    {MAP_2C_MMM_BATHROOM,               LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Room 4 : Bathroom"},
    {MAP_2D_MMM_BEDROOM,                LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Room 5 : Bedroom"},
    {MAP_2E_MMM_HONEYCOMB_ROOM,         LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Room 6 : Floorboards"},
    {MAP_2F_MMM_WATERDRAIN_BARREL,      LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Barrel"},
    {MAP_30_MMM_MUMBOS_SKULL,           LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Shamen Hut"},
    {MAP_8D_MMM_INSIDE_LOGGO,           LEVEL_A_MAD_MONSTER_MANSION,    "Haunted House - Septic Tank"},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,       LEVEL_9_RUSTY_BUCKET_BAY,       "Ship"},
    {MAP_8B_RBB_ANCHOR_ROOM,            LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Anchor room"},
    {MAP_34_RBB_ENGINE_ROOM,            LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Prop Room"},
    {MAP_35_RBB_WAREHOUSE,              LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Warehouse 1"},
    {MAP_36_RBB_BOATHOUSE,              LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Warehouse 2"},
    {MAP_37_RBB_CONTAINER_1,            LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Container 1"},
    {MAP_38_RBB_CONTAINER_3,            LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Container 3"},
    {MAP_39_RBB_CREW_CABIN,             LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Crew Cabin"},
    {MAP_3A_RBB_BOSS_BOOM_BOX,          LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Hold"},
    {MAP_3B_RBB_STORAGE_ROOM,           LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Store Room"},
    {MAP_3C_RBB_KITCHEN,                LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Galley"},
    {MAP_3D_RBB_NAVIGATION_ROOM,        LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Navigation Room"},
    {MAP_3E_RBB_CONTAINER_2,            LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Container 2"},
    {MAP_3F_RBB_CAPTAINS_CABIN,         LEVEL_9_RUSTY_BUCKET_BAY,       "Ship - Captain's Cabin"},
    {MAP_40_CCW_HUB,                    LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Start"},
    {MAP_43_CCW_SPRING,                 LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Main (Spring)"},
    {MAP_44_CCW_SUMMER,                 LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Main (Summer)"},
    {MAP_45_CCW_AUTUMN,                 LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Main (Autumn)"},
    {MAP_46_CCW_WINTER,                 LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Main (Winter)"},
    {MAP_47_BGS_MUMBOS_SKULL,           LEVEL_4_BUBBLEGLOOP_SWAMP,      "Swamp - Shamen Hut"},
    {MAP_4A_CCW_SPRING_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Shamen Hut (Spring)"},
    {MAP_4B_CCW_SUMMER_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Shamen Hut (Summer)"},
    {MAP_4C_CCW_AUTUMN_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Shamen Hut (Autumn)"},
    {MAP_4D_CCW_WINTER_MUMBOS_SKULL,    LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Shamen Hut (Winter)"},
    {MAP_53_FP_CHRISTMAS_TREE,          LEVEL_5_FREEZEEZY_PEAK,         "Snow - Inside Xmas Tree"},
    {MAP_41_FP_BOGGYS_IGLOO,            LEVEL_5_FREEZEEZY_PEAK,         "Snow - Igloo"},
    {MAP_27_FP_FREEZEEZY_PEAK,          LEVEL_5_FREEZEEZY_PEAK,         "Snow"},
    {MAP_48_FP_MUMBOS_SKULL,            LEVEL_5_FREEZEEZY_PEAK,         "Snow - Shamen Hut"},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,      LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Wasp Hive (Summer)"},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,      LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Wasp Hive (Spring)"},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,      LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Wasp Hive (Autumn)"},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Squirrel House (Spring)"},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Squirrel House (Summer)"},
    {MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Squirrel House (Autumn)"},
    {MAP_61_CCW_WINTER_NABNUTS_HOUSE,   LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Squirrel House (Winter)"},
    {MAP_62_CCW_WINTER_HONEYCOMB_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Squirrel Room 1 (Winter)"},
    {MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, LEVEL_8_CLICK_CLOCK_WOOD,  "Tree - Squirrel Room 2 (Autumn)"},
    {MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, LEVEL_8_CLICK_CLOCK_WOOD,  "Tree - Squirrel Room 2 (Winter)"},
    {MAP_65_CCW_SPRING_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Top (Spring)"},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Top (Summer)"},
    {MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Top (Autumn)"},
    {MAP_68_CCW_WINTER_WHIPCRACK_ROOM,  LEVEL_8_CLICK_CLOCK_WOOD,       "Tree - Top (Winter)"},
    {MAP_69_GL_MM_LOBBY,                LEVEL_6_LAIR,                   "Witch - Flr 1, Area 1 : Mumbo"},
    {MAP_6A_GL_TTC_AND_CC_PUZZLE,       LEVEL_6_LAIR,                   "Witch - Flr 1, Area 2"},
    {MAP_6B_GL_180_NOTE_DOOR,           LEVEL_6_LAIR,                   "Witch - Flr 1, Area 3"},
    {MAP_6C_GL_RED_CAULDRON_ROOM,       LEVEL_6_LAIR,                   "Witch - Flr 1, Area 3a : Cauldron"},
    {MAP_6D_GL_TTC_LOBBY,               LEVEL_6_LAIR,                   "Witch - Flr 1, Area 4 : Pirate ship"},
    {MAP_70_GL_CC_LOBBY,                LEVEL_6_LAIR,                   "Witch - Flr 1, Area 5 : Pipes room"},
    {MAP_71_GL_STATUE_ROOM,             LEVEL_6_LAIR,                   "Witch - Flr 1, Area 6 : Witch statue"},
    {MAP_72_GL_BGS_LOBBY,               LEVEL_6_LAIR,                   "Witch - Flr 1, Area 7 : Swamp/Snow"},
    {MAP_6E_GL_GV_LOBBY,                LEVEL_6_LAIR,                   "Witch - Flr 2, Area 1 : Sand Chamber"},
    {MAP_6F_GL_FP_LOBBY,                LEVEL_6_LAIR,                   "Witch - Flr 2, Area 2 : Spooky/Advent"},
    {MAP_74_GL_GV_PUZZLE,               LEVEL_6_LAIR,                   "Witch - Flr 2, Area 4 : Dark room"},
    {MAP_75_GL_MMM_LOBBY,               LEVEL_6_LAIR,                   "Witch - Flr 2, Area 5 : Crypt outside"},
    {MAP_7A_GL_CRYPT,                   LEVEL_6_LAIR,                   "Witch - Flr 2, Area 5a : Crypt inside"},
    {MAP_76_GL_640_NOTE_DOOR,           LEVEL_6_LAIR,                   "Witch - Flr 3, Area 1"},
    {MAP_77_GL_RBB_LOBBY,               LEVEL_6_LAIR,                   "Witch - Flr 3, Area 2 : Ship side"},
    {MAP_78_GL_RBB_AND_MMM_PUZZLE,      LEVEL_6_LAIR,                   "Witch - Flr 3, Area 3"},
    {MAP_79_GL_CCW_LOBBY,               LEVEL_6_LAIR,                   "Witch - Flr 3, Area 4 : Tree trunks"},
    {MAP_80_GL_FF_ENTRANCE,             LEVEL_6_LAIR,                   "Witch - Flr 3, Area 4a"},
    {MAP_8E_GL_FURNACE_FUN,             LEVEL_6_LAIR,                   "Witch - Flr 4, Area 1 : Quiz Room"},
    {MAP_93_GL_DINGPOT,                 LEVEL_6_LAIR,                   "Witch - Flr 5, Area 1 : Gruntie's rooms"},
    {MAP_90_GL_BATTLEMENTS,             LEVEL_C_BOSS,                   "Witch - Battlements"},
    {MAP_7F_FP_WOZZAS_CAVE,             LEVEL_5_FREEZEEZY_PEAK,         "Snow - Wozza Cave"},
    {MAP_8C_SM_BANJOS_HOUSE,            LEVEL_B_SPIRAL_MOUNTAIN,        "Training - Banjo Cave"},
    {MAP_91_FILE_SELECT,                LEVEL_B_SPIRAL_MOUNTAIN,        "Training - Banjo Cave Save"},
    {0,                                 0,                              "(gcSectionMax)"}
};

Struct_core2_83D70_1 D_8036BCE8[] = {
    {LEVEL_1_MUMBOS_MOUNTAIN,       MAP_2_MM_MUMBOS_MOUNTAIN,        0x5},
    {LEVEL_2_TREASURE_TROVE_COVE,   MAP_7_TTC_TREASURE_TROVE_COVE,   0x4},
    {LEVEL_3_CLANKERS_CAVERN,       MAP_B_CC_CLANKERS_CAVERN,        0x5},
    {LEVEL_4_BUBBLEGLOOP_SWAMP,     MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x2},
    {LEVEL_5_FREEZEEZY_PEAK,        MAP_27_FP_FREEZEEZY_PEAK,        0x1},
    {LEVEL_7_GOBIS_VALLEY,          MAP_12_GV_GOBIS_VALLEY,          0x8},
    {LEVEL_8_CLICK_CLOCK_WOOD,      MAP_40_CCW_HUB,                  0x7},
    {LEVEL_9_RUSTY_BUCKET_BAY,      MAP_31_RBB_RUSTY_BUCKET_BAY,    0x10},
    {LEVEL_A_MAD_MONSTER_MANSION,   MAP_1B_MMM_MAD_MONSTER_MANSION, 0x14},
    {LEVEL_B_SPIRAL_MOUNTAIN,       MAP_1_SM_SPIRAL_MOUNTAIN,       0x12},
    {LEVEL_D_CUTSCENE,              MAP_7B_CS_INTRO_GL_DINGPOT_1,    0x0},
    {LEVEL_6_LAIR,                  MAP_69_GL_MM_LOBBY,              0x0},
    {LEVEL_C_BOSS,                  MAP_90_GL_BATTLEMENTS,           0x0}
};

/* .bss */
char D_803823A0[0x70];

/* .data */
MapInfo * func_8030AD00(enum map_e map_id){
    MapInfo *phi_v1;

    for(phi_v1 = &D_8036B810[1]; phi_v1->map_id != 0; phi_v1++){
        if (map_id == phi_v1->map_id) {
            return phi_v1;
        }
    }
    return NULL;
}

enum level_e map_getLevel(enum map_e map){
    return func_8030AD00(map)->level_id;
}

/* returns string containing the map name and index */
char *gcsection_getName(enum map_e map){
    MapInfo *map_info = func_8030AD00(map);
    D_803823A0[0] = 0;
    strcat(D_803823A0, map_info->name);
    strcat(D_803823A0, " (");
    strIToA(D_803823A0, map);
    strcat(D_803823A0, ")");
    return D_803823A0;
}

enum map_e level_get_main_map(enum level_e level_id) {
    Struct_core2_83D70_1 *phi_v1;

    for(phi_v1 = D_8036BCE8; phi_v1->level_id != 0; phi_v1++){
        if (level_id == phi_v1->level_id) {
            return phi_v1->map_id;
        }
    }
    return 0;
}


s32 level_get_main_exit(enum level_e level_id) {
    Struct_core2_83D70_1 *phi_v1;

    for(phi_v1 = D_8036BCE8; phi_v1->level_id != 0; phi_v1++){
        if (level_id == phi_v1->level_id) {
            return phi_v1->exit_id;
        }
    }
    return 0;
}

void func_8030AE70(s32 *arg0) {
    MapInfo *var_v0;
    s16 var_v1;
    s32 *var_s0;
    s32 *var_s0_2;
    s32 temp_t1;
    s32 temp_v0;
    s32 var_s1;
    s32 i;

    var_v0 = D_8036B810 + 1;
    var_s1 = 0;
    while(var_v0->map_id != 0) {
        arg0[var_s1] = var_v0->map_id;
        var_s1++;
        var_v0++;
    }
    arg0[var_s1] = 0;
    var_s1 = 0;
    while(arg0[var_s1 + 1] != 0){
        if (strcmp(func_8030AD00(arg0[var_s1])->name, func_8030AD00(arg0[var_s1 + 1])->name) > 0) {
            temp_v0 = arg0[var_s1];
            arg0[var_s1] = arg0[var_s1 + 1];
            arg0[var_s1 + 1] = temp_v0;
            var_s1 = 0;
        } else {
            var_s1++;
        }
    }
}

bool func_8030AF58(enum map_e arg0) {
    MapInfo *phi_v0;

    for(phi_v0 = &D_8036B810[1]; phi_v0->map_id != 0; phi_v0++) {
        if(phi_v0->map_id == arg0){
            return TRUE;
        }
    }
    return FALSE;
}

void func_8030AFA0(enum map_e arg0){
    s32 level = map_getLevel(arg0);
    if(level > 0 && level < LEVEL_C_BOSS){
        jiggylist_set_level(arg0);
    }
}

void func_8030AFD8(s32 arg0){
    s32 sp1C = level_get();
    func_80321918(0);
    if(arg0){
        func_802C5994();
    }
    if(sp1C > 0 && sp1C < 0xC){
        func_8033301C();
    }
    func_8034789C();
    baMotor_80250FC0(); //stop controller motor
    gcpausemenu_80314B24();
    func_80347A70();
}
