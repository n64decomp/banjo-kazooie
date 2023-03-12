#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80294404(void);

/* .data */
s16 D_80364580[] = {
    MAP_7_TTC_TREASURE_TROVE_COVE,
    MAP_2_MM_MUMBOS_MOUNTAIN,
    MAP_1B_MMM_MAD_MONSTER_MANSION,
    MAP_B_CC_CLANKERS_CAVERN,
    MAP_21_CC_WITCH_SWITCH_ROOM,
    MAP_22_CC_INSIDE_CLANKER,
    MAP_23_CC_GOLDFEATHER_ROOM,
    MAP_28_MMM_EGG_ROOM,
    MAP_29_MMM_NOTE_ROOM,
    MAP_2A_MMM_FEATHER_ROOM,
    MAP_2C_MMM_BATHROOM,
    MAP_2D_MMM_BEDROOM,
    MAP_2E_MMM_HONEYCOMB_ROOM,
    MAP_2B_MMM_SECRET_CHURCH_ROOM,
    MAP_26_MMM_NAPPERS_ROOM,
    MAP_1C_MMM_CHURCH,
    MAP_1D_MMM_CELLAR,
    MAP_31_RBB_RUSTY_BUCKET_BAY,
    MAP_34_RBB_ENGINE_ROOM,
    MAP_35_RBB_WAREHOUSE,
    MAP_36_RBB_BOATHOUSE,
    MAP_3A_RBB_BOSS_BOOM_BOX,
    MAP_37_RBB_CONTAINER_1,
    MAP_3E_RBB_CONTAINER_2,
    MAP_38_RBB_CONTAINER_3,
    MAP_39_RBB_CREW_CABIN,
    MAP_3F_RBB_CAPTAINS_CABIN,
    MAP_3B_RBB_STORAGE_ROOM,
    MAP_3C_RBB_KITCHEN,
    MAP_3D_RBB_NAVIGATION_ROOM,
    MAP_8B_RBB_ANCHOR_ROOM,
    MAP_43_CCW_SPRING,
    MAP_44_CCW_SUMMER,
    MAP_45_CCW_AUTUMN,
    MAP_46_CCW_WINTER,
    MAP_5A_CCW_SUMMER_ZUBBA_HIVE,
    MAP_5B_CCW_SPRING_ZUBBA_HIVE,
    MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,
    MAP_5E_CCW_SPRING_NABNUTS_HOUSE,
    MAP_5F_CCW_SUMMER_NABNUTS_HOUSE,
    MAP_60_CCW_AUTUMN_NABNUTS_HOUSE,
    MAP_61_CCW_WINTER_NABNUTS_HOUSE,
    MAP_62_CCW_WINTER_HONEYCOMB_ROOM,
    MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY,
    MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY,
    MAP_65_CCW_SPRING_WHIPCRACK_ROOM,
    MAP_66_CCW_SUMMER_WHIPCRACK_ROOM,
    MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM,
    MAP_68_CCW_WINTER_WHIPCRACK_ROOM,
    MAP_11_BGS_TIPTUP,
    MAP_10_BGS_MR_VILE,
    MAP_C_MM_TICKERS_TOWER,
    MAP_8F_TTC_SHARKFOOD_ISLAND,
    MAP_8D_MMM_INSIDE_LOGGO,
    MAP_69_GL_MM_LOBBY,
    MAP_6A_GL_TTC_AND_CC_PUZZLE,
    MAP_6B_GL_180_NOTE_DOOR,
    MAP_6C_GL_RED_CAULDRON_ROOM,
    MAP_6D_GL_TTC_LOBBY,
    MAP_70_GL_CC_LOBBY,
    MAP_71_GL_STATUE_ROOM,
    MAP_72_GL_BGS_LOBBY,
    MAP_6E_GL_GV_LOBBY,
    MAP_6F_GL_FP_LOBBY,
    MAP_74_GL_GV_PUZZLE,
    MAP_75_GL_MMM_LOBBY,
    MAP_7A_GL_CRYPT,
    MAP_76_GL_640_NOTE_DOOR,
    MAP_77_GL_RBB_LOBBY,
    MAP_78_GL_RBB_AND_MMM_PUZZLE,
    MAP_79_GL_CCW_LOBBY,
    MAP_80_GL_FF_ENTRANCE,
    MAP_90_GL_BATTLEMENTS,
    MAP_93_GL_DINGPOT,
    MAP_92_GV_SNS_CHAMBER,
    MAP_8C_SM_BANJOS_HOUSE,
    0
};

/*.bss*/
struct {
    u8 unk0;
    f32 unk4[3]; 
}
D_8037C6F0;

