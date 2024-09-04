#include <ultra64.h>
#include "functions.h"
#include "variables.h"




extern void rumbleManager_80250E6C(f32, f32);
extern void func_802BB360(s32, f32);
extern void func_802BB378(s32, f32, f32);
extern void func_802BB3AC(s32, f32);
extern void func_8031B908(s32, s32, s32, f32);

/* .bss */
s32 D_8037BF10;

/* .code */
void func_802888C0(s32 arg0, s32 arg1)
{
  u8 sp1C[3];
  f32 f0;
  sp1C[0] = (arg0 >> 16) & 0xFF;
  sp1C[1] = (arg0 >> 8) & 0xFF;
  sp1C[2] = (arg0 >> 0) & 0xFF;
  f0 = reinterpret_cast(f32, arg1);
  func_8031B908(sp1C[0], sp1C[1], sp1C[2], f0);
}

void func_80288914(s32 arg0, s32 arg1, s32 arg2){
    f32 f0 = reinterpret_cast(f32, arg1);
    f32 f2 = reinterpret_cast(f32, arg2);
    func_802BB378(arg0, f0, f2);
}

void func_8028894C(s32 arg0, s32 arg1, s32 arg2){
    f32 f0 = reinterpret_cast(f32, arg1);
    f32 f2 = reinterpret_cast(f32, arg2);
    func_802BB3DC(arg0, f0, f2);
}

void func_80288984(s32 arg0, s32 arg1){
    f32 f0 = reinterpret_cast(f32, arg1);
    func_802BB360(arg0, f0);
    func_802BB3AC(arg0, 1.0f);
    func_802BB3C4(arg0);
}

void func_802889C8(s32 arg0, s32 arg1){
    f32 f0 = reinterpret_cast(f32, arg1);
    func_802BB3AC(arg0, f0);
}

void func_802889F4(s32 arg0) {
    s32 sp18;
    s32 temp_t6;
    s32 phi_a3;

    phi_a3 = arg0 >> 0x10;
    if( !(phi_a3 == 0xF2 && map_get() == MAP_91_FILE_SELECT && func_802C5A30() != 0) 
        && !((phi_a3 == 0x21 || phi_a3 == 0x3ED) && map_get() == MAP_91_FILE_SELECT && (func_802C5A30() == 1))
    ){
        func_8030E6A4(phi_a3, (f32) ((f64) ((arg0 >> 8) & 0xFF) * 0.0078125), (s32) ((f64) (arg0 & 0xFF) * 128.0));
    }
}


void func_80288AE0(s32 arg0){
    func_8025A6EC((u16) (arg0 >> 16), (u16)arg0 - 1);
}

void func_80288B14(enum sfx_e arg0){
    func_8025A7DC(arg0);
}

void func_80288B34(s32 arg0, s32 arg1){
    f32 f12 = reinterpret_cast(f32, arg0);
    f32 f14 = reinterpret_cast(f32, arg1);
    rumbleManager_80250E6C(f12, f14);
}

void func_80288B60(s32 arg0, s32 arg1, s32 arg2){
    f32 f12 = reinterpret_cast(f32, arg0);
    f32 f14 = reinterpret_cast(f32, arg1);
    f32 f0 = reinterpret_cast(f32, arg2);
    rumbleManager_80250D94(f12, f14, f0);
}

void func_80288B98(vector(struct2s) **arg0, struct2s *arg1){
    if(arg1->unk5){
        if(arg1->unk5 == 0xFF)
            return;
        if(--arg1->unk5)
            return;

        arg1->unk5 = 0xFF;
    }

     switch(arg1->unk4){
        case 0:// 80288BF8
            ((void (*)(void)) arg1->unk14)();
            break;
        case 1:// 80288C0C
            ((void (*)(s32)) arg1->unk14)(arg1->unk8);
            break;
        case 2:// 80288C24
            ((void (*)(s32, s32)) arg1->unk14)(arg1->unk8, arg1->unkC);
            break;
        case 3:// 80288C40
            ((void (*)(s32, s32, s32)) arg1->unk14)(arg1->unk8, arg1->unkC, arg1->unk10);
            break;
        case 4:// 80288C5C
            ((void (*)(u8*)) arg1->unk14)((u8*)&arg1->unk8);
            break;
     }
}

