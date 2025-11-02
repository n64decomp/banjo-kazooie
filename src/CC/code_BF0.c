#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s32 unk0;
    s32 egg_count;
    f32 unk8;
}ActorLocal_CC_BF0;

void func_803870F8(Actor *this);

/* .data */
extern ActorInfo D_80389B00 = {
    MARKER_4C_CLANKER_TOKEN_TOOTH_EXT, ACTOR_44_CLANKER_TOKEN_TOOTH_EXTERIOR, ASSET_309_MODEL_CLANKER_TOKEN_TOOTH_EXTERIOR, 
    0, NULL,
    func_803870F8, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

extern ActorInfo D_80389B24 = {
    MARKER_4D_CLANKER_JIGGY_TOOTH_EXT, ACTOR_45_CLANKER_JIGGY_TOOTH_EXTERIOR, ASSET_30A_MODEL_CLANKER_JIGGY_TOOTH_EXTERIOR, 
    0, NULL,
    func_803870F8, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .bss */
u8 D_80389F80;

/* .code */
void CC_func_80386FE0(Actor *this, s32 next_state){
    ActorLocal_CC_BF0 *local = (ActorLocal_CC_BF0 *)&this->local;
    s32 prev_state = this->state;
    this->state = next_state;
    local->unk8 = 0.0f;
    if(this->state == 2){
        coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
    }
    else if(this->state == 3){
        if(prev_state == 2){
            levelSpecificFlags_set((local->unk0 == 1) ? LEVEL_FLAG_0_CC_TOKEN_TOOTH_OPEN : LEVEL_FLAG_1_CC_JIGGY_TOOTH_OPEN, TRUE);
        }
        if(local->unk0 == 1){
            this->yaw = -30.0f;
            this->pitch = -90.0f;
            this->roll = -5.0f;
        }
        else{
            this->yaw = 30.0f;
            this->pitch = 90.0f;
            this->roll = 5.0f;
        }
    }
}

void CC_func_803870E0(void) {
    D_80389F80 = 0;
}

void func_803870EC(s32 arg0) {
    D_80389F80 = arg0;
}

void func_803870F8(Actor *this){
    ActorMarker *marker = this->marker;
    f32 sp70[3];
    ActorLocal_CC_BF0 *local = (ActorLocal_CC_BF0 *)&this->local;
    f32 sp68 = time_getDelta();
    f32 sp5C[3];
    f32 sp50[3];
    f32 temp_f2;
    s32 flagCnt;
    f32 sp3C[3];
    

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker->propPtr->unk8_3 = 1;
        this->pitch = 0.0f;
        this->yaw = 0.0f;
        this->roll = 0.0f;
        local->unk0 = (marker->modelId == 0x309) ? 1 : 2;
        local->egg_count = 0;
        CC_func_80386FE0(this, 1);
        if(levelSpecificFlags_get((local->unk0 == 1)? LEVEL_FLAG_0_CC_TOKEN_TOOTH_OPEN: LEVEL_FLAG_1_CC_JIGGY_TOOTH_OPEN)){
            CC_func_80386FE0(this, 3);
        }
    }//L803871D8
    player_getPosition(sp70);
    local->unk8 += sp68;
    if(this->state == 2){
        temp_f2 = local->unk8/1;
        if(local->unk0 == 1){
            this->yaw = -temp_f2*30.0f;
            this->pitch = -temp_f2*90.0f;
            this->roll = -temp_f2*5.0f;

        }//L8038726C
        else{
            this->yaw = temp_f2*30.0f;
            this->pitch = temp_f2*90.0f;
            this->roll = temp_f2*5.0f;
        }
    }//L803872A0

    if(local->unk0 == 1){
        func_80388B78(&sp5C, &sp50);
    }
    else{
        func_80388BBC(&sp5C, &sp50);
    }//L803872D4
    TUPLE_COPY(this->position, sp5C);

    if(this->state == 1)
        func_8028E668(this->position, 290.0f, -10.0f, 150.0f);
    
    if(this->state == 1 && D_80389F80 == local->unk0){
        D_80389F80 = 0;
        local->egg_count++;
        if(local->egg_count == 3){
            CC_func_80386FE0(this, 2);
        }else{
            coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
        }
    }
    else if(this->state == 2 && 1.0f <= local->unk8){
        flagCnt = levelSpecificFlags_get(LEVEL_FLAG_0_CC_TOKEN_TOOTH_OPEN) + levelSpecificFlags_get(LEVEL_FLAG_1_CC_JIGGY_TOOTH_OPEN);
        if(!jiggyscore_isCollected(JIGGY_1B_CC_TOOTH)){
            gcdialog_showDialog((local->unk0 == 1)? ((flagCnt == 0)? ASSET_D30_DIALOG_CLANKER_RIGHT_TOOTH_FIRST : ASSET_D31_DIALOG_CLANKER_RIGHT_TOOTH_SECOND) : ((flagCnt == 0)? ASSET_D2E_DIALOG_CLANKER_LEFT_TOOTH_FIRST : ASSET_D2F_DIALOG_CLANKER_LEFT_TOOTH_SECOND), 4, NULL, NULL, NULL, NULL);
        }
        CC_func_80386FE0(this, 3);
    }//L80387474

    if(this->state == 3){
        sp3C[0] = this->position_x;
        sp3C[1] = this->position_y + 100;
        sp3C[2] = this->position_z;
        if(ml_vec3f_distance(sp3C, sp70) < 120.0f){
            func_8031D04C(MAP_22_CC_INSIDE_CLANKER, (local->unk0  == 1)? 7 : 6);
        }
    }//L80387500
}
