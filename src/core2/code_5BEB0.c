#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"

void func_8024CE60(f32, f32);


void func_802E40A8(s32 map, s32 exit);
void func_802E40D0(s32 map, s32 exit);
void func_802E40E8(s32 transition);
int func_802E4A08(void);

f32 func_8033DC20(void);
void func_8033DC9C(f32);
extern void func_80324C58(void);


extern f32 D_80377114;

extern struct{
    s32 unk0;
    s32 game_mode; //game_mode
    f32 unk8; 
    s32 unkC; //freeze_scene_flag (used for pause menu)
    f32 unk10;
    u8 unk14; //map
    u8 unk15; //exit
    u8 unk16;
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

void func_802E3BD0(s32 arg0);
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

void mapSavestate_clearAll(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            free(D_8037E650[i]);
            D_8037E650[i] = NULL;
        }
    }
}

void func_802E2ED4(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            D_8037E650[i] = func_802555DC(D_8037E650[i]);
        }
    }
}

//mapSavestate_save
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E2F2C.s")
// void func_802E2F2C(s32 map){
//     u32 **tmp;
//     u32 wSize;
//     volatile u32 * sp38;
//     s32 iBit;
//     s32 bit_max;
//     s32 reg_s4;
//     u32* reg_v1;
//     u32* valPtr;

      
//     wSize = 4;
//     tmp = &D_8037E650[map];
//     if(*tmp)
//         free(*tmp);
      
//     *tmp = (MapSavestate *) malloc(4*sizeof(u32));
//     sp38 =  *tmp;

//     *sp38 = mapSpecificFlags_getAll();
    
//     iBit = 0x20;
//     func_80308230(1, sp38);
//     func_803083B0(-1);
    
//     for(reg_s4 = func_803083B0(-2);reg_s4 != -1; reg_s4 = func_803083B0(-2, valPtr)){
//         if( !(iBit < wSize*sizeof(u32)*8)){
//             wSize += 4;
//             *tmp = (MapSavestate *)realloc(*tmp, wSize*sizeof(u32));
//             reg_v1 = ((s32)D_8037E650[map] + wSize*sizeof(u32));
//             reg_v1[-1] = 0;
//             reg_v1[-2] = 0;
//             reg_v1[-3] = 0;
//             reg_v1[-4] = 0;
//         }
//         valPtr = *tmp;
//         valPtr[(iBit >> 5)] = (reg_s4)
//             ? valPtr[(iBit >> 5)] | (1 << (iBit & 0x1f))
//             : valPtr[(iBit >> 5)] & ~(1 << (iBit & 0x1f));
        
//         iBit++;
        
//     }
//     //if(sp38);
//     *tmp = actors_appendToSavestate(*tmp, *tmp + 4*((iBit + 0x7F) >> 7));   
// }  

//mapSavestate_apply
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E30AC.s")
// void func_802E30AC(enum map_e map){
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3854.s")

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

    func_802F6E94(gdl, mptr, vptr);

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

void func_802E3BD0(s32 arg0){
    func_8024A85C(arg0);
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
        FUNC_8030E624(SFX_C9_PAUSEMENU_ENTER, 0x3FF, 0x465);
        func_8024E7C8();
        func_8025A430(0, 2000, 3);
        func_8025A23C(COMUSIC_6F_PAUSE_SCREEN);
        func_80312B8C();
    }//L802E3E6C
}

void func_802E3E7C(enum game_mode_e mode){
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 prev_mode;

    func_80254008();
    sp34 = D_8037E8E0.unk18;
    sp30 = D_8037E8E0.unk17;
    sp2C = D_8037E8E0.unk15;
    sp28 = D_8037E8E0.unk16;
    prev_mode = D_8037E8E0.unk0;
    func_802E3BF8(2, 0);
    if(!func_80320454(0x21, 0) || map_getLevel(func_803348C0()) == map_getLevel(D_8037E8E0.unk15)){
        if(!func_803203FC(0x1F))
            func_802E2F2C(func_803348C0()); //mapSavestate_save;
    }
    func_802E398C(1);
    func_802E38E8(sp2C, sp28, sp34);
    func_802E30AC(sp2C);
    D_8037E8E0.unk0 = prev_mode;
    func_802E3BF8(mode, sp30);
    func_80332CCC();
    func_80346CA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E3F8C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E40C4.s")

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
    func_8032517C();
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/func_802E4214.s")
// //99.9% there
// void func_802E4214(s32 arg0){
//     D_8037E8E0.unk14 = 0;
//     D_8037E8E0.unk18 = 0;
//     D_8037E8E0.unk19 = 0;
//     D_8037E8E0.unk17 = 0;
//     D_8037E8E0.unk16 = 0;
//     D_8037E8E0.unk15 = 0;
//     D_8037E8E0.unk1A = 0;
//     D_8037E8E0.unk1B = 0;
//     D_8037E8E0.unkC = 0;
//     D_8037E8E0.unk1C = 0;
//     func_8033C070();
//     sns_save_and_update_global_data();
//     func_8030D86C();
//     func_80259A24();
//     func_80322764();
//     func_803251A0();
//     func_802F9CD8();
//     func_8031B62C();
//     if(!func_802E4A08())
//         func_802F51B8();
//     func_802E5F38();
//     func_802407C0();
//     func_8033A1A4();
//     func_80253428(1);
//     func_80288070();
//     func_8024CCC4();
//     func_8024CE60(1.0f, D_80377114);
//     func_8034A6B4();
//     func_80254348();
//     func_80253FE8();
//     func_8033DC70();
//     func_8033DC04();
//     func_8031FBA0();
//     D_8037E8E0.game_mode = 2; //save to t0 instead of t6
//     D_8037E8E0.unk8 = 0.0f;
//     func_8033DC9C(0.0f);
//     func_8033DD04(0);
//     func_803216D0(arg0);
//     func_8030AFA0(arg0);
//     func_802E3854();
//     func_802E38E8(arg0, 0, 0);
//     D_8037E8E0.unk0 = 0;
//     func_802E3BF8(3,1);
// }

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
    
    D_8037E8E0.unk8 += func_8033DD9C();
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
    func_8031169C();
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
    return (D_8037E8E0.game_mode == 6) 
        || (D_8037E8E0.game_mode == 5)
        || (D_8037E8E0.game_mode == 7)
        || (D_8037E8E0.game_mode == 8)
        || (D_8037E8E0.game_mode == 9)
        || (D_8037E8E0.game_mode == 10);
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