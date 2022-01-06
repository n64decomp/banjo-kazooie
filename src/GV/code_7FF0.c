#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "SnS.h"

extern ActorInfo D_80390BF0;
extern ActorInfo D_80390C5C;
extern ActorInfo D_80390C80;
extern ActorInfo D_80390D30;
extern ActorInfo D_80390D60;
extern ActorInfo D_80390CB0;
extern ActorInfo D_80390D00;
extern ActorInfo D_80390D90;
extern ActorInfo D_80390DD0;
extern ActorInfo D_80390E30;
extern ActorInfo D_80390E54;
extern ActorInfo D_80390ED0;
extern ActorInfo D_80390F00;
extern ActorInfo D_80390FD0;
extern ActorInfo D_80391010;
extern ActorInfo D_80391098;
extern ActorInfo D_80391158;
extern ActorInfo D_803911C0;
extern ActorInfo D_803911F4;
extern ActorInfo D_80391218;
extern ActorInfo D_8039123C;
extern ActorInfo D_80391260;
extern ActorInfo D_80391318;
extern ActorInfo D_80391358;
extern ActorInfo D_803912B8;
extern ActorInfo D_80391390;
extern ActorInfo D_803913B4;
extern ActorInfo D_80390F40;
extern ActorInfo D_80391494;
extern ActorInfo D_803915C0;
extern ActorInfo D_80391620;
extern ActorInfo D_803914B8;
extern ActorInfo D_803914DC;
extern ActorInfo D_80391500;
extern ActorInfo D_80391524;
extern ActorInfo D_8039156C;
extern ActorInfo D_80391428;
extern ActorInfo D_8039144C;
extern ActorInfo D_80391470;
extern ActorInfo D_80391548;
extern ActorInfo D_80391590;

