#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern f32  func_8033DDEC(void);
extern u8   func_8033E8D0(void);
extern void func_8033FFE4(u8, s32, s32);
extern void func_8033FC34(u8, s32);
extern void projectile_setPosition(u8, f32[3]);
extern void func_80344D94(u8, f32[3]);
extern void func_80344E3C(u8, f32[3]);

/* .data */
extern struct53s D_80372670;

/* .code */
void func_80352CA0(u8 arg0, f32 *arg1){
    func_8033FFE4(arg0, (s32)arg1[0], (s32)arg1[0]);
    func_8033FC34(arg0, (s32)arg1[2]);
}

void func_80352CF4(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3) {
    f32 *sp1C;
    u8 sp1B;
    u8 sp1A;


    if (func_8033E3F0(7, 1) >= 0) {
        sp1A = func_8033E8D0();
        sp1B = func_8033E93C();
        sp1C = func_8033E960();
        sp1C[0] = arg2;
        sp1C[1] = (arg3 - arg2) / 20.0f;
        projectile_setPosition(sp1A, arg0);
        func_80344D94(sp1B, arg0);
        func_80344E3C(sp1B, arg1);
        func_80352CA0(sp1A, sp1C);
    }
}

s32 func_80352D9C(void) {
    return (s32) ((randf() * 10.0) + 245.0);
}

void func_80352DE4(void) {
    u8 temp_s0;
    struct54s *sp58;
    u8 sp57;
    ParticleStruct0s *temp_s1;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    temp_s0 = func_8033E8D0();
    sp58 = func_8033E8F4();
    sp57 = func_8033E93C();
    temp_s1 = func_8033E960();
    player_getPosition(sp44);
    temp_s1->unk0 = 10.0f;
    temp_s1->unk4 = 8.0f;
    temp_s1->unk8 = 255.0f;
    temp_s1->unkC = -11.0f;
    projectile_setSprite(temp_s0, ASSET_70D_SPRITE_SMOKE_1);
    func_8033FCD8(temp_s0, 0xC);
    func_8033FC60(temp_s0, func_80352D9C(), func_80352D9C(), func_80352D9C());
    projectile_setPosition(temp_s0, sp44);
    sp2C[0] = 0.0f;
    sp2C[1] = 0.0f;
    sp2C[2] = randf() * 359.0f;
    func_8033FD98(temp_s0, sp2C);
    func_80287E9C(sp58);
    func_80287F7C(sp58, 1);
    func_80287F50(sp58, &D_80372670, 0x28);
    func_80287F10(sp58);
    sp38[0] = 0.0f;
    sp38[1] = 40.0f;
    sp38[2] = 0.0f;
    func_80344E18(sp57, 2);
    func_80344E3C(sp57, sp38);
    func_80344D94(sp57, sp44);
    func_80352CA0(temp_s0, temp_s1);
}

void func_80352F58(void){
    f32 *sp2C = func_8033E960();
    struct54s *sp28 = func_8033E8F4();
    u8 sp27 = func_8033E8D0();
    f32 sp20 = func_8033DDEC();
    if(func_80288034(sp28)){
        func_8033E984();
    }
    else{
        sp2C[0] += sp2C[1]*sp20;
        sp2C[2] = max_f(0.0f, sp2C[2] + sp2C[3]*sp20);
        func_80352CA0(sp27, sp2C);
    }
}

void func_80352FF4(void){}

void func_80352FFC(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3){
    f32 sp1C[3];
    func_802589E4(sp1C, arg1, arg2);
    sp1C[1] = arg3;
    func_80352CF4(arg0, sp1C, randf2(380.0f, 250.0f), 4.0f);
}

void func_80353064(f32 arg0[3], f32 arg1){
    f32 tmp_f22;
    arg0[1] += arg1;
    for(tmp_f22 = 0.0f; tmp_f22 < 359.0; tmp_f22 += 60.0){
        func_80352FFC(arg0, tmp_f22, 730.0f, 120.0f);
        func_80352FFC(arg0, mlNormalizeAngle(tmp_f22 + 30.0f), 470.0f, 60.0f);
    }
    arg0[1] -= arg1; 
}
