#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8034E78C(void *, s32, f32);

/* .data */
f32 D_80389BF0[3] = {0.0f, 1300.0f, -2800.0f}; 

/* .bss */
extern struct {
    u8 unk0;
    u8 unk1;
    //u8 pad2[2];
    f32 unk4;
    f32 unk8;
} D_80389F90;

/* .code */
void func_80387F80(void){
    func_8034E71C(func_8034C5AC(0x131), 0x190, 0.0f);
}

void func_80387FB0(void){
    item_set(ITEM_0_HOURGLASS_TIMER, 48*60 - 1);
    item_set(ITEM_6_HOURGLASS, 1);
    D_80389F90.unk1 = 1;
}

void func_80387FE8(void){
    item_set(ITEM_6_HOURGLASS, 0);
    D_80389F90.unk1 = 0;
}

s32 func_80388010(void){
    if(D_80389F90.unk0 > 0 && D_80389F90.unk0 < 0xA){
        return D_80389F90.unk0;
    }
    return 0;
}

void func_8038803C(s32 arg0){
    if(arg0 == D_80389F90.unk0){
        if(arg0 == 1){
            func_80387FB0();
        }
        D_80389F90.unk0++;
        if(D_80389F90.unk0 >= 9){
            func_80387FE8();
            D_80389F90.unk8 = 1.0f;
        }
        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
    }
    else{//L803880BC
        func_8025A6EC(COMUSIC_2C_BUZZER, 28000);
    }
}

void func_803880D4(void){
    if(D_80389F90.unk0 != 0){
        func_80387FE8();
    }
}

void func_80388104(void){
    D_80389F90.unk0 = 0;
    if(map_get() == MAP_22_CC_INSIDE_CLANKER){
        if(jiggyscore_80320F7C(JIGGY_1C_CC_RINGS)){
            timedFunc_set_0(0.0f, func_80387F80);
        }
        else{
            D_80389F90.unk0 = 1;
            D_80389F90.unk1 = 0;
            D_80389F90.unk8 = 0.0f;
            D_80389F90.unk4 = 0.0f;
        }
    }
}

void func_8038817C(void){
    f32 sp24[3];
    f32 sp20 = time_getDelta();
    s32 tmp_v0;

    if(D_80389F90.unk0 != 0){
        D_80389F90.unk4 += sp20;
        player_getPosition(sp24);
        if(func_8025773C(&D_80389F90.unk8, sp20)){
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            func_80324E38(0.0f, 3);
            func_80324E60(2.0f, 0);
            timedJiggySpawn(2.1f, JIGGY_1C_CC_RINGS, D_80389BF0);
            func_80324E38(5.0f, 0);
            func_80324E88(5.0f);
            tmp_v0 = func_8034C5AC(0x131);
            if(tmp_v0){
                func_8034E78C(tmp_v0, 0x190, 12.0f);
            }
            D_80389F90.unk4 = 0.0f;
        }//L80388264
        if(!(D_80389F90.unk0 < 2) && D_80389F90.unk1 != 0){
            if( (sp24[0] < -1100.0f && sp24[1] < -40.0f)
                || (1560.0f < sp24[0])
                || (2850.0f < sp24[2])
                || (sp24[2] < -3000.0f)
                || (D_80389F90.unk0 < 9 && item_empty(ITEM_6_HOURGLASS))
            ){
                func_80387FE8();
                func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 28000);
                func_803880D4();
                func_80388104();
            }
        }//L8038834C
    }//L8038834C
}
