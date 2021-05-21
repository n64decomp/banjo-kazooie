#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void player_setYPosition(f32);
void func_802AFB94(f32);
void func_802AFBA0(f32);
void func_802AFBAC(f32);
void func_8024E3A8(f32 (*)[3], f32);
void func_802AFBB8(f32 (*)[3]);
void func_802991FC(void);
void func_802978DC(int);
void func_8030E624(u32);
void func_8030E6D4(int);

extern struct {
    u8 pad0[0x1C];
    u8 unk1C;
    u8 pad1D[0x3];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 unk30;
    u8 unk31;
    u8 unk32;
} D_8037D470;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AF7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AF88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AF900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802AFFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802B0060.s")

void func_802B014C(void){
    func_80289EBC(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802B016C.s")
/* void func_802B016C(void){
    D_8037D470.unk20 = 0.0f;
    D_8037D470.unk28 = 0.0f;
    D_8037D470.unk24 = 1.0f;
    func_80289EBC(func_802B0060);
}//*/

void func_802B01B0(f32 arg0){
   D_8037D470.unk28 = arg0;
}

void func_802B01BC(f32 arg0){
   D_8037D470.unk24 = arg0;
}

void func_802B01C8(void){
   D_8037D470.unk20 += func_8033DD9C();
}

static void __bsdronexform_setState(int arg0){
    enum asset_e sp34;
    f32 sp30;
    f32 sp24[3];

    D_8037D470.unk32 = arg0;
    switch(arg0){
        case 1:// 802B0230
            D_8037D470.unk1C = 1;
            D_8037D470.unk2C = player_getYPosition();
            func_802AFB94(0.28f);
            func_802AFBA0(180.0f);
            func_802AFBAC(0.04f);
            func_802B01B0(0.05f);
            func_802978DC(7);
            func_8029E3C0(0, 2.8f);
            func_8030E624(0x7feea17e);
            break; 
        
        case 2:// 802B02A8
            func_8029E3C0(0, 0.5f);
            func_802978DC(0xb);
            break;

        case 3:// 802B02C4
            func_8029E3C0(0, 0.05f);
            break;

        case 4:// 802B02DC
            func_8029E3C0(0, 0.8f);
            break;

        case 5:// 802B02F4
            _player_getPosition(&sp24);
            sp24[1] += 30.0f;
            func_8024E3A8(&sp24, 80.0f);
            func_802AFBB8(&sp24);
            func_8029E3C0(0, 0.1f);
            break;

        case 6: // 802B033C
            func_802BB3DC(2, 80.0f, 0.85f);
            func_8030E6D4(0x147);
            if(D_8037D470.unk30 == 7 || D_8037D470.unk31 == 7){
                yaw_setIdeal(yaw_get() + 180.0f);
                func_802991FC();
            }
            func_8029A95C(func_80294A4C()); //set player transformation
            func_80291D04(); //update player model
            func_8029BD44(&sp34, &sp30);
            func_8028A010(sp34, sp30);
            func_8029E3C0(0, 0.1f);
            break;

        case 7: // 802B03E4
            func_8029E3C0(0, 0.8f);
            break;

        case 8: // 802B03FC
            if(D_8037D470.unk30 == 1 && D_8037D470.unk31 == 1){
                func_8025A6EC(JINGLE_MINIGAME_LOSS, 28000);
            }
            func_8029E3C0(0, 1.0f);
            break;

        case 9:// 802B0438
            D_8037D470.unk1C = 0;
            func_8029E3C0(0, 0.7f);
            func_802978DC(7);
            break; 
    }
}

void bsdronexform_init(void){
    f32 sp1C;
    enum asset_e sp18;
    func_8029BCAC(&sp18, &sp1C);
    func_8028A010(sp18, sp1C);
    func_8029C7F4(1,1,3,7);
    func_80297A0C(0);
    func_80297930(0);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80294378(6);
    func_802AFB0C();
    func_802B016C();
    D_8037D470.unk31 = func_8029A8F4();
    D_8037D470.unk30 = func_80294A4C();
    func_802933E8(0x1b);
    D_8037D470.unk32 = 0;
    __bsdronexform_setState(1);
}

f32 func_802B051C(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    return mlMap_f(func_8029E270(arg0), arg1, 0.0f, arg2, arg3);
}

void bsdronexform_update(void){
    int sp24;
    if(D_8037D470.unk1C)
        func_802AFFAC();

    func_802B01C8();
    switch(D_8037D470.unk32){
        case 1: 
            sp24 = func_8029E1A8(0);
            player_setYPosition(func_802B051C(0, 2.8f, 0.0f, 90.0f) + D_8037D470.unk2C);
            func_802AFB94(func_802B051C(0, 2.8f, 0.28f, 1.0f));
            func_802AFBA0(func_802B051C(0, 2.8f, 180.0f, 55.0f));
            func_802AFBAC(func_802B051C(0, 2.8f, 0.04f, 0.35f));
            func_802B01BC(func_802B051C(0, 2.8f, 1.0f, 0.8f));
            func_802B01B0(func_802B051C(0, 2.8f, 0.05f, 0.4f));
            func_8031B990(
                (s32)func_802B051C(0, 2.8f, 255.0f, 200.0f),
                (s32)func_802B051C(0, 2.8f, 255.0f, 80.0f),
                (s32)func_802B051C(0, 2.8f, 255.0f, 80.0f)
            );

            if(sp24)
                __bsdronexform_setState(2);

            break;

        case 2:
            sp24 = func_8029E1A8(0);
            func_802B01B0(func_802B051C(0, 0.5f, 0.4f, 0.6f));
            if(sp24)
                __bsdronexform_setState(3);
            break;

        case 3:
            sp24 = func_8029E1A8(0);
            func_802B01BC(func_802B051C(0, 0.05f, 0.8f, 1.2f));
            if(sp24)
                __bsdronexform_setState(4);
            break;

        case 4:
            sp24 = func_8029E1A8(0);
            func_802B01BC(func_802B051C(0, 0.8f, 1.2f, 0.09f));
            if(sp24)
                __bsdronexform_setState(5);
            break;

        case 5:
            sp24 = func_8029E1A8(0);
            if(sp24)
                __bsdronexform_setState(6);
            break;

        case 6:
            sp24 = func_8029E1A8(0);
            if(sp24)
                __bsdronexform_setState(7);
            break;

        case 7:
            sp24 = func_8029E1A8(0);
            func_802B01BC(func_802B051C(0, 0.8f, 0.09f, 1.0f));
            if(sp24)
                __bsdronexform_setState(8);
            break;

        case 8:
            func_802AFBAC(func_802B051C(0, 1.0f, 0.35f, 0.03f));
            func_802B01B0(func_802B051C(0, 1.0f, 0.6f, 0.05f));
            func_8031B990(
                (s32)func_802B051C(0, 1.0f, 200.0f, 255.0f),
                (s32)func_802B051C(0, 1.0f, 80.0f, 255.0f),
                (s32)func_802B051C(0, 1.0f, 80.0f, 255.0f)
            );
            if(func_8029E1A8(0)){
                if(player_getTransformation() == TRANSFORM_WISHWASHY){
                    bs_setState(0x33);
                }else{
                    __bsdronexform_setState(9);
                }
            }
            break;

        case 9:
            sp24 = func_8029E1A8(0);
            player_setYPosition(func_802B051C(0, 0.7f, 90.0f, 0.0f) + D_8037D470.unk2C);
            if(sp24)
                bs_setState(func_8029BF78());
            break;
        // 802B08AC 8
        // 802B09A4 9
    }
}

void bsdronexform_end(void){
    func_80294378(1);
    func_8031B990(0xff,0xff,0xff);
    func_802AFADC();
    func_802B014C();
    func_80298A64();
    func_802933FC(0x1b);
}

void bsdronexform_interrupt(void){};