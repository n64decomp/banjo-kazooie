#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_6AC0_0;

void func_8038CFB4(Actor *this);

/* .data */
extern ActorInfo D_8038F4D0 = { 
    0x1BE, 0x2AB, 0x48F,
    0x0, NULL,
    func_8038CFB4, func_8038CFB4, func_80325888,
    0, 0, 2.2f, 0
};

extern Struct_CCW_6AC0_0 D_8038F4F4[];
extern Struct_CCW_6AC0_0 D_8038F53C[];
extern Struct_CCW_6AC0_0 D_8038F5D8[];

/* .code */
void func_8038CEB0(Actor *this, s32 next_state) {
    ActorProp *temp_v0;

    if (next_state == 1) {
        func_80335924(this->unk148, 0x1A6, 0.2f, 4.5f);
    }
    if (next_state == 2) {
        this->marker->propPtr->unk8_3 = FALSE;
        func_80335924(this->unk148, 0x1A7, 0.2f, 3.0f);
        func_80335A8C(this->unk148, 2);
        func_80311480(0xCD0, 0x24, NULL, NULL, NULL, NULL);
    }
    if (next_state == 3) {
        func_80335924(this->unk148, 0x1A8, 0.2f, 0.5f);
        func_80335A8C(this->unk148, 1);
    }
    if (next_state == 4) {
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void func_8038CFB4(Actor *this) {
    Struct_CCW_6AC0_0 *phi_s0;
    f32 sp70;
    f32 sp6C;
    f32 sp60[3];

    if (!this->unk16C_4) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk16C_4 = TRUE;
        this->unk138_24 = FALSE;
        func_8038CEB0(this, 1);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY) != 0) {
            levelSpecificFlags_set(0x25, 1);
        }
        if (levelSpecificFlags_get(0x25) != 0) {
            marker_despawn(this->marker);
        }
        return;
    } 

    if (this->state == 1) {
        phi_s0 = &D_8038F4F4;
    } else if (this->state == 2) {
        phi_s0 = &D_8038F53C;
    } else if (this->state == 3) {
        phi_s0 = &D_8038F5D8;
    } else{
        phi_s0 = NULL;
    }

    if (phi_s0 != NULL) {
        func_8033568C(this->unk148, &sp70, &sp6C);
        while(phi_s0->unk0 > 0.0f){
            if (((sp70 < phi_s0->unk0) || (sp6C < sp70)) && (phi_s0->unk0 <= sp6C)) {
                func_8030E878(phi_s0->unk8, randf2(phi_s0->unk4 - 0.05, phi_s0->unk4 + 0.05), randi2(phi_s0->unkA - 200, phi_s0->unkA + 100), this->position, 500.0f, 1500.0f);
            }
            phi_s0++;
        }
    }

    if (this->state == 1) {
        if (!this->unk138_24) {
            player_getPosition(&sp60);
            if (ml_vec3f_distance(this->position, &sp60) < 900.0f) {
                func_80311480(0xCCF, 4, NULL, NULL, NULL, NULL);
                this->unk138_24 = TRUE;
            }
        }
        if (levelSpecificFlags_get(0x25) != 0) {
            func_8038CEB0(this, 2);
        }
    }

    if (this->state == 2){
        if((func_80335794(this->unk148) > 0)) {
            func_8038CEB0(this, 3);
        }
    }
    
    if (this->state == 3) {
        func_80326224(this);
        if (0.99 < (f64) this->unk48) {
            func_8038CEB0(this, 4);
        }
    }
}
