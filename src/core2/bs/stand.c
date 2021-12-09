#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

extern f32 func_8029B2E8(void);
void func_80299234(f32, f32);

void func_802875AC(AnimCtrl *, char*, s32);

void func_802900B4(void);
void func_80250D94(f32, f32, f32);

extern u8 D_80364D20[];

//.rodata
extern char D_80375A70[];
extern char D_80375A7C[];
extern char D_80375A88[];

//.bss
extern s32 D_8037D540;
extern u8  D_8037D544;

u32 func_802B4870(u32 arg0){
    if(++arg0 > 0x14)
        arg0 = 0;
    return arg0;
}

s32 func_802B488C(s32 arg0){
    s32 retVal = arg0;
    switch(func_8029B300()){
        case 1: //L802B48CC
            retVal = BS_WALK_CREEP;
            break;
        case 2: //L802B48D4
            retVal = BS_WALK_SLOW;
            break;
        case 3: //L802B48D4
            retVal = BS_WALK;
            break;
        case 4: //L802B48D4
            retVal = BS_WALK_FAST;
            break;
    }
    if(button_held(BUTTON_Z))
        retVal = BS_CROUCH;

    if(button_pressed(BUTTON_B) && can_claw())
        retVal = BS_CLAW;

    if(button_pressed(BUTTON_A))
        retVal = func_8029C780();

    if(func_80294F78())
        retVal = func_802926C0();

    if(player_isSliding())
        retVal = BS_SLIDE;

    retVal = func_8029CA94(retVal);

    if(player_inWater())
        retVal = BS_2D_SWIM_IDLE;
    
    return retVal;
}

