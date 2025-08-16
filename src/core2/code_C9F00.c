#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern BKCollisionTri *func_802E805C(BKCollisionList *arg0, BKVertexList *vtxList, f32 arg2[3], f32 arg3[3], f32 arg4, f32 arg5[3], f32 arg6[3], f32 arg7[3], s32 arg8);
extern BKCollisionTri *func_802E9118(BKCollisionList *arg0, BKVertexList *vtxList, f32 arg2[3], f32 arg3[3], f32 arg4, f32 arg5[3], f32 arg6[3], f32 arg7, f32 arg8[3], s32 arg9, s32 arg10);
extern BKCollisionTri *func_802E9DD8(BKCollisionList *arg0, BKVertexList *vtxList, f32 arg2[3], f32 arg3[3], f32 arg4, f32 arg5[3], f32 arg6, f32 arg7[3], s32 arg8);
extern s32 func_802EA760(BKModelUnk14List *, s32, f32[3], f32[3], f32, s32, f32*, f32*);
extern bool func_80309DBC(f32[3], f32[3], f32, f32 sp54[3], s32, s32);
extern BKCollisionList *model_getCollisionList(BKModelBin *);
extern BKModelUnk14List *func_8033A12C(BKModelBin *);
void func_80351954(Struct68s *arg);
void func_80351AD0(Struct68s *arg0, enum asset_e model_id);
typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
}Struct_Core2_C9F00_1;

typedef struct {
    void (*unk0)(void *, Struct68s *);
    void (*unk4)(void *, Struct68s *, f32);
}Struct_Core2_C9F00_0;

Struct_Core2_C9F00_1 D_803725C0[] = {
    { 0x37, 0x1, 0x00}, 
    { 0x38, 0x2, 0x24},  
    { 0xF9, 0x5, 0x22}, 
    { 0xFA, 0x6, 0x22},
    { 0xFB, 0x7, 0x22}, 
    { 0xFC, 0x8, 0x22},  
    { 0xFD, 0x9, 0x22}, 
    { 0xFE, 0xA, 0x22},
    { 0xFF, 0xB, 0x22}, 
    {0x100, 0xC, 0x22},  
    {0x100, 0xC, 0x22}, 
    { 0x13, 0xD, 0x00},
    0
};


void func_80351DE0(Struct6Bs *, Struct68s *);
extern void chTumblar_init(void *, Struct68s *);
extern void func_80387940(void *, Struct68s *);
extern void GV_func_80387960(void *, Struct68s *);
extern void func_80387980(void *, Struct68s *);
extern void func_803879A0(void *, Struct68s *);
extern void func_803879C0(void *, Struct68s *);
extern void CC_func_803879E0(void *, Struct68s *);
extern void CC_func_80387A00(void *, Struct68s *);
extern void CC_func_80387A20(void *, Struct68s *);
extern void func_80351FE0(void *, Struct68s *);

void func_80351E60(Struct6Bs *, Struct68s *, f32);
extern void chTumblar_update(void *, Struct68s *, f32);
extern void func_8038B790(void *, Struct68s *, f32);
extern void CCW_func_80387A40(void *, Struct68s *, f32);
extern void func_80352114(void *, Struct68s *, f32);

Struct_Core2_C9F00_0 D_803725F4[] = {
    {         NULL,          NULL}, 
    {(void (*)(void *, Struct68s *))func_80351DE0, (void (*)(void *, Struct68s *, f32))func_80351E60}, 
    {chTumblar_init, chTumblar_update},
    {         NULL,          NULL}, 
    {         NULL, func_8038B790}, 
    {func_80387940, CCW_func_80387A40}, 
    {GV_func_80387960, CCW_func_80387A40}, 
    {func_80387980, CCW_func_80387A40}, 
    {func_803879A0, CCW_func_80387A40}, 
    {func_803879C0, CCW_func_80387A40}, 
    {CC_func_803879E0, CCW_func_80387A40}, 
    {CC_func_80387A00, CCW_func_80387A40}, 
    {CC_func_80387A20, CCW_func_80387A40}, 
    {func_80351FE0, func_80352114}
};

