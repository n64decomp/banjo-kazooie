#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80328FF0(Actor *, f32);
extern f32 func_80309B24(f32[3]);
extern ParticleEmitter *func_802EDD8C(f32[3], f32, f32);

typedef struct {
    s32 unk0;
    s32 unk4;
}ActorLocal_core2_D6600;

#define LOCAL_D6600(actor) ((ActorLocal_core2_D6600*)&actor->local)

void chchumpfish_update(Actor *this);

/* .data */

enum chumpfish_states
{
    CHUMPFISH_STATE_1_IDLE_UNK = 1,
    CHUMPFISH_STATE_2_IDLE_UNK,
    CHUMPFISH_STATE_3_UNK,
    CHUMPFISH_STATE_4_UNK,
    CHUMPFISH_STATE_5_OW,
    CHUMPFISH_STATE_6_ATTACK,
    CHUMPFISH_STATE_7_DIE
};

ActorAnimationInfo chChumpFishAnimations[] = {
    {0, 0.0f},
    {ASSET_B3_ANIM_CHUMP_IDLE,   1.8f},
    {ASSET_B3_ANIM_CHUMP_IDLE,   0.9f},
    {ASSET_B3_ANIM_CHUMP_IDLE,   0.6f},
    {ASSET_B3_ANIM_CHUMP_IDLE,   0.4f},
    {ASSET_B3_ANIM_CHUMP_IDLE,   0.5f},
    {ASSET_B4_ANIM_CHUMP_ATTACK, 0.4f},
    {ASSET_2C0_ANIM_CHUMP_DIE,   1.5f}
};

ActorInfo chChumpFish = { 
    MARKER_69_CHUMP_FISH, ACTOR_A_CHUMP_FISH, ASSET_36B_CHUMP_FISH, 
    0x2, chChumpFishAnimations, 
    chchumpfish_update, actor_update_func_80326224, actor_draw, 
    3000, 0, 0.0f, 0
};

/* .code */
f32 func_8035D590(f32 arg0) {
    if ((arg0 >= 180.0f) && (arg0 < 330.0f)) {
        return 330.0f;
    }
    if ((arg0 < 180.0f) && (arg0 > 30.0f)) {
        return 30.0f;
    }
    return arg0;
}

bool func_8035D608(Actor *this) {
    f32 player_pos[3];

    player_getPosition(player_pos);
    if (LOCAL_D6600(this)->unk4 == 8) {
        return TRUE;
    }
    return func_80309D58(&player_pos, this->unk10_18);
}


void func_8035D65C(Actor *this) {
    if (this->unk38_31 != 0) {
        this->unk38_31--;
        return;
    }
    if (subaddie_playerIsWithinSphereAndActive(this, 500) && player_isSwimming() && func_8035D608(this)) {
        this->actor_specific_1_f = 2.0f;
        subaddie_set_state_with_direction(this, CHUMPFISH_STATE_4_UNK, 0.0f, -1);
    }
}

void func_8035D6FC(Actor *this) {
    subaddie_set_state_with_direction(this, CHUMPFISH_STATE_3_UNK, 0.0f, -1);
    this->actor_specific_1_f = 2.0f;
    subaddie_set_ideal_yaw(this, (s32) (randf2(-45.0f, 45.0f) + (this->yaw + 180.0f)));
    func_80328CA8(this, (s32) func_8035D590(randf2(-45.0f, 45.0f) + (360.0f - this->pitch)));
    this->unk38_31 = 0x78;
}

void func_8035D7CC(Actor *this) {
    subaddie_set_state_with_direction(this, CHUMPFISH_STATE_3_UNK, 0.0f, -1);
    this->actor_specific_1_f = 2.0f;
    subaddie_set_ideal_yaw(this, (s32) (randf2(-45.0f, 45.0f) + (this->yaw + 180.0f)));
    func_80328CA8(this, (s32) func_8035D590(randf2(-45.0f, 45.0f) + (360.0f - this->pitch)));
}

void chchumpfish_die(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    subaddie_set_state_with_direction(this, CHUMPFISH_STATE_7_DIE, 0.0f, -1);
    actor_playAnimationOnce(this);
    sfx_playFadeShorthandDefault(SFX_115_BUZZBOMB_DEATH, 0.8f, 30000, this->position, 1500, 3000);
    actor_collisionOff(this);
}

void chchumpfish_ow(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if (this->state >= CHUMPFISH_STATE_5_OW) {
        if (func_803294F0(this, 0x50, subaddie_getYawToPlayer(this))) {
            func_8030E58C(SFX_6D_CROC_BITE, 1.3f);
            func_8035D6FC(this);
        }
    }
}

void func_8035D95C(ActorMarker *marker) {
    f32 sp34[3];
    ParticleEmitter *pCtrl;

    if (marker->unk14_21) {
        func_8034A174(marker->unk44, 5, sp34);
        pCtrl = func_802EDD8C(sp34, 20.0f, func_80309B24(sp34));
        particleEmitter_setParticleVelocityRange(pCtrl, -50.0f, -50.0f, -50.0f, 50.0f, 50.0f, 50.0f);
        particleEmitter_setStartingScaleRange(pCtrl, 0.1f, 0.2f);
        particleEmitter_setFinalScaleRange(pCtrl, 0.1f, 0.2f);
        particleEmitter_emitN(pCtrl, 3);
    }
}

