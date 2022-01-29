#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80389B1C(Actor *this);

/* .data */
ActorAnimationInfo D_80390EA0[] = {
    {0x00, 0.0f},
    {0xDF, 4.5f},
    {0xE3, 2.0f},
    {0xE4, 1.95f},
    {0xCE, 2.4f},
    {0xDF, 4.5f}
};

ActorInfo D_80390ED0 = { MARKER_A9_RUBEE, ACTOR_11B_RUBEE, ASSET_3DD_MODEL_RUBEE, 
    0x2, D_80390EA0,
    func_80389B1C, func_80326224, func_80325888,
    { 0x9, 0xC4}, 0, 1.6f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
void func_80389A20(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    func_8038E18C();
    func_80328B8C(this, 3, 0.0f, 1);
}

void func_80389A60(Actor *this){
    func_80311480(ASSET_A70_TEXT_CHARMER_HELPED, 4, NULL, this->marker, func_80389A20, NULL);
    this->unk138_24 = TRUE;
    func_80328A84(this, 5);
}

void func_80389ABC(Actor *this){
    if(this->unk138_23){
        func_80389A20(this->marker, ASSET_A70_TEXT_CHARMER_HELPED, -1);
    }
    else{
        this->unk138_23 = TRUE;
        mapSpecificFlags_set(2, TRUE);
        func_80389A60(this);
    }
}

void func_80389B1C(Actor *this){
    if(!this->unk16C_4){
        this->unk60 = (f32) func_8038E184();
        this->unk138_24 = jiggyscore_isCollected(JIGGY_43_GV_HISTUP) || mapSpecificFlags_get(0);
        this->unk138_23 = jiggyscore_isCollected(JIGGY_43_GV_HISTUP) || mapSpecificFlags_get(2);
        this->unk16C_4 = TRUE;
    }

    if(!this->initialized){
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }

    animctrl_setTransitionDuration(this->animctrl, 0.15f);

    if(this->state == 1 || this->state == 2){
        if(! this->unk138_24 && func_80329530(this, 250) && !func_80329530(this, 0x50)){
            func_80311480(ASSET_A6F_TEXT_CHARMER_MEET, 0xe, this->position, NULL, NULL, NULL);
            this->unk138_24 = TRUE;
            mapSpecificFlags_set(0, TRUE);
        }
    }

    switch(this->state){
        case 1://L80389CC4
            if(this->unk60 <= (f32)func_8038E178()){
                func_80389ABC(this);
            }
            else if(actor_animationIsAt(this, 0.99f)){
                func_80328B38(this, 2, 0.9f);
            }

            if( actor_animationIsAt(this, 0.42f)
                || actor_animationIsAt(this, 0.46f)
                || actor_animationIsAt(this, 0.51f)
                || actor_animationIsAt(this, 0.57f)
            ){
                FUNC_8030E8B4(SFX_8_BANJO_LANDING_04, 250, 0xF31, this->position, 1500, 4500);
            }

            if( actor_animationIsAt(this, 0.4f)){
                func_803865E8();
            }
            break;

        case 2: //L80389DB0
            if(this->unk60 <= (f32)func_8038E178()){
                func_80389ABC(this);
            }
            else if(actor_animationIsAt(this, 0.99f)){
                func_80328B38(this, 1, 0.4f);
            }
            break;
        case 3: //L80389E14
            if( actor_animationIsAt(this, 0.2f)){
                func_8025A58C(500, 400);
                func_8025A6EC(COMUSIC_27_GV_RUBEES_SONG, 28000);
            }

            if( actor_animationIsAt(this, 0.99f)){
                func_80328A84(this, 4);
            }
            break; 
        case 4: //L80389E64
            if(!func_8038E178())
                func_80328A84(this, 2);
            break; 
    }//L80389E80
}