/* .bss */
struct {
    Struct68s *unk0;
    Struct6Cs unk4;
    f32 unk14[3];
    s32 unk20[3];
    Struct68s *unk2C;
}D_80386180;

struct {
    s32 unk0;
    Struct68s *unk4; //start
    Struct68s *unk8; //end
    Struct68s *unkC; //capacity_end
}D_803861B0;


/* .code */
Actor *func_80350E90(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Struct68s *temp_s0;
    BKModelBin *temp_v0;
    void *temp_a2;

    temp_s0 = &D_803861B0.unk4[marker->actrArrayIdx];
    temp_v0 = temp_s0->unkC;

    if (temp_v0 == NULL) {
        return NULL;
    }

    if (temp_s0->unk8 != NULL) {
        temp_s0->unk8(&temp_s0->local, temp_s0, temp_s0->position, temp_s0->unk20, temp_s0->unk2C, temp_v0, gfx, mtx, vtx);
    }
    else {
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(gfx, mtx, temp_s0->position, temp_s0->unk20, temp_s0->unk2C, NULL, temp_s0->unkC);
    }

    return NULL;
}

BKCollisionTri * func_80350F7C(ActorMarker *marker, f32 arg1[3], f32 arg2[3], f32 arg3[3], s32 arg4) {
    BKCollisionTri * sp4C;
    Struct68s *temp_s0;
    BKVertexList *vtx_list;
    BKCollisionList *colision_list;

    temp_s0 = &D_803861B0.unk4[marker->actrArrayIdx];
    if ((temp_s0->unkC == NULL) || (temp_s0->unk30 & 1)) {
        return 0;
    }

    colision_list = model_getCollisionList(temp_s0->unkC);
    vtx_list = model_getVtxList(temp_s0->unkC);
    sp4C = func_802E805C(colision_list, vtx_list, temp_s0->position, temp_s0->unk20, temp_s0->unk2C, arg1, arg2, arg3, arg4);
    if (sp4C != 0) {
        if (func_8029453C()) {
            D_80386180.unk20[0] = (s32) arg2[0];
            D_80386180.unk20[1] = (s32) arg2[1];
            D_80386180.unk20[2] = (s32) arg2[2];
            D_80386180.unk2C = temp_s0;
        }
    }
    return sp4C;
}

BKCollisionTri *func_803510B4(ActorMarker *marker, f32 arg1[3], f32 arg2[3], f32 arg3, f32 arg4[3], s32 arg5, u32 flagFliter) {
    s32 pad44;
    Struct68s *sp40;
    BKVertexList *vertex_list;
    BKCollisionList *collision_list;

    sp40 = &D_803861B0.unk4[marker->actrArrayIdx];
    if ((sp40->unkC == NULL) || (sp40->unk30 & 1)) {
        return 0;
    }
    collision_list = model_getCollisionList(sp40->unkC);
    vertex_list = model_getVtxList(sp40->unkC);
    return func_802E9118(collision_list, vertex_list, sp40->position, sp40->unk20, sp40->unk2C, arg1, arg2, arg3, arg4, arg5, flagFliter);
}

BKCollisionTri *func_80351198(ActorMarker *marker, f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4) {
    s32 pad3C;
    Struct68s *sp38;
    BKVertexList *vtx_list;
    BKCollisionList *collision_list;

    sp38 = &D_803861B0.unk4[marker->actrArrayIdx];
    if ((sp38->unkC == NULL) || (sp38->unk30 & 1)) {
        return 0;
    }
    collision_list = model_getCollisionList(sp38->unkC);
    vtx_list = model_getVtxList(sp38->unkC);
    return func_802E9DD8(collision_list, vtx_list, sp38->position, sp38->unk20, sp38->unk2C, arg1, arg2, arg3, arg4);
}


