#ifndef STRUCTS_H
#define STRUCTS_H

#include <ultra64.h>
#include "model.h"
#include "core2/vla.h"
#define MERGE(a, b) a ## b

#define UNK_TYPE(t) t

typedef int bool;
#define NOT(boolean) ((boolean) ^ 1)
#define BOOL(boolean) ((boolean) ? TRUE : FALSE)

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

#define KEY_VALUE_PAIR(T1, T2) struct { T1 key; T2 value; }

typedef struct freelist_s{
    s16 elem_size;
    s16 elem_cnt;
    u8 unk4[];
}FLA;

#define FREE_LIST(T) struct freelist_s
//^defined to keep element type with sla

typedef struct bk_sprite_s{
    s16 frameCnt;
    s16 type;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    struct{
        u32 bit31 : 4;
        u32 bit27 : 3;
        u32 bit24 : 2;
        u32 bit22 : 2;
        u32 pad_bit20 : 21;
    }unkC;
    s32 offsets[];
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
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
} BKSpriteFrame;

typedef struct bk_sprite_texture_block_s{
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} BKSpriteTextureBlock;

typedef struct model_cache_s{
    BKModelBin * modelPtr;
    BKSprite   * unk4; 
    BKSpriteDisplayData *unk8;
    u32     animated_texture_cache_id;
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
    BKCollisionTri unk4;
    BKCollisionTri unk10;
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
    f32 unk4[3];
    f32 unk10[3];
    u8 unk1C;
    u8 pad1D[0x3];
    vector(struct struct_4_s) *unk20;
    s32 unk24;
    s32 unk28;
    void *unk2C;
    f32 unk30;
    u8 unk34;
    u8 pad35[0x3];
    f32 unk38;
    f32 unk3C;
    f32 unk40[0x4];
} struct3s;

typedef struct struct_4_s{
    f32 unk0[3];
    f32 unkC[3];
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
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
}struct7s;

typedef struct struct_8_s{
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    f32 unk1C; //first 0x20 should be struct7s
    u32 unk20; //item_id
    s32 unk24; //asset_id
    u32 unk28;
    s32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38; //added to x string print position (position?)
    f32 unk3C; //added to y string print position (position?)
    f32 unk40; //scale???
    f32 unk44; //added to x string print position (sprite w)
    f32 unk48; //added to y string print position (sprite h)
    f32 unk4C; 
    u32 unk50; //asset_ptr (indx in unk24)
    s8 string_54[0xC]; //value string
    f32 unk60;
}struct8s;

