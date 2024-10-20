#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern f32 func_8028EF88(void);
void func_802D8730(Actor *this);

/* .data */
ActorInfo D_80367C60 = { 
    0x15E, 0x188, 0x0, 
    0, NULL, 
    func_802D8730, actor_update_func_80326224, func_80325340,
    0, 0, 0.0f, 0
};

s32 D_80367C84[3] = {255, 100, 100};

/* .code */
void func_802D8730(Actor *this) {
    f32 dt;
    f32 sp38;
    ParticleEmitter *pCtrl;

    dt = time_getDelta();
    if (!func_8032BBE8(this)) {
        this->velocity_y = 0.0f;
        this->velocity_x = 1.0f;
    } else {
        this->velocity_x -= dt;
    }
    if (this->velocity_x < 0.0f) {
        marker_despawn(this->marker);
        return;
    }

    sp38 = func_8028EF88();
    player_getPosition(this->position);
    if(sp38 < this->position_y)
        return;

    viewport_adjustPointDistance(this->position, 40.0f);
    this->position_y = sp38;
    this->velocity_y -= dt;
    if (this->velocity_y < 0.0f) {
        this->velocity_y = 0.07f;
        pCtrl = func_802F4094(this->position, 40.0f);
        particleEmitter_setStartingScaleRange(pCtrl, 0.05f, 0.06f);
        particleEmitter_setAccelerationRange(pCtrl, 0.0f, -3400.0f, 0.0f, 0.0f, -3400.0f, 0.0f);
        particleEmitter_setRGB(pCtrl, D_80367C84);
        particleEmitter_setParticleVelocityRange(pCtrl, -180.0f, 200.0f, -180.0f, 180.0f, 400.0f, 180.0f);
        particleEmitter_emitN(pCtrl, 9);
    }
}
