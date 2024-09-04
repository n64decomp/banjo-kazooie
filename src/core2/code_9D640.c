#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s16 map_id;
    u8 unk2[5];
    // u8 pad6[1];
}Struct_core2_9D640_0;

typedef struct {
    s32 unk0;
    s32 unk4;
}Struct_core2_9D640_1;

extern Struct_core2_9D640_0 D_8036E420[] = {
    { MAP_1_SM_SPIRAL_MOUNTAIN,         {1,  7,  6,  5, 1}},
    { MAP_2_MM_MUMBOS_MOUNTAIN,         {1,  5,  6,  1, 1}},
    { MAP_7_TTC_TREASURE_TROVE_COVE,    {2,  5,  6,  1, 1}},
    { MAP_26_MMM_NAPPERS_ROOM,          {1,  5,  1,  1, 1}},
    { MAP_B_CC_CLANKERS_CAVERN,         {1,  9, 10,  8, 1}},
    { MAP_D_BGS_BUBBLEGLOOP_SWAMP,      {8, 11,  1,  1, 1}},
    { MAP_12_GV_GOBIS_VALLEY,           {2,  6,  1,  1, 1}},
    { MAP_13_GV_MEMORY_GAME,            {6,  1,  1,  6, 1}},
    { MAP_14_GV_SANDYBUTTS_MAZE,        {6,  1,  1,  1, 1}},
    { MAP_15_GV_WATER_PYRAMID,          {6,  1,  1,  1, 1}},
    { MAP_16_GV_RUBEES_CHAMBER,         {6,  1,  1,  1, 1}},
    { MAP_1A_GV_INSIDE_JINXY,           {6,  1,  1,  1, 1}},
    { MAP_1B_MMM_MAD_MONSTER_MANSION,   {1,  7,  6, 12, 5}},
    { MAP_21_CC_WITCH_SWITCH_ROOM,      {1,  9, 10,  8, 1}},
    { MAP_22_CC_INSIDE_CLANKER,         {1,  9, 10,  8, 1}},
    { MAP_23_CC_GOLDFEATHER_ROOM,       {1,  9, 10,  8, 1}},
    { MAP_27_FP_FREEZEEZY_PEAK,         {3,  5,  3,  1, 1}},
    { MAP_31_RBB_RUSTY_BUCKET_BAY,      {9, 10,  5,  6, 1}},
    { MAP_46_CCW_WINTER,                {3,  1,  1,  1, 1}},
    { MAP_72_GL_BGS_LOBBY,              {1,  8, 11,  3, 5}},
    { MAP_6F_GL_FP_LOBBY,               {1,  3,  3,  1, 1}},
    { MAP_40_CCW_HUB,                   {1,  6,  5,  3, 7}},
    {0}
};
extern Struct_core2_9D640_1 D_8036E4D8[] = {
    {0X80000000,  1},
    {0X80000100, 10},
    {0X80000200,  9},
    {0X80000300,  6},
    {0X80000400,  5},
    {0X80000500,  3},
    {0X80000600,  7},
    {0X80000700,  8},
    {0X80000800,  2},
    {0X80000900, 11},
    {0X80000A00,  1},
    {0X80000B00,  1},
    {0X80000C00,  1},
    {0X80000D00,  1},
    {0X80000E00,  1},
    {0X80000F00,  1},
    00
};

s32 func_803245D0(enum map_e map_id, s32 arg1){
    s32 i;

    for(i = 0; D_8036E4D8[i].unk0; i++){
        if(D_8036E4D8[i].unk0 == (arg1 & 0x80001F00)){
            return D_8036E4D8[i].unk4;
        }
    }
    return TRUE;
}

s32 func_80324624(enum map_e map_id, s32 arg1){
    s32 i;
    s32 sub_indx;

    sub_indx = 0;
    if(arg1 & 0x0200){ sub_indx = 1; }
    if(arg1 & 0x0400){ sub_indx = 2; }
    if(arg1 & 0x0800){ sub_indx = 3; }
    if(arg1 & 0x1000){ sub_indx = 4; }
    for(i = 0; D_8036E420[i].map_id != 0; i++){
        if(map_id == D_8036E420[i].map_id){
            return D_8036E420[i].unk2[sub_indx];
        }
    }
    return TRUE;
}

s32 func_803246B4(enum map_e map_id, s32 arg1){
    if(arg1 & 0x80000000){
        func_803245D0(map_id, arg1);
    }
    else{
        func_80324624(map_id, arg1);
    }
}
