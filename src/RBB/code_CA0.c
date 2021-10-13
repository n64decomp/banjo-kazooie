#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* typedefs and declarations */
void func_803878B0(Actor *this);
void func_8038756C(Actor *this, s32 arg1);

/* .data */
ActorInfo D_80390200 = {
    0x183, 0x173, 0x402, 0x0, NULL,
    func_803878B0, NULL, func_80325340,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

s32 D_80390224[4] = { 0xff, 0, 0, 0xff};
s32 D_80390234[4] = { 0x76, 0, 0, 0xff};
s32 D_80390244[4] = { 0x76, 0, 0, 0xff};
s32 D_80390254[4] = { 0xff, 0, 0, 0xff};

f32 D_80390264[3] = {-4900.0f, 0.0f, 0.0f};

/* .code */
void func_80387090(ActorMarker *marker, s32 arg1){
    func_8038756C(marker_getActor(marker), arg1);
}

void func_803870BC(s32 arg0, s32 arg1){
    s32 temp_v0;

    if(temp_v0 = func_8034C528(arg0))
        func_8034DFB0(temp_v0, &D_80390224, &D_80390234, (f64)arg1/1000.0);
}

void func_8038711C(s32 arg0, s32 arg1){
    s32 temp_v0;

    func_8030E6D4(0x90);
    if(temp_v0 = func_8034C528(arg0))
        func_8034DFB0(temp_v0, &D_80390244, &D_80390254, (f64)arg1/1000.0);
}

void func_8038718C(ActorMarker *marker){
    void *sp44;
    f32 sp38[3];
    f32 sp2C[3];

    if(sp44 = func_8034C528(0x19a)){
        sp38[0] = sp38[1] = sp38[2] = 0.0f;
        sp2C[0] = 0.0f;
        sp2C[2] = 0.0f;
        sp2C[1] = 450.0f;
        func_8034DDF0(sp44, &sp38, &sp2C, 4.0f, 1);
        func_8034E1A4(sp44, 0xd8, 1.0f, 1.0f);
    }
    func_80324E60(0.0f, 4);
    func_80324E60(2.5f, 5);
    func_80324C88(4.0f, 0x7f, 0.5f, 0x4a38);
    func_80324C88(4.0f, 0x7f, 0.6f, 0x4a38);
    func_80324C88(4.0f, 0x7f, 0.7f, 0x4a38);
    func_80324C88(4.0f, 0x7f, 0.8f, 0x4a38);
    func_80324C88(4.0f, 0x7f, 0.9f, 0x4a38);
    func_80324C88(4.0f, 0x7f, 1.0f, 0x4a38);\
    func_80324E88(5.0f);
    func_80324E38(5.0f, 0);
    timedFunc_set_2(5.0f, (TFQM2) func_80387090, (s32) marker, 3);
}

void func_80387308(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    void *sp40;
    f32 sp34[3];
    f32 sp28[3];

    if(sp40 = func_8034C528(0x19a)){
        TUPLE_ASSIGN(sp34, 0.0f,200.0f,0.0f);
        TUPLE_ASSIGN(sp28, 0.0f, 0.0f, 0.0f);
        func_8034DDF0(sp40, &sp34, &sp28, 0.5f, 1);
        func_8034E1A4(sp40, 0xd8, 1.0f, 1.0f);
    }//L80387394

    func_80324C88(0.5f, 0x7f, 0.5f, 0x4a38);
    func_80324C88(0.5f, 0x7f, 0.6f, 0x4a38);
    func_80324C88(0.5f, 0x7f, 0.7f, 0x4a38);
    func_80324C88(0.5f, 0x7f, 0.8f, 0x4a38);
    func_80324C88(0.5f, 0x7f, 0.9f, 0x4a38);
    func_80324C88(0.5f, 0x7f, 1.0f, 0x4a38);
    timedFunc_set_2(0.5f, (TFQM2) func_80387090, (s32) actor->marker, 1);
    
    timedFunc_set_2(1.5f, (TFQM2) func_803870BC, 0x19d, 0x1f4);
    func_80324E88(1.5f);
    func_80324E38(1.5f, 0);

}

void func_80387488(ActorMarker *marker){
    f32 sp1C[3];
    Actor *actor = marker_getActor(marker);

    player_getPosition(&sp1C);
    if(-50.0f < sp1C[1] && sp1C[1] < 600.0f){
        sp1C[1] = 0;
        if(func_80256064(&sp1C, &D_80390264) < 500.0f){
            timedFunc_set_1(1.0f, (TFQM1) func_80387488, (s32)actor->marker);
            return;
        }
    }
    func_80324E38(0.0f, 3);
    func_80324E60(0.0f, 6);
    timedFunc_set_1(0.5f, (TFQM1) func_80387308, (s32) actor->marker);
}

void func_8038756C(Actor *this, s32 arg1){
    f32 sp6C[3];
    f32 sp60[3];
    void * temp_v0;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;
    void * sp3C;
    f32 sp30[3];
    f32 sp24[3];
    
    if(arg1 == 1){
        if(this->state != 0){
            sp6C[0] = 0.0f;
            sp6C[1] = 0.0f;
            sp6C[2] = -40.0f;
            sp60[0] = sp60[1] = sp60[2] = 0.0f;
            
            if(temp_v0 = func_8034C528(0x19C))
                func_8034DDF0(temp_v0, &sp6C, &sp60, 0.1f, 1);
            
            if(temp_v0 = func_8034C528(0x19D))
                func_8034DDF0(temp_v0, &sp6C, &sp60, 0.1f, 1);
        }
    }//L80387610

    if(arg1 == 2){
        sp50[0] = sp50[1] = sp50[2] = 0.0f;
        sp44[0] =  0.0f;
        sp44[1] = 0.0f;
        sp44[2] = -40.0f;
        
        if(temp_v0 = func_8034C528(0x19C))
            func_8034DDF0(temp_v0, &sp50, &sp44, 0.1f, 1);
        
        if(temp_v0 = func_8034C528(0x19D))
            func_8034DDF0(temp_v0, &sp50, &sp44, 0.1f, 1);
        
        timedFunc_set_2(0.1f, func_8038711C, 0x19d, 0x1f4);
        timedFunc_set_2(0.1f, func_8025A6EC, COMUSIC_2B_DING_B, 28000);
        func_80324E38(0.2f, 3);
        timedFunc_set_1(1.1f, func_8038718C, this->marker);
    }//L80387704

    if(arg1 == 3){
        func_80346414(6, 1);
        func_80346414(0, 0x3bf);
    }

    if(this->state == 3){
        func_80346414(6, 0);
    }

    if(arg1 == 4){
        sp3C = func_8034C528(0x19a);
        if(sp3C){
            sp30[0] = 0.0f;
            sp30[1] = 450.0f;
            sp30[2] = 0.0f;
            sp24[0] = 0.0f;
            sp24[1] = 200.0f;
            sp24[2] = 0.0f;
            
            
            func_8034DDF0(sp3C, &sp30, &sp24, 3.0f, 1);
            func_8034E1A4(sp3C, 0xd8, 1.0f, 1.0f);
        }//L803877D4
        func_80324C88(3.0f, 0x7f, 0.5f, 0x61a8);
        func_80324C88(3.0f, 0x7f, 0.6f, 0x61a8);
        timedFunc_set_1(4.0f, func_80387488, this->marker);
    }//L80387828

    this->state = arg1;
}

void func_80387850(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1){
        func_8038756C(actor, 2);
    }
}

void func_80387890(Actor *this){
    func_8038756C(this, 0);
}

void func_803878B0(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->marker->unk30 = func_80387890;
        func_803300A8(this->marker, 0, func_80387850, 0);
        func_8032AA58(this, 1.1f);
        func_8038756C(this, 1);
    }

    if(this->state == 3){
        if(item_empty(0)){
            func_8038756C(this, 4);
        }
    }
}
