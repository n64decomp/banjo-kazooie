#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct {
    s32 eggCount;
    s32 unk4;
    s32 unk8;
} rubeeEggPot;

/* .code */
void rubeeEggPot_addedEggToPot(void){
    rubeeEggPot.eggCount++;
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 26000);
}

s32 func_8038E178(void){
    return rubeeEggPot.eggCount;
}

s32 rubeeEggPot_getEggGoal(void){
    return 5;
}

void func_8038E18C(void){
    rubeeEggPot.unk8 = TRUE;
}
