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

void func_8035DA1C(Actor *this);

/* .data */
ActorAnimationInfo D_80372EA0[] = {
    {0, 0.0f},
    {0x0B3, 1.8f},
    {0x0B3, 0.9f},
    {0x0B3, 0.6f},
    {0x0B3, 0.4f},
    {0x0B3, 0.5f},
    {0x0B4, 0.4f},
    {0x2C0, 1.5f}
};

ActorInfo D_80372EE0 = { 
    MARKER_69_CHUMP_FISH, ACTOR_A_CHUMP_FISH, ASSET_36B_CHUMP_FISH, 
    0x2, D_80372EA0, 
    func_8035DA1C, func_80326224, actor_draw, 
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
    f32 sp1C[3];

    player_getPosition(sp1C);
    if (LOCAL_D6600(this)->unk4 == 8) {
        return TRUE;
    }
    return func_80309D58(&sp1C, this->unk10_18);
}


void func_8035D65C(Actor *this) {
    if (this->unk38_31 != 0) {
        this->unk38_31--;
        return;
    }
    if (func_80329530(this, 500) && func_8028B470() && func_8035D608(this)) {
        this->unk28 = 2.0f;
        func_80328B8C(this, 4, 0.0f, -1);
    }
}

void func_8035D6FC(Actor *this) {
    func_80328B8C(this, 3, 0.0f, -1);
    this->unk28 = 2.0f;
    func_80328C64(this, (s32) (randf2(-45.0f, 45.0f) + (this->yaw + 180.0f)));
    func_80328CA8(this, (s32) func_8035D590(randf2(-45.0f, 45.0f) + (360.0f - this->pitch)));
    this->unk38_31 = 0x78;
}

void func_8035D7CC(Actor *this) {
    func_80328B8C(this, 3, 0.0f, -1);
    this->unk28 = 2.0f;
    func_80328C64(this, (s32) (randf2(-45.0f, 45.0f) + (this->yaw + 180.0f)));
    func_80328CA8(this, (s32) func_8035D590(randf2(-45.0f, 45.0f) + (360.0f - this->pitch)));
}

void func_8035D88C(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    func_80328B8C(this, 7, 0.0f, -1);
    actor_playAnimationOnce(this);
    FUNC_8030E8B4(SFX_115_BUZZBOMB_DEATH, 0.8f, 30000, this->position, 1500, 3000);
    actor_collisionOff(this);
}

void func_8035D8F0(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if (this->state >= 5U) {
        if (func_803294F0(this, 0x50, func_80329784(this))) {
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
        func_802EFB70(pCtrl, 0.1f, 0.2f);
        func_802EFB84(pCtrl, 0.1f, 0.2f);
        particleEmitter_emitN(pCtrl, 3);
    }
}

void func_8035DA1C(Actor *this) {
    f32 sp44;
    f32 sp40;
    s32 sp3C;
    bool sp38;

    if (!this->initialized) {
        this->initialized = TRUE;
        this->unk138_25 = TRUE;
        this->unk28 = 4.0f;
        LOCAL_D6600(this)->unk4 =(map_get() == MAP_71_GL_STATUE_ROOM) ? 8 : 0xf;
        if (func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)) {
            this->unk28 = 0.0f;
            func_80328B8C(this, 1, 0.0f, 1);
        }
        func_8032CA80(this, LOCAL_D6600(this)->unk4);
        marker_setCollisionScripts(this->marker, func_8035D8F0, NULL, func_8035D88C);
    }

    this->marker->unk14_20 = MARKER_69_CHUMP_FISH;
    if (randf() < 0.01) {
        LOCAL_D6600(this)->unk0 = 5;
    }
    if (LOCAL_D6600(this)->unk0 != 0 && !(func_8023DB5C() & 0xF)) {
        LOCAL_D6600(this)->unk0--;
        func_8035D95C(this->marker);
    }
    switch(this->state){
        case 1://L8035DB78
            func_80328FB0(this, 0.5f);
            func_80328FF0(this, 0.5f);
            func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (func_80328B38(this, 2, 0.05f) && !func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)) {
                this->unk28 = 4.0f;
            }
            func_8035D65C(this);
            break;

        case 2://L8035DBE4
            func_80328FB0(this, 0.5f);
            func_80328FF0(this, 0.5f);
            if (func_80329480(this) && randf() < 0.01) {
                func_80328C64(this, (s32)(this->yaw + randf2(-45.0f, 45.0f)));
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
            if (func_80328BD4(this, 1, 0.0f, 1, 0.005f)) {
                this->unk28 = 2.0f;
            }
            func_8035D65C(this);
            break;

        case 3://L8035DD54
            func_80328FB0(this, 3.0f);
            func_80328FF0(this, 3.0f);
            func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (func_80329480(this) && func_8032944C(this)) {
                func_80328B8C(this, 2, 0.0f, -1);
                this->unk28 = 4.0f;
            }
            break;

        case 4://L8035DDB8
            func_803297FC(this, &sp40, &sp44);
            func_80328C64(this, (s32) sp44);
            func_80328CA8(this, (s32) func_8035D590(sp40));
            func_80328FB0(this, 10.0f);
            func_80328FF0(this, 10.0f);
            func_8032CA80(this, LOCAL_D6600(this)->unk4);
            if (func_80329480(this) && func_8032944C(this)) {
                func_80328B8C(this, 5, 0.0f, -1);
                this->unk28 = 10.5f;
            }
            break;

        case 6://L8035DE60
            if (actor_animationIsAt(this, 0.5f)) {
                func_8030E6A4(SFX_6D_CROC_BITE, 1.1f, 10000);
            }
        case 5://L8035DE84
            this->marker->unk14_20 = MARKER_173_CHUMP_FISH_2;
            func_803297FC(this, &sp40, &sp44);
            func_80328C64(this, (s32) sp44);
            func_80328CA8(this, (s32) func_8035D590(sp40));
            func_80328FB0(this, 10.0f);
            func_80328FF0(this, 10.0f);
            sp38 = func_80329530(this, 0x12C);
            if ((this->state == 5) && sp38) {
                func_80328B8C(this, 6, 0.0f, -1);
            }
            if ((this->state == 6) && !sp38) {
                func_80328B8C(this, 5, 0.0f, -1);
            }
            if ((func_8032CA80(this, LOCAL_D6600(this)->unk4) & ~2)) {
                func_8035D7CC(this);
            }
            break;
        
        case 7://L8035DFA0 
            if(actor_animationIsAt(this, 0.5f)) {
                func_80326310(this);
            }
            break;
    }
}
