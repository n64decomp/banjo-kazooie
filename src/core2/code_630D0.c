#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA190.s")

void func_80251BCC(Mtx*);
void func_8033A5B8(s32, s32, f32[3],f32[3], f32[3]);

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA1A8.s")
#else
void func_802EA1A8(struct58s **arg0, BKAnimationList *anim_list, s32 arg2){
    struct58s * s2;
    Mtx *s4;
    Mtx *s6;
    int i;
    Mtx *s1;
    BKAnimation *s0;
    s32 pad94;
    f32 sp88[3];
    f32 pad80[2];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 pad58[1];
    s32 v0;

    s2 = (*arg0);

    if(s2->capacity_44 < anim_list->cnt_4){
        s2 = (struct58s *)realloc(s2, anim_list->cnt_4*sizeof(Mtx) + sizeof(struct58s));
        s2->capacity_44 = anim_list->cnt_4;
        *arg0 = s2;
    }

    s6 = s2->data + anim_list->cnt_4;
    s4 = s2->data;
    s2->size_40 = anim_list->cnt_4;
    s0 = anim_list->anim;
    
    for(s1 = s4; s1 < s6; s1++){
        func_8033A5B8(arg2, s0->unkC, sp74, sp68, sp5C);
        pad94 = s1 - s4;
        if(s0->unkE == -1){
            mlMtxIdent();
        }
        else{
            if(pad94 != s0->unkE + 1){
                func_80251BCC(s4 + s0->unkE);
            }
        }//L802EA2A0
        
        mlMtxTranslate(s0->unk0[0] + sp5C[0]*anim_list->unk0, s0->unk0[1] + sp5C[1]*anim_list->unk0, s0->unk0[2] + sp5C[2]*anim_list->unk0);
        if(func_80345434(sp74) == 0){
            func_80345274(sp74, sp88);
            func_802515D4(sp88);
        }

        mlMtxScale_xyz(sp68[0], sp68[1], sp68[2]);
        mlMtxTranslate(-s0->unk0[0], -s0->unk0[1], -s0->unk0[2]);
        func_802513B0(s1);
        //s1++;
        s0++;
    }//L802EA344
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_630D0/func_802EA374.s")
