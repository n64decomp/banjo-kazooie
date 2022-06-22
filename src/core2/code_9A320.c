#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define HONEYCOMB_COUNT 0x19
#define HONEYCOMBSCORE_SIZE (((HONEYCOMB_COUNT-1 + 7) & ~7)/8)

void honeycombscore_debug(void);
void honeycombscore_clear(void);

/* .bss */
extern u8 sHoneycombScore[3];

/* .code */
void func_803212B0(void){
    honeycombscore_debug();
    honeycombscore_clear();
}

u8 *honeycombscore_get_ptr(void){
    return sHoneycombScore;
}

bool honeycombscore_get(enum honeycomb_e indx){
    if( indx <= 0 || indx >= HONEYCOMB_COUNT)
        return 0;
    return (sHoneycombScore[(indx - 1) / 8] & (1 << (indx & 7))) != 0;
}

void honeycombscore_debug(void){}

void honeycombscore_clear(void){
    s32 i;
    for(i = 0; i < HONEYCOMBSCORE_SIZE; i++){
        sHoneycombScore[i] = 0;
    }
}

void honeycombscore_set(enum honeycomb_e indx,  bool val){
    if( 0 < indx && indx < HONEYCOMB_COUNT){
        if(val)
            sHoneycombScore[(indx - 1) / 8] |= (1 << (indx & 7));
        else
            sHoneycombScore[(indx - 1) / 8] &= ~(1 << (indx & 7));
    }
}

s32 honeycombscore_get_level_total(enum level_e level_id){
    s32 v1;
    s32 s2;
    int i;
    s32 total;

    if(level_id <= 0 || level_id == LEVEL_6_LAIR || level_id >= 0xC)
        return 0;

    v1 = level_id*2 - 1;
    v1 = (level_id < 7) ? v1 : v1 - 2;

    s2 = (level_id*2 - 1 == 0x15) ? v1 + 6 : v1 + 2;
    for(i = v1, total = 0; i<s2; i++){
        if(honeycombscore_get(i))
            total++;
    }
    return total;
        
}

s32 honeycombscore_get_total(void){
    int i;
    s32 total;

    for(i = 0, total = 0; i < 0xC; i++){
        total += honeycombscore_get_level_total(i);
    }
    return total;
}

void honeycombscore_get_size_and_ptr(s32 *size, u8 **addr){
    *size = HONEYCOMBSCORE_SIZE;
    *addr = sHoneycombScore;
}
