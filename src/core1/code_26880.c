#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_26880/func_802642A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_26880/func_802642D0.s")

void alUnlink(ALLink *ln){
    if (ln->next)
        ln->next->prev = ln->prev;
        if (ln->prev)
        ln->prev->next = ln->next;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_26880/alLink.s")
// void alLink(ALLink *ln, ALLink *to){
//     ln->next = to->next;
//     ln->prev = to;
//     if (to->next)
//         to->next->prev = ln;
//     to->next = ln;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_26880/alClose.s")
//void alClose(ALGlobals *glob)
// {
//     if (alGlobals) {
//         alSynDelete(&glob->drvr);
//         alGlobals = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_26880/alInit.s")
// void alInit(ALGlobals *g, ALSynConfig *c){
//     if (!alGlobals) { /* already initialized? */
//         alGlobals = g;
//         alSynNew(&alGlobals->drvr, c);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_26880/func_802644F0.s")
