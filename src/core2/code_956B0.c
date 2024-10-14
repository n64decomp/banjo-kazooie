#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F3D8(f32 *, f32,  void(*)(ActorMarker *), ActorMarker *);
extern void func_8028F760(s32, f32, f32);
extern void func_8031CE70(f32 *arg0, enum map_e arg1, s32 arg2);
extern s32  fileProgressFlag_get(s32);
extern s32  fileProgressFlag_getN(s32 offset, s32 numBits);
extern void func_8031FFAC(void);
extern void fileProgressFlag_set(enum file_progress_e index, s32 set);
extern void ml_vec3h_to_vec3f(f32 *, s32);
extern NodeProp *func_80304ED0(void*, f32 *);
extern void func_8031CD44(enum map_e, s32, f32, f32, s32);
extern void func_80256E24(f32 *, f32, f32, f32, f32, f32);
extern void mapSpecificFlags_set(s32, s32);

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
    if ((func_8024E698(0) == 1) && (gameFile_anyNonEmpty() != 0)) {
        return TRUE;
    }
    return FALSE;
}

// func_8031C688
bool cutscene_skipEnterLairCutsceneCheck(void) {
    if ((func_8024E698(0) == 1) 
        && ((D_8037DCCE[0] != 0) 
            || (D_8037DCCE[1] != 0) 
            || (D_8037DCCE[2] != 0))) {
        return TRUE;
    }
    return FALSE;
}


