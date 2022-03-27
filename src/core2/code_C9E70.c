#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8 pad0[0x20];
    gczoombox_t *unk20;
    u8 pad24[0x24];
    void *unk48;
}Struct_core2_C9E70_0;

Struct_core2_C9E70_0 *D_8037DCB8;

void func_80350E00(void){
    func_803208F0();
    func_8031A4CC();
    if(D_8037DCB8 == NULL)
        return;
    
    if(D_8037DCB8->unk20){
        func_80318C0C(D_8037DCB8->unk20);
        D_8037DCB8->unk20 = defrag(D_8037DCB8->unk20);
    }
    D_8037DCB8->unk48 = defrag(D_8037DCB8->unk48);
    D_8037DCB8 = defrag(D_8037DCB8);
}
