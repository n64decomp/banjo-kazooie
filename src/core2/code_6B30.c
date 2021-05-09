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

s32 func_8028DB14(ActorMarker *arg0){
    s32 retVal;
    if(D_8037BFA0)
        return 3;
    
    switch(bs_getState()){

        case BS_BBUSTER: //8028DBA4
            return __maybe(func_8029FC58(),1);
            break;
        case BS_BBARGE://8028DBC0
            return __maybe(func_8029F644(),2);
            break;
        case BS_BOMB://8028DBDC
            return __maybe(func_802A3F90(),3);
            break;
        case BS_CLAW://8028DBF8
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 90.0f))
                return 0;
            
            retVal = __maybe(bsclaw_hitboxActive(),4);
            if(retVal != 0)
                return retVal;
            return 8;
            break;
        case BS_BPECK://8028DC50
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 60.0f))
                return 0;
            return __maybe(func_802A6510(),5);
            break;
        case BS_WONDERWING_ENTER:
        case BS_WONDERWING_IDLE:
        case BS_WONDERWING_WALK:
        case BS_WONDERWING_JUMP:
        case BS_WONDERWING_EXIT:
        case BS_WONDERWING_UNKA4:
        case BS_WONDERWING_UNKA5://L8028DC98
            return 6;
            break;
        //8028DCA0
        case BS_ROLL:
            return __maybe(bstwirl_hitboxActive(),7);
            break;
        case BS_CROC_BITE://L8028DCBC
            return __maybe(bscroc_hitboxActive(),9);
            break;
        case BS_JUMP://8028DCD8
        case BS_FALL_TUMBLING:
            if(func_80297AAC() < 0.0f && !func_8028B2E8())
                return 0xa;
        case BS_FALL://8028DD10
            if(func_80297AAC() < -1400.0f && !func_8028B2E8())
                return 0xa;
        default://8028DD4C
            return 0;
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
