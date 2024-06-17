#include "functions.h"

#include "core2/ba/carry.h"


void bacarry_set_offsets(f32 arg0, f32 arg1);

/* .bss */
struct {
    f32 height;
    f32 rotation;
} bacarry_offsets;
ActorMarker* baCarry_marker;
u8 bacarry_active;

/* .code */
void bacarry_init(void){
    baCarry_marker = NULL;
    bacarry_active = 0;
    bacarry_set_offsets(0.0f, 0.0f);
}

void bacarry_end(void){}

void __bacarry_set_position_and_rotation(ActorMarker *marker, f32 arg1[3], f32 arg2[3]){
    Actor * actor = marker_getActor(marker);
    if(actor->unk138_22){
        actor->position_x = arg1[0];
        actor->position_y = arg1[1];
        actor->position_z = arg1[2];

        actor->yaw = arg2[1];
    }
}

void __bacarry_update(void){
    f32 banjoPos[3];
    f32 banjoRot[3];
    
    
    player_getRotation(banjoRot);
    baModel_getPosition(banjoPos);
    banjoRot[1] = mlNormalizeAngle(banjoRot[1] + bacarry_offsets.rotation);
    banjoPos[1] += bacarry_offsets.height;
    __bacarry_set_position_and_rotation(baCarry_marker, banjoPos, banjoRot);
}

void bacarry_update(void){
    if(baCarry_marker != NULL){
        if(bacarry_active == 0){
            baCarry_marker = NULL;
        }
        else{
            __bacarry_update();
            bacarry_active = 0;
        }
    }
}

void bacarry_reset_marker(void){
    baCarry_marker = NULL;
}

ActorMarker *bacarry_get_marker(void){
   return baCarry_marker; 
}

void bacarry_set_marker(ActorMarker *arg0){
    baCarry_marker = arg0;
    __bacarry_update();
    bacarry_active = 1;
}

void bacarry_set_offsets(f32 height, f32 rotation){
    bacarry_offsets.height = height;
    bacarry_offsets.rotation = rotation;
}
