#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    f32 unk0;
    f32 unk4;
    u8 rgb[3];
    u8 unkB[3];
    u8 unkE[3];
    u8 unk11;
}D_80383170;

/* .code */
void func_8031B710(void){}

void func_8031B718(void){
    D_80383170.unk11 = 0;
    D_80383170.unk0 = D_80383170.unk4 = 0.0f;
    D_80383170.unkE[0] = D_80383170.unkE[1] = D_80383170.unkE[2] = 0xFF;
    D_80383170.unkB[0] = D_80383170.unkB[1] = D_80383170.unkB[2] = 0xFF;
    D_80383170.rgb[0] = D_80383170.rgb[1] = D_80383170.rgb[2] = 0xFF;
}

void func_8031B760(void){
    levelModel_setEnvColor(D_80383170.rgb[0], D_80383170.rgb[1], D_80383170.rgb[2]);
}

void func_8031B790(void) {
    s32 i;

    if (D_80383170.unk11 != 0) {
        D_80383170.unk0 = max_f(0.0f, D_80383170.unk0 - time_getDelta());
        for(i = 0; i < 3; i++){
            D_80383170.rgb[i] = ml_map_f(D_80383170.unk0, D_80383170.unk4, 0.0f,D_80383170.unkE[i], D_80383170.unkB[i]);
        }
        func_8031B760();
        if (D_80383170.unk0 == 0.0f) {
            D_80383170.unk11 = 0;
        }
    }
}

void func_8031B908(s32 red, s32 blue, s32 green, f32 arg3) {
    if (arg3 != 0.0f) {
        D_80383170.unk11 = 1;
        D_80383170.unk0 = arg3;
        D_80383170.unk4 = arg3;
        D_80383170.unkB[0] = red;
        D_80383170.unkB[1] = blue;
        D_80383170.unkB[2] = green;
        D_80383170.unkE[0] = D_80383170.rgb[0];
        D_80383170.unkE[1] = D_80383170.rgb[1];
        D_80383170.unkE[2] = D_80383170.rgb[2];
        return;
    }
    else{
        D_80383170.unk11 = 0;
        D_80383170.rgb[0] = red;
        D_80383170.rgb[1] = blue;
        D_80383170.rgb[2] = green;
        func_8031B760();
    }
}

void func_8031B990(s32 red, s32 blue, s32 green) {
    func_8031B908(red, blue, green, 0.0f);
}
