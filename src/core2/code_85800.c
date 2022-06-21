#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80256AB4(f32, f32, f32, f32);
extern void func_80335394(s32, f32);
extern f32 func_8034A788(f32, f32);

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    s16 unk14;
    u8 unk16;
    u8 pad17[0x1];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 sfx_uid;
    s16 unk2A;
    u8 unk2C;
    u8 pad2D[3];
    void (*unk30)(u8 indx);
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43_7:3;
    u8 unk43_4:3;
    u8 unk43_1:2;
}struct45s;

u8   func_8030D90C(void);
void func_8030DA80(u8 indx, enum sfx_e uid);
void func_8030DABC(u8, s32);
void func_8030DD90(u8, s32);
void func_8030DCCC(u8, s32);
void func_8030E0B4(u8, f32, f32);
f32  func_8030E200(u8);
void func_8030E2C4(u8);
int func_8030ED70(enum sfx_e uid);
void func_8030EDAC(f32, f32);

/* .bss */
extern struct46s D_80382470[16];
extern struct45s D_803824C0[35];
extern f32 D_80382E0C;
extern f32 D_80382E10;

/* .code */
void func_8030C790(f32 (*arg0)[3]){
    if(player_is_present())
        player_getPosition(arg0);
    else
        ml_vec3f_clear(arg0);
}

void func_8030C7D0(struct45s *arg0, s32 arg1){
    arg0->unk43_7 = arg1;
}

s32 func_8030C7E8(struct45s *arg0){
    return arg0->unk43_7;
}

void func_8030C7F8(struct45s *arg0, s32 arg1){
    arg0->unk43_4 = arg1;
}

int func_8030C814(struct45s *arg0, s32 arg1){
    return arg0->unk43_4 == arg1;
}

void func_8030C82C(struct45s *arg0, s32 arg1){
    arg0->unk41 |= arg1;
}

void func_8030C83C(struct45s *arg0, s32 arg1){
    arg0->unk41 &= ~arg1;
}

s32 func_8030C850(struct45s *arg0, s32 arg1){
    return arg0->unk41 & arg1;
}

int func_8030C85C(struct45s *arg0, s32 arg1){
    return (arg0->unk41 & arg1) == 0;
}

void func_8030C870(void){
    int i;
    for(i = 0; i < 35; i++)
        D_803824C0[i].unk42 = 0;
}

struct45s *func_8030C8B8(u8 indx){
    return D_803824C0 + indx;
}

struct46s *func_8030C8DC(s32 indx){
    return D_80382470 + indx - 1;
}

s32 func_8030C8F4(s32 indx){
    return D_80382470[indx - 1].unk0;
}

u8 func_8030C908(void){
    int i;
    for(i = 1; i < 35; i++){
        if(D_803824C0[i].unk42 == 0){
            D_803824C0[i].unk42 = 1;
            return i;
        }
    }
    return 0;
}

