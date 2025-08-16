#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/commonParticle.h"
#include "core2/anim/sprite.h"

extern f32 player_getYaw(void);
extern void projectile_getPosition(u8 arg0, f32 arg1[3]);
extern void func_8033FC98(u8 arg0, s32 arg1);
extern f32 *bundle_getVelocity(Actor *actor);

/* .data */
u8 D_803726C0[] = { 0,   1,   1,  1,  2,  1,  3,  1, 4,   1,  5,  1,  6,  1,  7,  1,  8,  1,  9,  1};
u8 D_803726D4[] = {10, 10,  15,  20, 25, 30, 35, 40, 45, 50, 54, 58, 62, 66, 70, 74, 76, 78, 80, 40, 20};
f32 D_803726EC = 0.0f;

/* .bss */
void func_80354670(u8 arg0, s32 arg1) {
    func_8033FFE4(arg0, D_803726D4[arg1], D_803726D4[arg1]);
    func_8033FC34(arg0, ml_map_f(arg1, 0.0f, 8.0f, 40.0f, 255.0f));
}

void func_803546E8(void) {
    u8 projectile_indx;
    AnimSprite* sp48;
    u8 sp47;
    CommonParticle* temp_s0;
    f32 plyr_pos[3];
    f32 sp28[3];

    projectile_indx = commonParticle_getCurrentProjectileIndex();
    sp48 = commonParticle_getCurrentAnimSprite();
    sp47 = func_8033E93C();
    temp_s0 = commonParticle_getCurrentParticle();
    player_getPosition(plyr_pos);

    temp_s0->unk0 = randf2(-10.0f, 10.0f);
    temp_s0->unk4 = (randf() * 35.0f) + 50.0f;
    temp_s0->unk8 = randf2(-10.0f, 10.0f);
    func_802589E4(sp28, player_getYaw(), 48.0f);
    sp28[1] = 0.0f;
    temp_s0->unk0 += sp28[0];
    temp_s0->unk4 += sp28[1];
    temp_s0->unk8 += sp28[2];
    projectile_setSprite(projectile_indx, ASSET_713_SPRITE_SPARKLE_YELLOW);
    projectile_setPosition(projectile_indx, plyr_pos);
    func_8033FCD8(projectile_indx, 0xC);
    animsprite_default(sp48);
    animsprite_set_state(sp48, ANIM_SPRITE_STATE_STOPPED);
    func_80344E18(sp47, 5);
    func_80344EE4(sp47, -700.0f, -22000.0f);
    func_802589E4(sp28, D_803726EC, 250.0f);
    sp28[1] = 250.0f;
    D_803726EC = mlNormalizeAngle(D_803726EC + 45.0);
    func_80344E3C(sp47, sp28);
    func_80344D94(sp47, plyr_pos);
    temp_s0->unk20 = 0x14;
    func_80354670(projectile_indx, 0x14);
}

void func_8035489C(void) {
    CommonParticle* temp_s0;
    u8 projectile_indx;
    f32 playerVelocity[3];
    f32 playerPosition[3];

    temp_s0 = commonParticle_getCurrentParticle();
    projectile_indx = commonParticle_getCurrentProjectileIndex();
    projectile_addRoll(projectile_indx, 7.0f);
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        commonParticle_setCurrentInUseFalse();
        return;
    }
    func_80354670(projectile_indx, temp_s0->unk20);
    if (temp_s0->unk20 >= 0x10) {
        player_getPosition(playerPosition);
        player_getVelocity(playerVelocity);
        playerVelocity[1] = 0.0f;
        playerPosition[0] += playerVelocity[0] * time_getDelta();
        playerPosition[2] += playerVelocity[2] * time_getDelta();
        playerPosition[0] += temp_s0->unk0;
        playerPosition[1] += temp_s0->unk4;
        playerPosition[2] += temp_s0->unk8;
        projectile_setPosition(projectile_indx, playerPosition);
    }
}

void func_80354990(void){}

