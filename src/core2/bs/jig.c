#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80295C08(void (* arg0)(void));

extern char D_80375940[];
extern char D_80375948[];
extern f32 D_80375950;
extern f32 D_80375954;

extern u8 D_8037D4B0;
extern u8 D_8037D4B1;
extern u8 D_8037D4B2;
extern ActorMarker *D_8037D4B4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0A6C.s")

void bsjig_jiggy_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    int tmp;

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x2e);
    animctrl_setDuration(aCtrl, 4.3f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, D_80375940, 0x7f);
    yaw_setIdeal(func_8029B41C()); //face camera
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_8024BD08(0);
    func_8025A2FC(0,0xfa0);
    tmp = (item_getCount(ITEM_JIGGY) == 9); 
    if(tmp == 0) //weird if...
        tmp = 0;
    D_8037D4B1 =  tmp;
    func_8025A6EC(JINGLE_JIGGY_COLLECTED, -1);
    func_8029151C(0xC);
    func_8029E070(1);
    func_8030E6D4(0x33);
    func_802933FC(7);
    func_802933FC(0xf);
    func_8028D5DC();
    func_802C82C0(marker_getActor(D_8037D4B4), 1);
    D_8037D4B0 = 0;
}

void func_802B0BA8(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0BA8.s")


void bsjig_jiggy_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();
    
    yaw_setIdeal(func_8029B41C());
    
    if(animctrl_isAt(aCtrl, 0.6502f))
        func_80299BD4();

    if(animctrl_isAt(aCtrl, 0.835f)){
        D_8037D4B0++;
        func_80345F24(0xe);
        func_8030E58C(0x4b, 1.3f);
    }

    if(animctrl_isAt(aCtrl, 0.94f))
        func_8030E484(0x3ea);

    if(animctrl_isStopped(aCtrl)){
        if(D_8037D4B1)
            sp1C =  BS_JIG_NOTEDOOR;
        else
            sp1C =  BS_IDLE;
    }

    func_80295C08(func_802B0BA8);
    bs_setState(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/jig/func_802B0EF0.s")

void bsjig_notedoor_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    D_8037D4B2 = (bs_getPrevState() == BS_JIG_JIGGY);
    func_802933FC(0x1A);
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x282);
    animctrl_setDuration(aCtrl, 3.6f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, D_80375948, 0x14d);
    yaw_setIdeal(func_8029B41C());
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    if(bs_getPrevState() != BS_JIG_JIGGY){
        func_8024BD08(0);
        func_8025A2FC(0,0xfa0);
    }
    func_8025A6EC(JINGLE_NOTEDOOR_OPENING_FANFARE,-1);
    func_8029151C(0xc);
    func_8029E070(1);
    func_8030E6D4(0x33);
    func_8028D5DC();
}

void bsjig_notedoor_update(void){
    enum bs_e sp1C = 0;

    if(func_80289FE8(D_80375950) || func_80289FE8(D_80375954))
        func_80299CF4(0x3ea, 1.0f, 30000);

    if(func_80289FC4())
        sp1C = BS_IDLE;

    bs_setState(sp1C);
}