void func_8030C9F4(s32 indx){
    D_80382470[indx - 1].unk4 = 0;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030CA08.s")
#else
void func_8030CA08(void){
    int i;
    for(i = 0; i < 10; i++){
        D_80382470[i].unk0 = 0;
        D_80382470[i].unk4 = 0;
    }
}
#endif

s32 func_8030CA60(void){
    int i;
    for(i = 0; i < 10; i++){
        if(D_80382470[i].unk4 == 0 && D_80382470[i].unk0 == 0){
            D_80382470[i].unk4 = 1;
            return i+1;
        }
        
    }
    return 0;
}

void func_8030CB74(u8 indx){
    struct45s *ptr = func_8030C8B8(indx);
    if(ptr->unk40){
        func_8030C9F4(ptr->unk40);
        ptr->unk40 = 0;
    }
    D_803824C0[indx].unk42 = 0;
}

void func_8030CBD0(struct45s *arg0){
    s32 sp24 = func_8030CA60();
    struct46s *temp_a1;
    if(sp24){
        if(arg0->unk40)
            func_8030C9F4(arg0->unk40);
        arg0->unk40 = sp24;
        func_8030C7F8(arg0, 1);
        func_8030C82C(arg0, 4);
        func_8030C82C(arg0, 8);
        func_8030C82C(arg0, 0x10);
        if(arg0->sfx_uid > 0x3e8){
            func_80335354(arg0->sfx_uid - 0x3e9, func_8030C8DC(arg0->unk40));
        }
        else{
            func_8033531C(arg0->sfx_uid, func_8030C8DC(arg0->unk40));
        }
    }//L8030CC7C
}

void func_8030CC90(struct45s *arg0){
    if(func_8030C814(arg0, 1)){
        func_8030C83C(arg0, 0x20);
        func_8030C7F8(arg0, 2);
        if(arg0->unk40){
            func_8033543C(func_8030C8F4(arg0->unk40));
        }
    }
}

s32 func_8030CCF0(struct45s *arg0, s32 arg1){
    f32 sp3C[3];
    f32 sp30[3];
    f32 dist_sqr;
    s32 retVal;
    func_8030C790(sp3C);
    sp30[0] = arg0->unk0[0] - sp3C[0];
    sp30[1] = arg0->unk0[1] - sp3C[1];
    sp30[2] = arg0->unk0[2] - sp3C[2];
    dist_sqr = sp30[0]*sp30[0] + sp30[1]*sp30[1] + sp30[2]*sp30[2];
    if( dist_sqr < arg0->unkC)
        retVal = arg1;
    else if( dist_sqr < arg0->unk10) 
        retVal = arg0->unk14 + (((arg0->unk10-dist_sqr))/(arg0->unk10 - arg0->unkC))*(arg1 - arg0->unk14);
    else
        retVal = arg0->unk14;
    return retVal;
}

s32 func_8030CDE4(struct45s *arg0){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 temp_f0;
    f32 pad;

    func_8024C5CC(&sp44);
    func_8024C5A8(&sp38);
    sp2C[0] = arg0->unk0[0] - sp44[0];
    sp2C[1] = arg0->unk0[1] - sp44[1];
    sp2C[2] = arg0->unk0[2] - sp44[2];
    sp2C[1] = 0.0f;
    if(sp2C[0]*sp2C[0] + sp2C[1]*sp2C[1] + sp2C[2]*sp2C[2] < 10.0f){
        return 0x40;
    }
    ml_vec3f_normalize(&sp2C);
    sp38[1] = 0.0f;
    ml_vec3f_normalize(&sp38);
    temp_f0 = func_80256AB4(sp38[0], sp38[2], sp2C[0], sp2C[2]);
    if(arg0->unk16){
        arg0->unk18 += 0.07*((f32)(s32)(64.0f - (temp_f0 * 63.0f)) - arg0->unk18);
    }
    else{
        arg0->unk18 = (f32)(s32)(64.0f - temp_f0*63.0f);
    }
    return (s32)arg0->unk18;
}

void func_8030CF68(s32 arg0, s32 arg1){
    if(arg0){
        func_803353F4(func_8030C8F4(arg0), arg1);
    }
}

void func_8030CF9C(s32 arg0, s32 arg1){
    if(arg0){
        func_80335418(func_8030C8F4(arg0), arg1);
    }
}

void func_8030CFD0(s32 arg0, f32 arg1){
    if(arg0){
        func_80335394(func_8030C8F4(arg0), arg1);
    }
}

void func_8030D004(s32 arg0, s32 arg1){
    if(arg0){
        func_803353BC(func_8030C8F4(arg0), (u16) arg1);
    }
}

s32 func_8030D038(struct45s *arg0, s32 arg1){
    if(func_8030C850(arg0, 1 << 6)){
        if(func_8030C850(arg0, 1 << 7)){
            if(player_is_present() && func_8028EE84() == 2)
                    arg1 *= arg0->unk3C;
        }
        else{//L8030D0B4
            if(player_is_present() && func_8028EE84() != 2)
                    arg1 *= arg0->unk38;
        }
    }
    return arg1;
}

s32 func_8030D10C(u8 indx){
    s32 sp24;
    struct45s * ptr;
    s32 tmp_v0;
    f32 tmp_f2;

    ptr = func_8030C8B8(indx);
    sp24 = 0;
    if(func_8030C814(ptr, 1)){
        if(func_8030C850(ptr, 1 << 2)){
            func_8030CFD0(ptr->unk40, ptr->unk34);
        }//L8030D164
        
        if(func_8030C850(ptr, 1 << 4)){
            tmp_f2 = ((f32)ptr->unk2C + D_80382E0C*127.0f)*D_80382E10;
            tmp_f2 = MAX(0.0f,MIN(127.0f, tmp_f2));
            func_8030CF68(ptr->unk40, tmp_f2);
        }

        //L8030D228
        if(func_8030C850(ptr, 1 << 1)){
            tmp_v0 = func_8030CCF0(ptr, ptr->unk2A);
            if(tmp_v0 < 0x64)
                sp24 = 1;
            func_8030D004(ptr->unk40, func_8030D038(ptr, tmp_v0));
            func_8030CF9C(ptr->unk40, func_8030CDE4(ptr));
        }else{//L8030D288
            if(func_8030C850(ptr, 1 << 3)){
                tmp_v0 = func_8030D038(ptr, ptr->unk2A);
                if(tmp_v0 < 0x64)
                    sp24 = 1;
                func_8030D004(ptr->unk40, tmp_v0);
            }
        }
        func_8030C83C(ptr, 1 << 2);
        func_8030C83C(ptr, 1 << 3);
        func_8030C83C(ptr, 1 << 4);
    }//L8030D2E0
    if(getGameMode() == GAME_MODE_4_PAUSED)
        sp24++;

    return sp24;
}

void func_8030D310(u8 indx){
    f32 pad0;
    s32 sp30;
    f32 pad1;
    struct45s * ptr;
    f32 sp24;
    
    ptr = func_8030C8B8(indx);
    
    if( func_8030C814(ptr, 1) 
        && ptr->unk40
        && func_8030C8F4(ptr->unk40)
    ){
        switch(ptr->unk43_1){
            case 0:
                break;
            case 1: //L8030D388[
                ptr->unk34 += ptr->unk1C*time_getDelta();
                if(0.0f < ptr->unk1C)
                    ptr->unk34 = min_f(ptr->unk34, ptr->unk20);
                else
                    ptr->unk34 = max_f(ptr->unk34, ptr->unk20);
                func_8030C82C(ptr, 1 << 2);
                break;
            case 2: //L8030D3E8
                sp24 = time_getDelta();
                ptr->unk34 +=  func_8034A788(-ptr->unk24, ptr->unk24)*sp24;
                ptr->unk34 = mlClamp_f(ptr->unk34, ptr->unk20, ptr->unk1C);
                func_8030C82C(ptr, 1 << 2);
                break;
        }
    }//L8030D434
    switch(func_8030C7E8(ptr)){
        case 1://L8030D468
            if( func_8030C814(ptr, 0) || (func_8030C814(ptr, 1) && !ptr->unk40))
                func_8030DA44(indx);
            break;
        case 2://L8030D4A4
            if(func_8030C814(ptr, 1) && func_8030C85C(ptr, 1))
                func_8030E394(indx);
            else
                func_8030C83C(ptr, 1);
            break;
        case 3://L8030D4E0
            break;
    }//L8030D4E0
    sp30 = func_8030D10C(indx);
    if( func_8030C814(ptr, 1)
        && func_8030ED70(ptr->sfx_uid)
    ){
        if(func_8030C850(ptr, 1 << 5)){
            if(sp30 == 0){
                osSetThreadPri(NULL, 0x33);
                func_8030CBD0(ptr);
                func_8030C83C(ptr, 0x20);
                func_8030D10C(indx);
                osSetThreadPri(NULL, 0x14);
            }
        }
        else{//L8030D568
            if(sp30){
                func_8030CC90(ptr);
                func_8030C7F8(ptr, 1);
                func_8030C82C(ptr, 0x20);
            }
        }
    }//L8030D594
    if(ptr->unk40 && !func_8030C8F4(ptr->unk40)){
        func_8030C9F4(ptr->unk40);
        ptr->unk40 = 0;
    }
}

int func_8030D5CC(u8 indx){
    struct45s * sp1C = func_8030C8B8(indx);
    if(!func_8030C814(sp1C, 3))
        return 0;

    if(!sp1C->unk40)
        return 1;

    if(func_8030C8F4(sp1C->unk40))
        return 0;
    return 1;
}

void func_8030D644(void){
    int i;
    for(i = 1; i < 35; i++){
        if(D_803824C0[i].unk42){
            func_8030D310(i);
            if(func_8030D5CC(i))
                func_8030CB74(i);
        }
    }
}

void func_8030D6C4(enum sfx_e uid, f32 arg1, s32 arg2, s32 arg3, s32 arg4){
    u8 indx = func_8030D90C();
    if(indx){
        func_8030DA80(indx, uid);
        func_8030DABC(indx, arg2);
        func_8030DBB4(indx, arg1);
        func_8030DCCC(indx, arg3);
        func_8030DD14(indx, 1);
        func_8030DD90(indx, arg4);
        func_8030E2C4(indx);
    }
}

void func_8030D750(void){
    func_8030CA08();
    func_8030C870();
    
}

void func_8030D778(void){
    int i;
    int temp_s1;
    for(i = 1; i < 35; i++){
        if(D_803824C0[i].unk42)
            func_8030DA44(i);
    }
    do{
        temp_s1 = 0;
        func_8030D644();
        for(i = 1; i < 35; i++){
            if(D_803824C0[i].unk42)
                temp_s1++;
        }
    }while(temp_s1);
}

void func_8030D86C(void){
    func_8030D750();
    func_80244AB0();
    func_8030EDAC(0.0f, 1.0f);
}

void func_8030D8A8(s32 arg0, s32 arg){
    return;
}

void func_8030D8B4(void){
    func_8024FB8C();
    func_8024F83C();
}

void func_8030D8DC(void){
    func_80244B3C();
    func_8030D778();
    func_8030D8B4();
}

u8 func_8030D90C(void){
    u8 s1 = func_8030C908();
    struct45s *s0;

    if(s1 == 0)
        return 0;

    s0 = func_8030C8B8(s1);
    s0->unk30 = NULL;
    s0->sfx_uid = -1;
    s0->unk2A = 22000;
    s0->unk2C = 0;
    s0->unk40 = 0;
    s0->unk43_1 = 0;
    s0->unk34 = 1.0f;
    func_8030C7F8(s0, 0);
    func_8030C7D0(s0, 0);
    func_8030C82C(s0, 1);
    func_8030C82C(s0, 4);
    func_8030C82C(s0, 8);
    func_8030C82C(s0, 0x10);
    s0->unkC = 62500.0f;
    s0->unk10 = 1440000.0f;
    s0->unk14 = 0xa;
    s0->unk16 = 0;
    s0->unk18 = 64.0f;
    ml_vec3f_clear(&s0->unk0);
    func_8030C83C(s0, 2);
    func_8030C83C(s0, 0x20);
    func_8030DD90(s1, 2);
    func_8030E0B4(s1, 0.2f, 0.1f);
    return s1;
}

void func_8030DA44(u8 indx){
    struct45s * sp1C = func_8030C8B8(indx);
    func_8030E394(indx);
    func_8030C7F8(sp1C, 3);
}

void func_8030DA80(u8 indx, enum sfx_e uid){
    if(indx)
        func_8030C8B8(indx)->sfx_uid = uid;
}

void func_8030DABC(u8 indx, s32 arg1){
    struct45s *temp_v0;
    if(indx){
        temp_v0 = func_8030C8B8(indx);
        temp_v0->unk2A = arg1;
       func_8030C82C(temp_v0, 8);
    }
}

void func_8030DB04(u8 indx, s32 arg1, f32 arg2[3], f32 arg3, f32 arg4){
    f32 sp24[3];
    f32 dist;
    f32 temp_f2;
    func_8030C790(sp24);
    dist = func_80256064(arg2, sp24);
    if(arg4 <= dist)
        temp_f2 = 0.0f;
    else{
        if(arg3 <= dist){
            temp_f2 = 1.0f - (dist - arg3)/(arg4 - arg3);
        }
        else{
            temp_f2 = 1.0f;
        }
    }
    func_8030DABC(indx, (s32)arg1*temp_f2);
}

void func_8030DBB4(u8 indx, f32 arg1){
    struct45s *temp_v0;
    if(indx){
        temp_v0 = func_8030C8B8(indx);
        temp_v0->unk34 = arg1;
       func_8030C82C(temp_v0, 4);
    }
}

void func_8030DBFC(u8 indx, f32 arg1, f32 arg2, f32 arg3){
    f32 temp_f2 = func_8030E200(indx);
    f32 temp_f0;
    if( temp_f2 < arg1){
        temp_f2 += arg3;
    }
    else if(arg2 < temp_f2){
        temp_f2 -= arg3;
    }
    else{
        temp_f2 += func_8034A788(-arg3, arg3);
        if(temp_f2 < arg1)
            temp_f2 = arg1;
        else{
            temp_f0 = MIN(arg2 , temp_f2);
            temp_f2 = temp_f0;
        }
    }
    func_8030DBB4(indx, temp_f2);

}

void func_8030DCCC(u8 indx, s32 arg1){
    struct45s *temp_v0;
    if(indx){
        temp_v0 = func_8030C8B8(indx);
        temp_v0->unk2C = arg1;
       func_8030C82C(temp_v0, 0x10);
    }
}

void func_8030DD14(u8 indx, int arg1){
    struct45s *temp_v0;
    if(indx){
        temp_v0 = func_8030C8B8(indx);
        func_8030C7D0(temp_v0, arg1);
    }
}

void func_8030DD54(u8 indx, void (*arg1)(u8)){
    struct45s *temp_v0;
    if(indx){
        temp_v0 = func_8030C8B8(indx);
        temp_v0->unk30 = arg1;
    }
}

void func_8030DD90(u8 indx, s32 arg1){
    struct45s *temp_v0;
    if(indx){
        temp_v0 = func_8030C8B8(indx);
        switch(arg1){
            case 0://L8030DDE4
                func_8030C83C(temp_v0, 0x40);
                func_8030C83C(temp_v0, 0x80);
                break;
            case 1: //L8030DE00
                func_8030C82C(temp_v0, 0x40);
                func_8030C83C(temp_v0, 0x80);
                break;
            case 2: //L8030DE1C
                func_8030C82C(temp_v0, 0x40);
                func_8030C82C(temp_v0, 0x80);
                break;
        }
    }
}

void func_8030DE44(u8 indx, s32 arg1, f32 arg2){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        switch(arg1){
            case 0:
                break;
            case 1://L8030DE98
                ptr->unk38 = arg2;
                break;
            case 2:
                ptr->unk3C = arg2;
                break;
        }
    }
}

