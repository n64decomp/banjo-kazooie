#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void player_walkToPosition(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);
extern void func_8028F760(s32, f32, f32);
extern void func_8031CE70(f32 *arg0, enum map_e arg1, s32 arg2);
extern NodeProp *func_80304ED0(void*, f32 *);
extern void func_8031CD44(enum map_e, s32, f32, f32, s32);

bool cutscene_skipEnterLairCutsceneCheck(void);
bool cutscene_skipGameOverCutsceneCheck(void);
bool cutscene_skipIntroCutsceneCheck(void);
bool cutscene_skipBeachCutsceneCheck(void);

extern void func_802DC560(s32, s32);

extern u8 D_8037DCCE[];

/* .data */
enum actor_e D_8036DDD0[] = {0, 0x184, 0x185, 0x186, -1};

/* .bss */
u8 D_80383190;

/* .code */
// func_8031C640
bool cutscene_skipIntroCutsceneCheck(void) {
    if ((controller_getStartButtonSafe(0) == 1) && (gameFile_anyNonEmpty() != 0)) {
        return TRUE;
    }
    return FALSE;
}

// func_8031C688
bool cutscene_skipEnterLairCutsceneCheck(void) {
    if ((controller_getStartButtonSafe(0) == 1) 
        && ((D_8037DCCE[0] != 0) 
            || (D_8037DCCE[1] != 0) 
            || (D_8037DCCE[2] != 0))) {
        return TRUE;
    }
    return FALSE;
}


bool cutscene_skipGameOverCutsceneCheck(void) {
    s32 sp24;

    sp24 = controller_getStartButtonSafe(0);
    if (mapSpecificFlags_get(0) != 0) {
        fileProgressFlag_set(FILEPROG_E1_UNKNOWN, 1);
    }
    if ((sp24 == 1) && fileProgressFlag_get(FILEPROG_E1_UNKNOWN) && !gctransition_8030BDC0()) {
        if (!mapSpecificFlags_get(0xC)) {
            mapSpecificFlags_set(0xC, TRUE);
            func_802DC528(0, 0);
            timedFunc_set_2(11.0f, (GenFunction_2)func_802DC560, 0, 0);
            timedFunc_set_3(12.0f, (GenFunction_3)transitionToMap, MAP_1F_CS_START_RAREWARE, 0, 1);
        } else {
            timedFuncQueue_flush();
        }
    }
    return FALSE;
}

bool cutscene_skipBeachCutsceneCheck(void){
    func_803219F4(1);
    return FALSE;
}

//checks is a cutscene can be inturrupted and performs take me there
void cutscenetrigger_check(s32 cs_map, s32 arg1, s32 return_map, s32 return_exit, bool (* condFunc)(void)){
    if(gsworld_getMap() != cs_map)
        return;

    if((condFunc && condFunc()) || mapSpecificFlags_get(arg1)){
        mapSpecificFlags_set(arg1, 0);
        transitionToMap(return_map, (return_exit == -1)? 0: return_exit, 1);
    }
}

//check cutscene interrupts
s32 cutscenetrigger_update(void)
{
    cutscenetrigger_check(MAP_86_CS_SPIRAL_MOUNTAIN_4,        0, MAP_89_CS_INTRO_BANJOS_HOUSE_2,                          -1, NULL);
    cutscenetrigger_check(MAP_7D_CS_SPIRAL_MOUNTAIN_1,        0, MAP_7C_CS_INTRO_BANJOS_HOUSE_1,                          -1, NULL);
    cutscenetrigger_check(MAP_7C_CS_INTRO_BANJOS_HOUSE_1,     0, MAP_86_CS_SPIRAL_MOUNTAIN_4,                             -1, NULL);
    cutscenetrigger_check(MAP_89_CS_INTRO_BANJOS_HOUSE_2,     0, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, NULL);
    cutscenetrigger_check(MAP_85_CS_SPIRAL_MOUNTAIN_3,        0, MAP_7B_CS_INTRO_GL_DINGPOT_1,                            -1, NULL);
    cutscenetrigger_check(MAP_7B_CS_INTRO_GL_DINGPOT_1,       1, MAP_81_CS_INTRO_GL_DINGPOT_2,                            -1, NULL);
    cutscenetrigger_check(MAP_81_CS_INTRO_GL_DINGPOT_2,       0, MAP_7D_CS_SPIRAL_MOUNTAIN_1,                             -1, NULL);
    cutscenetrigger_check(MAP_82_CS_ENTERING_GL_MACHINE_ROOM, 0, MAP_69_GL_MM_LOBBY,            WARP_GL_MM_LOBBY_12_ENTRANCE, cutscene_skipEnterLairCutsceneCheck);
    cutscenetrigger_check(MAP_83_CS_GAME_OVER_MACHINE_ROOM,   0, MAP_1F_CS_START_RAREWARE,                                -1, cutscene_skipGameOverCutsceneCheck);
    cutscenetrigger_check(MAP_87_CS_SPIRAL_MOUNTAIN_5,        0, MAP_88_CS_SPIRAL_MOUNTAIN_6,                             -1, NULL);
    cutscenetrigger_check(MAP_94_CS_INTRO_SPIRAL_7,           0, MAP_8E_GL_FURNACE_FUN,                                    4, NULL);
    cutscenetrigger_check(MAP_88_CS_SPIRAL_MOUNTAIN_6,        1, MAP_96_CS_END_BEACH_1,                                   -1, NULL);
    cutscenetrigger_check(MAP_98_CS_END_SPIRAL_MOUNTAIN_1,    0, MAP_1F_CS_START_RAREWARE,                                -1, NULL);
    cutscenetrigger_check(MAP_99_CS_END_SPIRAL_MOUNTAIN_2,    0, MAP_1F_CS_START_RAREWARE,                                -1, NULL);
    cutscenetrigger_check(MAP_20_CS_END_NOT_100,              0, MAP_98_CS_END_SPIRAL_MOUNTAIN_1,                         -1, NULL);
    cutscenetrigger_check(MAP_95_CS_END_ALL_100,              0, MAP_99_CS_END_SPIRAL_MOUNTAIN_2,                         -1, NULL);
    cutscenetrigger_check(MAP_97_CS_END_BEACH_2,              0, MAP_99_CS_END_SPIRAL_MOUNTAIN_2,                         -1, cutscene_skipBeachCutsceneCheck);
    cutscenetrigger_check(MAP_85_CS_SPIRAL_MOUNTAIN_3,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_7B_CS_INTRO_GL_DINGPOT_1,     0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_81_CS_INTRO_GL_DINGPOT_2,     0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_7D_CS_SPIRAL_MOUNTAIN_1,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_7C_CS_INTRO_BANJOS_HOUSE_1,   0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_86_CS_SPIRAL_MOUNTAIN_4,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_89_CS_INTRO_BANJOS_HOUSE_2,   0xC, MAP_1_SM_SPIRAL_MOUNTAIN,             WARP_SM_12_FROM_HOUSE, cutscene_skipIntroCutsceneCheck);

    if (gsworld_getMap() == MAP_95_CS_END_ALL_100 && mapSpecificFlags_get(1))
    {
        func_8034B9E4();
        mapSpecificFlags_set(1, 0);
    }

    return 0;
}

