#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct map_savestate_s{
    u32 flags;
}MapSavestate;

/* .bss */
MapSavestate *D_8037E650[0x9A];
u8 pad_8037E8A8[0x18];

/* public functions */
void func_802E3BD0(s32 frame_buffer_indx);
int func_802E49F0(void);

/* .code */
void func_802E2E40(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        D_8037E650[i] = 0;
    }
}

void mapSavestate_free_all(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            free(D_8037E650[i]);
            D_8037E650[i] = NULL;
        }
    }
}

void mapSavestate_defrag_all(void){
    int i;
    for(i = 0; i < 0x9A; i++){
        if(D_8037E650[i]){
            D_8037E650[i] = defrag(D_8037E650[i]);
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/mapSavestate_save.s")
#else
void mapSavestate_save(enum map_e map){
    u32 wSize;
    volatile u32 * sp38;
    s32 iBit;
    s32 bit_max;
    s32 reg_s4;
    u32* reg_v1;
    u32* valPtr;

      
    wSize = 4;
    if(D_8037E650[map])
        free(D_8037E650[map]);
      
    D_8037E650[map] = (MapSavestate *) malloc(4*sizeof(u32));
    sp38 =   D_8037E650[map];

    *sp38 = mapSpecificFlags_getAll();
    
    iBit = 0x20;
    func_80308230(1, D_8037E650[map]);
    func_803083B0(-1);
    
    for(reg_s4 = func_803083B0(-2); reg_s4 != -1; reg_s4 = func_803083B0(-2, valPtr)){
        if( !(iBit < wSize*sizeof(u32)*8)){
            wSize += 4;
             D_8037E650[map] = (MapSavestate *)realloc( D_8037E650[map], wSize*sizeof(u32));
            reg_v1 = ((s32)D_8037E650[map] + wSize*sizeof(u32));
            reg_v1[-1] = 0;
            reg_v1[-2] = 0;
            reg_v1[-3] = 0;
            reg_v1[-4] = 0;
        }
        valPtr =  D_8037E650[map];
        valPtr[(iBit >> 5)] = (reg_s4)
            ? valPtr[(iBit >> 5)] | (1 << (iBit & 0x1f))
            : valPtr[(iBit >> 5)] & ~(1 << (iBit & 0x1f));
        
        iBit++;
        
    }
    //if(sp38);
     D_8037E650[map] = actors_appendToSavestate( D_8037E650[map],  (s32)D_8037E650[map] + 16*((iBit + 0x7F) >> 7));   
}  
#endif

//mapSavestate_apply
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5BEB0/mapSavestate_apply.s")
// void mapSavestate_apply(enum map_e map){
//     u32 **mssp = D_8037E650 + map;
//     int s0;
//     int val;
//     u8 *tmp;
//     if(*mssp){
//         mapSpecificFlags_setAll(**mssp);
//         func_80308230(1);
//         func_803083B0(-1);
//         for(s0 = 0x20; func_803083B0((((*mssp)[s0 >> 5]) & (1 << (s0 & 0x1f)))? 1 : 0) != -1; s0++);
//         func_80308230(0);
//         tmp = *mssp;
//         func_8032A09C(tmp, (tmp + 0x10*((s0 + 0x7f) >> 7)));
//         free(*mssp);
//         *mssp = NULL;
//     }
// }
