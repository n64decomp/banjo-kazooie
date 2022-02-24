#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8038B6D4(f32* arg0, s32 arg1);

/* internal definitions */
typedef struct {
    u8 pad0[4];
    s32 unk4;
} Struct_MMM_3420_0;

typedef struct {
    u8 unk0;
    u8 unk1;
} Struct_MMM_3420_1;

/* .data */
extern Struct_MMM_3420_0 D_8038BF70[];
extern Struct_MMM_3420_1 D_8038C198[];
extern f32 D_8038C1E0[3];

/* .rodata */
extern f32 D_8038C450;

/* .bss */
extern struct {
    s32 unk0;
    ActorMarker *unk4;
    Struct_MMM_3420_0 *unk8;
    u8 unkC;
}D_8038C4F0;

/* .code */
void func_80389810(s32 arg0, s32 arg1, s32 arg2) {
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

void func_803898A0() {
    jiggySpawn(JIGGY_60_MMM_MOTZHAND, D_8038C1E0);
}

void func_803898C8() {
    func_8025A58C(0, 450);
}

void func_803898EC() {
    func_8025A58C(-1, 300);
}

void func_80389910() {
    func_80311480(0xAD5, 0xE, NULL, NULL, func_80389810, NULL);
    timedFunc_set_2(0.0f, func_8025A6EC, COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
    timed_setCameraToNode(2.0f, 0);
    timedFunc_set_0(D_8038C450, func_803898A0);
    timedFunc_set_0(6.0f, func_803898EC);
    func_80324E88(6.0f);
    func_80324E38(6.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_803899BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389BCC.s")

void func_80389CD8() {

}

void func_80389CE0() {

}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389CE8.s")

void func_80389D9C(s32 key_id){
    s32 sp24;
    sp24 = D_8038C198[key_id].unk1;
    func_8038B6D4(func_803517B8(sp24), func_803517E8(sp24));
    D_8038C4F0.unk0++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_3420/func_80389DF4.s")

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
            D_8038C4F0.unk8 = D_8038BF70;
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
            if( func_80256064(motzhand_2->position, plyr_pos) < 400.0f
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
