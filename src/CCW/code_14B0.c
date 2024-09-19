#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030DBFC(u8, f32, f32, f32);
extern void sfxsource_setSampleRate(u8, s32);

typedef struct{
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
}Struct_CCW_14B0_0;

typedef struct {
    u8 unk0;
    // u8 pad1[3];
    Struct_CCW_14B0_0 *unk4;
    f32 unk8;
    f32 unkC[3];
    f32 unk18[3];
}ActorLocal_CCW_14B0;

void CCW_func_80387A40(Actor *this);

/* .data */
Struct_CCW_14B0_0 D_8038EC00[] = {
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE, 0x7, 0x4C, 0xCE1},
    {MAP_5C_CCW_AUTUMN_ZUBBA_HIVE, 0x8, 0x00, 0xCE5},
    0
};

ActorInfo D_8038EC14 = { 0x1AF, 0x29C, 0x446, 0x0, NULL, CCW_func_80387A40, NULL, actor_draw, 0, 0, 1.0f, 0};

/* .code */
void func_803878A0(Actor *this, s32 next_state) {
    ActorLocal_CCW_14B0 *local = (ActorLocal_CCW_14B0 *)&this->local;
    int i;

    if (next_state == 1) {
        if (skeletalAnim_getAnimId(this->unk148) != 0x16F) {
            skeletalAnim_set(this->unk148, 0x16F, 0.1f, 0.65f);
        }
        for(i = 0; i < 10; i++){
            local->unkC[0] = randf2(-500.0f, 500.0f);
            local->unkC[1] = randf2(400.0f, 900.0f);
            local->unkC[2] = randf2(-400.0f, 700.0f);
            if(ml_distance_vec3f(this->position, local->unkC) > 800.0f)
                break;
        }
        local->unk8 = randf2(500.0f, 1000.0f);
    }
    this->state = next_state;
}

void CCW_func_80387A20(Actor *this){
    ActorLocal_CCW_14B0 *local = (ActorLocal_CCW_14B0 *)&this->local;
    func_8030DA44(local->unk0);
}

void CCW_func_80387A40(Actor *this) {
    ActorLocal_CCW_14B0 *local;
    f32 sp68;
    f32 sp5C[3];
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];

    local = (ActorLocal_CCW_14B0 *)&this->local;
    sp68 = time_getDelta();
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = CCW_func_80387A20;
        local->unk4 = &D_8038EC00[0];
        while((local->unk4->unk0 != 0) && (map_get() != local->unk4->unk0)) {
            local->unk4++;
        }
        local->unk0 = func_8030D90C();
        local->unk18[0] = local->unk18[1] = local->unk18[2] = 0.0f;
        sfxsource_setSfxId(local->unk0, 0x3FA);
        func_8030DD14(local->unk0, 2);
        func_8030DBB4(local->unk0, 0.9f);
        sfxsource_setSampleRate(local->unk0, 0);
        func_803878A0(this, 1);
        return;
    }

    if (this->state == 1) {
        sp5C[0] = local->unkC[0] - this->position[0];
        sp5C[1] = local->unkC[1] - this->position[1];
        sp5C[2] = local->unkC[2] - this->position[2];
        if (ml_distance_vec3f(this->position, local->unkC) < 500.0f) {
            ml_vec3f_set_length(sp5C, local->unk8 * 8.0f);
        } else {
            ml_vec3f_set_length(sp5C, local->unk8 * 2);
        }
        this->position[0] += (local->unk18[0] * sp68) + (sp5C[0] * sp68 * sp68);
        this->position[1] += (local->unk18[1] * sp68) + (sp5C[1] * sp68 * sp68);
        this->position[2] += (local->unk18[2] * sp68) + (sp5C[2] * sp68 * sp68);
        local->unk18[0] += sp5C[0] * sp68;
        local->unk18[1] += sp5C[1] * sp68;
        local->unk18[2] += sp5C[2] * sp68;
        if (local->unk8 < gu_sqrtf(local->unk18[0]*local->unk18[0] + local->unk18[1]*local->unk18[1] + local->unk18[2]*local->unk18[2])) {
            ml_vec3f_set_length(local->unk18, local->unk8);
        }
        func_80258A4C(this->position, this->yaw - 90.0f, local->unkC, &sp58, &sp54, &sp50);
        this->yaw += 140.0f * sp50 * sp68;
        if (ml_distance_vec3f(this->position, local->unkC) < 100.0f) {
            func_803878A0(this, 1);
        }
    }

    if(this->position[0]);

    func_8030DBFC(local->unk0, 0.8f, 0.9f, 0.05f);
    sfxsource_set_fade_distances(local->unk0, 500.0f, 1500.0f);
    sfxsource_set_position(local->unk0, this->position);
    func_8030E2C4(local->unk0);
    sfxsource_setSampleRate(local->unk0, 2000.0f + 8000.0f*(gu_sqrtf(local->unk18[0]*local->unk18[0] + local->unk18[1]*local->unk18[1] + local->unk18[2]*local->unk18[2])/ local->unk8));
    if (!mapSpecificFlags_get(local->unk4->unk2)) {
        player_getPosition(sp44);
        if (sp44[2] > -600.0f) {
            if (!local->unk4->unk3 || !jiggyscore_isCollected(local->unk4->unk3) ) {
                gcdialog_showText(local->unk4->unk4, 4, NULL, NULL, NULL, NULL);
                mapSpecificFlags_set(local->unk4->unk2, TRUE);
            }
        }
    }
}
