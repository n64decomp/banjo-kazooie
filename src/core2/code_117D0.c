#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
struct50s D_80364450[] = 
{
    {0x01, 0x01, 510.0f, -1200.0f, 200.0f},
    {0x02, 0x01, 600.0f, -1500.0f, 300.0f},
    {0x03, 0x01, 510.0f, -1200.0f, 100.0f},
    {0x04, 0x01, 510.0f, -1200.0f, 200.0f},
    {0x05, 0x01, 510.0f, -1200.0f, 300.0f},
    {0x06, 0x01, 510.0f, -1200.0f, 400.0f},
    {0x07, 0x01, 510.0f, -1200.0f, 500.0f},
    {0x08, 0x01, 600.0f, -1500.0f, 100.0f},
    {0x09, 0x01, 600.0f, -1500.0f, 200.0f},
    {0x0A, 0x01, 600.0f, -1500.0f, 300.0f},
    {0x0B, 0x01, 600.0f, -1500.0f, 400.0f},
    {0x0C, 0x01, 600.0f, -1500.0f, 500.0f},
    {0x0D, 0x02, 300.0f, -1200.0f, 0.0f},
    {0x0F, 0x01, 300.0f, -1200.0f, 0.0f},
    {0x0E, 0x03, 300.0f, -1200.0f, 0.0f},
    {0x10, 0x03, 300.0f, -1200.0f, 0.0f},
    {00}
};

/*.bss*/
extern struct{
    struct50s *unk0;
    f32 unk4[3];
}D_8037C5E0;

/*.code*/
int func_80298760(s32 arg0){
    int i;
    for(i = 0; D_80364450[i].unk0; i++){
        if(arg0 == D_80364450[i].unk0){
            D_8037C5E0.unk0 = D_80364450 + i;
            break;
        }
    }
}

s32 func_802987B4(void){
    return D_8037C5E0.unk0->unk1;
}

f32 func_802987C4(void){
    return D_8037C5E0.unk0->unk4[0];
}

f32 func_802987D4(void){
    return D_8037C5E0.unk0->unk4[2];
}

f32 func_802987E4(void){
    return D_8037C5E0.unk0->unk4[1];
}
