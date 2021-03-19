#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"



extern s32 D_80283430;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025BD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025BDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025BE0C.s")

int SnSPayload_validate(SnSPayload *payload){
    u32 result[2];

    SnSPayload_calcChecksum(payload, payload->checksum, &result);
    if((payload->checksum[0] == result[0]) && (payload->checksum[1] == result[1]))
        return TRUE;
    return FALSE;
}

SnSPayload *SnSPayload_scan(void){
    SnSPayload *iPtr;
    for(iPtr = 0x80000000; iPtr < (SnSPayload  *)0x80400080; iPtr++){
        if(iPtr->catch == 0xc908c52f){
            if( SnSPayload_validate(iPtr))
                return iPtr;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025BEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025BF6C.s")

void SnSPayload_rewind(void){
    D_80283430 = 0;
}

u32 SnSPayload_getWord(SnSPayload *this){
    while(D_80283430 < 0x1C){
        if(this->packet[D_80283430]){
            return this->packet[D_80283430++];
        }
        D_80283430++;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025C070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025C07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1E360/func_8025C0A4.s")
