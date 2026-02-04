#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 damage;
    s32 state;
} struct_C0E0;

typedef struct{
    s16 height;
    u8  damage;
    u8  state;
} struct_C0E0_1;

typedef struct{
    u8 pad0[0xC];
    struct_C0E0_1 unkC[];
} struct_C0E0_2;

void bafalldamage_start(void);

/* .data */
struct_C0E0_1 bafalldamage_lookup_table[]={
    {1000, 0, 0}, 
    {1500, 0, 0}, 
    {2000, 0, 0}, 
    {7000, 8, 2},  
    {6000, 7, 1}, 
    {5000, 6, 1}, 
    {4000, 5, 1}, 
    {3000, 4, 1},  
    {2000, 3, 1}, 
    {1000, 2, 1}, 
    {0, 1, 1}, 
    {-1, 0, 0}
};

/* .bss */
f32 bafalldamage_start_position[3];
u8  bafalldamage_state;
struct_C0E0 D_8037C1C0;

/* .code */
s32 __bafalldamage_lookup(struct_C0E0 *arg0, s32 height, struct_C0E0_1 *arg2){
    struct_C0E0_1 *iPtr;
    for(iPtr = &arg2[3]; iPtr->height >= 0; iPtr++){
        if(iPtr->height + 1000 < height){
            arg0->damage = iPtr->damage;
            return iPtr->state;
        }
    }
    return 0;
}

s32 __bafalldamage_get_damage(struct_C0E0 *arg0, s32 height){
    arg0->damage = 0;
    if(height < 0)
        return 0;
    else{
        switch(bsStoredState_getTransformation()){
            case TRANSFORM_2_TERMITE: //L80293110 
                return __bafalldamage_lookup(arg0, height, bafalldamage_lookup_table);
            case TRANSFORM_3_PUMPKIN: //L80293124
                return __bafalldamage_lookup(arg0, height, bafalldamage_lookup_table);
            case TRANSFORM_5_CROC: //L80293138  
                return __bafalldamage_lookup(arg0, height, bafalldamage_lookup_table);
            case TRANSFORM_4_WALRUS: //L8029314C
                return __bafalldamage_lookup(arg0, height, bafalldamage_lookup_table);
            case TRANSFORM_6_BEE: //L80293160
                return __bafalldamage_lookup(arg0, height, bafalldamage_lookup_table);
            default:
                return __bafalldamage_lookup(arg0, height, bafalldamage_lookup_table);
                break;
        }
    }
}

void __bafalldamage_update(void){
    f32 player_position[3];
    s32 height;

    player_getPosition(player_position);
    height = bafalldamage_start_position[1] - player_position[1];
    D_8037C1C0.state = __bafalldamage_get_damage(&D_8037C1C0, height);
}

s32 bafalldamage_get_damage(s32 *damage){
    *damage = D_8037C1C0.damage;
    return D_8037C1C0.state;
}

f32 bafalldamage_get_distance_fallen(void){
    f32 player_position[3];
    s32 temp_v0;

    player_getPosition(player_position);
    temp_v0 = bafalldamage_start_position[1] - player_position[1];
    return temp_v0;
}

s32 bafalldamage_get_state(void){
    return bafalldamage_state;
}

void bafalldamage_set_state(s32 arg0){
    bafalldamage_state = arg0;
    if(bafalldamage_state == 2 || bafalldamage_state == 3)
        bafalldamage_start();
}

void bafalldamage_set_start_position(f32 arg0[3]){
    ml_vec3f_copy(bafalldamage_start_position, arg0);
}

void bafalldamage_init(void){
    playerPosition_get(bafalldamage_start_position);
    bafalldamage_state = 0;
    bafalldamage_set_state(1);
    D_8037C1C0.damage = 0;
    D_8037C1C0.state = 0;
}

void bafalldamage_update(void){
    enum bsgroup_e player_movement_group;
    player_movement_group = player_movementGroup();
    if(player_isStable() || (player_getWaterState() != BSWATERGROUP_0_NONE) || player_movement_group == BSGROUP_A_FLYING){
        bafalldamage_start();
        bafalldamage_set_state(1);
    }
    __bafalldamage_update();
}

void bafalldamage_start(void){
    f32 player_position[3];

    playerPosition_get(player_position);
    bafalldamage_set_start_position(player_position);
}
