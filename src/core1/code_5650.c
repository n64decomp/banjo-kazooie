#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_libaudio.h"
#include "n_synth.h"

void  func_802444C0(N_AL_Struct81s *arg0);
void  func_80244050(ALEventQueue *arg0, N_AL_Struct81s *arg1, u16 arg2);

void  func_8024324C(N_ALSndPlayer *arg0);
void  func_802432F8(N_ALSndPlayer *sndp, N_ALEvent *event);
void  func_80243F84(N_AL_Struct81s *arg0);
void  func_80243FE4(N_AL_Struct81s *arg0);
s32   func_80244110(u16 *arg0, u16 *arg1);
void  func_80244190(N_AL_Struct81s *arg0);
void *func_80244608(ALBank *bank, s16 arg1, struct46s *arg2);
void  func_80244978(s32 arg0, s16 type, s32 arg2);
// extern ALEventUnknown;
/* .bss */
#define CODE_5650_ABS(s) (((s) >= 0)? (s): -(s))

N_ALSndPlayer D_8027EEC0;
s16 *D_8027EF14;
extern struct {
    s32 volume[4];
}D_8027EF18;

/* .data */
struct{
    N_AL_Struct81s *unk0;
    N_AL_Struct81s *unk4;
    N_AL_Struct81s *unk8;
}D_802758C0 = {NULL, NULL, NULL};
N_ALSndPlayer *D_802758CC = &D_8027EEC0;
s32 D_802758D0 = 1;
s16 D_802758D4 = 0;

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

void func_8024324C(N_ALSndPlayer *arg0)
{
  N_ALSndPlayer *new_var = (N_ALSndPlayer *)arg0;
  N_ALEvent2 sp3C;
  
  do
  {
    if ((s16)(new_var->nextEvent.type) == 0x20)
    {
      sp3C.type = 0x20;
      alEvtqPostEvent(&new_var->evtq, (ALEvent *) (&sp3C), new_var->frameTime);
      func_80244190(new_var);
    }
    else
    {
      func_802432F8(new_var, &arg0->nextEvent);
    }
    new_var->nextDelta = alEvtqNextEvent(&new_var->evtq, &arg0->nextEvent);
  }
  while (arg0->nextDelta == 0);
  new_var->curTime += new_var->nextDelta;
}

