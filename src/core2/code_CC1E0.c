#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"

extern void func_80244D94(f32[3], f32[3], f32[3], u32, f32);

extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);

extern f32 func_8033EA14(s32);
extern void func_8033EA40(s32, f32);
extern void projectile_setSprite(u8, enum asset_e);
extern void func_8033FCD8(u8, s32);
extern void projectile_setPosition(u8, f32[3]);
extern void projectile_getPosition(u8, f32[3]);
extern void func_8033FFE4(u8, s32, s32);
extern void func_80344E18(u8, s32);
extern void func_80344E3C(u8, f32[3]);
extern void func_80344EE4(u8, f32, f32);
extern void func_80354030(f32[3], f32);
extern bool func_80344EC0(u8);
extern ActorMarker *func_8033E840(void);
extern ActorProp *func_80320EB0(ActorMarker *, f32, s32);


void fxegg_collide(s32 arg0, ActorMarker *arg1, s32 arg2);

/* .data */
struct53s D_803726A0[] = {
    {9, 1}, 
    {8, 1}, 
    {7, 1}, 
    {6, 1}, 
    {5, 1}, 
    {4, 1}, 
    {3, 1}, 
    {2, 1}, 
    {1, 1}, 
    {0, 1}
};

/* .code */
void fxegg_shatter(u8 projectile_indx){
    f32 position[3];
    projectile_getPosition(projectile_indx, position);
    func_8030EBC8(SFX_D_EGGSHELL_BREAKING, 1.6f, 1.7f, 13000, 13000);
    eggShatter_new(position);
}

s32 func_803531C8(u8 projectile_indx, s32 arg1){
    ActorProp *prop;
    f32 sp40[3];
    ActorMarker * marker;
    ActorMarker * other_marker;
    s32 sp34;
    f32 temp_f2;
    Actor *other_actor;
    s32 pad;
    s32 sp20;

    
    marker = func_8033E840();
    sp34 = 0;
    projectile_getPosition(projectile_indx, sp40);
    marker->unk38[1] = 0x1E;
    prop = func_80320EB0(marker, 30.0f, 1);
    if(prop != NULL && prop->unk8_0){
        other_marker = prop->marker;
        sp34 =other_marker->unk14_20;
        if(!func_8033D410(marker, other_marker)){
            switch(sp34){
                case MARKER_FC_CROCTUS: //L803532C4
                    other_actor = marker_getActor(other_marker);
                    if(other_actor->unk38_31 == 0){
                        temp_f2 = animctrl_getAnimTimer(other_actor->animctrl);
                        if(0.25 <= temp_f2 && temp_f2 <= 0.75){
                            other_actor->unk38_31 = 1;
                        }
                        func_8033E984();
                        fxegg_shatter(projectile_indx);
                    }
                    break;

                case MARKER_33_LEAKY: //L80353350
                    if(func_802458A8(sp40, other_marker, 0x32) && chLeaky_eggCollision(other_marker)){
                        func_8033E984();
                    }
                    break;

                case MARKER_4C_CLANKER_TOKEN_TOOTH_EXT: //L80353384
                    func_8033E984();
                    func_803870EC(1);
                    break;

                case 0x1ae: //L8035339C //zubba?
                    func_8033E984();
                    fxegg_shatter(projectile_indx);
                    break;

                case MARKER_4D_CLANKER_JIGGY_TOOTH_EXT: //L803533B4
                    func_8033E984();
                    func_803870EC(2);
                    break;

                case MARKER_182_RBB_EGG_TOLL: //L803533CC
                    func_8033E984();
                    func_8038685C(other_marker);
                    break;

                case 0xbb: //L803533E4 //"BIG_JINXYHEAD"
                    other_actor = marker_getActor(other_marker);
                    *(s32 *)&other_actor->local = 1;
                    func_8033E984();
                    break;

                case MARKER_34_CEMETARY_POT: //L80353400
                    if(func_802458A8(sp40, other_marker, 0x3C) && MMM_func_80387340(other_marker)){
                        func_8033E984();
                    }
                    break;

                case MARKER_AB_RUBEES_EGG_POT: //L80353434
                    if(func_802458A8(sp40, other_marker, 0x1E) && (func_8038E178() < func_8038E184())){
                        func_8033E984();
                        func_8038E140();
                    }
                    break;

                case 0xae: //L80353480 //big_jynxy_head
                    if(func_8038E344(other_marker)){
                        func_8033E984();
                        func_8038E2FC(other_marker);
                    }
                    break;
            }
            func_8032B258(marker_getActor(other_marker), COLLISION_0_TOUCH);
        }
    }
    return sp34;
}

