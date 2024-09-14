#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorInfo D_80390FD0;

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 *unk4;
}ActorLocal_RBB_5060;

void chWhistleCtrl_update(Actor * this);

/* .data */
ActorInfo D_80390A50 = {
    0x2D, 0x1C5, 0x0, 0x0, NULL,
    chWhistleCtrl_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

f32 D_80390A74[3]  = {-3820.0f,   850.0f, 0.0f}; //whistle jiggy spawn position

/* .code */
void __chWhistleCtrl_setState(Actor *actor, s32 arg1){
    actor->state = arg1;
}

void __chWhistleCtrl_soundWhistle(void){
    func_802C8F70(225.0f);
    jiggy_spawn(JIGGY_54_RBB_WHISTLE, D_80390A74);
}

void __chWhistleCtrl_correct(void){
    func_8025A6EC(COMUSIC_2B_DING_B, 28000);
}

void __chWhistleCtrl_wrong(ActorMarker *marker){
    func_8025A6EC(COMUSIC_2C_BUZZER, 28000);
    func_8028F530(0xD);
}

void __chWhistleCtrl_complete(void){
    func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    func_80324E38(1.0f, 3);
    timed_setStaticCameraToNode(2.0f, 10);
    timedFunc_set_0(2.2f, __chWhistleCtrl_soundWhistle);
    timed_exitStaticCamera(5.0f);
    func_80324E38(5.0f, 0);
}

s32 chWhistleCtrl_newEvent(Actor *this, s32 whistle_id, Actor *other){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(this->state != 1)
        return 0;

    if(whistle_id + 0x30 == local->unk4[local->unk0]){ //correct
        if(local->unk4[++local->unk0] == 0){ //end of string
            timedFunc_set_0(0.6f, __chWhistleCtrl_complete); //spawn jiggy
            __chWhistleCtrl_setState(this, 2);
            return 3;
        }else{
            timedFunc_set_0(0.6f, __chWhistleCtrl_correct);
            return 1;
        }
    }
    else{ //wrong
        timedFunc_set_1(1.0f, __chWhistleCtrl_wrong, other->marker);
        local->unk0 = 0;
        return 2;
    }
}

void chWhistleCtrl_update(Actor *this){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->unk2 = 1;
        local->unk4 = "312111";
        if(jiggyscore_isSpawned(JIGGY_54_RBB_WHISTLE))
            __chWhistleCtrl_setState(this, 2);
        else
            __chWhistleCtrl_setState(this, 1);
    }
}
