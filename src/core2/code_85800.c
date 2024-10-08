#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "n_libaudio.h"
#include <core1/viewport.h>

extern f32 func_80256AB4(f32, f32, f32, f32);
extern void func_80335394(s32, f32);
extern f32 sfx_randf2(f32, f32);

#define SFX_SRC_FLAG_0_UNKOWN (1 << 0)
#define SFX_SRC_FLAG_1_UNKOWN (1 << 1)
#define SFX_SRC_FLAG_2_UNKOWN (1 << 2)
#define SFX_SRC_FLAG_3_UNKOWN (1 << 3)
#define SFX_SRC_FLAG_4_UNKOWN (1 << 4)
#define SFX_SRC_FLAG_5_UNKOWN (1 << 5)
#define SFX_SRC_FLAG_6_UNKOWN (1 << 6)
#define SFX_SRC_FLAG_7_UNKOWN (1 << 7)

typedef struct {
    f32 position[3];
    f32 fade_inner_radius_sqr; //inner_radius_squared
    f32 fade_outer_radius_sqr; //outer_radius_squared
    s16 unk14;
    u8 unk16;
    u8 pad17[0x1];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    s16 sfx_uid;
    s16 sample_rate;//sample_rate
    u8 unk2C;
    u8 pad2D[3];
    void (*unk30)(u8 indx);
    f32 unk34; //volume
    f32 unk38;
    f32 unk3C;
    u8 unk40;
    u8 unk41;
    u8 busy;
    u8 unk43_7:3; // value is set to 1, 2 or 3
    u8 unk43_4:3;
    u8 unk43_1:2;
}SfxSource;

u8   sfxsource_createSfxsourceAndReturnIndex(void);
void sfxsource_setSfxId(u8 indx, enum sfx_e uid);
void sfxsource_setSampleRate(u8, s32);
void func_8030DD90(u8, s32);
void func_8030DCCC(u8, s32);
void func_8030E0B4(u8, f32, f32);
f32  func_8030E200(u8);
void func_8030E2C4(u8);
int func_8030ED70(enum sfx_e uid);
void func_8030EDAC(f32, f32);

/* .bss */
struct46s D_80382470[10];
SfxSource sfxsources[35];
f32 D_80382E0C;
f32 D_80382E10;

/* .code */
void __sfx_getPlayerPositionIfPresent(f32 arg0[3]){
    if(player_is_present())
        player_getPosition(arg0);
    else
        ml_vec3f_clear(arg0);
}

void func_8030C7D0(SfxSource *arg0, s32 arg1){
    arg0->unk43_7 = arg1;
}

s32 func_8030C7E8(SfxSource *arg0){
    return arg0->unk43_7;
}

void func_8030C7F8(SfxSource *arg0, s32 arg1){
    arg0->unk43_4 = arg1;
}

int func_8030C814(SfxSource *arg0, s32 arg1){
    return arg0->unk43_4 == arg1;
}

void sfxsource_setFlag(SfxSource *arg0, s32 arg1){
    arg0->unk41 |= arg1;
}

void sfxsource_clearFlag(SfxSource *arg0, s32 arg1){
    arg0->unk41 &= ~arg1;
}

s32 sfxsource_isFlagSet(SfxSource *arg0, s32 arg1){
    return arg0->unk41 & arg1;
}

int sfxsource_isFlagCleared(SfxSource *arg0, s32 arg1){
    return (arg0->unk41 & arg1) == 0;
}

void sfxsource_initAll(void){
    int i;
    for(i = 0; i < 35; i++)
        sfxsources[i].busy = FALSE;
}

SfxSource *sfxsource_at(u8 indx){
    return sfxsources + indx;
}

struct46s *func_8030C8DC(s32 indx){
    return D_80382470 + indx - 1;
}

Struct81s *func_8030C8F4(s32 indx){
    return D_80382470[indx - 1].unk0;
}

u8 sfxsource_getNewIndex(void){
    int i;
    for(i = 1; i < 35; i++){
        if(!sfxsources[i].busy){
            sfxsources[i].busy = TRUE;
            return i;
        }
    }
    return 0;
}

void func_8030C9F4(s32 indx){
    D_80382470[indx - 1].unk4 = 0;
}

