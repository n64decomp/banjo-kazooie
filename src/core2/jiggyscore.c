#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u32 jiggyscore_isCollected(enum jiggy_e);
void jiggyscore_debug(void);
void jiggyscore_clearAll(void);
void jiggyscore_setSpawned(s32, s32);

/* .bss */
struct {
    u8 D_803832C0[0xD];
    u8 D_803832CD[0xD];
}jiggyscore;

/* .code */
void jiggyscore_clearAll_debug(void){ //jiggyscore_clearAll
    jiggyscore_debug();
    jiggyscore_clearAll();
}

void *jiggyscore_clearAllSpawned(void) {
    s32 i;
    for(i = 0; i < 0x0D; i++){
        jiggyscore.D_803832CD[i] = 0;
    }
}

u8* jiggyscore_getPtr(void){
    return jiggyscore.D_803832C0;
}

int jiggyscore_isSpawned(enum jiggy_e jiggy_id) {
    return ((jiggyscore.D_803832CD[(jiggy_id - 1) / 8] & (1 << (jiggy_id & 7))) != 0) 
           || (jiggyscore_isCollected(jiggy_id) != 0);
}

u32 jiggyscore_isCollected(enum jiggy_e jiggy_id){
    if( jiggy_id <= 0 || jiggy_id >= 0x65)
        return 0;
    return (jiggyscore.D_803832C0[(jiggy_id - 1) / 8] & (1 << (jiggy_id & 7))) != 0;
}

void jiggyscore_debug(void){}

void jiggyscore_clearAll(void){
    s32 i;
    for(i = 0; i < 0x0D; i++){
        jiggyscore.D_803832C0[i] = 0;
    }
    jiggyscore_clearAllSpawned();
}

void jiggyscore_setCollected(s32 indx,  s32 val){
    if( 0 < indx && indx < 0x65){
        if(val)
            jiggyscore.D_803832C0[(indx - 1) / 8] |= (1 << (indx & 7));
        else
            jiggyscore.D_803832C0[(indx - 1) / 8] &= ~(1 << (indx & 7));
    }
}

void jiggyscore_setSpawned(s32 indx, s32 val) {
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (val) {
        temp_v0 = (u8*)(((s32) (indx - 1) / 8) + 0xD);
        temp_v0 += (s32) jiggyscore.D_803832C0;
        *temp_v0 |= (1 << (indx & 7));
        return;
    }
    temp_v0_2 = (u8*)(((s32) (indx - 1) / 8) + 0xD);
    temp_v0_2 += (s32)jiggyscore.D_803832C0;
    *temp_v0_2 &=  ~(1 << (indx & 7));
}

s32 jiggyscore_leveltotal(s32 lvl) {
    s32 i;
    s32 start;
    s32 end;
    s32 cnt;

    if (lvl <= 0 || lvl == 0xB || lvl >= 0xB)
        return 0;

    cnt = 0;
    start = (lvl - 1)*10 + 1;
    end = (lvl)*10 + 1;
    for(i = start; i < end; i++ ){
        if(jiggyscore_isCollected(i))
            cnt++;
    }
    return cnt;
}

s32 jiggyscore_total(void) {
    s32 i;
    s32 cnt;
    
    for(i = 0, cnt = 0; i < 0xC; i++){
        cnt += jiggyscore_leveltotal(i);
    }
    return cnt;
}

void jiggyscore_info(s32 *size, u8 **addr){
    *size = 0x0D;
    *addr = jiggyscore.D_803832C0; 
}
