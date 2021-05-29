#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_2a_s{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
} struct2As;

extern u8 D_80363590;
extern u8 D_80379B90;
extern u8 D_80286F90;
extern u8 D_803863F0;
extern u8 D_F55960;
extern u8 D_1048560;

extern  struct2As D_802762D0[];
extern int D_80282800;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_802510F0.s")

s32 func_80251170(void){return 0;}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_802511C4.s")

int get_loaded_overlay_id(void){
    return D_80282800;
}

int is_overlay_loaded(int overlay_id){
    return D_80282800 == overlay_id;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_802512FC.s")

#if NONMATCHING
void func_80251308(void){
    func_802512FC();
    func_80253050(0, &D_80286F90, &D_803863F0, &D_F55960, &D_1048560, &D_80286F90, &D_80363590, &D_80363590, &D_80379B90, &D_80379B90, &D_803863F0);
    func_802511C4();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251308.s")
#endif

void func_802513A4(void){}