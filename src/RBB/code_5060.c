#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorInfo D_80390FD0;

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 *unk4;
}ActorLocal_RBB_5060;

void func_8038B654(Actor * this);

/* .data */
ActorInfo D_80390A50 = {
    0x2D, 0x1C5, 0x0, 0x0, NULL,
    func_8038B654, NULL, func_80325340,
    0, 0, 0.0f, 0
};

f32 D_80390A74[3]  = {-3820.0f,   850.0f, 0.0f}; //whistle jiggy spawn position

/* .code */
void func_8038B450(Actor *actor, s32 arg1){
    actor->state = arg1;
}

void func_8038B468(void){
    func_802C8F70(225.0f);
    jiggySpawn(JIGGY_54_RBB_WHISTLE, D_80390A74);
}

void func_8038B4A0(void){
    func_8025A6EC(COMUSIC_2B_DING_B, 28000);
}

void func_8038B4C4(ActorMarker *marker){
    func_8025A6EC(COMUSIC_2C_BUZZER, 28000);
    func_8028F530(0xD);
}

void func_8038B4F4(void){
    func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    func_80324E38(1.0f, 3);
    timed_setCameraToNode(2.0f, 10);
    timedFunc_set_0(2.2f, func_8038B468);
    func_80324E88(5.0f);
    func_80324E38(5.0f, 0);
}

s32 func_8038B56C(Actor *this, s32 whistle_id, Actor *other){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(this->state != 1)
        return 0;

    if(whistle_id + 0x30 == local->unk4[local->unk0]){ //correct
        if(local->unk4[++local->unk0] == 0){ //end of string
            timedFunc_set_0(0.6f, func_8038B4F4); //spawn jiggy
            func_8038B450(this, 2);
            return 3;
        }else{
            timedFunc_set_0(0.6f, func_8038B4A0);
            return 1;
        }
    }
    else{ //wrong
        timedFunc_set_1(1.0f, func_8038B4C4, other->marker);
        local->unk0 = 0;
        return 2;
    }
}

void func_8038B654(Actor *this){
    ActorLocal_RBB_5060 *local = (ActorLocal_RBB_5060 *)&this->local;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        local->unk2 = 1;
        local->unk4 = "312111";
        if(jiggyscore_isSpawned(JIGGY_54_RBB_WHISTLE))
            func_8038B450(this, 2);
        else
            func_8038B450(this, 1);
    }
}
