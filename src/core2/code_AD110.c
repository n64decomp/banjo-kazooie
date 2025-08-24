#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//these funtions include references to overlay functions
extern void func_802DC528(NodeProp *, ActorMarker *);
extern void func_802DC560(NodeProp *, ActorMarker *);
extern void func_802DC748(NodeProp *, ActorMarker *);
extern void func_802DC780(NodeProp *, ActorMarker *);
extern void chOverlayPressStart_spawn(NodeProp *, ActorMarker *);
extern void chOverlayPressStart_func_802DCDC0(NodeProp *, ActorMarker *);
extern void func_8031D06C(NodeProp *, ActorMarker *);
extern void func_8031D09C(NodeProp *, ActorMarker *);
extern void warp_mmEnterMumbosHut(NodeProp *, ActorMarker *);
extern void warp_mmExitMumbosHut(NodeProp *, ActorMarker *);
extern void warp_mmEnterTickersTowerLower(NodeProp *, ActorMarker *);
extern void warp_mmExitTickersTowerLower(NodeProp *, ActorMarker *);
extern void warp_mmEnterTickersTowerUpper(NodeProp *, ActorMarker *);
extern void warp_mmExitTickersTowerUpper(NodeProp *, ActorMarker *);
extern void warp_csNintendoLogo(NodeProp *, ActorMarker *);
extern void warp_bgsEnterTanktupConditional(NodeProp *, ActorMarker *);
extern void warp_ttcEnterNippersShell(NodeProp *, ActorMarker *);
extern void warp_gvEnterJinxy(NodeProp *, ActorMarker *);
extern void warp_gvExitJinxy(NodeProp *, ActorMarker *);
extern void warp_bgsExitMumbosHut(NodeProp *, ActorMarker *);
extern void warp_bgsEnterMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcEnterLevel(NodeProp *, ActorMarker *);
extern void warp_ccEnterLevel(NodeProp *, ActorMarker *);
extern void warp_bgsEnterLevel(NodeProp *, ActorMarker *);
extern void warp_gvEnterLevel(NodeProp *, ActorMarker *);
extern void warp_mmmEnterLevel(NodeProp *, ActorMarker *);
extern void warp_rbbEnterLevel(NodeProp *, ActorMarker *);
extern void warp_ttcExitNipper(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSpringWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSummerWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwEnterAutumnWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwEnterWinterWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwEnterWinterAcornStorage(NodeProp *, ActorMarker *);
extern void warp_ccwEnterAutumnFloodedAttic(NodeProp *, ActorMarker *);
extern void warp_ccwEnterWinterFloodedAttic(NodeProp *, ActorMarker *);
extern void warp_ccwExitWinterAcornStorage(NodeProp *, ActorMarker *);
extern void warp_ccwExitAutumnFloodedAttic(NodeProp *, ActorMarker *);
extern void warp_ccwExitWinterFloodedAttic(NodeProp *, ActorMarker *);
extern void warp_fpEnterMumbosHut(NodeProp *, ActorMarker *);
extern void warp_fpEnterBoggyIgloo(NodeProp *, ActorMarker *);
extern void warp_fpEnterXmasTree(NodeProp *, ActorMarker *);
extern void warp_fpExitMumbosHut(NodeProp *, ActorMarker *);
extern void warp_fpExitBoggyIgloo(NodeProp *, ActorMarker *);
extern void warp_fpExitXmasTree(NodeProp *, ActorMarker *);
extern void warp_lairEnterMMLobbyFromMMLevel(NodeProp *, ActorMarker *);
extern void func_8031EF20(NodeProp *, ActorMarker *);
extern void warp_lairEnterPuzzlesRoomFromMMLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterPointingStatueRoomFromGVLobbyNoteDoor(NodeProp *, ActorMarker *);
extern void warp_lairEnterPuzzlesRoomFromCCWPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCWPuzzleRoomFromPuzzlesRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCWPuzzleRoomFromRedCauldronRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterRedCauldronRoomFromCCWPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCWPuzzleRoomFromTTCLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterTTCLobbyFromCCWPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCWPuzzleRoomFromCCLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCLobbyFromCCWPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCLobbyFromCCLevel(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCWPuzzleFromPointingGruntyStatueRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterPointingGruntyStatueFromCCWPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterRBBLobbyFromRBBPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterRBBLobbyFromMMMPuzzleRoom(NodeProp *, ActorMarker *);
extern void func_80334430(NodeProp *, ActorMarker *);
extern void func_80363388(NodeProp *, ActorMarker *);
extern void chOrangePad_handleOrangeCollision(NodeProp *, ActorMarker *);
extern void func_80388BEC(NodeProp *, ActorMarker *);
extern void func_80388C00(NodeProp *, ActorMarker *);
extern void func_80388C28(NodeProp *, ActorMarker *);
extern void func_80388C50(NodeProp *, ActorMarker *);
extern void CC_func_80388C78(NodeProp *, ActorMarker *);
extern void func_8038A0E4(NodeProp *, ActorMarker *);
extern void func_8038A150(NodeProp *, ActorMarker *);
extern void func_8038F10C(NodeProp *, ActorMarker *);
extern void func_8038F130(NodeProp *, ActorMarker *);

extern void warp_lairEnterGVLobbyFromPointingStatueRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterMMLobbyFromPuzzlesRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterFPLobbyFromGVLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterGVLobbyFromGVLevel(NodeProp *, ActorMarker *);
extern void warp_lairEnterGVLobbyFromFPLobby(NodeProp *, ActorMarker *);
extern void warp_ccwExitSpringWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwExitSummerWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwExitAutumnWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_ccwExitWinterWhipcrackRoom(NodeProp *, ActorMarker *);
extern void warp_gvEnterMatchingPyramid(NodeProp *, ActorMarker *);
extern void warp_gvEnterMazePyramid(NodeProp *, ActorMarker *);
extern void warp_gvEnterWaterPyramidUpper(NodeProp *, ActorMarker *);
extern void warp_gvEnterWaterPyramidLower(NodeProp *, ActorMarker *);
extern void warp_gvEnterRubeePyramid(NodeProp *, ActorMarker *);
extern void warp_gvExitMatchingPyramid(NodeProp *, ActorMarker *);
extern void warp_gvExitMazePyramid(NodeProp *, ActorMarker *);
extern void warp_gvExitWaterPyramidLower(NodeProp *, ActorMarker *);
extern void warp_gvExitRubeePyramid(NodeProp *, ActorMarker *);
extern void warp_bgsEnterTanktup(NodeProp *, ActorMarker *);
extern void warp_bgsEnterMrVileRightNostril(NodeProp *, ActorMarker *);
extern void warp_bgsEnterMrVileLeftNostril(NodeProp *, ActorMarker *);
extern void warp_bgsExitTanktup(NodeProp *, ActorMarker *);
extern void warp_bgsExitVileRightNostril(NodeProp *, ActorMarker *);
extern void warp_bgsExitVileLeftNostril(NodeProp *, ActorMarker *);
extern void warp_ttcEnterSandcastle(NodeProp *, ActorMarker *);
extern void warp_ttcStairAlcoveDown(NodeProp *, ActorMarker *);
extern void warp_ttcStairAlcoveUp(NodeProp *, ActorMarker *);
extern void warp_ttcEnterBlubbersShipUpper(NodeProp *, ActorMarker *);
extern void warp_ttcEnterBlubbersShipSide(NodeProp *, ActorMarker *);
extern void func_8031D628(NodeProp *, ActorMarker *);
extern void warp_ttcExitLighthouseTop(NodeProp *, ActorMarker *);
extern void warp_ttcExitSandcastle(NodeProp *, ActorMarker *);
extern void warp_fpEnterLevel(NodeProp *, ActorMarker *);
extern void func_8031FAB4(NodeProp *, ActorMarker *);
extern void warp_ttcExitBlubbersShipUpper(NodeProp *, ActorMarker *);
extern void warp_ttcExitBlubbersShipSide(NodeProp *, ActorMarker *);
extern void warp_lairEnterDingpotRoomFromFurnaceFun(NodeProp *, ActorMarker *);
extern void func_8031FA90(NodeProp *, ActorMarker *);
extern void warp_mmmEnterDiningRoomDoor(NodeProp *, ActorMarker *);
extern void warp_mmmEnterDiningRoomChimney(NodeProp *, ActorMarker *);
extern void warp_mmmEnterWellTop(NodeProp *, ActorMarker *);
extern void warp_mmmEnterTumblarShed(NodeProp *, ActorMarker *);
extern void func_8031DAE0(NodeProp *, ActorMarker *);
extern void warp_mmmEnterChurchSecretRoom(NodeProp *, ActorMarker *);
extern void func_8031DC10(NodeProp *, ActorMarker *);
extern void warp_mmmEnterRainBarrelBottom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterCellar(NodeProp *, ActorMarker *);
extern void warp_mmmEnterRedFeatherRoom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterBlueEggRoom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterNoteRoom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterBrokenFloorboardRoom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterBedroom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterBathroomWindow(NodeProp *, ActorMarker *);
extern void warp_mmmExitDiningRoomDoor(NodeProp *, ActorMarker *);
extern void func_8031D820(NodeProp *, ActorMarker *);
extern void warp_mmmExitWellTop(NodeProp *, ActorMarker *);
extern void warp_mmmExitTumblarShed(NodeProp *, ActorMarker *);
extern void warp_mmmExitChurchFrontDoor(NodeProp *, ActorMarker *);
extern void warp_mmmExitChurchSecretRoom(NodeProp *, ActorMarker *);
extern void func_8031D8D4(NodeProp *, ActorMarker *);
extern void warp_mmmExitRainBarrelBottom(NodeProp *, ActorMarker *);
extern void warp_mmmExitCellar(NodeProp *, ActorMarker *);
extern void warp_mmmExitRedFeatherRoom(NodeProp *, ActorMarker *);
extern void warp_mmmExitBlueEggRoom(NodeProp *, ActorMarker *);
extern void warp_mmmExitBathroomWindow(NodeProp *, ActorMarker *);
extern void warp_mmmExitBrokenFloorboardRoom(NodeProp *, ActorMarker *);
extern void warp_mmmExitBedroom(NodeProp *, ActorMarker *);
extern void warp_mmmExitNoteRoom(NodeProp *, ActorMarker *);
extern void warp_mmmChurchTowerUp(NodeProp *, ActorMarker *);
extern void warp_mmmChurchTowerDown(NodeProp *, ActorMarker *);
extern void warp_mmmExitMumbosHut(NodeProp *, ActorMarker *);
extern void warp_mmmEnterMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ccExitWonderwingRoom(NodeProp *, ActorMarker *);
extern void warp_ccEnterClankerBelly(NodeProp *, ActorMarker *);
extern void warp_ccEnterClankerMouth(NodeProp *, ActorMarker *);
extern void warp_ccEnterWonderwingRoom(NodeProp *, ActorMarker *);
extern void warp_mmEnterLevel(NodeProp *, ActorMarker *);
extern void warp_rbbEnterCaptainsRoomWindow(NodeProp *, ActorMarker *);
extern void warp_rbbEnterCabinRoomWindow(NodeProp *, ActorMarker *);
extern void warp_rbbEnterEngineRoomPipe(NodeProp *, ActorMarker *);
extern void warp_rbbEnterKitchenPipe(NodeProp *, ActorMarker *);
extern void warp_rbbEnterNavigationRoomWindow(NodeProp *, ActorMarker *);
extern void warp_rbbEnterBoomBoxPipe(NodeProp *, ActorMarker *);
extern void warp_rbbEnterEngineRoomDoor(NodeProp *, ActorMarker *);
extern void warp_rbbEnterChumpWarehouseWindow(NodeProp *, ActorMarker *);
extern void warp_rbbEnterBoatRoom(NodeProp *, ActorMarker *);
extern void warp_rbbEnterChompaContainer(NodeProp *, ActorMarker *);
extern void warp_rbbEnterSeamanGrublinContainer(NodeProp *, ActorMarker *);
extern void warp_rbbEnterBoomBoxContainer(NodeProp *, ActorMarker *);
extern void warp_rbbExitCaptainsRoomWindow(NodeProp *, ActorMarker *);
extern void warp_rbbExitCabinRoomWindow(NodeProp *, ActorMarker *);
extern void warp_rbbExitEngineRoomPipe(NodeProp *, ActorMarker *);
extern void warp_rbbExitKitchenPipe(NodeProp *, ActorMarker *);
extern void warp_rbbExitNavigationRoomWindow(NodeProp *, ActorMarker *);
extern void warp_rbbExitBoomBoxPipe(NodeProp *, ActorMarker *);
extern void warp_rbbExitEngineRoomDoor(NodeProp *, ActorMarker *);
extern void warp_rbbExitBoatRoom(NodeProp *, ActorMarker *);
extern void warp_rbbExitChompaContainer(NodeProp *, ActorMarker *);
extern void warp_rbbExitSeamanGrublinContainer(NodeProp *, ActorMarker *);
extern void warp_rbbExitBoomBoxContainer(NodeProp *, ActorMarker *);
extern void warp_rbbExitBossBoomBoxRoom(NodeProp *, ActorMarker *);
extern void warp_rbbEnterBossBoomBoxRoom(NodeProp *, ActorMarker *);
extern void warp_rbbEnterChumpWarehouseDoor(NodeProp *, ActorMarker *);
extern void warp_rbbExitChumpWarehouseDoor(NodeProp *, ActorMarker *);
extern void func_8031E308(NodeProp *, ActorMarker *);
extern void func_8031E32C(NodeProp *, ActorMarker *);
extern void func_8031E350(NodeProp *, ActorMarker *);
extern void func_8031E374(NodeProp *, ActorMarker *);
extern void func_8031E398(NodeProp *, ActorMarker *);
extern void func_8031E3BC(NodeProp *, ActorMarker *);
extern void func_8031E3E0(NodeProp *, ActorMarker *);
extern void func_8031E404(NodeProp *, ActorMarker *);
extern void func_8031E428(NodeProp *, ActorMarker *);
extern void func_8031E44C(NodeProp *, ActorMarker *);
extern void func_8031E470(NodeProp *, ActorMarker *);
extern void func_8031E494(NodeProp *, ActorMarker *);
extern void func_8031E4B8(NodeProp *, ActorMarker *);
extern void func_8031E4DC(NodeProp *, ActorMarker *);
extern void func_8031E500(NodeProp *, ActorMarker *);
extern void func_8031E524(NodeProp *, ActorMarker *);
extern void func_8031E548(NodeProp *, ActorMarker *);
extern void func_8031E56C(NodeProp *, ActorMarker *);
extern void func_8031E590(NodeProp *, ActorMarker *);
extern void func_8031E5B4(NodeProp *, ActorMarker *);
extern void func_8031E5D8(NodeProp *, ActorMarker *);
extern void func_8031E5FC(NodeProp *, ActorMarker *);
extern void func_8031E620(NodeProp *, ActorMarker *);
extern void func_8031E644(NodeProp *, ActorMarker *);
extern void func_8031E668(NodeProp *, ActorMarker *);
extern void func_8031E68C(NodeProp *, ActorMarker *);
extern void func_8031E6B0(NodeProp *, ActorMarker *);
extern void warp_ccwExitWinterToHub(NodeProp *, ActorMarker *);
extern void warp_ccwExitSpringToHub(NodeProp *, ActorMarker *);
extern void warp_ccwExitSummerToHub(NodeProp *, ActorMarker *);
extern void warp_ccwExitAutumnToHub(NodeProp *, ActorMarker *);
extern void warp_ccwEnterWinter(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSpring(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSummer(NodeProp *, ActorMarker *);
extern void warp_ccwEnterAutumn(NodeProp *, ActorMarker *);
extern void warp_gvExitSandybuttMazeBack(NodeProp *, ActorMarker *);
extern void warp_ttcExitSpringMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcExitSummerMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcExitAutumnMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcExitWinterMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcEnterSpringMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcEnterSummerMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcEnterAutumnMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ttcEnterWinterMumbosHut(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSpringNabnutDoor(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSummerNabnutDoor(NodeProp *, ActorMarker *);
extern void warp_ccwEnterAutumnNabnutDoor(NodeProp *, ActorMarker *);
extern void warp_ccwExitSpringNabnutDoor(NodeProp *, ActorMarker *);
extern void warp_ccwExitSummerNabnutDoor(NodeProp *, ActorMarker *);
extern void warp_ccwExitAutumnNabnutDoor(NodeProp *, ActorMarker *);
extern void warp_ccwExitWinterNabnutDoor(NodeProp *, ActorMarker *);
extern void func_8031F0F4(NodeProp *, ActorMarker *);
extern void func_8031F118(NodeProp *, ActorMarker *);
extern void warp_lairEnterGVPuzzleRoomFromMMMLobby(NodeProp *, ActorMarker *);
extern void warp_ttcExitSharkfoodIsland(NodeProp *, ActorMarker *);
extern void warp_lairEnterRBBLobbyFromRBBLevel(NodeProp *, ActorMarker *);
extern void warp_lairEnterBGSLobbyFromBGSLevel(NodeProp *, ActorMarker *);
extern void warp_fpExitWozzasCave(NodeProp *, ActorMarker *);
extern void warp_fpEnterWozzasCave(NodeProp *, ActorMarker *);
extern void warp_lairEnterCryptFromMMMLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterMMMLobbyFromCrypt(NodeProp *, ActorMarker *);
extern void warp_lairEnterPointingGruntyStatueFromBGSLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterBGSLobbyFromPointingGruntyStatueRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterMMMLobbyFromGVPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnterGVPuzzleRoomFromFPLobby(NodeProp *, ActorMarker *);
extern void warp_lairFPLobbyFromGVPuzzleRoom(NodeProp *, ActorMarker *);
extern void warp_lairEnter640NoteDoorRoomFromFPLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnter640NoteDoorRoomFromCCWLobbyTokenEntrance(NodeProp *, ActorMarker *);
extern void warp_lairEnter640NoteDoorRoomFromCCWLobbyDoorEntrance(NodeProp *, ActorMarker *);
extern void warp_lairEnter640NoteDoorRoomFromRBBLobby(NodeProp *, ActorMarker *);
extern void warp_lairRBBLobbyFrom640NoteDoorRoom(NodeProp *, ActorMarker *);
extern void warp_lairCCWLobbyFrom640NoteDoorRoomDoorEntrance(NodeProp *, ActorMarker *);
extern void warp_lairCCWLobbyFrom640NoteDoorRoomTokenEntrance(NodeProp *, ActorMarker *);
extern void warp_lairEnterFPLobbyFrom640NoteDoorRoom(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSpringZubbaHive(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSummerZubbaHive(NodeProp *, ActorMarker *);
extern void warp_ccwEnterAutumnZubbaHive(NodeProp *, ActorMarker *);
extern void warp_ccwExitSpringZubbaHive(NodeProp *, ActorMarker *);
extern void warp_ccwExitSummerZubbaHive(NodeProp *, ActorMarker *);
extern void warp_ccwExitAutumnZubbaHive(NodeProp *, ActorMarker *);
extern void warp_lairEnterMMMPuzzleFromRBBLobby(NodeProp *, ActorMarker *);
extern void warp_lairEnterRBBPuzzleFromRBBLobby(NodeProp *, ActorMarker *);
extern void func_8031FB6C(NodeProp *, ActorMarker *);
extern void warp_lairEnterCCWLobbyFromFurnaceFunPath(NodeProp *, ActorMarker *);
extern void warp_lairEnterFurnaceFunPathFromCCWLobby(NodeProp *, ActorMarker *);
extern void warp_smEnterBanjosHouse(NodeProp *, ActorMarker *);
extern void warp_smExitBanjosHouse(NodeProp *, ActorMarker *);
extern void warp_lairEnterMMLobbyFromSMLevel(NodeProp *, ActorMarker *);
extern void warp_smExitLair(NodeProp *, ActorMarker *);
extern void warp_rbbExitAnchorRoom(NodeProp *, ActorMarker *);
extern void warp_rbbEnterAnchorRoom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterWellBottom(NodeProp *, ActorMarker *);
extern void warp_mmmExitWellBottom(NodeProp *, ActorMarker *);
extern void warp_mmmEnterBathroomFromLoggo(NodeProp *, ActorMarker *);
extern void warp_mmmEnterLoggo(NodeProp *, ActorMarker *);
extern void warp_ccwEnterLevel(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSpringNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwEnterSummerNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwEnterAutumnNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwEnterWinterNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwExitSpringNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwExitSummerNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwExitAutumnNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_ccwExitWinterNabnutWindow(NodeProp *, ActorMarker *);
extern void warp_gvEnterSNSChamper(NodeProp *, ActorMarker *);
extern void warp_gvExitSNSChamper(NodeProp *, ActorMarker *);
extern void warp_lairEnterLairFromSMLevel(NodeProp *, ActorMarker *);

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
void (*sWarpFunctions[])(NodeProp *, ActorMarker *) = {
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

    switch(codeA5BC0_getNodePropBit6(arg0)) {
        case 3: // warp (L80334480)
            global_timer_time = globalTimer_getTime();
            if ((codeA5BC0_getNodePropUnkC(arg0) + 1) != global_timer_time) {
                ((CodeAD110Callback) sWarpFunctions[codeA5BC0_getNodePropUnk8(arg0)])(arg0, arg1);
            }
            codeA5BC0_setNodePropUnkC(arg0, global_timer_time);
            break;

        case 4: // radius trigger like camera (L803344E0)
            sRadiusTriggers[codeA5BC0_getNodePropUnk8(arg0)](arg0, arg1);
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
