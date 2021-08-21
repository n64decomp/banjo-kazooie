#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct {
    void *unk0;
    int unk4;
} D_80282FE0;

extern u8 D_8000E800;
extern u8 D_803A5D00[2][0x1ecc0];

void func_80253208(Gfx **gdl, s32 x, s32 y, s32 w, s32 h, void *color_buffer);

void func_80253190(Gfx **gdl){
    func_80253208(gdl, 0, 0, D_80276588, D_8027658C, D_803A5D00[func_8024BDA0()]);
}

void func_80253208(Gfx **gdl, s32 x, s32 y, s32 w, s32 h, void *color_buffer){
    if( D_80282FE0.unk0 != NULL && (getGameMode() != GAME_MODE_4_PAUSED || func_80335134())){
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

int func_80253400(void){
    return D_80282FE0.unk4;
}

int func_8025340C(void){
    return D_80282FE0.unk0 != NULL;
}

void func_80253420(void){}

#if NONMATCHING
void func_80253428(int arg0){
    s32 i;

    if(arg0){
        D_80282FE0.unk0 = &D_8000E800;
        while((s32)D_80282FE0.unk0 % 0x40){
            D_80282FE0.unk0 = (s32)D_80282FE0.unk0 + 2;
        }
    }else{//L80253494
        D_80282FE0.unk0 = NULL;
        
    }//L802534A0
    D_80282FE0.unk4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_15770/func_80253428.s")
#endif

void func_802534A8(int arg0){
    D_80282FE0.unk4 = (D_80282FE0.unk0 != NULL && arg0);
}

//zBuffer_set
void func_802534CC(Gfx **gdl){
    if(D_80282FE0.unk0 && getGameMode() != GAME_MODE_4_PAUSED){
        gDPPipeSync((*gdl)++);
        gDPSetDepthImage((*gdl)++, D_80282FE0.unk0);
    }
}

//zBuffer_get
void *func_80253540(void){
    return D_80282FE0.unk0;
}
