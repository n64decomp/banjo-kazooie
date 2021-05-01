#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8028A274(s32, f32);
void func_80299234(f32, f32);
void func_802875AC(AnimCtrl *, char*, s32);


extern u8 D_8037D2F0;
extern u8 D_8037D2F1;

s32 func_8030E760(s32, f32, s32);
f32 func_802877D8(AnimCtrl *);
s32 func_802878E8(AnimCtrl *, f32);

void func_802A23E0(void){
    func_8028A274(0x2A, 1.0f);
    func_8029C7F4(1,3,1,3);
    func_80299234(350.0f, 14.0f);
    func_80297970(0.0f);
    func_8029E070(1);
    D_8037D2F0 = (D_8037D2F1 = 1);
    func_802952A8(2,0);
}

void func_802A2468(void) {
    s32 next_state;
    AnimCtrl *plyr_mvmt;
    s32 has_eggs;
    s32 sp28;
    s32 fill1;
    s32 fill2;

    next_state = 0;
    plyr_mvmt = player_getAnimCtrlPtr();
    has_eggs = (item_empty(item_eggs) == 0);
    if (func_802950A4()) {
        if (has_eggs)
            D_8037D2F0 = func_80258948(D_8037D2F0 + 1, 3);
        else 
            func_80346C10(&sp28, -1, 0, 0xD, 0);
    }
    if (has_eggs) {
        if (func_802878E8(plyr_mvmt, 0.1f))
            func_8030E760(0x46, 1.0f, 0x7fff);

        if (func_802878E8(plyr_mvmt, 0.4f))
            func_8030E760(0x57, 1.0f, 0x7fff);

        if (func_802878E8(plyr_mvmt, 0.4704f)){
            func_8033E3F0(1, 1);
            func_80345F44(0xD);
            func_80295610(7);
        }
        if ((func_802878E8(plyr_mvmt,  0.5919f)) &&  (D_8037D2F1 < D_8037D2F0)) {
            func_8028774C(plyr_mvmt, 0.3878f);
            func_802875AC(plyr_mvmt, "bsbegghead.c", 0x62);
            D_8037D2F1++;
        }
    }
    if (func_802878C4(plyr_mvmt)) {
        next_state = (button_held(BUTTON_Z))? BS_CROUCH : BS_IDLE;

    } else if (0.65 < (f64) func_802877D8(plyr_mvmt)) {
        next_state = func_802ADCD4(0);
    }
    if (func_8028B094())
        next_state = 0x2F;
    bs_setState(next_state);
}


void func_802A2650(void){
    func_802952A8(2, 1);
    func_80297B70();
    func_8029E070(0);
}