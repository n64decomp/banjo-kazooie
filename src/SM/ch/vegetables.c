#include <ultra64.h>
#include "functions.h"
#include "variables.h"



//external
void func_80326224(Actor *);
void func_803300A8(ActorMarker *, void(*)(ActorMarker *), void(*)(ActorMarker *), void(*)(ActorMarker *));
int func_8032886C(Actor*, f32);
f32 func_80309724(f32*);
void func_80256A24(f32 *, f32);
f32 func_80256064(f32 *, f32 *);
void func_80256900(f32*, f32*, f32);
void func_802C4218(s32, f32, f32, f32);
void func_803252D0(f32, s32);
void func_80328B8C(Actor *, s32, f32, s32);
void func_802EF9F8(Actor *, f32);
void func_802EFE24(Actor *, f32, f32, f32, f32, f32, f32);

//typedefs
typedef struct ch_vegatable{
    TUPLE(f32, unk0);
    s32 unkC;
    u32 pad10_31: 19;
    u32 unk10_12: 4;
    u32 pad10_8: 9;
} ChVeg;

//public
Actor *func_80387DF4(ActorMarker *, Gfx**, Mtx**, s32);
void func_80388080(Actor *);

/* .data */
ActorAnimationInfo chCarrotAnimations[5] = {
    {0, 0.0f},
    {0x223, 1000000.0f},
    {0x223, 1.0f},
    {0x224, 0.75f},
    {0x223, 1.0f}
};

ActorInfo D_8038AC78 = { 0x12A, ACTOR_TOPPER_A, MODEL_TOPPER, 1, chCarrotAnimations,
    func_80388080, func_80326224, func_80387DF4,
    {0x07,0xD0,0,0}, 1.0f, {0,0,0,0}
};

ActorInfo D_8038AC9C = { 0x1E6, ACTOR_TOPPER_B, MODEL_TOPPER, 1, chCarrotAnimations,
    func_80388080, func_80326224, func_80387DF4,
    {0x07,0xD0,0,0}, 1.0f, {0,0,0,0}
};

ActorAnimationInfo chOnionAnimations[5] = {
    {0, 0.0f},
    {0x226, 1000000.0f},
    {0x226, 1.0f},
    {0x227, 0.75f},
    {0x226, 1.0f}
};

ActorInfo D_8038ACE8 = { 0x129, ACTOR_BAWL_A, MODEL_BAWL, 1, chOnionAnimations,
    func_80388080, func_80326224, func_80387DF4,
    {0,0,0,0}, 1.0f, {0,0,0,0}
};

ActorInfo D_8038AD0C = { 0x1E7, ACTOR_BAWL_B, MODEL_BAWL, 1, chOnionAnimations,
    func_80388080, func_80326224, func_80387DF4,
    {0,0,0,0}, 1.0f, {0,0,0,0}
};

ActorAnimationInfo chCauliflowerAnimations[5] = {
    {0, 0.0f},
    {0x225, 10000000.0f},
    {0x225, 1.0f},
    {0x225, 10000000.0f},
    {0x225, 1.0f}
};

ActorInfo D_8038AD58 = { 0x128, ACTOR_COLLYWOBBLE_A, MODEL_COLLYWOBBLE, 1, chCauliflowerAnimations,
    func_80388080, func_80326224, func_80387DF4,
    {0,0,0,0}, 2.0f, {0,0,0,0}
};

ActorInfo D_8038AD7C = { 0x1E8, ACTOR_COLLYWOBBLE_B, MODEL_COLLYWOBBLE, 1, chCauliflowerAnimations,
    func_80388080, func_80326224, func_80387DF4,
    {0,0,0,0}, 2.0f, {0,0,0,0}
};
extern f32 D_8038ADA0[3];

extern s32 D_8038ADAC;
extern s32 D_8038ADD4;

extern s32 D_8038AE04;
extern s32 D_8038AE2C;

extern s32 D_8038AE74;
extern s32 D_8038AE9C;

extern s32 D_8038AEE4;
extern s32 D_8038AF0C;

/* .rodata */
extern f64 D_8038B1A0;
extern f64 D_8038B1A8;
extern f64 D_8038B1B0;
extern f64 D_8038B1B8;
extern f64 D_8038B1C0;
extern f64 D_8038B1C8;
extern f64 D_8038B1D0;
extern f64 D_8038B1D8;
extern f64 D_8038B1E0;
extern f64 D_8038B1E8;
extern f64 D_8038B1F0;

