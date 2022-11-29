#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8035ECA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8035F138(Actor *this);
extern void func_80325794(ActorMarker *);
extern f32 func_80257204(f32, f32, f32, f32);

typedef struct {
    s32 unk0;
}ActorLocal_core2_D7D10;

/* .data */
ActorAnimationInfo D_80372F80[] = {
    {0, 0.0f},
    {0x9A, 8000000.0f},
    {0x9A,       1.3f},
    {0x9B,       0.6f},
    {0x9B,       0.75f},
    {0x9A,       1.5f},
    {0x1ED,      1.0f},
    {0x1EE,      2.4f}
};

ActorInfo D_80372FC0 = { 
    MARKER_96_RIPPER, ACTOR_C7_RIPPER, ASSET_3C9_MODEL_RIPPER, 
    0x1, D_80372F80, 
    func_8035F138, func_80326224, func_8035ECA0, 
    3500, 0, 1.2f, 0
};

ActorInfo D_80372FE4 = { 
    MARKER_297_GIANT_RIPPER, ACTOR_3C2_GIANT_RIPPER, ASSET_3C9_MODEL_RIPPER, 
    0x1, D_80372F80, 
    func_8035F138, func_80326224, func_8035ECA0, 
    14000, 0, 3.2f, 0
};

/* .code */
Actor *func_8035ECA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    static f32 D_80373008[3] = {0.0f, 0.0f, 0.0f};
    f32 rotation[3];
    Actor *this;
    ActorLocal_core2_D7D10 *local;

    this = func_80325300(marker, rotation);
    local = (ActorLocal_core2_D7D10 *)&this->local;
    func_8033A45C(3, (s32) this->velocity[1]);
    func_8033A45C(4, local->unk0);
    func_8033A2D4(func_803253A0, this);
    func_8033A2E8(func_80325794, marker);
    func_803391A4(gfx, mtx, this->position, rotation, this->scale, D_80373008, func_803257B4(marker));
    return this;
}

bool func_8035ED60(Actor *this) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = this->position[0] - this->unk1C[0];
    temp_f2 = this->position[2] - this->unk1C[2];
    if (((temp_f0 * temp_f0) + (temp_f2 * temp_f2)) < 110.0f) {
        return TRUE;
    }
    return FALSE;
}

void func_8035EDB0(f32 position[3], s32 count, enum asset_e sprite) {
    static s32 D_80373014[3] = {0xAA, 0xAA, 0xAA};
    static struct31s D_80373020 = {{0.4f, 0.8f}, {1.4f, 2.0f}, {0.0f, 0.01f}, {1.2f, 1.8f}, 0.0f, 0.01};
    static struct43s D_80373048 = {
        {{-200.0f, -200.0f, -200.0f}, { 200.0f,  200.0f,  200.0f}}, 
        {{   0.0f,  -10.0f,    0.0f}, {   0.0f,  -10.0f,    0.0f}}, 
        {{ -50.0f,    0.0f,  -50.0f}, {  50.0f,  200.0f,   50.0f}}
    };
    ParticleEmitter *p_ctrl;

    p_ctrl = partEmitList_pushNew(count);
    func_802EFFA8(p_ctrl, D_80373014);
    particleEmitter_setSprite(p_ctrl, sprite);
    particleEmitter_setPosition(p_ctrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(p_ctrl, &D_80373048);
    func_802EFB98(p_ctrl, &D_80373020);
    func_802EFA70(p_ctrl, 0x10);
    particleEmitter_emitN(p_ctrl, count);
}

void func_8035EE48(Actor *this){
    u8 val = this->unk44_31;
    if(val != 0){
        func_8030DA44(val);
        this->unk44_31 = 0;
    }
}

void func_8035EE80(Actor *this){
    func_80328A84(this, 3);
    actor_loopAnimation(this);
    this->unk28 = 10.5f;
    func_8035EE48(this);
}

void func_8035EEC0(Actor *this){
    func_80328A84(this, 4);
    actor_loopAnimation(this);
    this->unk28 = 9.0f;
    func_8035EE48(this);
}

void func_8035EF00(Actor *this, f32 arg1){
    this->yaw_ideal = (f32)func_80329784(this);
    func_80328FB0(this, arg1);
}

void func_8035EF3C(Actor *this) {
    if( actor_animationIsAt(this, 0.2f)
        || actor_animationIsAt(this, 0.7f)
    ) {
        FUNC_8030E8B4(SFX_123_BANJO_LANDING_10, 0.5f, 24000, this->position, 1750, 3500);
    }
}

void func_8035EF9C(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_core2_D7D10 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_D7D10 *)&this->local;
    this->velocity[2] = 0.0f;
    func_80328B8C(this, 7, 0.02f, 1);
    actor_playAnimationOnce(this);
    local->unk0 = 2;
    actor_collisionOff(this);
    FUNC_8030E8B4(SFX_115_BUZZBOMB_DEATH, 0.6f, 32000, this->position, 1750, 3500);
    FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 0.9f, 22000, this->position, 1750, 3500);
    func_8035EE48(this);
}

