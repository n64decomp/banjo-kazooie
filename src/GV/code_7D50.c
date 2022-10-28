#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct {
    s32 unk0;
    u8 pad4[4];
    s32 unk8;
}GV_D_80391AB0;

/* .code */
void func_8038E140(void){
    GV_D_80391AB0.unk0++;
    func_8025A6EC(COMUSIC_2B_DING_B, 26000);
}

s32 func_8038E178(void){
    return GV_D_80391AB0.unk0;
}

s32 func_8038E184(void){
    return 5;
}

void func_8038E18C(void){
    GV_D_80391AB0.unk8 = TRUE;
}
