#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80321598(void);
void func_803215A0(void);

extern u8 D_803832F0[0x10];

void func_80321510(void){
    func_80321598();
    func_803215A0();
}

u8* func_80321538(void){
    return D_803832F0;
}

s32 func_80321544(s32 indx){
    if( indx <= 0 || indx >= 0x7E)
        return 0;
    return (D_803832F0[(indx - 1) / 8] & (1 << (indx & 7))) != 0;
}

void func_80321598(void){}

void func_803215A0(void){
    s32 i;
    for(i = 0; i < 0x10; i++){
        D_803832F0[i] = 0;
    }
}

void func_803215D0(s32 indx,  s32 val){
    if( 0 < indx && indx < 0x7E){
        if(val)
            D_803832F0[(indx - 1) / 8] |= (1 << (indx & 7));
        else
            D_803832F0[(indx - 1) / 8] &= ~(1 << (indx & 7));
    }
}

s32 func_80321664(void){
    s32 i = 1;
    s32 cnt = 0;

    for(; i < 0x7E; i++){
        cnt += func_80321544(i);
    }
    return cnt;
}

void func_803216B4(s32 *size, u8 **addr){
    *size = 0x10;
    *addr = &D_803832F0; 
}

