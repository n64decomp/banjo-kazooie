#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
    u8  unk30;
} ActorLocal_Wozza;

Actor *func_8038F210(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038F7AC(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392520[];

extern ActorInfo D_80392588 = { MARKER_20B_WOZZA, ACTOR_1F3_WOZZA, ASSET_494_MODEL_WOZZA, 
    0x1, D_80392520,
    func_8038F7AC, func_80326224, func_8038F210,
    0, 0, 1.6f, 0
};

extern f32 D_803925AC[3];

/* .code */
Actor *func_8038F210(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(func_8038BFA0() || this->unk38_31)
        return this;
    
    return func_80325888(marker, gfx, mtx, vtx);
    
}

void func_8038F274(void){
    UNK_TYPE(s32) v0 = func_8034C528(0x191);
    if(v0){
        func_8034DE60(v0, 0.0f, -500.0f, 0.2f, 1);
    }
}

void func_8038F2B8(Actor *this){
    func_80328B8C(this, 3, 0.02f, 1);
    actor_loopAnimation(this);
}

void func_8038F2F0(Actor *this){
    func_80328B8C(this, 11, 0.02f, 1);
    actor_loopAnimation(this);
    func_8038F274();
}

void func_8038F330(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    switch(text_id){
        case 0xC1B:
            func_80324E88(0.0f);
            break;

        case 0xC1C:
            func_80324E88(0.0f);
            func_8038F2F0(this);
            break;
    }
}

void func_8038F3A0(void){
    mapSpecificFlags_set(8, 1);
}

void func_8038F3C4(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    if(arg2 == 1){
        func_8038F3A0();
    }
}

void func_8038F3F4(ActorMarker *marker){
    Actor *actor  = marker_getActor(marker);
    func_8038F2B8(actor);
}

void func_8038F41C(Actor *this){
    func_80328B8C(this, 1, 0.02f, 1);
    actor_loopAnimation(this);
}

void func_8038F454(Actor *this){
    if(!mapSpecificFlags_get(7) && func_8028ECAC() != 0xA && func_80329530(this, 1000) ){
        mapSpecificFlags_set(7, TRUE);
        func_80328A84(this, 2);
        actor_loopAnimation(this);
        timed_setCameraToNode(0.0f, 0x2e);
        func_80324DBC(0.0f, 0xc1b, 0x2a, this->position, this->marker, func_8038F330, NULL);
        timedFunc_set_1(2.5f, (TFQM1)func_8038F3F4, (s32)this->marker);
    }
    else{
        func_8038F2B8(this);
    }
}

void func_8038F528(Actor *this){
    func_80328B8C(this, 4, 0.02f, 1);
    actor_loopAnimation(this);
}

void func_8038F560(Actor *this){
    func_80328B8C(this, 7, 0.02f, 1);
    actor_loopAnimation(this);
}

void func_8038F598(Actor *this, f32 arg1){
    this->yaw_moving = func_80329784(this);
    func_80328FB0(this, arg1);
}

bool func_8038F5D4(Actor *this, f32 arg1[3], f32 arg2, f32 arg3, s32 arg4){
    f32 sp24;

    sp24 = func_802877D8(this->animctrl);
    this->yaw_moving = (f32) func_803297C8(this, arg1);
    func_80328FB0(this, arg3);
    if(actor_animationIsAt(this, 0.9f)){
        FUNC_8030E8B4(SFX_3F2_UNKNOWN, 750, 0x332, this->position, 500, 2000);
    }
    this->unk28 = (1.0f- sp24)*arg2;
    func_80329054(this, 2);
    if(func_80256064(this->position, arg1) <= arg4)
        return TRUE;
    return FALSE;

}

bool func_8038F6C4(Actor *this, f32 arg1[3], f32 arg2){
    s32 dTheta;

    func_80328C64(this, func_803297C8(this, arg1));
    func_80328FB0(this, arg2);
    dTheta = this->yaw - this->yaw_moving;
    if(-arg2 <= dTheta && dTheta <= arg2){
        return TRUE;
    }
    return FALSE;
}

void func_8038F758(ActorMarker *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    Actor *jiggy = spawn_child_actor(ACTOR_1F4_WOZZAS_JIGGY, &this);
    s32 pad;
    
    jiggy->yaw = this->yaw;
    this->unk100 = jiggy->marker;
    jiggy->unk100 = this->marker;

}

void func_8038F7AC(Actor *this){
    ActorLocal_Wozza * local = (ActorLocal_Wozza *)&this->local;

    if(func_803203FC(0xC4)){
        if(!this->unk16C_4){
            this->unk16C_4 = TRUE;
            this->marker->propPtr->unk8_3 = FALSE;
            actor_collisionOff(this);
            this->unk58_0 = FALSE;
            func_8038F274();
        }
        return;
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        if(jiggyscore_isCollected(JIGGY_32_FP_WOZZA)){
            func_8038F274();
            marker_despawn(this->marker);
            return;
        }

        if(levelSpecificFlags_get(0x26)){
            this->unk38_31 = TRUE;
            func_8038F274();
        }
        else{//L8038F8A0
            func_80304E24(0x359, local->unk24);
            func_80304E24(0x35A, local->unk0);
            func_80304E24(0x35B, local->unkC);
            func_80304E24(0x35C, local->unk18);
            this->position[0] = local->unkC[0];\
            this->position[1] = local->unkC[1];\
            this->position[2] = local->unkC[2];
            func_802C3C88(func_8038F758, this->marker);
            local->unk30 = FALSE;
        }
    }//L8038F910

    if(func_8038BFA0() || this->unk38_31 || !actor_playerIsWithinDist(this, 3000)){
        actor_collisionOff(this);
        return;
    }

    actor_collisionOn(this);
    switch(this->state){
        case 1: //L8038F984
            if(func_8028ECAC() == 0xa){
                func_8038F454(this);
                break;
            }
            
            if(func_80329530(this, 1300) && player_getTransformation() == TRANSFORM_4_WALRUS){
                func_80328B8C(this, 8, 0.02f, 1);
                actor_loopAnimation(this);
                break;
            }

            if(func_80329530(this, 1000) && !func_803203FC(0x1f)){
                func_8038F454(this);
                break;
            }

            func_8038F598(this, 1.0f);
            if( actor_animationIsAt(this, 0.38f) || actor_animationIsAt(this, 0.7f)){
                if(randf() < 0.4)
                    animctrl_setDirection(this->animctrl, animctrl_isPlayedForwards(this->animctrl) ^ 1);
            }
            break;

        case 3: //L8038FA9C
            if(func_8038F5D4(this, local->unk24, 30.0f, 12.0f, 0x3C))
                func_8038F528(this);
            break;

        case 4: //L8038FAD0
            if(!func_80329530(this, 2000) && func_8028ECAC() != 0xA){
                func_8038F560(this);
                break;
            }

            if(func_8038F5D4(this, local->unk0, 30.0f, 12.0f, 0x3C)){
                func_80328B8C(this, 5, 0.02f, 1);
                actor_playAnimationOnce(this);
            }
            break;

        case 5: //L8038FB50
            func_8038F6C4(this, local->unk18, 1.0f);
            if(0.97 < func_802877D8(this->animctrl)){
                func_80328B8C(this, 6, 0.02f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 6: //L8038FBA8
            func_8038F6C4(this, local->unk18, 1.0f);
            if( func_80329530(this, 1700) ) break;
            if( func_8028ECAC() == 0xA )    break;
            
            func_8038F560(this);

            if(!local->unk30){
                if(func_80311480(0xc1d, 0x20, NULL, NULL, NULL, NULL)){
                    local->unk30 =  TRUE;
                }
            }
            break;

        case 7: //L8038FC30
            if(!func_8038F6C4(this, local->unkC, 4.5f)) 
                break;

            if(func_80329530(this, 1000) || func_8028ECAC() == 0xA){
                func_8038F528(this);
                break;
            }

            if(func_8038F5D4(this, local->unkC, 30.0f, 12.0f, 0x3C)){
                func_8038F41C(this);
            }
            break;

        case 8: //L8038FCB0
            if(player_getTransformation() != TRANSFORM_4_WALRUS){
                func_8038F41C(this);
                break;
            }

            if(func_80329530(this, 500) && !this->unk138_24){
                if(func_80311480(0xc1c, 0xAA, this->position, this->marker, func_8038F330, func_8038F3C4)){
                    timed_setCameraToNode(0.0f, 0x2E);
                    this->unk138_24 = TRUE;
                }
                break;
            }//L8038FD40

            if(mapSpecificFlags_get(8)){
                if(func_8038F6C4(this, D_803925AC, 9.0f)){
                    func_80328B8C(this, 9, 0.02f, 1);
                    actor_playAnimationOnce(this);
                }
                break;
            }

            func_8038F598(this, 2.0f);

            if(!func_803114B0()){
                if( actor_animationIsAt(this, 0.02f)
                    || actor_animationIsAt(this, 0.14f)
                    || actor_animationIsAt(this, 0.28f)
                    || actor_animationIsAt(this, 0.42f)
                ){
                    FUNC_8030E8B4(SFX_88_WOZZA_NOISE, 1000, 0x3ff, this->position, 500, 2000);
                }
            }
            break;

        case 9: //L8038FE14
            func_8038F6C4(this, D_803925AC, 9.0f);
            if(0.97 < func_802877D8(this->animctrl)){
                func_80328B8C(this, 10, 0.02f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 10: //L8038FE70
            func_8038F598(this, 9.0f);
            break;

        case 11: //L8038FE84
            if(func_8038F5D4(this, local->unk24, 30.0f, 12.0f, 0x3C)){
                func_80328A84(this, 12);
            }
            break;

        case 12: //L8038FEB8
            if(func_8038F5D4(this, local->unk18, 30.0f, 12.0f, 0x3C)){
                this->unk38_31 = TRUE;
            }
            break;
    }//L8038FEEC
}
