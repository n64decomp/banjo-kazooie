#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802D9D60(Actor *this);
Actor *func_802D94B4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802D9830(ActorMarker *marker, enum asset_e arg1, s32 arg2);

typedef struct{
    s16 unk0;
    s16 unk2;
    s8 unk4;
    s8 unk5;
} struct_core2_52290;

/* .data */
ActorAnimationInfo D_80367D70[]= {
    {0, 0.0f},
    {ASSET_13A_ANIM_BOTTLES_ENTER,  2000000000.0f},  
    {ASSET_13A_ANIM_BOTTLES_ENTER,  4.5f},
    {ASSET_13B_ANIM_BOTTLES_IDLE,   7.0f},  
    {ASSET_139_ANIM_BOTTLES_EXIT,   1.7f},
    {ASSET_13A_ANIM_BOTTLES_ENTER,  2000000000.0f},
};

ActorInfo D_80367DA0= {
    0x1DF, ACTOR_37A_BOTTLES, ASSET_387_MODEL_BOTTLES, 
    1, D_80367D70, 
    func_802D9D60, func_80326224, func_802D94B4,
    {0,0}, 0, 0.0f, {0,0,0,0}
}; 

struct_core2_52290 D_80367DC4[] = {
    {0x0C23, 0x0C24, 0x0F, ABILITY_1_BEAK_BOMB}, 
    {0x0B47, 0x0B4B, 0x16, ABILITY_6_EGGS},
    {0x0B48, 0x0B4C, 0x17, ABILITY_2_BEAK_BUSTER},
    {0x0B49, 0x0B4A, 0x18, ABILITY_10_TALON_TROT},
    {0x0A1F, 0x0A23, 0x0C, ABILITY_D_SHOCK_JUMP},
    {0x0A20, 0x0A22, 0x0D, ABILITY_9_FLY},
    {0x0D35, 0x0D36, 0x01, ABILITY_12_WONDERWING},
    {0x0C88, 0x0C89, 0x10, ABILITY_E_WADING_BOOTS},
    {0x0A84, 0x0A85, 0x19, ABILITY_11_TURBO_TALON},
    {0x0F64, 0x0F65, 0x0E, ABILITY_13_1ST_NOTEDOOR}
};

/* .code */
int func_802D9220(enum level_e level){
    switch (level){
        case LEVEL_1_MUMBOS_MOUNTAIN:
            return ability_isUnlocked(ABILITY_6_EGGS)
                && ability_isUnlocked(ABILITY_2_BEAK_BUSTER)
                && ability_isUnlocked(ABILITY_10_TALON_TROT);
        case LEVEL_2_TREASURE_TROVE_COVE:
            return ability_isUnlocked(ABILITY_D_SHOCK_JUMP)
                && ability_isUnlocked(ABILITY_9_FLY);
        case LEVEL_3_CLANKERS_CAVERN:
            return ability_isUnlocked(ABILITY_12_WONDERWING);
        case LEVEL_4_BUBBLEGLOOP_SWAMP:
            return ability_isUnlocked(ABILITY_E_WADING_BOOTS);
        case LEVEL_5_FREEZEEZY_PEAK:
            return ability_isUnlocked(ABILITY_1_BEAK_BOMB);
        case LEVEL_7_GOBIS_VALLEY:
            return ability_isUnlocked(ABILITY_11_TURBO_TALON);
        default:
            return FALSE;
  }
}

enum asset_e func_802D9304(void){
    s32 level_id = level_get();
    int learned_all_moves = func_802D9220(level_id);
    switch(level_id){
        case LEVEL_1_MUMBOS_MOUNTAIN:
            return learned_all_moves ? 0xb4e : 0xd38;
        case LEVEL_2_TREASURE_TROVE_COVE:
            return learned_all_moves ? 0xa27 : 0xd38;
        case LEVEL_3_CLANKERS_CAVERN:
            return learned_all_moves ? 0xd37 : 0xd38;
        case LEVEL_4_BUBBLEGLOOP_SWAMP:
            return learned_all_moves ? 0xc8a : 0xd38;
        case LEVEL_5_FREEZEEZY_PEAK:
            return learned_all_moves ? 0xc2a : 0xd38;
        case LEVEL_7_GOBIS_VALLEY:
            return learned_all_moves ? 0xc2a : 0xd38;
        default:
            return 0xd38;

    }
}


