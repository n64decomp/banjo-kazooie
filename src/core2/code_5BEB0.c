#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"

void func_8024CE60(f32, f32);


void func_802E40A8(s32 map, s32 exit);
void func_802E40C4( s32 arg0);
void func_802E40D0(s32 map, s32 exit);
void func_802E40E8(s32 transition);
int  func_802E4A08(void);

f32 func_8033DC20(void);
void func_8033DC9C(f32);
extern void func_80324C58(void);


extern f32 D_80377110;
extern f32 D_80377114;

extern s32 D_8037E8EC;

extern struct{
    s32 unk0;
    s32 game_mode; //game_mode
    f32 unk8; 
    s32 unkC; //freeze_scene_flag (used for pause menu)
    f32 unk10;
    u8 unk14; //
    u8 unk15; //map
    u8 unk16; //exit
    u8 unk17; //reset_on_map_load
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_8037E8E0;

typedef struct map_savestate_s{
    u32 flags;
}MapSavestate;

extern MapSavestate *D_8037E650[];

void func_802E3BD0(s32 frame_buffer_indx);
int func_802E49F0(void);

/* .code */

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E2E40.s")
#else
void func_802E2E40(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        D_8037E650[i] = 0;
    }
}
#endif

void mapSavestate_free_all(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            free(D_8037E650[i]);
            D_8037E650[i] = NULL;
        }
    }
}

void mapSavestate_defrag_all(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            D_8037E650[i] = defrag(D_8037E650[i]);
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/mapSavestate_save.s")
#else
void mapSavestate_save(enum map_e map){
    u32 wSize;
    volatile u32 * sp38;
    s32 iBit;
    s32 bit_max;
    s32 reg_s4;
    u32* reg_v1;
    u32* valPtr;

      
    wSize = 4;
    if(D_8037E650[map])
        free(D_8037E650[map]);
      
    D_8037E650[map] = (MapSavestate *) malloc(4*sizeof(u32));
    sp38 =   D_8037E650[map];

    *sp38 = mapSpecificFlags_getAll();
    
    iBit = 0x20;
    func_80308230(1, D_8037E650[map]);
    func_803083B0(-1);
    
    for(reg_s4 = func_803083B0(-2); reg_s4 != -1; reg_s4 = func_803083B0(-2, valPtr)){
        if( !(iBit < wSize*sizeof(u32)*8)){
            wSize += 4;
             D_8037E650[map] = (MapSavestate *)realloc( D_8037E650[map], wSize*sizeof(u32));
            reg_v1 = ((s32)D_8037E650[map] + wSize*sizeof(u32));
            reg_v1[-1] = 0;
            reg_v1[-2] = 0;
            reg_v1[-3] = 0;
            reg_v1[-4] = 0;
        }
        valPtr =  D_8037E650[map];
        valPtr[(iBit >> 5)] = (reg_s4)
            ? valPtr[(iBit >> 5)] | (1 << (iBit & 0x1f))
            : valPtr[(iBit >> 5)] & ~(1 << (iBit & 0x1f));
        
        iBit++;
        
    }
    //if(sp38);
     D_8037E650[map] = actors_appendToSavestate( D_8037E650[map],  (s32)D_8037E650[map] + 16*((iBit + 0x7F) >> 7));   
}  
#endif

//mapSavestate_apply
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/mapSavestate_apply.s")
// void mapSavestate_apply(enum map_e map){
//     u32 **mssp = D_8037E650 + map;
//     int s0;
//     int val;
//     u8 *tmp;
//     if(*mssp){
//         mapSpecificFlags_setAll(**mssp);
//         func_80308230(1);
//         func_803083B0(-1);
//         for(s0 = 0x20; func_803083B0((((*mssp)[s0 >> 5]) & (1 << (s0 & 0x1f)))? 1 : 0) != -1; s0++);
//         func_80308230(0);
//         tmp = *mssp;
//         func_8032A09C(tmp, (tmp + 16*((s0 + 0x7f) >> 7)));
//         free(*mssp);
//         *mssp = NULL;
//     }
// }

//===== BREAK ======//

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E31D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E329C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3580.s")

void func_802E35D0(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E35D8.s")

extern void func_8024C510(f32);
extern void func_8024CDF8(f32, f32, f32);
extern void func_8024CE40(f32, f32, f32);

void func_802E3800(void){
    func_8024CDF8(0.0f, 0.0f, 0.0f);
    func_8024CE40(-30.0f, 30.0f, 0.0f);
    func_8024C510(D_80377110);
    func_8024CFD4();
}

void func_802E3854(void){
    int i;

    func_8033B61C();
    func_80254464();
    for(i = 0; i < 0xF; i++){
        func_802E6820(5);
        func_8033A4D8();
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E398C.s")

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

    func_80314320(gdl, mptr, vptr);
    if(!func_802E49F0()){
        func_8025AFC0(gdl, mptr, vptr);
    }

    func_8030F410(gdl, mptr, vptr);
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
        func_803117E8();
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
                if(func_803203FC(0x1F)){
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
                sp1C = func_8034BDA4(D_8037E8E0.unk15, D_8037E8E0.unk16);
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
        func_80312B8C();
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
    map = D_8037E8E0.unk15;
    sp28 = D_8037E8E0.unk16;
    prev_mode = D_8037E8E0.unk0;
    func_802E3BF8(2, 0);
    if(!func_80320454(0x21, 0) || map_getLevel(map_get()) == map_getLevel(D_8037E8E0.unk15)){
        if(!func_803203FC(0x1F))
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3F80.s")

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
    if(D_8037E8EC == 1){
        func_80254404(&sp34, &sp28, &sp24);
    }
    sp30 = sp34;
    func_802E39D0(&sp34, &sp28, &sp24, func_8024BDA0(), arg0);
    if(D_8037E8EC == 0){
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
    D_8037E8E0.unk15 = map;
    D_8037E8E0.unk16 = exit;
}

void func_802E40C4( s32 arg0){
    D_8037E8E0.unk14 = arg0;   
}

void func_802E40D0(s32 map, s32 exit){
    D_8037E8E0.unk18 = 0;
    D_8037E8E0.unk15 = map;
    D_8037E8E0.unk16 = exit;
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4214.s")
#else
// //99.9% there
void func_802E4214(s32 arg0){
    D_8037E8E0.unk14 = 0;
    D_8037E8E0.unk18 = 0;
    D_8037E8E0.unk19 = 0;
    D_8037E8E0.unk17 = 0;
    D_8037E8E0.unk16 = 0;
    D_8037E8E0.unk15 = 0;
    D_8037E8E0.unk1A = 0;
    D_8037E8E0.unk1B = 0;
    D_8037E8E0.unkC = 0;
    D_8037E8E0.unk1C = 0;
    func_8033C070();
    func_8025B0E4();
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
    func_8024CE60(1.0f, D_80377114);
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
#endif

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4424.s")

void func_802E48B8(enum GAME_MODE_E mode, s32 arg1){
    func_802E3BF8(mode, arg1);
}

s32 func_802E48D8(void){
    func_802555C4();
    if( !level_get() )
        return NULL;
    
    func_80343F3C();
    func_80288470();
    func_802F1320();
    func_802BA128();
    func_8033A4D8();
    func_8028FB68();
    func_802F0E58();
    func_8030A298();
    func_803086B4();
    func_8032AF94();
    func_802C4320();
    func_802F3300();
    func_802F542C();
    gcdialog_defrag();
    if(D_8037E8E0.game_mode == 4)
        func_80311740();
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4B24.s")

f32 func_802E4B38(void){
    return D_8037E8E0.unk8;
}