/*.code */
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12F30/func_80299EC0.s")
#else
void func_80299EC0(f32 arg0[3]) {
    f32 spEC[3]; //player_pos
    f32 spE0[3];
    f32 spD4[3];
    BKModelBin *spC8;
    f32 spB8[3];
    f32 spAC[3];
    f32 spA0[3];
    f32 sp7C[3][3]; //tri_vtx_colors
    s32 sp78;
    s32 i;
    f32 sp70;
    BKCollisionTri *sp6C; //floor_vtx_list
    f32 sp48[3][3]; //tri_vtx_coord
    f32 temp_f0_2;
    f32 temp_f2_2;
    f32 temp_f2_4;
    Vtx *vtx_buffer;
    Vtx *temp_v1;
    f32 phi_f18;


    arg0[0] = 255.0f;\
    arg0[1] = 255.0f;\
    arg0[2] = 255.0f;
    if (D_8037C6F0.unk0 == 1) {
        sp78 = 50;
    } else if (func_8028EE84() == BSWATERGROUP_0_NONE) {
        sp78 = 200;
    } else {
        sp78 = 250;
    }
    _player_getPosition(spEC);
    sp6C = func_8029463C();
    spC8 = func_802946A8();
    if (spC8 == NULL) {
        sp6C = NULL;
    }
    if ((spEC[1] - func_80294438()) > 100.0f) {
        sp6C = NULL;
    }
    if (sp6C == NULL) return;
    if (sp6C->unk6 &2) return;

    vtx_buffer = vtxList_getVertices(model_getVtxList(spC8));
    for(i = 0; i<3; i++){
        temp_v1 =  vtx_buffer + sp6C->unk0[i];
        sp48[i][0] = (f32) temp_v1->v.ob[0];
        sp48[i][1] = (f32) temp_v1->v.ob[1];
        sp48[i][2] = (f32) temp_v1->v.ob[2];
        sp48[i][1] = 0.0f;

        sp7C[i][0] = (f32) temp_v1->v.cn[0];
        sp7C[i][1] = (f32) temp_v1->v.cn[1];
        sp7C[i][2] = (f32) temp_v1->v.cn[2];
    }
    // spEC[1] = 0.0f;

    spE0[0] = spEC[0] - sp48[0][0];
    spE0[2] = spEC[2] - sp48[0][2];
    spE0[1] = 0.0f;

    spAC[0] = sp48[0][0] - sp48[1][0];
    spAC[2] = sp48[0][2] - sp48[1][2];
    spAC[1] = 0.0f;

    spB8[0] = -(sp48[2][2] - sp48[1][2]);
    spB8[2] = sp48[2][0] - sp48[1][0];
    spB8[1] = 0.0f;

    phi_f18 =  (spE0[0] * spB8[0]) + (spE0[1] * spB8[1]) + (spB8[2] * spE0[2]);
    phi_f18 = (phi_f18 == 0.0f)? 0.1f : phi_f18;

    temp_f0_2 = -((spB8[2] * spAC[2]) + ((spAC[0] * spB8[0]) + 0.0f)) / phi_f18;
    spA0[0] = (spE0[0] * temp_f0_2) + sp48[0][0];
    spA0[1] = 0.0f;
    spA0[2] = (spE0[2] * temp_f0_2) + sp48[0][2];

    spD4[0] = spA0[0] - sp48[1][0];
    spD4[1] = spA0[1] - sp48[1][1];
    spD4[2] = spA0[2] - sp48[1][2];

    temp_f2_2 = gu_sqrtf(spD4[0]*spD4[0] + spD4[1]*spD4[1] + spD4[2]*spD4[2]) / (gu_sqrtf(spB8[0] * spB8[0] + spB8[1] * spB8[1] + spB8[2] * spB8[2]) + 0.01);
    for(i = 0; i < 3; i++){
        arg0[i] = sp7C[1][i] + (sp7C[2][i] - sp7C[1][i])*temp_f2_2;
    }

    spD4[0] = spA0[0] - sp48[0][0];
    spD4[1] = spA0[1] - sp48[0][1];
    spD4[2] = spA0[2] - sp48[0][2];
    temp_f2_4 = (1.0 - (gu_sqrtf(spE0[0]*spE0[0] + spE0[1]*spE0[1] + spE0[2]*spE0[2]) / (gu_sqrtf(spD4[0]*spD4[0] + spD4[1]*spD4[1] + spD4[2]*spD4[2]) + 0.01)));

    for(i = 0; i < 3; i++){
        arg0[i] += (sp7C[0][i] - arg0[i])*temp_f2_4;
    }

    for(i = 0; i < 3; i++){
        arg0[i] += (255.0f - arg0[i]) * (func_80294404() / 100.0f);
    }

    for(i = 0; i < 3; i++){
        if(arg0[i] > 255.0f){ arg0[i] = 255.0f; }
        if(arg0[i] < 0.0f) {  arg0[i] = 0.0f; }
    }
    arg0[0] = ((arg0[0] + arg0[1] + arg0[2]) * (f32) (0xFF - sp78)) / 765.0f + sp78;
    arg0[1] = arg0[0];
    arg0[2] = arg0[0];
}
#endif

void func_8029A47C(s32 arg0[3]){
    arg0[0] = (s32)(D_8037C6F0.unk4[0] + 0.5);
    arg0[1] = (s32)(D_8037C6F0.unk4[1] + 0.5);
    arg0[2] = (s32)(D_8037C6F0.unk4[2] + 0.5);
}

void func_8029A4D0(void){
    int i;
    s32 map_id = map_get();
    D_8037C6F0.unk0 = 0;
    D_8037C6F0.unk4[0] = 255.0f;
    D_8037C6F0.unk4[1] = 255.0f;
    D_8037C6F0.unk4[2] = 255.0f;
    for(i = 0; D_80364580[i] != 0; i++){
        if(map_id == D_80364580[i]){
            D_8037C6F0.unk0 = 1;
            break;
        }
    }
}

void func_8029A54C(void){}

void func_8029A554(void){
    int i;
    f32 sp28[3];
    func_80299EC0(sp28);
    for(i = 0; i < 3; i++){
        if(D_8037C6F0.unk4[i] < sp28[i]){
            D_8037C6F0.unk4[i] += 40.0f;
            if(sp28[i] < D_8037C6F0.unk4[i])
                D_8037C6F0.unk4[i] = sp28[i];

        }
        else{//L8029A5C0
            D_8037C6F0.unk4[i] -= 40.0f;
            if( D_8037C6F0.unk4[i] < sp28[i])
                 D_8037C6F0.unk4[i] = sp28[i];
        }
    }
}
