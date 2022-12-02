#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"

extern void func_8024C510(f32);
extern void func_8024CDF8(f32, f32, f32);
extern void func_8024CE40(f32, f32, f32);
extern void func_8024CE60(f32, f32);
extern void func_802F5374(void);
extern void func_802FA0F8(void);
extern void timedFuncQueue_update(void);
extern void func_80335128(s32);
extern void func_8025A2B0(void);
extern void func_8025A430(s32, s32, s32);
extern void func_80335110(s32);
extern void func_8034BB90(void);
extern void func_8030C27C(void);
extern void func_80321C34(void);
extern void func_8030ED0C(void);
extern void func_80259BD0(void);

enum transition_e {
    TRANSITION_0_NONE,

};

void func_802E3BD0(s32 frame_buffer_indx);
void func_802E40A8(s32 map, s32 exit);
void func_802E40C4( s32 arg0);
void func_802E40D0(s32 map, s32 exit);
void func_802E40E8(s32 transition);
int  func_802E4A08(void);

f32 func_8033DC20(void);
void func_8033DC9C(f32);
extern void func_80324C58(void);

/* .data */
s16 D_803687F0[] = {
    0x159A, 0x02BC, 0x21C8, 0x00C8, 0x14ED, 0x03A2, 0x1951, 0x0003,
    '**', ' B', 'AN', 'JO', ' K', 'AZ', 'OO', 'IE',
    ' (', 'c)', ' R', 'AR', 'E ', 'Lt', 'd ', '19',
    '98', ' *', '*\0',   0,    0,    0,    0,    0,
 
};

