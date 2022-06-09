#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F4B8(s32, f32, f32);

void func_80386570(ActorMarker *arg0, Gfx **arg1, Mtx **arg2, s32 arg3);
void func_8038856C(Actor *actor, f32 *arg1);
void func_8038BCF0(Actor *this);
void func_80387110(ActorMarker *, f32[3], f32, s32);
void func_8025727C(f32, f32, f32, f32, f32, f32, f32*, f32*);
void func_802C8F70(f32);
s32 func_803297C8(Actor*, s32*);
Actor *func_8032813C();
void func_803900DC(ActorMarker *, f32 *, f32, f32);
extern Actor* func_80329958(ActorMarker *this, s32 arg1);
extern void func_803298D8();
void func_80324E88(f32);
extern void func_80324E60(Actor*, s32, f32);

void func_80388184(Actor *arg0, s32 arg1);
void func_8038B780();

typedef struct ch_fight_180_s{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad24[4];
    f32 unk28;
    f32 unk2C;
}ActorLocal_fight_180;

/* .data */
extern f32 D_80391380[4];
extern f32 D_80391390[4];
extern ActorAnimationInfo D_803913A0[]; /* =
{
    { 0, 0.0f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.6f},
    { 0x25C, 1.0f},
    { 0x25C, 1.0f},
    { 0x25E, 6.5f},
    { 0x25E, 6.5f},
    { 0x25A, 1.1f},
    { 0x1C5, 1.0f},
    { 0x257, 2.5f},
    { 0x259, 1.4f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x257, 2.5f},
    { 0x1C5, 0.8f},
    { 0x258, 1.0f},
    { 0x259, 1.4f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x259, 1.4f},
    { 0x267, 3.0f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x1C5, 0.8f},
    { 0x259, 1.4f},
    { 0x263, 0.5f},
    { 0x25D, 7.0f},
    { 0x25F, 1.0f},
    { 0x25F, 1.0f},
    { 0x260, 1.1f},
    { 0x261, 2.5f},
    { 0x25F, 1.0f},
    { 0x279, 3.0f},
    { 0x283, 0.25f},
    { 0x27A, 1.0f},
    { 0x266, 4.0f}
};*/

extern ActorInfo D_80391500;/* = {
    0x25E, 0x38B, 0x53D, 
    1,  D_803913A0,
    func_8038BCF0, func_80326224, func_80386570,
    { 0, 0}, 0, 0.0f, {0, 0, 0, 0}
};*/
extern f32 D_80391524[3]; //= {0.0f, -8.0f, 400.0f};
extern f32 D_80391530[3]; //= {0.0f, -8.0f, 0.0f};

//                                      3F 80 00 00
// 3F 80 00 00 3F 80 00 00  3F 80 00 00 00 00 00 00
// 3C 23 D7 0A 40 33 33 33  40 4C CC CD 3F 00 00 00
// 3F 33 33 33 C3 96 00 00  C3 96 00 00 C3 96 00 00
// 43 96 00 00 43 FA 00 00  43 96 00 00 00 00 00 00
// C4 96 00 00 00 00 00 00  00 00 00 00 C4 96 00 00
// 00 00 00 00 C2 C8 00 00  C1 A0 00 00 C2 C8 00 00
// 42 C8 00 00 42 C8 00 00  42 C8 00 00 00 00 00 24
// 00 00 00 24 00 00 00 24  C2 8C 00 00 C2 48 00 00
// C2 8C 00 00 42 8C 00 00  42 48 00 00 42 8C 00 00
// C2 C8 00 00 C1 A0 00 00  C2 C8 00 00 42 C8 00 00
// 42 C8 00 00 42 C8 00 00  3F E6 66 66 40 06 66 66
// 3F A6 66 66 3F B3 33 33  00 00 00 00 3C 23 D7 0A
// 3F 8C CC CD 3F A6 66 66  3E 19 99 9A 3E 99 99 9A
extern struct31s D_8039153C;
extern struct43s D_80391564;
extern s32 D_803915AC[3];
extern struct42s D_803915B8;
extern struct40s D_803915E8;
extern struct42s D_80391618;
extern struct40s D_80391648;
extern struct43s D_80391678;
extern s32 D_803916F4;
extern f32 D_80391700[3];
extern s32 D_8039170C;
extern f32 D_80391710[3];
extern f32 D_8039171C[3];
extern f32 D_80391728;
extern s32 D_80391738[];
extern s32 D_80391804;
extern f32 D_803920C8;
extern f32 D_803920CC;
extern f32 D_803920D0;
extern f32 D_803920D4;
extern f32 D_803920D8;
extern f32 D_803920DC;
extern f32 D_803920E0;
extern f32 D_803920E4;
extern f32 D_803920E8;
extern f32 D_803920EC;
extern f32 D_803920F0;
extern f32 D_803920F4;
extern f64 D_803920F8;
//extern f64 D_80392100; // = -500.0;
extern s32 D_80392108[6];
// s32 D_80392108[] = {
//     0x80387794, 0x803877F8,
//     0x803878FC, 0x803879A0,
//     0x80387A20, 0x80387A98
// };

/* .rodata */
extern f64 D_80392210;
// jtbl_80392218
// jtbl_80392234
// jtbl_8039224C
// jtbl_80392280
// jtbl_80392310
// jtbl_80392388
// jtbl_803923F4
// jtbl_8039242C
// jtbl_803924B8

extern f32 D_80392440;
extern f32 D_80392444;
extern f32 D_80392448;
extern f32 D_8039244C;
// jtbl_80392454

extern f64 D_80392470;
extern f32 D_80392478;



/* .bss */
extern f32 D_80392758[3];
extern f32 D_80392768[3];
extern f32 D_80392778[3];
extern f32 D_80392788[3];
extern f32 D_80392798[];
extern ActorMarker *D_803927A4;
extern ActorMarker *D_803927A8;
extern s32 D_803927B0;
extern s32 D_803927B4;
extern s32 D_803927B8;
extern s32 D_803927BC;
extern u8 D_803927C4;
extern u8 D_803927C5;
extern u8 D_803927C6;
extern u8 D_803927C7;
extern u8 D_803927C8;
extern u8 D_803927C9;
extern f32 D_803927D0[3][3];

