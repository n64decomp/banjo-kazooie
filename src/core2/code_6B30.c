#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_8037BFA0;

static s32 __maybe(int arg0, s32 arg1){
    if(arg0)
        return arg1;
    return 0;
}

void func_8028DAD8(void){
    D_8037BFA0 = 0;
}

void func_8028DAE4(void){
    if(D_8037BFA0 != 0)
        D_8037BFA0--;
}

void func_8028DB04(void){
    D_8037BFA0 = 2;
}

enum hitbox_e func_8028DB14(ActorMarker *arg0){
    s32 retVal;
    if(D_8037BFA0)
        return HITBOX_3_BEAK_BOMB;
    
    switch(bs_getState()){

        case BS_F_BBUSTER: //8028DBA4
            return __maybe(bsbbuster_hitboxActive(),HITBOX_1_BEAK_BUSTER);
            break;
        case BS_BBARGE://8028DBC0
            return __maybe(bsbbarge_hitboxActive(),HITBOX_2_BEAK_BARGE);
            break;
        case BS_BOMB://8028DBDC
            return __maybe(bsbfly_bombHitboxActive(),HITBOX_3_BEAK_BOMB);
            break;
        case BS_CLAW://8028DBF8
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 90.0f))
                return HITBOX_0_NONE;
            
            retVal = __maybe(bsclaw_hitboxActive(),HITBOX_4_CLAW);
            if(retVal != 0)
                return retVal;
            return HITBOX_8_CLAW_DOWN;
            break;
        case BS_11_BPECK://8028DC50
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 60.0f))
                return HITBOX_0_NONE;
            return __maybe(func_802A6510(),HITBOX_5_PECK);
            break;
        case BS_WONDERWING_ENTER:
        case BS_1B_WONDERWING_IDLE:
        case BS_WONDERWING_WALK:
        case BS_WONDERWING_JUMP:
        case BS_WONDERWING_EXIT:
        case BS_A4_WONDERWING_DRONE:
        case BS_A5_WONDERWING_UNKA5://L8028DC98
            return HITBOX_6_WONDERWING;
            break;
        //8028DCA0
        case BS_ROLL:
            return __maybe(bstwirl_hitboxActive(),HITBOX_7_ROLL);
            break;
        case BS_6E_CROC_BITE://L8028DCBC
            return __maybe(bscroc_hitboxActive(),HITBOX_9_CROC_BITE);
            break;
        case BS_5_JUMP://8028DCD8
        case BS_3D_FALL_TUMBLING:
            if(func_80297AAC() < 0.0f && !func_8028B2E8())
                return HITBOX_A_FAST_FALLING;
        case BS_2F_FALL://8028DD10
            if(func_80297AAC() < -1400.0f && !func_8028B2E8())
                return HITBOX_A_FAST_FALLING;
        default://8028DD4C
            return HITBOX_0_NONE;
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DFB8.s")
