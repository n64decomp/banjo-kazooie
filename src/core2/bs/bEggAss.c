#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8028774C(Movement *, f32);
f32 func_802877D8(Movement *);
s32 func_802878E8(Movement*, f32);
void func_802875AC(Movement *, char*, s32);

void func_8028A274(s32, f32);
void func_80299234(f32, f32);
void func_8030E760(s32, f32, s32);




extern u8 D_8037D2E0;
extern u8 D_8037D2E1;


void func_802A2170(void){
    func_8028A274(0x2B, 1.0f);
    func_8029C7F4(1,3,1,3);
    func_80299234(350.0f, 14.0f);
    func_80297970(0.0f);
    func_8029E058(1);
    D_8037D2E0 = (D_8037D2E1 = 1);
    func_802952A8(5,0);
}

void func_802A21F8(void) {
    s32 next_state;
    Movement *plyr_mvmt;
    s32 has_eggs;
    s32 sp28;
    s32 fill1;
    s32 fill2;

    next_state = 0;
    plyr_mvmt = func_80289F64();
    has_eggs = (func_80345F74(0xD) == 0);
    if (func_80295068()) {
        if (has_eggs)
            D_8037D2E0 = func_80258948(D_8037D2E0 + 1, 3);
        else 
            func_80346C10(&sp28, -1, 0, 0xD, 0);
    }
    if (has_eggs) {
        if (func_802878E8(plyr_mvmt, 0.3837f)) {
            func_8030E760(0x3E, 1.4f, 0x6D60);
            func_8033E3F0(4, 1);
            func_80345F44(0xD);
            func_80295610(7);
        }
        if ((func_802878E8(plyr_mvmt,  0.4885f)) &&  (D_8037D2E1 < D_8037D2E0)) {
            func_8028774C(plyr_mvmt, 0.349f);
            func_802875AC(plyr_mvmt, "bsbeggass.c", 0x5E);
            D_8037D2E1++;
        }
    }
    if (func_802878C4(plyr_mvmt)) {
        next_state = (button_held(1))? 7 : 1;
    } else if (0.6 < (f64) func_802877D8(plyr_mvmt)) {
        next_state = func_802ADCD4(0);
    }
    if (func_8028B094())
        next_state = 0x2F;
    bs_setState(next_state);
}


void func_802A23AC(void){
    func_802952A8(5, 1);
    func_80297B70();
    func_8029E058(0);
}
