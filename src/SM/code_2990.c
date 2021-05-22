#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//external
Actor *func_802D94B4(ActorMarker*, Gfx**, Mtx**, s32);
void func_80326224(Actor * this);
void func_803300D8(Actor *, void *);
void func_8028E668(f32*, f32, f32, f32);
void func_80328FB0(Actor *, f32);
f32 func_80256064(f32 *, f32 *);
int actor_animationIsAt(Actor *, f32);

void func_8030E878(s32, f32, s32, f32*, f32, f32);
void func_8030DA44(u8);
void func_80324E88(f32);
void func_80324E60(f32, s32);
void func_80328B8C(ActorMarker *, s32, f32, s32);
void func_8030DBB4(s32, f32);


//static types
typedef struct sm_2900_struct{
    s16 unk0; //text_id
    s16 unk2; //text_id
    s8 unk4; 
    s8 unk5; //ability_id
}SM2900Struct;

//public
void func_803899B0(Actor * this);
void func_80389610(Actor * this);

/* .data */
ActorAnimationInfo D_8038AF60[6] = {
    {0, 0.0f},
    {0x13A, 2000000000.0f},
    {0x13A, 4.5f},
    {0x13B, 7.0f},
    {0x139, 1.7f},
    {0x13A, 2000000000.0f}
};

ActorInfo D_8038AF90 = { 0xB7, 0x12B, 0x387, 1, D_8038AF60, //bottles
    func_803899B0, func_80326224, func_802D94B4,
    {0,0,0,0}, 0.0f, {0,0,0,0}


};

SM2900Struct D_8038AFB4[8] = {
    {0xdf3, 0xe08, 1, -1},
    {0xdf4, 0xdf5, 3, ABILITY_CAMERA_CONTROL},
    {0xdfb, 0xdfe, 5, ABILITY_DIVE},
    {   -1, 0xe00, 6, ABILITY_RATATAT_RAP},
    {0xe04, 0xe06, 8, ABILITY_BARGE},
    {   -1, 0xdf8, 4, ABILITY_FLIP},
    {0xe01, 0xe03, 7, ABILITY_CLIMB},
    {0xe10, 0xe11, 0x11, -1},
};

s32 D_8038AFE4 = 0;


/* .code */
int func_80388D80(void){
    return ability_isUnlocked(ABILITY_DIVE)
        || ability_isUnlocked(ABILITY_BEAR_PUNCH)
        || ability_isUnlocked(ABILITY_ROLL)
        || ability_isUnlocked(ABILITY_RATATAT_RAP)
        || ability_isUnlocked(ABILITY_BARGE)
        || ability_isUnlocked(ABILITY_HOLD_A_JUMP_HIGHER)
        || ability_isUnlocked(ABILITY_FLAP)
        || ability_isUnlocked(ABILITY_FLIP)
        || ability_isUnlocked(ABILITY_CLIMB);
}

void func_80388E48(void){
    ability_unlock(ABILITY_CAMERA_CONTROL);
    ability_setHasUsed(ABILITY_BARGE);
    ability_setHasUsed(ABILITY_BEAK_BOMB);
    ability_setHasUsed(ABILITY_BEAK_BUSTER);
    ability_setHasUsed(ABILITY_CAMERA_CONTROL);
    ability_setHasUsed(ABILITY_BEAR_PUNCH);
    ability_setHasUsed(ABILITY_CLIMB);
    ability_setHasUsed(ABILITY_RATATAT_RAP);
    ability_setHasUsed(ABILITY_ROLL);
    ability_setHasUsed(ABILITY_HOLD_A_JUMP_HIGHER);
}

void func_80388EB0(void){
    ability_unlock(ABILITY_DIVE);
    ability_unlock(ABILITY_BEAR_PUNCH);
    ability_unlock(ABILITY_ROLL);
    ability_unlock(ABILITY_RATATAT_RAP);
    ability_unlock(ABILITY_BARGE);
    ability_unlock(ABILITY_HOLD_A_JUMP_HIGHER);
    ability_unlock(ABILITY_FLAP);
    ability_unlock(ABILITY_FLIP);
    ability_unlock(ABILITY_CLIMB);
    func_80388E48();
    mapSpecificFlags_set(3,1);
}

