#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//these funtions include references to overlay functions
extern void func_802DC528(s32, s32);
extern void func_802DC560(s32, s32);
extern void func_802DC748(s32, s32);
extern void func_802DC780(s32, s32);
extern void chOverlayPressStart_spawn(s32, s32);
extern void chOverlayPressStart_func_802DCDC0(s32, s32);
extern void func_8031D06C(s32, s32);
extern void func_8031D09C(s32, s32);
extern void warp_mmEnterMumbosHut(s32, s32);
extern void warp_mmExitMumbosHut(s32, s32);
extern void warp_mmEnterTickersTowerLower(s32, s32);
extern void warp_mmExitTickersTowerLower(s32, s32);
extern void warp_mmEnterTickersTowerUpper(s32, s32);
extern void warp_mmExitTickersTowerUpper(s32, s32);
extern void warp_csNintendoLogo(s32, s32);
extern void warp_bgsEnterTanktupConditional(s32, s32);
extern void warp_ttcEnterNippersShell(s32, s32);
extern void warp_gvEnterJinxy(s32, s32);
extern void warp_gvExitJinxy(s32, s32);
extern void warp_bgsExitMumbosHut(s32, s32);
extern void warp_bgsEnterMumbosHut(s32, s32);
extern void warp_ttcEnterLevel(s32, s32);
extern void warp_ccEnterLevel(s32, s32);
extern void warp_bgsEnterLevel(s32, s32);
extern void warp_gvEnterLevel(s32, s32);
extern void warp_mmmEnterLevel(s32, s32);
extern void warp_rbbEnterLevel(s32, s32);
extern void warp_ttcExitNipper(s32, s32);
extern void warp_ccwEnterSpringWhipcrackRoom(s32, s32);
extern void warp_ccwEnterSummerWhipcrackRoom(s32, s32);
extern void warp_ccwEnterAutumnWhipcrackRoom(s32, s32);
extern void warp_ccwEnterWinterWhipcrackRoom(s32, s32);
extern void warp_ccwEnterWinterAcornStorage(s32, s32);
extern void warp_ccwEnterAutumnFloodedAttic(s32, s32);
extern void warp_ccwEnterWinterFloodedAttic(s32, s32);
extern void warp_ccwExitWinterAcornStorage(s32, s32);
extern void warp_ccwExitAutumnFloodedAttic(s32, s32);
extern void warp_ccwExitWinterFloodedAttic(s32, s32);
extern void warp_fpEnterMumbosHut(s32, s32);
extern void warp_fpEnterBoggyIgloo(s32, s32);
extern void warp_fpEnterXmasTree(s32, s32);
extern void warp_fpExitMumbosHut(s32, s32);
extern void warp_fpExitBoggyIgloo(s32, s32);
extern void warp_fpExitXmasTree(s32, s32);
extern void warp_lairEnterMMLobbyFromMMLevel(s32, s32);
extern void func_8031EF20(s32, s32);
extern void warp_lairEnterPuzzlesRoomFromMMLobby(s32, s32);
extern void warp_lairEnterPointingStatueRoomFromGVLobbyNoteDoor(s32, s32);
extern void warp_lairEnterPuzzlesRoomFromCCWPuzzleRoom(s32, s32);
extern void warp_lairEnterCCWPuzzleRoomFromPuzzlesRoom(s32, s32);
extern void warp_lairEnterCCWPuzzleRoomFromRedCauldronRoom(s32, s32);
extern void warp_lairEnterRedCauldronRoomFromCCWPuzzleRoom(s32, s32);
extern void warp_lairEnterCCWPuzzleRoomFromTTCLobby(s32, s32);
extern void warp_lairEnterTTCLobbyFromCCWPuzzleRoom(s32, s32);
extern void warp_lairEnterCCWPuzzleRoomFromCCLobby(s32, s32);
extern void warp_lairEnterCCLobbyFromCCWPuzzleRoom(s32, s32);
extern void warp_lairEnterCCLobbyFromCCLevel(s32, s32);
extern void warp_lairEnterCCWPuzzleFromPointingGruntyStatueRoom(s32, s32);
extern void warp_lairEnterPointingGruntyStatueFromCCWPuzzleRoom(s32, s32);
extern void warp_lairEnterRBBLobbyFromRBBPuzzleRoom(s32, s32);
extern void warp_lairEnterRBBLobbyFromMMMPuzzleRoom(s32, s32);
extern void func_80334430(NodeProp *, ActorMarker  *);
extern void func_80363388(s32, s32);
extern void chOrangePad_handleOrangeCollision(s32, s32);
extern void func_80388BEC(s32, s32);
extern void func_80388C00(s32, s32);
extern void func_80388C28(s32, s32);
extern void func_80388C50(s32, s32);
extern void CC_func_80388C78(s32, s32);
extern void func_8038A0E4(s32, s32);
extern void func_8038A150(s32, s32);
extern void func_8038F10C(s32, s32);
extern void func_8038F130(s32, s32);

