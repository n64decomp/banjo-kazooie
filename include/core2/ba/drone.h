#ifndef __BA_DRONE_H__
#define __BA_DRONE_H__

#include <ultra64.h>
#include "prop.h"

typedef enum ba_drone_type_e{
    BA_DRONE_NONE,
    BA_DRONE_GOTO,
    BA_DRONE_LOOK,
    BA_DRONE_UNKNOWN_3,
    BA_DRONE_TRANSFORM,
    BA_DRONE_ENTER,
    BA_DRONE_VANISH
} BaDroneType;

void badrone_set_type(BaDroneType type);
BaDroneType badrone_get_type(void);
void badrone_get_position_and_duration(f32 position[3], f32 *duration);

enum bs_e badrone_enter(void);
enum bs_e badrone_goto(f32 position[3], f32 duration, void (*arg2)(ActorMarker *), ActorMarker *arg3);

#endif
