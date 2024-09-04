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

f32 D_80391EC0[3] ={-625.0f, 466.0f, -111.0f};

/* .bss */
Struct_FP_45D0_0 D_80392F50;

/* .code */
void fp_snowmanButtonGame_init(void){
        if( map_get() != MAP_27_FP_FREEZEEZY_PEAK
        || jiggyscore_isCollected(JIGGY_2D_FP_SNOWMAN_BUTTONS)
        || jiggyscore_isSpawned(JIGGY_2D_FP_SNOWMAN_BUTTONS)
    ){
        D_80392F50.unk0 = 0;
        return;
    }

    D_80392F50.unk18 = 0;
    if(nodeProp_findPositionFromActorId(0x15E, D_80392F50.spawn_pos)){
        D_80392F50.unk18 = 1;
    }
    D_80392F50.unk0 = 1;
    D_80392F50.unk4 = 3;
}

void fp_snowmanButtonGame_end(void){}

void fp_snowmanButtonGame_update(void){
    switch(D_80392F50.unk0){
        case 1:
            if(D_80392F50.unk4 <= 0){
                D_80392F50.unk0 = 2;
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
                D_80392F50.unk8 = 0;
            }
            break;

        case 2://L8038A8F4
            if(D_80392F50.unk8 >= 0x1e){

                if(D_80392F50.unk18){
                    func_802BAFE4(0x11);
                    jiggy_spawn(JIGGY_2D_FP_SNOWMAN_BUTTONS, D_80392F50.spawn_pos);
                    __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4C_STEAM, 
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
        case 0:
        case 3://L8038A96C
            break;
    }
}

void fp_snowmanButtonGame_decRemaining(void){
    D_80392F50.unk4--;
}
