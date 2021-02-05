#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "rarezip.h"

extern u8 D_F19250;
extern u8 D_F37F90;
extern u8 D_8002D500;
extern u8 D_8023DA20;
extern u32 D_803FFE00[4];

void func_80000594(u8 *, u8 *);

void func_80001D70(void);
void func_80002000(s32, u32, void*, u32);
void func_8023DA20(s32);

void func_80000450(s32 arg0){
    u8 *tmp;
    u8 *dst;
    
    tmp = &D_8002D500;
    dst = &D_8023DA20;
    func_80001D70();
    func_80002000(0, &D_F19250, tmp, &D_F37F90 - &D_F19250);
    while(func_800020E0() & 1 != 0);
    func_8000055C();
    func_80000594(&tmp, &dst);
    D_803FFE00[0] = D_8000729C;
    D_803FFE00[1] = D_800072A0;
    func_80000594(&tmp, &dst);
    D_803FFE00[2] = D_8000729C;
    D_803FFE00[3] = D_800072A0;
    func_80001BF0();
    (&func_8023DA20)(arg0);
    
}