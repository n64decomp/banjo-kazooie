#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef MIN
#define MIN(s,t) (((s) < t)?(s):(t))
#endif

#ifndef MAX
#define MAX(s,t) (((s) > t)?(s):(t))
#endif

void func_803204E4(s32, s32);
f32 func_8024DE1C(f32, f32, f32 *, f32 *);
void mlMtxApply(Mtx*);
void func_80310D2C(void);

s32 level_get(void);
void gczoombox_update(gczoombox_t *);
void func_8024E6E0(s32, void *);
void func_8024E60C(s32, void *);
void func_8024E71C(s32, void *);
void func_8024E55C(s32, void *);
s32 getGameMode(void);
void func_803120FC(s32);

void gczoombox_highlight(gczoombox_t *, int);

extern s32 D_80383084;

extern struct1As D_8036C4E0[4];
extern struct1As D_8036C520[4];
extern struct1Bs D_8036C560[0xD];
extern struct1Cs D_8036C58C[0xC];
extern u8 D_8036C604[7];
extern const char D_8036C618[] = "";
extern int D_8036C620;



extern struct{
    u32         unk0_31:8; //menu state
    u32         unk0_23:8;
    u32         unk0_15:8; //menu page
    u32         unk0_7:1;
    u32         unk0_6:1;
    u32         unk0_5:1;
    u32 pad0_4:1;
    u32         unk0_3:1;
    u32         unk0_2:1;
    u32         unk0_1:1;
    u32 pad0_0:1;
    s8          unk4;
    s8          unk5;
    u8          unk6;
    u8          unk7;
    s8          unk8;
    s8          unk9;
    s8          unkA;       //joystick frame
    u8          unkB;       //joystick total frames
    f32         unkC;
    gczoombox_t *zoombox[4];
    f32         unk20;
    BKSprite *  unk24;      //joystick sprite
    f32         unk28;
    BKSprite *  unk2C;      //B-button sprite
    u8          unk30;      //B-button frame
    u8          unk31;      //B-button total frames
    s16         unk32;      //B-button alpha
    s16         unk34;      //left joystick alpha
    s16         unk36;      //right joystick alpha
    u8          pad38[0x2];
    u8          unk3A;
    u8  pad3B[1];
    s16         unk3C[7];
    s16         unk4A[7];
    u8 pad58[0x4];
    void *      unk5C; //SnS Egg Model
    void *      unk60; //Ice key model
    u8 pad64[0xC];
    u32         unk70_31:1;
    u32         unk70_30:1;
    u32         unk70_29:1;
    u32 pad70_28:29;
}D_80383010;

extern char D_80383088[];

void func_803129DC(s32,s32);
void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
void func_80318640(gczoombox_t *, s32, f32, f32, s32);
void func_80318734(gczoombox_t *, f32);

/* .rodata */
extern char D_803786B0[]; // ""
extern char D_803786B4[]; // ":"
extern char D_803786B8[]; // "0"
extern char D_803786BC[]; // ":"
extern char D_803786C0[]; // "0"
extern char D_803786C4[]; // ""
extern char D_803786C8[]; // "/"
extern char D_803786CC[]; // "/"
extern char D_803786D0[]; // "/"
extern char D_803786D4[]; //"ARE YOU SURE?"
extern char D_803786E4[]; //"A - YES, B - NO"
extern f32 D_803786F4;
extern f32 D_803786F8;
extern f32 D_803786FC;
extern f32 D_80378700;
extern f32 D_80378704;
// jump table D_80378708;
extern f64 D_80378850;
extern f64 D_80378858;
extern f64 D_80378860;
extern f64 D_80378868;
extern f32 D_80378870;
extern f32 D_80378874;


void func_80311740(void){
    s32 i;
    for(i =0; i< 4; i++){
        if(D_80383010.zoombox[i]){
            func_80318C0C(D_80383010.zoombox[i]);
            D_80383010.zoombox[i] = defrag(D_80383010.zoombox[i]);
        }
    }
}

//_gcpausemenu_freeZoomboxes
void func_803117A0(void){
    s32 i;
    for(i =0; i< 4; i++){
        gczoombox_free(D_80383010.zoombox[i]);
        D_80383010.zoombox[i] = NULL;
    }
}

void func_803117E8(void){
    s32 i;
    for( i=0; i<2; i++){
        assetcache_release(D_80383010.unk24);
        D_80383010.unk24 = NULL;
        assetcache_release(D_80383010.unk2C);
        D_80383010.unk2C = NULL;
    }
    func_803117A0();
    func_80311650();
}

