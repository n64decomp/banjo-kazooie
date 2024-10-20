#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3);
extern void func_8028FA34(s32, Actor*);
extern  s32 func_802E0970(s32, f32, f32, f32, s32, s32, f32[3]);

typedef struct {
    u8 unk0[0xE]; // unused?
    s16 unkE; // some sort of index
    f32 throw_target_position[3];
    s32 throw_target_radius;
    NodeProp* gold_bullion_throw_target_node_prop;
    s32 unk24; // bullions left to collect ? (changes from 4 to 0)
} ActorLocal_Blubber;

static void __chBlubber_updateFunc(Actor *this);
static void __chBlubber_update2Func(Actor *this);
static Actor *__chBlubber_drawFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

enum ch_blubber_states_e {
    CH_BLUBBER_STATE_1_UNKNOWN = 1, // initial state (80387A84)
    CH_BLUBBER_STATE_2_UNKNOWN = 2, // 80387B10
    CH_BLUBBER_STATE_3_UNKNOWN = 3,
    CH_BLUBBER_STATE_4_UNKNOWN = 4, // 80387C04
    CH_BLUBBER_STATE_5_UNKNOWN = 5  // 80387CD4
};

/* .data */
ActorAnimationInfo gChBlubberAnimations[6] = {
    {NULL, NULL},
    {ASSET_B5_ANIM_BLUBBER_WALK, 2.0f},
    {ASSET_B6_ANIM_BLUBBER_CRY, 2.0f},
    {ASSET_B6_ANIM_BLUBBER_CRY, 2.0f},
    {ASSET_B7_ANIM_BLUBBER_DANCE, 1.4f},
    {ASSET_B8_ANIM_BLUBBER_RUN, 0.8f}
};

ActorInfo gChBlubber = {
    MARKER_A3_BLUBBER, ACTOR_115_BLUBBER, ASSET_370_MODEL_BLUBBER,
    0x1, gChBlubberAnimations,
    __chBlubber_updateFunc, __chBlubber_update2Func, __chBlubber_drawFunc,
    0, 0x399, 1.8f, 0
};

/* .code */
static void __chBlubber_initiliaze(Actor *this){
    ActorLocal_Blubber *local = (ActorLocal_Blubber *)&this->local;

    animctrl_setTransitionDuration(this->animctrl, 0.2f);
    this->initialized = TRUE;
    local->gold_bullion_throw_target_node_prop = nodeprop_findByActorIdAndActorPosition(ACTOR_2B_GOLD_BULLION_THROW_TARGET, this);
    if(local->gold_bullion_throw_target_node_prop){
        nodeprop_getPosition(local->gold_bullion_throw_target_node_prop, local->throw_target_position);
        local->throw_target_radius = nodeprop_getRadius(local->gold_bullion_throw_target_node_prop);
    }
    local->unk24 = 4;
    func_8032A82C(this, 0x14C);
}

static void __chBlubber_showTextCallback(ActorMarker *caller, enum asset_e text_id, s32 arg1){
    Actor *this = marker_getActor(caller);
    ActorLocal_Blubber *local =  (ActorLocal_Blubber*)&this->local;

    if(text_id == ASSET_A0D_DIALOG_BLUBBER_COMPLETE || text_id == ASSET_A2A_BLUBBER_COMPLETE_JIGGY_COLLECTED){
        local->unk24 = 0;
    }
    else{
        subaddie_set_state_with_direction(this, CH_BLUBBER_STATE_2_UNKNOWN, 0, 1);
    }
}

static void __chBlubber_showTextCallback2(ActorMarker *caller, enum asset_e text_id, s32 arg1){
    f32 sp24[3];

    if(nodeProp_findPositionFromActorId(ACTOR_14B_TTC_BLUBBER_UNKNOWN, sp24)){
        jiggy_spawn(JIGGY_14_TTC_BLUBBER, sp24);
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM, reinterpret_cast(s32, sp24[0]), reinterpret_cast(s32, sp24[1]), reinterpret_cast(s32, sp24[2]));
    }
}

