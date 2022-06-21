#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern f32 func_8028EBA4(void);
extern void func_8033FF10(u8 arg0, f32 arg1[3]);
extern void func_8033FC98(u8 arg0, s32 arg1);

extern u8 D_803726D4[];
extern f32 D_803726EC;
extern f64 D_80379480;

void func_80354670(u8 arg0, s32 arg1) {
    func_8033FFE4(arg0, D_803726D4[arg1], D_803726D4[arg1]);
    func_8033FC34(arg0, ml_map_f(arg1, 0.0f, 8.0f, 40.0f, 255.0f));
}

void func_803546E8(void) {
    u8 sp4F;
    struct54s* sp48;
    u8 sp47;
    ParticleStruct0s* temp_s0;
    f32 sp34[3];
    f32 sp28[3];

    sp4F = func_8033E8D0();
    sp48 = func_8033E8F4();
    sp47 = func_8033E93C();
    temp_s0 = func_8033E960();
    player_getPosition(sp34);
    temp_s0->unk0 = randf2(-10.0f, 10.0f);
    temp_s0->unk4 = (randf() * 35.0f) + 50.0f;
    temp_s0->unk8 = randf2(-10.0f, 10.0f);
    func_802589E4(sp28, func_8028EBA4(), 48.0f);
    sp28[1] = 0.0f;
    temp_s0->unk0 += sp28[0];
    temp_s0->unk4 += sp28[1];
    temp_s0->unk8 += sp28[2];
    func_8033FBC8(sp4F, ASSET_713_SPRITE_SPARKLE_YELLOW);
    func_8033FEC8(sp4F, sp34);
    func_8033FCD8(sp4F, 0xC);
    func_80287E9C(sp48);
    func_80287F7C(sp48, 3);
    func_80344E18(sp47, 5);
    func_80344EE4(sp47, -700.0f, -22000.0f);
    func_802589E4(sp28, D_803726EC, 250.0f);
    sp28[1] = 250.0f;
    D_803726EC = mlNormalizeAngle((f32) ((f64) D_803726EC + D_80379480));
    func_80344E3C(sp47, sp28);
    func_80344D94(sp47, sp34);
    temp_s0->unk20 = 0x14;
    func_80354670(sp4F, 0x14);
}

void func_8035489C(void) {
    ParticleStruct0s* temp_s0;
    u8 temp_v0;
    f32 playerVelocity[3];
    f32 playerPosition[3];

    temp_s0 = func_8033E960();
    temp_v0 = func_8033E8D0();
    func_8033FE2C(temp_v0, 7.0f);
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        func_8033E984();
        return;
    }
    func_80354670(temp_v0, temp_s0->unk20);
    if (temp_s0->unk20 >= 0x10) {
        player_getPosition(playerPosition);
        player_getVelocity(playerVelocity);
        playerVelocity[1] = 0.0f;
        playerPosition[0] += playerVelocity[0] * time_getDelta();
        playerPosition[2] += playerVelocity[2] * time_getDelta();
        playerPosition[0] += temp_s0->unk0;
        playerPosition[1] += temp_s0->unk4;
        playerPosition[2] += temp_s0->unk8;
        func_8033FEC8(temp_v0, playerPosition);
    }
}

void func_80354990(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD6E0/func_80354998.s")

void func_80354C18(void) {
    ParticleStruct0s* temp_s0;
    s32 pad;
    s32 sp4C;
    u8 sp4B;
    s32 sp44;
    s32 sp40;
    f32 sp34[3];
    f32 sp28[3];
    u8 temp_s1;

    temp_s0 = func_8033E960();
    temp_s1 = func_8033E8D0();
    sp4C = func_8033E864();
    sp4B = func_8033E93C();
    sp44 = func_8033E888();
    sp40 = func_8033E8AC();
    func_8033FE2C(temp_s1, 7.0f);
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        func_8033E984();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x10) {
            if (((s32 (*)(s32, s32, f32*)) sp44)(sp4C, sp40, sp34) != 0) {
                func_8033FC98(temp_s1, 0);
            } else {
                func_8033FC98(temp_s1, 1);
            }
        } else {
            func_8033FF10(temp_s1, sp34);
        }
        func_80344E7C(sp4B, sp28);
        sp28[0] += temp_s0->unkC;
        sp28[1] += temp_s0->unk10;
        sp28[2] += temp_s0->unk14;
        func_80344E3C(sp4B, sp28);
        temp_s0->unk0 += sp28[0];
        temp_s0->unk4 += sp28[1];
        temp_s0->unk8 += sp28[2];
        sp34[0] += temp_s0->unk0;
        sp34[1] += temp_s0->unk4;
        sp34[2] += temp_s0->unk8;
        func_8033FEC8(temp_s1, sp34);
    }
    func_8033FC34(temp_s1, 0xB4);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80354DC8(void){}