void func_8035F048(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_core2_D7D10 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_D7D10 *)&this->local;

    FUNC_8030E8B4(SFX_F9_GRUNTLING_NOISE_1,  1.2f, 22000, this->position, 1750, 3500);
    FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 0.9f, 22000, this->position, 1750, 3500);
    this->velocity[2] = 0.0f;
    func_80328B8C(this, 6, 0.02f, 1);
    actor_playAnimationOnce(this);
    local->unk0 = 2;
    func_8035EE48(this);
}

void func_8035F0E8(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_core2_D7D10 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_D7D10 *)&this->local;
    FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 0.9f, 22000, this->position, 1750, 3500);
    this->velocity[2] = 0.8f;
    func_8035EE80(this);
}

void func_8035F138(Actor *this) {
    f32 sp2C;
    ActorLocal_core2_D7D10 *local;


    local = (ActorLocal_core2_D7D10 *)&this->local;
    sp2C = time_getDelta();
    if ((this->state == 1) && (animctrl_getAnimTimer(this->animctrl) < 0.04)) {
        this->velocity[1] = 2.0f;
    } else {
        this->velocity[1] = 1.0f;
    }
    if (this->velocity[2] <= 0.0) {
        this->velocity[2] = 0.0f;
    }
    else{
        this->velocity[2] -= sp2C;
        return;
    }
    switch(this->state){
        case 1: //L8035F20C
            if (!this->unk16C_4) {
                this->unk16C_4 = TRUE;
                marker_setCollisionScripts(this->marker, func_8035F0E8, func_8035F048, func_8035EF9C);
                local->unk0 = 1;
                this->unk1C[0] = this->position[0];
                this->unk28 = 0.0f;
                this->velocity[1] = 0.0f;
                this->unk1C[2] = this->position[2];
                this->velocity[0] = this->yaw;
            }
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            if (func_80329530(this, (s32) (this->scale * 650.0f)) && func_803292E0(this)) {
                func_80328A84(this, 2U);
                actor_playAnimationOnce(this);
                this->unk1C[1] = 1.0f;
                this->unk44_31 = func_8030ED2C(SFX_2C_PULLING_NOISE, 3);
                func_8030E2C4(this->unk44_31);
            }
            break;

        case 2: //L8035F2F4
            if (this->unk1C[1] < 1.9) {
                this->unk1C[1] += 0.1;
            }
            func_8030DBB4(this->unk44_31, this->unk1C[1]);
            if (actor_animationIsAt(this, 0.66f)) {
                FUNC_8030E8B4(SFX_F9_GRUNTLING_NOISE_1, 0.8f, 32000, this->position, 1750, 3500);

            }
            if (0.99 <= animctrl_getAnimTimer(this->animctrl)) {
                func_8035EE80(this);
                break;
            }
            func_8035EF00(this, 7.0f);
            break;

        case 3: //L8035F3AC
            func_8035EF3C(this);
            if (!func_80329530(this, (s32) (this->scale * 1050.0f)) || !func_803292E0(this)) {
                func_8035EEC0(this);
                break;
            }

            func_8035EF00(this, 6.0f);
            if ((func_80329030(this, 2) == 0) && (func_80329480(this) != 0)) {
                func_8035EEC0(this);
                this->unk38_31 = 3;
                break;
            }

            if (((this->unk28 + 0.28) <= 18.0) && ( 0.36 <= animctrl_getDuration(this->animctrl) - 0.0056000000000000008)) {
                this->unk28 += 0.28;
                animctrl_setDuration(this->animctrl, animctrl_getDuration(this->animctrl) - 0.0056000000000000008);
            }
            break;

        case 4: //L8035F4FC
            func_8035EF3C(this);
            if (((f64)this->unk38_31 <= 0.0) && func_80329530(this, (s32) (this->scale * 1050.0f)) && func_803292E0(this)) {
                func_8035EE80(this);
                break;
            }
            this->unk38_31 -= sp2C;
            if (func_8035ED60(this)) {
                func_80328B8C(this, 5, 0.99f, 0);
                actor_playAnimationOnce(this);
                this->unk28 = 0.0f;
                this->unk1C[1] = 1.9f;
                this->unk44_31 = func_8030ED2C(SFX_2C_PULLING_NOISE, 3);
                break;
            }

            this->yaw_ideal = (f32)(s32)func_80257204(this->position[0], this->position[2], this->unk1C[0], this->unk1C[2]);
            func_80328FB0(this, 7.0f);
            func_80329030(this, 2);
            break;

        case 5: //L8035F6F4
            if (actor_animationIsAt(this, 0.36f) != 0) {
                func_8030E2C4(this->unk44_31);
            }
            if ((this->unk44_31 != 0) && func_8030E3FC(this->unk44_31)) {
                if (this->unk1C[1] > 1.0) {
                    this->unk1C[1] -= 0.1;
                }
                func_8030DBB4(this->unk44_31, this->unk1C[1]);
            }
            if (animctrl_getAnimTimer(this->animctrl) <= 0.02) {
                func_80328B8C(this, 1, 0.02f, 1);
                actor_playAnimationOnce(this);
                this->unk28 = 0.0f;
                func_8035EE48(this);
                break;
            }
            this->yaw_ideal = this->velocity[0];
            func_80328FB0(this, 7.5f);
            func_80329030(this, 2);
            break;

        case 6: //L8035F7F0
            if (actor_animationIsAt(this, 0.64f)) {
                local->unk0 = 1;
            }
            if (0.99 <= animctrl_getAnimTimer(this->animctrl)) {
                func_8035EEC0(this);
            }
            break;

        case 7: //L8035F840
            if (actor_animationIsAt(this, 0.3f)) {
                FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 0.6f, 32000, this->position, 1750, 3500);
                FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 0.9f, 26000, this->position, 1750, 3500);
            }

            if( actor_animationIsAt(this, 0.5f) 
                || actor_animationIsAt(this, 0.7f)
            ) {
                FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 16000, this->position, 1750, 3500);
            }

            if (actor_animationIsAt(this, 0.8f)) {
                FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 14000, this->position, 1750, 3500);
            }

            if (actor_animationIsAt(this, 0.9f)) {
                FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 12000, this->position, 1750, 3500);
            }

            if (actor_animationIsAt(this, 0.25f)) {
                func_8035EDB0(this->position, 12, ASSET_700_SPRITE_DUST);
            }

            if (actor_animationIsAt(this, 0.5f) != 0) {
                func_80326310(this);
            }
            break;
    }

}
