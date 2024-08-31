#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/code_C9E70.h"

extern struct FF_StorageStruct *D_8037DCB8;

void func_80350E00(void){
    quizQuestionAskedBitfield_defrag();
    func_8031A4CC();
    if(D_8037DCB8 == NULL)
        return;
    
    if(D_8037DCB8->unk20){
        func_80318C0C(D_8037DCB8->unk20);
        D_8037DCB8->unk20 = (gczoombox_t *)defrag(D_8037DCB8->unk20);
    }
    D_8037DCB8->unk48 = (struct FF_StorageStruct_48 *)defrag(D_8037DCB8->unk48);
    D_8037DCB8 = (struct FF_StorageStruct *) defrag(D_8037DCB8);
}
