#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_80390290(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80390388(Actor *this);

/* .data */
ActorAnimationInfo D_80392680[] = {
    {0, 0.0f},
    {0x222, 2.0f}
};

ActorInfo D_80392690 = { 0x20D, 0x33D, 0x38A,
    0x1, D_80392680,
    func_80390388, func_80326224, func_80390290,
    2500, 0, 1.0f, 0
};

/* .code */
Actor *func_80390290(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    s32 sp18;

    sp18 = 2;

    if(this->unk38_31) return this;

    if(func_803114C4() == 0xC1F || func_803114C4() == 0xC1E){
        sp18 = 1;
    }
    func_8033A45C(1, 0);
    func_8033A45C(3, sp18);
    actor_draw(marker, gfx, mtx, vtx);
}


int func_80390334(void){
    if( levelSpecificFlags_get(0x11) && levelSpecificFlags_get(0x12) && levelSpecificFlags_get(0x13)){ 
        return TRUE; 
    } 
    return FALSE;
}

void func_80390388(Actor *this){
    actor_collisionOff(this);
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(jiggyscore_isSpawned(JIGGY_2E_FP_PRESENTS) || jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)){
            levelSpecificFlags_set(0x11, TRUE);
            levelSpecificFlags_set(0x12, TRUE);
            levelSpecificFlags_set(0x13, TRUE);
        }
        if(jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3) || jiggyscore_isSpawned(JIGGY_2C_FP_BOGGY_3)){
            this->unk38_31 = FALSE;
            this->marker->propPtr->unk8_3 = TRUE;
        }
        else{
            this->unk38_31 = TRUE;
            this->marker->propPtr->unk8_3 = FALSE;
            return;
        }
    }//L80390468

    if( this->unk38_31 )   return;
    if( this->state != 1 )  return;

    if( jiggyscore_isSpawned(JIGGY_2E_FP_PRESENTS) 
        || jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)
        || func_80390334()
    ){
        this->unk138_24 = TRUE;
    }

    if( func_80329530(this, 0xFA) 
        && (func_8028ECAC() == 0 || func_8028ECAC() == BSGROUP_8_TROT)
    ){
        if(0.0f == this->unk1C[0] && func_80390334()){
            if(func_80311480(0xc1f, 0xb, this->position, NULL, NULL, NULL)){
                this->unk138_24 = TRUE;
                this->unk1C[0] = 1.0f;
            }
        }
        else{
            if( !this->unk138_24 ){
                if(func_80311480(0xc1e, 0x2b, this->position, NULL, NULL, NULL)){
                    this->unk138_24 = TRUE;
                }
            }
        }
    }
}
