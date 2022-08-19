#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80328B8C(Actor *, s32, f32 , s32);
extern f32 func_80309B24(f32*);
extern void func_80329904(ActorMarker*, s32, f32*);
extern void func_80326310(Actor *);
extern void func_8032BB88(Actor *, s32, s32);

void func_802CDD78(Actor *this);

/* .data */
extern ActorAnimationInfo D_803671B0[];
extern ActorInfo D_80367200 = { 0x5A, 0x60, 0x3C0, 0x1, D_803671B0, func_802CDD78, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367224 = { 0x5B, 0x62, 0x3C2, 0x1, D_803671B0, func_802CDD78, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367248 = { 0x5E, 0x5E, 0x3BB, 0x1, D_803671B0, func_802CDD78, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_8036726C = { 0x5D, 0x61, 0x3C1, 0x1, D_803671B0, func_802CDD78, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80367290 = { 0x5C, 0x5F, 0x3BC, 0x1, D_803671B0, func_802CDD78, func_80326224, func_80325888, 0, 0, 0.0f, 0};

/*.rodata */
//jumptable D_80376560
extern f64 D_80376578; //45.0
extern f64 D_80376580; //182.04444
extern f64 D_803765A8; //0.015
extern f64 D_803765B0; //0.8
extern f64 D_803765B8; //0.3
extern f64 D_803765C0; //0.2
extern f64 D_803765C8; //0.9
//0.1
//.rodata end 803765d0

s32 func_802CDB50(s32 arg0){
    switch(arg0){
        case 0x5A:
            return 0xD98;
        case 0x5B:
            return 0xD99;
        case 0x5C:
            return 0xD9b;
        case 0x5d:
            return 0xD9a;
        case 0x5e:
            return 0xD97;
    }
    return 0;
}

void func_802CDBA8(ActorMarker *this, s32 arg1){
    Actor *actorPtr = marker_getActor(this);
    ActorLocal_Jinjo *localPtr = &actorPtr->jinjo;

    if(actorPtr->state < 5){
        if(!func_8031FF1C(BKPROG_E_JINJO_TEXT)){
            func_80311480(func_802CDB50(actorPtr->marker->unk14_20), 4, 0, 0, 0, 0);
            func_80320004(BKPROG_E_JINJO_TEXT, 1);
        }
        func_80328B8C(actorPtr, 6, 0.0f , -1);
        if(func_803463D4(ITEM_12_JINJOS, 1 << (this->unk14_20 + 6) ) == 0x1f)
            localPtr->unk4 = 1;
        actor_loopAnimation(actorPtr);
        this->collidable = 0;
    }
}

void func_802CDC9C(Actor *this, s16 arg1){
    f32 tmpf; 

    tmpf = this->yaw;
    tmpf -= time_getDelta()*arg1/45.0;
    
    if(tmpf >= 360.0f)
        tmpf -= 360.0f;
    else if (tmpf < 0.0f)
        tmpf += 360.0f;

    this->yaw = tmpf;
}


void func_802CDD3C(Actor * this){
    ActorLocal_Jinjo *localPtr = &this->jinjo;
    if(localPtr->unkC != 0){
        func_802F9D38(localPtr->unkC);
        localPtr->unkC = 0;
    }
}

#ifdef NONMATCHING
void func_802CDD78(Actor * this){
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
    int sp50;
    //f32 sp4C; //unused
    f32 sp40[3];
    //s32 sp3C;
    //s32 sp38;
    f32 *sp30;
    f32 tmp_f0;
    s32 i;
    
    local = &this->jinjo;
    if(!this->initialized){
        this->initialized = 1;
        local->unk0 = 1;
        local->unk4 = 0;
        local->unk8 = (this->position_y < func_80309B24(this->position));
        this->marker->unkC = func_802CDBA8;
        func_803300D8(this->marker, func_802CDD3C);
        if(func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)){
            marker_despawn(this->marker);
        }
    }//L802CDE24
    sp30 = this->position;
    func_8028E964(sp7C);
    func_80257F18(sp30, sp7C, &sp6C);
    sp64 = (this->yaw * 182.04444);
    sp66 = sp64 - (s32)(sp6C*182.04444);
    sp60 = func_8028AED4(sp30, 55.0f);

    switch(this->state){
        case 1:
            if(randf() < 0.015){
                if(sp60){
                    func_80328B8C(this, 3, 0.0f, -1);
                }else{
                    func_80328B8C(this, 2, 0.0f, -1);
                }
                actor_playAnimationOnce(this);
            }//L802CDF24
            break;

        case 2: /* 46FA0 802CDF30 3C053F7D */
        case 3:
            if(actor_animationIsAt(this, 0.99f)){
                func_80328B8C(this, 1, 0.0f, -1);
            }
            break;
        
        case 4: /* 46FD8 802CDF68 3C053F7D */
            if(actor_animationIsAt(this, 0.99f)){
                func_80328B8C(this, 1, 0.0f, -1);
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
            func_802CDC9C(this, sp66);
            if(actor_animationIsAt(this, 0.0f) && --(local->unk0) == 0){
                func_80328B8C(this, 7, 0.0f, -1);
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
            if(!sp50 || 0.8 < animctrl_getAnimTimer(this->animctrl)){//L802CE158
                player_getVelocity(sp70);
                sp70[0] *= sp58*6.0f;
                sp70[1] *= sp58*6.0f;
                sp70[2] *= sp58*6.0f;
                sp70[0] += sp7C[0];
                sp70[1] += sp7C[1];
                sp70[2] += sp7C[2];
                sp70[0] -=  this->position_x;
                sp70[1] -=  this->position_y;
                sp70[2] -=  this->position_z;
                sp70[0] *= sp58*3.0f;
                sp70[1] *= sp58*3.0f;
                sp70[2] *= sp58*3.0f;
                this->position_x += sp70[0];
                this->position_y += sp70[1];
                this->position_z += sp70[2];
                if(sp50 || animctrl_getAnimTimer(this->animctrl) < 0.3){
                    for(i = 0; i < 4; i++){
                        if(randf() < 0.2){
                            func_8033E73C(this->marker, i + 5, func_80329904);
                            func_8033E3F0(8, this->marker->unk14_21);
                        } //L802CE2C4
                    }
                }//L802CE2D0
            }

            if(sp50){ 
                if(animctrl_getAnimTimer(this->animctrl) < 0.9)
                    func_802CDC9C(this, sp66);

                if(actor_animationIsAt(this, 0.1f)){
                    local->unkC = func_802F9AA8(SFX_18_BIGBUTT_SLIDE);
                    func_802F9EC4(local->unkC, sp30, 500, 2000);
                    func_802F9F80(local->unkC, 0.0f, 0x50061c46, 0.0f);
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
                    if(local->unk4){
                        func_802F9D38();
                        local->unk4 = 0;
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
                    func_80328B8C(this, 8, 0.0f, -1);
                    actor_playAnimationOnce(this);
                }
            }
            break;
    }//L802CE5F0
    if(this->state < 4 &&  !(((sp66 >= 0)? sp66: -sp66) <= 0x100)){
        func_80328B8C(this, 4, 0.0f, -1);
        actor_playAnimationOnce(this);
    }//L802CE630
    if(!func_803114B0()){
        switch(D_803671B0[this->state].index){
            case 0x31: 
                if(actor_animationIsAt(this, 0.6f)){
                    if(local->unk8){
                        func_8030E988(SFX_8_BANJO_LANDING_04, 1.8f, 18000, sp30, 120.0f, 1200.0f);
                    }else{
                        FUNC_8030E8B4(SFX_8_BANJO_LANDING_04, 1.8f, 18000, sp30, 120, 1200);
                    }
                }
                break;
            case 0x2D: //L802CE6F4
                if(actor_animationIsAt(this, 0.2f)){
                    if(local->unk8){
                        func_8030E988(SFX_17_JINJO_WHISTLE, 1.0f, 22000, sp30, 120.0f, 1200.0f);
                    }else{
                        FUNC_8030E8B4(SFX_27_JINJO_HI, 1.0f, 22000, sp30, 120, 1200);
                    }
                }
                break;
            case 0x2F: //L802CE760
                if(actor_animationIsAt(this, 0.2f)){
                    if(local->unk8){
                        func_8030E988(SFX_27_JINJO_HI, 1.0f, 22000, sp30, 120.0f, 1200.0f);
                    }else{
                        FUNC_8030E8B4(SFX_17_JINJO_WHISTLE, 1.0f, 22000, sp30, 120, 1200);
                    }
                }
                break;
            default: //L802CE7C8
                break;
        }
    }//L802CE7CC
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/jinjo/func_802CDD78.s")
#endif