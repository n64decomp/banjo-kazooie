#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "music.h"

extern void func_8025F570(ALCSPlayer *, u8);
extern void func_8025F510(ALCSPlayer *, u8, u8);
extern void func_8025F5C0(ALCSPlayer *, u8);

extern ALBankFile D_EA3EB0;
extern ALWaveTable D_EADE60;

/* dependent functions */
void func_8024FA98(u8, enum comusic_e);
void func_8024FD28(u8, s16);
int func_80250074(u8);
u8 func_8025F4A0(ALCSPlayer *, u8);

void func_8025F3F0(ALCSPlayer *, f32, f32);
u16 func_80250474(s32 arg0);
void func_8024AF48(void);
void func_8024FB8C(void);

/* .data */
extern MusicTrackMeta D_80275D40[0xB0];
extern s32          D_802762C0;
extern s32          D_802762C4;

/* .rodata */
extern f32          D_80278180;
extern f32          D_80278184;


/* .data */
MusicTrack   D_80281720[6];
MusicTrack **D_802820E0;
ALSeqpConfig D_802820E8;
u16          D_80282104; //called as u16 someplaces and s16 others
ALBank *     D_80282108;
structBs     D_80282110[0x20];



/* .rodata */

/* .code */
void func_8024F4E0(void){
    s32 size;
    ALBankFile * bnk_f; //sp38
    s32 i;
    f32 tmpf1;
    
    size = (u8*)&D_EADE60 - (u8*)&D_EA3EB0;
    bnk_f = malloc(size);
    osWriteBackDCacheAll();
    osPiStartDma(func_802405D0(), 0, 0, &D_EA3EB0, bnk_f, size, func_802405C4());
    osRecvMesg(func_802405C4(), 0, 1); //osRecvMesg
    D_80282104 = 0xAD;
    D_802820E0 = (MusicTrack **) malloc(D_80282104 * sizeof(MusicTrack *));
    for(i = 0; i < D_80282104; i++){
        D_802820E0[i] = NULL;
    }
    D_802820E8.maxVoices = 0x18;
    D_802820E8.maxEvents = 0x55;
    D_802820E8.maxChannels = 0x10;
    D_802820E8.heap = func_802405B8();
    D_802820E8.initOsc = NULL;
    D_802820E8.updateOsc = NULL;
    D_802820E8.stopOsc = NULL;
    func_8023FA64(&D_802820E8);
    for(i = 0; i < 6; i++){
        n_alCSPNew(&D_80281720[i].cseqp, &D_802820E8); //alCSPNew
    }

    alBnkfNew(bnk_f, (u8 *)&D_EADE60);
    D_80282108 = bnk_f->bankArray[0];
    for(i = 0; i < 6; i++){
        alCSPSetBank(&D_80281720[i].cseqp, D_80282108);
    }

    for(i = 0; i < 6; i++){
        D_80281720[i].unk2 = 0;
        D_80281720[i].unk3 = 0;
        D_80281720[i].index_cpy = 0;
        D_80281720[i].unk17C = 0.0f;
        D_80281720[i].unk180 = 1.0f;
    }
    func_8024FB8C();
}

ALBank *func_8024F758(void){
    return D_80282108;
}

void func_8024F764(s32 arg0){//music track load
    if(D_802820E0[arg0] == NULL){
        func_8033B788();
        D_802820E0[arg0] = assetcache_get(arg0 + 0x1516);
    } 
}

void func_8024F7C4(s32 arg0){
    s32 i;
    if(D_802820E0[arg0] != NULL){
        i = 0;
        for(i = 0; i != 6; i++){
            if(D_80281720[i].index == arg0)
                return;
        }
        assetcache_release(D_802820E0[arg0]);
        D_802820E0[arg0] = 0;
    }
}

void func_8024F83C(void){
    s32 i;
    for(i = 0; i < D_80282104; i++){
        func_8024F7C4(i);
    }
}

