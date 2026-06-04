#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern 

void chBoomBoxMinigameCtrl_update(Actor *this);

/* .data */
ActorInfo chBoomBoxMinigameCtrl = {
    MARKER_1B8_BOOM_BOX_MINIGAME_CTRL, ACTOR_2A5_BOOM_BOX_MINIGAME_CTRL, 0x0,
    0x0, NULL,
    chBoomBoxMinigameCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

enum chboomboxminigamectrl_state_e {
    CH_BOOMBOX_MINIGAME_CTRL_STATE_0_NOT_INIT,
    CH_BOOMBOX_MINIGAME_CTRL_STATE_1_INIT,
    CH_BOOMBOX_MINIGAME_CTRL_STATE_2_PARTIAL_COMPLETE,
    CH_BOOMBOX_MINIGAME_CTRL_STATE_3_COMPLETE
};

/* .bss */
u8 chBoomBoxMinigameRemainingCount;

/* .code */
void chBoomBoxMinigameCtrl_spawnExtraLife(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    bundle_setYaw(actor->yaw);
    bundle_spawn_f32(BUNDLE_6_MM_HUT_EXTRA_LIFE, &actor->position);
}

void chBoomBoxMinigameCtrl_setState(Actor *this, s32 next_state){
    if(next_state == CH_BOOMBOX_MINIGAME_CTRL_STATE_3_COMPLETE){
        func_80324E38(0.0f, 3);
        timedFunc_set_2(1.0f, (GenFunction_2)coMusicPlayer_playMusic, COMUSIC_2B_DING_B, 28000);
        timed_setStaticCameraToNode(1.8f, 1);
        timedFunc_set_1(2.0f, (GenFunction_1) chBoomBoxMinigameCtrl_spawnExtraLife, (s32)this->marker);
        timed_exitStaticCamera(5.0f);
        func_80324E38(5.0f, 0);
    }
    this->state = next_state;
}

void chBoomBoxMinigameCtrl_countInc(void){
    chBoomBoxMinigameRemainingCount++;
}

void chBoomBoxMinigameCtrl_countDec(void){
    chBoomBoxMinigameRemainingCount--;
}

void chBoomBoxMinigameCtrl_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        chBoomBoxMinigameRemainingCount = 0;
        chBoomBoxMinigameCtrl_setState(this, CH_BOOMBOX_MINIGAME_CTRL_STATE_1_INIT);
    }

    if(this->state == CH_BOOMBOX_MINIGAME_CTRL_STATE_1_INIT){
        if(chBoomBoxMinigameRemainingCount > 0)
            chBoomBoxMinigameCtrl_setState(this, CH_BOOMBOX_MINIGAME_CTRL_STATE_2_PARTIAL_COMPLETE);
    }

    if(this->state == CH_BOOMBOX_MINIGAME_CTRL_STATE_2_PARTIAL_COMPLETE){
        if(chBoomBoxMinigameRemainingCount == 0)
            chBoomBoxMinigameCtrl_setState(this, CH_BOOMBOX_MINIGAME_CTRL_STATE_3_COMPLETE);
    }
}
