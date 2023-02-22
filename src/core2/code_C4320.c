#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802E40A8(enum map_e, s32 exit);

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
}Struct_core2_C4320_0;

s32 func_8034BAFC(void);

/* .data*/
//EAF70:
extern Struct_core2_C4320_0 D_80371F00[] ={
    {MAP_2_MM_MUMBOS_MOUNTAIN,    4, 0x5B, 1, 2, 2}, 
    {MAP_22_CC_INSIDE_CLANKER,    7, 0x5B, 1, 2, 2},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP, 4, 0x5B, 1, 3, 3},
    {MAP_1C_MMM_CHURCH,           7, 0x5B, 1, 2, 2},
    {MAP_1F_CS_START_RAREWARE,    1, 0x00, 1, 2, 2},
    {MAP_6_TTC_NIPPERS_SHELL,     4, 0x5B, 1, 2, 2},
    {MAP_46_CCW_WINTER,           7, 0x5B, 1, 2, 2},
    {MAP_34_RBB_ENGINE_ROOM,      4, 0x5B, 1, 2, 2},
    {MAP_12_GV_GOBIS_VALLEY,      7, 0x5B, 1, 2, 2},
    {MAP_1F_CS_START_RAREWARE,    1, 0x00, 1, 2, 2},
    {MAP_91_FILE_SELECT,          0, 0x00, 1, 2, 2}
};

extern Struct_core2_C4320_0 D_80371F44[] = {
    {MAP_8C_SM_BANJOS_HOUSE,            0, 0x5C, 0xA, 3, 3,},
    {MAP_41_FP_BOGGYS_IGLOO,            0, 0x5C, 0xA, 3, 3,},
    {MAP_3F_RBB_CAPTAINS_CABIN,         0, 0x5C, 0xA, 3, 3,},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE,   0, 0x5C, 0xA, 3, 3,},
    {MAP_11_BGS_TIPTUP,                 0, 0x5C, 0xA, 3, 3,},
    {MAP_2D_MMM_BEDROOM,                0, 0x5C, 0xA, 3, 3,},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,      0, 0x5C, 0xA, 3, 3,}
};

extern Struct_core2_C4320_0 D_80371F70 = {MAP_41_FP_BOGGYS_IGLOO, 6, 0x5D, 7, 8, 3};

extern Struct_core2_C4320_0 D_80371F78[] ={
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0, 0x5F, 6, 9, 9},
    {MAP_27_FP_FREEZEEZY_PEAK,      0, 0x5F, 9, 9, 9},
    {MAP_12_GV_GOBIS_VALLEY,        0, 0x5F, 9, 5, 9}
};

extern s32 D_80371F8C = 0xA; //attract demo count
extern s32 D_80371F90 = 0x7; //bottles bonus demo count
extern s32 D_80371F94 = 1;
extern s32 D_80371F98 = 3;
extern s32 D_80371F9C = 1;
extern u16 D_80371FA0[] = { 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC };
//EB030:

/* .bss */
s32 D_80386110;                   //current attract demo index
Struct_core2_C4320_0 *D_80386114; //current attract demo ptr
s32 D_80386118;
s32 D_8038611C;
bool D_80386120;
s32 D_80386124;
f32 D_80386128;

/* .code */
void func_8034B2B0(s32 arg0) {
    Struct_core2_C4320_0 *sp18;

    sp18 = &D_80371F00[arg0];
    func_802E40A8(sp18->unk0, sp18->unk2);
    if ((map_getLevel(sp18->unk0) == LEVEL_D_CUTSCENE) || (arg0 == D_80371F8C)) {
        func_802E40C4(1);
    } else {
        func_802E40C4(6);
    }
    func_802E40E8(1);
}

void func_8034B33C(s32 arg0) {
    Struct_core2_C4320_0 *sp18;

    sp18 = &D_80371F44[arg0];
    func_802E40A8(sp18->unk0, sp18->unk2);
    func_802E412C(1, 0xB);
    func_802E40C4(7);
    D_80386114 = sp18;
    D_80386124 = func_802C5A30();
}

void func_8034B3A4(enum map_e map_id, s32 exit_id) {
    func_802E40A8(map_id, exit_id);
    func_802E412C(1, 8);
    func_802E40C4(8);
    D_80386114 = &D_80371F70;
    D_80386124 = func_802C5A30();
}


