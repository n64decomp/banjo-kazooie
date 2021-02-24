#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8029797C(f32);
f32 func_80297A64(void);
void func_80297970(f32);
f32 func_80297A7C(void);
s32 func_802878E8(Movement*, f32);
s32 func_8029E2E0(s32, f32);
void  func_80292864(f32, f32);
void func_802979AC(f32, f32);
void func_8032728C(f32*, f32, s32, s32(*)(Actor *));
void func_8029E3C0(s32, f32);
void func_8030E760(s32, f32, s32);



extern f32 D_8037D2A0;
extern u8 D_8037D2A4;
extern u8 D_8037D2A5;
extern u8 D_8037D2A6;


s32 func_8029F4E0(Actor * arg0){
    return arg0->unk138_31 == 0;
}

void func_8029F4F0(void){
    u8 val;
    f32 tmp_f;
    if(func_8029E1A8(2)){
        func_8029AE74(0);
        func_8029E3C0(2, 0.12f);
    }
    if( (++D_8037D2A4) >= 3)
        D_8037D2A4 = 0;

    switch(D_8037D2A4){
        case 0:
            tmp_f = (func_80297A7C() + 180.0f);
            func_80292864(tmp_f - 70.0f, 20.0f);
            break;
        case 1:
            tmp_f = (func_80297A7C() + 180.0f);
            func_80292864(tmp_f - 10.0f, 20.0f);
            break;
        case 2:
            tmp_f = (func_80297A7C() + 180.0f);
            func_80292864(tmp_f + 50.0f, 20.0f);
            break;
    }
}

void func_8029F60C(void){
    f32 plyrPos[3];
    player_getPosition(plyrPos);
    func_8032728C(plyrPos, 50.0f, 2, func_8029F4E0);
}


s32 func_8029F644(void){
    return D_8037D2A6;
}

//bsbarge_start
void func_8029F650(void){
    Movement *plyrMvmnt;

    plyrMvmnt = func_80289F64();
    func_802874AC(plyrMvmnt);
    func_80287684(plyrMvmnt, 0);
    movement_setIndex(plyrMvmnt, 0x1C);
    movement_setDuration(plyrMvmnt, 1.0f);
    func_802876CC(plyrMvmnt, 0, 0.375f);
    func_80287674(plyrMvmnt, 1);
    func_802875AC(plyrMvmnt, "bsbbarge.c", 0x98);
    D_8037D2A4 = 0;
    func_8029C7F4(1,1,3,3);
    func_8029797C(player_getMovingYaw());
    func_80297970(func_80297A64()*0.3);
    func_802979AC(player_getMovingYaw(), func_80297A64());
    func_8029E070(1);
    D_8037D2A6 = 0;
    D_8037D2A5 = 0;
    func_802933FC(0xA);
    func_802933FC(0xB);
    func_802933FC(0xC);
    func_8029E3C0(2, 0.01f);

}

//bsbarge_update
void func_8029F77C(void){
    s32 sp24;
    Movement *plyrMvmnt;
    
    sp24 = 0;
    plyrMvmnt = func_80289F64();
    if(func_80295590(9))
        func_802933E8(0xA);
    switch(D_8037D2A5){
        case 0:
            if(func_802878E8(plyrMvmnt, 0.1392f))
                func_80299BD4();
            
            if(!func_802878C4(plyrMvmnt))
                break;

            if(func_802933D0(0xA)){
                func_802933E8(0xC);
                D_8037D2A0 = 850.0f;
            }else{
                D_8037D2A0 = 500.0f;
            }
            func_8029E3C0(1, 0.01f);
            D_8037D2A5 = 1;
            break;
        case 1:
            func_8029E1A8(1);
            if(func_802933D0(0xB) && func_8029E2E0(1, 0.1f)){
                if(func_802933C0(0xC)){
                    func_8030E560(4, 0x7530);
                }else{
                    func_8030E560(0x43, 0x7530);
                }
                func_802933E8(0xB);
            }
            if(!func_8029E384(1))
                break;
            
            movement_setDuration(plyrMvmnt, 1.0f);
            func_8028A37C(0.565f);
            func_80297970(D_8037D2A0);
            func_802979AC(player_getMovingYaw(), func_80297A64());
            func_8030E760(2, 0.558f, 22000);
            D_8037D2A5 = 2;
            func_8029F4F0();
            D_8037D2A6 = 1;
            break;
        case 2:
            func_80297970(D_8037D2A0);
            if(func_802878C4(plyrMvmnt)){
                movement_setDuration(plyrMvmnt, 2.0f);
                func_8028A37C(0.6f);
                func_8029E3C0(0, 0.1f);
                D_8037D2A5 = 3;
            }
            func_8029F4F0();
            break;
        case 3:
            func_8029E1A8(0);
            if(func_802933D0(0xC) || func_8029E384(0)){
                D_8037D2A0 -= 80.0f;
            }
            func_80297970(D_8037D2A0);
            if(D_8037D2A0 < 200.0f){
                movement_setDuration(plyrMvmnt, 1.5f);
                func_8028A37C(1.0f);
                D_8037D2A5 = 4;
            }
            func_8029F4F0();
            break;
        case 4:
            if(!func_8028B2E8())
                sp24 = 0x2F;

            if(func_802878E8(plyrMvmnt, 0.7f)){
                D_8037D2A0 = 0.0f;
                D_8037D2A6 = 0;
            }
            func_80297970(D_8037D2A0);
            if(func_802878E8(plyrMvmnt, 0.9193f))
                sp24 = 0x20;
            break;
    }
    if(D_8037D2A6)
        func_8029F60C();

    if(func_8028B51C())
        sp24 = 0x4c;
    func_8029A72C(sp24);
}

//bsbarge_end
void func_8029FAE8(void){
    func_80295610(5);
    func_8029E070(0);
    D_8037D2A6 = 0;
}