int func_802D93EC(void){
    return ability_isUnlocked(ABILITY_6_EGGS)
        && ability_isUnlocked(ABILITY_2_BEAK_BUSTER)
        && ability_isUnlocked(ABILITY_10_TALON_TROT)
        && ability_isUnlocked(ABILITY_D_SHOCK_JUMP)
        && ability_isUnlocked(ABILITY_9_FLY)
        && ability_isUnlocked(ABILITY_12_WONDERWING)
        && ability_isUnlocked(ABILITY_E_WADING_BOOTS)
        && ability_isUnlocked(ABILITY_1_BEAK_BOMB)
        && ability_isUnlocked(ABILITY_11_TURBO_TALON);
}

Actor *func_802D94B4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = marker_getActor(marker);

    if(actor->state != 1 && actor->state != 5){
        func_8033A45C(3, 0);
        func_8033A45C(4, 0);
        actor = func_80325888(marker, gfx, mtx, vtx);
    }

    return actor;
}

void func_802D9530(Actor *this){
    Actor *other = func_80329980(this);
    if(this->unk100 && other){
        if(this->unk100->unk14_20 == 0xB8)
            func_80328B8C(other, 3, 0.0001f, 1);
    }
    func_80328B8C(this, 4, 0.0001f, 1);
    actor_playAnimationOnce(this);
    this->unk44_31 = func_8030D90C();
    func_8030DA80(this->unk44_31, SFX_3F9_UNKNOWN);
    func_8030DD14(this->unk44_31, 2);
    func_8030DBB4(this->unk44_31, 1.4f);
    func_8030DABC(this->unk44_31, 26000);
    func_8028F918(0);
}

void func_802D9600(Actor * this){
    animctrl_setSmoothTransition(this->animctrl, 0);
    func_80328B8C(this, 1, 0.0001f, 1);
    this->marker->propPtr->unk8_3 = 0;
}

void func_802D9658(Actor *this){
    timed_setCameraToNode(0.0f, D_80367DC4[this->unkF4_8-9].unk4);
}

void func_802D9698(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    Actor *actor = marker_getActor(marker);

    if( arg1 == D_80367DC4[actor->unkF4_8-9].unk0 
        && item_getCount(ITEM_14_HEALTH) < item_getCount(ITEM_15_HEALTH_TOTAL)
    ){
        func_80311480(0xd39, 7, 0, actor->marker, func_802D9698, func_802D9830);
    }//L802D9738
    else if(arg1 == D_80367DC4[actor->unkF4_8-9].unk0 || arg1 == 0xd39){
        func_80311480(func_802D93EC()? 0xa87 : func_802D9304(), 7, 0, actor->marker, func_802D9698, NULL);
    }
    else{//L802D97BC
        if(actor->unk138_24){
            func_80347A14(1);
            actor->unk138_24 = FALSE;
        }
        func_80324E88(0.0f);
        if(actor->state == 5){
            func_8028F918(0);
            func_802D9600(actor);
        }//L802D9814
        else{
            func_802D9530(actor);
        }
    }//L802D9820
}

void func_802D9830(ActorMarker *marker, enum asset_e arg1, s32 arg2){
    Actor *actor = marker_getActor(marker);
    switch(arg2){
        case 1:
            timed_setCameraToNode(0.0f, 0x11);
            levelSpecificFlags_set(0x1A, 1);
            break;
        case 2:
            levelSpecificFlags_set(0x1A, 0);
            func_802D9658(actor);
            break;
        case 3:
            timed_setCameraToNode(0.0f, 0x29);
            levelSpecificFlags_set(0x1A, 1);
            break;
        case 4:
            levelSpecificFlags_set(0x1A, 0);
            func_802D9658(actor);
            break;
        case 5:
            func_803463D4(ITEM_D_EGGS, 50);
            break;
        case 6:
            func_803463D4(ITEM_F_RED_FEATHER, 25);
            break;
        case 7:
            func_803463D4(ITEM_10_GOLD_FEATHER, 5);
            break;
        case 8:
            item_set(ITEM_14_HEALTH, item_getCount(ITEM_15_HEALTH_TOTAL));
            break;
        case 0xff:
            func_802D9658(actor);
            break;
    }
}

