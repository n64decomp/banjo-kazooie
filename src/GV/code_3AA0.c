#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80389E90(Actor *this);
void func_80389EA8(Actor *this);

/* .data */
ActorInfo D_80390F00 = { MARKER_AB_RUBEES_EGG_POT, ACTOR_11D_RUBEES_EGG_POT, ASSET_3E1_MODEL_RUBEES_EGG_POT, 
    0x1, NULL, 
    func_80389E90, func_80389EA8, func_80325888, 
    2500, 0, 0.9f, 0
};

/* .code */
void func_80389E90(Actor *this){
    this->marker->propPtr->unk8_3 = FALSE;
}

void func_80389EA8(Actor *this){
    this->marker->propPtr->unk8_3 = FALSE;
    this->unk4C = 100 + 40*func_8038E178();
    func_80343DEC(this);

}