void func_80354DD0(void) {
    ParticleStruct0s* temp_s0;
    struct54s* sp40;
    u8 sp3F;
    u8 pad3C[3];
    u8 temp_s1;
    f32 sp2C[3];
    f32 sp20[3];

    temp_s1 = func_8033E8D0();
    sp40 = func_8033E8F4();
    sp3F = func_8033E93C();
    temp_s0 = func_8033E960();
    ml_vec3f_clear(sp2C);
    temp_s0->unk0 = randf2(-50.0f, 50.0f);
    temp_s0->unk4 = randf2(-65.0f, -65.0f);
    temp_s0->unk8 = randf2(-50.0f, 50.0f);
    func_8033FBC8(temp_s1, ASSET_710_SPRITE_SPARKLE_PURPLE);
    func_8033FC60(temp_s1, 0xE1, 0xFF, 0);
    func_8033FEC8(temp_s1, sp2C);
    func_80287E9C(sp40);
    func_80287F7C(sp40, 3);
    func_80344E18(sp3F, 3);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    func_80344E3C(sp3F, sp20);
    func_80344D94(sp3F, sp2C);
    temp_s0->unk20 = 0x14;
    func_80354670(temp_s1, 0x14);
}

void func_80354EEC(void) {
    ParticleStruct0s* temp_s0;
    s32 pad;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 sp28[3];
    u8 temp_s1;

    temp_s0 = func_8033E960();
    temp_s1 = func_8033E8D0();
    sp3C = func_8033E864();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        func_8033E984();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x10) {
            if (((s32 (*)(s32, s32, f32*)) sp38)(sp3C, sp34, sp28) != 0) {
                func_8033FC98(temp_s1, 0);
            } else {
                func_8033FC98(temp_s1, 1);
            }
            sp28[0] += temp_s0->unk0;
            sp28[1] += temp_s0->unk4;
            sp28[2] += temp_s0->unk8;
            func_8033FEC8(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xBE);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80355004(void){}

void func_8035500C(void) {
    u8 sp47;
    struct54s* sp40;
    u8 sp3F;
    ParticleStruct0s* temp_s0;
    f32 sp2C[3];
    f32 sp20[3];

    sp47 = func_8033E8D0();
    sp40 = func_8033E8F4();
    sp3F = func_8033E93C();
    temp_s0 = func_8033E960();
    ml_vec3f_clear(sp2C);
    temp_s0->unk0 = randf2(-40.0f, 40.0f);
    temp_s0->unk4 = randf2(-40.0f, 40.0f);
    temp_s0->unk8 = randf2(-40.0f, 40.0f);
    func_8033FBC8(sp47, 0x70F);
    func_8033FC60(sp47, 0xFF, 0xE6, 0xF5);
    func_8033FEC8(sp47, sp2C);
    func_80287E9C(sp40);
    func_80287F7C(sp40, 3);
    func_80287FB4(sp40, 0);
    func_80344E18(sp3F, 3);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    func_80344E3C(sp3F, sp20);
    func_80344D94(sp3F, sp2C);
    temp_s0->unk20 = 0x14;
    func_80354670(sp47, 0x14);
}

void func_80355134(void) {
    ParticleStruct0s* temp_s0;
    u8 temp_s1;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 sp28[3];

    temp_s0 = func_8033E960();
    temp_s1 = func_8033E8D0();
    sp3C = func_8033E864();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    if ((func_8023DB5C() & 1) == 0) {
        temp_s0->unk20--;
    }
    if (temp_s0->unk20 < 0) {
        func_8033E984();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x13) {
            ((s32 (*)(s32, s32, f32*)) sp38)(sp3C, sp34, sp28);
            temp_s0->unk4 -= time_getDelta() * 200.0f;
            sp28[0] += temp_s0->unk0;
            sp28[1] += temp_s0->unk4;
            sp28[2] += temp_s0->unk8;
            func_8033FEC8(temp_s1, sp28);
        } else {
            func_8033FF10(temp_s1, sp28);
            sp28[1] -= time_getDelta() * 200.0f;
            func_8033FEC8(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xFF);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80355294(void){}

void func_8035529C(void) {
    u8 sp4F;
    struct54s* sp48;
    u8 sp47;
    ParticleStruct0s* sp40;
    f32 sp34[3];
    f32 sp28[3];

    sp4F = func_8033E8D0();
    sp48 = func_8033E8F4();
    sp47 = func_8033E93C();
    sp40 = func_8033E960();
    ml_vec3f_clear(sp34);
    sp40->unk0 = randf2(-40.0f, 40.0f);
    sp40->unk4 = 0.0f;
    sp40->unk8 = randf2(-40.0f, 40.0f);
    func_8033FBC8(sp4F, 0x70F);
    func_8033FC60(sp4F, randi2(0xD2, 0xFF), randi2(0xBE, 0xFF), randi2(0xC8, 0xFF));
    func_8033FEC8(sp4F, sp34);
    func_80287E9C(sp48);
    func_80287F7C(sp48, 3);
    func_80287FB4(sp48, 0);
    func_80344E18(sp47, 3);
    sp28[0] = 0.0f;
    sp28[1] = 0.0f;
    sp28[2] = 0.0f;
    func_80344E3C(sp47, sp28);
    func_80344D94(sp47, sp34);
    sp40->unk20 = 0xE;
    func_80354670(sp4F, 0xE);
}

void func_803553E8(void) {
    ParticleStruct0s* temp_s0;
    u8 temp_s1;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 sp28[3];

    temp_s0 = func_8033E960();
    temp_s1 = func_8033E8D0();
    sp3C = func_8033E864();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    if ((func_8023DB5C() & 1) == 0) {
        temp_s0->unk20--;
    }
    if (temp_s0->unk20 < 0) {
        func_8033E984();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0xD) {
            ((s32 (*)(s32, s32, f32*)) sp38)(sp3C, sp34, sp28);
            temp_s0->unk4 -= time_getDelta() * 40.0f;
            sp28[0] += temp_s0->unk0;
            sp28[1] += temp_s0->unk4;
            sp28[2] += temp_s0->unk8;
            func_8033FEC8(temp_s1, sp28);
        } else {
            func_8033FF10(temp_s1, sp28);
            sp28[1] -= time_getDelta() * 40.0f;
            func_8033FEC8(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xFF);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80355548(void){}

//Static var not defined properly
#ifdef NON_MATCHING
void func_80355550(void) {
    static s32 D_803863E0;
    u8 sp3F;
    struct54s *sp38;
    u8 sp37;
    ParticleStruct0s *sp30;
    f32 sp24[3];
    f32 sp18[3];

    sp3F = func_8033E8D0();
    sp38 = func_8033E8F4();
    sp37 = func_8033E93C();
    sp30 = func_8033E960();
    ml_vec3f_clear(sp24);
    sp30->unk0 = randf2(-30.0f, 30.0f);
    sp30->unk4 = randf2(-30.0f, 30.0f);
    sp30->unk8 = randf2(-30.0f, 30.0f);
    if ((f64) randf() < 0.25) {
        func_8033FBC8(sp3F, ASSET_711_SPRITE_SPARKLE_DARK_BLUE);
    } else if ((f64) randf() < 0.5) {
        func_8033FBC8(sp3F, ASSET_716_SPRITE_SPARKLE_WHITE);
    } else {
        func_8033FBC8(sp3F, ASSET_710_SPRITE_SPARKLE_PURPLE);
    }
    func_8033FC60(sp3F, 0xFF, 0xFF, 0xFF);
    func_8033FEC8(sp3F, sp24);
    func_80287E9C(sp38);
    func_80287F7C(sp38, 3);
    func_80287FB4(sp38, 0);
    if (D_803863E0 >= 4) {
        D_803863E0 = 0;
    }
    func_80344E18(sp37, 3);
    sp18[0] = 0.0f;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    func_80344E3C(sp37, sp18);
    func_80344D94(sp37, sp24);
    sp30->unk20 = 0x14;
    func_80354670(sp3F, 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD6E0/func_80355550.s")
#endif

void func_8035570C(void) {
    ParticleStruct0s* temp_s0;
    u8 temp_s1;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 sp28[3];

    temp_s0 = func_8033E960();
    temp_s1 = func_8033E8D0();
    sp3C = func_8033E864();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        func_8033E984();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x13) {
            ((s32 (*)(s32, s32, f32*)) sp38)(sp3C, sp34, sp28);
            temp_s0->unk4 -= time_getDelta() * 80.0f;
            sp28[0] += temp_s0->unk0;
            sp28[1] += temp_s0->unk4;
            sp28[2] += temp_s0->unk8;
            func_8033FEC8(temp_s1, sp28);
        } else {
            func_8033FF10(temp_s1, sp28);
            sp28[1] -= time_getDelta() * 200.0f;
            func_8033FEC8(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xFF);
    func_8033FCD8(temp_s1, 0xC);
}

void func_8035585C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD6E0/func_80355864.s")

void func_80355B00(void) {
    ParticleStruct0s *sp44;
    u8 sp43;
    ActorMarker *pad40;
    Actor *sp38;
    f32 *sp34;
    f32 sp28[3];

    sp44 = func_8033E960();
    sp43 = func_8033E8D0();
    pad40 = func_8033E864();
    sp38 = marker_getActor(pad40);
    sp34 = func_802C9C0C(sp38);
    func_8033FE2C(sp43, 7.0f);
    sp28[0] = sp38->position[0];
    sp28[1] = sp38->position[1];
    sp28[2] = sp38->position[2];
    if (sp44->unk28 > 0) {
        sp44->unk20 = (s32) (sp44->unk20 - 1);
    }
    if (sp44->unk24 != 0) {
        sp44->unk28 = (s32) -sp44->unk28;
    }

    if (sp44->unk20 < 0) {
        func_8033E984();
        return;
    }
    func_80354670(sp43, sp44->unk20);
    if (sp44->unk20 >= 0x10) {
        sp28[0] += sp34[0] * time_getDelta();
        sp28[2] += sp34[2] * time_getDelta();

        sp28[0] += sp44->unk0;
        sp28[1] += sp44->unk4;
        sp28[2] += sp44->unk8;
        func_8033FEC8(sp43, sp28);
    }
}

void func_80355C4C(void){}