void func_8031CB50(enum map_e map_id, s32 exit_id, s32 arg2) {
    s32 sp1C;

    if ((D_80383190 == 0) && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS) && (getGameMode() != GAME_MODE_7_ATTRACT_DEMO)) {
        sp1C = core2_9B650_getMusicTrackFromMap(gsworld_getMap());
        if ((core2_9B650_getMusicTrackFromMap(map_id) != sp1C) && (func_80322914() == 0)) {
            func_8025A388(0, 0x4E2);
            func_8025AB00();
            midichannel_incOrDecCounter(FALSE);
        }
        if (func_802E4A08()) {
            game_setNextMap(map_id, exit_id);
            game_setMapTransition(1);
            game_setMapChangeRequest(0xB);
        } else {
            transitionToMap(map_id, exit_id, 1);
        }
        gsworld_setEnableUpdate(arg2);
    }
}

void func_8031CC40(enum map_e map_id, s32 arg1) {
    func_8031CB50(map_id, arg1, 0);
}

#define _func_8031CC60(map, entry) \
    func_8031CC60(((map) << 8) + (entry))

void func_8031CC60(s32 arg0) {
    func_8031CB50(arg0 >> 8, arg0 & 0xFF, 1);
}

#define _func_8031CC8C(nodepos, map, entry) \
    func_8031CC8C((nodepos), ((map) << 8) + (entry))

void func_8031CC8C(s32 arg0, s32 arg1) {
    // arg1 = MAP_ID + ENTRY_ID
    f32 vec[3];
    f32 unused[3];

    if ((D_80383190 == 0) && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS)) {
        if (getGameMode() != GAME_MODE_7_ATTRACT_DEMO) {
            if (arg0 != 0) {
                ml_vec3h_to_vec3f(vec, arg0);
                func_8031CE70(vec, arg1 >> 8, arg1 & 0xFF);
            } else {
                func_8031CE70(NULL, arg1 >> 8, arg1 & 0xFF);
            }
        }
    }
}

void func_8031CD20(s32 arg0, s32 arg1, s32 arg2) {
    _func_8031CC8C(arg0, arg1, arg2);
}

void func_8031CD44(enum map_e arg0, s32 arg1, f32 arg2, f32 yaw, s32 arg4) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    player_getPosition((f32 *) &sp3C);
    func_80256E24(sp24, 0.0f, yaw, 0.0f, 0.0f, ml_map_f((f32) arg4, 0.0f, 200.0f, 10.0f, 800.0f));
    sp24[0] = sp3C[0] + sp24[0];
    sp24[1] = sp3C[1] + sp24[1];
    sp24[2] = sp3C[2] + sp24[2];
    sp30[0] = sp24[0];
    sp30[1] = arg2;
    sp30[2] = sp24[2];
    ncDynamicCamera_setUpdateEnabled(0);
    func_8031CB50(arg0, arg1, 1);
    player_walkToPosition(sp30, 1.0f, NULL, NULL);
}

void func_8031CE28(s32 arg0, s32 arg1, f32 arg2) {
    f32 vec[3];

    player_getPosition(vec);
    func_8031CD44(arg0, arg1, vec[1], arg2, 0x25);
}

void func_8031CE70(f32 *arg0, enum map_e arg1, s32 arg2) {
    f32 playerPos[3];
    f32 sp38[3];
    NodeProp *phi_s0;
    f32 phi_f2;

    if ((D_80383190 == 0) && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS) && (getGameMode() != GAME_MODE_7_ATTRACT_DEMO)) {
        if (arg0 != 0) {
            phi_s0 = func_80304ED0(&D_8036DDD0[1], arg0);
        } else {
            phi_s0 = NULL;
        }
        player_getPosition(playerPos);
        if (phi_s0 != NULL) {
            nodeprop_getPosition(phi_s0, sp38);
            phi_f2 = 500.0f;
            if (phi_s0->actorId == 0x186) {
                phi_f2 = 1000.0f;
            }
            if (ml_vec3f_distance(arg0, sp38) < phi_f2) {
                if (phi_s0->actorId == 0x184) {
                    ncDynamicCamera_setUpdateEnabled(0);
                    func_8031CB50(arg1, arg2, 1);
                    player_walkToPosition(sp38, 1.0f, NULL, NULL);
                } else if (phi_s0->actorId == 0x185) {
                    func_8031CD44(arg1, arg2, sp38[1], (f32) phi_s0->yaw, phi_s0->scale);
                } else {
                    func_8031CD44(arg1, arg2, playerPos[1], (f32) phi_s0->yaw, phi_s0->scale);
                }
                return;
            }
        }
        func_8031CB50(arg1, arg2, 0);
    }
}

// set map and exit id?
void func_8031D04C(enum map_e arg0, s32 exit_id) {
    func_8031CB50(arg0, exit_id, 0);
}

void func_8031D06C(enum map_e arg0, s32 arg1) {
    func_8031CB50(MAP_20_CS_END_NOT_100, 0, 0);
}

void func_8031D09C(s32 arg0, s32 arg1) {
    func_8034B968();
}

void func_8031D0C0(s32 arg0, s32 arg1) {
    if (controller_getStartButtonSafe(0) == 1) {
        game_setMapTransitionWithStyle(1, 2);
        func_8025A2FC(0, 0x320);
        func_8025AB00();
        func_8031D09C(arg0, arg1);
    }
}

void warp_mmEnterMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_E_MM_MUMBOS_SKULL, WARP_MM_MUMBOS_HUT_1_ENTRANCE);
}

void warp_mmExitMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2_MM_MUMBOS_MOUNTAIN, WARP_MM_1_MUMBOS_HUT);
}

void warp_mmEnterTickersTowerLower(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_C_MM_TICKERS_TOWER, WARP_MM_TICKERS_TOWER_2_BOTTOM);
}

void warp_mmExitTickersTowerLower(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2_MM_MUMBOS_MOUNTAIN, WARP_MM_2_TOWER_BOTTOM);
}

void warp_mmEnterTickersTowerUpper(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_C_MM_TICKERS_TOWER, WARP_MM_TICKERS_TOWER_1_TOP);
}

void warp_mmExitTickersTowerUpper(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2_MM_MUMBOS_MOUNTAIN, WARP_MM_3_TOWER_TOP);
}

void warp_csNintendoLogo(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1E_CS_START_NINTENDO, 0);
}

void warp_gvEnterWaterPyramidLower(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_15_GV_WATER_PYRAMID, WARP_GV_WATER_PYRAMID_6_LOWER_EXIT);
}

