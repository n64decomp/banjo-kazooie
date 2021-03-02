#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8034A754(f32, f32);


Actor *

void func_8038FD9C(Actor *this);
Actor *func_8038FD10(ActorMarker *this, Gfx** gdl, Mtx** mtx, u32 arg3);

extern f64 bgs_D_80391220;
extern f64 bgs_D_80391228;

/* .data section */
u32 D_80390DA0 = 1;
u16 D_80390DA4 = 0x0101;

ActorInfo D_80390DA8 = {0xDA, actor_leafboat, 0x30D, 0x01, NULL,
    func_8038FD9C, func_8038FD9C, func_8038FD10,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};


/* .code section */
Actor *func_8038FD10(ActorMarker *this, Gfx** gdl, Mtx** mtx, u32 arg3){
    Actor * thisActor;

    thisActor = marker_getActor(this);
    if((thisActor->unk1C != 0.0f) && (0x80 < thisActor->unk124_19)){
        thisActor = func_80325888(this, gdl, mtx, arg3);
    }
    return thisActor;
}

void func_8038FD88(ActorMarker *this, u32 arg1){
    this->unk3C_1 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/leafboat/func_8038FD9C.s")
// void func_8038FD9C(Actor *this){
//     ActorLocal_Leafboat *s1;
//     u8 tmp[5];

//     s1 = &this->leafboat;
//     if(!this->unkF4_21){
//         this->unkF4_21 = 1;
//         func_803300A8(this->marker, func_8038FD88, NULL, NULL);
//         (s1 = &this->leafboat)->unk6C = func_8034A754(80.0f, 100.0f);
//         this->unk1C = 0.0f;
//         this->unk20 = 0.0f;
//         this->unk24 = 0.0f;
//         s1->unk0 = 0.0f;
//         s1->unk4 = 0.0f;
//         s1->unk8 = 0.0f;
//         s1->unkC = 0.0f;
//         s1->unk10 = 0.0f;
//         s1->unk14 = 0.0f;
//         s1->unk18 = 0.0f;
//         s1->unk1C = 0.0f;
//         s1->unk20 = 0.0f;
//         s1->unk24 = 0.0f;
//         s1->unk28 = 0.0f;
//         s1->unk2C = 0.0f;
//         s1->unk30 = 0.0f;
//         s1->unk34 = 0.0f;
//         s1->unk38 = 0.0f;
//         s1->unk3C = 0.0f;
//         s1->unk40 = 0.0f;
//         s1->unk44 = 0.0f;
//         s1->unk48 = 0.0f;
//         s1->unk4C = 0.0f;
//         s1->unk50 = 0.0f;
//         s1->unk54 = this->position_x;
//         s1->unk58 = this->position_y;
//         s1->unk5C = this->position_z;
//         s1->unk60 = this->pitch;
//         s1->unk64 = this->yaw;
//         s1->unk68 = this->roll;
//         this->unk60 = 0.0f;
//         this->unk2C = 0.0f;
//         this->unk10_4 = 0;
//         return;
//     }

//     this->position_x = s1->unk54;
//     this->position_y = s1->unk58;
//     this->position_z = s1->unk5C;
//     this->pitch = s1->unk60;
//     this->yaw = s1->unk64;
//     this->roll = s1->unk68;
//     switch(this->unk10_31){
//         case 1:
//             if(this->marker->unk2C_2)
//                 func_80326224(this);
//             this->marker->propPtr->unk8_3 = 1;
//             this->unk1C = 1.0f;
//             this->unk124_19 = -1;
//             if(this->unk54 != 0.0f){
//                 func_80328A84(this, 2);
//             }
//             break;
//         case 2:
//             if(this->marker->unk2C_2)
//                 func_80326224(this);
//             this->marker->propPtr->unk8_3 = 1;
//             this->unk1C = 1.0f;
//             if(15.0f <= this->unk2C){
//                 func_80328A84(this, 3);
//                 this->unk2C = 0.0f;
//             }
//             else{
//                 if(tmp[((u32)this->unk2C)%6])
//                     this->unk124_19 ^= -1;
//                 //else
                    
//                 this->unk2C = this->unk2C + 1.0f;
//             }
            
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
//     }

//     s1->unk54 = this->position_x;
//     s1->unk58 = this->position_y;
//     s1->unk5C = this->position_z;
//     s1->unk60 = this->pitch;
//     s1->unk64 = this->yaw;
//     s1->unk68 = this->roll;


//     this->unk20 = 2.0*sinf
//     this->position_x += s1->unk18 + s1->unk24 + s1->unk3C;
//     this->position_y += s1->unk1C + s1->unk28 + s1->unk40;
//     this->position_z += s1->unk20 + s1->unk2C + s1->unk44;

//     s1->unk8 += (s1->unk14 - s1->unk8)/bgs_D_80391220;
//     s1->unk28 += (s1->unk34 - s1->unk28)/bgs_D_80391228;
//     this->pitch += s1->unk0 + this->unk1C + s1->unk44;
//     this->yaw += s1->unk4 + this->unk20 + s1->unk48;
//     this->roll += s1->unk8 + this->unk24 + s1->unk4C;
// }