void func_8034B3F0(s32 arg0) {
    Struct_core2_C4320_0 *temp_s0;

    temp_s0 = &D_80371F78[arg0];
    func_802E40A8(temp_s0->unk0, temp_s0->unk2);
    if (temp_s0 == &D_80371F78[0]) {
        func_802E412C(1, 5);
    } else {
        func_802E40E8(0);
    }
    func_802E40C4(0xC);
    D_80386114 = temp_s0;
    D_80386124 = func_802C5A30();
}


void func_8034B474(void) {
    D_80386114 = &D_80371F00[D_80386110];
    D_80386110 = (D_80386110 + 1) % D_80371F8C;
}

void func_8034B4E4(s32 arg0){
    D_80386128 = 0;
    if(getGameMode() == GAME_MODE_8_BOTTLES_BONUS || getGameMode() == GAME_MODE_A_SNS_PICTURE){
        return;
    }

    switch(arg0){
        case 1: //L8034B544
        case 3: //L8034B544
        case 4: //L8034B544
            func_802DC9A4(0,0);
            /* fall-through */
        case 2: //L8034B550
        case 7: //L8034B550
            chOverlayCopyright_spawn(0,0);
            break;

        case 5: //L8034B564
            func_802DC9A4(0,0);
            break;
    }
}

void func_8034B580(s32 arg0) {
    f32 sp1C;

    sp1C = D_80386128;
    if (gctransition_8030BD98() != 0) {
        D_80386128 += time_getDelta();
    }
    if ((getGameMode() != GAME_MODE_8_BOTTLES_BONUS) && (getGameMode() != GAME_MODE_A_SNS_PICTURE)) {
        switch (arg0) {
        case 4:
            if ((D_80386128 >= 2.5) && (sp1C < 2.5) && (D_80371F9C == 0)) {
                chOverlayCopyright_func_802DCB0C(0, 0);
            }
            /* fallthrough */
        case 3:
            if ((D_80386128 >= 2.5) && (sp1C < 2.5) && (D_80371F9C == 0)) {
                func_802DC9DC(0, 0);
            }
            if ((D_80386128 >= 4.0) && (sp1C < 4.0) && !pfsManager_contErr()) {
                chOverlayPressStart_spawn(0, 0);
                if (D_80371F9C != 0) {
                    chOverlayPressStart_func_802DCDB0();
                    return;
                }
            }
            break;
        case 7:
            if ((D_80386128 >= 2.5) && (sp1C < 2.5)) {
                chOverlayCopyright_func_802DCB0C(0, 0);
            }
            if ((D_80386128 >= 4.0) && (sp1C < 4.0) && !pfsManager_contErr()) {
                chOverlayPressStart_spawn(0, 0);
            }
            break;
        }
    }
}

void func_8034B7F0(s32 arg0) {
    func_802DC9DC(0, 0);
    chOverlayCopyright_func_802DCB0C(0, 0);
    chOverlayPressStart_func_802DCDC0(0, 0);
    D_80371F9C = 0;
}

void func_8034B834(void) {
    s32 i;

    item_set(ITEM_D_EGGS, 100);
    item_set(ITEM_F_RED_FEATHER, 50);
    item_set(ITEM_10_GOLD_FEATHER, 10);
    item_set(ITEM_1C_MUMBO_TOKEN, 25);
    ability_setAllLearned(-1);
    ability_setAllUsed(-1);
    for(i = 0; i < 10; i++){
        fileProgressFlag_set(D_80371FA0[i], 1);
    }
}

void func_8034B8C0(enum map_e map_id, s32 demo_id) {
    demo_load(map_id,demo_id);
    D_80386118 = D_8038611C = 0;
    if (D_80386114->unk1 == 6) {
        func_803204E4(0x1F, 1);
        func_802E4A70();
    }
    if ((demo_id == 0x5B) || (demo_id == 0x5F)) {
        sns_backup_items_and_unlock_all();
    }
}

void func_8034B940(void){
    demo_free();
    sns_restore_backed_up_items();
}

void func_8034B968(void){
    func_8034B2B0(D_80386110);
    func_8034B474();
}