void warp_gvEnterRubeePyramid(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
    core1_7090_freeSfxSource(1);
    _func_8031CC8C(arg0, MAP_16_GV_RUBEES_CHAMBER, WARP_GV_RUBEE_PYRAMID_7_ENTRANCE);
}

void warp_gvEnterMatchingPyramid(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
    _func_8031CC8C(arg0, MAP_13_GV_MEMORY_GAME, WARP_GV_MEMORY_PYRAMID_1_ENTRANCE);
}

void warp_gvEnterWaterPyramidUpper(s32 arg0, s32 arg1) {
    core1_7090_freeSfxSource(0);
    volatileFlag_set(VOLATILE_FLAG_AC_GV_TRAPDOOR_MISSED, 1);
    _func_8031CC8C(arg0, MAP_15_GV_WATER_PYRAMID, WARP_GV_WATER_PYRAMID_2_TOP);
}

void warp_gvEnterMazePyramid(s32 arg0, s32 arg1) {
    if (fileProgressFlag_getN(FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2) == 3)
        _func_8031CC8C(arg0, MAP_14_GV_SANDYBUTTS_MAZE, WARP_GV_MAZE_PYRAMID_1_ENTRANCE);
}

void warp_gvExitMatchingPyramid(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_3_MEMORY_PYRAMID);
}

void warp_gvExitMazePyramid(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_4_MAZE_PYRAMID_FRONT);
}

void warp_gvExitWaterPyramidLower(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_5_WATER_PYRAMID);
}

void warp_gvExitRubeePyramid(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_6_RUBEE_PYRAMID);
}

void warp_bgsEnterTanktup(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_11_BGS_TIPTUP, WARP_BGS_TIPTUP_1_ENTRANCE);
}

void warp_bgsExitTanktup(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_D_BGS_BUBBLEGLOOP_SWAMP, WARP_BGS_3_TURTLE);
}

void warp_bgsExitVileRightNostril(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_D_BGS_BUBBLEGLOOP_SWAMP, WARP_BGS_4_CROC_LEFT);
}

void warp_bgsExitVileLeftNostril(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_D_BGS_BUBBLEGLOOP_SWAMP, WARP_BGS_5_CROC_RIGHT);
}

void warp_ttcEnterSandcastle(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_A_TTC_SANDCASTLE, WARP_TCC_SANDCASTLE_1_ENTRANCE);
}

void warp_ttcStairAlcoveDown(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_F_CLIFFSIDE_STAIRS);
}

void warp_ttcStairAlcoveUp(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_E_ISLAND_TOP_STAIRS);
}

void warp_ttcEnterBlubbersShipUpper(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5_TTC_BLUBBERS_SHIP, WARP_TCC_BLUBBERS_SHIP_5_TOP_HATCH);
}

void warp_ttcEnterBlubbersShipSide(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5_TTC_BLUBBERS_SHIP, WARP_TCC_BLUBBERS_SHIP_6_SIDE_HATCH);
}

void warp_ttcExitLighthouseTop(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_8_LIGHTHOUSE_TOP);
}

void warp_ttcExitSandcastle(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_3_SANDCASTLE);
}

// Unused
void func_8031D550(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_4_WORLD_ENTRANCE);
}

// Unused
void func_8031D574(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_5_UNKNOWN);
}

void warp_ttcExitBlubbersShipUpper(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_6_SHIP_TOP_HATCH);
}

void warp_ttcExitBlubbersShipSide(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_7_SHIP_SIDE_HATCH);
}

// Unused
void warp_ttcExitLighthouseTopUnused(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_8_LIGHTHOUSE_TOP);
}

// Unused
void func_8031D604(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_9_UNKNOWN);
}

void func_8031D628(s32 arg0, s32 arg1) {
    Actor *actor;

    actor = actorArray_findActorFromActorId(ACTOR_13E_LIGHTHOUSE_DOOR);
    if (actor)
        marker_despawn(actor->marker);

    func_8031CB50(MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_C_LIGHTHOUSE_BOTTOM, 0);
}

void warp_mmmEnterDiningRoomDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_26_MMM_NAPPERS_ROOM, WARP_MMM_DINING_1_FRONT_ENTRANCE);
}

void warp_mmmEnterDiningRoomChimney(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_26_MMM_NAPPERS_ROOM, WARP_MMM_DINING_2_CHIMNEY);
}

void warp_mmmEnterWellTop(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_25_MMM_WELL, WARP_MMM_WELL_1_TOP_ENTRANCE);
}

void warp_mmmEnterTumblarShed(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_24_MMM_TUMBLARS_SHED, WARP_MMM_SHED_1_ENTRANCE);
}

void warp_mmmEnterCellar(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1D_MMM_CELLAR, WARP_MMM_CELLAR_1_ENTRANCE);
}

void warp_mmmEnterRedFeatherRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2A_MMM_FEATHER_ROOM, WARP_MMM_RED_FEATHER_1_ENTRANCE);
}

void warp_mmmEnterBlueEggRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_28_MMM_EGG_ROOM, WARP_MMM_EGG_1_ENTRANCE);
}

void warp_mmmEnterNoteRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_29_MMM_NOTE_ROOM, WARP_MMM_NOTE_1_ENTRANCE);
}

void warp_mmmEnterBrokenFloorboardRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2E_MMM_HONEYCOMB_ROOM, 0x1);
}

void warp_mmmEnterBedroom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2D_MMM_BEDROOM, WARP_MMM_BEDROOM_1_ENTRANCE);
}

void warp_mmmEnterBathroomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2C_MMM_BATHROOM, WARP_MMM_BATHROOM_1_ENTRANCE);
}

void warp_mmmExitDiningRoomDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_1_MANSION_DOOR);
}

void func_8031D820(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_2_stubbed);
}

void warp_mmmExitWellTop(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_3_WELL_TOP);
}

void warp_mmmExitTumblarShed(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_4_SHED);
}

void warp_mmmExitChurchFrontDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_5_CHURCH_DOOR);
}

void warp_mmmExitChurchSecretRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_6_CHURCH_WINDOW);
}

void func_8031D8D4(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_7_CHIMNEY);
}

void warp_mmmExitRainBarrelBottom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_8_DRAINPIPE_BOTTOM);
}

void warp_mmmExitCellar(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_9_CELLAR);
}

void warp_mmmExitRedFeatherRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_A_F1_RED_FEATHER_WINDOW);
}

void warp_mmmExitBlueEggRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_B_F1_EGG_WINDOW);
}

void warp_mmmExitBathroomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_C_F2_BATHROOM_WINDOW);
}

void warp_mmmExitBrokenFloorboardRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_D_F2_GOLD_FEATHER_WINDOW);
}

void warp_mmmExitBedroom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_E_F3_BEDROOM_WINDOW);
}

void warp_mmmExitNoteRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_F_F3_NOTE_WINDOW);
}

void warp_mmmChurchTowerUp(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_10_CHURCH_TOP);
}

void warp_mmmChurchTowerDown(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_11_CHURCH_CLOCK);
}