extern void warp_lairEnterGVLobbyFromPointingStatueRoom(s32, s32);
extern void warp_lairEnterMMLobbyFromPuzzlesRoom(s32, s32);
extern void warp_lairEnterFPLobbyFromGVLobby(s32, s32);
extern void warp_lairEnterGVLobbyFromGVLevel(s32, s32);
extern void warp_lairEnterGVLobbyFromFPLobby(s32, s32);
extern void warp_ccwExitSpringWhipcrackRoom(s32, s32);
extern void warp_ccwExitSummerWhipcrackRoom(s32, s32);
extern void warp_ccwExitAutumnWhipcrackRoom(s32, s32);
extern void warp_ccwExitWinterWhipcrackRoom(s32, s32);
extern void warp_gvEnterMatchingPyramid(s32, s32);
extern void warp_gvEnterMazePyramid(s32, s32);
extern void warp_gvEnterWaterPyramidUpper(s32, s32);
extern void warp_gvEnterWaterPyramidLower(s32, s32);
extern void warp_gvEnterRubeePyramid(s32, s32);
extern void warp_gvExitMatchingPyramid(s32, s32);
extern void warp_gvExitMazePyramid(s32, s32);
extern void warp_gvExitWaterPyramidLower(s32, s32);
extern void warp_gvExitRubeePyramid(s32, s32);
extern void warp_bgsEnterTanktup(s32, s32);
extern void warp_bgsEnterMrVileRightNostril(s32, s32);
extern void warp_bgsEnterMrVileLeftNostril(s32, s32);
extern void warp_bgsExitTanktup(s32, s32);
extern void warp_bgsExitVileRightNostril(s32, s32);
extern void warp_bgsExitVileLeftNostril(s32, s32);
extern void warp_ttcEnterSandcastle(s32, s32);
extern void warp_ttcStairAlcoveDown(s32, s32);
extern void warp_ttcStairAlcoveUp(s32, s32);
extern void warp_ttcEnterBlubbersShipUpper(s32, s32);
extern void warp_ttcEnterBlubbersShipSide(s32, s32);
extern void func_8031D628(s32, s32);
extern void warp_ttcExitLighthouseTop(s32, s32);
extern void warp_ttcExitSandcastle(s32, s32);
extern void warp_fpEnterLevel(s32, s32);
extern void func_8031FAB4(s32, s32);
extern void warp_ttcExitBlubbersShipUpper(s32, s32);
extern void warp_ttcExitBlubbersShipSide(s32, s32);
extern void warp_lairEnterDingpotRoomFromFurnaceFun(s32, s32);
extern void func_8031FA90(s32, s32);
extern void warp_mmmEnterDiningRoomDoor(s32, s32);
extern void warp_mmmEnterDiningRoomChimney(s32, s32);
extern void warp_mmmEnterWellTop(s32, s32);
extern void warp_mmmEnterTumblarShed(s32, s32);
extern void func_8031DAE0(s32, s32);
extern void warp_mmmEnterChurchSecretRoom(s32, s32);
extern void func_8031DC10(s32, s32);
extern void warp_mmmEnterRainBarrelBottom(s32, s32);
extern void warp_mmmEnterCellar(s32, s32);
extern void warp_mmmEnterRedFeatherRoom(s32, s32);
extern void warp_mmmEnterBlueEggRoom(s32, s32);
extern void warp_mmmEnterNoteRoom(s32, s32);
extern void warp_mmmEnterBrokenFloorboardRoom(s32, s32);
extern void warp_mmmEnterBedroom(s32, s32);
extern void warp_mmmEnterBathroomWindow(s32, s32);
extern void warp_mmmExitDiningRoomDoor(s32, s32);
extern void func_8031D820(s32, s32);
extern void warp_mmmExitWellTop(s32, s32);
extern void warp_mmmExitTumblarShed(s32, s32);
extern void warp_mmmExitChurchFrontDoor(s32, s32);
extern void warp_mmmExitChurchSecretRoom(s32, s32);
extern void func_8031D8D4(s32, s32);
extern void warp_mmmExitRainBarrelBottom(s32, s32);
extern void warp_mmmExitCellar(s32, s32);
extern void warp_mmmExitRedFeatherRoom(s32, s32);
extern void warp_mmmExitBlueEggRoom(s32, s32);
extern void warp_mmmExitBathroomWindow(s32, s32);
extern void warp_mmmExitBrokenFloorboardRoom(s32, s32);
extern void warp_mmmExitBedroom(s32, s32);
extern void warp_mmmExitNoteRoom(s32, s32);
extern void warp_mmmChurchTowerUp(s32, s32);
extern void warp_mmmChurchTowerDown(s32, s32);
extern void warp_mmmExitMumbosHut(s32, s32);
extern void warp_mmmEnterMumbosHut(s32, s32);
extern void warp_ccExitWonderwingRoom(s32, s32);
extern void warp_ccEnterClankerBelly(s32, s32);
extern void warp_ccEnterClankerMouth(s32, s32);
extern void warp_ccEnterWonderwingRoom(s32, s32);
extern void warp_mmEnterLevel(s32, s32);
extern void warp_rbbEnterCaptainsRoomWindow(s32, s32);
extern void warp_rbbEnterCabinRoomWindow(s32, s32);
extern void warp_rbbEnterEngineRoomPipe(s32, s32);
extern void warp_rbbEnterKitchenPipe(s32, s32);
extern void warp_rbbEnterNavigationRoomWindow(s32, s32);
extern void warp_rbbEnterBoomBoxPipe(s32, s32);
extern void warp_rbbEnterEngineRoomDoor(s32, s32);
extern void warp_rbbEnterChumpWarehouseWindow(s32, s32);
extern void warp_rbbEnterBoatRoom(s32, s32);
extern void warp_rbbEnterChompaContainer(s32, s32);
extern void warp_rbbEnterSeamanGrublinContainer(s32, s32);
extern void warp_rbbEnterBoomBoxContainer(s32, s32);
extern void warp_rbbExitCaptainsRoomWindow(s32, s32);
extern void warp_rbbExitCabinRoomWindow(s32, s32);
extern void warp_rbbExitEngineRoomPipe(s32, s32);
extern void warp_rbbExitKitchenPipe(s32, s32);
extern void warp_rbbExitNavigationRoomWindow(s32, s32);
extern void warp_rbbExitBoomBoxPipe(s32, s32);
extern void warp_rbbExitEngineRoomDoor(s32, s32);
extern void warp_rbbExitBoatRoom(s32, s32);
extern void warp_rbbExitChompaContainer(s32, s32);
extern void warp_rbbExitSeamanGrublinContainer(s32, s32);
extern void warp_rbbExitBoomBoxContainer(s32, s32);
extern void warp_rbbExitBossBoomBoxRoom(s32, s32);
extern void warp_rbbEnterBossBoomBoxRoom(s32, s32);
extern void warp_rbbEnterChumpWarehouseDoor(s32, s32);
extern void warp_rbbExitChumpWarehouseDoor(s32, s32);
extern void func_8031E308(s32, s32);
extern void func_8031E32C(s32, s32);
extern void func_8031E350(s32, s32);
extern void func_8031E374(s32, s32);
extern void func_8031E398(s32, s32);
extern void func_8031E3BC(s32, s32);
extern void func_8031E3E0(s32, s32);
extern void func_8031E404(s32, s32);
extern void func_8031E428(s32, s32);
extern void func_8031E44C(s32, s32);
extern void func_8031E470(s32, s32);
extern void func_8031E494(s32, s32);
extern void func_8031E4B8(s32, s32);
extern void func_8031E4DC(s32, s32);
extern void func_8031E500(s32, s32);
extern void func_8031E524(s32, s32);
extern void func_8031E548(s32, s32);
extern void func_8031E56C(s32, s32);
extern void func_8031E590(s32, s32);
extern void func_8031E5B4(s32, s32);
extern void func_8031E5D8(s32, s32);
extern void func_8031E5FC(s32, s32);
extern void func_8031E620(s32, s32);
extern void func_8031E644(s32, s32);
extern void func_8031E668(s32, s32);
extern void func_8031E68C(s32, s32);
extern void func_8031E6B0(s32, s32);
extern void warp_ccwExitWinterToHub(s32, s32);
extern void warp_ccwExitSpringToHub(s32, s32);
extern void warp_ccwExitSummerToHub(s32, s32);
extern void warp_ccwExitAutumnToHub(s32, s32);
extern void warp_ccwEnterWinter(s32, s32);
extern void warp_ccwEnterSpring(s32, s32);
extern void warp_ccwEnterSummer(s32, s32);
extern void warp_ccwEnterAutumn(s32, s32);
extern void warp_gvExitSandybuttMazeBack(s32, s32);
extern void warp_ttcExitSpringMumbosHut(s32, s32);
extern void warp_ttcExitSummerMumbosHut(s32, s32);
extern void warp_ttcExitAutumnMumbosHut(s32, s32);
extern void warp_ttcExitWinterMumbosHut(s32, s32);
extern void warp_ttcEnterSpringMumbosHut(s32, s32);
extern void warp_ttcEnterSummerMumbosHut(s32, s32);
extern void warp_ttcEnterAutumnMumbosHut(s32, s32);
extern void warp_ttcEnterWinterMumbosHut(s32, s32);
extern void warp_ccwEnterSpringNabnutDoor(s32, s32);
extern void warp_ccwEnterSummerNabnutDoor(s32, s32);
extern void warp_ccwEnterAutumnNabnutDoor(s32, s32);
extern void warp_ccwExitSpringNabnutDoor(s32, s32);
extern void warp_ccwExitSummerNabnutDoor(s32, s32);
extern void warp_ccwExitAutumnNabnutDoor(s32, s32);
extern void warp_ccwExitWinterNabnutDoor(s32, s32);
extern void func_8031F0F4(s32, s32);
extern void func_8031F118(s32, s32);
extern void warp_lairEnterGVPuzzleRoomFromMMMLobby(s32, s32);
extern void warp_ttcExitSharkfoodIsland(s32, s32);
extern void warp_lairEnterRBBLobbyFromRBBLevel(s32, s32);
extern void warp_lairEnterBGSLobbyFromBGSLevel(s32, s32);
extern void warp_fpExitWozzasCave(s32, s32);
extern void warp_fpEnterWozzasCave(s32, s32);
extern void warp_lairEnterCryptFromMMMLobby(s32, s32);
extern void warp_lairEnterMMMLobbyFromCrypt(s32, s32);
extern void warp_lairEnterPointingGruntyStatueFromBGSLobby(s32, s32);
extern void warp_lairEnterBGSLobbyFromPointingGruntyStatueRoom(s32, s32);
extern void warp_lairEnterMMMLobbyFromGVPuzzleRoom(s32, s32);
extern void warp_lairEnterGVPuzzleRoomFromFPLobby(s32, s32);
extern void warp_lairFPLobbyFromGVPuzzleRoom(s32, s32);
extern void warp_lairEnter640NoteDoorRoomFromFPLobby(s32, s32);
extern void warp_lairEnter640NoteDoorRoomFromCCWLobbyTokenEntrance(s32, s32);
extern void warp_lairEnter640NoteDoorRoomFromCCWLobbyDoorEntrance(s32, s32);
extern void warp_lairEnter640NoteDoorRoomFromRBBLobby(s32, s32);
extern void warp_lairRBBLobbyFrom640NoteDoorRoom(s32, s32);
extern void warp_lairCCWLobbyFrom640NoteDoorRoomDoorEntrance(s32, s32);
extern void warp_lairCCWLobbyFrom640NoteDoorRoomTokenEntrance(s32, s32);
extern void warp_lairEnterFPLobbyFrom640NoteDoorRoom(s32, s32);
extern void warp_ccwEnterSpringZubbaHive(s32, s32);
extern void warp_ccwEnterSummerZubbaHive(s32, s32);
extern void warp_ccwEnterAutumnZubbaHive(s32, s32);
extern void warp_ccwExitSpringZubbaHive(s32, s32);
extern void warp_ccwExitSummerZubbaHive(s32, s32);
extern void warp_ccwExitAutumnZubbaHive(s32, s32);
extern void warp_lairEnterMMMPuzzleFromRBBLobby(s32, s32);
extern void warp_lairEnterRBBPuzzleFromRBBLobby(s32, s32);
extern void func_8031FB6C(s32, s32);
extern void warp_lairEnterCCWLobbyFromFurnaceFunPath(s32, s32);
extern void warp_lairEnterFurnaceFunPathFromCCWLobby(s32, s32);
extern void warp_smEnterBanjosHouse(s32, s32);
extern void warp_smExitBanjosHouse(s32, s32);
extern void warp_lairEnterMMLobbyFromSMLevel(s32, s32);
extern void warp_smExitLair(s32, s32);
extern void warp_rbbExitAnchorRoom(s32, s32);
extern void warp_rbbEnterAnchorRoom(s32, s32);
extern void warp_mmmEnterWellBottom(s32, s32);
extern void warp_mmmExitWellBottom(s32, s32);
extern void warp_mmmEnterBathroomFromLoggo(s32, s32);
extern void warp_mmmEnterLoggo(s32, s32);
extern void warp_ccwEnterLevel(s32, s32);
extern void warp_ccwEnterSpringNabnutWindow(s32, s32);
extern void warp_ccwEnterSummerNabnutWindow(s32, s32);
extern void warp_ccwEnterAutumnNabnutWindow(s32, s32);
extern void warp_ccwEnterWinterNabnutWindow(s32, s32);
extern void warp_ccwExitSpringNabnutWindow(s32, s32);
extern void warp_ccwExitSummerNabnutWindow(s32, s32);
extern void warp_ccwExitAutumnNabnutWindow(s32, s32);
extern void warp_ccwExitWinterNabnutWindow(s32, s32);
extern void warp_gvEnterSNSChamper(s32, s32);
extern void warp_gvExitSNSChamper(s32, s32);
extern void warp_lairEnterLairFromSMLevel(s32, s32);

