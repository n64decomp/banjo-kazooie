#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8028E668(f32 *, f32, f32, f32);
int actor_animationIsAt(Actor *, f32);
void subaddie_set_state_with_direction(Actor *, s32, f32, s32);
void timed_exitStaticCamera(f32);
void func_80324E38(f32,s32);
void timed_setStaticCameraToNode(f32, s32);
s32 func_8028F31C(f32 *, f32, s32, Actor **);
void func_8028FA34(s32, Actor *);


void chLMonkey_update(Actor *);

/* .data */
ActorAnimationInfo chlmonkeyAnimations[5] = {
    {0, 0.0f},
    {ASSET_5C_ANIM_CHIMPY_IDLE, 2.3f},
    {ASSET_5B_ANIM_CHIMPY_JUMP, 0.67f},
    {ASSET_5D_ANIM_CHIMPY_WALK, 0.5f},
    {ASSET_5C_ANIM_CHIMPY_IDLE, 2.3f}
};

ActorInfo chlmonkeyInfo = { MARKER_A_CHIMPY, ACTOR_F_CHIMPY, ASSET_35D_MODEL_CHIMPY, 
    1, chlmonkeyAnimations,
    NULL, chLMonkey_update, actor_draw,
    2500, 0, 0.8f, 0
};

/* .code */
void func_80388300(Actor **arg0){
    func_8028F31C((*arg0)->position, 800.0f, ACTOR_29_ORANGE_COLLECTIBLE, arg0);
    if( func_80329530(*arg0, 345) 
        && bacarry_get_markerId() == MARKER_36_ORANGE_COLLECTIBLE
        && func_8028FC34()
    ){
        func_8028FA34(0xc6, *arg0);
        (*arg0)->unk138_24 = 1;
        timed_setStaticCameraToNode(1.2f, 0xF);
        func_80324E38(1.2f, 3);
    }
    if(arg0);
}

void MM_func_803883AC(Actor *this){
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

void __chLMonkey_spawnJiggy(s32 x, s32 y, s32 z){
    f32 sp1C[3];
    TUPLE_ASSIGN(sp1C, x, y, z);
    jiggySpawn(JIGGY_9_MM_CHIMPY, sp1C);
}

void __chLMonkey_complete(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    Actor * actor = marker_getActor(marker);
    mapSpecificFlags_set(4,1);
    subaddie_set_state(actor, 3);
    timed_setStaticCameraToNode(2.3f, 0x12);
    timedFunc_set_3(2.9f,__chLMonkey_spawnJiggy, actor->position_x, actor->position_y + 150.0f, actor->position_z);
    timed_exitStaticCamera(4.3f);
    func_80324E38(4.3f, 0);
}

void chLMonkey_update(Actor *this){
    func_8028E668(this->position, 35.0f, 0.0f, 65.0f);
    actor_collisionOff(this);
    this->marker->propPtr->unk8_3 = 1;
    if(map_get() != MAP_2_MM_MUMBOS_MOUNTAIN){
        func_80343DEC(this);
    }else{//L80388630
        if(func_80329530(this, 700) && !func_803114B0()){
            MM_func_803883AC(this);
        }//L8038865C
        switch(this->state){
            case 1://L80388690
                if(mapSpecificFlags_get(2)){
                    subaddie_set_state(this, 4);
                    if(!jiggyscore_isCollected(JIGGY_9_MM_CHIMPY)){
                        func_80311480(ASSET_B40_DIALOG_CHIMPY_COMPLETE, 0xE, this->position, this->marker, __chLMonkey_complete, NULL);
                    }else{//L803886E8
                        __chLMonkey_complete(this->marker, ASSET_B40_DIALOG_CHIMPY_COMPLETE, -1);
                    }//L80388898
                }else{
                    func_80388300(&this);
                    if( func_80329530(this, 345)
                        && !func_80329530(this, 150)
                        && !item_getCount(ITEM_19_ORANGE)
                        && !this->unk138_24
                    ){
                        func_80311480(ASSET_B3F_DIALOG_CHIMPY_MEET, 0xe, this->position, NULL, NULL, NULL);
                        this->unk138_24 = 1;
                    }//L80388774
                    actor_loopAnimation(this);
                    subaddie_maybe_set_state_position_direction(this, 2, 0.0f, -1, 0.02f);
                }
                break;
            case 2: //L803887A4
                func_80388300(&this);
                actor_playAnimationOnce(this);
                if(actor_animationIsAt(this, 0.99f)){
                    subaddie_set_state_with_direction(this,1,0.0f,-1);
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
