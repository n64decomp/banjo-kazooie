#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/statetimer.h"
extern void player_stateTimer_set(s32, f32);
extern f32 player_stateTimer_get(enum state_timer_e);

/* .data */
//TODO Implement CRC calculation in Makefile(?)
u32 D_80390F30 = 0x00274530; //GV.code CRC1
u32 D_80390F34 = 0xAA18BBF3; //GV.code CRC2
u32 D_80390F38 = 0x0003031C; //GV.data CRC1 (with this value = 0)


/* .code */
#if !DISABLE_PIRACY_CHECKS
void code3B10_makeRunningShoesRunOutInstantly(void){
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO && 2.0f < player_stateTimer_get(STATE_TIMER_3_TURBO_TALON)){
        player_stateTimer_set(STATE_TIMER_3_TURBO_TALON, 2.0f);
    }
}
#endif

void code3B10_checkGVChecksums(void){
#if !DISABLE_PIRACY_CHECKS
    u32 rom_data;
    osPiReadIo(0x800, &rom_data);
    rom_data <<= 0x10;
    if(rom_data != 0x10000)
        code3B10_makeRunningShoesRunOutInstantly();
#endif
}
