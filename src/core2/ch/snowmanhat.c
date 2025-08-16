#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chSnowmanHat_update(Actor *this);

/* .data */
ActorInfo chSnowmanHat = {
    MARKER_B3_SIR_SLUSH_HAT, ACTOR_126_SIR_SLUSH_HAT, ASSET_379_MODEL_SIRSLUSH_HAT,
    0x1, NULL, 
    chSnowmanHat_update, actor_update_func_80326224, actor_draw, 
    4500, 0, 1.0f, 0
};

/* code */
void chSnowmanHat_update(Actor *this){
    switch(this->state){
        case 1:
            this->position[0] += this->velocity[0];
            this->position[1] += this->velocity[1];
            this->position[2] += this->velocity[2];

            this->velocity[1] += -3.0f;

            this->pitch += 10.0f;
            if( 360.0f <= this->pitch)
                this->pitch -= 360.0f;

            if(this->position_y <= mapModel_getFloorY(this->position)){
                subaddie_set_state(this, 2);
                sfx_playFadeShorthandDefault(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 32750, this->position, 2250, 4500);
            }
            break;

        case 2:
            func_80326310(this);
            break;
    }
}
