#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void yaw_setVelocityBounded(f32, f32);
void animctrl_start(AnimCtrl *, char*, s32);

/* .bss */
u8 D_8037D2F0;
u8 D_8037D2F1;

/* .code */
void bsegghead_init(void){
    baanim_playForDuration_onceSmooth(ASSET_2A_ANIM_BSEGGHEAD, 1.0f);
    func_8029C7F4(1,3,1,3);
    yaw_setVelocityBounded(350.0f, 14.0f);
    func_80297970(0.0f);
    func_8029E070(1);
    D_8037D2F0 = (D_8037D2F1 = 1);
    func_802952A8(2,0);
}

void bsegghead_update(void) {
    s32 next_state;
    AnimCtrl *aCtrl;
    s32 has_eggs;
    s32 sp28;
    s32 fill1;
    s32 fill2;

    next_state = 0;
    aCtrl = baanim_getAnimCtrlPtr();
    has_eggs = (item_empty(ITEM_D_EGGS) == 0);
    if (should_shoot_egg()) {
        if (has_eggs)
            D_8037D2F0 = ml_min_w(D_8037D2F0 + 1, 3);
        else 
            func_80346C10(&sp28, -1, 0, ITEM_D_EGGS, 0);
    }
    if (has_eggs) {
        if (animctrl_isAt(aCtrl, 0.1f))
            func_8030E760(SFX_46_KAZOOIE_CHOKING_UP, 1.0f, 0x7fff);

        if (animctrl_isAt(aCtrl, 0.4f))
            func_8030E760(SFX_57_KAZOOIE_HEGH, 1.0f, 0x7fff);

        if (animctrl_isAt(aCtrl, 0.4704f)){
            func_8033E3F0(COMMON_PARTICLE_1_EGG_HEAD, 1);
            item_dec(ITEM_D_EGGS);
            ability_use(7);
        }
        if ((animctrl_isAt(aCtrl,  0.5919f)) &&  (D_8037D2F1 < D_8037D2F0)) {
            animctrl_setStart(aCtrl, 0.3878f);
            animctrl_start(aCtrl, "bsbegghead.c", 0x62);
            D_8037D2F1++;
        }
    }
    if (animctrl_isStopped(aCtrl)) {
        next_state = (button_held(BUTTON_Z))? BS_CROUCH : BS_1_IDLE;

    } else if (0.65 < (f64) animctrl_getAnimTimer(aCtrl)) {
        next_state = func_802ADCD4(0);
    }
    if (func_8028B094())
        next_state = BS_2F_FALL;
    bs_setState(next_state);
}

void bsegghead_end(void){
    func_802952A8(2, 1);
    gravity_reset();
    func_8029E070(0);
}
