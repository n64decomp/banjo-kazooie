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
    void (*init)(Struct81s *);
    void (*update)(Struct81s *);
    void (*draw)(Struct81s *, Gfx**, Mtx **, Vtx **);
    void (*free)(Struct81s *);
    Struct81s unk10;
}Struct_core2_ABC00_0;

void codeABC00_spawnJiggyAtLocation(enum jiggy_e, f32[3]);
void jiggy_free(Actor *);

/* .data */
u8 D_8036E830 = 0;
Struct_core2_ABC00_0 jiggylist_list[] = {
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
s32 s_jiggyList_level_start_index;
s32 s_jiggyList_level_end_index;
s32 s_jiggyList_level_jiggy_count;
s32 s_jiggylist_current_index;

/* .code */
void func_80332B90(void){
    core1_ce60_incOrDecCounter(TRUE);
}

void func_80332BB0(void) {
    timedFunc_set_0(1.0f, func_80332B90);
    func_8025A55C(-1, 4000, 5);
}

void jiggylist_set_level(enum map_e map_id) {
    s32 temp_a2;
    s32 temp_at;
    s32 temp_hi;
    s32 temp_lo;
    s32 temp_t4;
    s32 level_index;
    s32 var_v1;
    s32 var_v0;

    var_v1 = (map_getLevel(map_id) - 1) % (s_jiggyList_level_jiggy_count = 0xA);
    level_index = MAX(0, var_v1);
    s_jiggyList_level_start_index = level_index * 0xA;
    s_jiggyList_level_end_index = (level_index + 1) * 0xA;
    for(s_jiggylist_current_index = s_jiggyList_level_start_index; s_jiggylist_current_index < s_jiggyList_level_end_index; s_jiggylist_current_index++){
            jiggylist_list[s_jiggylist_current_index].unk10.marker = NULL;
    }
    D_8036E830 = 0;
}

void jiggylist_map_actors(void) {
    Actor **jiggy_actors;
    s32 i;

    jiggy_actors = actorArray_findJiggyActors();
    for(s_jiggylist_current_index = 0; jiggy_actors[s_jiggylist_current_index] != NULL; s_jiggylist_current_index++){
        if(!jiggy_actors[s_jiggylist_current_index]->unk44_2){
            jiggylist_list[chjiggy_getJiggyId(jiggy_actors[s_jiggylist_current_index]) - 1].unk10.marker = jiggy_actors[s_jiggylist_current_index]->marker;
        }
    }
}


void func_80332D98(enum map_e map_id, enum jiggy_e jiggy_id, enum file_progress_e flag_id, s32 arg3) {
    f32 sp1C[3];

    if ((gsworld_get_map() == map_id) 
        && fileProgressFlag_get(flag_id)
        && !jiggyscore_isSpawned(jiggy_id)
        && nodeProp_findPositionFromActorId(arg3, sp1C)
    ) {
        codeABC00_spawnJiggyAtLocation(jiggy_id, sp1C);
    }
}

void func_80332E08(void) {
    s32 temp_t0;
    s32 var_v0;
    void *temp_v1;

    for(s_jiggylist_current_index = s_jiggyList_level_start_index; s_jiggylist_current_index < s_jiggyList_level_end_index; s_jiggylist_current_index++) {
            if (jiggylist_list[s_jiggylist_current_index].unk10.marker != NULL) {
                jiggylist_list[s_jiggylist_current_index].update(&jiggylist_list[s_jiggylist_current_index].unk10);
                var_v0 = s_jiggylist_current_index;
            }
    }
    func_80332D98(MAP_69_GL_MM_LOBBY, JIGGY_34_LAIR_MM_WITCH_SWITCH, FILEPROG_18_MM_WITCH_SWITCH_JIGGY_PRESSED, 0x205);
    func_80332D98(MAP_6F_GL_FP_LOBBY, JIGGY_39_LAIR_MMM_WITCH_SWITCH, FILEPROG_19_MMM_WITCH_SWITCH_JIGGY_PRESSED, 0x207);
    func_80332D98(MAP_6D_GL_TTC_LOBBY, JIGGY_36_LAIR_TTC_WITCH_SWITCH, FILEPROG_1A_TTC_WITCH_SWITCH_JIGGY_PRESSED, 0x209);
    func_80332D98(MAP_76_GL_640_NOTE_DOOR, JIGGY_3B_LAIR_RBB_WITCH_SWITCH, FILEPROG_1C_RBB_WITCH_SWITCH_JIGGY_PRESSED, 0x20C);
    func_80332D98(MAP_79_GL_CCW_LOBBY, JIGGY_3C_LAIR_CCW_WITCH_SWITCH, FILEPROG_46_CCW_WITCH_SWITCH_JIGGY_PRESSED, 0x238);
    if ((D_8036E830 == 0) && fileProgressFlag_get(FILEPROG_9C_LAIR_CC_WITCH_SWITCH_LEFT_EYE_PRESSED)) {
        func_80332D98(MAP_6A_GL_TTC_AND_CC_PUZZLE, JIGGY_35_LAIR_CC_WITCH_SWITCH, FILEPROG_9D_LAIR_CC_WITCH_SWITCH_RIGHT_EYE_PRESSED, 0x190);
    }
    D_8036E830 = 1;
}

void jiggylist_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    for(s_jiggylist_current_index = s_jiggyList_level_start_index; s_jiggylist_current_index < s_jiggyList_level_end_index; s_jiggylist_current_index++) {
        if (jiggylist_list[s_jiggylist_current_index].unk10.marker != NULL) {
            jiggylist_list[s_jiggylist_current_index].draw(&jiggylist_list[s_jiggylist_current_index].unk10, gfx, mtx, vtx);
        }
    }
}

