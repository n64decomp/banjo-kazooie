#include <ultra64.h>
#include "functions.h"
#include "variables.h"

int func_8028AED4(Actor *, f32);

extern u8 D_8037BFA0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DAC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DAE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DB04.s")

s32 func_8028DB14(ActorMarker *arg0){
    s32 retVal;
    if(D_8037BFA0)
        return 3;
    
    switch(bs_getState()){

        case BS_BBUSTER: //8028DBA4
            return func_8028DAC0(func_8029FC58(),1);
            break;
        case BS_BBARGE://8028DBC0
            return func_8028DAC0(func_8029F644(),2);
            break;
        case BS_BOMB://8028DBDC
            return func_8028DAC0(func_802A3F90(),3);
            break;
        case BS_CLAW://8028DBF8
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 90.0f))
                return 0;
            
            retVal = func_8028DAC0(func_802AB280(),4);
            if(retVal != 0)
                return retVal;
            return 8;
            break;
        case BS_BPECK://8028DC50
            if(arg0 && !func_8028AED4(marker_getActor(arg0)->position, 60.0f))
                return 0;
            return func_8028DAC0(func_802A6510(),5);
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
            return func_8028DAC0(bstwirl_hitboxActive(),7);
            break;
        case BS_CROC_BITE://L8028DCBC
            return func_8028DAC0(func_802ACF4C(),9);
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

// 8028DD10 2f
// 8028DD4C  30
// 8028DCA0 31
// 8028DD4C  32
// 8028DD4C 33
// 8028DD4C  34
// 8028DD4C 35
// 8028DD4C  36
// 8028DD4C 37
// 8028DD4C  38
// 8028DD4C 39
// 8028DD4C  3a
// 8028DD4C 3b
// 8028DD4C  3c
// 8028DCD8 3d
// 00000000  
// 00000000 
// 00000000
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6B30/func_8028DFB8.s")
