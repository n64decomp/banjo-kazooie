#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8 D_8037D4B0;
u8 D_8037D4B1;
u8 D_8037D4B2;
ActorMarker *bsjig_gJiggyMarker;

/* .code */
int bsjig_inJiggyJig(enum bs_e state){
    return state == BS_44_JIG_JIGGY;
}

void bsjig_setJiggyMarkerPtr(ActorMarker * jiggyMarkerPtr){
    bsjig_gJiggyMarker = jiggyMarkerPtr;
}

void bsjig_jiggy_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    int tmp;

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BJIG_JIGGY);
    animctrl_setDuration(aCtrl, 4.3f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsjig.c", 0x7f);
    yaw_setIdeal(func_8029B41C()); //face camera
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_8024BD08(0);
    func_8025A2FC(0,0xfa0);
    tmp = (item_getCount(ITEM_E_JIGGY) == 9); 
    if(tmp == 0) //weird if...
        tmp = 0;
    D_8037D4B1 =  tmp;
    func_8025A6EC(COMUSIC_D_JINGLE_JIGGY_COLLECTED, -1);
    func_8029151C(0xC);
    func_8029E070(1);
    func_8030E6D4(SFX_33_BANJO_AHOO);
    miscflag_clear(7);
    miscflag_clear(0xf);
    baMarker_collisionOff();
    func_802C82C0(marker_getActor(bsjig_gJiggyMarker), 1);
    D_8037D4B0 = 0;
}

void func_802B0BA8(void){
    if(bsjig_gJiggyMarker){
        func_802C82C0(marker_getActor(bsjig_gJiggyMarker), 4);
    }
}

void bsjig_jiggy_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    
    yaw_setIdeal(func_8029B41C());
    
    if(animctrl_isAt(aCtrl, 0.6502f))
        func_80299BD4();

    if(animctrl_isAt(aCtrl, 0.835f)){
        D_8037D4B0++;
        item_inc(ITEM_E_JIGGY);
        func_8030E58C(SFX_4B_GULPING, 1.3f);
    }

    if(animctrl_isAt(aCtrl, 0.94f))
        func_8030E484(0x3ea);

    if(animctrl_isStopped(aCtrl)){
        if(D_8037D4B1)
            sp1C =  BS_34_JIG_NOTEDOOR;
        else
            sp1C =  BS_1_IDLE;
    }

    func_80295C08(func_802B0BA8);
    bs_setState(sp1C);
}

void func_802B0CD8(void){
    if(bsjig_gJiggyMarker){
        func_802C82C0(marker_getActor(bsjig_gJiggyMarker), 5);
        bsjig_gJiggyMarker = NULL;
    }
}

void bsjig_jiggy_end(void){
    s32 sp2C;
    s32 sp28 = 4;
    int sp24;
    sp2C = 0;
    sp24  = marker_getActor(bsjig_gJiggyMarker)->unk38_31;
    if(D_8037D4B0 == 0)
        item_inc(ITEM_E_JIGGY);

    func_802B0CD8();
    func_8029E070(0);
    func_80291548();

    if(bs_getNextState() != BS_34_JIG_NOTEDOOR){
        func_8025A2FC(-1, 0xfa0);
        func_8024BD08(1);
    }
    baMarker_collisionOn();
    if( jiggyscore_total() == 100 
        && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY) 
        && bs_getNextState() != BS_34_JIG_NOTEDOOR
    ){
        func_8028F918(2);
        func_802E4078(MAP_95_CS_END_ALL_100, 0, 1);
    } else {//L802B0DFC
        if( jiggyscore_total() == 2
            && map_get() == MAP_2_MM_MUMBOS_MOUNTAIN
        ){
            sp2C = 0xb51;
            sp28 = 0xe;
        }
        else{//L802B0E34
            switch(sp24){
                case 0x13:
                    sp2C = 0xa16;
                    break;
                case 0x17:
                    if(!levelSpecificFlags_get(0) || !levelSpecificFlags_get(1))
                        sp2C = 0xd2d;
                    break;
            }
        }//L802B0E88
        if(sp2C != 0){
            func_80311480(sp2C, sp28, 0, 0, 0, 0);
        }
    }//L802B0EA4
    func_80298A64();
}

void bsjig_jiggy_interrupt(void){
    if(bs_getInterruptType() == BS_INTR_26)
        func_80296608();
}

void bsjig_notedoor_end(void){
    baMarker_collisionOn();
    func_8025A2FC(-1, 0xfa0);
    func_8024BD08(1);
    func_8029E070(0);
    func_80291548();
    if( D_8037D4B2 
        && jiggyscore_total() == 100
        && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)
    ){
        func_8028F918(2);
        func_802E4078(MAP_95_CS_END_ALL_100, 0, 1);
    }
    func_80298A64();
}

void bsjig_notedoor_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    D_8037D4B2 = (bs_getPrevState() == BS_44_JIG_JIGGY);
    miscflag_clear(0x1A);
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x282);
    animctrl_setDuration(aCtrl, 3.6f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bsjig.c", 0x14d);
    yaw_setIdeal(func_8029B41C());
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    if(bs_getPrevState() != BS_44_JIG_JIGGY){
        func_8024BD08(0);
        func_8025A2FC(0,0xfa0);
    }
    func_8025A6EC(COMUSIC_42_NOTEDOOR_OPENING_FANFARE,-1);
    func_8029151C(0xc);
    func_8029E070(1);
    func_8030E6D4(SFX_33_BANJO_AHOO);
    baMarker_collisionOff();
}

void bsjig_notedoor_update(void){
    enum bs_e sp1C = 0;

    if(baanim_isAt(0.59f) || baanim_isAt(0.84f))
        func_80299CF4(SFX_3EA_UNKNOWN, 1.0f, 30000);

    if(baanim_isStopped())
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