void chchumpfish_update(Actor *this) {
    f32 sp44;
    f32 sp40;
    s32 sp3C;
    bool player_within_radius;

    if (!this->initialized) {
        this->initialized = TRUE;
        this->unk138_25 = TRUE;
        this->actor_specific_1_f = 4.0f;
        LOCAL_D6600(this)->unk4 =(gsworld_get_map() == MAP_71_GL_STATUE_ROOM) ? 8 : 0xf;
        if (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {
            this->actor_specific_1_f = 0.0f;
            subaddie_set_state_with_direction(this, CHUMPFISH_STATE_1_IDLE_UNK, 0.0f, 1);
        }
        func_8032CA80(this, LOCAL_D6600(this)->unk4);
        marker_setCollisionScripts(this->marker, chchumpfish_ow, NULL, chchumpfish_die);
    }

    this->marker->id = MARKER_69_CHUMP_FISH;
    if (randf() < 0.01) {
        LOCAL_D6600(this)->unk0 = 5;
    }
    if (LOCAL_D6600(this)->unk0 != 0 && !(globalTimer_getTime() & 0xF)) {
        LOCAL_D6600(this)->unk0--;
        func_8035D95C(this->marker);
    }
    switch(this->state){
        case CHUMPFISH_STATE_1_IDLE_UNK://L8035DB78
            subaddie_turnToYaw(this, 0.5f);
            func_80328FF0(this, 0.5f);
            func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (subaddie_maybe_set_state(this, CHUMPFISH_STATE_2_IDLE_UNK, 0.05f) && !volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)) {
                this->actor_specific_1_f = 4.0f;
            }
            func_8035D65C(this);
            break;

        case CHUMPFISH_STATE_2_IDLE_UNK://L8035DBE4
            subaddie_turnToYaw(this, 0.5f);
            func_80328FF0(this, 0.5f);
            if (func_80329480(this) && randf() < 0.01) {
                subaddie_set_ideal_yaw(this, (s32)(this->yaw + randf2(-45.0f, 45.0f)));
            }
            if (func_8032944C(this) && randf() < 0.01) {
                func_80328CA8(this, (s32)func_8035D590(this->pitch + randf2(-45.0f, 45.0f)));
            }
            sp3C = func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (sp3C & ~2) {
                func_8035D7CC(this);
            }
            if (sp3C & 2) {
                func_80328CA8(this, 0);
            }
            if (subaddie_maybe_set_state_position_direction(this, CHUMPFISH_STATE_1_IDLE_UNK, 0.0f, 1, 0.005f)) {
                this->actor_specific_1_f = 2.0f;
            }
            func_8035D65C(this);
            break;

        case CHUMPFISH_STATE_3_UNK://L8035DD54
            subaddie_turnToYaw(this, 3.0f);
            func_80328FF0(this, 3.0f);
            func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (func_80329480(this) && func_8032944C(this)) {
                subaddie_set_state_with_direction(this, CHUMPFISH_STATE_2_IDLE_UNK, 0.0f, -1);
                this->actor_specific_1_f = 4.0f;
            }
            break;

        case CHUMPFISH_STATE_4_UNK://L8035DDB8
            func_803297FC(this, &sp40, &sp44);
            subaddie_set_ideal_yaw(this, (s32) sp44);
            func_80328CA8(this, (s32) func_8035D590(sp40));
            subaddie_turnToYaw(this, 10.0f);
            func_80328FF0(this, 10.0f);
            func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (func_80329480(this) && func_8032944C(this)) {
                subaddie_set_state_with_direction(this, CHUMPFISH_STATE_5_OW, 0.0f, -1);
                this->actor_specific_1_f = 10.5f;
            }
            break;

        case CHUMPFISH_STATE_6_ATTACK://L8035DE60
            if (actor_animationIsAt(this, 0.5f)) {
                gcsfx_playWithPitch(SFX_6D_CROC_BITE, 1.1f, 10000);
            }
        case CHUMPFISH_STATE_5_OW://L8035DE84
            this->marker->id = MARKER_173_CHUMP_FISH_2;
            func_803297FC(this, &sp40, &sp44);
            subaddie_set_ideal_yaw(this, (s32) sp44);
            func_80328CA8(this, (s32) func_8035D590(sp40));
            subaddie_turnToYaw(this, 10.0f);
            func_80328FF0(this, 10.0f);
            player_within_radius = subaddie_playerIsWithinSphereAndActive(this, 300);
            if ((this->state == CHUMPFISH_STATE_5_OW) && player_within_radius) {
                subaddie_set_state_with_direction(this, CHUMPFISH_STATE_6_ATTACK, 0.0f, -1);
            }
            if ((this->state == CHUMPFISH_STATE_6_ATTACK) && !player_within_radius) {
                subaddie_set_state_with_direction(this, CHUMPFISH_STATE_5_OW, 0.0f, -1);
            }
            if ((func_8032CA80(this, LOCAL_D6600(this)->unk4) & ~2)) {
                func_8035D7CC(this);
            }
            break;
        
        case CHUMPFISH_STATE_7_DIE://L8035DFA0 
            if(actor_animationIsAt(this, 0.5f)) {
                func_80326310(this);
            }
            break;
    }
}