extern void func_802C1674(NodeProp *, ActorMarker *);
extern void func_802C169C(NodeProp *, ActorMarker *);
extern void chTreasurehunt_checkStepProgress0(NodeProp *, ActorMarker *);
extern void chTreasurehunt_checkStepProgress1(NodeProp *, ActorMarker *);
extern void chTreasurehunt_checkStepProgress2(NodeProp *, ActorMarker *);
extern void chTreasurehunt_checkStepProgress3(NodeProp *, ActorMarker *);
extern void chTreasurehunt_checkStepProgress4(NodeProp *, ActorMarker *);
extern void chTreasurehunt_checkStepProgress5(NodeProp *, ActorMarker *);
extern void chMumbo_detransformWarn(NodeProp *, ActorMarker *);
extern void chMumbo_detransformTrigger(NodeProp *, ActorMarker *);
extern void func_8033443C(NodeProp *arg0, ActorMarker *arg1);

typedef void (*CodeAD110Callback)(NodeProp *arg0, ActorMarker *arg1);


typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18;
    u8 unk1C;
    u8 pad1D[3];
}Struct_core2_AD110_0;


/* .data */
void * sWarpFunctions[] = {
    func_80388BEC, func_80334430, chOrangePad_handleOrangeCollision, chOrangePad_handleOrangeCollision,
    chOrangePad_handleOrangeCollision, warp_gvEnterJinxy, warp_gvExitJinxy, func_8038F10C,
    func_8038F130, warp_bgsEnterMumbosHut, warp_bgsExitMumbosHut, warp_ttcExitNipper,
    warp_ttcEnterLevel, warp_ccEnterLevel, warp_bgsEnterLevel, warp_gvEnterLevel,
    warp_mmmEnterLevel, warp_rbbEnterLevel, warp_ccwEnterSpringWhipcrackRoom, warp_ccwEnterSummerWhipcrackRoom,
    warp_ccwEnterAutumnWhipcrackRoom, warp_ccwEnterWinterWhipcrackRoom, warp_mmEnterMumbosHut, warp_mmExitMumbosHut,
    warp_mmEnterTickersTowerLower, warp_mmExitTickersTowerLower, warp_mmEnterTickersTowerUpper, warp_mmExitTickersTowerUpper,
    warp_csNintendoLogo, func_8031D09C, func_8031D06C, func_80334430,
    func_80334430, func_80334430, warp_lairEnterCCWPuzzleFromPointingGruntyStatueRoom, warp_lairEnterPointingGruntyStatueFromCCWPuzzleRoom,
    warp_lairEnterCCLobbyFromCCLevel, warp_lairEnterCCLobbyFromCCWPuzzleRoom, warp_lairEnterCCWPuzzleRoomFromCCLobby, warp_lairEnterCCWPuzzleRoomFromTTCLobby,
    warp_lairEnterTTCLobbyFromCCWPuzzleRoom, warp_ccwEnterWinterAcornStorage, warp_ccwEnterAutumnFloodedAttic, warp_ccwEnterWinterFloodedAttic,
    warp_ccwExitWinterAcornStorage, warp_ccwExitAutumnFloodedAttic, warp_ccwExitWinterFloodedAttic, func_80388C00,
    func_80388C28, func_80388C50, CC_func_80388C78, func_80334430,
    func_80334430, func_80334430, func_802DC748, func_802DC780,
    warp_lairEnterRBBLobbyFromRBBPuzzleRoom, warp_lairEnterRBBLobbyFromMMMPuzzleRoom, warp_lairEnterCCWPuzzleRoomFromRedCauldronRoom, warp_lairEnterRedCauldronRoomFromCCWPuzzleRoom,
    warp_lairEnterPuzzlesRoomFromCCWPuzzleRoom, warp_lairEnterCCWPuzzleRoomFromPuzzlesRoom, warp_lairEnterPointingStatueRoomFromGVLobbyNoteDoor, warp_lairEnterPuzzlesRoomFromMMLobby,
    warp_fpEnterMumbosHut, warp_fpEnterBoggyIgloo, warp_fpEnterXmasTree, warp_fpExitMumbosHut,
    warp_fpExitBoggyIgloo, warp_fpExitXmasTree, warp_bgsEnterTanktupConditional, warp_ttcEnterNippersShell,
    func_80363388, func_8038A0E4, func_8038A150, func_80334430,
    chOverlayPressStart_spawn, chOverlayPressStart_func_802DCDC0, func_802DC528, func_802DC560,
    func_8031EF20, warp_lairEnterMMLobbyFromMMLevel, func_80334430, warp_lairEnterGVLobbyFromGVLevel,
    warp_lairEnterGVLobbyFromFPLobby, warp_lairEnterFPLobbyFromGVLobby, warp_lairEnterMMLobbyFromPuzzlesRoom, warp_lairEnterGVLobbyFromPointingStatueRoom,
    warp_ccwExitSpringWhipcrackRoom, warp_ccwExitSummerWhipcrackRoom, warp_ccwExitAutumnWhipcrackRoom, warp_ccwExitWinterWhipcrackRoom,
    warp_gvEnterMatchingPyramid, warp_gvEnterMazePyramid, warp_gvEnterWaterPyramidUpper, warp_gvEnterWaterPyramidLower,
    warp_gvEnterRubeePyramid, warp_gvExitMatchingPyramid, warp_gvExitMazePyramid, warp_gvExitWaterPyramidLower,
    warp_gvExitRubeePyramid, warp_bgsEnterTanktup, warp_bgsEnterMrVileRightNostril, warp_bgsEnterMrVileLeftNostril,
    warp_bgsExitTanktup, warp_bgsExitVileRightNostril, warp_bgsExitVileLeftNostril, warp_ttcEnterSandcastle,
    warp_ttcStairAlcoveDown, warp_ttcStairAlcoveUp, warp_ttcEnterBlubbersShipUpper, warp_ttcEnterBlubbersShipSide,
    func_8031D628, warp_ttcExitLighthouseTop, warp_ttcExitSandcastle, warp_fpEnterLevel,
    func_8031FAB4, warp_ttcExitBlubbersShipUpper, warp_ttcExitBlubbersShipSide, warp_lairEnterDingpotRoomFromFurnaceFun,
    func_8031FA90, warp_mmmEnterDiningRoomDoor, warp_mmmEnterDiningRoomChimney, warp_mmmEnterWellTop,
    warp_mmmEnterTumblarShed, func_8031DAE0, warp_mmmEnterChurchSecretRoom, func_8031DC10,
    warp_mmmEnterRainBarrelBottom, warp_mmmEnterCellar, warp_mmmEnterRedFeatherRoom, warp_mmmEnterBlueEggRoom,
    warp_mmmEnterNoteRoom, warp_mmmEnterBrokenFloorboardRoom, warp_mmmEnterBedroom, warp_mmmEnterBathroomWindow,
    warp_mmmExitDiningRoomDoor, func_8031D820, warp_mmmExitWellTop, warp_mmmExitTumblarShed,
    warp_mmmExitChurchFrontDoor, warp_mmmExitChurchSecretRoom, func_8031D8D4, warp_mmmExitRainBarrelBottom,
    warp_mmmExitCellar, warp_mmmExitRedFeatherRoom, warp_mmmExitBlueEggRoom, warp_mmmExitBathroomWindow,
    warp_mmmExitBrokenFloorboardRoom, warp_mmmExitBedroom, warp_mmmExitNoteRoom, warp_mmmChurchTowerUp,
    warp_mmmChurchTowerDown, warp_mmmExitMumbosHut, warp_mmmEnterMumbosHut, warp_ccExitWonderwingRoom,
    warp_ccEnterClankerBelly, warp_ccEnterClankerMouth, warp_ccEnterWonderwingRoom, warp_mmEnterLevel,
    warp_rbbEnterCaptainsRoomWindow, warp_rbbEnterCabinRoomWindow, warp_rbbEnterEngineRoomPipe, warp_rbbEnterKitchenPipe,
    warp_rbbEnterNavigationRoomWindow, warp_rbbEnterBoomBoxPipe, warp_rbbEnterEngineRoomDoor, warp_rbbEnterChumpWarehouseWindow,
    warp_rbbEnterBoatRoom, warp_rbbEnterChompaContainer, warp_rbbEnterSeamanGrublinContainer, warp_rbbEnterBoomBoxContainer,
    warp_rbbExitCaptainsRoomWindow, warp_rbbExitCabinRoomWindow, warp_rbbExitEngineRoomPipe, warp_rbbExitKitchenPipe,
    warp_rbbExitNavigationRoomWindow, warp_rbbExitBoomBoxPipe, warp_rbbExitEngineRoomDoor, warp_rbbExitBoatRoom,
    warp_rbbExitChompaContainer, warp_rbbExitSeamanGrublinContainer, warp_rbbExitBoomBoxContainer, warp_rbbExitBossBoomBoxRoom,
    warp_rbbEnterBossBoomBoxRoom, warp_rbbEnterChumpWarehouseDoor, warp_rbbExitChumpWarehouseDoor, func_8031E308,
    func_8031E32C, func_8031E350, func_8031E374, func_8031E398,
    func_8031E3BC, func_8031E3E0, func_8031E404, func_8031E428,
    func_8031E44C, func_8031E470, func_8031E494, func_8031E4B8,
    func_8031E4DC, func_8031E500, func_8031E524, func_8031E548,
    func_8031E56C, func_8031E590, func_8031E5B4, func_8031E5D8,
    func_8031E5FC, func_8031E620, func_8031E644, func_8031E668,
    func_8031E68C, func_8031E6B0, warp_ccwExitWinterToHub, warp_ccwExitSpringToHub,
    warp_ccwExitSummerToHub, warp_ccwExitAutumnToHub, warp_ccwEnterWinter, warp_ccwEnterSpring,
    warp_ccwEnterSummer, warp_ccwEnterAutumn, warp_gvExitSandybuttMazeBack, warp_ttcExitSpringMumbosHut,
    warp_ttcExitSummerMumbosHut, warp_ttcExitAutumnMumbosHut, warp_ttcExitWinterMumbosHut, warp_ttcEnterSpringMumbosHut,
    warp_ttcEnterSummerMumbosHut, warp_ttcEnterAutumnMumbosHut, warp_ttcEnterWinterMumbosHut, warp_ccwEnterSpringNabnutDoor,
    warp_ccwEnterSummerNabnutDoor, warp_ccwEnterAutumnNabnutDoor, func_80334430, warp_ccwExitSpringNabnutDoor,
    warp_ccwExitSummerNabnutDoor, warp_ccwExitAutumnNabnutDoor, warp_ccwExitWinterNabnutDoor, func_8031F0F4,
    func_8031F118, warp_lairEnterGVPuzzleRoomFromMMMLobby, func_80334430, func_80334430,
    func_80334430, func_80334430, func_80334430, func_80334430,
    func_80334430, warp_ttcExitSharkfoodIsland, warp_lairEnterRBBLobbyFromRBBLevel, warp_lairEnterBGSLobbyFromBGSLevel,
    warp_fpExitWozzasCave, warp_fpEnterWozzasCave, warp_lairEnterCryptFromMMMLobby, warp_lairEnterMMMLobbyFromCrypt,
    warp_lairEnterPointingGruntyStatueFromBGSLobby, warp_lairEnterBGSLobbyFromPointingGruntyStatueRoom, warp_lairEnterMMMLobbyFromGVPuzzleRoom, warp_lairEnterGVPuzzleRoomFromFPLobby,
    warp_lairFPLobbyFromGVPuzzleRoom, warp_lairEnter640NoteDoorRoomFromFPLobby, warp_lairEnter640NoteDoorRoomFromCCWLobbyTokenEntrance, warp_lairEnter640NoteDoorRoomFromCCWLobbyDoorEntrance,
    warp_lairEnter640NoteDoorRoomFromRBBLobby, warp_lairRBBLobbyFrom640NoteDoorRoom, warp_lairCCWLobbyFrom640NoteDoorRoomDoorEntrance, warp_lairCCWLobbyFrom640NoteDoorRoomTokenEntrance,
    warp_lairEnterFPLobbyFrom640NoteDoorRoom, warp_ccwEnterSpringZubbaHive, warp_ccwEnterSummerZubbaHive, warp_ccwEnterAutumnZubbaHive,
    warp_ccwExitSpringZubbaHive, warp_ccwExitSummerZubbaHive, warp_ccwExitAutumnZubbaHive, warp_lairEnterMMMPuzzleFromRBBLobby,
    warp_lairEnterRBBPuzzleFromRBBLobby, func_8031FB6C, warp_lairEnterCCWLobbyFromFurnaceFunPath, warp_lairEnterFurnaceFunPathFromCCWLobby,
    warp_smEnterBanjosHouse, warp_smExitBanjosHouse, warp_lairEnterMMLobbyFromSMLevel, warp_smExitLair,
    warp_rbbExitAnchorRoom, warp_rbbEnterAnchorRoom, warp_mmmEnterWellBottom, warp_mmmExitWellBottom,
    warp_mmmEnterBathroomFromLoggo, warp_mmmEnterLoggo, warp_ccwEnterLevel, warp_ccwEnterSpringNabnutWindow,
    warp_ccwEnterSummerNabnutWindow, warp_ccwEnterAutumnNabnutWindow, warp_ccwEnterWinterNabnutWindow, warp_ccwExitSpringNabnutWindow,
    warp_ccwExitSummerNabnutWindow, warp_ccwExitAutumnNabnutWindow, warp_ccwExitWinterNabnutWindow, warp_gvEnterSNSChamper,
    warp_gvExitSNSChamper, warp_lairEnterLairFromSMLevel, func_80334430, func_80334430,
    func_80334430, func_80334430, func_80334430, func_80334430,
    func_80334430, func_80334430, func_80334430,
};

