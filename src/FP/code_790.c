#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80386B80(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80386CF8(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391A90[];

extern ActorInfo D_80391AB0 = { 
    0xB9, ACTOR_116_FP_SNOWMAN_BUTTON, ASSET_421_MODEL_FP_SNOWMAN_BUTTON, 
    0x1, D_80391A90, 
    func_80386CF8, func_80326224, func_80386B80, 
    { 0x0, 0x0, 0x8, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern struct31s D_80391AD4;
extern struct43s D_80391AFC;
extern s32       D_80391B44[3];

/* .code  */
Actor *func_80386B80(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(1, this->state == 3);
    func_8033A45C(2, func_8033A0F0(1) ^ 1);
    return func_80325888(marker, gfx, mtx, vtx);

}

void func_80386BEC(Actor *this){
    f32 plyr_pos[3];
    ParticleEmitter *pCtrl = func_802F0BD0(12);
    
    player_getPosition(plyr_pos);
    func_80328B8C(this, 2, 0.01f, 1);
    actor_collisionOff(this);
    func_8025A6EC(COMUSIC_2B_DING_B, 28000);
    FUNC_8030E624(SFX_90_SWITCH_PRESS, 1000, 0x3ff);
    func_8038AB40();
    func_802EFFA8(pCtrl, D_80391B44);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setPosition(pCtrl, plyr_pos);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80391AFC);
    func_802EFB98(pCtrl, &D_80391AD4);
    particleEmitter_emitN(pCtrl, 12);
}

void func_80386CB8(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    
    if(this->state == 1)
        func_80386BEC(this);
    
}

void func_80386CF8(Actor *this){
    func_803300A8(this->marker, NULL, NULL, func_80386CB8);
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOn(this);
    
    if(!this->initialized){
        this->initialized = TRUE;
        this->pitch += (f32)(this->unkF4_8 - 1);
    }
    
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(this->state == 3){
            func_8038AB40();
        }
    }

    switch(this->state){
        case 1:
            break;
        case 2:
            if(actor_animationIsAt(this, 0.99f)){
                func_80328B8C(this, 3, 0.99f, 0);
            }
            break;
        case 3:
            break;
    }
}