/* .code */
void func_80386570(ActorMarker *arg0, Gfx **arg1, Mtx **arg2, s32 arg3) {
    Actor *temp_v0;
    ActorLocal_fight_180 *localActor;

    temp_v0 = marker_getActor(arg0);
    localActor = (ActorLocal_fight_180 *)&temp_v0->local;
    func_8033A45C(3, localActor->unkD);
    func_8033A45C(4, localActor->unkE);
    func_8033A45C(5, localActor->unkC);
    if (localActor->unk0 == 1) {
        func_8033A25C(0);
    }
    func_80325888(arg0, arg1, arg2, arg3);
}

void func_80386600(ActorMarker *arg0, s32 arg1) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(arg0);
    local = (ActorLocal_fight_180 *)&this->local;
    local->unkC = arg1;
}

void func_80386628(ActorMarker *arg0, s32 arg1) {
    Actor *temp_v0;
    ActorLocal_fight_180 *local;


    temp_v0 = marker_getActor(arg0);
    local = (ActorLocal_fight_180 *)&temp_v0->local;
    local->unkD = arg1;
    local->unkE = arg1;
}

void func_8034DF30(s32, s32, s32, f32);

void func_80386654(f32 arg0, f32 (*arg1)[4], f32 (*arg2)[4]) {
    s32 temp_v0;

    temp_v0 = func_8034C528(0x190);
    if (temp_v0 != 0) {
        func_8034DF30(temp_v0, arg1, arg2, arg0);
    }
}

void func_80386698(f32 arg0) {
    s32 temp_v0;

    temp_v0 = func_8034C528(0x19A);
    if (temp_v0 != 0) {
        func_8034DDF0(temp_v0, &D_80391524, &D_80391530, arg0, 1);
    }
}

void func_803866E4(f32 position[3], enum asset_e model_id, s32 n) {
    ParticleEmitter *temp_s0;

    temp_s0 = partEmitList_pushNew(n);
    particleEmitter_setModel(temp_s0, model_id);
    particleEmitter_setPosition(temp_s0, position);
    func_802EFE24(temp_s0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_80391564);
    func_802EFB98(temp_s0, &D_8039153C);
    func_802EFA78(temp_s0, 1);
    particleEmitter_emitN(temp_s0, n);
}

void func_8038679C(f32 (*arg0)[3], s32 arg1, f32 (*arg2)[4]) {
    ParticleEmitter *temp_s0;
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitList_pushNew(arg1);
    temp_s0 = temp_v0;
    particleEmitter_setSprite(temp_v0, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFFA8(temp_s0, &D_803915AC);
    particleEmitter_setStartingFrameRange(temp_s0, 0, 7);
    particleEmitter_setPosition(temp_s0, arg0);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_803915B8);
    func_802EFB70(temp_s0, (*arg2)[0], (*arg2)[1]);
    func_802EFB84(temp_s0, (*arg2)[2], (*arg2)[3]);
    particleEmitter_setSpawnIntervalRange(temp_s0, 0.0f, 0.01f);
    func_802EFEC0(temp_s0, 2.8f, 3.2f);
    func_802EFA5C(temp_s0, 0.3f, 0.4f);
    func_802EFA78(temp_s0, 1);
    particleEmitter_emitN(temp_s0, arg1);
}

void func_803868A0(f32 (*arg0)[3], s32 (*arg1)[3]) {
    ParticleEmitter * temp_s0;

    temp_s0 = partEmitList_pushNew(1);
    particleEmitter_setSprite(temp_s0, ASSET_45A_SPRITE_GREEN_GLOW);
    particleEmitter_setStartingFrameRange(temp_s0, 2, 2);
    func_802EFFA8(temp_s0, arg1);
    particleEmitter_setPosition(temp_s0, arg0);
    func_802EFA78(temp_s0, 1);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_80391618);
    func_802EFC28(temp_s0, &D_803915E8);
}

void func_80386934(f32 position[3], enum asset_e sprite_id) {
    ParticleEmitter * temp_s0;

    temp_s0 = partEmitList_pushNew(1);
    particleEmitter_setSprite(temp_s0, sprite_id);
    particleEmitter_setStartingFrameRange(temp_s0, 1, 6);
    particleEmitter_setPosition(temp_s0, position);
    func_802EFA78(temp_s0, 1);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_80391678);
    func_802EFC28(temp_s0, &D_80391648);
}

extern TUPLE(s32, unk) D_803916C0;
extern TUPLE(s32, unk) D_803916CC;
extern TUPLE(s32, unk) D_803916D8;
extern s32 D_803916E4;
extern f64 D_803920C0;
void func_803869BC(Actor *this) {
    s32 sp3C;
    TUPLE(s32, unk) sp30;
    s32 sp2C;
    vec3f sp20;
    u32 temp_t3;

    if (this->marker->unk14_21) {
        sp3C = func_8023DB5C();
        temp_t3 = (u32) this->state;
        if ((temp_t3 == 6) || (temp_t3 == 7)) {
            sp30.unk_x = D_803916CC.unk_x;
            sp30.unk_y = D_803916CC.unk_y;
            sp30.unk_z = D_803916CC.unk_z;
            sp2C = 0x715;
        } else if ((temp_t3 == 8) || (temp_t3 == 9)) {
            sp30.unk_x = D_803916D8.unk_x;
            sp30.unk_y = D_803916D8.unk_y;
            sp30.unk_z = D_803916D8.unk_z;
            sp2C = 0x000;
        } else {
            sp30.unk_x = D_803916C0.unk_x;
            sp30.unk_y = D_803916C0.unk_y;
            sp30.unk_z = D_803916C0.unk_z;
            sp2C = 0x713;
        }
        func_8034A174(this->marker->unk44, 7, &sp20);
        if (((sp2C == 0x715) && ((sp3C & 1) != 0)) || ((sp2C == 0x713) && ((sp3C & 3) == 0))) {
            func_803868A0(&sp20, &sp30);
        }
        if (sp2C == 0) {
            func_8038856C(this, &D_803916E4);
        }
        if ((sp2C != 0) && ((sp2C == 0x715) || (sp2C = sp2C, ((f64) randf() < D_803920C0)))) {
            func_80386934(&sp20, sp2C);
        }
    }
}

