#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"
#include "actor.h"

extern ActorInfo D_8038BC28;
extern ActorInfo D_8038BCDC;
extern ActorInfo D_8038BC4C;
extern ActorInfo D_8038BDB4;
extern ActorInfo D_8038BDD8;
extern ActorInfo D_8038BDFC;
extern ActorInfo D_8038BC94;
extern ActorInfo D_8038BC70;
extern ActorInfo D_8038BD00;
extern ActorInfo D_8038BD24;
extern ActorInfo D_8038BD48;
extern ActorInfo D_8038BD6C;
extern ActorInfo D_8038BCB8;
extern ActorInfo D_8038BD90;
extern ActorInfo chNapper;
extern ActorInfo D_8038BA68;
extern ActorInfo chMotzhand;
extern ActorInfo chLoggo;
extern ActorInfo D_8038BAD0;
extern ActorInfo D_8038BE48;
extern ActorInfo D_8038BE6C;
extern ActorInfo D_8038BE90;
extern ActorInfo D_8038BEB4;
extern ActorInfo D_8038BED8;
extern ActorInfo D_8038BEFC;

extern ActorInfo D_80367E70;
extern ActorInfo D_80372C3C;

extern void func_80244BB0(s32, s32, s32, f32);
extern void func_8025AE0C(s32, f32);
extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void *func_80309B48(f32[3], f32[3], f32[3], u32);

void func_802D3D54(Actor *this);
void func_803888B8(Actor *this);
Actor *func_80388994(ActorMarker *marker, Gfx ** gfx, Mtx **mtx, Vtx **vtx);
void func_80388BDC(Actor *this);
void func_80388FE4(Actor *this);
void func_80389004(Actor *this);
void func_80389060(Actor *this);
void func_803890B8(Actor *this);

/* .data */
ActorAnimationInfo D_8038BBE0[] = {
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0xD4, 0.15f},
    {0xD5, 0.5f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0x00, 0.0f}
};

