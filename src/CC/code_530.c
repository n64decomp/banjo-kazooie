#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030E730(s32, f32, s32);

void func_80388EA4(void);


typedef struct {
    u8 sfxsourceIdx;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4[3];
    s16 unk10;
    u8 pad12[2];
    f32 unk14;
} ActorLocal_CC_530;

void func_80386B28(Actor* this);

/* .data */
ActorInfo D_80389AD0 = {
    MARKER_4A_CC_KEY, ACTOR_3C_CC_KEY, ASSET_429_MODEL_CC_KEY, 0, NULL,
    func_80386B28, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

f32 D_80389AF4[3] = {6200.0f, -2600.0f, 0.0f};

/* .code */
void CC_func_80386920(Actor *this, s32 next_state){
    ActorLocal_CC_530 *local = (ActorLocal_CC_530 *)&this->local;
    f32 sp28[3];
    s16 sp20[3];

    local->unk14 = 0.0f;
    if(this->state == 2 || this->state == 3 || this->state == 4){
        func_8030E394(local->sfxsourceIdx);
    }

    if(next_state == 2 || next_state == 3 || next_state == 4){
        func_8030DD90(local->sfxsourceIdx, 1);
        sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.3f);
        sfxsource_setSfxId(local->sfxsourceIdx, 0x3ec);
        func_8030DD14(local->sfxsourceIdx, 3);
        sfxsource_setSampleRate(local->sfxsourceIdx, 28000);
        func_8030E2C4(local->sfxsourceIdx);
    }
    
    if(next_state == 2 || next_state == 4){
        func_8025A6EC(COMUSIC_2B_DING_B, 0x7fff);
        player_getPosition(&sp28);
        TUPLE_COPY(sp20, sp28);
        fxSparkle_giantGoldFeather(&sp20);
    }

    if(next_state == 4){
        CC_func_8038868C();
        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
    }

    if(this->state == 4)
        func_8030E730(0x7f, 0.7f, 0x7FFF);

    this->state = next_state;
}


void func_80386AD0(ActorMarker *arg0, s32 arg1) {
    Actor *actor = marker_getActor(arg0);
    ActorLocal_CC_530 *local = (ActorLocal_CC_530 *)&actor->local;
    local-> unk1 = 1;
}

void func_80386AF8(Actor *arg0) {
    ActorLocal_CC_530 *local = (ActorLocal_CC_530 *)&arg0->local;
    CC_func_80386920(arg0, 0);
    func_8030DA44(local->sfxsourceIdx);
}

void func_80386B28(Actor *this){
    ActorMarker *marker = this->marker;
    f32 sp58[3];
    ActorLocal_CC_530 * local = (ActorLocal_CC_530 *)&this->local;
    int temp_v0;
    f32 sp44[3];
    f32 sp38[3];
    int temp_a0;
    

    f32 tick = time_getDelta();
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_80386AD0, NULL);
        local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        local->unk1 = 0;
        local->unk2 = 0;
        local->unk10 = this->pitch;
        local->unk14 = 0.0f;
        player_getPosition(&local->unk4);
        local->unk3 = 3;
        marker->actorFreeFunc = func_80386AF8;
        marker->propPtr->unk8_3 = 1;
        this->position_x = 5700.0f;
        this->position_y = -2620.0f;
        this->position_z = -20.0f;
        if(jiggyscore_isSpawned(JIGGY_17_CC_CLANKER_RAISED)){
            CC_func_80386920(this, 5);
        }
        else{
            CC_func_80386920(this, 1);
        }
    }
    else{//L80386C40
        local->unk14 += tick;
        player_getPosition(&sp58);
        if(local->unk1 && ! local->unk2){
            sp38[0] = 0.0f;
            sp38[1] = 0.0f;
            sp38[2] = -200.0f;
            ml_vec3f_pitch_rotate_copy(&sp38, &sp38, this->pitch);

            sp44[0] = local->unk4[0] - D_80389AF4[0]; 
            sp44[1] = local->unk4[1] - D_80389AF4[1]; 
            sp44[2] = local->unk4[2] - D_80389AF4[2]; 

            temp_a0 = (0.0f <=  sp44[0]*sp38[0] + sp44[1]*sp38[1] + sp44[2]*sp38[2]) ? 1 : -1;

            TUPLE_ASSIGN(sp44, 
                sp58[0] - D_80389AF4[0], 
                sp58[1] - D_80389AF4[1], 
                sp58[2] - D_80389AF4[2]
            );


            temp_v0 = (0.0f <=  sp44[0]*sp38[0] + sp44[1]*sp38[1] + sp44[2]*sp38[2]) ? 1 : -1;

            if(temp_a0 != temp_v0){
                local->unk2 = 1;
            }
            else{
                local->unk2 = 0;
            }
        }
        else{//L80386DA0
            if(local->unk1){
                local->unk2 = 2;
            }
            else{
                local->unk2 = 0;
            }
        }//L80386DB4

        local->unk1 = 0;
        local->unk4[0] = sp58[0];
        local->unk4[1] = sp58[1];
        local->unk4[2] = sp58[2];
        if(this->state == 0x1 && local->unk2 == 1){
            if(--local->unk3 == 0){
                CC_func_80386920(this, 4);
            }
            else{
                CC_func_80386920(this, 2);
            }
        }//L80386E4C

        if(this->state == 2){
            if(1.0f <= local->unk14){
                local->unk14 = 1.0f;
            }
            this->pitch = (f32)local->unk10 + 30.0f*local->unk14;
            if(1.0f <= local->unk14){
                CC_func_80386920(this, 3);
            }
        }//L80386EC0

        if(this->state == 3){
            if(1.0f <= local->unk14){
                local->unk14 = 1.0f;
            }
            this->pitch = (f32)local->unk10 + 30.0f*(1.0f - local->unk14);
            if(1.0f <= local->unk14){
                CC_func_80386920(this, 1);
            }
        }//L80386F44

        if(this->state == 4){
            if(5.0f <= local->unk14){
                local->unk14 = 5.0f;
            }
            this->pitch = (f32)local->unk10 + 180.0f*(local->unk14/5.0f);
            if(5.0f <= local->unk14){
                CC_func_80386920(this, 5);
                func_80388EA4();
            }
        }//L80386FC0
    }
}