void func_8030DEB4(u8 indx, f32 arg1, f32 arg2){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        ptr->unkC = arg1*arg1;
        ptr->unk10 = arg2*arg2;
        func_8030DFF0(indx, 1);
    }
}

void func_8030DF18(u8 indx, f32 arg1){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        ptr->unk14 = (s16)arg1;
        func_8030DFF0(indx, 1);
    }
}

void func_8030DF68(u8 indx, f32 arg1[3]){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        ml_vec3f_copy(&ptr->unk0, arg1);
        func_8030DFF0(indx, 1);
    }
}

void func_8030DFB4(u8 indx, s32 arg1){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        ptr->unk16 = arg1;
    }
}

void func_8030DFF0(u8 indx, s32 arg1){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        if(arg1){
            func_8030C82C(ptr, 2);
        }
        else{
            func_8030C83C(ptr, 2);
        }
    }
}

void func_8030E04C(u8 indx, f32 arg1, f32 arg2, f32 arg3){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        ptr->unk43_1 = 1;
        ptr->unk1C = arg3;
        ptr->unk20 = arg2;
        func_8030DBB4(indx, arg1);
    }
}

void func_8030E0B4(u8 indx, f32 arg1, f32 arg2){
    struct45s *ptr;
    if(indx){
        ptr = func_8030C8B8(indx);
        ptr->unk38 = arg1;
        ptr->unk3C = arg2;
    }
}

