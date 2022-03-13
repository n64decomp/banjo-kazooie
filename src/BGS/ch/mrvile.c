#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void func_80335A24(void *, u32, f32, f32);
void set_model_render_mode(u32);
Actor *mrVileDraw(ActorMarker*, Gfx **, Mtx **, u32);
void func_8038C48C(Actor *);
void func_8038BB40(ActorMarker *);

extern f32 D_80391040;
extern f32 D_80391044;
extern f32 D_80391048;
extern f32 D_8039104C;
extern f32 D_80391050;
extern f32 D_80391054;
extern f32 D_80391058;
extern f32 D_8039105C;
extern f32 D_80391060;

ActorInfo D_80390A70 = {0xC8, 0x13A, 0x373, 0x00, NULL,
    func_8038C48C, NULL, mrVileDraw,
    {0,0}, 0, 0.0f, {0,0,0,0}
};

f32 D_80390A94[7] = {0.0f, 0.8f, 0.9f, 1.0f, 0.9f, 0.95f, 1.0f};

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038B9F0.s")

void func_8038BB40(ActorMarker * arg0){
    if(func_8038A9E0(marker_getActor(arg0)->mrVile.unk8) >= 3){
        item_set(ITEM_14_HEALTH, 0);
        func_8028F66C(0xF);
    }
    else{
        item_dec(ITEM_14_HEALTH);
        func_8028F590(4, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BBA0.s")
// 99.9% matching
// void func_8038BBA0(Actor * arg0, u32 arg1){
//     struct2 *reg_s1;

//     (reg_s1 = &arg0->mrVile)->unk14 = 0.0f;
//     if(arg1 == 0x65){
//         reg_s1->unk24 = 0.0f;
//         reg_s1->unk30 = 0.0f;
//         reg_s1->unk2C = 0.0f;
//         reg_s1->unk28 = 0.0f;
//         func_80335924(arg0->unk148, 0xe1, 0.10000000149f, 1.0f); //0xe1 = croc_idle
//     }
//     if(arg1 == 0x66){
//         if(reg_s1->unk24 < 100.0f){
//             reg_s1->unk24 = 100.0f;
//         };
//         func_80335A24(arg0->unk148, 0xe0, 0.1f, 0.5f); //0xe1 = croc_walk
//     }
//     if(arg1 == 0x67){
//         func_80335A24(arg0->unk148, 0x124, 0.1f, 0.5f); //0x124 = croc_munch
//         if(arg0->unk10_31 == 4){
//             timed_playSfx(D_80391040, 0x4C, 0.90f, 0x61A8);
//             timedFunc_set_1(D_80391044, func_8038BB40, arg0->marker);
//         }
//         else{
//             timed_playSfx(D_80391048, 0x4C, 0.90f, 0x61A8);
//             timed_playSfx(D_8039104C, 0x4C, 0.93f, 0x61A8);
//             timed_playSfx(D_80391050, 0x4C, 0.91f, 0x61A8);
//         }
//     }
//     if(arg1 == 0x68){
//         reg_s1->unk14 = 1.0f;
        
//         //!!! bad reg for arg2; !!!
//         timed_playSfx(randf2(D_80391054, D_80391058), (0x97), randf2(D_8039105C, D_80391060), randi2(25000, 32000));
//     }
//     reg_s1->unkC = arg1; 
// }

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BD84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038BDD4.s")

void func_8038C0C8(Actor * arg0, u32 arg1){
    ActorLocal_MrVile *reg_v0;
    if(arg1 == 1)
        func_8038BBA0(arg0, 0x65);
    if(arg1 == 2)
        func_8038BBA0(arg0, 0x65);
    if(arg1 == 3)
        func_8038BBA0(arg0, 0x66);
    if(arg1 == 4)
        func_8038BBA0(arg0, 0x66);
    reg_v0 = &arg0->mrVile;
    if(arg1 == 5){
        reg_v0->unk20 = 0.0f;
        reg_v0->unk1C = 0.0f;
        reg_v0->unk18 = 0.0f;
        func_8038BBA0(arg0, 0x66);
    }
    if(arg1 == 6){
        reg_v0->unk20 = 0.0f;
        reg_v0->unk1C = 0.0f;
        reg_v0->unk18 = 0.0f;
        reg_v0->unk24 = 300.0f;
        func_8038BBA0(arg0, 0x66);
    }
    arg0->state = arg1; 
}

Actor *mrVileDraw(ActorMarker *this, Gfx **gdl, Mtx** mp, u32 arg3){
    Actor *thisActor;
    ActorLocal_MrVile *sp40;
    f32 sp34[3];
    

    thisActor = func_80325888(this, gdl, mp, arg3);
    sp40 = &thisActor->mrVile;
    if (
        (sp40->unkC == 0x68) &&
        (sp40->unk14 > 0.0f) 
        && (thisActor->marker->unk14_21)
    ) {
        func_8034A174(func_80329934(), 5, &sp34);
        sp34[1] -= 30.0f;
        set_model_render_mode(1);
        func_803391A4(gdl, mp, &sp34, 0, sp40->unk14, 0, sp40->unk4);
    }
    return thisActor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C3DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C434.s")

void func_8038C460(ActorMarker *arg0){
    func_8038C0C8(marker_getActor(arg0), 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/mrvile/func_8038C48C.s")
