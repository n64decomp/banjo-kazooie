#ifndef BANJO_KAZOOIE_CORE2_FLA_H
#define BANJO_KAZOOIE_CORE2_FLA_H

#include <ultra64.h>

typedef struct freelist_s{
    s16 elem_size;
    s16 elem_cnt;
    u8 unk4[];
}FLA;

#define FREE_LIST(T) struct freelist_s
//^defined to keep element type with sla

void freelist_clear(FLA *this);
void *freelist_at(FLA *this, s32 indx);
s32 freelist_size(FLA *this);
void *freelist_freeListPtr(FLA *this);
void *freelist_next(FLA **this_ptr, s32 *arg1);
bool freelist_elementIsAlive(FLA *this, s32 index);
void freelist_free(FLA *this);
FLA *freelist_new(s32 size, s32 cnt);
void freelist_freeElement(FLA *this, s32 indx);
FLA *freelist_defrag(FLA *this);

#endif