void func_8030CA08(void){
    int i;
    for(i = 0; i < 10; i++){
        D_80382470[i].unk0 = 0;
        D_80382470[i].unk4 = 0;
    }
}

s32 func_8030CA60(void){
    int i;
    for(i = 0; i < 10; i++){
        if(D_80382470[i].unk4 == 0 && D_80382470[i].unk0 == 0){
            D_80382470[i].unk4 = 1;
            return i+1;
        }
        
    }
    return 0;
}

void sfxsource_free(u8 indx){
    SfxSource *ptr = sfxsource_at(indx);
    if(ptr->unk40){
        func_8030C9F4(ptr->unk40);
        ptr->unk40 = 0;
    }
    sfxsources[indx].busy = FALSE;
}

void func_8030CBD0(SfxSource *arg0){
    s32 sp24 = func_8030CA60();
    struct46s *temp_a1;
    if(sp24){
        if(arg0->unk40)
            func_8030C9F4(arg0->unk40);
        arg0->unk40 = sp24;
        func_8030C7F8(arg0, 1);
        sfxsource_setFlag(arg0, SFX_SRC_FLAG_2_UNKOWN);
        sfxsource_setFlag(arg0, SFX_SRC_FLAG_3_UNKOWN);
        sfxsource_setFlag(arg0, SFX_SRC_FLAG_4_UNKOWN);
        if(arg0->sfx_uid > 0x3e8){
            func_80335354(arg0->sfx_uid - 0x3e9, func_8030C8DC(arg0->unk40));
        }
        else{
            func_8033531C(arg0->sfx_uid, func_8030C8DC(arg0->unk40));
        }
    }//L8030CC7C
}

void func_8030CC90(SfxSource *arg0){
    if(func_8030C814(arg0, 1)){
        sfxsource_clearFlag(arg0, SFX_SRC_FLAG_5_UNKOWN);
        func_8030C7F8(arg0, 2);
        if(arg0->unk40){
            func_8033543C(func_8030C8F4(arg0->unk40));
        }
    }
}

s32 func_8030CCF0(SfxSource *arg0, s32 sample_rate){
    f32 player_position[3];
    f32 diff[3];
    f32 dist_sqr;
    s32 retVal;
    __sfx_getPlayerPositionIfPresent(player_position);
    diff[0] = arg0->position[0] - player_position[0];
    diff[1] = arg0->position[1] - player_position[1];
    diff[2] = arg0->position[2] - player_position[2];
    dist_sqr = diff[0]*diff[0] + diff[1]*diff[1] + diff[2]*diff[2];
    if( dist_sqr < arg0->fade_inner_radius_sqr)
        retVal = sample_rate;
    else if( dist_sqr < arg0->fade_outer_radius_sqr) 
        retVal = arg0->unk14 + (((arg0->fade_outer_radius_sqr-dist_sqr))/(arg0->fade_outer_radius_sqr - arg0->fade_inner_radius_sqr))*(sample_rate - arg0->unk14);
    else
        retVal = arg0->unk14;
    return retVal;
}

s32 func_8030CDE4(SfxSource *arg0){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 temp_f0;
    f32 pad;

    viewport_getPosition_vec3f(sp44);
    viewport_getLookVector(sp38);
    sp2C[0] = arg0->position[0] - sp44[0];
    sp2C[1] = arg0->position[1] - sp44[1];
    sp2C[2] = arg0->position[2] - sp44[2];
    sp2C[1] = 0.0f;
    if(sp2C[0]*sp2C[0] + sp2C[1]*sp2C[1] + sp2C[2]*sp2C[2] < 10.0f){
        return 0x40;
    }
    ml_vec3f_normalize(sp2C);
    sp38[1] = 0.0f;
    ml_vec3f_normalize(sp38);
    temp_f0 = func_80256AB4(sp38[0], sp38[2], sp2C[0], sp2C[2]);
    if(arg0->unk16){
        arg0->unk18 += 0.07*((f32)(s32)(64.0f - (temp_f0 * 63.0f)) - arg0->unk18);
    }
    else{
        arg0->unk18 = (f32)(s32)(64.0f - temp_f0*63.0f);
    }
    return (s32)arg0->unk18;
}

void func_8030CF68(s32 arg0, s32 arg1){
    if(arg0){
        func_803353F4(func_8030C8F4(arg0), arg1);
    }
}

