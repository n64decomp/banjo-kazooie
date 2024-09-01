#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

#include "core2/ba/physics.h"

void func_80292900(f32, f32);
void rumbleManager_80250D94(f32, f32, f32);

/* .bss */
u8 D_8037D530;

/* .code */
void func_802B4570(void) {
    f32 i;

    for(i = 0.0f; i < 360.0f; i += 45.0f){
        func_80292900(i, 230.0f);
    }
}

void bssplat_init(void){
    s32 sp1C;
    baanim_playForDuration_onceSmooth(ASSET_149_ANIM_BSSPLAT, 1.1f);
    func_8029C7F4(1,1,3, BA_PHYSICS_LOCKED_ROTATION);
    bafalldamage_get_damage(&sp1C);
    func_803463D4(ITEM_14_HEALTH, -sp1C);
    if(func_8029CEB0() == 4){
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.7f, 32000);
        FUNC_8030E624(SFX_116_DEAF_RUSTLING, 0.8f, 32000);
        rumbleManager_80250D94(0.75f, 0.25f, 0.3f);
    }else{
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 32750);
        rumbleManager_80250D94(1.0f, 0.5f, 0.4f);
    }
    func_80299CF4(SFX_38_BANJO_AYE_1, 1.0f, 28000);
    func_802B4570();
    func_802BB3DC(0, 45.0f, 0.71f);
    if(item_getCount(ITEM_14_HEALTH) == 0)
        bs_setState(BS_41_DIE);

    D_8037D530 = 0;
    baMarker_collisionOff();
}

void bssplat_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl =  baanim_getAnimCtrlPtr();
    baphysics_set_target_horizontal_velocity(ml_max_f(0.0f, baphysics_get_target_horizontal_velocity() - 15.0f));

    switch (D_8037D530)
    {
    case 0://L802B4760
        if(140.0f < baphysics_get_target_horizontal_velocity())
            func_802929F8();

        if(func_8028B094())
            sp1C = BS_2F_FALL;

        if(animctrl_isStopped(aCtrl)){
            baanim_playForDuration_once(ASSET_D2_ANIM_BSSPLAT, 2.25f);
            D_8037D530 = 1;
        }
        break;
    
    case 1://L802B47C8
        if(animctrl_isAt(aCtrl, 0.63f))
            sp1C = BS_20_LANDING;

        if(animctrl_isStopped(aCtrl))
            sp1C = BS_1_IDLE;

        if(func_8028B094())
            sp1C = BS_2F_FALL;
        break;
    }//L802B4808

    if(func_8028B2E8() == 0 && player_inWater())
        sp1C = BS_2D_SWIM_IDLE;

    bs_setState(sp1C);

}

void bssplat_end(void){
    baMarker_collisionOn();
    func_80297CA8();
}