void func_802432F8(N_ALSndPlayer *sndp, N_ALEvent *event) {
    N_AL_Struct81s *temp_s0;
    ALVoiceConfig spDC;
    N_ALSndPlayer *temp_fp;
    N_ALEvent2 *var_s5;
    ALSound *temp_s1;
    
    N_ALEvent spC0;
    N_ALEvent spB0;
    s32 spAC; 
    N_AL_Struct81s *temp_s6;
    s32 spA4;
    s32 temp_t6;
    s32 var_v0;
    bool var_s2;
    s32 sp94;
    s32 sp90;
    N_ALVoice *voice;
    ALKeyMap *keymap;
    
    u16 sp86;
    u16 sp84;
    N_AL_Struct81s *sp80;
    N_ALEvent sp70; 
    s32 var_v1_4;
    s32 sp68;
    u8 clamped_pan;

    temp_fp = n_syn->n_sndp;
    var_s5 = event;
    sp94 = 1;
    sp90 = 0;
    temp_s0 = NULL;
    temp_s6 = NULL;
    do{
        if (temp_s6 != NULL) {
            spB0.msg.generic.data[0].i = temp_s0;
            spB0.type = var_s5->type;
            spB0.msg.generic.data[1].i = var_s5->msg.vol.delta;
            var_s5 = (N_ALEvent *) &spB0;
        }
        temp_s0 = (N_AL_Struct81s*)var_s5->msg.generic.data[0].i;
        temp_s1 = temp_s0->unk8;
        if (temp_s1 == NULL) {
            func_80244110(&sp86, &sp84);
            return;
        }
        keymap = temp_s1->keyMap;
        temp_s6 = temp_s0->node.next;
        switch (var_s5->type) {                         /* irregular */
            case 0x1:
                if((temp_s0->unk40 != 5) && (temp_s0->unk40 != 4))
                    return;
                    
                spDC.fxBus = 0;
                spDC.priority = (u8)temp_s0->unk36;
                spDC.unityPitch = 0;
                var_s2 = (D_802758D4 >= temp_fp->maxSounds); //SHOULD BE ^1
                if (!(var_s2) || (temp_s0->unk3F & 0x10)) {
                    sp90 = n_alSynAllocVoice(&temp_s0->voice, &spDC);
                }
                if (sp90 == 0) {
                    if ((temp_s0->unk3F & 0x12) || (temp_s0->unk38 > 0)) {
                        temp_s0->unk40 = 4U;
                        temp_s0->unk38 = (s32) (temp_s0->unk38 - 1);
                        alEvtqPostEvent(&temp_fp->evtq, (ALEvent *) var_s5, 0x8235);
                        return;
                    }
                    
                    if(var_s2){
                        sp80 = D_802758C0.unk4;
                        do{
                            if (!(sp80->unk3F & 0x12) && (sp80->unk3F & 0x4) && (sp80->unk40 != 3)) {
                                sp70.type = 0x80;
                                sp70.msg.generic.data[0].i = sp80;
                                sp80->unk40 = 3U;
                                var_s2 = 0;
                                alEvtqPostEvent(&temp_fp->evtq, (ALEvent *) &sp70, 0x3E8);
                                n_alSynSetVol(&sp80->voice, 0, 0x3E8);
                            }
                            sp80 = sp80->node.prev;
                        }while(var_s2 && sp80 != NULL);
                        if (!var_s2) {
                            temp_s0->unk38 = 2;
                            alEvtqPostEvent(&temp_fp->evtq, (ALEvent *) var_s5, 0x3E9);
                        }
                        else{
                            func_80243F84(temp_s0);
                        }
                    }
                    else{
                        func_80243F84(temp_s0);
                    }
                    return;
                }
                temp_s0->unk3F |=  4;
                n_alSynStartVoice(&temp_s0->voice, temp_s1->wavetable);
                temp_s0->unk40 = 1;
                D_802758D4 += 1;
                spAC = (s32) (((f32) temp_s1->envelope->attackTime / temp_s0->unk2C) / temp_s0->unk28);
                spA4 = MAX(0, ((D_8027EF14[keymap->keyMin & 0x3F] * ((temp_s1->envelope->attackVolume * temp_s0->unk34 * temp_s1->sampleVolume) / 16129)) / 32767) - 1);
                n_alSynSetVol(&temp_s0->voice, 0, 0);
                n_alSynSetVol(&temp_s0->voice, (s16) spA4, spAC);
                var_v1_4 = (temp_s0->unk3D + temp_s1->samplePan) - 0x40;
                clamped_pan = MIN(MAX(var_v1_4, 0), 0x7F);
                n_alSynSetPan(&temp_s0->voice, clamped_pan);
                n_alSynSetPitch(&temp_s0->voice, temp_s0->unk2C * temp_s0->unk28);
                if ((keymap->keyMax & 0xF) >= 0xE) {
                    var_v0= (keymap->keyMax & 0xF) * 8;
                } else {
                    var_v0 = temp_s0->unk3E;
                    if (D_802758D0) {
                        var_v0 += (keymap->keyMax & 0xF) * 8;
                    }
                }
                var_v0 = MIN(0x7F, MAX(0,  var_v0));
                n_alSynSetFXMix(&temp_s0->voice, var_v0);
                spC0.type = 0x40;
                spC0.msg.generic.data[0].i = temp_s0;
                spAC = (s32) (((f32) temp_s1->envelope->attackTime / temp_s0->unk2C) / temp_s0->unk28);
                alEvtqPostEvent(&temp_fp->evtq, (ALEvent *) &spC0, spAC);
                
                break;
            
            case 0x2:
            case 0x400:
            case 0x1000:
                if ((var_s5->type != 0x1000) || (temp_s0->unk3F & 2)) {
                    switch (temp_s0->unk40) {                      /* switch 1; irregular */
                    case 1:                                 /* switch 1 */
                        func_80244050(&temp_fp->evtq, temp_s0, 0x40);
                        spAC = (s32) (((f32) temp_s1->envelope->releaseTime / temp_s0->unk28) / temp_s0->unk2C);
                        temp_s0->envPhase = 2;
                        temp_s0->unk48 = 0;
                        n_alSynSetVol(&temp_s0->voice, 0, spAC);
                        if (spAC != 0) {
                            spC0.type = 0x80;
                            spC0.msg.generic.data[0].i = temp_s0;
                            if (spAC <= 0x7D00) {
                                spAC = 0x7D00;
                            }
                            alEvtqPostEvent(&temp_fp->evtq, (ALEvent *) &spC0, spAC);
                            temp_s0->unk40 = 2U;
                        } else {
                            func_80243F84(temp_s0);
                        }
                        break;
                        
                    case 4:                                 /* switch 1 */
                    case 5:                                 /* switch 1 */
                        func_80243F84(temp_s0);
                        break;
                    }
                    if (var_s5->type == 2) {
                        var_s5->type = 0x1000;
                    }

                }
                
                break;
            
            case 0x4:
                 temp_s0->unk3D = var_s5->msg.generic.data[1].i;
                if (temp_s0->unk40 == 1) {
                    clamped_pan = MIN(MAX((temp_s0->unk3D + temp_s1->samplePan) - 0x40, 0), 0x7F);
                    n_alSynSetPan(&temp_s0->voice, clamped_pan);
                }
                
                break;
            
            case 0x10:
                temp_s0->unk2C = var_s5->msg.generic.data[1].f;
                if (temp_s0->unk40 == 1) {
                    n_alSynSetPitch(&temp_s0->voice, temp_s0->unk2C * temp_s0->unk28);
                    if (temp_s0->unk3F & 0x20) {
                        func_80243FE4(temp_s0);
                    }
                }
                
                break;
            
            case 0x100:
                temp_s0->unk3E = (u8) var_s5->msg.vol.delta;
                if (temp_s0->unk40 == 1) {
                    if ((keymap->keyMax & 0xF) >= 0xE) {
                        var_v0 = (keymap->keyMax & 0xF) * 8;
                    } else {
                        var_v0 = temp_s0->unk3E;
                        if (D_802758D0 != 0) {
                            var_v0 += (keymap->keyMax & 0xF) * 8;
                        }
                    }

                    var_v0 = MIN(0x7F, MAX(0, var_v0));
                    n_alSynSetFXMix(&temp_s0->voice, var_v0);
                }
                
                break;
            
            case 0x8:
                temp_t6 = MAX(0, (((f32) D_8027EF14[keymap->keyMin & 0x3F] * ((temp_s0->unk44 * (f32) temp_s0->unk34 * (f32)temp_s1->sampleVolume) / 16129)) / 32767) - 1);
                temp_s0->unk34 = (s16) var_s5->msg.vol.delta;
                if (temp_s0->unk40 == 1) {
                    spA4 = MAX(0, (((f32) D_8027EF14[keymap->keyMin & 0x3F] * ((temp_s0->unk44 * (f32) temp_s0->unk34 * (f32)temp_s1->sampleVolume) / 16129)) / 32767) - 1); 
                    var_v0 = spA4 - temp_t6;
                    n_alSynSetVol(&temp_s0->voice, (s16)spA4, MAX(0x3E8, CODE_5650_ABS(var_v0) >> 2));
                }
                
                break;
            
            case 0x800:
                if (temp_s0->unk40 == 1) {
                    spAC = ((temp_s1->envelope->releaseTime / temp_s0->unk28) / temp_s0->unk2C);
                    spA4 = MAX(0, ((f32) (s16) D_8027EF14[keymap->keyMin & 0x3F] * ((temp_s0->unk44 * (f32) temp_s0->unk34 * (f32)temp_s1->sampleVolume) / 16129)) / 32767  - 1);
                    n_alSynSetVol(&temp_s0->voice, (s16)spA4, spAC);
                }
                
                break;
            case 0x40:
                if (!(temp_s0->unk3F & 2)) {
                    spA4 =  MAX(0, ((s32) ((s16) D_8027EF14[keymap->keyMin & 0x3F] * ( (temp_s1->envelope->decayVolume  * temp_s0->unk34 * temp_s1->sampleVolume) / 16129)) / 32767) - 1);
                    spAC = (s32) (((f32) temp_s1->envelope->decayTime / temp_s0->unk28) / temp_s0->unk2C);
                    n_alSynSetVol(&temp_s0->voice, spA4, spAC);
                    spC0.type = 2;
                    spC0.msg.generic.data[0].i = temp_s0;
                    alEvtqPostEvent(&temp_fp->evtq, (ALEvent *) &spC0, spAC);
                    if (temp_s0->unk3F & 0x20) {
                        func_80243FE4(temp_s0);
                    }
                }
                
                break;
            case 0x80:
                func_80243F84(temp_s0);
                
                break;
            
            case 0x200:
                if (temp_s0->unk3F & 0x10) {
                    sp68 = func_80244608(var_s5->msg.midi.duration, (s16)var_s5->msg.generic.data[1].i, temp_s0->unk30);
                    func_80244978(sp68, 8, temp_s0->unk34);
                    func_80244978(sp68, 4, temp_s0->unk3D);
                    func_80244978(sp68, 0x100, temp_s0->unk3E);
                    func_80244978(sp68, 0x10, reinterpret_cast(s32, temp_s0->unk2C));
                }
                
                break;
            default: 
                break;
        }
        var_v0 = (u16)var_s5->type & 0x2D1;
        temp_s0 = temp_s6;
        if ((temp_s0 != NULL) && !var_v0) {
            sp94 = temp_s0->unk3F & 1;
        }
    }while((sp94 == 0) && (temp_s0 != NULL) && !var_v0);
}

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

