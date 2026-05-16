#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8034CB64(Struct70s *, s32, BKModel *, s32);
extern void func_8034CD30(Struct70s *, s32, BKModel *, s32);
extern void func_8034CF74(Struct70s *, s32, BKModel *, s32);
extern void func_8034D170(Struct70s *, s32, BKModel *, s32);
extern void func_8034DD74(Struct70s *, s32, BKModel *, s32);
extern void func_8034E6A8(Struct70s *, s32, BKModel *, s32);
extern void func_8034EE2C(Struct70s *, s32, BKModel *, s32);
extern void func_8034F570(Struct70s *, s32, BKModel *, s32);
extern void func_8034CB9C(Struct70s *, BKModel *, s32);
extern void func_8034CF90(Struct70s *, BKModel *, s32);
extern void func_8034CD8C(Struct70s *, BKModel *, s32);
extern void func_8034D048(Struct70s *, BKModel *, s32);
extern void func_8034D194(Struct70s *, BKModel *, s32);
extern void func_8034E26C(Struct70s *, BKModel *, s32);
extern void func_8034E8E4(Struct70s *, BKModel *, s32);
extern void func_8034EF60(Struct70s *, BKModel *, s32);
extern void func_8034F5B0(Struct70s *, BKModel *, s32);
extern void func_8034CB5C(Struct70s *);
extern void func_8034CD28(Struct70s *);
extern void func_8034CF6C(Struct70s *);
extern void func_8034D168(Struct70s *);
extern void func_8034DD48(Struct70s *);
extern void func_8034E6A0(Struct70s *);
extern void func_8034EE24(Struct70s *);
extern void func_8034F568(Struct70s *);

typedef struct{
    void (*unk0)(Struct70s *, s32, BKModel *, s32);
    void (*unk4)(Struct70s *, BKModel *, s32);
    void (*unk8)(Struct70s *); //free function
}Struct_core2_C4F40_1;

/* .data */
Struct_core2_C4F40_1 D_80371FC0[] = {
    {func_8034CF74, func_8034CF90, func_8034CF6C},
    {func_8034CF74, func_8034D048, func_8034CF6C},
    {func_8034D170, func_8034D194, func_8034D168},
    {func_8034DD74, func_8034E26C, func_8034DD48},
    {func_8034E6A8, func_8034E8E4, func_8034E6A0},
    {func_8034CB64, func_8034CB9C, func_8034CB5C},
    {func_8034EE2C, func_8034EF60, func_8034EE24},
    {func_8034CD30, func_8034CD8C, func_8034CD28},
    {func_8034F570, func_8034F5B0, func_8034F568}
};

/* .bss */
vector(Struct6Es) *D_80386130;

/* .code */
Struct6Es *func_8034BED0(ActorMarker *marker, s32 arg1, s32 arg2, s32 arg3) {
    Struct6Es *sp1C;
    s32 temp_a2;

    sp1C = (Struct6Es *)vector_pushBackNew(&marker->unk4C);
    sp1C->unk0 = arg2;
    sp1C->unk4 = marker->unk48;
    sp1C->unk8 = arg1;
    D_80371FC0[sp1C->unk0].unk0(&sp1C->unkC, arg3, sp1C->unk4, sp1C->unk8);
    return sp1C;
}

void func_8034BF54(ActorMarker *marker) {
    Struct6Es *begin_ptr;
    Struct6Es *end_ptr;
    Struct6Es *i_ptr;

    end_ptr = (Struct6Es *)vector_getEnd(marker->unk4C);
    begin_ptr = (Struct6Es *)vector_getBegin(marker->unk4C);
    for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++){
        D_80371FC0[i_ptr->unk0].unk8(&i_ptr->unkC);
    }
    vector_free(marker->unk4C);
}

void func_8034BFF8(ActorMarker *marker) {
    BKMeshList *mesh_list;
    BKMesh *mesh;
    int i;

    if (marker->unk48 != NULL) {
        marker->unk4C = vector_new(sizeof(Struct6Es), 0);
        mesh_list = model_getMeshList(marker->unk48);
        mesh = mesh_list->data;
        for (i = 0; i < mesh_list->count; i++) {
            if ((mesh->uid >= 101) && (mesh->uid < 200)) {
                func_8034BED0(marker, mesh->uid, 2, mesh->uid - 100);
            } else if ((mesh->uid >= 200) && (mesh->uid < 300)) {
                if (func_802E4A08()) {
                    func_8034BED0(marker, mesh->uid, 1, mesh->uid - 200);
                } else {
                    func_8034BED0(marker, mesh->uid, 0, mesh->uid - 200);
                }
            } else if ((mesh->uid >= 300) && (mesh->uid < 400)) {
                func_8034BED0(marker, mesh->uid, 4, mesh->uid - 300);
            } else if ((mesh->uid >= 400) && (mesh->uid < 500)) {
                func_8034BED0(marker, mesh->uid, 3, mesh->uid - 400);
            } else if ((mesh->uid >= 500) && (mesh->uid < 600)) {
                func_8034BED0(marker, mesh->uid, 5, mesh->uid - 500);
            } else if ((mesh->uid >= 600) && (mesh->uid < 700)) {
                func_8034BED0(marker, mesh->uid, 3, mesh->uid - 600);
            } else if ((mesh->uid >= 700) && (mesh->uid < 800)) {
                func_8034BED0(marker, mesh->uid, 6, mesh->uid - 700);
            } else if ((mesh->uid >= 800) && (mesh->uid < 900)) {
                func_8034BED0(marker, mesh->uid, 7, mesh->uid - 800);
            } else if ((mesh->uid >= 900) && (mesh->uid < 1000)) {
                func_8034BED0(marker, mesh->uid, 8, mesh->uid - 900);
            }
            
            mesh = (BKMesh *) &mesh->vertices[mesh->vtx_count];
        }
    }
}

void func_8034C21C(ActorMarker *marker) {
    Struct6Es *i_ptr;
    Struct6Es *end_ptr;
    Struct6Es *begin_ptr;

    end_ptr = (Struct6Es *)vector_getEnd(marker->unk4C);
    D_80386130 = marker->unk4C;
    begin_ptr = (Struct6Es *)vector_getBegin(marker->unk4C);
    for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++){
        D_80371FC0[i_ptr->unk0].unk4(&i_ptr->unkC, i_ptr->unk4, i_ptr->unk8);
    }
}

Struct70s *func_8034C2C4(ActorMarker *marker, s32 arg1) {
    Struct6Es *i_ptr;
    Struct6Es *end_ptr;
    Struct6Es *begin_ptr;

    end_ptr = (Struct6Es *)vector_getEnd(marker->unk4C);
    begin_ptr = (Struct6Es *)vector_getBegin(marker->unk4C);
    for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++){
        if ((i_ptr->unk0 == 3) && (arg1 == i_ptr->unk8)) {
            return &i_ptr->unkC;
        }
    }
    return NULL;
}

Struct70s *func_8034C344(s32 arg0) {
    Struct6Es *i_ptr;
    Struct6Es *end_ptr;
    Struct6Es *begin_ptr;

    end_ptr =  (Struct6Es *)vector_getEnd(D_80386130);
    begin_ptr = (Struct6Es *)vector_getBegin(D_80386130);
    for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++){
        if ((i_ptr->unk0 == 8) && (arg0 == i_ptr->unk8)) {
            return &i_ptr->unkC;
        }
    }
    return NULL;
}