void func_8024F890(u8 arg0, enum comusic_e arg1){
    s32 i;
    if(arg1 == -1){
        if(arg1 !=  D_80281720[arg0].index)
          alCSPStop(&D_80281720[arg0].cseqp);
        D_80281720[arg0].index = arg1;

    }
    else{
        if(-1 != D_80281720[arg0].index){
            func_8024F890(arg0, -1);
        }
        D_80281720[arg0].unk2 = 0;
        D_80281720[arg0].unk3 = 0;
        D_80281720[arg0].index = arg1;
        for(i = 0; i < 0xe; i++){
            D_80281720[arg0].unk184[i] = 0;
            D_80281720[arg0].unk192[i] = 0;
        }
        func_8024F764(D_80281720[arg0].index);
        n_alCSeqNew(&D_80281720[arg0].cseq, D_802820E0[D_80281720[arg0].index]);
        
        D_80281720[arg0].cseqp.chanMask = func_80250474(arg0);
        alCSPSetSeq(&D_80281720[arg0].cseqp, &D_80281720[arg0].cseq);
        alCSPPlay(&D_80281720[arg0].cseqp);
        alCSPSetVol(&D_80281720[arg0].cseqp, D_80281720[arg0].unk0);
        if(player_is_present() && func_8028EE84() == BSWATERGROUP_2_UNDERWATER){
            func_8025F3F0(&D_80281720[arg0].cseqp, 0.0f, 1.0f);
        }
        else{
            func_8025F3F0(&D_80281720[arg0].cseqp, D_80281720[arg0].unk17C, D_80281720[arg0].unk180);
        }
    }
}

s32 func_8024FA6C(u8 arg0){
    return D_80281720[arg0].index;
}

void func_8024FA98(u8 arg0, enum comusic_e arg1){
    s32 sp2C;
    s32 sp24;
    volatile s64 sp20;

    sp2C = D_80281720[arg0].index;
    if(arg1 == sp2C || sp2C == -1){
        func_8024F890(arg0, arg1);
    }else{
        func_8024F890(arg0, -1);
        sp20 = osGetTime();
        while(D_80281720[arg0].cseqp.state != AL_STOPPED){
            osGetTime();
        };
        func_8024F7C4(sp2C);
        func_8024F890(arg0, arg1);
    }
}

s32 func_8024FB60(u8 arg0){
    return D_80281720[arg0].cseqp.state;
}

void func_8024FB8C(void){
    s32 i, allStopped;
    volatile s64 sp2C;

    for(i = 0; i < 6; i++){
        func_8024F890(i,-1);
    }
    sp2C = osGetTime();

    do{
        allStopped = 0;
        for(i = 0; i < 6; i++){
            if(func_8024FB60(i) != AL_STOPPED)
                allStopped++;
        }
        osGetTime();
    }while(allStopped);

}

void func_8024FC1C(u8 arg0, enum comusic_e arg1){
    D_80281720[arg0].index_cpy = arg1;
    D_80281720[arg0].unk2 = 1;
    D_80281720[arg0].unk3 = 0;
    D_80281720[arg0].unk0 =  D_80275D40[arg1].unk4;
}

void func_8024FC6C(u8 arg0){
    s32 indx;
    indx = D_80281720[arg0].index;
    if(indx == 0x2D || indx == 0x3D){
        D_80281720[arg0].unk2 = 1;
        D_80281720[arg0].unk3 = 0;
        D_80281720[arg0].index_cpy = D_80281720[arg0].index;
    }else{
        D_80281720[arg0].index_cpy = -1;
        D_80281720[arg0].unk3 = 1;
        D_80281720[arg0].unk2 = 1;
        D_80281720[arg0].unk0 = 0;
    }
}

void func_8024FCE0(u8 arg0, s16 arg1){
    D_80281720[arg0].unk3 = 1;
    D_80281720[arg0].unk2 = 1;
    D_80281720[arg0].unk0 = arg1;
    D_80281720[arg0].index_cpy = D_80281720[arg0].index;
}

//musicTrack_setVolume
void func_8024FD28(u8 arg0, s16 arg1){
    D_80281720[arg0].unk0 = arg1;
    alCSPSetVol(&D_80281720[arg0].cseqp, arg1);
    if(D_80281720[arg0].unk3 && arg1){
        func_8024FCE0(arg0, arg1);
    }
    else if(!D_80281720[arg0].unk3 && arg1 == 0){
        if(func_80250074(arg0) == 0)
            func_8024FC6C(arg0);
    }
}

