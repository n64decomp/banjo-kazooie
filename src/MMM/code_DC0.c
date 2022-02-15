#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80387280(Actor *this);

/* .data */
ActorAnimationInfo D_8038BA50[] = {
    {0x00, 0.0f},
    {ASSET_A9_ANIM_FLOWER_POT, 2.0f},
    {ASSET_A9_ANIM_FLOWER_POT, 2.0f}
};

ActorInfo D_8038BA68 = {
    MARKER_34_CEMETARY_POT, ACTOR_25_CEMETARY_POT, ASSET_3AE_MODEL_GRAVE_FLOWER_POT, 
    0x1, D_8038BA50, 
    func_80387280, func_80326224, func_80325888, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
//chflowerpots_getRemaining
s32 func_803871B0(void) {
    return levelSpecificFlags_getN(0x39, 3);
}

//chflowerpots_setRemaining
void func_803871D4(s32 arg0) { 
    levelSpecificFlags_setN(0x39, arg0, 3);
}

void func_803871FC(Actor *this){
    switch(this->state){
        case 1:
            func_8033A45C(3, FALSE);
            break;
        case 2:
            func_8033A45C(3, TRUE);
            break;
    }
    func_803255FC(this);
}

void func_80387260() {
    func_803871D4(5);
}

//chflowerpots_update
void func_80387280(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    if(!this->initialized){
        this->initialized = TRUE;
        this->unk130 = func_803871FC;
    }

    switch(this->state){
        case 1:
            animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
            break;

        case 2:
            if(actor_animationIsAt(this, 0.2f)){
                FUNC_8030E8B4(SFX_12F_FUUUCK_YOUUU, 0x3A9, 0x3ff, this->position, 300, 2000);
            }
            break;
    }
}

bool func_80387340(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    f32 sp20[3];
    s32 sp1C;
    
    if(actor->state == 2) 
        return FALSE;

    func_80328A84(actor, 2);
    animctrl_setPlaybackType(actor->animctrl, ANIMCTRL_ONCE);
    sp1C = func_803871B0();
    if(sp1C != 0){
        sp1C--;
        if(sp1C == 0){
            ml_vec3f_copy(sp20, actor->position);
            sp20[1] += 80.0f;
            func_8025A70C(COMUSIC_2D_PUZZLE_SOLVED_FANFARE);
            jiggySpawn(JIGGY_63_MMM_FLOWER_POTS, sp20);
        }
        else{
            func_8025A70C(COMUSIC_2B_DING_B);
        }
    }
    func_803871D4(sp1C);
    return TRUE;
}