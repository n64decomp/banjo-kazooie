#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorProp *func_80320EB0(ActorMarker *, f32, s32);

Actor *func_8038DD70(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038E094(Actor *this);

/* .data */
extern ActorAnimationInfo D_80392390[] ={
    {0, 0.0f},
    {ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR, 10000000.0f},
    {ASSET_1B0_ANIM_TWINKLY_MUNCHER_DIE,    1.0f},
    {ASSET_1B1_ANIM_TWINKLY_MUNCHER_IDLE,   1.0f},
    {ASSET_1B2_ANIM_TWINKLY_MUNCHER_ATTACK, 1.0f},
    {ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR, 0.667f},
    {ASSET_1B1_ANIM_TWINKLY_MUNCHER_IDLE,   1.0f},
    {ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR, 0.667f}
};

extern ActorInfo D_803923D0 = { MARKER_205_TWINKLY_MUNCHER, ACTOR_337_TWINKLY_MUNCHER, ASSET_496_MODEL_TWINKLY_MUNCHER, 
    0x1, D_80392390,
    func_8038E094, func_80326224, func_8038DD70,
    2500, 0, 1.0f, 0
};

/* .code */
Actor *func_8038DD70(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->state == 1)
        return this;
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_8038DDC8(Actor *this){
    actor_collisionOn(this);
    func_80328B8C(this, 2, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void func_8038DE08(Actor *this){
    func_80328B8C(this, 3, 0.03f, 1);
    actor_loopAnimation(this);
}

void func_8038DE40(Actor *this){
    func_80328B8C(this, 4, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void func_8038DE78(Actor *this){
    actor_collisionOff(this);
    func_80328B8C(this, 5, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void func_8038DEB8(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    if(this->state != 1 && this->state != 5){
        func_8038DE78(this);
        FUNC_8030E8B4(SFX_87_TANKTUP_OOOHW, 1.6f, 32000, this->position, 1250, 2500);
        FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 26000, this->position, 1250, 2500);
    }
}

Actor *func_8038DF34(Actor *this){
    ActorProp *prop;
    Actor *other;
    s32 marker_id;
    f32 sp18[3];

    func_8034A174(this->marker->unk44, 5, sp18);
    this->marker->unk38[0] = sp18[0] - this->position[0];
    this->marker->unk38[1] = sp18[1] - this->position[1];
    this->marker->unk38[2] = sp18[2] - this->position[2];
    prop = func_80320EB0(this->marker, 75.0f, 1);

    if(prop && prop->unk8_0){
        other = marker_getActor(prop->marker);
        marker_id = other->marker->unk14_20;
        if( marker_id == MARKER_200_TWINKLY_BLUE
            || marker_id == MARKER_201_TWINKLY_GREEN 
            || marker_id == MARKER_202_TWINKLY_ORANGE
            || marker_id == MARKER_203_TWINKLY_RED
        ){
            return other;
        }
    }
    return NULL;
}

void func_8038E040(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    func_80324E88(0.5f);
    func_80328B8C(this, 7, 0.03f, 1);
    actor_playAnimationOnce(this);
}

void func_8038E094(Actor *this){
    s32 sp3C;
    Actor *sp38;
    f32 sp34 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_8038DEB8, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        animctrl_setAnimTimer(this->animctrl, 0.99999f);
        this->unk60 = 0.0f;
        if(this->unkF4_8 == 1){
            func_8038DDC8(this);
        }
        if(this->unkF4_8 == 2){
            if(func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) && gcparade_8031B4F4() == -2){
                func_8038DDC8(this);
            }
            else{
                marker_despawn(this->marker);
                return;
            }
        }
    }//L8038E180
    if(this->unk100){
        sp38 = marker_getActor(this->unk100);
        if(sp38->unk1C[1] == 1.0f){
            if(this->unkF4_8 == 1 && !func_8031FF1C(BKPROG_13)){
                if(this->state != 6 && this->state != 7 && 0.0f == this->velocity[0]){
                    timed_setCameraToNode(0.5f, 0xd);
                    func_80311480(ASSET_C15_TEXT_TWINKLIE_MINIGAME_LOST, 0x2b, this->position, this->marker, func_8038E040, NULL);
                    this->velocity[0] = 1.0f;
                    func_80328B8C(this, 6, 0.03f, 1);
                    actor_loopAnimation(this);
                }
            }
            else{//L8038E274
                if(this->state == 1){
                    marker_despawn(this->marker);
                }
                else if( this->state != 1 && this->state != 5){
                    func_8038DE78(this);
                }
            }
        }
    }//L8038E2B4

    switch(this->state){
        case 1: //L8038E2DC
            this->marker->propPtr->unk8_3 = FALSE;
            animctrl_setAnimTimer(this->animctrl, 0.99f);
            if(this->unk60 < 5.0){
                this->unk60 += sp34;
            }
            else{
                if(10.0 <= this->unk60 || randf() < this->unk60/10.0){
                    if(!func_8038DF34(this)){
                        this->unk60 = 0.0f;
                        func_8038DDC8(this);
                        break;
                    }
                }
                this->unk60 += sp34;
            }
            break;

        case 2: //L8038E3C0
            this->marker->propPtr->unk8_3 = TRUE;
            sp38 = func_8038DF34(this);
            if(sp38){
                func_8038DE40(this);
                this->unk38_31 = sp38->marker->unk14_20;
                break;
            }
            
            if(actor_animationIsAt(this, 0.15f))
                FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 1250, 2500);

            if(actor_animationIsAt(this, 0.35f))
                FUNC_8030E8B4(SFX_C4_TWINKLY_MUNCHER_GRR, 1.2f, 32000, this->position, 1250, 2500);

            if(actor_animationIsAt(this, 0.97f))
                func_8038DE08(this);
            break;

        case 3: //L8038E498
            this->marker->propPtr->unk8_3 = TRUE;
            sp38 = func_8038DF34(this);
            if(sp38){
                func_8038DE40(this);
                this->unk38_31 = sp38->marker->unk14_20;
            }
            break;

        case 4: //L8038E4F0
            this->marker->propPtr->unk8_3 = TRUE;
            sp38 = func_8038DF34(this);
            if(sp38 && sp38->marker->unk14_20 == this->unk38_31){
                if(actor_animationIsAt(this, 0.23)){
                    func_8038C398(sp38->position, sp38->marker->unk14_20);
                    FUNC_8030E8B4(SFX_110_TWINKLY_DEATH, 1.0f, 32000, this->position, 1250, 2500);
                    FUNC_8030E8B4(SFX_27_JINJO_HI, 1.6f, 32000, this->position, 1250, 2500);
                    func_80324D54(0.35f, SFX_110_TWINKLY_DEATH, 1.0f, 32000, this->position, 1250.0f, 2500.0f);
                    marker_despawn(sp38->marker);
                    if( !mapSpecificFlags_get(0xa) && func_80311480(0xc16, 0, NULL, NULL, NULL, NULL)){
                        mapSpecificFlags_set(0xa, TRUE);
                    }
                }
            }//L8038E620
            if(actor_animationIsAt(this, 0.97f)){
                func_8038DE08(this);
            }
            break;

        case 5: //L8038E644
            this->marker->propPtr->unk8_3 = TRUE;
            if(actor_animationIsAt(this, 0.97f)){
                func_80328B8C(this, 1, 0.97f, 0);
                actor_playAnimationOnce(this);
                this->unk60 = 0.0f;
            }
            break;

        case 6: //L8038E698
            this->marker->propPtr->unk8_3 = FALSE;
            this->yaw_ideal = (f32)func_80329784(this);
            func_80328FB0(this, 12.0f);
            break;

        case 7: //L8038E6D4
            this->marker->propPtr->unk8_3 = FALSE;
            if(actor_animationIsAt(this, 0.97f)){
                marker_despawn(this->marker);
            }
            break;
    }
}