typedef struct struct_11_s{
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    s16 track_id; //trackId
    s16 unk12;
    u8 unk14;
    u8 unk15;
    u8 pad16[0x2];
    FREE_LIST(struct12s) *unk18;
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

typedef struct struct_1B_s{
    s16 map;
    s16 exit;
}struct1Bs;

typedef struct struct_1C_1_s{
    s16 level_id;
    s16 x;   //0x2
    u8 *string; //0x4
}struct1Cs_1;

typedef struct struct_21_s{
    s32 unk0;
    void * unk1;
}struct21s;



//particle_ctrl
typedef struct particle_emitter{
    u32 pad0_31:8;
    u32 doneSpawning_0_23:7; //doneSpawning
    u32 unk0_16:1;
    u32 assetId_0_15:14; //uid
    u32 dead:1;
    u32 auto_free:1;
    f32 unk4[3];
    f32 fade_in; //fade_in_end
    f32 fade_out; //fade_out_start
    u32 draw_mode;
    BKSprite *sprite_1C; //sprite_ptr
    BKModelBin *model_20; //model_ptr
    f32 particleSpawnTimer_24; //particleSpawnTimer?
    f32 postion_28[3]; //position
    BKSpriteDisplayData *unk34;
    f32 spawnIntervalTimer_38; //spawnIntervalTimer
    s32 rgb[3];
    u8  sphericalParticleVelocity_48; //sphericalParticalVelocity
    u8  alpha;
    u8  pad4A[0x2];
    TUPLE_PAIR(f32, particleAccerationRange_4C);
    s16 unk64;
    s16 sfx_id;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    s32 unk7C;
    void  (*particleCallback_80)(struct particle_emitter *, f32 [3]); //particleCallback
    PAIR(s32, particleStartingFrameRange_84);
    PAIR(f32, particleFramerateRange_8C);
    TUPLE_PAIR(f32, particleSpawnPositionRange_94);
    PAIR(f32, particleStartingScaleRange_AC);
    PAIR(f32, particleFinalScaleRange_B4);
    f32 unkBC[3];
    f32 unkC8[3];
    PAIR(f32, spawnIntervalRange_D4);
    f32 particleLifeTimeRange[2];
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
    struct particle *pList_start_124; //start_ptr?
    struct particle *pList_end_128; //end_ptr
    struct particle *pList_capacity_12C; //capacity_end_ptr;
} ParticleEmitter;

typedef struct particle_scale_and_lifetime_ranges_s{
    f32 unk0[2]; //particle_starting_scale_range
    f32 unk8[2]; //particle_starting_scale_range
    f32 unk10[2]; //particle_spawn_interval_range
    f32 unk18[2]; //particle_lifetime_range
    f32 unk20; //particle_fade_in
    f32 unk24; //particle_fade_in
} ParticleScaleAndLifetimeRanges;

typedef struct struct_32_s{
    f32 unk0[3];
    f32 unkC[3];
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
    ParticleScaleAndLifetimeRanges unk0;
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
    struct struct_81_s *unk0;
    s32 unk4;
}struct46s;


typedef struct{
    f32 unk0[3];
    f32 unkC[3];
    u8 unk18;
    u8 pad19[3];
    struct struct_4D_s *unk1C;
}struct4Cs;

typedef struct struct_4D_s{
    f32 unk0[3];
    f32 unkC[3];
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
    s32 unk0;
    s32 unk4;
    f32 unk8[0][3];
} struct56s;



typedef struct {
    f32 (*unk0)[3];
    f32 (*unk4)[3];
}struct5Bs;

typedef struct{
    u16 unk0_15 : 4;
    u16 unk0_11 : 2;
    u16 unk0_9  : 3;
    u16 unk0_6  : 2;
    u16 unk0_4  : 3;
    u16 unk0_1  : 2;
}struct5Cs;

typedef struct struct_5d_s{
    s32 unk0;
    f32 unk4[3];
    f32 unk10;
    void (*unk14)(struct struct_5d_s *, s32);
    void (*unk18)(struct struct_5d_s *, s32);
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
}Struct5Ds;

typedef struct struct_5e_s{
    u8 pad0[0x8];
    union{
        u32 unk8;
        struct{
            u32 pad8_31 : 4;
            s32 unk8_27 : 1;
            u32 pad8_26 : 27;
        };
    };
}Struct5Es;

typedef struct {
    f32 unk0;
    f32 unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    //u8 padB;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} Struct5Fs;

//Struct60s moved to top

typedef struct{
    void *unk0;
    void *unk4;
    void *unk8; //start_ptr
    void *unkC; //current_ptr
    void *unk10; //end_ptr
    s32 unk14;
    u8 pad18[0x64];
    s32 unk7C;
    s32 unk80;
}Struct61s; //file stream

typedef struct {
    s16 unk0;
    // u8 pad2[2];
    struct struct_63_s *unk4;
}Struct62s;

typedef struct struct_63_s{
    s16 unk0;
    // u8 pad2[2];
    void (*unk4)(vector(struct2s) **, struct actorMarker_s *);
} Struct63s;

typedef struct struct_64_s{
    struct struct_65_s *unk0;
    s32 unk4;
} Struct64s;

typedef struct struct_65_s{
    f32 unk0[3];
    struct actorMarker_s *unkC;
    s32 (*unk10)(f32[3], f32, struct actorMarker_s *);
    s16 unk14[3];
    s16 unk1A[3];
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    s8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
}Struct65s;


typedef void  (*Struct68DrawMethod)(void *, struct struct_68_s *, f32[3], f32[3], f32, BKModelBin*, Gfx**, Mtx**, Vtx**);

typedef struct struct_68_s{
    u8 unk0;
    // u8 pad1[0x3];
    struct actorMarker_s *unk4;
    Struct68DrawMethod unk8;
    BKModelBin *unkC;
    u8 pad10[0x4];
    f32 unk14[3]; //position
    f32 unk20[3]; //rotation
    f32 unk2C;    //scale
    u8 unk30;
    u8 unk31;
    u8 pad32[2];
    u8 local[0x80];
} Struct68s;

typedef struct {
    f32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34;
} Struct6Bs;

typedef struct{
    s32 (* unk0)(struct actorMarker_s *, f32[3], f32[3], f32[3], s32);
    s32 (* unk4)(struct actorMarker_s *, f32[3], f32[3], f32, f32[3], s32, u32);
    s32 (* unk8)(struct actorMarker_s *, f32[3], f32, f32[3], s32);
    s32 (* unkC)(struct actorMarker_s *, f32[3], f32, f32[3], s32);
} Struct6Cs;

typedef struct struct_6D_s{
    u8 unk0;
    // u8 pad1[3];
    f32 unk4;
    f32 unk8;
    void (*unkC)(struct struct_6D_s *);
    void (*unk10)(struct struct_6D_s *);
    s16 unk14[3];//min_vtx
    s16 unk1A[3];//max_vtx
    f32 unk20;
    f32 unk24;
    u8 unk28;
    u8 unk29;
    u8 pad2A[2];
    f32 unk2C[3];
    f32 unk38[3];
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    f32 unk50[4];
    f32 unk60[4];
    f32 unk70;
    f32 unk74;
    f32 unk78[3];
    f32 unk84;
    f32 unk88[3];
    f32 unk94;
    f32 unk98;
    f32 unk9C;
}Struct6Ds;



typedef struct {
    f32 unk0;
    f32 unk4;
}Struct6Fs;

typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
}Struct71s;

typedef struct {
    f32 unk0;
}Struct72s;

typedef struct {
    s16 d_tc[2];
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 dy;
    //u8 pad12[2];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
}Struct73s;

typedef struct {
    u8 pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18[0x8];
    f32 unk20;
    f32 unk24;
    f32 unk28[2];
}Struct74s;

typedef struct {
    f32 unk0;
}Struct75s;

typedef struct {
    s16 alpha;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
}Struct76s;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18[0x8];
    f32 unk20;
    f32 unk24;
    s16 unk28[2];
    f32 unk2C;
}Struct77s;