void func_80288C7C(vector(struct2s) **arg0){
    vector_clear(*arg0);
}

s32 func_80288C9C( vector(struct2s) **arg0, f32 arg1, s32 arg_cnt, void *funcPtr, s32 arg4, s32 arg5, s32 arg6){
    struct2s *ptr = (struct2s *) vector_pushBackNew(arg0);
    ptr->unk0 = arg1;
    ptr->unk4 = arg_cnt;
    ptr->unk14 = funcPtr;
    ptr->unk8 = arg4;
    ptr->unkC = arg5;
    ptr->unk10 = arg6;
    ptr->unk5 = D_8037BF10;
    D_8037BF10 = 0;

}

void func_80288D08(vector(struct2s) **arg0, f32 arg1, void *arg2){
    func_80288C9C(arg0, arg1, 0, arg2, 0, 0, 0);
}

void func_80288D40(vector(struct2s) **arg0, f32 arg1, void *arg2, s32 arg3){
    func_80288C9C(arg0, arg1, 1, arg2, arg3, 0, 0);
}

void func_80288D84(vector(struct2s) **arg0, f32 arg1, void *arg2, s32 arg3, s32 arg4){
    func_80288C9C(arg0, arg1, 2, arg2, arg3, arg4, 0);
}

void func_80288DCC(vector(struct2s) **arg0, f32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5){
    func_80288C9C(arg0, arg1, 3, arg2, arg3, arg4, arg5);
}

void func_80288E18(vector(struct2s) **arg0, f32 arg1, void *func_ptr, void* arg_ptr, s32 arg_size){
    s32 out = func_80288C9C(arg0, arg1, 4, func_ptr, 0, 0, 0);
    memcpy(out + 8, arg_ptr, arg_size);
}

void func_80288E68(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4){
    func_80288DCC(arg0, arg1, func_80288914, arg2, arg3, arg4);
}

void func_80288EB0(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4){
    func_80288DCC(arg0, arg1, func_8028894C, arg2, arg3, arg4);
}

void func_80288EF8(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3){
    func_80288D84(arg0, arg1, func_80288984, arg2, arg3);
}

void func_80288F38(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3){
    func_80288D84(arg0, arg1, func_802889C8, arg2, arg3);
}

void func_80288F78(vector(struct2s) **arg0, f32 arg1, s32 arg2){
    func_80288D40(arg0, arg1, func_802889F4, arg2);
}

void func_80288FA8(vector(struct2s) **arg0, f32 arg1, enum sfx_e sfx_id){
    func_80288D40(arg0, arg1, func_80288B14, sfx_id);
}

void func_80288FD8(vector(struct2s) **arg0, f32 arg1, s32 arg2){
    func_80288D40(arg0, arg1, func_80288AE0, arg2);
}

void func_80289008(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3){
    do{
        func_80288D84(arg0, arg1, func_80288B34, arg2, arg3);
    }while(0);
}

void func_80289048(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4){
    do{
        func_80288DCC(arg0, arg1, func_80288B60, arg2, arg3, arg4);
    }while(0);
}

void func_80289090(vector(struct2s) **arg0, f32 arg1, s32 arg2, s32 arg3){
    func_80288D84(arg0, arg1, func_802888C0, arg2, arg3);
}

void func_802890D0(VLA** arg0){
    vector_free(*arg0);
    free(arg0);
}

vector(struct2s) **func_802890FC(void){
    vector(struct2s) **ptr = (vector(struct2s) **)malloc(sizeof(vector(struct2s) **));
    *ptr = vector_new(sizeof(struct2s), 2);
    func_80288C7C(ptr);
    return ptr;
}


void func_8028913C(vector(struct2s) **arg0, s32 arg1){
    D_8037BF10 = arg1;
}

void func_8028914C(vector(struct2s) **arg0, AnimCtrl *arg1){
    struct2s *iPtr;
    for(iPtr = vector_getBegin(*arg0); iPtr != (struct2s*)vector_getEnd(*arg0); iPtr++){
        if(animctrl_isAt(arg1, iPtr->unk0))
            func_80288B98(arg0, iPtr);
    }
}
