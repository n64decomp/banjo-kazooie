#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define MUMBO_TOKEN_COUNT 126
#define MUMBOSCORE_SIZE (((MUMBO_TOKEN_COUNT-1 + 7) & ~7)/8)

void mumboscore_debug(void);
void mumboscore_clear(void);

u8 sMumboTokenScore[MUMBOSCORE_SIZE];

void func_80321510(void){
    mumboscore_debug();
    mumboscore_clear();
}

u8* func_80321538(void){
    return sMumboTokenScore;
}

bool mumboscore_get(s32 indx){
    if( indx <= 0 || indx >= MUMBO_TOKEN_COUNT)
        return 0;
    return (sMumboTokenScore[(indx - 1) / 8] & (1 << (indx & 7))) != 0;
}

void mumboscore_debug(void){}

void mumboscore_clear(void){
    s32 i;
    for(i = 0; i < MUMBOSCORE_SIZE; i++){
        sMumboTokenScore[i] = 0;
    }
}

void mumboscore_set(s32 indx,  bool val){
    if( 0 < indx && indx < MUMBO_TOKEN_COUNT){
        if(val)
            sMumboTokenScore[(indx - 1) / 8] |= (1 << (indx & 7));
        else
            sMumboTokenScore[(indx - 1) / 8] &= ~(1 << (indx & 7));
    }
}

s32 mumboscore_get_total(void){
    s32 i = 1;
    s32 cnt = 0;

    for(; i < MUMBO_TOKEN_COUNT; i++){
        cnt += mumboscore_get(i);
    }
    return cnt;
}

void mumboscore_get_size_and_ptr(s32 *size, u8 **addr){
    *size = MUMBOSCORE_SIZE;
    *addr = sMumboTokenScore; 
}

