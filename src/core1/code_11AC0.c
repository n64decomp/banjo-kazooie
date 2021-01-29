#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "music.h"

extern MusicTrack D_80281898[];
extern MusicTrack **D_802820E0;
extern ALSeqpConfig D_802820E8;
extern u16 D_80282104;
extern ALBank *D_80282108;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024F4E0.s")
// void func_8024F4E0(void){
//     ALBankFile * bnk_f;
//     void * mb;
//     void * mq;
//     void * mq2;
//     s32 i;
//     ALCSPlayer * cseqp;
    
//     //volatile s32    phi2 = 0xea3eb0;
//     //volatile s32    phi0 = 0xeade60;

//     bnk_f = malloc(0x9FB0);
//     func_80263BE0(); //osWritebackDCacheAll()
//     mb = func_802405D0();
//     mq = func_802405C4();
//     func_802647D0(mb, 0, 0, 0xea3eb0, bnk_f, 0x9FB0, mq);
//     mq2 = func_802405C4();
//     func_80264550(mq2, 0, 1); //osRecvMesg
//     D_80282104 = 0xAD;
//     D_802820E0 = (MusicTrack **) malloc(0xAD * sizeof(MusicTrack *));
//     for(i = 0; i < D_80282104; i++){
//         D_802820E0[i] = NULL;
//     }
//     D_802820E8.maxVoices = 0x18;
//     D_802820E8.maxEvents = 0x55;
//     D_802820E8.maxChannels = 0x10;
//     D_802820E8.heap = func_802405B8();
//     D_802820E8.initOsc = NULL;
//     D_802820E8.updateOsc = NULL;
//     D_802820E8.stopOsc = NULL;
//     func_8023FA64(&D_802820E8);
//     for(i = 0; i < 6; i++){
//         func_8025EABC(&D_80281898[i].cseqp, &D_802820E8); //alCSPNew
//     }
//     func_80267144(bnk_f, 0xeade60); //alBnkfNew
//     for(i = 0; i < 6; i++){
//         func_8025EC30(&D_80281898[i].cseqp, D_80282108); //alSeqpSetBank
//     }
//     for(i = 0; i < 6; i++){
//         D_80281898[i].unk2 = 0;
//         D_80281898[i].unk3 = 0;
//         D_80281898[i].index_cpy = 0;
//         D_80281898[i].unk17C = 0.0f;
//         D_80281898[i].unk180 = 1.0f;
//     }
//     func_8024FB8C();
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024F758.s")

void func_8024F764(s32 arg0){//music track load
    if(D_802820E0[arg0] == NULL){
        func_8033B788();
        D_802820E0[arg0] = assetcache_get(arg0 + 0x1516);
    } 
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024F7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024F83C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024F890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FA98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FB60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FB8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FC6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FE44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8024FF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_802500C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_802500CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_802500F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_802500FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_802501A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_802508E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8025098C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250C84.s")

void func_80250D8C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80251060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8025106C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_8025108C.s")
