#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803864B8(Actor *this);

ActorInfo D_8038EB50 = { 0x1AC, 0x298, 0x444, 0x0, NULL, func_803864B8, NULL, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8038EB74 = { 0x1AC, 0x29A, 0x445, 0x0, NULL, func_803864B8, NULL, actor_draw, 0, 0, 0.0f, 0};

/* .code */
void CCW_func_803863F0(Actor *this, s32 next_state){
    if(next_state == 2){
        FUNC_8030E8B4(SFX_2F_ORANGE_SPLAT, 1.0f, 32000, this->position, 500, 3000);
        levelSpecificFlags_set(0x10, TRUE);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void func_80386468(ActorMarker* marker, ActorMarker *arg1) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1 && map_get() == MAP_44_CCW_SUMMER) {
        CCW_func_803863F0(actor, 2);
    }
}

void func_803864B8(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, func_80386468);
        CCW_func_803863F0(this, 1);
        if(levelSpecificFlags_get(0x10)){
            marker_despawn(this->marker);
        }
    }
}
