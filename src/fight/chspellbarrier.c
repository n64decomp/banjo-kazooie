#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

typedef struct chspellbarrier_s {
    s32 unk0;
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
    u8 sfxsourceIdx;
} ActorLocal_SpellBarrier;

ActorInfo chSpellBarrier = { MARKER_284_GRUNTY_SPELL_BARRIER, ACTOR_3AB_GRUNTY_SPELL_BARRIER, ASSET_546_MODEL_GRUNTY_SPELL_BARRIER, 1, NULL, chspellbarrier_update, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0 };

void chspellbarrier_collisionPassive(ActorMarker *this, ActorMarker *other) {
    Actor *actor_spellbarrier = marker_getActor(this);
    ActorLocal_SpellBarrier *local  = (ActorLocal_SpellBarrier *) &actor_spellbarrier->local;

    local->unk0 = 0xFF;
    local->unk4 = 0;

    if (func_8030E3FC(local->sfxsourceIdx) == 0) {
        func_8030E2C4(local->sfxsourceIdx);
    }

    if (func_8030E3FC(actor_spellbarrier->unk44_31) == 0) {
        func_8030E2C4(actor_spellbarrier->unk44_31);
    }
}

void chspellbarrier_free(Actor *this) {
    ActorLocal_SpellBarrier *local = (ActorLocal_SpellBarrier *) &this->local;

    if ((u8) this->unk44_31) {
        sfxsource_freeSfxsourceByIndex(this->unk44_31);
        this->unk44_31 = 0;
    }

    if (local->sfxsourceIdx != 0) {
        sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
        local->sfxsourceIdx = 0;
    }
}

void chspellbarrier_update(Actor *this) {
    ActorLocal_SpellBarrier *local = (ActorLocal_SpellBarrier *) &this->local;
    f32 delta_time = time_getDelta();
    ActorMarker *jinjo_marker;

    if (!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chspellbarrier_collisionPassive, NULL);
        marker_setFreeMethod(this->marker, chspellbarrier_free);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        local->unk0 = 0;
        local->unk4 = 1;
        this->depth_mode = 0;
        this->scale = 0.0f;
        this->unk44_31 = func_8030ED2C(SFX_142_GRUNTY_LAUGH_3, 3);
        func_8030DB04(this->unk44_31, 32000, this->position, 4000.0f, 12000.0f);
        sfxsource_playSfxAtVolume(this->unk44_31, 1.0f);
        local->sfxsourceIdx = func_8030ED2C(0x415, 3);
        func_8030DB04(local->sfxsourceIdx, 32000, this->position, 4000.0f, 12000.0f);
        sfxsource_playSfxAtVolume(local->sfxsourceIdx, 1.0f);
        FUNC_8030E8B4(SFX_416, 0.8f, 32000, this->position, 10000, 25000);
    }

    jinjo_marker = chfinalboss_findCollidingJinjo(this, 600.0f);

    if (jinjo_marker) {
        if (jinjo_marker->id == MARKER_285_JINJONATOR) {
            marker_despawn(this->marker);
            chfinalboss_spellBarrierInactive();
            return;
        } else {
            local->unk0 = 0;
            local->unk4 = 1;
            actor_setOpacity(this, 0);
            this->unk58_0 = 0;
            this->lifetime_value = 2.0f;
        }
    }

    if (this->state == 1) {
        this->yaw += 30.0f * delta_time;
        if (this->scale < 1.0) {
            this->scale = MIN(1.0, this->scale + ((f64)delta_time + (f64)delta_time));
        }

        if (0.0 < this->lifetime_value) {
            this->unk58_0 = 0;
            this->lifetime_value -=  delta_time;
        } else {
            this->unk58_0 = 1;

            if (local->unk4) {
                local->unk0 = MIN(0x64, local->unk0 + (s32)(60.0f * delta_time));

                if(local->unk0 >= 0x64){
                    local->unk0 = 0x64;
                    local->unk4 = 0;
                }
            } else {
                local->unk0 = MAX(0, local->unk0 - (s32)(60.0f*delta_time));

                if (local->unk0 <= 0) {
                    local->unk0 = 0;
                    local->unk4 = 1;
                    this->lifetime_value = 0.25f;
                }
            }

            actor_setOpacity(this, local->unk0);
        }
    }
}
