#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorInfo D_80390FD0;

typedef struct {
    s16 currentIndex;
    s16 unk2;
    u8 *codeString;
}ActorLocal_RBB_5060;

void chWhistleCtrl_update(Actor * this);

/* .data */
ActorInfo chRBBWhistleCtrl = {
    MARKER_2D_WHISTLE_CTRL, ACTOR_1C5_WHISTLE_CTRL, 0x0,
    0x0, NULL,
    chWhistleCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

f32 chRBBWhistleCtrlJiggyPosition[3] = {-3820.0f, 850.0f, 0.0f};

enum chrbbwhistlectrl_state_e {
    CH_RBB_WHISTLE_CTRL_STATE_0_NOT_INIT,
    CH_RBB_WHISTLE_CTRL_STATE_1_AWAITING_PLAYER,
    CH_RBB_WHISTLE_CTRL_STATE_2_COMPLETE
};

#define RBB_WHISTLE_CODE        "312111"

/* .code */
void __chWhistleCtrl_setState(Actor *actor, s32 arg1){
    actor->state = arg1;
}

void __chWhistleCtrl_soundWhistle(void){
    bundle_setYaw(225.0f);
    jiggy_spawn(JIGGY_54_RBB_WHISTLE, chRBBWhistleCtrlJiggyPosition);
}

void __chWhistleCtrl_correct(void){
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
}

void __chWhistleCtrl_wrong(ActorMarker *marker){
    coMusicPlayer_playMusic(COMUSIC_2C_BUZZER, 28000);
    func_8028F530(0xD);
}

void __chWhistleCtrl_complete(void){
    coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    func_80324E38(1.0f, 3);
    timed_setStaticCameraToNode(2.0f, 10);
    timedFunc_set_0(2.2f, __chWhistleCtrl_soundWhistle);
    timed_exitStaticCamera(5.0f);
    func_80324E38(5.0f, 0);
}

s32 chWhistleCtrl_newEvent(Actor *this, s32 whistle_id, Actor *other){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(this->state != CH_RBB_WHISTLE_CTRL_STATE_1_AWAITING_PLAYER)
        return 0;

    if(whistle_id + 0x30 == local->codeString[local->currentIndex]){ //correct
        if(local->codeString[++local->currentIndex] == 0){ //end of string
            timedFunc_set_0(0.6f, __chWhistleCtrl_complete); //spawn jiggy
            __chWhistleCtrl_setState(this, CH_RBB_WHISTLE_CTRL_STATE_2_COMPLETE);
            return 3;
        }else{
            timedFunc_set_0(0.6f, __chWhistleCtrl_correct);
            return 1;
        }
    }
    else{ //wrong
        timedFunc_set_1(1.0f, (GenFunction_1)__chWhistleCtrl_wrong, (s32)other->marker);
        local->currentIndex = 0;
        return 2;
    }
}

void chWhistleCtrl_update(Actor *this){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->unk2 = 1;
        local->codeString = RBB_WHISTLE_CODE;
        if(jiggyscore_isSpawned(JIGGY_54_RBB_WHISTLE))
            __chWhistleCtrl_setState(this, CH_RBB_WHISTLE_CTRL_STATE_2_COMPLETE);
        else
            __chWhistleCtrl_setState(this, CH_RBB_WHISTLE_CTRL_STATE_1_AWAITING_PLAYER);
    }
}
