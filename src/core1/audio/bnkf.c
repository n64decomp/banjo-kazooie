#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* copt used??? */

void _bnkfPatchWaveTable(void){}

void _bnkfPatchSound(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/bnkf/_bnkfPatchInst.s")


void _bnkfPatchBank(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/audio/bnkf/alBnkfNew.s")


void alSeqFileNew(ALSeqFile *file, u8 *base)
{
    s32 offset = (s32) base;
    s32 i;
    
    /*
     * patch the file so that offsets are pointers
     */
    for (i = 0; i < file->seqCount; i++) {
        file->seqArray[i].offset = (u8 *)((u8 *)file->seqArray[i].offset + offset);
    }
}