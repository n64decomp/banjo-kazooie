#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_C9E70.h"

extern struct FF_StorageStruct *D_8037DCB8;

void func_80350E00(void){
    quizQuestionAskedBitfield_defrag();
    func_8031A4CC();
    if(D_8037DCB8 == NULL)
        return;
    
    if(D_8037DCB8->unk20){
        gczoombox_defrag(D_8037DCB8->unk20);
        D_8037DCB8->unk20 = (GcZoombox *)defrag(D_8037DCB8->unk20);
    }
    D_8037DCB8->unk48 = (struct FF_StorageStruct_48 *)defrag(D_8037DCB8->unk48);
    D_8037DCB8 = (struct FF_StorageStruct *) defrag(D_8037DCB8);
}
