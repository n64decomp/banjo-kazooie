#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* typedefs and declarations */
void chCageUpSwitch_update(Actor *this);
void chCageUpSwitch_setState(Actor *this, s32 arg1);

/* .data */
ActorInfo chCageUpSwitch = {
    MARKER_183_RBB_CAGE_UP_SWITCH, ACTOR_173_RBB_CAGE_UP_SWITCH, ASSET_402_MODEL_EGG_TOLL,
    0x0, NULL,
    chCageUpSwitch_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};

s32 D_80390224[4] = { 0xff, 0, 0, 0xff};
s32 D_80390234[4] = { 0x76, 0, 0, 0xff};
s32 D_80390244[4] = { 0x76, 0, 0, 0xff};
s32 D_80390254[4] = { 0xff, 0, 0, 0xff};

f32 D_80390264[3] = {-4900.0f, 0.0f, 0.0f};

enum chcageupswitch_state_e {
    CH_CAGE_UP_SWITCH_STATE_0_NOT_INIT,
    CH_CAGE_UP_SWITCH_STATE_1_NOT_PRESSED,
    CH_CAGE_UP_SWITCH_STATE_2_RAISING_CAGE,
    CH_CAGE_UP_SWITCH_STATE_3_TIMED_RAISED_CAGE,
    CH_CAGE_UP_SWITCH_STATE_4_LOWER_CAGE
};

/* .code */
void chCageUpSwitch_setStateByMarker(ActorMarker *marker, s32 next_state){
    chCageUpSwitch_setState(marker_getActor(marker), next_state);
}

void func_803870BC(s32 arg0, s32 arg1){
    Struct6Ds *temp_v0;

    if(temp_v0 = &func_8034C528(arg0)->type_6D)
        func_8034DFB0(temp_v0, D_80390224, D_80390234, (f64)arg1 / 1000.0);
}

void func_8038711C(s32 arg0, s32 arg1){
    Struct6Ds *temp_v0;

    func_8030E6D4(SFX_90_SWITCH_PRESS);
    if(temp_v0 = &func_8034C528(arg0)->type_6D)
        func_8034DFB0(temp_v0, D_80390244, D_80390254, (f64)arg1 / 1000.0);
}

void func_8038718C(ActorMarker *marker){
    void *sp44;
    f32 sp38[3];
    f32 sp2C[3];

    if(sp44 = func_8034C528(0x19a)){
        sp38[0] = sp38[1] = sp38[2] = 0.0f;
        sp2C[0] = 0.0f;
        sp2C[2] = 0.0f;
        sp2C[1] = 450.0f;
        func_8034DDF0(sp44, sp38, sp2C, 4.0f, 1);
        func_8034E1A4(sp44, SFX_D8_CRANE, 1.0f, 1.0f);
    }
    timed_setStaticCameraToNode(0.0f, 4);
    timed_setStaticCameraToNode(2.5f, 5);
    timed_playSfx(4.0f, SFX_7F_HEAVYDOOR_SLAM, 0.5f, 19000);
    timed_playSfx(4.0f, SFX_7F_HEAVYDOOR_SLAM, 0.6f, 19000);
    timed_playSfx(4.0f, SFX_7F_HEAVYDOOR_SLAM, 0.7f, 19000);
    timed_playSfx(4.0f, SFX_7F_HEAVYDOOR_SLAM, 0.8f, 19000);
    timed_playSfx(4.0f, SFX_7F_HEAVYDOOR_SLAM, 0.9f, 19000);
    timed_playSfx(4.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 19000);\
    timed_exitStaticCamera(5.0f);
    func_80324E38(5.0f, 0);
    timedFunc_set_2(5.0f, (GenFunction_2) chCageUpSwitch_setStateByMarker, (s32) marker, CH_CAGE_UP_SWITCH_STATE_3_TIMED_RAISED_CAGE);
}

void func_80387308(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    void *sp40;
    f32 sp34[3];
    f32 sp28[3];

    if(sp40 = func_8034C528(0x19a)){
        TUPLE_ASSIGN(sp34, 0.0f,200.0f,0.0f);
        TUPLE_ASSIGN(sp28, 0.0f, 0.0f, 0.0f);
        func_8034DDF0(sp40, sp34, sp28, 0.5f, 1);
        func_8034E1A4(sp40, SFX_D8_CRANE, 1.0f, 1.0f);
    }//L80387394

    timed_playSfx(0.5f, SFX_7F_HEAVYDOOR_SLAM, 0.5f, 19000);
    timed_playSfx(0.5f, SFX_7F_HEAVYDOOR_SLAM, 0.6f, 19000);
    timed_playSfx(0.5f, SFX_7F_HEAVYDOOR_SLAM, 0.7f, 19000);
    timed_playSfx(0.5f, SFX_7F_HEAVYDOOR_SLAM, 0.8f, 19000);
    timed_playSfx(0.5f, SFX_7F_HEAVYDOOR_SLAM, 0.9f, 19000);
    timed_playSfx(0.5f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 19000);
    timedFunc_set_2(0.5f, (GenFunction_2) chCageUpSwitch_setStateByMarker, (s32) actor->marker, CH_CAGE_UP_SWITCH_STATE_1_NOT_PRESSED);
    
    timedFunc_set_2(1.5f, (GenFunction_2) func_803870BC, 0x19d, 0x1f4);
    timed_exitStaticCamera(1.5f);
    func_80324E38(1.5f, 0);
}

