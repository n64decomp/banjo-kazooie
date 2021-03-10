#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void alEvtqNew(ALEventQueue *evtq, ALEventListItem *items, s32 itemCount)
{
    s32 i;
    
    evtq->eventCount     = 0;
    evtq->allocList.next = 0;
    evtq->allocList.prev = 0;
    evtq->freeList.next  = 0;
    evtq->freeList.prev  = 0;
    if(itemCount > 0){
        i = 0;
        do{
            alLink(&items[i].node, &evtq->freeList);
            i++;
        } while (i != itemCount);
    }
}

ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt) 
{
    ALEventListItem *item;
    ALMicroTime delta;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    
    item = (ALEventListItem *)evtq->allocList.next;

    if (item)
    {
        alUnlink((ALLink *)item);
        alCopy(&item->evt, evt, sizeof(*evt));
        alLink((ALLink *)item, &evtq->freeList);
	delta = item->delta;
    }
    else
    {
        /* sct 11/28/95 - If we get here, most like we overflowed the event queue */
	/* with non-self-perpetuating events.  Eg. if we filled the evtq with volume */
	/* events, then when the seqp is told to play it will handle all the events */
	/* at once completely emptying out the queue.  At this point this problem */
	/* must be treated as an out of resource error and the evtq should be increased. */
	evt->type = -1;
	delta = 0;	    
    }

    osSetIntMask(mask);
    
    return delta;
}

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta)
{
    ALEventListItem     *item;
    ALEventListItem     *nextItem;
    ALLink              *node;
    s32                 postAtEnd=0;
    OSIntMask           mask;

    mask = osSetIntMask(OS_IM_NONE);


    item = (ALEventListItem *)evtq->freeList.next;
    if (!item) {
        osSetIntMask(mask);  
        return;
    }
    
    alUnlink(&item->node);
    alCopy(evt, &item->evt, sizeof(item->evt));

    if (delta == AL_EVTQ_END)
        postAtEnd = -1;
    
    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) { /* end of the list */
            if (postAtEnd)
                item->delta = 0;
            else
                item->delta = delta;
            alLink(&item->node, node);
            break;
        } else {
            nextItem = (ALEventListItem *)node->next;

            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;
                    
                alLink(&item->node, node);
                break;
            }
                
            delta -= nextItem->delta;

        }
    }

    osSetIntMask(mask);
    
}



void alEvtqFlushType(ALEventQueue *evtq, s16 type)
{
    ALLink      	*thisNode;
    ALLink      	*nextNode;
    ALEventListItem     *thisItem, *nextItem;
    OSIntMask   	mask;

    mask = osSetIntMask(OS_IM_NONE);

    thisNode = evtq->allocList.next;
    while( thisNode != 0 )
    {
	nextNode = thisNode->next;
	thisItem = (ALEventListItem *)thisNode;
	nextItem = (ALEventListItem *)nextNode;
	if (thisItem->evt.type == type)
	{
	    if (nextItem)
		nextItem->delta += thisItem->delta;
	    alUnlink(thisNode);
	    alLink(thisNode, &evtq->freeList);
	}
	thisNode = nextNode;
    }

    osSetIntMask(mask);
}


