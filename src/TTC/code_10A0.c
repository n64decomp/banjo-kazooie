#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);
extern void func_8028FA34(s32, Actor*);
extern  s32 func_802E0970(s32, f32, f32, f32, s32, s32, f32[3]);

typedef struct {
    u8 unk0[0xE];
    s16 unkE;
    f32 unk10[3];
    s32 unk1C;
    u16* unk20;
    s32 unk24;
}ActorLocal_Blubber;

void func_803878CC(Actor *this);
void func_80387CF4(Actor *this);
Actor *func_80387D6C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorAnimationInfo D_8038C4E0[];

extern ActorInfo D_8038C510 = { 
    MARKER_A3_BLUBBER, ACTOR_115_BLUBBER, ASSET_370_MODEL_BLUBBER,
    0x1, D_8038C4E0, 
    func_803878CC, func_80387CF4, func_80387D6C, 
    { 0x0, 0x0}, 0x399, 1.8f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_80387490(Actor *this){
    ActorLocal_Blubber *local = &this->local;

    animctrl_setTransitionDuration(this->animctrl, 0.2f);
    this->initialized = TRUE;
    local->unk20 = func_80304C38(0x2b, this);
    if(local->unk20){
        
        func_80304D68(local->unk20, local->unk10);
        local->unk1C = func_80304D3C(local->unk20);
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

    if(func_80304E24(0x14b, sp24)){
        jiggySpawn(JIGGY_14_TTC_BLUBBER, sp24);
        func_802C3F04(func_802C4140, 0x4C, reinterpret_cast(s32, sp24[0]), reinterpret_cast(s32, sp24[1]), reinterpret_cast(s32, sp24[2]));
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

    this->yaw_moving = (f32) func_80329784(this);
    mapSpecificFlags_set(3, TRUE);
    func_8028F918(2);
    timed_setCameraToNode(0.0f, 4);
    timedFunc_set_1(1.0f, (TFQM1)func_803875D4, this->marker);
    func_80328B8C(this, 1, 0.0f, 1);
}

void func_8038771C(Actor *this){
    if( !func_80329030(this, 0)
        && func_80329480(this)
    ){
        func_80328CEC(this, (s32)this->yaw_moving, 120, 180);
    }
}

void func_80387774(Actor **this_ptr){
    ActorLocal_Blubber *local = &(*this_ptr)->local;

    func_8028F364(local->unk10, local->unk1C, 100.0f, 0x2a, this_ptr);
    if( func_80329530(*this_ptr, 200)
        && func_8028E88C() == 0x37
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
                FUNC_8030E8B4(SFX_83_BLUBBER_CRYING, 0x213, 0x3CB, this->position, 1250, 2500);
            }

            if(actor_animationIsAt(this, 0.53f)){
                FUNC_8030E8B4(SFX_83_BLUBBER_CRYING, 0x213, 0x3B7, this->position, 1250, 2500);
            }

            if(actor_animationIsAt(this, 0.72f)){
                FUNC_8030E8B4(SFX_83_BLUBBER_CRYING, 0x213, 0x3A2, this->position, 1250, 2500);
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
                FUNC_8030E624(SFX_8C_BOGGY_WAHEY, 0x34B, 0x3ff);
            }

            if(actor_animationIsAt(this, 0.28f) || 
                (actor_animationIsAt(this, 0.78f) && !func_803114B0())
            ){
                FUNC_8030E624(SFX_80_YUMYUM_CLACK, 0x196, 0x398);
            }
            break;

        case 5:// 80387CD4
            local =  (ActorLocal_Blubber*)&this->local;
            func_8032A95C(this, local->unkE, 0x21c);
            break;
    }
}

void func_80387CF4(Actor *this){
    func_80343DEC(this);
    if(0.99 <= this->unk48){
        func_8028F918(0);
        func_80324E88(0.0f);
        marker_despawn(this->marker);
    }
    func_80387830(this, 0.5f, 0.97f);
}

Actor *func_80387D6C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(4, 0);
    return func_80325888(marker, gfx, mtx, vtx);
}
