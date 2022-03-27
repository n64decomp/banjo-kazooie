#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8   func_8033E8D0(void);
extern void func_8033FBC8(u8, enum asset_e);
extern void func_8033FC34(u8, s32);
extern void func_8033FC60(u8, s32, s32, s32);
extern void func_8033FCD8(u8, s32);
extern void func_8033FD98(u8, f32[3]);
extern void func_8033FEC8(u8, f32[3]);
extern void func_8033FFE4(u8, s32, s32);

extern void func_80344E18(u8, s32);
extern void func_80344E3C(u8, f32[3]);
extern void func_80344D94(u8, f32[3]);

/* .data */
extern struct53s *D_80372700;

/* .rodata */
extern f32 D_803794E0;

/* .code */
void func_80356020(u8 arg0, f32 arg1[4]){
    func_8033FFE4(arg0, (s32)arg1[0], (s32)arg1[0]);
    func_8033FC34(arg0, (s32)arg1[2]);
}

void func_80356074(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3){
    f32 *sp1C;
    u8 sp1B;
    u8 sp1A;

    if(func_8033E3F0(6, 1) < 0)
        return;
    
    sp1A = func_8033E8D0();
    sp1B = func_8033E93C();
    sp1C = func_8033E960();
    sp1C[0] = arg2;
    sp1C[1] = (arg3 - sp1C[0])/20.0f;
    func_8033FEC8(sp1A, arg0);
    func_80344D94(sp1B, arg0);
    func_80344E3C(sp1B, arg1);
    func_80356020(sp1A, sp1C);
}

void func_8035611C(void){
    u8 temp_s0;
    struct54s *sp58;
    u8 sp57;
    f32 *sp54;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    temp_s0 = (u8)func_8033E8D0();
    sp58 = func_8033E8F4();
    sp57 = func_8033E93C();
    sp54 = func_8033E960();
    player_getPosition(sp44);
    sp54[0] = 10.0f;
    sp54[1] = 8.0f;
    sp54[2] = 255.0f;
    sp54[3] = -6.0f;
    func_8033FBC8(temp_s0, ASSET_70D_SPRITE_SMOKE_1);
    func_8033FCD8(temp_s0, 5);

    func_8033FC60(temp_s0, (s32)(randf()*30.0f + 60.0f) ,(s32)(randf()*20.0f + 210.0f), (s32)(randf()*30.0f + 140.0f));
    func_8033FEC8(temp_s0, sp44);
    sp2C[0] = 0.0f;
    sp2C[1] = 0.0f;
    sp2C[2] = randf()*D_803794E0;
    func_8033FD98(temp_s0, sp2C);
    func_80287E9C(sp58);
    func_80287F7C(sp58, 1);
    func_80287F50(sp58, &D_80372700, 0x28);
    func_80287F10(sp58);

    sp38[0] = 0.0f;
    sp38[1] = 40.0f;
    sp38[2] = 0.0f;
    func_80344E18(sp57, 2);
    func_80344E3C(sp57, sp38);
    func_80344D94(sp57, sp44);
    func_80356020(temp_s0, sp54);
}

void func_803562E8(void){
    f32 *sp24;
    struct54s *sp20;
    u8 sp1F;
    
    sp24 = func_8033E960();
    sp20 = func_8033E8F4();
    sp1F = func_8033E8D0();
    if(func_80288034(sp20)){
        func_8033E984();
    }
    else{
        sp24[0] += sp24[1];
        sp24[2] += sp24[3];
        func_80356020(sp1F, sp24);
    }
}

void func_80356364(void){}
