#ifndef PROP_H
#define PROP_H

#include <ultra64.h>

#include "structs.h"

enum ch_id{
    ch_id_bigbutt = 4
};

typedef struct sprite_prop_s{
    u8 pad0[0x12];
} SpriteProp;

typedef struct prop_prop_s{
    u8 pad0[0x12];
} PropProp;

typedef struct actor_prop_s{
    struct actorMarker_s* marker;
    u8 pad4[0x4];
    u32 unk8_31:24;
    u32 pad8_7:3;
    u32 unk8_4:1;
    u32 unk8_3:1;
    u32 pad8_2:2;
    u32 unk8_0:1;
    u8 padC;
} ActorProp;

typedef struct actorMarker_s{
    ActorProp*  propPtr;
    struct cude_s*     cubePtr;
    u8          pad8[0xC];
    u32         pad14_31:10;
    u32         unk14_21:1;
    u32         pad14_20:21;
    u8          pad18[0x14];
    u32         actrArrayIdx:11; //unk2C
    u32         pad2C_21:18;
    u32         unk2C_2:1;
    u32         pad2C_1:1;
    u32         collidable:1;
    u8          pad30[0xC];
    u32         pad3C_31:30;
    u32         unk3F_1:1;
    u32         pad3F_0:1;
    u8          pad40[0x20];
} ActorMarker;



/*typedef struct mtx_array{
    u32 count;
    u32 size;
    float mtx[];
} MtxArray;*/

typedef struct animation_s{
    void (* matrices)(s32, s32);
    s32     unk4;
    u8      unk8;
    u8      unk9;
    s16     unkA;
    s16     unkC;
    s16     unkE;
    u32     index;
    f32     timer;
    f32     duration;
    u8      unk1C;
    u8      unk1D;
    u8      unk1E;
    u8      unk1F;
} Animation;

typedef struct movement_s{
    Animation *animation;
    f32     timer;
    f32     duration_min;
    f32     duration_max;
    f32     animation_timer;
    f32     transition_timer;
    float     unk18;
    s32     index;
    u8      playback_type;
    u8      playback_direction;
    u8      unk22;
    u8      unk23;
    u8      unk24;
    u8      unk25;
    u8      pad26[2];
} Movement;

typedef struct actorMovement_s{
    Movement movement;
    Animation animation;
} ActorMovement;

typedef struct chmrvile_s{
    u8  pad0[0x4];
    u32 unk4;
    void *unk8;
    u8  unkC;
    u8  padD[0x7];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} ActorLocal_MrVile;

typedef struct chpinkegg_s{
    u32 unk0;
    u32 unk4;
} ActorLocal_PinkEgg;

typedef struct chyumblie_s{
    f32 unk0;
    u8  unk4;
    u8  pad7[3];
    f32 unk8;
    u32 unkC;
} ActorLocal_Yumblie;

typedef struct ch_bgs_6730_s{
    u32  unk0;
    u32  unk4;
    s32  unk8;
    s32  unkC;
} ActorLocal_BGS_6730;

typedef struct chflibbit_s{
    u8  pad0;
    u8  unk1;
    s16 unk2[3];
    s16 unk8[3];
}ActorLocal_Flibbit;

typedef struct chleafboat_s{
    f32 unk0;
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
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
} ActorLocal_Leafboat;

typedef struct chjiggy_s{
    u32 unk0;
    u32 index;
} ActorLocal_Jiggy;

typedef struct actor_anim_info_s{
    u32     index;
    f32     duration;
} ActorAnimationInfo;

typedef struct actor_s{
    ActorMarker* marker;
    f32 position_x;
    f32 position_y;
    f32 position_z;
    u32 unk10_31:6;
    u32 pad10_27:13;
    u32 unk10_4:4;
    u32 pad10_0:8;
    ActorMovement *movement;
    ActorAnimationInfo *unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28; //used in cheggs
    f32 unk2C;
    u8  pad30[8];
    u32  unk38_31:10;
    u32  pad38_21:21;
    u32  unk38_0:1;
    u8  pad3C[0x8];
    s32 unk44_0:28;
    s32 despawn_flag:1;
    s32 unk44_1D:3;
    u8  pad48[0x8];
    f32 yaw; //0x50
    f32 unk54; //0x54
    u8  pad58[0x8];//0x58, 0x5C, 0x60
    f32 unk60; //0x60
    f32 yaw_moving; //0x64
    f32 pitch;//0x68
    u32 unk6C;
    u8  pad70[0xC];
    union
    {
        ActorLocal_Jiggy    jiggy;
        ActorLocal_MrVile   mrVile; 
        ActorLocal_PinkEgg  pinkEgg; 
        ActorLocal_Yumblie  yumblie; 
        ActorLocal_Leafboat leafboat;
        ActorLocal_BGS_6730 bgs_6730;
        ActorLocal_Flibbit  flibbit;
        u8  pad7C[0x70];
    };
    //u8  padAC[0x44];
    u8  padEC[0x8];
    u32 unkF4_31:10;
    u32 unkF4_21:1;
    u32 unkF4_20:12;
    u32 unkF4_8:9;
    u8  padF8[0xC];
    ActorMarker *unk104;
    u8  pad108[8];
    f32 roll;//110
    f32 sound_timer;
    f32 spawn_position_x;
    f32 spawn_position_y;
    f32 spawn_position_z;//120
    u32 pad124_31:12;
    u32  unk124_19:8;
    u32  pad124_11:2;
    u32  unk124_9:2;
    u32  pad124_7:1;
    u32  unk124_6:1;
    u32  pad124_5:6;
    f32 scale;
    u8  pad12C[0x1C];
    void *unk148;
    u8  pad14C[0x20];
    u32  pad16C_31:27;
    u32  unk16C_4:1;
    u32  pad16C_3:4;
    u8  pad170[0x10];
} Actor;



typedef struct actor_info_s{
    u16     unk0;
    s16     actorId;
    u16     modelId;
    u16     startAnimation;
    ActorAnimationInfo*   animations;
    void    (* update_func)(Actor *);
    void    (* unk14)(Actor *);
    Actor*  (* draw_func)(ActorMarker *, Gfx **, Mtx**, u32);
    u8      pad18[4];
    f32     shadow_scale;
    u8      pad20[4];
} ActorInfo;

typedef struct actor_spawn_s{
    ActorInfo   *infoPtr;
    Actor *(*spawnFunc)(f32*, f32*, void*, s32);
    s32         unk8;
} ActorSpawn;

typedef union prop_s
{
    ActorProp   actor;
    SpriteProp  sprite;
    PropProp    prop;
    struct{
        u8 pad0[8];
        s32 pad8: 31;
        s32 markerFlag: 1;
    };
} Prop;


typedef struct cude_s{
    u32 x:5;
    u32 y:5;
    u32 z:5;
    u32 prop1Cnt:6;
    u32 prop2Cnt:6;
    u32 pad0:5;
    Prop *prop1Ptr;
    Prop *prop2Ptr;
}Cube;

typedef struct actor_array{
    u32 unk0;
    u32 unk4;
    Actor data[]; //variable size array
}ActorArray;

#endif