void warp_mmmExitMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_12_MUMBOS_HUT);
}

void warp_mmmEnterChurchSecretRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2B_MMM_SECRET_CHURCH_ROOM, WARP_MMM_CHURCH_WINDOW_1_ENTRANCE);
}

void func_8031DAA8(enum map_e arg0, s32 arg1) {
    func_8028F918(0);
    func_8031CB50(arg0, arg1, 0);
}

void func_8031DAE0(s32 arg0, s32 arg1) {
    if (mapSpecificFlags_get(2) == 0) {
        volatileFlag_set(VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED, 1);
        core1_7090_freeSfxSource(0);
        mapSpecificFlags_set(2, 1);
        coMusicPlayer_playMusic(COMUSIC_3B_MINIGAME_VICTORY, 0x6D60);
        func_8028F918(1);
        timedFunc_set_2(1.8f, &func_8031DAA8, MAP_1C_MMM_CHURCH, WARP_MMM_CHURCH_1_ENTRANCE);
        func_802D6924();
    }
}

// Unused
void warp_mmmEnterMumbosHutUnused(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_30_MMM_MUMBOS_SKULL, WARP_MMM_MUMBOS_HUT_1_ENTRANCE);
}

void warp_mmmEnterMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_30_MMM_MUMBOS_SKULL, WARP_MMM_MUMBOS_HUT_1_ENTRANCE);
}

void warp_mmmEnterRainBarrel(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC8C(arg0, MAP_2F_MMM_WATERDRAIN_BARREL, arg1);
}

void func_8031DBE8(void) {
    func_8031CB50(MAP_2F_MMM_WATERDRAIN_BARREL, WARP_MMM_DRAINPIPE_1_TOP_ENTRANCE, 1);
}

void func_8031DC10(s32 arg0, s32 arg1) {
    f32 vec[3];

    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        ml_vec3h_to_vec3f(vec, arg0);
        func_8028F6E4(BS_INTR_2F_LOGGO, vec);
        timedFunc_set_0(0.8f, &func_8031DBE8);
    }
}

void warp_mmmEnterRainBarrelBottom(s32 arg0, s32 arg1) {
    warp_mmmEnterRainBarrel(arg0, 2);
}

void warp_bgsEnterMrVileNostril(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_5_CROC)
        _func_8031CC8C(arg0, MAP_10_BGS_MR_VILE, arg1);
}

void warp_bgsEnterMrVileRightNostril(s32 arg0, s32 arg1) {
    warp_bgsEnterMrVileNostril(arg0, 3);
}

void warp_bgsEnterMrVileLeftNostril(s32 arg0, s32 arg1) {
    warp_bgsEnterMrVileNostril(arg0, 4);
}

void warp_bgsEnterTanktupConditional(s32 arg0, s32 arg1) {
    if (func_8038F570() != 0)
        _func_8031CC8C(arg0, MAP_11_BGS_TIPTUP, WARP_BGS_TIPTUP_1_ENTRANCE);
}

void warp_ttcEnterNippersShell(s32 arg0, s32 arg1) {
    if (chNipper_isInState7() != 0)
        _func_8031CC8C(arg0, MAP_6_TTC_NIPPERS_SHELL, WARP_TCC_NIPPERS_SHELL_1_ENTRANCE);
}

void warp_ccExitWonderwingRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_22_CC_INSIDE_CLANKER, WARP_CC_INSIDE_CLANKER_3_GOLD_FEATHER_ENTRANCE);
}

void warp_ccEnterClankerBelly(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_22_CC_INSIDE_CLANKER, WARP_CC_INSIDE_CLANKER_1_TOP);
}

void warp_ccEnterClankerMouth(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_22_CC_INSIDE_CLANKER, WARP_CC_INSIDE_CLANKER_2_MOUTH_ROOFTOP);
}

void warp_ccEnterWonderwingRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_23_CC_GOLDFEATHER_ROOM, WARP_CC_GOLD_FEATHER_1_ENTRANCE);
}

void warp_mmEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_2_MM_MUMBOS_MOUNTAIN, WARP_MM_5_WORLD_ENTRACE);
}

void warp_gvEnterJinxy(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1A_GV_INSIDE_JINXY, WARP_GV_INSIDE_JINXY_2_ENTRANCE);
}

void warp_gvExitJinxy(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_2_JINXY_SPHINX);
}

void warp_rbbEnterCaptainsRoomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_3F_RBB_CAPTAINS_CABIN, WARP_RBB_CAPTAIN_CABIN_1_ENTRANCE);
}

void warp_rbbEnterCabinRoomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_39_RBB_CREW_CABIN, WARP_RBB_CREW_CABIN_1_ENTRANCE);
}

void warp_rbbEnterEngineRoomPipe(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_34_RBB_ENGINE_ROOM, WARP_RBB_ENGINE_4_PIPE_ENTRANCE);
}

void warp_rbbEnterEngineRoomDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_34_RBB_ENGINE_ROOM, WARP_RBB_ENGINE_1_ENTRANCE);
}

void warp_rbbEnterKitchenPipe(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_3C_RBB_KITCHEN, WARP_RBB_KITCHEN_1_ENTRANCE);
}

void warp_rbbEnterNavigationRoomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_3D_RBB_NAVIGATION_ROOM, WARP_RBB_NAVIGATION_1_ENTRANCE);
}

void warp_rbbEnterBoomBoxPipe(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_3B_RBB_STORAGE_ROOM, WARP_RBB_STORAGE_1_ENTRANCE);
}

void warp_rbbEnterChumpWarehouseWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_35_RBB_WAREHOUSE, WARP_RBB_WAREHOUSE_2_WINDOW);
}

void warp_rbbEnterBoatRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_36_RBB_BOATHOUSE, WARP_RBB_BOAT_1_ENTRANCE);
}

void warp_rbbEnterChompaContainer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_37_RBB_CONTAINER_1, WARP_RBB_CONTAINER_1_ENTRANCE);
}

void warp_rbbEnterSeamanGrublinContainer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_3E_RBB_CONTAINER_2, WARP_RBB_CONTAINER_2_ENTRANCE);
}

void warp_rbbEnterBoomBoxContainer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_38_RBB_CONTAINER_3, WARP_RBB_CONTAINER_3_ENTRANCE);
}

void warp_rbbExitCaptainsRoomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_1_CAPTAIN_ROOM_WINDOW);
}

void warp_rbbExitCabinRoomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_2_CREW_ROOM_WINDOW);
}

void warp_rbbExitEngineRoomPipe(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_3_ENGINE_SWITCH_PIPE);
}

void warp_rbbExitKitchenPipe(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_4_KITCHEN_PIPE);
}

void warp_rbbExitNavigationRoomWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_5_NAV_ROOM_PIPE);
}

void warp_rbbExitBoomBoxPipe(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_6_STORAGE_PIPE);
}

void warp_rbbExitEngineRoomDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_7_ENGINE_ENTRANCE);
}