Struct68s * func_8035126C(f32 position[3], f32 arg1[3], f32 arg2, s32 arg3, enum asset_e arg4) {
    s32 sp2C;
    s32 sp1C;

    sp2C = arg3;
    if (D_803861B0.unk8 == D_803861B0.unkC) {
        sp2C = D_803861B0.unk8 - D_803861B0.unk4;
        sp1C = sp2C * 2;
        D_803861B0.unk4 = (Struct68s *) realloc(D_803861B0.unk4, sp1C * sizeof(Struct68s));
        D_803861B0.unk8 = D_803861B0.unk4 + sp2C;
        D_803861B0.unkC = D_803861B0.unk4 + sp1C;
    }

    D_803861B0.unk8->unk0 = 0;
    D_803861B0.unk8->unk30 = 0;
    D_803861B0.unk8->unk8 = NULL;
    D_803861B0.unk8->unkC = NULL;
    D_803861B0.unk8->unk2C = arg2;
    D_803861B0.unk8->unk31 = arg3;

    TUPLE_COPY(D_803861B0.unk8->position, position)
    TUPLE_COPY(D_803861B0.unk8->unk20, arg1)
    func_80351AD0(D_803861B0.unk8, arg4);
    return D_803861B0.unk8++;

}

void func_803513EC(ModelProp *arg0, s32 arg1) {
    f32 sp3C[3];
    s32 pad30;
    f32 rotation[3];

    arg0->unkB_5 = TRUE;
    arg0->unkB_4 = FALSE;
    sp3C[0] = (f32) arg0->position[0];
    sp3C[1] = (f32) arg0->position[1];
    sp3C[2] = (f32) arg0->position[2];
    rotation[0] = 0.0f;
    rotation[1] = (f32) (arg0->yaw * 2);
    rotation[2] = (f32) (arg0->roll * 2);
    func_8035126C(sp3C, rotation, (f32) (arg0->scale / 100.0), arg1, arg0->model_index + 0x2D1);
}


void func_803514F4(Struct68s *arg0){
    func_80351954(arg0);
    marker_free(arg0->unk4);
    if(arg0->unkC){
        assetcache_release(arg0->unkC);
    }
}

void func_80351538(Struct68s *arg0){
    arg0->unk4 = (ActorMarker *)func_8032FBE4(arg0->position, func_80350E90, 1, 0x47);
    ((ActorMarker *)arg0->unk4)->collidable = FALSE;
    ((ActorMarker *)arg0->unk4)->actrArrayIdx = (arg0 - D_803861B0.unk4);
    ((ActorMarker *)arg0->unk4)->unk18 = &D_80386180.unk4;
    if (D_803725F4[arg0->unk31].unk0 != NULL) {
        D_803725F4[arg0->unk31].unk0(&arg0->local, arg0);
    }
}

bool func_803515EC(NodeProp *arg0) {
    Struct_Core2_C9F00_1 *phi_s0;
    s32 sp48[3];
    s32 sp44;
    ModelProp *sp40;
    s16 temp_v0;
    s16 phi_v0;


    if (arg0->bit6 != 6) {
        return TRUE;
    } else {
        for(phi_s0 = D_803725C0; phi_s0->unk0 != 0; phi_s0++){
            if( (arg0->unk8 == phi_s0->unk0) 
                && ((phi_s0->unk3 == 0) || (map_get() == phi_s0->unk3))
            ){
                sp48[0] = (s32) arg0->x;
                sp48[1] = (s32) arg0->y;
                sp48[2] = (s32) arg0->z;
                if(func_803048E0(&sp48, &sp44, &sp40, 2, 0x1F4)){
                    func_803513EC(sp40, phi_s0->unk2);
                    break;
                }
            }
        } 
    }
    return TRUE;
}

bool func_80351700(Prop * arg0){
    if (((*(u16*)((s32)arg0 + 0xA) << 0x1E) >> 0x1F)) {
        return TRUE;
    }
    return TRUE;
}

bool func_80351724(void * arg0){
    ActorProp *a_prop;
    if (((*(u16*)((s32)arg0 + 0xA) << 0x1E) >> 0x1F) && ((*(u16*)((s32)arg0 + 0xA) << 0x1A) >> 0x1F)) {
        a_prop = (ActorProp *)arg0;
        a_prop->unk8_5 = FALSE;
        a_prop->unk8_4 = TRUE;
    }
    return TRUE;
}

