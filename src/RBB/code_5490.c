#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80335A24(void *, s32, f32, f32);
extern f32 func_80335684(void *);
extern s32 func_802EDD8C(f32 (*)[3], f32, f32);

void func_8038B900(Actor *this);

/* .data */
ActorInfo D_80390AB0 = {
    0x30, 0x1C8, 0x41C, 0x0, NULL,
    NULL, func_8038B900, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038B880(Actor *this, s32 new_state){
    if(new_state == 1)
        func_80335924(this->unk148, 0x13f, 0.0f, 5.5f);

    if(new_state == 2)
        func_80335A24(this->unk148, 0x13e, 1.0f, 0.65f);

    this->state = new_state;
}

void func_8038B900(Actor *this){
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp48[3];
    struct30s *other;

    this->marker->propPtr->unk8_3 = 1;
    if(this->marker->unk14_21){
        sp54 = func_80335684(this->unk148);
        if( ( func_8023DB5C() & (1 << 4) )
            && ( func_8023DB5C() & (1 << 2) )
            && ( randf() < 0.90 )
        ){
            if( ( this->state == 3 
                  && (0.255 <= sp54 && sp54 <= 0.856) 
                )
                || ( this->state == 1
                     && ( (0.053 <= sp54 && sp54 <= 0.35)
                          || (0.39 <= sp54 && sp54 <= 0.44999999999999996)
                          || (0.45999999999999996 <= sp54 && sp54 <= 0.52)
                          || (0.54 <= sp54 && sp54 <= 0.73)
                          || (0.76 <= sp54 && sp54 <= 0.8200000000000001)
                          || (0.84 <= sp54 && sp54 <= 0.9)
                          || (0.94 <= sp54 && sp54 <= 1.0)
                     )
                )
            ){//L8038BB24
                func_8034A174(this->marker->unk44, 5, &sp48);
                other = func_802EDD8C(&sp48, 0.0f, -1300.0f);
                func_802EFB70(other, 0.04f, 0.04f);
                func_802EFB84(other, 0.18f, 0.18f);
                func_802EFB1C(other, -10.0f, 0.0f, -10.0f, 10.0f, 20.0f, 10.0f);
                func_802EFED4(other, 0.0f, 31.0f, 0.0f, 0.0f, 37.0f, 0.0f);
                func_802EF5C8(other, 1);
            }
        }
    }////L8038BBFC

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->position_x = -5100.0f;
        this->position_y = -2600.0f;
        this->position_z = 1460.0f;
        this->yaw = 0.0f;
        func_8038B880(this, 1);
        if(jiggyscore_80320F7C(JIGGY_RBB_SNORKEL)){
            marker_despawn(this->marker);
        }
    }
    else{//L8038BC74
        func_8033568C(this->unk148, &sp5C, &sp58);
        if( sp5C < 0.22 && 0.22 <= sp58 ){
            func_8030E988(0xd1, randf2(0.8f, 0.9f), 0x3a98, &this->position, 1500.0f, 2000.0f);
        }

        if( sp5C < 0.54 && 0.54 <= sp58 ){
            func_8030E988(0xd1, randf2(0.9f, 1.0f), 0x4a38, &this->position, 1500.0f, 2000.0f);
        }

        if(this->state == 1){
            if( !this->unk138_24
                && func_80329530(this, 0x258)
                && !func_8028ECAC()
            ){
                func_80311480(0xb9b, 4, 0, 0, 0, 0);
                this->unk138_24 = 1;
            }
        }

        if(this->state == 1){
            if(mapSpecificFlags_get(4))
                func_8038B880(this, 2);
        }

        if(this->state == 2){
            if(jiggyscore_80320F7C(JIGGY_RBB_SNORKEL))
                func_8038B880(this, 3);
        }

        if(this->state == 3){
            func_80326224(this);
            if(0.99 < this->unk48){   
                mapSpecificFlags_set(4, FALSE);
                marker_despawn(this->marker);
            }
        }
    }//L8038BE90
}