#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef enum {
    MA_SNOW_BUTTON_STATE_0_NONE,
    MA_SNOW_BUTTON_STATE_1_ACTIVE,
    MA_SNOW_BUTTON_STATE_2_WIN,
    MA_SNOW_BUTTON_STATE_3_DONE
} MaSnowButtonState;

/* .data */
f32 D_80391EC0[3] ={-625.0f, 466.0f, -111.0f};

/* .bss */
static struct {
    u8  state;
    // u8 pad1[3];
    s32 remainingButtonCount;
    s32 delay;
    f32 spawn_pos[3];
    u8  jiggySpawnerExists;
} Me;

/* .code */
void maSnowButton_init(void){
    if( gsworld_get_map() != MAP_27_FP_FREEZEEZY_PEAK
        || jiggyscore_isCollected(JIGGY_2D_FP_SNOWMAN_BUTTONS)
        || jiggyscore_isSpawned(JIGGY_2D_FP_SNOWMAN_BUTTONS)
    ){
        Me.state = MA_SNOW_BUTTON_STATE_0_NONE;
        return;
    }

    Me.jiggySpawnerExists = 0;
    if(nodeProp_findPositionFromActorId(0x15E, Me.spawn_pos)){
        Me.jiggySpawnerExists = 1;
    }
    Me.state = MA_SNOW_BUTTON_STATE_1_ACTIVE;
    Me.remainingButtonCount = 3;
}

void maSnowButton_end(void){}

void maSnowButton_update(void){
    switch(Me.state){
        case MA_SNOW_BUTTON_STATE_1_ACTIVE:
            if(Me.remainingButtonCount <= 0){
                Me.state = MA_SNOW_BUTTON_STATE_2_WIN;
                coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
                Me.delay = 0;
            }
            break;

        case MA_SNOW_BUTTON_STATE_2_WIN:
            if(!(Me.delay < 30)){

                if(Me.jiggySpawnerExists){
                    gcStaticCamera_activate(0x11);
                    jiggy_spawn(JIGGY_2D_FP_SNOWMAN_BUTTONS, Me.spawn_pos);
                    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM,
                        reinterpret_cast(s32, Me.spawn_pos[0]),
                        reinterpret_cast(s32, Me.spawn_pos[1]),
                        reinterpret_cast(s32, Me.spawn_pos[2])
                    );
                }
                // * WARNING * :maSnowButton.c: Jigsaw 45 CANNOT find it's bootup marker point

                Me.state = MA_SNOW_BUTTON_STATE_3_DONE;
            }
            else{
                Me.delay++;
            }
            break;
        case MA_SNOW_BUTTON_STATE_0_NONE:
        case MA_SNOW_BUTTON_STATE_3_DONE:
            break;
    }
}

void maSnowButton_decRemaining(void){
    Me.remainingButtonCount--;
}
