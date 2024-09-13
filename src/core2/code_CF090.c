#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "code_B6EA0.h"
#include "core2/anim/sprite.h"

/* .data */
AnimSpriteStep D_80372700[] = {
    {0x00, 1}, 
    {0x01, 1}, 
    {0x02, 1}, 
    {0x03, 1}, 
    {0x04, 1}, 
    {0x05, 1}, 
    {0x06, 1}, 
    {0x07, 1},
    {0x08, 1}, 
    {0x09, 1}, 
    {0x0A, 1}, 
    {0x0B, 1}, 
    {0x0C, 1}, 
    {0x0D, 1}, 
    {0x0E, 1}, 
    {0x0F, 1},
    {0x10, 1}, 
    {0x11, 1}, 
    {0x12, 1}, 
    {0x13, 1}
};


/* .code */
void func_80356020(u8 arg0, f32 arg1[4]){
    func_8033FFE4(arg0, (s32)arg1[0], (s32)arg1[0]);
    func_8033FC34(arg0, (s32)arg1[2]);
}

void func_80356074(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3){
    ParticleStruct0s *sp1C;
    u8 sp1B;
    u8 sp1A;

    if(func_8033E3F0(6, 1) < 0)
        return;
    
    sp1A = func_8033E8D0();
    sp1B = func_8033E93C();
    sp1C = func_8033E960();
    sp1C->unk0 = arg2;
    sp1C->unk4 = (arg3 - sp1C->unk0)/20.0f;
    projectile_setPosition(sp1A, arg0);
    func_80344D94(sp1B, arg0);
    func_80344E3C(sp1B, arg1);
    func_80356020(sp1A, sp1C);
}

void func_8035611C(void){
    u8 projectile_indx;
    AnimSprite *sp58;
    u8 sp57;
    ParticleStruct0s *sp54;
    f32 plyr_pos[3];
    f32 sp38[3];
    f32 sp2C[3];

    projectile_indx = (u8)func_8033E8D0();
    sp58 = func_8033E8F4();
    sp57 = func_8033E93C();
    sp54 = func_8033E960();
    player_getPosition(plyr_pos);
    sp54->unk0 = 10.0f;
    sp54->unk4 = 8.0f;
    sp54->unk8 = 255.0f;
    sp54->unkC = -6.0f;
    projectile_setSprite(projectile_indx, ASSET_70D_SPRITE_SMOKE_1);
    func_8033FCD8(projectile_indx, 5);

    projectile_setColor(projectile_indx, (s32)(randf()*30.0f + 60.0f) ,(s32)(randf()*20.0f + 210.0f), (s32)(randf()*30.0f + 140.0f));
    projectile_setPosition(projectile_indx, plyr_pos);
    sp2C[0] = 0.0f;
    sp2C[1] = 0.0f;
    sp2C[2] = randf()*359.0f;
    projectile_setRotation(projectile_indx, sp2C);
    animsprite_default(sp58);
    animsprite_set_state(sp58, ANIM_SPRITE_STATE_ONCE);
    animsprite_set_steps(sp58, D_80372700, sizeof(D_80372700));
    animsprite_loop(sp58);

    sp38[0] = 0.0f;
    sp38[1] = 40.0f;
    sp38[2] = 0.0f;
    func_80344E18(sp57, 2);
    func_80344E3C(sp57, sp38);
    func_80344D94(sp57, plyr_pos);
    func_80356020(projectile_indx, sp54);
}

void func_803562E8(void){
    ParticleStruct0s *sp24;
    AnimSprite *sp20;
    u8 sp1F;
    
    sp24 = func_8033E960();
    sp20 = func_8033E8F4();
    sp1F = func_8033E8D0();
    if(animsprite_is_stopped(sp20)){
        func_8033E984();
    }
    else{
        sp24->unk0 += sp24->unk4;
        sp24->unk8 += sp24->unkC;
        func_80356020(sp1F, sp24);
    }
}

void func_80356364(void){}
