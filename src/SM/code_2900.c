#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
#if !DISABLE_PIRACY_CHECKS
void code2900_moveBridgeOutOfBounds(void){
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO){
        func_8034DEB4(func_8034C528(0x1F2), 0.0f);
        func_8034DEB4(func_8034C528(0x1F3), -5000.0f);
    }
}
#endif

void code2900_checkSMChecksums(void){
#if !DISABLE_PIRACY_CHECKS
    if(*(u32*)PHYS_TO_K1(0x200) - PHYS_TO_K1(0xC290000)){
        code2900_moveBridgeOutOfBounds();
    }
#endif
}
