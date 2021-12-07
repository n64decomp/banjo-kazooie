#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80294404(void);

extern s16 D_80364580[];

extern f32 D_80374CF0;
extern f64 D_80374CF8;
extern f64 D_80374D00;
extern f32 D_80374D08;

/*.bss*/
struct {
    u8 unk0;
    f32 unk4[3]; 
}
D_8037C6F0;

/*.code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12F30/func_80299EC0.s")

void func_8029A47C(s32 arg0[3]){
    arg0[0] = (s32)(D_8037C6F0.unk4[0] + 0.5);
    arg0[1] = (s32)(D_8037C6F0.unk4[1] + 0.5);
    arg0[2] = (s32)(D_8037C6F0.unk4[2] + 0.5);
}

void func_8029A4D0(void){
    int i;
    s32 map_id = func_803348C0();
    D_8037C6F0.unk0 = 0;
    D_8037C6F0.unk4[0] = 255.0f;
    D_8037C6F0.unk4[1] = 255.0f;
    D_8037C6F0.unk4[2] = 255.0f;
    for(i = 0; D_80364580[i]; i++){
        if(map_id == D_80364580[i]){
            D_8037C6F0.unk0 = 1;
            break;
        }
    }
}

void func_8029A54C(void){}

void func_8029A554(void){
    int i;
    f32 sp28[3];
    func_80299EC0(sp28);
    for(i = 0; i < 3; i++){
        if(D_8037C6F0.unk4[i] < sp28[i]){
            D_8037C6F0.unk4[i] += 40.0f;
            if(sp28[i] < D_8037C6F0.unk4[i])
                D_8037C6F0.unk4[i] = sp28[i];

        }
        else{//L8029A5C0
            D_8037C6F0.unk4[i] -= 40.0f;
            if( D_8037C6F0.unk4[i] < sp28[i])
                 D_8037C6F0.unk4[i] = sp28[i];
        }
    }
}
