#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038CEE8(Actor *);
void func_8038CC08(Actor * arg0, u32 arg1);
void func_8025A58C(u32, u32);
void func_80324E88(f32);


ActorInfo BGS_D_80390AB0 = {MARKER_C4_YELLOW_FLIBBIT_CTRL, ACTOR_136_YELLOW_FLIBBIT_CONTROLLER, 0x00, 0x00, NULL,
    func_8038CEE8, NULL, func_80325340,
    0, 0, 0.0f, 0
};

f32 D_80390AD4[3] = {1985.0f, 200.0f, -1386.0f};

/* .bss */
u8 D_80391240[4];

/* .code */
void BGS_func_8038CB20(void){
    jiggySpawn(JIGGY_24_BGS_FLIBBITS, D_80390AD4);
}

void func_8038CB48(ActorMarker *arg0, u32 arg1, u32 arg2){
    Actor *actPtr = marker_getActor(arg0);
    mapSpecificFlags_set(0x10, 0);
    if(actPtr->state == 4){
        func_8038CC08(actPtr,5);
    }
    else{
        func_8038CC08(actPtr,3);
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

void func_8038CC08(Actor * arg0, u32 arg1){
    ActorLocal_BGS_6730 *s0;

    s0 = &arg0->bgs_6730;
    if(arg1 == 2){
        func_8028F8F8(0x12, 1);
        func_8028F8F8(0x1F, 0);
        mapSpecificFlags_set(0x10, 1);
        if(!func_8031FF1C(0x1B)){
            func_80320004(0x1B, 1);
            func_80311480(text_flibbits_meet, 0xf, arg0->position, arg0->marker, func_8038CB48, 0);
        }else{
            if(!arg0->bgs_6730.unk8){
                func_80311480(text_flibbits_return, 0x4, arg0->position, arg0->marker, func_8038CB48, 0);
            }
            else{
                func_8038CB48(arg0->marker, text_flibbits_return, 0);
                return;
            }
        }
    }
    if(arg1 == 3){
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
        if(arg1 == 1){
            if(s0->unk4){
                comusic_8025AB44(MUSIC_BGS_FLIBBIT_FIGHT, 18000, 100);
            }
        }
        else{
            func_8038CBB4(arg0);
        }
    }

    if(arg1 == 4){
        func_80311480(text_flibbits_defeat, 0xf, arg0->position, arg0->marker, func_8038CB48, 0);
    }
    if(arg1 == 5){
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.0f, 0x27);
        timedFunc_set_0(0.2f, BGS_func_8038CB20);
        func_80324E88(3.0f);
        func_80324E38(3.0f, 0);
        arg1 = 6;
    }
    if(arg1 == 6){
        func_8028F8F8(0x12, 0);
        func_8028F8F8(0x1F, 1);
    }
    arg0->state = arg1;
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

void func_8038CEE8(Actor *this){
    f32 sp34[3];
    u32 sp28;
    ActorLocal_BGS_6730 *bgs6730;

    bgs6730 = &this->bgs_6730;
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        bgs6730->unk0 = 0;
        bgs6730->unk4 = 0;
        bgs6730->unk8 = 0;
        bgs6730->unkC = 0;
        D_80391240[0] = 0;
        D_80391240[1] = 0;
        D_80391240[2] = 0;
        D_80391240[3] = 0;
        mapSpecificFlags_set(0x12, 0);
        mapSpecificFlags_set(0x10, 0);
        if(jiggyscore_isSpawned(JIGGY_24_BGS_FLIBBITS)){
            func_8038CC08(this,6);
            return;
        }else{
            func_8038CC08(this,1);
            return;
        }
    }
    if(D_80391240[0]>0){
        bgs6730->unk8 += D_80391240[0];
        bgs6730->unkC -= D_80391240[0];
        D_80391240[0] = 0;
    }
    if(D_80391240[1]>0){
        bgs6730->unk8 -= D_80391240[1];
        D_80391240[1] = 0;
    }
    if(D_80391240[2]>0){
        bgs6730->unk8 -= D_80391240[2];
        bgs6730->unkC += D_80391240[2];
        D_80391240[2] = 0;
    }
    if(D_80391240[3]>0){
        bgs6730->unkC += D_80391240[3];
        D_80391240[3] = 0;
    }
    player_getPosition(&sp34);
    sp28 = (sp34[1] < 500.0f) && (func_80329210(this,sp34) != 0);
    if(this->state == 1){
        if(sp28 && ((bgs6730->unk8 > 0) || (bgs6730->unkC > 0)) && !func_8028FB48(0xe000)){
            func_8038CC08(this,2);
        }
        else{
            //L8038D0E0
            if(bgs6730->unk4 && !bgs6730->unk8){
                func_8038CBB4(this);
            }
        }
    }
    if(this->state == 3){
        if(!sp28){
            func_8038CC08(this, 1);
        }else{
            if(bgs6730->unk8 < 2 && bgs6730->unkC > 0){
                mapSpecificFlags_set(0x12, 1);
            }
        }
    }
    if(this->state == 1 || this->state == 3){
        if( (bgs6730->unk0) 
          && !jiggyscore_isSpawned(JIGGY_24_BGS_FLIBBITS)
          && !bgs6730->unk8
          && !bgs6730->unkC
        ){
                func_8038CC08(this, 4);
        }
    }
}