bool cutscene_skipGameOverCutsceneCheck(void) {
    s32 sp24;

    sp24 = func_8024E698(0);
    if (mapSpecificFlags_get(0) != 0) {
        fileProgressFlag_set(FILEPROG_E1_UNKNOWN, 1);
    }
    if ((sp24 == 1) && fileProgressFlag_get(FILEPROG_E1_UNKNOWN) && !gctransition_8030BDC0()) {
        if (!mapSpecificFlags_get(0xC)) {
            mapSpecificFlags_set(0xC, TRUE);
            func_802DC528(0, 0);
            timedFunc_set_2(11.0f, (GenFunction_2)func_802DC560, 0, 0);
            timedFunc_set_3(12.0f, (GenFunction_3)func_802E4078, MAP_1F_CS_START_RAREWARE, 0, 1);
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
    if(map_get() != cs_map)
        return;

    if((condFunc && condFunc()) || mapSpecificFlags_get(arg1)){
        mapSpecificFlags_set(arg1, 0);
        func_802E4078(return_map, (return_exit == -1)? 0: return_exit, 1);
    }
}

//check cutscene interrupts
s32 cutscenetrigger_update(void){
    cutscenetrigger_check(MAP_86_CS_SPIRAL_MOUNTAIN_4,        0, MAP_89_CS_INTRO_BANJOS_HOUSE_2,  -1, NULL);
    cutscenetrigger_check(MAP_7D_CS_SPIRAL_MOUNTAIN_1,        0, MAP_7C_CS_INTRO_BANJOS_HOUSE_1,  -1, NULL);
    cutscenetrigger_check(MAP_7C_CS_INTRO_BANJOS_HOUSE_1,     0, MAP_86_CS_SPIRAL_MOUNTAIN_4,     -1, NULL);
    cutscenetrigger_check(MAP_89_CS_INTRO_BANJOS_HOUSE_2,     0, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, NULL);
    cutscenetrigger_check(MAP_85_CS_SPIRAL_MOUNTAIN_3,        0, MAP_7B_CS_INTRO_GL_DINGPOT_1,    -1, NULL);
    cutscenetrigger_check(MAP_7B_CS_INTRO_GL_DINGPOT_1,       1, MAP_81_CS_INTRO_GL_DINGPOT_2,    -1, NULL);
    cutscenetrigger_check(MAP_81_CS_INTRO_GL_DINGPOT_2,       0, MAP_7D_CS_SPIRAL_MOUNTAIN_1,     -1, NULL);
    cutscenetrigger_check(MAP_82_CS_ENTERING_GL_MACHINE_ROOM, 0, MAP_69_GL_MM_LOBBY,            0x12, cutscene_skipEnterLairCutsceneCheck);
    cutscenetrigger_check(MAP_83_CS_GAME_OVER_MACHINE_ROOM,   0, MAP_1F_CS_START_RAREWARE,        -1, cutscene_skipGameOverCutsceneCheck);
    cutscenetrigger_check(MAP_87_CS_SPIRAL_MOUNTAIN_5,        0, MAP_88_CS_SPIRAL_MOUNTAIN_6,     -1, NULL);
    cutscenetrigger_check(MAP_94_CS_INTRO_SPIRAL_7,           0, MAP_8E_GL_FURNACE_FUN,            4, NULL);
    cutscenetrigger_check(MAP_88_CS_SPIRAL_MOUNTAIN_6,        1, MAP_96_CS_END_BEACH_1,           -1, NULL);
    cutscenetrigger_check(MAP_98_CS_END_SPIRAL_MOUNTAIN_1,    0, MAP_1F_CS_START_RAREWARE,        -1, NULL);
    cutscenetrigger_check(MAP_99_CS_END_SPIRAL_MOUNTAIN_2,    0, MAP_1F_CS_START_RAREWARE,        -1, NULL);
    cutscenetrigger_check(MAP_20_CS_END_NOT_100,              0, MAP_98_CS_END_SPIRAL_MOUNTAIN_1, -1, NULL);
    cutscenetrigger_check(MAP_95_CS_END_ALL_100,              0, MAP_99_CS_END_SPIRAL_MOUNTAIN_2, -1, NULL);
    cutscenetrigger_check(MAP_97_CS_END_BEACH_2,              0, MAP_99_CS_END_SPIRAL_MOUNTAIN_2, -1, cutscene_skipBeachCutsceneCheck);
    cutscenetrigger_check(MAP_85_CS_SPIRAL_MOUNTAIN_3,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_7B_CS_INTRO_GL_DINGPOT_1,     0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_81_CS_INTRO_GL_DINGPOT_2,     0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_7D_CS_SPIRAL_MOUNTAIN_1,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_7C_CS_INTRO_BANJOS_HOUSE_1,   0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_86_CS_SPIRAL_MOUNTAIN_4,      0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    cutscenetrigger_check(MAP_89_CS_INTRO_BANJOS_HOUSE_2,   0xC, MAP_1_SM_SPIRAL_MOUNTAIN,      0x12, cutscene_skipIntroCutsceneCheck);
    if(map_get() == MAP_95_CS_END_ALL_100 && mapSpecificFlags_get(1)){
        func_8034B9E4();
        mapSpecificFlags_set(1, 0);
    }
    return 0;
}

void func_8031CB50(enum map_e map_id, s32 exit_id, s32 arg2) {
    s32 sp1C;

    if ((D_80383190 == 0) && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS) && (getGameMode() != GAME_MODE_7_ATTRACT_DEMO)) {
        sp1C = func_803226E8(map_get());
        if ((func_803226E8(map_id) != sp1C) && (func_80322914() == 0)) {
            func_8025A388(0, 0x4E2);
            func_8025AB00();
            func_8024BD08(0);
        }
        if (func_802E4A08()) {
            func_802E40D0(map_id, exit_id);
            func_802E40E8(1);
            func_802E40C4(0xB);
        } else {
            func_802E4078(map_id, exit_id, 1);
        }
        func_80335110(arg2);
    }
}

void func_8031CC40(enum map_e map_id, s32 arg1) {
    func_8031CB50(map_id, arg1, 0);
}

void func_8031CC60(s32 arg0) {
    func_8031CB50(arg0 >> 8, arg0 & 0xFF, 1);
}

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
    func_8031CC8C(arg0, (arg1 << 8) + arg2);
}

void func_8031CD44(enum map_e arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    player_getPosition((f32 *) &sp3C);
    func_80256E24(sp24, 0.0f, arg3, 0.0f, 0.0f, ml_map_f((f32) arg4, 0.0f, 200.0f, 10.0f, 800.0f));
    sp24[0] = sp3C[0] + sp24[0];
    sp24[1] = sp3C[1] + sp24[1];
    sp24[2] = sp3C[2] + sp24[2];
    sp30[0] = sp24[0];
    sp30[1] = arg2;
    sp30[2] = sp24[2];
    ncDynamicCamera_setUpdateEnabled(0);
    func_8031CB50(arg0, arg1, 1);
    func_8028F3D8(sp30, 1.0f, NULL, NULL);
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
            if (phi_s0->unk8 == 0x186) {
                phi_f2 = 1000.0f;
            }
            if (ml_distance_vec3f(arg0, sp38) < phi_f2) {
                if (phi_s0->unk8 == 0x184) {
                    ncDynamicCamera_setUpdateEnabled(0);
                    func_8031CB50(arg1, arg2, 1);
                    func_8028F3D8(sp38, 1.0f, NULL, NULL);
                } else if (phi_s0->unk8 == 0x185) {
                    func_8031CD44(arg1, arg2, sp38[1], (f32) phi_s0->unkC_31, phi_s0->unkC_22);
                } else {
                    func_8031CD44(arg1, arg2, playerPos[1], (f32) phi_s0->unkC_31, phi_s0->unkC_22);
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
    if (func_8024E698(0) == 1) {
        func_802E412C(1, 2);
        func_8025A2FC(0, 0x320);
        func_8025AB00();
        func_8031D09C(arg0, arg1);
    }
}

void warp_mmEnterMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0E01);
}

void warp_mmExitMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0201);
}