void func_8030CF9C(s32 arg0, s32 arg1){
    if(arg0){
        func_80335418(func_8030C8F4(arg0), arg1);
    }
}

void func_8030CFD0(s32 arg0, f32 arg1){
    if(arg0){
        func_80335394(func_8030C8F4(arg0), arg1);
    }
}

void func_8030D004(s32 arg0, s32 arg1){
    if(arg0){
        func_803353BC(func_8030C8F4(arg0), (u16) arg1);
    }
}

s32 func_8030D038(SfxSource *arg0, s32 arg1){
    if(sfxsource_isFlagSet(arg0,SFX_SRC_FLAG_6_UNKOWN)){
        if(sfxsource_isFlagSet(arg0, SFX_SRC_FLAG_7_UNKOWN)){
            if(player_is_present() && player_getWaterState() == BSWATERGROUP_2_UNDERWATER)
                    arg1 *= arg0->unk3C;
        }
        else{//L8030D0B4
            if(player_is_present() && player_getWaterState() != BSWATERGROUP_2_UNDERWATER)
                    arg1 *= arg0->unk38;
        }
    }
    return arg1;
}

s32 func_8030D10C(u8 indx){
    s32 sp24;
    SfxSource * ptr;
    s32 tmp_v0;
    f32 tmp_f2;

    ptr = sfxsource_at(indx);
    sp24 = 0;
    if(func_8030C814(ptr, 1)){
        if(sfxsource_isFlagSet(ptr, SFX_SRC_FLAG_2_UNKOWN)){
            func_8030CFD0(ptr->unk40, ptr->unk34);
        }//L8030D164
        
        if(sfxsource_isFlagSet(ptr,SFX_SRC_FLAG_4_UNKOWN)){
            tmp_f2 = ((f32)ptr->unk2C + D_80382E0C*127.0f)*D_80382E10;
            tmp_f2 = MAX(0.0f,MIN(127.0f, tmp_f2));
            func_8030CF68(ptr->unk40, tmp_f2);
        }

        //L8030D228
        if(sfxsource_isFlagSet(ptr, SFX_SRC_FLAG_1_UNKOWN)){
            tmp_v0 = func_8030CCF0(ptr, ptr->sample_rate);
            if(tmp_v0 < 100)
                sp24 = 1;
            func_8030D004(ptr->unk40, func_8030D038(ptr, tmp_v0));
            func_8030CF9C(ptr->unk40, func_8030CDE4(ptr));
        }else{//L8030D288
            if(sfxsource_isFlagSet(ptr, SFX_SRC_FLAG_3_UNKOWN)){
                tmp_v0 = func_8030D038(ptr, ptr->sample_rate);
                if(tmp_v0 < 100)
                    sp24 = 1;
                func_8030D004(ptr->unk40, tmp_v0);
            }
        }
        sfxsource_clearFlag(ptr, SFX_SRC_FLAG_2_UNKOWN);
        sfxsource_clearFlag(ptr, SFX_SRC_FLAG_3_UNKOWN);
        sfxsource_clearFlag(ptr, SFX_SRC_FLAG_4_UNKOWN);
    }//L8030D2E0
    if(getGameMode() == GAME_MODE_4_PAUSED)
        sp24++;

    return sp24;
}

