#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u16 D_803A5D00[2][0xF660]; //framebuffer
extern s32 framebuffer_width; //framebuffer width
extern s32 framebuffer_height; //framebuffer height

/* .data */
u8 D_80275A50[8][3] = {
    {0xFF, 0x00, 0x00},
    {0x00, 0xFF, 0x00},
    {0x00, 0x00, 0xFF},
    {0xFF, 0xFF, 0x00},
    {0xFF, 0x00, 0xFF},
    {0xFF, 0xFF, 0xFF},
    {0xFF, 0x80, 0x00},
    {0x00, 0xFF, 0xFF}
};
s32 D_80275A68 = 0xFF;
s32 D_80275A6C = 0xFF;
s32 D_80275A70 = 0xFF;
u8  D_80275A74[] = {1, 7, 3, 4, 0, 6, 5, 0};
u32 D_80275A7C[] = {
    3, 0x0F6DE000,
    1, 0x0F800000,
    3, 0x0C4AE000,
    3, 0x0E59E000, 
    4, 0x088AF200,
    3, 0x0F39E000, 
    3, 0x0F3DE000,
    3, 0x0E4A4000, 
    3, 0x0F7DE000,
    3, 0x0F79E000, 
    3, 0x0F6FA000,
    3, 0x0D75C000, 
    3, 0x0F24E000,
    3, 0x0D6DC000, 
    3, 0x0F34E000,
    3, 0x0F348000, 
    3, 0x0F25E000,
    3, 0x0B7DA000, 
    3, 0x0E92E000,
    3, 0x0E928000, 
    3, 0x0B75A000,
    3, 0x0924E000, 
    5, 0x08EEB188,
    4, 0x09DFB900, 
    4, 0x06999600,
    3, 0x0F7C8000, 
    4, 0x069DB700,
    3, 0x0F7EA000, 
    3, 0x0F39E000,
    3, 0x0E924000, 
    4, 0x09999600,
    5, 0x08C62A20, 
    5, 0x08C63550,
    3, 0x0B55A000, 
    3, 0x0B79E000, 
    4, 0x0F124F00,
    1, 0x00800000,
    1, 0x05000000,
    3, 0x00380000,
    2, 0x00000000
};

s16 D_80275BBC = 0;
s16 D_80275BC0 = 0;
s16 D_80275BC4 = 0;
s16 D_80275BC8 = 0;
s16 D_80275BCC = 0;
s16 D_80275BD0 = 0;
s16 D_80275BD4 = 0;
s16 D_80275BD8 = 0;
s16 D_80275BDC = 0;
 u8 D_80275BE0 = 0;
s32 D_80275BE4 = 0;
char D_80275BE8[] = {'a','z','A','Z','0','9','.',':', '-', ' '};


/* .h */
void func_802484D0(void);
void func_8024856C(void);
void func_80248520(void);

/* code */
void func_80247750(s32 r, s32 g, s32 b){
    D_80275A68 = r;
    D_80275A6C = g;
    D_80275A70 = b;
}

