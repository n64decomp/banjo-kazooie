#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 unk0;
    u8 pad2[0x2];
    s32 unk4;
    s32 unk8;
    u8 padC[0x8];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 pad2C[0x4];
    f32 unk30;
} struct41FB0s;

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8[3];
    f32 unk14[3];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
} struct41FB0s_1;

/* .data */
extern struct41FB0s D_80366460[];
extern f32 D_80366C4C;

/* .rodata */
extern f64 D_80376410;

/* .bss */
UNK_TYPE(s32) D_8037DDB0;
f32 D_8037DDB4;
f32 D_8037DDB8;


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C8F40.s")

void func_802C8F68(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C8F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C8F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C8F88.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C8FE4.s")
#else
Actor *func_802C8FE4(s32 arg0, f32 position[3], Actor *arg2){
    struct41FB0s * sp74; //s2
    Actor *actor; //s3
    s32 i;
    struct41FB0s_1 *s0;

    sp74 = D_80366460 + arg0;
    actor = NULL;
    for(i = 0; i < sp74->unk8; i++){//L802C90B0
        for( D_8037DDB4 = D_8037DDB4 + 360.0/sp74->unk8; 360.0 <= D_8037DDB4; D_8037DDB4 -= 360.0);
        //L802C9114
        actor =(i == 0 && arg2) ? arg2 : func_8032813C(sp74->unk4, position, 0);
        actor->unk10_0 = 1;
        s0 = (struct41FB0s_1 *) &actor->unkBC;
        s0->unk0 = arg0; 
        s0->unk2F = 1;
        s0->unk6 = 1;
        ml_vec3f_copy(s0->unk8, actor->position);
        ml_vec3f_copy(actor->position, s0->unk8);
        if(D_8037DDB8 != 1.0f){
            s0->unk14[0] = sp74->unk14*D_8037DDB8;
            s0->unk14[1] = sp74->unk1C + randf2(0.0f, sp74->unk20);
            s0->unk14[2] = sp74->unk24*D_8037DDB8;
            D_8037DDB8 = 1.0f;
        }
        else{//L802C91CC
            s0->unk14[0] = sp74->unk14 + randf2(0.0f, sp74->unk18);
            s0->unk14[1] = sp74->unk1C + randf2(0.0f, sp74->unk20);
            s0->unk14[2] = sp74->unk24 + randf2(0.0f, sp74->unk28);

        }//L802C9210
        ml_vec3f_yaw_rotate_copy(s0->unk14, s0->unk14, D_8037DDB4);
        s0->unk24 = -1.0f * D_80366C4C;
        D_80366C4C = s0->unk24;
        actor->unk5C = s0->unk20 = (sp74->unk0 & 0x20) ? sp74->unk30 : randf2(0.0f, 360.0f);
        s0->unk28 = 0.0f;
        s0->unk2C = 0;
        s0->unk2D = 1;
        s0->unk4 = sp74->unk0;
        s0->unk2E = (sp74->unk0 & 0x1) ? ((0.5 < randf()) ? 1 : 0) : 0 ;
        if(sp74->unk0 & 0x200){
            actor->unk5C = s0->unk8[1];
        }
    }//L802C92E8
    return actor;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C9334.s")

Actor *func_802C937C(s32 arg0, f32 position[3]){
    return func_802C8FE4(arg0, position, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C939C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C96E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C9C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41FB0/func_802C9C14.s")