void func_8034B994(void){
    func_8034B2B0(D_80371F8C);
    D_80386110 = 0;
}

void func_8034B9BC(s32 arg0) {
    func_80347A7C();
    func_8034B33C(arg0);
}

void func_8034B9E4(void){
    func_803219F4(5);
    func_8034B3F0(D_80386110);
    D_80386110++;
}

void func_8034BA20(void) {
    func_803219F4(5);
    func_802E412C(1, 5);
    func_802E40A8(MAP_97_CS_END_BEACH_2, 0);
    func_802E40C4(1);
    if (func_8025AD7C(5)) {
        func_8025A7DC(5);
    }
    D_80386110 = 0;
}

void func_8034BA7C(enum map_e map_id, s32 exit_id){
    func_8034B3A4(map_id, exit_id);
}

void func_8034BA9C(void) {
    if (func_8034BAFC() != -1) {
        func_802C5A3C(func_8034BAFC());
        gameFile_load(func_8034BAFC());
        func_80347AA8();
    }
    func_8031B010();
    D_80386110 = 0;
}

s32 func_8034BAFC(void){
    return D_80386124;
}

void func_8034BB08(bool arg0) {
    D_80386120 = arg0;
    func_802E412C(1, 3);
    func_802E40A8(MAP_8C_SM_BANJOS_HOUSE, 2);
    func_802E40C4(1);
}

bool func_8034BB48(void) {
    if (D_80386120 && gctransition_8030BD98()) {
        D_80386120 = FALSE;
        return TRUE;
    }
    return FALSE;
}

void func_8034BB90(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = gctransition_8030BDC0();
    sp18 = gctransition_8030BD98();
    if (!D_80386118) {
        func_8034B834();
        func_8034B4E4(D_80386114->unk1);
        D_80386118 = 1;
    }
    func_8034B580(D_80386114->unk1);
    if (func_803203FC(0xC3)) {
        func_803204E4(0xC3, 0);
        func_8034B9E4();
    }
    if( !sp1C 
        && sp18 
        && !D_8038611C 
        && (getGameMode() != GAME_MODE_8_BOTTLES_BONUS) 
        && ((func_803203FC(0x64) && (getGameMode() != GAME_MODE_A_SNS_PICTURE)) 
        || func_803203FC(0x63))
    ) {
        func_8034B7F0(D_80386114->unk1);
        if (getGameMode() == GAME_MODE_9_BANJO_AND_KAZOOIE) {
            func_8034BA9C();
        } else if (getGameMode() == GAME_MODE_A_SNS_PICTURE) {
            if (D_80386110 == D_80371F98) {
                func_8034BA20();
            } else {
                func_802DF0C8();
            }
        } else if (func_803203FC(0x64)) {
            func_802E412C(1, D_80386114->unk5);
            func_8034B994();
        } else {
            func_802E412C(1, D_80386114->unk4);
            func_8034B2B0(D_80386110);
            func_8034B474();
        }
        if (getGameMode() != GAME_MODE_A_SNS_PICTURE) {
            func_8025A58C(0, 800);
            func_8025AB00();
        }
        func_803204E4(0x64, 0);
        func_803204E4(0x63, 0);
        D_8038611C = 1;
    }
}

s32 func_8034BDA4(enum map_e map_id, s32 exit_id) {
    s32 phi_v0;

    if (func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) {
        return D_80371F70.unk3;
    }


    for(phi_v0 = 0; phi_v0 < D_80371F8C; phi_v0++){
        if( map_id == D_80371F00[phi_v0].unk0 && exit_id == D_80371F00[phi_v0].unk2){
            return D_80371F00[phi_v0].unk3;
        }
    }

    for(phi_v0 = 0; phi_v0 < D_80371F90; phi_v0++){
        if( map_id == D_80371F44[phi_v0].unk0 && exit_id == D_80371F44[phi_v0].unk2){
            return D_80371F44[phi_v0].unk3;
        }
    }

    for(phi_v0 = 0; phi_v0 < D_80371F98; phi_v0++){
        if( map_id == D_80371F78[phi_v0].unk0 && exit_id == D_80371F78[phi_v0].unk2){
            return D_80371F78[phi_v0].unk3;
        }
    }

    return 4;
}