void warp_rbbExitBoatRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_8_BOAT_ROOM);
}

void warp_rbbExitChompaContainer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_9_FIRST_CONTAINER);
}

void warp_rbbExitSeamanGrublinContainer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_A_SECOND_CONTAINER);
}

void warp_rbbExitBoomBoxContainer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_B_THIRD_CONTAINER);
}

void warp_rbbExitBossBoomBoxRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_C_AFTER_BOSS);
}

void warp_rbbEnterBossBoomBoxRoom(s32 arg0, s32 arg1) {
    func_8031CB50(MAP_3A_RBB_BOSS_BOOM_BOX, WARP_RBB_BOSS_1_ENTRANCE, 0);
}

void func_8031E204(NodeProp *node, s32 arg1, s32 arg2){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    nodeprop_getPosition(nodeprop_findByActorIdAndPosition_s16(ACTOR_154_UNKNOWN, &node->position_x), sp34);
    nodeprop_getPosition(nodeprop_findByActorIdAndPosition_s16(ACTOR_155_UNKNOWN, &node->position_x), sp28);
    player_getPosition(sp1C);
    if(sp28[1] < sp1C[1]){
        sp1C[1] = sp28[1];
    }
    func_8028F760(2, (sp1C[1] - sp34[1])/(sp28[1] - sp34[1]), 0.0f);
    func_8031CC8C(node, (arg1 <<8) + arg2);
}

void warp_rbbEnterChumpWarehouseDoor(NodeProp *node, ActorMarker *marker){
    func_8031E204(node, MAP_35_RBB_WAREHOUSE, WARP_RBB_WAREHOUSE_1_DOOR);
}

void warp_rbbExitChumpWarehouseDoor(NodeProp *node, ActorMarker *marker){
    func_8031E204(node, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_D_FISH_WAREHOUSE);
}

void func_8031E308(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_6);
}

// Unknown
void func_8031E32C(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_52_STUB_LL_TEMPLE, WARP_LL_TEMPLE_0);
}

// Unknown
void func_8031E350(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_51_STUB_LL_SWIM, WARP_LL_SWIM_0);
}

// Unknown
void func_8031E374(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_51_STUB_LL_SWIM, WARP_LL_SWIM_1);
}

// Unknown
void func_8031E398(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_42_STUB_LL_TIPTUPS_CAVE, WARP_LL_TIPTUPS_CAVE_0);
}

// Unknown
void func_8031E3BC(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_1);
}

// Unknown
void func_8031E3E0(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_2);
}

// Unknown
void func_8031E404(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_3);
}

// Unknown
void func_8031E428(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_4);
}

// Unknown
void func_8031E44C(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_5);
}

// Unknown
void func_8031E470(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_7);
}

// Unknown
void func_8031E494(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_8);
}

// Unknown
void func_8031E4B8(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_9);
}

// Unknown
void func_8031E4DC(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_A);
}

// Unknown
void func_8031E500(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_B);
}

// Unknown
void func_8031E524(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_C);
}

// Unknown
void func_8031E548(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_D);
}

// Unknown
void func_8031E56C(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_E);
}

// Unknown
void func_8031E590(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_F);
}

// Unknown
void func_8031E5B4(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_10);
}

// Unknown
void func_8031E5D8(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_11);
}

// Unknown
void func_8031E5FC(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_12);
}

// Unknown
void func_8031E620(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_13);
}

// Unknown
void func_8031E644(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_14);
}

// Unknown
void func_8031E668(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_15);
}

// Unknown
void func_8031E68C(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_16);
}

// Unknown
void func_8031E6B0(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_32_STUB_LL_LAVA_LEVEL, WARP_LL_17);
}

void warp_ccwExitWinterToHub(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_40_CCW_HUB, WARP_CCW_1_WINTER);
}

void warp_ccwExitSpringToHub(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_40_CCW_HUB, WARP_CCW_2_SPRING);
}

void warp_ccwExitSummerToHub(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_40_CCW_HUB, WARP_CCW_3_SUMMER);
}

void warp_ccwExitAutumnToHub(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_40_CCW_HUB, WARP_CCW_4_AUTUMN);
}

void warp_ccwEnterWinter(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_1_ENTRANCE);
}

void warp_ccwEnterSpring(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_43_CCW_SPRING, WARP_CCW_SPRING_1_ENTRANCE);
}

void warp_ccwEnterSummer(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_44_CCW_SUMMER, WARP_CCW_SUMMER_1_ENTRANCE);
}

void warp_ccwEnterAutumn(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_1_ENTRANCE);
}

void warp_gvExitSandybuttMazeBack(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_7_MAZE_PYRAMID_BACK);
}

void warp_bgsExitMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_D_BGS_BUBBLEGLOOP_SWAMP, WARP_BGS_6_MUMBOS_HUT);
}

void warp_bgsEnterMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_47_BGS_MUMBOS_SKULL, WARP_BGS_MUMBOS_HUT_1_ENTRANCE);
}

void warp_ttcEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_4_WORLD_ENTRANCE);
}

void warp_ccEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_B_CC_CLANKERS_CAVERN, WARP_CC_5_WORLD_ENTRANCE);
}

void warp_bgsEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_D_BGS_BUBBLEGLOOP_SWAMP, WARP_BGS_2_WORLD_ENTRANCE);
}

void warp_gvEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_8_WORLD_ENTRANCE);
}

void warp_mmmEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_14_WORLD_ENTRANCE);
}

void warp_rbbEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_10_WORLD_ENTRANCE);
}

void warp_ttcExitNipper(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_A_NIPPER);
}

void warp_ttcEnterSpringMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_4A_CCW_SPRING_MUMBOS_SKULL, WARP_CCW_MUMBOS_HUT_SPRING_1_ENTRANCE);
}

void warp_ttcEnterSummerMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_4B_CCW_SUMMER_MUMBOS_SKULL, WARP_CCW_MUMBOS_HUT_SUMMER_1_ENTRANCE);
}

void warp_ttcEnterAutumnMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_4C_CCW_AUTUMN_MUMBOS_SKULL, WARP_CCW_MUMBOS_HUT_AUTUMN_1_ENTRANCE);
}

void warp_ttcEnterWinterMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_4D_CCW_WINTER_MUMBOS_SKULL, WARP_CCW_MUMBOS_HUT_WINTER_1_ENTRANCE);
}

void warp_ttcExitSpringMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_43_CCW_SPRING, WARP_CCW_SPRING_9_MUMBOS_HUT);
}

void warp_ttcExitSummerMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_44_CCW_SUMMER, WARP_CCW_SUMMER_9_MUMBOS_HUT);
}

void warp_ttcExitAutumnMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_9_MUMBOS_HUT);
}

void warp_ttcExitWinterMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_9_MUMBOS_HUT);
}

void warp_ccwEnterSpringWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_65_CCW_SPRING_WHIPCRACK_ROOM, WARP_CCW_WHIPCRACK_SPRING_1_ENTRANCE);
}

