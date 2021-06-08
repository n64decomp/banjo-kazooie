#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern s32 D_803820B8;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80301F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80301F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80302634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80302C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803035F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030364C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803036A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F6C.s")

extern s32 D_80382148;

void func_80303D78(s32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F7C.s")
// s32 func_80303F7C(s32 arg0, f32 arg1, s32 arg2, s32 arg3) {
//     s32 temp_v1;

//     if (arg3 == 0) {
//         func_80303D78(arg0, arg1);
//         D_80382148 = 0;
//         return 0;
//     }
//     temp_v1 = *(&D_803820B8 + D_80382148);
//     if (temp_v1 != 0) {
//         D_80382148++;
//     }
//     return temp_v1;
// }

s32 func_80303FE4(s32 arg0, f32 arg1) {
    func_80303D78(arg0, arg1);
    return D_803820B8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803040EC.s")

void func_803045CC(s32 arg0, s32 arg1){}

void func_803045D8(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803045E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803046A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803048E0.s")

s32 func_80304984(s32 arg0, u32 *arg1) {
    u16 *temp_v0;

    temp_v0 = func_803049CC(arg0, 0);
    if (temp_v0 != 0) {
        *arg1 = (u32) ((u32) temp_v0[3] >> 7);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803049CC.s")

Actor *func_80304C38(s32 arg0, Actor *arg1){
    s32 vec[3];
    s32 *phi_a1;

    if (arg1 != 0) {
        vec[0] = arg1->position_x;
        vec[1] = arg1->position_y;
        vec[2] = arg1->position_z;
    }
    if (arg1 == 0) {
        phi_a1 = NULL;
    } else {
        phi_a1 = vec;
    }
    return func_803049CC(arg0, phi_a1);
}

void func_80304CAC(s32 arg0, f32 *arg1) {
    s32 vec[3];

    vec[0] = arg1[0];
    vec[1] = arg1[1];
    vec[2] = arg1[2];
    func_803049CC(arg0, vec);
}

void func_80304D04(s32 arg0, s16 *arg1) {
    s32 arr[3];

    arr[0] = arg1[0];
    arr[1] = arg1[1];
    arr[2] = arg1[2];
    func_803049CC(arg0, arr);
}

u32 func_80304D3C(u16 *arg0) {
    return (u32)arg0[3] >> 7;
}

void func_80304D4C(s16 *arg0, s32 *arg1) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

void func_80304D68(s16 *arg0, f32 *arg1) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

u32 func_80304DA8(u32 *arg0) {
    return arg0[3] >> 0x17;
}

s32 func_80304DB8(u32 *arg0) {
    return arg0[3] & 0x7FFFFF;
}

s32 func_80304DD0(s32 arg0, s32 *arg1) {
    s16 *temp_v0;

    temp_v0 = func_803049CC(arg0, 0, arg1);
    if (temp_v0 != 0) {
        arg1[0] = (s32) temp_v0[0];
        arg1[1] = (s32) temp_v0[1];
        arg1[2] = (s32) temp_v0[2];
        return 1;
    }
    return 0;
}

s32 func_80304E24(s32 arg0, f32 *arg1) {
    s32 vec[3];

    if (func_80304DD0(arg0, vec) == 0) {
        return 0;
    }
    arg1[0] = vec[0];
    arg1[1] = vec[1];
    arg1[2] = vec[2];
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030508C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030515C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030526C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305344.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030538C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803053B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803053E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803054A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803055E0.s")

extern s32 D_8036A9B0;
extern ActorSpawn *D_8036A9B4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803056FC.s")
// Actor *func_803056FC(s32 arg0, f32 *arg1, f32 *arg2) {
//     s32 phi_a3;
//     s32 i;
//     ActorSpawn *cur;
//     ActorSpawn *next;
//     ActorInfo *tmp;

//     if (func_80320248() == 0) {
//         arg0 = ch_id_bigbutt;
//     }
//     for(i=0; i < D_8036A9B0; i++){
//         if(arg0 == D_8036A9B4[i].infoPtr->actorId)
//             return D_8036A9B4[i].spawnFunc(arg1, arg2, D_8036A9B4[i].infoPtr, D_8036A9B4[i].unk8);
//     }
//     return NULL;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030578C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803058C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803062D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803063A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803063C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803063D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030644C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803064C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803065E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030688C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803073CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803077FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803080C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803082D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803083B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803084F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803086B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803088C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030895C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803091D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803097A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803097AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A4B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A5EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030AA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030ABA4.s")