CodeAD110Callback sRadiusTriggers[] ={
    func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C1674, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, chTreasurehunt_checkStepProgress0, chTreasurehunt_checkStepProgress1, chTreasurehunt_checkStepProgress2,
    chTreasurehunt_checkStepProgress3, chTreasurehunt_checkStepProgress4, chTreasurehunt_checkStepProgress5, chMumbo_detransformWarn,
    chMumbo_detransformTrigger, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C
};

/* .bss */
vector(Struct_core2_AD110_0) *D_803835C0;

/* .code */
bool func_803340A0(f32 arg0[3], f32 arg1[3], f32 arg2) {
    f32 sp4C[3];
    f32 sp40[3];
    Struct_core2_AD110_0 *begin_ptr;
    Struct_core2_AD110_0 *i_ptr;
    Struct_core2_AD110_0 *end_ptr;
    s32 i;

    for(i = 0; i < 3; i++){
        if (arg0[i] <= arg1[i]) {
            sp4C[i] = arg0[i] - arg2;
            sp40[i] = arg1[i] + arg2;
        } else {
            sp4C[i] = arg1[i] - arg2;
            sp40[i] = arg0[i] + arg2;
        }
    }

    end_ptr = (Struct_core2_AD110_0 *)vector_getEnd(D_803835C0);
    begin_ptr = (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0);
    for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++) {
        if( (i_ptr->unk1C == 1) 
            && ((!((i_ptr->unk0[0] + i_ptr->unk18) <= sp4C[0])) || !((i_ptr->unkC[0] + i_ptr->unk18) <= sp4C[0]))
            && ((!((i_ptr->unk0[1] + i_ptr->unk18) <= sp4C[1])) || !((i_ptr->unkC[1] + i_ptr->unk18) <= sp4C[1]))
            && ((!((i_ptr->unk0[2] + i_ptr->unk18) <= sp4C[2])) || !((i_ptr->unkC[2] + i_ptr->unk18) <= sp4C[2])) 
            && (!(sp40[0] <= (i_ptr->unk0[0] - i_ptr->unk18)) || !(sp40[0] <= (i_ptr->unkC[0] - i_ptr->unk18))) 
            && (!(sp40[1] <= (i_ptr->unk0[1] - i_ptr->unk18)) || !(sp40[1] <= (i_ptr->unkC[1] - i_ptr->unk18))) 
            && (!(sp40[2] <= (i_ptr->unk0[2] - i_ptr->unk18)) || !(sp40[2] <= (i_ptr->unkC[2] - i_ptr->unk18)))) {
            return FALSE;
        }
    }
    return TRUE;
}