void warp_ccwEnterSummerWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_66_CCW_SUMMER_WHIPCRACK_ROOM, WARP_CCW_WHIPCRACK_SUMMER_1_ENTRANCE);
}

void warp_ccwEnterAutumnWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM, WARP_CCW_WHIPCRACK_AUTUMN_1_ENTRANCE);
}

void warp_ccwEnterWinterWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_68_CCW_WINTER_WHIPCRACK_ROOM, WARP_CCW_WHIPCRACK_WINTER_1_ENTRANCE);
}

void warp_ccwExitSpringWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_43_CCW_SPRING, WARP_CCW_SPRING_8_WHIPCRACK);
}

void warp_ccwExitSummerWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_44_CCW_SUMMER, WARP_CCW_SUMMER_8_WHIPCRACK);
}

void warp_ccwExitAutumnWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_8_WHIPCRACK);
}

void warp_ccwExitWinterWhipcrackRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_8_WHIPCRACK);
}

void warp_ccwEnterSpringNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5E_CCW_SPRING_NABNUTS_HOUSE, WARP_CCW_NABNUT_SPRING_1_DOOR);
}

void warp_ccwEnterSummerNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5F_CCW_SUMMER_NABNUTS_HOUSE, WARP_CCW_NABNUT_SUMMER_1_DOOR);
}

void warp_ccwEnterAutumnNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_60_CCW_AUTUMN_NABNUTS_HOUSE, WARP_CCW_NABNUT_AUTUMN_1_DOOR);
}

void warp_ccwExitSpringNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_43_CCW_SPRING, WARP_CCW_SPRING_7_NABNUT_DOOR);
}

void warp_ccwExitSummerNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_44_CCW_SUMMER, WARP_CCW_SUMMER_7_NABNUT_DOOR);
}

void warp_ccwExitAutumnNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_7_NABNUT_DOOR);
}

void warp_ccwExitWinterNabnutDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_7_NABNUT_DOOR_stubbed);
}

void warp_ccwEnterWinterAcornStorage(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_62_CCW_WINTER_HONEYCOMB_ROOM, WARP_CCW_ATTIC_WINTER_1_ENTRANCE);
}

void warp_ccwEnterAutumnFloodedAttic(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY, WARP_CCW_WATER_ROOM_AUTUMN_1_ENTRANCE);
}

void warp_ccwEnterWinterFloodedAttic(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY, WARP_CCW_WATER_ROOM_WINTER_1_ENTRANCE);
}

void warp_ccwExitWinterAcornStorage(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_6_NABNUT_WINDOW_UPPER);
}

void warp_ccwExitAutumnFloodedAttic(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_6_ATTIC);
}

void warp_ccwExitWinterFloodedAttic(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_5_ATTIC);
}

void warp_fpEnterMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_48_FP_MUMBOS_SKULL, WARP_FP_MUMBOS_HUT_1_ENTRANCE);
}

void warp_fpEnterBoggyIgloo(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_41_FP_BOGGYS_IGLOO, WARP_FP_BOGGYS_IGLOO_1_ENTRANCE);
}

void warp_fpEnterXmasTree(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_53_FP_CHRISTMAS_TREE, WARP_FP_CHRISTMAS_TREE_1_ENTRANCE);
}

void warp_fpExitMumbosHut(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_27_FP_FREEZEEZY_PEAK, WARP_FP_7_MUMBOS_HUT);
}

void warp_fpExitBoggyIgloo(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_27_FP_FREEZEEZY_PEAK, WARP_FP_8_IGLOO);
}

void warp_fpExitXmasTree(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_27_FP_FREEZEEZY_PEAK, WARP_FP_9_TREE_BOTTOM);
}

void warp_lairEnterGVLobbyFromPointingStatueRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6E_GL_GV_LOBBY, WARP_GL_GV_LOBBY_1_LOWER_ENTRANCE);
}

void warp_lairEnterMMLobbyFromPuzzlesRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_69_GL_MM_LOBBY, WARP_GL_MM_LOBBY_1_NOTE_DOOR);
}

void warp_lairEnterFPLobbyFromGVLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6F_GL_FP_LOBBY, WARP_GL_FP_LOBBY_1_LOWER_ENTRANCE);
}

void warp_lairEnterGVLobbyFromFPLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6E_GL_GV_LOBBY, WARP_GL_GV_LOBBY_2_HIGHER_EXIT);
}

void warp_lairEnterGVLobbyFromGVLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6E_GL_GV_LOBBY, WARP_GL_GV_LOBBY_3_GV_ENTRANCE);
}

void warp_lairEnterMMLobbyFromMMLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_69_GL_MM_LOBBY, WARP_GL_MM_LOBBY_2_MM_ENTRANCE);
}

// Unknown
void func_8031EF20(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_69_GL_MM_LOBBY, WARP_GL_MM_LOBBY_3_stubbed);
}

void warp_lairEnterPuzzlesRoomFromMMLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6A_GL_TTC_AND_CC_PUZZLE, WARP_GL_TTC_PUZZLE_1_LOWER_ENTRANCE);
}

void warp_lairEnterPointingStatueRoomFromGVLobbyNoteDoor(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_71_GL_STATUE_ROOM, WARP_GL_STATUE_ROOM_1_HIGHER_EXIT);
}

void warp_lairEnterPuzzlesRoomFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6A_GL_TTC_AND_CC_PUZZLE, WARP_GL_TTC_PUZZLE_2_HIGHER_EXIT);
}

void warp_lairEnterCCWPuzzleRoomFromPuzzlesRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6B_GL_180_NOTE_DOOR, WARP_GL_CCW_PUZZLE_1_LOWER_ENTRANCE);
}

void warp_lairEnterCCWPuzzleRoomFromRedCauldronRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6B_GL_180_NOTE_DOOR, WARP_GL_CCW_PUZZLE_2_PIPE_ROOM);
}

void warp_lairEnterRedCauldronRoomFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6C_GL_RED_CAULDRON_ROOM, WARP_GL_PIPE_ROOM_1_ENTRANCE);
}

void warp_lairEnterCCWPuzzleRoomFromTTCLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6B_GL_180_NOTE_DOOR, WARP_GL_CCW_PUZZLE_3_TO_TTC);
}

void warp_lairEnterTTCLobbyFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6D_GL_TTC_LOBBY, WARP_GL_TTC_LOBBY_1_ENTRANCE);
}

void warp_lairEnterCCWPuzzleRoomFromCCLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6B_GL_180_NOTE_DOOR, WARP_GL_CCW_PUZZLE_4_TO_CC);
}

void warp_lairEnterCCLobbyFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_70_GL_CC_LOBBY, WARP_GL_CC_LOBBY_1_ENTRANCE);
}

void warp_lairEnterCCLobbyFromCCLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_70_GL_CC_LOBBY, WARP_GL_CC_LOBBY_2_CC_ENTRANCE);
}

