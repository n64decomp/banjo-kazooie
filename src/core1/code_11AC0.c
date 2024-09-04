#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "music.h"
#include "n_libaudio.h"

extern void func_8025F570(ALCSPlayer *, u8);
extern void func_8025F510(ALCSPlayer *, u8, u8);
extern void func_8025F5C0(ALCSPlayer *, u8);

extern u8 soundfont2ctl_ROM_START[];
extern u8 soundfont2ctl_ROM_END[];
extern u8 soundfont2tbl_ROM_START[];

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
MusicTrackMeta D_80275D40[0xB0] = {
    {"Blank", 15000},
    {"Scrap", 15000},
    {"Jungle 2", 20000},
    {"Snow 2", 20000},
    {"Bells", 21000},
    {"Beach", 20000},
    {"Swamp", 15000},
    {"Crab Cave", 20000},
    {"Title", 15000},
    {"Notes", 15000},
    {"Jinjo", 15000},
    {"Feather", 15000},
    {"Egg", 15000},
    {"Jigpiece", 28000},
    {"Sky", 0x7FFF},
    {"Spooky", 21000},
    {"Training", 15000},
    {"Lighthouse", 24000},
    {"Crab", 15000},
    {"Shell", 0x7FFF},
    {"Feather Inv", 15000},
    {"Extra life", 15000},
    {"Honeycomb", 15000},
    {"Empty honey piece", 15000},
    {"Extra honey", 15000},
    {"Mystery", 15000},
    {"You lose", 20000},
    {"Termite nest", 0x7FFF},
    {"Outside whale", 15000},
    {"Spell", 15000},
    {"Witch House", 23000},
    {"In whale", 0x4650},
    {"Desert", 20000},
    {"In spooky", 0x4650},
    {"Grave", 24000},
    {"Church", 28000},
    {"Sphinx", 20000},
    {"Invulnerabilty", 28000},
    {"Collapse", 15000},
    {"Snake", 15000},
    {"Sandcastle", 15000},
    {"Summer", 20000},
    {"Winter", 0x6978},
    {"Right", 28000},
    {"Wrong", 0x7D00},
    {"Achieve", 0x7D00},
    {"Autumn", 0x55F0},
    {"Default forest", 0x7530},
    {"5 Jinjos", 15000},
    {"Game over", 15000},
    {"Nintendo", 15000},
    {"Ship", 24000},
    {"Shark", 15000},
    {"Ship inside", 24000},
    {"100 Notes", 15000},
    {"Door Open", 15000},
    {"Organ sequence", 0x4650},
    {"Advent", 15000},
    {"Slalom", 15000},
    {"Race win", 15000},
    {"Race lose", 15000},
    {"Jigsaw magic", 15000},
    {"Oh dear", 15000},
    {"Up", 15000},
    {"Down", 15000},
    {"Shamen Hut", 0x4A38},
    {"Jig 10", 0x61A8},
    {"Carpet", 15000},
    {"Squirrel", 15000},
    {"Hornet", 15000},
    {"Treetop", 0x7D00},
    {"Turtle Shell", 0x61A8},
    {"House Summer", 15000},
    {"House Autumn", 15000},
    {"Out Buildings", 15000},
    {"Hornet 2", 15000},
    {"Cabins", 15000},
    {"Rain", 15000},
    {"Jigsaw Open", 15000},
    {"Jigsaw Close", 15000},
    {"Witch 1", 23000},
    {"Witch 2", 23000},
    {"Witch 3", 23000},
    {"Witch 4", 23000},
    {"Witch 5", 23000},
    {"Mr Vile", 15000},
    {"Bridge", 0x55F0},
    {"Turbo Talon Trot", 28000},
    {"Long legs", 28000},
    {"Witch 6", 23000},
    {"Boggy sad", 15000},
    {"Boggy happy", 15000},
    {"Quit", 15000},
    {"Witch 7", 23000},
    {"Witch 8", 23000},
    {"Spring", 0x4650},
    {"Squirrel attic", 0x6590},
    {"Lights", 15000},
    {"Box", 0x4268},
    {"Witch 9", 23000},
    {"Open up", 15000},
    {"Puzzle complete", 0x61A8},
    {"Xmas tree", 15000},
    {"Puzzle in", 15000},
    {"Lite tune", 15000},
    {"Open extra", 15000},
    {"Ouija", 0x7148},
    {"Wozza", 15000},
    {"Intro", 20000},
    {"Gnawty", 15000},
    {"Banjo's Pad", 15000},
    {"Pause", 15000},
    {"Cesspit", 0x61A8},
    {"Quiz", 15000},
    {"Frog", 20000},
    {"GameBoy", 15000},
    {"Lair", 15000},
    {"Red Extra", 0x7D00},
    {"Gold Extra", 0x7D00},
    {"Egg Extra", 0x7D00},
    {"Note door", 15000},
    {"Cheaty", 15000},
    {"Fairy", 20000},
    {"Skull", 0x61A8},
    {"Square Grunty", 0x61A8},
    {"Square Banjo", 0x61A8},
    {"Square Joker", 0x7530},
    {"Square Music", 0x61A8},
    {"Lab", 20000},
    {"Fade Up", 0x61A8},
    {"Puzzle Out", 15000},
    {"Secret Gobi", 20000},
    {"Secret Beach", 20000},
    {"Secret Ice", 20000},
    {"Secret Spooky", 20000},
    {"Secret Squirrel", 20000},
    {"Secret Egg", 20000},
    {"Jinjup", 0x7D00},
    {"Turbo Talon Trot short", 28000},
    {"Fade Down", 0x61A8},
    {"Big Jinjo", 0x7D00},
    {"T1000", 15000},
    {"Credits", 15000},
    {"T1000x", 20000},
    {"Big Door", 20000},
    {"Descent", 20000},
    {"Wind up", 20000},
    {"Air", 20000},
    {"Do jig", 20000},
    {"Picture", 28000},
    {"Piece up", 20000},
    {"Piece down", 20000},
    {"Spin", 20000},
    {"BarBQ", 15000},
    {"Chord1", 20000},
    {"Chord2", 20000},
    {"Chord3", 20000},
    {"Chord4", 20000},
    {"Chord5", 20000},
    {"Chord6", 20000},
    {"Chord7", 20000},
    {"Chord8", 20000},
    {"Chord9", 20000},
    {"Chord10", 20000},
    {"Shock1", 20000},
    {"Shock2", 20000},
    {"Shock3", 20000},
    {"Shock4", 20000},
    {"Sad grunt", 20000},
    {"Podium", 20000},
    {"Endbit", 20000},
    {"Rock", 20000},
    {"Last Bit", 20000},
    {"Unnamed piece", 15000},
    {"Unnamed piece", 15000},
    0
};
s32 D_802762C0 = 0;
s32 D_802762C4 = 0;

