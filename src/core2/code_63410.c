#include <ultra64.h>
#include "functions.h"
#include "variables.h"
typedef struct{
    s16 unk0[3];
} Struct_core2_63410_2;

typedef struct {
    Struct_core2_63410_2 *unk0;
    f32 unk4[3];
    f32 unk10[3];
} Struct_core2_63410_1;

typedef struct {
    Struct_core2_63410_1 *unk0;
    Struct_core2_63410_1 *unk4;
    Struct_core2_63410_1 *unk8;
} Struct_core2_63410_0;

/* .code */
void func_802EA3A0(Struct_core2_63410_0 *arg0){
    //clears vec
    arg0->unk4 = arg0->unk0;
}

s32 func_802EA3AC(Struct_core2_63410_0 *arg0, s32 indx, f32 arg2[3], f32 arg3[3]){
    //get elem at indx
    Struct_core2_63410_1 *phi_v1;

    phi_v1 = &arg0->unk0[indx];

    arg2[0] = phi_v1->unk4[0];
    arg2[1] = phi_v1->unk4[1];
    arg2[2] = phi_v1->unk4[2];

    arg3[0] = phi_v1->unk10[0];
    arg3[1] = phi_v1->unk10[1];
    arg3[2] = phi_v1->unk10[2];
    return phi_v1->unk0;
}

s32 func_802EA3F8(Struct_core2_63410_0 *arg0){
    //return size of vector
    return arg0->unk4 - arg0->unk0;
}

void func_802EA418(Struct_core2_63410_0 **arg0, Struct_core2_63410_2 *arg1, f32 arg2[3], f32 arg3[3]) {
    /* adds elem (arg1) to vec (arg0), resize if end_ptr == capacity_ptr */
    Struct_core2_63410_1 *phi_v1;
    Struct_core2_63410_0 *phi_s1;
    s32 sp34;
    s32 sp20;

    //check is elem already exists in vec
    phi_s1 = *arg0;
    for(phi_v1 = phi_s1->unk0; phi_v1 < phi_s1->unk4; phi_v1++){
        if   ( (phi_v1->unk0->unk0[0] == arg1->unk0[0]) 
            && (phi_v1->unk0->unk0[1] == arg1->unk0[1]) 
            && (phi_v1->unk0->unk0[2] == arg1->unk0[2])
        ){
            return;
        }
    }

    //check if vector capacity needs to increas
    if (phi_s1->unk4 == phi_s1->unk8) {
        sp34 = (phi_s1->unk8 - phi_s1->unk0);
        sp20 = sp34 * 2;
        phi_s1 = (Struct_core2_63410_0 *)realloc(phi_s1, sizeof(Struct_core2_63410_0) + (sizeof(Struct_core2_63410_1)*sp20));
        phi_s1->unk0 = (Struct_core2_63410_1 *)(phi_s1 + 1);
        phi_s1->unk4 = phi_s1->unk0 + sp34;
        phi_s1->unk8 = phi_s1->unk0 + sp20;
        (*arg0) = phi_s1;
    }

    //copy arg1, arg2, arg3 over;
    phi_s1->unk4->unk0 = arg1;
    phi_s1->unk4->unk4[0] = arg2[0];
    phi_s1->unk4->unk4[1] = arg2[1];
    phi_s1->unk4->unk4[2] = arg2[2];
    phi_s1->unk4->unk10[0] = arg3[0];
    phi_s1->unk4->unk10[1] = arg3[1];
    phi_s1->unk4->unk10[2] = arg3[2];
    phi_s1->unk4++;
}

void func_802EA5C4(Struct_core2_63410_0 *arg0){
    //free vec
    free(arg0);
}

Struct_core2_63410_0 *func_802EA5E4(void){
    //new
    Struct_core2_63410_0 *phi_v0;

    phi_v0 = (Struct_core2_63410_0 *)malloc(sizeof(Struct_core2_63410_0) + 2 * sizeof(Struct_core2_63410_1));
    phi_v0->unk0 = (Struct_core2_63410_1 *)(phi_v0 + 1);
    phi_v0->unk4 = phi_v0->unk0;
    phi_v0->unk8 = phi_v0->unk0 + 2;
    return phi_v0;
}