void warp_fpEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_27_FP_FREEZEEZY_PEAK, WARP_FP_1_WORLD_ENTRANCE);
}

// Unknown
void func_8031F0F4(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6F_GL_FP_LOBBY, WARP_GL_FP_LOBBY_3_stubbed);
}

// Unknown
void func_8031F118(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6F_GL_FP_LOBBY, WARP_GL_FP_LOBBY_4_stubbed);
}

void warp_lairEnterCCWPuzzleFromPointingGruntyStatueRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6B_GL_180_NOTE_DOOR, WARP_GL_CCW_PUZZLE_5_NOTE_DOOR);
}

void warp_lairEnterPointingGruntyStatueFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_71_GL_STATUE_ROOM, WARP_GL_STATUE_ROOM_2_LOWER_ENTRANCE);
}

void warp_lairEnterGVPuzzleRoomFromMMMLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_74_GL_GV_PUZZLE, WARP_GL_GV_PUZZLE_1_TO_MMM);
}

void warp_lairEnterMMMLobbyFromGVPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_75_GL_MMM_LOBBY, WARP_GL_MMM_LOBBY_1_ENTRANCE);
}

void warp_lairEnterGVPuzzleRoomFromFPLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_74_GL_GV_PUZZLE, WARP_GL_GV_PUZZLE_2_ENTRANCE);
}

void warp_lairFPLobbyFromGVPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6F_GL_FP_LOBBY, WARP_GL_FP_LOBBY_5_MOUTH_EXIT);
}

void warp_lairEnterPointingGruntyStatueFromBGSLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_71_GL_STATUE_ROOM, WARP_GL_STATUE_ROOM_3_TO_BGS);
}

void warp_lairEnterBGSLobbyFromPointingGruntyStatueRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_72_GL_BGS_LOBBY, WARP_GL_BGS_LOBBY_1_ENTRANCE);
}

void warp_lairEnterCryptFromMMMLobby(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC8C(arg0, MAP_7A_GL_CRYPT, WARP_GL_COFFIN_ROOM_1_ENTRANCE);
}

void warp_lairEnterMMMLobbyFromCrypt(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC8C(arg0, MAP_75_GL_MMM_LOBBY, WARP_GL_MMM_LOBBY_3_COFFIN);
}

void warp_fpExitWozzasCave(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_27_FP_FREEZEEZY_PEAK, WARP_FP_6_WOZZA_CAVE);
}

void warp_fpEnterWozzasCave(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7F_FP_WOZZAS_CAVE, WARP_FP_WOZZAS_CAVE_1_ENTRANCE);
}

void warp_lairEnterBGSLobbyFromBGSLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_72_GL_BGS_LOBBY, WARP_GL_BGS_LOBBY_2_BGS_ENTRANCE);
}

void warp_lairEnter640NoteDoorRoomFromFPLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_76_GL_640_NOTE_DOOR, WARP_GL_WATER_SWITCH_ROOM_1_LOWER_ENTRANCE);
}

void warp_lairEnter640NoteDoorRoomFromCCWLobbyTokenEntrance(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_76_GL_640_NOTE_DOOR, WARP_GL_WATER_SWITCH_ROOM_2_CCW_LOBBY_MUMBO_TOKEN);
}

void warp_lairEnter640NoteDoorRoomFromCCWLobbyDoorEntrance(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_76_GL_640_NOTE_DOOR, WARP_GL_WATER_SWITCH_ROOM_3_CCW_LOBBY);
}

void warp_lairEnter640NoteDoorRoomFromRBBLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_76_GL_640_NOTE_DOOR, WARP_GL_WATER_SWITCH_ROOM_4_UNDERWATER_EXIT);
}

void warp_lairRBBLobbyFrom640NoteDoorRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_77_GL_RBB_LOBBY, WARP_GL_RBB_LOBBY_1_LOWER_ENTRANCE);
}

void warp_lairCCWLobbyFrom640NoteDoorRoomDoorEntrance(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_79_GL_CCW_LOBBY, WARP_GL_CCW_LOBBY_1_WHIPCRACK_ENTRANCE);
}

void warp_lairCCWLobbyFrom640NoteDoorRoomTokenEntrance(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_79_GL_CCW_LOBBY, WARP_GL_CCW_LOBBY_2_HIGHER_ENTRANCE);
}

void warp_ccwEnterSummerZubbaHive(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5A_CCW_SUMMER_ZUBBA_HIVE, WARP_CCW_BEEHIVE_SUMMER_2_TOP);
}

void warp_ccwEnterAutumnZubbaHive(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5C_CCW_AUTUMN_ZUBBA_HIVE, WARP_CCW_BEEHIVE_AUTUMN_2_TOP);
}

void warp_ccwExitSpringZubbaHive(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_43_CCW_SPRING, WARP_CCW_SPRING_6_ZUBBA_HIVE_FRONT);
}

void warp_ccwExitSummerZubbaHive(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_44_CCW_SUMMER, WARP_CCW_SUMMER_6_ZUBBA_HIVE_TOP);
}

void warp_ccwExitAutumnZubbaHive(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_5_ZUBBA_HIVE_TOP);
}

void warp_ccwEnterSpringZubbaHive(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_6_BEE)
        _func_8031CC8C(arg0, MAP_5B_CCW_SPRING_ZUBBA_HIVE, WARP_CCW_BEEHIVE_SPRING_1_ENTRANCE);
}

void warp_lairEnterFPLobbyFrom640NoteDoorRoom(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
    _func_8031CC8C(arg0, MAP_6F_GL_FP_LOBBY, WARP_GL_FP_LOBBY_2_HIGHEST_EXIT);
}

void warp_lairEnterRBBLobbyFromRBBLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_77_GL_RBB_LOBBY, WARP_GL_RBB_LOBBY_2_RBB_ENTRANCE);
}

void warp_lairEnterRBBLobbyFromRBBPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_77_GL_RBB_LOBBY, WARP_GL_RBB_LOBBY_3_UNDERWATER_EXIT);
}

void warp_lairEnterRBBLobbyFromMMMPuzzleRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_77_GL_RBB_LOBBY, WARP_GL_RBB_LOBBY_4_HIGHER_EXIT);
}

void warp_lairEnterMMMPuzzleFromRBBLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_78_GL_RBB_AND_MMM_PUZZLE, WARP_GL_MMM_PUZZLE_1_UNDERWATER_ENTRANCE);
}

void warp_lairEnterRBBPuzzleFromRBBLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_78_GL_RBB_AND_MMM_PUZZLE, WARP_GL_MMM_PUZZLE_2_HIGHER_ENTRANCE);
}

void warp_lairEnterCCWLobbyFromFurnaceFunPath(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_79_GL_CCW_LOBBY, WARP_GL_CCW_LOBBY_3_FURNACE_EXIT);
}

void warp_lairEnterFurnaceFunPathFromCCWLobby(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_80_GL_FF_ENTRANCE, WARP_GL_FURNACE_FUN_PATH_1_ENTRANCE);
}