//gc_zoombox_init
#ifdef NONMATCHING
//MATCHING, but needs .rodata
void func_80311854(void){
    s32 i;
    for(i = 0; i<4; i++){
        D_80383010.zoombox[i] = gczoombox_new(D_8036C4E0[i].unkC,D_8036C4E0[i].unkE, 2, 0,func_803129DC);
        func_803184C8(D_80383010.zoombox[i], 60.0f, 5, 2, 0.3f, 0, 0);
        func_80318640(D_80383010.zoombox[i], 0x1C, 0.75f, 0.9f, 0);
        func_80318760(D_80383010.zoombox[i], 8000);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80311854.s")
#endif

#ifdef NONMATCHING
//MATCHING, but needs .rodata
void func_80311954(void){
    s32 i;

    for(i = 0; i<4; i++){
        D_80383010.zoombox[i] = gczoombox_new(D_8036C520[i].unkC,D_8036C520[i].unkE, (i == 3) ? 1 : 2 , 0,func_803129DC);
        func_803184C8(D_80383010.zoombox[i], 40.0f, 5, 2, 0.3f, 0, 0);
        func_80318640(D_80383010.zoombox[i], 0x46, 0.9f, 0.7f, 1);
        func_80318760(D_80383010.zoombox[i], 8000);
    }
    func_80318734(D_80383010.zoombox[3], 24.0f);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80311954.s")
#endif

void func_80311A84(void){
    s32 i;

    func_802FA5D0();
    for(i = 0; i< 7; i++){
        func_802FACA4(D_8036C604[i]);
    }

    if(func_802FC3C4()){
        D_80383010.unk70_31 = 1;
        func_802FAD64(ITEM_12_JINJOS);
    }else{
        func_802FACA4(ITEM_12_JINJOS);
    }

    if(func_802FD2D4()){
        D_80383010.unk70_30 = 1;
        func_802FAD64(ITEM_16_LIFE);
    }else{
        func_802FACA4(ITEM_16_LIFE);
    }
}


void func_80311B44(void){
    s32 i;
    
    for(i = 0; i<7; i++){
        func_802FAD64(D_8036C604[i]);
    }
    func_802FAD64(ITEM_12_JINJOS);
    func_802FAD64(ITEM_16_LIFE);
}

void func_80311B9C(s32 level, s32 *valPtr, s32 *maxPtr){
    *valPtr = itemscore_noteScores_get(level); //get note highscore
    *maxPtr = 100;
}

void func_80311BD4(s32 level, s32 *valPtr, s32 *maxPtr){
    *valPtr = jiggyscore_leveltotal(level); //get note highscore
    *maxPtr = 10;
}

void func_80311C0C(s32 level, s32 *valPtr, s32 *maxPtr){
    *valPtr = honeycombscore_get_level_total(level);
    *maxPtr = (level == LEVEL_B_SPIRAL_MOUNTAIN)? 6 : 2;
}

u8 *func_80311C64(int time){
    s32 hours;
    s32 minutes;
    s32 seconds;
    
    strcpy(D_80383088, D_803786B0); //strcpy(D_80383088, "");
    strIToA(D_80383088, time/3600);
    strcat(D_80383088, D_803786B4); //strcat(D_80383088, ":");
    minutes = (time/60)%60;
    if(minutes < 10){
        strcat(D_80383088, D_803786B8); //strcat(D_80383088, "0");
    }
    strIToA(D_80383088, minutes);
    strcat(D_80383088, D_803786BC); //strcat(D_80383088, ":");
    seconds = time % 60;
    if(seconds < 10){
        strcat(D_80383088, D_803786C0); //strcat(D_80383088, "0");
    }
    strIToA(D_80383088, seconds); //strcat(D_80383088, ":");
    strcat(D_80383088, D_803786C4); //strcpy(D_80383088, "");
    return D_80383088;
}

#if NONMATCING
//MATCHING NEEDS .data defined
void func_80311D74(s32 level){
    s32 val;
    s32 max;
    const char empty[] = ""; //D_8036C618

    //note ratio 2 string
    func_80311B9C(level, &val, &max);
    strcpy(D_8036C520[0].str, empty);
    strIToA(D_8036C520[0].str, val);
    strcat(D_8036C520[0].str, D_803786C8);
    strIToA(D_8036C520[0].str, max);
    strcat(D_8036C520[0].str, empty);

    //jiggy_ratio_2_string
    func_80311BD4(level, &val, &max);
    strcpy(D_8036C520[1].str, empty);
    strIToA(D_8036C520[1].str, val);
    strcat(D_8036C520[1].str, D_803786CC);
    strIToA(D_8036C520[1].str, max);
    strcat(D_8036C520[1].str, empty);

    //honeycomb_ratio_2_string
    func_80311C0C(level, &val, &max);
    strcpy(D_8036C520[2].str, empty);
    strIToA(D_8036C520[2].str, val);
    strcat(D_8036C520[2].str, D_803786D0);
    strIToA(D_8036C520[2].str, max);
    strcat(D_8036C520[2].str, empty);

    //gametime_2_sting
    strcpy(D_8036C520[3].str, empty);
    strcat(D_8036C520[3].str, func_80311C64(itemscore_timeScores_get(level)));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80311D74.s")
#endif

void func_80311ED0(s32 *dst){
    *dst = itemscore_noteScores_getTotal(); //note_total
}

void func_80311EF8(s32 *dst){
    *dst = jiggyscore_total();
}

void func_80311F20(s32 *dst){
    *dst = honeycombscore_get_total(); //honeycomb_total
}

#ifdef NONMATCHING
//MATCHING NEEDS .data defined
void func_80311F48(void){
    s32 val;
    const char empty[] = ""; //D_8036C618

    //note ratio 2 string
    func_80311ED0(&val);
    strcpy(D_8036C520[0].str, empty);
    strIToA(D_8036C520[0].str, val);
    strcat(D_8036C520[0].str, empty);

    //jiggy_ratio_2_string
    func_80311EF8(&val);
    strcpy(D_8036C520[1].str, empty);
    strIToA(D_8036C520[1].str, val);
    strcat(D_8036C520[1].str, empty);

    //honeycomb_ratio_2_string
    func_80311F20(&val);
    strcpy(D_8036C520[2].str, empty);
    strIToA(D_8036C520[2].str, val);
    strcat(D_8036C520[2].str, empty);

    //gametime_2_sting
    strcpy(D_8036C520[3].str, empty);
    strcat(D_8036C520[3].str, func_80311C64(itemscore_timeScores_getTotal()));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80311F48.s")
#endif

#ifdef NONMATCHING
//MATCHING but need .rodata
s32 func_80312034(s32 arg0){
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return arg0 +2;

    case 6:
    case 12:
        return 2;
    case 7:
        return 8;
    case 8:
        return 11;
    case 9:
        return 10;
    case 10:
        return 9;
    case 11:
        return 1;
    default:
        return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80312034.s")
#endif

void func_8031209C(struct1As *arg0, s32 arg1){
    s32 i;
    s32 j;

    for(i = 0; i < arg1; i++){//L803120B8
        arg0[i].unkF = 0;
    }
}

#ifdef NONMATCHING
void func_803120FC(s32 arg0){
    s32 i;
    int _t;
    switch(arg0){
        case 0:
            func_80311A84();
            D_80383010.unk0_23 = 0;
            D_80383010.unk0_2 = D_80383010.unk0_7 = D_80383010.unk4 = 0;
            D_80383010.unk0_15 = D_80383010.unk4;
            D_80383010.unk0_3 = D_80383010.unk0_2;
            break;

        case 1:
            D_80383010.unkC = D_80383010.unk0_6 = D_80383010.unk7 = 0;
            func_8031209C(D_8036C4E0, 4);
            
            for(i = 0; i < 4; i++){
                gczoombox_highlight(D_80383010.zoombox[i], 1);
            }
            if(D_80383010.unk70_29){
                gczoombox_highlight(D_80383010.zoombox[1],0);
            }
            break;
        
        case 2:
            D_80383010.unk0_6 = 0;
            break;

        case 3:
            func_80311B44();
            D_80383010.unkC = D_80383010.unk0_6 = 0;
            D_80383010.unk5 = 3;
            func_8031209C(D_8036C4E0, 4);
            break;

        case 5:/* 8B334 803122C4 3C128038 */
            D_80383010.unkC = 3.0f;
            D_80383010.unk5 = D_80383010.unk0_6 = 0;
            func_8031209C(D_8036C4E0, 4);
            for(i = 0; i < 4; i++){
                D_80383010.unk5 += func_803188B4(D_80383010.zoombox[i]);
            }
            break;

        case 6:/* 8B3A8 80312338 0C0C46D1 */
            func_80311B44();
            D_80383010.unk0_15 = 0;
            D_80383010.unk4 = 0;
            D_80383010.unkC = 0.0f;
            for(i = 0; i < 4; i++){
                func_80318964(D_80383010.zoombox[i]);
            }
            break;

        case 7:/* 8B3F4 80312384 44803000 */
            D_80383010.unk20 = D_80383010.unk28 = 0.0f;
            D_80383010.unk0_23 = 1;
            D_80383010.unk0_1 = 1;
            func_803117A0();
            func_80311954();
            if(D_80383010.unk0_15 ==  func_80312034(level_get())){
                func_802F5060(0x6e7);
            }
            if(D_80383010.unk0_15 != 0){
                func_80311D74(D_8036C58C[D_80383010.unk0_15].unk0);
            }else{
                func_80311F48();
            }

            for(i = 0; i<4; i++){//L80312420

                if(D_8036C58C[D_80383010.unk0_15].unk0 == 6){
                    _t = (!(i == 0) && !(i == 2));
                    gczoombox_highlight(D_80383010.zoombox[i], _t);
                }
                else if(D_8036C58C[D_80383010.unk0_15].unk0 == 0xB){
                    _t = (!(i == 0) && !(i == 1));
                    gczoombox_highlight(D_80383010.zoombox[i], _t);
                }
                else{
                    gczoombox_highlight(D_80383010.zoombox[i], 1);
                }
            }
            break;

        case 8: /* 8B54C 803124DC 44809000 */
            D_80383010.unk4 = 0;
            D_80383010.unkC = 0.0f;
            func_8031209C(D_8036C520, 4);
            D_80383010.unk8 = -0x10;
            D_80383010.unk6 = 0xFF;
            D_80383010.unk0_5 = 1;
            break;

        case 0xA:
            D_80383010.unk0_5 = 1;
            D_80383010.unk5 = 4;
            D_80383010.unkC = 0.0f;
            if(D_80383010.unk9 != 0xC){
                D_80383010.unk0_2 = 0;
            }
            func_8031209C(D_8036C520, 4);
            break;

        case 0xB:
            if(D_80383010.unk0_15 != 0 && D_80383010.unk0_15 == func_80312034(level_get())){
                func_802F5188();
            }
            func_803117A0();
            func_80311854();
            break;

        case 0xC:
            D_80383010.unk0_23 = 2;
            D_80383010.unk6++;
            D_80383010.unk0_5 = 1;
            D_80383010.unk5 = 0;
            for(i = 0; i<4; i++){
                D_80383010.unk5 += func_803188B4(D_80383010.zoombox[i]);
            }
            break;

        case 0xD:/* 8B694 80312624 3C128038 */
            D_80383010.unk6 = 0xFF;
            D_80383010.unk0_5 = 1;
            if(D_80383010.unk0_15 != 0 && D_80383010.unk0_15 == func_80312034(level_get())){
                func_802F5188();
            }
            D_80383010.unk0_15 = D_80383010.unk9;
            if(D_80383010.unk0_15 != 0 && D_80383010.unk0_15 == func_80312034(level_get())){
                func_802F5060(0x6e7);
            }
            if(D_80383010.unk0_15 != 0)
                func_80311D74(D_8036C58C[D_80383010.unk0_15].unk0);
            else{
                func_80311F48();
            }
            for(i = 0; i < 4; i++){//L803126D8
                //L80312764
                if(D_8036C58C[D_80383010.unk0_15].unk0 == 6){
                    _t = (!(i == 0) || !(i == 2));
                    gczoombox_highlight(D_80383010.zoombox[i], _t);
                }
                else if(D_8036C58C[D_80383010.unk0_15].unk0 == 0xB){//L80312728
                    _t = (!(i == 0) && !(i == 1));
                    gczoombox_highlight(D_80383010.zoombox[i], _t);
                }
                else{
                    gczoombox_highlight(D_80383010.zoombox[i], 1);
                }
                if(func_80318604(D_80383010.zoombox[i])){
                    gczoombox_maximize(D_80383010.zoombox[i]);
                    func_803183A4( D_80383010.zoombox[i], D_8036C520[i].str);
                }
                //L8031279C
            }
            break;
        
        case 0xE:/* 8B824 803127B4 3C128038 */
            D_80383010.unk0_23 = 4;
            D_80383010.unk0_15 = D_80383010.unk9;
            D_80383010.unk9 = -1;
            D_80383010.unk5C = assetcache_get(0x50D);
            D_80383010.unk60 = assetcache_get(0x50C);
            for(i = 0; i < 7; i++){
                D_80383010.unk3C[i+1] = randf2(0.0f, 360.0f);
                D_80383010.unk4A[i] =  ((i & 1)? -1.0: 1.0)*randf2( 60.0f, 180.0f);
            }
            break;

        case 0xF: /* 8B8FC 8031288C 3C128038 */
            D_80383010.unk8 = -0x10;
            D_80383010.unk6 = 0xff;
            D_80383010.unk0_5 = D_80383010.unk3A =  1;
            break;

        case 0x10:
            break;

        case 0x11: /* 8B944 803128D4 3C128038 */
            D_80383010.unk0_5 = 1;
            D_80383010.unk3A =  0;
            if(D_80383010.unk9 == -1)
                D_80383010.unk0_1 = 0;
            break;

        case 0x12: /* 8B978 80312908 3C128038 */
            D_80383010.unk0_15 = D_80383010.unk9;
            func_8033BD20(D_80383010.unk5C);
            func_8033BD20(D_80383010.unk60);
            break;

        case 0x13: /* 8B9A8 80312938 3C128038 */
            D_80383010.unk0_7 = 0;
            break;

        case 0x14: /* 8B9C0 80312950 3C128038 */
            D_80383010.unk0_6 = 0;
            D_80383010.unk0_7 = D_80383010.unk0_6;
            D_80383010.unkC = 0.0;
            func_8025A430(-1, 0x7D0, 3);
            func_8025A2B0();
            func_802DC528(0,0);
            break;
        default:
            break;
    }
    D_80383010.unk0_31 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_803120FC.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_803129DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80312B04.s")

s32 func_80312B84(void){ return 1; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80312B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80312D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80312E80.s")

func_80312F88(s32 arg0){
    struct1Cs *v0 = D_8036C58C + arg0;
    print_bold_overlapping(v0->x, D_80383010.unk8, -1.05f, v0->string);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80312FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80313070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_8031307C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80313134.s")


#ifdef NONMATCHING
s32 func_80313380(void){
    s32 temp;
    s32 sp6C[6];
    s32 sp60[3];
    s32 sp50[4];
    f32 sp48[2];
    s32 level = level_get(); //sp44
    s32 i;
    
    
    if(getGameMode() != GAME_MODE_4_PAUSED)
        return 0;
    
    func_8024E55C(0, sp6C);
    func_8024E71C(0, sp48);
    func_8024E60C(0, sp60);
    func_8024E6E0(0, sp50);
    func_80310D2C();
    for(i = 0; i < 4; i++){
        gczoombox_update(D_80383010.zoombox[i]);//gczoombox_update;
    }

    
    D_80383010.unkC += time_getDelta();
    switch(D_80383010.unk0_31){
        case 0: //closed
            func_803120FC(1); 
            break;
        case 1: //opening
            if(func_80312D78(D_8036C4E0, 4) == 4){
                if(((D_80383010.unk70_29)? 3: 4 ) == D_80383010.unk4){
                    D_80383010.unk4 = 0;
                    func_803120FC(2);
                }
            }
            if(func_8024E67C(BUTTON_START) == 1){
                func_803120FC(6);
            }
            break;
        case 2: //open
            if(D_80383010.unk70_31 && !func_802FC3C4()){
                func_802FACA4(ITEM_12_JINJOS);
                D_80383010.unk70_31 = 0;
            }//L8031350C
            if(D_80383010.unk70_30 && !func_802FD2D4()){
                func_802FACA4(ITEM_16_LIFE);
                D_80383010.unk70_30 = 0;
            }
            if(func_8024E67C(BUTTON_START) == 1){
                func_803120FC(6);
            }else if(sp6C[0] == 1){
                switch(D_80383010.unk0_15){
                    case 1://L80313594
                        if(level > 0 && level < 0xC)
                            if(D_8036C560[level-1].map != -1)
                                func_803120FC(5);
                        break;
                    case 3://L803135D0
                        func_803120FC(5);
                        break;
                    default://L803135E4
                        func_803120FC(3);
                        break;
                }
            }
            else if(sp6C[1] == 1){//L803135F8
                gczoombox_highlight(D_80383010.zoombox[D_80383010.unk0_15], 0);
                D_80383010.unk0_15 = 0;
                gczoombox_highlight(D_80383010.zoombox[D_80383010.unk0_15], 1);
                func_803120FC(3);
            }
            else if(D_80383010.unk7 > 0) {//L8031364C
                D_80383010.unk7--;
            }//L80313664
            else {
                if( D_80383010.unk0_15 == 2 && !D_80383010.unk0_6){
                    func_803160A8(D_80383010.zoombox[D_80383010.unk0_15]);
                    D_80383010.unk0_6 = 1;
                }
                if(0.75 < sp48[1]){
                    if((s32)D_80383010.unk0_15 > 0){
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.unk0_15], 0);
                        D_80383010.unk0_15--;
                        if(D_80383010.unk70_29 && D_80383010.unk0_15 == 1)
                            D_80383010.unk0_15 --;
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.unk0_15], 1);
                        func_803160A8(D_80383010.zoombox[D_80383010.unk0_15]);
                        D_80383010.unk0_6 = 0;
                        D_80383010.unk7 = 6;
                    }
                }else if(sp48[1] < -0.75){
                    if((s32)D_80383010.unk0_15 < 3){
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.unk0_15], 0);
                        D_80383010.unk0_15++;
                        if(D_80383010.unk70_29 && D_80383010.unk0_15 == 1)
                            D_80383010.unk0_15++;
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.unk0_15], 1);
                        func_803160A8(D_80383010.zoombox[D_80383010.unk0_15]);
                        D_80383010.unk0_6 = 0;
                        D_80383010.unk7 = 6;
                    }
                }
            }
            temp = D_80383010.unk0_15;
            if(temp == 2 && !D_80383010.unk0_6 && D_80383010.unk7 == 3){
                func_803160A8(D_80383010.zoombox[D_80383010.unk0_15]);
                D_80383010.unk0_6 = 1;
            }
            break;
        
        case 3: //returning to game
            func_80312E80(D_8036C4E0,4);
            if(D_80383010.unk5 <= 0){
                for(i = 0; i<4; i++){
                    gczoombox_close(D_80383010.zoombox[i]);
                }
                D_80383010.unk5 = 0x7F;
            }
            if(D_80383010.unk4 == 4){
                D_80383010.unk4 = 0;
                func_803120FC(4);
            }
            break;
        case 4:
            switch(D_80383010.unk0_15){
                case 0://L803138FC
                    D_80383010.unk0_7 = 1;
                    break;
                case 1://L80313908 //return to lair
                    func_803204E4(0x16, 1);
                    if(map_get() == MAP_LAIR_FURNACE_FUN){
                        func_803204E4(0,0);
                        func_802E4078(MAP_LAIR_FF_ENTRANCE, 2, 1);
                    }else{
                        func_802E4078(D_8036C560[level-1].map, D_8036C560[level-1].exit, 1);
                    }
                    func_803120FC(0x13);
                    break;
                case 2://L80313978
                    D_80383010.unk0_15 = func_80312034(level_get());
                    func_803120FC(7);
                    break;
                case 3://L8031399C
                    func_802C5994();
                    func_803204E4(0,0);
                    if(!func_8031FF1C(BKPROG_BD_ENTER_LAIR_CUTSCENE) || func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)){
                        func_803120FC(0x14);
                    }else{
                        func_802E412C(1,0);
                        func_802E4078(MAP_CUTSCENE_GAMEOVER, 0, 1);
                        func_803120FC(0x13);
                    }
                    break;
            }
            break;
            case 5:
                if(3.0 < D_80383010.unkC){
                    if( D_8036C4E0[D_80383010.unk0_15].unkF){
                        gczoombox_minimize(D_80383010.zoombox[D_80383010.unk0_15]);
                    }
                    D_80383010.unk0_6 ^= 1;
                    gczoombox_maximize(D_80383010.zoombox[D_80383010.unk0_15]);
                    if(D_8036C4E0[D_80383010.unk0_15].unkF = func_803183A4(D_80383010.zoombox[D_80383010.unk0_15], (D_80383010.unk0_6)? "ARE YOU SURE?" : "A - YES, B - NO"))
                        D_80383010.unkC = 0.0;
                }//L80313AF4
                if(func_8024E67C(BUTTON_START) == 1){
                    func_803120FC(6);
                }else if(sp6C[1] == 1){
                    D_80383010.unk4 = (D_80383010.unk70_29)? 3 : 4;
                    func_803188B4(D_80383010.zoombox[D_80383010.unk0_15]);
                    func_803120FC(1);
                }else if(sp6C[0] == 1){//L80313B68
                    func_803120FC(3);
                }
                break;

            case 6://80313B80
                if(D_80383010.unk4 == 4){
                    if(0.2 < D_80383010.unkC){
                        D_80383010.unk4 = 0;
                        func_803120FC(4);
                    }
                }
                break;
            
            case 7:
                func_803120FC(8);
                break;
            case 8:
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(1);
                func_80312D78(D_8036C520,4);
                func_80313134();
                if(D_80383010.unk4 == 4){
                    D_80383010.unk4 = 0;
                    func_803120FC(9);
                }
                break;
            case 9:
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(1);
                func_80313134();
                if(func_8024E67C(BUTTON_START) == 1){
                    D_80383010.unk0_23 = 3;
                    func_803120FC(0xA);
                }else if(sp6C[1] == 1){
                    func_803120FC(0xA);
                }else if(0.75 < sp48[0]){
                    if((s32)D_80383010.unk0_15 < func_80313070())
                        func_8031307C(1);
                }else if(sp48[0] < -0.75){//L80313CCC
                    if((s32)D_80383010.unk0_15 > 0){
                        func_8031307C(-1);
                    }
                }
                break;
            
            case 0xA://80313D00
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(-1);
                func_80312E80(D_8036C520, 4);
                func_80313134();
                if(D_80383010.unk9 != 0xC){
                    D_80383010.unk0_3 = 0;
                    D_80383010.unk0_2 = 0;
                }//L80313D50
                if(!D_80383010.unk5){
                    for(i = 0; i < 4; i++){
                        gczoombox_close(D_80383010.zoombox[i]);
                    }
                    D_80383010.unk5 = 1;
                }//L80313D8C
                if( D_80383010.unk4 == 4){
                     D_80383010.unk4 = 0;
                    func_803120FC(0xB);
                }
                break;
            
            case 0xB:
                if(D_80383010.unk0_23 == 3){
                    D_80383010.unk0_7 = 1;
                }
                else{
                    func_803120FC((D_80383010.unk9 == 0xC)? 0xE : 0);
                }
                break;

            case 0xC:
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(-1);
                func_80313134();
                if(D_80383010.unk5 == 0 && !D_80383010.unk0_5){
                    func_803120FC(0xd);
                }
                break;
            
            case 0xD:
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(1);
                func_80313134();
                if(D_80383010.unk7 > 0)
                    D_80383010.unk7--;
                else
                   func_803120FC(9);
                break;

            case 0xE:
                func_803120FC(0xF);
                break;

            case 0xF:
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(1);
                func_80313134();
                if(!D_80383010.unk0_5){
                    func_803120FC(0x10);
                }
                break;
            
            case 0x10:
                func_80312F88(D_80383010.unk0_15);
                func_80313134();
                if(func_8024E67C(BUTTON_START) == 1){
                    D_80383010.unk0_23 = 3;
                    func_803120FC(0x11);
                }//L80313EFC
                else if(sp6C[1] == 1){
                    func_803120FC(0x11);
                }
                else if(sp48[0] < -0.75){
                    func_8031307C(-1);
                    func_803120FC(0x11);
                }
                break;

            case 0x11:
                func_80312F88(D_80383010.unk0_15);
                func_80312FD0(-1);
                func_80313134();
                if(D_80383010.unk9 == -1){
                    D_80383010.unk0_3 = 0;
                    D_80383010.unk0_2 = 0;
                }
                if(D_80383010.unk3C[0] == 0){
                    func_803120FC(0x12);
                }
                break;

            case 0x12:
                if(D_80383010.unk0_23 == 3){
                    D_80383010.unk0_7 = 1;
                }else{
                    func_803120FC((D_80383010.unk9 != -1)?7:0);
                }
                break;

            case 0x14:
                func_802DC5B8();
                if( 5.0 < D_80383010.unkC){
                    if(!D_80383010.unk0_6){
                        func_802DC560(0,0);
                        func_802E412C(1,0);
                        func_802E4078(0x1f, 0, 1);
                        D_80383010.unk0_6 = 1;
                    }
                }
                break;

    }
    return D_80383010.unk0_7;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80313380.s")
#endif

void __pause_drawSprite(Gfx** gdl, Mtx** mptr, void* vptr, BKSprite* sprite, s32 frame, f32 x, f32 y, f32 w, f32 h, u8 a){
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    BKSpriteFrame *_frame;
    f32 sp2C;
    f32 sp28;
    
    _frame = spriteGetFramePtr(sprite, frame);
    sp2C = _frame->w;
    sp28 = _frame->h;
    func_803382E4(5);
    func_80338338(0xFF, 0xFF, 0xFF);
    func_803382FC(a);
    func_8033837C(0);
    func_8024C5CC(sp50);
    
    sp34 = func_8024DE1C(x, y, sp5C, sp44);
    mlMtxIdent(); //matrix_stack_identity
    sp38[0] = sp5C[0] - sp50[0];
    sp38[1] = sp5C[1] - sp50[1];
    sp38[2] = sp5C[2] - sp50[2];
    mlMtxTranslate(sp38[0], sp38[1], sp38[2]); //mtx_translate
    mlMtxRotYaw(sp44[1]); //mtx_rot_yaw
    mlMtxRotPitch(sp44[0]); //mtx_rot_pitch
    mlMtxRotRoll(sp44[2]); //mtx_rot_roll
    mlMtxScale_xyz((sp34 * w)/sp2C, (sp34 * h)/sp28, sp34);
    mlMtxApply(*mptr); //add matrix;
    gSPMatrix((*gdl)++, (*mptr)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80338308((s32)sp2C, (s32)sp28);
    func_80336904(gdl, vptr, sprite, frame);
    gSPPopMatrix((*gdl)++, G_MTX_MODELVIEW);
}


void func_80314234(Gfx** gdl, Mtx** mptr, s32 vptr, BKSprite *sprite, s32 frame, f32 x, f32 y, s32 mirror, u8 a){
    BKSpriteFrame *_frame; 
    s32 w;
    s32 h;
    _frame = spriteGetFramePtr(sprite, frame);
    w = ((mirror)? -1 : 1) * _frame->w;
    h = _frame->h;
    __pause_drawSprite(gdl, mptr, vptr, sprite, frame, (x - w * 0.5), (y - h * 0.5), w, h, a);
}

#ifdef NONMATCHING
void func_80314320(Gfx **gdl, Mtx **mptr, s32 arg2){
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    s32 i;
    s32 j;
    f32 sp7C;

    if(getGameMode() != GAME_MODE_4_PAUSED){
        if(!D_8036C620)
            func_803151D0(gdl, mptr, arg2);
        D_8036C620 = 1;
    }else{
        if(D_8036C620){
            func_8033B61C();
            func_80315084(gdl, mptr, arg2); //viBuffer_2_zBuffer
            D_8036C620 = 0;
        }else{
            func_80315110(gdl, mptr, arg2); //zBuffer_2_viBuffer
        }//L803143D8

        //draw_zoomboxes
        for(i = 0; i < 4; i++){
            gczoombox_draw(D_80383010.zoombox[i], gdl, mptr, arg2); 
        }

        //draw_control_stick_sprites
        func_80314234(gdl, mptr, arg2, D_80383010.unk24, D_80383010.unkA, 30.0f, 196.0f, 1, D_80383010.unk34);
        func_80314234(gdl, mptr, arg2, D_80383010.unk24, D_80383010.unkA, (f32)(D_80276588 - 30), 196.0f, 0, D_80383010.unk36);
        if(D_80383010.unk0_3 && D_80383010.unk34 < 0xFF){
            D_80383010.unk34 = MIN(D_80383010.unk34 + 0xC, 0xFF);
        }
        if(!D_80383010.unk0_3 && D_80383010.unk34 > 0){
            D_80383010.unk34 = MAX(D_80383010.unk34 - 0xC, 0);
        }
        if(D_80383010.unk0_2 && D_80383010.unk36 < 0xFF){
            D_80383010.unk36 = MIN(D_80383010.unk36 + 0xC, 0xFF);
        }
        if(!D_80383010.unk0_2 && D_80383010.unk36 > 0){
            D_80383010.unk36 = MAX(D_80383010.unk36 - 0xC, 0);
        }

        //draw_b_button
        func_80314234(gdl, mptr, arg2, D_80383010.unk2C, D_80383010.unk30, D_80276588 * 0.5, 196.0f, 0, D_80383010.unk32);
        if(D_80383010.unk0_1 && D_80383010.unk32 < 0xFF){
            D_80383010.unk32 = MIN(D_80383010.unk32 + 0xC, 0xFF);
        }
        if(!D_80383010.unk0_1 && D_80383010.unk32 > 0){
            D_80383010.unk32 = MAX(D_80383010.unk32 - 0xC, 0);
        }

        //L80314664
        if(D_80383010.unk3C[0]){//L80314690
            sp7C = time_getDelta();
            for(i = 1; i<7; i++){
                if(sns_get_item_state(i, 0)){
                    D_80383010.unk3C[i] = (s16) ((f32)D_80383010.unk3C[i] + D_80383010.unk4A[i]*sp7C);
                    if(360.0 < (f64)D_80383010.unk3C[i]){
                        D_80383010.unk3C[i] = D_80383010.unk3C[i] - 360.0;
                    }//L80314728
                    if((f64)D_80383010.unk3C[i] < 0.0){
                        D_80383010.unk3C[i] = D_80383010.unk3C[i] + 360.0;
                    }//L80314748

                    func_8024E258();
                    sp98[0] = ((i-1)*0.4)*360.0 + -360.0;
                    sp98[1] = 0.0f;
                    sp98[2] = 1000.0f;
                    sp8C[0] = 0.0f;
                    sp8C[1] = 0.0f;
                    sp8C[2] = 0.0f;
                    
                    func_8024CD88(sp98);
                    func_8024CE18(sp8C);
                    func_8024CFD4();
                    func_8024C904(gdl, mptr);
                    for(j = 1; j < 7 ; j++){
                        func_8033A45C(j, 0);
                    }
                    func_8033A45C(i, 1);

                    sp98[0] = 0.0f;
                    sp98[1] = 0.0f;
                    sp98[2] = 0.0f;
                    sp8C[0] = 0.0f;
                    sp8C[1] = 0.0f;
                    sp8C[2] = 0.0f;
                    sp80[0] = 0.0f;
                    sp80[1] = -50.0f;
                    sp80[2] = 0.0f;
                    
                    set_model_render_mode(0);
                    func_8033A410(D_80383010.unk3C[0]);
                    func_803391A4(gdl, mptr, sp98, sp8C, 0.8f, sp80, D_80383010.unk5C);
                    func_8024E2FC();
                    func_8024C904(gdl, mptr);
                }
            }//L80314880
            if(sns_get_item_state(7,0)){
                D_80383010.unk3C[1]  += D_80383010.unk4A[1] *  sp7C;
                if(360.0 < D_80383010.unk3C[1]){
                    D_80383010.unk3C[1] -= 360.0;
                }
                if(D_80383010.unk3C[1] > 0.0){
                    D_80383010.unk3C[1] += 360.0;
                }
                func_8024E258();
                sp98[0] = 0.0f;
                sp98[1] = 0.0f;
                sp98[2] = 1000.0f;
                sp8C[0] = 0.0f;
                sp8C[1] = 0.0f;
                sp8C[2] = 0.0f;
                func_8024CD88(sp98);
                func_8024CE18(sp8C);
                func_8024CFD4();
                func_8024C904(gdl, mptr);

                sp98[0] = 0.0f;
                sp98[1] = 0.0f;
                sp98[2] = 0.0f;
                sp8C[0] = 0.0f;
                sp8C[1] = D_80383010.unk3C[1];
                sp8C[2] = 0.0f;
                sp80[0] = 0.0f;
                sp80[1] = 120.0f;
                sp80[2] = 0.0f;
                set_model_render_mode(0);
                func_8033A410(D_80383010.unk3C[0]);
                func_803391A4(gdl, mptr, sp98, sp8C, 0.8f, sp80, D_80383010.unk60);
                func_8024E2FC();
                func_8024C904(gdl, mptr);
            }//L80314A20
        }
        //L80314A20
        if(D_80383010.unk3A && D_80383010.unk3C[0] < 0xFF){
            D_80383010.unk3C[0] = MIN(D_80383010.unk3C[0] + 0xC, 0xFF);
        }
        if(!D_80383010.unk3A && D_80383010.unk3C[0] > 0){
            D_80383010.unk3C[0] = MAX(D_80383010.unk3C[0] - 0xC, 0);
        }
        if(D_80383010.unk0_31 == 0x14){
            func_802DC604(gdl, mptr, arg2);
        }
        
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/pauseMenu/func_80314320.s")
#endif

void func_80314AC8(int arg0){
    if(arg0)
        D_80383084--;
    else
        D_80383084++;
}

int func_80314B00(void){
    return (!D_80383084) ? 1: 0;
}

void func_80314B24(void){
    D_80383084 = 0;
}

void func_80314B30(void){
    s32 level = level_get();
    if(0 < level && level < 0xC && D_8036C560[level-1].map != -1){
        func_803204E4(0x16, 1);
        func_802E4078(D_8036C560[level-1].map, D_8036C560[level-1].exit, 1);
    }
}