/* .bss */
struct{
    s32 unk0;
    s32 game_mode; //game_mode
    f32 unk8; 
    s32 unkC; //freeze_scene_flag (used for pause menu)
    f32 unk10;
    u8 transition;
    u8 map;
    u8 exit;
    u8 unk17; //reset_on_map_load
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_8037E8E0;

void func_802E3800(void){
    func_8024CDF8(0.0f, 0.0f, 0.0f);
    func_8024CE40(-30.0f, 30.0f, 0.0f);
    func_8024C510(3000.0f);
    func_8024CFD4();
}

void func_802E3854(void){
    int i;

    func_8033B61C();
    func_80254464();
    for(i = 0; i < 0xF; i++){
        func_802E6820(5);
        modelRender_defrag();
        mapSavestate_defrag_all();
        gctransition_8030B740();
        func_802F542C();
        func_80350E00();
        func_802FA4E0();
        func_8033B5FC();
        timedFuncQueue_defrag();
        func_8025AF38();
    }
}

void func_802E38E8(enum map_e map, s32 exit, s32 reset_on_load){
    if(reset_on_load || level_get() != map_getLevel(map)){
        func_8030AFD8(1);
        func_80321854();
        func_803216D0(map); //load_map_asm
        func_8030AFA0(map);
    }
    else{
        func_8030AFD8(1);
        func_8030AFA0(map);
    }
    func_802FA508();
    func_80334B20(map, exit, 0);
    func_802E3800();
    func_8033DC10();
}

void func_802E398C(s32 arg0) {
    func_80334910();
    func_8030ED0C();
    func_80259BD0();
    if (arg0 != 0) {
        func_802E3854();
    }
}

void func_802E39D0(Gfx **gdl, Mtx **mptr, Vtx **vptr, s32 arg3, s32 arg4){
    Mtx* m_start = *mptr; 
    Vtx* v_start = *vptr;

    func_802539AC(gdl, arg3);
    D_8037E8E0.unkC = FALSE;
    func_80334540(gdl, mptr, vptr);
    if(!arg4){
        func_802E67AC();
        func_802E3BD0(func_8024BDA0());
        func_802E67C4();
        func_802E5F10(gdl);
    }
    if( D_8037E8E0.game_mode == GAME_MODE_A_SNS_PICTURE
        && D_8037E8E0.unk19 != 6
        && D_8037E8E0.unk19 != 5
    ){
        gctransition_draw(gdl, mptr, vptr);
    }
    
    if( D_8037E8E0.game_mode == GAME_MODE_8_BOTTLES_BONUS
        || D_8037E8E0.game_mode == GAME_MODE_A_SNS_PICTURE
    ){
        func_8030C2D4(gdl, mptr, vptr);
    }

    if(!func_802E49F0() && func_80335134()){
        func_8032D474(gdl, mptr, vptr);
    }

    gcpausemenu_draw(gdl, mptr, vptr);
    if(!func_802E49F0()){
        func_8025AFC0(gdl, mptr, vptr);
    }

    gcdialog_draw(gdl, mptr, vptr);
    if(!func_802E49F0()){
        func_802FAB54(gdl, mptr, vptr);
    }

    printbuffer_draw(gdl, mptr, vptr);

    if( D_8037E8E0.game_mode != GAME_MODE_A_SNS_PICTURE
        || D_8037E8E0.unk19 == 6
        || D_8037E8E0.unk19 == 5
    ){
        gctransition_draw(gdl, mptr, vptr);
    }
    func_80253DE0(gdl);
    osWritebackDCache(m_start, sizeof(Mtx)*( *mptr - m_start));
    osWritebackDCache(v_start, sizeof(Vtx)*( *vptr - v_start));
}

void func_802E3BD0(s32 frame_buffer_indx){
    func_8024A85C(frame_buffer_indx);
}

void func_802E3BF0(void){
    return;
}

//_set_game_mode
void func_802E3BF8(enum game_mode_e next_mode, s32 arg1){
    s32 prev_mode = D_8037E8E0.game_mode;
    s32 sp20;
    s32 sp1C;

    if( ( ( D_8037E8E0.game_mode == GAME_MODE_3_NORMAL || func_802E4A08())
            && next_mode != GAME_MODE_4_PAUSED
          )
          || ( D_8037E8E0.game_mode == GAME_MODE_4_PAUSED && next_mode != GAME_MODE_3_NORMAL )
        ){
        func_80324C58();
    }

    if(D_8037E8E0.game_mode == GAME_MODE_4_PAUSED && next_mode != GAME_MODE_4_PAUSED ){
        gcpausemenu_free();
    }

    //L802E3C84
    if(next_mode == GAME_MODE_8_BOTTLES_BONUS || next_mode == GAME_MODE_A_SNS_PICTURE){
        func_8030C1A0();
    }
    else{
        func_8030C204();
    }//L802E3CB4

    D_8037E8E0.game_mode = next_mode;

    if(next_mode == 2){
        func_80334E1C(3);
    }
    else if(next_mode == GAME_MODE_3_NORMAL || func_802E4A08()){
        if(prev_mode != GAME_MODE_4_PAUSED) {
            func_80334E1C(2);
        }//L802E3D18
        if(arg1){
            sp20 = FALSE;
            if(next_mode == GAME_MODE_3_NORMAL){
                if(func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)){
                    sp20 = TRUE;
                    sp1C = 7;
                }
                else if(func_8032190C()
                    && level_get() != LEVEL_C_BOSS
                    && level_get() != LEVEL_B_SPIRAL_MOUNTAIN
                    && level_get() != LEVEL_6_LAIR
                    && level_get() != LEVEL_D_CUTSCENE
                ){
                    sp20 = TRUE;
                    sp1C = 1;
                }
            }
            else if(func_802E4A08()){//L802E3DBC
                sp20 = TRUE;
                sp1C = func_8034BDA4(D_8037E8E0.map, D_8037E8E0.exit);
            }

            if(sp20)
                gctransition_8030BEA4(sp1C);
            else
                gctransition_8030BD4C();
        }
        func_80346CA8();
        D_8037E8E0.unk10 = 0.0f; 
    }
    else if(next_mode == GAME_MODE_4_PAUSED){//L802E3E24
        func_80335110(0);
        FUNC_8030E624(SFX_C9_PAUSEMENU_ENTER, 1.1f, 32750);
        func_8024E7C8();
        func_8025A430(0, 2000, 3);
        func_8025A23C(COMUSIC_6F_PAUSE_SCREEN);
        gcpausemenu_init();
    }//L802E3E6C
}

void func_802E3E7C(enum game_mode_e mode){
    s32 sp34;
    s32 sp30;
    s32 map;
    s32 sp28;
    s32 prev_mode;

    func_80254008();
    sp34 = D_8037E8E0.unk18;
    sp30 = D_8037E8E0.unk17;
    map = D_8037E8E0.map;
    sp28 = D_8037E8E0.exit;
    prev_mode = D_8037E8E0.unk0;
    func_802E3BF8(2, 0);
    if(!func_80320454(0x21, 0) || map_getLevel(map_get()) == map_getLevel(D_8037E8E0.map)){
        if(!func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE))
            mapSavestate_save(map_get());
    }
    func_802E398C(1);
    func_802E38E8(map, sp28, sp34);
    mapSavestate_apply(map);
    D_8037E8E0.unk0 = prev_mode;
    func_802E3BF8(mode, sp30);
    func_80332CCC();
    func_80346CA8();
}