void func_8030D310(u8 indx){
    f32 pad0;
    s32 sp30;
    f32 pad1;
    SfxSource * ptr;
    f32 sp24;
    
    ptr = sfxsource_at(indx);
    
    if( func_8030C814(ptr, 1) 
        && ptr->unk40
        && func_8030C8F4(ptr->unk40)
    ){
        switch(ptr->unk43_1){
            case 0:
                break;
            case 1: //L8030D388[
                ptr->unk34 += ptr->unk1C*time_getDelta();
                if(0.0f < ptr->unk1C)
                    ptr->unk34 = ml_min_f(ptr->unk34, ptr->unk20);
                else
                    ptr->unk34 = ml_max_f(ptr->unk34, ptr->unk20);
                sfxsource_setFlag(ptr, SFX_SRC_FLAG_2_UNKOWN);
                break;
            case 2: //L8030D3E8
                sp24 = time_getDelta();
                ptr->unk34 +=  sfx_randf2(-ptr->unk24, ptr->unk24)*sp24;
                ptr->unk34 = ml_clamp_f(ptr->unk34, ptr->unk20, ptr->unk1C);
                sfxsource_setFlag(ptr, SFX_SRC_FLAG_2_UNKOWN);
                break;
        }
    }//L8030D434
    switch(func_8030C7E8(ptr)){
        case 1://L8030D468
            if( func_8030C814(ptr, 0) || (func_8030C814(ptr, 1) && !ptr->unk40))
                func_8030DA44(indx);
            break;
        case 2://L8030D4A4
            if(func_8030C814(ptr, 1) && sfxsource_isFlagCleared(ptr, 1))
                func_8030E394(indx);
            else
                sfxsource_clearFlag(ptr, SFX_SRC_FLAG_0_UNKOWN);
            break;
        case 3://L8030D4E0
            break;
    }//L8030D4E0
    sp30 = func_8030D10C(indx);
    if( func_8030C814(ptr, 1)
        && func_8030ED70(ptr->sfx_uid)
    ){
        if(sfxsource_isFlagSet(ptr, SFX_SRC_FLAG_5_UNKOWN)){
            if(sp30 == 0){
                osSetThreadPri(NULL, 0x33);
                func_8030CBD0(ptr);
                sfxsource_clearFlag(ptr, SFX_SRC_FLAG_5_UNKOWN);
                func_8030D10C(indx);
                osSetThreadPri(NULL, 0x14);
            }
        }
        else{//L8030D568
            if(sp30){
                func_8030CC90(ptr);
                func_8030C7F8(ptr, 1);
                sfxsource_setFlag(ptr, SFX_SRC_FLAG_5_UNKOWN);
            }
        }
    }//L8030D594
    if(ptr->unk40 && !func_8030C8F4(ptr->unk40)){
        func_8030C9F4(ptr->unk40);
        ptr->unk40 = 0;
    }
}

bool func_8030D5CC(u8 indx){
    SfxSource * sp1C = sfxsource_at(indx);
    if(!func_8030C814(sp1C, 3))
        return 0;

    if(!sp1C->unk40)
        return 1;

    if(func_8030C8F4(sp1C->unk40))
        return 0;
    return 1;
}

void func_8030D644(void){
    int i;
    for(i = 1; i < 35; i++){
        if(sfxsources[i].busy){
            func_8030D310(i);
            if(func_8030D5CC(i))
                sfxsource_free(i);
        }
    }
}

void func_8030D6C4(enum sfx_e uid, f32 arg1, s32 sampleRate, s32 arg3, s32 arg4){
    u8 indx = sfxsource_createSfxsourceAndReturnIndex();
    if(indx){
        sfxsource_setSfxId(indx, uid);
        sfxsource_setSampleRate(indx, sampleRate);
        sfxsource_playSfxAtVolume(indx, arg1);
        func_8030DCCC(indx, arg3);
        func_8030DD14(indx, 1);
        func_8030DD90(indx, arg4);
        func_8030E2C4(indx);
    }
}

void func_8030D750(void){
    func_8030CA08();
    sfxsource_initAll();
    
}

void func_8030D778(void){
    int i;
    int temp_s1;
    for(i = 1; i < 35; i++){
        if(sfxsources[i].busy)
            func_8030DA44(i);
    }
    do{
        temp_s1 = 0;
        func_8030D644();
        for(i = 1; i < 35; i++){
            if(sfxsources[i].busy)
                temp_s1++;
        }
    }while(temp_s1);
}

void func_8030D86C(void){
    func_8030D750();
    func_80244AB0();
    func_8030EDAC(0.0f, 1.0f);
}

void func_8030D8A8(s32 arg0, s32 arg){
    return;
}

void func_8030D8B4(void){
    func_8024FB8C();
    func_8024F83C();
}

void func_8030D8DC(void){
    func_80244B3C();
    func_8030D778();
    func_8030D8B4();
}

