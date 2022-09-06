#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80309DBC(f32[3], f32[3], f32, f32 sp54[3], s32, s32);
extern bool func_80320C94(f32[3], f32[3], f32, f32 sp54[3], s32, s32);
extern f32 func_8033229C(ActorMarker *);
extern bool func_80309D58(f32[3], s32);

extern void ml_vec3f_normalize(f32 [3]);

typedef struct {
    s16 unk0;
    // u8 pad2[0x2];
    s32 actor_id;
    s32 count;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    // u8 pad12[0x2];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} struct41FB0s;

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8[3];
    f32 unk14[3];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
} struct41FB0s_1;

/* .data */
enum core2_41FB0_e{
    CORE2_41FB0_0_MM_HUT_NOTES,
    CORE2_41FB0_1_MM_HUT_EGGS,
    CORE2_41FB0_2_MM_HUT_GRUBLIN,
    CORE2_41FB0_3_MM_HUT_JINJO,
    CORE2_41FB0_4_MM_HUT_JIGGY,

    CORE2_41FB0_6_MM_HUT_EXTRA_LIFE = 0x6,


    CORE2_41FB0_A_BGS_HUT_JUMP_PAD = 0xA,
    CORE2_41FB0_B_BGS_HUT_NOTES,
    CORE2_41FB0_C_BGS_HUT_JIGGY,

    CORE2_41FB0_E_YUMYUM_EGG = 0xe,
    CORE2_41FB0_F_YUMYUM_RED_FEATHER,

};