s32 func_802E3F80(void){
    return D_8037E8E0.unk0;
}

//game_draw
void func_802E3F8C(s32 arg0){
    Gfx *sp34;
    Gfx *sp30;
    Gfx *sp2C;
    Mtx *sp28;
    Vtx *sp24;
    if(arg0){
        func_80254348();
    }

    func_80254404(&sp34, &sp28, &sp24);
    if(D_8037E8E0.unkC == 1){
        func_80254404(&sp34, &sp28, &sp24);
    }
    sp30 = sp34;
    func_802E39D0(&sp34, &sp28, &sp24, func_8024BDA0(), arg0);
    if(D_8037E8E0.unkC == 0){
        sp2C = sp34;
        func_8024C1DC();
        func_80253EC4(sp30, sp2C);
        if(arg0){
            func_80254348();
        }
    }
}

void func_802E4048(s32 map, s32 exit, s32 transition){
    func_802E40A8(map, exit);
    func_802E40E8(transition);
    func_802E40C4(1);
}

//take me there
extern void func_802E4078(enum map_e map, s32 exit, s32 transition){
    func_802E40D0(map, exit);
    func_802E40E8(transition);
    func_802E40C4(1);
}

void func_802E40A8(s32 map, s32 exit){
    D_8037E8E0.unk18 = 1;
    D_8037E8E0.map = map;
    D_8037E8E0.exit = exit;
}

void func_802E40C4( s32 arg0){
    D_8037E8E0.transition = arg0;   
}

void func_802E40D0(s32 map, s32 exit){
    D_8037E8E0.unk18 = 0;
    D_8037E8E0.map = map;
    D_8037E8E0.exit = exit;
}

void func_802E40E8(s32 transition){
    D_8037E8E0.unk17 = transition;
    D_8037E8E0.unk19 = 0;
    if(transition && !gctransition_8030BDC0()){
        gctransition_8030BE60();
    }
    
}

void func_802E412C(s32 arg0, s32 arg1){
    D_8037E8E0.unk17 = arg0;
    D_8037E8E0.unk19 = arg1;
    if(arg0 && !gctransition_8030BDC0()){
        gctransition_8030BEA4(arg1);
    }
}

void func_802E4170(void){
    func_802E3BF8(2,0);
    func_80240844();
    func_802E5F68();
    if(!func_802E4A08())
        func_802F4F64();
    timedFuncQueue_free();
    func_802F9C48();
    func_8033A17C();
    func_80253420();
    func_802E398C(0);
    func_8030AFD8(0);
    func_80321854();
    func_8031FBF8();
    func_802880C0();
    func_80259B14();
    func_8030D8DC();
}

void func_802E4214(s32 arg0){
    D_8037E8E0.transition = TRANSITION_0_NONE;
    D_8037E8E0.unk19 = D_8037E8E0.unk18 = 0;
    D_8037E8E0.map = D_8037E8E0.exit = D_8037E8E0.unk17 = 0;
    D_8037E8E0.unk1B = D_8037E8E0.unk1A = 0;
    D_8037E8E0.unkC = 0;
    D_8037E8E0.unk1C = 0;
    func_8033C070();
    sns_save_and_update_global_data();
    func_8030D86C();
    func_80259A24();
    func_80322764();
    timedFuncQueue_init();
    func_802F9CD8();
    func_8031B62C();
    if(!func_802E4A08())
        func_802F51B8();
    func_802E5F38();
    func_802407C0();
    func_8033A1A4();
    func_80253428(1);
    func_80288070();
    func_8024CCC4();
    func_8024CE60(1.0f, 10000.0f);
    func_8034A6B4();
    func_80254348();
    func_80253FE8();
    func_8033DC70();
    func_8033DC04();
    func_8031FBA0();
    D_8037E8E0.game_mode = 2;
    D_8037E8E0.unk8 = 0.0f;
    func_8033DC9C(0.0f);
    func_8033DD04(0);
    func_803216D0(arg0);
    func_8030AFA0(arg0);
    func_802E3854();
    func_802E38E8(arg0, 0, 0);
    D_8037E8E0.unk0 = 0;
    func_802E3BF8(3,1);
}

