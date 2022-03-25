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
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12F30/func_80299EC0.s")
#else
void func_80299EC0(f32 arg0[3]) {
    f32 spEC[3]; //player_pos
    f32 spE0[3];
    f32 spD4[3];
    BKModelBin *spC8;
    f32 spB8[3];
    f32 spAC[3];
    f32 spA0[3];
    f32 sp7C[3][3]; //tri_vtx_colors
    s32 sp78;
    s32 i;
    f32 sp70;
    Struct60s *sp6C; //floor_vtx_list
    f32 sp48[3][3]; //tri_vtx_coord
    f32 temp_f0_2;
    f32 temp_f2_2;
    f32 temp_f2_4;
    Vtx *vtx_buffer;
    Vtx *temp_v1;
    f32 phi_f18;


    arg0[0] = 255.0f;\
    arg0[1] = 255.0f;\
    arg0[2] = 255.0f;
    if (D_8037C6F0.unk0 == 1) {
        sp78 = 50;
    } else if (!func_8028EE84()) {
        sp78 = 200;
    } else {
        sp78 = 250;
    }
    _player_getPosition(spEC);
    sp6C = func_8029463C();
    spC8 = func_802946A8();
    if (spC8 == NULL) {
        sp6C = NULL;
    }
    if ((spEC[1] - func_80294438()) > 100.0f) {
        sp6C = NULL;
    }
    if (sp6C == NULL) return;
    if (sp6C->unk6 &2) return;

    vtx_buffer = vtxList_getVertices(func_8033A148(spC8));
    for(i = 0; i<3; i++){
        temp_v1 =  vtx_buffer + sp6C->unk0[i];
        sp48[i][0] = (f32) temp_v1->v.ob[0];
        sp48[i][1] = (f32) temp_v1->v.ob[1];
        sp48[i][1] = 0.0f;
        sp48[i][2] = (f32) temp_v1->v.ob[2];

        sp7C[i][0] = (f32) temp_v1->v.cn[0];
        sp7C[i][1] = (f32) temp_v1->v.cn[1];
        sp7C[i][2] = (f32) temp_v1->v.cn[2];
    }
    // spEC[1] = 0.0f;

    spE0[0] = spEC[0] - sp48[0][0];
    spE0[1] = 0.0f;
    spE0[2] = spEC[2] - sp48[0][2];

    spAC[0] = sp48[0][0] - sp48[1][0];
    spAC[1] = 0.0f;
    spAC[2] = sp48[0][2] - sp48[1][2];

    spB8[0] = -(sp48[2][2] - sp48[1][2]);
    spB8[1] = 0.0f;
    spB8[2] = sp48[2][0] - sp48[1][0];

    phi_f18 =  (spE0[0] * spB8[0]) + (spE0[1] * spB8[1]) + (spB8[2] * spE0[2]);
    if(phi_f18 == 0.0f){
        phi_f18 = D_80374CF0;
    }

    temp_f0_2 = -((spB8[2] * spAC[2]) + ((spAC[0] * spB8[0]) + 0.0f)) / phi_f18;
    spA0[0] = (spE0[0] * temp_f0_2) + sp48[0][0];
    spA0[1] = 0.0f;
    spA0[2] = (spE0[2] * temp_f0_2) + sp48[0][2];

    spD4[0] = spA0[0] - sp48[1][0];
    spD4[1] = spA0[1] - sp48[1][1];
    spD4[2] = spA0[2] - sp48[1][2];

    temp_f2_2 = gu_sqrtf(spD4[0]*spD4[0] + spD4[1]*spD4[1] + spD4[2]*spD4[2]) / (gu_sqrtf(spB8[0] * spB8[0] + spB8[1] * spB8[1] + spB8[2] * spB8[2]) + D_80374CF8);
    for(i = 0; i < 3; i++){
        arg0[i] = sp7C[1][i] + (sp7C[2][i] - sp7C[1][i])*temp_f2_2;
    }

    spD4[0] = spA0[0] - sp48[0][0];
    spD4[1] = spA0[1] - sp48[0][1];
    spD4[2] = spA0[2] - sp48[0][2];
    temp_f2_4 = (1.0 - (gu_sqrtf(spE0[0]*spE0[0] + spE0[1]*spE0[1] + spE0[2]*spE0[2]) / (gu_sqrtf(spD4[0]*spD4[0] + spD4[1]*spD4[1] + spD4[2]*spD4[2]) + D_80374D00)));

    for(i = 0; i < 3; i++){
        arg0[i] += (sp7C[0][i] - arg0[i])*temp_f2_4;
    }

    for(i = 0; i < 3; i++){
        arg0[i] += (255.0f - arg0[i]) * (func_80294404() / 100.0f);
    }

    for(i = 0; i < 3; i++){
        if(arg0[i] > 255.0f){ arg0[i] = 255.0f; }
        if(arg0[i] < 0.0f) {  arg0[i] = 0.0f; }
    }
    arg0[0] = ((arg0[0] + arg0[1] + arg0[2]) * (f32) (0xFF - sp78)) / D_80374D08 + sp78;
    arg0[1] = arg0[0];
    arg0[2] = arg0[0];
}
#endif

void func_8029A47C(s32 arg0[3]){
    arg0[0] = (s32)(D_8037C6F0.unk4[0] + 0.5);
    arg0[1] = (s32)(D_8037C6F0.unk4[1] + 0.5);
    arg0[2] = (s32)(D_8037C6F0.unk4[2] + 0.5);
}

void func_8029A4D0(void){
    int i;
    s32 map_id = map_get();
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
