#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80292974(f32, f32, f32);
void func_80297BF8(f32);
void func_80297CCC(f32);
void func_8030E5F4(s32, f32);
void func_8030E760(s32, f32, s32);

int func_8032728C(f32*, f32, s32, s32(*)(Actor *));


extern f32 D_80364990;
extern f32 D_80364994;

extern f32 D_80364998;
extern f32 D_8036499C;

extern f32 D_803649A0;
extern f32 D_803649A4;
extern f32 D_803649A8;



extern f32 D_8037D2B0;
extern u8 D_8037D2B4;
extern u8 D_8037D2B5;
extern u8 D_8037D2B6;
extern u8 D_8037D2B7;
extern u8 D_8037D2B8;
extern u8 D_8037D2B9;
extern u8 D_8037D2BA;
extern u8 D_8037D2BB;
extern u8 D_8037D2BC;

void func_802A02B4(s32 arg0);

int func_8029FB20(Actor *arg0){
    return !arg0->unk124_0;
}

void func_8029FB30(void) {
    f32 i;

    for(i = 0.0f; i < 359.0; i += 60.0){
        func_80292974(i, 730.0f, 100.0f);
    }
    for(i = 0.0f; i < 359.0; i += 60.0){
        func_80292974(mlNormalizeAngle(i + 30.0f), 430.0f, 40.0f);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FC4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bbuster/func_8029FC58.s")

void bsbbuster_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp20[3];
    
    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, 0x1D);
    animctrl_setDuration(aCtrl, 1.02f);
    func_802876CC(aCtrl, 0.0f, 0.35f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsbbuster.c", 0x81);
    func_8029C7F4(1,1,3,6);
    func_80297BEC(0.0f);
    func_80297970(0.0f);
    clear_vec3f(sp20);
    func_80297A0C(sp20);
    func_8029E070(1);
    func_802A02B4(0);
    D_8037D2B9 = 0;
    D_8037D2B7 = 0;
    D_8037D2B8 = 0;
    D_8037D2B0 = 0.0001f;
    D_8037D2B4 = 0;
    D_8037D2B5 = 0;
    D_8037D2B6 = 0;
    D_8037D2BC = 0;
    D_8037D2BA = 0;
}

void bsbbuster_update(void){
    enum bs_e sp44 = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    s32 sp3C;
    f32 sp30[3];
    s32 sp24[3];

    D_8037D2B8 = 0;
    if(func_802878E8(aCtrl, 0.24f))
        func_80299BD4();

    switch(D_8037D2BA){
        case 0://8029FDF0
            if(func_802878C4(player_getAnimCtrlPtr())){
                animctrl_setDuration(aCtrl, 0.4f);
                D_8037D2BA = 1;
            }
            break;
        case 1://8029FE24
            D_8037D2B0 -= func_8033DD9C();
            if(D_8037D2B0 <= 0.0f){
                func_80297B70();
                func_80297BF8(D_803649A8);
                func_80297BEC(D_803649A4);
                func_802979A0(D_803649A0);
                D_8037D2B7 = 1;
                D_8037D2BA = 2;
            }
            break;
        case 2://8029FEA0
            if(D_8037D2B5 == 0 && func_80297AAC() < 0.0f){
                func_8030E760(0x45, 1.2f, 0x7530);
                D_8037D2B5++;
            }
            if(D_8037D2B4 == 0 && func_8028B254(0x8c)){
                func_8030E5F4(0x13, 1.0f);
                D_8037D2B4++;
            }
            if(D_8037D2B6 == 0 && func_8028B254(0x4b)){
                func_80250D94(1.0f, 0.3f, 0.4f);
                D_8037D2B6++;
            }
            D_8037D2B9 = func_802933C0(8);
            func_8029445C(sp30);
            //L8029FF78
            if(((0.0f <= sp30[1])? sp30[1] : -sp30[1]) < 1.0){
                D_8037D2BC++;
            }else{
                D_8037D2BC = 0;
            }
            if(D_8037D2B7 == 2){
                D_8037D2B7 = 0;
            }
            if(func_8028B2E8() || D_8037D2B9 || !(D_8037D2BC < 4)){
                func_802BB3DC( 0, 45.0f, 0.71f);
                func_8029AE74(0);
                func_8029FB30();
                func_80297A0C(0);
                func_80297BEC(0.0f);
                func_80297970(0.0f);
                D_8037D2B7 = 2;
                D_8037D2B8 = 1;
                D_8037D2B0 = 0.09f;
                D_8037D2BA = 3;
                _player_getPosition(sp24);
                func_8032728C(sp24, 150.0f, 2, func_8029FB20);
                if(func_802931DC(&sp3C)){
                    sp44 = BS_SPLAT;
                }
            }
            break;
        case 3://802A00F0
            D_8037D2B7 = 0;
            if(func_80297C6C() == 1){
                func_80297CCC(0.9f);
            }
            
            D_8037D2B0 -= func_8033DD9C();
            if(D_8037D2B0 <= 0.0f){
                if(D_8037D2BB){
                    func_802979A0(D_80364990);
                    func_80297BEC(D_80364994);
                }else{
                    func_802979A0(D_80364998);
                    func_80297BEC(D_8036499C);
                }
            
                func_802876CC(aCtrl, 0.0f, 0.7299f);
                animctrl_setDuration(aCtrl, 1.9f);
                func_80287674(aCtrl, 1);
                D_8037D2BA = 4;
            }
            break;
        
        case 4://802A01CC
            func_802B6FA8();
            if(func_802878C4(aCtrl)){
                func_802876CC(aCtrl, 0.0f, 0.74f);
                animctrl_setDuration(aCtrl, 15.0f);
                func_80287674(aCtrl, 1);
            }
            if(func_8028B2E8()){
                func_802876CC(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.9f);
                func_80287674(aCtrl, 1);
                sp44 = BS_LANDING;
            }
            break;
    }
    if(player_inWater())
        sp44 = BS_LANDING_IN_WATER;

    bs_setState(sp44);
}//L802A024C

void bsbbuster_end(void){
    func_80297B70();
    func_80297B94();
    func_8029E070(0);
    D_8037D2B7 = 0;
    D_8037D2B8 = 0;
}

void func_802A02B4(s32 arg0){
    D_8037D2BB = arg0;
}