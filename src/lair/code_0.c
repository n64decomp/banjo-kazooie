#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"

extern void func_8028F918(s32);
extern void func_802D2FB0(Actor *, s32, s32, s32, f32, s32, s32, s32);
extern void func_802D3CE8(Actor *);
extern void func_802D3D54(Actor *);
extern void func_802D3D74(Actor *this);
extern void func_802D4830(Actor *, s32, f32);
extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern int  actor_animationIsAt(Actor *, f32);
extern void subaddie_set_state_with_direction(Actor *, s32, f32, s32);
extern void func_8033A45C(s32, s32);
extern void func_8034E0FC(void *, s32);



void   chFloorCobweb_update(Actor *this);
void   chWallCobweb_update(Actor *this);
void   lair_func_80386550(Actor *this);
Actor *func_8038664C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void   func_80386D78(Actor *this);
void   func_80386780(Actor *this);
void   func_803867A8(Actor *this);
void   func_80386D20(Actor *this);
void   func_803870DC(Actor *this);
Actor *lair_func_80387560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void   func_80387730(Actor *this);
void   func_803880BC(Actor *this);
void   func_8038824C(Actor *this);
void   func_803882B0(Actor *this);
void   func_80388524(Actor *this);
void   func_80388FC8(Actor *this);
void   lair_func_80389204(Actor *this);
void   func_803893B8(Actor *this);
void   lair_func_803894B0(Actor *this);
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
void   lair_func_8038A084(Actor *this);
void   func_8038A0A4(Actor *this);

