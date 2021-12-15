#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_80309724(f32 (*)[3]);

typedef struct struct_24_s{
    u32 unk0;
    void *unk4;
    
    f32 unk8[3];
    
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    
    f32 unk20;
    f32 unk24;
    f32 unk28;

    f32 unk2C;
    
    f32 unk30[3];
    
    s32 unk3C;
    s32 unk40;
    
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    f32 unk50;
} struct24s;

typedef struct struct_25_s{
    struct24s *begin;
    struct24s *current;
    struct24s *end;
    struct24s data[];
} struct25s;

void func_802C8484(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802C8C5C(Actor *this);
void func_802C8EC0(Actor *this);

/* .data */
extern ActorInfo D_80366340 = { 0x56,  0x4A,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80366364 = { 0x56,  0x4B,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80366388 = { 0x56,   0xD,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803663AC = { 0x56, 0x11F,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803663D0 = { 0x56, 0x14F,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_803663F4 = { 0x56, 0x3AD,   0x0, 0x2, 0x0, func_802C8C5C, func_80326224, func_802C8484, { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}};
extern ActorInfo D_80366430 = { MARKER_61_EXTRA_LIFE,  ACTOR_49_EXTRA_LIFE, ASSET_36E_MODEL_EXTRA_LIFE, 0x0, 0x0, func_802C8EC0, func_80326224, func_80325934, { 0x0, 0x0, 0x0, 0x0}, 0.7f, { 0x0, 0x0, 0x0, 0x0}};

/* .bss */
extern s32 D_8037DD90;
extern s32 D_8037DD94;
// extern struct{
//     u32 unk0;
//     u32 unk4;
//     u32 unk8;
//     u32 unkC;
// } D_8037DD98;

extern u32 D_8037DD98;
extern u32 D_8037DD9C;
extern u32 D_8037DDA0;
extern u32 D_8037DDA4;



void func_802C83F0(ActorMarker *);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C83F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8484.s")

Actor *func_802C8580(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    struct25s *s1 =  malloc(sizeof(struct25s) + D_8037DD90 * sizeof(struct24s));
    Actor *actor = actor_new(position, yaw, actorInfo, flags);
    f32 f24;
    f32 sp68[3];
    struct24s * s0;

    actor->marker->collidable = FALSE;
    s1->begin = &s1->data[0];
    s1->current = &s1->data[0];
    s1->end = s1->begin + D_8037DD90;

    for(s1->current = s1->begin; s1->current < s1->end; s1->current++){//L802C8670
        f24 = randf2(0.0f, 360.0f);
        s0 = s1->current;
        s0->unk0 = 2;
        s0->unk40 = D_8037DD98;
        s0->unk44 = D_8037DD9C;
        s0->unk48 = D_8037DDA0;
        s0->unk4C = D_8037DDA4;

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
            s0->unk4 = assetcache_get(0x2e7);
            s0->unk2C = 18.0f;
            break; 
        case 2: // 802C87A8
            s0->unk4 = assetcache_get(0x344);
            s0->unk2C = 2.0f;
            break; 
        case 4: // 802C87C4
            s0->unk4 = assetcache_get(0x345);
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
                s0->unk4 = assetcache_get(0x2d1);
            else
                s0->unk4 = assetcache_get(0x2e5);

            s0->unk2C = randf2(5.0f, 12.0f);
            break;
        case 3: // 802C88A0
            s0->unk4 = assetcache_get(0x30e);
            s0->unk2C = randf2(9.0f, 15.0f);
            break;
        case 5: // 802C88C8
            s0->unk4 = assetcache_get(0x8a2);
            s0->unk2C = 2.0f;
            break;
        }//L802C88E0
        s0->unk3C = 0;
        sp68[0] = (f32)(* position)[0];
        sp68[1] = (f32)(* position)[1];
        sp68[2] = (f32)(* position)[2];

        sp68[0] += s0->unk30[0]*3.0f;
        s0->unk50 = func_80309724(&sp68);

        s0->unk1C = 0.0f;
        s0->unk18 = 0.0f;
        s0->unk14 = 0.0f;

        s0->unk20 = randf2(0.05f, 0.4f);
        s0->unk24 = randf2(0.05f, 0.4f);
        s0->unk28 = randf2(0.05f, 0.4f);

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

Actor *func_802C8A54(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xF;
    D_8037DD94 = 1;
    D_8037DD98 = 0xFA;
    *(&D_8037DD98 + 1) = 0xFA;
    *(&D_8037DD98 + 2) = 0xFA;
    *(&D_8037DD98 + 3) = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8AA8(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0x19;
    D_8037DD94 = 0;
    D_8037DD98 = 0xFA;
    *(&D_8037DD98 + 1) = 0xFA;
    *(&D_8037DD98 + 2) = 0xFA;
    *(&D_8037DD98 + 3) = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8AF8(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0x19;
    D_8037DD94 = 3;
    D_8037DD98 = 0xFA;
    *(&D_8037DD98 + 1) = 0xFA;
    *(&D_8037DD98 + 2) = 0xFA;
    *(&D_8037DD98 + 3) = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8B4C(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xF;
    D_8037DD94 = 2;
    D_8037DD98 = 0x95;
    *(&D_8037DD98 + 1) = 0x55;
    *(&D_8037DD98 + 2) = 0x2B;
    *(&D_8037DD98 + 3) = 0x9B;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8BA8(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0x19;
    D_8037DD94 = 4;
    D_8037DD98 = 0x95;
    *(&D_8037DD98 + 1) = 0x55;
    *(&D_8037DD98 + 2) = 0x2B;
    *(&D_8037DD98 + 3) = 0x9B;
    return func_802C8580(position, yaw, actorInfo, flags);
}

Actor *func_802C8C04(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xf;
    D_8037DD94 = 5;
    D_8037DD98 = 0xC8;
    *(&D_8037DD98 + 1) = 0xC8;
    *(&D_8037DD98 + 2) = 0xA0;
    *(&D_8037DD98 + 3) = 0x9B;
    return func_802C8580(position, yaw, actorInfo, flags);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8C5C.s")

void func_802C8EC0(Actor *this){
    if(!this->initialized){
        func_8032AA58(this, 0.8f);
        this->initialized = TRUE;
        if(func_803203FC(1) || func_803203FC(2)){
            marker_despawn(this->marker);
        }
    }
}