void func_8024776C(s32 x, s32 y) {
    s32 rgba16;
    if( ((x >= 0) && (x < framebuffer_width))
        && ((y >= 0) && (y < framebuffer_height))
    ) {
        D_803A5D00[0][x + y*framebuffer_width] = _SHIFTL(D_80275A68 >> 3, 11, 5) | _SHIFTL(D_80275A6C >> 3, 6, 5) | _SHIFTL(D_80275A70 >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        D_803A5D00[1][x + y*framebuffer_width] = _SHIFTL(D_80275A68 >> 3, 11, 5) | _SHIFTL(D_80275A6C >> 3, 6, 5) | _SHIFTL(D_80275A70 >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        
    }
}

void func_80247818(s32 x, s32 y, s32 w, s32 h) {
    s32 iy;
    s32 var_s1;
    s32 ix;

    for(ix = 0; ix < w; ix++){
        for(iy = 0; iy < h; iy++){
            func_8024776C(x + ix, y + iy);
        }
    }
    osWriteBackDCacheAll();
}

void func_802478C0(s32 r, s32 g, s32 b) {
    func_80247750(r, g, b);
    func_80247818((framebuffer_width - 128) / 2, (framebuffer_height - 100) / 2, 128, 100);
}

void func_8024792C(void){}

void func_80247934(void) {
    s32 var_s0;

    for(var_s0 = 0; var_s0 < 2000000; var_s0++){
        func_8024792C();
    }
}

void func_80247978(s32 arg0) {
    do{
        func_802478C0(D_80275A50[arg0][0], D_80275A50[arg0][1], D_80275A50[arg0][2]);
        func_80247934();
        func_802478C0(0, 0, 0);
        func_80247934();
    }
    while(1);
}

void func_802479E4(s32 arg0) {
    func_802478C0(D_80275A50[arg0][0], D_80275A50[arg0][1], D_80275A50[arg0][2]);
    func_80247934();
    func_802478C0(0, 0, 0);
    func_80247934();
}

void func_80247A40(s32 arg0) {
    func_802478C0(D_80275A50[arg0][0], D_80275A50[arg0][1], D_80275A50[arg0][2]);
}

void func_80247A7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 r, s32 g, s32 b) {
    s32 var_s3;
    s32 sp48;
    u32 sp44;
    u32 sp40;
    s32 temp_lo;
    s32 temp_s1;
    s32 temp_t8;
    s32 var_s0;
    u32 temp_t4;
    u32 var_s4;
    u32 *ptr = D_80275A7C + (arg1*2);
    
    var_s4 = 0x10000000;
    sp44 = ptr[0];
    sp40 = ptr[1];
    for(sp48 = 0; sp48 < 5; sp48++){
        temp_lo = sp48 * arg2;
        for(var_s3 = 0; var_s3 != sp44; var_s3++){
            var_s4 >>= 1;
            if (sp40 & var_s4) {
                func_80247750(r, g, b);
                func_80247818((D_80275BC4 + arg2*var_s3) - arg3, (D_80275BC8 + temp_lo) - arg3, (arg2 + arg3) + arg3, (arg2 + arg3) + arg3);
            } else {
                if (arg4 != 0) {
                    func_80247750(0, 0, 0);
                }
                func_80247818((D_80275BC4 + arg2*var_s3) - arg3, (D_80275BC8 + temp_lo) - arg3, (arg2 + arg3) + arg3, (arg2 + arg3) + arg3);
            }
        }
    }
    if (arg3 == 0) {
        D_80275BC4 += (sp44 * arg2) + 2;
    }
}

void func_80247C20(void) {
    s16 *var_v0;
    s16 *var_v1;
    s32 temp_lo;
    void *temp_a0;
    s32 i;

    if (D_80275BE4 == 0) {
        D_80275BE4 = func_8023DB5C();
        return;
    }
    if (func_8023DB5C() != D_80275BE4) {
        D_80275BE0 = FALSE;
        D_80275BE4 = func_8023DB5C();
    }

    if (D_80275BE0) {
        for(i = 0; i < framebuffer_width * framebuffer_height; i++){
                D_803A5D00[0][i] = 0;
                D_803A5D00[1][i] = 0;
        }
        osWriteBackDCacheAll();
    }
}

void func_80247CEC(s32 arg0, s32 arg1, s32 arg2) {
    func_80247A7C(arg0, arg1, arg2, 1, 1, 0, 0, 0);
    func_80247A7C(arg0, arg1, arg2, 0, 1, D_80275A50[D_80275A74[arg0]][0], D_80275A50[D_80275A74[arg0]][1], D_80275A50[D_80275A74[arg0]][2]);
}

void func_80247D80(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;
    s32 var_a1;
    s32 var_s0;
    s32 var_s1;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = arg2;
    if (arg1 < 0) {
        func_80247CEC(arg0, 0x26, arg2);
        arg1 *= -1;
    }
    
    for(var_s0 = 1000000000; var_s0 >= 10 && arg1 < var_s0; var_s0 /= 10){
        continue;
    }

    for(var_s0 = var_s0; var_s0 >= 10; var_s0 /= 10){
        for(var_a1 = 0; arg1 >= var_s0; var_a1++){
            arg1 -= var_s0;
        }
        func_80247CEC(arg0, var_a1, arg2);
    }

    func_80247CEC(arg0, arg1, arg2);
    func_8024856C();
    if (arg2 == 7) {
        D_80275BD8 = D_80275BC4;
        D_80275BDC = 0;
    }
    else if (D_80275BC4 >= D_80275BDC) {
        D_80275BDC = D_80275BC4;
    }
}

void func_80247F24(s32 arg0, s32 arg1) {
    D_80275BD0 = 0;
    D_80275BCC = arg0;
    D_80275BBC = 0xE;
    D_80275BC8 = 0xA;
    func_80247D80(arg0, arg1, 7);
    func_802484D0();
    D_80275BC0 = D_80275BC8;
    D_80275BDC = D_80275BBC;
    D_80275BE0 = 1;
}


void func_80247F9C(s32 arg0){
    func_80247D80(D_80275BCC, arg0, 2);
    func_802484D0();
}

void func_80247FD0(u32 arg0) {
    s32 var_s0;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    func_80247CEC(D_80275BCC, 0x25, 2);
     var_s0 = (arg0 >= 0x01000000U) ? 0x1C
            : (arg0 >= 0x10000U) ? 0x14
            :0xC;
    if (var_s0 >= 0) {
        do {
            func_80247CEC(D_80275BCC, ((s32) arg0 >> var_s0) & 0xF, 2);
            var_s0 -= 4;
        } while (var_s0 >= 0);
    }
    func_80248520();
}

void func_80248098(f32 arg0) {
    f32 var_f22;
    s32 var_s0;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    if (arg0 < 0.0f) {
        func_80247CEC(D_80275BCC, 0x26, 2);
        arg0 *= -1.0f;
    }
    var_f22 = 1e+09;
    while((var_f22 >= 10.0f) && (arg0 < var_f22)) {
        var_f22 /= 10.0f;
    }
    while (1e-09 <= var_f22) {
            if ((0.09 < var_f22) && (var_f22 < 0.11)) {
                func_80247CEC(D_80275BCC, 0x24, 2);
            }
            
            var_s0 = 0;
            while (var_f22 <= arg0) {
                    arg0 -= var_f22;
                    var_s0 += 1;
            }
            func_80247CEC(D_80275BCC, var_s0, 2);
            var_f22 /= 10.0f;
    }
    func_80248520();
}

s32 func_8024824C(s32 arg0) {
    if ((arg0 >= (s32) D_80275BE8[0]) && ((s32) D_80275BE8[1] >= arg0)) {
        return (arg0 - D_80275BE8[0]) + 0xA;
    }

    if ((arg0 >= (s32) D_80275BE8[2]) && ((s32) D_80275BE8[3] >= arg0)) {
        return (arg0 - D_80275BE8[2]) + 0xA;
    }

    if ((arg0 >= (s32) D_80275BE8[4]) && ((s32) D_80275BE8[5] >= arg0)) {
        return (arg0 - D_80275BE8[4]);
    }

    if (arg0 == D_80275BE8[6]) {
        return 0x24;
    }
    if (arg0 == D_80275BE8[7]) {
        return 0x25;
    }
    if (arg0 == D_80275BE8[8]) {
        return 0x26;
    }
    if (arg0 == D_80275BE8[9]) {
        return 0x27;
    }
    return 0x27;
}


void func_80248330(u8 *arg0){
    s32 i;
    s32 var_v0;

    D_80275BC4 = D_80275BBC;
    D_80275BD4 = 2;
    for(i = 0; arg0[i] != 0; i++){
        var_v0 = arg0[i];
        func_80247CEC(D_80275BCC, func_8024824C(var_v0), 2);
    }
    func_80248520();
}


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

void func_80248444(s32 arg0) {
    D_80275BC8 += arg0;
    if (D_80275BC8 >= 0xCD) {
        D_80275BBC = D_80275BDC + 4;
        D_80275BC4 = D_80275BBC;
        D_80275BC8 = (D_80275BD8 < D_80275BC4) ? 0xA : D_80275BC0;
        D_80275BDC = 0;
    }
}

void func_802484D0(void){
    func_80248444( D_80275BD4*5 + 2);
}

void func_80248500(void){
    func_80248444(2);
}

void func_80248520(void){
    func_8024856C();
    if(D_80275BC4 >= D_80275BDC){
        D_80275BDC = D_80275BC4;
    }
    func_802484D0();
}

void func_8024856C(void) {
    s16 sp1E;
    s16 temp_v0;

    sp1E = D_80275BC4--;
    func_80247CEC(D_80275BCC, 0x27, D_80275BD4);
    D_80275BC4 = sp1E;
}


s32 func_802485BC(void){
    return D_80275BD0;
}

void func_802485C8(UNK_TYPE(s32) arg0){

}

