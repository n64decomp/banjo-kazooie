#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025CD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/alEvtqPostEvent.s")
// void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta)
// {
//     ALEventListItem     *item;
//     ALEventListItem     *nextItem;
//     ALLink              *node;
//     s32                 postAtEnd=0;
//     OSIntMask           mask;

//     mask = osSetIntMask(OS_IM_NONE);


//     item = (ALEventListItem *)evtq->freeList.next;
//     if (!item) {
//         osSetIntMask(mask);
// #ifdef _DEBUG
//         __osError(ERR_ALEVENTNOFREE, 0);
// #endif        
//         return;
//     }
    
//     alUnlink(&item->node);
//     alCopy(evt, &item->evt, sizeof(item->evt));

//     if (delta == AL_EVTQ_END)
//         postAtEnd = -1;
    
//     for (node = &evtq->allocList; node != 0; node = node->next) {
//         if (!node->next) { /* end of the list */
//             if (postAtEnd)
//                 item->delta = 0;
//             else
//                 item->delta = delta;
//             alLink(&item->node, node);
//             break;
//         } else {
//             nextItem = (ALEventListItem *)node->next;

//             if (delta < nextItem->delta) {
//                 item->delta = delta;
//                 nextItem->delta -= delta;
                    
//                 alLink(&item->node, node);
//                 break;
//             }
                
//             delta -= nextItem->delta;

//         }
//     }

//     osSetIntMask(mask);
    
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025CF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025CFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025D030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025D130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025D1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025D200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1F330/func_8025D208.s")
