#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_libaudio.h"

typedef struct {
    ALLink node;
    ALSound *unk8;
    u8 padC[0x1C];
    f32 unk28;
    f32 unk2C;
    s32 unk30;
    s16 unk34;
    s8 unk36;
    u8 pad37[1];
    s32 unk38;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    u8 pad41[3];
    f32 unk44;
    s32 unk48;
    s32 unk4C;
} Struct_core1_3A70_0;

extern struct{
    Struct_core1_3A70_0 *unk0;
    Struct_core1_3A70_0 *unk4;
    Struct_core1_3A70_0 *unk8;
}D_802758C0;
extern ALSndPlayer *D_802758CC;
extern s32 D_802758D0;

u8 pad_8027EEC0[0x54];
u16 *D_8027EF14;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80241490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80241928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802424D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80242BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80243070.s")
// BREAK???===
// void func_80243070(void *arg0) {
    // s16 sp40;
    // ALLink *temp_a0;
    // s32 var_s1;
    // s32 var_v0;
    // u32 var_s0;
    // u32 var_s0_2;
    // void *temp_s0;
    // void *temp_s0_2;
    // void *temp_s0_3;

    // D_802758CC->maxSounds = (s32) arg0->unk8;
    // D_802758CC->target = NULL;
    // D_802758CC->frameTime = 33000;
    // ;
    // D_802758CC->sndState = alHeapDBAlloc(NULL, 0, arg0->unkC, 1, arg0->unk0 * sizeof(Struct_core1_3A70_0));
    // alEvtqNew(&D_802758CC->evtq, alHeapDBAlloc(NULL, 0, arg0->unkC, 1, arg0->unk4 * 0x1C), arg0->unk4);
    // // var_s0 = 1;
    // // var_s1 = 0x50;
    // D_802758C0.unk8 = D_802758CC->sndState;
    // if ((u32) arg0->unk0 >= 2U) {
    //     do {
    //         temp_a0 = var_s1 + D_802758CC->unk40;
    //         alLink(temp_a0, temp_a0 - 0x50);
    //         var_s0 += 1;
    //         var_s1 += 0x50;
    //     } while (var_s0 < (u32) arg0->unk0);
    // }
    // D_8027EF14 = alHeapDBAlloc(NULL, 0, arg0->unkC, 2, (s32) arg0->unk10);
    // var_v0 = 0;
    // var_s0_2 = 0;
    // if (arg0->unk10 != 0) {
    //     do {
    //         var_s0_2 += 1;
    //         *(D_8027EF14 + var_v0) = 0x7FFF;
    //         var_v0 += 2;
    //     } while (var_s0_2 < (u16) arg0->unk10);
    // }
    // D_802758CC->unk0 = 0;
    // D_802758CC->unk8 = &func_8024324C;
    // temp_s0 = D_802758CC;
    // temp_s0->unk4 = temp_s0;
    // n_alSynAddSndPlayer(D_802758CC);
    // temp_s0_2 = D_802758CC;
    // sp40 = 0x20;
    // alEvtqPostEvent(temp_s0_2 + 0x14, (ALEvent *) &sp40, temp_s0_2->unk48);
    // temp_s0_3 = D_802758CC;
    // D_802758CC->unk4C = alEvtqNextEvent(temp_s0_3 + 0x14, temp_s0_3 + 0x28);
