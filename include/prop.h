#ifndef PROP_H
#define PROP_H

#include <ultra64.h>

#include "structs.h"

typedef struct sprite_prop_s{
    u8 pad[0x12];
} SpriteProp;

typedef struct prop_prop_s{
    u8 pad[0x12];
} PropProp;

typedef struct actor_prop_s{
    struct actorBehavior_s* behavior;
    u8 pad[0x8];
} ActorProp;

typedef struct actorBehavior_s{
    ActorProp*  propPtr;
    struct cude_s*     cudePtr;
    u8          pad8[0x27];
    u8          pad2F:7;
    u8          collidable:1;
    u8          pad30[0x30];
} ActorBehavior;

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

typedef struct actor_s{
    ActorBehavior* behavior;
    f32 position_x;
    f32 position_y;
    f32 position_z;
    u8  pad10[0x4];
    ActorMovement *movement;
    u8  pad18[0x38];
    f32 yaw;
    u8  pad54[0x10];
    f32 yaw_moving;
    f32 pitch;
    f32 unk6C;
    u8  pad70[0xA0];
    f32 roll;
    f32 sound_timer;
    f32 spawn_position_x;
    f32 spawn_position_y;
    f32 spawn_position_z;
    u8  pad124[1];
    u8  alpha;
    u8  render_order;
    u8  pad127[1];
    f32 scale;
    u8  pad130[0x50];
} Actor;

typedef union prop_s
{
    ActorProp   actor;
    SpriteProp  sprite;
    PropProp    prop;
} Prop;


typedef struct cude_s{
    u32 x:5;
    u32 y:5;
    u32 z:5;
    u32 markerCnt:6;
    u32 propCnt:6;
    u32 pad0:5;

}Cube;

#endif
