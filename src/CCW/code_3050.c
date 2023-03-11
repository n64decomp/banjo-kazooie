#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *CCW_func_8038954C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_803895F4(Actor *this);

/* .data */
ActorInfo D_8038EE70 = { 0x1B3, 0x2A0, 0x483, 0x0, NULL, func_803895F4, NULL, CCW_func_8038954C, 0, 0, 0.0f, 0};

/* .code */
void func_80389440(Actor *this, s32 next_state) {
    void *temp_v0;

    if (next_state == 2) {
        func_8030E510(SFX_AA_BGS_EGG_BREAKING_1, 28000);
        this->marker->propPtr->unk8_3 = FALSE;
        fileProgressFlag_set(FILEPROG_E6_SPRING_EYRIE_HATCHED, TRUE);
        func_80335924(this->unk148, 0x187, 0.0f, 2.0f);
        func_80335A8C(this->unk148, 2);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 2);
        timed_exitStaticCamera(8.0f);
        func_80324E38(8.0f, 0);
    }
    this->state = next_state;
}

void func_8038950C(ActorMarker* marker, ActorMarker* other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        func_80389440(actor, 2);
    }
}

Actor *CCW_func_8038954C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;

    this = marker_getActor(marker);
    if (this->state == 0)
        return this;

    func_8033A45C(3, (this->state < 2) ? 1 : 0);
    func_8033A45C(4, (this->state < 2) ? 0 : 1);
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_803895F4(Actor *this) {
    f32 sp2C;
    f32 sp28;

    if(!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, &func_8038950C);
        func_80389440(this, 1);
        if (fileProgressFlag_get(FILEPROG_E6_SPRING_EYRIE_HATCHED) || jiggyscore_isSpawned(JIGGY_49_CCW_EYRIE)) {
            marker_despawn(this->marker);
        }
        return;
    }

    if (this->state == 2) {
        func_8033568C(this->unk148, &sp2C, &sp28);
        if ((sp2C < 0.5) && (sp28 >= 0.5)) {
            func_80326310(this);
        }
    }
}