void func_8033301C(void) {
    for(s_jiggylist_current_index = s_jiggyList_level_start_index; s_jiggylist_current_index < s_jiggyList_level_end_index; s_jiggylist_current_index++) {
        if (jiggylist_list[s_jiggylist_current_index].unk10.marker != NULL) {
            jiggy_free(marker_getActor(jiggylist_list[s_jiggylist_current_index].unk10.marker));
        }
    }
}

void jiggy_spawn(enum jiggy_e jiggy_id, f32 pos[3]) {
    Struct_core2_ABC00_0 *temp_v0;

    jiggy_id = ((jiggy_id <= 0) || (jiggy_id >= (s_jiggyList_level_jiggy_count * 10))) ? JIGGY_A_MM_CONGA : jiggy_id;
    temp_v0 = &jiggylist_list[jiggy_id - 1];
    if (jiggylist_list[jiggy_id - 1].unk10.marker == NULL) {
        temp_v0->unk10.position[0] = pos[0];
        temp_v0->unk10.position[1] = pos[1];
        temp_v0->unk10.position[2] = pos[2];
        temp_v0->init(&temp_v0->unk10);
        jiggyscore_setSpawned(jiggy_id, TRUE);
        if (!jiggyscore_isCollected(jiggy_id) && (jiggy_id != JIGGY_3E_GV_GRABBA) && (jiggy_id != JIGGY_0B_TTC_JINJO)) {
            core1_ce60_incOrDecCounter(FALSE);
            func_8025A55C(0, 4000, 5);
            coMusicPlayer_playMusic(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
            timedFunc_set_0(3.5f, func_80332BB0);
        }
    }
}

void codeABC00_spawnJiggyAtLocation(enum jiggy_e jiggy_id, f32 location[3]) {
    jiggy_id = ((jiggy_id <= 0) || (jiggy_id >= (s_jiggyList_level_jiggy_count * 10))) ? JIGGY_A_MM_CONGA : jiggy_id;

    jiggylist_list[jiggy_id - 1].unk10.position[0] = location[0];
    jiggylist_list[jiggy_id - 1].unk10.position[1] = location[1];
    jiggylist_list[jiggy_id - 1].unk10.position[2] = location[2];
    jiggylist_list[jiggy_id - 1].init(&jiggylist_list[jiggy_id - 1].unk10);
    jiggyscore_setSpawned(jiggy_id, TRUE);
}

void func_80333270(enum jiggy_e jiggy_id, f32 position[3], void (*method)(Actor *, ActorMarker *), ActorMarker *other_marker) {
    Struct_core2_ABC00_0 *ptr;

    ptr = &jiggylist_list[jiggy_id - 1];
    jiggy_spawn(jiggy_id, position);
    ptr->unk10.unk14 = method;
    ptr->unk10.unk18 = other_marker;
}

void jiggy_free(Actor *arg0)
{
  s32 indx = chjiggy_getJiggyId(arg0) - 1;
  Struct81s *sp18 = &jiggylist_list[indx].unk10;
  if (jiggylist_list[indx].free)
  {
  }
  jiggylist_list[indx].free(sp18);
  sp18->marker = 0;
}

void func_80333334(enum jiggy_e jiggy_id) {
    Struct_core2_ABC00_0 *temp_v0;

    temp_v0 = &jiggylist_list[jiggy_id - 1];
    temp_v0->init = func_80347B54;
    temp_v0->update = func_80347B80;
    temp_v0->draw = func_80347C5C;
    temp_v0->free = func_80347C70;
}

void func_80333388(enum jiggy_e jiggy_id) {
    Struct_core2_ABC00_0 *temp_v0;

    temp_v0 = &jiggylist_list[jiggy_id - 1];
    temp_v0->init = func_80347CC8;
    temp_v0->update = func_80347CF4;
    temp_v0->draw = func_80347DD0;
    temp_v0->free = func_80347DE4;

}

void func_803333DC(Struct81s *arg0, Actor *arg1) {
    s32 jiggy_id;

    arg0->marker = arg1->marker;
    if (arg0->unk14 != NULL) {
        arg0->unk14(arg1, arg0->unk18);
    }
    marker_setFreeMethod(arg1->marker, jiggy_free);
    jiggy_id = ((s32) ((s32)arg0 - (s32)&jiggylist_list) / 0x2C) + 1;
    chjiggy_setJiggyId(arg1, jiggy_id);
    if ((jiggy_id == JIGGY_49_CCW_EYRIE) || (jiggy_id == JIGGY_39_LAIR_MMM_WITCH_SWITCH) || (jiggy_id == JIGGY_3C_LAIR_CCW_WITCH_SWITCH)) {
        arg1->marker->unk40_21 = TRUE;
        arg1->marker->unk40_20 = TRUE;
    }
}
