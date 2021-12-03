#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_8037D2E0;
extern u8 D_8037D2E1;


void bseggass_init(void){
    func_8028A274(0x2B, 1.0f);
    func_8029C7F4(1,3,1,3);
    func_80299234(350.0f, 14.0f);
    func_80297970(0.0f);
    func_8029E058(1);
    D_8037D2E0 = (D_8037D2E1 = 1);
    func_802952A8(5,0);
}

void bseggass_update(void) {
    s32 next_state;
    AnimCtrl *plyr_mvmt;
    s32 has_eggs;
    s32 sp28;
    s32 fill1;
    s32 fill2;

    next_state = 0;
    plyr_mvmt = player_getAnimCtrlPtr();
    has_eggs = (item_empty(ITEM_D_EGGS) == 0);
    if (should_poop_egg()) {
        if (has_eggs)
            D_8037D2E0 = func_80258948(D_8037D2E0 + 1, 3);
        else 
            func_80346C10(&sp28, -1, 0, ITEM_D_EGGS, 0);
    }
    if (has_eggs) {
        if (animctrl_isAt(plyr_mvmt, 0.3837f)) {
            func_8030E760(SFX_3E_POOP_NOISE, 1.4f, 28000);
            func_8033E3F0(4, 1);
            func_80345F44(ITEM_D_EGGS);
            func_80295610(7);
        }
        if ((animctrl_isAt(plyr_mvmt,  0.4885f)) &&  (D_8037D2E1 < D_8037D2E0)) {
            func_8028774C(plyr_mvmt, 0.349f);
            func_802875AC(plyr_mvmt, "bsbeggass.c", 0x5E);
            D_8037D2E1++;
        }
    }
    if (animctrl_isStopped(plyr_mvmt)) {
        next_state = (button_held(BUTTON_Z))? BS_CROUCH : BS_1_IDLE;
    } else if (0.6 < (f64) func_802877D8(plyr_mvmt)) {
        next_state = func_802ADCD4(0);
    }
    if (func_8028B094())
        next_state = BS_FALL;
    bs_setState(next_state);
}


void bseggass_end(void){
    func_802952A8(5, 1);
    gravity_reset();
    func_8029E058(0);
}
