#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_C9E70.h"

extern struct FF_StorageStruct *ffStorage;

void code_C9E70_defrag(void){
    quizQuestionAskedBitfield_defrag();
    gcquiz_defrag();
    if(ffStorage == NULL)
        return;
    
    if(ffStorage->zoombox){
        gczoombox_defrag(ffStorage->zoombox);
        ffStorage->zoombox = (GcZoombox *)defrag(ffStorage->zoombox);
    }
    ffStorage->unk48 = (struct FF_StorageStruct_48 *)defrag(ffStorage->unk48);
    ffStorage = (struct FF_StorageStruct *) defrag(ffStorage);
}