void func_8030E0FC(u8 indx, f32 arg1, f32 arg2, f32 arg3){
    struct45s *ptr;

    if(indx){
        ptr = func_8030C8B8(indx);
        ptr->unk43_1 = 2;
        ptr->unk24 = arg3;
        ptr->unk20 = arg1;
        ptr->unk1C = arg2;
        func_8030DBB4(indx, (arg1 + arg2)/2);
    }
}

enum sfx_e func_8030E188(u8 indx){
    struct45s *ptr;

    if(!indx)
        return 0;
    else{
        ptr = func_8030C8B8(indx);
        return ptr->sfx_uid;
    }
}

s32 func_8030E1C4(u8 indx){
    struct45s *ptr;

    if(!indx)
        return 0;
    else{
        ptr = func_8030C8B8(indx);
        return ptr->unk2A;
    }
}

f32 func_8030E200(u8 indx){
    struct45s *ptr;

    if(!indx)
        return 1.0f;
    else{
        ptr = func_8030C8B8(indx);
        return ptr->unk34;
    }
}

s32 func_8030E244(u8 indx){
    struct45s *ptr;

    if(!indx)
        return 0;
    else{
        ptr = func_8030C8B8(indx);
        return ptr->unk2C;
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E280.s")
#else
int func_8030E280(struct45s *arg0){
    int temp_v1;
    int temp_v0;
    if(func_8030C850(arg0, 2)){
        temp_v1 = func_8030CCF0(arg0, arg0->unk2A);
    }
    else{
        temp_v1 = arg0->unk2A;
    }
    temp_v0 = (temp_v1 < 0x65);
    return temp_v0 ^ 1;
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_85800/func_8030E2C4.s")
#else
void func_8030E2C4(u8 indx){
    struct45s *ptr;

    if(indx){
        ptr = func_8030C8B8(indx);
        if(func_8030E280(ptr) || func_8030ED70(ptr->sfx_uid)){
            if(func_8030C7E8(ptr) == 2){
                func_8030C82C(ptr, 1);
                if(func_8030C814(ptr, 1)){
                    return;
                }
            }else{
                if(func_8030C814(ptr, 1)){
                    func_8030E394(indx);
                }
            }
            osSetThreadPri(NULL, 0x33);
            func_8030CBD0(ptr);
            func_8030D10C(indx);
            osSetThreadPri(NULL, 0x14);
        }
    }
}
#endif

void func_8030E394(u8 indx){
    struct45s *ptr;

    if(indx){
        ptr = func_8030C8B8(indx);
        if(func_8030C814(ptr, 1)){
            func_8030CC90(ptr);
            if(ptr->unk30)
                ptr->unk30(indx);
        }
    }
}


int func_8030E3FC(u8 indx){
    struct45s *ptr;

    if(!indx)
        return 0;
    else {
        ptr = func_8030C8B8(indx);
        return indx
            && func_8030C814(ptr, 1)
            && ptr->unk40 
            && func_8030C8F4(ptr->unk40);
    }
}

void func_8030E484(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 22000, 0, 2);
}

void func_8030E4B4(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 22000, 0, 1);
}

void func_8030E4E4(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 22000, 0, 0);
}

