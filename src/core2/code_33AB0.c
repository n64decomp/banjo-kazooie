#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    f32 unk0[3];
    f32 unkC[3];
} Struct_core2_33AB0_0;

void func_802BAAD4(Struct_core2_33AB0_0 *this, f32 src[3]);
void func_802BAB1C(Struct_core2_33AB0_0 *this, f32 src[3]);

/* .code */
Struct_core2_33AB0_0 *func_802BAA40(void){
    Struct_core2_33AB0_0 *this;
    f32 sp18[3];

    this = (Struct_core2_33AB0_0 *)malloc(sizeof(Struct_core2_33AB0_0));
    ml_vec3f_clear(sp18);
    func_802BAAD4(this, sp18);
    func_802BAB1C(this, sp18);
    return this;
}

void func_802BAA88(Struct_core2_33AB0_0 *this){
    free(this);
}

void func_802BAAA8(Struct_core2_33AB0_0 *this, f32 dst[3]){\
    ml_vec3f_copy(dst, this->unk0);
}

void func_802BAAD4(Struct_core2_33AB0_0 *this, f32 src[3]){
    ml_vec3f_copy(this->unk0, src);
}

void func_802BAAF4(Struct_core2_33AB0_0 *this, f32 dst[3]){\
    ml_vec3f_copy(dst, this->unkC);
}

void func_802BAB1C(Struct_core2_33AB0_0 *this, f32 src[3]){
    ml_vec3f_copy(this->unkC, src);
}

void func_802BAB3C(Struct61s *file_ptr, Struct_core2_33AB0_0 *arg1){
    while(!func_8034AF98(file_ptr, 0)){
        if(!func_8034B108(file_ptr, 1, arg1->unk0, 3)){
            func_8034B108(file_ptr, 2, arg1->unkC, 3);
        }//L802BAA0C
    }
}
