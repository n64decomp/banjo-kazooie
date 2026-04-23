#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "../CC.h"

/* .data */
f32 maClankerRingsJiggyPosition[3] = {0.0f, 1300.0f, -2800.0f};

#define RINGS_TIMER 48 // Seconds
#define RING_COUNT   9

/* .bss */
struct {
    u8 currentActiveRing;
    u8 isMinigameActive;
    f32 timer1;
    f32 timer2;
} maClankerRings;

/* .code */
void func_80387F80(void){
    func_8034E71C(func_8034C5AC(0x131), 0x190, 0.0f);
}

void maClankerRings_startMinigame(void){
    item_set(ITEM_0_HOURGLASS_TIMER, RINGS_TIMER * 60 - 1);
    item_set(ITEM_6_HOURGLASS, 1);
    maClankerRings.isMinigameActive = 1;
}

void maClankerRings_endMinigame(void){
    item_set(ITEM_6_HOURGLASS, 0);
    maClankerRings.isMinigameActive = 0;
}

s32 maClankerRings_isMinigameActive(void){
    if(maClankerRings.currentActiveRing > 0 && maClankerRings.currentActiveRing < 0xA){
        return maClankerRings.currentActiveRing;
    }
    return 0;
}

void maClankerRings_passRing(s32 ring_num){
    if(ring_num == maClankerRings.currentActiveRing){
        if(ring_num == 1){
            maClankerRings_startMinigame();
        }
        maClankerRings.currentActiveRing++;
        if(maClankerRings.currentActiveRing >= RING_COUNT){
            maClankerRings_endMinigame();
            maClankerRings.timer2 = 1.0f;
        }
        coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
    }
    else{//L803880BC
        coMusicPlayer_playMusic(COMUSIC_2C_BUZZER, 28000);
    }
}

void maClankerRings_release(void){
    if(maClankerRings.currentActiveRing != 0){
        maClankerRings_endMinigame();
    }
}

void maClankerRings_init(void){
    maClankerRings.currentActiveRing = 0;
    if(gsworld_getMap() == MAP_22_CC_INSIDE_CLANKER){
        if(jiggyscore_isSpawned(JIGGY_1C_CC_RINGS)){
            timedFunc_set_0(0.0f, func_80387F80);
        }
        else{
            maClankerRings.currentActiveRing = 1;
            maClankerRings.isMinigameActive = 0;
            maClankerRings.timer2 = 0.0f;
            maClankerRings.timer1 = 0.0f;
        }
    }
}

void maClankerRings_update(void){
    f32 player_position[3];
    f32 time_delta = time_getDelta();
    s32 tmp_v0;

    if(maClankerRings.currentActiveRing != 0){
        maClankerRings.timer1 += time_delta;
        player_getPosition(player_position);
        if(ml_timer_update(&maClankerRings.timer2, time_delta)){
            coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(2.0f, 0);
            timedJiggySpawn(2.1f, JIGGY_1C_CC_RINGS, maClankerRingsJiggyPosition);
            func_80324E38(5.0f, 0);
            timed_exitStaticCamera(5.0f);
            tmp_v0 = func_8034C5AC(0x131);
            if(tmp_v0){
                func_8034E78C(tmp_v0, 0x190, 12.0f);
            }
            maClankerRings.timer1 = 0.0f;
        }//L80388264
        if(!(maClankerRings.currentActiveRing < 2) && maClankerRings.isMinigameActive != 0){
            if( (player_position[0] < -1100.0f && player_position[1] < -40.0f)
                || (1560.0f < player_position[0])
                || (2850.0f < player_position[2])
                || (player_position[2] < -3000.0f)
                || (maClankerRings.currentActiveRing < RING_COUNT && item_empty(ITEM_6_HOURGLASS))
            ){
                maClankerRings_endMinigame();
                coMusicPlayer_playMusic(COMUSIC_3C_MINIGAME_LOSS, 28000);
                maClankerRings_release();
                maClankerRings_init();
            }
        }//L8038834C
    }//L8038834C
}

