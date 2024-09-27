#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

extern Actor *actor_spawnWithYaw_f32(enum actor_e, f32[3], s32);

/* .bss */
u8 D_8037BFA0;

/* code */
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

enum hitbox_e hitbox_getHitboxForActor(ActorMarker *arg0){
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
            return __maybe(bsbpeck_hitboxActive(),HITBOX_5_PECK);
            break;
        case BS_1A_WONDERWING_ENTER:
        case BS_1B_WONDERWING_IDLE:
        case BS_1C_WONDERWING_WALK:
        case BS_1D_WONDERWING_JUMP:
        case BS_1E_WONDERWING_EXIT:
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
            if(baphysics_get_vertical_velocity() < 0.0f && !player_isStable())
                return HITBOX_A_FAST_FALLING;
        case BS_2F_FALL://8028DD10
            if(baphysics_get_vertical_velocity() < -1400.0f && !player_isStable())
                return HITBOX_A_FAST_FALLING;
        default://8028DD4C
            return HITBOX_0_NONE;
            break;
    }
}