static void __chBlubber_showJiggySpawnedText(ActorMarker *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    enum asset_e text_id;

    subaddie_set_state(this, CH_BLUBBER_STATE_4_UNKNOWN);
    actor_loopAnimation(this);
    this->actor_specific_1_f = 0.0f;

    if(!mapSpecificFlags_get(TTC_SPECIFIC_FLAG_2_BLUBBER_JIGGY_SPAWNED_TEXT_SHOWN)) {
        text_id = jiggyscore_isCollected(JIGGY_14_TTC_BLUBBER) ? ASSET_A2A_BLUBBER_COMPLETE_JIGGY_COLLECTED : ASSET_A0D_DIALOG_BLUBBER_COMPLETE;
        gcdialog_showText(text_id, 0xf, this->position, this->marker, __chBlubber_showTextCallback, __chBlubber_showTextCallback2);
        mapSpecificFlags_set(TTC_SPECIFIC_FLAG_2_BLUBBER_JIGGY_SPAWNED_TEXT_SHOWN, TRUE);
    }
}

static void __chBlubber_checkJiggySpawnedTextAndAdvanceState(Actor *this){
    if( !mapSpecificFlags_get(TTC_SPECIFIC_FLAG_1_UNKNOWN) ) return;
    if(  mapSpecificFlags_get(TTC_SPECIFIC_FLAG_3_BLUBBER_SHOW_JIGGY_SPAWNED_TEXT_FLAG) ) return;

    this->yaw_ideal = (f32) func_80329784(this);
    mapSpecificFlags_set(TTC_SPECIFIC_FLAG_3_BLUBBER_SHOW_JIGGY_SPAWNED_TEXT_FLAG, TRUE);
    func_8028F918(2);
    timed_setStaticCameraToNode(0.0f, 4);
    timedFunc_set_1(1.0f, (GenFunction_1)__chBlubber_showJiggySpawnedText, (s32)this->marker);
    subaddie_set_state_with_direction(this, CH_BLUBBER_STATE_1_UNKNOWN, 0.0f, 1);
}

static void __func_8038771C(Actor *this){
    if( !func_80329030(this, 0)
        && func_80329480(this)
    ){
        func_80328CEC(this, (s32)this->yaw_ideal, 120, 180);
    }
}

// probably something related to blubber throwing the bullions
static void __func_80387774(Actor **this_ptr){
    ActorLocal_Blubber *local = (ActorLocal_Blubber *)&(*this_ptr)->local;

    player_setCarryObjectPoseInCylinder(local->throw_target_position, local->throw_target_radius, 100.0f, ACTOR_2A_GOLD_BULLION, this_ptr);
    if( func_80329530(*this_ptr, 200)
        && bacarry_get_markerId() == MARKER_37_GOLD_BULLION
        && player_throwCarriedObject()
    ) {
        func_8028FA34(!mapSpecificFlags_get(TTC_SPECIFIC_FLAG_0_BLUBBER_UNKNOWN) ? ACTOR_149_TTC_BLUBBER_UNKNOWN : ACTOR_14A_TTC_BLUBBER_UNKNOWN, *this_ptr);
        (*this_ptr)->has_met_before = TRUE;
    }

}

static void __func_80387830(Actor *this , f32 arg1, f32 arg2){
    if( actor_animationIsAt(this, arg1) 
        || actor_animationIsAt(this, arg2)
    ){
        this->unk10_12 = func_802E0970(SFX_26_BANJO_LANDING_09, 0.75f, 0.85f, 0.05f, 11000, this->unk10_12, this->position);
    }
}