void func_8030E510(enum sfx_e uid, s32 arg1){
    func_8030D6C4(uid, 1.0f, arg1, 0, 2);
}

void func_8030E540(enum sfx_e uid){
    func_8030E510(uid, 0x7ff8);
}

void func_8030E560(enum sfx_e uid, s32 arg1){
    func_8030D6C4(uid, 1.0f, arg1, 0, 0);
}

void func_8030E58C(enum sfx_e uid, f32 arg1){
    func_8030D6C4(uid, arg1, 22000, 0, 2);
}

void func_8030E5C0(enum sfx_e uid, f32 arg1){
    func_8030D6C4(uid, arg1, 22000, 0, 1);
}

void func_8030E5F4(enum sfx_e uid, f32 arg1){
    func_8030D6C4(uid, arg1, 22000, 0, 0);
}

void func_8030E624(u32 arg0){
    f32 f6 = (arg0 >> 0x15) & 0x7ff;
    func_8030D6C4(arg0 & 0x7FF, f6/1023.0, (arg0 >> 6) & 0x7fe0, 0, 2);
}

void func_8030E6A4(enum sfx_e uid, f32 arg1, s32 arg2){
    func_8030D6C4(uid, arg1, arg2, 0, 2);
}

void func_8030E6D4(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 0x7ff8, 0, 2);
}