//musicTrack_setTempo
void func_8024FDDC(u8 arg0, s32 tempo){
    if(func_80250074(arg0) == 0){
        if(!D_80281720[arg0].unk2){
            alCSPSetTempo(&D_80281720[arg0].cseqp, tempo);
        }
    }
}

void func_8024FE44(u8 arg0, f32 arg1, f32 arg2){
    D_80281720[arg0].unk17C = arg1;
    D_80281720[arg0].unk180 = arg2;
    if(func_80250074(arg0) == 0){
        if(func_8028EE84() == BSWATERGROUP_2_UNDERWATER){
            func_8025F3F0(&D_80281720[arg0].cseqp, 0.0f, 1.0f);
        }else{
            func_8025F3F0(&D_80281720[arg0].cseqp, arg1, arg2);
        }
    }
}

void func_8024FEEC(u8 arg0){
    alCSeqGetTicks(&D_80281720[arg0].cseq);
}

void func_8024FF34(void){
    s32 i;

    for(i = 0; i < 6 ; i++){
        switch(D_80281720[i].cseqp.state){
            case AL_PLAYING://L8024FF94
                if(D_80281720[i].unk2){
                    alCSPStop(&(D_80281720[i].cseqp));

                    if(D_80281720[i].unk3)
                        D_80281720[i].unk2 = 0;
                }
                break;
            
            case AL_STOPPED: //L8024FFBC
                if(D_80281720[i].unk2){
                    if(D_80281720[i].unk3){
                        alCSPPlay(&D_80281720[i].cseqp);
                    } else{
                        func_8024FA98(i, D_80281720[i].index_cpy);
                    }
                    D_80281720[i].unk3 = 0;
                    D_80281720[i].unk2 = 0;
                    func_8024FD28(i, D_80281720[i].unk0);
                }
                break;
            case AL_STOPPING: //L80250008
                break;
        }
    }
}

s32 func_80250034(enum comusic_e track_id){
    return D_80275D40[track_id].unk4;
}

void func_80250048(enum comusic_e track_id, u16 arg1){
    D_80275D40[track_id].unk4 = arg1;
}

//song_getName
char *func_80250060(enum comusic_e track_id){
    return D_80275D40[track_id].name;
}

int func_80250074(u8 arg0){
    return (D_80281720[arg0].cseqp.state == AL_STOPPED && D_80281720[arg0].unk3 == 0);
}

s32 func_802500C0(void){
    return *(s16 *)&D_80282104;
}

ALCSPlayer *func_802500CC(s32 arg0){
    return &D_80281720[arg0].cseqp;
}

void func_802500F4(s32 arg0){}

void func_802500FC(s32 arg0){}

void func_80250104(ALCSeq *arg0, s32 arg1, s32 arg2){
    u8 i;
    for(i = 0; i < 6; i++){
        if(arg0 == &D_80281720[i].cseq){
            D_80281720[i].unk184[arg1 - 0x6A] = 1;
            D_80281720[i].unk192[arg1 - 0x6A] = arg2;
            return;
        }
    }
}

void func_80250170(u8 arg0, s32 arg1, s32 arg2){
    D_80281720[arg0].unk184[arg1 - 0x6A] = arg2;
}

s32 func_802501A0(u8 arg0, s32 arg1, s32 *arg2){
    if(arg2 != 0){
        *arg2 =  D_80281720[arg0].unk192[arg1 - 0x6A];
    }
    return D_80281720[arg0].unk184[arg1 - 0x6A];
}

void func_80250200(s32 arg0, s16 chan, s16 arg2, f32 arg3){
    s32 i;
    ALCSPlayer *sp28;
    f32 tmpf;
    s32 mask; 

    sp28 = func_802500CC(arg0);
    mask = osSetIntMask(OS_IM_NONE);
    tmpf = (!func_80250074(arg0))? func_8025F4A0(sp28, chan) :127.0f;

    if(arg3 < D_80278180){
        arg3 = D_80278180;
    }

    for(i = 0; i< 0x20; i++){
        if( (D_80282110[i].unk8 == D_80282110[i].unk10) 
            || (D_80282110[i].unk0 == arg0 && chan ==D_80282110[i].chan)
        ){
            D_80282110[i].unk0 = arg0;
           D_80282110[i].chan = chan;
            D_80282110[i].unk8 = tmpf;
            D_80282110[i].unkC = (arg2 - tmpf)/((arg3 * 60.0f)/2);
            D_80282110[i].unk10 = arg2;
            osSetIntMask(mask);
            return;
        }
    }
    osSetIntMask(mask);
}

