#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EE6CC(f32[3], s32[4], s32[4], s32, f32, f32, s32, s32, s32);

typedef struct {
    s32 closed_ticks_counter;
    s32 open_ticks_counter;
} ActorLocal_Lockup;

static Actor *__chLockup_drawFunc(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void __chLockup_updateFunc(Actor *this);

enum ch_lockup_states_e {
    CH_LOCKUP_STATE_CLOSED = 1,   // L803896F0
    CH_LOCKUP_STATE_OPENING = 2,  // L803897DC
    CH_LOCKUP_STATE_OPEN = 3,     // L80389864
    CH_LOCKUP_STATE_CLOSING = 4,  // L803898F4
    CH_LOCKUP_STATE_CLOSING2 = 5  // L803898F4
};

/* .data */
ActorAnimationInfo gChLockupAnimations[6] ={
    {NULL, NULL},
    {ASSET_BC_ANIM_LOCKUP, 8000000.0f},
    {ASSET_BC_ANIM_LOCKUP, 4.0f},
    {ASSET_BC_ANIM_LOCKUP, 8000000.0f},
    {ASSET_BC_ANIM_LOCKUP, 1.4f},
    {ASSET_BC_ANIM_LOCKUP, 8000000.0f}
};

ActorInfo gChLockupSlow = {
    MARKER_A4_LOCKUP_SLOW, ACTOR_151_LOCKUP_SLOW, ASSET_3D4_MODEL_LOCKUP, 
    1, gChLockupAnimations, 
    __chLockup_updateFunc, actor_update_func_80326224, __chLockup_drawFunc,
    2500, 0x366, 0.0f, 0
}; 

ActorInfo gChLockupMedium = {
    MARKER_F6_LOCKUP_MEDIUM, ACTOR_152_LOCKUP_MEDIUM, ASSET_3D4_MODEL_LOCKUP, 
    1, gChLockupAnimations, 
    __chLockup_updateFunc, actor_update_func_80326224, __chLockup_drawFunc,
    2500, 0x366, 0.0f, 0
}; 

ActorInfo gChLockupFast = {
    MARKER_F7_LOCKUP_FAST, ACTOR_153_LOCKUP_FAST, ASSET_3D4_MODEL_LOCKUP, 
    1, gChLockupAnimations, 
    __chLockup_updateFunc, actor_update_func_80326224, __chLockup_drawFunc,
    2500, 0x366, 0.0f, 0
}; 

static s32 sLockup_CloseColor[4] = {120, 120, 120, 120};
static s32 sLockup_CloseVelocity[3] = {0,0,0};

/* .code */
static Actor *__chLockup_drawFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor * actor = marker_getActor(marker);
    func_8033A45C(3, actor->unk38_31);
    func_8033A45C(4, actor->unk38_31);
    actor_draw(marker, gfx, mtx, vtx);
}

static void __chLockup_close(Actor *this){
    subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_CLOSED, 0.2f, 1);
    this->marker->collidable = FALSE;
    this->unk38_31 = 0;
    FUNC_8030E8B4(SFX_6C_LOCKUP_CLOSING, 1.0f, 32000, this->position, 1250, 2500);
}

static void __chLockup_open(Actor *this){
    func_80389468();
    subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_OPENING, 0.2f, 1);
    this->unk38_31 = 1;
    FUNC_8030E8B4(SFX_6B_LOCKUP_OPENING, 1.0f, 32000, this->position, 1250, 2500);
}

static void __chLockup_updateFunc(Actor *this){
    ActorLocal_Lockup *local = (ActorLocal_Lockup *)&this->local;
    s32 tmp_v1;
    int i;

    if( !this->has_met_before
        && this->unkF4_8 == 0xA
        && !jiggyscore_isCollected(JIGGY_13_TTC_LOCKUP)
        && func_80329530(this, 320)
        && !func_80329530(this, 160)
        && !func_8028ECAC()
        && gcdialog_showText(ASSET_A15_TEXT_TTC_LOCKUP_SPAWNED, 0, NULL, NULL, NULL, NULL)
    ){
        this->has_met_before = TRUE;
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
    }

    switch(this->state){
        case CH_LOCKUP_STATE_CLOSED:
            if(!this->initialized){
                this->marker->propPtr->unk8_3 = TRUE;
                subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_CLOSED, 0.2f, 1);
                this->marker->collidable = FALSE;
                this->unk38_31 = 0;
                this->initialized = TRUE;
            }
            local->closed_ticks_counter++;

            tmp_v1 = (this->modelCacheIndex == ACTOR_151_LOCKUP_SLOW) ? 0x1E :
                     (this->modelCacheIndex == ACTOR_152_LOCKUP_MEDIUM) ? 0x14 :
                     (this->modelCacheIndex == ACTOR_153_LOCKUP_FAST) ? 0xA :
                     10000;
            

            if(!(local->closed_ticks_counter < tmp_v1)){
                local->closed_ticks_counter = 0;
                __chLockup_open(this);
            }
            break;

        case CH_LOCKUP_STATE_OPENING:
            if(subaddie_playerIsWithinSphere(this, 400) && func_8028FB48(0x8000000)){
                func_8028F428(0xA, this->marker);
            }

            if(actor_animationIsAt(this, 0.5f)){
                subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_OPEN, 0.5f, 1);
            }
            if(0.15 < animctrl_getAnimTimer(this->animctrl)){
                this->marker->collidable = TRUE;
            }
            break;

        case CH_LOCKUP_STATE_OPEN:
            local->open_ticks_counter++;
            tmp_v1 = (this->modelCacheIndex == ACTOR_151_LOCKUP_SLOW) ? 0x1E :
                     (this->modelCacheIndex == ACTOR_152_LOCKUP_MEDIUM) ? 0x14 :
                     (this->modelCacheIndex == ACTOR_153_LOCKUP_FAST) ? 0xA :
                     10000;
            
            if(!(local->open_ticks_counter < tmp_v1)){
                local->open_ticks_counter = 0;
                subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_CLOSING, 0.5f, 1);
            }
            break;

        case CH_LOCKUP_STATE_CLOSING:
        case CH_LOCKUP_STATE_CLOSING2:
            if(this->marker->unk14_21 && actor_animationIsAt(this, 0.99f)){
                __chLockup_close(this);
                for(i = 5; i < 0xe; i++){
                    func_8034A174(this->marker->unk44, i, this->unk1C);
                    func_802EE6CC(this->unk1C, sLockup_CloseVelocity, sLockup_CloseColor, 1, 0.4f, 50.0f, 0xb4, 0xa0, 0);
                }
            }
            break;
    }
}