// #define 41FB0_FLAG_SET_YAW 0x0020
struct41FB0s D_80366460[] = {
    /*MM HUT 1*/        {0x0021, ACTOR_51_MUSIC_NOTE,       5, SFX_3E9_UNKNOWN,         1, 16000, 125.0f,  25.0f,  725.0f, 125.0f, 125.0f,  25.0f, 0.6f,   0.0f},
    /*MM HUT 2*/        {0x0021, ACTOR_52_BLUE_EGG,         5, SFX_21_EGG_BOUNCE_1,     1, 16000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    /*MM HUT 3*/        {0x0021, ACTOR_6_GRUBLIN,           1, SFX_8_BANJO_LANDING_04,  1, 20000,   0.0f,   0.0f,  550.0f, 250.0f, 200.0f,   0.0f, 0.6f,   0.0f},
    /*MM HUT 4*/        {0x0021, ACTOR_62_JINJO_GREEN,      1, SFX_8_BANJO_LANDING_04,  1, 20000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    /*MM HUT 6*/        {0x0021, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_50_HONEYCOMB,        3, SFX_3E9_UNKNOWN,         1, 16000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    /*MM HUT 5*/        {0x0021, ACTOR_49_EXTRA_LIFE,       1, SFX_3E9_UNKNOWN,         1, 16000, 100.0f,  50.0f,  500.0f, 250.0f, 100.0f,  50.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f, 1000.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0005, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,  90.0f,   0.0f,  930.0f,   0.0f, 100.0f,   0.0f, 0.6f,   0.0f},
    {0x0049, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f, 1000.0f,   0.0f, 300.0f,   0.0f, 0.5f,   0.0f},
    /*BGS HUT 1,2,4,5 */{0x002D, ACTOR_B_SHOCKSPRING_PAD,   1, 0,                       1, 16000,   0.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.2f, 315.0f},
    /*BGS HUT 3 */      {0x0005, ACTOR_51_MUSIC_NOTE,       5, SFX_3E9_UNKNOWN,         1, 16000,  75.0f,   0.0f,  725.0f,   0.0f,  75.0f,   0.0f, 0.6f,   0.0f},
    /*BGS HUT 4 */      {0x0005, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f, 1000.0f,   0.0f,   0.0f,   0.0f, 0.5f,   0.0f},
    {0x0009, ACTOR_47_EMPTY_HONEYCOMB,  1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f,  200.0f,   0.0f, 300.0f,   0.0f, 0.6f,   0.0f},
    /*YUM YUM EGG*/     {0x0001, ACTOR_52_BLUE_EGG,         1, SFX_21_EGG_BOUNCE_1,     1, 16000,   0.0f, 350.0f,  500.0f, 500.0f,   0.0f, 350.0f, 0.6f,   0.0f},
    /*YUM YUM FEATHER*/ {0x0001, ACTOR_129_RED_FEATHER,     1, SFX_21_EGG_BOUNCE_1,     1, 16000,   0.0f, 350.0f,  500.0f, 500.0f,   0.0f, 350.0f, 0.6f,   0.0f},
    {0x0005, ACTOR_46_JIGGY,            1, 0,                       0,     0,   0.0f,   0.0f,  100.0f,   0.0f,   0.0f,   0.0f, 0.75f,  0.0f},
    {0x0005, 0x06A,                     1, 0,                       0,     0,   0.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0009, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,   0.0f,   0.0f,  650.0f,   0.0f, 950.0f,   0.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_51_MUSIC_NOTE,       1, SFX_21_EGG_BOUNCE_1,     1, 16000, 125.0f,  25.0f,  725.0f, 125.0f, 125.0f,  25.0f, 0.6f,   0.0f},
    {0x0001, ACTOR_50_HONEYCOMB,        1, SFX_3E9_UNKNOWN,         1, 18000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x0065, ACTOR_46_JIGGY,            1, SFX_3E9_UNKNOWN,         1, 16000,  90.0f,   0.0f,  930.0f,   0.0f, 100.0f,   0.0f, 0.7f,   0.0f},
    {0x0021, ACTOR_50_HONEYCOMB,        1, SFX_3E9_UNKNOWN,         1, 18000,   0.0f,   0.0f,  750.0f, 250.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_50_HONEYCOMB,        2, SFX_3E9_UNKNOWN,         1, 18000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_50_HONEYCOMB,        3, SFX_3E9_UNKNOWN,         1, 18000,  50.0f, 150.0f,  500.0f, 250.0f,  50.0f, 150.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 250.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 350.0f,   0.0f,  350.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 450.0f,   0.0f,  400.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 550.0f,   0.0f,  450.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x00A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 650.0f,   0.0f,  500.0f,   0.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0021, ACTOR_46_JIGGY,            1, 0,                       0,     0,   0.0f,   0.0f,    0.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    /* SM QUARRIES & VEGGIES*/ {0x0025, ACTOR_47_EMPTY_HONEYCOMB,  1, SFX_3E9_UNKNOWN,         1, 18000,   0.0f,   0.0f,  750.0f, 500.0f,   0.0f,   0.0f, 0.6f,   0.0f},
    {0x0129, 0x352,                     1, SFX_3F2_UNKNOWN,         1, 16000,   0.0f,   0.0f, 2500.0f,   0.0f,   0.0f,   0.0f, 0.4f,   0.0f},
    {0x0081, ACTOR_3A0_ICECUBE_B,       1, SFX_116_DEAF_RUSTLING,   1, 32000, 220.0f, 100.0f,  350.0f, 200.0f, 220.0f, 100.0f, 0.6f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 250.0f,   0.0f,  200.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 350.0f,   0.0f,  350.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 450.0f,   0.0f,  400.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 550.0f,   0.0f,  450.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f},
    {0x02A1, ACTOR_50_HONEYCOMB,        1, SFX_8_BANJO_LANDING_04,  1, 20000, 650.0f,   0.0f,  500.0f,   0.0f,   0.0f,   0.0f, 0.0f,   0.0f}
};

/* .bss */
s32 D_8037DDB0;
f32 D_8037DDB4;
f32 D_8037DDB8;

/* .public */
Actor *func_802C937C(s32 arg0, f32 position[3]);

/* .code */
void func_802C8F40(void){
    D_8037DDB0 = 0;
    D_8037DDB4 = 0.0f;
    D_8037DDB8 = 1.0f;
}

void func_802C8F68(void){}

void func_802C8F70(f32 arg0){
    D_8037DDB4 = arg0;
}

void func_802C8F7C(f32 arg0){
    D_8037DDB8 = arg0;
}

Actor *func_802C8F88(s32 arg0, s32 arg1[3]){
    f32 sp1C[3];

    sp1C[0] = arg1[0];
    sp1C[1] = arg1[1];
    sp1C[2] = arg1[2];
    return func_802C937C(arg0, sp1C);
}

Actor *func_802C8FE4(s32 arg0, f32 position[3], Actor *arg2){
    static f32 D_80366C4C = 400.0f;
    struct41FB0s * sp74; //s2
    Actor *actor; //s3
    s32 i;
    struct41FB0s_1 *s0;

    sp74 = D_80366460 + arg0;
    actor = NULL;
    for(i = 0; i < sp74->count; i++){//L802C90B0
        D_8037DDB4 += 360.0/sp74->count;
        while(360.0 <= D_8037DDB4){ D_8037DDB4 -= 360.0;}
        //L802C9114
        actor =(i == 0 && arg2) ? arg2 : func_8032813C(sp74->actor_id, position, 0);
        actor->unk10_0 = 1;
        s0 = (struct41FB0s_1 *) &actor->unkBC;
        s0->unk0 = arg0; 
        s0->unk2F = 1;
        s0->unk6 = 1;
        ml_vec3f_copy(s0->unk8, actor->position);
        ml_vec3f_copy(actor->position, s0->unk8);
        if(D_8037DDB8 != 1.0f){
            s0->unk14[0] = sp74->unk14*D_8037DDB8;
            s0->unk14[1] = sp74->unk1C + randf2(0.0f, sp74->unk20);
            s0->unk14[2] = sp74->unk24*D_8037DDB8;
            D_8037DDB8 = 1.0f;
        }
        else{//L802C91CC
            s0->unk14[0] = sp74->unk14 + randf2(0.0f, sp74->unk18);
            s0->unk14[1] = sp74->unk1C + randf2(0.0f, sp74->unk20);
            s0->unk14[2] = sp74->unk24 + randf2(0.0f, sp74->unk28);

        }//L802C9210
        ml_vec3f_yaw_rotate_copy(s0->unk14, s0->unk14, D_8037DDB4);
        s0->unk24 = D_80366C4C *= -1;
        actor->yaw = s0->unk20 = (sp74->unk0 & 0x20) ? sp74->unk30 : randf2(0.0f, 360.0f);
        s0->unk28 = 0.0f;
        s0->unk2C = 0;
        s0->unk2D = 1;
        s0->unk4 = sp74->unk0;
        s0->unk2E = (sp74->unk0 & 0x1) ? (0.5 < randf()) : 0 ;
        if(sp74->unk0 & 0x200){
            actor->unk5C = s0->unk8[1];
        }
    }//L802C92E8
    return actor;
}

Actor *func_802C9334(s32 arg0, Actor * arg1){
    D_80366460[arg0].unk30 = arg1->yaw;
    return func_802C8FE4(arg0, arg1->position, arg1);
}

Actor *func_802C937C(s32 arg0, f32 position[3]){
    return func_802C8FE4(arg0, position, 0);
}

bool func_802C939C(Actor *actor, f32 arg1[3], f32 arg2[3], f32 arg3[3], bool arg4) {
    struct41FB0s_1 *sp64 = (struct41FB0s_1 *)&actor->unkBC;
    f32 sp60;
    bool var_v1;
    f32 sp50[3];
    f32 sp44[3];
    s32 sp40;
    s32 sp3C;


    if (sp64->unk4 & 0x80) {
        if (actor->unk10_25 != 0) {
            if (func_80307258(arg2, actor->unk10_25 - 1, actor->unk10_18 - 1) == -1) {
                ml_vec3f_diff_copy(arg3, arg2, arg1);
                ml_vec3f_normalize(arg3);
                ml_vec3f_copy(arg2, arg1);
                return TRUE;
            }
        }
        else {
            if ((actor->unk10_18 != 0)){
                if(func_80309D58(arg2, actor->unk10_18) == 0) {
                    ml_vec3f_diff_copy(arg3, arg2, arg1);
                    ml_vec3f_normalize(arg3);
                    ml_vec3f_copy(arg2, arg1);
                    return TRUE;
                }
            }
        }
    }

    sp60 =  func_8033229C(actor->marker) * 0.66666666;
    ml_vec3f_copy(sp50, arg2);
    arg1[1] += sp60;
    arg2[1] += sp60;
    if (arg4) {
        var_v1 = func_80309DBC(arg1, arg2, sp60, arg3, 3, actor->unk154);
        if (!var_v1) {
            var_v1 = func_80309B48(arg1, arg2, arg3, actor->unk154);
            if (var_v1) {
                arg2[0] += arg3[0];
                arg2[1] += arg3[1];
                arg2[2] += arg3[2];
            }
        }
    } else {
        var_v1 = func_80320C94(arg1, arg2, sp60, arg3, 3, actor->unk154);
        if (!var_v1) {
            var_v1 = func_80320B98(arg1, arg2, arg3, actor->unk154);
            if (var_v1) {
                arg2[0] += arg3[0];
                arg2[1] += arg3[1];
                arg2[2] += arg3[2];
            }
        }
    }
    if (var_v1 && sp64->unk2D && (actor->marker->modelId == ASSET_363_MODEL_HONEYCOMB)) {
        ml_vec3f_scale_copy(sp44, arg3, sp60 / (f32) (1 << sp64->unk6));
        var_v1 = TRUE;
        arg2[0] += sp44[0];
        arg2[1] += sp44[1];
        arg2[2] += sp44[2];
        if (actor->marker->modelId != ASSET_363_MODEL_HONEYCOMB) {
            sp64->unk6++;
        }
        if (sp64->unk6 == 5) {
            sp64->unk2D = FALSE;
        } else {
            var_v1 = FALSE;
        }
    } else {
        sp64->unk2D = FALSE;
    }
    arg1[1] -= sp60;
    arg2[1] -= sp60;
    return var_v1;
}

void func_802C96E4(Actor *actor) {
    f32 sp6C;
    struct41FB0s_1 *sp68;
    struct41FB0s *sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    s32 pad;
    s32 pad2;
    f32 var_f0;

    sp6C = time_getDelta();
    sp68 = (struct41FB0s_1 *)&actor->unkBC;
    sp64 = &D_80366460[sp68->unk0];
    if (D_8037DDB0 > 0) D_8037DDB0--;
    
    switch (sp68->unk2F) {
        case 3:
            break;
        case 1:
            sp68->unk28 += sp6C;
            ml_vec3f_copy(sp58, sp68->unk8);
            ml_vec3f_scale_copy(sp4C, sp68->unk14, sp6C);
            sp68->unk8[0] += sp4C[0];
            sp68->unk8[1] += sp4C[1];
            sp68->unk8[2] += sp4C[2];
            if (1.2 < sp68->unk28) {
                sp68->unk2C = 1;
            }
            if (!((sp64->unk0 & 0x40) && (sp68->unk28 < 1.2)) 
                && ( (func_802C939C(actor, sp58, sp68->unk8, sp40, sp64->unk0 & 8)) 
                      || ((sp64->unk0 & 0x200) && (sp68->unk14[1] < -((sp64->unk20 / 2) + sp64->unk1C)))
                )
            ) {
                if (sp64->unk0 & 0x204) {
                    sp40[0] = 0.0f;
                    sp40[1] = 1.0f;
                    sp40[2] = 0.0f;
                }
                ml_vec3f_scale(sp68->unk14, -1.0f);
                var_f0 = ((sp68->unk14[0] * sp40[0]) + (sp68->unk14[1] * sp40[1]) + (sp68->unk14[2] * sp40[2]));
                ml_vec3f_scale(sp40, 2*var_f0);
                ml_vec3f_diff_copy(sp68->unk14, sp40, sp68->unk14);
                if (D_8037DDB0 == 0) {
                    if (sp64->unkC != 0) {
                        func_8030E878(sp64->unkC, (f32)sp64->unkE, sp64->unk10, sp68->unk8, 300.0f, 3000.0f);
                    }
                    D_8037DDB0 = sp64->count * 8;
                }
                ml_vec3f_scale(sp68->unk14, sp64->unk2C);
                var_f0 = gu_sqrtf((sp68->unk14[0]*sp68->unk14[0]) + (sp68->unk14[1]*sp68->unk14[1]) + (sp68->unk14[2]*sp68->unk14[2]));
                if (((var_f0 < 200.0f) && (sp40[1] > 0.75)) || (var_f0 < 10.0f)) {
                    sp68->unk2F = 2;
                    sp68->unk2C = 1;
                    if (sp64->unk0 & 0x10) {
                        actor->marker->propPtr->unk8_3 = TRUE;
                    }
                }
                else{

                }
                if (sp64->unk0 & 0x200) {
                    sp68->unk8[1] = actor->unk5C;
                }
            } else {
                if (sp64->unk0 & 0x100) {
                    sp68->unk14[1] -= 4000.0 * sp6C;
                } else {
                    sp68->unk14[1] -= 1500.0 * sp6C;
                }
            }
            ml_vec3f_copy(actor->position, sp68->unk8);
            break;

        case 2:
            if (sp64->unk0 & 2) {
                sp68->unk20 += (sp68->unk24 * sp6C);
                while (sp68->unk20 >= 360.0f) { sp68->unk20 -= 360.0f; }
                while (sp68->unk20 < 0.0f) { sp68->unk20 += 360.0f; }
                actor->yaw = sp68->unk20;
            }
            var_f0 = (sp68->unk24 >= 0.0f) ? sp68->unk24 : -sp68->unk24;
            if (var_f0 < 0.1) {
                sp68->unk2F = 3U;
            }
            break;
    }
    if (actor->position[1] < -5000.0f) {
        marker_despawn(actor->marker);
    }
}

f32 *func_802C9C0C(Actor *actor){
    struct41FB0s_1 *ptr = (struct41FB0s_1 *)&actor->unkBC;
    return ptr->unk14;
}

bool func_802C9C14(Actor *actor){
    struct41FB0s_1 *ptr = (struct41FB0s_1 *)&actor->unkBC;
    return ptr->unk2C < 1U;
}