u8 sfxsource_createSfxsourceAndReturnIndex(void){
    u8 s1 = sfxsource_getNewIndex();
    SfxSource *s0;

    if(s1 == 0)
        return 0;

    s0 = sfxsource_at(s1);
    s0->unk30 = NULL;
    s0->sfx_uid = -1;
    s0->sample_rate = 22000;
    s0->unk2C = 0;
    s0->unk40 = 0;
    s0->unk43_1 = 0;
    s0->unk34 = 1.0f;
    func_8030C7F8(s0, 0);
    func_8030C7D0(s0, 0);
    sfxsource_setFlag(s0, SFX_SRC_FLAG_0_UNKOWN);
    sfxsource_setFlag(s0, SFX_SRC_FLAG_2_UNKOWN);
    sfxsource_setFlag(s0, SFX_SRC_FLAG_3_UNKOWN);
    sfxsource_setFlag(s0, SFX_SRC_FLAG_4_UNKOWN);
    s0->fade_inner_radius_sqr = 62500.0f;
    s0->fade_outer_radius_sqr = 1440000.0f;
    s0->unk14 = 0xa;
    s0->unk16 = 0;
    s0->unk18 = 64.0f;
    ml_vec3f_clear(s0->position);
    sfxsource_clearFlag(s0, SFX_SRC_FLAG_1_UNKOWN);
    sfxsource_clearFlag(s0, SFX_SRC_FLAG_5_UNKOWN);
    func_8030DD90(s1, 2);
    func_8030E0B4(s1, 0.2f, 0.1f);
    return s1;
}

void func_8030DA44(u8 indx){
    SfxSource * sp1C = sfxsource_at(indx);
    func_8030E394(indx);
    func_8030C7F8(sp1C, 3);
}

void sfxsource_setSfxId(u8 indx, enum sfx_e uid){
    if(indx)
        sfxsource_at(indx)->sfx_uid = uid;
}

void sfxsource_setSampleRate(u8 indx, s32 sample_rate){
    SfxSource *temp_v0;
    if(indx){
        temp_v0 = sfxsource_at(indx);
        temp_v0->sample_rate = sample_rate;
        sfxsource_setFlag(temp_v0, SFX_SRC_FLAG_3_UNKOWN);
    }
}

void func_8030DB04(u8 indx, s32 arg1, f32 arg2[3], f32 min_dist, f32 max_dist){
    f32 sp24[3];
    f32 dist;
    f32 temp_f2;
    __sfx_getPlayerPositionIfPresent(sp24);
    dist = ml_distance_vec3f(arg2, sp24);
    if(max_dist <= dist)
        temp_f2 = 0.0f;
    else{
        if(min_dist <= dist){
            temp_f2 = 1.0f - (dist - min_dist)/(max_dist - min_dist);
        }
        else{
            temp_f2 = 1.0f;
        }
    }
    sfxsource_setSampleRate(indx, (s32)arg1*temp_f2);
}

void sfxsource_playSfxAtVolume(u8 indx, f32 arg1){
    SfxSource *temp_v0;
    if(indx){
        temp_v0 = sfxsource_at(indx);
        temp_v0->unk34 = arg1;
       sfxsource_setFlag(temp_v0, SFX_SRC_FLAG_2_UNKOWN);
    }
}

void func_8030DBFC(u8 indx, f32 arg1, f32 arg2, f32 arg3){
    f32 temp_f2 = func_8030E200(indx);
    f32 temp_f0;
    if( temp_f2 < arg1){
        temp_f2 += arg3;
    }
    else if(arg2 < temp_f2){
        temp_f2 -= arg3;
    }
    else{
        temp_f2 += sfx_randf2(-arg3, arg3);
        if(temp_f2 < arg1)
            temp_f2 = arg1;
        else{
            temp_f0 = MIN(arg2 , temp_f2);
            temp_f2 = temp_f0;
        }
    }
    sfxsource_playSfxAtVolume(indx, temp_f2);

}

void func_8030DCCC(u8 indx, s32 arg1){
    SfxSource *temp_v0;
    if(indx){
        temp_v0 = sfxsource_at(indx);
        temp_v0->unk2C = arg1;
       sfxsource_setFlag(temp_v0, SFX_SRC_FLAG_4_UNKOWN);
    }
}

void func_8030DD14(u8 indx, int arg1){
    SfxSource *temp_v0;
    if(indx){
        temp_v0 = sfxsource_at(indx);
        func_8030C7D0(temp_v0, arg1);
    }
}

void func_8030DD54(u8 indx, void (*arg1)(u8)){
    SfxSource *temp_v0;
    if(indx){
        temp_v0 = sfxsource_at(indx);
        temp_v0->unk30 = arg1;
    }
}

