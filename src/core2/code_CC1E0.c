#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80244D94(f32[3], f32[3], f32[3], u32, f32);

extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);

extern f32 func_8033EA14(s32);
extern void func_8033EA40(s32, f32);
extern void func_8033FBC8(u8, enum asset_e);
extern void func_8033FCD8(u8, s32);
extern void func_8033FEC8(u8, f32[3]);
extern void func_8033FF10(u8, f32[3]);
extern void func_8033FFE4(u8, s32, s32);
extern void func_80344E18(u8, s32);
extern void func_80344E3C(u8, f32[3]);
extern void func_80344EE4(u8, f32, f32);
extern void func_80354030(f32[3], f32);

void func_80353FBC(s32 arg0, ActorMarker *arg1, s32 arg2);

/* .data */
extern struct53s D_803726A0;

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

void func_803535A0(void){
    u8 sp7f = func_8033E8D0();
    struct54s *sp78 = func_8033E8F4();
    u8 sp77 = func_8033E93C();
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    ActorMarker *marker = func_8033E840();
    f32 tmp_f8 = 20.0f;

    marker->unk2C_1 = 1;
    marker->collidable = 1;
    func_803300B8(marker, func_80353FBC);
    func_8033EA40(0, 20.0f);
    func_8033EA40(1, 0.0f);
    func_8033EA40(2, 0.0f);
    _player_getPosition(sp50);
    sp50[1] += 80.0f;
    ml_vec3f_copy(sp68, sp50);
    player_getRotation(sp44);
    func_80256E24(sp5C, 0.0f, sp44[1], 0.0f, 0.0f, 70.0f);
    sp50[0] += sp5C[0];
    sp50[1] += sp5C[1];
    sp50[2] += sp5C[2];
    func_80244D94(sp68, sp50, sp38, 0x25e0080, 15.0f);

    func_8033FBC8(sp7f, ASSET_708_SPRITE_EGG_PROJECTILE);
    func_8033FFE4(sp7f, (s32)tmp_f8, (s32)tmp_f8);
    func_8033FEC8(sp7f, sp50);
    func_8033FCD8(sp7f, 0xe);

    func_80287E9C(sp78);
    func_80287F50(sp78, &D_803726A0, 0x14);
    func_80287F10(sp78);

    func_80344E18(sp77, 1);
    func_80344EE4(sp77, 0.0f, 0.0f);
    func_80344D94(sp77, sp50);
    sp44[1] += 4.0;
    func_80256E24(sp5C, 0.0f, sp44[1], 0.0f, 0.0f, 800.0f);
    sp5C[1] = 0.0f;
    func_80344E3C(sp77, sp5C);
}

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
    tmp_f24 -= time_getDelta();
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
    sp78 += time_getDelta();
    func_8033EA40(1, sp78);
    if(2.0 < sp78){
        func_8033E984();
    }
}

void func_80353A90(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353CC8.s")

void func_80353FB4(void){}

void func_80353FBC(s32 arg0, ActorMarker *arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CC1E0/func_80353FBC.s")
