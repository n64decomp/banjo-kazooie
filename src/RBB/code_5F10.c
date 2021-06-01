#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038C300(Actor *this);

ActorInfo D_80390B40 = {
    0x198, 0x1ca, 0x41e, 0x0, NULL,
    func_8038C300, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

void func_8038C300(Actor *this){
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = 1;
        func_80335924(this->unk148, 0x140, 0.0f, 1.0f);
    }
}