void func_8030DD90(u8 indx, s32 arg1){
    SfxSource *temp_v0;
    if(indx){
        temp_v0 = sfxsource_at(indx);
        switch(arg1){
            case 0://L8030DDE4
                sfxsource_clearFlag(temp_v0, SFX_SRC_FLAG_6_UNKOWN);
                sfxsource_clearFlag(temp_v0, SFX_SRC_FLAG_7_UNKOWN);
                break;
            case 1: //L8030DE00
                sfxsource_setFlag(temp_v0, SFX_SRC_FLAG_6_UNKOWN);
                sfxsource_clearFlag(temp_v0, SFX_SRC_FLAG_7_UNKOWN);
                break;
            case 2: //L8030DE1C
                sfxsource_setFlag(temp_v0, SFX_SRC_FLAG_6_UNKOWN);
                sfxsource_setFlag(temp_v0, SFX_SRC_FLAG_7_UNKOWN);
                break;
        }
    }
}

void func_8030DE44(u8 indx, s32 arg1, f32 arg2){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        switch(arg1){
            case 0:
                break;
            case 1://L8030DE98
                ptr->unk38 = arg2;
                break;
            case 2:
                ptr->unk3C = arg2;
                break;
        }
    }
}

void sfxsource_set_fade_distances(u8 indx, f32 min, f32 max){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        ptr->fade_inner_radius_sqr = min*min;
        ptr->fade_outer_radius_sqr = max*max;
        func_8030DFF0(indx, 1);
    }
}

void func_8030DF18(u8 indx, f32 arg1){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        ptr->unk14 = (s16)arg1;
        func_8030DFF0(indx, 1);
    }
}

void sfxsource_set_position(u8 indx, f32 position[3]){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        ml_vec3f_copy(ptr->position, position);
        func_8030DFF0(indx, 1);
    }
}

void func_8030DFB4(u8 indx, s32 arg1){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        ptr->unk16 = arg1;
    }
}

void func_8030DFF0(u8 indx, s32 arg1){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        if(arg1){
            sfxsource_setFlag(ptr, SFX_SRC_FLAG_1_UNKOWN);
        }
        else{
            sfxsource_clearFlag(ptr, SFX_SRC_FLAG_1_UNKOWN);
        }
    }
}

void func_8030E04C(u8 indx, f32 arg1, f32 arg2, f32 arg3){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        ptr->unk43_1 = 1;
        ptr->unk1C = arg3;
        ptr->unk20 = arg2;
        sfxsource_playSfxAtVolume(indx, arg1);
    }
}

void func_8030E0B4(u8 indx, f32 arg1, f32 arg2){
    SfxSource *ptr;
    if(indx){
        ptr = sfxsource_at(indx);
        ptr->unk38 = arg1;
        ptr->unk3C = arg2;
    }
}

void func_8030E0FC(u8 indx, f32 arg1, f32 arg2, f32 arg3){
    SfxSource *ptr;

    if(indx){
        ptr = sfxsource_at(indx);
        ptr->unk43_1 = 2;
        ptr->unk24 = arg3;
        ptr->unk20 = arg1;
        ptr->unk1C = arg2;
        sfxsource_playSfxAtVolume(indx, (arg1 + arg2)/2);
    }
}

enum sfx_e sfxsource_getSfxId(u8 indx){
    SfxSource *ptr;

    if(!indx)
        return 0;
    else{
        ptr = sfxsource_at(indx);
        return ptr->sfx_uid;
    }
}

s32 func_8030E1C4(u8 indx){
    SfxSource *ptr;

    if(indx == 0)
        return 0;
    else{
        ptr = sfxsource_at(indx);
        return ptr->sample_rate;
    }
}

f32 func_8030E200(u8 indx){
    SfxSource *ptr;

    if(!indx)
        return 1.0f;
    else{
        ptr = sfxsource_at(indx);
        return ptr->unk34;
    }
}

s32 func_8030E244(u8 indx){
    SfxSource *ptr;

    if(!indx)
        return 0;
    else{
        ptr = sfxsource_at(indx);
        return ptr->unk2C;
    }
}