void func_80244190(N_AL_Struct81s *arg0)
{
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
    for (var_v0 = D_802758C0.unk0; var_v0 != 0; var_v0 = (N_AL_Struct81s *) var_v0->node.next)
    {
        var_v1 = var_v0;
        envelope = var_v1->unk8->envelope;
        temp_a1 = &envelope->attackTime;
        D_8027EF18.volume[1] = (s32) envelope->attackVolume;
        D_8027EF18.volume[2] = (s32) envelope->decayVolume ;
        while (((var_v1->envPhase < 3) && (var_v1->unk48 >= temp_a1[var_v1->envPhase])) && (temp_a1[var_v1->envPhase] != (-1)))
        {
            var_v1->unk48 -= temp_a1[var_v1->envPhase];
            var_v1->envPhase++;
        }

        if (var_v1->envPhase < 3){
            if (temp_a1[var_v1->envPhase] != (-1)) {
                var_v1->unk44 = D_8027EF18.volume[var_v1->envPhase]
                    + (D_8027EF18.volume[var_v1->envPhase + 1] - D_8027EF18.volume[var_v1->envPhase])
                    * var_v0->unk48
                    / temp_a1[var_v1->envPhase];
            } else {
                var_v0->unk44 = D_8027EF18.volume[var_v1->envPhase];
            }
        }

        var_v1->unk48 += arg0->unk48;
    }
}