void warp_mmEnterTickersTowerLower(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0C02);
}

void warp_mmExitTickersTowerLower(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0202);
}

void warp_mmEnterTickersTowerUpper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0C01);
}

void warp_mmExitTickersTowerUpper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0203);
}

void warp_csNintendoLogo(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1E00);
}

void warp_gvEnterWaterPyramidLower(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1506);
}

void warp_gvEnterRubeePyramid(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
    func_80244C78(1);
    func_8031CC8C(arg0, 0x1607);
}

void warp_gvEnterMatchingPyramid(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
    func_8031CC8C(arg0, 0x1301);
}

void warp_gvEnterWaterPyramidUpper(s32 arg0, s32 arg1) {
    func_80244C78(0);
    volatileFlag_set(VOLATILE_FLAG_AC_GV_TRAPDOOR_MISSED, 1);
    func_8031CC8C(arg0, 0x1502);
}

void warp_gvEnterMazePyramid(s32 arg0, s32 arg1) {
    if (fileProgressFlag_getN(FILEPROG_F8_KING_SANDYBUTT_PYRAMID_STATE, 2) == 3) {
        func_8031CC8C(arg0, 0x1401);
    }
}

void warp_gvExitMatchingPyramid(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1203);
}

void warp_gvExitMazePyramid(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1204);
}

void warp_gvExitWaterPyramidLower(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1205);
}

void warp_gvExitRubeePyramid(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1206);
}

void warp_bgsEnterTanktup(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1101);
}

void warp_bgsExitTanktup(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D03);
}

void warp_bgsExitVileRightNostril(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D04);
}

void warp_bgsExitVileLeftNostril(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D05);
}

void warp_ttcEnterSandcastle(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0A01);
}

void warp_ttcStairAlcoveDown(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x070F);
}

void warp_ttcStairAlcoveUp(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x070E);
}

void warp_ttcEnterBlubbersShipUpper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0505);
}

void warp_ttcEnterBlubbersShipSide(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0506);
}

void warp_ttcExitLighthouseTop(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0708);
}

void warp_ttcExitSandcastle(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0703);
}

// Unused
void func_8031D550(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0704);
}

// Unused
void func_8031D574(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0705);
}

