#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F7D4(f32, f32);
void func_802D8528(Actor *this);

extern ActorAnimationInfo D_80367B50[];

extern ActorInfo D_80367B80 = {
    0x36, 0x29, 0x2D2,
    0x5, NULL,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 0.6f,0
};

extern ActorInfo D_80367BA4 = {
    0x37, 0x2A, 0x3C7,
    0x5, NULL,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 0.6f, 0
};

extern ActorInfo D_80367BC8 = {
    0x1FD, 0x1ED, 0x47F,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 1.8f, 0
};

extern ActorInfo D_80367BEC = {
    0x1FE, 0x1EF, 0x480,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 1.4f, 0
};

extern ActorInfo D_80367C10 = {
    0x1FF, 0x1F1, 0x481,
    0x5, D_80367B50,
    func_802D8528, func_80326224, func_80325888,
    0, 0, 1.4f, 0
};

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D7960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D7A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D7B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D7BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D7C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D7DE8.s")

void func_802D8030(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D8030.s")

void func_802D8068(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D8068.s")

void func_802D8374(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D8374.s")

void func_802D83EC(Actor *this);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_509D0/func_802D83EC.s")

void func_802D84F4(Actor *this){
    this->marker->propPtr->unk8_3 = ( this->state == 2 );
}

void func_802D8528(Actor *this){
    s32 marker_id;
    if(this->despawn_flag) return;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if( this->marker->unk14_20 == 0x1FD
            || this->marker->unk14_20 == 0x1FE
            || this->marker->unk14_20 == 0x1FF
        ){
            if(jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)){
                marker_despawn(this->marker);
                return;
            }
        }
        if(this->unk138_22){
            func_8028F7D4(0.0f, 0.0f);
            func_80328A84(this, 3);
        }
    }//L802D85DC

    switch(this->state){
        case 5:// 802D8604
            func_802D8030(this);
            break;

        case 1:// 802D8620
            func_802D8068(this);
            break;

        case 2:// 802D863C
            break;

        case 3:// 802D8650
            func_802D8374(this);
            break;

        case 4:// 802D866C
            func_802D8068(this);
            break;

        default:
            break;
    }

    marker_id = this->marker->unk14_20;

    switch(this->marker->unk14_20){

        case 0x37: //L802D86CC
            func_802D83EC(this);
            break;
        case 0x36: //L802D86DC
            if(mapSpecificFlags_get(3) && map_get() == MAP_2_MM_MUMBOS_MOUNTAIN){
                marker_despawn(this->marker);
            }
            break;
        
        case 0x1FD:
        case 0x1FE:
        case 0x1FF:
            func_802D84F4(this);
            break;
    }
}
