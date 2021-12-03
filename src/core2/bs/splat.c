#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

void func_80292900(f32, f32);
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
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 1000, 0x2cc);
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 1000, 0x332);
        func_80250D94(0.75f, 0.25f, 0.3f);
    }else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0x3FF, 0x332);
        func_80250D94(1.0f, 0.5f, 0.4f);
    }
    func_80299CF4(SFX_38_BANJO_AYE_1, 1.0f, 28000);
    func_802B4570();
    func_802BB3DC(0, 45.0f, 0.71f);
    if(item_getCount(ITEM_14_HEALTH) == 0)
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

        if(animctrl_isStopped(aCtrl)){
            func_8028A180(ASSET_D2_ANIM_BANJO_GETTING_UP, 2.25f);
            D_8037D530 = 1;
        }
        break;
    
    case 1://L802B47C8
        if(animctrl_isAt(aCtrl, 0.63f))
            sp1C = BS_LANDING;

        if(animctrl_isStopped(aCtrl))
            sp1C = BS_1_IDLE;

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
