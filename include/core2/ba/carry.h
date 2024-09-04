#ifndef __BA_CARRY_H__
#define __BA_CARRY_H__

#include <ultra64.h>
#include "prop.h"

void bacarry_init(void);
void bacarry_end(void);
void bacarry_update(void);

void bacarry_reset_marker(void);
ActorMarker *bacarry_get_marker(void);
void bacarry_set_marker(ActorMarker *arg0);
void bacarry_set_offsets(f32 height, f32 rotation);


#endif
