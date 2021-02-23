#include <ultra64.h>
#include "functions.h"
#include "variables.h"


Actor *func_80329958(ActorMarker *);
void func_8038CEE8(Actor *);
Actor *func_80325340(ActorMarker*, Gfx **, Mtx **, u32);
void func_8038CC08(Actor * arg0, u32 arg1);
void func_8025A58C(u32, u32);
void func_8025A6EC(u32, u32);
void func_80324E38(f32, u32);
void func_80324E60(f32, u32);
void timedFuncAdd_0(f32, void(*)(void));
void func_80324E88(f32);
void func_8028E9A4(f32 *);
void mapSpecificFlags_set(u32, u32);

ActorInfo D_80390AB0 = {0xC4, 0x136, 0x00, 0x00, NULL,
    func_8038CEE8, NULL, func_80325340,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

f32 D_80390AD4[3] = {1985.0f, 200.0f, -1386.0f};
extern f32 D_80391090;
extern u8 D_80391240[4];

void func_8038CB20(void){
    jiggySpawn(jiggy_bgs_flibbits, D_80390AD4);
}

void func_8038CB48(ActorMarker *arg0, u32 arg1, u32 arg2){
    Actor *actPtr = func_80329958(arg0);
    mapSpecificFlags_set(0x10, 0);
    if(actPtr->unk10_31 == 4){
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
    func_8025AB44(0x72,0, 400);
    func_8025AABC(0x72);
    
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
            func_80311480(0xc81, 0xf, &arg0->position_x, arg0->marker, func_8038CB48, 0);
        }else{
            if(!arg0->bgs_6730.unk8){
                func_80311480(0xc83, 0x4, &arg0->position_x, arg0->marker, func_8038CB48, 0);
            }
            else{
                func_8038CB48(arg0->marker, 0xc83, 0);
                return;
            }
        }
    }
    if(arg1 == 3){
        s0->unk0 = 1;
        if(!s0->unk4){
            func_8025A58C(0, 400);
            func_8025A6EC(0x72, 30000);
            s0->unk4 = 1;
        }
        else{
            func_8025AB44(0x72, 30000, 400);
        }
    }

    if(arg0->unk10_31 == 3){
        func_8028F8F8(0x12, 0);
        func_8028F8F8(0x1F, 1);
        if(arg1 == 1){
            if(s0->unk4){
                func_8025AB44(0x72, 18000, 100);
            }
        }
        else{
            func_8038CBB4(arg0);
        }
    }

    if(arg1 == 4){
        func_80311480(0xc82, 0xf, &arg0->position_x, arg0->marker, func_8038CB48, 0);
    }
    if(arg1 == 5){
        func_80324E38(0.0f, 3);
        func_80324E60(0.0f, 0x27);
        timedFuncAdd_0(D_80391090, func_8038CB20);
        func_80324E88(3.0f);
        func_80324E38(3.0f, 0);
        arg1 = 6;
    }
    if(arg1 == 6){
        func_8028F8F8(0x12, 0);
        func_8028F8F8(0x1F, 1);
    }
    arg0->unk10_31 = arg1;
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

void func_8038CED0(void){
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
        if(jiggyscore_80320F7C(jiggy_bgs_flibbits)){
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
    func_8028E9A4(sp34);
    sp28 = (sp34[1] < 500.0f) && (func_80329210(this,sp34) != 0);
    if(this->unk10_31 == 1){
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
    if(this->unk10_31 == 3){
        if(!sp28){
            func_8038CC08(this, 1);
        }else{
            if(bgs6730->unk8 < 2 && bgs6730->unkC > 0){
                mapSpecificFlags_set(0x12, 1);
            }
        }
    }
    if(this->unk10_31 == 1 || this->unk10_31 == 3){
        if( (bgs6730->unk0) 
          && !jiggyscore_80320F7C(jiggy_bgs_flibbits)
          && !bgs6730->unk8
          && !bgs6730->unkC
        ){
                func_8038CC08(this, 4);
        }
    }
}