ActorInfo D_8038BC28 = {
    0x9C, 0x109, 0x3CD,
    0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BC4C = {
    0x9E, 0x10B, 0x3CF,
    0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BC70 = {
    0x9A,  0xCB, 0x3CC,
    0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BC94 = {
    0xA2, 0x114, 0x3D3,
    0x1, NULL,
    func_80388BDC, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BCB8 = {
    0xE7, 0x265, 0x4DA,
    0x1, NULL,
    func_80389004, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BCDC = {
    0x9D, 0x10A, 0x3CE,
    0x1, NULL,
    func_80389004, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BD00 = {
    0xD3, 0x191, 0x50B,
    0x1, NULL,
    func_80389060, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BD24 = {
0x123, 0x2E8, 0x4C0,
    0x1, NULL,
    func_803890B8, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BD48 = {
0x1F2, 0x2E9, 0x4C1,
    0x1, NULL,
    func_803890B8, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BD6C = {
0x1F3, 0x2EA, 0x4C2,
    0x1, NULL,
    func_803890B8, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BD90 = {
    0xFE, 0x1FD, 0x43D, 
    0x1, D_8038BBE0,
    func_80388FE4, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BDB4 = {
    0x9F, 0x10C, 0x3D0,
    0x1, NULL,
    func_803888B8, func_80326224, func_80388994,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BDD8 = {
    0xA0, 0x10D, 0x3D1,
    0x1, NULL,
    func_803888B8, func_80326224, func_80388994,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BDFC = {
    0xFF, 0x1FE, 0x43E,
    0x1, NULL,
    func_803888B8, func_80326224, func_80388994,
    0, 0, 0.0f, 0
};

s32 D_8038BE20[4] = {0x87, 0x87, 0x87, 0xB4};

/* .code */
f32 MMM_func_80388430(Actor *this, s32 arg1, s32 arg2, f32 arg3) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    if (this->unk38_31 == 0) {
        this->unk38_31 = 1;
        this->unk1C[1] = 71.0f;
    }
    this->position[arg1] += (f32) (arg2 * 0x13);

    sp34[0] = sp4C[0] = this->position[0];
    sp4C[1] = this->position[1];
    sp34[2] = sp4C[2] = this->position[2];

    this->position[1] += this->unk1C[1];
    this->unk1C[1] -= 8.0;
    sp34[1] = this->position[1] - 400.0f;
    if (this->unk1C[1] < 0.0f) {
        if (func_80309B48(sp4C, sp34, sp40, 0) && (this->position[1] <= sp34[1])) {
            this->position[1] = sp34[1] + 6.0f;
            switch (this->unk38_31) {
            case 1:
                this->unk38_31 = 2;
                this->unk1C[1] = 38.0f;
                break;
            case 2:
                this->unk38_31 = 3;
                this->unk1C[1] = 11.0f;
                break;
            case 3:
                subaddie_set_state(this, 5);
                break;
            }
            func_8030E878(SFX_82_METAL_BREAK, randf2(0.93f, 1.07f), 0x7FF8, this->position, 100.0f, 900.0f);
            this->unk60 = 1.0f;
        }
    }
    arg3 += 4.5;
    return (arg3 >= 90.0f) ? 90.0f : arg3;
}

bool func_80388670(ActorMarker * this_marker, ActorMarker * other_marker){
    Actor *this = marker_getActor(this_marker);
    f32 sp20[3];

    player_getPosition(sp20);
    switch(this->marker->id){
        case 0x9f: //L803886D0
            return (-335.0f < sp20[0] &&  sp20[0] < -200.0f) && (-2730.0f < sp20[2] &&  sp20[2] < -2400.0f);

        case 0xa0: //L80388770
            return (-2915.0f < sp20[0] &&  sp20[0] < -2584.0f) && ( -500.0f < sp20[2] &&  sp20[2] < -355.0f);

        case 0xFF: //L80388810
            return (5470.0f < sp20[0] &&  sp20[0] < 5920.0f) && ( -850.0f < sp20[2] &&  sp20[2] < -780.0f);
        
        default:
            return FALSE;
    }
}

void func_803888B8(Actor *this){
    func_803300C0(this->marker, func_80388670);
    func_802D3CE8(this);
    this->unk60 = 0.0f;
    switch(this->state){
        case 4:
            switch(this->marker->id){
                case 0x9F:
                    this->roll = MMM_func_80388430(this, 0, -1, this->roll);
                    break;
                case 0xa0:
                case 0xff:
                    this->pitch = MMM_func_80388430(this, 2, 1, this->pitch);
                    break;
            }
            break;
        case 5:
            func_80326310(this);
            break;
    }
}

Actor *func_80388994(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    
    static s32 i;
    Actor *this;
    f32 sp90[3];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];

    this = actor_drawFullDepth(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && (this->unk60 != 0.0f)) {
        func_8034A174((struct5Bs *) marker->unk44, 5, &sp84);
        func_8034A174((struct5Bs *) marker->unk44, 6, &sp78);
        for(i = 0;  i < 8; i++){
            sp6C[0] = sp6C[2] = 0.0f;
            sp6C[1] = randf2(5.0f, 20.0f);
            sp90[0] = sp84[0] + (sp78[0] - sp84[0]) * randf();
            sp90[1] = sp84[1];
            sp90[2] = sp84[2] + (sp78[2] - sp84[2]) * randf();
            func_802EE6CC(sp90, sp6C, D_8038BE20, 1, 0.3f, 50.0f, 0xB4, randi2(0x82, 0xC8), 0);
        }
    }
    return this;
}

void func_80388B2C(Actor *this, f32 arg1) {
    
    this->yaw += arg1;

    while ((arg1 > 0.0f) && (this->yaw >= 360.0f)) {
        this->yaw -= 360.0f;
    }

    while ((arg1 < 0.0f) && (this->yaw < 0.0f)) {
        this->yaw += 360.0f;
    }
}

void func_80388BDC(Actor *this) {
    f64 phi_f0;

    func_802D3D74(this);
    mapSpecificFlags_set(1, ((this->yaw > 260.0f) && (this->yaw < 330.0f)) ? TRUE : FALSE);
    if (!this->unk16C_4) {
        if (this->yaw != 0.0f) {
            this->unk60 = 0.5f;
            subaddie_set_state(this, 7);
            this->unk38_31 = 1;
            this->yaw = 270.0f;
        } else {
            this->unk38_31 = 0;
            this->unk60 = 0.0f;
        }
        this->unk16C_4 = TRUE;
    }

    switch (this->state) {
    case 1:
        this->yaw = 0.0f;
        if(mapSpecificFlags_get(0)) {
            func_802BAFE4(0x21);
            subaddie_set_state(this, 6);
            func_80244BB0(0, 0x6A, 0x7FF8, 0.3f);
            mapSpecificFlags_set(2, 0);
            func_8025A6EC(COMUSIC_4_MMM_CLOCK_VERSION, -1);
            func_8025AE0C(2000, 3.0f);
        }
        break;

    case 6:
        func_80388B2C(this, - (((this->yaw == 0.0f) || (359.0 < this->yaw)) ? 0.023 : 1.09));
        if ((this->yaw <= 270.0f) && (this->yaw > 260.0f)) {
            subaddie_set_state(this, 7U);
            this->yaw = 270.0f;
            func_8030E540(0x7F);
            func_80244C78(0);
            func_802D68F0(0xE);
            item_set(6, 1);
        }
        break;
    case 7:
        if (this->unk38_31) {
            this->unk60 -= time_getDelta();
            if (this->unk60 < 0.0f) {
                this->unk60 = 0.0f;
            }
        }
        if( (!this->unk38_31 && item_empty(ITEM_0_HOURGLASS_TIMER))
            || ((this->unk38_31) && (this->unk60 == 0.0f))
        ) {
            if (!this->unk38_31) {
                func_802BAFE4(0x22);
            } else {
                func_802BAFE4(0x23);
            }
            subaddie_set_state(this, 8);
            func_80244BB0(0, 0x6A, 0x7FF8, 0.3f);
        }
        break;
    case 8:
        func_80388B2C(this, 1.3f);
        if ((this->yaw >= 0.0f) && (this->yaw < 10.0f)) {
            subaddie_set_state(this, 1U);
            this->yaw = 0.0f;
            func_8030E540(SFX_7F_HEAVYDOOR_SLAM);
            mapSpecificFlags_set(0, 0);
            func_80244C78(0);
            if (!this->unk38_31) {
                func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 0x7FF8);
                func_8025AE0C(0x7D0, 2.5f);
            }
            this->unk38_31 = 0;
            this->unk60 = 0.0f;
            volatileFlag_setAndTriggerDialog_0(VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED);
        }
        break;
    }
}

void func_80388FE4(Actor *this) { 
    func_802D4A9C(this,0);
}

void func_80389004(Actor *this){
    func_802D3CE8(this);
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(levelSpecificFlags_get(0x2e))
            marker_despawn(this->marker);
    }
}

void func_80389060(Actor *this){
    if(!this->initialized && sns_get_item_state(SNS_ITEM_EGG_CYAN, TRUE)){
        marker_despawn(this->marker);
    }
    else{
        func_802D3CE8(this);
    }
}

void func_803890B8(Actor *this) {
    func_802D3D54(this);
    func_8038AC04();
}

void MMM_func_803890E0(void){
    spawnableActorList_add(&D_8038BC28, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038BCDC, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038BC4C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038BDB4, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038BDD8, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&D_8038BDFC, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038BC94, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038BC70, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038BD00, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8038BD24, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038BD48, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038BD6C, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038BCB8, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_8038BD90, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chNapper,   actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_8038BA68, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chMotzhand, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&D_80367E70, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chLoggo,    actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_8038BAD0, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_8038BE48, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_8038BE6C, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_8038BE90, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_8038BEB4, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_8038BED8, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_8038BEFC, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_80372C3C, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_19);
}
