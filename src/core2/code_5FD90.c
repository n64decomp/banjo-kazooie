#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8 pad0[0xC];
}Struct_Core2_5FD90_s;

extern void func_80252C08(f32[3],f32[3], f32, f32[3]);
extern void func_80252CC4(f32[3],s32, f32, s32);

extern Struct_Core2_5FD90_s D_8037EAA8[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E6D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E6DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E70FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E73C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E7408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E7468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E7470.s")

int func_802E74A0(f32[3], f32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E74A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E7588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E75D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E76B0.s")


int func_802E805C(BKCollisionList *arg0, BKVertexList *vtxList, f32 arg2[3], f32 arg3[3], f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8){
    f32 sp44[3];
    f32 sp38[3];
    int sp34;
    int i;

    if(!func_802E74A0(arg2, vtxList->unk16*arg4, arg5, arg6)){
        return 0;
    }
    else{
        mlMtxIdent();
        func_80252CC4(arg2, arg3, arg4, 0);
        func_8025235C(sp44, arg5);
        func_8025235C(sp38, arg6);
        sp34 = func_802E76B0(arg0, vtxList, sp44, sp38, arg7, arg8);
        if(!sp34){
            return 0;
        }
        else{
            mlMtxIdent();
            func_80252C08(arg2, arg3, arg4, NULL);
            func_8025235C(arg6, sp38);

            mlMtxIdent();
            func_80252C08(NULL, arg3, 1.0f, 0);
            func_8025235C(arg7, arg7);

            mlMtxIdent();
            func_80252C08(arg2, arg3, arg4, 0);

            for(i = 0; i < 3; i++){
                func_8025235C(&D_8037EAA8[i], &D_8037EAA8[i]);
            }

        }
    }
    return sp34;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E81CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E879C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E8E88.s")

void func_802E9118(BKCollisionList *, BKVertexList *, f32[3], s32, f32, s32, s32, f32, s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E9118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E92AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5FD90/func_802E9DD8.s")