int func_802D997C(Actor *this){
    s32 sp2C;
    s32 sp28 = 0xe;
    if(ability_isUnlocked(D_80367DC4[this->unkF4_8-9].unk5)){
        sp28 = 0xf;
        sp2C = D_80367DC4[this->unkF4_8-9].unk2;
    }//L802D99EC
    else{
        func_80347A14(0);
        this->unk138_24 = 1;
        sp2C = D_80367DC4[this->unkF4_8-9].unk0; 
        ability_unlock(D_80367DC4[this->unkF4_8-9].unk5);
        switch(D_80367DC4[this->unkF4_8-9].unk5){
            case ABILITY_9_FLY:
            case ABILITY_D_SHOCK_JUMP:
                func_8030E6A4(SFX_113_PAD_APPEARS, 0.9f, 32000);
                break;
            case ABILITY_13_1ST_NOTEDOOR:
                func_802FAD64(ITEM_C_NOTE);
                break;
        }
    }//L802D9A9C
    func_80311480(sp2C, sp28, this->position, this->marker, func_802D9698, func_802D9830);
    return TRUE;
}

void func_802D9ADC(Actor *this){
    Actor *other = func_80329980(this);
    if(this->unk100 && other && this->unk100->unk14_20 == 0xB8){
        func_80328B8C(other, 2, 0.0001f, 1);
    }
    this->marker->propPtr->unk8_3 = 1;
    animctrl_setSmoothTransition(this->animctrl, TRUE);
    func_80328B8C(this, 2, 0.0001f, 1);
    actor_playAnimationOnce(this);
    this->unk44_31 = func_8030D90C();
    func_8030DA80(this->unk44_31, SFX_3F9_UNKNOWN);
    func_8030DD14(this->unk44_31, 2);
    func_8030DBB4(this->unk44_31, 1.4f);
    func_8030DABC(this->unk44_31, 26000);
    func_802D9658(this);
    func_8028F94C(2, this->position);
}

void func_802D9BD8(Actor *this){
    func_80328A84(this, 5);
    func_802D9658(this);
    func_8028F94C(2, this->position);
    func_802D997C(this);
}

void func_802D9C1C(Actor *this){
    func_80328B8C(this, 3, 0.0001f, 1);
    actor_loopAnimation(this);
}

void func_802D9C54(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    Actor *other = spawn_child_actor(ACTOR_12C_MOLEHILL, &actor);
    f32 pad[1];

    actor->unk100 = other->marker;
    if(marker);
}

void func_802D9C90(Actor *this){
    u8 tmp_a1 = this->unk44_31;
    if(tmp_a1){
        func_8030DA44(tmp_a1);
    }
}

void func_802D9CBC(Actor *this){
    if(ability_isUnlocked(D_80367DC4[this->unkF4_8 - 9].unk5)){
        func_802D9BD8(this);
    }
    else{
        if(func_80329530(this, 150)){
            if(this->unk38_0 == 0)
                func_8028F45C(9, this->position);
            else
                func_8028F490(this->unk1C);
        }//L802D9D44
        func_802D9ADC(this);
    }
}