void func_802E4384(void){
    if(D_8037E8E0.unk8 == 0.0f){
        func_8033DC9C(0.0f);
    }
    else{
        func_8033DC18();
        ;
        func_8033DD04((s32)(func_8033DC20()*60.0f + 0.5));
    }
    func_8033DC10();
    
    D_8037E8E0.unk8 += time_getDelta();
}

bool func_802E4424(void) {
    s32 sp1C;
    u8 temp_v0;

    func_8024CC00();
    func_8034A85C();
    if (!gctransition_8030BDC0()) {
        temp_v0 = D_8037E8E0.transition;
        D_8037E8E0.transition = TRANSITION_0_NONE;
        switch (temp_v0) {                          /* switch 1 */
            case 9:                                     /* switch 1 */
                if( (D_8037E8E0.game_mode == GAME_MODE_7_ATTRACT_DEMO)
                    || (D_8037E8E0.game_mode == GAME_MODE_8_BOTTLES_BONUS)
                    || (D_8037E8E0.game_mode == GAME_MODE_A_SNS_PICTURE)
                    || (D_8037E8E0.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
                ) {
                    func_8034B940();
                }
                gcparade_8031ABF8();
                func_802E3E7C(GAME_MODE_3_NORMAL);
                return FALSE;

            case 10:                                    /* switch 1 */
                if( (D_8037E8E0.game_mode == GAME_MODE_7_ATTRACT_DEMO)
                    || (D_8037E8E0.game_mode == GAME_MODE_8_BOTTLES_BONUS)
                    || (D_8037E8E0.game_mode == GAME_MODE_A_SNS_PICTURE)
                    || (D_8037E8E0.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
                ) {
                    func_8034B940();
                }
                gcparade_8031ABA0();
                func_802E3E7C(GAME_MODE_3_NORMAL);
                return FALSE;

            case 1:                                     /* switch 1 */
                if( (D_8037E8E0.game_mode == GAME_MODE_7_ATTRACT_DEMO)
                    || (D_8037E8E0.game_mode == GAME_MODE_8_BOTTLES_BONUS)
                    || (D_8037E8E0.game_mode == GAME_MODE_A_SNS_PICTURE)
                    || (D_8037E8E0.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
                ) {
                    func_8034B940();
                }
                func_802E3E7C(GAME_MODE_3_NORMAL);
                return FALSE;

            case 6:                                     /* switch 1 */
                func_8034B8C0(D_8037E8E0.map, D_8037E8E0.exit);
                func_802E3E7C(GAME_MODE_7_ATTRACT_DEMO);
                return FALSE;

            case 12:                                    /* switch 1 */
                func_8034B8C0(D_8037E8E0.map, D_8037E8E0.exit);
                func_802E3E7C(GAME_MODE_A_SNS_PICTURE);
                return FALSE;

            case 7:                                     /* switch 1 */
                func_8034B8C0(D_8037E8E0.map, D_8037E8E0.exit);
                func_802E3E7C(GAME_MODE_8_BOTTLES_BONUS);
                return FALSE;

            case 8:                                     /* switch 1 */
                func_8034B8C0(D_8037E8E0.map, D_8037E8E0.exit);
                func_802E3E7C(GAME_MODE_9_BANJO_AND_KAZOOIE);
                return FALSE;

            case 11:                                    /* switch 1 */
                func_802E3E7C(D_8037E8E0.game_mode);
                return FALSE;

            case 2:                                     /* switch 1 */
                func_8023DFF0(1);
                return FALSE;

            case 3:                                     /* switch 1 */
                func_8023DFF0(4);
                return FALSE;
            case 0:
                break;
        }
    }
    if (D_8037E8E0.unk1A != 0) {
        func_802E3BF8(D_8037E8E0.unk1A - 1, D_8037E8E0.unk1B);
        D_8037E8E0.unk1A = 0;
    }
    sp1C = func_80334ECC();
    func_80321C34();
    func_8030ED0C();
    func_80259BD0();
    switch (D_8037E8E0.game_mode) {
        case GAME_MODE_8_BOTTLES_BONUS:
        case GAME_MODE_A_SNS_PICTURE:
            func_8030C27C();
            /* fallthrough */
        case GAME_MODE_7_ATTRACT_DEMO:
        case GAME_MODE_9_BANJO_AND_KAZOOIE:
            func_8034BB90();
            if ((func_8024E67C(0) == 1) && (D_8037E8E0.unk0 != 0)) {
                func_802E3BF8(GAME_MODE_1_UNKNOWN, 0U);
            }
            break;
        case GAME_MODE_3_NORMAL:                                     /* switch 2 */
            D_8037E8E0.unk10 += time_getDelta();
            if( (func_8024E698(0) == 1)
                && func_8028F070()
                && (func_8028EC04() == 0)
                && !gctransition_8030BDC0()
                && gctransition_8030BD98()
                && (level_get() != 0)
                && (0.6 < D_8037E8E0.unk10)
                && gcpausemenu_80314B00()
                && !func_8028F22C()
                && func_8032056C()
                && levelSpecificFlags_validateCRC1()
                && func_80320248()
            ) {
                func_802E3BF8(GAME_MODE_4_PAUSED, 0U);
            } else if ((func_8024E67C(0) == 1) && (D_8037E8E0.unk0 != 0)) {
                func_802E3BF8(GAME_MODE_1_UNKNOWN, 0U);
            } else if (sp1C == 0) {
                func_802E3BF8(GAME_MODE_3_NORMAL, 1U);
            }
            break;

        case GAME_MODE_4_PAUSED:                                     /* switch 2 */
            if (gcPauseMenu_update() || func_8031C880()) {
                FUNC_8030E624(SFX_C9_PAUSEMENU_ENTER, 0.899316, 32736);
                func_80335110(1);
                func_8025A430(-1, 2000, 3);
                func_8025A2B0();
                func_80335128(1);
                func_802E3BF8(GAME_MODE_3_NORMAL, 0U);
            }
            break;
    }
    if ((D_8037E8E0.game_mode == GAME_MODE_3_NORMAL) || (func_802E4A08() != 0)) {
        timedFuncQueue_update();
        func_802FA0F8();
    }
    gctransition_update();
    if (func_802E4A08() == 0) {
        func_802F5374();
    }
    return TRUE;
}

void func_802E48B8(enum game_mode_e mode, s32 arg1){
    func_802E3BF8(mode, arg1);
}

s32 func_802E48D8(void){
    func_802555C4();
    if( !level_get() )
        return NULL;
    
    glspline_defrag();
    func_80288470();
    func_802F1320();
    func_802BA128();
    modelRender_defrag();
    func_8028FB68();
    func_802F0E58();
    mapModel_defrag();
    func_803086B4();
    func_8032AF94();
    func_802C4320();
    func_802F3300();
    func_802F542C();
    gcdialog_defrag();
    if(D_8037E8E0.game_mode == GAME_MODE_4_PAUSED)
        gcpausemenu_defrag();
    switch(get_loaded_overlay_id()){
        case OVERLAY_2_WHALE:
            func_803894A0();
            break;
        case OVERLAY_D_WITCH:
            func_80350E00();
            break;
    }
    return func_802555D0();
}

void func_802E49E0(void){
    D_8037E8E0.unkC = TRUE;
}

int func_802E49F0(void){
    return D_8037E8E0.unkC;
}

s32 getGameMode(void){
    return D_8037E8E0.game_mode;
}

int func_802E4A08(void){
    return (D_8037E8E0.game_mode == GAME_MODE_6_FILE_PLAYBACK) 
        || (D_8037E8E0.game_mode == 5)
        || (D_8037E8E0.game_mode == GAME_MODE_7_ATTRACT_DEMO)
        || (D_8037E8E0.game_mode == GAME_MODE_8_BOTTLES_BONUS)
        || (D_8037E8E0.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
        || (D_8037E8E0.game_mode == GAME_MODE_A_SNS_PICTURE);
}

void func_802E4A70(void){
    D_8037E8E0.unk1C = 1;
}

void func_802E4A80(void){
    D_8037E8E0.unk1C = 0;
}

u8 func_802E4A8C(void){
    return D_8037E8E0.unk1C;
}

s32 func_802E4A98(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 0];
}

s32 func_802E4AAC(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 1];
}

s32 func_802E4AC0(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 2];
}

s32 func_802E4AD4(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 3];
}

s32 func_802E4AE8(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 4];
}

s32 func_802E4AFC(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 5];
}

s32 func_802E4B10(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 6];
}

s32 func_802E4B24(s32 arg0){
    return D_803687F0[8*(arg0 - 0x80) + 7];
}

f32 func_802E4B38(void){
    return D_8037E8E0.unk8;
}
