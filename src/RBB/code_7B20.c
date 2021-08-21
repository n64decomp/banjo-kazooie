#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    f32 unk0;
    ActorMarker *unk4;
    f32 unk8[3];
    f32 unk14[3];
    s32 unk20;
    f32 unk24[3];
}ActorLocal_7B20;

void func_8038DF6C(Actor* this);


/* .data */
ActorInfo D_80390D20 = {
    0x1AA, 0x296, 0x43B, 0x0, NULL,
    func_8038DF6C, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};


/*.code */
void func_8038DF10(Actor *this, int arg1){
    if(arg1 == 1){
        func_80335924(this->unk148, 0x16a, 0, 1.2f);
    }
    this->state = arg1;
}

void func_8038DF6C(Actor* this){
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp6C;
    f32 sp68 = func_8033DD9C();
    f32 sp5C[3];
    f32 sp58;
    ActorLocal_7B20 *local = (ActorLocal_7B20 *)&this->local;
    Actor* other;
    int i;
    
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = 1;
        local->unk0 = randf2(80.0f, 100.0f);
        local->unk4 = NULL;
        local->unk20 = 0;
        local->unk24[0] = 0.0f;
        local->unk24[1] = 1.0f;
        local->unk24[2] = 0.5f;
        local->unk8[0] = this->position_x;
        local->unk8[1] = this->position_y;
        local->unk8[2] = this->position_z;
        local->unk14[0] = this->pitch;
        local->unk14[1] = this->yaw;
        local->unk14[2] = this->roll;
        func_8038DF10(this, 1);
    }//L8038E050
    if(++local->unk20 == 2){
        for(i = 0x5e; i < 0x63; i++){
            
            other = func_80326D68(this->position, i, -1, &sp58);
            if(sp58 < 300.0f){
                local->unk4 = other->marker;
                other->position_x = this->position_x;
                other->position_y = this->position_y;
                other->position_z = this->position_z;
                break;
            }
        }
    }
    if(func_8025773C(&local->unk24[1], sp68)){
        local->unk24[1] = randf2(1.5f, 2.5f);
        func_8030E8B4(0xBFD38C0E, this->position, 0x05DC01F4);
    }//L8038E118

    if(func_8025773C(&local->unk24[2], sp68)){
        local->unk24[2] = randf2(3.5f, 5.5f);
        func_8030E878(0x69, randf2(1.1f, 1.2f), 0x55f0, this->position, 500.0f, 1500.0f);
    }//L8038E184

    local->unk24[0] += sp68;
    sp70[0] = 0.0f;
    sp70[1] = sinf((local->unk24[0]*local->unk0)/ 180.0 * 3.141592654) * 10.0f;
    sp70[2] = 0.0f;

    sp7C[0] = cosf((local->unk24[0]*local->unk0)/ 180.0 * 3.141592654)*7.5;
    sp7C[1] = sinf((local->unk24[0]*local->unk0)/ 180.0 * 3.141592654)*3.0;
    sp7C[2] = 0.0f;

    this->position_x = local->unk8[0] + sp70[0];
    this->position_y = local->unk8[1] + sp70[1];
    this->position_z = local->unk8[2] + sp70[2];

    sp5C[0] = local->unk14[0] + sp7C[0];
    sp5C[1] = local->unk14[1] + sp7C[1];
    sp5C[2] = local->unk14[2] + sp7C[2];

    this->pitch = sp5C[0];
    this->yaw = sp5C[1];
    this->roll = sp5C[2];

    if(local->unk4){
        other = marker_getActor(local->unk4);
        if(!(other->state < 7)){
            local->unk4 = NULL;
        }else{
            other->pitch = sp5C[0];
            other->roll = sp5C[2];
            TUPLE_ASSIGN(sp5C, 0.0f, 48.0f, 0.0f);
            ml_vec3f_pitch_rotate_copy(&sp5C, &sp5C, this->pitch);
            ml_vec3f_yaw_rotate_copy(&sp5C, &sp5C, this->yaw);
        
            other->position_x = sp5C[0] + this->position_x;
            other->position_y = sp5C[1] + this->position_y;
            other->position_z = sp5C[2] + this->position_z;
        }
    }//L8038E39C
}
