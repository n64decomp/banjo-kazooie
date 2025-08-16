#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *chgloop_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chgloop_update(Actor *this);

/* .data */
ActorAnimationInfo chgloop_animations[] ={
    {0x00, 0.0f},
    {ASSET_CA_ANIM_GLOOP_SWIMMING, 2.0f},
    {ASSET_CA_ANIM_GLOOP_SWIMMING, 1.0f},
    {ASSET_CA_ANIM_GLOOP_SWIMMING, 0.4f},
    {ASSET_CB_ANIM_GLOOP_BLOWING_BUBBLE, 1.5f},
    {ASSET_CA_ANIM_GLOOP_SWIMMING, 2.0f},
    {ASSET_CA_ANIM_GLOOP_SWIMMING, 2.0f}
};

ActorInfo chGloop = {
    MARKER_6A_GLOOP, ACTOR_E6_GLOOP, ASSET_372_MODEL_GLOOP, 
    0x2, chgloop_animations,
    chgloop_update, chgloop_update, chgloop_draw, 
    1900, 0, 0.0f, 0
};

/* .code */
Actor *chgloop_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = actor_draw(marker, gfx, mtx, vtx);
    if(!marker->unk14_21)
        return this;

    func_8034A174(func_80329934(), 5, this->unk1C);
    return this;
}

void chgloop_spawnBubble(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    f32 sp1C[3];
    sp1C[0] = reinterpret_cast(f32, arg0);
    sp1C[1] = reinterpret_cast(f32, arg1);
    sp1C[2] = reinterpret_cast(f32, arg2);
    actor_spawnWithYaw_f32(ACTOR_E7_GLOOP_BUBBLE, sp1C, (s32)reinterpret_cast(f32, arg3));
}

void chgloop_update(Actor *this){
    f32 sp34[3];

    if(!this->initialized){
        actor_collisionOff(this);
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
    }

    actor_update_func_80326224(this);
    
    switch(this->state){
        case 2://L802D14DC
            actor_loopAnimation(this);
            if(this->unk54 != 0.0f)
                subaddie_set_state(this, 4);
            
            if( !mapSpecificFlags_get(2) 
                && subaddie_playerIsWithinSphereAndActive(this, 350)
                && gcdialog_showDialog(ASSET_D34_DIALOG_GLOOP_MEET, 0, NULL, NULL, NULL, NULL)
            ){
                mapSpecificFlags_set(2, TRUE);
            }
            break;

        case 4://L802D1558
            actor_playAnimationOnce(this);
            if(this->unk54 == 0.0f)
                subaddie_set_state(this, 2);

            if(actor_animationIsAt(this, 0.6f)){
                if(this->marker->unk14_21){
                    sp34[0] = this->unk1C[0];
                    sp34[1] = this->unk1C[1];
                    sp34[2] = this->unk1C[2];
                }
                else{
                    sp34[0] = this->position[0];
                    sp34[1] = this->position[1];
                    sp34[2] = this->position[2];
                }
                if(subaddie_playerIsWithinSphereAndActive(this, 1900)){
                    __spawnQueue_add_4(chgloop_spawnBubble, reinterpret_cast(s32, sp34[0]), reinterpret_cast(s32, sp34[1]), reinterpret_cast(s32, sp34[2]), reinterpret_cast(s32, this->yaw));
                }

                func_8030E9C4(SFX_3ED_BUBBLE_POP, randf()/2 + 0.6, 32000, this->position, 100.0f, 3000.0f);
            }
            break;
    }//L802D1670
}
