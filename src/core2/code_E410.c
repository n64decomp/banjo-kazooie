#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    u32 unk0[0xE];
    u32 unk38[0xE];
    u8 unk70[0xE];
    u8 unk7E[0xE];
} D_8037C310;


/* .code */
void func_802953A0(void){
    s32 i;

    for(i = 0; i<0xe; i++){
        D_8037C310.unk0[i] = D_8037C310.unk38[i] = 0;
        D_8037C310.unk70[i] = D_8037C310.unk7E[i] = 0;
    }
}

void func_80295448(void){
    s32 i;

    D_8037C310.unk0[0] = func_8024E67C(BUTTON_START);
    func_8024E60C(0, &D_8037C310.unk0[1]);
    func_8024E6E0(0, &D_8037C310.unk0[4]);
    func_8024E55C(0, &D_8037C310.unk0[8]);
    for(i=0; i<0xE; i++){//L802954A8
        D_8037C310.unk7E[i] = D_8037C310.unk70[i];
        if(D_8037C310.unk70[i]){
            D_8037C310.unk0[i] = 0;
            if(D_8037C310.unk70[i] == 2)
                D_8037C310.unk70[i] = 0;
        }
        D_8037C310.unk38[i] = (D_8037C310.unk0[i])? 0: D_8037C310.unk38[i] + 1 ;
    }
    if(gctransition_8030BDC0()){
        func_802953A0();
    }
}


int func_8029551C(s32 button_indx){
    return D_8037C310.unk0[button_indx];
}

int func_80295530(s32 button_indx){
    return D_8037C310.unk38[button_indx];
}

int button_pressed(s32 button_indx){
    return D_8037C310.unk0[button_indx] == 1;
}

int func_80295560(s32 button_indx){
    return D_8037C310.unk38[button_indx] == 1;
}

u32 button_held(s32 button_indx){
    return D_8037C310.unk0[button_indx];
}

int button_released(s32 button_indx){
    return D_8037C310.unk38[button_indx];
}

int func_802955A4(s32 button_indx, s32 val){
    D_8037C310.unk70[button_indx] = val;
    return D_8037C310.unk7E[button_indx];
}

void func_802955BC(s32 arg0){
    s32 i;
    for(i=0; i<0xe; i++){
        func_802955A4(i, arg0);
    }
}