void func_80250360(s32 arg0, s32 arg1, f32 arg2){
    ALCSPlayer * sp24;
    s32 i;
    s32 sp1C;
    f32 tempo;
    
    sp24 = func_802500CC(arg0);
    sp1C = osSetIntMask(1);
    tempo = alCSPGetTempo(sp24);
    if( arg2 < D_80278184){
        arg2 = D_80278184;
    }
    for(i = 0; i < 0x20; i++){
        if(D_80282110[i].unk8 == D_80282110[i].unk10 
            || (D_80282110[i].unk0 == arg0 && -1 ==D_80282110[i].chan)
        ){
            D_80282110[i].unk0 = arg0;
           D_80282110[i].chan = -1;
            D_80282110[i].unk8 = tempo;
            D_80282110[i].unkC = (arg1 - tempo)/((arg2 * 60.0f)/2);
            D_80282110[i].unk10 = arg1;
            osSetIntMask(sp1C);
            return;
        }
    }
    osSetIntMask(sp1C);
}

u16 func_80250474(s32 arg0){
    ALCSPlayer * sp24;
    s32 i;
    s32 sp1C;
    f32 tmpf;
    

    if(arg0 != 0)
        return ~0;
    D_802762C0 = (D_802762C4 = -1);
    sp1C = osSetIntMask(1);
    for(i = 0; i < 0x20; i++){
        D_80282110[i].unk8 = -1.0f;
        D_80282110[i].unk10 = -1.0f;
    }
    osSetIntMask(sp1C);
    func_8024AF48();
    if(D_802762C0 == -1){
        D_802762C0 = 0xFFFF;
    }
    return D_802762C0;

}

void func_80250530(s32 arg0, u16 chan_mask, f32 arg2){
    s32 chan;
    if(D_802762C0 != chan_mask){
        if(D_802762C0 == -1){
            arg2 = 0.0f;
        }
        D_802762C0 = chan_mask;
        for(chan = 0; chan < 16; chan++){
            if(chan_mask & (1 << chan)){
                func_80250200(arg0, chan, 0x7F, arg2);
            }
            else{
                func_80250200(arg0, chan, 0, arg2);
            }
        }
    }//L802505E4
}

void func_80250604(s32 arg0, s32 arg1, f32 arg2){
    if(arg1 != D_802762C4){
        if(D_802762C4 == -1){
            arg2 = 0.0f;
        }
        D_802762C4 = arg1;
        func_80250360(arg0, arg1, arg2);
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_11AC0/func_80250650.s")
#else
void func_80250650(void) {
    ALCSPlayer *csplayer;
    s32 i;
    s32 mask;

    for(i = 0; i < 0x20; i++){
        csplayer = func_802500CC(D_80282110[i].unk0);
        if ((D_80282110[i].unk8 != D_80282110[i].unk10) && (func_80250074((u8)D_80282110[i].unk0) == 0)) {
            if (D_80282110[i].unkC >= 0.0f) {
                D_80282110[i].unk8 = MIN(D_80282110[i].unk8 + D_80282110[i].unkC, D_80282110[i].unk10);
            } else {
                D_80282110[i].unk8 = MAX(D_80282110[i].unk8 + D_80282110[i].unkC, D_80282110[i].unk10);
            }
            if (D_80282110[i].chan == -1) {
                alCSPSetTempo(csplayer, (s32) D_80282110[i].unk8);
            } else {
                func_8025F510(csplayer,D_80282110[i].chan, D_80282110[i].unk8);
                if ((csplayer->chanMask) & (1U << D_80282110[i].chan)) {
                    if (D_80282110[i].unk8 == 0.0) {
                        func_8025F5C0(csplayer, D_80282110[i].chan);
                    }
                } else {
                    if (D_80282110[i].unk8 != 0.0f) {
                        func_8025F570(csplayer, D_80282110[i].chan);
                    }
                }
            }
        }
    }
}
#endif