bool fxegg_isCollidingWithPlayer(f32 arg0[3]){
    f32 sp2C[3];
    f32 sp20[3];

    player_getPosition(sp2C);
    ml_vec3f_diff_copy(sp20, sp2C, arg0);
    return (sp2C[1] < arg0[1]) && (arg0[1] < sp2C[1] + 100.0f)
        && (sp20[0]*sp20[0] + sp20[2]*sp20[2] < 4900.0f);
}

void func_80353580(ActorMarker *marker){
    func_8033E9A8(marker->unk28);
}

void fxegg_head_spawn(void){
    u8 projectile_indx = func_8033E8D0();
    struct54s *sp78 = func_8033E8F4();
    u8 sp77 = func_8033E93C();
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 other_marker[3];
    ActorMarker *marker = func_8033E840();
    f32 tmp_f8 = 20.0f;

    marker->unk2C_1 = 1;
    marker->collidable = 1;
    func_803300B8(marker, fxegg_collide);
    func_8033EA40(0, 20.0f);
    func_8033EA40(1, 0.0f);
    func_8033EA40(2, 0.0f);
    _player_getPosition(sp50);
    sp50[1] += 80.0f;
    ml_vec3f_copy(sp68, sp50);
    player_getRotation(sp44);
    func_80256E24(sp5C, 0.0f, sp44[1], 0.0f, 0.0f, 70.0f);
    sp50[0] += sp5C[0];
    sp50[1] += sp5C[1];
    sp50[2] += sp5C[2];
    func_80244D94(sp68, sp50, other_marker, 0x25e0080, 15.0f);

    projectile_setSprite(projectile_indx, ASSET_708_SPRITE_EGG_PROJECTILE);
    func_8033FFE4(projectile_indx, (s32)tmp_f8, (s32)tmp_f8);
    projectile_setPosition(projectile_indx, sp50);
    func_8033FCD8(projectile_indx, 0xe);

    func_80287E9C(sp78);
    func_80287F50(sp78, D_803726A0, 0x14);
    func_80287F10(sp78);

    func_80344E18(sp77, 1);
    func_80344EE4(sp77, 0.0f, 0.0f);
    func_80344D94(sp77, sp50);
    sp44[1] += 4.0;
    func_80256E24(sp5C, 0.0f, sp44[1], 0.0f, 0.0f, 800.0f);
    sp5C[1] = 0.0f;
    func_80344E3C(sp77, sp5C);
}

void fxegg_head_update(void){
    u8 projectile_indx;
    u8 sp96;
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp78;
    f32 tmp_f24;
    ActorMarker *s0;
    f32 sp6C;
    f32 sp60[3];
    f32 sp54[3];
    f32 tmp_f20;
    
    projectile_indx = func_8033E8D0();
    sp96 = func_8033E93C();
    sp78 = func_8033EA14(1);
    tmp_f24 = func_8033EA14(2);
    tmp_f24 -= time_getDelta();
    sp6C = ml_map_f(sp78, 0.0f, 2.0f, 0.0333f, 0.1f);
    while(tmp_f24 <= 0.0f){//L80353868
        tmp_f24 += sp6C;
        projectile_getPosition(projectile_indx, sp7C);
        func_8033E9D4();
        sp7C[0] += randf2(-8.0f, 8.0f);
        sp7C[1] += randf2(-8.0f, 8.0f);
        sp7C[2] += randf2(-8.0f, 8.0f);
        if(randf() < 0.5){
            func_803541C0(1);
        }
        else{
            func_803541C0(6);
        }
        func_803541CC(0x32);
        func_80354030(sp7C, 0.15f);
        func_8033E9F4();
    }//L80353930
    func_8033EA40(2, tmp_f24);
    func_803531C8(projectile_indx, 0);
    func_80344E7C(sp96, sp88);
    if(ml_isZero_vec3f(sp88)){
        s0 = func_8033E840();
        projectile_getPosition(projectile_indx, sp60);
        sp54[0] = (f32)s0->propPtr->x;
        sp54[1] = (f32)s0->propPtr->y;
        sp54[2] = (f32)s0->propPtr->z;
        func_8033E984();
        fxegg_shatter(projectile_indx);
    }//L803539D4
    func_80344E3C(sp96, sp88);
    tmp_f20 = func_8033EA14(0);
    func_8033FFE4(projectile_indx, (s32) tmp_f20, (s32) tmp_f20);
    func_8033EA40(0, ml_min_f(tmp_f20 + 4.0f, 50.0f));
    sp78 += time_getDelta();
    func_8033EA40(1, sp78);
    if(2.0 < sp78){
        func_8033E984();
    }
}

