#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
struct43s  D_803637A0 = {
    {{-200.0f, 200.0f}, {-200.0f, 200.0f}, {400.0f, 200.0f}},
    {{0.0f, -800.0, 0.0f}, {0.0f, -800.0f, 0.0f}},
    {{-10.0f, -10.0f, -10.0f}, {10.0f, 10.0f, 10.0f}}
};

/* .bss */
struct30s *D_8037C180;

/*.code */
void func_80292AE0(Gfx **gPtr, Mtx **mPtr, Vtx **vPtr){
    func_802EF3A8(D_8037C180, gPtr, mPtr, vPtr);
}

void func_80292B18(void){
    func_802EF684(D_8037C180);
}

void func_80292B3C(void){
    D_8037C180 = func_802EF6AC(0x14);
    func_802EFAC8(D_8037C180, 0x360);
    func_802EF9F8(D_8037C180, 0.6f);
    func_802EFA18(D_8037C180, 0);
    func_802EFB70(D_8037C180, 0.8f, 1.0f);
    func_802EFE24(D_8037C180, 400.0f, 400.0f, 400.0f, 800.0f, 800.0f, 800.0f);
    func_802EFE5C(D_8037C180, 0.0f, 0.01f);
    func_802EFEC0(D_8037C180, 1.5f, 1.5f);
    func_802EFD7C(D_8037C180, &D_803637A0);
}

void func_80292C1C(void){
    func_802EFFE4(D_8037C180);
}

void func_80292C40(f32 arg0[3]){
    func_802EFB54(D_8037C180, arg0);
    func_802EF5C8(D_8037C180, 5);
}

void func_80292C78(void){
    if(D_8037C180 != NULL){
        D_8037C180 = func_802F0D74(D_8037C180);
    }
}
