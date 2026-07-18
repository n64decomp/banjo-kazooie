#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/statetimer.h"
extern void player_stateTimer_set(s32, f32);
extern f32 player_stateTimer_get(enum state_timer_e);

s32 D_80390F30 = VER_SELECT(0x00274530, 0x002764CA, 0, 0); // GV_TEXT_CRC1
s32 D_80390F34 = VER_SELECT(0xAA18BBF3, 0xFB1E80F4, 0, 0); // GV_TEXT_CRC2
s32 D_80390F38 = VER_SELECT(0x0003031C, 0x00031973, 0, 0); // GV_DATA_CRC1


/* .code */
#if ANTI_TAMPER
void code3B10_makeRunningShoesRunOutInstantly(void){
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO && 2.0f < player_stateTimer_get(STATE_TIMER_3_TURBO_TALON)){
        player_stateTimer_set(STATE_TIMER_3_TURBO_TALON, 2.0f);
    }
}
#endif

void code3B10_checkGVChecksums(void){
#if ANTI_TAMPER
    u32 rom_data;
    osPiReadIo(0x800, &rom_data);
    rom_data <<= 0x10;
    if(rom_data != 0x10000)
        code3B10_makeRunningShoesRunOutInstantly();
#endif
}