N_AL_Struct81s *func_8024431C(ALBank *bank, ALSound *sound) {
    s32 sp24;
    ALKeyMap *sp30;
    N_AL_Struct81s *temp_s0;
    OSIntMask mask;

    temp_s0 = D_802758C0.unk8;
    sp30 = sound->keyMap;
    if (temp_s0 != NULL) {
        mask = osSetIntMask(OS_IM_NONE);
        D_802758C0.unk8 = (N_AL_Struct81s *) temp_s0->node.next;
        alUnlink((ALLink *)temp_s0);
        if (D_802758C0.unk0 != NULL) {
            temp_s0->node.next = D_802758C0.unk0;
            temp_s0->node.prev = NULL;
            D_802758C0.unk0->node.prev = temp_s0;
            D_802758C0.unk0 = temp_s0;
        } else {
            temp_s0->node.prev = NULL;
            temp_s0->node.next = NULL;
            D_802758C0.unk0 = temp_s0;
            D_802758C0.unk4 = temp_s0;
        }
        osSetIntMask(mask);
        sp24 = ((sound->envelope->decayTime + 1) == 0);
        // sp24 = sp20 + 0x40;
        temp_s0->unk36 = sp24 + 0x40;
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
        if (sp24 != 0) {
            temp_s0->unk3F |= 2;
        }
        temp_s0->unk3E = 0;
        temp_s0->unk3D = 0x40;
        temp_s0->unk34 = 0x7FFF;
    }
    return temp_s0;
}

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
    return (u16)D_8027EF14[arg0];
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
