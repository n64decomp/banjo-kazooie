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
    u8 pad4[0x7];
    u8 padB_7:4;
    u8 unkB_3:1;
    u8 padB_2:3;
    u8 padC;
} ActorProp;

typedef struct actorMarker_s{
    ActorProp*  propPtr;
    struct cude_s*     cubePtr;
    u8          pad8[0xC];
    u32         pad14_31:10;
    u32         unk14_21:1;
    u32         pad14_20:21;
    u8          pad18[0x17];
    u8          pad2F:7;
    u8          collidable:1;
    u8          pad30[0x30];
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

typedef struct actor_s{
    ActorMarker* marker;
    f32 position_x;
    f32 position_y;
    f32 position_z;
    u32 unk10_31:6;
    u32 pad10_27:26;
    ActorMovement *movement;
    u8  pad18[0x04];
    f32 unk1C;
    u8  pad20[0x18];
    u32  unk38_31:10;
    u32  pad38_21:22;
    u8  pad3C[0x8];
    s32 unk44_0:28;
    s32 despawn_flag:1;
    s32 unk44_1D:3;
    u8  pad48[0x8];
    f32 yaw;
    u8  pad54[0xC];
    f32 unk60;
    f32 yaw_moving;
    f32 pitch;
    f32 unk6C;
    u8  pad70[0xC];
    union
    {
        ActorLocal_MrVile mrVile; 
        ActorLocal_PinkEgg pinkEgg; 
        ActorLocal_Yumblie yumblie; 
        struct {
            u32  unk7C;
            u32  unk80;
            u8  pad84[0x4];
            u8  unk88;
            u8  pad89[0x23];
        };
    };
    u8  padAC[0x44];
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

typedef struct actor_anim_info_s{
    u32     index;
    f32     duration;
} ActorAnimationInfo;

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

#endif
