#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EE6CC(f32[3], s32[4], s32[4], s32, f32, f32, s32, s32, s32);

typedef struct {
    s32 unk0;
    s32 unk4;
}ActorLocal_Lockup;

Actor *func_803894C0(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80389600(Actor *this);

/* .data */
ActorAnimationInfo D_8038C760[] ={
    {0, 0.0f},
    {ASSET_BC_ANIM_LOCKUP, 8000000.0f},
    {ASSET_BC_ANIM_LOCKUP, 4.0f},
    {ASSET_BC_ANIM_LOCKUP, 8000000.0f},
    {ASSET_BC_ANIM_LOCKUP, 1.4f},
    {ASSET_BC_ANIM_LOCKUP, 8000000.0f}
};

ActorInfo D_8038C790 = {
    MARKER_A4_LOCKUP_SLOW, ACTOR_151_LOCKUP_SLOW, ASSET_3D4_MODEL_LOCKUP, 
    1, D_8038C760, 
    func_80389600, func_80326224, func_803894C0,
    2500, 0x366, 0.0f, 0
}; 

ActorInfo D_8038C7B4 = {
    MARKER_F6_LOCKUP_MEDIUM, ACTOR_152_LOCKUP_MEDIUM, ASSET_3D4_MODEL_LOCKUP, 
    1, D_8038C760, 
    func_80389600, func_80326224, func_803894C0,
    2500, 0x366, 0.0f, 0
}; 

ActorInfo D_8038C7D8 = {
    MARKER_F7_LOCKUP_FAST, ACTOR_153_LOCKUP_FAST, ASSET_3D4_MODEL_LOCKUP, 
    1, D_8038C760, 
    func_80389600, func_80326224, func_803894C0,
    2500, 0x366, 0.0f, 0
}; 

s32 D_8038C7FC[4] = {120, 120, 120, 120};
s32 D_8038C80C[4] = {0,0,0,0};

/* .code */
Actor *func_803894C0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor * actor = marker_getActor(marker);
    func_8033A45C(3, actor->unk38_31);
    func_8033A45C(4, actor->unk38_31);
    actor_draw(marker, gfx, mtx, vtx);

}

void TTC_func_80389530(Actor *this){
    subaddie_set_state_with_direction(this, 1, 0.2f, 1);
    this->marker->collidable = FALSE;
    this->unk38_31 = 0;
    FUNC_8030E8B4(SFX_6C_LOCKUP_CLOSING, 1.0f, 32000, this->position, 1250, 2500);

}

void func_8038959C(Actor *this){
    func_80389468();
    subaddie_set_state_with_direction(this, 2, 0.2f, 1);
    this->unk38_31 = 1;
    FUNC_8030E8B4(SFX_6B_LOCKUP_OPENING, 1.0f, 32000, this->position, 1250, 2500);
}

void func_80389600(Actor *this){
    ActorLocal_Lockup *local = (ActorLocal_Lockup *)&this->local;
    s32 tmp_v1;
    int i;

    if( !this->unk138_24 
        && this->unkF4_8 == 0xA
        && !jiggyscore_isCollected(JIGGY_13_TTC_LOCKUP)
        && func_80329530(this, 320)
        && !func_80329530(this, 160)
        && !func_8028ECAC()
        && func_80311480(0xA15, 0, NULL, NULL, NULL, NULL)
    ){
        this->unk138_24 = 1;
    }//L803896AC

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
    }

    switch(this->state){
        case 1: //L803896F0
            if(!this->initialized){
                this->marker->propPtr->unk8_3 = TRUE;
                subaddie_set_state_with_direction(this, 1, 0.2f, 1);
                this->marker->collidable = FALSE;
                this->unk38_31 = 0;
                this->initialized = TRUE;
            }//L80389758
            local->unk0++;

            tmp_v1 = (this->modelCacheIndex == ACTOR_151_LOCKUP_SLOW) ? 0x1E :
                     (this->modelCacheIndex == ACTOR_152_LOCKUP_MEDIUM) ? 0x14 :
                     (this->modelCacheIndex == ACTOR_153_LOCKUP_FAST) ? 0xA :
                     10000;
            

            if(!(local->unk0 < tmp_v1)){
                local->unk0 = 0;
                func_8038959C(this);
            }
            break;

        case 2: //L803897DC
            if(subaddie_playerIsWithinSphere(this, 400) && func_8028FB48(0x8000000)){
                func_8028F428(0xA, this->marker);
            }

            if(actor_animationIsAt(this, 0.5f)){
                subaddie_set_state_with_direction(this, 3, 0.5f, 1);
            }
            if(0.15 < animctrl_getAnimTimer(this->animctrl)){
                this->marker->collidable = TRUE;
            }
            break;

        case 3: //L80389864
            local->unk4++;
            tmp_v1 = (this->modelCacheIndex == ACTOR_151_LOCKUP_SLOW) ? 0x1E :
                     (this->modelCacheIndex == ACTOR_152_LOCKUP_MEDIUM) ? 0x14 :
                     (this->modelCacheIndex == ACTOR_153_LOCKUP_FAST) ? 0xA :
                     10000;
            
            if(!(local->unk4 < tmp_v1)){
                local->unk4 = 0;
                subaddie_set_state_with_direction(this, 4, 0.5f, 1);
            }
            break;

        case 4: //L803898F4
        case 5: //L803898F4
            if(this->marker->unk14_21 && actor_animationIsAt(this, 0.99f)){
                TTC_func_80389530(this);
                for(i = 5; i < 0xe; i++){
                    func_8034A174(this->marker->unk44, i, this->unk1C);
                    func_802EE6CC(this->unk1C, D_8038C80C, D_8038C7FC, 1, 0.4f, 50.0f, 0xb4, 0xa0, 0);
                }
            }
            break;
    }//L8038999C
}
