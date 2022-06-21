#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *func_80326EEC();
extern void func_80328B8C(Actor*, s32, f32, s32);
extern f32 func_8038D268(void);

void func_8038DA04(Actor *);

/* .data */
ActorAnimationInfo D_803919F0[] ={
    {0, 0.0f},
    {0x265, 1e+8f},
    {0x265, 1e+8f},
    {0x265, 1e+8f},
};
ActorInfo D_80391A10 = { 0x276, 0x3A1, 0x545, 0x1, D_803919F0, func_8038DA04, func_80326224, func_80325888, 0, 0x800, 1.0f, 0};


/* .code */
void func_8038D970(ActorMarker *arg0) {
    Actor *temp_v0;
    Actor *phi_v0;

    temp_v0 = marker_getActor(arg0);
    if (temp_v0->unkF4_8 == 5) {
        phi_v0 = spawn_child_actor(0x3AC, &temp_v0);
    } else {
        phi_v0 = spawn_child_actor((temp_v0->unkF4_8) + 0x3A4, &temp_v0);
    }
    phi_v0->unkF4_8 = temp_v0->unkF4_8;
    phi_v0->unk60 = temp_v0->unk1C[0];
    phi_v0->scale = temp_v0->scale;
}

void func_8038DA04(Actor *this) {
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        if (this->unkF4_8 == 5) {
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
        func_8028764C(this->animctrl, 0.0f);
        break;
    case 2:
        if (this->unkF4_8 != 5) {
            if (actor_animationIsAt(this, 0.001f)) {
                func_8030E8B4(0x9978680D, this->position, 0x138803E8);
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.6f, 0.8f), 0x4E20U, this->position, 1000.0f, 5000.0f);
            }
            if( actor_animationIsAt(this, 0.26f)
                || actor_animationIsAt(this, 0.43f)
                || actor_animationIsAt(this, 0.55f)
                || actor_animationIsAt(this, 0.62f)
                || actor_animationIsAt(this, 0.77f)
            ) {
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.6f, 0.8f), 0x4E20U, this->position, 1000.0f, 5000.0f);
            }
        } else {
            if (actor_animationIsAt(this, 0.001f)) {
                func_8030E8B4(0x9978680D, this->position, 0x138803E8);
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.4f, 0.6f), 0x4E20U, this->position, 1000.0f, 5000.0f);
            }
            if( actor_animationIsAt(this, 0.26f) 
                || actor_animationIsAt(this, 0.43f)
                || actor_animationIsAt(this, 0.55f)
                || actor_animationIsAt(this, 0.62f)
                || actor_animationIsAt(this, 0.77f)
            ) {
                func_8030E878(SFX_80_YUMYUM_CLACK, randf2(0.4f, 0.6f), 0x4E20U, this->position, 1000.0f, 5000.0f);
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
                func_8030E6A4(SFX_3_DULL_CANNON_SHOT, randf2(1.2f, 1.4f), 0x4E20);
            }
        }
        if (actor_animationIsAt(this, 0.999f) != 0) {
            func_80328B8C(this, 3, 0.99999f, 1);
            actor_playAnimationOnce(this);
            func_80326310(this);
        }
        break;
    }
}

void func_8038DE98(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp24[3];
    
    if(actor->state != 2){
        func_80328B8C(actor, 2, 0.0f, 1);
        actor_playAnimationOnce(actor);
        animctrl_setDuration(actor->animctrl, actor->unk1C[0]);
        func_802C3C88(func_8038D970, actor->marker);
        if(!func_8031FF1C(0xD1) && actor->unkF4_8 != 5){
            sp38 = 0x30 + actor->unkF4_8*2;
            sp34 = func_8038D268();
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
    return func_80326EEC(0x3A1)->unk1C_x;
}