void jiggyShine_init(void) {
    u8 sp57;
    ActorMarker *sp50;
    AnimSprite *sp4C;
    u8 sp4B;
    CommonParticle *temp_s0;
    f32 sp38[3];
    f32 sp2C[3];
    s32 sp28;

    sp57 = commonParticle_getCurrentProjectileIndex();
    sp50 = commonParticle_getCurrentActorMarker();
    sp4C = commonParticle_getCurrentAnimSprite();
    sp4B = func_8033E93C();
    temp_s0 = commonParticle_getCurrentParticle();
    ml_vec3f_clear(sp38);
    (&temp_s0->unk0)[0] = randf2(-2.0f, 2.0f);
    (&temp_s0->unk0)[1] = 0.0f;
    randf2(-10.0f, 10.0f);
    (&temp_s0->unk0)[2] = randf2(-2.0f, 2.0f);
    (&temp_s0->unkC)[0] = 0.0f;
    (&temp_s0->unkC)[1] = -0.05f;
    (&temp_s0->unkC)[2] = 0.0f;
    animsprite_default(sp4C);
    animsprite_set_speed(sp4C, 3.0f);
    animsprite_set_state(sp4C, ANIM_SPRITE_STATE_STOPPED);

    switch (sp50->modelId) {                        /* irregular */
        case 0x3BB:
            sp28 = 7;
            break;
        case 0x3BC:
            sp28 = 0xB;
            break;
        case 0x3C0:
        case 0x551:
            sp28 = 8;
            break;
        case 0x3C1:
            sp28 = 0xA;
            break;
        case 0x3C2:
            sp28 = 9;
            break;
        case 0x548:
            sp28 = 5;
            ml_vec3f_clear(&temp_s0->unk0);
            ml_vec3f_clear(&temp_s0->unkC);
            break;
        case 0x549:
            sp28 = 3;
            ml_vec3f_clear(&temp_s0->unk0);
            ml_vec3f_clear(&temp_s0->unkC);
            break;
        case 0x547:
            sp28 = 1;
            ml_vec3f_clear(&temp_s0->unk0);
            ml_vec3f_clear(&temp_s0->unkC);
            break;
        default:
            sp28 = 3;
            ml_vec3f_clear(&temp_s0->unk0);
            ml_vec3f_clear(&temp_s0->unkC);
            break;
    }

    projectile_setSprite(sp57, sp28 + 0x710);
    projectile_setPosition(sp57, sp38);
    func_80344E18(sp4B, 3);
    sp2C[0] = 0.0f;
    sp2C[1] = 0.0f;
    sp2C[2] = 0.0f;
    func_80344E3C(sp4B, sp2C);
    func_80344D94(sp4B, sp38);
    temp_s0->unk20 = 0x14;
    func_80354670(sp57, 0x14);
}

void jiggyShine_update(void) {
    CommonParticle* particle;
    s32 pad;
    ActorMarker *sp4C;
    u8 sp4B;
    FuncUnk40 sp44;
    s32 sp40;
    f32 sp34[3];
    f32 sp28[3];
    u8 projectile_indx;

    particle = commonParticle_getCurrentParticle();
    projectile_indx = commonParticle_getCurrentProjectileIndex();
    sp4C = commonParticle_getCurrentActorMarker();
    sp4B = func_8033E93C();
    sp44 = func_8033E888();
    sp40 = func_8033E8AC();
    projectile_addRoll(projectile_indx, 7.0f);
    particle->unk20--;

    if (particle->unk20 < 0) {
        commonParticle_setCurrentInUseFalse();
    } else {
        func_80354670(projectile_indx, particle->unk20);

        if (particle->unk20 >= 0x10) {
            if (sp44(sp4C, sp40, sp34) != 0) {
                func_8033FC98(projectile_indx, 0);
            } else {
                func_8033FC98(projectile_indx, 1);
            }
        } else {
            projectile_getPosition(projectile_indx, sp34);
        }

        func_80344E7C(sp4B, sp28);
        sp28[0] += (&particle->unkC)[0];
        sp28[1] += (&particle->unkC)[1];
        sp28[2] += (&particle->unkC)[2];
        func_80344E3C(sp4B, sp28);
        (&particle->unk0)[0] += sp28[0];
        (&particle->unk0)[1] += sp28[1];
        (&particle->unk0)[2] += sp28[2];
        sp34[0] += (&particle->unk0)[0];
        sp34[1] += (&particle->unk0)[1];
        sp34[2] += (&particle->unk0)[2];
        projectile_setPosition(projectile_indx, sp34);
    }

    func_8033FC34(projectile_indx, 0xB4);
    func_8033FCD8(projectile_indx, 0xC);
}

void jiggyShine_free(void) { }

