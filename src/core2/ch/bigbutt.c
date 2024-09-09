#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802C6240(Actor *);
Actor *func_802C6E84(ActorMarker *, Gfx **, Mtx **, Vtx **);
/*.data */
ActorAnimationInfo D_80366010[] ={
    {0x00, 0.0f},
    {ASSET_33_ANIM_BIGBUTT_EAT,     5.5f},
    {ASSET_36_ANIM_BIGBUTT_WALK,    0.7f},
    {ASSET_10_ANIM_BIGBUTT_RUN,     0.8f},
    {ASSET_21_ANIM_BIGBUTT_SLIDE,   0.9f},
    {ASSET_32_ANIM_BIGBUTT_ATTACK,  1.1f},
    {ASSET_35_ANIM_BIGBUTT_ALERT,   0.6f},
    {ASSET_34_ANIM_BIGBUTT_DIE,     4.0f},
    {ASSET_36_ANIM_BIGBUTT_WALK,    1.3f},
    {ASSET_10_ANIM_BIGBUTT_RUN,     0.6f},
    {ASSET_33_ANIM_BIGBUTT_EAT,     5.5f},
    {ASSET_36_ANIM_BIGBUTT_WALK,    1.3f},
    {ASSET_253_ANIM_BIGBUTT_OW,     0.7f},
    {ASSET_254_ANIM_BIGBUTT_FALL,   1.1f},
    {ASSET_254_ANIM_BIGBUTT_FALL, 1000000000.0f},
    {ASSET_255_ANIM_BIGBUTT_GET_UP, 1.0f},
};


ActorInfo D_80366090 = {0x3, ACTOR_4_BIGBUTT, ASSET_353_MODEL_BIGBUTT, 
    1, D_80366010, 
    func_802C6240, func_80326224, func_802C6E84,
    3200, 0, 0.0f, 0
}; 

ActorInfo D_803660B4 = {0x9, ACTOR_E_BULL_INTRO, ASSET_354_MODEL_BULL_INTRO, 
    1, D_80366010, 
    func_802C6240, func_80326224, func_802C6E84,
    3200, 0, 0.0f, 0
}; 

/* .code */
void func_802C5E80(Actor *this){
    this->unk28 = randf2(3.5f, 4.9f);
}

void func_802C5EB8(Actor *this){
    if(volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE))
        return;

    if(this->unk38_31){
        this->unk38_31--; 
    }
    else{
        if(func_80329530(this, 1200) && func_803292E0(this)){
            subaddie_set_state(this, 8);
        }
    }
}

void func_802C5F44(Actor *this){
    if(!func_80329530(this, 1200) || !func_803292E0(this)){
        subaddie_set_state_with_direction(this, 1, 0.16f, 1);
    }
}

void func_802C5F94(Actor *this){
    subaddie_set_state(this, 2);
    func_802C5E80(this);
    func_80328CEC(this, (s32)this->yaw_ideal, 135, 175);
    this->unk38_31 = 150;
}

void func_802C5FF8(Actor *this){
    if( !this->unk138_28
        && actor_animationIsAt(this, 0.4f)
        && randf() < 0.14
        && player_getWaterState() != BSWATERGROUP_2_UNDERWATER
    ){
        func_8030E878(SFX_2B_BULL_MOO_1, randf2(0.9f, 1.1f), 32000, this->position, 0.0f, 2000.0f);
    }
}

void func_802C60AC(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    if( actor->state == 4 
        && 5.0 <= actor->unk28 
        && func_803294F0(actor, 80, func_80329784(actor))
    ){
        animctrl_setPlaybackType(actor->animctrl, ANIMCTRL_ONCE);
        subaddie_set_state(actor, 5);
        func_8030E58C(SFX_1E_HITTING_AN_ENEMY_2, 1.0f);
    }
}

void func_802C6150(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    subaddie_set_state_forward(actor, 0xC);
    func_8030E878(SFX_2B_BULL_MOO_1, randf2(1.28f, 1.37f), 32000, actor->position, 0.0f, 2000.0f);
}

void func_802C61C0(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    if( actor->state != 0xd
        && actor->state != 0xe
        && actor->state != 0xf
    ){
        subaddie_set_state_forward(actor, 0xd);
        FUNC_8030E8B4(SFX_143_BULL_DAMAGE, 1.0f, 16000, actor->position, 0, 2000);
        FUNC_8030E8B4(SFX_143_BULL_DAMAGE, 1.0f, 16000, actor->position, 0, 2000);
    }
}

