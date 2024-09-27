#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chfrogminigame_update(Actor *);
void chFrogMinigame_setState(Actor * arg0, u32 next_state);
void func_8025A58C(u32, u32);
void timed_exitStaticCamera(f32);


ActorInfo chFrogMinigame = {MARKER_C4_YELLOW_FLIBBIT_CTRL, ACTOR_136_YELLOW_FLIBBIT_CONTROLLER, 0x00, 
    0x00, NULL,
    chfrogminigame_update, NULL, func_80325340,
    0, 0, 0.0f, 0
};


/* .bss */
u8 D_80391240[4];

/* .code */
static void __chFrogMinigame_spawnJiggy(void){
    static f32 D_80390AD4[3] = {1985.0f, 200.0f, -1386.0f};
    jiggy_spawn(JIGGY_24_BGS_FLIBBITS, D_80390AD4);
}

static void __chFrogMinigame_textCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *actPtr = marker_getActor(marker);
    mapSpecificFlags_set(0x10, 0);
    if(actPtr->state == 4){
        chFrogMinigame_setState(actPtr,5);
    }
    else{
        chFrogMinigame_setState(actPtr,3);
    }
}

void func_8038CBB4(Actor * arg0){
    if(!arg0->bgs_6730.unk4)
        return;
    func_8025A58C(-1, 400);
    comusic_8025AB44(MUSIC_BGS_FLIBBIT_FIGHT,0, 400);
    func_8025AABC(MUSIC_BGS_FLIBBIT_FIGHT);
    
    arg0->bgs_6730.unk4 = 0;
}

void chFrogMinigame_setState(Actor * arg0, u32 next_state){
    ActorLocal_BGS_6730 *s0;

    s0 = &arg0->bgs_6730;
    if(next_state == 2){
        func_8028F8F8(0x12, 1);
        func_8028F8F8(0x1F, 0);
        mapSpecificFlags_set(0x10, 1);
        if(!fileProgressFlag_get(FILEPROG_1B_MET_YELLOW_FLIBBITS)){
            fileProgressFlag_set(FILEPROG_1B_MET_YELLOW_FLIBBITS, 1);
            gcdialog_showText(text_flibbits_meet, 0xf, arg0->position, arg0->marker, __chFrogMinigame_textCallback, 0);
        }else{
            if(!arg0->bgs_6730.unk8){
                gcdialog_showText(text_flibbits_return, 0x4, arg0->position, arg0->marker, __chFrogMinigame_textCallback, 0);
            }
            else{
                __chFrogMinigame_textCallback(arg0->marker, text_flibbits_return, 0);
                return;
            }
        }
    }
    if(next_state == 3){
        s0->unk0 = 1;
        if(!s0->unk4){
            func_8025A58C(0, 400);
            func_8025A6EC(MUSIC_BGS_FLIBBIT_FIGHT, 30000);
            s0->unk4 = 1;
        }
        else{
            comusic_8025AB44(MUSIC_BGS_FLIBBIT_FIGHT, 30000, 400);
        }
    }

    if(arg0->state == 3){
        func_8028F8F8(0x12, 0);
        func_8028F8F8(0x1F, 1);
        if(next_state == 1){
            if(s0->unk4){
                comusic_8025AB44(MUSIC_BGS_FLIBBIT_FIGHT, 18000, 100);
            }
        }
        else{
            func_8038CBB4(arg0);
        }
    }

    if (next_state == 4) {
        gcdialog_showText(text_flibbits_defeat, 0xf, arg0->position, arg0->marker, __chFrogMinigame_textCallback, 0);
    }

    if(next_state == 5){
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0x27);
        timedFunc_set_0(0.2f, __chFrogMinigame_spawnJiggy);
        timed_exitStaticCamera(3.0f);
        func_80324E38(3.0f, 0);
        next_state = 6;
    }
    if(next_state == 6){
        func_8028F8F8(0x12, 0);
        func_8028F8F8(0x1F, 1);
    }
    arg0->state = next_state;
}

void func_8038CE88(void){
    D_80391240[0]++;
}

void func_8038CEA0(void){
    D_80391240[1]++;
}

void func_8038CEB8(void){
    D_80391240[2]++;
}

void BGS_func_8038CED0(void){
    D_80391240[3]++;
}

void chfrogminigame_update(Actor *this){
    f32 player_position[3];
    u32 sp28;
    ActorLocal_BGS_6730 *local;

    local = &this->bgs_6730;
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->unk0 = 0;
        local->unk4 = 0;
        local->unk8 = 0;
        local->unkC = 0;
        D_80391240[0] = 0;
        D_80391240[1] = 0;
        D_80391240[2] = 0;
        D_80391240[3] = 0;
        mapSpecificFlags_set(0x12, 0);
        mapSpecificFlags_set(0x10, 0);
        if(jiggyscore_isSpawned(JIGGY_24_BGS_FLIBBITS)){
            chFrogMinigame_setState(this,6);
            return;
        }else{
            chFrogMinigame_setState(this,1);
            return;
        }
    }
    if(D_80391240[0]>0){
        local->unk8 += D_80391240[0];
        local->unkC -= D_80391240[0];
        D_80391240[0] = 0;
    }
    if(D_80391240[1]>0){
        local->unk8 -= D_80391240[1];
        D_80391240[1] = 0;
    }
    if(D_80391240[2]>0){
        local->unk8 -= D_80391240[2];
        local->unkC += D_80391240[2];
        D_80391240[2] = 0;
    }
    if(D_80391240[3]>0){
        local->unkC += D_80391240[3];
        D_80391240[3] = 0;
    }
    player_getPosition(player_position);
    sp28 = (player_position[1] < 500.0f) && (func_80329210(this, player_position) != 0);
    if(this->state == 1){
        if(sp28 && ((local->unk8 > 0) || (local->unkC > 0)) && !func_8028FB48(0xe000)){
            chFrogMinigame_setState(this,2);
        }
        else{
            //L8038D0E0
            if(local->unk4 && !local->unk8){
                func_8038CBB4(this);
            }
        }
    }
    if(this->state == 3){
        if(!sp28){
            chFrogMinigame_setState(this, 1);
        }else{
            if(local->unk8 < 2 && local->unkC > 0){
                mapSpecificFlags_set(0x12, 1);
            }
        }
    }
    if(this->state == 1 || this->state == 3){
        if( (local->unk0) 
          && !jiggyscore_isSpawned(JIGGY_24_BGS_FLIBBITS)
          && !local->unk8
          && !local->unkC
        ){
                chFrogMinigame_setState(this, 4);
        }
    }
}
