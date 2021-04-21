#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

extern f32 func_8029B2E8(void);
void func_80299234(f32, f32);
int func_802878E8(AnimCtrl *, f32);
void func_802876C0(AnimCtrl *, f32);
void func_802875AC(AnimCtrl *, char*, s32);
void func_80299D2C(s32, f32, s32);
void func_8028774C(AnimCtrl *, f32);
f32 func_802877D8(AnimCtrl *);
void func_802900B4(void);
void func_80250D94(f32, f32, f32);
void func_8030E58C(s32, f32);
void func_80299CF4(s32, f32, s32);

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
            retVal = BS_CREEP;
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

    if(button_pressed(BUTTON_B) && func_8028A9E0())
        retVal = BS_PUNCH;

    if(button_pressed(BUTTON_A))
        retVal = func_8029C780();

    if(func_80294F78())
        retVal = func_802926C0();

    if(func_8028B338())
        retVal = BS_SLIDE;

    retVal = func_8029CA94(retVal);

    if(player_inWater())
        retVal = BS_SWIM_IDLE;
    
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
    if(func_802878E8(arg0, 0.2057f)){ //(30/145)
        func_8030E624(0xe62fa021);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4A54

    if(func_802878E8(arg0, 0.2057f)) //(30/145)
        func_80292E48();
    //L802B4A78

    if(func_802878E8(arg0, 0.2555f)){ //(37/145)
        func_8030E624(0xe62fa021);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4AB0

    if(func_802878E8(arg0, 0.2896f)){ //(42/145)
        func_8030E624(0xe62fa021);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4AEC

    if(func_802878E8(arg0, 0.3f)){ //(43.5/145)?
        func_8030E624(0x7ffb5862);
    }//L802B4B0C

    if(func_802878E8(arg0, 0.3607f)){
        func_80292EA4();
    }//L802B4B30

    if(func_802878E8(arg0, 0.4183f)){
        func_8030E58C(0x3f1, 1.6f);
    }//L802B4B50

    if(func_802878E8(arg0, 0.455f)){
        func_8030E58C(0x3f1, 1.45f);
    }//L802B4B74

    if(func_802878E8(arg0, 0.49f)){
        func_8030E58C(0x3f1, 1.4f);
    }//L802B4B98

    if(func_802878E8(arg0, 0.5397f)){
        func_802900D8();
    }//L802B4BBC

    if(func_802878E8(arg0, 0.6619f)){
        func_8030E624(0xe62fa021);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4BF4

    if(func_802878E8(arg0, 0.6688f))
        func_80292E48();
    //L802B4C18

    if(func_802878E8(arg0, 0.6964f)){
        func_8030E624(0xe62fa021);
        func_80250D94(0.5f, 0.25f, 0.4f);
    }//L802B4C50

    if(func_802878E8(arg0, 0.7747f))
        func_80292EA4();
    //L802B4C74

    if(func_802878E8(arg0, 0.7822f)){
        func_8030E624(0x7feda86f);
    }//L802B4C90

    if(func_802878E8(arg0, 0.8322f)){
        func_8030E624(0x7feda86f);
    }//L802B4CB0

    if(func_802878E8(arg0, 0.8669f)){
        func_8030E624(0x7feda86f);
    }//L802B4CD0

    if(func_802878E8(arg0, 0.9048f)){
        func_8030E624(0x7feda86f);
    }//L802B4CF0

    if(func_802878E8(arg0, 0.9649f)){
        func_802900D8();
    }//L802B4CF0
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/stand/bsstand_update.s")
/*void bsstand_update(void){
    s32 temp_v1;
    s32 sp24 = 0;
    AnimCtrl * sp20 = player_getAnimCtrlPtr();
    f32 sp1C;
    s32 sp18;
    

    if(!func_8029B300() && (0.0f < func_8029B2E8())){
        D_8037D544 = 1;
        func_802991A8(3);
        func_80299234(200.0f, 14.0f);

    }
    else{ 
        if(D_8037D544)
            player_setMovingYaw(player_getYaw());
        D_8037D544 = 0;
        func_802991A8(1);
    }//L802B4DBC
    sp24 = func_802B488C(0);
    if((D_80364D20[D_8037D540] & (1 << 3))){
        if(sp18 = D_80364D20[D_8037D540] & (1 << 2)){
            if(func_802878E8(sp20, 0.0909f)){
                temp_v1 = sp18;
                sp18 = temp_v1;
                func_80299BD4();
            }

            if(func_802878E8(sp20, 0.0909f)){
                temp_v1 = sp18;
                sp18 = temp_v1;
                func_8029E070(1);
            }
            
            if(func_802878E8(sp20, 0.6818f)){
                temp_v1 = sp18;
                sp18 = temp_v1;
                func_8029E070(0);
            }
            
        }//L802B4E70
        if( temp_v1 & (1 << 1)){
            if(func_802878E8(sp20, 0.7727f))
                func_8029E070(1);

            if(func_802878E8(sp20, 0.9999f))
                func_8029E070(0);
        }else{
        }
    }
    else{ 
        if(D_80364D20[D_8037D540] & (1 << 5)){//L802B4EC0
            if(func_80287790(sp20) == 0x95){
                func_802B4A10(sp20);

                if(func_802878E8(sp20, 0.37f)){
                    func_802874AC(sp20);
                    func_802876C0(sp20, 0.1f);
                    animctrl_setIndex(sp20, 0xf6);
                    animctrl_setDuration(sp20, 5.0f);
                    func_80287674(sp20, 1);
                    func_802875AC(sp20, D_80375A70, 0x170);
                }
            }
            else{//L802B4F54
                if(func_802878E8(sp20, 0.069f)) //nice
                    func_80299D2C(0x4b, 1.4f, 0x4650);

                if(func_802878E8(sp20, 0.1677f))
                    func_80299D2C(0x8b, 1.0f, 0x4650);
                
                if(func_802878E8(sp20, 0.2441f))
                    func_80299D2C(0x8b, 1.03f, 0x4650);

                if(func_802878E8(sp20, 0.3141f))
                    func_80299D2C(0x8b, 1.06f, 0x4650);

                if(func_802878E8(sp20, 0.3859f))
                    func_80299D2C(0x8b, 1.5f, 0x7D00);

                if(func_802878E8(sp20, 0.414f))
                    func_80299D2C(0x2d, 1.0f, 0x4650);

                if(func_802878E8(sp20, 0.55f))
                    func_80299D2C(0xa3, 1.0f, 0x6d60);

                if(func_802878E8(sp20, 0.6187f))
                    func_80299D2C(0xa0, 1.7f, 0x4650);

                if(func_802878E8(sp20, 0.7108f))
                    func_80299D2C(0xa0, 1.6f, 0x4650);

                if(func_802878E8(sp20, 0.7927f))
                    func_80299D2C(0xa0, 1.5f, 0x4650);
            }
        } 
        else if(D_80364D20[D_8037D540] & (1 << 4)){//L802B50D4
            func_802B4A10(sp20);
        }//L802B50E4
    }

    if(func_802878E8(sp20, 0.9999f)){
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
            if(func_80287790(sp20) == 0x6f){
                sp1C = func_802877D8(sp20);
            }else{
                sp1C = 0.0f;
                func_802900B4();
            }
            func_802874AC(sp20);
            animctrl_setIndex(sp20, 0x6f);
            animctrl_setDuration(sp20, 5.5f);
            func_80287674(sp20, 2);
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
    AnimCtrl * sp18 = player_getAnimCtrlPtr();

    if(func_80287790(sp18) == 0xd2){
        if(func_802878E8(sp18, 0.8264f)){
            func_80299CF4(0x6f, 1.0f, 0x36b0);
        }

        //L802B52F8
        if(func_802878E8(sp18, 0.8864f)){
            func_80299CF4(0x6f, 1.0f, 0x36b0);
        }
    }
    //L802B531C
    if(func_802878C4(sp18))
        sp1C = BS_IDLE;

    bs_setState(func_802B488C(sp1C));
}


///BREAK???
void func_802B5350(void){
    s32 sp1C = bs_getInterruptType();
    if(sp1C == 0xd){
        bs_setState(0x52);
    }
    if(sp1C == 0x7){
        if(func_8029A8F4() != 1)
            func_8029A86C(1);
        else{
            func_802948F8(func_8028D688());
            bs_setState(BS_CARRY_IDLE);
        }
    }
    else if(sp1C == 0x12){//L802B53D0
        func_8029A86C(1);
        if( func_8029A8F4() == 1 && !func_802933C0(0xF) && func_802916CC(0)){
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