void func_80388F24(Actor *this){
    if(this->unkF4_8 == 1 && !mapSpecificFlags_get(1)){
        func_80324E60(0.0f, 0x12);
    }
    else{ //L80388F68
        func_80324E60(0.0f, D_8038AFB4[this->unkF4_8 -1].unk4);
    }
}

void func_80388FA0(Actor *this, s32 arg1){
    ActorMarker *other;
    ActorMarker *myOther;

    switch(this->unk10_31){
        case 1://L80388FE8
            this->unk138_23 = 1;
            break;
        case 4://L80388FF8
            this->unk138_23 = 0;
        case 2://L80389004
            func_8030DA44(this->unk44_31);
            this->unk44_31 = 0;
            break;
        case 5://L80389018
            this->unk138_23 = 0;
            func_8028F918(0);
            
            break;
    }//L8038902C

    switch(arg1){
        case 4:
            other = func_80329980(this);
            myOther = this->unk100;
            if(myOther && other && myOther->unk14_20 == 0xB8)
                func_80328B8C(other, 3, 0.0001f, 1);
            actor_playAnimationOnce(this);
            this->unk44_31 = func_8030D90C();
            func_8030DA80(this->unk44_31, 0x3f9);
            func_8030DD14(this->unk44_31, 2);
            func_8030DBB4(this->unk44_31, 1.4f);
            func_8030DABC(this->unk44_31, 0x6590);
            func_8028F918(0);
            break;
        case 1:
            animctrl_setSmoothTransition(this->animctrl, 0);
            break;
        case 5:
            func_80388F24(this);
            func_8028F94C(2,this->position);
            func_80389610(this);
            break;
        case 3:
            actor_loopAnimation(this);
            break;
        case 2:
             other = func_80329980(this);
             myOther = this->unk100;
            if(myOther && other && myOther->unk14_20 == 0xB8)
                 func_80328B8C(other, 2, 0.0001f, 1);
            animctrl_setSmoothTransition(this->animctrl, 1);
            actor_playAnimationOnce(this);
            this->unk44_31 = func_8030D90C();
            func_8030DA80(this->unk44_31, 0x3f9);
            func_8030DD14(this->unk44_31, 2);
            func_8030DBB4(this->unk44_31, 1.4f);
            func_8030DABC(this->unk44_31, 0x6590);
            func_80388F24(this);
            func_8028F94C(2, this->position);
            break;
    }
    func_80328B8C(this, arg1, 0.0001f, 1);
}

void func_80389214(ActorMarker *marker, s32 text_id, s32 arg2){
    Actor *actor = marker_getActor(marker);
    switch(arg2){
        case 3:
            func_80324E60(0.0f, 2);
            break;
        case 4:
            mapSpecificFlags_set(4,1);
            break;
        case 5:
            func_80324E60(0.0f, 0x12);
            break;
        case 6:
            func_8025A70C(SFX_DING_B);
            break;
        case 0xff:
            func_80388F24(actor);
            break;
    }
}

void func_803892C8(ActorMarker *marker, s32 text_id, s32 arg2){
    Actor *actor;

    actor = marker_getActor(marker);
    if(!mapSpecificFlags_get(3) && func_802DA498()){
        mapSpecificFlags_set(3, 1);
        func_80311480(0xe12, 0xe, actor->position, actor->marker, func_803892C8, NULL);
    }//L8038933C
    else{ 
        if( !(text_id == 0xdf3 || text_id == 0xe1f || text_id == 0xe1d) ){
            func_80324E88(0.0f);
        }
        switch(text_id){
            case 0xd38:
                break;
            case 0xdf3:/* 2FB8 803893A8 3C188039 */
                func_80311480(0xe1f, 0x8e, actor->position, actor->marker, func_803892C8, func_80389214);
                break;

            case 0xe1f:/* 2FEC 803893DC 9209003B */
                actor->unk38_0 = 1;
                break;

            case 0xe1d:/* 2FFC 803893EC 920B0138 */
                actor->unk138_24 = 0;
                actor->unk60 = 0.0f;
                break;

            case 0xdf6: /* 3014 80389404 0C0A3E46 */
            case 0xdff: /* 3014 80389404 0C0A3E46 */
                func_8028F918(0);
                break;

            case 0xe09:
            case 0xe12:
                func_80388FA0(actor,4);
                break;

            default:
                if(actor->unk10_31 !=5 )
                    func_80311480(0xd38, 4, NULL, NULL, NULL, NULL);
                
                func_80388FA0(actor, actor->unk10_31 == 5 ? 1:4);
                break;
        }
    }
}

