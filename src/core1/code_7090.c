#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void sfxsource_setSampleRate(u8, s32);
extern void func_8030E2C4(u8);


typedef struct struct_27_s{
    s16 unk0;
    u8 pad2[0x12];
}struct27s;

s16 * D_802758E0 = NULL;

void func_80244C78(int arg0);

/* .code */
void func_80244AB0(void){
    int i;
    if(D_802758E0)
        return;

    D_802758E0 = (struct16s *) malloc(10*sizeof(s16));
    for(i = 0; i < 10; i++){
        D_802758E0[i] = 0;
    }
}

void func_80244B3C(void){
    int i;

    if(!D_802758E0)
        return;

    for(i = 0; i < 10; i++){
        if(D_802758E0[i])
            func_8030E394((u8)D_802758E0[i]);
    }
    free(D_802758E0);
    D_802758E0 = NULL;

}

void func_80244BB0(s32 arg0, s32 arg1, s32 arg2, f32 arg3){
    s32 i;
    u8 indx;
    if(func_8030ED70(func_80255D44(arg1))){
        i = sfxsource_createSfxsourceAndReturnIndex();
        indx = i;
        if(i){
            sfxsource_setSfxId(indx, func_80255D44(arg1));
            sfxsource_playSfxAtVolume(indx, arg3);
            sfxsource_setSampleRate(indx, arg2);
            func_8030E2C4(indx);
            func_80244C78(arg0);
            D_802758E0[arg0] = indx;
        }
    }
    else{
        func_8030E6A4(func_80255D44(arg1), arg3, arg2);
    }
}

void func_80244C78(int arg0){
    if(D_802758E0[arg0]){
        sfxsource_freeSfxsourceByIndex(D_802758E0[arg0]);
    }
    D_802758E0[arg0] = 0;
}