void func_80386B54(f32 *arg0, f32 arg1) {
    f32 sp34;
    f32 sp28[3];
    s32 i;

    sp34 = time_getDelta();
    player_getPosition(sp28);
    for(i = 0; i < 3; i++){
        arg0[i] = (i == 1) ? sp28[i] : sp28[i] + ((sp28[i] - D_80392788[i]) * arg1) / sp34;
    }
}

bool func_80386BEC(Actor *this, f32 arg1) {
    this->yaw_moving = (f32) func_80329784(this);
    func_80328FB0(this, arg1);
    if ((this->yaw_moving < (this->yaw + arg1)) && ((this->yaw - arg1) < this->yaw_moving)) {
        return TRUE;
    }
    return FALSE;
}

bool func_80386C68(Actor *this, f32 arg1) {
    f32 sp2C[3];

    func_8039129C(&sp2C);
    this->yaw_moving = (f32) func_803297C8(this, &sp2C);
    func_80328FB0(this, arg1);

    if ((this->yaw_moving < ( this->yaw + arg1)) && (( this->yaw - arg1) < this->yaw_moving)) {
        return TRUE;
    }
    return FALSE;
}

void func_80386CF8(Actor *actor) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    sp28[0] = actor->position[0];
    sp28[1] = actor->position[1];
    sp28[2] = actor->position[2];
    sp28[1] += 220.0f;
    sp34[1] = 0.0f;
    sp34[0] = 0.0f;
    sp34[2] = 1000.0f;
    ml_vec3f_yaw_rotate_copy(&sp34, &sp34, actor->yaw);
    sp4C[0] = sp28[0] + sp34[0];
    sp4C[1] = sp28[1] + sp34[1];
    sp4C[2] = sp28[2] + sp34[2];
    func_8025727C(sp28[0], sp28[1], sp28[2], sp4C[0], sp4C[1], sp4C[2], &sp40[0], &sp40[1]);
    sp40[0] = 360.0f - sp40[0];
    sp40[2] = 0.0f;
    func_802BAE6C(sp4C, sp40);
}

void func_80386DE4(ActorMarker *arg0) {
    Actor *actor;

    actor = marker_getActor(arg0);
    func_802C8F70(func_803297C8(actor, &D_803916F4));
    func_802C937C(0x14, &actor->position_x);
}

void func_80386E34(void) {
    marker_despawn(D_803927A8);
    D_803927A8 = NULL;
}

void func_80386E5C(s32 arg0) {
    s16 *temp_v1;
    Actor *temp_v0;

    temp_v0 = func_8032813C(0x39F, &D_80391700, D_8039170C);
    temp_v0->alpha_124_19 = 0;
    temp_v0->unk38_31 = 6;
    D_803927A8 = temp_v0->marker;
}

void func_80386EC0(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x38A, &D_80392758, 0)->marker;
    func_8030E878(SFX_147_GRUNTY_SPELL_ATTACK_2, randf2(D_803920C8, D_803920CC), 0x7D00, &D_80392758, D_803920D0, D_803920D4);
    func_803900DC(marker, &D_80392758, D_80392768[1], D_80392768[2]);
}

void func_80386F5C(ActorMarker * arg0, f32 arg1[3], f32 arg2, f32 arg3) {
    arg1[1] += 100.0f;
    D_80392758[0] = (f32) arg1[0];
    D_80392758[1] = (f32) arg1[1];
    D_80392758[2] = (f32) arg1[2];
    D_80392768[1] = arg2;
    D_80392768[2] = arg3;
    func_802C3C88(func_80386EC0, reinterpret_cast(s32, arg0));
}

void func_80386FD8(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x389, D_80392758, 0)->marker;
    func_8030E878(SFX_146_GRUNTY_SPELL_ATTACK_1, randf2(D_803920D8, D_803920DC), 0x7D00, D_80392758, D_803920E0, D_803920E4);
    func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387074(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x3AA, D_80392758, 0)->marker;
    func_8030E878(SFX_146_GRUNTY_SPELL_ATTACK_1, randf2(D_803920E8, D_803920EC), 0x7D00, D_80392758, D_803920F0, D_803920F4);
    func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387110(ActorMarker *this, f32 arg1[3], f32 arg2, s32 arg3) {
    Actor *temp_v0;
    ActorLocal_fight_180 *local;
    f32 sp2C[3];
    s32 i;
    
    temp_v0 = (Actor*) marker_getActor(this);
    local = (ActorLocal_fight_180 *)&temp_v0->local;
    D_80392758[0] = arg1[0];
    D_80392758[1] = arg1[1];
    D_80392758[2] = arg1[2];
    D_80392758[1] += 80.0f;
    
    if (arg3 == 0) {
        func_80386B54(sp2C, arg2);
    } else if (local->unk7 == 0) {
        sp2C[0] = D_80391710[0];
        sp2C[1] = D_80391710[1];
        sp2C[2] = D_80391710[2];
    } else {
        sp2C[0] = D_8039171C[0];
        sp2C[1] = D_8039171C[1];
        sp2C[2] = D_8039171C[2];
    }
    
    D_80392778[0] = 0.0f;
    D_80392778[1] = (arg3 == 0) ? D_803920F8 : -500.0;
    D_80392778[2] = 0.0f;
        
    for(i = 0; i < 3; i++){
        D_80392768[i] = (sp2C[i] - arg1[i]) / arg2 - (D_80392778[i] * arg2 / 2);
    }
    if (arg3 == 0) {
        func_802C3C88(&func_80386FD8, this);
    }
    else{
        func_802C3C88(func_80387074, this);
    }
}