void warp_ttcExitBlubbersShipUpper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0706);
}

void warp_ttcExitBlubbersShipSide(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0707);
}

// Unused
void warp_ttcExitLighthouseTopUnused(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0708);
}

// Unused
void func_8031D604(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0709);
}

void func_8031D628(s32 arg0, s32 arg1) {
    Actor *actor;

    actor = actorArray_findActorFromActorId(0x13E);
    if (actor) {
        marker_despawn(actor->marker);
    }
    func_8031CB50(MAP_7_TTC_TREASURE_TROVE_COVE, 0xC, 0);
}

void warp_mmmEnterDiningRoomDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2601);
}

void warp_mmmEnterDiningRoomChimney(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2602);
}

void warp_mmmEnterWellTop(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2501);
}

void warp_mmmEnterTumblarShed(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2401);
}

void warp_mmmEnterCellar(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1D01);
}

void warp_mmmEnterRedFeatherRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2A01);
}

void warp_mmmEnterBlueEggRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2801);
}

void warp_mmmEnterNoteRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2901);
}

void warp_mmmEnterBrokenFloorboardRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2E01);
}

void warp_mmmEnterBedroom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2D01);
}

void warp_mmmEnterBathroomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2C01);
}

void warp_mmmExitDiningRoomDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B01);
}

// Unsure
void func_8031D820(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B02);
}

void warp_mmmExitWellTop(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B03);
}

void warp_mmmExitTumblarShed(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B04);
}

void warp_mmmExitChurchFrontDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B05);
}

void warp_mmmExitChurchSecretRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B06);
}

// Unsure
void func_8031D8D4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B07);
}

void warp_mmmExitRainBarrelBottom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B08);
}

void warp_mmmExitCellar(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B09);
}

void warp_mmmExitRedFeatherRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0A);
}

void warp_mmmExitBlueEggRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0B);
}

void warp_mmmExitBathroomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0C);
}

void warp_mmmExitBrokenFloorboardRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0D);
}

void warp_mmmExitBedroom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0E);
}

void warp_mmmExitNoteRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B0F);
}

void warp_mmmChurchTowerUp(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B10);
}

void warp_mmmChurchTowerDown(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B11);
}

void warp_mmmExitMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B12);
}

void warp_mmmEnterChurchSecretRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2B01);
}

void func_8031DAA8(enum map_e arg0, s32 arg1) {
    func_8028F918(0);
    func_8031CB50(arg0, arg1, 0);
}

void func_8031DAE0(s32 arg0, s32 arg1) {
    if (mapSpecificFlags_get(2) == 0) {
        volatileFlag_set(VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED, 1);
        func_80244C78(0);
        mapSpecificFlags_set(2, 1);
        func_8025A6EC(COMUSIC_3B_MINIGAME_VICTORY, 0x6D60);
        func_8028F918(1);
        timedFunc_set_2(1.8f, &func_8031DAA8, 0x1C, 1);
        func_802D6924();
    }
}

// Unused
void warp_mmmEnterMumbosHutUnused(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3001);
}

void warp_mmmEnterMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3001);
}

void warp_mmmEnterRainBarrel(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, arg1 + 0x2F00);
    }
}

void func_8031DBE8(void) {
    func_8031CB50(MAP_2F_MMM_WATERDRAIN_BARREL, 1, 1);
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
    if (player_getTransformation() == TRANSFORM_5_CROC) {
        func_8031CC8C(arg0, arg1 + 0x1000);
    }
}

void warp_bgsEnterMrVileRightNostril(s32 arg0, s32 arg1) {
    warp_bgsEnterMrVileNostril(arg0, 3);
}

void warp_bgsEnterMrVileLeftNostril(s32 arg0, s32 arg1) {
    warp_bgsEnterMrVileNostril(arg0, 4);
}

void warp_bgsEnterTanktupConditional(s32 arg0, s32 arg1) {
    if (func_8038F570() != 0) {
        func_8031CC8C(arg0, 0x1101);
    }
}