void func_80389494(Actor * this, s32* arg1, s32 *arg2){
    if(ability_isUnlocked(D_8038AFB4[this->unkF4_8 -1].unk5)){
        if(func_8031FF1C(0xDB)){
            *arg1 = D_8038AFE4 + 0xE0A; //dialog index
            D_8038AFE4++;
            D_8038AFE4 = MIN(D_8038AFE4, 5);
            if(*arg1 != 0xE0E){
                *arg2 |= 1;
            }
        }else{//L8038956C
            *arg2 |= 1;
            *arg1 = D_8038AFB4[this->unkF4_8 -1].unk2;
            if(*arg1 == 0xdfe && !func_802957A0(3)){
                *arg1 = 0xdfd;
            }
        }
    }else{//L803895C0
        *arg1 = D_8038AFB4[this->unkF4_8 -1].unk0;
        ability_unlock(D_8038AFB4[this->unkF4_8 -1].unk5);
    }
}

void func_80389610(Actor * this){
    s32 sp2C;
    s32 sp28;

    sp28 = 0xe;
    sp2C = 0;

    switch(this->unkF4_8){
        case 1://L8038965C
            if(mapSpecificFlags_get(1)){
                sp28 |= 1;
                if(func_8031FF1C(0xDB)){
                    sp2C = D_8038AFE4 + 0xE0A; //dialog index
                    D_8038AFE4++;
                    D_8038AFE4 = MIN(D_8038AFE4, 5);
                }else{//L803896C0
                    sp2C = D_8038AFB4[this->unkF4_8 -1].unk2;
                }
            }
            else{//L803896E8
                sp2C = D_8038AFB4[this->unkF4_8 -1].unk0;
                mapSpecificFlags_set(1,1);
            }
            break;
        case 8://L80389720
            if(mapSpecificFlags_get(3)){
                if(func_8031FF1C(0xa6)){
                    sp2C = 0xe37;
                    sp28 |= 1;
                }else{//L80389758
                    if(mapSpecificFlags_get(0xf)){
                        sp2C = 0xe0f;
                        sp28 |= 1;
                    }else{//L80389780
                        func_80388E48();
                        sp2C = func_8031FF1C(0xdb) ? 0xe1e : 0xe13;
                        mapSpecificFlags_set(0xf, 1);
                    }
                } //L803897B4
                mapSpecificFlags_set(2, 1);
            }
            else{//L803897C8
                if(mapSpecificFlags_get(2)){
                    sp2C = D_8038AFB4[this->unkF4_8 -1].unk2;
                    sp28 |= 1;
                }
                else{
                    sp2C = D_8038AFB4[this->unkF4_8 -1].unk0;
                    mapSpecificFlags_set(2, 1);
                }

            }
            break;
            
        case 4://L80389848
            if( !ability_isUnlocked(ABILITY_BEAR_PUNCH)
                || !ability_isUnlocked(ABILITY_ROLL)
                || !ability_isUnlocked(ABILITY_RATATAT_RAP)
            ){//L803898D4
                mapSpecificFlags_set(4, 1);
            }
            else{//L803898E4
                func_80389494(this, &sp2C, &sp28);
            }
            break;
        
        case 6://L803898A0
            if( !ability_isUnlocked(ABILITY_HOLD_A_JUMP_HIGHER)
                || !ability_isUnlocked(ABILITY_FLAP)
                || !ability_isUnlocked(ABILITY_FLIP)
            ){//L803898D4
                mapSpecificFlags_set(0xE, 1);
            }
            else{//L803898E4
                func_80389494(this, &sp2C, &sp28);
            }
            break;
        default://L803898F8
            func_80389494(this, &sp2C, &sp28);
            break;
    }//L80389904
    if(sp2C){
        func_80311480(sp2C, sp28, this->position, this->marker, func_803892C8, func_80389214);
    }
}

