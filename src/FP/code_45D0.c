#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8  unk0;
    // u8 pad1[3];
    s32 unk4;
    s32 unk8;
    f32 spawn_pos[3];
    u8  unk18;
} Struct_FP_45D0_0;

extern Struct_FP_45D0_0 D_80392F50;

/* .code */
void func_8038A9C0(void){
        if( map_get() != MAP_27_FP_FREEZEEZY_PEAK
        || jiggyscore_isCollected(JIGGY_2D_FP_SNOWMAN_BUTTONS)
        || jiggyscore_isSpawned(JIGGY_2D_FP_SNOWMAN_BUTTONS)
    ){
        D_80392F50.unk0 = 0;
        return;
    }

    D_80392F50.unk18 = 0;
    if(func_80304E24(0x15E, D_80392F50.spawn_pos)){
        D_80392F50.unk18 = 1;
    }
    D_80392F50.unk0 = 1;
    D_80392F50.unk4 = 3;
}

void func_8038AA58(void){}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_45D0/func_8038AA60.s")
#else
void func_8038AA60(void){
    switch(D_80392F50.unk0){
        // case 0:
        //     break;

        case 1:
            if(D_80392F50.unk4 <= 0){
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
                D_80392F50.unk0 = 2;
                D_80392F50.unk8 = 0;
            }
            break;

        case 2://L8038A8F4
            if(D_80392F50.unk8 >= 0x1e){

                if(D_80392F50.unk18){
                    func_802BAFE4(0x11);
                    jiggySpawn(JIGGY_2D_FP_SNOWMAN_BUTTONS, D_80392F50.spawn_pos);
                    func_802C3F04(func_802C4140, ACTOR_4C_STEAM, 
                        reinterpret_cast(s32, D_80392F50.spawn_pos[0]),
                        reinterpret_cast(s32, D_80392F50.spawn_pos[1]),
                        reinterpret_cast(s32, D_80392F50.spawn_pos[2])
                    );
                }
                D_80392F50.unk0 = 3;
            }
            else{
                D_80392F50.unk8++;
            }
            break;
        
        case 3://L8038A96C
            break;
    }
}
#endif

void func_8038AB40(void){
    D_80392F50.unk4--;
}
