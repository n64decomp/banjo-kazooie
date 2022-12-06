#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 D_80391EB0[3] = {-625.0f, 8840.0f, -111.0f};
/* .bss */
struct {
    u8  unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 spawn_pos[3];
    u8 unk1C;
} D_80392F30;

/* .code */
void func_8038A7F0(void){
    if( map_get() != MAP_27_FP_FREEZEEZY_PEAK
        || jiggyscore_isCollected(JIGGY_31_FP_SIR_SLUSH)
        || jiggyscore_isSpawned(JIGGY_31_FP_SIR_SLUSH)
    ){
        D_80392F30.unk0 = 0;
        return;
    }

    D_80392F30.unk1C = 0;
    if(nodeProp_findPositionFromActorId(0x128, D_80392F30.spawn_pos)){
        D_80392F30.unk1C = 1;
    }
    D_80392F30.unk0 = 1;
    D_80392F30.unk4 = 0;
    D_80392F30.unk8 = 0;
}

void func_8038A888(void){}

void func_8038A890(void){
    switch(D_80392F30.unk0){
        case 0:
            break;

        case 1://L8038A8CC
            if(D_80392F30.unk4)  break;
            if(!D_80392F30.unk8) break;

            D_80392F30.unk0 = 2;
            D_80392F30.unkC = 0;
            break;

        case 2://L8038A8F4
            if(D_80392F30.unkC >= 0x4b){

                if(D_80392F30.unk1C){
                    func_802BAFE4(0x12);
                    jiggySpawn(JIGGY_31_FP_SIR_SLUSH, D_80392F30.spawn_pos);
                    __spawnQueue_add_4((GenMethod_4)func_802C4140, ACTOR_4C_STEAM, 
                        reinterpret_cast(s32, D_80392F30.spawn_pos[0]),
                        reinterpret_cast(s32, D_80392F30.spawn_pos[1]),
                        reinterpret_cast(s32, D_80392F30.spawn_pos[2])
                    );
                }
                D_80392F30.unk0 = 3;
            }
            else{
                D_80392F30.unkC++;
            }
            break;

        case 3://L8038A96C
            break;
    }
}

void func_8038A978(void){
    D_80392F30.unk4--;
}

void func_8038A990(void){
    D_80392F30.unk8++;
    D_80392F30.unk4++;
}
