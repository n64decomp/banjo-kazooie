#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct {
    void *unk0;
    int unk4;
} D_80282FE0;
extern u8 D_8000E800;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15770/func_80253190.s")

void func_80253208(Gfx **gdl, s32 x, s32 y, s32 w, s32 h, void *color_buffer){
    if( D_80282FE0.unk0 != NULL && (getGameMode() != GAME_MODE_PAUSED || func_80335134())){
        //draw z_buffer
        gDPPipeSync((*gdl)++);
        gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, OS_K0_TO_PHYSICAL(D_80282FE0.unk0));
        gDPSetCycleType((*gdl)++, G_CYC_FILL);
        gDPSetRenderMode((*gdl)++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor((*gdl)++, 0xFFFCFFFC);
        gDPScisFillRectangle((*gdl)++, x, y, x + w - 1, y + h - 1);
        
        //draw color_buffer
        gDPPipeSync((*gdl)++);
        gDPSetColorImage((*gdl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, OS_K0_TO_PHYSICAL(color_buffer));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15770/func_80253400.s")

int func_8025340C(void){
    return D_80282FE0.unk0 != NULL;
}

void func_80253420(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15770/func_80253428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15770/func_802534A8.s")

//zBuffer_set
void func_802534CC(Gfx **gdl){
    if(D_80282FE0.unk0 && getGameMode() != GAME_MODE_PAUSED){
        gDPPipeSync((*gdl)++);
        gDPSetDepthImage((*gdl)++, D_80282FE0.unk0);
    }
}

//zBuffer_get
void *func_80253540(void){
    return D_80282FE0.unk0;
}
