/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"



/* extern function declarations */

void func_802C8F70(f32);
void func_802C4218(s32, s32, s32, s32);

/* public function declarations */
Actor *chhut_draw(ActorMarker *, Gfx **, Mtx**, Vtx **);
void  chhut_update(Actor *);

/* .bss */
extern s32 D_8037DCB0; //mm_hut_smash_count


/* .data */
ActorAnimationInfo chhutAnimations[3] = {
    {0, 0.0f}, 
    {ASSET_4E_ANIM_MUDHUT_SMASH, 0.25f}, 
    {ASSET_4E_ANIM_MUDHUT_SMASH, 1000000.0f}
};

/* .code */
Actor *chhut_draw(ActorMarker *this, Gfx **arg1, Mtx **arg2, Vtx **arg3){
    Actor *actorPtr;
    s32 temp_a1;
    s32 temp_a2;

    actorPtr = marker_getActor(this);

    temp_a1 = actorPtr->state != 2;
    temp_a2 = actorPtr->state == 0 || actorPtr->state == 2;
    this->propPtr->unk8_3 = temp_a2;
    func_8033A45C(1, temp_a1);

    return actor_draw(this, arg1, arg2, arg3);
}

void func_803869EC(ActorMarker *this){
    Actor * actorPtr;
    f32 *pos;

    actorPtr = marker_getActor(this);
    actorPtr = func_8032813C(0x4B, actorPtr->position, 0);
    func_8032813C(ACTOR_4D_STEAM_2, actorPtr->position, 0);
    
    if(this);
}

void    chhut_update(Actor *this){
    static s32 D_803898D8[6] = { 0, 1, 2, 3, 6, 4};
    f32 sp3C[3];
    f32 sp30[3];

    if(func_80334904() != 2)
        return;

    if(!this->initialized){
        this->marker->collidable = 0;
        this->initialized = 1;
    }
    switch(this->state){
        case 0: //L80386AA4
            player_getPosition(sp30);
            sp3C[0] = sp30[0] - this->position_x;
            sp3C[1] = sp30[1] - this->position_y;
            sp3C[2] = sp30[2] - this->position_z;
            if(150.0f < sp3C[1] 
                && player_getActiveHitbox(this->marker) == HITBOX_1_BEAK_BUSTER 
                && func_8028F20C()
                && gu_sqrtf(sp3C[0]*sp3C[0] + sp3C[1]*sp3C[1] + sp3C[2]*sp3C[2]) < 350.0f
            ){
                sp3C[0] = this->position_x;
                sp3C[1] = this->position_y;
                sp3C[2] = this->position_z;
                sp3C[1] += 125.0;
                func_8030E484(SFX_5B_HEAVY_STUFF_FALLING);
                func_80328A84(this, 1);
                actor_playAnimationOnce(this);
                __spawnQueue_add_1((GenFunction_1)func_803869EC, (s32)this->marker);
                func_802C8F70(this->yaw);
                if(D_8037DCB0 < 5){
                    __spawnQueue_add_4((GenFunction_4)func_802C4218, D_803898D8[D_8037DCB0], *(s32*)(&sp3C[0]),*(s32*)(&sp3C[1]),*(s32*)(&sp3C[2]));
                }
                else{
                    jiggySpawn(JIGGY_5_MM_HUTS, sp3C);
                }
                D_8037DCB0 = ( D_8037DCB0 + 1 ) % 6;
            }
            break;
        case 1: //L80386C2C
            if(animctrl_getAnimTimer(this->animctrl) > 0.99){
                animctrl_setTransitionDuration(this->animctrl, 0.0f);
                func_80328A84(this, 2);
                this->position_y -= 160.0f;
            }
            break;
        case 2: //L80386C80
            break;
    }

}

void mm_resetHuts(void){
    D_8037DCB0 = 0;
}

ActorInfo chhutInfo = { MARKER_51_MM_HUT, ACTOR_9_MM_HUT, ASSET_7D7_MODEL_MM_HUT, 
    0, chhutAnimations,
    chhut_update, func_80326224, chhut_draw,
    0, 0x100, 0.0f, 0
};