s32 func_803342AC(f32 arg0[3], f32 arg1[3], f32 arg2){
    Struct_core2_AD110_0 * iPtr;
    Struct_core2_AD110_0 * end_ptr;

    if(!func_803340A0(arg0, arg1, arg2))
        return 0;

    end_ptr = (Struct_core2_AD110_0 *)vector_getEnd(D_803835C0);
    for(iPtr = (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0); iPtr < end_ptr; iPtr++){
        if(iPtr->unk1C == 0)
            break;
    }
    if(iPtr == end_ptr){
        iPtr = (Struct_core2_AD110_0 *)vector_pushBackNew(&D_803835C0);
    }
    iPtr->unk1C = 1;

    iPtr->unk0[0] = arg0[0];
    iPtr->unk0[1] = arg0[1];
    iPtr->unk0[2] = arg0[2];

    iPtr->unkC[0] = arg1[0];
    iPtr->unkC[1] = arg1[1];
    iPtr->unkC[2] = arg1[2];

    iPtr->unk18 = arg2;
    return (iPtr - (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0)) + 1;
}


void func_803343AC(void){
    vector_free(D_803835C0);
}

void func_803343D0(void){
    D_803835C0 = vector_new(sizeof(Struct_core2_AD110_0), 2);
}

void func_803343F8(s32 indx){
    Struct_core2_AD110_0 *elem;
    elem = (Struct_core2_AD110_0 *)vector_at(D_803835C0, indx - 1);
    elem->unk1C = 0;
}