void warp_smEnterBanjosHouse(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_8C_SM_BANJOS_HOUSE, WARP_SM_BANJOS_HOUSE_1_ENTRANCE);
}

void warp_smExitBanjosHouse(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1_SM_SPIRAL_MOUNTAIN, WARP_SM_12_FROM_HOUSE);
}

void warp_lairEnterMMLobbyFromSMLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_69_GL_MM_LOBBY, WARP_GL_MM_LOBBY_12_ENTRANCE);
}

void warp_smExitLair(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_1_SM_SPIRAL_MOUNTAIN, WARP_SM_13_LAIR_ENTRANCE);
}

void warp_rbbExitAnchorRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_31_RBB_RUSTY_BUCKET_BAY, WARP_RBB_13_ANCHOR_ROOM);
}

void warp_rbbEnterAnchorRoom(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_8B_RBB_ANCHOR_ROOM, WARP_RBB_ANCHOR_4_SWITCH);
}

void warp_mmmEnterWellBottom(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC8C(arg0, MAP_25_MMM_WELL, WARP_MMM_WELL_4_BOTTOM_ENTRANCE);
}

void warp_mmmExitWellBottom(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC8C(arg0, MAP_1B_MMM_MAD_MONSTER_MANSION, WARP_MMM_13_WELL_BOTTOM);
}

void warp_mmmEnterBathroomFromLoggo(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC8C(arg0, MAP_2C_MMM_BATHROOM, WARP_MMM_BATHROOM_4_LOGGO);
}

void warp_mmmEnterLoggo(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN)
        _func_8031CC60(MAP_8D_MMM_INSIDE_LOGGO, WARP_MMM_SEPTIC_TANK_4_ENTRANCE);
}

// Unused
void func_8031F80C(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_75_GL_MMM_LOBBY, WARP_GL_MMM_LOBBY_2_MMM_ENTRANCE);
}

void warp_lairTTCLobbyFromTTCLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6D_GL_TTC_LOBBY, WARP_GL_TTC_LOBBY_4_TTC_ENTRANCE);
}

void warp_lairCCWLobbyFromCCWLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_79_GL_CCW_LOBBY, WARP_GL_CCW_LOBBY_6_CCW_ENTRANCE);
}

void warp_ccwEnterLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_40_CCW_HUB, WARP_CCW_7_WORLD_ENTRANCE);
}

void warp_lairFPLobbyFromFPLevel(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_6F_GL_FP_LOBBY, WARP_GL_FP_LOBBY_6_FP_ENTRANCE);
}

void warp_ccwEnterSpringNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5E_CCW_SPRING_NABNUTS_HOUSE, WARP_CCW_NABNUT_SPRING_2_WINDOW);
}

void warp_ccwEnterSummerNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_5F_CCW_SUMMER_NABNUTS_HOUSE, WARP_CCW_NABNUT_SUMMER_2_WINDOW);
}

void warp_ccwEnterAutumnNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_60_CCW_AUTUMN_NABNUTS_HOUSE, WARP_CCW_NABNUT_AUTUMN_2_WINDOW);
}

void warp_ccwEnterWinterNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_61_CCW_WINTER_NABNUTS_HOUSE, WARP_CCW_NABNUT_WINTER_2_WINDOW);
}

void warp_ccwExitSpringNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_43_CCW_SPRING, WARP_CCW_SPRING_4_NABNUT_WINDOW);
}

void warp_ccwExitSummerNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_44_CCW_SUMMER, WARP_CCW_SUMMER_4_NABNUT_WINDOW);
}

void warp_ccwExitAutumnNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_45_CCW_AUTUMN, WARP_CCW_AUTUMN_4_NABNUT_WINDOW);
}

void warp_ccwExitWinterNabnutWindow(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_46_CCW_WINTER, WARP_CCW_WINTER_4_NABNUT_WINDOW);
}

void func_8031F9E0(void){}

void func_8031F9E8(){
    D_80383190 = 0;
}

void func_8031F9F4(s32 arg0){
    D_80383190 = arg0;
}

void warp_ttcExitSharkfoodIsland(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_7_TTC_TREASURE_TROVE_COVE, WARP_TTC_80_SHARKFOOD_ISLAND);
}

void warp_gvEnterSNSChamber(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_92_GV_SNS_CHAMBER, WARP_GV_EGG_ROOM_5_ENTRANCE);
}

void warp_gvExitSNSChamber(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_12_GV_GOBIS_VALLEY, WARP_GV_A_EGG_ROOM);
}

void warp_lairEnterDingpotRoomFromFurnaceFun(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_93_GL_DINGPOT, WARP_GL_TOWER_5_ENTRANCE);
}

// warp_lairEnterFurnaceFunFrom?
void func_8031FA90(s32 arg0, s32 arg1) {
    _func_8031CC8C(arg0, MAP_8E_GL_FURNACE_FUN, WARP_GL_FURNACE_FUN_5_TO_TOWER);
}

void func_8031FAB4(s32 arg0, s32 arg1) {
    if ((fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY) != 0) && (jiggyscore_total() == 100)) {
        // Beach Cutscene
        _func_8031CC8C(arg0, MAP_95_CS_END_ALL_100, 1);
    } else {
        // Final Battle
        _func_8031CC8C(arg0, MAP_90_GL_BATTLEMENTS, 1);
    }
}

void warp_lairEnterLairFromSMLevel(s32 arg0, s32 arg1) {
    if (fileProgressFlag_get(FILEPROG_BD_ENTER_LAIR_CUTSCENE) != 0) {
        // MM Lobby
        _func_8031CC8C(arg0, MAP_69_GL_MM_LOBBY, WARP_GL_MM_LOBBY_12_ENTRANCE);
    } else {
        fileProgressFlag_set(FILEPROG_BD_ENTER_LAIR_CUTSCENE, 1);
        // Enter Lair Cutscene
        _func_8031CC8C(arg0, MAP_82_CS_ENTERING_GL_MACHINE_ROOM, 4);
    }
}

void func_8031FB6C(s32 arg0, s32 arg1) {
    func_8030E6D4(SFX_7C_CHEBOOF);
    _func_8031CC8C(arg0, MAP_71_GL_STATUE_ROOM, WARP_GL_STATUE_ROOM_4_CEILING_EXIT);
}

void clearScoreStates(void) {
    bsStoredState_clear();
    fileprogressflag_func_8031FFAC();
    item_setItemsStartCounts();
    jiggyscore_clearAll();
    honeycombscore_clear();
    mumboscore_clear();
    volatileFlag_clear();
    func_802D6344();
}

// Mostly does nothing, but it resets the selected game in the file select screen (even if it does get re-written right after)
void debugScoreStates(void) {
    mumboscore_debug();
    honeycombscore_debug();
    jiggyscore_debug();
    func_803465DC();
    bsStoredState_debug();
    gameSelect_resetGameNumber();
}