extern void func_802D3D54(Actor *this);
extern Actor *func_80325F2C(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

void func_8038E460(Actor *this);
void func_8038E4DC(Actor *this);
void func_8038E648(Actor *this);
void func_8038E914(Actor *this);
void func_8038E97C(Actor *this);
void func_8038EB40(Actor *this);
void func_8038ED54(Actor *this);
void func_8038EE10(Actor *this);
void chHoneycombSwitch_update(Actor *this);
void func_8038EF14(Actor *this);
void func_8038EF3C(Actor *this);

/* .data */
extern ActorAnimationInfo D_803913E0[];
extern ActorInfo D_80391428 = { MARKER_EC_GV_SUN_SWITCH, ACTOR_13F_GV_SUN_SWITCH, ASSET_400_MODEL_SUN_SWITCH, 
    0x1, D_803913E0, 
    func_8038ED54, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8039144C = { MARKER_F1_GV_STAR_SWITCH, ACTOR_144_GV_STAR_SWITCH, ASSET_3D7_MODEL_STAR_SWITCH, 
    0x1, D_803913E0, 
    func_8038EE10, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391470 = { MARKER_F2_HONEYCOMB_SWITCH, ACTOR_145_HONEYCOMB_SWITCH, ASSET_438_MODEL_HONEYCOMB_SWITCH, 
    0x1, D_803913E0, 
    chHoneycombSwitch_update, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391494 = { MARKER_23C_GV_SNS_SWITCH, ACTOR_245_GV_SNS_SWITCH, ASSET_515_MODEL_GV_SNS_SWITCH, 
    0x1, D_803913E0, 
    func_8038EF14, func_80326224, func_80325888,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803914B8 = { MARKER_EB_GV_BANJO_DOOR, ACTOR_6D_GV_BANJO_DOOR, ASSET_3D8_MODEL_GV_BANJO_DOOR, 
    0x1, 0x0, 
    func_802D3D54, func_8038E460, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803914DC = { MARKER_ED_GV_SUN_DOOR, ACTOR_140_GV_SUN_DOOR, ASSET_3FF_MODEL_GV_SUN_DOOR, 
    0x1, 0x0, 
    func_802D3D54, func_8038E4DC, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391500 = { MARKER_F0_GV_KAZOOIE_DOOR, ACTOR_143_GV_KAZOOIE_DOOR, ASSET_3D9_MODEL_GV_KAZOOIE_DOOR, 
    0x1, 0x0, 
    func_8038EB40, func_80326224, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391524 = { MARKER_EF_GV_STAR_HATCH, ACTOR_142_GV_STAR_HATCH, ASSET_3DB_MODEL_GV_STAR_HATCH, 
    0x1, 0x0, 
    func_8038E648, func_80326224, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391548 = { MARKER_F3_GV_KAZOOIE_TARGET, ACTOR_146_GV_KAZOOIE_TARGET, ASSET_3E2_MODEL_GV_KAZOOIE_TARGET, 
    0x1, 0x0, 
    func_8038EF3C, func_80326224, func_80325E78,
    { 0x0, 0x0, 0x4, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8039156C = { MARKER_F8_GV_KAZOOIE_DOOR, ACTOR_1F5_GV_KAZOOIE_DOOR, ASSET_3D9_MODEL_GV_KAZOOIE_DOOR, 
    0x1, 0x0, 
    func_8038E97C, func_80326224, func_80325F2C,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391590 = { MARKER_243_GV_SNS_CHAMBER_DOOR, ACTOR_243_GV_SNS_CHAMBER_DOOR, ASSET_514_MODEL_GV_SNS_CHAMBER_DOOR, 
    0x1, 0x0, 
    func_8038E914, func_80326224, func_80325F2C, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .bss */
extern f32 D_80391AC0;
extern f32 D_80391AC4;
extern f32 D_80391AC8;

/* .code */
void func_8038E3E0(Actor *this){
   D_80391AC0 = this->yaw;
   D_80391AC4 = this->pitch;
   D_80391AC8 = this->roll;
}

void func_8038E408(Actor *this){
   this->yaw =  D_80391AC0;
   this->pitch = D_80391AC4;
   this->roll = D_80391AC8;
}

void func_8038E430(Actor *this){
    func_8038E3E0(this);
    func_80343DEC(this);
    func_8038E408(this);
}

void func_8038E460(Actor *this){//banjo_door
    func_802D3D74(this);
    if(mapSpecificFlags_get(0x10)){
        func_8038E430(this);
        if(!mapSpecificFlags_get(2)){
            mapSpecificFlags_set(2, TRUE);
            func_8028F918(0);
            func_80324DBC(4.0f, 0xa7d, 4, NULL, NULL, NULL, NULL);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038E4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038E648.s")

void func_8038E914(Actor *this){
    func_80389F5C(this);
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
        if(sns_get_item_state(SNS_ITEM_EGG_BLUE, 1))
            marker_despawn(this->marker);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038E97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038EB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038ED54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038EE10.s")

void chHoneycombSwitch_update(Actor *this){
    if(!mapSpecificFlags_get(0xd) && func_803212E4(HONEYCOMB_B_GV_CACTUS)){
        mapSpecificFlags_set(0xd, TRUE);
    }
    func_802D4A9C(this, 0xd);
}

void func_8038EF14(Actor *this){
    func_802D4AC0(this, 0x8000a3, 0xa4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038EF3C.s")

void func_8038F004(void){
    func_8025A6EC(SFX_2D_KABOING, 0x7fff);
}

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038F028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038F10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_7FF0/func_8038F130.s")

void func_8038F154(void)
{
    spawnableActorList_add(&D_80390BF0, actor_new, 0X180);
    spawnableActorList_add(&D_80390C5C, actor_new, 0X58A);
    spawnableActorList_add(&D_80390C80, actor_new, 0X9A8);
    spawnableActorList_add(&D_80390D30, actor_new, 0X880);
    spawnableActorList_add(&D_80390D60, actor_new, 0X80);
    spawnableActorList_add(&D_80390CB0, actor_new, 0XDA8);
    spawnableActorList_add(&D_80390D00, actor_new, 0X9A8);
    spawnableActorList_add(&D_80390D90, actor_new, 0XD80);
    spawnableActorList_add(&D_80390DD0, actor_new, 0X4004);
    spawnableActorList_add(&D_80390E30, actor_new, 0X448);
    spawnableActorList_add(&D_80390E54, actor_new, 0X48);
    spawnableActorList_add(&D_80390ED0, actor_new, 0X180);
    spawnableActorList_add(&D_80390F00, actor_new, 0X80);
    spawnableActorList_add(&D_80390FD0, actor_new, 0X4048);
    spawnableActorList_add(&D_80391010, actor_new, 0X4048);
    spawnableActorList_add(&D_80391098, actor_new, 0X10069);
    spawnableActorList_add(&D_80391158, actor_new, 0X48);
    spawnableActorList_add(&D_803911C0, actor_new, 8);
    spawnableActorList_add(&D_803911F4, actor_new, 0X80988);
    spawnableActorList_add(&D_80391218, actor_new, 0X80988);
    spawnableActorList_add(&D_8039123C, actor_new, 0X80988);
    spawnableActorList_add(&D_80391260, actor_new, 0X80);
    spawnableActorList_add(&D_80391318, actor_new, 0X78A);
    spawnableActorList_add(&D_80391358, actor_new, 0X518);
    spawnableActorList_add(&D_803912B8, actor_new, 0X500);
    spawnableActorList_add(&D_80391390, actor_new, 0X500);
    spawnableActorList_add(&D_803913B4, actor_new, 0X500);
    spawnableActorList_add(&D_80390F40, actor_new, 0);
    spawnableActorList_add(&D_80391494, actor_new, 0X408);
    spawnableActorList_add(&D_803915C0, actor_new, 0);
    spawnableActorList_add(&D_80391620, actor_new, 0X400);
    spawnableActorList_add(&D_803914B8, actor_new, 0X400);
    spawnableActorList_add(&D_803914DC, actor_new, 0X400);
    spawnableActorList_add(&D_80391500, actor_new, 0X400);
    spawnableActorList_add(&D_80391524, actor_new, 0X400);
    spawnableActorList_add(&D_8039156C, actor_new, 0X400);
    spawnableActorList_add(&D_80391428, actor_new, 8);
    spawnableActorList_add(&D_8039144C, actor_new, 8);
    spawnableActorList_add(&D_80391470, actor_new, 8);
    spawnableActorList_add(&D_80391548, actor_new, 0X400);
    spawnableActorList_add(&D_80391590, actor_new, 0X400);
}

s32 func_8038F4C0(Actor *arg0, s32 arg1){
    if( getGameMode() != GAME_MODE_7_ATTRACT_DEMO 
        && (0xDBF4E829 + *(s32*)PHYS_TO_K1(0x284))
    ){
        return arg1;
    }
    else{
        return arg0->state;
    }
}
