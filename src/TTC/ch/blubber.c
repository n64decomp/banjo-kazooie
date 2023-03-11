#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);
extern void func_8028FA34(s32, Actor*);
extern  s32 func_802E0970(s32, f32, f32, f32, s32, s32, f32[3]);

typedef struct {
    u8 unk0[0xE];
    s16 unkE;
    f32 throw_target_position[3];
    s32 throw_target_radius;
    NodeProp* unk20;
    s32 unk24;
}ActorLocal_Blubber;

void func_803878CC(Actor *this);
void TTC_func_80387CF4(Actor *this);
Actor *func_80387D6C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_8038C4E0[] = {
    {0x00, 0.0f},
    {ASSET_B5_ANIM_BLUBBER_WALK, 2.0f},
    {ASSET_B6_ANIM_BLUBBER_CRY, 2.0f},
    {ASSET_B6_ANIM_BLUBBER_CRY, 2.0f},
    {ASSET_B7_ANIM_BLUBBER_DANCE, 1.4f},
    {ASSET_B8_ANIM_BLUBBER_RUN, 0.8f}
};

ActorInfo TTC_D_8038C510 = { 
    MARKER_A3_BLUBBER, ACTOR_115_BLUBBER, ASSET_370_MODEL_BLUBBER,
    0x1, D_8038C4E0, 
    func_803878CC, TTC_func_80387CF4, func_80387D6C, 
    0, 0x399, 1.8f, 0
};

/* .code */
void func_80387490(Actor *this){
    ActorLocal_Blubber *local = (ActorLocal_Blubber *)&this->local;

    animctrl_setTransitionDuration(this->animctrl, 0.2f);
    this->initialized = TRUE;
    local->unk20 = func_80304C38(ACTOR_2B_GOLD_BULLION_THROW_TARGET, this);
    if(local->unk20){
        
        nodeprop_getPosition(local->unk20, local->throw_target_position);
        local->throw_target_radius = nodeprop_getRadius(local->unk20);
    }
    local->unk24 = 4;
    func_8032A82C(this, 0x14C);
}

void func_80387520(ActorMarker *caller, enum asset_e text_id, s32 arg1){
    Actor *this = marker_getActor(caller);
    ActorLocal_Blubber *local =  (ActorLocal_Blubber*)&this->local;

    if(text_id == 0xa0d || text_id == 0xa2a){
        local->unk24 = 0;
    }
    else{
        func_80328B8C(this, 2, 0, 1);
    }
}

void func_80387574(ActorMarker *caller, enum asset_e text_id, s32 arg1){
    f32 sp24[3];

    if(nodeProp_findPositionFromActorId(0x14b, sp24)){
        jiggySpawn(JIGGY_14_TTC_BLUBBER, sp24);
        __spawnQueue_add_4((GenMethod_4)func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, sp24[0]), reinterpret_cast(s32, sp24[1]), reinterpret_cast(s32, sp24[2]));
    }
}

void func_803875D4(ActorMarker *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    enum asset_e text_id;

    func_80328A84(this, 4);
    actor_loopAnimation(this);
    this->unk28 = 0.0f;

    if(!mapSpecificFlags_get(2)) {
        text_id = jiggyscore_isCollected(JIGGY_14_TTC_BLUBBER) ? 0xa2a : 0xa0d;
        func_80311480( text_id, 0xf, this->position, this->marker, func_80387520, func_80387574);
        mapSpecificFlags_set(2, TRUE);
    }
}

void func_80387678(Actor *this){
    if( !mapSpecificFlags_get(1) ) return;
    if(  mapSpecificFlags_get(3) ) return;

    this->yaw_ideal = (f32) func_80329784(this);
    mapSpecificFlags_set(3, TRUE);
    func_8028F918(2);
    timed_setStaticCameraToNode(0.0f, 4);
    timedFunc_set_1(1.0f, (GenMethod_1)func_803875D4, (s32)this->marker);
    func_80328B8C(this, 1, 0.0f, 1);
}

void func_8038771C(Actor *this){
    if( !func_80329030(this, 0)
        && func_80329480(this)
    ){
        func_80328CEC(this, (s32)this->yaw_ideal, 120, 180);
    }
}

void func_80387774(Actor **this_ptr){
    ActorLocal_Blubber *local = (ActorLocal_Blubber *)&(*this_ptr)->local;

    func_8028F364(local->throw_target_position, local->throw_target_radius, 100.0f, ACTOR_2A_GOLD_BULLION, this_ptr);
    if( func_80329530(*this_ptr, 200)
        && carriedObj_getMarkerId() == MARKER_37_GOLD_BULLION
        && func_8028FC34()
    ){
        func_8028FA34(!mapSpecificFlags_get(0)? 0x149 : 0x14a, *this_ptr);
        (*this_ptr)->unk138_24 = TRUE;
    }

}

