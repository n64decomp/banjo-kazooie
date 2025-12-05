#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    u8 id;
    u8 unk1;
    f32 vertical_velocity;
    f32 gravity;
    f32 horizontal_velocity;
}BaRebound;

/* .data */
BaRebound s_rebound_list[] = {
    {BA_REBOUND_1_UNK, 0x01, 510.0f, -1200.0f, 200.0f},
    {BA_REBOUND_2_UNK, 0x01, 600.0f, -1500.0f, 300.0f},
    {BA_REBOUND_3_UNK, 0x01, 510.0f, -1200.0f, 100.0f},
    {BA_REBOUND_4_UNK, 0x01, 510.0f, -1200.0f, 200.0f},
    {BA_REBOUND_5_UNK, 0x01, 510.0f, -1200.0f, 300.0f},
    {BA_REBOUND_6_UNK, 0x01, 510.0f, -1200.0f, 400.0f},
    {BA_REBOUND_7_UNK, 0x01, 510.0f, -1200.0f, 500.0f},
    {BA_REBOUND_8_UNK, 0x01, 600.0f, -1500.0f, 100.0f},
    {BA_REBOUND_9_UNK, 0x01, 600.0f, -1500.0f, 200.0f},
    {BA_REBOUND_A_UNK, 0x01, 600.0f, -1500.0f, 300.0f},
    {BA_REBOUND_B_UNK, 0x01, 600.0f, -1500.0f, 400.0f},
    {BA_REBOUND_C_UNK, 0x01, 600.0f, -1500.0f, 500.0f},
    {BA_REBOUND_D_UNK, 0x02, 300.0f, -1200.0f, 0.0f},
    {BA_REBOUND_F_UNK, 0x01, 300.0f, -1200.0f, 0.0f},
    {BA_REBOUND_E_UNK, 0x03, 300.0f, -1200.0f, 0.0f},
    {BA_REBOUND_10_UNK, 0x03, 300.0f, -1200.0f, 0.0f},
    {00}
};

/*.bss*/
BaRebound *s_active_rebound;

/*.code*/
int barebound_set_active(enum ba_rebound_id id){
    int i;
    for(i = 0; s_rebound_list[i].id; i++){
        if(id == s_rebound_list[i].id){
            s_active_rebound = &s_rebound_list[i];
            break;
        }
    }
}

s32 barebound_802987B4(void){
    return s_active_rebound->unk1;
}

f32 barebound_get_vertical_velocity(void){
    return s_active_rebound->vertical_velocity;
}

f32 barebound_get_horizontal_velocity(void){
    return s_active_rebound->horizontal_velocity;
}

f32 barebound_get_gravity(void){
    return s_active_rebound->gravity;
}