/* .bss */
MusicTrack   D_80281720[6];
MusicTrack **D_802820E0;
ALSeqpConfig D_802820E8;
u16          D_80282104; //called as u16 someplaces and s16 others
ALBank *     D_80282108;
structBs     D_80282110[0x20];

/* .code */
void musicInstruments_init(void){
    s32 size;
    ALBankFile * bnk_f; //sp38
    s32 i;
    f32 tmpf1;
    
    size = soundfont2ctl_ROM_END - soundfont2ctl_ROM_START;
    bnk_f = malloc(size);
    osWriteBackDCacheAll();
    osPiStartDma(func_802405D0(), 0, 0, (u32)soundfont2ctl_ROM_START, bnk_f, size, func_802405C4());
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
        n_alCSPNew(&D_80281720[i].cseqp, &D_802820E8);
    }

    alBnkfNew(bnk_f, soundfont2tbl_ROM_START);
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

ALBank *music_get_sound_bank(void){
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

N_ALCSPlayer *func_802500CC(s32 arg0){
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

    if(arg3 < 0.0333333351f){
        arg3 = 0.0333333351f;
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
    if( arg2 < 0.0333333351f){
        arg2 = 0.0333333351f;
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

void func_80250650(void) {
    N_ALCSPlayer *csplayer;
    s32 i;
    s32 channel;

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
                channel = D_80282110[i].chan;

                if (((csplayer->chanMask) & (1 << channel))) {
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
