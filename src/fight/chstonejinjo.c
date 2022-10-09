#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

extern Actor *func_80326EEC();
extern void func_80328B8C(Actor*, s32, f32, s32);
extern f32 chbossjinjo_8038D268(void);

void chstonejinjo_update(Actor *);

/* .data */
ActorAnimationInfo D_803919F0[] ={
    {0, 0.0f},
    {0x265, 1e+8f},
    {0x265, 1e+8f},
    {0x265, 1e+8f},
};
ActorInfo D_80391A10 = {
    MARKER_276_STONE_JINJO, ACTOR_3A1_STONE_JINJO, ASSET_545_MODEL_STONE_JINJO,
    0x1, D_803919F0,
    chstonejinjo_update, func_80326224, func_80325888,
    0, 0x800, 1.0f, 0
};

/* .code */
void chstonejinjo_spawnJinjo(ActorMarker *marker) {
    Actor *this;
    Actor *jinjo;

    this = marker_getActor(marker);
    if (this->unkF4_8 == BOSSJINJO_JINJONATOR) {
        jinjo = spawn_child_actor(ACTOR_3AC_JINJONATOR, &this);
    } else {
        jinjo = spawn_child_actor((this->unkF4_8) + 0x3A4, &this);
    }
    jinjo->unkF4_8 = this->unkF4_8;
    jinjo->unk60 = this->unk1C[0];
    jinjo->scale = this->scale;
}

void chstonejinjo_update(Actor *this) {
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        if (this->unkF4_8 == BOSSJINJO_JINJONATOR) {
            this->marker->unk40_23 = TRUE;
            this->marker->unk40_20 = TRUE;
            this->unk1C[0] = 6.0f;
            this->scale *= 4.0;
        } else {
            this->unk1C[0] = 2.0f;
            this->scale *= 1.8;
        }
    }
    switch (this->state) {
    case 1:
        animctrl_setAnimTimer(this->animctrl, 0.0f);
        break;
    case 2:
        if (this->unkF4_8 != BOSSJINJO_JINJONATOR) {
            if (actor_animationIsAt(this, 0.001f)) {
                FUNC_8030E8B4(SFX_D_EGGSHELL_BREAKING, 1.2f, 25000, this->position, 1000, 5000);
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.6f, 0.8f), 20000, this->position, 1000.0f, 5000.0f);
            }
            if( actor_animationIsAt(this, 0.26f)
                || actor_animationIsAt(this, 0.43f)
                || actor_animationIsAt(this, 0.55f)
                || actor_animationIsAt(this, 0.62f)
                || actor_animationIsAt(this, 0.77f)
            ) {
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.6f, 0.8f), 20000, this->position, 1000.0f, 5000.0f);
            }
        } else {
            if (actor_animationIsAt(this, 0.001f)) {
                FUNC_8030E8B4(SFX_D_EGGSHELL_BREAKING, 1.2f, 25000, this->position, 1000, 5000);
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.4f, 0.6f), 20000, this->position, 1000.0f, 5000.0f);
            }
            if( actor_animationIsAt(this, 0.26f) 
                || actor_animationIsAt(this, 0.43f)
                || actor_animationIsAt(this, 0.55f)
                || actor_animationIsAt(this, 0.62f)
                || actor_animationIsAt(this, 0.77f)
            ) {
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.4f, 0.6f), 20000, this->position, 1000.0f, 5000.0f);
            }
            if( actor_animationIsAt(this, 0.1f)
                || actor_animationIsAt(this, 0.23f)
                || actor_animationIsAt(this, 0.34f)
                || actor_animationIsAt(this, 0.45f)
                || actor_animationIsAt(this, 0.55f)
                || actor_animationIsAt(this, 0.65f)
                || actor_animationIsAt(this, 0.78f)
                || actor_animationIsAt(this, 0.83f)
                || actor_animationIsAt(this, 0.9f)
                || actor_animationIsAt(this, 0.98f)
            ) {
                func_8030E6A4(SFX_3_DULL_CANNON_SHOT, randf2(1.2f, 1.4f), 20000);
            }
        }
        if (actor_animationIsAt(this, 0.999f)) {
            func_80328B8C(this, 3, 0.99999f, 1);
            actor_playAnimationOnce(this);
            func_80326310(this);
        }
        break;
    }
}

void chstonejinjo_breakOpen(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24[3];
    
    if(actor->state != 2){
        func_80328B8C(actor, 2, 0.0f, 1);
        actor_playAnimationOnce(actor);
        animctrl_setDuration(actor->animctrl, actor->unk1C[0]);
        SPAWNQUEUE_ADD_1(chstonejinjo_spawnJinjo, actor->marker);
        if(!func_8031FF1C(BKPROG_D1_HAS_ACTIVATED_A_JINJO_STATUE_IN_FINAL_FIGHT) && actor->unkF4_8 != BOSSJINJO_JINJONATOR){
            sp38 = 0x30 + actor->unkF4_8*2;
            sp34 = chbossjinjo_8038D268();
            sp30 = actor->unk1C[0] + sp34;
            func_8038C0DC(&sp24);
            func_8028F94C(2, &sp24);
            func_8038C27C(1);
            timed_setCameraToNode(0 * sp30, sp38);
            func_80324E88(1 * sp30);
            timed_setCameraToNode(1 * sp30, sp38 + 1);
        }
    }//L8038DF8C
}

f32 func_8038DFA0(void) {
    return func_80326EEC(ACTOR_3A1_STONE_JINJO)->unk1C_x;
}