void func_803872F8(Actor *arg0) { 
    f32 vec[3];

    func_8034A174(arg0->marker->unk44, 0xA, vec);
    func_80387110(arg0->marker, vec, 3.0f, 1);
}

s32 func_80387340(Actor *this, f32 arg1) {
    f32 sp24[3];

    if (actor_animationIsAt(this, 0.50f) != 0) {
        if (this->marker->unk14_21) {
            func_8034A174(this->marker->unk44, 5, &sp24);
        } else {
            sp24[0] = this->position_x;
            sp24[1] = this->position_y;
            sp24[2] = this->position_z;
        }
        func_80387110(this->marker, sp24, arg1, 0);
        return 1;
    }
    return 0;
}

void func_803873DC(Actor *actor, f32 arg1, f32 arg2) {
    f32 vec[3];
    ActorMarker *marker;

    if (actor_animationIsAt(actor, 0.5f) != 0) {
        marker = actor->marker;
        if (marker->unk14_21) {
            func_8034A174(marker->unk44, 6, vec);
        } else {
            vec[0] = actor->position[0];
            vec[1] = actor->position[1];
            vec[2] = actor->position[2];
        }
        func_80386F5C(actor->marker, vec, arg1, arg2);
    }
}

s32 func_80387470(Actor *this, f32 arg1[3], f32 v_max, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 dt;
    TUPLE(f32, vec) diff;
    TUPLE(f32, pos) temp;
    TUPLE(f32, pos) next;
    dt = time_getDelta();
    
    diff.vec_x = arg1[0] - this->position_x;
    diff.vec_y = arg1[1] - this->position_y;
    diff.vec_z = arg1[2] - this->position_z;

    if (arg5 != 0.00f) {
        if (func_80256064(this->position, arg1) < arg5) {
            ml_vec3f_set_length(diff.vec, arg3 * 4.00f);
        } else {
            ml_vec3f_set_length(diff.vec, arg3 * 1.00f);
        }
    } else {
        ml_vec3f_set_length(diff.vec, arg3);
    }

    this->position_x += (this->velocity_x * dt) + (diff.vec_x * dt * dt);
    this->position_y += (this->velocity_y * dt) + (diff.vec_y * dt * dt);
    this->position_z += (this->velocity_z * dt) + (diff.vec_z * dt * dt);

    this->velocity_x += (diff.vec_x * dt);
    this->velocity_y += (diff.vec_y * dt);
    this->velocity_z += (diff.vec_z * dt);

    // has to be z^2 + (x^2 + y^2) for whacky compiler reasons ? Is there a Macro for this ?
    if (v_max < gu_sqrtf(
         (this->velocity_z * this->velocity_z) +
        ((this->velocity_x * this->velocity_x) +
         (this->velocity_y * this->velocity_y)) )) {
        
        ml_vec3f_set_length(this->velocity, v_max);
    }  

    next.pos_x = this->velocity_x + this->position_x;
    next.pos_y = this->velocity_y + this->position_y;
    next.pos_z = this->velocity_z + this->position_z;

    func_80258A4C(this->position, this->yaw - 90.0f, &next.pos_x, &temp.pos_z, &temp.pos_y, &temp.pos_x);

    this->yaw += (arg4 * temp.pos_x * dt);

    if (func_80256064(this->position, arg1) < arg6) {
        return 1;
    }
    return 0;
}

void func_8038770C(Actor *actor) {
    ActorLocal_fight_180 *local;

    local = (ActorLocal_fight_180 *)&actor->local;
    local->unk1 = 0;
    local->unk2 = 0;
    local->unk3 = 0;
    local->unk4 = 0;
    local->unk6 = 0;
    local->unkA = 0;
}

void func_80387728(ActorMarker *this, u32 arg1)
{   
    Actor *actor = marker_getActor(this);
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *) &actor->local;
    
    local->unk0 = arg1;
    func_8038770C(actor);
    func_80386600(actor->marker, 0);
    func_80386628(actor->marker, 1);

    switch(arg1)
    {
        case 0:
            func_80328B8C(actor, 1, 0.0001f, 1);
            timed_setCameraToNode(0.0f, 0);
            func_80324E88(2.0f);
            timed_setCameraToNode(2.0f, 1);
            timedFunc_set_1(2.0f, func_8038B780, actor->marker);
            return;

        case 1:
            func_80328B8C(actor, 2, 0.0001f, 1);
            func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, actor->position, 5000.0f, 12000.0f);
            local->unk5 = 0x0;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            local->unk10 = 0;
            if (actor->unk44_31 == 0)
            {
                actor->unk44_31 = (u8)func_8030D90C();
                func_8030DA80(actor->unk44_31, SFX_152_MOTOR_BREAKDOWN_01);
                func_8030DD14(actor->unk44_31, 3);
                func_8030DBB4(actor->unk44_31, 1.0f);
                func_8030DABC(actor->unk44_31, 0x7D00);
            }
            return;

        case 2:
            func_80328B8C(actor, 0xE, 0.0001f, 1);
            local->unk5 = 0x8;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            func_80311480(randi2(0, 5) + 0x1106, 4, NULL, NULL, NULL, NULL);
            return;

            
        case 3:
            func_80328B8C(actor, 0x15, 0.0001f, 1);
            local->unk5 = 0xC;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            actor->unk60 = 15.0f;
            return;

        case 4:
            func_80328B8C(actor, 0x1C, 0.0001f, 1);
            local->unk5 = 0x10;
            actor->unk1C_x = D_803927D0[(local->unk5)][0];
            actor->unk1C_y = D_803927D0[(local->unk5)][1];
            actor->unk1C_z = D_803927D0[(local->unk5)][2];
            return;

        case 5:
            func_80386628(actor->marker, 0);
            func_8038AC88(actor, 0x24);
            actor_loopAnimation(actor);
    }
}

extern void func_80328FF0(Actor *arg0, f32 arg1);
void func_80387ACC(Actor *arg0, f32 arg1) {
    func_80328CA8(arg0, 0);
    func_80328FF0(arg0, arg1);
}