void func_80354DD0(void) {
    CommonParticle* temp_s0;
    AnimSprite* sp40;
    u8 sp3F;
    u8 pad3C[3];
    u8 projectile_indx;
    f32 sp2C[3];
    f32 sp20[3];

    projectile_indx = commonParticle_getCurrentProjectileIndex();
    sp40 = commonParticle_getCurrentAnimSprite();
    sp3F = func_8033E93C();
    temp_s0 = commonParticle_getCurrentParticle();
    ml_vec3f_clear(sp2C);
    (&temp_s0->unk0)[0] = randf2(-50.0f, 50.0f);
    (&temp_s0->unk0)[1] = randf2(-65.0f, -65.0f);
    (&temp_s0->unk0)[2] = randf2(-50.0f, 50.0f);
    projectile_setSprite(projectile_indx, ASSET_710_SPRITE_SPARKLE_PURPLE);
    projectile_setColor(projectile_indx, 0xE1, 0xFF, 0);
    projectile_setPosition(projectile_indx, sp2C);
    animsprite_default(sp40);
    animsprite_set_state(sp40, ANIM_SPRITE_STATE_STOPPED);
    func_80344E18(sp3F, 3);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    func_80344E3C(sp3F, sp20);
    func_80344D94(sp3F, sp2C);
    temp_s0->unk20 = 0x14;
    func_80354670(projectile_indx, 0x14);
}