void func_8030E704(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 0x7ff8, 0, 0);
}

void func_8030E730(enum sfx_e uid, f32 arg1, s32 arg2){
    func_8030D6C4(uid, arg1, arg2, 0, 1);
}

void func_8030E760(enum sfx_e uid, f32 arg1, s32 arg2){
    func_8030D6C4(uid, arg1, arg2, 0, 0);
}

void func_8030E78C(enum sfx_e uid, f32 arg1, u32 arg2, f32 arg3[3], f32 arg4, f32 arg5, s32 arg6){
    u8 s0;
    f32 sp20[3];
    
    func_8030C790(&sp20);
    if( !(arg5 <= func_80256064(sp20, arg3))
        && levelSpecificFlags_validateCRC2()
        && func_80320240()
    ){
        s0 = func_8030D90C();
        if(s0){
            func_8030DD90(s0, arg6);
            func_8030DA80(s0, uid);
            func_8030DABC(s0, arg2);
            func_8030DBB4(s0, arg1);
            func_8030DEB4(s0, arg4, arg5);
            func_8030DF68(s0, arg3);
            func_8030DD14(s0, 1);
            func_8030E2C4(s0);
        }
    }
}

void func_8030E878(enum sfx_e id, f32 arg1, u32 arg2, f32 arg3[3], f32 arg4, f32 arg5){
    func_8030E78C(id, arg1, arg2, arg3, arg4, arg5, 2);
}

