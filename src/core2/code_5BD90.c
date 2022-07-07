#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802E2D20(Actor *this);

/* .data */
ActorInfo D_803687C0 = {
    0xB3, 0x126, 0x379,
    0x1, NULL, 
    func_802E2D20, func_80326224, func_80325888, 
    4500, 0, 1.0f, 0
};

/* code */
void func_802E2D20(Actor *this){
    switch(this->state){
        case 1:
            this->position[0] += this->velocity[0];
            this->position[1] += this->velocity[1];
            this->position[2] += this->velocity[2];

            this->velocity[1] += -3.0f;

            this->pitch += 10.0f;
            if( 360.0f <= this->pitch)
                this->pitch -= 360.0f;

            if(this->position_y <= func_80309724(this->position)){
                func_80328A84(this, 2);
                FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 32750, this->position, 2250, 4500);
            }
            break;

        case 2:
            func_80326310(this);
            break;
    }
}
