#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void MMM_func_8038B6D4(f32* arg0, s32 arg1);

/* internal definitions */
typedef struct {
    s32 unk0;
    s32 unk4;
} Struct_MMM_3420_0;

typedef struct {
    u8 unk0;
    u8 unk1;
} Struct_MMM_3420_1;

void func_80389A0C(s32 arg0);

/* .data */
Struct_MMM_3420_0 D_8038BF20[] = {
    {      0, 11},
    {  0xC05,  0},
    { 0x1E00,  8},
    { 0x2400,  3},
    { 0x2A00,  1},
    { 0x3000,  0},
    { 0x3600,  8},
    { 0x3C00,  7},
    { 0x3F00,  7},
    { 0x4200,  0},
    { 0x49D0,  0},
    { 0x4E00,  8},
    { 0x5400,  3},
    { 0x5A00,  6},
    { 0x6000,  7},
    { 0x6600,  8},
    { 0x6C00,  0},
    { 0x6F00,  7},
    { 0x7200,  0},
    { 0x7800, 10},
    { 0x7E00,  3},
    { 0x8400,  8},
    { 0x8A00,  1},
    { 0x9000,  2},
    { 0x9600,  3},
    { 0x9C00,  8},
    { 0xA200,  7},
    { 0xA800,  0},
    { 0xAE00,  8},
    { 0xB400,  3},
    { 0xBA00,  6},
    { 0xC000,  7},
    { 0xC600,  8},
    { 0xCC00,  0},
    { 0xCF00,  7},
    { 0xD200,  3},
    { 0xD800,  1},
    { 0xDB00,  7},
    { 0xDE00,  1},
    { 0xE100,  0},
    { 0xE400,  1},
    { 0xE700,  7},
    { 0xEA00,  1},
    { 0xED00,  2},
    { 0xF000,  1},
    { 0xF600,  9},
    { 0xFC00,  1},
    {0x10200,  7},
    {0x10800,  1},
    {0x10E00,  9},
    {0x11400,  1},
    {0x11700,  8},
    {0x11A00,  1},
    {0x12000, 11},
    {0x12600,  4},
    {0x12C00,  9},
    {0x13200,  2},
    {0x13800, 11},
    {0x13E00,  4},
    {0x14400,  9},
    {0x14A00,  8},
    {0x15000,  1},
    {0x15600,  9},
    {0x15C00,  1},
    {0x16200,  7},
    {0x16800,  1},
    {0x16E00,  9},
    {0x17400,  1},
    {0x17700,  8},
    {0x17A00,  1},
    {0x18000,  0},
    {0x18300,  6},
    {0x18600,  3},
    {0x18900, 11},
    {0x18C00,  7},
    {0x18F60,  6},
    {0x19260,  0},
    {0x19500, 11},
    {0x19802, -1}
};

Struct_MMM_3420_1 D_8038C198[] = {
    {01, 00},
    {02, 00},
    {03, 00},
    {04, 00},
    {05, 00},
    {06, 00},
    {04, 00},
    {07, 00},
    {04, 00},
    {07, 00},
    {04, 00},
    {05, 00},
    {06, 00},
    {04, 00},
    {07, 00},
    {04, 00},
    {05, 00},
    {06, 00},
    {04, 00},
    {07, 00},
    {04, 00},
    {07, 00},
    {04, 00},
    {05, 00},
    {00, 00},
    {00, 00},
};

u8 D_8038C1CC[] = {0x7, 0xE, 0xD, 0x9, 0x11, 0, 0, 0};
u8 D_8038C1D4[] = {0xA, 0x12, 0xF, 0x9, 0xE, 0xD, 0x9, 0x11, 0xB, 0xF, 0, 0};
f32 D_8038C1E0[3] = {0.0f, 3250.0f, -3200.0f}; //jiggy spawn position

/* .bss */
extern struct {
    s32 unk0;
    ActorMarker *unk4;  //motzhand_marker
    Struct_MMM_3420_0 *unk8;
    u8 unkC;            //state
    u8 unkD;            //pattern id
    //u8 padE[2];
    u8 *unk10;
}D_8038C4F0;

