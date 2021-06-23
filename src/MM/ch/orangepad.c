#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void func_80326224(Actor *);
int func_80311480(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg5)(ActorMarker *, s32, s32));
void func_80329904(ActorMarker *, s32, void *);

/* public functions */
void func_80386768(Actor *);


/* .data */
ActorInfo chorangepadInfo = { 0x66, actor_orange_pad, model_orange_pad, 0, NULL,
    func_80386768, func_80326224, func_80325888,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

extern f64 D_80389B48;

/*.code */
void func_803863F0(s32 x, s32 y, s32 z){
    f32 pos[3];

    TUPLE_ASSIGN(pos, x, y, z);
    
    jiggySpawn(jiggy_mm_orange_pads, pos);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/orangepad/func_80386444.s")

void func_80386744(s32 arg0, s32 arg1) {
    func_80386444(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/orangepad/func_80386768.s")
/*void func_80386768(Actor * this){
    Actor *sp3C;
    f32 *sp34;
    

    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOff(this);
        this->initialized = 1;
    }//L803867B0

    if(!this->unk16C_4){
        this->unk100 = func_80326D68(this->position, 8,-1, &sp34)->marker;
        this->unk16C_4 = 1;
    }//L803867E0

    if(this->unk100){
        sp3C = marker_getActor(this->unk100);
    }

    if( func_80329530(this, 0x28)
        && !func_8028ECAC()
        && !mapSpecificFlags_get(6)
        && sp3C->unk10_31 != 3
    ){
        if(func_80311480(0xb3d, 0, NULL, NULL, NULL, NULL))
            mapSpecificFlags_set(6,1);
    }

    if(this->unk10_31 == 1){
            if(this->unk60 < 72.0f){
                func_8033E73C(this->marker, 5, func_80329904);
                func_8033E3F0(9, this->marker->unk14_21);
            }
            this->unk60 = MIN(D_80389B48, this->unk60 + 7.0);

            if(D_80389B48 == this->unk60){
                marker_despawn(this->marker);
            }
    }//L80386928
    else{ }
    func_8032628C(this, 0xFF - (s32)this->unk60);
}//*/
