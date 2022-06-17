#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern u8 D_803726D4[];

void func_80354380(f32 *arg0, f32 arg1) {
    u8 sp1F;
    u8 sp1E;
    ParticleStruct0s* sp18;

    if (func_8033E3F0(0xE, 1) >= 0) {
        sp1E = func_8033E8D0();
        sp1F = func_8033E93C();
        sp18 = func_8033E960();
        func_8033FEC8(sp1E, arg0);
        func_80344D94(sp1F, arg0);
        sp18->unk4 = arg1;
    }
}

void func_803543F4(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_803543FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_8035451C.s")

void func_80354670(u8 arg0, s32 arg1) {
    func_8033FFE4(arg0, D_803726D4[arg1], D_803726D4[arg1]);
    func_8033FC34(arg0, ml_map_f(arg1, 0.0f, 8.0f, 40.0f, 255.0f));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_803546E8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80354998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80354C18.s")

void func_80354DC8(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80354DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80354EEC.s")

void func_80355004(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_8035500C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80355134.s")

void func_80355294(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_8035529C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_803553E8.s")

void func_80355548(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80355550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_8035570C.s")

void func_8035585C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CD3F0/func_80355864.s")

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