void func_802D9D60(Actor *this){
    s32 sp50[6];
    f32 sp4C;
    f32 pad44[2];
    Actor *other;
    f32 sp34[3];

    if(this->unkF4_8 < 8 || this->unkF4_8 >= 0x13)
        return;
    
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_803300D8(this->marker, func_802D9C90);
        if(this->initialized){
            other = func_80326D68(this->position, ACTOR_12C_MOLEHILL, -1, &sp4C);
            this->unk100 = (other) ? other->marker : NULL;
            if(this->unk100){
                other = func_80329980(this);
                if(other && this->unk100->unk14_20 == 0xB8){
                    func_80328A84(other, 1);
                }
            }
        }
    }//L802D9E34

    if(!this->initialized){
        other = func_80304C38(0x372, this);
        if(other == NULL){
            this->unk38_0 = FALSE;
        }
        else{
            this->unk38_0 = TRUE;
            func_80304D68(other, this->unk1C);
        }
        func_802C3C88(func_802D9C54, this->marker);
        this->marker->propPtr->unk8_3 = FALSE;
        this->marker->collidable = FALSE;
        this->initialized = TRUE;
        if(this->unkF4_8 == 0x12){
            other = func_80304C38(0x349, this);
            if(other == NULL){
                this->velocity[0] = this->position[0];
                this->velocity[1] = this->position[1];
                this->velocity[2] = this->position[2];
                this->unk28 = 500.0f;
            }
            else{ //L802D9F08
                func_80304D68(other, this->velocity);
                this->unk28 = 2*func_80304D3C(other);
            }
        }
    }//L802D9F34
    func_8024E55C(0, sp50);//get face buttons press counters
    switch(this->state){
        case 1://L802D9F70
            this->yaw_moving = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if(func_8028F20C() && func_8028F0D4() && !func_8028EC04()){
                if( this->unkF4_8 == 0x12 
                    && !ability_isUnlocked(D_80367DC4[this->unkF4_8-9].unk5)
                    && (!func_8028ECAC() || func_8028ECAC() == 8)
                ){
                    player_getPosition(sp34);
                    if(func_80256064(sp34, this->velocity) < this->unk28){
                        func_802D9CBC(this);
                    }
                }
                else{//L802DA054
                    if( !func_8028ECAC() 
                        && func_80329530(this, 0xFA)
                        && func_8028EFC8()
                        && sp50[BUTTON_Z] == 1
                    ){
                        func_802D9CBC(this);
                    }
                }
            }
            break;
        case 2://L802DA0A0
            this->marker->propPtr->unk8_3 = TRUE;
            this->yaw_moving = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if( 0.0 < func_802877D8(this->animctrl)
                && func_802877D8(this->animctrl) < 0.16
            ){
                func_8030E2C4(this->unk44_31);
            }//L802DA128
            if(actor_animationIsAt(this, 0.9999f)){
                func_802D9C1C(this);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
            }
            else if(actor_animationIsAt(this, 0.14f)){//L802DA154
                FUNC_8030E8B4(SFX_C6_SHAKING_MOUTH, 750, 0x4CB, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.4f)){//L802DA188
                FUNC_8030E8B4(SFX_2C_PULLING_NOISE, 750, 0x4CB, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.75f)){//L802DA1BC
                FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1000, 0x3FF, this->position, 1250, 2500);
            }
            else if(actor_animationIsAt(this, 0.35f)){//L802DA1EC
                func_802D997C(this);
            }
            break;
        case 3://L802DA210
            this->yaw_moving = func_80329784(this);
            func_80328FB0(this, 4.0f);
            if( ( actor_animationIsAt(this, 0.37f)
                  || actor_animationIsAt(this, 0.66f)
                  || actor_animationIsAt(this, 0.85f)
                )
                && randf() < 0.2
            ){
                    animctrl_setDirection(this->animctrl, 1 ^ animctrl_isPlayedForwards(this->animctrl));
            }
            else if(
                actor_animationIsAt(this, 0.25f)
                || actor_animationIsAt(this, 0.28f)
                || actor_animationIsAt(this, 0.31f)
            ){//L802DA2B4
                func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.4f, 1.55f), 16000, this->position, 1250.0f, 2500.0f);
            }
            else if(
                actor_animationIsAt(this, 0.45f)
                || actor_animationIsAt(this, 0.48f)
                || actor_animationIsAt(this, 0.51f)
                || actor_animationIsAt(this, 0.7f)
                || actor_animationIsAt(this, 0.73f)
                || actor_animationIsAt(this, 0.76f)
            ){//L802DA33C
                func_8030E878(SFX_6F_BANJO_HEADSCRATCH, randf2(1.35f, 1.5f), 6000, this->position, 1250.0f, 2500.0f);
            }
            break;
        case 4://L802DA400
            if( 0.35 < func_802877D8(this->animctrl) 
                &&  func_802877D8(this->animctrl) < 0.9
            ){
                func_8030E2C4(this->unk44_31);
            }
            else if(actor_animationIsAt(this, 0.9999f)){//L802DA45C
                func_802D9600(this);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
            }
            break;
    }//L802DA488
}

int func_802DA498(void){
    return ability_isUnlocked(ABILITY_F_DIVE)
        && ability_isUnlocked(ABILITY_4_BEAR_PUNCH)
        && ability_isUnlocked(ABILITY_C_ROLL)
        && ability_isUnlocked(ABILITY_B_RATATAT_RAP)
        && ability_isUnlocked(ABILITY_0_BARGE)
        && ability_isUnlocked(ABILITY_A_HOLD_A_JUMP_HIGHER)
        && ability_isUnlocked(ABILITY_7_FLAP)
        && ability_isUnlocked(ABILITY_8_FLIP)
        && ability_isUnlocked(ABILITY_5_CLIMB)
    ;
}
