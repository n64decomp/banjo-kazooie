#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0:24;
    s32 unk3:8;
    s32 unk4;
} Struct_Core2_32DB0_0s;

void func_802B9E00(s32 arg0);
s32 func_802B9EA8(s32 arg0);
void func_802B9EBC(s32 arg0, s32 arg1);

/* .bss */
Struct_Core2_32DB0_0s D_8037D5E0[];

/* .code */
void func_802B9D40(void){
    int i;
    for(i = 0; i< 0x46; i++){
        D_8037D5E0[i].unk3 = 0;
    }
}

void func_802B9D80(void){
    int i;

    for(i=0; i< 0x46; i++){
        if(func_802B9EA8(i))
            func_802B9E00(i);
    }
}

void func_802B9DD0(s32 arg0){
    D_8037D5E0[arg0].unk3 = 1;
    D_8037D5E0[arg0].unk0 = 0;

}

void func_802B9E00(s32 arg0){
    func_802B9EBC(arg0, 0);
    D_8037D5E0[arg0].unk3 = 0;
}

s32 func_802B9E34(s32 arg0){
    return D_8037D5E0[arg0].unk4;
}

s32 func_802B9E48(s32 arg0){
    return D_8037D5E0[arg0].unk4;
}

s32 func_802B9E5C(s32 arg0){
    return D_8037D5E0[arg0].unk4;
}

s32 func_802B9E70(s32 arg0){
    return D_8037D5E0[arg0].unk4;
}

s32 func_802B9E84(void){
    return 0x46;
}

s32 func_802B9E8C(s32 arg0){
    return D_8037D5E0[arg0].unk0;
}

s32 func_802B9EA8(s32 arg0){
    return D_8037D5E0[arg0].unk3;
}

void func_802B9EBC(s32 arg0, s32 arg1){
    if(arg1 == D_8037D5E0[arg0].unk0)
        return;
    switch(D_8037D5E0[arg0].unk0){
        case 4:// L802B9F08
            func_802BA214(D_8037D5E0[arg0].unk4);
            break;
        case 3:// L802B9F18
            func_802BA398(D_8037D5E0[arg0].unk4);
            break;
        case 1:// L802B9F28
            func_802BA76C(D_8037D5E0[arg0].unk4);
            break;
        case 2:// L802B9F38
            func_802BAA88(D_8037D5E0[arg0].unk4);
            break;
        case 0:// L802B9F40
            break;
    }
    D_8037D5E0[arg0].unk0 = arg1;
    switch (arg1)
    {
    case 4:// L802B9F80
        D_8037D5E0[arg0].unk4 = func_802BA1E0();
        break;
    case 3:// L802B9F90
        D_8037D5E0[arg0].unk4 = func_802BA2F4();
        break;
    case 1:// L802B9FA0
        D_8037D5E0[arg0].unk4 = func_802BA6D4();
        break;
    case 2:// L802B9FB0
        D_8037D5E0[arg0].unk4 = func_802BAA40();
        break;
    case 0:// L802B9FBC
        break;
    }

}

void func_802B9FD0(Struct61s *file_ptr, s32 arg1){
    u8 sp27;
    func_802B9DD0(arg1);
    func_8034B040(file_ptr, 2, &sp27);
    func_802B9EBC(arg1, sp27);
    switch(func_802B9E8C(arg1)){
        case 4:// L802BA030
            func_802BA244(file_ptr, func_802B9E34(arg1));
            break;
        case 3:// L802BA04C
            func_802BA550(file_ptr, func_802B9E48(arg1));
            break;
        case 1:// L802BA068
            func_802BA93C(file_ptr, func_802B9E5C(arg1));
            break;
        case 2:// L802BA084
            func_802BAB3C(file_ptr, func_802B9E70(arg1));
            break;
        case 0:// L802BA098
            break;
    }
}

void func_802BA0AC(Struct61s *file_ptr){
    s16 sp26;
    func_802B9D80();
    func_802B9D40();
    while(!func_8034AF98(file_ptr, 0)){
        if(func_8034B220(file_ptr, 1, &sp26))
            func_802B9FD0(file_ptr, sp26);
    }

}

void func_802BA128(void){
    int i;
    for(i = 0; i< 0x46; i++){
        if(D_8037D5E0[i].unk3){
            switch(D_8037D5E0[i].unk0){
                case 4:// L802BA17C
                    D_8037D5E0[i].unk4 = defrag(D_8037D5E0[i].unk4);
                    break;
                case 3:// L802BA18C
                    D_8037D5E0[i].unk4 = defrag(D_8037D5E0[i].unk4);
                    break;
                case 1:// L802BA19C
                    D_8037D5E0[i].unk4 = defrag(D_8037D5E0[i].unk4);
                    break;
                case 2:// L802BA1AC
                    D_8037D5E0[i].unk4 = defrag(D_8037D5E0[i].unk4);
                    break;
                case 0:// L802BA1B8
                    break;
            }
        }
    }
}