void func_80334428(void){}

void func_80334430(NodeProp *arg0, ActorMarker *arg1){}

void func_8033443C(NodeProp *arg0, ActorMarker *arg1){}

void func_80334448(NodeProp *arg0, ActorMarker *arg1) {
    s32 global_timer_time;

    switch(codeA5BC0_getNodePropCategory(arg0)) {
        case 3: // warp (L80334480)
            global_timer_time = globalTimer_getTime();
            if ((codeA5BC0_getNodePropUnkC(arg0) + 1) != global_timer_time) {
                ((CodeAD110Callback) sWarpFunctions[codeA5BC0_getNodePropActorId(arg0)])(arg0, arg1);
            }
            codeA5BC0_setNodePropUnkC(arg0, global_timer_time);
            break;

        case 4: // radius trigger like camera (L803344E0)
            sRadiusTriggers[codeA5BC0_getNodePropActorId(arg0)](arg0, arg1);
            break;

        case 0: //L80334508
        case 1: //L80334508
        case 2: //L80334508
        case 5: //L80334508
            break;

    }
}


s32 func_8033451C(s32 arg0){
    return arg0 - 0x16;
}

s32 func_80334524(s32 arg0){
    return arg0 + 0xcc;
}

s32 func_8033452C(s32 arg0){
    return arg0 + 0x19d;
}