void warp_ttcEnterNippersShell(s32 arg0, s32 arg1) {
    if (chNipper_isInState7() != 0) {
        func_8031CC8C(arg0, 0x601);
    }
}

void warp_ccExitWonderwingRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2203);
}

void warp_ccEnterClankerBelly(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2201);
}

void warp_ccEnterClankerMouth(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2202);
}

void warp_ccEnterWonderwingRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2301);
}

void warp_mmEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0205);
}

void warp_gvEnterJinxy(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1A02);
}

void warp_gvExitJinxy(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1202);
}

void warp_rbbEnterCaptainsRoomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3F01);
}

void warp_rbbEnterCabinRoomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3901);
}

void warp_rbbEnterEngineRoomPipe(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3404);
}

void warp_rbbEnterEngineRoomDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3401);
}

void warp_rbbEnterKitchenPipe(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3C01);
}

void warp_rbbEnterNavigationRoomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3D01);
}

void warp_rbbEnterBoomBoxPipe(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3B01);
}

void warp_rbbEnterChumpWarehouseWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3502);
}

void warp_rbbEnterBoatRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3601);
}

void warp_rbbEnterChompaContainer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3701);
}

void warp_rbbEnterSeamanGrublinContainer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3E01);
}

void warp_rbbEnterBoomBoxContainer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3801);
}

void warp_rbbExitCaptainsRoomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3101);
}

void warp_rbbExitCabinRoomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3102);
}

void warp_rbbExitEngineRoomPipe(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3103);
}

void warp_rbbExitKitchenPipe(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3104);
}

void warp_rbbExitNavigationRoomWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3105);
}

void warp_rbbExitBoomBoxPipe(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3106);
}

void warp_rbbExitEngineRoomDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3107);
}

void warp_rbbExitBoatRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3108);
}

void warp_rbbExitChompaContainer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3109);
}

void warp_rbbExitSeamanGrublinContainer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x310A);
}

void warp_rbbExitBoomBoxContainer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x310B);
}

void warp_rbbExitBossBoomBoxRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x310C);
}

void warp_rbbEnterBossBoomBoxRoom(s32 arg0, s32 arg1) {
    func_8031CB50(MAP_3A_RBB_BOSS_BOOM_BOX, 1, 0);
}

void func_8031E204(NodeProp *node, s32 arg1, s32 arg2){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    nodeprop_getPosition(func_80304D04(0x154, &node->x), sp34);
    nodeprop_getPosition(func_80304D04(0x155, &node->x), sp28);
    player_getPosition(sp1C);
    if(sp28[1] < sp1C[1]){
        sp1C[1] = sp28[1];
    }
    func_8028F760(2, (sp1C[1] - sp34[1])/(sp28[1] - sp34[1]), 0.0f);
    func_8031CC8C(node, (arg1 <<8) + arg2);
}

void warp_rbbEnterChumpWarehouseDoor(NodeProp *node, ActorMarker *marker){
    func_8031E204(node, MAP_35_RBB_WAREHOUSE, 0x1);
}

void warp_rbbExitChumpWarehouseDoor(NodeProp *node, ActorMarker *marker){
    func_8031E204(node, MAP_31_RBB_RUSTY_BUCKET_BAY, 0xd);
}

// Unknown
void func_8031E308(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3206);
}

// Unknown
void func_8031E32C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5200);
}

// Unknown
void func_8031E350(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5100);
}

// Unknown
void func_8031E374(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5101);
}

// Unknown
void func_8031E398(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4200);
}

// Unknown
void func_8031E3BC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3201);
}

// Unknown
void func_8031E3E0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3202);
}

// Unknown
void func_8031E404(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3203);
}

// Unknown
void func_8031E428(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3204);
}

// Unknown
void func_8031E44C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3205);
}

// Unknown
void func_8031E470(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3207);
}

// Unknown
void func_8031E494(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3208);
}

