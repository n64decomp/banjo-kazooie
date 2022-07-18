#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8024A3C8(s32 x, s32 y);
void func_8024A840(s32 r, s32 g, s32 b);
void func_8024A85C(s32 buffer_indx);


extern s32 D_80276588; //framebuffer width
extern s16 D_803A5D00[2][0xF660]; //framebuffer

extern s16 D_80275BBC;


extern s16 D_80275BC4;

extern s16 D_80275BCC;
extern s16 D_80275BD0;
extern s16 D_80275BD4;

/* .bss */
s32 D_802806E0;
s32 D_802806E4;
s32 D_802806E8;
s32 D_802806EC;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024776C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802478C0.s")

void func_8024792C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802479E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247F24.s")

void func_80247F9C(s32 arg0){
    func_80247D80(D_80275BCC, arg0, 2);
    func_802484D0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80247FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024824C.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248330.s")
#else
void func_80248330(u8 *arg0){
    s32 i;
    s32 val;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    for(i = 0; arg0[i] != 0; i++){
        func_8024824C(arg0[i]);
        func_80247CEC(D_80275BCC, arg0[i], 2);
    }
    func_80248520();
}
#endif

void func_802483B8(void){
    D_80275BD0 = 1;
    do{}while(1);
}

void func_802483D8(void){
    s32 i;
    D_80275BD0 = 1;
    for(i = 30000000; i != 0; i--){}
    D_80275BD0 = 0;
}

void func_80248404(s32 arg0){
    s32 i;

    D_80275BD0 = 1;
    while(arg0 != 0){
        for(i = 30000000; i != 0; i--){}
        arg0--;
    }
    D_80275BD0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802484D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024856C.s")

s32 func_802485BC(void){
    return D_80275BD0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802485C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802485D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80248F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802499BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802499D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_802499E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249DE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_80249F34.s")

//fill framebuffer with vert and horz lines
void func_8024A284(s32 x, s32 y, s32 arg2, s32 arg3, s32 horz_spacing, s32 vert_spacing) {
    s32 var_s2;
    s32 var_s3;

    for(var_s2 = 0; var_s2 < D_80276588; var_s2 += horz_spacing){
        for(var_s3 = 0; var_s3 < D_8027658C; var_s3++){
            func_8024A3C8(x + var_s2, y + var_s3);

        }
    }
    for(var_s3 = 0; var_s3 < D_8027658C; var_s3 += vert_spacing) {
        for(var_s2 = 0; var_s2 < D_80276588; var_s2++){
            func_8024A3C8(x + var_s2, y + var_s3);
        }
    }
}

//fills in pixel in frame buffer with D_802806E0 color
void func_8024A3C8(s32 x, s32 y) {
    s32 temp_v0;

    if (x >= 0) {
        if ((x < D_80276588) && (y >= 0) && (y < D_8027658C)) {
            D_803A5D00[D_802806EC][x + y * D_80276588] = _SHIFTL(D_802806E0 >> 3, 11, 5) | _SHIFTL(D_802806E4 >> 3, 6, 5) | _SHIFTL(D_802806E8 >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        }
    }
}

//draw rectangular outline
void func_8024A490(s32 x, s32 y, s32 w, s32 h) {
    s32 var_s1;

    for(var_s1 = 0; var_s1 < w; var_s1++){
        func_8024A3C8(x + var_s1, y);
        func_8024A3C8(x + var_s1, y + h - 1);
    }
    for(var_s1 = 1; var_s1 < h - 1; var_s1++){
        func_8024A3C8(x, y + var_s1);
        func_8024A3C8(x + w - 1, y + var_s1);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_9D30/func_8024A564.s")
#else
void func_8024A564(s32 x, s32 y, u16 *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_f6;
    s32 temp_f6_2;
    s32 temp_lo;
    s32 temp_t5;
    s32 var_a0;
    s32 var_a2;
    s32 var_t1;
    s32 var_t3;
    s32 var_v0;
    s32 var_v1;
    u16 temp_t8;
    s16 *var_t0;
    s16 *var_t2;

    var_v0 = 0;
    var_v1 = D_80276588;
    var_t0 = &D_803A5D00[D_802806EC][x + y * D_80276588];
    for( var_t1 = (arg4 * arg6) + 0.5; var_t1 != 0; var_t1--){
        var_a2 = ((var_v0 >> 8) * arg3) << 8;
        var_t2 = var_t0;
        var_v0 += (s32) ((f64) (256.0f / arg6) + 0.5);
        for(var_t3 = (arg3 * arg5) + 0.5; var_t3 != 0; var_t3--){
            *var_t2 = arg2[var_a2 >> 8];
            var_a2 += (s32) ((f64) (256.0f / arg5) + 0.5);
            var_t2++;
        }
        var_t0 += D_80276588;
    }
}
#endif

//fills in rectangle in frame buffer with D_802806E0 color
void func_8024A770(s32 x, s32 y, s32 w, s32 h) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s4;

    var_s4 = 0;
    for(var_s4 = 0; var_s4 < w; var_s4++) {
        for(var_s0 = 0; var_s0 < h; var_s0++){
                func_8024A3C8(x + var_s4, y + var_s0);
            }
    }
}

void func_8024A810(void){
    func_8024A840(0, 0x80, 0);
    func_8024A85C(0);
}

void func_8024A840(s32 r, s32 g, s32 b){
    D_802806E0 = r;
    D_802806E4 = g;
    D_802806E8 = b;
}

void func_8024A85C(s32 buffer_indx){
    D_802806EC = buffer_indx;
}

s32 func_8024A868(void){
    return D_802806EC;
}