extern f32 func_8025715C(f32, f32);

void func_80387B00(Actor *this) {
    ActorLocal_fight_180 *local;
    f32 sp28[3];
    
    local = (ActorLocal_fight_180 *) this->local;

    func_80386B54(&sp28, 0.80f);
    this->unk1C_x = sp28[0];
    this->unk1C_y = sp28[1];
    this->unk1C_z = sp28[2];
    this->unk1C_y = 0;
    
    this->velocity_x = this->position_x - sp28[0];
    this->velocity_y = this->position_y - sp28[1];
    this->velocity_z = this->position_z - sp28[2];
    this->velocity_y = 0;
    
    local->unk14 = gu_sqrtf(
        (this->velocity_z * this->velocity_z) +
        ((this->velocity_x * this->velocity_x) +
        (this->velocity_y * (this->velocity_y)))
    );

    ml_vec3f_normalize(this->velocity);
    this->yaw_moving = func_8025715C(this->velocity_x, this->velocity_z) + 180.0f;
    
    local->unk18 = this->position_y;
    local->unk1C = (f64) sp28[1];
    local->unk20 = local->unk14;
}

void func_80387BFC(Actor *this, f32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387BFC.s")

void func_80387D4C(Actor *);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80387D4C.s")

void func_80387E1C(Actor *this, f32 arg1[3]) {
    ActorLocal_fight_180 *local;
    f32 dz;
    f32 distance;
    f32 dx;
    f32 min_distance;
    s32 i;

    local = (ActorLocal_fight_180 *)&this->local;
    min_distance = 1e+8f;
    for(i = 0; i < 8; i++){
        dx = D_803927D0[i][0] - this->position[0];
        dz = D_803927D0[i][2] - this->position[2];
        distance = (dx * dx) + (dz * dz);
        if (distance < min_distance) {
            local->unk5 = i;
            min_distance = distance;
            arg1[0] = D_803927D0[local->unk5][0];
            arg1[1] = D_803927D0[local->unk5][1];
            arg1[2] = D_803927D0[local->unk5][2];
        }
    }
}



void func_80387F70(Actor *actor, f32 *arg1, f32 arg2) {
    ActorLocal_fight_180 *temp_v0 = &actor->local;
    f32 vec[3];
    f32 playerPos[3];

    player_getPosition(&playerPos);
    vec[0] = D_803927D0[temp_v0->unk5][0] - playerPos[0];
    vec[1] = D_803927D0[temp_v0->unk5][1] - playerPos[1];
    vec[2] = D_803927D0[temp_v0->unk5][2] - playerPos[2];
    ml_vec3f_normalize(vec);
    arg1[0] = D_803927D0[temp_v0->unk5][0] + (arg2 * vec[0]);
    arg1[1] = D_803927D0[temp_v0->unk5][1] + (arg2 * vec[1]);
    arg1[2] = D_803927D0[temp_v0->unk5][2] + (arg2 * vec[2]);
}

void func_803880A0(Actor *actor, f32 arg1) {
    actor->velocity[2] = arg1;
    actor->velocity[1] = 0.0f;
    actor->velocity[0] = 0.0f;
    ml_vec3f_yaw_rotate_copy(&actor->velocity, &actor->velocity, actor->yaw);
}

void func_803880E0(ActorMarker *arg0, s32 arg1, s32 arg2) {
    func_80388184(marker_getActor(arg0), 0xC);
}

void func_80388110(ActorMarker *arg0, s32 arg1, s32 arg2) {
    Actor *actor;
    ActorLocal_fight_180 *actorLocal;

    actor = marker_getActor(arg0);
    actorLocal = &actor->local;
    func_802BAE4C();
    func_80311480(randi2(0, 5) + 0x1101, 4, 0, actor->marker, func_803880E0, 0);
    actorLocal->unk9 = (u8)1;
}

void func_80388184(Actor *this, s32 next_state) {
    ActorLocal_fight_180 *local;
    s32 sp40;
    f32 sp3C;
    f32 temp_f12;

    local = (ActorLocal_fight_180 *)&this->local;
    sp40 = func_8023DB5C();
    sp3C = func_802877D8(this->animctrl);
    local->unk0 = 1;
    func_80328B8C(this, next_state, 0.0001f, 1);
    actor_loopAnimation(this);
    func_80386600(this->marker, 0);
    if (next_state != 9) {
        if (func_8030E3FC(this->unk44_31)) {
            func_8030E394(this->unk44_31);
            func_8030E624(0x7FFF4162U);
        }
    }
    switch (next_state) {
    case 2:
        func_80387E1C(this, this->unk1C);
        break;
    case 5:
        if ((sp40 & 1) == 0) {
            func_8030E878(SFX_142_GRUNTY_LAUGH_3, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        } else {
            func_8030E878(SFX_14B_GRUNTY_LAUGH_4, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        }
        this->unk28 = 0.0f;
        this->unk60 = 0.0f;
        break;
    case 6:
        local = local;
        func_80386600(this->marker, 1);
        func_80324D54(0.4f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
        this->unk28 = 0.0f;
        func_80387B00(this);
        local->unkA = 0;
        break;
    case 7:
        local->unk14 = (local->unk14 > 2000.0f) ? local->unk14 : 2000.0f;
        local->unk14 = (local->unk14 < 2700.0f) ? local->unk14 : 2700.0f;
        local->unk18 = 400.0f;
        local->unk28 = (-this->unk28 * this->unk28) / (2.0 * local->unk14);
        func_80386600(this->marker, 1);
        func_8028764C(this->animctrl, sp3C);
        break;
    case 8:
        temp_f12 = 1150.0f;
        local->unk28 = (-this->unk28 * this->unk28) / (2.0 * temp_f12);
        local->unk2C = (100.0f - local->unk1C) / temp_f12;
        break;
    case 9:
        actor_playAnimationOnce(this);
        func_8028764C(this->animctrl, sp3C);
        break;
    case 10:
        func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        break;
    case 12:
        func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
        break;
    case 13:
        func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        if ((s32) local->unk1 >= 4) {
            func_802C3C88(func_80386DE4, this->marker);
            func_80388110(this->marker, 0, 0);
        }
        break;
    }
}


void func_8038856C(Actor *actor, f32 *arg1) {
    f32 vec[3];
    ActorMarker *marker;

    marker = actor->marker;
    if (marker->unk14_21) {
        func_8034A174(marker->unk44, 7, vec);
    } else {
        vec[0] = actor->position[0];
        vec[1] = actor->position[1];
        vec[2] = actor->position[2];
    }
    func_8038679C(vec, 2, arg1);
}

void func_803885DC(Actor *this) {
    s32 sp24 = func_8023DB5C();
    
    if (func_8030E3FC(this->unk44_31) == 0) {
        func_8030E2C4(this->unk44_31);
    }
    if (((sp24 & 7) == 0) && (randf() < 0.5)) {
        func_8038856C(this, &D_80391728);
    }
    if ((actor_animationIsAt(this, 0.30f) != 0) || (actor_animationIsAt(this, 0.78f) != 0)) {
        func_8030E8B4(0x7FF8681E, this->position, 0x271007D0);
        func_8030E8B4(0x7FF8688E, this->position, 0x271007D0);
    }
    if ((actor_animationIsAt(this, 0.40f) != 0) || (actor_animationIsAt(this, 0.88f) != 0)) {
        func_8030E8B4(0x7FF8681E, this->position, 0x271007D0);
        func_8030E8B4(0x7318688E, this->position, 0x271007D0);
    }
}

s32 func_8038871C(Actor *arg0, f32 arg1, f32 arg2) {
    if (arg0->position[1] + arg2 > arg1) {
        arg0->position[1] = arg1;
        return 1;
    }
    else
    {
        arg0->position[1] = arg0->position[1] + arg2;
        return 0;
    }
}

void func_80388758(ActorMarker *marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp54;
    f32 sp50;
    s32 var_a0;
    f32 sp40[3];

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp54 = time_getDelta();
    switch (this->state) {
    case 2:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        func_80387ACC(this, 60.0f * sp54);
        func_80387F70(this, this->unk1C, 950.0f);
        if (func_80387470(this, this->unk1C, 1000.0f, 1800.0f, 200.0f, 1000.0f, 600.0f)) {
            func_80388184(this, 3);
            this->unk1C[0] = D_803927D0[local->unk5][0];
            this->unk1C[1] = D_803927D0[local->unk5][1];
            this->unk1C[2] = D_803927D0[local->unk5][2];
        }
        break;
    case 3:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        sp50 = ml_map_f(func_80256064(this->position, this->unk1C), 300.0f, 1000.0f, 100.0f, 1000.0f);
        func_80387ACC(this, 60.0f * sp54);
        if (func_80387470(this, this->unk1C, sp50, 1800.0f, 200.0f, 500.0f, 300.0f)) {
            func_80388184(this, 4);
        }
        break;
    case 4:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        func_80387ACC(this, 60.0f * sp54);
        if (func_80386BEC(this, 240.0f * sp54)) {
            func_80388184(this, 5);
            func_80386654(1.0f, &D_80391380, &D_80391390);
        }
        break;
    case 5:
        func_80387B00(this);
        this->unk60 += sp54;
        if (this->unk60 < 0.3333333333333333) {
            this->unk28 += 3300.0 * sp54;
        } else if (0.7333333333333334 < this->unk60) {
            this->unk28 -= 3300.0 * sp54;
        }
        local->unk20 += this->unk28 * sp54;
        func_80387BFC(this, 45.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if (this->unk60 > 1.0) {
            func_80388184(this, 6);
        }
        break;
    case 6:
        func_803869BC(this);
        if (local->unk4 >= (local->unk1 + 1)) {
            this->unk28 += (D_80391738[local->unk1] * sp54) * 0.66;
        } else {
            this->unk28 +=  D_80391738[local->unk1] * sp54;
        }
        local->unk20 -= this->unk28 * sp54;
        func_80387BFC(this, 180.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if ((local->unkA == 0) && (local->unk20 < (local->unk14 * /*0.65*/D_80392210))) {
            local->unkA = 1U;
            func_8030E8B4(0x4CBB58C4, this->position, 0x271007D0);
        }
        if ((local->unk14 * 0.75) < local->unk20) {
            func_80386B54(sp40, 0);
            this->unk1C[0] = sp40[0];
            this->unk1C[1] = sp40[1];
            this->unk1C[2] = sp40[2];
            this->unk1C[1] = 0.0f;
            this->velocity[0] = this->position[0] - sp40[0];
            this->velocity[1] = this->position[1] - sp40[1];
            this->velocity[2] = this->position[2] - sp40[2];
            this->velocity[1] = 0.0f;
            ml_vec3f_normalize(this->velocity);
            this->yaw_moving = func_8025715C(this->velocity[0], this->velocity[2]) + 180.0f;
        }
        if (local->unk20 < 0.0) {
            var_a0 =  (local->unk1 == 0) ? 1 : 0;
            if (local->unk4 >= (var_a0 + local->unk1)) {
                func_80388184(this, 8);
                local->unk4 = 0;
            }
            else{
                func_80388184(this, 7);
                local->unk4++;
            }
        }
        break;
    case 7:
        func_803869BC(this);
        this->unk28 = this->unk28 + local->unk28 * sp54;
        local->unk20 =  local->unk20 - this->unk28 * sp54;
        func_80387BFC(this, 180.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if (this->unk28 < 0) {
            func_80388184(this, 4);
            func_80386654(1.5f, D_80391390, D_80391380);
        }
        break;
    case 8:
        func_803885DC(this);
        func_803869BC(this);
        this->unk28 = this->unk28 + local->unk28 * sp54;
        local->unk20 = local->unk20 - this->unk28 * sp54;
        func_80387ACC(this, 60.0f * sp54);
        func_80387D4C(this);
        func_80328FB0(this, 30.0f * sp54);
        if (this->unk28 < 0) {
            func_80388184(this, 9);
            func_80386654(2.0f, D_80391390, D_80391380);
            this->unk60 = 4.0f;
        }
        break;
    case 9:
        func_803885DC(this);
        if (this->unk60 > 0.0) {
            this->unk60 -= sp54;
        }
        else{
            if (actor_animationIsAt(this, 0.9999f)) {
                func_80388184(this, 2);
                func_803880A0(this, 2000.0f);
            }
        }
        break;
    case 10:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        func_8038871C(this, 460.0f, 400.0f * sp54);
        func_80387340(this, 1.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            func_80388184(this, 2);
            func_803880A0(this, 2000.0f);
        }
        break;
    case 11:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        if (local->unk9) {
            func_8038871C(this, 460.0f, 400.0f * sp54);
        }
        break;
    case 12:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        func_8038871C(this, 460.0f, 400.0f * sp54);
        func_803873DC(this, 600.0f, 2000.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            func_8030DA44(this->unk44_31);
            this->unk44_31 = 0U;
            func_80387728(this->marker, 2);
        }
        break;
    case 13:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            if (local->unk1 >= 4) {
                func_80388184(this, 0xB);
            }
            else{
                func_80388184(this, 0xA);
            }
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_803891E4.s")

void func_80389358(s32 arg0, s32 arg1, s32 arg2) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_80386E5C, *arg0ptr);
}

void func_8038938C(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038938C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80389720.s")

void func_80389720();

void func_803898A4(s32 arg0) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_80389720, *arg0ptr);
}

void func_803898D0(ActorMarker *marker) {
    Actor *actor;

    actor = marker_getActor(marker);
    actor->unk100 = spawn_child_actor(0x3AB, &actor)->marker;
    D_803927C5 = (u8)1;
}

void func_80389918(s32 arg0) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_803898D0, *arg0ptr);
}


void func_80389944(ActorMarker *marker, s32 arg1, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(marker);
    func_802BAE4C();
    func_80324E38(0, 0);
    func_80387728(actor->marker, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038998C.s")

void func_80389B44(s32 arg0) {
    s32 *arg0ptr = &arg0; // Does not match without the pointer
    func_802C3C88(&func_80386DE4, *arg0ptr);
}

void func_80389B70(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80389B70.s")

void func_80389F54(void) {
    func_80320004(0xD2, 1);
    D_803927C4 = (u8)0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_80389F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038A4E8.s")

void func_8038A5F4(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038A5F4.s")

void func_80328B8C(Actor *, s32, f32, s32);

void func_8038AC50(ActorMarker *arg0) {
    func_80328B8C(marker_getActor(arg0), 0x24, 0.0001f, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038AC88.s")

void func_8038AF84(ActorMarker *arg0) {
    func_8038AC88(marker_getActor(arg0), 0x29);
}

void func_8038AFB0(void) {
    func_802E4078(MAP_87_CS_SPIRAL_MOUNTAIN_5, 0, 1);
}

void func_8038AFD8(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038AFD8.s")


void func_8038B730(ActorMarker *arg0, s32 arg1, s32 arg2) {
    Actor *sp1C;

    sp1C = marker_getActor(arg0);
    func_802BE720();
    func_80324E88(0);
    func_8028F784(0);
    func_80387728(sp1C->marker, 1);
}

void func_8038B780(ActorMarker *arg0) {
    Actor *sp24;

    sp24 = marker_getActor(arg0);
    if (!func_8031FF1C(0xCF)) {
        sp24 = sp24;
        func_80320004(0xCF, 1);
        func_80311480(0x10E7, 0x2A, &sp24->position_x, sp24->marker, &func_8038B730, 0);
        return;
    }
    sp24 = sp24;
    func_80311480(randi2(0, 5) + 0x10E8, 0x2B, &sp24->position_x, sp24->marker, &func_8038B730, 0);
}

void func_8038B82C(ActorMarker *arg0) { return; }

void func_8038B834(ActorMarker *, ActorMarker *);
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038B834.s")


void func_8038B9AC(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    switch (local->unk0) {
    case 1:
        if (local->unk1 == 0) {
            func_80311480(randi2(0, 5) + 0x10F7, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->unk1 + 1) < 5) {
            local->unk1++;
            func_80388184(this, 0xD);
            local->unk4 = 0;
        }
        break;

    case 2:
        if (this->state != 0x14) {
            if ((local->unk2 + 1) >= 3) {
                local->unk2 = 0;
                if (local->unk1 == 0) {
                    func_80311480(randi2(0, 5) + 0x1110, 0x20, NULL, NULL, NULL, NULL);
                }
                if ((local->unk1 + 1) < 5) {
                    local->unk1++;
                    func_803891E4(this, 0x14);
                }
            } else {
                local->unk2++;
                func_803891E4(this, 0x13);
            }
        }
        break;
    case 3:
        if (local->unk1 == 0) {
            func_80311480(randi2(0, 5) + 0x1127, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->unk1 + 1) < 5) {
            local->unk1++;
            func_8038998C(this, 0x19);
            if (local->unk1 == 4) {
                func_802C3C88(func_80386DE4, this->marker);
            }
        }
        break;
    }
}

void func_8038BB8C(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    u8 temp_v0_2;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    if (local->unk0 == 1) {
        func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(D_80392440, D_80392444), 32000, this->position, D_80392448, D_8039244C);
        if (local->unk10 == 0) {
            if (func_80311480(randi2(0, 5) + 0x10ED, 0, NULL, NULL, NULL, NULL)) {
                local->unk10++;
            }
        }
    }
    if (local->unk0 == 3) {
        temp_v0_2 = local->unk6;
        if ((local->unk6 == 0) && (this->state != 0x1A)) {
            local->unk6++;
            func_80311480(randi2(0, 5) + 0x111D, 0, NULL, NULL, NULL, NULL);
        }
    }
}

void func_8038BCB8(ActorMarker *arg0) {
    Actor *sp1C;

    sp1C = marker_getActor(arg0);
    D_803927A4 = spawn_child_actor(0x3AF, &sp1C)->marker;
}

extern f32 D_80392450;

#ifndef NONMATHCING
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038BCF0.s")
#else
void func_8038BCF0(Actor *this){
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *) &this->local;
    s32 i;
    s32 tmp_s0;
    Actor *other;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        func_803300C0(this->marker, func_8038B834);
        marker_setCollisionScripts(this->marker, func_8038BB8C, func_8038B9AC, NULL);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        for(i = 0x38C; i < 0x39F; i++){
            func_80304E24(i, D_803927D0[i - 0x38C]);
        }
        D_803927A8 = 0;
        D_803927A4 = 0;
        D_803927C4 = 0;
        D_803927C5 = 0;
        D_803927C6 = 0;
        D_803927C7 = 0;
        D_803927C8 = 0;
        D_803927C9 = 0;

        local->unk8 = 0;
        local->unk9 = 0;
        local->unkB = 0;

        D_803927B4 = 0;
        D_803927B0 = 0;
        D_803927B8 = 0;
        D_803927BC = 0;
        func_802C3C88(func_8038BCB8, this->marker);
        func_80387728(this->marker, 0);
        local->unk1 = 0;
        func_80386600(this->marker, 0);
        func_80386628(this->marker, 1);
        func_8038FC00();

        func_80386654(1.0f, D_80391380, D_80391390);
        func_8028F784(1);
        func_8028F4B8(&D_80391804, 2000.0f, -2800.0f);
        func_8028FA14(0x93, 2);
        func_8034C9B0(0);
        func_80386698(2.0f);
        tmp_s0 = func_802F9AA8(SFX_9A_MECHANICAL_CLOSING);
        func_802F9DB8(tmp_s0, D_80392450, D_80392450, 0.0f);
        func_802F9FD0(tmp_s0, 0.0f, 2.0f, 0.0f);
        func_802FA060(tmp_s0, 25000, 25000, 0);
        timed_playSfx(2.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 32000);
    }//L8038BF0C
    switch(local->unk0){
        case 0:
            func_8038B82C(this->marker);
            break;
        case 1:
            func_80388758(this->marker);
            break;
        case 2:
            func_8038938C(this->marker);
            break;
        case 3:
            func_80389B70(this->marker);
            break;
        case 4:
            func_8038A5F4(this->marker);
            break;
        case 5:
            func_8038AFD8(this->marker);
            break;
    }
    func_80320524(0x23, local->unk0, 3);
    player_getPosition(D_80392788);
    D_80392798[0] = this->position[0];
    D_80392798[1] = this->position[1];
    D_80392798[2] = this->position[2];
    if(this->unk100 && D_803927C5){
        func_8038EB90(this->unk100, this->position);
    }

    if(D_803927A4){
        other = marker_getActor(D_803927A4);
        sp4C[0] = this->position[0];\
        sp4C[1] = this->position[1];\
        sp4C[2] = this->position[2];
        sp4C[1] = 200.0f;

        sp34[0] = this->position[0];\
        sp34[1] = this->position[1];\
        sp34[2] = this->position[2];
        sp34[1] = -50.0f;
        if(func_80309B48(sp4C, sp34, sp40, 0)){
            sp34[1] += 6.0f;
            other->position_x = sp34[0];\
            other->position_y = sp34[1];\
            other->position_z = sp34[2];
            other->unk1C[0] = this->position_y - sp34[1];
            other->scale = this->scale;
            other->unk58_0 = 1;
        }
        else{//L8038C0B8
            other->unk58_0 = 0;
        }
    }//L8038C0C8
}
#endif

void func_8038C0DC(f32 (*arg0)[3]) {
    (*arg0)[0] = D_80392798[0];
    (*arg0)[1] = D_80392798[1];
    (*arg0)[2] = D_80392798[2];
}

void func_8038C100() {
    D_803927C5 = 0;
}

void func_8038C10C(s32 arg0) {
    func_8038AC88(marker_getActor((ActorMarker*)arg0), 0x28);
}

void func_8038C138() {
    D_803927C7 = 1;
}

Actor *func_80326EEC(s32);
f32 func_80391234();
f32 func_8038DFA0();
void func_80324E88(f32);
f32 func_80391240();


// Very minor stack diff
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_180/func_8038C148.s")
#else
void func_8038C148(void) {
    Actor *sp4C;
    ActorLocal_fight_180 *sp48;
    f32 temp_f20;
    f32 sp40;
    f32 temp_f12;
    s32 phi_s0;
    f32 sp34;
    f32 temp_f12_2;

    sp4C = func_80326EEC(0x38B);
    sp48 = (ActorLocal_fight_180 *)&sp4C->local;
    sp34 = func_8038DFA0();
    temp_f20 = sp34 + func_80391234();
    sp40 = func_80391240();
    phi_s0 = 0x14;
    func_80320004(0xFC, 1);
    if (sp48->unk7 != 0) {
        phi_s0 = 0x23;
    }
    func_8038AC88(sp4C, 0x27);
    sp48->unk8 = (u8)1;
    func_80324E38(0, 1);
    timed_setCameraToNode(0, phi_s0);
    func_80324E88(temp_f20);
    timedFunc_set_0(temp_f20 * D_80392470, &func_8038C138);
    timed_setCameraToNode(temp_f20, phi_s0 + 1);
    temp_f12 = temp_f20 + sp40;
    func_80324E88(temp_f12);
    timedFunc_set_1(temp_f12, func_8038C10C, (s32)sp4C->marker);
    timed_setCameraToNode(temp_f12, phi_s0 + 2);
    temp_f12_2 = temp_f12 + D_80392478;
    func_80324E88(temp_f12_2);
    timed_setCameraToNode(temp_f12_2, phi_s0 + 3);
}
#endif

void func_8038C27C(s32 arg0) {
    D_803927C4 = arg0;
}

f32 func_8038C288() {
    return 3.0f;
}

s32 func_8038C298() {
    return D_803927C7;
}

s32 func_8038C2A4() {
    return D_803927C8;
}

s32 func_8038C2B0() {
    return D_803927C9;
}
