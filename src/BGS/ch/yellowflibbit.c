#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 unk2;
    u8 pad3[1];
    s16 unk4[3];
    s16 unkA[3];
    s16 unk10[3];
    u8 pad16[0x2];
    f32 unk18;
    f32 unk1C;
    f32 unk20[2];
    f32 unk28;
}ActorLocal_Yellow_Flibbit;

Actor *func_8038DE5C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx** vtx);
void func_8038E034(Actor *this);

/* .data */
ActorInfo D_80390AE0 = {
    0xC5, 0x137, 0x385,
    0, NULL, 
    func_8038E034, NULL, func_8038DE5C,
    {0, 0}, 0, 1.0f, 0
};
s32 D_80390B04[3] = {0xFF, 0xB3, 0};
f32 D_80390B10[3] = {0.0f, 0.0f, 0.0f};

/* .rodata */
extern f32 D_80391108;
extern f32 D_8039110C;


#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D930.s")

void func_8038D9D0(Actor *this, s32 next_state);
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038D9D0.s")

void func_8038DD9C(ActorMarker *this_marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038DD9C.s")

void func_8038DDDC(ActorMarker *this_marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038DDDC.s")

void func_8038DE1C(ActorMarker *this_marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038DE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/yellowflibbit/func_8038DE5C.s")

void func_8038E034(Actor *this) {
    f32 spB4[3];
    f32 spA8[3];
    f32 spA4;
    ActorLocal_Yellow_Flibbit *local = (ActorLocal_Yellow_Flibbit *)&this->local;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp7C[3];
    f32 temp_f12;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp60[3];
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp48[3];

    sp9C = time_getDelta();
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, &func_8038DD9C, &func_8038DDDC, &func_8038DE1C);
        local->unk2 = 0U;
        local->unk20[0] = randf2(-2.0f, -1.0f);
        local->unk20[1] = randf2(-2.0f, -1.0f);
        local->unk10[0] = (s16) (s32) this->position[0];
        local->unk10[1] = (s16) (s32) this->position[1];
        local->unk10[2] = (s16) (s32) this->position[2];
        func_8038D9D0(this, 1);
        if (jiggyscore_isSpawned(JIGGY_24_BGS_FLIBBITS) != 0) {
            marker_despawn(this->marker);
        }
        return;
    } 
    if (!local->unk2) {
        local->unk2 = TRUE;
        func_8038CED0();
    }
    player_getPosition(&spB4);
    spA8[0] = spB4[0] - this->position[0];
    spA8[1] = spB4[1] - this->position[1];
    spA8[2] = spB4[2] - this->position[2];
    spA4 = gu_sqrtf(spA8[0]*spA8[0] + spA8[1]*spA8[1] + spA8[2]*spA8[2]);
    if (func_8025773C(&local->unk28, sp9C) != 0) {
        func_8030E878(0x3F0, randf2(D_80391108, D_8039110C), randi2(12000, 19000), this->position, 500.0f, 2500.0f);
        local->unk28 = randf2(1.0f, 6.0f);
    }
    local->unk20[0] += sp9C;
    local->unk20[0] = (0.2 < (f64) local->unk20[0]) ? randf2(-3.0f, -1.0f) : local->unk20[0];

        local->unk20[1] += sp9C;
    local->unk20[1] = (0.2 < (f64) local->unk20[1]) ? randf2(-3.0f, -1.0f) : local->unk20[1];

    if(this->state == 1){
        if(mapSpecificFlags_getClear(0x12)){
            func_8038D9D0(this, 2);
            return;
        }

        if(spA4 < 2000.0f){
            func_80258A4C(this->position, this->yaw - 90.0f, spB4, &sp98, &sp94, &sp90);
            this->yaw += (sp90*90.0f) *sp9C; 
        }
    }

    if(this->state == 2){
        if(func_8025773C(&local->unk1C, sp9C)){
            func_8038D9D0(this, 3);
        }
    }

    if(this->state == 3){
         if (func_80329210(this, spB4)) {
                func_8038D9D0(this, 5);
            } else {
                func_8038D9D0(this, 1);
            }
    }


    if(this->state == 4){
        if(!mapSpecificFlags_get(0x10))
            func_8038D9D0(this, 5);
    }

    if (this->state == 5) {
        func_8033568C(this->unk148, &sp8C, &sp88);
        if (sp8C < 0.8 && 0.8 <= sp88) {
            func_8030E878(SFX_8_BANJO_LANDING_04, randf2(0.8f, 0.9f), randi2(0x61A8, 0x6978), this->position, 100.0f, 1500.0f);
        }
        if (func_80335794(this->unk148) > 0) {
            sp7C[0] = (f32) local->unk10[0];
            sp7C[1] = (f32) local->unk10[1];
            sp7C[2] = (f32) local->unk10[2];
            if (func_80256064(this->position, sp7C) < 30.0f) {
                func_8038D9D0(this, 1);
            } else {
                func_8038D9D0(this, 5);
            }
        } else {

            if ((0.2 <= sp88) && (sp88 <= 0.8)) {
                temp_f12 = ((sp88 - 0.2) / 0.60000000000000009);
                this->position_x = local->unk4[0] + (local->unkA[0] - local->unk4[0])*temp_f12;
                this->position_y = local->unk4[1] + (local->unkA[1] - local->unk4[1])*temp_f12;
                this->position_z = local->unk4[2] + (local->unkA[2] - local->unk4[2])*temp_f12;

                if (local->unk1 != 0) {
                    if (sp88 <= 0.5) {
                        this->position[1] = (f32) ((f64) this->position[1] + ((sp88 / 0.5) * 70.0));
                    } else {
                        this->position[1] = (f32) ((f64) this->position[1] + ((1.0 - ((sp88 - 0.5) / 0.5)) * 70.0));
                    }
                }
                sp60[0] = (f32) (local->unkA[0] - local->unk4[0]);
                sp60[1] = (f32) (local->unkA[1] - local->unk4[1]);
                sp60[2] = (f32) (local->unkA[2] - local->unk4[2]);
                func_80258A4C(D_80390B10, this->yaw - 90.0f, sp60, &sp74, &sp70, &sp6C);
                this->yaw += sp6C * 220.0f * sp9C;
            }
        }
    }

    if (this->state == 6) {
        func_80258A4C(this->position, this->yaw - 90.0f, spB4, &sp5C, &sp58, &sp54);
        this->yaw += sp54 * 90.0f * sp9C;
        if ((-0.4 <= sp54) && (sp54 <= 0.4) && ((f64) randf() > 0.5)) {
            func_8038D9D0(this, 5);
        }
        if ((sp58 < 0.0f) && (randf() > 0.5)) {
            func_8038D9D0(this, 5);
        }
    }

    if(this->state == 7 || this->state == 8){
        if(func_8025773C(&local->unk1C, sp9C)){
            func_8038D9D0(this, 6);
        }
    }

    if(this->state == 9){
        sp48[0] = this->position[0] - spB4[0];
        sp48[1] = this->position[1] - spB4[1];
        sp48[2] = this->position[2] - spB4[2];
        sp48[1] = 0.0f;
        ml_vec3f_set_length(sp48, 400.0f * sp9C);

        this->position[0] = this->position[0] + sp48[0];
        this->position[1] = this->position[1] + sp48[1];
        this->position[2] = this->position[2] + sp48[2];

        this->position_y += local->unk18*sp9C;
        local->unk18 -= 3000.0f*sp9C;
        if(this->position_y  < func_80309724(this->position)){
            this->position_y  = func_80309724(this->position);
            func_8038D9D0(this, 10);
        }
    }

    if(this->state == 10){
        if(func_80335794(this->unk148) > 0){
            func_8038D9D0(this, 11);
        }
    }
}
 