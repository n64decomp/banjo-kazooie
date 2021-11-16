#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8033EA14(s32);
extern void func_8033EA40(s32, f32);
extern void func_8033FFE4(u8, s32, s32);
extern void func_80354030(f32[3], f32);
extern void func_8033FF10(u8, f32[3]);
extern void func_80344E3C(u8, f32[3]);

/* .rodata */
extern f32 D_80379434;

/* .code */
void func_80353170(u8 arg0){
    f32 sp24[3];
    func_8033FF10(arg0, sp24);
    func_8030EBC8(SFX_D_EGGSHELL_BREAKING, 1.6f, 1.7f, 13000, 13000);
    func_80292C40(sp24);
}

void func_803531C8(u8, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_803531C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_803534C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_803535A0.s")

void func_803537B8(void){
    u8 s1;
    u8 sp96;
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp78;
    f32 tmp_f24;
    ActorMarker *s0;
    f32 sp6C;
    f32 sp60[3];
    f32 sp54[3];
    f32 tmp_f20;
    
    s1 = func_8033E8D0();
    sp96 = func_8033E93C();
    sp78 = func_8033EA14(1);
    tmp_f24 = func_8033EA14(2);
    tmp_f24 -= func_8033DD9C();
    sp6C = ml_map_f(sp78, 0.0f, 2.0f, 0.0333f, D_80379434);
    while(tmp_f24 <= 0.0f){//L80353868
        tmp_f24 += sp6C;
        func_8033FF10(s1, sp7C);
        func_8033E9D4();
        sp7C[0] += randf2(-8.0f, 8.0f);
        sp7C[1] += randf2(-8.0f, 8.0f);
        sp7C[2] += randf2(-8.0f, 8.0f);
        if(randf() < 0.5){
            func_803541C0(1);
        }
        else{
            func_803541C0(6);
        }
        func_803541CC(0x32);
        func_80354030(sp7C, 0.15f);
        func_8033E9F4();
    }//L80353930
    func_8033EA40(2, tmp_f24);
    func_803531C8(s1, 0);
    func_80344E7C(sp96, sp88);
    if(func_802582EC(sp88)){
        s0 = func_8033E840();
        func_8033FF10(s1, sp60);
        sp54[0] = (f32)s0->propPtr->x;
        sp54[1] = (f32)s0->propPtr->y;
        sp54[2] = (f32)s0->propPtr->z;
        func_8033E984();
        func_80353170(s1);
    }//L803539D4
    func_80344E3C(sp96, sp88);
    tmp_f20 = func_8033EA14(0);
    func_8033FFE4(s1, (s32) tmp_f20, (s32) tmp_f20);
    func_8033EA40(0, min_f(tmp_f20 + 4.0f, 50.0f));
    sp78 += func_8033DD9C();
    func_8033EA40(1, sp78);
    if(2.0 < sp78){
        func_8033E984();
    }
}

void func_80353A90(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353CC8.s")

void func_80353FB4(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353FBC.s")