static void __chBlubber_updateFunc(Actor *this){
    ActorLocal_Blubber *local;

    this->marker->propPtr->unk8_3 = TRUE;
    func_8028E668(this->position, 90.0f, -10.0f, 110.0f);
    if(!mapSpecificFlags_get(TTC_SPECIFIC_FLAG_1_UNKNOWN) && !func_80329530(this, 2500))
        return;
    
    if(!this->volatile_initialized){
        if(this->state == CH_BLUBBER_STATE_3_UNKNOWN){
            subaddie_set_state_with_direction(this, CH_BLUBBER_STATE_2_UNKNOWN, 0.0f, 1);
        }
        this->volatile_initialized = TRUE;
    }//L80387970

    if(func_80329530(this, 250) && !func_80329530(this, 80)
        && !this->has_met_before
        && item_getCount(ITEM_18_GOLD_BULLIONS) == 0
    ){
        gcdialog_showText(ASSET_A0B_DIALOG_BLUBBER_FIRST_MEET, 0xe, this->position, this->marker, __chBlubber_showTextCallback, NULL);
        this->has_met_before = TRUE;
        subaddie_set_state_forward(this, CH_BLUBBER_STATE_3_UNKNOWN);
    }

    if( mapSpecificFlags_get(TTC_SPECIFIC_FLAG_0_BLUBBER_UNKNOWN)
        && !this->unk138_23
    ){
        if (item_getCount(ITEM_18_GOLD_BULLIONS) == 0) {
            gcdialog_showText(ASSET_A0C_DIALOG_BLUBBER_HALF_GOLD, 4, NULL, NULL, NULL, NULL);
        }
        
        this->unk138_23 = TRUE;
        this->has_met_before = TRUE;
    }//L80387A54

    switch(this->state){//D_8038CD40
        case CH_BLUBBER_STATE_1_UNKNOWN:
            if(!this->initialized){
                actor_collisionOff(this);
                __chBlubber_initiliaze(this);
            }
            __func_80387774(&this);
            
            if(subaddie_maybe_set_state_position_direction(this, CH_BLUBBER_STATE_2_UNKNOWN, 0.0f, 1, 0.007f))
                break;

            func_80328FB0(this, 3.0f);
            __func_8038771C(this);
            __func_80387830(this, 0.14f, 0.68f);
            __chBlubber_checkJiggySpawnedTextAndAdvanceState(this);
            break;

        case CH_BLUBBER_STATE_2_UNKNOWN:
            __func_80387774(&this);
            if( actor_animationIsAt(this, 0.99f) 
                && subaddie_maybe_set_state_position_direction(this, CH_BLUBBER_STATE_1_UNKNOWN, 0.0f, 1, 0.78f)
            ){
                this->actor_specific_1_f = 4.0f;
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

            __chBlubber_checkJiggySpawnedTextAndAdvanceState(this);
            break;
        
        case CH_BLUBBER_STATE_3_UNKNOWN:
            break;
        
        case CH_BLUBBER_STATE_4_UNKNOWN:
            {                
                func_80328FB0(this, 3.0f);
                local =  (ActorLocal_Blubber*)&this->local;
                if(actor_animationIsAt(this, 0.99f) && !local->unk24){
                    subaddie_set_state(this, CH_BLUBBER_STATE_5_UNKNOWN);
                    this->actor_specific_1_f = 8.0f;
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

        case CH_BLUBBER_STATE_5_UNKNOWN:
            local =  (ActorLocal_Blubber*)&this->local;
            func_8032A95C(this, local->unkE, 0x21c);
            break;
    }
}

static void __chBlubber_update2Func(Actor *this){
    func_80343DEC(this);
    if(0.99 <= this->unk48){
        func_8028F918(0);
        timed_exitStaticCamera(0.0f);
        marker_despawn(this->marker);
    }
    __func_80387830(this, 0.5f, 0.97f);
}

static Actor *__chBlubber_drawFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(4, 0);
    return actor_draw(marker, gfx, mtx, vtx);
}
