#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038FF00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038FF54(Actor *this);

/* .data */
ActorAnimationInfo D_803925C0[] = {
    {0x000, 0.0f},
    {0x1AC, 3.8f},
    {0x1AC, 3.8f},
    {0x1AE, 0.55f},
    {0x1AE, 0.55f},
    {0x1B3, 0.6f},
    {0x1B4, 0.8f},
    {0x1AE, 0.55f},
    {0x1AD, 4.4f},
    {0x1B6, 1.2f},
    {0x221, 5.0f},
    {0x1AE, 0.55f},
    {0x1AE, 0.55f}
};

ActorInfo D_80392628 = { MARKER_20C_WOZZAS_JIGGY, ACTOR_1F4_WOZZAS_JIGGY, ASSET_495_MODEL_WOZZAS_JIGGY,
    0x1, D_803925C0,
    func_8038FF54, func_80326224, func_8038FF00,
    0, 0, 0.0f, 0
};

/* .code */
Actor *func_8038FF00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(func_8038BFA0()) return this;

    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8038FF54(Actor *this){
    static struct31s D_8039264C = {{0.3f, 0.5f}, {0.5f, 0.7f}, {0.0f, 0.01f}, {0.3f, 0.4f}, 0.3f, 0.7f};
    Actor *other;
    f32 sp40[3];
    ParticleEmitter *sp3C;

    if( func_8038BFA0() )               return;
    if( !subaddie_playerIsWithinSphere(this, 4500) )    return;

    this->marker->propPtr->unk8_3 = FALSE;
    actor_collisionOff(this);
    if(this->unk100){
        other = marker_getActor(this->unk100);
        if(this->state != 9){
            if(other->state == 9){
                subaddie_set_state_with_direction(this, 9, 0.01f, 1);
                actor_playAnimationOnce(this);
            }
            else{
                animctrl_setIndex(this->animctrl, animctrl_getIndex(other->animctrl));
                animctrl_setStart(this->animctrl, animctrl_getAnimTimer(other->animctrl));
                animctrl_setDuration(this->animctrl, animctrl_getDuration(other->animctrl));
                animctrl_setSmoothTransition(this->animctrl, FALSE);
                animctrl_start(this->animctrl, "chwozzasjig.c", 0x87);
                this->position[0] = other->position[0];
                this->position[1] = other->position[1];
                this->position[2] = other->position[2];
                this->yaw = other->yaw;
            }
        }
    }//L8039008C

    if(this->state == 9){
       if(0.99999 <= animctrl_getAnimTimer(this->animctrl)){
            func_8034A174(this->marker->unk44, 5, sp40);
            sp40[0] = (f32)(s32)sp40[0];
            sp40[1] = (f32)(s32)sp40[1];
            sp40[2] = (f32)(s32)sp40[2];
            func_802C8F70(this->yaw + 90.0f);
            jiggy_spawn(JIGGY_32_FP_WOZZA, sp40);
            levelSpecificFlags_set(0x26, TRUE);
            marker_despawn(this->marker);
       }
       else if(this->marker->unk14_21){//L8039016C
            sp3C = partEmitMgr_newEmitter(1);
            func_8034A174(this->marker->unk44, 5, sp40);
            particleEmitter_setSprite(sp3C, ASSET_713_SPRITE_SPARKLE_YELLOW);
            particleEmitter_setStartingFrameRange(sp3C, 1, 6);
            particleEmitter_setPosition(sp3C, sp40);
            particleEmitter_setParticleSpawnPositionRange(sp3C,
                0.0f, 20.0f, 0.0f,
                0.0f, 20.0f, 0.0f
            );
            particleEmitter_setParticleVelocityRange(sp3C,
                -180.0f,   0.0f, -180.0f,
                 180.0f, 280.0f,  180.0f
            );
            particleEmitter_setParticleAccelerationRange(sp3C,
                0.0f, -60.0f, 0.0f,
                0.0f, -90.0f, 0.0f
            );
            func_802EFB98(sp3C, &D_8039264C);
            particleEmitter_emitN(sp3C, 1);
       }
    }
}
