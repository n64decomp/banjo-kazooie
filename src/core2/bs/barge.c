#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_80299228(void );
void func_8029797C(f32);
f32 func_80297A64(void);
void func_80297970(f32);
f32 func_80297A7C(void);
void  func_80292864(f32, f32);
void func_802979AC(f32, f32);
void func_8032728C(f32*, f32, s32, s32(*)(Actor *));
void func_8029E3C0(s32, f32);



extern u8 D_8037D2A4;
extern u8 D_8037D2A5;
extern u8 D_8037D2A6;

extern s8 D_803752D0[]; //"bsbarge.c"
extern f64 D_803752E0;

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

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/barge/func_8029F650.s")
void func_8029F650(void){
    Movement *plyrMvmnt;

    plyrMvmnt = func_80289F64();
    func_802874AC(plyrMvmnt);
    func_80287684(plyrMvmnt, 0);
    movement_setIndex(plyrMvmnt, 0x1C);
    movement_setDuration(plyrMvmnt, 1.0f);
    func_802876CC(plyrMvmnt, 0, 0.375f);
    func_80287674(plyrMvmnt, 1);
    func_802875AC(plyrMvmnt, D_803752D0, 0x98);
    D_8037D2A4 = 0;
    func_8029C7F4(1,1,3,3);
    func_8029797C(func_80299228());
    func_80297970(func_80297A64()*D_803752E0);
    func_802979AC(func_80299228(), func_80297A64());
    func_8029E070(1);
    D_8037D2A6 = 0;
    D_8037D2A5 = 0;
    func_802933FC(0xA);
    func_802933FC(0xB);
    func_802933FC(0xC);
    func_8029E3C0(2, 0.01f);

}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/barge/func_8029F77C.s")

void func_8029FAE8(void){
    func_80295610(5);
    func_8029E070(0);
    D_8037D2A6 = 0;
}
