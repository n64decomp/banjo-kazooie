#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8031A9E4(Actor *this);

/* .data */
extern ActorInfo D_8036D970 = { 
    0x1E1, 0x376, 0x0, 
    0x1, NULL,
    func_8031A9E4, func_80326224, func_80325340, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
int func_8031A580(void){
    switch(map_get()){
        case MAP_3A_RBB_BOSS_BOOM_BOX:
            return 0;
        case MAP_10_BGS_MR_VILE:
            return 1;
        case MAP_13_GV_MEMORY_GAME:
            return 2;
        case MAP_5A_CCW_SUMMER_ZUBBA_HIVE:
        case MAP_5B_CCW_SPRING_ZUBBA_HIVE:
        case MAP_5C_CCW_AUTUMN_ZUBBA_HIVE:
            return 3;
        case MAP_11_BGS_TIPTUP:
            return 4;
        case MAP_A_TTC_SANDCASTLE:
            return 5;
    }
    return 0xf;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_935F0/func_8031A618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_935F0/func_8031A678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_935F0/func_8031A794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_935F0/func_8031A7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_935F0/func_8031A7F4.s")

void func_8031A9BC(Actor *this){
    func_803204E4(3, 0);
}

void func_8031A9E4(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->unk10_12 = func_8031A580();
        actor_collisionOff(this);
        if(!func_803203FC(2)){
            func_8031A678(this);
            return;
        }
    
        func_8031A618(this);
        func_803300D8(this->marker, func_8031A9BC);
        func_8028FAB0(this->position);
        this->unk1C[0] = 0.0f; this->unk1C[1] = this->yaw; this->unk1C[2] = 0.0f;
        func_8028FAEC(this->unk1C);
        this->unk138_24 = 0;
        if(this->unk10_12 >= 7){
            marker_despawn(this->marker);
            return;
        }
        func_803204E4(5, 0);
        func_803204E4(3, 0);
        func_8031A7F4(this, 1);
        func_80314AC8(0);
    }
    if(func_803203FC(2)){
        switch(this->state){
            case 1://L8031AB2C
                if(this->unk138_24)
                    func_8031A7F4(this, 2);
                break;
            case 2://L8031AB50
                func_8028FA14(0x8E, 2);
                if(item_getCount(ITEM_14_HEALTH) == 0)
                    item_set(ITEM_6_HOURGLASS, FALSE);
                if(!func_803203FC(3)){
                    func_8031A7F4(this, 3);
                }
                break;
            case 3:
                break;
        }
    }//L8031AB8C
}