void func_80354EEC(void) {
    CommonParticle* temp_s0;
    s32 pad;
    ActorMarker *sp3C;
    FuncUnk40 sp38;
    s32 sp34;
    f32 sp28[3];
    u8 temp_s1;

    temp_s0 = commonParticle_getCurrentParticle();
    temp_s1 = commonParticle_getCurrentProjectileIndex();
    sp3C = commonParticle_getCurrentActorMarker();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        commonParticle_setCurrentInUseFalse();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x10) {
            if (sp38(sp3C, sp34, sp28) != 0) {
                func_8033FC98(temp_s1, 0);
            } else {
                func_8033FC98(temp_s1, 1);
            }
            sp28[0] += (&temp_s0->unk0)[0];
            sp28[1] += (&temp_s0->unk0)[1];
            sp28[2] += (&temp_s0->unk0)[2];
            projectile_setPosition(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xBE);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80355004(void){}

void func_8035500C(void) {
    u8 projectile_indx;
    AnimSprite* sp40;
    u8 sp3F;
    CommonParticle* temp_s0;
    f32 sp2C[3];
    f32 sp20[3];

    projectile_indx = commonParticle_getCurrentProjectileIndex();
    sp40 = commonParticle_getCurrentAnimSprite();
    sp3F = func_8033E93C();
    temp_s0 = commonParticle_getCurrentParticle();
    ml_vec3f_clear(sp2C);
    (&temp_s0->unk0)[0] = randf2(-40.0f, 40.0f);
    (&temp_s0->unk0)[1] = randf2(-40.0f, 40.0f);
    (&temp_s0->unk0)[2] = randf2(-40.0f, 40.0f);
    projectile_setSprite(projectile_indx, 0x70F);
    projectile_setColor(projectile_indx, 0xFF, 0xE6, 0xF5);
    projectile_setPosition(projectile_indx, sp2C);
    animsprite_default(sp40);
    animsprite_set_state(sp40, ANIM_SPRITE_STATE_STOPPED);
    animsprite_set_frame(sp40, 0); //set frame
    func_80344E18(sp3F, 3);
    sp20[0] = 0.0f;
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    func_80344E3C(sp3F, sp20);
    func_80344D94(sp3F, sp2C);
    temp_s0->unk20 = 0x14;
    func_80354670(projectile_indx, 0x14);
}

void func_80355134(void) {
    CommonParticle* temp_s0;
    u8 temp_s1;
    ActorMarker *sp3C;
    FuncUnk40 sp38;
    s32 sp34;
    f32 sp28[3];

    temp_s0 = commonParticle_getCurrentParticle();
    temp_s1 = commonParticle_getCurrentProjectileIndex();
    sp3C = commonParticle_getCurrentActorMarker();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    if ((globalTimer_getTime() & 1) == 0) {
        temp_s0->unk20--;
    }
    if (temp_s0->unk20 < 0) {
        commonParticle_setCurrentInUseFalse();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x13) {
            sp38(sp3C, sp34, sp28);
            (&temp_s0->unk0)[1] -= time_getDelta() * 200.0f;
            sp28[0] += (&temp_s0->unk0)[0];
            sp28[1] += (&temp_s0->unk0)[1];
            sp28[2] += (&temp_s0->unk0)[2];
            projectile_setPosition(temp_s1, sp28);
        } else {
            projectile_getPosition(temp_s1, sp28);
            sp28[1] -= time_getDelta() * 200.0f;
            projectile_setPosition(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xFF);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80355294(void){}

void func_8035529C(void) {
    u8 projectile_indx;
    AnimSprite* sp48;
    u8 sp47;
    CommonParticle* sp40;
    f32 sp34[3];
    f32 sp28[3];

    projectile_indx = commonParticle_getCurrentProjectileIndex();
    sp48 = commonParticle_getCurrentAnimSprite();
    sp47 = func_8033E93C();
    sp40 = commonParticle_getCurrentParticle();
    ml_vec3f_clear(sp34);
    (&sp40->unk0)[0] = randf2(-40.0f, 40.0f);
    (&sp40->unk0)[1] = 0.0f;
    (&sp40->unk0)[2] = randf2(-40.0f, 40.0f);
    projectile_setSprite(projectile_indx, 0x70F);
    projectile_setColor(projectile_indx, randi2(0xD2, 0xFF), randi2(0xBE, 0xFF), randi2(0xC8, 0xFF));
    projectile_setPosition(projectile_indx, sp34);
    animsprite_default(sp48);
    animsprite_set_state(sp48, ANIM_SPRITE_STATE_STOPPED);
    animsprite_set_frame(sp48, 0);
    func_80344E18(sp47, 3);
    sp28[0] = 0.0f;
    sp28[1] = 0.0f;
    sp28[2] = 0.0f;
    func_80344E3C(sp47, sp28);
    func_80344D94(sp47, sp34);
    sp40->unk20 = 0xE;
    func_80354670(projectile_indx, 0xE);
}

void func_803553E8(void) {
    CommonParticle* temp_s0;
    u8 temp_s1;
    ActorMarker *sp3C;
    FuncUnk40 sp38;
    s32 sp34;
    f32 sp28[3];

    temp_s0 = commonParticle_getCurrentParticle();
    temp_s1 = commonParticle_getCurrentProjectileIndex();
    sp3C = commonParticle_getCurrentActorMarker();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    if ((globalTimer_getTime() & 1) == 0) {
        temp_s0->unk20--;
    }
    if (temp_s0->unk20 < 0) {
        commonParticle_setCurrentInUseFalse();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0xD) {
            sp38(sp3C, sp34, sp28);
            (&temp_s0->unk0)[1] -= time_getDelta() * 40.0f;
            sp28[0] += (&temp_s0->unk0)[0];
            sp28[1] += (&temp_s0->unk0)[1];
            sp28[2] += (&temp_s0->unk0)[2];
            projectile_setPosition(temp_s1, sp28);
        } else {
            projectile_getPosition(temp_s1, sp28);
            sp28[1] -= time_getDelta() * 40.0f;
            projectile_setPosition(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xFF);
    func_8033FCD8(temp_s1, 0xC);
}

void func_80355548(void){}

void func_80355550(void) {
    static s32 D_803863E0;
    u8 projectile_indx;
    AnimSprite *sp38;
    u8 sp37;
    CommonParticle *sp30;
    f32 sp24[3];
    f32 sp18[3];

    projectile_indx = commonParticle_getCurrentProjectileIndex();
    sp38 = commonParticle_getCurrentAnimSprite();
    sp37 = func_8033E93C();
    sp30 = commonParticle_getCurrentParticle();
    ml_vec3f_clear(sp24);
    (&sp30->unk0)[0] = randf2(-30.0f, 30.0f);
    (&sp30->unk0)[1] = randf2(-30.0f, 30.0f);
    (&sp30->unk0)[2] = randf2(-30.0f, 30.0f);
    if ((f64) randf() < 0.25) {
        projectile_setSprite(projectile_indx, ASSET_711_SPRITE_SPARKLE_DARK_BLUE);
    } else if ((f64) randf() < 0.5) {
        projectile_setSprite(projectile_indx, ASSET_716_SPRITE_SPARKLE_WHITE);
    } else {
        projectile_setSprite(projectile_indx, ASSET_710_SPRITE_SPARKLE_PURPLE);
    }
    projectile_setColor(projectile_indx, 0xFF, 0xFF, 0xFF);
    projectile_setPosition(projectile_indx, sp24);
    animsprite_default(sp38);
    animsprite_set_state(sp38, ANIM_SPRITE_STATE_STOPPED);
    animsprite_set_frame(sp38, 0);
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
    func_80354670(projectile_indx, 0x14);
}

void func_8035570C(void) {
    CommonParticle* temp_s0;
    u8 temp_s1;
    ActorMarker *sp3C;
    FuncUnk40 sp38;
    s32 sp34;
    f32 sp28[3];

    temp_s0 = commonParticle_getCurrentParticle();
    temp_s1 = commonParticle_getCurrentProjectileIndex();
    sp3C = commonParticle_getCurrentActorMarker();
    sp38 = func_8033E888();
    sp34 = func_8033E8AC();
    temp_s0->unk20--;
    if (temp_s0->unk20 < 0) {
        commonParticle_setCurrentInUseFalse();
    } else {
        func_80354670(temp_s1, temp_s0->unk20);
        if (temp_s0->unk20 >= 0x13) {
            sp38(sp3C, sp34, sp28);
            (&temp_s0->unk0)[1] -= time_getDelta() * 80.0f;
            sp28[0] += (&temp_s0->unk0)[0];
            sp28[1] += (&temp_s0->unk0)[1];
            sp28[2] += (&temp_s0->unk0)[2];
            projectile_setPosition(temp_s1, sp28);
        } else {
            projectile_getPosition(temp_s1, sp28);
            sp28[1] -= time_getDelta() * 200.0f;
            projectile_setPosition(temp_s1, sp28);
        }
    }
    func_8033FC34(temp_s1, 0xFF);
    func_8033FCD8(temp_s1, 0xC);
}

void func_8035585C(void){}

void func_80355864(void) {
    u8 sp5F;
    AnimSprite *sp58;
    u8 sp57;
    static s32 D_803863E4;
    f32 var_f2;
    Actor *sp4C;
    CommonParticle *sp48;
    s32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;

    sp5F = commonParticle_getCurrentProjectileIndex();
    sp58 = commonParticle_getCurrentAnimSprite();
    sp57 = func_8033E93C();
    sp4C = marker_getActor(commonParticle_getCurrentActorMarker());
    sp48 = commonParticle_getCurrentParticle();
    D_803863E4 = (D_803863E4 + 1) % 10;
    sp44 = (D_803863E4 == 0);
    sp38[0] = sp4C->position[0];
    sp38[1] = sp4C->position[1];
    sp38[2] = sp4C->position[2];
    (&sp48->unk0)[0] = randf2(-10.0f, 10.0f);
    (&sp48->unk0)[1] = (f32) ((randf() * 45.0f) + 10.0f);
    (&sp48->unk0)[2] = randf2(-10.0f, 10.0f);
    projectile_setSprite(sp5F, 0x713);
    projectile_setPosition(sp5F, sp38);
    func_8033FCD8(sp5F, 0xC);
    animsprite_default(sp58);
    animsprite_set_state(sp58, ANIM_SPRITE_STATE_STOPPED);
    animsprite_set_speed(sp58, (sp44)? 16.0 : 3.0);
    func_80344E18(sp57, 5);
    func_80344EE4(sp57, -700.0f, -22000.0f);
    sp28 = (sp44) ? randf2(-75.0f, 75.0f) + 400.0f
         : randf2(-50.0f, 50.0f) + 250.0f;

    func_802589E4(sp2C, D_803726EC, sp28);
    sp2C[1] = sp28 * ((sp44 * 0.5) + 1.0);
    D_803726EC = mlNormalizeAngle(D_803726EC + 45.0);
    func_80344E3C(sp57, sp2C);
    func_80344D94(sp57, sp38);
    sp48->unk20 = 0x14;
    sp48->unk24 = sp44;
    sp48->unk28 = 1;
    func_80354670(sp5F, 0x14);
}

void func_80355B00(void) {
    CommonParticle *sp44;
    u8 projectile_indx;
    ActorMarker *pad40;
    Actor *sp38;
    f32 *sp34;
    f32 sp28[3];

    sp44 = commonParticle_getCurrentParticle();
    projectile_indx = commonParticle_getCurrentProjectileIndex();
    pad40 = commonParticle_getCurrentActorMarker();
    sp38 = marker_getActor(pad40);
    sp34 = bundle_getVelocity(sp38);
    projectile_addRoll(projectile_indx, 7.0f);
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
        commonParticle_setCurrentInUseFalse();
        return;
    }
    func_80354670(projectile_indx, sp44->unk20);
    if (sp44->unk20 >= 0x10) {
        sp28[0] += sp34[0] * time_getDelta();
        sp28[2] += sp34[2] * time_getDelta();

        sp28[0] += (&sp44->unk0)[0];
        sp28[1] += (&sp44->unk0)[1];
        sp28[2] += (&sp44->unk0)[2];
        projectile_setPosition(projectile_indx, sp28);
    }
}

void func_80355C4C(void){}
