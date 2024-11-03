#include <ultra64.h>
#include "functions.h"

#include "core2/ba/drone.h"

/* .bss */
struct {
    u8 type;
    // u8 pad1[3];
    f32 duration;
    f32 position[3];
    void (*unk14)(ActorMarker *);
    ActorMarker *unk18;
}badrone;

/* .code */
void badrone_set_type(BaDroneType type){
    badrone.type = type;
}

BaDroneType badrone_get_type(void){
    return badrone.type;
}

void badrone_get_position_and_duration(f32 position[3], f32 *duration){
    ml_vec3f_copy(position, badrone.position);
    *duration = badrone.duration;
}

enum bs_e badrone_enter(void){
    badrone_set_type(BA_DRONE_ENTER);
    return func_8029BD90();
}

enum bs_e badrone_goto(f32 position[3], f32 duration, void (*arg2)(ActorMarker *), ActorMarker *arg3){
    ml_vec3f_copy(badrone.position, position);
    badrone.duration = duration;
    badrone.unk14 = arg2;
    badrone.unk18 = arg3;
    badrone_set_type(BA_DRONE_GOTO);
    return func_8029BD90();
}

enum bs_e badrone_look(void){
    badrone_set_type(BA_DRONE_LOOK);
    return func_8029BD90();
}

enum bs_e badrone_802926E8(void){
    badrone_set_type(BA_DRONE_UNKNOWN_3);
    return func_8029BD90();
}

enum bs_e badrone_vanish(void){
    badrone_set_type(BA_DRONE_VANISH);
    return func_8029BD90();
}

enum bs_e badrone_transform(void){
    baflag_clear(BA_FLAG_19_SHOULD_TRANSFORM);
    badrone_set_type(BA_DRONE_TRANSFORM);
    return func_8029BD90();
}

void badrone_goto_end(void){
    if(badrone.unk14){
        badrone.unk14(badrone.unk18);
    }
}

void badrone_init(void){
    badrone.type = 0;
    badrone.unk14 = NULL;
    badrone.duration = 0.1f;
    ml_vec3f_clear(badrone.position);
}