void func_80387830(Actor *this , f32 arg1, f32 arg2){
    if( actor_animationIsAt(this, arg1) 
        || actor_animationIsAt(this, arg2)
    ){
        this->unk10_12 = func_802E0970(0x26, 0.75f, 0.85f, 0.05f, 11000, this->unk10_12, this->position);
    }
}

void func_803878CC(Actor * this){
    ActorLocal_Blubber *local;

    this->marker->propPtr->unk8_3 = TRUE;
    func_8028E668(this->position, 90.0f, -10.0f, 110.0f);
    if(!mapSpecificFlags_get(1) && !func_80329530(this, 2500))
        return;
    
    if(!this->unk16C_4){
        if(this->state == 3){
            func_80328B8C(this, 2, 0.0f, 1);
        }
        this->unk16C_4 = TRUE;
    }//L80387970

    if(func_80329530(this, 250) && !func_80329530(this, 80)
        && !this->unk138_24
        && item_getCount(ITEM_18_GOLD_BULLIONS) == 0
    ){
        func_80311480(0xa0b, 0xe, this->position, this->marker, func_80387520, NULL);
        this->unk138_24 = TRUE;
        func_80328AC8(this, 3);
    }

    if( mapSpecificFlags_get(0) 
        && !this->unk138_23
    ){
        if(item_getCount(ITEM_18_GOLD_BULLIONS) == 0)
            func_80311480(0xa0c, 4, NULL, NULL, NULL, NULL);
        
        this->unk138_23 = TRUE;
        this->unk138_24 = TRUE;

    }//L80387A54

    switch(this->state){//D_8038CD40
        case 1:// 80387A84
            if(!this->initialized){
                actor_collisionOff(this);
                func_80387490(this);
            }
            func_80387774(&this);
            
            if(func_80328BD4(this, 2, 0.0f, 1, 0.007f))
                break;

            func_80328FB0(this, 3.0f);
            func_8038771C(this);
            func_80387830(this, 0.14f, 0.68f);
            func_80387678(this);
            break;

        case 2:// 80387B10
            func_80387774(&this);
            if( actor_animationIsAt(this, 0.99f) 
                && func_80328BD4(this, 1, 0.0f, 1, 0.78f)
            ){
                this->unk28 = 4.0f;
                break;
            }

            if(actor_animationIsAt(this, 0.3f)){
                FUNC_8030E8B4(SFX_83_BLUBBER_CRYING, 0.95f, 17000, this->position, 1250, 2500);
            }

            if(actor_animationIsAt(this, 0.53f)){
                FUNC_8030E8B4(SFX_83_BLUBBER_CRYING, 0.93f, 17000, this->position, 1250, 2500);
            }

            if(actor_animationIsAt(this, 0.72f)){
                FUNC_8030E8B4(SFX_83_BLUBBER_CRYING, 0.91f, 17000, this->position, 1250, 2500);
            }

            func_80387678(this);
            break;
        
        case 3: 
            break;
        
        case 4:// 80387C04
            {                
                func_80328FB0(this, 3.0f);
                local =  (ActorLocal_Blubber*)&this->local;
                if(actor_animationIsAt(this, 0.99f) && !local->unk24){
                    func_80328A84(this, 5);
                    this->unk28 = 8.0f;
                }
            }
            
            if(actor_animationIsAt(this, 0.3f) && !func_803114B0()){
                FUNC_8030E624(SFX_8C_BOGGY_WAHEY, 1.0f, 27000);
            }

            if(actor_animationIsAt(this, 0.28f) || 
                (actor_animationIsAt(this, 0.78f) && !func_803114B0())
            ){
                FUNC_8030E624(SFX_80_YUMYUM_CLACK, 0.9f, 13000);
            }
            break;

        case 5:// 80387CD4
            local =  (ActorLocal_Blubber*)&this->local;
            func_8032A95C(this, local->unkE, 0x21c);
            break;
    }
}

void TTC_func_80387CF4(Actor *this){
    func_80343DEC(this);
    if(0.99 <= this->unk48){
        func_8028F918(0);
        timed_exitStaticCamera(0.0f);
        marker_despawn(this->marker);
    }
    func_80387830(this, 0.5f, 0.97f);
}

Actor *func_80387D6C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(4, 0);
    return func_80325888(marker, gfx, mtx, vtx);
}