/* .code */
void func_80387910(Actor *arg0, f32 *arg1, s32 arg2){
    f32 sp24[3] = D_8038ADA0;
    func_802EFFA8(arg0, sp24);
    func_802EF950(arg0, 0x700);
    func_802EFA90(arg0, 0, 7);
    func_802EFB54(arg0, arg1);
    func_802EFB98(arg0, &D_8038ADAC);
    func_802EFD00(arg0, &D_8038ADD4);
    func_802EF5C8(arg0, arg2);
}

void func_803879B8(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3){
    func_802EF9F8(arg0, 0.6f);
    func_802EFA18(arg0, 2);
    func_802EFAC8(arg0, arg3);
    func_802EFB54(arg0, arg1);
    func_802EFA70(arg0, 2);
    func_802EFE24(arg0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB98(arg0, &D_8038AE04);
    func_802EFD7C(arg0, &D_8038AE2C);
    func_802EF5C8(arg0, arg2);
}

void func_80387A80(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3){
    func_802EF9F8(arg0, 0.6f);
    func_802EFA18(arg0, 3);
    func_802EFAC8(arg0, arg3);
    func_802EFB54(arg0, arg1);
    func_802EFA70(arg0, 2);
    func_802EFE24(arg0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB98(arg0, &D_8038AE74);
    func_802EFD7C(arg0, &D_8038AE9C);
    func_802EF5C8(arg0, arg2);
}

void func_80387B48(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3){
    func_802EF9F8(arg0, 0.7f);
    func_802EFA18(arg0, 4);
    func_802EFAC8(arg0, arg3);
    func_802EFB54(arg0, arg1);
    func_802EFA70(arg0, 2);
    func_802EFE24(arg0, 150.0f, -300.0f, -300.0f, 300.0f, 300.0f, -150.0f);
    func_802EF9EC(arg0, 0x1f, 0x1f40);
    func_802EFB98(arg0, &D_8038AEE4);
    func_802EFD7C(arg0, &D_8038AF0C);
    func_802EF5C8(arg0, arg2);
}

void func_80387C28(Actor * this){
    ChVeg * local = &this->local;
    f32 sp30[3];

    func_8030E8B4(0x7FFF4111, this->position, 0x7d003e8);
    if(local->unkC == 3){
        sp30[0] = this->position_x;
        sp30[1] = this->position_y;
        sp30[2] = this->position_z;
        sp30[1] += 50.0f;
        func_80387B48(func_802F0BD0(0xC), sp30, 0xC, 0x4F4);
        func_803879B8(func_802F0BD0(4), sp30, 0x4, 0x4F2);
        func_803879B8(func_802F0BD0(4), sp30, 0x4, 0x4F3);
        sp30[1] += 50.0f;
        func_80387910(func_802F0BD0(8), sp30, 8);
    }//L80387D18
    if(this->unk38_31){
        this->position_y += 100.0f;
        func_802CA1CC(0x17);
        func_802C3F04(func_802C4218, 0x1f, *(s32 *)&this->position_x, *(s32 *)&this->position_y, *(s32 *)&this->position_z);
    }//L80387D64
    func_803252D0(1.5f, 7);
    actor_collisionOff(this);
    if(local->unkC != 3){
        func_80328B8C(this, 3, 0.0f, 1);
        func_803298AC(this);
    }
    else{
        marker_despawn(this->marker);
    }
}

void func_80387DCC(ActorMarker *marker, s32 arg1){
    func_80387C28(marker_getActor(marker));
}

Actor *func_80387DF4(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);

    if(actor->unk138_24)
        func_8033A470(3, 7);
    else
        func_8033A45C(3, 0);

    func_80325888(marker, gdl, mptr, arg3);
}

void func_80387E64(Actor *this){
    ChVeg *local = &this->local;

    this->unk1C = randf2(-50.0f, 50.0f);
    this->unk20 = randf2(-50.0f, 50.0f);
    this->unk24 = randf2(-50.0f, 50.0f);

    this->unk1C = local->unk0_x + this->unk1C;
    this->unk20 = local->unk0_y + this->unk20;
    this->unk24 = local->unk0_z + this->unk24;
}

void func_80387F00(Actor *this){
    ChVeg *local = &this->local;
    
    this->position_y += (mapSpecificFlags_get(0xC) || func_803203FC(0xC1, this)) ? 120.0 : D_8038B1A0;
    local->unk0_x = this->position_x;
    local->unk0_y = this->position_y;
    local->unk0_z = this->position_z;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    func_80387E64(this);
}

int func_80387FA8(Actor *this, ChVeg *local, s32 yaw, s32 arg3){
    f32 sp24[3];
    f32 sp18[3];
    
    sp18[0] = arg3;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    func_80256900(sp18, sp18, yaw - D_8038B1A8);
    sp24[0] = sp18[0] + local->unk0_x;
    sp24[1] = sp18[1] + local->unk0_y;
    sp24[2] = sp18[2] + local->unk0_z;
    if(func_80307258(sp24, this->unk10_25 - 1, this->unk10_18 - 1) == -1)
        return 0;
    else
        return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388080.s")
//99.99% Matching
/*void func_80388080(Actor *this){
    f32 temp_velZ;
    f32 temp_velX;
    f32 temp_f0;
    f32 sp78;
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    ChVeg *local = this->local; //sp38
    f32 sp30;

    

    if(!this->initialized){
        switch(this->marker->unk14_20){
            default:
                local->unkC = 3; //cauliflower
                break;
            case 0x12A: //L803880F0
            case 0x1E6: //L803880F0
                local->unkC = 1; //carrot
                break;
            case 0x129: //L80388100
            case 0x1E7: //L80388100
                local->unkC = 2; //onion
                break;
        }
        actor_collisionOff(this);
        func_803300A8(this->marker, NULL, NULL, func_80387DCC);
        this->unk1C = this->position_x;
        this->unk20 = this->position_y;
        this->unk24 = this->position_z;
        this->position_y -= 200.f;

        do{//L80388154
            temp_velX = randf2(-10.0f, 10.0f);
            temp_f0 =(0.0f <= temp_velX) ? temp_velX : -temp_velX;
        }while(temp_f0 < 5.0);

        do{//L803881AC
            temp_velZ = randf2(-10.0f, 10.0f);
            temp_f0 =(0.0f <= temp_velZ) ? temp_velZ : -temp_velZ;
        }while(temp_f0 < 5.0);

        this->velocity_x = temp_velX;
        this->velocity_y = (local->unkC == 3) ? 90.0f : 70.0f;
        this->velocity_z = temp_velZ;
        this->unk138_24 = 1;
        this->unk138_23 = 0;
        this->unk38_0 = 0;
        this->initialized = 1;
        this->scale = 0.5;
    }//L80388278
    switch (this->unk10_31)
    {
    case 1: //L803882B0
        if(mapSpecificFlags_get(0xC) || func_803203FC(0xC1) || this->unk10_12){
            //L803882E4
            if(mapSpecificFlags_get(0xC) || func_803203FC(0xC1)){ //L8038830C
                this->unk20 += (local->unkC == 3)? 120.0 : 0.0;
            }else{//L80388350
                this->unk20 += (local->unkC == 3)? D_8038B1B0 : D_8038B1B8;
            }
            //L80388384
            func_80328A84(this, 4);
        }
        break;
    case 4: //L8038839C
        this->position_x = this->velocity_x + this->position_x;
        this->position_y = this->velocity_y + this->position_y;
        this->position_z = this->velocity_z + this->position_z;
        this->velocity_y -= 5.0f;
        this->scale = MIN(this->scale + D_8038B1C0, 1.0);
        if(this->velocity_y < 0.0f && this->position_y < this->unk20){
            this->position_y = func_80309724(this->position);
            if(local->unkC == 3)
                func_80387F00(this);

            actor_collisionOn(this);
            func_80328A84(this, 2);
        }//L80388494

        if(!this->unk138_23){
            if(0.0f < this->position_y){
                func_8030E8B4(0x7FFF40C5, this->position, 0x7D003E8);
                this->unk138_23 = 1;
                this->scale = 1.0f;
            }
        }

        break;
    case 2: //L803884E4
        if(this->unk38_0){
            if(func_80329480(this)){
                this->unk38_0 = 0;
            }
        }else{//L80388520
            if(local->unkC == 1){
                this->unk28 = 3.0f;
                if(mapSpecificFlags_get(0xC) || func_803203FC(0xC1)){//L80388554
                    if(!func_80329030(this, 0) && func_80329480(this)){
                        func_80328CEC(this, (s32)this->yaw, 0x78, 0xb4);
                        this->unk38_0 = 1;
                    }//L803885A0
                    if(func_803292E0(this)){
                        this->yaw_moving = func_80329784(this);
                    }
                    else{//L803885CC
                        if(randf() < D_8038B1C8){
                            func_80328CEC(this, (s32)this->yaw, 0x1E, 0x5A);
                        }
                    }//L80388B68
                }
                else{//L80388618
                    this->yaw_moving = func_80329784(this);
                }
            }
            else if(local->unkC == 2){//L80388634
                this->unk28 = 4.0f;
                if(!func_80329030(this, 0) && func_80329480(this)){
                    func_80328CEC(this, (s32)this->yaw, 0x78, 0xB4);
                    this->unk38_0 = 1;
                }//L80388698
                if(mapSpecificFlags_get(0xC) || (func_803203FC(0xC1) && func_803292E0(this))){
                    this->yaw_moving = func_80329784(this);
                }else{//L803886E4
                    if(randf() < D_8038B1D0){
                        func_80328CEC(this, (s32)this->yaw, 0x1E, 0x5A);
                    }
                }
            }else{//L80388730
                sp78 = func_8033DD9C();
                sp6C[0] = this->unk1C - this->position_x;
                sp6C[1] = this->unk20 - this->position_y;
                sp6C[2] = this->unk24 - this->position_z;
                if( gu_sqrtf(sp6C[0]*sp6C[0] + sp6C[1]*sp6C[1] + sp6C[2]*sp6C[2] ) < 40.0f){
                    func_80256A24(sp6C, 400.0f);
                }
                else{
                    func_80256A24(sp6C, 100.0f);
                }
                this->position_x += this->velocity_x*sp78 + sp6C[0]*sp78*sp78;
                this->position_y += this->velocity_y*sp78 + sp6C[1]*sp78*sp78;
                this->position_z += this->velocity_z*sp78 + sp6C[2]*sp78*sp78;
                this->velocity_x += sp6C[0]*sp78;
                this->velocity_y += sp6C[1]*sp78;
                this->velocity_z += sp6C[2]*sp78;
                if(gu_sqrtf(this->velocity_z*this->velocity_z + (this->velocity_x*this->velocity_x + this->velocity_y*this->velocity_y)) > 50.0f){
                    func_80256A24(this->velocity, 50.0f);
                }
                if(func_80256064(this->position, &this->unk1C) < 20.0f){
                    func_80387E64(this);
                }
                this->unk28 = 5.0f;
                if(mapSpecificFlags_get(0xC) || (func_803203FC(0xc1))){ //L8038892C
                    if(!func_80387FA8(this, local, (s32)this->yaw, (s32)this->unk28)){
                        if(func_80329480(this)){
                            func_80328CEC(this, (s32)this->yaw, 0x78, 0xb4);
                            this->unk38_0 = 1;
                        }//L80388994
                    }else{ //L803889A0

                        this->position_x -= local->unk0_x;
                        this->position_y -= local->unk0_y; 
                        this->position_z -= local->unk0_z; 
                        this->unk1C -= local->unk0_x;
                        this->unk20 -= local->unk0_y;
                        this->unk24 -= local->unk0_z;
                        sp60[0] = this->unk28;
                        sp60[2] = 0.0f; //register assignment order swapped;
                        sp60[1] = 0.0f; //register assignment order swapped;
                        func_80256900(sp60, sp60, this->yaw - D_8038B1D8);
                        local->unk0_x = sp60[0] + local->unk0_x;
                        local->unk0_y = sp60[1] + local->unk0_y;
                        local->unk0_z = sp60[2] + local->unk0_z;
                        this->position_x = local->unk0_x + this->position_x;
                        this->position_y = local->unk0_y + this->position_y;
                        this->position_z = local->unk0_z + this->position_z;
                        this->unk1C = local->unk0_x + this->unk1C;
                        this->unk20 = local->unk0_y + this->unk20;
                        this->unk24 = local->unk0_z + this->unk24;
                    }//L80388AD8
                    if(func_803292E0(this)){
                        this->yaw_moving = func_80329784(this);
                    }else{//L80388B04
                        if(randf() < D_8038B1E0){
                            func_80328CEC(this, (s32)this->yaw, 0x1e, 0x5A);
                        }
                    }
                }else{
                    //L80388B50
                    this->yaw_moving = func_80329784(this);
                }

            }
        }//L80388B68
        func_80328FB0(this, 0x40000000);
        
        if(local->unkC != 3 && func_8032886C(this, 0.3f))
            func_8030E8B4(0x7FF57BF2, this->position, 0x7D003E8);
        
        if(local->unkC == 3 && func_8032886C(this, 0.4f)){
            func_8030E8B4(0x7307D002, this->position, 0x7D003E8);
        }
        break;
    case 3: //L80388BFC
        if(func_8032886C(this, (local->unkC == 2) ? D_8038B1E8 : D_8038B1F0)){
            sp54[0] = this->position_x;
            sp54[1] = this->position_y;
            sp54[2] = this->position_z;
            if(local->unkC == 1)
                sp54[1] += 150.0f;
            this->unk138_24 = 0;
            func_80387A80(func_802F0BD0(3), sp54, 3, (local->unkC == 1)? 0x4f0: 0x4f1);
        }//L80388CC4
        
        if(func_8032886C(this, 0.75f))
            func_80326310(this);
        break;
    }//L80388CE0
}//*/

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80388FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80389214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_803892C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80389494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80389610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80389948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_80389984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_803899B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/ch/vegetables/func_8038A3B0.s")