// }


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_8024324C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802432F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80243F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80243FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244190.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_8024431C.s")
#else
void *func_8024431C(ALBank *bank, ALSound *sound) {
    s32 pad;
    ALKeyMap *sp30;
    Struct_core1_3A70_0 *temp_s0;
    OSIntMask mask;
    s32 sp24;

    temp_s0 = D_802758C0.unk8;
    sp30 = sound->keyMap;
    if (temp_s0 != NULL) {
        mask = osSetIntMask(OS_IM_NONE);
        D_802758C0.unk8 = (Struct_core1_3A70_0 *) temp_s0->unk0.next;
        alUnlink((ALLink *)temp_s0);
        if (D_802758C0.unk0 != NULL) {
            temp_s0->unk0.next = D_802758C0.unk0;
            temp_s0->unk0.prev = NULL;
            D_802758C0.unk0->unk0.prev = temp_s0;
            D_802758C0.unk0 = temp_s0;
        } else {
            temp_s0->unk0.prev = NULL;
            temp_s0->unk0.next = NULL;
            D_802758C0.unk0 = temp_s0;
            D_802758C0.unk4 = temp_s0;
        }
        osSetIntMask(mask);
        sp24 = ((sound->envelope->decayTime + 1) == 0) + 0x40;
        temp_s0->unk36 = sp24;
        temp_s0->unk40 = 5;
        temp_s0->unk38 = 2;
        temp_s0->unk8 = sound;
        temp_s0->unk2C = 1.0f;
        temp_s0->unk3F = sp30->keyMax & 0xF0;
        temp_s0->unk30 = 0;
        temp_s0->unk3C = 0;
        temp_s0->unk44 = 0.0f;
        temp_s0->unk48 = 0;
        if (temp_s0->unk3F & 0x20) {
            temp_s0->unk28 = alCents2Ratio((sp30->keyBase * 0x64) - 0x1770);
        } else {
            temp_s0->unk28 = alCents2Ratio(((sp30->keyBase * 0x64) + sp30->detune) - 0x1770);
        }
        if (sp24 != 0x40) {
            temp_s0->unk3F |= 2;
        }
        temp_s0->unk3E = 0;
        temp_s0->unk3D = 0x40;
        temp_s0->unk34 = 0x7FFF;
    }
    return temp_s0;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802444C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_80244594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_3A70/func_802445AC.s")

bool func_802445C4(ALBank *bank, s16 arg1){
    ALSound *snd = bank->instArray[0]->soundArray[arg1-1];
    if (snd->envelope->decayTime == -1)
        return TRUE;
    else
        return FALSE;
}

void *func_80244608(ALBank *bank, s16 arg1, struct46s *arg2) {
    ALKeyMap *temp_v0_2;
    ALSound *temp_s2;
    Struct_core1_3A70_0 *temp_v0;
    s32 var_s3;
    s16 sp6E;
    s32 sp68;
    s32 var_s4;
    Struct_core1_3A70_0 *var_fp;
    ALEvent sp50;
    ALEvent sp40;

    var_fp = NULL;
    sp6E = 0;
    var_s3 = 0;
    if (arg1 == 0) {
        return NULL;
    }

    do{
        temp_s2 = bank->instArray[0]->soundArray[arg1-1];
        temp_v0 = func_8024431C(bank, temp_s2);
        if (temp_v0 != NULL) {
            temp_v0->unk4C = (s32) (arg1 - 1);
            D_802758CC->target = temp_v0;
            sp50.type = AL_SEQ_MIDI_EVT;
            ((s32 *)&sp50.msg)[0] = temp_v0;
            var_s4 = temp_s2->keyMap->velocityMax * 0x8235;
            if (temp_v0->unk3F & 0x10) {
                temp_v0->unk3F &= ~(0x10);
                alEvtqPostEvent(&D_802758CC->evtq, (ALEvent *) &sp50, var_s3 + 1);
                sp68 = var_s4 + 1;
                sp6E = arg1;
            } else {
                alEvtqPostEvent(&D_802758CC->evtq, (ALEvent *) &sp50, var_s4 + 1);
            }
            var_fp = temp_v0;
        }
        temp_v0_2 = temp_s2->keyMap;
        var_s3 += var_s4;
        arg1 = temp_v0_2->velocityMin + ((temp_v0_2->keyMin & 0xC0) * 4);
    } while (arg1 != 0 && temp_v0 != NULL);

    if (var_fp != NULL) {
        var_fp->unk3F |= 1;
        var_fp->unk30 = arg2;
        if (sp6E != 0) {
            var_fp->unk3F |= 0x10;
            sp40.type = 0x200;
            ((s32 *)&sp40.msg)[0] = var_fp;
            ((s32 *)&sp40.msg)[1] = sp6E;
            ((s32 *)&sp40.msg)[2] = bank;
            alEvtqPostEvent(&D_802758CC->evtq, &sp40, sp68);
        }
    }
    if (arg2 != NULL) {
        arg2->unk0 = (s32) var_fp;
    }
    return var_fp;
}

void func_80244814(Struct_core1_3A70_0 *arg0){
    ALEvent evt;

    evt.type = 0x400;
    ((s32 *)&evt.msg)[0] = arg0;
    if(arg0 != NULL){
        arg0->unk3F &= ~(0x10);
        alEvtqPostEvent(&D_802758CC->evtq, &evt, 0);
    }
}

void func_80244860(u8 arg0) {
    OSIntMask mask;
    ALEvent evt;
    Struct_core1_3A70_0 *var_s0;

    mask = osSetIntMask(1U);
    for(var_s0 = D_802758C0.unk0; var_s0 != NULL; var_s0 =  (Struct_core1_3A70_0 *)var_s0->node.next){
        evt.type = 0x400;
        ((s32 *)&evt.msg)[0] = (s32)var_s0;
        if ((var_s0->unk3F & arg0) == arg0) {
            var_s0->unk3F &= ~(0x10);
            alEvtqPostEvent(&D_802758CC->evtq, &evt, 0);
        }
    }
    osSetIntMask(mask);
}

void func_80244918(void){
    func_80244860(1);
}

void func_80244938(void){
    func_80244860(0x11);
}

void func_80244958(void){
    func_80244860(3);
}

void func_80244978(s32 arg0, s16 type, s32 arg2){
    ALEvent sp18;
    if(arg0){
        sp18.type = type;
        ((s32 *)&sp18.msg)[0] = arg0;
        ((s32 *)&sp18.msg)[1] = arg2;

        alEvtqPostEvent(&D_802758CC->evtq, &sp18, 0);
    }
}

s32 func_802449C4(u8 arg0){
    return D_8027EF14[arg0];
}

void func_802449E4(u8 arg0, u16 arg1) {
    Struct_core1_3A70_0 *var_s0;
    s32 pad30;
    ALEvent evt;

    var_s0 = D_802758C0.unk0;
    D_8027EF14[arg0] = arg1;
    while(var_s0 != NULL){
        if ((var_s0->unk8->keyMap->keyMin & 0x3F) == arg0) {
            evt.type = 0x800;
            ((s32 *)&evt.msg)[0] = var_s0;
            alEvtqPostEvent(&D_802758CC->evtq, &evt, 0);
        }
        var_s0 = (Struct_core1_3A70_0 *)var_s0->node.next;
    }
}

void func_80244A98(s32 arg0){
    D_802758D0 = arg0;
}
