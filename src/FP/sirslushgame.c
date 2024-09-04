#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 D_80391EB0[3] = {-625.0f, 8840.0f, -111.0f};
/* .bss */
struct {
    u8  state;
    s32 remaining;
    s32 total;
    s32 unkC;
    f32 spawn_pos[3];
    u8 unk1C;
} D_80392F30;

/* .code */
void fp_sirslushgame_init(void){
    if( map_get() != MAP_27_FP_FREEZEEZY_PEAK
        || jiggyscore_isCollected(JIGGY_31_FP_SIR_SLUSH)
        || jiggyscore_isSpawned(JIGGY_31_FP_SIR_SLUSH)
    ){
        D_80392F30.state = 0;
        return;
    }

    D_80392F30.unk1C = 0;
    if(nodeProp_findPositionFromActorId(0x128, D_80392F30.spawn_pos)){
        D_80392F30.unk1C = 1;
    }
    D_80392F30.state = 1;
    D_80392F30.remaining = 0;
    D_80392F30.total = 0;
}

void fp_sirslushgame_end(void){}

void fp_sirslushgame_update(void){
    switch(D_80392F30.state){
        case 0:
            break;

        case 1://L8038A8CC
            if(D_80392F30.remaining)  break;
            if(!D_80392F30.total) break;

            D_80392F30.state = 2;
            D_80392F30.unkC = 0;
            break;

        case 2://L8038A8F4
            if(D_80392F30.unkC >= 0x4b){

                if(D_80392F30.unk1C){
                    func_802BAFE4(0x12);
                    jiggy_spawn(JIGGY_31_FP_SIR_SLUSH, D_80392F30.spawn_pos);
                    __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4C_STEAM, 
                        reinterpret_cast(s32, D_80392F30.spawn_pos[0]),
                        reinterpret_cast(s32, D_80392F30.spawn_pos[1]),
                        reinterpret_cast(s32, D_80392F30.spawn_pos[2])
                    );
                }
                D_80392F30.state = 3;
            }
            else{
                D_80392F30.unkC++;
            }
            break;

        case 3://L8038A96C
            break;
    }
}

void fp_sirslushgame_decRemaining(void){
    D_80392F30.remaining--;
}

void fp_sirslushgame_incTotal(void){
    D_80392F30.total++;
    D_80392F30.remaining++;
}
