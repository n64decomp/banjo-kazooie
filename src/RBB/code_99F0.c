#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 pad_803912C0[2];
u8 D_803912C8;

void func_8038FDE0(s32 arg0){  
    static f32 D_803912CC;  

    D_803912CC = 0.0f;
    if(arg0 == 1)
        D_803912CC = 6.5f;

    if(arg0 == 2){
        item_set(ITEM_3_PROPELLOR_TIMER, 0xf3b);
        item_set(ITEM_9_PROPELLOR, 1);
    }

    if(arg0 == 3 || arg0 == 4){
        levelSpecificFlags_set(0x27, FALSE);
        levelSpecificFlags_set(0x28, FALSE);
        item_set(ITEM_9_PROPELLOR,0);
        if(arg0 == 3 && !jiggyscore_isCollected(0x57)){
            timedFunc_set_1(0.5f, (TFQM1)func_802FAD64, 3);
            func_80324DBC(1.0f, 0xb9d, 4, NULL, NULL, NULL, NULL);
        }
        else{
            func_802FAD64(3);
        }
    }//L8038FED4
    D_803912C8 = arg0;
}

void func_8038FEE8(void){
    if(D_803912C8 == 2)
        func_8038FDE0(4);
}

void func_8038FF18(void){
    D_803912C8 = 0;
    func_8038FDE0(0);
}

void func_8038FF40(void){
    if(D_803912C8 == 2)
        func_8038FDE0(2);
}

void func_8038FF70(void){
    extern static f32 D_803912CC;  

    if( D_803912C8 == 0)
        if(levelSpecificFlags_get(0x27) && levelSpecificFlags_get(0x28))
            func_8038FDE0(1);

    if(D_803912C8 == 1)
        if(func_8025773C(&D_803912CC,time_getDelta()))
            func_8038FDE0(2);

    if(D_803912C8 == 2)
        if(item_getCount(3) == 0)
            func_8038FDE0(3);

    if(D_803912C8 == 3)
        func_8038FDE0(0);
}