void func_8030E8B4(u32 arg0, f32 arg1[3], u32 arg2){
    func_8030E78C(
        (arg0 & 0x7ff), (f32)((arg0 >> 0x15) & 0x7ff)/1023.0, ((arg0 >> 0x6) & 0x7fe0),
        arg1, (f32)(arg2 & 0xffff), (f32)((arg2 >> 0x10) & 0xffff),
        2
    );
}

void func_8030E988(enum sfx_e uid, f32 arg1, u32 arg2, f32 arg3[3], f32 arg4, f32 arg5){
    func_8030E78C(uid, arg1, arg2, arg3, arg4, arg5, 1);
}

void func_8030E9C4(enum sfx_e uid, f32 arg1, u32 arg2, f32 arg3[3], f32 arg4, f32 arg5){
    func_8030E78C(uid, arg1, arg2, arg3, arg4, arg5, 0);
}

void func_8030E9FC(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, f32 (*arg4)[3], f32 arg5, f32 arg6){
    func_8030E78C(uid, func_8034A788(arg1, arg2), arg3, arg4, arg5, arg6, 2);
}

void func_8030EA54(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, f32 (*arg4)[3], f32 arg5, f32 arg6){
    func_8030E78C(uid, func_8034A788(arg1, arg2), arg3, arg4, arg5, arg6, 1);
}

void func_8030EAAC(enum sfx_e uid, f32 arg1, s32 arg2, s32 arg3){
    func_8030D6C4(uid, arg1, arg2, arg3, 2);
}

void func_8030EAD8(enum sfx_e uid, f32 arg1, s32 arg2, s32 arg3){
    func_8030D6C4(uid, arg1, arg2, arg3, 0);
}

void func_8030EB00(enum sfx_e uid, f32 arg1, f32 arg2){
    func_8030D6C4(uid, func_8034A788(arg1, arg2), 22000, 0, 2);
}

void func_8030EB44(enum sfx_e uid, f32 arg1, f32 arg2){
    func_8030D6C4(uid, func_8034A788(arg1, arg2), 22000, 0, 1);
}

void func_8030EB88(enum sfx_e uid, f32 arg1, f32 arg2){
    func_8030D6C4(uid, func_8034A788(arg1, arg2), 22000, 0, 0);
}

void func_8030EBC8(enum sfx_e uid, f32 arg1, f32 arg2, s32 arg3, s32 arg4){
    func_8030D6C4(uid, func_8034A788(arg1, arg2), func_8034A80C(arg3, arg4), 0, 2);
}

void func_8030EC20(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, u32 arg4){
    func_8030D6C4(uid, func_8034A788(arg1, arg2), func_8034A80C(arg3, arg4), 0, 0);
}

void func_8030EC74(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, u32 arg4, f32 (*arg5)[3]){
    u8 indx = func_8030D90C();
    if(indx){
        func_8030DA80(indx, uid);
        func_8030DABC(indx, func_8034A80C(arg3, arg4));
        func_8030DBB4(indx, func_8034A788(arg1, arg2));
        func_8030DF68(indx, arg5);
        func_8030DD14(indx, 1);
        func_8030E2C4(indx);
    }
}

void func_8030ED0C(void){
    func_8030D644();
}

u8 func_8030ED2C(enum sfx_e uid, s32 arg1){
    u8 indx = func_8030D90C();
    func_8030DA80(indx, uid);
    func_8030DD14(indx, arg1);
    return indx;
}

int func_8030ED70(enum sfx_e uid){
    if(!(uid < 0x3e9)){
        return func_80335520(uid - 0x3e9);
    }
    else{
        return func_803354EC(uid);
    }
}

void func_8030EDAC(f32 arg0, f32 arg1){
    D_80382E0C = arg0;
    D_80382E10 = arg1;
}

