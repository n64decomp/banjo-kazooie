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
int func_8032886C(Actor *, f32);
f32 func_802877D8(ActorMovement *);
void func_8030E878(s32, f32, s32, f32*, f32, f32);
void func_8030DA44(u8);

//static types
typedef struct sm_2900_struct{
    s16 unk0;
    s16 unk2;
    u8 pad4[1];
    s8 unk5;
}SM2900Struct;

//public
void func_803899B0(Actor * this);

/* .data */
/*ActorAnimationInfo D_8038AF60[6] = {
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


};//*/
//D_8038AFB0
extern SM2900Struct D_8038AFB4[];

extern s32 D_8038AFE4;


/* .rodata */
extern f64 D_8038B2C8;
extern f64 D_8038B2D0;
extern f32 D_8038B2D8;
extern f32 D_8038B2DC;
extern f32 D_8038B2E0;
extern f32 D_8038B2E4;
extern f32 D_8038B2E8;
extern f32 D_8038B2EC;
extern f32 D_8038B2F0;
extern f64 D_8038B2F8;
extern f64 D_8038B300;



#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80388FA0.s")

void func_80389214(ActorMarker *marker, s32 text_id, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80389214.s")

void func_803892C8(ActorMarker *marker, s32 text_id, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_803892C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80389494.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_80389610.s")
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
    other = func_8032818C(0x12c, &actor);
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
    s32 sp50[6];
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

    func_8024E55C(0,sp50);
    player_getPosition(sp44);
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
        if( (f64) 0.0 < func_802877D8(this->movement)
            && func_802877D8(this->movement) < D_8038B2C8
        ){
            func_8030E2C4(this->unk44_31);
        }//L80389EA0
        if(func_8032886C(this, 0.9999f)){
            if(!mapSpecificFlags_get(1)){
                func_80389610(this);
            }
            func_80388FA0(this, 3);
        }//L80389EE0
        else if(func_8032886C(this, 0.14f)){
            func_8030E8B4(0x997770c6, this->position, 0x9C404e2);
        }
        else if(func_8032886C(this, 0.4f)){ //L80389F14
            func_8030E8B4(0x9977702c, this->position, 0x9C404e2);
        }else if(func_8032886C(this, 0.75f)){//L80389F48
            func_8030E8B4(0x7fff40c5, this->position, 0x9C404e2);
        }else if(func_8032886C(this, 0.35f)){//L80389F78
            if(mapSpecificFlags_get(1)){
                func_80389610(this);
            }
        }
        break;
    case 3://L80389FAC
        this->yaw_moving = func_80329784(this);
        func_80328FB0(this, 4.0f);
        if( ( func_8032886C(this, 0.37f)
              || func_8032886C(this, 0.66f)
              || func_8032886C(this, 0.85f)
            ) 
            && randf() < D_8038B2D0
        ){
            movement_setDirection(this->movement, func_802877B8(this->movement)^1);
        }//L8038A088
        else if( func_8032886C(this, 0.25f)
            || func_8032886C(this, 0.28f)
            || func_8032886C(this, 0.31f)
        ){
            func_8030E878(0x6f, randf2(D_8038B2D8, D_8038B2DC), 0x3e80, this->position, D_8038B2E0, D_8038B2E4);
        } //L8038A0D8
        else if( func_8032886C(this, 0.45f)
            || func_8032886C(this, 0.48f)
            || func_8032886C(this, 0.51f)
            || func_8032886C(this, 0.7f)
            || func_8032886C(this, 0.73f)
            || func_8032886C(this, 0.76f)
        ){
            func_8030E878(0x6f, randf2(D_8038B2E8, 1.5f), 0x1770, this->position, D_8038B2EC, D_8038B2F0);
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
                    sp38 = 1;
                else if(sp50[1] == 1)
                    sp38 = 0;
            }//L8038A218

            if( sp38 != -1){
                func_80320004(0xdb, (sp38)?0:1);
                func_80311480((sp38)? 0xe07 : 0xe09, 0xe, this->position, this->marker, func_803892C8, func_80389214);
                if(!sp38){
                    func_80388EB0();
                }
                this->unk38_0 = 0;
            }else if(!this->unk138_24 && 5.0 < this->unk60){
                func_80311480(0xe1d, 0x86, this->position, this->marker, func_803892C8, NULL);
                this->unk138_24 = 1;
            }
        }
        break;
    case 4://L8038A31C
        if( D_8038B2F8 < func_802877D8(this->movement) 
            && func_802877D8(this->movement) < D_8038B300
        ){
            func_8030E2C4(this->unk44_31);
        }else{//L8038A378
            if(func_8032886C(this, 0.9999f)){
                func_80388FA0(this, 1);
                func_80386540();
            }
        }
        break;
    }//L8038A3A0
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_2900/func_8038A3B0.s")
