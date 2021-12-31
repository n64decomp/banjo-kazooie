#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CD8(f32);

typedef struct {
    u8 pad0[4];
    s16 unk4;
    //u8 pad6[2];
    f32 unk8; 
} ActorLocal_GVMazeCtrl;

void __chmazectrl_setState(Actor *this, s32 next_state);
void chmazectrl_update(Actor *this);

/* .data */
ActorInfo D_803915C0 = { 0x1CD, ACTOR_319_GV_MAZE_CTRL, 0x0,
    0, NULL, 
    chmazectrl_update, 0x0, func_80325340, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};
f32 D_803915E4[3] = {460.0f, 1400.0f, 0.0f};
f32 D_803915F0[3] = {0.0f, 0.0f, 0.0f};
f32 D_803915FC[3] = {0.0f, 0.0f, 0.0f};
f32 D_80391608[3] = {460.0f, 1400.0f, 0.0f};

/* .code */
void func_8038F520(f32 arg0){
    s32 tmp_v0 = func_8034C528(0x19A);
    if(tmp_v0){
        func_8034DDF0(tmp_v0, D_803915E4, D_803915F0, arg0, 1);
    }
}

void func_8038F56C(f32 arg0){
    s32 tmp_v0 = func_8034C528(0x19A);
    if(tmp_v0){
        func_8034DDF0(tmp_v0, D_803915FC, D_80391608, arg0, 1);
    }
}

void __chmazectrl_markerSetState(ActorMarker *this_marker, s32 arg1){
    Actor *this = marker_getActor(this_marker);
    __chmazectrl_setState(this, arg1);
}

void __chmazectrl_8038F5E4(Actor *this){
    if(this->state == 2){
        comusic_8025AB44(COMUSIC_26_GV_SANDYBUTT_DANGER, 0, 30000);
        func_80346414(6, 0);
    }
}

void __chmazectrl_setState(Actor *this, s32 next_state){
    f32 plyr_pos[3];
    s32 tmp_v0;
    ActorLocal_GVMazeCtrl *local;
    f32 sp28[3];

    local  = (ActorLocal_GVMazeCtrl *)&this->local;
    player_getPosition(plyr_pos);
    local->unk8 = 0.0f;
    if(next_state == 2){
        func_8025A58C(0, 4000);
        func_8025A6EC(COMUSIC_26_GV_SANDYBUTT_DANGER, 30000);
        func_80346414(0, 0xdd3);
        func_80346414(6, 1);
        func_8038F520(1.0f);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x30D, 0x332);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x30D, 0x2CC);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x30D, 0x1FF);
        if(1500.0f < plyr_pos[0]){
            func_80324E38(0.0f, 3);
            func_80324E60(0.0f, 8);
            func_80324C88(1.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 32000);
            func_80324CD8(1.2f);
            func_80324E88(1.2f);
            func_80324E38(1.2f, 0);
        }
        else{//L8038F754
            func_80324C88(1.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 32000);
        }
        if(!levelSpecificFlags_get(0x16)){
            func_80311480(0xA82, 4, NULL, NULL, NULL, NULL);
            levelSpecificFlags_set(0x16, TRUE);
        }
    }//L8038F794

    if(this->state == 2){
        func_8025A58C(-1, 400);
        comusic_8025AB44(COMUSIC_26_GV_SANDYBUTT_DANGER, 0, 0x190);
        func_8025AABC(COMUSIC_26_GV_SANDYBUTT_DANGER);
        func_80346414(6, 0);
    }

    if(next_state == 3){
        func_80324E38(0.0f, 3);
        timedFunc_set_2(0.0f, (TFQM2)func_8025A6EC, COMUSIC_3E_SANDYBUTT_FAILURE, 0x7FFF);
        timedFunc_set_2(1.0f, (TFQM2)__chmazectrl_markerSetState, reinterpret_cast(s32, this->marker), 6);
        timedFunc_set_2(2.0f, (TFQM2)__chmazectrl_markerSetState, reinterpret_cast(s32, this->marker), 4);
    }//L8038F850

    if(next_state == 4){
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x3A9, 0x3FF);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x38A, 0x332);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x36B, 0x2CC);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0x3C8, 0x1FF);
        func_8030E6D4(SFX_52_BANJO_YAH_OH);
        tmp_v0 = func_8034C528(400);
        if(tmp_v0){
            func_8034DE60(tmp_v0, 0.0f, -1700.0f, 1.0f, 1);
        }
    }//L8038F8C4

    if(this->state == 4){
        FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 0x3FF, 0x265);
        FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 0x3FE, 0x332);
        func_8030E6D4(SFX_7F_HEAVYDOOR_SLAM);
        func_8028F66C(0x26);
    }

    if(next_state == 6){
        player_getPosition(sp28);
        sp28[1] = 2000.0f;
        func_8028F94C(4, sp28);
    }

    if(next_state == 5){
        func_8038F56C(0.0f);
        if(++local->unk4 == 1)
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7fff);
        
        if(!levelSpecificFlags_get(0x17)){
            func_80311480(0xA83, 4, NULL, NULL, NULL, NULL);
            levelSpecificFlags_set(0x17, TRUE);
        }
    }

    this->state = next_state;
}

void chmazectrl_update(Actor *this){
    f32 sp3C[3];
    s32 sp38;
    f32 sp34;
    s32 sp30;
    ActorLocal_GVMazeCtrl *local  = (ActorLocal_GVMazeCtrl *)&this->local;

    sp34 = time_getDelta();
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->unk30 = __chmazectrl_8038F5E4;
        if(this->state == 2){
            comusic_8025AB44(COMUSIC_26_GV_SANDYBUTT_DANGER, 30000, 30000);
            func_80346414(6, 1);
        }
        else{
            func_8038F56C(0.0f);
            local->unk4 = 0;
            this->state = 0;
            __chmazectrl_setState(this, 1);
            local->unk8 = 1.0f;
        }//L8038FA8C
        if(jiggyscore_isCollected(JIGGY_41_GV_MAZE))
            levelSpecificFlags_set(0x17, TRUE);
    }//L8038FAA4

    player_getPosition(sp3C);
    if(this->state == 1){
        sp38 = func_8034C528(0x191);
        if(sp38 && func_8034DC80(sp38, sp3C)){
            __chmazectrl_setState(this, 2);
        }
        if( !levelSpecificFlags_get(0x15) 
            && func_8025773C(&local->unk8, sp34)
            && func_80311480(0xA81, 0, NULL, NULL, NULL, NULL)
        ){
            levelSpecificFlags_set(0x15, TRUE);
        }
    }//L8038FB34

    if(this->state == 2){
        if( sp3C[0] <= -1750.0f && 80.0f <= sp3C[2] && sp3C[2] <= 350.0f){
            __chmazectrl_setState(this, 5);
        }
        else{
            if(item_empty(ITEM_6_HOURGLASS)){
                __chmazectrl_setState(this, 3);
            }
        }
    }//L8038FBBC

    if(this->state == 5){
        if(-1700.0f < sp3C[0]){
            __chmazectrl_setState(this, 2);
        }
    }

    if(this->state == 4){
        sp30 = func_8034C528(0x190);
        if(sp30 && func_8034DC78(sp30)){
            __chmazectrl_setState(this, 0);
        }
    }
}