s32 func_80351758_getSfxsourceIndex(Struct68s *arg0) {
    if (arg0->unk0 == NULL) {
        arg0->unk0 = sfxsource_createSfxsourceAndReturnIndex();
    }

    return arg0->unk0;
}

ActorMarker *func_80351794(Struct68s *arg0){
    return arg0->unk4;
}

void func_8035179C_copyPosition(Struct68s* arg0, f32 position[3]) {
    TUPLE_COPY(position, arg0->position)
}

void * func_803517B8(s32 arg0){
    return  &D_803861B0.unk4[arg0].local;
}

Struct68s * func_803517E8(s32 arg0){
    return  &D_803861B0.unk4[arg0];
}

void func_80351814(Struct68s *arg0, f32 arg1[3]) {
    TUPLE_COPY(arg1, arg0->unk20)
}

f32 func_80351830(Struct68s *arg0) {
    return arg0->unk2C;
}


s32 func_80351838(f32 position[3], s32 key_flag, s32 arg2) {
    f32 rotation[3];
    Struct68s *sp28;

    rotation[0] = rotation[1] = rotation[2] = 0.0f;
    sp28 = func_8035126C(position, rotation, 1.0f, 4, key_flag + 0x884);
    func_80351538(sp28);
    func_8038B5D8(&sp28->local, sp28, key_flag, arg2);
    return sp28 - D_803861B0.unk4;
}


bool func_803518C0(Struct68s *arg0){
    return arg0 == D_80386180.unk0;
}

bool func_803518D4(Struct68s *arg0){
    return arg0 == D_80386180.unk2C;
}

void func_803518E8(void){
    Struct68s *phi_s0;
       
    for(phi_s0 = D_803861B0.unk4; phi_s0 < D_803861B0.unk8; phi_s0++){
        func_803514F4(phi_s0);
    }
    free(D_803861B0.unk4);
}

void func_80351954(Struct68s *arg0){
    if(arg0->unk0){
        sfxSource_triggerCallbackByIndex(arg0->unk0);
        sfxsource_freeSfxsourceByIndex(arg0->unk0);
        arg0->unk0 = 0;
    }
}

void func_80351998(void) {

    D_803861B0.unk4 = (Struct68s*)malloc(2*sizeof(Struct68s));
    D_803861B0.unk8 = D_803861B0.unk4;
    D_803861B0.unkC = D_803861B0.unk4 + 2;

    D_80386180.unk0 = NULL;
    D_80386180.unk4.unk0 = func_80350F7C;
    D_80386180.unk4.unk4 = func_803510B4;
    D_80386180.unk4.unk8 = func_80351198;
    D_80386180.unk4.unkC = NULL;
    D_80386180.unk2C = NULL;
}


void func_80351A04(Struct68s *arg0, s32 arg1) {
    arg0->unk30 = (u8)(arg0->unk30 | arg1);
}

void func_80351A14(Struct68s *arg0, Struct68DrawMethod arg1) {
    arg0->unk8 = arg1;
}

void func_80351A1C(s32 arg0, s32 arg1) {
    Struct68s *phi_s0;

    if (arg0 == 2) {
        func_80305290(NULL, func_80351724);
        func_803518E8();
        func_80351998();
    }
    if (arg1 == 2) {
        func_803518E8();
        func_80351998();
        func_80305290(&func_803515EC, &func_80351700);
        for(phi_s0 = D_803861B0.unk4; phi_s0 < D_803861B0.unk8; phi_s0++){
            func_80351538(phi_s0);

        }
    }
}

void func_80351AD0(Struct68s *arg0, enum asset_e model_id) {
    if (arg0->unkC != NULL) {
        assetcache_release(arg0->unkC);
        arg0->unkC = NULL;
    }
    if (model_id != 0) {
        arg0->unkC = assetcache_get(model_id);
    }
}