typedef union {
    Struct6Ds type_6D;
    Struct6Fs type_6F;
    Struct71s type_71;
    Struct72s type_72;
    Struct73s type_73;
    Struct74s type_74;
    Struct77s type_77;
}Struct70s;


typedef struct {
    u8 unk0;
    // u8 pad1[0x3];
    BKModel *unk4;
    s16 unk8;
    u8 padA[2];
    Struct70s unkC;
}Struct6Es;






typedef struct {
    int actor_id;
    struct actorMarker_s *marker;
    f32 position[3];
    void (*unk14)(struct actor_s *, struct actorMarker_s *);
    struct actorMarker_s *unk18;
}Struct81s;

typedef struct {
    int actor_id;
    struct actorMarker_s *marker;
    f32 position[3];
    void (*unk14)(struct actor_s *, struct actorMarker_s *);
    struct actorMarker_s *unk18;
}Struct82s;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8[3];
    s16 unk14[3];
    u8 unk1A;
    u8 pad1B[1];
}Struct83s;

typedef struct{
    s16 texture_type;
    s16 count;
    s32 offset[];
}Struct84s;

typedef struct{
    u8 pad0[1];
}struct85s;

typedef struct{
    f32 unk0[3];
    f32 unkC;
    u32 flags;
    s16 unk14;
    // u8 pad16[2];
    void *unk18;
}struct86s;

typedef struct {
    s32 unk0; //sound state cnt
    s32 unk4;
    s32 unk8; //maxSounds
    ALHeap *unkC; //heap
    u16 unk10;
}Struct87s;
#endif
