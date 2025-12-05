#include <ultra64.h>
#include "functions.h"
#include "variables.h"
Actor *func_8038F0F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038F144(Actor *this);

/* .data */
ActorAnimationInfo D_803924A0[] = {
    {0, 0.0f},
    {ASSET_18A_ANIM_XMAS_GIFT, 1.5f}
};

ActorInfo gChPresentBlue = { MARKER_208_BLUE_PRESENT, ACTOR_33A_BLUE_PRESENT, ASSET_47F_MODEL_XMAS_GIFT_BLUE, 
    0x1, D_803924A0,
    func_8038F144, actor_update_func_80326224, func_8038F0F0,
    2500, 0, 1.2f, 0
};

ActorInfo gChPresentGreen = { MARKER_209_GREEN_PRESENT, ACTOR_33B_GREEN_PRESENT, ASSET_480_MODEL_XMAS_GIFT_GREEN, 
    0x1, D_803924A0,
    func_8038F144, actor_update_func_80326224, func_8038F0F0,
    2500, 0, 1.2f, 0
};

ActorInfo gChPresentRed = { MARKER_20A_RED_PRESENT, ACTOR_33C_RED_PRESENT, ASSET_481_MODEL_XMAS_GIFT_RED, 
    0x1, D_803924A0,
    func_8038F144, actor_update_func_80326224, func_8038F0F0,
    2500, 0, 1.2f, 0
};

/* .code */
Actor *func_8038F0F0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->unk38_31)
        return this;
    else
        return actor_draw(marker, gfx, mtx, vtx);
    
}

void func_8038F144(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(!jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)){
            this->unk38_31 = TRUE;
            this->marker->collidable = FALSE;
            this->marker->propPtr->unk8_3 = FALSE;
        }
        else{
            this->unk38_31 = FALSE;
            this->marker->collidable = FALSE;
            this->marker->propPtr->unk8_3 = TRUE;
            anctrl_setAnimTimer(this->anctrl, randf());
        }
    }
    if (this) if (this);
}
