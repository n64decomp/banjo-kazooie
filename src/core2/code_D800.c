#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"


void func_80294924(f32 arg0, f32 arg1);

/* .bss */
struct {
    f32 unk0;
    f32 unk4;
} D_8037C290;
ActorMarker* D_8037C298;
u8 D_8037C29C;

/* .code */
void func_80294790(void){
    D_8037C298 = NULL;
    D_8037C29C = 0;
    func_80294924(0.0f, 0.0f);
}

void func_802947C4(void){}

void func_802947CC(ActorMarker *marker, f32 arg1[3], f32 arg2[3]){
    Actor * actor = marker_getActor(marker);
    if(actor->unk138_22){
        actor->position_x = arg1[0];
        actor->position_y = arg1[1];
        actor->position_z = arg1[2];

        actor->yaw = arg2[1];
    }
}

void func_80294828(void){
    f32 banjoPos[3];
    f32 banjoRot[3];
    
    
    player_getRotation(banjoRot);
    playerModel_getPosition(banjoPos);
    banjoRot[1] = mlNormalizeAngle(banjoRot[1] + D_8037C290.unk4);
    banjoPos[1] += D_8037C290.unk0;
    func_802947CC(D_8037C298, banjoPos, banjoRot);
}

int func_80294890(void){
    if(D_8037C298){
        if(D_8037C29C == 0){
            D_8037C298 = NULL;
        }
        else{
            func_80294828();
            D_8037C29C = 0;
        }
    }
}

void func_802948E0(void){
    D_8037C298 = NULL;
}

ActorMarker *carriedobj_getMarker(void){
   return D_8037C298; 
}

void func_802948F8(ActorMarker *arg0){
    D_8037C298 = arg0;
    func_80294828();
    D_8037C29C = 1;
}

void func_80294924(f32 arg0, f32 arg1){
    D_8037C290.unk0 = arg0;
    D_8037C290.unk4 = arg1;
}
