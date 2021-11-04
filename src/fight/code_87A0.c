#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CFC(f32, s32, s32);
extern void func_80386654(f32 arg0, f32 (*arg1)[4], f32 (*arg2)[4]);
extern void func_8038E03C(f32*, u32);
extern Actor *func_80325CAC(ActorMarker*, Gfx**, Mtx**, s32);
int func_80320C94(f32 (*)[3], f32(*)[3], f32, s32, s32, u32);
f32 func_8033229C(ActorMarker *);
void func_8038CED8(f32 (*)[3], s32, f32, f32);
void func_8038C5F0(Actor *, s32, s32, f32);

typedef struct {
    f32 unk0;
}ActorLocal_fight_87A0;

void func_8038F620(Actor *this);

/* .data */
ActorInfo D_80391B00 = {
    0x25C, 0x389, 0x541, 0x1, NULL,
    func_8038F620, func_80326224, func_80325888,
    {0, 0, 0, 0}, 1.0f, {0,0,0,0}
};

ActorInfo D_80391B24 = {
    0x280, 0x3AA, 0x6C9, 0x1, NULL,
    func_8038F620, func_80326224, func_80325CAC,
    {0, 0, 0, 0}, 1.0f, {0,0,0,0}
};

s32 D_80391B48[3] = {0xBA, 0xBA, 0xBA};
struct42s D_80391B54 = {
    { {-70.0f, 50.0f},
      {-70.0f, 70.0f},
      {100.0f, 70.0f}
    },
    { {-55.0f, 0.0f, -55.0f},
      {55.0f, 20.0f, 55.0f}
    }
};
f32 D_80391B84[4] = {1.0f, 1.0f, 1.0f, 1.0f};
f32 D_80391B94[4] = {0.3f, 0.3f, 0.3f, 1.0f};
s32 D_80391BA4[2] = {1, 9};
f32 D_80391BAC[4] = {4.5f, 4.5f, 4.5f, 4.5f};
f32 D_80391BBC[4] = {0.0f, 0.0f, 1.0f, 1.0f};
f32 D_80391BCC[4] = {0.0f, 0.0f, 0.85f, 1.35f};
f32 D_80391BDC[2] = {0.6f, 0.7f};
f32 D_80391BE4[6] = {-130.0f, 0.0f, -130.0f, 130.0f, 0.0f, 130.0f};
f32 D_80391BFC[4] = {1.1f, 1.1f, 4.0f, 5.4f};