// Unknown
void func_8031E4B8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3209);
}

// Unknown
void func_8031E4DC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320A);
}

// Unknown
void func_8031E500(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320B);
}

// Unknown
void func_8031E524(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320C);
}

// Unknown
void func_8031E548(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320D);
}

// Unknown
void func_8031E56C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320E);
}

// Unknown
void func_8031E590(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x320F);
}

// Unknown
void func_8031E5B4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3210);
}

// Unknown
void func_8031E5D8(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3211);
}

// Unknown
void func_8031E5FC(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3212);
}

// Unknown
void func_8031E620(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3213);
}

// Unknown
void func_8031E644(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3214);
}

// Unknown
void func_8031E668(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3215);
}

// Unknown
void func_8031E68C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3216);
}

// Unknown
void func_8031E6B0(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3217);
}

void warp_ccwExitWinterToHub(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4001);
}

void warp_ccwExitSpringToHub(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4002);
}

void warp_ccwExitSummerToHub(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4003);
}

void warp_ccwExitAutumnToHub(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4004);
}

void warp_ccwEnterWinter(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4601);
}

void warp_ccwEnterSpring(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4301);
}

void warp_ccwEnterSummer(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4401);
}

void warp_ccwEnterAutumn(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4501);
}

void warp_gvExitSandybuttMazeBack(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1207);
}

void warp_bgsExitMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D06);
}

void warp_bgsEnterMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4701);
}

void warp_ttcEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0704);
}

void warp_ccEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0B05);
}

void warp_bgsEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x0D02);
}

void warp_gvEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1208);
}

void warp_mmmEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x1B14);
}

void warp_rbbEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3110);
}

void warp_ttcExitNipper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x070A);
}

void warp_ttcEnterSpringMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4A01);
}

void warp_ttcEnterSummerMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4B01);
}

void warp_ttcEnterAutumnMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4C01);
}

void warp_ttcEnterWinterMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4D01);
}

void warp_ttcExitSpringMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4309);
}

void warp_ttcExitSummerMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4409);
}

void warp_ttcExitAutumnMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4509);
}

void warp_ttcExitWinterMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4609);
}

void warp_ccwEnterSpringWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6501);
}

void warp_ccwEnterSummerWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6601);
}

void warp_ccwEnterAutumnWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6701);
}

void warp_ccwEnterWinterWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6801);
}

void warp_ccwExitSpringWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4308);
}

void warp_ccwExitSummerWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4408);
}

void warp_ccwExitAutumnWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4508);
}

void warp_ccwExitWinterWhipcrackRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4608);
}

void warp_ccwEnterSpringNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5E01);
}

void warp_ccwEnterSummerNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5F01);
}

void warp_ccwEnterAutumnNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6001);
}

void warp_ccwExitSpringNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4307);
}

void warp_ccwExitSummerNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4407);
}

void warp_ccwExitAutumnNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4507);
}

void warp_ccwExitWinterNabnutDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4607);
}

void warp_ccwEnterWinterAcornStorage(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6201);
}

void warp_ccwEnterAutumnFloodedAttic(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6301);
}

void warp_ccwEnterWinterFloodedAttic(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6401);
}

void warp_ccwExitWinterAcornStorage(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4606);
}

void warp_ccwExitAutumnFloodedAttic(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4506);
}

void warp_ccwExitWinterFloodedAttic(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4605);
}

void warp_fpEnterMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4801);
}

void warp_fpEnterBoggyIgloo(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4101);
}

void warp_fpEnterXmasTree(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5301);
}

void warp_fpExitMumbosHut(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2707);
}

void warp_fpExitBoggyIgloo(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2708);
}

void warp_fpExitXmasTree(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2709);
}

void warp_lairEnterGVLobbyFromPointingStatueRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6E01);
}

void warp_lairEnterMMLobbyFromPuzzlesRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6901);
}

void warp_lairEnterFPLobbyFromGVLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F01);
}

void warp_lairEnterGVLobbyFromFPLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6E02);
}

void warp_lairEnterGVLobbyFromGVLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6E03);
}

void warp_lairEnterMMLobbyFromMMLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6902);
}

// Unknown
void func_8031EF20(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6903);
}

void warp_lairEnterPuzzlesRoomFromMMLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6A01);
}

void warp_lairEnterPointingStatueRoomFromGVLobbyNoteDoor(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7101);
}

void warp_lairEnterPuzzlesRoomFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6A02);
}

void warp_lairEnterCCWPuzzleRoomFromPuzzlesRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B01);
}

void warp_lairEnterCCWPuzzleRoomFromRedCauldronRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B02);
}

void warp_lairEnterRedCauldronRoomFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6C01);
}

void warp_lairEnterCCWPuzzleRoomFromTTCLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B03);
}

void warp_lairEnterTTCLobbyFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6D01);
}

void warp_lairEnterCCWPuzzleRoomFromCCLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B04);
}

void warp_lairEnterCCLobbyFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7001);
}

void warp_lairEnterCCLobbyFromCCLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7002);
}

void warp_fpEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2701);
}

// Unknown
void func_8031F0F4(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F03);
}

// Unknown
void func_8031F118(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F04);
}

void warp_lairEnterCCWPuzzleFromPointingGruntyStatueRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6B05);
}

void warp_lairEnterPointingGruntyStatueFromCCWPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7102);
}

void warp_lairEnterGVPuzzleRoomFromMMMLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7401);
}

void warp_lairEnterMMMLobbyFromGVPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7501);
}

void warp_lairEnterGVPuzzleRoomFromFPLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7402);
}

void warp_lairFPLobbyFromGVPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F05);
}

void warp_lairEnterPointingGruntyStatueFromBGSLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7103);
}

void warp_lairEnterBGSLobbyFromPointingGruntyStatueRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7201);
}

void warp_lairEnterCryptFromMMMLobby(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x7A01);
    }
}

void warp_lairEnterMMMLobbyFromCrypt(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x7503);
    }
}

void warp_fpExitWozzasCave(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x2706);
}

void warp_fpEnterWozzasCave(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7F01);
}

void warp_lairEnterBGSLobbyFromBGSLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7202);
}

void warp_lairEnter640NoteDoorRoomFromFPLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7601);
}

void warp_lairEnter640NoteDoorRoomFromCCWLobbyTokenEntrance(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7602);
}

void warp_lairEnter640NoteDoorRoomFromCCWLobbyDoorEntrance(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7603);
}

void warp_lairEnter640NoteDoorRoomFromRBBLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7604);
}

void warp_lairRBBLobbyFrom640NoteDoorRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7701);
}

void warp_lairCCWLobbyFrom640NoteDoorRoomDoorEntrance(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7901);
}

void warp_lairCCWLobbyFrom640NoteDoorRoomTokenEntrance(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7902);
}

void warp_ccwEnterSummerZubbaHive(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5A02);
}

void warp_ccwEnterAutumnZubbaHive(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5C02);
}

void warp_ccwExitSpringZubbaHive(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4306);
}

void warp_ccwExitSummerZubbaHive(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4406);
}

void warp_ccwExitAutumnZubbaHive(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4505);
}

void warp_ccwEnterSpringZubbaHive(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_6_BEE) {
        func_8031CC8C(arg0, 0x5B01);
    }
}

void warp_lairEnterFPLobbyFrom640NoteDoorRoom(s32 arg0, s32 arg1) {
    item_set(ITEM_6_HOURGLASS, 0);
    func_8031CC8C(arg0, 0x6F02);
}

void warp_lairEnterRBBLobbyFromRBBLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7702);
}

void warp_lairEnterRBBLobbyFromRBBPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7703);
}

void warp_lairEnterRBBLobbyFromMMMPuzzleRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7704);
}

void warp_lairEnterMMMPuzzleFromRBBLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7801);
}

