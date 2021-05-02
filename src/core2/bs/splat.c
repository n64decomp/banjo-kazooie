#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

void func_8028A274(s32, f32);
void func_80292900(f32, f32);
void func_80299CF4(s32, f32, s32);
void func_80250D94(f32, f32, f32);

extern u8 D_8037D530;

void func_802B4570(void) {
    f32 i;

    for(i = 0.0f; i < 360.0f; i += 45.0f){
        func_80292900(i, 230.0f);
    }
}

void bssplat_init(void){
    s32 sp1C;
    func_8028A274(0x149, 1.1f);
    func_8029C7F4(1,1,3,3);
    func_802931DC(&sp1C);
    func_803463D4(0x14, -sp1C);
    if(func_8029CEB0() == 4){
        func_8030E624(0x599f4116);
        func_8030E624(0x665f4116);
        func_80250D94(0.75f, 0.25f, 0.3f);
    }else{
        func_8030E624(0x665ff81f);
        func_80250D94(1.0f, 0.5f, 0.4f);
    }
    func_80299CF4(0x38, 1.0f, 0x6D60);
    func_802B4570();
    func_802BB3DC(0, 45.0f, 0.71f);
    if(item_getCount(item_health) == 0)
        bs_setState(BS_DIE);

    D_8037D530 = 0;
    func_8028D5DC();
}

void bssplat_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl =  player_getAnimCtrlPtr();
    func_80297970(max_f(0.0f, func_80297A64() - 15.0f));

    switch (D_8037D530)
    {
    case 0://L802B4760
        if(140.0f < func_80297A64())
            func_802929F8();

        if(func_8028B094())
            sp1C = BS_FALL;

        if(func_802878C4(aCtrl)){
            func_8028A180(0xd2, 2.25f);
            D_8037D530 = 1;
        }
        break;
    
    case 1://L802B47C8
        if(func_802878E8(aCtrl, 0.63f))
            sp1C = BS_LANDING;

        if(func_802878C4(aCtrl))
            sp1C = BS_IDLE;

        if(func_8028B094())
            sp1C = BS_FALL;
        break;
    }//L802B4808

    if(func_8028B2E8() == 0 && player_inWater())
        sp1C = BS_SWIM_IDLE;

    bs_setState(sp1C);

}

void bssplat_end(void){
    func_8028D5F4();
    func_80297CA8();
}
