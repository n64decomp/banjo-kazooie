#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef enum {
    MA_SNOWY_STATE_0_NONE,
    MA_SNOWY_STATE_1_ACTIVE,
    MA_SNOWY_STATE_2_WIN,
    MA_SNOWY_STATE_3_DONE
} MaSnowyState;

f32 D_80391EB0[3] = {-625.0f, 8840.0f, -111.0f};

/* .bss */
static struct {
    u8  state;
    s32 remaining;
    s32 total;
    s32 delay;
    f32 spawn_pos[3];
    u8 jiggySpawnerExists;
} Me;

/* .code */
void maSnowy_init(void){
    if( gsworld_get_map() != MAP_27_FP_FREEZEEZY_PEAK
        || jiggyscore_isCollected(JIGGY_31_FP_SIR_SLUSH)
        || jiggyscore_isSpawned(JIGGY_31_FP_SIR_SLUSH)
    ){
        Me.state = MA_SNOWY_STATE_0_NONE;
        return;
    }

    Me.jiggySpawnerExists = 0;
    if(nodeProp_findPositionFromActorId(0x128, Me.spawn_pos)){
        Me.jiggySpawnerExists = 1;
    }
    Me.state = MA_SNOWY_STATE_1_ACTIVE;
    Me.remaining = 0;
    Me.total = 0;
}

void maSnowy_end(void){}

void maSnowy_update(void){
    switch(Me.state){
        case MA_SNOWY_STATE_0_NONE:
            break;

        case MA_SNOWY_STATE_1_ACTIVE:
            if(Me.remaining)  break;
            if(!Me.total) break;

            Me.state = MA_SNOWY_STATE_2_WIN;
            Me.delay = 0;
            break;

        case MA_SNOWY_STATE_2_WIN:
            if(Me.delay >= 75){
                if(Me.jiggySpawnerExists){
                    gcStaticCamera_activate(0x12);
                    jiggy_spawn(JIGGY_31_FP_SIR_SLUSH, Me.spawn_pos);
                    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM,
                        reinterpret_cast(s32, Me.spawn_pos[0]),
                        reinterpret_cast(s32, Me.spawn_pos[1]),
                        reinterpret_cast(s32, Me.spawn_pos[2])
                    );
                }
                // * WARNING * :masnowy.c: Jigsaw 49 CANNOT find it's bootup marker point
                Me.state = MA_SNOWY_STATE_3_DONE;
            }
            else{
                Me.delay++;
            }
            break;

        case MA_SNOWY_STATE_3_DONE:
            break;
    }
}

void maSnowy_decRemaining(void){
    Me.remaining--;
}

void maSnowy_incTotal(void){
    Me.total++;
    Me.remaining++;
}
