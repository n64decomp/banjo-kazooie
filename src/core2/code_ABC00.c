#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80347B54(Struct81s *);
extern void func_80347B80(Struct81s *);
extern void func_80347C5C(Struct81s *, Gfx **, Mtx **, Vtx **);
extern void func_80347C70(Struct81s *);

extern void func_80347CC8(Struct81s *);
extern void func_80347CF4(Struct81s *);
extern void func_80347DD0(Struct81s *, Gfx **, Mtx **, Vtx **);
extern void func_80347DE4(Struct81s *);

void func_80347E34(Struct81s*);
void func_80347E60(Struct81s*);
void func_80347FA4(Struct81s *, Gfx**, Mtx **, Vtx **);
void func_80347FB8(Struct81s*);


typedef struct {
    void (*unk0)(Struct81s *);
    void (*unk4)(Struct81s *);
    void (*unk8)(Struct81s *, Gfx**, Mtx **, Vtx **);
    void (*unkC)(Struct81s *);
    Struct81s unk10;
}Struct_core2_ABC00_0;

void func_803331D8(enum jiggy_e, f32[3]);
void func_803332D0(Actor *);

/* .data */
u8 D_8036E830 = 0;
Struct_core2_ABC00_0 D_8036E834[] = {
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x7,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x4,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x4,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x7,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x15, NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x4,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x7,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347CC8, func_80347CF4, func_80347DD0, func_80347DE4, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0xC,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x7,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0xC,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x9,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x8,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x9,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x7,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x12, NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0x1E, NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0xC,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0xC,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0xC,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0xC,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x7,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x8,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x8,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347E34, func_80347E60, func_80347FA4, func_80347FB8, {0x4,  NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
    {func_80347B54, func_80347B80, func_80347C5C, func_80347C70, {0,    NULL, {0.0f, 0.0f, 0.0f}, NULL, NULL}},
};

/* .bss */
s32 D_80383560;
s32 D_80383564;
s32 D_80383568;
s32 D_8038356C;

/* .code */
void func_80332B90(void){
    func_8024BD08(1);
}

void func_80332BB0(void) {
    timedFunc_set_0(1.0f, func_80332B90);
    func_8025A55C(-1, 4000, 5);
}

void func_80332BEC(enum map_e map_id) {
    s32 temp_a2;
    s32 temp_at;
    s32 temp_hi;
    s32 temp_lo;
    s32 temp_t4;
    s32 var_a1;
    s32 var_v1;
    s32 var_v0;

    var_v1 = (map_getLevel(map_id) - 1) % (D_80383568 = 0xA);
    var_a1 = MAX(0, var_v1);
    D_80383560 = var_a1 * 0xA;
    D_80383564 = (var_a1 + 1) * 0xA;
    for(D_8038356C = D_80383560; D_8038356C < D_80383564; D_8038356C++){
            D_8036E834[D_8038356C].unk10.marker = NULL;
    }
    D_8036E830 = 0;
}

void func_80332CCC(void) {
    Actor **temp_v0;
    s32 i;

    temp_v0 = func_80326FC0();
    for(D_8038356C = 0; temp_v0[D_8038356C] != NULL; D_8038356C++){
        if(!temp_v0[D_8038356C]->unk44_2){
            D_8036E834[func_802C8088(temp_v0[D_8038356C]) - 1].unk10.marker = temp_v0[D_8038356C]->marker;
        }
    }
}


void func_80332D98(enum map_e map_id, enum jiggy_e jiggy_id, enum bkprog_e flag_id, s32 arg3) {
    f32 sp1C[3];

    if ((map_get() == map_id) 
        && func_8031FF1C(flag_id)
        && !jiggyscore_isSpawned(jiggy_id)
        && func_80304E24(arg3, sp1C)
    ) {
        func_803331D8(jiggy_id, sp1C);
    }
}

void func_80332E08(void) {
    s32 temp_t0;
    s32 var_v0;
    void *temp_v1;

    for(D_8038356C = D_80383560; D_8038356C < D_80383564; D_8038356C++) {
            if (D_8036E834[D_8038356C].unk10.marker != NULL) {
                D_8036E834[D_8038356C].unk4(&D_8036E834[D_8038356C].unk10);
                var_v0 = D_8038356C;
            }
    }
    func_80332D98(MAP_69_GL_MM_LOBBY, JIGGY_34_LAIR_MM_WITCH_SWITCH, BKPROG_18_MM_WITCH_SWITCH_JIGGY_SPAWNED, 0x205);
    func_80332D98(MAP_6F_GL_FP_LOBBY, JIGGY_39_LAIR_MMM_WITCH_SWITCH, BKPROG_19_MMM_WITCH_SWITCH_JIGGY_SPAWNED, 0x207);
    func_80332D98(MAP_6D_GL_TTC_LOBBY, JIGGY_36_LAIR_TTC_WITCH_SWITCH, BKPROG_1A_TTC_WITCH_SWITCH_JIGGY_SPAWNED, 0x209);
    func_80332D98(MAP_76_GL_640_NOTE_DOOR, JIGGY_3B_LAIR_RBB_WITCH_SWITCH, BKPROG_1C_RBB_WITCH_SWITCH_JIGGY_SPAWNED, 0x20C);
    func_80332D98(MAP_79_GL_CCW_LOBBY, JIGGY_3C_LAIR_CCW_WITCH_SWITCH, BKPROG_46_CCW_WITCH_SWITCH_JIGGY_SPAWNED, 0x238);
    if ((D_8036E830 == 0) && func_8031FF1C(BKPROG_9C_LAIR_CC_WITCH_SWITCH_LEFT_EYE_PRESSED)) {
        func_80332D98(MAP_6A_GL_TTC_AND_CC_PUZZLE, JIGGY_35_LAIR_CC_WITCH_SWITCH, BKPROG_9D_LAIR_CC_WITCH_SWITCH_RIGHT_EYE_PRESSED, 0x190);
    }
    D_8036E830 = 1;
}

void func_80332F4C(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    for(D_8038356C = D_80383560; D_8038356C < D_80383564; D_8038356C++) {
        if (D_8036E834[D_8038356C].unk10.marker != NULL) {
            D_8036E834[D_8038356C].unk8(&D_8036E834[D_8038356C].unk10, gfx, mtx, vtx);
        }
    }
}

void func_8033301C(void) {
    for(D_8038356C = D_80383560; D_8038356C < D_80383564; D_8038356C++) {
        if (D_8036E834[D_8038356C].unk10.marker != NULL) {
            func_803332D0(marker_getActor(D_8036E834[D_8038356C].unk10.marker));
        }
    }
}

void jiggySpawn(enum jiggy_e jiggy_id, f32 pos[3]) {
    Struct_core2_ABC00_0 *temp_v0;

    jiggy_id = ((jiggy_id <= 0) || (jiggy_id >= (D_80383568 * 10))) ? 10 : jiggy_id;
    temp_v0 = &D_8036E834[jiggy_id - 1];
    if (D_8036E834[jiggy_id - 1].unk10.marker == NULL) {
        temp_v0->unk10.position[0] = pos[0];
        temp_v0->unk10.position[1] = pos[1];
        temp_v0->unk10.position[2] = pos[2];
        temp_v0->unk0(&temp_v0->unk10);
        jiggyscore_setSpawned(jiggy_id, TRUE);
        if (!jiggyscore_isCollected(jiggy_id) && (jiggy_id != 0x3E) && (jiggy_id != 0xB)) {
            func_8024BD08(0);
            func_8025A55C(0, 4000, 5);
            func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
            timedFunc_set_0(3.5f, func_80332BB0);
        }
    }
}

void func_803331D8(enum jiggy_e jiggy_id, f32 arg1[3]) {
    jiggy_id = ((jiggy_id <= 0) || (jiggy_id >= (D_80383568 * 10))) ? JIGGY_A_MM_CONGA : jiggy_id;

    D_8036E834[jiggy_id - 1].unk10.position[0] = arg1[0];
    D_8036E834[jiggy_id - 1].unk10.position[1] = arg1[1];
    D_8036E834[jiggy_id - 1].unk10.position[2] = arg1[2];
    D_8036E834[jiggy_id - 1].unk0(&D_8036E834[jiggy_id - 1].unk10);
    jiggyscore_setSpawned(jiggy_id, TRUE);
}

void func_80333270(enum jiggy_e jiggy_id, f32 position[3], void (*method)(Actor *, ActorMarker *), ActorMarker *other_marker) {
    Struct_core2_ABC00_0 *ptr;

    ptr = &D_8036E834[jiggy_id - 1];
    jiggySpawn(jiggy_id, position);
    ptr->unk10.unk14 = method;
    ptr->unk10.unk18 = other_marker;
}

void func_803332D0(Actor *arg0)
{
  s32 indx = func_802C8088(arg0) - 1;
  Struct81s *sp18 = &D_8036E834[indx].unk10;
  if (D_8036E834[indx].unkC)
  {
  }
  D_8036E834[indx].unkC(sp18);
  sp18->marker = 0;
}

void func_80333334(enum jiggy_e jiggy_id) {
    Struct_core2_ABC00_0 *temp_v0;

    temp_v0 = &D_8036E834[jiggy_id - 1];
    temp_v0->unk0 = func_80347B54;
    temp_v0->unk4 = func_80347B80;
    temp_v0->unk8 = func_80347C5C;
    temp_v0->unkC = func_80347C70;
}

void func_80333388(enum jiggy_e jiggy_id) {
    Struct_core2_ABC00_0 *temp_v0;

    temp_v0 = &D_8036E834[jiggy_id - 1];
    temp_v0->unk0 = func_80347CC8;
    temp_v0->unk4 = func_80347CF4;
    temp_v0->unk8 = func_80347DD0;
    temp_v0->unkC = func_80347DE4;

}

void func_803333DC(Struct81s *arg0, Actor *arg1) {
    s32 sp20;

    arg0->marker = arg1->marker;
    if (arg0->unk14 != NULL) {
        arg0->unk14(arg1, arg0->unk18);
    }
    func_803300D8(arg1->marker, func_803332D0);
    sp20 = ((s32) ((s32)arg0 - (s32)&D_8036E834) / 0x2C) + 1;
    func_802C80B4(arg1, sp20);
    if ((sp20 == JIGGY_49_CCW_EYRIE) || (sp20 == JIGGY_39_LAIR_MMM_WITCH_SWITCH) || (sp20 == JIGGY_3C_LAIR_CCW_WITCH_SWITCH)) {
        arg1->marker->unk40_21 = TRUE;
        arg1->marker->unk40_20 = TRUE;
    }
}
