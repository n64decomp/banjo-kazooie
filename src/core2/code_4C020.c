#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802D3D54(Actor *this);
void func_802D3DA4(Actor *this);
Actor *func_802D3F48(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D3FD4(Actor *this);
Actor *func_802D41C4(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D4250(Actor *this);
void func_802D4388(Actor *this);
Actor *func_802D4588(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D4680(Actor *this);
void func_802D4B94(Actor *this);
void func_802D4BBC(Actor *this);
void func_802D4BE4(Actor *this);
void func_802D4C0C(Actor *this);
void func_802D4C34(Actor *this);
void func_802D4C5C(Actor *this);
void func_802D4C84(Actor *this);
void func_802D4CAC(Actor *this);
void func_802D4CD4(Actor *this);


/* .data */
extern ActorAnimationInfo D_803676B0[];
extern ActorInfo D_80367760 = { 0x26E, 0x2D9, 0x3B4,  0x1, NULL,       func_802D3D54, func_80326224, func_80325E78, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367784 = { 0x26F, 0x2DA, 0x3B5,  0x1, NULL,       func_802D3D54, func_80326224, func_80325E78, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803677A8 = { 0x168, 0x25D, 0x50C,  0x1, NULL,       func_802D4250, func_80326224, func_80325E78, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803677CC = { 0x233, 0x23D, 0x4DD, 0x12, D_803676B0, func_802D4388, func_80326224, func_802D4588, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803677F0 = { 0x16A, 0x242,   0x0,  0x0, NULL,       func_802D4680,          NULL, func_80325340, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367814 = { 0x169, 0x25E, 0x50D,  0x1, NULL,       func_802D3FD4,          NULL, func_802D41C4, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367838 = { 0x265, 0x2E4, 0x55A,  0x1, NULL,       func_802D3DA4,          NULL, func_802D3F48, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_8036785C = { 0x103, 0x204, 0x4DC,  0x1, D_803676B0, func_802D4B94, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367880 = { 0x104, 0x206, 0x4DC,  0x1, D_803676B0, func_802D4C34, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803678A4 = { 0x105, 0x208, 0x4DC,  0x1, D_803676B0, func_802D4C5C, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803678C8 = { 0x106, 0x20B, 0x4DC,  0x1, D_803676B0, func_802D4C84, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803678EC = { 0x22A, 0x237, 0x4DC,  0x1, D_803676B0, func_802D4CAC, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367910 = { 0x22B, 0x239, 0x4DC,  0x1, D_803676B0, func_802D4CD4, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367934 = { 0x166, 0x25B, 0x4DC,  0x1, D_803676B0, func_802D4BBC, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80367958 = { 0x162, 0x257, 0x4DC,  0x1, D_803676B0, func_802D4BE4, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_8036797C = { 0x161, 0x256, 0x4DC,  0x1, D_803676B0, func_802D4C0C, func_80326224, func_80325888, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};


extern f32 D_80367680;
extern s32 D_80367684; //enum map_e
extern s32 D_80367688;
extern s32 D_8036768C;
extern s32 D_80367690;
extern s32 D_80367694; //enum map_e
extern s32 D_80367698;
extern s32 D_8036769C; //enum bkprog_e
extern s32 D_803676A0; //enum actor_e

extern u8  D_803676AC;

extern s32 D_803679E8;
extern s32 D_803679EC;
extern f32 D_803679F0;


/* .rodata */
extern f32 D_803769B0;
extern f64 D_803769B8; //3FA999999999999A
extern f32 D_803769C0; //3F666666

extern f32 D_80376A78;
extern f32 D_80376A7C;
extern f32 D_80376A80;
extern f32 D_80376A84;
extern f32 D_80376A88;
extern f64 D_80376A90;
extern f64 D_80376A98;

// 3ECCCCCD 3ECCCCCD
// 3ECCCCCD 3ECCCCCD  3ECCCCCD
// 4072C00000000000  4072C00000000000

/* .bss */
extern int D_8037DE00;
extern f32 D_8037DE04;
extern f32 D_8037DE08;

void func_802D6114(void);
void func_802D6264(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, s32 arg4, enum bkprog_e arg5);
void func_802D6344(void);
void func_802D63D4(void);
void func_802D6750(void);

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D2FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D317C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D31AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D3FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D41C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D42F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4680.s")

void func_802D4794(Actor *arg0, enum sfx_e arg1, f32 arg2, s32 arg3, s32 arg4);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4794.s")

void func_802D4830(Actor *arg0, enum sfx_e arg1, f32 arg2){
    func_802D4794(arg0, arg1, arg2, 32000, 0);
}

void func_802D485C(Actor *arg0, enum sfx_e arg1, f32 arg2, s32 arg3){
    func_802D4794(arg0, arg1, arg2, arg3, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D48B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D48F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4CD4.s")

void func_802D4D3C(s32 arg0, s32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D4D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D5000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D5058.s")

void func_802D5140(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    notescore_getLevelScore(func_80320424(0x19, 4));
}

void func_802D5178(s32 arg0, enum bkprog_e arg1, s32 arg2, enum map_e arg3, s32 arg4, s32 arg5, enum actor_e arg6, s32 arg7){
    if(levelSpecificFlags_get(arg0) && !func_8031FF1C(arg1)){
        levelSpecificFlags_set(arg0, FALSE);
        func_80320004(arg1, TRUE);
        func_802D6264(D_803769B0, arg3, arg2, arg4, arg5, 0);
        D_803676A0 = arg6;
        D_80367690 = arg7;
    }
}

void func_802D520C(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(func_803203FC(1) && func_803348C0() != MAP_8E_GL_FURNACE_FUN){
        func_80319214(gfx, mtx, vtx);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D5260.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D5628.s")
#else
void func_802D5628(void){
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp50[6];
    s32 sp4C;

    if( func_803348C0() != MAP_8E_GL_FURNACE_FUN
        && func_803348C0() != MAP_80_GL_FF_ENTRANCE
    ){
        D_803676AC = 0;
    }

    if(getGameMode() != GAME_MODE_4_PAUSED){
        if( func_802BB294() == 0x82 
            && ! gctransition_8030BDC0()
        ){
            D_803679E8++;
            if(D_803679EC < D_803679E8){
                D_803679EC--;
                D_803679E8 = 0;
                if(D_803679EC < 2){
                    D_803679EC = 2;
                }
                func_8030E6A4(SFX_2_CLAW_SWIPE, MIN(2.0,D_803679F0), 20000);
                D_803679F0 += D_803769B8;
            }
        }
        else{//L802D5750
            D_803679F0 = 0.9f;
            D_803679EC = 0xD;
            D_803679E8 = 0;
        }
    }//L802D5774
    if(D_80367684 && func_803348C0() == D_80367684){
        switch(D_8036768C){
            case 0x1: // L802D57C8
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x34, 0x205);
                    D_80367690++;
                }
                break;

            case 0x2: // L802D5808
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x39, 0x207);
                    D_80367690++;
                }
                break;

            case 0x3: // L802D5848
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x36, 0x20a);
                    D_80367690++;
                }   
                break;

            case 0x4: // L802D5888
                func_802D5260();
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x3b, 0x20c);
                    D_80367690++;
                }
                break;

            case 0x12: // L802D58D0
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (TFQM2) func_802D4D3C, 0x3c, 0x238);
                    D_80367690++;
                }
                break;

            case 0x5: // L802D5910
                if(!D_80367690){
                    sp7C = func_802F9AA8(0x3EC);
                    sp78 = func_8034C528(0x191);
                    if(sp78){
                        func_8034DE60(sp78, -580.0f, 0.0f, 2.5f, 1);
                    }
                    func_802FA060(sp7C, 20000, 20000, 0.0f);
                    func_802F9F80(sp7C, 0.0f, 2.2f, 0.7f);
                    D_80367690++;
                }
                break;

            case 0x6:// L802D599C
                if(!D_80367690){
                    sp74 = func_802F9AA8(0x3EC);
                    sp70 = func_8034C528(0x191);
                     if(sp70){
                        func_8034DE60(sp70, 0.0f, 1550.0f, 6.5f, 1);
                    }
                    func_802FA060(sp74, 20000, 20000, 0.0f);
                    func_802F9F80(sp74, 0.0f, 6.2f, 0.5f);
                    D_80367690++;
                }
                break;

            case 0x7: // L802D5A28
                if(!D_80367690){
                    sp6C = func_802F9AA8(0x3EC);
                    sp68 = func_8034C528(0x190);
                     if(sp68){
                        func_8034DE60(sp68, 1200.0f, 1900.0f, 3.0f, 1);
                    }
                    func_802FA060(sp6C, 20000, 20000, 0.0f);
                    func_802F9F80(sp6C, 0.0f, 2.7f, 0.5f);
                    D_80367690++;
                }
                break;

            case 0x15:// L802D5AB4
            case 0x2d:// L802D5AB4
                if(D_80367684 && D_80367684 == func_803348C0()){
                    func_80319EA4();
                    if(0.0f < D_8037DE08){
                        D_8037DE08 -= time_getDelta();
                    }
                    else{//L802D5B24
                        func_8024E55C(0, sp50); //get button inputs
                        if(sp50[4] == 1){
                            func_80324C58();
                            func_802D6114();
                        }
                    }
                }
                break;

            case 0xd: // L802D5B54
                func_802D5260();
                break;
        }//L802D6078
    }
    else{//L802D5B64
        func_802D5260();
        func_802D5178(0x1C, 0x28, 0x30, MAP_69_GL_MM_LOBBY,  0x8, 0xA, ACTOR_20E_MM_ENTRANCE_DOOR,  0x28);
        func_802D5178(0x21, 0x2D, 0x31, MAP_6E_GL_GV_LOBBY,  0xA, 0xA, ACTOR_226_GV_ENTRANCE,       0x12);
        func_802D5178(0x1E, 0x2A, 0x32, MAP_70_GL_CC_LOBBY,  0xE, 0xA, ACTOR_212_IRON_BARS,         0xA);
        func_802D5178(0x1D, 0x29, 0x33, MAP_6D_GL_TTC_LOBBY, 0x9, 0xB, ACTOR_211_CHEST_LID,         0xA);
        func_802D5178(0x1F, 0x2B, 0x34, MAP_72_GL_BGS_LOBBY, 0xB, 0xB, ACTOR_210_BGS_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x23, 0x2F, 0x35, MAP_77_GL_RBB_LOBBY, 0xD, 0x5, ACTOR_20F_RBB_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x22, 0x2E, 0x36, MAP_75_GL_MMM_LOBBY, 0xC, 0x6, ACTOR_228_INVISIBLE_WALL,    0xA);
        func_802D5178(0x24, 0x30, 0x37, MAP_79_GL_CCW_LOBBY, 0xF, 0xB, ACTOR_234_CCW_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x20, 0x2C, 0x38, MAP_6F_GL_FP_LOBBY, 0x11, 0xA, ACTOR_235_FP_ENTANCE_DOOR,   0xA);
        func_802D5178(0x3F, 0xE2, 0x40, MAP_93_GL_DINGPOT,  0x10, 0xA, ACTOR_2E5_WOODEN_DOOR,       0x28);
        if(func_803203FC(0x18)){
            if(!func_8031FF1C(BKPROG_99_PAST_50_NOTE_DOOR_TEXT)){
                func_80311174(0xF75, 0xE, NULL, NULL, NULL, NULL, func_802D5140);
                func_80320004(BKPROG_99_PAST_50_NOTE_DOOR_TEXT, TRUE);
                func_803204E4(0x18, 0);
            }
            else{//L802D5DD8
                if(!func_803203FC(0x16)){
                    func_80311174(0xF77, 0x4, NULL, NULL, NULL, NULL, func_802D5140);
                    func_803204E4(0x18, 0);
                }
            }
        }//L802D5E18
        if(level_get() == LEVEL_6_LAIR){
            if( getGameMode() == GAME_MODE_3_NORMAL
                || func_802E4A08()
            ){
                if( func_803348C0() != MAP_8E_GL_FURNACE_FUN
                    && func_803348C0() != MAP_90_GL_BATTLEMENTS
                    && !func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)
                ){
                    D_8037DE04 += time_getDelta();
                    if(D_80367680 < D_8037DE04 && !func_803203FC(0x16)){
                        if(func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)){
                            sp4C = 0xF9D;
                        }
                        else{
                            sp4C = 0xFA5;
                        }

                        if(!D_8037DE00){
                            D_8037DE00 = randi2(0xF86, sp4C);
                        }//L802D5F1C

                        if(func_803203FC(0x22)){
                            if(func_80311480(0xF82, 4, NULL, NULL, NULL, NULL)){
                                func_80320004(0xc1, 1);
                                func_803204E4(0x22, 0);
                                D_8037DE04 = 0.0f;
                                D_80367680 += 60.0;
                                if(300.0 < D_80367680)
                                    D_80367680 = 130.0f;
                            }
                        }
                        else{//L802D5FCC
                            if(func_80311480(D_8037DE00, 0, NULL, NULL, NULL, NULL)){
                                D_8037DE00++;
                                if(!(D_8037DE00 < sp4C)){
                                    D_8037DE00 = 0xF86;
                                }//L802D6018
                                D_8037DE04 = 0.0f;
                                D_80367680 += 60.0;
                                if(300.0 < D_80367680)
                                    D_80367680 = 130.0f;
                            }
                        }
                    }
                }
            }
        }//L802D607C
    }//L802D607C
}
#endif

//water_level_atleast_2;
int func_802D6088(void){
    return func_8031FF1C(BKPROG_25_LAIR_WATER_LEVEL_2)
        || func_8031FF1C(BKPROG_27_LAIR_WATER_LEVEL_3);
}

//water_level_atleast_1;
int func_802D60C4(void){
    return func_8031FF1C(BKPROG_23_LAIR_WATER_LEVEL_1)
        || func_8031FF1C(BKPROG_25_LAIR_WATER_LEVEL_2)
        || func_8031FF1C(BKPROG_27_LAIR_WATER_LEVEL_3);
}

#ifndef NONMATCHING
void func_802D6114(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_4C020/func_802D6114.s")
#else
void func_802D6114(void){
    s32 sp24; 
    s32 sp20;

    sp20 =  D_80367698;
    sp24 =  D_80367694;
    if(D_8036769C)
        func_80320004(D_8036769C, TRUE);
    func_802D6344();
    if(func_803348C0() != sp24){
        if(map_getLevel(sp24) != map_getLevel(func_803348C0())){
            func_802E4A70();
        }//L802D6194
        func_803204E4(0x21, 1);
        if(sp24 != 0x1C || !func_8025ADBC(COMUSIC_23_MMM_INSIDE_CHURCH)){
            func_803228D8();
        }
        func_802E4078(sp24, sp20, 0);
    }
    else{//L802D61DC
        func_80347A14(1);
        func_80314AC8(1);
    }
}
#endif

void func_802D61FC(enum map_e arg0){
    if( map_getLevel(arg0) != map_getLevel(func_803348C0()))
        func_802E4A70();
    func_803228D8();
    func_802E4078(D_80367684, 0, 0);
    func_802D6750();
}

void func_802D6264(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, s32 arg4, enum bkprog_e arg5){
    D_80367684 = arg1;
    D_80367688 = arg2;
    D_8036768C = arg3;
    D_80367690 = 0;

    D_80367694 = func_803348C0();
    D_80367698 = arg4;
    D_8036769C = arg5;
    D_803676A0 = 0;

    if(arg1 != D_80367694){
        timedFunc_set_1(arg0, (TFQM1) func_802D61FC, arg1);
    }
    else{
        timedFunc_set_0(arg0, func_802D63D4);
    }
    func_80314AC8(0);
}

void func_802D6310(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, enum bkprog_e arg4){
    func_802D6264(arg0, arg1, arg2, arg3, 0x63, arg4);
    func_8028FCE8();
}

void func_802D6344(void){
    D_80367684 = 0;
    D_80367688 = 0;
    D_8036768C = 0;
    D_80367690 = 0;
    D_80367694 = 0;
    D_80367698 = 0;
    D_8036769C = 0;
    D_803676A0 = 0;
}

void func_802D6388(void){
    timedFunc_set_0(5.0f, func_802D6114);
    func_802BBC58(1);
    func_802BAE20(D_80367688);
    D_8037DE08 = 0.5f;
}

void func_802D63D4(void){
    f32 sp1C[3];

    if(D_80367684 == 0)
        return;

    if(func_803348C0() != D_80367684)
        return;

    func_80347A14(0);
    switch(D_8036768C){
        case 0x15:  //L802D6430
            func_802D6388();
            break;
        case 0x2D: //L802D6440
            func_802D6388();
            func_802BAEF4(sp1C);
            func_8028F85C(sp1C);
            break;
        default: //L802D6460
            func_802BAFE4(D_80367688);
            func_803251D4();
            func_803204E4(0xbf, 0);
            func_802D6750();
            break;
    }
}


void func_802D6494(void){
    if( (!D_80367684 || (D_80367684 && (func_803348C0() == D_80367684)))
    ){
        switch(D_803676A0){
            case ACTOR_2E5_WOODEN_DOOR:
                break;
            case ACTOR_20E_MM_ENTRANCE_DOOR:// L802D6510
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 1000, 0x265);
                func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                break;
            case ACTOR_211_CHEST_LID:// L802D6530
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 1000, 0x265);
                func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                break;
            case ACTOR_212_IRON_BARS:// L802D6550
                if(func_803348C0() == MAP_70_GL_CC_LOBBY && !func_803203FC(UNKFLAGS1_7F_SANDCASTLE_OPEN_CC)){
                    func_802D4830(func_80326EEC(ACTOR_212_IRON_BARS), SFX_9A_MECHANICAL_CLOSING, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_234_CCW_ENTRANCE_DOOR:// L802D65A0
                if(func_803348C0() == MAP_79_GL_CCW_LOBBY && !func_803203FC(UNKFLAGS1_93_SANDCASTLE_OPEN_CCW)){
                    func_802D485C(func_80326EEC(ACTOR_234_CCW_ENTRANCE_DOOR), SFX_3EC_CCW_DOOR_OPENING, 0.8f, 15000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_210_BGS_ENTRANCE_DOOR:// L802D65F8
                if(!func_803203FC(0x84)){
                    FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 1000, 0x265);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_235_FP_ENTANCE_DOOR:// L802D6624
                if(func_803348C0() == MAP_6F_GL_FP_LOBBY && !func_803203FC(UNKFLAGS1_8B_SANDCASTLE_OPEN_FP)){
                    func_802D4830(func_80326EEC(ACTOR_235_FP_ENTANCE_DOOR), SFX_18_BIGBUTT_SLIDE, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_226_GV_ENTRANCE:// L802D6674
                if(func_803348C0() == MAP_6E_GL_GV_LOBBY && !func_803203FC(UNKFLAGS1_87_SANDCASTLE_OPEN_GV)){
                    func_802D485C(func_80326EEC(ACTOR_226_GV_ENTRANCE), SFX_3EC_CCW_DOOR_OPENING, 0.8f, 15000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_228_INVISIBLE_WALL:// L802D66CC
                if(!func_803203FC(UNKFLAGS1_8C_SANDCASTLE_OPEN_MMM)){
                    FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 1000, 0x265);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_20F_RBB_ENTRANCE_DOOR:// L802D66F8
                if(func_803348C0() == MAP_77_GL_RBB_LOBBY && !func_803203FC(UNKFLAGS1_90_SANDCASTLE_OPEN_RBB)){
                    func_802D4830(func_80326EEC(ACTOR_20F_RBB_ENTRANCE_DOOR), SFX_9A_MECHANICAL_CLOSING, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
        }
    }
}

void func_802D6750(void){
    timedFunc_set_0(0.4f, func_802D6494);
}

enum map_e func_802D677C(enum map_e arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367684;
    out = D_80367684;
    D_80367684 = arg0;
    return out;
}

s32 func_802D67AC(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_8036768C;
    out = D_8036768C;
    D_8036768C = arg0;
    return out;
}

enum actor_e func_802D67DC(enum actor_e arg0){
    s32 out;
    if(arg0 == -1)
        return D_803676A0;
    out = D_803676A0;
    D_803676A0 = arg0;
    return out;
}

s32 func_802D680C(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367690;
    out = D_80367690;
    D_80367690 = arg0;
    return out;
}

s32 func_802D683C(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367688;
    out = D_80367688;
    D_80367688 = arg0;
    return out;
}

int func_802D686C(void){
    if(func_803203FC(0x1E)){
        return FALSE;
    } 
    return func_803348C0() == D_80367684;
}

int func_802D68B4(void){
    return func_802D686C() || func_803203FC(0x21);
}

//BREAK????

//set_hourglass_timer_minutes
void func_802D68F0(s32 minutes){
    func_80346414(ITEM_0_HOURGLASS_TIMER, minutes*60 - 1);
}

//hide_hourglass_timer
void func_802D6924(void){
    func_80346414(ITEM_6_HOURGLASS, 0);
}

//update_has_entered_level_flags
void func_802D6948(void){
    switch(func_803348C0()){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            func_80320004(BKPROG_B0_HAS_ENTERED_MM, TRUE);
            break;
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            func_80320004(BKPROG_B2_HAS_ENTERED_TTC, TRUE);
            break;
        case MAP_B_CC_CLANKERS_CAVERN:
            func_80320004(BKPROG_B8_HAS_ENTERED_CC, TRUE);
            break;
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
            func_80320004(BKPROG_B1_HAS_ENTERED_BGS, TRUE);
            break;
        case MAP_12_GV_GOBIS_VALLEY:
            func_80320004(BKPROG_B3_HAS_ENTERED_GV, TRUE);
            break;
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            func_80320004(BKPROG_B7_HAS_ENTERED_MMM, TRUE);
            break;
        case MAP_27_FP_FREEZEEZY_PEAK:
            func_80320004(BKPROG_B6_HAS_ENTERED_FP, TRUE);
            break;
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            func_80320004(BKPROG_B4_HAS_ENTERED_RBB, TRUE);
            break;
        case MAP_40_CCW_HUB:
            func_80320004(BKPROG_B5_HAS_ENTERED_CCW, TRUE);
            break;
    }
}

//has entered map and level
int func_802D6A38(enum map_e map_id){
    switch(map_id){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            return func_8031FF1C(BKPROG_B0_HAS_ENTERED_MM);
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            return func_8031FF1C(BKPROG_B2_HAS_ENTERED_TTC);
        case MAP_B_CC_CLANKERS_CAVERN:
            return func_8031FF1C(BKPROG_B8_HAS_ENTERED_CC);
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
            return func_8031FF1C(BKPROG_B1_HAS_ENTERED_BGS);
        case MAP_12_GV_GOBIS_VALLEY:
            return func_8031FF1C(BKPROG_B3_HAS_ENTERED_GV);
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            return func_8031FF1C(BKPROG_B7_HAS_ENTERED_MMM);
        case MAP_27_FP_FREEZEEZY_PEAK:
            return func_8031FF1C(BKPROG_B6_HAS_ENTERED_FP);
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            return func_8031FF1C(BKPROG_B4_HAS_ENTERED_RBB);
        case MAP_40_CCW_HUB:
            return func_8031FF1C(BKPROG_B5_HAS_ENTERED_CCW);
    }
    return FALSE;
}
