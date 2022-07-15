#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80250E6C(f32, f32);
extern void func_80258E60(f32[3], f32[3], f32);
extern void func_80258EF4(f32[3], f32[3], f32);
extern void func_80258F88(f32[3], f32[3], f32);
extern void func_802BE720(void);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8  unk1C;
    // u8 pad1D[3];
}Struct_core2_33F90_0;

void func_802BB200(void);
void func_802BB22C(void);
void func_802BB318(s32 arg0);
void func_802BB360(s32 arg0, f32 arg1);
void func_802BB3AC(s32 arg0, f32 arg1);

/* .data */
extern s32 D_80364E00;
extern s32 D_80364E04;
extern s16 *D_803654B8[];

/* .code */
void func_802BAF20(void){
    func_802BB200();
}

void func_802BAF40(void){
    if(D_80364E00 && timedFuncQueue_is_empty()){
        func_802BB200();
    }
}

void func_802BAF80(s32 arg0){
    func_802BE720();
}

f32  func_802BAFA0(s32 arg0, s32 arg1){
    return (f32)D_803654B8[arg0][arg1]/10.0;
}

void func_802BAFE4(s32 arg0) {
    f32 temp_f0;
    s32 phi_s1;
    s32 phi_s0;

    phi_s0 = 0;
    if (arg0 != D_80364E04) {
        D_80364E04 = arg0;
        func_802BB22C();
        D_80364E00 = 1;
        for(phi_s1 = 0; D_803654B8[arg0][phi_s1] != -1 && D_803654B8[arg0][phi_s1] != -4; phi_s1+=2){
            temp_f0 = func_802BAFA0(arg0, phi_s1);
            switch(D_803654B8[arg0][phi_s1 + 1]){
                case -5:
                    timedFunc_set_6(temp_f0, (TFQM6) func_802BAF80, NULL);
                    phi_s0++;
                    break;

                case -3:
                    func_80324E38(temp_f0, 1);
                    phi_s0++;
                    break;

                case -2:
                    func_80324E38(temp_f0, 2);
                    phi_s0++;
                    break;

                case -1:
                    func_80324E38(temp_f0, 3);
                    phi_s0++;
                    break;

                case -4:
                    func_80324E38(temp_f0, 4);
                    break;

                case -6:
                    func_80324E38(temp_f0, 4);
                    break;
                
                default:
                    timed_setCameraToNode(temp_f0, D_803654B8[arg0][phi_s1 + 1]);
                    break;
            }
        }
        temp_f0 = func_802BAFA0(arg0, phi_s1 + 1);
        if (D_803654B8[arg0][phi_s1] == -4) {
            func_80324E38(temp_f0, 4);
        } else {
            func_80324E88(temp_f0);
        }
        for(phi_s1 = 0; phi_s1 < phi_s0; phi_s1++){
            func_80324E38(temp_f0, 0);
        }
    }
}

void func_802BB200(void){
    if(D_80364E00){
        D_80364E00 = FALSE;
        D_80364E04 = -1;
    }
}

void func_802BB22C(void){
    if(D_80364E00){
        timedFuncQueue_flush();
        D_80364E00 = FALSE;
        D_80364E04 = -1;
    }
}

bool func_802BB270(void){
    return (!D_80364E00) ? TRUE : FALSE;
}

s32 func_802BB294(void){
    return D_80364E04;
}