bool func_8030E280(SfxSource *arg0){
    int temp_v1;
    if(sfxsource_isFlagSet(arg0, SFX_SRC_FLAG_1_UNKOWN)){
        temp_v1 = func_8030CCF0(arg0, arg0->sample_rate);
    }
    else{
        temp_v1 = arg0->sample_rate;
    }
    return (temp_v1 > 100);
}

void func_8030E2C4(u8 indx){
    SfxSource *ptr;

    if(!indx)
        return;

    ptr = sfxsource_at(indx);
    if(func_8030E280(ptr) || func_8030ED70(ptr->sfx_uid)){
        switch(func_8030C7E8(ptr)){
            case 2:
                sfxsource_setFlag(ptr, SFX_SRC_FLAG_0_UNKOWN);
                if(func_8030C814(ptr, 1)){
                    return;
                }
                break;

            default:
                if(func_8030C814(ptr, 1)){
                    func_8030E394(indx);
                }
                break;
        }
        osSetThreadPri(NULL, 0x33);
        func_8030CBD0(ptr);
        func_8030D10C(indx);
        osSetThreadPri(NULL, 0x14);
    }
}

void func_8030E394(u8 indx){
    SfxSource *ptr;

    if(indx){
        ptr = sfxsource_at(indx);
        if(func_8030C814(ptr, 1)){
            func_8030CC90(ptr);
            if(ptr->unk30)
                ptr->unk30(indx);
        }
    }
}


int func_8030E3FC(u8 indx){
    SfxSource *ptr;

    if(!indx)
        return 0;
    else {
        ptr = sfxsource_at(indx);
        return indx
            && func_8030C814(ptr, 1)
            && ptr->unk40 
            && func_8030C8F4(ptr->unk40);
    }
}

void sfxsource_playHighPriority(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 22000, 0, 2);
}

void func_8030E4B4(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 22000, 0, 1);
}

void func_8030E4E4(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 22000, 0, 0);
}

void sfxsource_play(enum sfx_e uid, s32 sampleRate){
    func_8030D6C4(uid, 1.0f, sampleRate, 0, 2);
}

void func_8030E540(enum sfx_e uid){
    sfxsource_play(uid, 0x7ff8);
}

void func_8030E560(enum sfx_e uid, s32 arg1){
    func_8030D6C4(uid, 1.0f, arg1, 0, 0);
}

void func_8030E58C(enum sfx_e uid, f32 arg1){
    func_8030D6C4(uid, arg1, 22000, 0, 2);
}

void func_8030E5C0(enum sfx_e uid, f32 arg1){
    func_8030D6C4(uid, arg1, 22000, 0, 1);
}

void func_8030E5F4(enum sfx_e uid, f32 arg1){
    func_8030D6C4(uid, arg1, 22000, 0, 0);
}

void func_8030E624(u32 arg0){
    f32 f6 = (arg0 >> 0x15) & 0x7ff;
    func_8030D6C4(arg0 & 0x7FF, f6/1023.0, (arg0 >> 6) & 0x7fe0, 0, 2);
}

void func_8030E6A4(enum sfx_e uid, f32 arg1, s32 arg2){
    func_8030D6C4(uid, arg1, arg2, 0, 2);
}

void func_8030E6D4(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 0x7ff8, 0, 2);
}

void func_8030E704(enum sfx_e uid){
    func_8030D6C4(uid, 1.0f, 0x7ff8, 0, 0);
}

void func_8030E730(enum sfx_e uid, f32 arg1, s32 arg2){
    func_8030D6C4(uid, arg1, arg2, 0, 1);
}

void func_8030E760(enum sfx_e uid, f32 arg1, s32 arg2){
    func_8030D6C4(uid, arg1, arg2, 0, 0);
}

void sfx_play(enum sfx_e uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance, s32 arg6){
    u8 sfxsource;
    f32 player_position[3];
    
    __sfx_getPlayerPositionIfPresent(player_position);
    if( !(maxFadeDistance <= ml_distance_vec3f(player_position, position))
        && levelSpecificFlags_validateCRC2()
        && dummy_func_80320240()
    ){
        sfxsource = sfxsource_createSfxsourceAndReturnIndex();
        if(sfxsource){
            func_8030DD90(sfxsource, arg6); // priority ?
            sfxsource_setSfxId(sfxsource, uid);
            sfxsource_setSampleRate(sfxsource, sampleRate);
            sfxsource_playSfxAtVolume(sfxsource, volume);
            sfxsource_set_fade_distances(sfxsource, minFadeDistance, maxFadeDistance);
            sfxsource_set_position(sfxsource, position);
            func_8030DD14(sfxsource, 1);
            func_8030E2C4(sfxsource);
        }
    }
}