void func_80387488(ActorMarker *marker){
    f32 player_position[3];
    Actor *actor = marker_getActor(marker);

    player_getPosition(player_position);
    if(-50.0f < player_position[1] && player_position[1] < 600.0f){
        player_position[1] = 0;
        if(ml_vec3f_distance(player_position, D_80390264) < 500.0f){
            timedFunc_set_1(1.0f, (GenFunction_1) func_80387488, (s32)actor->marker);
            return;
        }
    }
    func_80324E38(0.0f, 3);
    timed_setStaticCameraToNode(0.0f, 6);
    timedFunc_set_1(0.5f, (GenFunction_1) func_80387308, (s32) actor->marker);
}

void chCageUpSwitch_setState(Actor *this, s32 next_state){
    f32 sp6C[3];
    f32 sp60[3];
    void * temp_v0;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;
    void * sp3C;
    f32 sp30[3];
    f32 sp24[3];
    
    if(next_state == CH_CAGE_UP_SWITCH_STATE_1_NOT_PRESSED){
        if(this->state != 0){
            sp6C[0] = 0.0f;
            sp6C[1] = 0.0f;
            sp6C[2] = -40.0f;
            sp60[0] = sp60[1] = sp60[2] = 0.0f;
            
            if(temp_v0 = func_8034C528(0x19C))
                func_8034DDF0(temp_v0, sp6C, sp60, 0.1f, 1);
            
            if(temp_v0 = func_8034C528(0x19D))
                func_8034DDF0(temp_v0, sp6C, sp60, 0.1f, 1);
        }
    }//L80387610

    if(next_state == CH_CAGE_UP_SWITCH_STATE_2_RAISING_CAGE){
        sp50[0] = sp50[1] = sp50[2] = 0.0f;
        sp44[0] =  0.0f;
        sp44[1] = 0.0f;
        sp44[2] = -40.0f;
        
        if(temp_v0 = func_8034C528(0x19C))
            func_8034DDF0(temp_v0, sp50, sp44, 0.1f, 1);
        
        if(temp_v0 = func_8034C528(0x19D))
            func_8034DDF0(temp_v0, sp50, sp44, 0.1f, 1);
        
        timedFunc_set_2(0.1f, (GenFunction_2)func_8038711C, 0x19d, 0x1f4);
        timedFunc_set_2(0.1f, (GenFunction_2)coMusicPlayer_playMusic, COMUSIC_2B_DING_B, 28000);
        func_80324E38(0.2f, 3);
        timedFunc_set_1(1.1f, (GenFunction_1)func_8038718C, (s32)this->marker);
    }//L80387704

    if(next_state == CH_CAGE_UP_SWITCH_STATE_3_TIMED_RAISED_CAGE){
        item_set(ITEM_6_HOURGLASS, 1);
        item_set(ITEM_0_HOURGLASS_TIMER, VER_SELECT(0x3bf, 0x31f, 0, 0));
    }

    if(this->state == CH_CAGE_UP_SWITCH_STATE_3_TIMED_RAISED_CAGE){
        item_set(ITEM_6_HOURGLASS, 0);
    }

    if(next_state == CH_CAGE_UP_SWITCH_STATE_4_LOWER_CAGE){
        sp3C = func_8034C528(0x19a);
        if(sp3C){
            sp30[0] = 0.0f;
            sp30[1] = 450.0f;
            sp30[2] = 0.0f;
            sp24[0] = 0.0f;
            sp24[1] = 200.0f;
            sp24[2] = 0.0f;
            
            
            func_8034DDF0(sp3C, sp30, sp24, 3.0f, 1);
            func_8034E1A4(sp3C, SFX_D8_CRANE, 1.0f, 1.0f);
        }//L803877D4
        timed_playSfx(3.0f, SFX_7F_HEAVYDOOR_SLAM, 0.5f, 25000);
        timed_playSfx(3.0f, SFX_7F_HEAVYDOOR_SLAM, 0.6f, 25000);
        timedFunc_set_1(4.0f, (GenFunction_1)func_80387488, (s32)this->marker);
    }//L80387828

    this->state = next_state;
}

void chCageUpSwitch_pushSwitch(ActorMarker *marker, ActorMarker *arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == CH_CAGE_UP_SWITCH_STATE_1_NOT_PRESSED){
        chCageUpSwitch_setState(actor, CH_CAGE_UP_SWITCH_STATE_2_RAISING_CAGE);
    }
}

void chCageUpSwitch_free(Actor *this){
    chCageUpSwitch_setState(this, CH_CAGE_UP_SWITCH_STATE_0_NOT_INIT);
}

void chCageUpSwitch_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = chCageUpSwitch_free;
        marker_setCollisionScripts(this->marker, NULL, chCageUpSwitch_pushSwitch, NULL);
        suSetSpriteScale(this, 1.1f);
        chCageUpSwitch_setState(this, CH_CAGE_UP_SWITCH_STATE_1_NOT_PRESSED);
    }

    if(this->state == CH_CAGE_UP_SWITCH_STATE_3_TIMED_RAISED_CAGE){
        if(item_empty(ITEM_0_HOURGLASS_TIMER)){
            chCageUpSwitch_setState(this, CH_CAGE_UP_SWITCH_STATE_4_LOWER_CAGE);
        }
    }
}
