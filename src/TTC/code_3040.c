#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "checksums.h"

s32 D_8038C750 = VER_SELECT(0x0016D2FD, 0x0016D2D7, 0, 0); // TTC_TEXT_CRC1
s32 D_8038C754 = VER_SELECT(0xFB70B01D, 0xFCA4DD1E, 0, 0); // TTC_TEXT_CRC2
s32 D_8038C758 = VER_SELECT(0x0004EFAC, 0x0004FD17, 0, 0); // TTC_DATA_CRC1

/* .code */
#if ANTI_TAMPER
void __code3040_makeBanjoAlwaysSlippery(){
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO){
        func_8029CF48(2, 1, 0.0f);
    }
}
#endif

void code3040_checkTTCChecksums(void){
#if ANTI_TAMPER
    if(gChecksumsTTC.text_checksum2 != D_8038C754 ||  gChecksumsTTC.data_checksum2 != D_80276CB0){
        __code3040_makeBanjoAlwaysSlippery();
    }
#endif
}
