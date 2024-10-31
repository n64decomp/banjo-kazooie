#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void baeyes_blinkSingleEye(s32, f32);

typedef struct {
    f32 unk0;
    u8  unk4;
    //u8 pad5[3];
    f32 unk8;
} Struct_core2_7060_0;

/* .data */
Struct_core2_7060_0 D_803636D0[] = {
    {2.0f,   1, 0.1f},
    {0.034f, 0, 0.1f},
    {5.0f,   1, 0.06f},
    {0.034f, 0, 0.06f},
    {0.2f,   1, 0.09f},
    {0.034f, 0, 0.09f},
    {1.0f,   1, 0.1f},
    {0.034f, 0, 0.1f},
    {5.0f,   1, 0.1f},
    {0.034f, 0, 0.1f},
    {1.0f,   4, 0.0f}
};
Struct_core2_7060_0 D_80363754[] = {
    {0.0f,   1, 0.1f},
    {0.034f, 0, 0.1f},
    {0.0f,   4, 0.0f}
};

/* .bss */
struct{
    Struct_core2_7060_0 *unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
} D_8037C000;

/* .code */
void func_80290070(void){
    D_8037C000.unk0 = NULL;
    D_8037C000.unk9 = FALSE;
    D_8037C000.unk8 = 0;
    D_8037C000.unk4 = 0.0f;
}

void func_80290090(Struct_core2_7060_0 *arg0){
    D_8037C000.unk0 = arg0;
    D_8037C000.unk9 = TRUE;
    D_8037C000.unk8 = 0;
    D_8037C000.unk4 = arg0->unk0;
}

void func_802900B4(void){
    func_80290090(D_803636D0);
}

void func_802900D8(void){
    func_80290090(D_80363754);
}

void func_802900FC(void){
    D_8037C000.unk9 = FALSE;
}

void func_80290108(void) {
    f32 phi_f20;
    Struct_core2_7060_0 *phi_s0;

    if (D_8037C000.unk9){
        phi_f20 = time_getDelta();
        while(phi_f20 > 0.0f){
            D_8037C000.unk4 -= phi_f20;
            if(D_8037C000.unk4 > 0.0f)
                break;

            phi_f20 = mlAbsF(D_8037C000.unk4);
            phi_s0 = &D_8037C000.unk0[D_8037C000.unk8];
            baeyes_blinkSingleEye(phi_s0->unk4, phi_s0->unk8);
            phi_s0++;
            if (phi_s0->unk4 == 4) {
                if (phi_s0->unk0 == 0.0f) {
                    D_8037C000.unk9 = FALSE;
                    return;
                }
                phi_s0 = D_8037C000.unk0;
                D_8037C000.unk8 = 0;
            }
            else{
                D_8037C000.unk8++;
            }
            D_8037C000.unk4 = phi_s0->unk0;
        }
    }
}