extern ActorInfo D_80393560;
extern ActorInfo D_80393584;
extern ActorInfo D_803947B0;
extern ActorInfo D_803947D4;
extern ActorInfo chBrentilda;
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
ActorAnimationInfo D_80392CB0[] = {
    {    0,   0.0f}, 
    {    0,   0.0f},
    { 0xD4,   0.15f}, 
    { 0xD5,   0.5f},
    {    0,   0.0f}, 
    {    0,   0.0f},
    { 0xD4,   0.15f}, 
    { 0xD5,   0.5f},
    { 0xD5, 1e+08f}, 
    {0x1E3,   0.73},
    {0x1E3, 1e+08f}, 
    {0x1F0,   1.0f},
    {0x1F1,   0.7f}, 
    {0x1F1, 1e+08f},
    {0x1F2,   1.0f}, 
    {0x1F3,   0.4f},
    {0x1F3, 1e+08f}, 
    {    0,   0.0f},
    {0x218, 1e+08f}, 
    {0x218,   1.0f},
    {0x218, 1e+08f}, 
    {0x235, 1e+08f},
    {0x235, 1e+08f}, 
    {0x235,   1.0f},
    {0x235, 1e+08f}, 
    {0x271, 1e+08f},
    {0x271,   3.0f}, 
    {0x271, 1e+08f}
};
ActorInfo lair_D_80392D90 = { 0x270, 0x2D8, 0x3B2, 0x1, NULL, func_802D3D54, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80392DB4 = { 0x110, 0x214, 0x4AB, 0x1, D_80392CB0, func_803896D4, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392DD8 = { 0x113, 0x217, 0x4A9, 0x1, D_80392CB0, func_803896F4, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392DFC = { 0x115, 0x219, 0x4AA, 0x1, D_80392CB0, func_80389714, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392E20 = { 0x11B, 0x221, 0x4B5, 0x1, D_80392CB0, func_80389734, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392E44 = { 0x11C, 0x222, 0x4B2, 0x1, D_80392CB0, func_8038975C, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392E68 = { 0x11D, 0x223, 0x4B0, 0x1, D_80392CB0, func_80389784, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392E8C = { 0x232, 0x23C, 0x4B8, 0x1, D_80392CB0, func_803897AC, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392EB0 = { 0x23F, 0x246, 0x534, 0x1, D_80392CB0, func_80386D20, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392ED4 = { 0x241, 0x248, 0x540, 0x1, D_80392CB0, func_80386780, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392EF8 = { MARKER_109_BREAKABLE_BRICK_WALL, ACTOR_20D_BREAKABLE_BRICK_WALL, ASSET_4A1_MODEL_BREAKABLE_BRICK_WALL, 0x1, D_80392CB0, lair_func_80386550, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0x85};
ActorInfo D_80392F1C = { 0x264, 0x2E5, 0x550, 0x19, D_80392CB0, func_80388524, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80392F40 = { MARKER_224_BREAKABLE_FLOOR_COBWEB, ACTOR_230_BREAKABLE_FLOOR_COBWEB, ASSET_4BF_MODEL_FLOOR_COBWEB, 0xB, D_80392CB0, chFloorCobweb_update, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0x88};
ActorInfo D_80392F64 = { MARKER_225_BREAKABLE_WALL_COBWEB,  ACTOR_231_BREAKABLE_WALL_COBWEB, ASSET_4D5_MODEL_WALL_COBWEB, 0xE, D_80392CB0, chWallCobweb_update, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0x88};
ActorInfo D_80392F88 = { 0x111, 0x215, 0x4A4, 0x1, NULL, func_80388FC8, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80392FAC = { 0x112, 0x216, 0x4A5, 0x1, NULL, func_80388FC8, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80392FD0 = { 0x114, 0x218, 0x4A6, 0x1, NULL, lair_func_80389204, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80392FF4 = { 0x10D, 0x211, 0x4A3, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80393018 = { 0x22C, 0x23A, 0x4D9, 0x1, NULL, func_803882B0, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_8039303C = { 0x164, 0x259, 0x507, 0x1, NULL, func_803880BC, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80393060 = { 0x165, 0x25A, 0x508, 0x1, NULL, func_8038824C, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80393084 = { MARKER_240_LAIR_SWITCH_FLIGHT_PAD, 0x247, 0x48A, 0x1, NULL, func_80386D78, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_803930A8 = { 0x242, 0x249, 0x2DD, 0x1, NULL, func_803867A8, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_803930CC = { 0x11F, 0x225, 0x4B3, 0x1, NULL, func_8038A064, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_803930F0 = { 0x10A, 0x20E, 0x4A2, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_80393114 = { 0x11A, 0x220, 0x4B7, 0x1, NULL, func_80389FF4, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x91};
ActorInfo D_80393138 = { 0x11E, 0x224, 0x4AF, 0x1, NULL, func_8038A014, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x83};
ActorInfo D_8039315C = { 0x227, 0x234, 0x4D6, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x93};
ActorInfo D_80393180 = { 0x228, 0x235, 0x4D7, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x8B};
ActorInfo D_803931A4 = { 0x229, 0x236, 0x4D8, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x8B};
ActorInfo D_803931C8 = { MARKER_121_GLASS_EYE, ACTOR_227_GLASS_EYE, ASSET_4BD_MODEL_GLASS_EYE, 0x1, NULL, func_8038A034, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0x89};
ActorInfo D_803931EC = { 0x116, 0x21A, 0x4AC, 0x1, NULL, func_803893B8, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x82};
ActorInfo D_80393210 = { 0x117, 0x21B, 0x4AD, 0x1, NULL, lair_func_803894B0, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x82};
ActorInfo D_80393234 = { 0x10B, 0x20F, 0x4B4, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x90};
ActorInfo D_80393258 = { 0x10C, 0x210, 0x4AE, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x84};
ActorInfo D_8039327C = { 0x10E, 0x212, 0x4A7, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x7F};
ActorInfo D_803932A0 = { 0x120, 0x226, 0x4BC, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x87};
ActorInfo D_803932C4 = { 0x122, ACTOR_228_MMM_ENTRANCE_DOOR, 0x4BE, 0x1, NULL, func_80388524, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x8C};
ActorInfo D_803932E8 = { 0x10F, 0x213, 0x4A8, 0x1, NULL, func_803875F0, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x80};
ActorInfo D_8039330C = { 0x118, 0x21E, 0x4B1, 0x1, NULL, lair_func_8038A084, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x8F};
ActorInfo D_80393330 = { 0x119, 0x21F, 0x4B6, 0x1, NULL, func_8038A0A4, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0x92};
ActorInfo D_80393354 = { 0x266, 0x2E3, 0x563, 0x1, NULL, func_803870DC, actor_update_func_80326224, lair_func_80387560, 0, 0,   0.0f, 0};
ActorInfo D_80393378 = { 0x17D, 0x1E1, 0x517, 0x1, NULL, func_80389D08, actor_update_func_80326224, func_80389E10, 0, 0,   0.0f, 0x8D};
ActorInfo D_8039339C = { 0x234, 0x23E, 0x4E1, 0x12, D_80392CB0, func_8038982C, actor_update_func_80326224, actor_drawFullDepth, 0, 0,   0.0f, 0};
ActorInfo D_803933C0 = { 0x163, 0x258, 0x511, 0x12, D_80392CB0, func_80389898, actor_update_func_80326224, func_8038664C, 0, 0,   0.0f, 0x8E};
ActorInfo D_803933E4 = { 0x160, 0x255, 0x509, 0x15, D_80392CB0, func_80389934, actor_update_func_80326224, actor_draw, 0, 0,   0.0f, 0};
ActorInfo D_80393408 = { 0x102, 0x203, 0x491, 0x1, D_80392CB0, func_80387730, actor_update_func_80326224, func_80387DA8, 0, 0,   0.0f, 0};
ParticleScaleAndLifetimeRanges D_8039342C = {
    {0.31f, 0.37f},
    {0.17f, 0.22f},
    {0.0f,  0.01f},
    {0.9f,  0.9f},
    0.0f, 0.0f
}; 
s16 D_80393454[] = {
    FILEPROG_31_MM_OPEN, 
    FILEPROG_32_TTC_OPEN,
    FILEPROG_33_CC_OPEN,
    FILEPROG_34_BGS_OPEN,
    FILEPROG_35_FP_OPEN,
    FILEPROG_36_GV_OPEN,
    FILEPROG_37_MMM_OPEN,
    FILEPROG_38_RBB_OPEN,
    FILEPROG_39_CCW_OPEN,
    NULL
};

s16 D_80393468[] = {
    NULL, 
    NULL, 
    VOLATILE_FLAG_7F_SANDCASTLE_OPEN_CC, 
    VOLATILE_FLAG_84_SANDCASTLE_OPEN_BGS, 
    VOLATILE_FLAG_8B_SANDCASTLE_OPEN_FP, 
    VOLATILE_FLAG_87_SANDCASTLE_OPEN_GV, 
    VOLATILE_FLAG_8C_SANDCASTLE_OPEN_MMM, 
    VOLATILE_FLAG_90_SANDCASTLE_OPEN_RBB, 
    VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW, 
    NULL
};

s16 D_8039347C[] = {50, 180, 260, 350, 450, 640, 765, 810, 828, 846, 864, 882}; //notedoor_notes_required_to_open

s16 D_80393494[]  = {0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B}; 
s32 D_803934A0[3] = {0x00, 0xFF, 0x00};
ParticleScaleAndLifetimeRanges D_803934AC = {
    {1.0f, 2.0f},
    {2.4f, 5.0f},
    {0.0f, 3.2f},
    {3.8f, 5.0f},
    0.31f, 0.93f
};
ParticleSettingsVelocityPosition D_803934D4 = {
    {{-80.0f, 30.0f, -80.0f}, {80.0f, 270.0f, 80.0f}},
    {{40.0f, 0.0f, -50.0f}, {100.0f, 200.0f, 50.0f}},
};
s32 D_80393504[4] = {0x87, 0x87, 0x87, 0xB4};


//chcobweb
void chFloorCobweb_update(Actor *this)
{
    if(!this->initialized)
    {
        func_802D3CE8(this);

        if (fileProgressFlag_get(this->unkF4_8 == 1 ? FILEPROG_CB_LAIR_COBWEB_OVER_FLIGHTPAD_BROKEN : FILEPROG_CC_LAIR_COBWEB_OVER_GREEN_CAULDRON_BROKEN))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    if (this->state == 0xC)
    {
        if (actor_animationIsAt(this, 0.95f))
        {
            subaddie_set_state_with_direction(this, 0xD, 0.98f, 1);
            func_80326310(this);
        }
    }
}

//chbigyellowcobweb
void chWallCobweb_update(Actor *this)
{
    if (!this->initialized)
    {
        func_802D3CE8(this);

        if (fileProgressFlag_get(FILEPROG_CA_COBWEB_BLOCKING_PURPLE_CAULDRON_BROKEN))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    if (this->state == 0xF)
    {
        if (actor_animationIsAt(this, 0.9f))
        {
            subaddie_set_state_with_direction(this, 0x10, 0.98f, 1);
            func_80326310(this);
        }
    }
}

void lair_func_80386550(Actor *this)
{
    if (!this->initialized)
    {
        func_802D3CE8(this);

        if (fileProgressFlag_get(this->unkF4_8 == 1 ? FILEPROG_C8_LAIR_BRICKWALL_TO_WADINGBOOTS_BROKEN : FILEPROG_C9_LAIR_BRICKWALL_TO_SHOCKJUMP_PAD_BROKEN))
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

            if (actor_animationIsAt(this, 0.95f))
            {
                func_80326310(this);
                subaddie_set_state_with_direction(this, 10, 0.98f, 1);

                this->pitch = 270.0f;
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

    return actor_draw(marker, gfx, mtx, vtx);
}

ParticleEmitter *func_803866D8(s32 a0)
{

    void *ptr;
    s32 colour[3];

    ptr = partEmitMgr_newEmitter(0x28);

    particleEmitter_manualFree(ptr);
    particleEmitter_setSprite(ptr, ASSET_710_SPRITE_SPARKLE_PURPLE);
    particleEmitter_setScaleAndLifetimeRanges(ptr, &D_8039342C);
    particleEmitter_setParticleVelocityRange(ptr, 0.f, 70.f, 0.f, 0.f, 140.f, 0.f);

    colour[0] = a0 * 0xFF;
    colour[1] = 0xFF;
    colour[2] = 0;

    particleEmitter_setRGB(ptr, colour);

    return ptr;
}

void func_80386780(Actor *this)
{
    func_802D4AC0(this, 0x800000 | FILEPROG_C6_LAIR_JUMP_PAD_SWITCH_PRESSED, FILEPROG_C7_LAIR_JUMP_PAD_ACTIVE);
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

        this->lifetime_value = this->yaw;
        this->yaw = 0.0f;
        this->velocity[0] = 0.0f;
        return;
    }
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->unk158[0] = func_803866D8(0);
        this->unk158[1] = func_803866D8(1);
        if (volatileFlag_get(VOLATILE_FLAG_86_SANDCASTLE_SHOCKSPRING_JUMP_UNLOCKED)) {
            ability_unlock(ABILITY_D_SHOCK_JUMP);
            fileProgressFlag_set(FILEPROG_C6_LAIR_JUMP_PAD_SWITCH_PRESSED, TRUE);
            fileProgressFlag_set(FILEPROG_C7_LAIR_JUMP_PAD_ACTIVE, TRUE);
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
                        func_8030E6A4(SFX_3F6_RUBBING, 0.5f, this->alpha_124_19*0x25 + 0x3840);
                    }
                }
            }
        } else {
            this->velocity[0] += 1.0f;
            if ((this->velocity[0] < 0.0f) || (this->velocity[0] > 19.0f)) {
                this->velocity[0] = 0.0f;
                FUNC_8030E8B4(SFX_3F6_RUBBING, 0.5f, 24000, this->position, 100, 2300);

            }
        }
        this->lifetime_value += 2.5;
        while(this->lifetime_value >= 360.0f){ this->lifetime_value -= 360.0f;}

        this->position_y = this->unk1C[1];
        sp5C[1] = sp5C[2] =0.0f;
        sp5C[0] = this->unkF4_8*2;
        ml_vec3f_yaw_rotate_copy(sp5C, sp5C, this->lifetime_value);
        this->position[0] = this->unk1C[0] + sp5C[0];
        this->position[2] = this->unk1C[2] + sp5C[2];
        if (this->marker->unk14_21) {
            sp44 = this->unk158[globalTimer_getTime() & 1];
            if (sp44 != NULL) {
                particleEmitter_setAlpha(sp44, this->alpha_124_19);
                phi_f0 = this->lifetime_value - 10.0f;
                while(phi_f0 < 0.0f) {phi_f0 += 360.0f;}

                sp50[1] = this->unk1C[1];
                sp5C[1] = sp5C[2] = 0.0f;
                sp5C[0] = this->unkF4_8*2;
                ml_vec3f_yaw_rotate_copy(sp5C, sp5C, phi_f0);
                sp50[0] = this->unk1C[0] + sp5C[0];
                sp50[2] = this->unk1C[2] + sp5C[2];
                particleEmitter_setPosition(sp44, sp50);
                particleEmitter_setSpawnPositionRange(sp44, -25.0f, 0.0f, -25.0f, 25.0f, 6.0f, 25.0f);
                particleEmitter_emitN(sp44, 1);
                particleEmitter_setSpawnPositionRange(sp44, -75.0f, 0.0f, -75.0f, 75.0f, 6.0f, 75.0f);
                particleEmitter_emitN(sp44, 1);
            }
        }
    } else if (fileProgressFlag_get(FILEPROG_C6_LAIR_JUMP_PAD_SWITCH_PRESSED)) {
        this->position_y = this->unk1C[1];

        if (fileProgressFlag_get(FILEPROG_C7_LAIR_JUMP_PAD_ACTIVE)) {
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

void func_80386D40(void)
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

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        if (volatileFlag_get(VOLATILE_FLAG_8A_SANDCASTLE_FLIGHT_UNLOCKED)) {
            ability_unlock(ABILITY_9_FLIGHT);
            mapSpecificFlags_set(0, TRUE);
            this->lifetime_value = 0.0f;
            this->position[1] = this->unk1C[1];
            this->scale = 1.0f;
        }
    }
    if ((this->unk1C[1] - 150.0f) <= this->position[1]) {
        if (!volatileFlag_get(VOLATILE_FLAG_8A_SANDCASTLE_FLIGHT_UNLOCKED)) {
            if (this->lifetime_value != 0.0f) {
                this->lifetime_value -= 1.0f;
                if (this->lifetime_value == 0.0f) {
                    FUNC_8030E624(SFX_25_METAL_SLIDING_OVER_SMTH, 0.8f, 32000);
                }
            } else {
                this->scale = (this->scale < 1.0) ? this->scale + 0.04 : 1.0;
                if (this->scale < 1.0) {
                    this->yaw_ideal += 8.0;
                    if (this->yaw_ideal >= 360.0f) {
                        phi_f2 = this->yaw_ideal - 360.0f;
                    } else {
                        phi_f2 = this->yaw_ideal;
                    }
                    this->yaw_ideal = phi_f2;
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
        this->lifetime_value = 26.0f;
        this->position[1] = this->unk1C[1];
        func_802BAFE4(0x80);
        timedFunc_set_0(3.0f, func_80386D40);
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

    phi_v1 = fileProgressFlag_get(D_80393454[this->unkF4_8 - 1]) 
             || (D_80393468[this->unkF4_8 - 1] != 0 && volatileFlag_get(D_80393468[this->unkF4_8 - 1]));

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        if (phi_v1) {
            this->alpha_124_19 = 0xFF;
        } else {
            this->alpha_124_19 = 0;
        }
    }
    if ((this->alpha_124_19 == 0) && (phi_v1)) {
        this->alpha_124_19 = 1;
        this->lifetime_value = 23.0f;
    }

    phi_a0 = this->alpha_124_19;
    if (phi_a0 == 1) {
        this->lifetime_value -= 1.0f;
        if (this->lifetime_value == 0.0f) {
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
                temp_s5 = partEmitMgr_newEmitter(temp_s7);
                func_8034A174(func_80329934(), 5, sp90);
                func_8034A174(func_80329934(), 6, sp84);
                particleEmitter_setSprite(temp_s5, ASSET_710_SPRITE_SPARKLE_PURPLE);
                particleEmitter_setStartingScaleRange(temp_s5, 0.13f, 0.18f);
                particleEmitter_setFinalScaleRange(temp_s5, 0.08f, 0.13f);
                particleEmitter_setAccelerationRange(temp_s5, -500.0f, -1800.0f, -500.0f, 500.0f, 1800.0f, 500.0f);
                particleEmitter_setSpawnIntervalRange(temp_s5, 0.0f, 0.01f);
                particleEmitter_setParticleLifeTimeRange(temp_s5, 0.9f, 0.9f);
                particleEmitter_setParticleVelocityRange(temp_s5, -400.0f, 400.0f, -400.0f, 400.0f, -400.0f, 400.0f);
                particleEmitter_setAlpha(temp_s5, this->alpha_124_19);
                for(phi_s4 = 0; phi_s4 < temp_s7; phi_s4++){
                    for(i = 0; i < 3; i++){
                        sp64[i] = randf2(sp90[i], sp84[i]);
                    }
                    particleEmitter_setPosition(temp_s5, sp64);
                    sp70[0] = (s32) ((randf() * 130.0f) + 125.0f);
                    sp70[2] = sp70[1] = (s32) ((randf() * 170.0f) + 85.0f);
                    sp70[(randf() > 0.5) ? 2 : 1] = 0;
                    particleEmitter_setRGB(temp_s5, sp70);
                    particleEmitter_emitN(temp_s5, 1);
                }
            }
        }
    }
}

Actor *lair_func_80387560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx)
{
    Actor *actor = marker_getActor(marker);
    u32 i;

    for (i = 0; i != 10; i++)
        func_8033A45C(i + 1, actor->unkF4_8 + 1 == i + 2);

    return actor_drawFullDepth(marker, gfx, mtx, vtx);
}

//circular grate
void func_803875F0(Actor * this)
{
    func_802D3D74(this);

    if (!this->volatile_initialized)
    {
        if (fileProgressFlag_get(FILEPROG_1E_LAIR_GRATE_TO_BGS_PUZZLE_OPEN))
        {
            marker_despawn(this->marker);
            return;
        }

        if (mapSpecificFlags_get(0))
        {
            this->unk1C_y = this->position_y;
            func_802BAFE4(0x2A);
            fileProgressFlag_set(FILEPROG_1E_LAIR_GRATE_TO_BGS_PUZZLE_OPEN, TRUE);
            this->volatile_initialized = TRUE;
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
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->alpha_124_19 = 0xFF;
        this->unk1C[1] = 0.0f;
        this->unk1C[2] = 3.5f;
        if (fileProgressFlag_get(this->unkF4_8 + FILEPROG_39_CCW_OPEN)) {
            marker_despawn(this->marker);
            return;
        }
        if ((this->unkF4_8 >= 2U) && (this->unkF4_8 < 8U) && volatileFlag_get(D_80393494[this->unkF4_8 - 2])) {
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
    if (!fileProgressFlag_get(this->unkF4_8 + FILEPROG_39_CCW_OPEN) && ability_isUnlocked(ABILITY_13_1ST_NOTEDOOR)) {
        player_getPosition(spAC);
        if ((ml_vec3f_distance(spAC, this->position) < 500.0f) && (func_803114C4() != 0xF64)) {
            func_802FACA4(0xC);
        }
        if (itemscore_noteScores_getTotal() >= D_8039347C[this->unkF4_8 - 1]) {
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
                    fileProgressFlag_set(this->unkF4_8 + FILEPROG_39_CCW_OPEN, TRUE);
                    marker_despawn(this->marker);
                    func_8028F918(0);
                    func_8028F66C(BS_INTR_35);
                    return;
                }
                if (this->marker->unk14_21) {
                    temp_s5 = partEmitMgr_newEmitter((s32)((f32) this->alpha_124_19 / 11.0));
                    sp6C[2] = 0;
                    particleEmitter_setSprite(temp_s5, ASSET_710_SPRITE_SPARKLE_PURPLE);
                    particleEmitter_setStartingScaleRange(temp_s5, 0.13f, 0.18f);
                    particleEmitter_setFinalScaleRange(temp_s5, 0.08f, 0.13f);
                    particleEmitter_setAccelerationRange(temp_s5, -10.0f, 0.0f, -10.0f, 10.0f, 1600.0f, 10.0f);
                    particleEmitter_setSpawnIntervalRange(temp_s5, 0.0f, 0.01f);
                    particleEmitter_setParticleLifeTimeRange(temp_s5, 1.4f, 1.4f);
                    particleEmitter_setParticleVelocityRange(temp_s5, -100.0f, 100.0f, -100.0f, 100.0f, 0.0f, 100.0f);
                    particleEmitter_setAlpha(temp_s5, this->alpha_124_19);
                    for(phi_s4 = 0; phi_s4 < (s32) ((f32)this->alpha_124_19 / 11.0); phi_s4++){
                        for(i = 0; i < 3; i++){
                            sp60[i] = randf2(sp90[i], sp84[i]);
                        }
                        particleEmitter_setPosition(temp_s5, sp60);
                        sp6C[0] = (s32) ((randf() * 60.0f) + 195.0f);
                        sp6C[1] = (s32) ((randf() * 130.0f) + 125.0f);
                        particleEmitter_setRGB(temp_s5, sp6C);
                        particleEmitter_emitN(temp_s5, 1);
                    }
                }
            }
        } else if ((this->unkF4_8 >= 2) && (ml_vec3f_distance(spAC, this->position) < 290.0f)) {
            volatileFlag_setAndTriggerDialog_0(VOLATILE_FLAG_B0_NOT_ENOUGH_NOTES);
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
    return actor_drawFullDepth(marker, gfx, mtx, vtx);
}

void func_80387E94(s32 arg0)
{
    ActorMarker *marker;
    Actor *actor1;
    Actor *actorNew;
    Actor *actor2;

    marker = reinterpret_cast(ActorMarker *, arg0);
    actor1   = marker_getActor(marker);
    actorNew = actor_spawnWithYaw_f32(0x25A, actor1->position, actor1->yaw);

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

    if (nodeProp_findPositionFromActorId(400, tmp))
    {
        jiggy_spawn(JIGGY_35_LAIR_CC_WITCH_SWITCH, tmp);
        // FIXME: macro?
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM, *(s32 *)&tmp[0], *(s32 *)&tmp[1], *(s32 *)&tmp[2]);
    }
}

void func_80387F78(Actor *this, enum file_progress_e progress_flag)
{
    if (this->unk1C[0] != 2.f)
    {
        if (this->unk1C[0] != 0 && fileProgressFlag_get(FILEPROG_9B_LAIR_CC_WITCH_SWITCH_EYES_ACTIVE))
        {
            u32 flagState = fileProgressFlag_get(progress_flag);
            fileProgressFlag_set(progress_flag, TRUE);

            if (flagState == FALSE
                && !jiggyscore_isSpawned(JIGGY_35_LAIR_CC_WITCH_SWITCH)
                && fileProgressFlag_get(FILEPROG_9C_LAIR_CC_WITCH_SWITCH_LEFT_EYE_PRESSED)
                && fileProgressFlag_get(FILEPROG_9D_LAIR_CC_WITCH_SWITCH_RIGHT_EYE_PRESSED))
            {
                func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
                timedFunc_set_0(0.9f, func_80387F1C);
            }
        }

        if (fileProgressFlag_get(progress_flag))
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

    if (!this->volatile_initialized)
    {
        func_802D3CE8(this);

        this->volatile_initialized = TRUE;

        this->unk1C[1] = this->position_y;
        this->position_y -= 51.f;
        this->unk1C[0] = 0;

        __spawnQueue_add_1((GenFunction_1)func_80387E94, reinterpret_cast(s32, this->marker));

        if (volatileFlag_get(VOLATILE_FLAG_BC_WITCH_SWITCH_PRESSED_CC) && !fileProgressFlag_get(FILEPROG_9A_CC_WITCH_SWITCH_PRESSED))
            FUNC_8030E624(SFX_3F6_RUBBING, 0.75f, 30000);
    }

    if (fileProgressFlag_get(FILEPROG_9B_LAIR_CC_WITCH_SWITCH_EYES_ACTIVE))
    {
        if (!fileProgressFlag_get(FILEPROG_9C_LAIR_CC_WITCH_SWITCH_LEFT_EYE_PRESSED))
        {
            this->position_y = this->unk1C[1];
            actor_collisionOn(this);
        }

        if (this->unk100 != NULL && !fileProgressFlag_get(FILEPROG_9D_LAIR_CC_WITCH_SWITCH_RIGHT_EYE_PRESSED))
        {
            Actor *actor = marker_getActor(this->unk100);
            actor->position_y = this->unk1C[1];
            actor_collisionOn(actor);
        }
    }

    if (volatileFlag_get(VOLATILE_FLAG_BC_WITCH_SWITCH_PRESSED_CC) && !fileProgressFlag_get(FILEPROG_9B_LAIR_CC_WITCH_SWITCH_EYES_ACTIVE))
    {
        this->position_y += 1.7;

        if (this->position_y >= this->unk1C[1])
        {
            this->position_y = this->unk1C[1];
            fileProgressFlag_set(FILEPROG_9B_LAIR_CC_WITCH_SWITCH_EYES_ACTIVE, TRUE);
        }

        if (this->unk100 != NULL)
        {
            Actor *actor = marker_getActor(this->unk100);
            actor->position_y = this->position_y;
        }
    }

    func_80387F78(this, FILEPROG_9C_LAIR_CC_WITCH_SWITCH_LEFT_EYE_PRESSED);
}

void func_8038824C(Actor *this)
{
    func_802D3CE8(this);
    func_80387F78(this, FILEPROG_9D_LAIR_CC_WITCH_SWITCH_RIGHT_EYE_PRESSED);
}


void lair_func_80388278(Actor *this)
{
    void func_802F9D38(s32);

    if (!this->unk44_31)
        return;

    func_802F9D38(this->unk44_31);
    this->unk44_31 = 0;
}

void func_803882B0(Actor *this)
{
    if (!this->volatile_initialized)
    {
        func_802D3D74(this);

        this->volatile_initialized = TRUE;

        if (fileProgressFlag_get(FILEPROG_48_FP_WITCH_SWITCH_ADVENT_DOOR_OPEN))
            this->pitch = 90.f;

        this->lifetime_value = 0;
    }

    if (this->pitch == 90.f || !volatileFlag_get(VOLATILE_FLAG_BB_WITCH_SWITCH_PRESSED_FP))
        return;

    if (this->pitch == 0)
        func_802D4830(this, 0x18, 0.5f);

    this->pitch += 1.1;

    if (this->lifetime_value == 0 && this->pitch > 42.f)
    {
        this->lifetime_value = 1.f;
        func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
    }

    if (this->pitch > 90.f)
    {
        this->pitch = 90.f;
        fileProgressFlag_set(FILEPROG_48_FP_WITCH_SWITCH_ADVENT_DOOR_OPEN, TRUE);
        func_802D48B8(this);
    }
}

void func_80388404(enum file_progress_e progress_flag, enum sfx_e sfx, f32 a2, s32 a3)
{
    if (fileProgressFlag_get(progress_flag) == FALSE)
        func_8030E6A4(sfx, a2, a3);

    fileProgressFlag_set(progress_flag, TRUE);
}

void func_80388450(Actor *actor1, Actor *actor2)
{
    f32 vec1[3];
    f32 vec2[3];
    void *actor3 = nodeprop_findByActorIdAndActorPosition(0x22A, actor1);
    s32 val = nodeprop_getYaw(actor3);

    actor2->yaw = val;
    actor1->yaw = val;

    vec1[0] = actor1->unk1C[0] + 252.f;
    vec1[1] = 0;
    vec1[2] = 0;

    ml_vec3f_yaw_rotate_copy(vec2, vec1, actor1->yaw);
    nodeprop_getPosition(actor3, vec1);

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
                case ACTOR_2E5_DOOR_OF_GRUNTY://L80388630
                    if (!fileProgressFlag_get(FILEPROG_E2_DOOR_OF_GRUNTY_OPEN) && func_8038EAE0(0xA)) {
                        fileProgressFlag_set(FILEPROG_E2_DOOR_OF_GRUNTY_OPEN, TRUE);
                    }
                    break;

                case ACTOR_20E_MM_ENTRANCE_DOOR: //L80388660
                    if (!fileProgressFlag_get(FILEPROG_31_MM_OPEN) && func_8038EAE0(1)) {
                        fileProgressFlag_set(FILEPROG_31_MM_OPEN, TRUE);
                    }
                    break;

                case ACTOR_226_GV_ENTRANCE: //L80388690
                    if (!fileProgressFlag_get(FILEPROG_36_GV_OPEN) && func_8038EAE0(6)) {
                        fileProgressFlag_set(FILEPROG_36_GV_OPEN, TRUE);
                    }
                    break;

                case ACTOR_212_CC_ENTRANCE_BARS: //L803886C0
                    if (!fileProgressFlag_get(FILEPROG_33_CC_OPEN) && func_8038EAE0(3)) {
                        fileProgressFlag_set(FILEPROG_33_CC_OPEN, TRUE);
                    }
                    break;

                case ACTOR_211_TCC_ENTRANCE_CHEST_LID: //L803886F0
                    if (!fileProgressFlag_get(FILEPROG_32_TTC_OPEN) && func_8038EAE0(2)) {
                        fileProgressFlag_set(FILEPROG_32_TTC_OPEN, TRUE);
                    }
                    break;

                case ACTOR_210_BGS_ENTRANCE_DOOR: //L80388720
                    if (!fileProgressFlag_get(FILEPROG_34_BGS_OPEN) && func_8038EAE0(4)) {
                        fileProgressFlag_set(FILEPROG_34_BGS_OPEN, TRUE);
                    }
                    break;

                case ACTOR_20F_RBB_ENTRANCE_DOOR: //L80388750
                    if (!fileProgressFlag_get(FILEPROG_38_RBB_OPEN) && func_8038EAE0(8)) {
                        fileProgressFlag_set(FILEPROG_38_RBB_OPEN, TRUE);
                    }
                    break;

                case ACTOR_228_MMM_ENTRANCE_DOOR: //L80388780
                    if (!fileProgressFlag_get(FILEPROG_37_MMM_OPEN) && func_8038EAE0(7)) {
                        fileProgressFlag_set(FILEPROG_37_MMM_OPEN, TRUE);
                    }
                    break;

                case ACTOR_234_CCW_ENTRANCE_DOOR: //L803887B0
                    if (!fileProgressFlag_get(FILEPROG_39_CCW_OPEN) && func_8038EAE0(9)) {
                        fileProgressFlag_set(FILEPROG_39_CCW_OPEN, TRUE);
                    }
                    break;

                case ACTOR_235_FP_ENTANCE_DOOR: //L803887E0
                    if (!fileProgressFlag_get(FILEPROG_35_FP_OPEN) && func_8038EAE0(5)) {
                        fileProgressFlag_set(FILEPROG_35_FP_OPEN, TRUE);
                    }
                    break;
            }//L80388808
        }
        this->initialized = TRUE;
    }
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        switch(this->modelCacheIndex){
            case ACTOR_2E5_DOOR_OF_GRUNTY: //L80388880
                if (fileProgressFlag_get(FILEPROG_E2_DOOR_OF_GRUNTY_OPEN) && (this->state == 0x19)) {
                    subaddie_set_state_with_direction(this, 0x1B, 0.999f, 1);
                }
                break;

            case ACTOR_20E_MM_ENTRANCE_DOOR://L803888C0
                if(fileProgressFlag_get(FILEPROG_31_MM_OPEN)){
                    this->yaw = 270.0f;
                }
                break;
                
            case ACTOR_226_GV_ENTRANCE://L803888DC
                if(fileProgressFlag_get(FILEPROG_36_GV_OPEN)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 300.0f;
                break;
                
            case ACTOR_212_CC_ENTRANCE_BARS://L80388914
                if(fileProgressFlag_get(FILEPROG_33_CC_OPEN)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 365.0f;
                break;
                
            case ACTOR_211_TCC_ENTRANCE_CHEST_LID://L80388948
                if(fileProgressFlag_get(FILEPROG_32_TTC_OPEN)){
                    this->pitch = 90.0f;
                }
                break;
                
            case ACTOR_210_BGS_ENTRANCE_DOOR://L8038896C
                if(fileProgressFlag_get(FILEPROG_34_BGS_OPEN)){
                    this->yaw = 90.0f;
                }
                break;
                
            case ACTOR_20F_RBB_ENTRANCE_DOOR://L80388990
                if(fileProgressFlag_get(FILEPROG_38_RBB_OPEN)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 290.0f;
                break;
                
            case ACTOR_228_MMM_ENTRANCE_DOOR://L803889C8
                if(fileProgressFlag_get(FILEPROG_37_MMM_OPEN)){
                    this->yaw = 90.0f;
                }
                break;
                
            case ACTOR_234_CCW_ENTRANCE_DOOR://L803889EC
                if(fileProgressFlag_get(FILEPROG_39_CCW_OPEN)){
                    marker_despawn(this->marker);
                    return;
                }
                this->unk1C[1] = this->position[1] + 270.0f;
                break;
                
            case ACTOR_235_FP_ENTANCE_DOOR://L80388A24
                    sp30 = actorArray_findActorFromActorId(0x236);
                    if(fileProgressFlag_get(FILEPROG_35_FP_OPEN)){
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
                        subaddie_set_state_with_direction(this, 0x1A, 0.0f, 1);
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
                            subaddie_set_state_with_direction(this, 0x1B, 0.999f, 1);
                            fileProgressFlag_set(FILEPROG_E2_DOOR_OF_GRUNTY_OPEN, 1);
                            func_8030E6D4(SFX_6C_LOCKUP_CLOSING);
                        }
                        if (animctrl_getAnimTimer(this->animctrl) < 0.68) {
                            sp2C = partEmitMgr_newEmitter(3U);
                            particleEmitter_setSprite(sp2C, ASSET_70D_SPRITE_SMOKE_1);
                            particleEmitter_setStartingFrameRange(sp2C, 1, 6);
                            particleEmitter_setRGB(sp2C, D_803934A0);
                            particleEmitter_setAlpha(sp2C, 0x3C);
                            particleEmitter_setPosition(sp2C, this->position);
                            particleEmitter_setPositionAndVelocityRanges(sp2C, &D_803934D4);
                            particleEmitter_setScaleAndLifetimeRanges(sp2C, &D_803934AC);
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
                    lair_func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case 0x212://L80388D34
                this->position[1] += 5.0f;
                if (this->unk1C[1] < this->position[1]) {
                    func_80388404(0x33, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 17000);
                    lair_func_80388278(this);
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
                    lair_func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case ACTOR_228_MMM_ENTRANCE_DOOR://L80388E84
                this->yaw += 1.4;
                if (this->yaw > 90.0f) {
                    this->yaw = 90.0f;
                    func_80388404(0x37, SFX_6C_LOCKUP_CLOSING, 1.0f, 20000);
                }
                break;

            case ACTOR_234_CCW_ENTRANCE_DOOR://L80388ED4
                this->position[1] += 3.2;
                if (this->unk1C[1] <= this->position[1]) {
                    func_80388404(FILEPROG_39_CCW_OPEN, SFX_6C_LOCKUP_CLOSING, 1.0f, 20000);
                    lair_func_80388278(this);
                    marker_despawn(this->marker);
                }
                break;

            case ACTOR_235_FP_ENTANCE_DOOR://L80388F34
                {
                    sp28 = actorArray_findActorFromActorId(0x236);
                    this->unk1C[0] += 3.6;
                    if (this->unk1C[0] > 250.0f) {
                        lair_func_80388278(this);
                        marker_despawn(this->marker);
                        marker_despawn(sp28->marker);
                        fileProgressFlag_set(FILEPROG_35_FP_OPEN, TRUE);
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

        this->lifetime_value = 0;

        if (volatileFlag_get(VOLATILE_FLAG_7D_SANDCASTLE_RAISE_PIPES_TO_CC))
        {
            this->position_y = this->unk1C[1];
            this->lifetime_value = 1.f;
        }
    }

    if (this->lifetime_value)
        return;

    if (!this->volatile_initialized)
    {
        if (fileProgressFlag_get(this->modelCacheIndex == 0x215 ? FILEPROG_1F_CC_LOBBY_PIPE_1_RAISED : FILEPROG_20_CC_LOBBY_PIPE_2_RAISED))
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

            fileProgressFlag_set(this->modelCacheIndex == 0x215 ? FILEPROG_1F_CC_LOBBY_PIPE_1_RAISED : FILEPROG_20_CC_LOBBY_PIPE_2_RAISED, TRUE);

            this->volatile_initialized = TRUE;
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

            this->lifetime_value = 1.f;
        }
    }
}

void lair_func_80389204(Actor *this)
{
    func_802D3D74(this);

    if (!this->initialized)
    {
        this->initialized = TRUE;

        this->unk1C[1] = this->position_y;
        this->position_y -= 280.f;
        this->lifetime_value = 0;

        if (volatileFlag_get(VOLATILE_FLAG_7E_SANDCASTLE_RAISE_PIPE_TO_BRENTILDA))
        {
            this->position_y = this->unk1C[1];
            this->lifetime_value = 1.f;
        }
    }

    if (this->lifetime_value)
        return;

    if (!this->volatile_initialized)
    {
        if (fileProgressFlag_get(FILEPROG_21_CC_LOBBY_PIPE_3_RAISED))
        {
            this->position_y = this->unk1C[1];
            return;
        }

        if (mapSpecificFlags_get(2))
        {
            func_802BAFE4(0x2C);
            fileProgressFlag_set(FILEPROG_21_CC_LOBBY_PIPE_3_RAISED, TRUE);

            this->volatile_initialized = TRUE;
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

            this->lifetime_value = 1.f;
        }
    }
}

void func_803893B8(Actor *this)
{
    func_802D3D74(this);

    if (!this->volatile_initialized)
    {
        this->volatile_initialized = TRUE;

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

void lair_func_803894B0(Actor *this)
{
    void func_802EE2E8(Actor *, s32, s32, s32, f32, f32, f32);
    func_802D3D74(this);

    if (!this->volatile_initialized)
    {
        this->volatile_initialized = TRUE;
        this->unk1C[0] = 0;

        if (fileProgressFlag_get(FILEPROG_A1_STATUE_HAT_OPEN))
        {
            marker_despawn(this->marker);
            return;
        }

        this->unk1C[0] = volatileFlag_get(VOLATILE_FLAG_BD_WITCH_SWITCH_PRESSED_BGS) ? 22 : 0;
    }

    if (!this->unk1C[0])
        return;

    if (--this->unk1C[0] == 0)
    {
        fileProgressFlag_set(FILEPROG_A1_STATUE_HAT_OPEN, TRUE);
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
    func_802D4AC0(this, 0x800000 | FILEPROG_22_WATER_SWITCH_1_PRESSED, FILEPROG_23_LAIR_WATER_LEVEL_1);
}

void func_8038975C(Actor *this)
{
    func_802D4AC0(this, 0x800000 | FILEPROG_24_WATER_SWITCH_2_PRESSED, FILEPROG_25_LAIR_WATER_LEVEL_2);
}

void func_80389784(Actor *this)
{
    func_802D4AC0(this, 0x800000 | FILEPROG_26_WATER_SWITCH_3_PRESSED, FILEPROG_27_LAIR_WATER_LEVEL_3);
}

void func_803897AC(Actor *this)
{
    func_802D4AC0(this, 0x800000 | FILEPROG_53_CCW_PUZZLE_PODIUM_SWITCH_PRESSED, FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE);
}

void func_803897D4(s32 arg0)
{
    ActorMarker *marker1, *marker2;
    Actor *actor1, *actor2;

    marker1 = reinterpret_cast(ActorMarker *, arg0);
    actor1 = marker_getActor(marker1);

    actor1 = actor_spawnWithYaw_f32(0x258, actor1->position, actor1->yaw);

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

        if (!fileProgressFlag_get(FILEPROG_9E_CRYPT_COFFIN_LID_OPEN))
            __spawnQueue_add_1((GenFunction_1)func_803897D4, reinterpret_cast(s32, this->marker));
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
                subaddie_set_state_forward(this, 0x13);
                actor_playAnimationOnce(this);
                fileProgressFlag_set(FILEPROG_9E_CRYPT_COFFIN_LID_OPEN, TRUE);
            }

            break;
        }
        case 19:
        {
            if (actor_animationIsAt(this, 0.7f))
                marker_despawn(this->marker);

            break;
        }
        default:
            break;
    }
}

void func_80389934(Actor *this)
{
    if (!this->volatile_initialized)
    {
        func_802D3CE8(this);
        actor_collisionOff(this);

        this->volatile_initialized = TRUE;

        if (fileProgressFlag_get(FILEPROG_A2_GV_LOBBY_COFFIN_OPEN))
            subaddie_set_state_with_direction(this, 0x18, 0.999f, 1);
    }

    switch (this->state)
    {
        case 21:
        {
            if (volatileFlag_get(VOLATILE_FLAG_BE_WITCH_SWITCH_PRESSED_GV))
            {
                this->unk1C[0] = 25;

                subaddie_set_state_forward(this, 0x16);
                fileProgressFlag_set(FILEPROG_A2_GV_LOBBY_COFFIN_OPEN, TRUE);
            }

            break;
        }
        case 22:
        {
            if (--this->unk1C[0] == 0)
            {
                subaddie_set_state_forward(this, 0x17);
                actor_playAnimationOnce(this);
                FUNC_8030E624(SFX_3F6_RUBBING, 0.6f, 32000);
                func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
            }

            break;
        }
        case 23:
        {
            if (actor_animationIsAt(this, 0.95f))
            {
                subaddie_set_state_with_direction(this, 0x18, 0.999f, 1);
                FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 26000);
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
    f32   randf2(f32, f32);
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
                subaddie_set_state(this, 5);

                break;
            }
            default:
                break;
        }

        func_8030E878(SFX_82_METAL_BREAK, randf2(0.93f, 1.07f), 32760, this->position, 100, 1350.0f);

        this->lifetime_value = 1;
    }

    a1 -= 4.5; // f64

    while (a1 < 0)
        a1 += 360;

    return a1 <= 230 ? 230 : a1;
}

void func_80389D08(Actor *this)
{
    if (!this->volatile_initialized)
    {
        func_802D3CE8(this);

        this->volatile_initialized = TRUE;
        this->lifetime_value = 0;

        if (fileProgressFlag_get(FILEPROG_A5_LAIR_CRYPT_GATE_OPEN))
        {
            marker_despawn(this->marker);
            return;
        }
    }

    switch (this->state)
    {
        case 1:
        {
            if (this->lifetime_value)
            {
                subaddie_set_state_forward(this, 4);

                this->unk38_31 = 0;
                this->lifetime_value = 0;
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
    static s32 D_80395360;


    this = actor_drawFullDepth(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && (this->lifetime_value != 0.0f)) {
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

void func_80389FA8(Actor *this, enum file_progress_e flag)
{
    if (!this->initialized)
    {
        func_802D3D54(this);

        if (fileProgressFlag_get(flag))
            marker_despawn(this->marker);
    }
}

void func_80389FF4(Actor *this)
{
    func_80389FA8(this, FILEPROG_C2_GRATE_TO_RBB_PUZZLE_OPEN);
}

void func_8038A014(Actor *this)
{
    func_80389FA8(this, FILEPROG_C3_ICE_BALL_TO_CHEATO_BROKEN);
}

void func_8038A034(Actor *this)
{
    this->depth_mode = 2;

    func_80389FA8(this, FILEPROG_C4_STATUE_EYE_BROKEN);
}

void func_8038A064(Actor *this)
{
    func_80389FA8(this, FILEPROG_C5_RAREWARE_BOX_BROKEN);
}

void lair_func_8038A084(Actor *this)
{
    func_80389FA8(this, FILEPROG_CD_GRATE_TO_WATER_SWITCH_3_OPEN);
}

void func_8038A0A4(Actor *this)
{
    func_80389FA8(this, FILEPROG_CE_GRATE_TO_MMM_PUZZLE_OPEN);
}

void lair_func_8038A0C4(void)
{
    spawnableActorList_add(&D_80392F40, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_16);
    spawnableActorList_add(&D_80392F64, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_16);
    spawnableActorList_add(&D_803932E8, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393408, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392F88, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392FAC, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392FD0, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393018, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8039303C, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393060, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803931EC, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393210, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392EF8, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8039339C, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803933C0, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392DB4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392DD8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392DFC, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392E20, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392E44, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392E68, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392E8C, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803930F0, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393234, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393258, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392FF4, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8039327C, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803932A0, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803932C4, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8039315C, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393180, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803931A4, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8039330C, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393330, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393114, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80393138, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803930CC, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803931C8, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&D_80393560, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393584, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803933E4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393378, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803947B0, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_803947D4, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chBrentilda, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_80394A80, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80394AB0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_80392EB0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80393084, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80392ED4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803930A8, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80394870, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_80394894, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_803948B8, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_80394910, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_80394934, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80394958, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80392F1C, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80394A08, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_80394A2C, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_80394A50, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_80394980, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80394C28, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80394C4C, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80394C70, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80394D20, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80394CF0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_80394C94, actor_new, ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80393354, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&lair_D_80392D90, actor_new, ACTOR_FLAG_UNKNOWN_17);
}
