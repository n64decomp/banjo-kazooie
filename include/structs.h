#ifndef STRUCTS_H
#define STRUCTS_H

#include <ultra64.h>
#include "model.h"
#define MERGE(a, b) a ## b

typedef int unk_type;

typedef struct{
    f32 x;
    f32 y;
    f32 z;
} vec3f;

#define TUPLE(t, n) union{\
    struct{ t n##_x; t n##_y; t n##_z; };\
    struct{ t n##_pitch; t n##_yaw; t n##_roll; };\
    t n[3];\
}

#define PAIR(t, n) union{\
    struct{ t n##_first; t n##_second;};\
    struct{ t n##_min; t n##_max;};\
    struct{ t n##_x; t n##_y;};\
    t n[2];\
}

#define TUPLE_PAIR(t, n) union{\
    struct{ TUPLE(t, n##_min);  TUPLE(t, n##_max);};\
    t n[2][3];\
}


typedef struct variable_length_array{
    s32 elem_size;
    void * begin;
    void * end;
    void * mem_end;
    u8  data[];
}VLA;

#define vector(T) VLA
//^defined to keep element type with vla

typedef struct bk_sprite_s{
    s16 frameCnt;
    s16 type;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC[4];
} BKSprite;

typedef struct{
    Gfx *gfx; //gfx_offset
    Vtx *vtx; //vtx_offset
}BKSpriteFrameDisplayData;
typedef struct{
    BKSprite *sprite;
    BKSpriteFrameDisplayData frame[];
}BKSpriteDisplayData;

typedef struct bk_sprite_frame_s{
    s16 unk0;
    s16 unk2;
    s16 w;
    s16 h;
    s16 chunkCnt;
    s16 unkA;
    u8  padC[8];
} BKSpriteFrame;

typedef struct bk_sprite_texture_block_s{
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} BKSpriteTextureBlock;

typedef struct model_cache_s{
    BKModelBin * modelPtr;
    s32     unk4; 
    s32     unk8;
    u32     unkC;
    u32     unk10;
} ModelCache;

typedef struct portrait_voice_s{
    u16 sfxIndex;
    u8  pad2[2];
    f32 duration;
} PortraitVoice;

typedef struct portrait_info_s{
    u16 assetIndx;
    u8  pad2[2];
    PortraitVoice voiceInfo[5];
} PortraitInfo;

typedef struct struct_0_s{ //floor
    void *  model;
    u16     vtx1;
    u16     vtx2;
    u16     vtx3;
    u8      padA[0x6];
    s16     unk10[6];
    f32     unk1C[3];
    f32     unk28[3];
    f32     normX;
    f32     normY;
    f32     normZ;
    f32     posX; //40
    f32     posY; //44
    f32     posZ; //48
    union{
        struct{
            u32 unk4C_0:32;
        };
        u32     unk4C;
    };
    s16     unk50;
    s16     unk52;
    u32     unk54;
    u8      unk58;
    u8      unk59;
    u8      unk5A;
    u8      unk5B;
    u8      unk5C;
    u8      unk5D;
    u8      unk5E;
    u8      unk5F;
} struct0; //geo(used for floor)

typedef struct struct_1_s{
    u32 unk0;
    u8 pad4[4];
    u32 unk8;
    u8 padC[4];
    u32 unk10;
    u8 pad14[4];
    u32 unk18;
    u8 pad1C[4];
} struct1;

typedef struct struct_2_s{
    f32 unk0;
    u8 unk4; //argument_count
    u8 unk5;
    u8 pad6[2];
    u32 unk8;
    s32 unkC;
    s32 unk10;
    void *unk14; //function_ptr
} struct2s;

typedef struct struct_3_s{
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    u8 pad1D[0x3];
    vector(struct struct_4_s) *unk20;
    s32 unk24;
    s32 unk28;
    void *unk2C;
    f32 unk30;
    u8 unk34;
    u8 pad35[0x1B];
} struct3s;

typedef struct struct_4_s{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18;
    u8 pad19[3];
} struct4s;

typedef struct struct_5_s{
    BKModelBin *unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
    u8 unk34;
    u8 pad35[0x3];
}struct5s;

typedef struct struct_6_s{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u32 unk18;
    vector(struct5s) *unk1C;
    s16 unk20;
    u8 unk22;
    u8 pad23[1];
    void *unk24[4];
    u8    unk34;
    u8 pad35[0x3];
    f32 unk38;
}struct6s;

typedef struct struct_7_s{
    u32 unk0;
}struct7s;

typedef struct struct_8_s{
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
    u32 unk20;
    s32 unk24; //asset_index
    u32 unk28;
    s32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38; //added to x string print position (position?)
    f32 unk3C; //added to y string print position (position?)
    u8 pad40[4];
    f32 unk44; //added to x string print position (sprite w)
    f32 unk48; //added to y string print position (sprite h)
    f32 unk4C; 
    u32 unk50; //asset_ptr (indx in unk24)
    s8 unk54[0xC]; //value string
    f32 unk60;
}struct8s;

typedef struct struct_9_s{
    u8 uid;
    u8 unk1;
    u8 unk2;
    u8 pad3[1];
    f32 unk4; //duration
    s32 unk8; //asset_indx
    s32 unkC; //animation_indx
    f32 unk10;
}struct9s;

typedef struct struct_10_s{
    u8 map_indx;
    u8 unk1;
    u8 unk2;
}struct10s;

typedef struct struct_11_s{
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10; //trackId
    s16 unk12;
    u8 unk14;
    u8 unk15;
    u8 pad16[0x2];
    s32 unk18;
    s32 unk1C[0xE];
} CoMusic;

typedef struct struct_12_s{
    s32 unk0;
    s32 unk1;
} struct12s;

typedef struct struct_13_s{
    s32 cmd;
    u8* str;
}struct13s;

typedef struct struct_14_s{
    s16 unk0;
    s16 unk2;
    TUPLE(f32, unk4);
    struct actorMarker_s *unk10;
    s32 unk14;
    void (*unk18)(struct actorMarker_s *, s32, s32);
    void (*unk1C)(struct actorMarker_s *, s32, s32);
    s32 unk20;
}struct14s;

typedef struct struct_15_s{
    u8 unk0_7:2;
    u8 unk0_5:2;
    u8 pad0_3:4;
}struct15s;

typedef struct struct_16_s{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
}struct16s;

typedef struct struct_18_s{
    s16 uid; /* enum sfx_e */
    s16 unk2;
    f32 unk4;
}struct18s;

typedef struct struct_17_s{
    s16 uid;
    s8 unk2;
    s8 unk3;
    struct18s soundInfo[5];
}struct17s;

typedef struct struct_1A_s{
    u8  pad0[0x8];
    u8  *str;
    s16 unkC;
    u8  unkE;
    u8  unkF;
}struct1As;

typedef struct struct_1B_s{
    s16 map;
    s16 exit;
}struct1Bs;

typedef struct struct_1C_s{
    s16 unk0;
    s16 x;   //0x2
    u8 *string; //0x4
}struct1Cs;

typedef struct struct_1D_s{
    struct struct_1F_s **unk0;
    s16 unk4;
    u8 unk6;
    u8 pad7[1];
    u8 pad8[0xA0];
}struct1Ds;

typedef struct struct_1E_s{
    void (* unk0)(void * arg0, s32 arg1, s32 arg2, s32 arg3);
    void (* unk4)(void * arg0, s32 arg1, s32 arg2);
    void (* unk8)(void * arg0);
}struct1Es;

typedef struct struct_20_s{
    s16 uid;
    s16 count;
    s16 data[];
}struct20s;

typedef struct struct_1F_s{
    s16 count;
    struct20s unk2[];
}struct1Fs;

typedef struct struct_21_s{
    s32 unk0;
    void * unk1;
}struct21s;

typedef struct struct_22_s{
    f32 unk0[3];
    u8 padC[0xC];
    f32 unk18;
    f32 unk1C;
    u8 pad20[0x8];
    s32 unk28[3];
    u8 unk34;
    u8 pad35[0x3];
} struct22s;//size 0x38

//particle
typedef struct struct_2F_s{
    f32 unk0[3];
    f32 unkC;
    f32 frame_10; //frame
    f32 framerate_14; //framerate
    f32 position_18[3];
    f32 unk24[3];
    f32 size_30; //size
    f32 initialSize_34; //initial_size
    f32 finalSizeDiff; //delta_size
    f32 unk3C[3];
    f32 age_48;
    f32 lifetime_4C;
    f32 velocity_50[3];
    u8 unk5C;
    u8 pad5D[3];
} Particle;

//particle_ctrl
typedef struct struct_30_s{
    u32 pad0_31:8;
    u32 doneSpawning_0_23:7; //doneSpawning
    u32 unk0_16:1;
    u32 assetId_0_15:14; //uid
    u32 unk0_1:1;
    u32 unk0_0:1;
    f32 unk4[3];
    f32 unk10;
    f32 unk14;
    u32 unk18;
    BKSprite *sprite_1C; //sprite_ptr
    BKModelBin *model_20; //model_ptr
    f32 particleSpawnTimer_24; //particleSpawnTimer?
    f32 postion_28[3]; //position
    BKSpriteDisplayData *unk34;
    f32 spawnIntervalTimer_38; //spawnIntervalTimer
    s32 unk3C[3];
    u8  sphericalParticleVelocity_48; //sphericalParticalVelocity
    u8  unk49;
    u8  pad4A[0x2];
    TUPLE_PAIR(f32, particleAccerationRange_4C);
    s16 unk64;
    s16 unk66;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    s32 unk7C;
    void  (*particleCallback_80)(struct struct_30_s *, f32 [3]); //particleCallback
    PAIR(s32, particleStartingFrameRange_84);
    PAIR(f32, particleFramerateRange_8C);
    TUPLE_PAIR(f32, particleSpawnPositionRange_94);
    PAIR(f32, particleStartingScaleRange_AC);
    PAIR(f32, particleFinalScaleRange_B4);
    f32 unkBC[3];
    f32 unkC8[3];
    PAIR(f32, spawnIntervalRange_D4);
    f32 unkDC[2]; //particleLifetimeRange
    union
    {
        TUPLE_PAIR(f32, cartisian);
        struct{
            PAIR(f32, yaw);
            PAIR(f32, pitch);
            PAIR(f32, radius);
        }spherical;
    } particleVelocityRange_E4;
    f32 unkFC;
    s32 unk100;
    s16 unk104;
    u8 pad106[0x2];
    f32 unk108;
    f32 unk10C[3];
    f32 unk118[3];
    Particle *pList_start_124; //start_ptr?
    Particle *pList_end_128; //end_ptr
    Particle *pList_capacity_12C; //capacity_end_ptr;
    Particle data[];//end of struct 0x130 
} ParticleEmitter;

typedef struct struct_31_s{
    f32 unk0[2];
    f32 unk8[2];
    f32 unk10[2];
    f32 unk18[2];
    f32 unk20;
    f32 unk24;
} struct31s;

typedef struct struct_32_s{
    f32 unk0[2];
    f32 unk8[2];
    f32 unk10[2];
} struct32s;

typedef struct struct_33_s{
    f32 unk0[3];
    f32 unkC[3];
} struct33s;

typedef struct struct_34_s{
    f32 unk0[3];
    f32 unkC[3];
} struct34s;

typedef struct struct_40_s{
    struct31s unk0;
    f32 unk28;
    f32 unk2C;
} struct40s;

typedef struct struct_41_s{
    struct32s unk0;
    struct33s unk18;
} struct41s;

typedef struct struct_42_s{
    struct32s unk0;
    struct34s unk18;
} struct42s;

typedef struct struct_43_s{
    struct32s unk0;
    struct33s unk18;
    struct34s unk30;
} struct43s;

typedef struct {
    u32 unk0_31:11;
    u32 unk0_20:10;
    u32 unk0_10:11;
}struct44s;

typedef struct {
    s32 unk0;
    s32 unk4;
}struct46s;


typedef struct {
    s16 unk0;
    u8 pad2[0x2];
    f32 unk4;
    f32 unk8;
}struct47s;

typedef struct {
    s16 map;
    u8 pad2[2];
    struct47s unk4[3];
}struct48s;



typedef struct{
    f32 unk0[3];
    f32 unkC[3];
    u8 unk18;
    u8 pad19[3];
    struct struct_4D_s *unk1C;
}struct4Cs;

typedef struct struct_4D_s{
    u8 unk0[0x18];
}struct4Ds;

typedef struct{
    u8 unk0;
    u8 pad1[0x3];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    s16 unk38;
    s16 unk3A;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
}struct4Es;

typedef struct{
    u8 unk0;
    u8 unk1;
    f32 unk4[3];
}struct50s;

typedef struct{
    s16 unk0;
    u8 pad2[4];
    s16 unk6;
    u8 pad8[4];
}struct51s;

typedef struct{
    s32 unk0;
    u8 pad4[8];
}struct52s;

typedef struct{
    u8 unk0;
    u8 unk1;
} struct53s;

typedef struct{
    struct53s *unk0;
    f32 unk4;
    f32 unk8;
    u32 unkC_31:7;
    u32 unkC_24:7;
    u32 unkC_17:7;
    u32 unkC_10:7; 
    u32 unkC_3:2;
    u32 unkC_1:1;
    u32 unkC_0:1;
} struct54s;

typedef struct{
    u8 pad0[0xC];
}struct55s;

typedef struct{
    s32 unk0;
    u8 pad4[4];
    f32 unk8[0][3];
} struct56s;

typedef struct{
    u8 pad0[8];
    s32 unk8;
}struct57s;

typedef struct{
    Mtx mtx_0;
    s32 size_40;
    s32 capacity_44;
    Mtx data[];
}struct58s;

typedef struct {
    f32 (*unk0)[3];
    f32 (*unk4)[3];
}struct5Bs;
#endif
