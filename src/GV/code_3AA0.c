#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void GV_func_80389E90(Actor *this);
void GV_func_80389EA8(Actor *this);

/* .data */
ActorInfo D_80390F00 = { MARKER_AB_RUBEES_EGG_POT, ACTOR_11D_RUBEES_EGG_POT, ASSET_3E1_MODEL_RUBEES_EGG_POT, 
    0x1, NULL, 
    GV_func_80389E90, GV_func_80389EA8, actor_draw, 
    2500, 0, 0.9f, 0
};

/* .code */
void GV_func_80389E90(Actor *this){
    this->marker->propPtr->unk8_3 = FALSE;
}

void GV_func_80389EA8(Actor *this){
    this->marker->propPtr->unk8_3 = FALSE;
    this->unk4C = 100 + 40*func_8038E178();
    func_80343DEC(this);

}
