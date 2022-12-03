#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);

typedef struct struct_24_s{
    s32 unk0;
    BKModelBin *model_bin;
    f32 unk8[3];
    f32 unk14[3];
    f32 unk20[3];
    f32 unk2C;
    f32 unk30[3];
    ParticleEmitter *unk3C;
    s32 unk40[4];
    f32 unk50;
} Struct24s;

typedef struct struct_25_s{
    Struct24s *begin;
    Struct24s *current;
    Struct24s *end;
    Struct24s data[];
} Struct25s;

Actor *func_802C8484(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802C8C5C(Actor *this);

/* .data */
f32 D_80366330 = 0.5f;
f32 D_80366334 = 30.0f;
f32 D_80366338 = 150.0f;
f32 D_8036633C = 25.0f;
ActorInfo D_80366340 = { 0x56,  0x4A,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, 0, 0, 0.0f, 0};
ActorInfo D_80366364 = { 0x56,  0x4B,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, 0, 0, 0.0f, 0};
ActorInfo D_80366388 = { 0x56,   0xD,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, 0, 0, 0.0f, 0};
ActorInfo D_803663AC = { 0x56, 0x11F,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, 0, 0, 0.0f, 0};
ActorInfo D_803663D0 = { 0x56, 0x14F,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, 0, 0, 0.0f, 0};
ActorInfo D_803663F4 = { 0x56, 0x3AD,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, 0, 0, 0.0f, 0};
s32 D_80366418[3] = {0,0,0};

/* .bss */
s32 D_8037DD90;
s32 D_8037DD94;
u32 D_8037DD98;
u32 D_8037DD9C;
u32 D_8037DDA0;
u32 D_8037DDA4;

/* .code */
void func_802C83F0(Actor *actor) {
    Struct25s *phi_a1;
    Struct24s *phi_s0;

    phi_a1 = actor->unk40;
    for( phi_s0 = phi_a1->begin; phi_s0 < phi_a1->current; phi_s0++){
        if (phi_s0->model_bin != NULL) {
            assetcache_release(phi_s0->model_bin);
        }
        if (phi_s0->unk3C != 0) {
            func_802EE5E8(phi_s0->unk3C);
        }
        phi_s0->unk3C = NULL;
    }
    free(actor->unk40);
}

Actor *func_802C8484(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Struct25s *temp_s1;
    Struct24s *phi_s0;
    f32 sp5C;
    Actor *sp58;
    u32 phi_v1;
    s32 phi_s4;

    sp58 = marker_getActorAndRotation(marker, &sp5C);
    temp_s1 = sp58->unk40;
    phi_s4 = FALSE;
    for(phi_s0 = temp_s1->begin; phi_s0 < temp_s1->current; phi_s0++){
        if ((phi_s0->unk0 != 0) && (phi_s0->model_bin != NULL)) {
            modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
            modelRender_draw(gfx, mtx, phi_s0->unk8, phi_s0->unk14, phi_s0->unk2C / 10.0f, NULL, phi_s0->model_bin);
            phi_s4 = TRUE;
        }
    }
    if (phi_s4 == FALSE) {
        marker_despawn(marker);
    }
    return sp58;
}

Actor *func_802C8580(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    Struct25s *s1 =  malloc(sizeof(Struct25s) + D_8037DD90 * sizeof(Struct24s));
    Actor *actor = actor_new(position, yaw, actorInfo, flags);
    f32 f24;
    f32 sp68[3];
    Struct24s * s0;

    actor->marker->collidable = FALSE;
    s1->begin = &s1->data[0];
    s1->current = &s1->data[0];
    s1->end = s1->begin + D_8037DD90;

    for(s1->current = s1->begin; s1->current < s1->end; s1->current++){//L802C8670
        f24 = randf2(0.0f, 360.0f);
        s0 = s1->current;
        s0->unk0 = 2;
        s0->unk40[0] = D_8037DD98;
        s0->unk40[1] = D_8037DD9C;
        s0->unk40[2] = D_8037DDA0;
        s0->unk40[3] = D_8037DDA4;

        TUPLE_ASSIGN(s0->unk30, 
            randf2(100.0f, 250.0f), 
            randf2(500.0f, 750.0f), 
            randf2(100.0f, 250.0f)
        );

        s0->unk8[0] = randf2(50.0f, 150.0f);
        s0->unk8[1] = 0.0f;
        s0->unk8[2] = 0.0f;
        switch(D_8037DD94){
        case 1: // 802C8740
            s0->unk30[0] = randf2(125.0f, 175.0f);
            s0->unk30[1] = randf2(400.0f, 600.0f);
            s0->unk30[2] = randf2(125.0f, 175.0f);
            s0->model_bin = (BKModelBin *) assetcache_get(0x2e7);
            s0->unk2C = 18.0f;
            break; 
        case 2: // 802C87A8
            s0->model_bin = (BKModelBin *) assetcache_get(0x344);
            s0->unk2C = 2.0f;
            break; 
        case 4: // 802C87C4
            s0->model_bin = (BKModelBin *) assetcache_get(0x345);
            s0->unk2C = 1.0f;
            s0->unk30[0] = randf2(20.0f, 100.0f);
            s0->unk30[1] = randf2(400.0f, 740.0f);
            s0->unk30[2] = randf2(20.0f, 100.0f);

            s0->unk8[0] = randf2(0.0f, 30.0f);
            s0->unk8[1] = 0.0f;
            s0->unk8[2] = 0.0f;
            break; 
        case 0: // 802C883C
            if(0.5 < randf())
                s0->model_bin = (BKModelBin *) assetcache_get(0x2d1);
            else
                s0->model_bin = (BKModelBin *) assetcache_get(0x2e5);

            s0->unk2C = randf2(5.0f, 12.0f);
            break;
        case 3: // 802C88A0
            s0->model_bin = (BKModelBin *) assetcache_get(0x30e);
            s0->unk2C = randf2(9.0f, 15.0f);
            break;
        case 5: // 802C88C8
            s0->model_bin = (BKModelBin *) assetcache_get(0x8a2);
            s0->unk2C = 2.0f;
            break;
        }//L802C88E0
        s0->unk3C = 0;
        sp68[0] = (f32)position[0];
        sp68[1] = (f32)position[1];
        sp68[2] = (f32)position[2];

        sp68[0] += s0->unk30[0]*3.0f;
        s0->unk50 = func_80309724(&sp68);

        s0->unk14[2] = 0.0f;
        s0->unk14[1] = 0.0f;
        s0->unk14[0] = 0.0f;

        s0->unk20[0] = randf2(0.05f, 0.4f);
        s0->unk20[1] = randf2(0.05f, 0.4f);
        s0->unk20[2] = randf2(0.05f, 0.4f);

        ml_vec3f_yaw_rotate_copy(&s0->unk8, &s0->unk8, f24);
        s0->unk8[0] += actor->position_x;
        s0->unk8[1] += actor->position_y;
        s0->unk8[2] += actor->position_z;

        ml_vec3f_yaw_rotate_copy(&s0->unk30, &s0->unk30, randf2(15.0f, 90.0f) + f24);
    }//L802C8A08
    actor->unk40 = s1;
    func_803300D8(actor->marker, func_802C83F0);
    return actor;
}

Actor *func_802C8A54(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xF;
    D_8037DD94 = 1;
    D_8037DD98 = 0xFA;
    *(&D_8037DD98 + 1) = 0xFA;
    *(&D_8037DD98 + 2) = 0xFA;
    *(&D_8037DD98 + 3) = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8AA8(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0x19;
    D_8037DD94 = 0;
    D_8037DD98 = 0xFA;
    *(&D_8037DD98 + 1) = 0xFA;
    *(&D_8037DD98 + 2) = 0xFA;
    *(&D_8037DD98 + 3) = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8AF8(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0x19;
    D_8037DD94 = 3;
    D_8037DD98 = 0xFA;
    *(&D_8037DD98 + 1) = 0xFA;
    *(&D_8037DD98 + 2) = 0xFA;
    *(&D_8037DD98 + 3) = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8B4C(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xF;
    D_8037DD94 = 2;
    D_8037DD98 = 0x95;
    *(&D_8037DD98 + 1) = 0x55;
    *(&D_8037DD98 + 2) = 0x2B;
    *(&D_8037DD98 + 3) = 0x9B;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8BA8(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0x19;
    D_8037DD94 = 4;
    D_8037DD98 = 0x95;
    *(&D_8037DD98 + 1) = 0x55;
    *(&D_8037DD98 + 2) = 0x2B;
    *(&D_8037DD98 + 3) = 0x9B;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8C04(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xf;
    D_8037DD94 = 5;
    D_8037DD98 = 0xC8;
    *(&D_8037DD98 + 1) = 0xC8;
    *(&D_8037DD98 + 2) = 0xA0;
    *(&D_8037DD98 + 3) = 0x9B;
    return func_802C8580(position, yaw, actorInfo, flags);
}

void func_802C8C5C(Actor *actor) {
    f32 sp94[3];
    f32 temp_f0 = time_getDelta();
    f32 sp84[3];
    Struct25s *temp_s2 = actor->unk40;
    Struct24s *phi_s0;
    s32 sp70[3] = D_80366418;

    for(phi_s0 = temp_s2->begin; phi_s0 < temp_s2->current; phi_s0++){
        if (phi_s0->unk0 == 2) {
            phi_s0->unk30[1] -= 1000.0f * temp_f0;

            phi_s0->unk14[0] += phi_s0->unk20[0] / temp_f0;
            phi_s0->unk14[1] += phi_s0->unk20[1] / temp_f0;
            phi_s0->unk14[2] += phi_s0->unk20[2] / temp_f0;

            sp94[0] = phi_s0->unk8[0];
            sp94[1] = phi_s0->unk8[1];
            sp94[2] = phi_s0->unk8[2];

            sp84[0] = phi_s0->unk30[0] * temp_f0;
            sp84[1] = phi_s0->unk30[1] * temp_f0;
            sp84[2] = phi_s0->unk30[2] * temp_f0;

            phi_s0->unk8[0] = phi_s0->unk8[0] + sp84[0];
            phi_s0->unk8[1] = phi_s0->unk8[1] + sp84[1];
            phi_s0->unk8[2] = phi_s0->unk8[2] + sp84[2];

            if (phi_s0->unk8[1] <= phi_s0->unk50) {
                phi_s0->unk0 = 1;
                phi_s0->unk3C = func_802EE5E0(1);
                if (phi_s0->unk3C != 0) {
                    func_802EE6CC(phi_s0->unk8, sp70, phi_s0->unk40, 1, D_80366330, D_80366334, (s32)D_80366338, (s32)D_8036633C, 1);
                }
            }
        }
        if (phi_s0->unk0 == 1) {
            if (!func_802EE5F0(phi_s0->unk3C)) {
                phi_s0->unk0 = 0;
            }
            phi_s0->unk8[1] -= 2.0f;
        }
    }
}