void fxegg_head_destroy(void){}

void fxegg_ass_spawn(void) {
    u8 projectile_indx;
    struct54s *sp58;
    u8 sp57;
    f32 sp48[3];
    f32 marker[3];
    f32 sp30[3];
    f32 temp_f2;
    f32 temp_f18;

    projectile_indx = func_8033E8D0();
    sp58 = func_8033E8F4();
    sp57 = func_8033E93C();
    func_8033E840()->unk2C_1 = TRUE;
    func_8033E840()->collidable = TRUE;
    func_803300B8(func_8033E840(), &fxegg_collide);
    func_8033EA40(1, 0);
    func_8033EA40(0, 20.0f);
    func_8033EA40(2, 0);
    _player_getPosition(marker);
    player_getRotation(sp30);
    sp30[1] = mlNormalizeAngle(sp30[1] + 180.0f);
    func_80256E24(sp48, 0.0f, sp30[1], 0.0f, 0.0f, -18.0f);
    marker[0] += sp48[0];
    marker[1] += sp48[1];
    marker[2] += sp48[2];
    marker[1] += 60.0f;
    projectile_setSprite(projectile_indx, ASSET_708_SPRITE_EGG_PROJECTILE);
    temp_f18 = 20.0f;
    func_8033FFE4(projectile_indx, (s32)temp_f18, (s32)temp_f18);
    projectile_setPosition(projectile_indx, marker);
    func_8033FCD8(projectile_indx, 0xE);
    func_80287E9C(sp58);
    func_80287F50(sp58, &D_803726A0, 0x14);
    func_80287F10(sp58);
    func_80344E18(sp57, 4);
    func_80344EE4(sp57, -2200.0f, -22000.0f);
    func_80344D94(sp57, marker);
    temp_f2 = ((randf() * 6.0f) - 3.0f);
    sp30[1] = sp30[1] + temp_f2;
    func_80256E24(sp48, 0.0f, sp30[1], 0, 0, 200.0f);
    sp48[1] = (randf() * 20.0f) + 700.0f;
    func_80344E3C(sp57, sp48);
}

void fxegg_ass_update(void) {
    u8 projectile_indx;
    u8 sp8E;
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp64;
    f32 temp_f20;
    f32 temp_f2;
    f32 sp58;
    f32 var_f22;

    projectile_indx = func_8033E8D0();
    sp8E = func_8033E93C();
    sp64 = func_8033EA14(1);
    var_f22 = func_8033EA14(2);
    var_f22 -= time_getDelta();
    sp58 = ml_map_f(sp64, 0.0f, 3.0f, 0.0333f, 0.1f);
    while (var_f22 <= 0.0f) {
        var_f22 += sp58;
        projectile_getPosition(projectile_indx, sp68);
        func_8033E9D4();
        sp68[0] += randf2(-8.0f, 8.0f);
        sp68[1] += randf2(-8.0f, 8.0f);
        sp68[2] += randf2(-8.0f, 8.0f);
        if (randf() < 0.5) {
            func_803541C0(1);
        } else {
            func_803541C0(6);
        }
        func_803541CC(0x32);
        func_80354030(sp68, 0.15);
        func_8033E9F4();
    }
    func_8033EA40(2, var_f22);
    if (func_80344EC0(sp8E)) {
        func_8032320C();
    }
    func_803531C8(projectile_indx, 1);
    func_80344E7C(sp8E, sp74);
    if (0.6 < func_8033EA14(1)) {
        projectile_getPosition(projectile_indx, sp80);
        if (fxegg_isCollidingWithPlayer(sp80)) {
            chcollectable_collectEgg(NULL);
            func_8033E984();
        }
    }
    func_80344E3C(sp8E, sp74);
    temp_f20 = func_8033EA14(0);
    func_8033FFE4(projectile_indx, (s32)temp_f20, (s32)temp_f20);
    func_8033EA40(0, ml_min_f(temp_f20 + 8.0f, 50.0f));
    sp64 += time_getDelta();
    func_8033EA40(1, sp64);
    if ((2.8 < sp64) && (func_80344EC0(sp8E) || (sp64 > 3.5))) {
        func_8033E984();
        fxegg_shatter(projectile_indx);
    }
}

void fxegg_ass_destroy(void){}

void fxegg_collide(s32 arg0, ActorMarker *marker, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(marker);
    if (func_8033D5A4(arg2) != 0) {
        func_8033E984();
        if (actor->modelCacheIndex != 0x29D) {
            fxegg_shatter(func_8033E8D0());
        }
    }
}