void warp_lairEnterRBBPuzzleFromRBBLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7802);
}

void warp_lairEnterCCWLobbyFromFurnaceFunPath(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7903);
}

void warp_lairEnterFurnaceFunPathFromCCWLobby(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8001);
}

void warp_smEnterBanjosHouse(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8C01);
}

void warp_smExitBanjosHouse(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x112);
}

void warp_lairEnterMMLobbyFromSMLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6912);
}

void warp_smExitLair(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x113);
}

void warp_rbbExitAnchorRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x3113);
}

void warp_rbbEnterAnchorRoom(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8B04);
}

void warp_mmmEnterWellBottom(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x2504);
    }
}

void warp_mmmExitWellBottom(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x1B13);
    }
}

void warp_mmmEnterBathroomFromLoggo(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC8C(arg0, 0x2C04);
    }
}

void warp_mmmEnterLoggo(s32 arg0, s32 arg1) {
    if (player_getTransformation() == TRANSFORM_3_PUMPKIN) {
        func_8031CC60(0x8D04);
    }
}

// Unused
void func_8031F80C(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7502);
}

void warp_lairTTCLobbyFromTTCLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6D04);
}

void warp_lairCCWLobbyFromCCWLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x7906);
}

void warp_ccwEnterLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4007);
}

void warp_lairFPLobbyFromFPLevel(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6F06);
}

void warp_ccwEnterSpringNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5E02);
}

void warp_ccwEnterSummerNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x5F02);
}

void warp_ccwEnterAutumnNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6002);
}

void warp_ccwEnterWinterNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x6102);
}

void warp_ccwExitSpringNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4304);
}

void warp_ccwExitSummerNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4404);
}

void warp_ccwExitAutumnNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4504);
}

void warp_ccwExitWinterNabnutWindow(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x4604);
}

void func_8031F9E0(void){}

void func_8031F9E8(){
    D_80383190 = 0;
}

void func_8031F9F4(s32 arg0){
    D_80383190 = arg0;
}

void warp_ttcExitSharkfoodIsland(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x780);
}

void warp_gvEnterSNSChamper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x9205);
}

void warp_gvExitSNSChamper(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x120A);
}

void warp_lairEnterDingpotRoomFromFurnaceFun(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x9305);
}

// warp_lairEnterFurnaceFunFrom?
void func_8031FA90(s32 arg0, s32 arg1) {
    func_8031CC8C(arg0, 0x8E05);
}

void func_8031FAB4(s32 arg0, s32 arg1) {
    if ((fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY) != 0) && (jiggyscore_total() == 100)) {
        // Beach Cutscene
        func_8031CC8C(arg0, 0x9501);
    } else {
        // Final Battle
        func_8031CC8C(arg0, 0x9001);
    }
}

void warp_lairEnterLairFromSMLevel(s32 arg0, s32 arg1) {
    if (fileProgressFlag_get(FILEPROG_BD_ENTER_LAIR_CUTSCENE) != 0) {
        // MM Lobby
        func_8031CC8C(arg0, 0x6912);
    } else {
        fileProgressFlag_set(FILEPROG_BD_ENTER_LAIR_CUTSCENE, 1);
        // Enter Lair Cutscene
        func_8031CC8C(arg0, 0x8204);
    }
}

void func_8031FB6C(s32 arg0, s32 arg1) {
    func_8030E6D4(SFX_7C_CHEBOOF);
    func_8031CC8C(arg0, 0x7104);
}

void func_8031FBA0(void) {
    bsStoredState_clear();
    func_8031FFAC();
    item_setItemsStartCounts();
    jiggyscore_clearAll();
    honeycombscore_clear();
    mumboscore_clear();
    volatileFlag_clear();
    func_802D6344();
}

void func_8031FBF8(void) {
    mumboscore_debug();
    honeycombscore_debug();
    jiggyscore_debug();
    func_803465DC();
    bsStoredState_debug();
    func_802C5A48();
}
