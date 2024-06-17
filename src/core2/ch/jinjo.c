#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void subaddie_set_state_with_direction(Actor *, s32, f32 , s32);
extern f32 func_80309B24(f32*);
extern void func_80329904(ActorMarker*, s32, f32*);
extern void func_80326310(Actor *);
extern void func_8032BB88(Actor *, s32, s32);

void chJinjo_update(Actor *this);

/* .data */
ActorAnimationInfo chJinjoAnimations[] = {
    {0, 0.0f},
    {ASSET_2D_ANIM_JINJO_IDLE, 1000000.0f},
    {ASSET_2D_ANIM_JINJO_IDLE, 1.5f},
    {ASSET_2F_ANIM_JINJO_HELP, 1.5f},
    {ASSET_31_ANIM_JINJO_JUMP, 0.75f},
    {ASSET_2D_ANIM_JINJO_IDLE, 1000000.0f},
    {ASSET_31_ANIM_JINJO_JUMP, 0.4f},
    {ASSET_130_ANIM_JINJO_FLY_START, 1.75f},
    {ASSET_131_ANIM_JINJO_FLY_END, 2.13333f},
    {ASSET_31_ANIM_JINJO_JUMP, 0.75f}
};

ActorInfo chJinjoBlue   = { MARKER_5A_JINJO_BLUE,   ACTOR_60_JINJO_BLUE,   ASSET_3C0_MODEL_JINJO_BLUE,   0x1, chJinjoAnimations, chJinjo_update, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoGreen  = { MARKER_5B_JINJO_GREEN,  ACTOR_62_JINJO_GREEN,  ASSET_3C2_MODEL_JINJO_GREEN,  0x1, chJinjoAnimations, chJinjo_update, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoYellow = { MARKER_5E_JINJO_YELLOW, ACTOR_5E_JINJO_YELLOW, ASSET_3BB_MODEL_JINJO_YELLOW, 0x1, chJinjoAnimations, chJinjo_update, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoPink   = { MARKER_5D_JINJO_PINK,   ACTOR_61_JINJO_PINK,   ASSET_3C1_MODEL_JINJO_PINK,   0x1, chJinjoAnimations, chJinjo_update, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo chJinjoOrange = { MARKER_5C_JINJO_ORANGE, ACTOR_5F_JINJO_ORANGE, ASSET_3BC_MODEL_JINJO_ORANGE, 0x1, chJinjoAnimations, chJinjo_update, func_80326224, actor_draw, 0, 0, 0.0f, 0};

enum asset_e __chJinjo_getMeetDialogId(enum marker_e marker_id){
    switch(marker_id){
        case MARKER_5A_JINJO_BLUE:   return ASSET_D98_DIALOG_JINJO_MEET_BLUE;
        case MARKER_5B_JINJO_GREEN:  return ASSET_D99_DIALOG_JINJO_MEET_GREEN;
        case MARKER_5C_JINJO_ORANGE: return ASSET_D9B_DIALOG_JINJO_MEET_ORANGE;
        case MARKER_5D_JINJO_PINK:   return ASSET_D9A_DIALOG_JINJO_MEET_PINK;
        case MARKER_5E_JINJO_YELLOW: return ASSET_D97_DIALOG_JINJO_MEET_YELLOW;
    }
    return 0;
}

void __chJinjo_802CDBA8(ActorMarker *this, ActorMarker *other){
    Actor *actorPtr = marker_getActor(this);
    ActorLocal_Jinjo *localPtr = &actorPtr->jinjo;

    if(actorPtr->state < 5){
        if(!fileProgressFlag_get(FILEPROG_E_JINJO_TEXT)){
            func_80311480(__chJinjo_getMeetDialogId(actorPtr->marker->unk14_20), 4, 0, 0, 0, 0);
            fileProgressFlag_set(FILEPROG_E_JINJO_TEXT, 1);
        }
        subaddie_set_state_with_direction(actorPtr, 6, 0.0f , -1);
        if(func_803463D4(ITEM_12_JINJOS, 1 << (this->unk14_20 + 6) ) == 0x1f)
            localPtr->unk4 = 1;
        actor_loopAnimation(actorPtr);
        this->collidable = 0;
    }
}

void __chJinjo_802CDC9C(Actor *this, s16 arg1){
    f32 tmpf; 

    tmpf = this->yaw;
    tmpf -= time_getDelta()*arg1/45.0;
    
    if(tmpf >= 360.0f)
        tmpf -= 360.0f;
    else if (tmpf < 0.0f)
        tmpf += 360.0f;

    this->yaw = tmpf;
}

void __chJinjo_802CDD3C(Actor * this){
    ActorLocal_Jinjo *localPtr = &this->jinjo;
    if(localPtr->unkC != 0){
        func_802F9D38(localPtr->unkC);
        localPtr->unkC = 0;
    }
}

void chJinjo_update(Actor * this){
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp6C;
    f32 sp68; //unused??
    s16 sp66;
    s16 sp64;
    s32 sp60;
    // f32 sp5C;
    ActorLocal_Jinjo *local; //= &this->jinjo; //sp34
    f32 sp58 = time_getDelta();
    s32 i;
    int sp50;
    f32 *sp30;
    
    //f32 sp4C; //unused
    f32 sp40[3];
    //s32 sp3C;
    //s32 sp38;
    
    f32 tmp_f0;
    
    
    local = &this->jinjo;
    if(!this->initialized){
        this->initialized = 1;
        local->unk0 = 1;
        local->unk4 = 0;
        local->unk8 = (this->position_y < func_80309B24(this->position));
        this->marker->unkC = __chJinjo_802CDBA8;
        marker_setFreeMethod(this->marker, __chJinjo_802CDD3C);
        if(func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)){
            marker_despawn(this->marker);
        }
    }//L802CDE24
    sp30 = this->position;
    func_8028E964(sp7C);
    func_80257F18(sp30, sp7C, &sp6C);
    sp64 = (this->yaw * 182.04444);
    // sp66 = sp64 - (s32)(sp6C*182.04444);
    sp66 = (s32) (sp6C * 182.04444);
    sp66 = sp64 - sp66;
    sp60 = func_8028AED4(sp30, 55.0f);

    switch(this->state){
        case 1:
            if(randf() < 0.015){
                if(sp60){
                    subaddie_set_state_with_direction(this, 3, 0.0f, -1);
                }else{
                    subaddie_set_state_with_direction(this, 2, 0.0f, -1);
                }
                actor_playAnimationOnce(this);
            }//L802CDF24
            break;

        case 2: /* 46FA0 802CDF30 3C053F7D */
        case 3:
            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, 1, 0.0f, -1);
            }
            break;
        
        case 4: /* 46FD8 802CDF68 3C053F7D */
            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, 1, 0.0f, -1);
            }else{//L802CDF9C
                tmp_f0 = this->yaw;
                if(sp66 >= 0){
                    tmp_f0 -= 80.0f * sp58;
                }
                else{//L802CDFBC
                    tmp_f0 += 80.0f * sp58;
                }//L802CDFD0
                if(tmp_f0 >= 360.0f)
                    tmp_f0 -= 360.0f;
                else if(tmp_f0 < 0.0f)
                    tmp_f0 += 360.0f;

                this->yaw = tmp_f0;
            }//L802CE018
            break;
        case 6:/* 47094 802CE024 02002025 */
            __chJinjo_802CDC9C(this, sp66);
            if(actor_animationIsAt(this, 0.0f) && --(local->unk0) == 0){
                subaddie_set_state_with_direction(this, 7, 0.0f, -1);
                actor_playAnimationOnce(this);
                if(local->unk4){
                    sp40[0] = this->position_x;
                    sp40[1] = this->position_y;
                    sp40[2] = this->position_z;
                    sp40[1] += 50.0f;
                    jiggySpawn(10*level_get()-9, sp40);
                }//L802CE0CC
                func_8024BD08(0);
                func_8032BB88(this, 0, 4000);
                if(local->unk4){
                    func_8025A6EC(COMUSIC_30_5TH_JINJO_COLLECTED, 28000);
                }else{
                    func_8025A6EC(COMUSIC_A_JINJO_COLLECTED, 28000);
                }
            }//L802CE114
            break;

        case 7:
        case 8:
            sp50 = this->state == 7;
            if(!sp50 || 0.1 < animctrl_getAnimTimer(this->animctrl)){//L802CE158
                player_getVelocity(sp70);
                sp70[0] *= sp58*6.0f;\
                sp70[1] *= sp58*6.0f;\
                sp70[2] *= sp58*6.0f;
                sp70[0] = sp70[0] + sp7C[0];\
                sp70[1] = sp70[1] + sp7C[1];\
                sp70[2] = sp70[2] + sp7C[2];
                sp70[0] -=  this->position_x;\
                sp70[1] -=  this->position_y;\
                sp70[2] -=  this->position_z;
                sp70[0] *= sp58*3.0f;
                sp70[1] *= sp58*3.0f;
                sp70[2] *= sp58*3.0f;
                this->position_x = this->position_x + sp70[0];
                this->position_y = this->position_y + sp70[1];
                this->position_z = this->position_z + sp70[2];
                if(sp50 || animctrl_getAnimTimer(this->animctrl) < 0.8){
                    for(i = 0; i < 4; i++){
                        if(randf() < 0.3){
                            func_8033E73C(this->marker, i + 5, func_80329904);
                            func_8033E3F0(8, this->marker->unk14_21);
                        } //L802CE2C4
                    }
                }//L802CE2D0
            }

            if(sp50){ 
                if(animctrl_getAnimTimer(this->animctrl) < 0.2)
                    __chJinjo_802CDC9C(this, sp66);

                if(actor_animationIsAt(this, 0.1f)){
                    local->unkC = func_802F9AA8(SFX_18_BIGBUTT_SLIDE);
                    func_802F9EC4(local->unkC, sp30, 500, 2000);
                    func_802F9F80(local->unkC, 0.0f, 9e+09, 0.0f);
                    func_802FA0B0(local->unkC, 0);
                    func_8025A6EC(COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7FFF);
                    func_8025AABC(COMUSIC_43_ENTER_LEVEL_GLITTER);
                    func_8030E9C4(SFX_C7_SHWOOP, 0.8f, 0x7FFF, sp30, 300.0f, 2000.0f);
                }//L802CE3C4

                if(actor_animationIsAt(this, 0.434f)){
                    func_8030E9C4(SFX_C7_SHWOOP, 0.9f, 0x7fff, sp30, 300.0f, 2000.0f);
                }//L802CE408
                
                if(actor_animationIsAt(this, 0.811f)){
                    func_8030E9C4(SFX_C7_SHWOOP, 1.0f, 0x7fff, sp30, 300.0f, 2000.0f);
                }

            }else{//L802CE450
                if(actor_animationIsAt(this,0.214f)){
                    func_8030E9C4(SFX_C7_SHWOOP, 1.1f, 0x7fff, sp30, 300.0f, 2000.0f);
                }//L802CE490

                if(actor_animationIsAt(this,0.55f)){
                    func_8030E9C4(SFX_53_BANJO_HUIII, 1.5f, 0x7fff, sp30, 300.0f, 2000.0f);
                }//L802CE4D0

                if(actor_animationIsAt(this,0.75f)){ 
                    func_80326310(this);
                    if(local->unk4 == 0){
                        func_8032BB88(this, -1, 4000);
                        func_8024BD08(1);
                    }
                }//L802CE518

                if(actor_animationIsAt(this,0.85f)){ 
                    if(local->unkC){
                        func_802F9D38(local->unkC);
                        local->unkC = 0;
                    }
                    func_8030E4E4(SFX_19_BANJO_LANDING_08);
                    func_8025A7DC(COMUSIC_43_ENTER_LEVEL_GLITTER);
                }//L802CE558

                if(local->unk4 && actor_animationIsAt(this,0.95f)){
                    func_8032BB88(this, -1, 4000);
                    func_8024BD08(1);
                }
            }//L802CE598

            if(sp50){
                if(actor_animationIsAt(this, 0.96f) || actor_animationIsAt(this, 0.99f)){
                    subaddie_set_state_with_direction(this, 8, 0.0f, -1);
                    actor_playAnimationOnce(this);
                }
            }
            break;
    }//L802CE5F0
    if(this->state < 4 &&  !(((sp66 >= 0)? sp66: -sp66) <= 0x1000)){
        subaddie_set_state_with_direction(this, 4, 0.0f, -1);
        actor_playAnimationOnce(this);
    }//L802CE630
    if(!func_803114B0()){
        switch(chJinjoAnimations[this->state].index){
            case ASSET_31_ANIM_JINJO_JUMP: 
                if(actor_animationIsAt(this, 0.6f)){
                    if(local->unk8){
                        func_8030E988(SFX_8_BANJO_LANDING_04, 1.8f, 18000, sp30, 120.0f, 1200.0f);
                    }else{
                        FUNC_8030E8B4(SFX_8_BANJO_LANDING_04, 1.8f, 18000, sp30, 120, 1200);
                    }
                }
                break;
            case ASSET_2D_ANIM_JINJO_IDLE: //L802CE6F4
                if(actor_animationIsAt(this, 0.2f)){
                    if(local->unk8){
                        func_8030E988(SFX_17_JINJO_WHISTLE, 1.0f, 22000, sp30, 120.0f, 1200.0f);
                    }else{
                        FUNC_8030E8B4(SFX_17_JINJO_WHISTLE, 1.0f, 22000, sp30, 120, 1200);
                    }
                }
                break;
            case ASSET_2F_ANIM_JINJO_HELP: //L802CE760
                if(actor_animationIsAt(this, 0.2f)){
                    if(local->unk8){
                        func_8030E988(SFX_27_JINJO_HI, 1.0f, 22000, sp30, 120.0f, 1200.0f);
                    }else{
                        FUNC_8030E8B4(SFX_27_JINJO_HI, 1.0f, 22000, sp30, 120, 1200);
                    }
                }
                break;
            default: //L802CE7C8
                break;
        }
    }//L802CE7CC
}
