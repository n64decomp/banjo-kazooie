#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_libaudio.h"

void func_802444C0(N_AL_Struct81s *arg0);
void func_80244050(ALEventQueue *arg0, N_AL_Struct81s *arg1, u16 arg2);



void func_8024324C(N_ALSndPlayer *arg0);

// extern ALEventUnknown;
/* .bss */
N_ALSndPlayer D_8027EEC0;
u16 *D_8027EF14;
extern struct {
    u8 pad0[4];
    s32 volume[3];
}D_8027EF18;

/* .data */
extern struct{
    N_AL_Struct81s *unk0;
    N_AL_Struct81s *unk4;
    N_AL_Struct81s *unk8;
}D_802758C0 = {NULL, NULL, NULL};
extern N_ALSndPlayer *D_802758CC = &D_8027EEC0;
extern s32 D_802758D0 = 1;
extern s16 D_802758D4 = 0;

/* .code */
void func_80243070(Struct87s *arg0) {
    N_AL_Struct81s *temp_a0;
    N_AL_Struct81s *var_v0;
    ALEvent sp40;
    u32 var_s0;

    D_802758CC->maxSounds = (s32) arg0->unk8;
    D_802758CC->target = NULL;
    D_802758CC->frameTime = 33000;
    D_802758CC->sndState = alHeapDBAlloc(NULL, 0, arg0->unkC, 1, arg0->unk0 * sizeof(N_AL_Struct81s));
    alEvtqNew(&D_802758CC->evtq, alHeapDBAlloc(NULL, 0, arg0->unkC, 1, arg0->unk4 * 0x1C), arg0->unk4);
    D_802758C0.unk8 = D_802758CC->sndState;
    for(var_s0 = 1; var_s0 < arg0->unk0; var_s0++){
        var_v0 =  (N_AL_Struct81s *)D_802758CC->sndState;
        temp_a0 = var_s0 + var_v0;
        alLink((ALLink *)temp_a0, (ALLink*)(temp_a0 - 1));
    }
    D_8027EF14 = alHeapDBAlloc(NULL, 0, arg0->unkC, 2, (s32) arg0->unk10);
    for(var_s0 = 0; var_s0 < arg0->unk10; var_s0++){
        D_8027EF14[var_s0] = 0x7FFF;
    }
    D_802758CC->node.next = NULL;
    D_802758CC->node.handler = (ALVoiceHandler)func_8024324C;
    D_802758CC->node.clientData = D_802758CC;
    n_alSynAddSndPlayer(D_802758CC);
    sp40.type = 0x20;
    alEvtqPostEvent(&D_802758CC->evtq, &sp40, D_802758CC->frameTime);
    D_802758CC->nextDelta = alEvtqNextEvent(&D_802758CC->evtq, &D_802758CC->nextEvent);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_5650/func_8024324C.s")
#else
void func_8024324C(N_ALSndPlayer *arg0) {
    N_ALEvent sp3C;

    do {
        if (arg0->nextEvent.type == 0x20) {
            sp3C.type = 0x20;
            alEvtqPostEvent(&arg0->evtq, (ALEvent *) &sp3C, arg0->frameTime);
            func_80244190(arg0);
        } else {
            func_802432F8(arg0, &arg0->nextEvent);
        }
        arg0->nextDelta = alEvtqNextEvent(&arg0->evtq, &arg0->nextEvent);
    } while (arg0->nextDelta == 0);
    arg0->curTime += arg0->nextDelta;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_5650/func_802432F8.s")

void func_80243F84(N_AL_Struct81s *arg0) {
    if (arg0->unk3F & 4) {
        n_alSynStopVoice(&arg0->voice);
        n_alSynFreeVoice(&arg0->voice);
    }
    func_802444C0(arg0);
    func_80244050(&D_802758CC->evtq, arg0, 0xFFFF);
}

void func_80243FE4(N_AL_Struct81s *arg0) {
    ALEvent evt;
    f32 sp1C;

    sp1C = alCents2Ratio(arg0->unk8->keyMap->detune)* arg0->unk2C;
    evt.type = 0x10;
    evt.msg.unk3A70.unk0 = arg0;
    evt.msg.unk3A70.unk4 = reinterpret_cast(s32, sp1C);
    alEvtqPostEvent(&D_802758CC->evtq, &evt, 33333);
}

void func_80244050(ALEventQueue *arg0, struct struct_81_s *arg1, u16 arg2) {
    s32 pad[5];
    u32 mask;
    ALEventListItem *next_event_list;
    ALEventListItem *event_list;

    mask = osSetIntMask(OS_IM_NONE);
    for(event_list = (ALEventListItem *)arg0->allocList.next; event_list != NULL; event_list = next_event_list) {
        next_event_list = (ALEventListItem *)event_list->node.next;
        if ((arg1 == event_list->evt.msg.unk3A70.unk0) && (reinterpret_cast(u16, event_list->evt.type) & arg2)) {
            if (next_event_list != NULL) {
                next_event_list->delta += event_list->delta;
            }
            alUnlink((ALLink *)event_list);
            alLink((ALLink *)event_list, (ALLink *)arg0);
        }
    }
    osSetIntMask(mask);
}

s32 func_80244110(u16 *arg0, u16 *arg1) {
    N_AL_Struct81s *var_v0;
    N_AL_Struct81s *var_v1_2;
    N_AL_Struct81s *var_a2;
    u16 var_a0;
    u16 var_a3;
    u16 var_v1;

    var_v0 = D_802758C0.unk0;
    var_v1_2 = D_802758C0.unk8;
    var_a2 = D_802758C0.unk4;
    
    for(var_a3 = 0; var_v0 != NULL; var_a3++){
        var_v0 = (N_AL_Struct81s *) var_v0->node.next;
    }

    
    for(var_a0 = 0; var_v1_2 != NULL; var_a0++) {
        var_v1_2 = (N_AL_Struct81s *) var_v1_2->node.next;
    }
    
    for(var_v1 = 0; var_a2 != NULL; var_v1++) {
        var_a2 = (N_AL_Struct81s *) var_a2->node.prev;
    }

    *arg0 = var_a0;
    *arg1 = var_a3;
    return var_v1;
}


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_5650/func_80244190.s")
#else
void func_80244190(N_AL_Struct81s *arg0) {
    ALMicroTime *temp_a1;
    s32 prev_volume;
    s32 temp_t1;
    s32 temp_t5;
    s32 var_t0;
    ALMicroTime var_t1;
    u8 temp_t6;
    u8 var_a2;
    ALEnvelope *envelope;
    N_AL_Struct81s *var_v0;
    N_AL_Struct81s *var_v1;

    for(var_v0 = D_802758C0.unk0; var_v0 != NULL; var_v0 = (N_AL_Struct81s *)var_v0->node.next){
        var_v1 = var_v0;
        envelope = var_v0->unk8->envelope;
        temp_a1 = &envelope->attackTime;
        D_8027EF18.volume[AL_PHASE_ATTACK] = (s32) envelope->attackVolume;
        D_8027EF18.volume[AL_PHASE_DECAY] = (s32) envelope->decayVolume;
        while( var_v0->envPhase < AL_PHASE_RELEASE 
                && var_v0->unk48 >= temp_a1[var_v0->envPhase] 
                && temp_a1[var_v0->envPhase] != -1
        ){
            var_v0->unk48 -= temp_a1[var_v0->envPhase];
            var_v0->envPhase++;
        }

        if (var_v0->envPhase < AL_PHASE_RELEASE) {
            if (temp_a1[var_v1->envPhase] != -1) {
                var_v0->unk44 = D_8027EF18.volume[var_v0->envPhase - 1] + ((s32) ((D_8027EF18.volume[var_v0->envPhase] - D_8027EF18.volume[var_v0->envPhase - 1]) * var_v0->unk48) / temp_a1[var_v0->envPhase]);
            } else {
                var_v0->unk44 = D_8027EF18.volume[var_v0->envPhase - 1]; //
            }
        }
        var_v0->unk48 += arg0->unk48;
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_5650/func_8024431C.s")
#else
N_AL_Struct81s *func_8024431C(ALBank *bank, ALSound *sound) {
    s32 pad;
    ALKeyMap *sp30;
    N_AL_Struct81s *temp_s0;
    OSIntMask mask;
    s32 sp24;

    temp_s0 = D_802758C0.unk8;
    sp30 = sound->keyMap;
    if (temp_s0 != NULL) {
        mask = osSetIntMask(OS_IM_NONE);
        D_802758C0.unk8 = (N_AL_Struct81s *) temp_s0->unk0.next;
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
        temp_s0->envPhase = AL_PHASE_ATTACK;
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

void func_802444C0(N_AL_Struct81s *arg0){
    N_AL_Struct81s *var_v0;

    sizeof(ALVoice);

    var_v0 = D_802758C0.unk0;
    if(arg0 == D_802758C0.unk0){
        D_802758C0.unk0 = (N_AL_Struct81s *)arg0->node.next;
    }

    if(arg0 == D_802758C0.unk4){
        D_802758C0.unk4 = (N_AL_Struct81s *)arg0->node.prev;
    }

    alUnlink((ALLink *)arg0);

    if(D_802758C0.unk8 != NULL){
        arg0->node.next = (ALLink *)D_802758C0.unk8;
        arg0->node.prev = NULL;
        D_802758C0.unk8->node.prev = (ALLink *)arg0;
        D_802758C0.unk8 = arg0;
    }
    else{
        arg0->node.prev = NULL;
        arg0->node.next = NULL;
        D_802758C0.unk8 = arg0;
    }

    if(arg0->unk3F & 0x4){
        D_802758D4--;
    }

    arg0->unk40 = 0;
    if(arg0->unk30 != NULL){
        if(*arg0->unk30 == arg0){
            *arg0->unk30 = NULL;
        }
        arg0->unk30 = NULL;
    }
}

void func_80244594(N_AL_Struct81s *arg0, u8 arg1){
    if(arg0 != NULL)
        arg0->unk36 = arg1;
}

s32 func_802445AC(N_AL_Struct81s *arg0){
    if(arg0 != NULL)
        return arg0->unk40;
    return 0;
}

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
    N_AL_Struct81s *temp_v0;
    s32 var_s3;
    s16 sp6E;
    s32 sp68;
    s32 var_s4;
    N_AL_Struct81s *var_fp;
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

void func_80244814(N_AL_Struct81s *arg0){
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
    N_AL_Struct81s *var_s0;

    mask = osSetIntMask(1U);
    for(var_s0 = D_802758C0.unk0; var_s0 != NULL; var_s0 =  (N_AL_Struct81s *)var_s0->node.next){
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
    N_AL_Struct81s *var_s0;
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
        var_s0 = (N_AL_Struct81s *)var_s0->node.next;
    }
}

void func_80244A98(s32 arg0){
    D_802758D0 = arg0;
}
