#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CD8(f32);

Actor *func_803875E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038774C(Actor *this);
void func_8038794C(Actor *this);
Actor *func_80328230(enum actor_e id, f32 pos[3], f32 rot[3]);

/* .data */
ActorAnimationInfo D_80391B80[] = {
    {0x000, 0.0f},
    {0x14E, 2.0f},
    {0x14D, 7.0f},
    {0x14C, 2.0f},
    {0x14F, 0.5f},
    {0x14F, 1.0f}
};

ActorInfo D_80391BB0 = { 
    MARKER_124_BOGGY_1, ACTOR_160_BOGGY_1, ASSET_38A_MODEL_BOGGY_1, 
    0x1, D_80391B80, 
    func_8038774C, func_8038794C, func_803875E0, 
    2500, 0, 1.4f, 0
};

f32 D_80391BD4[3] = {1592.0f, 673.0f, 5895.0f};
f32 D_80391BE0[3] = { 0.0f, 0.0f, 0.0f};
f32 D_80391BEC[5] = {2.0f, 2.8f, 4.3f, 5.1f, 5.7f};

/* .code */
Actor *func_803875E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    
    if(!this->unk38_31 || this->state == 5)
        return this;
    
    func_8033A45C(1, 0);
    func_8033A45C(3, 1);
    this = actor_draw(marker, gfx, mtx, vtx);
    if(marker->unk14_21){
        func_8034A174(func_80329934(), 5, this->velocity);
    }
    return this;
}

void func_803876A4(Actor *this){
    subaddie_set_state_with_direction(this, 2, 0.0001f, 1);
    actor_playAnimationOnce(this);
    FUNC_8030E8B4(SFX_8E_GRUNTLING_DAMAGE, 1.0f, 32000, this->position, 1250, 2500);
}

void func_803876F8(Actor *this){
    this->marker->propPtr->unk8_3 = FALSE;
    subaddie_set_state_with_direction(this, 5, 0.0001f, 1);
    this->unk48 = 0.0f;
    func_80343DEC(this);
}

void func_8038774C(Actor *this){}

void func_80387754(ActorMarker *this_marker, ActorMarker *other_marker){}

void func_80387760(ActorMarker *marker){
    Actor *other = func_80328230(ACTOR_C8_BOGGY_2, D_80391BD4, D_80391BE0);
    other->unk4C = 1.0f;
    func_80343DEC(other);
}

void func_803877A8(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    
    if(arg2 == 1){
        jiggy_spawn(JIGGY_2A_FP_BOGGY_1, this->velocity);
    }
    else if(arg2 == 2){
        subaddie_set_state_with_direction(this, 4, 0.0001f, 1);
        actor_loopAnimation(this);
        actor_collisionOff(this);
    }
}

void func_80387828(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);

    if (text_id == 0xc00) {
        gcdialog_showText(ASSET_C2B_TEXT_UNKNOWN, 0xf, NULL, this->marker, NULL, func_803877A8);
    }
}

void func_8038787C(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    s32 s0;
    f32 sp24;
    s32 sp20;

    s0 = func_802F9AA8(SFX_12B_BOILING_AND_BUBBLING);
    sp24 = randf2(0.9f, 1.1f);
    sp20 = (s32)randf2(16000.0f, 23000.0f);
    func_802F9DB8(s0, sp24, sp24, 0.0f);
    func_802F9EC4(s0, this->position, 500, 1200);
    func_802F9F80(s0, 0.05f, 0.2f, 0.3f);
    func_802FA060(s0, sp20, sp20, 0.0f);
}

void func_8038794C(Actor *this){
    int i;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_80387754, NULL);
        this->unk38_31 = 1;
        ml_vec3f_copy(this->velocity, this->position);
        
        if(volatileFlag_get(VOLATILE_FLAG_1))
            return;

        if(!jiggyscore_isCollected(JIGGY_2A_FP_BOGGY_1) && jiggyscore_isSpawned(JIGGY_2A_FP_BOGGY_1)){
            func_803876F8(this);
            actor_collisionOff(this);
        }

        if(jiggyscore_isCollected(JIGGY_2A_FP_BOGGY_1)){
            if(!jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3) && !jiggyscore_isSpawned(JIGGY_2C_FP_BOGGY_3)){
                __spawnQueue_add_1((GenFunction_1)func_80387760, reinterpret_cast(s32, this->marker));
            }
            this->unk38_31 = 0;
            actor_collisionOff(this);
            this->marker->propPtr->unk8_3 = FALSE;
        }
    }//L80387A68
    
    if( !this->unk38_31 ) return;
    switch(this->state){
        case 1://L80387AB0
            if(mapSpecificFlags_get(0xb))
                this->has_met_before = TRUE;

            if(mapSpecificFlags_get(0x1)){
                func_8028F94C(1, this->position);
                timed_setStaticCameraToNode(0.0f, 0x12);
                func_80324DBC(1.0f, 0xc00, 0xe, NULL, this->marker, func_80387828, func_803877A8);
                func_803876A4(this);
                break;
            }//L80387B38

            if(!this->has_met_before && func_80329530(this, 0x1f4)){
                if(!func_8028ECAC() || func_8028ECAC() == BSGROUP_8_TROT){
                    if (gcdialog_showText(ASSET_BFF_TEXT_UNKNOWN, 0x2a, this->position, NULL, NULL, NULL)) {
                        for (i = 0; i < 5; i++) {
                            timedFunc_set_1(D_80391BEC[i], (GenFunction_1) func_8038787C, (s32) this->marker);
                        }
                        this->has_met_before = TRUE;
                    }
                }
            }

            break;
        case 2://L80387BEC
            func_8028FC8C(this->position);
            if(actor_animationIsAt(this, 0.1f)){
                FUNC_8030E8B4(SFX_F6_BLUBBER_TALKING_2, 1.0f, 32000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.24f)){//L80387C2C
                FUNC_8030E8B4(SFX_A0_COUGHING, 0.7f, 32000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.52f)){//L80387C60
                FUNC_8030E8B4(SFX_A0_COUGHING, 0.67f, 32000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.61f)){//L80387C94
                FUNC_8030E8B4(SFX_A0_COUGHING, 0.64f, 32000, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.69f)){//L80387CC8
                FUNC_8030E8B4(SFX_A0_COUGHING, 0.61f, 32000, this->position, 1250, 2500);
            }//L80387CF4

            if(actor_animationIsAt(this, 0.9999f)){
                subaddie_set_state_with_direction(this, 3, 0.0001f, 1);
                actor_loopAnimation(this);
            }
            break;
        case 4://L80387D2C
            func_80343DEC(this);
            func_8028FC8C(this->position);
            if(0.99 <= this->unk48){
                func_8028F918(0);
                func_80324CD8(0.0f);
                timed_exitStaticCamera(0.0f);
                func_803876F8(this);
            }
            break;
        case 5://L80387D90
            if(jiggyscore_isCollected(JIGGY_2A_FP_BOGGY_1)){
                this->unk38_31 = 0;
                __spawnQueue_add_1((GenFunction_1)func_80387760, reinterpret_cast(s32, this->marker));
            }
            break;
    }
}