void func_80351B28(Struct68s *arg0, f32 arg1[3]) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp38;
    BKModelUnk14List *sp34;

    if(arg0->unkC != NULL){
        sp34 = func_8033A12C(arg0->unkC);
        if(sp34 != NULL){
            if(func_802EA760(sp34, 0, arg0->position, arg0->unk20, arg0->unk2C, 0, sp48, &sp38)){
                func_802EA760(sp34, 0, arg1, arg0->unk20, arg0->unk2C, 0, sp3C, &sp38);
                if(func_80309DBC(sp48, sp3C, sp38, sp54, 3, 0)){
                    return;
                }
            }
        }
    }

    TUPLE_COPY(arg0->position, arg1)
    func_8032F64C(arg0->position, arg0->unk4);
}

void func_80351C2C(Struct68s *arg0, f32 arg1[3]){
    TUPLE_COPY(arg0->unk20, arg1)
}

void func_80351C48(void) {
    f32 sp4C[3];
    f32 temp_f20;
    Struct68s *phi_s0;
    s32 sp38[3];

    temp_f20 = time_getDelta();
    D_80386180.unk0 = NULL;
    if (D_80386180.unk2C != NULL) {
        player_getPosition_s32(&sp38);
        if ((sp38[0] == D_80386180.unk20[0]) && (sp38[1] == D_80386180.unk20[1]) && (sp38[2] == D_80386180.unk20[2])) {
            player_getPosition(sp4C);
            mlMtxIdent();
            func_80252CC4(D_80386180.unk2C->position, D_80386180.unk2C->unk20, D_80386180.unk2C->unk2C, 0);
            mlMtx_apply_vec3f(D_80386180.unk14, sp4C);
            if (func_8029FC4C() != 0) {
                D_80386180.unk0 = D_80386180.unk2C;
            } else {
                D_80386180.unk0 = NULL;
            }
        } else {
            D_80386180.unk2C = NULL;
        }
    }

    for(phi_s0 = D_803861B0.unk4; phi_s0 < D_803861B0.unk8; phi_s0++){
        if (D_803725F4[phi_s0->unk31].unk4 != NULL) {
            D_803725F4[phi_s0->unk31].unk4(&phi_s0->local, phi_s0, temp_f20);
        }
    }
    if (D_80386180.unk2C != NULL) {
        mlMtxIdent();
        func_80252C08(D_80386180.unk2C->position, D_80386180.unk2C->unk20, D_80386180.unk2C->unk2C, NULL);
        mlMtx_apply_vec3f(sp4C, D_80386180.unk14);
        func_8028FAB0(sp4C);
    }
    D_80386180.unk2C = NULL;
}

void func_80351DE0(Struct6Bs *arg0, Struct68s *arg1) {
    arg0->unk0 = randf2(80.0f, 100.0f);
    arg0->unk4[0] = arg0->unk4[1] = arg0->unk4[2] = 0.0f;
    arg0->unk10[0] = arg0->unk10[1] = arg0->unk10[2] = 0.0f;
    func_8035179C_copyPosition(arg1, arg0->unk1C);
    func_80351814(arg1, arg0->unk28);
    arg0->unk34 = 0.0f;
}

void func_80351E60(Struct6Bs *arg0, Struct68s *arg1, f32 arg2) {
    f32 sp24[3];

    arg0->unk34 += arg2;
    arg0->unk10[1] = sinf(((arg0->unk34 * arg0->unk0) / 180.0) * BAD_PI) * 20.0f;
    arg0->unk4[0] = cosf(((arg0->unk34 * arg0->unk0) / 180.0) * BAD_PI) * 7.5;
    arg0->unk4[1] = sinf(((arg0->unk34 * arg0->unk0) / 180.0) * BAD_PI) * 3.0f;

    TUPLE_ADD_COPY(sp24, arg0->unk1C, arg0->unk10)
    func_80351B28(arg1, sp24);

    TUPLE_ADD_COPY(sp24, arg0->unk28, arg0->unk4)
    func_80351C2C(arg1, sp24);
}