void func_8030E878(enum sfx_e id, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    sfx_play(id, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 2);
}

// fadeDistance is a 32-bit value where the lower 16 bits represent minFadeDistance and the upper 16 bits represent maxFadeDistance.
void func_8030E8B4(u32 arg0, f32 position[3], u32 fadeDistance){
    sfx_play(
        (arg0 & 0x7ff), (f32)((arg0 >> 0x15) & 0x7ff)/1023.0, ((arg0 >> 0x6) & 0x7fe0),
        position, (f32)(fadeDistance & 0xffff), (f32)((fadeDistance >> 0x10) & 0xffff),
        2
    );
}

void func_8030E988(enum sfx_e uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    sfx_play(uid, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 1);
}

void func_8030E9C4(enum sfx_e uid, f32 volume, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    sfx_play(uid, volume, sampleRate, position, minFadeDistance, maxFadeDistance, 0);
}

void func_8030E9FC(enum sfx_e uid, f32 arg1, f32 arg2, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    sfx_play(uid, sfx_randf2(arg1, arg2), sampleRate, position, minFadeDistance, maxFadeDistance, 2);
}

void func_8030EA54(enum sfx_e uid, f32 arg1, f32 arg2, u32 sampleRate, f32 position[3], f32 minFadeDistance, f32 maxFadeDistance){
    sfx_play(uid, sfx_randf2(arg1, arg2), sampleRate, position, minFadeDistance, maxFadeDistance, 1);
}

void func_8030EAAC(enum sfx_e uid, f32 arg1, s32 arg2, s32 arg3){
    func_8030D6C4(uid, arg1, arg2, arg3, 2);
}

void func_8030EAD8(enum sfx_e uid, f32 arg1, s32 arg2, s32 arg3){
    func_8030D6C4(uid, arg1, arg2, arg3, 0);
}

void func_8030EB00(enum sfx_e uid, f32 arg1, f32 arg2){
    func_8030D6C4(uid, sfx_randf2(arg1, arg2), 22000, 0, 2);
}

void func_8030EB44(enum sfx_e uid, f32 arg1, f32 arg2){
    func_8030D6C4(uid, sfx_randf2(arg1, arg2), 22000, 0, 1);
}

void func_8030EB88(enum sfx_e uid, f32 arg1, f32 arg2){
    func_8030D6C4(uid, sfx_randf2(arg1, arg2), 22000, 0, 0);
}

void func_8030EBC8(enum sfx_e uid, f32 arg1, f32 arg2, s32 arg3, s32 arg4){
    func_8030D6C4(uid, sfx_randf2(arg1, arg2), sfx_randi2(arg3, arg4), 0, 2);
}

void func_8030EC20(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, u32 arg4){
    func_8030D6C4(uid, sfx_randf2(arg1, arg2), sfx_randi2(arg3, arg4), 0, 0);
}

void func_8030EC74(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, u32 arg4, f32 arg5[3]){
    u8 indx = sfxsource_createSfxsourceAndReturnIndex();
    if(indx){
        sfxsource_setSfxId(indx, uid);
        sfxsource_setSampleRate(indx, sfx_randi2(arg3, arg4));
        sfxsource_playSfxAtVolume(indx, sfx_randf2(arg1, arg2));
        sfxsource_set_position(indx, arg5);
        func_8030DD14(indx, 1);
        func_8030E2C4(indx);
    }
}

void func_8030ED0C(void){
    func_8030D644();
}

u8 func_8030ED2C(enum sfx_e uid, s32 arg1){
    u8 indx = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(indx, uid);
    func_8030DD14(indx, arg1);
    return indx;
}

int func_8030ED70(enum sfx_e uid){
    if(!(uid < 0x3e9)){
        return func_80335520(uid - 0x3e9);
    }
    else{
        return func_803354EC(uid);
    }
}

void func_8030EDAC(f32 arg0, f32 arg1){
    D_80382E0C = arg0;
    D_80382E10 = arg1;
}

