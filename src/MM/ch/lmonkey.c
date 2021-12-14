#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8028E668(f32 *, f32, f32, f32);
int actor_animationIsAt(Actor *, f32);
void func_80328B8C(Actor *, s32, f32, s32);
void func_80324E88(f32);
void func_80324E38(f32,s32);
void func_80324E60(f32, s32);
void func_8028F31C(f32 *, f32, s32, Actor **);
void func_8028FA34(s32, Actor *);


void func_803885D0(Actor *);

/* .data */
ActorAnimationInfo chlmonkeyAnimations[5] = {
    {0, 0.0f},
    {0x5C, 2.3f},
    {0x5B, 0.67f},
    {0x5D, 0.5f},
    {0x5C, 2.3f}
};

ActorInfo chlmonkeyInfo = { 0xA, ACTOR_F_CHIMPY, model_chimpy, 1, chlmonkeyAnimations,
    NULL, func_803885D0, func_80325888,
    {0x09,0xC4,0,0}, 0.8f, {0,0,0,0}
};

/* .code */
void func_80388300(Actor **arg0){
    func_8028F31C((*arg0)->position, 800.0f, 0x29, arg0);
    if( func_80329530(*arg0, 0x159) 
        && func_8028E88C() == 0x36
        && func_8028FC34()
    ){
        func_8028FA34(0xc6, *arg0);
        (*arg0)->unk138_24 = 1;
        func_80324E60(1.2f, 0xF);
        func_80324E38(1.2f, 3);
    }
    if(arg0);
}

void func_803883AC(Actor *this){
    f32 sp2C;
    f32 sp28;
    static D_80389A5C = 0;
    

    sp2C = ml_map_f(func_8032970C(this), 1000000.0f, 343000000.0f, 18000.0f, 0.0f);
    sp28 = randf();
    D_80389A5C--;
    if(D_80389A5C < 0){
        if(randf() < 0.2){
            D_80389A5C = 6;
            func_8030E6A4(((sp28 < 0.5) ? SFX_58_CHIMPY_NOISE_1 : SFX_59_CHIMPY_NOISE_2 ), randf()*0.25 + 0.85, sp2C);
        }
    }
}

void func_803884C0(s32 x, s32 y, s32 z){
    f32 sp1C[3];
    TUPLE_ASSIGN(sp1C, x, y, z);
    jiggySpawn(JIGGY_9_MM_CHIMPY, sp1C);
}

void func_80388514(ActorMarker *marker, s32 arg1, s32 arg2){
    Actor * actor = marker_getActor(marker);
    mapSpecificFlags_set(4,1);
    func_80328A84(actor, 3);
    func_80324E60(2.3f, 0x12);
    timedFunc_set_3(2.9f,func_803884C0, actor->position_x, actor->position_y + 150.0f, actor->position_z);
    func_80324E88(4.3f);
    func_80324E38(4.3f, 0);
}

void func_803885D0(Actor *this){
    func_8028E668(this->position, 35.0f, 0.0f, 65.0f);
    actor_collisionOff(this);
    this->marker->propPtr->unk8_3 = 1;
    if(func_803348C0() != MAP_2_MM_MUMBOS_MOUNTAIN){
        func_80343DEC(this);
    }else{//L80388630
        if(func_80329530(this, 0x2BC) && !func_803114B0()){
            func_803883AC(this);
        }//L8038865C
        switch(this->state){
            case 1://L80388690
                if(mapSpecificFlags_get(2)){
                    func_80328A84(this, 4);
                    if(!jiggyscore_isCollected(JIGGY_9_MM_CHIMPY)){
                        func_80311480(0xB40, 0xE, this->position, this->marker, func_80388514, NULL);
                    }else{//L803886E8
                        func_80388514(this->marker, 0xB40, -1);
                    }//L80388898
                }else{
                    func_80388300(&this);
                    if( func_80329530(this, 0x159)
                        && !func_80329530(this, 0x96)
                        && !item_getCount(ITEM_19_ORANGE)
                        && !this->unk138_24
                    ){
                        func_80311480(0xb3f, 0xe, this->position, NULL, NULL, NULL);
                        this->unk138_24 = 1;
                    }//L80388774
                    actor_loopAnimation(this);
                    func_80328BD4(this, 2, 0.0f, -1, 0.02f);
                }
                break;
            case 2: //L803887A4
                func_80388300(&this);
                actor_playAnimationOnce(this);
                if(actor_animationIsAt(this, 0.99f)){
                    func_80328B8C(this,1,0.0f,-1);
                }
                break;
            case 4: //L803887E4
                actor_loopAnimation(this);
                break;
            case 3: //L803887F4
                func_80343DEC(this);
                actor_loopAnimation(this);
                if(0.19 <= this->unk48){
                    mapSpecificFlags_set(0, 1);
                }
                if(0.24 <= this->unk48){
                    mapSpecificFlags_set(3, 1);
                }
                if(0.99 <= this->unk48){
                    marker_despawn(this->marker);
                }
                break;
        }
    }//L80388898
}