void bsstand_init(void){
    if(bsclimb_inSet(bs_getPrevState()))
        climbRelease();

    func_8028A180(0x6F, 5.5f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    func_802900B4();
    D_8037D540 = 0;
    D_8037D544 = 0;
}

void func_802B4A10(AnimCtrl *arg0){
    if(animctrl_isAt(arg0, 0.2057f)){ //(30/145)
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 500, 0x731);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4A54

    if(animctrl_isAt(arg0, 0.2057f)) //(30/145)
        func_80292E48();
    //L802B4A78

    if(animctrl_isAt(arg0, 0.2555f)){ //(37/145)
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 500, 0x731);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4AB0

    if(animctrl_isAt(arg0, 0.2896f)){ //(42/145)
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 500, 0x731);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4AEC

    if(animctrl_isAt(arg0, 0.3f)){ //(43.5/145)?
        FUNC_8030E624(SFX_62_BANJO_ERGHH, 875, 0x3FF);
    }//L802B4B0C

    if(animctrl_isAt(arg0, 0.3607f)){
        func_80292EA4();
    }//L802B4B30

    if(animctrl_isAt(arg0, 0.4183f)){
        func_8030E58C(SFX_3F1_UNKNOWN, 1.6f);
    }//L802B4B50

    if(animctrl_isAt(arg0, 0.455f)){
        func_8030E58C(SFX_3F1_UNKNOWN, 1.45f);
    }//L802B4B74

    if(animctrl_isAt(arg0, 0.49f)){
        func_8030E58C(SFX_3F1_UNKNOWN, 1.4f);
    }//L802B4B98

    if(animctrl_isAt(arg0, 0.5397f)){
        func_802900D8();
    }//L802B4BBC

    if(animctrl_isAt(arg0, 0.6619f)){
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 500, 0x731);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4BF4

    if(animctrl_isAt(arg0, 0.6688f))
        func_80292E48();
    //L802B4C18

    if(animctrl_isAt(arg0, 0.6964f)){
        FUNC_8030E624(SFX_21_EGG_BOUNCE_1, 500, 0x731);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4C50

    if(animctrl_isAt(arg0, 0.7747f))
        func_80292EA4();
    //L802B4C74

    if(animctrl_isAt(arg0, 0.7822f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 0x1b5, 0x3ff);
    }//L802B4C90

    if(animctrl_isAt(arg0, 0.8322f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 0x1b5, 0x3ff);
    }//L802B4CB0

    if(animctrl_isAt(arg0, 0.8669f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 0x1b5, 0x3ff);
    }//L802B4CD0

    if(animctrl_isAt(arg0, 0.9048f)){
        FUNC_8030E624(SFX_6F_BANJO_HEADSCRATCH, 0x1b5, 0x3ff);
    }//L802B4CF0

    if(animctrl_isAt(arg0, 0.9649f)){
        func_802900D8();
    }//L802B4CF0
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/bsstand_update.s")
/*void bsstand_update(void){
    s32 temp_v1;
    s32 sp24 = 0;
    AnimCtrl * sp20 = _player_getAnimCtrlPtr();
    f32 sp1C;
    s32 sp18;
    

    if(!func_8029B300() && (0.0f < func_8029B2E8())){
        D_8037D544 = 1;
        func_802991A8(3);
        func_80299234(200.0f, 14.0f);

    }
    else{ 
        if(D_8037D544)
            yaw_setIdeal(yaw_get());
        D_8037D544 = 0;
        func_802991A8(1);
    }//L802B4DBC
    sp24 = func_802B488C(0);
    if((D_80364D20[D_8037D540] & (1 << 3))){
        if(sp18 = D_80364D20[D_8037D540] & (1 << 2)){
            if(animctrl_isAt(sp20, 0.0909f)){
                temp_v1 = sp18;
                sp18 = temp_v1;
                func_80299BD4();
            }

            if(animctrl_isAt(sp20, 0.0909f)){
                temp_v1 = sp18;
                sp18 = temp_v1;
                func_8029E070(1);
            }
            
            if(animctrl_isAt(sp20, 0.6818f)){
                temp_v1 = sp18;
                sp18 = temp_v1;
                func_8029E070(0);
            }
            
        }//L802B4E70
        if( temp_v1 & (1 << 1)){
            if(animctrl_isAt(sp20, 0.7727f))
                func_8029E070(1);

            if(animctrl_isAt(sp20, 0.9999f))
                func_8029E070(0);
        }else{
        }
    }
    else{ 
        if(D_80364D20[D_8037D540] & (1 << 5)){//L802B4EC0
            if(animctrl_getIndex(sp20) == 0x95){
                func_802B4A10(sp20);

                if(animctrl_isAt(sp20, 0.37f)){
                    animctrl_reset(sp20);
                    animctrl_setTransitionDuration(sp20, 0.1f);
                    animctrl_setIndex(sp20, 0xf6);
                    animctrl_setDuration(sp20, 5.0f);
                    animctrl_setPlaybackType(sp20,  ANIMCTRL_ONCE);
                    func_802875AC(sp20, D_80375A70, 0x170);
                }
            }
            else{//L802B4F54
                if(animctrl_isAt(sp20, 0.069f)) //nice
                    func_80299D2C(SFX_4B_GULPING, 1.4f, 0x4650);

                if(animctrl_isAt(sp20, 0.1677f))
                    func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.0f, 0x4650);
                
                if(animctrl_isAt(sp20, 0.2441f))
                    func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.03f, 0x4650);

                if(animctrl_isAt(sp20, 0.3141f))
                    func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.06f, 0x4650);

                if(animctrl_isAt(sp20, 0.3859f))
                    func_80299D2C(SFX_8B_KAZOOIE_RAWW, 1.5f, 0x7D00);

                if(animctrl_isAt(sp20, 0.414f))
                    func_80299D2C(SFX_2D_KABOING, 1.0f, 0x4650);

                if(animctrl_isAt(sp20, 0.55f))
                    func_80299D2C(SFX_A3_BANJO_DOUBLE_COUGH, 1.0f, 0x6d60);

                if(animctrl_isAt(sp20, 0.6187f))
                    func_80299D2C(SFX_A0_COUGHING, 1.7f, 0x4650);

                if(animctrl_isAt(sp20, 0.7108f))
                    func_80299D2C(SFX_A0_COUGHING, 1.6f, 0x4650);

                if(animctrl_isAt(sp20, 0.7927f))
                    func_80299D2C(SFX_A0_COUGHING, 1.5f, 0x4650);
            }
        } 
        else if(D_80364D20[D_8037D540] & (1 << 4)){//L802B50D4
            func_802B4A10(sp20);
        }//L802B50E4
    }

    if(animctrl_isAt(sp20, 0.9999f)){
        D_8037D540 = func_802B4870(D_8037D540);
        if(D_80364D20[D_8037D540] & (1<< 4)){
            func_8028A180(0x95, 5.5f);
            func_802875AC(sp20, D_80375A7C, 0x1AB);
            func_8029E070(1);
            func_802900FC();
        }
        else if(D_80364D20[D_8037D540] & (1<< 5)){//L802B5164
            func_8028A180(0x95, 5.5f);
            func_8029E070(1);
            func_802900FC();
        }
        else if(D_80364D20[D_8037D540] & (1<< 3)){//L802B5190
            if(animctrl_getIndex(sp20) == 0x6f){
                sp1C = func_802877D8(sp20);
            }else{
                sp1C = 0.0f;
                func_802900B4();
            }
            animctrl_reset(sp20);
            animctrl_setIndex(sp20, 0x6f);
            animctrl_setDuration(sp20, 5.5f);
            animctrl_setPlaybackType(sp20,  ANIMCTRL_LOOP);
            func_8028774C(sp20, sp1C);
            func_802875AC(sp20, D_80375A88, 0x1c3);
            func_8029E070(0);
        }
    }//L802B521C


    if(func_8028B094())
        sp24 = BS_FALL;
    bs_setState(sp24);

}//*/

void bsstand_end(void){
    func_8029E070(0);
    func_802900FC();
    func_80292EA4();
}

//bsStand_Land_init
void bsstand_landing_init(void){
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
}

//bsStand_Land_update
void bsstand_landing_update(void){
    s32 sp1C = 0;
    AnimCtrl * sp18 = _player_getAnimCtrlPtr();

    if(animctrl_getIndex(sp18) == 0xd2){
        if(animctrl_isAt(sp18, 0.8264f)){
            func_80299CF4(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 0x36b0);
        }

        //L802B52F8
        if(animctrl_isAt(sp18, 0.8864f)){
            func_80299CF4(SFX_6F_BANJO_HEADSCRATCH, 1.0f, 0x36b0);
        }
    }
    //L802B531C
    if(animctrl_isStopped(sp18))
        sp1C = BS_1_IDLE;

    bs_setState(func_802B488C(sp1C));
}


///BREAK???
void func_802B5350(void){
    s32 sp1C = bs_getInterruptType();
    if(sp1C == 0xd){
        bs_setState(0x52);
    }
    if(sp1C == 0x7){
        if(_player_getTransformation() != TRANSFORM_1_BANJO)
            func_8029A86C(1);
        else{
            func_802948F8(func_8028D688());
            bs_setState(BS_CARRY_IDLE);
        }
    }
    else if(sp1C == 0x12){//L802B53D0
        func_8029A86C(1);
        if( _player_getTransformation() == TRANSFORM_1_BANJO && !func_802933C0(0xF) && func_802916CC(0)){
            func_8028DE6C(carriedObject_getActorID());
            func_8029A86C(2);
        }
    }
    else if(sp1C == 0x8){//L802B5438
        func_8029A86C(2);
        bs_setState(0x3C);
    }else{
        func_802948E0();
        func_80296608();
    }
}
