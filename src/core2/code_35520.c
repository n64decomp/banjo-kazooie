#include <ultra64.h>
#include "functions.h"
#include "variables.h"

// This file defines the distances for type-4 camera nodes (the normal 3rd person view camera?) for each map

struct camera_node_type4_vectors_s {
    s16 map_id;
    s16 entry_id;
    s16 near[3];
    s16 medium[3];
    s16 far[3];
};

struct overlay_table_map_s {
    enum overlay_e overlay_id;
    struct camera_node_type4_vectors_s *table;
};

static struct camera_node_type4_vectors_s sCode35520Table_SM[] = {
    { MAP_1_SM_SPIRAL_MOUNTAIN, 1, { 800, 850, 375 }, { 950, 1000, 525 }, { 1100, 1150, 675 } },
    { MAP_0_UNKNOWN,            0, { 550, 600, 175 }, { 850,  900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_MM[] = {
    { MAP_2_MM_MUMBOS_MOUNTAIN, 1, { 800, 850, 550 }, { 950, 1000, 750 }, { 1100, 1150, 1050 } },
    { MAP_2_MM_MUMBOS_MOUNTAIN, 0, { 550, 600, 175 }, { 850,  900, 375 }, { 1100, 1150,  675 } },
    { MAP_0_UNKNOWN,            0, { 550, 600, 175 }, { 850,  900, 375 }, { 1100, 1150,  675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_TTC[] = {
    { MAP_8F_TTC_SHARKFOOD_ISLAND,   0, { 375, 425, 175 }, { 525, 575, 575 }, {  675,  725,  975 } },
    { MAP_7_TTC_TREASURE_TROVE_COVE, 4, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150,  675 } },
    { MAP_7_TTC_TREASURE_TROVE_COVE, 3, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150,  675 } },
    { MAP_7_TTC_TREASURE_TROVE_COVE, 2, { 550, 600, 175 }, { 850, 900, 475 }, {  950, 1000,  775 } },
    { MAP_7_TTC_TREASURE_TROVE_COVE, 1, { 700, 750, 450 }, { 850, 900, 750 }, { 1000, 1050, 1050 } },
    { MAP_7_TTC_TREASURE_TROVE_COVE, 0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150,  675 } },
    { MAP_0_UNKNOWN,                 0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150,  675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_CC[] = {
    { MAP_B_CC_CLANKERS_CAVERN, 1, { 650, 700, 275 }, { 875, 925, 475 }, { 1100, 1150, 675 } },
    { MAP_0_UNKNOWN,            0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_BGS[] = {
    { MAP_D_BGS_BUBBLEGLOOP_SWAMP, 5, { 550, 600, 225 }, { 850, 900, 450 }, { 1100, 1150, 750 } },
    { MAP_D_BGS_BUBBLEGLOOP_SWAMP, 3, { 550, 600, 225 }, { 850, 900, 375 }, { 1100, 1150, 675 } },
    { MAP_D_BGS_BUBBLEGLOOP_SWAMP, 2, { 550, 600, 175 }, { 750, 800, 475 }, {  950, 1000, 750 } },
    { MAP_D_BGS_BUBBLEGLOOP_SWAMP, 1, { 550, 600, 175 }, { 850, 900, 425 }, { 1100, 1150, 675 } },
    { MAP_0_UNKNOWN,               0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_FP[] = {
    { MAP_0_UNKNOWN, 0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_GV[] = {
    { MAP_12_GV_GOBIS_VALLEY, 4, { 550, 600, 175 }, { 750, 800, 375 }, {  950, 1000, 675 } },
    { MAP_12_GV_GOBIS_VALLEY, 3, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } },
    { MAP_12_GV_GOBIS_VALLEY, 2, { 550, 600, 175 }, { 725, 775, 475 }, {  900,  950, 775 } },
    { MAP_12_GV_GOBIS_VALLEY, 1, { 550, 600, 175 }, { 750, 800, 575 }, {  950, 1000, 975 } },
    { MAP_0_UNKNOWN,          0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_MMM[] = {
    { MAP_26_MMM_NAPPERS_ROOM,        1, { 550, 600, 175 }, { 850, 900, 225 }, { 1100, 1150, 275 } },
    { MAP_1B_MMM_MAD_MONSTER_MANSION, 3, { 550, 600, 200 }, { 750, 800, 375 }, {  950, 1000, 675 } },
    { MAP_1B_MMM_MAD_MONSTER_MANSION, 2, { 550, 600, 200 }, { 750, 800, 325 }, {  950, 1000, 450 } },
    { MAP_1B_MMM_MAD_MONSTER_MANSION, 1, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } },
    { MAP_0_UNKNOWN,                  0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_RBB[] = {
    { MAP_34_RBB_ENGINE_ROOM,      1, { 550, 600, 175 }, { 775, 825, 575 }, {  900,  950, 1000 } }, 
    { MAP_34_RBB_ENGINE_ROOM,      0, { 550, 600, 175 }, { 775, 825, 475 }, {  900,  950,  775 } }, 
    { MAP_31_RBB_RUSTY_BUCKET_BAY, 3, { 550, 600, 350 }, { 675, 725, 725 }, {  800,  850, 1100 } }, 
    { MAP_31_RBB_RUSTY_BUCKET_BAY, 2, { 550, 600, 175 }, { 750, 800, 525 }, {  950, 1000,  875 } }, 
    { MAP_31_RBB_RUSTY_BUCKET_BAY, 1, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150,  675 } }, 
    { MAP_0_UNKNOWN,               0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150,  675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_CCW[] = {
    { MAP_43_CCW_SPRING, 2, { 550, 600, 225 }, { 850,  900, 425 }, { 1100, 1150,  675 } },
    { MAP_44_CCW_SUMMER, 2, { 550, 600, 225 }, { 850,  900, 425 }, { 1100, 1150,  675 } },
    { MAP_45_CCW_AUTUMN, 2, { 550, 600, 225 }, { 850,  900, 425 }, { 1100, 1150,  675 } },
    { MAP_46_CCW_WINTER, 2, { 550, 600, 225 }, { 850,  900, 425 }, { 1100, 1150,  675 } },
    { MAP_43_CCW_SPRING, 1, { 800, 850, 550 }, { 950, 1000, 800 }, { 1100, 1150, 1050 } }, 
    { MAP_44_CCW_SUMMER, 1, { 800, 850, 550 }, { 950, 1000, 800 }, { 1100, 1150, 1050 } }, 
    { MAP_45_CCW_AUTUMN, 1, { 800, 850, 550 }, { 950, 1000, 800 }, { 1100, 1150, 1050 } }, 
    { MAP_46_CCW_WINTER, 1, { 800, 850, 550 }, { 950, 1000, 800 }, { 1100, 1150, 1050 } }, 
    { MAP_0_UNKNOWN,     0, { 550, 600, 175 }, { 850,  900, 375 }, { 1100, 1150,  675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_Lair [] = {
    { MAP_0_UNKNOWN, 0, { 550, 600, 150 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_Fight [] = {
    { MAP_90_GL_BATTLEMENTS, 0, { 600, 650, 200 }, { 1200, 1300, 325 }, { 1800, 1900, 450 } }
};

static struct camera_node_type4_vectors_s sCode35520Table_Default [] = {
    { MAP_0_UNKNOWN, 0, { 550, 600, 175 }, { 850, 900, 375 }, { 1100, 1150, 675 } }
};

static struct overlay_table_map_s sCode35520_map[] = {
    { OVERLAY_6_JUNGLE,   sCode35520Table_MM },
    { OVERLAY_5_BEACH,    sCode35520Table_TTC },
    { OVERLAY_2_WHALE,    sCode35520Table_CC },
    { OVERLAY_7_SWAMP,    sCode35520Table_BGS },
    { OVERLAY_9_SNOW,     sCode35520Table_FP },
    { OVERLAY_D_WITCH,    sCode35520Table_Lair },
    { OVERLAY_4_DESERT,   sCode35520Table_GV },
    { OVERLAY_A_TREE,     sCode35520Table_CCW },
    { OVERLAY_8_SHIP,     sCode35520Table_RBB },
    { OVERLAY_3_HAUNTED,  sCode35520Table_MMM },
    { OVERLAY_B_TRAINING, sCode35520Table_SM },
    { OVERLAY_E_BATTLE,   sCode35520Table_Fight },
    { 0 }
};

static struct camera_node_type4_vectors_s *sCode35520_activeTable;

static struct camera_node_type4_vectors_s *code35520_findTableEntry(s32 id) {
    s32 map_id = gsworld_getMap();
    s32 i;

    for (i = 0; sCode35520_activeTable[i].map_id != 0; i++) {
        if (map_id == sCode35520_activeTable[i].map_id && id == sCode35520_activeTable[i].entry_id) {
            return &sCode35520_activeTable[i];
        }
    }

    return &sCode35520_activeTable[i];
}

void code35520_getDistanceVectors(s32 id, s32 *vec11, s32 *vec12, s32 *vec13, s32 *vec21, s32 *vec22, s32 *vec23, s32 *vec31, s32 *vec32, s32 *vec33) {
    struct camera_node_type4_vectors_s *entry = code35520_findTableEntry(id);
    *vec11 = entry->near[0];
    *vec12 = entry->near[1];
    *vec13 = entry->near[2];
    *vec21 = entry->medium[0];
    *vec22 = entry->medium[1];
    *vec23 = entry->medium[2];
    *vec31 = entry->far[0];
    *vec32 = entry->far[1];
    *vec33 = entry->far[2];
}

void code35520_selectTable(void) {
    int i;
    enum overlay_e overlay = overlayManager_getLoadedID();

    sCode35520_activeTable = sCode35520Table_Default;

    for (i = 0; sCode35520_map[i].overlay_id; i++) {
        if (sCode35520_map[i].overlay_id == overlay) {
            sCode35520_activeTable = sCode35520_map[i].table;
        }
    }
}
