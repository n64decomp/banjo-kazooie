#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80325888(ActorMarker *, Gfx **, Mtx**, u32);
void func_8028E668(f32 *, f32, f32, f32);
int func_80311480(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg5)(ActorMarker *, s32, s32));
void func_80328BD4(Actor *, s32, f32, s32, f32);
int func_8032886C(Actor *, f32);
void func_80328B8C(Actor *, s32, f32, s32);
void func_80324E88(f32);
void func_80324E38(f32,s32);
void func_80324E60(f32, s32);
void func_8030E6A4(s32, f32, s32);
void func_8028F31C(f32 *, f32, s32, Actor **);
void func_8028FA34(s32, Actor *);

extern s32 D_80389A5C;

void func_803885D0(Actor *);

ActorAnimationInfo chlmonkeyAnimations[5] = {
    {0, 0.0f},
    {0x5C, 2.3f},
    {0x5B, 0.67f},
    {0x5D, 0.5f},
    {0x5C, 2.3f}
};


ActorInfo chlmonkeyInfo = { 0xA, actor_chimpy, model_chimpy, 1, chlmonkeyAnimations,
    NULL, func_803885D0, func_80325888,
    {0x09,0xC4,0,0}, 0.8f, {0,0,0,0}
};

extern f32 D_80389C00;
extern f32 D_80389C04;
extern f32 D_80389C08;
extern f64 D_80389C10;
extern f64 D_80389C18;
extern f32 D_80389C20;
extern f32 D_80389C24;
extern f32 D_80389C28;
extern f32 D_80389C2C;
extern f32 D_80389C30;
extern f64 D_80389C38;
extern f64 D_80389C40;
extern f64 D_80389C48;

void func_80388300(Actor **arg0){
    func_8028F31C((*arg0)->position, 800.0f, 0x29, arg0);
    if( func_80329530(*arg0, 0x159) 
        && func_8028E88C() == 0x36
        && func_8028FC34()
    ){
        func_8028FA34(0xc6, *arg0);
        (*arg0)->unk138_24 = 1;
        func_80324E60(D_80389C00, 0xF);
        func_80324E38(D_80389C04, 3);
    }
    if(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/lmonkey/func_803883AC.s")
/*void func_803883AC(Actor *this){
    f32 sp2C;
    f32 sp28;
    s32 v0 = 6;

    sp2C = mlMap_f(func_8032970C(), D_80389C08, 343000000.0f, 18000.0f, 0.0f);
    sp28 = randf();
    if(--D_80389A5C < 0){
        if(randf() < D_80389C10){
            D_80389A5C = v0;
            func_8030E6A4(((sp28 < 0.5) ? 0x58 : 0x59 ), randf()*0.25 + D_80389C18, sp2C);
        }
    }
}//*/


void func_803884C0(s32 x, s32 y, s32 z){
    f32 sp1C[3];
    TUPLE_ASSIGN(sp1C, x, y, z);
    jiggySpawn(JIGGY_MM_CHIMPY, sp1C);
}

void func_80388514(ActorMarker *marker, s32 arg1, s32 arg2){
    Actor * actor = marker_getActor(marker);
    mapSpecificFlags_set(4,1);
    func_80328A84(actor, 3);
    func_80324E60(D_80389C20, 0x12);
    timedFunc_set_3(D_80389C24,func_803884C0, actor->position_x, actor->position_y + 150.0f, actor->position_z);
    func_80324E88(D_80389C28);
    func_80324E38(D_80389C2C, 0);
}

void func_803885D0(Actor *this){
    func_8028E668(this->position, 35.0f, 0.0f, 65.0f);
    actor_collisionOff(this);
    this->marker->propPtr->unk8_3 = 1;
    if(func_803348C0() != 2){
        func_80343DEC(this);
    }else{//L80388630
        if(func_80329530(this, 0x2BC) && !func_803114B0()){
            func_803883AC(this);
        }//L8038865C
        switch(this->unk10_31){
            case 1://L80388690
                if(mapSpecificFlags_get(2)){
                    func_80328A84(this, 4);
                    if(!jiggyscore_isCollected(JIGGY_MM_CHIMPY)){
                        func_80311480(0xB40, 0xE, this->position, this->marker, func_80388514, NULL);
                    }else{//L803886E8
                        func_80388514(this->marker, 0xB40, -1);
                    }//L80388898
                }else{
                    func_80388300(&this);
                    if( func_80329530(this, 0x159)
                        && !func_80329530(this, 0x96)
                        && !item_getCount(ITEM_ORANGE)
                        && !this->unk138_24
                    ){
                        func_80311480(0xb3f, 0xe, this->position, NULL, NULL, NULL);
                        this->unk138_24 = 1;
                    }//L80388774
                    func_803298D8(this);
                    func_80328BD4(this, 2, 0.0f, -1, D_80389C30);
                }
                break;
            case 2: //L803887A4
                func_80388300(&this);
                func_803298AC(this);
                if(func_8032886C(this, 0.99f)){
                    func_80328B8C(this,1,0.0f,-1);
                }
                break;
            case 4: //L803887E4
                func_803298D8(this);
                break;
            case 3: //L803887F4
                func_80343DEC(this);
                func_803298D8(this);
                if(D_80389C38 <= this->unk48){
                    mapSpecificFlags_set(0, 1);
                }
                if(D_80389C40 <= this->unk48){
                    mapSpecificFlags_set(3, 1);
                }
                if(D_80389C48 <= this->unk48){
                    marker_despawn(this->marker);
                }
                break;
            
        }
    }//L80388898
}
