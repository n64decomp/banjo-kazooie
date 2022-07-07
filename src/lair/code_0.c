#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern void func_8028F918(s32);
extern void func_802D2FB0(Actor *, s32, s32, s32, f32, s32, s32, s32);
extern void func_802D3CE8(Actor *);
extern void func_802D3D54(Actor *);
extern void func_802D3D74(Actor *this);
extern void func_802D4830(Actor *, s32, f32);
extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern int  func_8032886C(Actor *, f32);
extern void func_80328B8C(Actor *, s32, f32, s32);
extern void func_8033A45C(s32, s32);
extern void func_8034E0FC(void *, s32);
extern void  *func_8034C2C4(ActorMarker *, s32);



void   func_803863F0(Actor *this);
void   func_803864B0(Actor *this);
void   func_80386550(Actor *this);
Actor *func_8038664C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void   func_80386D78(Actor *this);
void   func_80386780(Actor *this);
void   func_803867A8(Actor *this);
void   func_80386D20(Actor *this);
void   func_803870DC(Actor *this);
Actor *func_80387560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void   func_80387730(Actor *this);
void   func_803880BC(Actor *this);
void   func_8038824C(Actor *this);
void   func_803882B0(Actor *this);
void   func_80388524(Actor *this);
void   func_80388FC8(Actor *this);
void   func_80389204(Actor *this);
void   func_803893B8(Actor *this);
void   func_803894B0(Actor *this);
void   func_8038982C(Actor *this);
void   func_80389898(Actor *this);
void   func_80389D08(Actor *this);
void   func_803875F0(Actor *this);
Actor *func_80387DA8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void   func_803896D4(Actor *this);
void   func_803896F4(Actor *this);
void   func_80389714(Actor *this);
void   func_80389734(Actor *this);
void   func_8038975C(Actor *this);
void   func_80389784(Actor *this);
void   func_803897AC(Actor *this);
void   func_80389934(Actor *this);
Actor *func_80389E10(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void   func_80389FF4(Actor *this);
void   func_8038A014(Actor *this);
void   func_8038A034(Actor *this);
void   func_8038A064(Actor *this);
void   func_8038A084(Actor *this);
void   func_8038A0A4(Actor *this);

extern ActorInfo D_80393560;
extern ActorInfo D_80393584;
extern ActorInfo D_803947B0;
extern ActorInfo D_803947D4;
extern ActorInfo D_80393730;
extern ActorInfo D_80394A80;
extern ActorInfo D_80394AB0;
extern ActorInfo D_80394870;
extern ActorInfo D_80394894;
extern ActorInfo D_803948B8;
extern ActorInfo D_80394910;
extern ActorInfo D_80394934;
extern ActorInfo D_80394958;
extern ActorInfo D_80394A08;
extern ActorInfo D_80394A2C;
extern ActorInfo D_80394A50;
extern ActorInfo D_80394980;
extern ActorInfo D_80394C28;
extern ActorInfo D_80394C4C;
extern ActorInfo D_80394C70;
extern ActorInfo D_80394D20;
extern ActorInfo D_80394CF0;
extern ActorInfo D_80394C94;

/* .data */
extern ActorAnimationInfo D_80392CB0[];
extern ActorInfo D_80392D90 = { 0x270, 0x2D8, 0x3B2, 0x1, NULL, func_802D3D54, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80392DB4 = { 0x110, 0x214, 0x4AB, 0x1, D_80392CB0, func_803896D4, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392DD8 = { 0x113, 0x217, 0x4A9, 0x1, D_80392CB0, func_803896F4, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392DFC = { 0x115, 0x219, 0x4AA, 0x1, D_80392CB0, func_80389714, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392E20 = { 0x11B, 0x221, 0x4B5, 0x1, D_80392CB0, func_80389734, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392E44 = { 0x11C, 0x222, 0x4B2, 0x1, D_80392CB0, func_8038975C, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392E68 = { 0x11D, 0x223, 0x4B0, 0x1, D_80392CB0, func_80389784, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392E8C = { 0x232, 0x23C, 0x4B8, 0x1, D_80392CB0, func_803897AC, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392EB0 = { 0x23F, 0x246, 0x534, 0x1, D_80392CB0, func_80386D20, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392ED4 = { 0x241, 0x248, 0x540, 0x1, D_80392CB0, func_80386780, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392EF8 = { 0x109, 0x20D, 0x4A1, 0x1, D_80392CB0, func_80386550, func_80326224, func_80325888, 0, 0, 0.0f, 0x85};
extern ActorInfo D_80392F1C = { 0x264, 0x2E5, 0x550, 0x19, D_80392CB0, func_80388524, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80392F40 = { 0x224, 0x230, 0x4BF, 0xB, D_80392CB0, func_803863F0, func_80326224, func_80325888, 0, 0, 0.0f, 0x88};
extern ActorInfo D_80392F64 = { 0x225, 0x231, 0x4D5, 0xE, D_80392CB0, func_803864B0, func_80326224, func_80325888, 0, 0, 0.0f, 0x88};
extern ActorInfo D_80392F88 = { 0x111, 0x215, 0x4A4, 0x1, NULL, func_80388FC8, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80392FAC = { 0x112, 0x216, 0x4A5, 0x1, NULL, func_80388FC8, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80392FD0 = { 0x114, 0x218, 0x4A6, 0x1, NULL, func_80389204, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80392FF4 = { 0x10D, 0x211, 0x4A3, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80393018 = { 0x22C, 0x23A, 0x4D9, 0x1, NULL, func_803882B0, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_8039303C = { 0x164, 0x259, 0x507, 0x1, NULL, func_803880BC, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80393060 = { 0x165, 0x25A, 0x508, 0x1, NULL, func_8038824C, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80393084 = { 0x240, 0x247, 0x48A, 0x1, NULL, func_80386D78, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_803930A8 = { 0x242, 0x249, 0x2DD, 0x1, NULL, func_803867A8, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_803930CC = { 0x11F, 0x225, 0x4B3, 0x1, NULL, func_8038A064, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_803930F0 = { 0x10A, 0x20E, 0x4A2, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_80393114 = { 0x11A, 0x220, 0x4B7, 0x1, NULL, func_80389FF4, func_80326224, func_80325E78, 0, 0, 0.0f, 0x91};
extern ActorInfo D_80393138 = { 0x11E, 0x224, 0x4AF, 0x1, NULL, func_8038A014, func_80326224, func_80325E78, 0, 0, 0.0f, 0x83};
extern ActorInfo D_8039315C = { 0x227, 0x234, 0x4D6, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x93};
extern ActorInfo D_80393180 = { 0x228, 0x235, 0x4D7, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x8B};
extern ActorInfo D_803931A4 = { 0x229, 0x236, 0x4D8, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x8B};
extern ActorInfo D_803931C8 = { 0x121, 0x227, 0x4BD, 0x1, NULL, func_8038A034, func_80326224, func_80325888, 0, 0, 0.0f, 0x89};
extern ActorInfo D_803931EC = { 0x116, 0x21A, 0x4AC, 0x1, NULL, func_803893B8, func_80326224, func_80325E78, 0, 0, 0.0f, 0x82};
extern ActorInfo D_80393210 = { 0x117, 0x21B, 0x4AD, 0x1, NULL, func_803894B0, func_80326224, func_80325E78, 0, 0, 0.0f, 0x82};
extern ActorInfo D_80393234 = { 0x10B, 0x20F, 0x4B4, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x90};
extern ActorInfo D_80393258 = { 0x10C, 0x210, 0x4AE, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x84};
extern ActorInfo D_8039327C = { 0x10E, 0x212, 0x4A7, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x7F};
extern ActorInfo D_803932A0 = { 0x120, 0x226, 0x4BC, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x87};
extern ActorInfo D_803932C4 = { 0x122, 0x228, 0x4BE, 0x1, NULL, func_80388524, func_80326224, func_80325E78, 0, 0, 0.0f, 0x8C};
extern ActorInfo D_803932E8 = { 0x10F, 0x213, 0x4A8, 0x1, NULL, func_803875F0, func_80326224, func_80325E78, 0, 0, 0.0f, 0x80};
extern ActorInfo D_8039330C = { 0x118, 0x21E, 0x4B1, 0x1, NULL, func_8038A084, func_80326224, func_80325E78, 0, 0, 0.0f, 0x8F};
extern ActorInfo D_80393330 = { 0x119, 0x21F, 0x4B6, 0x1, NULL, func_8038A0A4, func_80326224, func_80325E78, 0, 0, 0.0f, 0x92};
extern ActorInfo D_80393354 = { 0x266, 0x2E3, 0x563, 0x1, NULL, func_803870DC, func_80326224, func_80387560, 0, 0, 0.0f, 0};
extern ActorInfo D_80393378 = { 0x17D, 0x1E1, 0x517, 0x1, NULL, func_80389D08, func_80326224, func_80389E10, 0, 0, 0.0f, 0x8D};
extern ActorInfo D_8039339C = { 0x234, 0x23E, 0x4E1, 0x12, D_80392CB0, func_8038982C, func_80326224, func_80325E78, 0, 0, 0.0f, 0};
extern ActorInfo D_803933C0 = { 0x163, 0x258, 0x511, 0x12, D_80392CB0, func_80389898, func_80326224, func_8038664C, 0, 0, 0.0f, 0x8E};
extern ActorInfo D_803933E4 = { 0x160, 0x255, 0x509, 0x15, D_80392CB0, func_80389934, func_80326224, func_80325888, 0, 0, 0.0f, 0};
extern ActorInfo D_80393408 = { 0x102, 0x203, 0x491, 0x1, D_80392CB0, func_80387730, func_80326224, func_80387DA8, 0, 0, 0.0f, 0};
extern struct31s D_8039342C;
extern s16       D_80393452[]; //enum bkprog_e
extern s16       D_80393466[];
extern s16       D_8039347A[]; //notedoor_notes_required_to_open
extern s16       D_80393490[];
extern s32       D_803934A0[3];
extern struct31s D_803934AC;
extern struct42s D_803934D4;
extern s32       D_80393504[4];

/* .rodata */
extern f32 D_80394D50;
extern f64 D_80394D58;
extern f32 D_80394D60;
extern f32 D_80394D64;
extern f32 D_80394D68;
extern f32 D_80394D6C;
extern f32 D_80394D70;
extern f32 D_80394D74;
extern f32 D_80394D78;
extern f32 D_80394D7C;

extern f64 D_80394F88;

extern f32 D_80394D80;
extern f32 D_80394D84;
extern f32 D_80394D88;
extern f32 D_80394D8C; //! .rodata : 0.9f
extern f64 D_80394D90; //! .rodata : 1.7
extern f64 D_80394D98; //! .rodata : 1.1
extern f32 D_80394FC0;
extern f32 D_80394FC4;
extern f32 D_80394FC8;
extern f32 D_80394FCC;
extern f32 D_80394FD0;
extern f32 D_80394FD4;
extern f32 D_80394FD8;
extern f32 D_80394FDC;
extern f32 D_80394FE0;
extern f32 D_80394FE4;
extern f32 D_80394FE8;
extern f32 D_80394FEC;
extern f32 D_80394FF0;

/* .bss */


//chcobweb
void func_803863F0(Actor *this)
{
    if(!this->initialized)
    {
        func_802D3CE8(this);

        if (func_8031FF1C(this->unkF4_8 == 1 ? 0xCB : 0xCC))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    if (this->state == 0xC)
    {
        if (actor_animationIsAt(this, 0.95f))
        {
            func_80328B8C(this, 0xD, 0.98f, 1);
            func_80326310(this);
        }
    }
}

//chbigyellowcobweb
void func_803864B0(Actor *this)
{
    if (!this->initialized)
    {
        func_802D3CE8(this);

        if (func_8031FF1C(0xCA))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    if (this->state == 0xF)
    {
        if (actor_animationIsAt(this, 0.9f))
        {
            func_80328B8C(this, 0x10, 0.98f, 1);
            func_80326310(this);
        }
    }
}

void func_80386550(Actor *this)
{
    if (!this->initialized)
    {
        func_802D3CE8(this);

        if (func_8031FF1C(this->unkF4_8 == 1 ? 0xC8 : 0xC9))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    switch (this->state)
    {
        case 9:
        {
            this->pitch -= 2;
            this->position_y--;

            if (func_8032886C(this, 0.95f))
            {
                func_80326310(this);
                func_80328B8C(this, 10, 0.98f, 1);

                this->pitch = 270.f;
            }

            break;
        }
        default:
            break;
    }
}

Actor *func_8038664C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx)
{
    u32    val;
    Actor *actor;

    actor = marker_getActor(marker);
    val = actor->unk10_12;

    func_8033A45C(3, val == 1 ? 1 : 0);
    func_8033A45C(4, val == 0 ? 1 : 0);

    return func_80325888(marker, gfx, mtx, vtx);
}

ParticleEmitter *func_803866D8(s32 a0)
{

    void *ptr;
    s32 colour[3];

    ptr = partEmitList_pushNew(0x28);

    func_802F0D54(ptr);
    particleEmitter_setSprite(ptr, ASSET_710_SPRITE_SPARKLE_PURPLE);
    func_802EFB98(ptr, &D_8039342C);
    particleEmitter_setParticleVelocityRange(ptr, 0.f, 70.f, 0.f, 0.f, 140.f, 0.f);

    colour[0] = a0 * 0xFF;
    colour[1] = 0xFF;
    colour[2] = 0;

    func_802EFFA8(ptr, colour);

    return ptr;
}

void func_80386780(Actor *this)
{
    func_802D4AC0(this, 0x8000C6, 0xC7);
}

void func_803867A8(Actor *this) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 phi_f0;
    s32 phi_v0;
    ParticleEmitter *sp44;

    if (!this->initialized) {
        func_802D3CE8(this);
        this->unk1C[0] = this->position[0];
        this->unk1C[1] = this->position[1];
        this->unk1C[2] = this->position[2];
        this->position[1] -= 300.0f;
        
        this->initialized = TRUE;
        this->alpha_124_19 = 0;

        this->unk60 = this->yaw;
        this->yaw = 0.0f;
        this->velocity[0] = 0.0f;
        return;
    }
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->unk158[0] = func_803866D8(0);
        this->unk158[1] = func_803866D8(1);
        if (func_803203FC(0x86)) {
            ability_unlock(ABILITY_D_SHOCK_JUMP);
            func_80320004(0xC6, TRUE);
            func_80320004(0xC7, TRUE);
        }
    }
    if ((this->unk1C[1] - 150.0f) <= this->position[1]) {
        if (this->alpha_124_19 < 0xFF) {
            if (this->unk38_31 != 0) {
                this->unk38_31--;
            } else {
                phi_v0 = this->alpha_124_19 + 3;
                if(phi_v0 >= 0x100){
                    phi_v0 = 0xFF;
                }
                this->alpha_124_19 = phi_v0;
                if (this->alpha_124_19 < 0xAA){
                    this->velocity[0] += 1.0f;
                    if((this->velocity[0] < 0.0f) || (this->velocity[0] > 19.0f)) {
                        this->velocity[0] = 0.0f;
                        func_8030E6A4(SFX_3F6_UNKNOWN, 0.5f, this->alpha_124_19*0x25 + 0x3840);
                    }
                }
            }
        } else {
            this->velocity[0] += 1.0f;
            if ((this->velocity[0] < 0.0f) || (this->velocity[0] > 19.0f)) {
                this->velocity[0] = 0.0f;
                FUNC_8030E8B4(SFX_3F6_UNKNOWN, 0.5f, 24000, this->position, 100, 2300);

            }
        }
        this->unk60 += 2.5;
        while(this->unk60 >= 360.0f){ this->unk60 -= 360.0f;}

        this->position_y = this->unk1C[1];
        sp5C[1] = sp5C[2] =0.0f;
        sp5C[0] = this->unkF4_8*2;
        ml_vec3f_yaw_rotate_copy(sp5C, sp5C, this->unk60);
        this->position[0] = this->unk1C[0] + sp5C[0];
        this->position[2] = this->unk1C[2] + sp5C[2];
        if (this->marker->unk14_21) {
            sp44 = this->unk158[func_8023DB5C() & 1];
            if (sp44 != NULL) {
                func_802EF9E4(sp44, this->alpha_124_19);
                phi_f0 = this->unk60 - 10.0f;
                while(phi_f0 < 0.0f) {phi_f0 += 360.0f;}

                sp50[1] = this->unk1C[1];
                sp5C[1] = sp5C[2] = 0.0f;
                sp5C[0] = this->unkF4_8*2;
                ml_vec3f_yaw_rotate_copy(sp5C, sp5C, phi_f0);
                sp50[0] = this->unk1C[0] + sp5C[0];
                sp50[2] = this->unk1C[2] + sp5C[2];
                particleEmitter_setPosition(sp44, sp50);
                particleEmitter_setParticleSpawnPositionRange(sp44, -25.0f, 0.0f, -25.0f, 25.0f, 6.0f, 25.0f);
                particleEmitter_emitN(sp44, 1);
                particleEmitter_setParticleSpawnPositionRange(sp44, -75.0f, 0.0f, -75.0f, 75.0f, 6.0f, 75.0f);
                particleEmitter_emitN(sp44, 1);
            }
        }
    } else if (func_8031FF1C(0xC6)) {
        this->position_y = this->unk1C[1];

        if (func_8031FF1C(0xC7)) {
            this->unk38_31 = 0;
            this->alpha_124_19 = 0xFF;
        }
        else{
            this->unk38_31 = 0x18;
            this->alpha_124_19 = 0;
        }
    }
}

void func_80386D20(Actor *this)
{
    func_802D4A9C(this, 0);
}

void chwasp_setState(void)
{
    func_802D68F0(0xC);
    item_set(ITEM_6_HOURGLASS, TRUE);
    mapSpecificFlags_set(1, TRUE);
}

void func_80386D78(Actor *this) {
    f32 phi_f2;

    if (!this->initialized) {
        func_802D3CE8(this);
        this->initialized = TRUE;
        this->unk1C[1] = this->position[1];
        this->position[1] -= 300.0f;
        this->scale = 0.0001f;
        return;
    }

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        if (func_803203FC(0x8A)) {
            ability_unlock(ABILITY_9_FLY);
            mapSpecificFlags_set(0, TRUE);
            this->unk60 = 0.0f;
            this->position[1] = this->unk1C[1];
            this->scale = 1.0f;
        }
    }
    if ((this->unk1C[1] - 150.0f) <= this->position[1]) {
        if (!func_803203FC(0x8A)) {
            if (this->unk60 != 0.0f) {
                this->unk60 -= 1.0f;
                if (this->unk60 == 0.0f) {
                    FUNC_8030E624(SFX_25_METAL_SLIDING_OVER_SMTH, 0.8f, 32000);
                }
            } else {
                this->scale = (this->scale < 1.0) ? this->scale + 0.04 : 1.0;
                if (this->scale < 1.0) {
                    this->yaw_moving += 8.0;
                    if (this->yaw_moving >= 360.0f) {
                        phi_f2 = this->yaw_moving - 360.0f;
                    } else {
                        phi_f2 = this->yaw_moving;
                    }
                    this->yaw_moving = phi_f2;
                    this->yaw = phi_f2;
                }
            }
            if (mapSpecificFlags_get(1) && (item_getCount(ITEM_6_HOURGLASS) == 0)) {
                func_802EE278(this, 8, 0x32, 0x46, 0.24f, 1.2f);
                func_802EE278(this, 9, 0x28, 0x64, 0.24f, 0.8f);
                func_802EE278(this, 0xA, 0x28, 0x28, 0.24f, 1.5f);
                func_802D2FB0(this, 0xA, -0x1E, 0xB4, 2.0f, 0x96, 0x28, 0x64);
                FUNC_8030E624(SFX_11_WOOD_BREAKING_1, 0.8f, 25000);
                func_8030E6D4(SFX_B6_GLASS_BREAKING_1);
                this->position[1] = this->unk1C[1] - 300.0f;
                mapSpecificFlags_set(1, FALSE);
                mapSpecificFlags_set(0, FALSE);
            }
        }
    } else if (mapSpecificFlags_get(0)) {
        this->scale = 0.0001f;
        this->unk60 = 26.0f;
        this->position[1] = this->unk1C[1];
        func_802BAFE4(0x80);
        timedFunc_set_0(3.0f, chwasp_setState);
    }
}

void func_803870DC(Actor *this) {
    s32 phi_v1;
    ParticleEmitter *temp_s5;
    s32 i;
    f32 sp90[3];
    f32 sp84[3];
    u32 phi_a0;
    s32 phi_s4;
    s32 sp70[3];
    f32 sp64[3];
    s32 temp_s7;

    phi_v1 = func_8031FF1C(D_80393452[this->unkF4_8]) 
             || (D_80393466[this->unkF4_8] != 0 && func_803203FC(D_80393466[this->unkF4_8]));

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        if (phi_v1) {
            this->alpha_124_19 = 0xFF;
        } else {
            this->alpha_124_19 = 0;
        }
    }
    if ((this->alpha_124_19 == 0) && (phi_v1)) {
        this->alpha_124_19 = 1;
        this->unk60 = 23.0f;
    }

    phi_a0 = this->alpha_124_19;
    if (phi_a0 == 1) {
        this->unk60 -= 1.0f;
        if (this->unk60 == 0.0f) {
            this->alpha_124_19 = 2;
            func_80324CFC(0, COMUSIC_43_ENTER_LEVEL_GLITTER, 32700);
            func_80324D2C(1.3f, COMUSIC_43_ENTER_LEVEL_GLITTER);
        }
    }

    if (this->alpha_124_19 >= 2U) {
        if (this->alpha_124_19 < 0xFF) {
            phi_v1 = this->alpha_124_19 + 8;
            if (phi_v1 >= 0x100) {
                phi_v1 = 0xFF;
            }
            this->alpha_124_19 = phi_v1;
            temp_s7 = (s32)((f32)this->alpha_124_19 / 5.0) - 0xC;
            if (this->marker->unk14_21 && (temp_s7 > 0)) {
                temp_s5 = partEmitList_pushNew(temp_s7);
                func_8034A174(func_80329934(), 5, sp90);
                func_8034A174(func_80329934(), 6, sp84);
                particleEmitter_setSprite(temp_s5, ASSET_710_SPRITE_SPARKLE_PURPLE);
                func_802EFB70(temp_s5, 0.13f, 0.18f);
                func_802EFB84(temp_s5, 0.08f, 0.13f);
                particleEmitter_setParticleAccelerationRange(temp_s5, -500.0f, -1800.0f, -500.0f, 500.0f, 1800.0f, 500.0f);
                particleEmitter_setSpawnIntervalRange(temp_s5, 0.0f, 0.01f);
                func_802EFEC0(temp_s5, 0.9f, 0.9f);
                particleEmitter_setParticleVelocityRange(temp_s5, -400.0f, 400.0f, -400.0f, 400.0f, -400.0f, 400.0f);
                func_802EF9E4(temp_s5, this->alpha_124_19);
                for(phi_s4 = 0; phi_s4 < temp_s7; phi_s4++){
                    for(i = 0; i < 3; i++){
                        sp64[i] = randf2(sp90[i], sp84[i]);
                    }
                    particleEmitter_setPosition(temp_s5, sp64);
                    sp70[0] = (s32) ((randf() * 130.0f) + 125.0f);
                    sp70[2] = sp70[1] = (s32) ((randf() * 170.0f) + 85.0f);
                    sp70[(randf() > 0.5) ? 2 : 1] = 0;
                    func_802EFFA8(temp_s5, sp70);
                    particleEmitter_emitN(temp_s5, 1);
                }
            }
        }
    }
}

Actor *func_80387560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx)
{
    Actor *actor = marker_getActor(marker);
    u32 i;

    for (i = 0; i != 10; i++)
        func_8033A45C(i + 1, actor->unkF4_8 + 1 == i + 2);

    return func_80325E78(marker, gfx, mtx, vtx);
}

//circular grate
void func_803875F0(Actor * this)
{
    func_802D3D74(this);

    if (!this->unk16C_4)
    {
        if (func_8031FF1C(0x1E))
        {
            marker_despawn(this->marker);
            return;
        }

        if (mapSpecificFlags_get(0))
        {
            this->unk1C_y = this->position_y;
            func_802BAFE4(0x2A);
            func_80320004(0x1E, TRUE);
            this->unk16C_4 = TRUE;
            this->unk38_31 = 0x0C;
        }
    }
    else
    {
        if (this->unk38_31)
        {
            this->unk38_31--;

            if (this->unk38_31)
                return;

            func_802D4830(this, 0x9A, 0.5f);
        }

        this->position_y += 4.0f;

        if (this->position_y > this->unk1C_y + 380.0f)
        {
            func_802D48B8(this);
            FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 17000);
            marker_despawn(this->marker);
        }
    }
}


//chnotedoor_update
void func_80387730(Actor *this) {
    f32 spAC[3];
    ParticleEmitter *temp_s5;
    f32 sp9C[3];
    f32 sp90[3];
    f32 sp84[3];
    s32 i;
    f32 phi_f20;
    s32 phi_s4;
    s32 sp6C[3];
    f32 sp60[3];

    func_802D3D74(this);
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->alpha_124_19 = 0xFF;
        this->unk1C[1] = 0.0f;
        this->unk1C[2] = 3.5f;
        if (func_8031FF1C(this->unkF4_8 + 0x39)) {
            marker_despawn(this->marker);
            return;
        }
        if ((this->unkF4_8 >= 2U) && (this->unkF4_8 < 8U) && func_803203FC(D_80393490[this->unkF4_8])) {
            marker_despawn(this->marker);
            return;
        }
    }

    this->unk1C[1] += this->unk1C[2];
    if (this->unk1C[1] >= 255.0f) {
        this->unk1C[1] = 255.0f;
        this->unk1C[2] = -3.5f;
    }
    if (this->unk1C[1] <= 0.0f) {
        this->unk1C[1] = 0.0f;
        this->unk1C[2] = 3.5f;
    }
    if (!func_8031FF1C(this->unkF4_8 + 0x39) && ability_isUnlocked(ABILITY_13_1ST_NOTEDOOR)) {
        player_getPosition(spAC);
        if ((ml_vec3f_distance(spAC, this->position) < 500.0f) && (func_803114C4() != 0xF64)) {
            func_802FACA4(0xC);
        }
        if (notescore_getTotal() >= D_8039347A[this->unkF4_8]) {
            if (this->marker->unk14_21) {
                func_8032BC60(this, 5, sp90);
                func_8032BC60(this, 6, sp84);
                sp9C[0] = (sp90[0] + sp84[0]) / 2;
                sp9C[2] = (sp90[2] + sp84[2]) / 2;
                phi_f20 = 140.0f;
            } else {
                sp9C[0] = this->position[0];
                sp9C[2] = this->position[2];
                phi_f20 = 290.0f;
            }
            sp9C[1] = this->position[1];
            if ((ml_vec3f_distance(spAC, sp9C) < phi_f20) || (this->alpha_124_19 != 0xFF)) {
                if (this->alpha_124_19 == 0xFF) {
                    func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 32700);
                    func_80324D2C(2.4f, COMUSIC_43_ENTER_LEVEL_GLITTER);
                    func_8028F918(2);
                }
                if (this->alpha_124_19 < 7U) {
                    this->alpha_124_19 = 0;
                } else {
                    this->alpha_124_19 -= 7;
                }
                if (this->alpha_124_19 == 0) {
                    func_80320004(this->unkF4_8 + 0x39, TRUE);
                    marker_despawn(this->marker);
                    func_8028F918(0);
                    func_8028F66C(0x35);
                    return;
                }
                if (this->marker->unk14_21) {
                    temp_s5 = partEmitList_pushNew((s32)((f32) this->alpha_124_19 / 11.0));
                    sp6C[2] = 0;
                    particleEmitter_setSprite(temp_s5, ASSET_710_SPRITE_SPARKLE_PURPLE);
                    func_802EFB70(temp_s5, 0.13f, 0.18f);
                    func_802EFB84(temp_s5, 0.08f, 0.13f);
                    particleEmitter_setParticleAccelerationRange(temp_s5, -10.0f, 0.0f, -10.0f, 10.0f, 1600.0f, 10.0f);
                    particleEmitter_setSpawnIntervalRange(temp_s5, 0.0f, 0.01f);
                    func_802EFEC0(temp_s5, 1.4f, 1.4f);
                    particleEmitter_setParticleVelocityRange(temp_s5, -100.0f, 100.0f, -100.0f, 100.0f, 0.0f, 100.0f);
                    func_802EF9E4(temp_s5, this->alpha_124_19);
                    for(phi_s4 = 0; phi_s4 < (s32) ((f32)this->alpha_124_19 / 11.0); phi_s4++){
                        for(i = 0; i < 3; i++){
                            sp60[i] = randf2(sp90[i], sp84[i]);
                        }
                        particleEmitter_setPosition(temp_s5, sp60);
                        sp6C[0] = (s32) ((randf() * 60.0f) + 195.0f);
                        sp6C[1] = (s32) ((randf() * 130.0f) + 125.0f);
                        func_802EFFA8(temp_s5, sp6C);
                        particleEmitter_emitN(temp_s5, 1);
                    }
                }
            }
        } else if ((this->unkF4_8 >= 2) && (ml_vec3f_distance(spAC, this->position) < 290.0f)) {
            func_80356520(0xB0);
        }
    }
}



//chnotedoor_draw
Actor *func_80387DA8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx)
{
    // TODO: Think of a better way of doing this, similar to the SM64 one
    #define NUM_NOTE_DOORS (12)
    #define noteDoorIdx    unkF4_8
    #define opacityTimer   unk1C[1]

    Actor *actor;
    void  *var1;
    void  *var2;
    s32    i, idx;

    actor = marker_getActor(marker);
    var1  = func_8034C2C4(marker, 0x1F3);
    var2  = func_8034C2C4(marker, 0x1F2);

    /**
     * Sets opacity of the "note" symbol
     */
    if (var2)
        func_8034E0FC(var2, actor->opacityTimer);

    /**
     * Sets opacity of note door numbers
     */
    if (var1)
        func_8034E0FC(var1, 0xFF - (s32)actor->opacityTimer);

    /**
     * Hides all note door graphics that don't match this note door's index
     * e.g. for the 50 note door, hides 180, 260, etc.
     */
    for (i = 0; i != NUM_NOTE_DOORS; i++)
        func_8033A45C(i + 1, actor->noteDoorIdx + 1 == i + 2);

    /**
     * Draw the note door
     */
    return func_80325E78(marker, gfx, mtx, vtx);
}

void func_80387E94(s32 arg0)
{
    ActorMarker *marker;
    Actor *actor1;
    Actor *actorNew;
    Actor *actor2;

    marker = reinterpret_cast(ActorMarker *, arg0);
    actor1   = marker_getActor(marker);
    actorNew = func_8032813C(0x25A, actor1->position, actor1->yaw);

    // Grab the same pointer again for good measure :^)
    actor2 = marker_getActor(marker);

    actorNew->unkF4_20 = actor2->unk78_13;

    actor2->unk100 = actorNew->marker;

    actorNew->unk1C[0] = 0;
}

void func_80387F1C(void)
{
    f32 tmp[3];

    func_802BAFE4(0x7B);

    if (func_80304E24(400, tmp))
    {
        jiggySpawn(JIGGY_35_LAIR_CC_WITCH_SWITCH, tmp);
        // FIXME: macro?
        func_802C3F04((GenMethod_4)func_802C4140, ACTOR_4C_STEAM, *(s32 *)&tmp[0], *(s32 *)&tmp[1], *(s32 *)&tmp[2]);
    }
}

void func_80387F78(Actor *this, u32 flag)
{
    if (this->unk1C[0] != 2.f)
    {
        if (this->unk1C[0] != 0 && func_8031FF1C(0x9B))
        {
            u32 flagState = func_8031FF1C(flag);
            func_80320004(flag, TRUE);

            if (flagState == FALSE
                && !jiggyscore_isSpawned(JIGGY_35_LAIR_CC_WITCH_SWITCH)
                && func_8031FF1C(0x9C)
                && func_8031FF1C(0x9D))
            {
                func_8025A6EC(0x2D, 0x7FFF);
                timedFunc_set_0(0.9f, func_80387F1C);
            }
        }

        if (func_8031FF1C(flag))
        {
            this->position_y -= 4.5; // f64

            if (this->position_y < this->unk1C[1] - 51.f)
            {
                this->position_y = -1000.f;
                this->unk1C[0] = 2.f;
            }
        }
    }
}

void func_803880BC(Actor *this)
{

    if (!this->unk16C_4)
    {
        func_802D3CE8(this);

        this->unk16C_4 = TRUE;

        this->unk1C[1] = this->position_y;
        this->position_y -= 51.f;
        this->unk1C[0] = 0;

        func_802C3C88((GenMethod_1)func_80387E94, reinterpret_cast(s32, this->marker));

        if (func_803203FC(0xBC) && !func_8031FF1C(0x9A))
            FUNC_8030E624(SFX_3F6_UNKNOWN, 0.75f, 30000);
    }

    if (func_8031FF1C(0x9B))
    {
        if (!func_8031FF1C(0x9C))
        {
            this->position_y = this->unk1C[1];
            actor_collisionOn(this);
        }

        if (this->unk100 != NULL && !func_8031FF1C(0x9D))
        {
            Actor *actor = marker_getActor(this->unk100);
            actor->position_y = this->unk1C[1];
            actor_collisionOn(actor);
        }
    }

    if (func_803203FC(0xBC) && !func_8031FF1C(0x9B))
    {
        this->position_y += 1.7;

        if (this->position_y >= this->unk1C[1])
        {
            this->position_y = this->unk1C[1];
            func_80320004(0x9B, TRUE);
        }

        if (this->unk100 != NULL)
        {
            Actor *actor = marker_getActor(this->unk100);
            actor->position_y = this->position_y;
        }
    }

    func_80387F78(this, 0x9C);
}

void func_8038824C(Actor *this)
{
    func_802D3CE8(this);
    func_80387F78(this, 0x9D);
}


void func_80388278(Actor *this)
{
    void func_802F9D38(s32);

    if (!this->unk44_31)
        return;

    func_802F9D38(this->unk44_31);
    this->unk44_31 = 0;
}

void func_803882B0(Actor *this)
{
    if (!this->unk16C_4)
    {
        func_802D3D74(this);

        this->unk16C_4 = TRUE;

        if (func_8031FF1C(0x48))
            this->pitch = 90.f;

        this->unk60 = 0;
    }

    if (this->pitch == 90.f || !func_803203FC(0xBB))
        return;

    if (this->pitch == 0)
        func_802D4830(this, 0x18, 0.5f);

    this->pitch += 1.1;

    if (this->unk60 == 0 && this->pitch > 42.f)
    {
        this->unk60 = 1.f;
        func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
    }

    if (this->pitch > 90.f)
    {
        this->pitch = 90.f;
        func_80320004(0x48, TRUE);
        func_802D48B8(this);
    }
}

void func_80388404(enum bkprog_e flag, enum sfx_e sfx, f32 a2, s32 a3)
{
    if (func_8031FF1C(flag) == FALSE)
        func_8030E6A4(sfx, a2, a3);

    func_80320004(flag, TRUE);
}

void func_80388450(Actor *actor1, Actor *actor2)
{
    f32 vec1[3];
    f32 vec2[3];
    void *actor3 = func_80304C38(0x22A, actor1);
    s32 val = func_80304DA8(actor3);

    actor2->yaw = val;
    actor1->yaw = val;

    vec1[0] = actor1->unk1C[0] + 252.f;
    vec1[1] = 0;
    vec1[2] = 0;

    ml_vec3f_yaw_rotate_copy(vec2, vec1, actor1->yaw);
    func_80304D68(actor3, vec1);

    actor1->position_x = vec1[0] - vec2[0];
    actor1->position_z = vec1[2] - vec2[2];
    actor2->position_x = vec1[0] + vec2[0];
    actor2->position_z = vec1[2] + vec2[2];
}

void func_80388524(Actor *this) {
    s32 sp34;
    Actor *sp30;
    ParticleEmitter *sp2C;
    Actor *sp28;

    sp34 = func_802D677C(-1) 
             && (func_802D677C(-1) == map_get())
             && (func_802D67AC(-1) >= 8)
             && (func_802D67AC(-1) < 0x12)
             && (func_802D67DC(-1) == this->modelCacheIndex)
             ;

    func_802D3D74(this);
    if (!this->initialized) {
        if (!sp34) {
            switch(this->modelCacheIndex){
                case 0x2E5://L80388630
                    if (!func_8031FF1C(0xE2) && func_8038EAE0(0xA)) {
                        func_80320004(0xE2, TRUE);
                    }
                    break;

                case 0x20e: //L80388660
                    if (!func_8031FF1C(0x31) && func_8038EAE0(1)) {
                        func_80320004(0x31, TRUE);
                    }
                    break;

                case 0x226: //L80388690
                    if (!func_8031FF1C(0x36) && func_8038EAE0(6)) {
                        func_80320004(0x36, TRUE);
                    }
                    break;

                case 0x212: //L803886C0
                    if (!func_8031FF1C(0x33) && func_8038EAE0(3)) {
                        func_80320004(0x33, TRUE);
                    }
                    break;

                case 0x211: //L803886F0
                    if (!func_8031FF1C(0x32) && func_8038EAE0(2)) {
                        func_80320004(0x32, TRUE);
                    }
                    break;

                case 0x210: //L80388720
                    if (!func_8031FF1C(0x34) && func_8038EAE0(4)) {
                        func_80320004(0x34, TRUE);
                    }
                    break;

                case 0x20f: //L80388750
                    if (!func_8031FF1C(0x38) && func_8038EAE0(8)) {
                        func_80320004(0x38, TRUE);
                    }
                    break;

                case 0x228: //L80388780
                    if (!func_8031FF1C(0x37) && func_8038EAE0(7)) {
                        func_80320004(0x37, TRUE);
                    }
                    break;

                case 0x234: //L803887B0
                    if (!func_8031FF1C(0x39) && func_8038EAE0(9)) {
                        func_80320004(0x39, TRUE);
                    }
                    break;

                case 0x235: //L803887E0
                    if (!func_8031FF1C(0x35) && func_8038EAE0(5)) {
                        func_80320004(0x35, TRUE);
                    }
                    break;
            }//L80388808
        }
        this->initialized = TRUE;
    }
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        switch(this->modelCacheIndex){
            case 0x2E5: //L80388880
                if (func_8031FF1C(0xE2) && (this->state == 0x19)) {
                    func_80328B8C(this, 0x1B, 0.999f, 1);
                }
                break;

            case 0x20e://L803888C0
                if(func_8031FF1C(0x31)){
                    this->yaw = 270.0f;
                }
                break;
                
            case 0x226://L803888DC
                if(func_8031FF1C(0x36)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 300.0f;
                break;
                
            case 0x212://L80388914
                if(func_8031FF1C(0x33)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 365.0f;
                break;
                
            case 0x211://L80388948
                if(func_8031FF1C(0x32)){
                    this->pitch = 90.0f;
                }
                break;
                
            case 0x210://L8038896C
                if(func_8031FF1C(0x34)){
                    this->yaw = 90.0f;
                }
                break;
                
            case 0x20f://L80388990
                if(func_8031FF1C(0x38)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 290.0f;
                break;
                
            case 0x228://L803889C8
                if(func_8031FF1C(0x37)){
                    this->yaw = 90.0f;
                }
                break;
                
            case 0x234://L803889EC
                if(func_8031FF1C(0x39)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 270.0f;
                break;
                
            case 0x235://L80388A24
                    sp30 = func_80326EEC(0x236);
                    if(func_8031FF1C(0x35)){
                        marker_despawn(this->marker);
                        marker_despawn(sp30->marker);
                        return;
                    }
                    this->unk1C[0] = 0.0f;
                    func_80388450(this, sp30);
                break;
        
        }//L80388A70
    }

    if (sp34) {
        if (func_802D680C(-1) != 0) {
            func_802D680C(func_802D680C(-1) - 1);
            return;
        }

        switch(this->modelCacheIndex){
            case 0x2E5:
                switch (this->state) {
                    case 0x19: //L80388B34
                        func_80328B8C(this, 0x1A, 0.0f, 1);
                        func_8025A6EC(JINGLE_END_OF_INTRO, -1);
                        break;

                    case 26: //L80388B54
                        if (actor_animationIsAt(this, 0.4f)) {
                            FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32675);
                        }
                        if (actor_animationIsAt(this, 0.42f)) {
                            func_8030E6D4(SFX_1B_EXPLOSION_1);
                        }
                        if (actor_animationIsAt(this, 0.97f)) {
                            func_80328B8C(this, 0x1B, 0.999f, 1);
                            func_80320004(0xE2, 1);
                            func_8030E6D4(SFX_6C_LOCKUP_CLOSING);
                        }
                        if (animctrl_getAnimTimer(this->animctrl) < 0.68) {
                            sp2C = partEmitList_pushNew(3U);
                            particleEmitter_setSprite(sp2C, ASSET_70D_SPRITE_SMOKE_1);
                            particleEmitter_setStartingFrameRange(sp2C, 1, 6);
                            func_802EFFA8(sp2C, D_803934A0);
                            func_802EF9E4(sp2C, 0x3C);
                            particleEmitter_setPosition(sp2C, this->position);
                            particleEmitter_setPositionAndVelocityRanges(sp2C, &D_803934D4);
                            func_802EFB98(sp2C, &D_803934AC);
                            particleEmitter_emitN(sp2C, 3);
                        }
                        break;
                    case 27://L80388FB8
                        break;
                }
                break;

            case 0x20e://L80388C7C
                this->yaw += 1.4;
                if (this->yaw > 270.0f) {
                    this->yaw = 270.0f;
                    func_80388404(0x31, SFX_6C_LOCKUP_CLOSING, 1.0f, 15000);
                }
                break;

            case 0x226://L80388CDC
                this->position[1] += 5.0f;
                if (this->unk1C[1] < this->position[1]) {
                    func_80388404(0x36, SFX_6C_LOCKUP_CLOSING, 1.0f, 15000);
                    func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case 0x212://L80388D34
                this->position[1] += 5.0f;
                if (this->unk1C[1] < this->position[1]) {
                    func_80388404(0x33, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 17000);
                    func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case 0x211://L80388D8C
                this->pitch += 1.4;
                if (this->pitch > 90.0f) {
                    this->pitch = 90.0f;
                    func_80388404(0x32, SFX_6C_LOCKUP_CLOSING, 1.0f, 15000);
                }
                break;

            case 0x210://L80388DDC
                this->yaw += 1.4;
                if (this->yaw > 90.0f) {
                    this->yaw = 90.0f;
                    func_80388404(0x34, SFX_6C_LOCKUP_CLOSING, 1.0f, 15000);
                }
                break;

            case 0x20f://L80388E2C
                this->position[1] += 5.0f;
                if (this->unk1C[1] < this->position[1]) {
                    func_80388404(0x38, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 17000);
                    func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case 0x228://L80388E84
                this->yaw += 1.4;
                if (this->yaw > 90.0f) {
                    this->yaw = 90.0f;
                    func_80388404(0x37, SFX_6C_LOCKUP_CLOSING, 1.0f, 20000);
                }
                break;

            case 0x234://L80388ED4
                this->position[1] += 3.2;
                if (this->unk1C[1] <= this->position[1]) {
                    func_80388404(0x39, SFX_6C_LOCKUP_CLOSING, 1.0f, 20000);
                    func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case 0x235://L80388F34
                {
                    sp28 = func_80326EEC(0x236);
                    this->unk1C[0] += 3.6;
                    if (this->unk1C[0] > 250.0f) {
                        func_80388278(this);
                        marker_despawn(this->marker);
                        marker_despawn(sp28->marker);
                        func_80320004(0x35, TRUE);
                        return;
                    }
                    func_80388450(this, sp28);
                }
                break;
            default:
                break;
        }
    }
}

void func_80388FC8(Actor *this)
{
    func_802D3D74(this);

    if (!this->initialized)
    {
        this->initialized = TRUE;

        this->unk1C[1] = this->position_y;
        this->position_y -= 500.f;

        this->unk60 = 0;

        if (func_803203FC(0x7D))
        {
            this->position_y = this->unk1C[1];
            this->unk60 = 1.f;
        }
    }

    if (this->unk60)
        return;

    if (!this->unk16C_4)
    {
        if (func_8031FF1C(this->modelCacheIndex == 0x215 ? BKPROG_1F_CC_LOBBY_PIPE_1_RAISED : BKPROG_20_CC_LOBBY_PIPE_2_RAISED))
        {
            this->position_y = this->unk1C[1];
            return;
        }

        if (mapSpecificFlags_get(1))
        {
            if (this->modelCacheIndex == 0x215)
            {
                func_802BAFE4(0x2B);
                if (1);  // oof
            }

            func_80320004(this->modelCacheIndex == 0x215 ? BKPROG_1F_CC_LOBBY_PIPE_1_RAISED : BKPROG_20_CC_LOBBY_PIPE_2_RAISED, TRUE);

            this->unk16C_4 = 1;
            this->unk38_31 = 12;
        }
    }
    else
    {
        if (this->unk38_31)
        {
            this->unk38_31--;

            if (this->unk38_31)
                return;

            if (this->modelCacheIndex == 0x215)
            {
                FUNC_8030E624(SFX_25_METAL_SLIDING_OVER_SMTH, 0.6f, 28000);
                func_802D4830(this, 0x3EC, 0.1f);
            }
        }

        this->position_y += 6.f;

        if (this->position_y >= this->unk1C[1])
        {
            this->position_y = this->unk1C[1];

            if (this->modelCacheIndex == 0x215)
            {
                func_802D48B8(this);
                func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
            }

            this->unk60 = 1.f;
        }
    }
}

void func_80389204(Actor *this)
{
    func_802D3D74(this);

    if (!this->initialized)
    {
        this->initialized = TRUE;

        this->unk1C[1] = this->position_y;
        this->position_y -= 280.f;
        this->unk60 = 0;

        if (func_803203FC(0x7E))
        {
            this->position_y = this->unk1C[1];
            this->unk60 = 1.f;
        }
    }

    if (this->unk60)
        return;

    if (!this->unk16C_4)
    {
        if (func_8031FF1C(BKPROG_21_CC_LOBBY_PIPE_3_RAISED))
        {
            this->position_y = this->unk1C[1];
            return;
        }

        if (mapSpecificFlags_get(2))
        {
            func_802BAFE4(0x2C);
            func_80320004(BKPROG_21_CC_LOBBY_PIPE_3_RAISED, TRUE);

            this->unk16C_4 = 1;
            this->unk38_31 = 12;
        }
    }
    else
    {
        if (this->unk38_31)
        {
            this->unk38_31--;

            if (this->unk38_31)
                return;
            FUNC_8030E624(SFX_25_METAL_SLIDING_OVER_SMTH, 0.7f, 28000);
            func_802D4830(this, 0x3EC, 0.2f);
        }

        this->position_y += 3.f;

        if (this->position_y >= this->unk1C[1])
        {
            this->position_y = this->unk1C[1];

            func_802D48B8(this);
            func_8030E540(SFX_7F_HEAVYDOOR_SLAM);

            this->unk60 = 1.f;
        }
    }
}

void func_803893B8(Actor *this)
{
    func_802D3D74(this);

    if (!this->unk16C_4)
    {
        this->unk16C_4 = TRUE;

        if (jiggyscore_isCollected(JIGGY_37_LAIR_BGS_WITCH_SWITCH))
        {
            marker_despawn(this->marker);
            return;
        }

        this->unk1C[1] = this->position_y;
    }

    if (jiggyscore_isCollected(JIGGY_37_LAIR_BGS_WITCH_SWITCH))
    {
        f32 *posY = &this->position_y;

        if (this->unk1C[1] == *posY)
            func_802D4830(this, 0x9A, 0.5f);

        this->position_y += 3.f;

        if (this->position_y > this->unk1C[1] + 200.f)
        {
            func_802D48B8(this);
            FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 29000);
            marker_despawn(this->marker);
        }
    }
}

void func_803894B0(Actor *this)
{
    void func_802EE2E8(Actor *, s32, s32, s32, f32, f32, f32);
    func_802D3D74(this);

    if (!this->unk16C_4)
    {
        this->unk16C_4 = TRUE;
        this->unk1C[0] = 0;

        if (func_8031FF1C(BKPROG_A1_STATUE_HAT_OPEN))
        {
            marker_despawn(this->marker);
            return;
        }

        this->unk1C[0] = func_803203FC(0xBD) ? 22 : 0;
    }

    if (!this->unk1C[0])
        return;

    if (--this->unk1C[0] == 0)
    {
        func_80320004(0xA1, TRUE);
        timed_playSfx(0.5f, SFX_3F9_UNKNOWN, 1.f, 32000);
        FUNC_8030E624(SFX_114_BRICKWALL_BREAKING, 0.8f, 32000);
        func_802EE2E8(this, 0xB, 0x19, 0x000, 0.6f, 1.8f, 3.f);
        func_802EE2E8(this, 0xB, 0x17, 0x0B4, 0.5f, 1.55f, 3.f);
        func_802EE2E8(this, 0xB, 0x15, 0x168, 0.4f, 1.3f, 3.f);
        func_802EE2E8(this, 0xB, 0x13, 0x21C, 0.3f, 1.05f, 3.f);
        func_802EE2E8(this, 0xB, 0x11, 0x2D0, 0.2f, 0.8f, 3.f);
        marker_despawn(this->marker);
    }
}

void func_803896D4(Actor *this)
{
    func_802D4A9C(this, 0);
}

void func_803896F4(Actor *this)
{
    func_802D4A9C(this, 1);
}

void func_80389714(Actor *this)
{
    func_802D4A9C(this, 2);
}

void func_80389734(Actor *this)
{
    func_802D4AC0(this, 0x800022, 0x23);
}

void func_8038975C(Actor *this)
{
    func_802D4AC0(this, 0x800024, 0x25);
}

void func_80389784(Actor *this)
{
    func_802D4AC0(this, 0x800026, 0x27);
}

void func_803897AC(Actor *this)
{
    func_802D4AC0(this, 0x800053, 0x54);
}

void func_803897D4(s32 arg0)
{
    ActorMarker *marker1, *marker2;
    Actor *actor1, *actor2;

    marker1 = reinterpret_cast(ActorMarker *, arg0);
    actor1 = marker_getActor(marker1);

    actor1 = func_8032813C(0x258, actor1->position, actor1->yaw);

    // Grab the same pointer again for good measure
    actor2 = marker_getActor(marker1);

    actor1->scale = actor2->scale;
}

void func_8038982C(Actor *this)
{
    if (!this->initialized)
    {
        func_802D3CE8(this);
        actor_collisionOff(this);

        this->initialized = TRUE;

        if (!func_8031FF1C(BKPROG_9E_CRYPT_COFFIN_LID_OPEN))
            func_802C3C88((GenMethod_1)func_803897D4, reinterpret_cast(s32, this->marker));
    }
}

void func_80389898(Actor *this)
{
    func_802D3CE8(this);

    switch (this->state)
    {
        case 18:
        {
            if (this->unk10_12)
            {
                func_80328AC8(this, 0x13);
                func_803298AC(this);
                func_80320004(BKPROG_9E_CRYPT_COFFIN_LID_OPEN, TRUE);
            }

            break;
        }
        case 19:
        {
            if (func_8032886C(this, 0.7f))
                marker_despawn(this->marker);

            break;
        }
        default:
            break;
    }
}

void func_80389934(Actor *this)
{
    if (!this->unk16C_4)
    {
        func_802D3CE8(this);
        actor_collisionOff(this);

        this->unk16C_4 = TRUE;

        if (func_8031FF1C(BKPROG_A2_GV_LOBBY_COFFIN_OPEN))
            func_80328B8C(this, 0x18, 0.999f, 1);
    }

    switch (this->state)
    {
        case 21:
        {
            if (func_803203FC(0xBE))
            {
                this->unk1C[0] = 25;

                func_80328AC8(this, 0x16);
                func_80320004(BKPROG_A2_GV_LOBBY_COFFIN_OPEN, TRUE);
            }

            break;
        }
        case 22:
        {
            if (--this->unk1C[0] == 0)
            {
                func_80328AC8(this, 0x17);
                func_803298AC(this);
                FUNC_8030E624(SFX_3F6_UNKNOWN, 0.6f, 32000);
                func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
            }

            break;
        }
        case 23:
        {
            if (func_8032886C(this, 0.95f))
            {
                func_80328B8C(this, 0x18, 0.999f, 1);
                FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 26000,);
            }

            break;
        }
        case 24: // unused
        default:
            break;
    }
}

f32 func_80389AAC(Actor *this, f32 a1)
{
    // defs
    f32   func_8034A754(f32, f32);
    void *func_80309B48(f32 *, f32 *, f32 *, u32);

    f32 vec3[3]; // $sp + 54
    f32 vec2[3]; // $sp + 48
    f32 vec1[3]; // $sp + 3C

    if (!this->unk38_31)
    {
        this->unk38_31 = 1;
        this->unk1C[1] = 71;
    }

    this->position_x -= 26;

    vec1[0] = vec3[0] = this->position_x;
    vec3[1] = this->position_y;
    vec1[2] = vec3[2] = this->position_z;

    this->position_y += this->unk1C[1];

    this->unk1C[1] -= 7.0; // f64

    vec1[1] = this->position_y - 400;

    if (this->unk1C[1] < 0 && func_80309B48(vec3, vec1, vec2, 0) && this->position_y <= vec1[1])
    {
        this->position_y = vec1[1] + 6;

        switch (this->unk38_31)
        {
            case 1:
            {
                this->unk38_31 = 2;
                this->unk1C[1] = 38;

                break;
            }
            case 2:
            {
                this->unk38_31 = 3;
                this->unk1C[1] = 11;

                break;
            }
            case 3:
            {
                func_80328A84(this, 5);

                break;
            }
            default:
                break;
        }

        func_8030E878(SFX_82_METAL_BREAK, func_8034A754(0.93f, 1.07f), 32760, this->position, 100, 1350.0f);

        this->unk60 = 1;
    }

    a1 -= 4.5; // f64

    while (a1 < 0)
        a1 += 360;

    return a1 <= 230 ? 230 : a1;
}

void func_80389D08(Actor *this)
{
    if (!this->unk16C_4)
    {
        func_802D3CE8(this);

        this->unk16C_4 = TRUE;
        this->unk60 = 0;

        if (func_8031FF1C(0xA5))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    switch (this->state)
    {
        case 1:
        {
            if (this->unk60)
            {
                func_80328AC8(this, 4);

                this->unk38_31 = 0;
                this->unk60 = 0;
            }

            break;
        }
        case 4:
        {
            this->pitch = func_80389AAC(this, this->pitch);
            this->roll--;

            break;
        }
        case 5:
        {
            func_80326310(this);

            break;
        }
        default:
            break;
    }
}

Actor *func_80389E10(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    f32 sp90[3];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    static u8 D_80395350[0x10]; //padding
    static s32 D_80395360;


    this = func_80325E78(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && (this->unk60 != 0.0f)) {
        func_8034A174((struct5Bs *) marker->unk44, 5, sp84);
        func_8034A174((struct5Bs *) marker->unk44, 6, sp78);
        
        for(D_80395360 = 0; D_80395360 < 8; D_80395360++){
            sp6C[0] =sp6C[2] = 0.0f;
            sp6C[1] = randf2(5.0f, 20.0f);

            sp90[0] = sp84[0] + ((sp78[0] - sp84[0]) * randf());
            sp90[1] = sp84[1];
            sp90[2] = sp84[2] + ((sp78[2] - sp84[2]) * randf());
            

            func_802EE6CC(sp90, sp6C, D_80393504, 1, 0.3f, 50.0f, 180, randi2(130, 200), 0);
        };
    }
    return this;
}

void func_80389FA8(Actor *this, enum bkprog_e flag)
{
    if (!this->initialized)
    {
        func_802D3D54(this);

        if (func_8031FF1C(flag))
            marker_despawn(this->marker);
    }
}

void func_80389FF4(Actor *this)
{
    func_80389FA8(this, BKPROG_C2_GRATE_TO_RBB_PUZZLE_OPEN);
}

void func_8038A014(Actor *this)
{
    func_80389FA8(this, BKPROG_C3_ICE_BALL_TO_CHEATO_BROKEN);
}

void func_8038A034(Actor *this)
{
    this->unk124_9 = 2;

    func_80389FA8(this, BKPROG_C4_STATUE_EYE_BROKEN);
}

void func_8038A064(Actor *this)
{
    func_80389FA8(this, BKPROG_C5_RAREWARE_BOX_BROKEN);
}

void func_8038A084(Actor *this)
{
    func_80389FA8(this, BKPROG_CD_GRATE_TO_WATER_SWITCH_3_OPEN);
}

void func_8038A0A4(Actor *this)
{
    func_80389FA8(this, BKPROG_CE_GRATE_TO_MMM_PUZZLE_OPEN);
}

void func_8038A0C4(void)
{
    spawnableActorList_add(&D_80392F40, actor_new, 0x18628);
    spawnableActorList_add(&D_80392F64, actor_new, 0x18608);
    spawnableActorList_add(&D_803932E8, actor_new, 0x8600);
    spawnableActorList_add(&D_80393408, actor_new, 0x96C0);
    spawnableActorList_add(&D_80392F88, actor_new, 0x8600);
    spawnableActorList_add(&D_80392FAC, actor_new, 0x8600);
    spawnableActorList_add(&D_80392FD0, actor_new, 0x8600);
    spawnableActorList_add(&D_80393018, actor_new, 0x8600);
    spawnableActorList_add(&D_8039303C, actor_new, 0x8600);
    spawnableActorList_add(&D_80393060, actor_new, 0x8604);
    spawnableActorList_add(&D_803931EC, actor_new, 0x8600);
    spawnableActorList_add(&D_80393210, actor_new, 0x8600);
    spawnableActorList_add(&D_80392EF8, actor_new, 0x8600);
    spawnableActorList_add(&D_8039339C, actor_new, 0x8600);
    spawnableActorList_add(&D_803933C0, actor_new, 0x8600);
    spawnableActorList_add(&D_80392DB4, actor_new, 0x8608);
    spawnableActorList_add(&D_80392DD8, actor_new, 0x8608);
    spawnableActorList_add(&D_80392DFC, actor_new, 0x8608);
    spawnableActorList_add(&D_80392E20, actor_new, 0x8608);
    spawnableActorList_add(&D_80392E44, actor_new, 0x8608);
    spawnableActorList_add(&D_80392E68, actor_new, 0x8608);
    spawnableActorList_add(&D_80392E8C, actor_new, 0x8608);
    spawnableActorList_add(&D_803930F0, actor_new, 0x8600);
    spawnableActorList_add(&D_80393234, actor_new, 0x8600);
    spawnableActorList_add(&D_80393258, actor_new, 0x8600);
    spawnableActorList_add(&D_80392FF4, actor_new, 0x8600);
    spawnableActorList_add(&D_8039327C, actor_new, 0x8600);
    spawnableActorList_add(&D_803932A0, actor_new, 0x8600);
    spawnableActorList_add(&D_803932C4, actor_new, 0x8600);
    spawnableActorList_add(&D_8039315C, actor_new, 0x8600);
    spawnableActorList_add(&D_80393180, actor_new, 0x8600);
    spawnableActorList_add(&D_803931A4, actor_new, 0x8600);
    spawnableActorList_add(&D_8039330C, actor_new, 0x8600);
    spawnableActorList_add(&D_80393330, actor_new, 0x8600);
    spawnableActorList_add(&D_80393114, actor_new, 0);
    spawnableActorList_add(&D_80393138, actor_new, 0x8600);
    spawnableActorList_add(&D_803930CC, actor_new, 0x8600);
    spawnableActorList_add(&D_803931C8, actor_new, 0x28600);
    spawnableActorList_add(&D_80393560, actor_new, 0x97AA);
    spawnableActorList_add(&D_80393584, actor_new, 0x87AA);
    spawnableActorList_add(&D_803933E4, actor_new, 0x8608);
    spawnableActorList_add(&D_80393378, actor_new, 0x8640);
    spawnableActorList_add(&D_803947B0, actor_new, 0xA1480);
    spawnableActorList_add(&D_803947D4, actor_new, 0xA1480);
    spawnableActorList_add(&D_80393730, actor_new, 0x140);
    spawnableActorList_add(&D_80394A80, actor_new, 0);
    spawnableActorList_add(&D_80394AB0, actor_new, 0x44);
    spawnableActorList_add(&D_80392EB0, actor_new, 0x8608);
    spawnableActorList_add(&D_80393084, actor_new, 0x8680);
    spawnableActorList_add(&D_80392ED4, actor_new, 0x8608);
    spawnableActorList_add(&D_803930A8, actor_new, 0xC680);
    spawnableActorList_add(&D_80394870, actor_new, 0x1A0);
    spawnableActorList_add(&D_80394894, actor_new, 0x1A0);
    spawnableActorList_add(&D_803948B8, actor_new, 0x1A0);
    spawnableActorList_add(&D_80394910, actor_new, 0x10C0);
    spawnableActorList_add(&D_80394934, actor_new, 200);
    spawnableActorList_add(&D_80394958, actor_new, 200);
    spawnableActorList_add(&D_80392F1C, actor_new, 0x8608);
    spawnableActorList_add(&D_80394A08, actor_new, 0x2010129);
    spawnableActorList_add(&D_80394A2C, actor_new, 0x2010129);
    spawnableActorList_add(&D_80394A50, actor_new, 0x2010129);
    spawnableActorList_add(&D_80394980, actor_new, 0x80);
    spawnableActorList_add(&D_80394C28, actor_new, 0x400);
    spawnableActorList_add(&D_80394C4C, actor_new, 0x400);
    spawnableActorList_add(&D_80394C70, actor_new, 0x400);
    spawnableActorList_add(&D_80394D20, actor_new, 0);
    spawnableActorList_add(&D_80394CF0, actor_new, 0x80508);
    spawnableActorList_add(&D_80394C94, actor_new, 0x500);
    spawnableActorList_add(&D_80393354, actor_new, 0x8602);
    spawnableActorList_add(&D_80392D90, actor_new, 0x20000);
}