void func_80389948(ActorMarker * marker){
    Actor *actor;
    Actor *other;
    s32      pad;

    actor = marker_getActor(marker);
    other = spawn_child_actor(0x12c, &actor);
    actor->unk100 = other->marker;
    
    if(marker);
}

void func_80389984(Actor * this){
    u8 tmp;

    tmp = this->unk44_31;
    if(tmp)
        func_8030DA44(tmp);
}

void func_803899B0(Actor * this){
    s32 sp50[6]; //face buttons
    f32 sp44[3]; //player position
    Actor *sp40;
    int sp34;
    int sp38;
    
    if(this->unkF4_8 >= 9)
        return;

    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOff(this);
        this->initialized = 1;
        func_803300D8(this->marker, func_80389984);
        if(this->unkF4_8 == 1 || this->unkF4_8 == 8){//L80389A30
            sp40 = func_80304C38(0x349, this);
            if(!sp40){
                this->unk1C = this->position_x;
                this->unk20 = this->position_y;
                this->unk24 = this->position_z;
                this->unk28 = 300.0f;
            } else{ //L80389A68
                func_80304D68(sp40, &this->unk1C);
                this->unk28 = func_80304D3C(sp40);
            }//L80389A8C
            if(this->unkF4_8 == 1){
                if(func_803203FC(1) || func_803203FC(0x1F)){
                    func_80388FA0(this, 3);
                }
            }
        }//L80389AC8
        if(func_80388D80()){
            mapSpecificFlags_set(1,1);

            if(func_802DA498()){
                mapSpecificFlags_set(3, 1);
                mapSpecificFlags_set(2, 1);
                mapSpecificFlags_set(0xC, 1);
                mapSpecificFlags_set(0xF, 1);
            }
        }
    }//L80389B20

    if(!this->unk16C_4){
        func_802C3C88(func_80389948, this->marker);
        this->unk16C_4 = 1;
    }//L80389B4C

    if(this->unk138_23){
        func_8028E668(this->position, 180.0f, -40.0f, 120.0f);
    }//L80389B64

    func_8024E55C(0,sp50); //get face buttons press counters
    player_getPosition(&sp44);
    switch (this->unk10_31)
    {
    case 1://L80389BAC
        this->yaw_moving = (f32)func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( (this->unkF4_8 == 1 && !mapSpecificFlags_get(1))
            || (this->unkF4_8 == 8 && !mapSpecificFlags_get(2))
            || (this->unkF4_8 == 8 && mapSpecificFlags_get(3) && !mapSpecificFlags_get(0xF))
        ){//L80389C50
            
            if( ((func_80256064(sp44, &this->unk1C) < this->unk28) && func_8028F20C())
                || mapSpecificFlags_get(0x10)
            ){//L80389C8C
                if(func_80329530(this, 0x96))
                    func_8028F45C(9, this->position);
                //L80389CA4
                func_80388FA0(this, 2);
            }  
        }
        else{//L80389CBC
            if( !func_80329530(this, 0xfa)
                || func_8028ECAC()
                || !func_8028F20C()
                || func_8028EC04()
            ) break;
            
            sp34 = !((!(D_8038AFB4[this->unkF4_8-1].unk5 + 1)) || (!ability_isUnlocked( D_8038AFB4[this->unkF4_8-1].unk5)));
            if( (!sp34 && this->unkF4_8 != 1)
                || func_8031FF1C(0xDB) == 0
                || D_8038AFE4 < 6
            ){
                if(this->unkF4_8 != 8 || !func_8031FF1C(0xFC)){
                    if( func_8028EFC8()
                        && sp50[1] == 1
                    ){
                        if(sp34 || this->unkF4_8 == 1 || this->unkF4_8 == 8){
                            func_80388FA0(this, 5);
                        }
                        else{
                            if(func_80329530(this, 0x96) && !sp34){
                                func_8028F45C(9, this->position);
                            }
                            func_80388FA0(this, 2);
                        }
                    }
                }
            }
        }
        break;
    case 2://L80389E2C
        this->yaw_moving = func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( (f64) 0.0 < func_802877D8(this->animctrl)
            && func_802877D8(this->animctrl) < 0.16
        ){
            func_8030E2C4(this->unk44_31);
        }//L80389EA0
        if(actor_animationIsAt(this, 0.9999f)){
            if(!mapSpecificFlags_get(1)){
                func_80389610(this);
            }
            func_80388FA0(this, 3);
        }//L80389EE0
        else if(actor_animationIsAt(this, 0.14f)){
            func_8030E8B4(0x997770c6, this->position, 0x9C404e2);
        }
        else if(actor_animationIsAt(this, 0.4f)){ //L80389F14
            func_8030E8B4(0x9977702c, this->position, 0x9C404e2);
        }else if(actor_animationIsAt(this, 0.75f)){//L80389F48
            func_8030E8B4(0x7fff40c5, this->position, 0x9C404e2);
        }else if(actor_animationIsAt(this, 0.35f)){//L80389F78
            if(mapSpecificFlags_get(1)){
                func_80389610(this);
            }
        }
        break;
    case 3://L80389FAC
        this->yaw_moving = func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( ( actor_animationIsAt(this, 0.37f)
              || actor_animationIsAt(this, 0.66f)
              || actor_animationIsAt(this, 0.85f)
            ) 
            && randf() < 0.2
        ){
            animctrl_setDirection(this->animctrl, animctrl_isPlayedForwards(this->animctrl)^1);
        }//L8038A088
        else if( actor_animationIsAt(this, 0.25f)
            || actor_animationIsAt(this, 0.28f)
            || actor_animationIsAt(this, 0.31f)
        ){
            func_8030E878(0x6f, randf2(1.4f, 1.55f), 0x3e80, this->position, 1250.0f, 2500.0f);
        } //L8038A0D8
        else if( actor_animationIsAt(this, 0.45f)
            || actor_animationIsAt(this, 0.48f)
            || actor_animationIsAt(this, 0.51f)
            || actor_animationIsAt(this, 0.7f)
            || actor_animationIsAt(this, 0.73f)
            || actor_animationIsAt(this, 0.76f)
        ){
            func_8030E878(0x6f, randf2(1.35f, 1.5f), 0x1770, this->position, 1250.0f, 2500.0f);
        }//L8038A194

        if(mapSpecificFlags_get(5)){
            mapSpecificFlags_set(5,0);
            func_80388FA0(this, 4);
        }//L8038A1B8
        sp38 = -1;
        if(this->unk38_0){
            this->unk60 += func_8033DD9C();
            if(func_803114C4() != 0xe1d){
                if(sp50[0] == 1) 
                    sp38 = 1; //A button pressed
                else if(sp50[1] == 1)
                    sp38 = 0; //B button pressed
            }//L8038A218

            if( sp38 != -1){ //button was pressed
                func_80320004(0xdb, (sp38)?0:1);
                func_80311480((sp38)? 0xe07 : 0xe09, 0xe, this->position, this->marker, func_803892C8, func_80389214);
                if(!sp38){
                    func_80388EB0(); //give all SM moves
                }
                this->unk38_0 = 0;
            }else if(!this->unk138_24 && 5.0 < this->unk60){
                func_80311480(0xe1d, 0x86, this->position, this->marker, func_803892C8, NULL);
                this->unk138_24 = 1;
            }
        }
        break;
    case 4://L8038A31C
        if( 0.35 < func_802877D8(this->animctrl) 
            && func_802877D8(this->animctrl) < 0.9
        ){
            func_8030E2C4(this->unk44_31);
        }else{//L8038A378
            if(actor_animationIsAt(this, 0.9999f)){
                func_80388FA0(this, 1);
                func_80386540();
            }
        }
        break;
    }//L8038A3A0
}