/* .code */
void MMM_func_80389810(ActorMarker *caller, enum asset_e text_id, s32 arg2) {
    switch (D_8038C4F0.unkC) {
    case 2:
        func_80389A0C(3);
        return;
    case 4:
        func_80389A0C(1);
        return;
    case 5:
        func_80389A0C(3);
        return;
    case 6:
        func_80389A0C(7);
        return;
    }
}

void MMM_func_803898A0() {
    jiggySpawn(JIGGY_60_MMM_MOTZHAND, D_8038C1E0);
}

void MMM_func_803898C8() {
    func_8025A58C(0, 450);
}

void func_803898EC() {
    func_8025A58C(-1, 300);
}

void func_80389910() {
    func_80311480(0xAD5, 0xE, NULL, NULL, MMM_func_80389810, NULL);
    timedFunc_set_2(0.0f, func_8025A6EC, COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
    timed_setCameraToNode(2.0f, 0);
    timedFunc_set_0(2.1f, MMM_func_803898A0);
    timedFunc_set_0(6.0f, func_803898EC);
    func_80324E88(6.0f);
    func_80324E38(6.0f, 0);
}

void func_803899BC(void){
    func_80324E38(0.0f, 3);
    timedFunc_set_2(0.0f, (TFQM2)func_8025A6EC, COMUSIC_38_MOTZAND_BEATEN, 0x7fff);
    timedFunc_set_0(2.25f, func_80389910);
}

void func_80389A0C(s32 next_state){
    func_8028F8F8(1, FALSE);
    if(next_state == 2){
        if(D_8038C4F0.unkD == 0){
            D_8038C4F0.unkD = 1;
            func_80311480(0xad3, 4, NULL, NULL, MMM_func_80389810, NULL);
        }
        else{//L80389A84
            func_80311480(0xad6, 4, NULL, NULL, MMM_func_80389810, NULL);
        }
    }//L80389A9C

    if(next_state == 3){
        D_8038C4F0.unk0 = 0;
        if(D_8038C4F0.unkD == 1){
            D_8038C4F0.unk10 = D_8038C1CC;
        }
        else{
            D_8038C4F0.unk10 = D_8038C1D4;
        }
        func_8028F8F8(1, TRUE);
        func_803876C8(D_8038C4F0.unk4, D_8038C4F0.unkD);
    }//L80389AF4

    if(next_state == 4){
        func_80311480(0xadd, 4, NULL, NULL, MMM_func_80389810, NULL);
        func_80387720(D_8038C4F0.unk4);
    }

    if(next_state == 5){
        D_8038C4F0.unkD++;
        func_80311480(0xad4, 4, NULL, NULL, MMM_func_80389810, NULL);
        func_80387720(D_8038C4F0.unk4);
    }

    if(next_state == 6){
        MMM_func_803898C8();
        timedFunc_set_0(1.25f, func_803899BC);
        func_80387654(D_8038C4F0.unk4);
    }

    D_8038C4F0.unkC = next_state;
}

s32 func_80389BBC(void){
    return D_8038C4F0.unk8->unk4;
}

//organCtrl_getKeyPosition
void func_80389BCC(s32 key_indx, f32 position[3]) {
    Struct_MMM_3420_1 *iPtr;
    s32 is_black_key;

    position[0] = -145.0f;
    position[1] = 0.0f;
    position[2] = 0.0f;
    for (iPtr = &D_8038C198[0]; iPtr <= &D_8038C198[key_indx]; iPtr++) {
        is_black_key = (iPtr->unk0 == 2 || iPtr->unk0 == 4);
        if (is_black_key != 0) {
            position[0] += 67.0f;
            position[1] += 12.5;
            position[2] += -230.0f;
        } else {
            position[0] += 170.0f;
        }
        if (iPtr == &D_8038C198[key_indx]) 
            break;

        if (is_black_key != 0) {
            position[0] -= 67.0f;
            position[1] -= 12.5;
            position[2] -= -230.0f;
        }
    }
}

void MMM_func_80389CD8() {}

void func_80389CE0() {}

int func_80389CE8(s32 arg0, s32 arg1, s32 arg2){
    if(D_8038C4F0.unkC == 3){
        if(*D_8038C4F0.unk10 == arg2){
            D_8038C4F0.unk0--;
            D_8038C4F0.unk10++;
            if(*D_8038C4F0.unk10 == 0){
                if(D_8038C4F0.unkD == 1){
                    func_80389A0C(5);
                }
                else{
                    func_80389A0C(6);
                }
            }
            return 1;
        }//L80389D6C
        else{
            func_8028F55C(0xD,  func_80351794(arg1));
            return 2;
        }
    }
    return 0;
}

void func_80389D9C(s32 key_id){
    s32 sp24;
    sp24 = D_8038C198[key_id].unk1;
    MMM_func_8038B6D4(func_803517B8(sp24), func_803517E8(sp24));
    D_8038C4F0.unk0++;
}

void func_80389DF4(s32 arg0, s32 arg1) {
    Struct_MMM_3420_1 *iPtr;
    f32 key_position[3];
    bool is_black_key;

    D_8038C4F0.unk8 = &D_8038BF20;
    func_80250170(0, 0x6A, 0);
    D_8038C4F0.unkC = 0;
    if ((map_get() == MAP_1C_MMM_CHURCH) && (arg1 == 2)) {
        D_8038C4F0.unk4 = NULL;
        D_8038C4F0.unkD = 0;
        key_position[0] = -1345.0f;
        key_position[1] = 1150.0f;
        key_position[2] = -2300.0f;
        for(iPtr = &D_8038C198[0]; iPtr->unk0; iPtr++){
                is_black_key = (iPtr->unk0 == 2 || iPtr->unk0 == 4);
                if (is_black_key) {
                    key_position[0] += 122.0f;
                    key_position[1] += 12.5;
                } else {
                    key_position[0] += 170.0f;
                }
                iPtr->unk1 = func_80351838(key_position, iPtr->unk0, iPtr - &D_8038C198[0]);
                if (is_black_key) {
                    key_position[0] -= 122.0f;
                    key_position[1] -= 12.5;
                }
        }
        if (jiggyscore_isSpawned(JIGGY_60_MMM_MOTZHAND)) {
            func_80389A0C(7);
            return;
        }
        func_80389A0C(1);
    }
}


void func_80389FC0(void){
    UNK_TYPE(u32) sp4C;
    f32 sp48;
    Actor *motzhand;
    f32 sp38[3];
    f32 plyr_pos[3];
    Actor *motzhand_2;


    if(D_8038C4F0.unkC == 0) return;

    if(func_802501A0(0, 0x6A, &sp4C)){
        func_80250170(0, 0x6A, 0);
        D_8038C4F0.unk8++;
        if(D_8038C4F0.unk8->unk4 == -1){
            D_8038C4F0.unk8 = &D_8038BF20[10];
        }
    }//L8038A02C

    if(D_8038C4F0.unkC == 1 && D_8038C4F0.unk4 == NULL){
        sp38[0] = sp38[1] = sp38[2] = 0.0f;
        motzhand = func_80326D68(sp38, ACTOR_3A_MOTZHAND, -1, &sp48);
        D_8038C4F0.unk4 = motzhand->marker;
    }//L8038A078

    if(D_8038C4F0.unkC == 1 || D_8038C4F0.unkC == 3){
        if(func_8038769C(D_8038C4F0.unk4)){
            player_getPosition(plyr_pos);
            motzhand_2 = marker_getActor(D_8038C4F0.unk4);
            if( ml_vec3f_distance(motzhand_2->position, plyr_pos) < 400.0f
                && motzhand_2->position_y - 50.0f <= plyr_pos[1]
            ){
                func_80389A0C(2);
            }
        }
    }//L8038A104

    if(D_8038C4F0.unkC == 3 && D_8038C4F0.unk0 >= 3){
        func_80389A0C(4);
    }
}