f32 D_80391C0C[6] = {-20.0f, 0.0f, -20.0f, 20.0f, 40.0f, 20.0f};
f32 D_80391C24[6] = {0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 D_80391C3C[6] = {-420.0f, 410.0f, -420.0f, 480.0f, 860.0f, 480.0f};
f32 D_80391C54[4] = {0.35f, 0.65f, 0.0f, 0.0f};
f32 D_80391C64[4] = {0.0f, 0.01f, 2.0f, 2.3f};
f32 D_80391C74[2] = {0.0f, 0.35f};

f32 D_80391C7C[6] = {0.0f, 50.0f, 0.0f, 0.0f, 50.0f, 0.0f};
f32 D_80391C94[4] = {0.0f, 0.0f, 0.0f, 0.0f}; 
f32 D_80391CA4[4] = {0.0f, 0.0f, 0.0f, 0.0f}; 
f32 D_80391CB4[2] = {0.0f, 0.0f}; 
f32 D_80391CBC[4] = {0.0f, 0.0f, 0.2f, 0.25f};
f32 D_80391DCC[2] = {2.3f, 2.5f};
f32 D_80391DD4[6] = {0.0f, 0.0f, 0.34f, 0.34f, 0.7f, 0.8f};

s32 D_80391CEC[2] = {2, 0xf};
f32 D_80391CF4[4] = {2.0f, 2.0f, 0.4f, 0.4f};
f32 D_80391D04[4] = {0.0f, 0.0f, 0.24f, 0.24f};
f32 D_80391D14[2] = {0.1f, 0.2f};
f32 D_80391D1C[4] = {0.0f, 0.0f, 0.44f, 0.44f};
f32 D_80391D2C[2] = {0.4f, 0.5f};
f32 D_80391D34[6] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

f32 D_80391D4C[6] = {-50.0f, -50.0f, -50.0f, 50.0f, 50.0f, 50.0f};
f32 D_80391D64[6] = {0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 D_80391D7C[6] = {-260.0f, -260.0f, -260.0f, 260.0f, 260.0f, 260.0f};
f32 D_80391D94[4] = {0.15f, 0.3f, 0.0f, 0.0f}; 
f32 D_80391DA4[4] = {0.0f, 0.01f, 0.7f, 0.8f}; 
f32 D_80391DB4[2] = {0.0f, 0.65f}; 

/* .rodata */
extern f32 D_803925C0;
extern f64 D_803925C8;
extern f32 D_803925D0;
extern f32 D_803925E8;
extern f32 D_803925EC;
//3F28F5C3

// 3DCCCCCD 3E851EB8

/* .bss */
extern u8 D_803928E0;
extern u8 D_803928E1;
extern u8 D_803928E2;
extern u8 D_803928E3;
extern u8 D_803928E4;
extern u8 D_803928E5;
extern f32 D_803928E8[3];
extern f32 D_803928F8[3];
extern f32 D_80392908[3];
extern f32 D_80392914;

/* .code */
void func_8038EB90(ActorMarker *arg0, f32 *arg1) {
    Actor *temp_v0;

    temp_v0 = marker_getActor(arg0);
    temp_v0->position_x = arg1[0];
    temp_v0->position_y = arg1[1];
    temp_v0->position_z = arg1[2];
    temp_v0->position_y = temp_v0->position_y + 210.0f;
}

void func_8038EBE0(f32 (*arg0)[3], u32 arg1, enum asset_e arg2, f32 (*arg3)[6], f32 (*arg4)[6], f32 (*arg5)[6], f32 (*arg6)[4], f32 (*arg7)[4], f32 (*arg8)[2]) {
    struct30s *temp_v0 = func_802F0BD0(arg1);

    func_802EF950(temp_v0, arg2);
    func_802EFA90(temp_v0, 1, 6);
    func_802EFB54(temp_v0, arg0);
    func_802EFB1C(temp_v0, (*arg3)[0], (*arg3)[1], (*arg3)[2], (*arg3)[3], (*arg3)[4], (*arg3)[5]);
    func_802EF9AC(temp_v0, (*arg4)[0], (*arg4)[1], (*arg4)[2], (*arg4)[3], (*arg4)[4], (*arg4)[5]);
    func_802EFED4(temp_v0, (*arg5)[0], (*arg5)[1], (*arg5)[2], (*arg5)[3], (*arg5)[4], (*arg5)[5]);
    func_802EFE24(temp_v0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB70(temp_v0, (*arg6)[0], (*arg6)[1]);
    func_802EFB84(temp_v0, (*arg6)[2], (*arg6)[3]);
    func_802EF9F8(temp_v0, 0.5f);
    func_802EFA18(temp_v0, 3);
    func_802EFE5C(temp_v0, (*arg7)[0], (*arg7)[1]);
    func_802EFEC0(temp_v0, (*arg7)[2], (*arg7)[3]);
    func_802EFA5C(temp_v0, (*arg8)[0], (*arg8)[1]);
    func_802EFA78(temp_v0, 1);
    func_802EFA70(temp_v0, 4);
    func_802EF5C8(temp_v0, arg1);
}

void func_8038ED9C(f32 (*arg0)[3], u32 arg1, s32 arg2, s32 (*arg3)[2], f32 (*arg4)[6], f32 (*arg5)[4], f32 (*arg6)[4], f32 (*arg7)[2]) {
    struct30s *temp_v0 = func_802F0BD0(arg2);

    func_802EF950(temp_v0, arg1);
    func_802EFA90(temp_v0, (*arg3)[0], (*arg3)[1]);
    func_802EFA9C(temp_v0, 8.0f, 8.0f);
    func_802EFB54(temp_v0, arg0);
    func_802EFB1C(temp_v0, (*arg4)[0], (*arg4)[1], (*arg4)[2], (*arg4)[3], (*arg4)[4], (*arg4)[5]);
    func_802EFED4(temp_v0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EFB70(temp_v0, (*arg5)[0], (*arg5)[1]);
    func_802EFB84(temp_v0, (*arg5)[2], (*arg5)[3]);
    func_802EFE5C(temp_v0, (*arg6)[0], (*arg6)[1]);
    func_802EFEC0(temp_v0, (*arg6)[2], (*arg6)[3]);
    func_802EFA5C(temp_v0, (*arg7)[0], (*arg7)[1]);
    func_802EFA70(temp_v0, 0x10);
    func_802EFA78(temp_v0, 1);
    func_802EF5C8(temp_v0, arg2);
}

void func_8038EEFC(f32 (*arg0)[3], u32 arg1, f32 *arg2) {
    struct30s *temp_v0 = func_802F0BD0(arg1);

    func_802EF950(temp_v0, 0x70E);
    func_802EFFA8(temp_v0, &D_80391B48);
    func_802EF9E4(temp_v0, 0xEB);
    func_802EFA90(temp_v0, 0, 7);
    func_802EFB54(temp_v0, arg0);
    func_802EFD00(temp_v0, &D_80391B54);
    func_802EFB70(temp_v0, 0.1f, 0.2f);
    func_802EFB84(temp_v0, 3.6f, 4.6f);
    func_802EFE5C(temp_v0, arg2[0], arg2[1]);
    func_802EFEC0(temp_v0, arg2[2], arg2[3]);
    func_802EFA5C(temp_v0, 0.05f, 0.1f);
    func_802EFA70(temp_v0, 0x10);
    func_802EFA78(temp_v0, 1);
    func_802EF5C8(temp_v0, arg1);
}

void func_8038F01C(void) {
    func_80386654(1.0f, &D_80391B94, &D_80391B84);
}

void func_8038F050(void) {
    func_80386654(1.0f, &D_80391B84, &D_80391B94);
}

#ifndef NONMATCHING //matches but requires .rodata
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_87A0/func_8038F084.s")
#else
void func_8038F084(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    ActorLocal_fight_87A0 *local = (ActorLocal_fight_87A0 *)&actor->local;
    
    D_803928E8[0] = actor->position_x;
    D_803928E8[1] = actor->position_y;
    D_803928E8[2] = actor->position_z;
    
    D_803928E8[1] += 120.0f;

    if(actor->state != 2){//L8038F39C
        func_8030E8B4(0x7fff4148, &actor->position, 0x0dac03e8);
        timedFunc_set_0(0.0f, func_8038F01C);
        timedFunc_set_0(0.3f, func_8038F050);
        actor->unk58_0 = 0;
        actor->scale *=  1.6;
        if(actor->marker->unk14_20 != 0x280){
            func_8038EBE0(&actor->position, 4, 0x713, 
                &D_80391C0C, &D_80391C24, &D_80391C3C,
                &D_80391C54, &D_80391C64, &D_80391C74
            );
            func_8038EBE0(&actor->position, 4, 0x715, 
                &D_80391C0C, &D_80391C24, &D_80391C3C,
                &D_80391C54, &D_80391C64, &D_80391C74
            );
            func_8038EEFC(&actor->position, 3, &D_80391BFC);
            func_8038ED9C(&D_803928E8, 0x4A0, 1, &D_80391BA4, &D_80391BE4, 
                &D_80391BAC,  &D_80391BBC, &D_80391BDC
            
            );
            D_803928E8[1] -= 50.0f;
            func_8038ED9C(&D_803928E8, 0x6C1, 2, &D_80391BA4, &D_80391BE4, 
                &D_80391BAC,  &D_80391BBC, &D_80391BDC
            
            );
        }
        else{//L8038F304
            func_8038EBE0(&actor->position, 4, 0x713, 
                &D_80391C0C, &D_80391C24, &D_80391C3C,
                &D_80391C54, &D_80391BCC, &D_80391C74
            );
            func_8038EEFC(&actor->position, 3, &D_80391BFC);
            func_8038CED8(&actor->position, 0x558, 0.15f, 0.5f);
            actor->position_y += 260.0f;
            func_8038C5F0(actor, 0x712, 0x6c3, 1.6f);
        }
        local->unk0 = 0.66f;
        func_80328A84(actor, 2);
    }//L8038F39C
}
#endif

#ifndef NONMATCHING //matches but requires .rodata
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_87A0/func_8038F3B4.s")
#else
void func_8038F3B4(ActorMarker *marker, ActorMarker *other){
    if( other->unk14_20 == 0x276
        || other->unk14_20 == 0x27A
        || other->unk14_20 == 0x27F
    ) return;

    func_8038F084(marker);
    switch(func_80320424(0x23, 3)){
        case 1: //8038F41C
            if(!D_803928E0 && func_80311480(randi2(0, 5) + 0x10f2, 0, 0, 0, 0, 0))
                D_803928E0 = 1;
            break;
        case 2: //8038F468
            if(!D_803928E1 && func_80311480(randi2(0, 5) + 0x110b, 0, 0, 0, 0, 0))
                D_803928E1 = 1;
            break;
        case 3: //8038F4B4
            if(!D_803928E2 && func_80311480(randi2(0, 5) + 0x1122, 0, 0, 0, 0, 0))
                D_803928E2 = 1;
            break;
        case 4: //8038F500
            if( !D_803928E3 
                && func_8038C2A4()
                && func_80311480(randi2(0, 5) + 0x113b, 0, 0, 0, 0, 0)
            )
                D_803928E3 = 1;
            break; 
        case 5:
            if( !D_803928E4 
                && func_8038C2B0()
                && func_80311480(randi2(0, 5) + 0x1154, 0, 0, 0, 0, 0)
            )
                D_803928E4 = 1;
            break; 
    }//L8038F5B0

}
#endif

s32 func_8038F5BC(f32 *arg0, f32 arg1) {
    if (((arg0[0] * arg0[0]) + (arg0[2] * arg0[2])) < arg1) {
        return 1;
    }
    return 0;
}

void func_8038F5F8(s32 arg0) {
    func_80324D2C(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_87A0/func_8038F620.s")
#else
void func_8038F620(Actor *this){
    ActorLocal_fight_87A0 * local = (ActorLocal_fight_87A0 *)&this->local;
    f32 sp40 = func_8033DD9C();
    //static f32 D_80392914;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        func_803300A8(this->marker, NULL, NULL, func_8038F3B4);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        this->unk60 = 8.0f;
        this->scale = 0.1f;
        if( this->marker->unk14_20 == 0x280){
            actor_collisionOff(this);
            func_803300D8(this->marker, func_8038F5F8);
            func_80324CFC(0.0f, 0x43, 32000);
            func_80324C88(0.0f, 0x113, 1.0f, 32000);
            func_80324C88(0.75f, 0x415, 1.0f, 32000);
            func_80324C88(2.0f, 0x415, 1.0f, 32000);


        }
        else{//L8038F738
            func_80324D54(0.26f, 0x14f, 1.0f, 0x61A8,
                &this->position, 1000.0f, 7500.0f
            );

            func_80324D54(0.4f, 0x14e, 1.0f, 0x61A8,
                &this->position, 500.0f, 4500.0f
            );
        }
    }//L8038F79C
    if(D_803928E5 && this->marker->unk14_20 == 0x280){
        func_802BAD08(&this->position);
    }//L8038F7D4

    switch(this->state){
        case 1://L8038F7F8
            { // TODO: get rid of f0, maybe D_80392914 is static?
                f32 temp_f0;
                
                temp_f0 = this->scale + (f32)(sp40*1.4);
                D_80392914 = sp40*1.4;
                this->scale = (temp_f0 < 1.0) ? temp_f0 : 1.0f;
            }

            switch(this->marker->unk14_20){
                case 0x25C://L8038F8AC
                    func_8038ED9C(&this->position, 0x4a0, 1, 
                        &D_80391CEC, &D_80391D34, 
                        &D_80391CF4, &D_80391D04, &D_80391D14
                    );
                    break;
                case 0x280://L8038F8C8
                    func_8038ED9C(&this->position, 0x6c9, 1, 
                        &D_80391CEC, &D_80391D34, 
                        &D_80391CF4, &D_80391D1C, &D_80391D2C
                    );
                    func_8023DB5C();
                    break;
            }//L8038F918
            D_803928F8[0] = this->position_x;
            D_803928F8[1] = this->position_y;
            D_803928F8[2] = this->position_z;

            this->position_x +=  this->velocity_x*sp40;
            this->position_y +=  this->velocity_y*sp40;
            this->position_z +=  this->velocity_z*sp40;

            this->velocity_x += this->unk1C[0]*sp40;
            this->velocity_y += this->unk1C[1]*sp40;
            this->velocity_z += this->unk1C[2]*sp40;

            this->pitch +=  200.0f*sp40;
            this->yaw += 200.0f*sp40;

            if( this->position_y < -2500.0f 
                || 5000.0f < this->position_y
                || !func_8038F5BC(&this->position, 10.0f)
            ){
                marker_despawn(this->marker);
            }
            else{
                if(this->position_y < 300.0f
                    && func_8038F5BC(&this->position, 16000000.0f)
                ){
                    if(func_80320C94(&D_803928F8, &this->position, func_8033229C(this->marker), &D_80392908, 8, 2.0f)){
                        func_8038F084(this->marker);
                        break;
                    }
                }
            }
            // L8038FABC
            if( this->marker->unk14_20 != 0x280
                && func_8028F25C()
            ){
                func_8038F084(this->marker);
            }
            else {
                if(0.0 <= this->unk60){
                    this->unk60 -= sp40;
                }else{
                    func_8038F084(this->marker);
                }
            }
            break;
        case 2://L8038FB34
            if(local->unk0 < 0.0){
                marker_despawn(this->marker);
            }else{
                local->unk0 -= sp40;
            }
            break;
    }//L8038FB74
}
#endif

void func_8038FB84(ActorMarker *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    Actor *temp_v0 = marker_getActor(arg0);

    temp_v0->position_x = arg1[0];
    temp_v0->position_y = arg1[1];
    temp_v0->position_z = arg1[2];
    temp_v0->velocity_x = arg2[0];
    temp_v0->velocity_y = arg2[1];
    temp_v0->velocity_z = arg2[2];
    temp_v0->unk1C_x = arg3[0];
    temp_v0->unk1C_y = arg3[1];
    temp_v0->unk1C_z = arg3[2];
}

void func_8038FC00(void) {
    D_803928E0 = (u8)0;
    D_803928E1 = (u8)0;
    D_803928E2 = (u8)0;
    D_803928E3 = (u8)0;
    D_803928E4 = (u8)0;
}

void func_8038FC2C(s32 arg0) {
    D_803928E5 = arg0;
}
