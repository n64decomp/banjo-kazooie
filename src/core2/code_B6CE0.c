#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct particle_struct_0_s{
    u8 pad0[0x30];
    ActorMarker *unk30;
    s32 unk34;
    u8 pad38[0xC];
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
} ParticleStruct0s;

extern ParticleStruct0s D_80384490[];
extern s32 D_80384FD0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DC9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DD04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DDB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE44.s")

void func_8033DE60(ActorMarker *);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033DEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E3F0.s")
// int func_8033E3F0(s32 particle_id, int arg1){
//     f32 sp34[3];

//     if(!arg1)
//         return -1;
    
//     clear_vec3f(sp34);
//     D_80384FD0 = func_8033E368();
//     if(D_80384FD0 < 0)
//         return -1;

    
//     D_80384490[D_80384FD0].unk45 = func_8033FA84();
//     D_80384490[D_80384FD0].unk34 = func_80287CA8();
//     D_80384490[D_80384FD0].unk46 = func_8035287C();
//     D_80384490[D_80384FD0].unk47 = func_80344CDC();
//     if( D_80384490[D_80384FD0].unk45 == 0
//         || D_80384490[D_80384FD0].unk34 == 0
//         || D_80384490[D_80384FD0].unk46 == 0
//         || D_80384490[D_80384FD0].unk47 == 0
//     ){//L8033E4DC
//         if(D_80384490[D_80384FD0].unk45){
//             func_8033FB64();
//         }
//         if(D_80384490[D_80384FD0].unk34){
//             func_80287D60();
//         }
//         if(D_80384490[D_80384FD0].unk46){
//             func_803529DC();
//         }
//         if(D_80384490[D_80384FD0].unk47){
//             func_80344D70();
//         }
//         D_80384490[D_80384FD0].unk44 = 0;
//         return -1;
//     }
//     else{ //L8033E5B4
//         D_80384490[D_80384FD0].unk30 = func_8032FBE4(sp34, func_8033DE60, 1, func_80352C7C(particle_id));
//         D_80384490[D_80384FD0].unk30->unk40_22 = 1;
//         func_8032FFEC(D_80384490[D_80384FD0].unk30, D_80384FD0);
//         D_80384490[D_80384FD0].unk30->collidable = 0;
//         func_80352A38(D_80384490[D_80384FD0].unk46, particle_id);
//         func_8033FFB8(D_80384490[D_80384FD0].unk45, func_80287FFC(D_80384490[D_80384FD0].unk34));
//         func_8033FF10(D_80384490[D_80384FD0].unk45, sp34);
//         func_8032F64C(sp34, D_80384490[D_80384FD0].unk30);
//         return D_80384FD0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E73C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033E9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033EA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033EA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B6CE0/func_8033EA78.s")
