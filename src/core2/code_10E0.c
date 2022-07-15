#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
    s16 unk4;
    u8 unk6;
    u8 pad7[1];
}struct10E0s;

/* .bss */
struct10E0s D_80379E20[340];

/* .code */
void func_80288070(void){
    int i;

    for(i = 0; i<340; i++){
        D_80379E20[i].unk6 = 0;
        D_80379E20[i].unk0 = 0;
        D_80379E20[i].unk4 = 0;
    }
}

void func_802880C0(void){
    int i;

    for(i = 0; i<340; i++){
        if(D_80379E20[i].unk6){
            if(D_80379E20[i].unk0){
                func_8033A6F0(D_80379E20[i].unk0);
            }
        }
    }
}

void func_80288120(void){
    int i;

    for(i = 0; i<340; i++){
        if(D_80379E20[i].unk6 == 1 && D_80379E20[i].unk0){
            if(D_80379E20[i].unk4 < 0x3b){
                func_8033A6F0(D_80379E20[i].unk0);
                D_80379E20[i].unk0 = 0;
                if(func_80254BC4(1)){
                    break;
                }
            }
        }
    }
}

void func_802881AC(void){
    int i;

    for(i = 0; i<340; i++){
        if(D_80379E20[i].unk6){
            func_803203FC(0);
            D_80379E20[i].unk4 = 0;
            func_8033A6F0(D_80379E20[i].unk0);
            D_80379E20[i].unk0 = 0;
        }
    }
}

void func_80288210(void){
    int i;

    for(i = 0; i<340; i++){
        if(D_80379E20[i].unk6 == 1 && D_80379E20[i].unk0){
            if(--D_80379E20[i].unk4 <= 0){
                func_8033A6F0(D_80379E20[i].unk0);
                D_80379E20[i].unk0 = 0;
            }
        }
    }
}

s16 func_80288298(void){
    int i;

    for(i = 0; i<340; i++){
        if(!D_80379E20[i].unk6){
            return i;
        }
    }
    return -1;
}

s16 func_80288330(void){
    int indx = func_80288298();
    D_80379E20[indx].unk6 = 1;
    D_80379E20[indx].unk4 = 0;
    D_80379E20[indx].unk0 = 0;
    return indx;
}

int func_80288374(s16 arg0){
    return (D_80379E20[arg0].unk0) ? 1 : 0; 
}

void func_802883AC(s16 arg0){
    if(D_80379E20[arg0].unk0){
        func_8033A6F0(D_80379E20[arg0].unk0);
    }
    D_80379E20[arg0].unk6 = 0;
    D_80379E20[arg0].unk0 = 0;
    D_80379E20[arg0].unk4 = 0;

}

int func_80288400(s16 arg0, s32 *arg1){
    D_80379E20[arg0].unk4 = 0x3C;
    if(D_80379E20[arg0].unk0){
        *arg1 = D_80379E20[arg0].unk0;
        return FALSE;
    }else{
        D_80379E20[arg0].unk0 = func_8033A710();
        *arg1 = D_80379E20[arg0].unk0;
        return TRUE;
    }
}

void func_80288470(void){
    int i;
    for(i = 0; i < 340; i++){
        if(D_80379E20[i].unk6 == 1 && D_80379E20[i].unk0){
            D_80379E20[i].unk0 = func_8033A9E4(D_80379E20[i].unk0);
        }
    }
}
