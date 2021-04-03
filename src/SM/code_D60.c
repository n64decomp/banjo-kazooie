#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* chbottlesctrl - controls bottle teaching moves in spiral*/

//external
void func_80324E60(f32, s32);

//public
void func_80387764(ActorMarker *);


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_80387150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_803871FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_80387258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_80387288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_80387314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_803874C4.s")

//chcolliwobble_update?
void func_80387514(Actor *this){
    f32 sp2C;
    Actor *colliPtr;
    
    
    if(!this->unkF4_21){ 
        colliPtr = func_80326D68(this->position, 0x12b, -1, &sp2C);
        if(colliPtr){
            this->unk1C = colliPtr->position_x;
            this->unk20 = colliPtr->position_y;
            this->unk24 = colliPtr->position_z;
        }else{
            {this->unk1C = this->position_x;
            this->unk20 = this->position_y;
            this->unk24 = this->position_z;}
        }
        this->unk10_14 = (func_8028F190(0xC))? 2 : (func_8028F190(4)? 1:0);
        this->unkF4_21 = 1;
    }

    switch(this->unk10_31){
        case 1://L80387610
            if(mapSpecificFlags_get(4))
                func_80387314(this, 5);
            
            if(func_803874C4() || func_803203FC(0xc1))
                func_80387314(this, 4);
            break;
        case 2://L80387658
            if(mapSpecificFlags_get(7)){
                func_80387764(this->marker);
                mapSpecificFlags_set(7,0);
            }
            break;
        case 5://L80387680
            break;
    }////L80387680      
}
//break???

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_D60/func_80387690.s")
void func_80387690(ActorMarker *, s32, s32);

void func_80387764(ActorMarker * marker){
    s32 sp34;
    int temp_a2;
    s32 sp2C = 4;
    
    Actor *actor = marker_getActor(marker);
    
    temp_a2 = actor->unk38_31 ? 1 : 0 ;
    if( temp_a2 ){
        sp2C = 0xE;
    }

    switch (actor->unk10_14)
    {
    case 0x1: //L803877D8
        sp34 = temp_a2 ? 0xe15 : 0xe14; //dialog enums
        break;

    case 0x2: //L803877F4
        sp34 = temp_a2 ? 0xe17 : 0xe16; //dialog enums
        break;

    case 3: //L80387810
        sp34 = temp_a2 ? 0xe19 : 0xe18; //dialog enums
        break;
    default:
        //sp34 = actor->unk38_31;
        break;
    }//L8038782C
    if(sp34 == 0xe19){ 
        func_8028F94C(2, &actor->unk1C);
    }
    //L80387848
    if(!mapSpecificFlags_get(3) && func_802DA498() && temp_a2){
        mapSpecificFlags_set(3, 1);
        sp34 = 0xE12;
    }//L80387898
    if(temp_a2){
        func_80324E60(0.0f, 6);
    }//L803878B0

    func_80311480(sp34, sp2C, &actor->unk1C, actor->marker, func_80387690, NULL);
    actor->unk38_31++;
}//*/