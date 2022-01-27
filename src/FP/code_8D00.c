#include <ultra64.h>
#include "functions.h"
#include "variables.h"
Actor *func_8038F0F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038F144(Actor *this);

/* .data */
ActorAnimationInfo D_803924A0[] = {
    {0, 0.0f},
    {ASSET_18A_XMAS_GIFT, 1.5f}
};

ActorInfo D_803924B0 = { MARKER_208_BLUE_PRESENT, ACTOR_33A_BLUE_PRESENT, ASSET_47F_MODEL_XMAS_GIFT_BLUE, 
    0x1, D_803924A0,
    func_8038F144, func_80326224, func_8038F0F0,
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

ActorInfo D_803924D4 = { MARKER_209_GREEN_PRESENT, ACTOR_33B_GREEN_PRESENT, ASSET_480_MODEL_XMAS_GIFT_GREEN, 
    0x1, D_803924A0,
    func_8038F144, func_80326224, func_8038F0F0,
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

ActorInfo D_803924F8 = { MARKER_20A_RED_PRESENT, ACTOR_33C_RED_PRESENT, ASSET_481_MODEL_XMAS_GIFT_RED, 
    0x1, D_803924A0,
    func_8038F144, func_80326224, func_8038F0F0,
    { 0x9, 0xC4}, 0, 1.2f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
Actor *func_8038F0F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->unk38_31)
        return this;
    else
        return func_80325888(marker, gfx, mtx, vtx);
    
}

void func_8038F144(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(!jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)){
            this->unk38_31 = TRUE;
            this->marker->collidable = FALSE;
            this->marker->propPtr->unk8_3 = FALSE;
        }
        else{
            this->unk38_31 = FALSE;
            this->marker->collidable = FALSE;
            this->marker->propPtr->unk8_3 = TRUE;
            func_8028764C(this->animctrl, randf());
        }
    }
    if (this) if (this);
}
