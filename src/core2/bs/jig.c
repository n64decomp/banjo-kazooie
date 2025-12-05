#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"

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
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    int tmp;

    anctrl_reset(aCtrl);
    anctrl_setSmoothTransition(aCtrl, FALSE);
    anctrl_setIndex(aCtrl, ASSET_2E_ANIM_BSJIG_JIGGY);
    anctrl_setDuration(aCtrl, 4.3f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsjig.c", 0x7f);
    yaw_setIdeal(func_8029B41C()); //face camera
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    core1_ce60_incOrDecCounter(FALSE);
    func_8025A2FC(0,0xfa0);
    tmp = (item_getCount(ITEM_E_JIGGY) == 9); 
    if(tmp == 0) //weird if...
        tmp = 0;
    D_8037D4B1 =  tmp;
    coMusicPlayer_playMusic(COMUSIC_D_JINGLE_JIGGY_COLLECTED, -1);
    func_8029151C(0xC);
    func_8029E070(1);
    func_8030E6D4(SFX_33_BANJO_AHOO);
    baflag_clear(BA_FLAG_7_TOUCHING_JIGGY);
    baflag_clear(BA_FLAG_F);
    baMarker_collisionOff();
    chJigsawDance_setState(marker_getActor(bsjig_gJiggyMarker), 1);
    D_8037D4B0 = 0;
}

void func_802B0BA8(void){
    if(bsjig_gJiggyMarker){
        chJigsawDance_setState(marker_getActor(bsjig_gJiggyMarker), 4);
    }
}

void bsjig_jiggy_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl * aCtrl = baanim_getAnimCtrlPtr();
    
    yaw_setIdeal(func_8029B41C());
    
    if(anctrl_isAt(aCtrl, 0.6502f))
        basfx_80299BD4();

    if(anctrl_isAt(aCtrl, 0.835f)){
        D_8037D4B0++;
        item_inc(ITEM_E_JIGGY);
        func_8030E58C(SFX_4B_GULPING, 1.3f);
    }

    if(anctrl_isAt(aCtrl, 0.94f))
        sfxsource_playHighPriority(0x3ea);

    if(anctrl_isStopped(aCtrl)){
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
        chJigsawDance_setState(marker_getActor(bsjig_gJiggyMarker), 5);
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
        core1_ce60_incOrDecCounter(TRUE);
    }
    baMarker_collisionOn();
    if( jiggyscore_total() == 100 
        && fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY) 
        && bs_getNextState() != BS_34_JIG_NOTEDOOR
    ){
        func_8028F918(2);
        transitionToMap(MAP_95_CS_END_ALL_100, 0, 1);
    } else {//L802B0DFC
        if( jiggyscore_total() == 2
            && gsworld_get_map() == MAP_2_MM_MUMBOS_MOUNTAIN
        ){
            sp2C = VER_SELECT(0xb51, 0x96f, 0, 0);
            sp28 = 0xe;
        }
        else{//L802B0E34
            switch(sp24){
                case 0x13:
                    sp2C = VER_SELECT(ASSET_A16_DIALOG_LOCKUP_GRUNTY_RESPONSE, 0x916, 0, 0);
                    break;
                case 0x17:
                    if(!levelSpecificFlags_get(LEVEL_FLAG_0_CC_TOKEN_TOOTH_OPEN) || !levelSpecificFlags_get(LEVEL_FLAG_1_CC_JIGGY_TOOTH_OPEN))
                        sp2C = VER_SELECT(ASSET_D2D_DIALOG_CLANKER_COLLECT_JIGGY, 0xa00, 0, 0);
                    break;
            }
        }//L802B0E88
        if(sp2C != 0){
            gcdialog_showDialog(sp2C, sp28, 0, 0, 0, 0);
        }
    }//L802B0EA4
    balookat_end();
}

void bsjig_jiggy_interrupt(void){
    if(bs_getInterruptType() == BS_INTR_26) {
        func_80296608();
    }
#if VERSION != VERSION_USA_1_0
    else {
        func_80296590();
    }
#endif
}

void bsjig_notedoor_end(void){
    baMarker_collisionOn();
    func_8025A2FC(-1, 0xfa0);
    core1_ce60_incOrDecCounter(TRUE);
    func_8029E070(0);
    func_80291548();
    if( D_8037D4B2 
        && jiggyscore_total() == 100
        && fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY)
    ){
        func_8028F918(2);
        transitionToMap(MAP_95_CS_END_ALL_100, 0, 1);
    }
    balookat_end();
}

void bsjig_notedoor_init(void){
    AnimCtrl *aCtrl = baanim_getAnimCtrlPtr();
    D_8037D4B2 = (bs_getPrevState() == BS_44_JIG_JIGGY);
    baflag_clear(BA_FLAG_1A_OPEN_NOTEDOOR);
    anctrl_reset(aCtrl);
    anctrl_setIndex(aCtrl, ASSET_282_ANIM_BSJIG_NOTEDOOR);
    anctrl_setDuration(aCtrl, 3.6f);
    anctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    anctrl_start(aCtrl, "bsjig.c", VER_SELECT(0x14d, 0x14f, 0, 0));
    yaw_setIdeal(func_8029B41C());
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    if(bs_getPrevState() != BS_44_JIG_JIGGY){
        core1_ce60_incOrDecCounter(FALSE);
        func_8025A2FC(0,0xfa0);
    }
    coMusicPlayer_playMusic(COMUSIC_42_NOTEDOOR_OPENING_FANFARE,-1);
    func_8029151C(0xc);
    func_8029E070(1);
    func_8030E6D4(SFX_33_BANJO_AHOO);
    baMarker_collisionOff();
}

void bsjig_notedoor_update(void){
    enum bs_e sp1C = 0;

    if(baanim_isAt(0.59f) || baanim_isAt(0.84f))
        basfx_80299CF4(SFX_3EA_BANJO_GUH_HUH, 1.0f, 30000);

    if(baanim_isStopped())
        sp1C = BS_1_IDLE;

    bs_setState(sp1C);
}