//chBigbuttUpdate
void func_802C6240(Actor *this){
    s32 sp2C;
    u8  tmp_a0;
    f32 tmp_f0;


    if(!this->initialized){
        this->marker->dieFunc = func_802C61C0;
        this->marker->collisionFunc = func_802C60AC;
        this->marker->collision2Func = func_802C6150;
        this->unk138_24 = 0;
        this->unk16C_0 = 1;
        this->initialized = TRUE;
        return;
    }//L802C62BC
    switch(this->state){
        case 0x1: //L802C62E4
            this->unk10_12 = 3;
            sp2C = func_8032863C(this->animctrl, 0.16f, 0.55f);
            if(!this->unk138_28){
                if( actor_animationIsAt(this, 0.157f)
                    || actor_animationIsAt(this, 0.289f)
                    || actor_animationIsAt(this, 0.4f)
                    || actor_animationIsAt(this, 0.536f)
                ){
                    if(player_getWaterState() != BSWATERGROUP_2_UNDERWATER){
                        func_8030E878(SFX_C8_CRUNCH,randf2(0.93f, 1.07f),10000, this->position, 0.0f, 1800.0f);
                    }
                }   
            }//L802C63C4
            if(sp2C == 2){
                func_80328A2C(this, 0.55f, 1, 0.35f);
            }
            func_802C5FF8(this);
            if( func_8032863C(this->animctrl, 0.65f, 0.99f) >= 2 
                && !func_80328A2C(this, 0.0f, -1, 0.45f)
                && subaddie_maybe_set_state_position_direction(this, 2, 0.0f, -1, 0.58f)
            ){
                func_80328CEC(this, (s32)this->yaw, 10, 45);
                func_802C5E80(this);
            }//L802C647C
            func_802C5EB8(this);
            break;

        case 0x2: //L802C6494
            func_802C5FF8(this);
            func_80328FB0(this, 2.0f);
            if(!func_80329030(this, 0) && func_80329480(this)){
                func_80328CEC(this, (s32)this->yaw, 90, 150);
            }//L802C64EC
            if(!(globalTimer_getTime() & 0xf))
                func_80328CEC(this, (s32)this->yaw_ideal, 10, 20);
            
            if(!(globalTimer_getTime() & 0x7))
                subaddie_maybe_set_state_position_direction(this, 1, 0.16f, 1, 0.02f);
            
            if( !(globalTimer_getTime() & 0xf)
                && func_80329078(this, (s32)this->yaw_ideal, 150)
                && subaddie_maybe_set_state(this, 3, 0.13f)
            ){
                this->unk28 = randf2(7.1f, 8.4f);
            }
            func_802C5EB8(this);
            break;

        case 0x8: //L802C65D0
            func_802C5F44(this);
            this->yaw_ideal = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if(func_80329480(this))
                subaddie_set_state(this, 6);
            break;

        case 0x3: //L802C6620
            func_80328FB0(this, 3.0f);
            if(! func_80329030(this, 0) && func_80329480(this)){
                func_80328CEC(this, (s32)this->yaw, 120, 180);
                subaddie_set_state(this, 2);
                func_802C5E80(this);
            }
            if(!(globalTimer_getTime() & 0xf) && subaddie_maybe_set_state(this, 2, 0.08f))
                func_802C5E80(this);
            func_802C5EB8(this);
            break;

        case 0x6: //L802C66D0
            animctrl_setDuration(this->animctrl, D_80366010[6].duration - (3 - this->unk10_12)*0.1085);
            this->yaw_ideal = (f32)func_80329784(this);
            if(!func_803294B4(this, 0x21)){
                subaddie_set_state(this, 8);
            }
            func_802C5F44(this);
            if(actor_animationIsAt(this, 0.35f) && player_getWaterState() != BSWATERGROUP_2_UNDERWATER){
                func_8030E58C(SFX_3C_BULL_GROWN, randf()/10.0f + 1.0);
                this->unk10_12--;
            }
            if(!func_80329078(this, (s32)this->yaw, 20))
                func_802C5F94(this);

            if(this->unk10_12 == 0 || (this->unk10_12 < 3 && func_80329530(this, 300))){
                subaddie_set_state(this, 9);
                this->unk28 = 13.0f;
            }
            break;

        case 0x9: //L802C6878
            if(actor_animationIsAt(this, 0.35f))
                func_8030E58C(SFX_2E_BIGBUTT_RUNNING, 1.0f);
            
            this->unk28 += 0.15;
            if(30.0f < this->unk28)
                this->unk28 = 30.0f;

            this->yaw_ideal = (f32)func_80329784(this);
            func_80328FB0(this, 9.0f);
            if(!func_80329030(this, 0))
                func_802C5F94(this);

            if(func_80329530(this, 320)){
                if(func_80329078(this, (s32)this->yaw_ideal,200)){
                    animctrl_setPlaybackType(this->animctrl, ANIMCTRL_ONCE);
                    subaddie_set_state(this, 4);
                    this->unk28  += 5.7;
                    tmp_a0 = this->unk44_31;
                    if(this->unk44_31 == 0){
                        this->unk44_31 = func_8030D90C();
                        tmp_a0 = this->unk44_31;
                    }
                    sfxsource_setSfxId(tmp_a0, SFX_18_BIGBUTT_SLIDE);
                    func_8030DD14(this->unk44_31, 2);
                    func_8030DBB4(this->unk44_31, (randf()*0.1 - 0.05) + 1.0);
                    func_8030E2C4(this->unk44_31);
                }
                else{//L802C69FC
                    func_802C5F94(this);
                }
            }//L802C6A08
            break;

        case 0x4: //L802C6A14
            if(animctrl_getAnimTimer(this->animctrl) < 0.99){
                this->yaw_ideal = (f32)func_80329784(this);
                func_80328FB0(this, 1.0f);
            }
            func_80329030(this, 0);
            func_8030E2C4(this->unk44_31);
            if(0.99 <= animctrl_getAnimTimer(this->animctrl)){
                func_80329878(this, func_80329530(this, 250)? 0.8: 1.2);
                if(0.0f == this->unk28){
                    animctrl_setPlaybackType(this->animctrl, ANIMCTRL_LOOP);
                    subaddie_set_state_with_direction(this, 1, 0.65f, 1);
                    func_8030DA44(this->unk44_31);
                    this->unk44_31 = 0;
                    func_8030E484(SFX_19_BANJO_LANDING_08);
                }
            }//L802C6B1C
            break;

        case 0x5: //L802C6B28
            actor_playAnimationOnce(this);
            tmp_f0 = animctrl_getAnimTimer(this->animctrl);
            animctrl_setDuration(this->animctrl, D_80366010[5].duration + ((0.65 < tmp_f0)? (tmp_f0 - 0.65)*16.0 : 0.0));
            if(actor_animationIsAt(this, 0.95f)){
                actor_loopAnimation(this);
                func_802C5F94(this);
            }
            break;

        case 0xc: //L802C6BDC
            actor_playAnimationOnce(this);
            if(actor_animationIsAt(this, 0.95f)){
                subaddie_set_state_with_direction(this, 1, 0.65f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 0xd: //L802C6C28
            actor_playAnimationOnce(this);
            if(actor_animationIsAt(this, 0.95f)){
                subaddie_set_state_with_direction(this, 0xe, 0.99f, 1);
                this->unk60 = 4.0f;
            }
            break;

        case 0xe: //L802C6C7C
            actor_playAnimationOnce(this);
            this->unk60 -= time_getDelta();
            if(this->unk60 <= 0.0f){
                this->unk166 = 0x63;
                subaddie_set_state_forward(this, 0xF);
            }

            break;

        case 0xf: //L802C6CD4
            actor_playAnimationOnce(this);
            if(actor_animationIsAt(this, 0.95f)){
                subaddie_set_state_with_direction(this, 1, 0.65f, 1);
                actor_loopAnimation(this);
            }
            break;
   }//L802C6D1C
   if(this->state == 0xe){
        if(this->marker->id != 0x29e)
            this->marker->id = 0x29e;
   }else{//L802C6D60
        if(this->marker->id != 3)
            this->marker->id = 3;
   }
}

void func_802C6DA0(s32 arg0, f32 arg1[3], f32 arg2[3]){
    func_8034A174(func_80329934(), arg0, arg2);
    arg2[0] = (arg2[0] - arg1[0])*0.2;
    arg2[1] = (arg2[1] - arg1[1])*0.2;
    arg2[2] = (arg2[2] - arg1[2])*0.2;

}

void func_802C6E3C(s32 arg0, f32 arg1[3]){
    f32 sp1C[3];
    func_8034A174(func_80329934(), arg0, sp1C);
    func_80352CF4(sp1C, arg1, 170.0f, 50.0f);
}

Actor *func_802C6E84(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor; //sp4C
    f32 sp40[3];
    
    
    actor = actor_draw(marker, gfx, mtx, vtx);
    if(marker->unk14_21){
        f32 sp34[3] = {0.0f, 4.0f, -15.0f};
        f32 sp28[3];
        f32 sp1C[3];

        ml_vec3f_yaw_rotate_copy(sp34, sp34, actor->yaw);
        switch(actor->state){
            case 6:
                if(actor_animationIsAt(actor, 0.65f)){
                    func_8034A174(func_80329934(), 9, sp40);
                    func_80352CF4(sp40, sp34, 60.0f, 50.0f);
                }
                break;
            case 4://L802C6F50
                if((globalTimer_getTime() & 1) == 1){
                    if(func_80259808(actor->yaw)){
                        func_802C6E3C(0xb, sp34);
                        func_802C6E3C(0xa, sp34);
                    }
                    else{
                        func_802C6E3C(0x8, sp34);
                        func_802C6E3C(0x9, sp34);
                    }
                }
                break;
            case 1://L802C6FB4
                if(actor_animationIsAt(actor, 0.85f)
                    && (globalTimer_getTime()& 0xe) == 8
                    && randf() < 0.6
                ){
                    func_8034A174(func_80329934(),5, sp40);
                    func_802C6DA0(6, sp40, sp28);
                    func_802C6DA0(7, sp40, sp1C);
                    func_80352CF4(sp40, sp28, 200.0f, 50.0f);
                    func_80352CF4(sp40, sp1C, 200.0f, 50.0f);

                }
                break;
        }
    }//L802C7064
    return actor;
}
