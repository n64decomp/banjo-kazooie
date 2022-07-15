#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8029E070(bool);
void func_8029E064(bool);
void func_8029E058(bool);
void func_8029E0C4(f32);
void func_8029E0D0(f32);
void func_8029E0DC(bool);
void func_8029E0F4(bool);
void func_8029E0E8(bool);

/* .bss */
f32 D_8037D230;
u8  D_8037D234;
u8  D_8037D235;
u8  D_8037D236;
u8  D_8037D237;
u8  D_8037D238;
u8  D_8037D239;
u8  D_8037D23A;
f32 D_8037D23C;
f32 D_8037D240;

/* .code */
void func_8029DBF0(void){
    s32 temp_s0;
    switch(func_80291FAC()){
        case 0x34D: //L8029DC24
        case 0x34E: //L8029DC24
            temp_s0 = (s32) func_80257C48(D_8037D23C, 1.0f, 8.0f);
            func_8033A45C(0x1B, temp_s0);
            func_8033A45C(0x1D, temp_s0);
            func_8033A45C(0x1F, temp_s0);
            func_8033A45C(0x21, temp_s0);
            temp_s0 = (s32) func_80257C48(D_8037D240, 1.0f, 8.0f);
            func_8033A45C(0x1A, temp_s0);
            func_8033A45C(0x1C, temp_s0);
            func_8033A45C(0x1E, temp_s0);
            func_8033A45C(0x20, temp_s0);
            break;

        case ASSET_34F_MODEL_BANJO_TERMITE: //L8029DCCC
        case ASSET_359_MODEL_BANJO_WALRUS: //L8029DCCC
        case ASSET_36F_MODEL_BANJO_PUMPKIN: //L8029DCCC
        case ASSET_374_MODEL_BANJO_CROC: //L8029DCCC
            func_8033A45C(0x1B, (s32) func_80257C48(D_8037D23C, 1.0f, 6.0f));
            func_8033A45C(0x1A, (s32) func_80257C48(D_8037D240, 1.0f, 6.0f));
            break;

        case ASSET_356_MODEL_BANJO_WISHYWASHY: //L8029DD2C
            func_8033A45C(1, (s32) func_80257C48(D_8037D240, 1.0f, 4.0f));
            break;
    }
}



void func_8029DD6C(void) {
    bool temp_s0;

    func_8033A1FC();
    switch (func_80291FAC()) {
    case 0x34D:
    case 0x34E:
        func_8033A45C(1, D_8037D238);
        func_8033A45C(9, D_8037D238);
        func_8033A45C(0xC, D_8037D238);
        func_8033A45C(0xF, D_8037D238);
        func_8033A45C(2, D_8037D236);
        func_8033A45C(0xA, D_8037D236);
        func_8033A45C(0xD, D_8037D236);
        func_8033A45C(0x10, D_8037D236);
        func_8033A45C(8, D_8037D235);
        func_8033A45C(0xB, D_8037D235);
        func_8033A45C(0xE, D_8037D235);
        func_8033A45C(0x11, D_8037D235);
        temp_s0 = D_8037D237 + 1;
        func_8033A45C(0x12, temp_s0);
        func_8033A45C(0x14, temp_s0);
        func_8033A45C(0x16, temp_s0);
        func_8033A45C(0x18, temp_s0);
        func_8033A45C(0x13, temp_s0);
        func_8033A45C(0x15, temp_s0);
        func_8033A45C(0x17, temp_s0);
        func_8033A45C(0x19, temp_s0);
        temp_s0 = D_8037D239 + 1;
        func_8033A45C(0x22, temp_s0);
        func_8033A45C(0x24, temp_s0);
        func_8033A45C(0x26, temp_s0);
        func_8033A45C(0x28, temp_s0);
        func_8033A45C(0x23, temp_s0);
        func_8033A45C(0x25, temp_s0);
        func_8033A45C(0x27, temp_s0);
        func_8033A45C(0x29, temp_s0);
        break;
    case ASSET_359_MODEL_BANJO_WALRUS:
        func_8033A45C(3, D_8037D23A);
        break;
    case ASSET_374_MODEL_BANJO_CROC:
        temp_s0 = D_8037D237 + 1;
        func_8033A45C(4, temp_s0);
        func_8033A45C(5, temp_s0);
        func_8033A45C(6, temp_s0);
        func_8033A45C(7, temp_s0);
        break;
    }
    func_8029DBF0();
}

bool func_8029DFA4(void){
    return D_8037D235;
}

bool func_8029DFB0(void){
    return D_8037D236;
}

bool func_8029DFBC(void){
    return D_8037D238;
}

f32 func_8029DFC8(void){
    return D_8037D23C;
}

f32 func_8029DFD4(void){
    return D_8037D240;
}

bool func_8029DFE0(void){
    return D_8037D237;
}

bool func_8029DFEC(void){
    return D_8037D239;
}

void func_8029DFF8(void) {
    func_8029E070(0);
    func_8029E064(0);
    func_8029E058(0);
    func_8029E0C4(0.0f);
    func_8029E0D0(0.0f);
    func_8029E0DC(0);
    func_8029E0F4(0);
    func_8029E0E8(0);
}

void func_8029E058(bool arg0){
    D_8037D235 = arg0;
}

void func_8029E064(bool arg0){
    D_8037D236 = arg0;
}

void func_8029E070(bool arg0) {
    func_8029E090(arg0, 0.0f);
}

void func_8029E090(bool arg0, f32 arg1) {
    D_8037D230 = arg1;
    D_8037D234 = arg0;
    if (arg1 == 0.0f) {
        D_8037D238 = arg0;
    }
}

void func_8029E0C4(f32 arg0){
    D_8037D23C = arg0;
}

void func_8029E0D0(f32 arg0){
    D_8037D240 = arg0;
}

void func_8029E0DC(bool arg0){
    D_8037D237 = arg0;
}

void func_8029E0E8(bool arg0){
    D_8037D23A = arg0;
}

void func_8029E0F4(bool arg0){
    D_8037D239 = arg0;
}

void func_8029E100(void) {
    if (D_8037D230 != 0.0f) {
        D_8037D230 -= time_getDelta();
        if (D_8037D230 <= 0.0f) {
            D_8037D238 = D_8037D234;
        }
    }
}
