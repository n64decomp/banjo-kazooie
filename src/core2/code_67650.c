#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_8024DB50(f32 (*)[3], f32);
extern void func_80256E24(f32 (*)[3], f32, f32, f32, f32, f32);
extern s32 spriteGetFrameCount(Sprite *);

void func_802EF9E4(struct30s *this, s32 arg1);
void func_802EF9EC(struct30s *this, s32 arg1, s32 arg2);
void func_802EFA04(struct30s *, f32);
void func_802EFA10(struct30s *this, s32 arg1);
void func_802EFA20(struct30s *, f32, f32);
void func_802EFA34(struct30s *, f32);
void func_802EFA40(struct30s *, f32 (*)[3]);
void func_802EFF5C(struct30s *, f32, f32, f32);
void func_802EFF7C(struct30s *, f32, f32, f32);
void func_802EFF9C(struct30s *, f32);

struct30s **D_803689B0; //particlePtrArrayPtr
s32 D_803689B4;         //particlePtrArraySize
f32 D_803689B8;

extern f64 D_803771B0;
extern f64 D_803771B8;
extern f64 D_803771C0;
extern f64 D_803771C8;

// 000F 0220: C0F86A0000000000 40F86A0000000000 
// 000F 0230: 40F86A0000000000 3F50624DD2F1A9FC 
// 000F 0240: 400921FB54524550 0000000000000000 

extern f32 D_80380920;
extern u8 D_80380924;



s32 func_802EE5E0(s32 arg0){
    return arg0;
}

void func_802EE5E8(struct30s *this){
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE5F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EE6CC.s")

void func_802EE930(struct30s *this){
    func_8033B388(&this->unk1C, &this->unk34);
    if(this->unk20)
        func_8033BD20(&this->unk20);
}

int func_802EE974(struct30s *this, f32 (*arg1)[3], f32 (*arg2)[3], f32 (*arg3)[3], s32 arg4){
    if(-100000.0 == this->unk74 && 100000.0 == this->unk78){
        return func_80309B48(arg1, arg2, arg3, 0);
    }

    if(100000.0 != this->unk78 && this->unk78 < (*arg2)[1]){
        (*arg2)[1] = this->unk78;
        (*arg3)[2] = 0.0f;
        (*arg3)[0] = 0.0f;
        (*arg3)[1] = -1.0f;
        return 1;
    }
    
    if(this->unk74 != -100000.0  && (*arg2)[1] < this->unk74){
        (*arg2)[1] = this->unk74;
        (*arg3)[2] = 0.0f;
        (*arg3)[0] = 0.0f;
        (*arg3)[1] = 1.0f;
        return 1;
    }
    
    return 0;
}

void func_802EEA9C(struct30s *this, struct2Fs *particle){
    particle->unk0[0] = randf2(this->unk4C[0], this->unk58[0]);
    particle->unk0[1] = randf2(this->unk4C[1], this->unk58[1]);
    particle->unk0[2] = randf2(this->unk4C[2], this->unk58[2]);
    particle->unk5C = this->unk64;
    
    particle->unkC = (0.0f == this->unk10) ? 1.0f : 0; 
    particle->unk10 = randf2((f32)this->unk84, (f32)this->unk88);
    particle->unk14 = randf2(this->unk8C, this->unk90);

    particle->unk18[0] = this->unk28[0];
    particle->unk18[1] = this->unk28[1];
    particle->unk18[2] = this->unk28[2];

    particle->unk18[0] = particle->unk18[0] + randf2(this->unk94[0], this->unkA0[0]);
    particle->unk18[1] = particle->unk18[1] + randf2(this->unk94[1], this->unkA0[1]);
    particle->unk18[2] = particle->unk18[2] + randf2(this->unk94[2], this->unkA0[2]);

    particle->unk34 = particle->unk30 = randf2(this->unkAC[0], this->unkAC[1]);
    if(0.0f == this->unkB4[0] && 0.0f == this->unkB4[1])
        particle->unk38 = 0.0f;
    else
        particle->unk38 = randf2(this->unkB4[0], this->unkB4[1])- particle->unk34;

    particle->unk24[2] = 0.0f;
    particle->unk24[1] = 0.0f;
    particle->unk24[0] = 0.0f;

    particle->unk3C[0] = randf2(this->unkBC[0], this->unkC8[0]);
    particle->unk3C[1] = randf2(this->unkBC[1], this->unkC8[1]);
    particle->unk3C[2] = randf2(this->unkBC[2], this->unkC8[2]);
    
    particle->unk48 = 0.0f;
    particle->unk4C = randf2(this->unkDC[0], this->unkDC[1]) + 0.001;
    if(this->unk48 == 0){
        particle->unk50[0] = randf2(this->unkE4[0], this->unkEC[1]);
        particle->unk50[1] = randf2(this->unkE4[1], this->unkF4[0]);
        particle->unk50[2] = randf2(this->unkEC[0], this->unkF4[1]);
    }
    else{
        func_80256E24(&particle->unk50, 
            mlNormalizeAngle(randf2(this->unkEC[0], this->unkEC[1])),
            mlNormalizeAngle(randf2(this->unkE4[0], this->unkE4[1])),
            0.0f,
            0.0f,
            randf2(this->unkF4[0], this->unkF4[1])
        );
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EED1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EEE3C.s")

void func_802EF3A8(struct30s *this, Gfx **gdl, Mtx **mPtr, Vtx **vPtr){
    func_802EEE3C(this, gdl, mPtr, vPtr, 4);
    func_802EEE3C(this, gdl, mPtr, vPtr, 0);
}

void func_802EF3F4(struct30s *this, f32 (* arg1)[3], f32 (*arg2)[3], s32 arg3){
    for(arg3; arg3 > 0; arg3--){
        if(this->unk128 < this->unk12C){
            func_802EEA9C(this, this->unk128);
            this->unk128->unk18[0] = randf2((*arg1)[0], (*arg2)[0]);
            this->unk128->unk18[1] = randf2((*arg1)[1], (*arg2)[1]);
            this->unk128->unk18[2] = randf2((*arg1)[2], (*arg2)[2]);
            this->unk128++;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802EF4AC.s")


void func_802EF5C8(struct30s *this, int arg1){
    for(arg1; arg1 > 0; arg1--){
        if(this->unk128 < this->unk12C){
            func_802EEA9C(this, this->unk128++);
        }
    }
}

int func_802EF628(struct30s *this){
    return (u32)(this->unk128 - this->unk124);
}

int func_802EF648(struct30s *this){
    return (u32)(this->unk128 - this->unk124) < 1 
           && this->unk0_23 == 1;
}

//free particle_ctl
void func_802EF684(struct30s *this){
    func_802EE930(this);
    free(this);
}

// new particle_ctrl
struct30s * func_802EF6AC(u32 arg0){
    struct30s *this = malloc(arg0*sizeof(struct2Fs) + sizeof(struct30s));
    f32 sp40[3];
    
    this->unk0_0 = 0;
    this->unk0_23 = 1;
    this->unk18 = 0;
    this->unk1C = NULL;
    this->unk0_16 = 0;
    this->unk20 = 0;
    this->unk34 = 0;
    this->unk0_15 = 0;
    this->unk3C[0] = 0xff;
    this->unk3C[1] = 0xff;
    this->unk3C[2] = 0xff;
    this->unk24 = 0.0f;
    this->unk38 = 0.0f;
    sp40[0] = sp40[1] = sp40[2] = 0.0f;
    
    func_802EFA40(this, &sp40);
    func_802EFA5C(this, 0.0f, 1.0f);
    func_802EFA70(this, 0);
    func_802EFB54(this, &sp40);
    func_802EF9AC(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EF9E4(this, 0xff);
    func_802EFB1C(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EFED4(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EF9EC(this, 0, 0);
    func_802EF9F8(this, 0.9f);
    func_802EFA04(this, -100000.0f);
    func_802EFA34(this, 100000.0f);
    func_802EFA10(this, 0);
    func_802EFA18(this, 0);
    func_802EFA20(this, 1.0f, 1.0f);
    func_802EFA90(this, 0, 0);
    func_802EFA9C(this, 0.0f, 0.0f);
    func_802EFB70(this, 1.0f, 1.0f);
    func_802EFB84(this, 0.0f, 0.0f);
    func_802EFE24(this, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EFE5C(this, 0.0f, 5.0f);
    func_802EFEC0(this, 0.0f, 5.0f);
    func_802EFF5C(this, 0.0f, 0.0f, 0.0f);
    func_802EFF7C(this, 0.0f, 0.0f, 0.0f);
    func_802EFF9C(this, 0.0f);
    func_802EFF50(this, 0.0f);
    this->unk100 = 0;
    this->unk104 = 0;
    this->unk124 = &this->data[0];
    this->unk128 = &this->data[0];
    this->unk12C = &this->unk124[arg0];
    return this;
}

void func_802EF950(struct30s *this, enum asset_e sprite_id){
    if(sprite_id != this->unk0_15){
        this->unk0_15 = sprite_id;
        func_802EE930(this);
        this->unk1C = func_8033B6C4(sprite_id, &this->unk34);
    }
}

void func_802EF9AC(struct30s *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    this->unk4C[0] = arg1;
    this->unk4C[1] = arg2;
    this->unk4C[2] = arg3;
    this->unk58[0] = arg4;
    this->unk58[1] = arg5;
    this->unk58[2] = arg6;
}

void func_802EF9E4(struct30s *this, s32 arg1){
    this->unk49 = arg1;
}

void func_802EF9EC(struct30s *this, s32 arg1, s32 arg2){
    this->unk66 = arg1;
    this->unk7C = arg2;
}

void func_802EF9F8(struct30s *this, f32 arg1){
    this->unk68 = arg1;
}

void func_802EFA04(struct30s *this, f32 arg1){
    this->unk74 = arg1;
}

void func_802EFA10(struct30s *this, s32 arg1){
    this->unk80 = arg1;
}

void func_802EFA18(struct30s *this, s32 arg1){
    this->unk64 = arg1;
}

void func_802EFA20(struct30s *this, f32 arg1, f32 arg2){
    this->unk6C = arg1;
    this->unk70 = arg2;
}

void func_802EFA34(struct30s *this, f32 arg1){
    this->unk78 = arg1;
}

void func_802EFA40(struct30s *this, f32 (*arg1)[3]){
    this->unk4[0] = (*arg1)[0];
    this->unk4[1] = (*arg1)[1];
    this->unk4[2] = (*arg1)[2];
}

void func_802EFA5C(struct30s *this, f32 arg1, f32 arg2){
    this->unk10 = arg1;
    this->unk14 = arg2;
}

void func_802EFA70(struct30s *this, s32 arg1){
    this->unk18 = arg1;
}

void func_802EFA78(struct30s *this, s32 arg1){
    this->unk0_16 = arg1;
}

void func_802EFA90(struct30s *this, s32 arg1, s32 arg2){
    this->unk84 = arg1;
    this->unk88 = arg2;
}

void func_802EFA9C(struct30s *this, f32 arg1, f32 arg2){
    this->unk8C = arg1;
    this->unk90 = arg2;
}

void func_802EFAB0(struct30s *this, s32 arg1, f32 arg2){
    this->unk100 = arg1;
    this->unk104 = (s16) arg2;
}

void func_802EFAC8(struct30s *this, enum asset_e arg1){
    if(this->unk0_15 != arg1){
        this->unk0_15 = arg1;
        func_802EE930(this);
        this->unk20 = assetcache_get(arg1);
    }
}

void func_802EFB1C(struct30s *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    this->unk94[0] = arg1;
    this->unk94[1] = arg2;
    this->unk94[2] = arg3;
    this->unkA0[0] = arg4;
    this->unkA0[1] = arg5;
    this->unkA0[2] = arg6;
}

void func_802EFB54(struct30s * this, f32 (* arg1)[3]){
    this->unk28[0] = (*arg1)[0];
    this->unk28[1] = (*arg1)[1];
    this->unk28[2] = (*arg1)[2];
}

void func_802EFB70(struct30s * this, f32 arg1, f32 arg2){
    this->unkAC[0] = arg1;
    this->unkAC[1] = arg2;
}

void func_802EFB84(struct30s * this, f32 arg1, f32 arg2){
    this->unkB4[0] = arg1;
    this->unkB4[1] = arg2;
}

void func_802EFB98(struct30s *this, struct31s *arg1){
    this->unkAC[0] = arg1->unk0[0];
    this->unkAC[1] = arg1->unk0[1];
    if(-1.0f != arg1->unk8[0]){
        this->unkB4[0] = arg1->unk8[0];
        this->unkB4[1] = arg1->unk8[1];
    }
    func_802EFE5C(this, arg1->unk10[0], arg1->unk10[1]);
    this->unkDC[0] = arg1->unk18[0];
    this->unkDC[1] = arg1->unk18[1];
    this->unk10 = arg1->unk20;
    this->unk14 = arg1->unk24;
}

void func_802EFC28(struct30s *this, struct40s *arg1){
    func_802EFB98(this, &arg1->unk0);
    func_802EFA70(this, (s32)arg1->unk28);
    func_802EF5C8(this, (s32)arg1->unk2C);
}

void func_802EFC84(struct30s *this, struct41s *arg1){
    func_802EFED4(this, 
        arg1->unk0.unk0[0], arg1->unk0.unk0[1], 
        arg1->unk0.unk8[0], arg1->unk0.unk8[1], 
        arg1->unk0.unk10[0], arg1->unk0.unk10[1]
    );
    func_802EF9AC(this, 
        arg1->unk18.unk0[0], arg1->unk18.unk0[1], arg1->unk18.unk0[2], 
        arg1->unk18.unkC[0], arg1->unk18.unkC[1], arg1->unk18.unkC[2]
    );
}

void func_802EFD00(struct30s *this, struct42s *arg1){
    func_802EFED4(this, 
        arg1->unk0.unk0[0], arg1->unk0.unk0[1], 
        arg1->unk0.unk8[0], arg1->unk0.unk8[1], 
        arg1->unk0.unk10[0], arg1->unk0.unk10[1]
    );

    func_802EFB1C( this, 
        arg1->unk18.unk0[0], arg1->unk18.unk0[1], arg1->unk18.unk0[2], 
        arg1->unk18.unkC[0], arg1->unk18.unkC[1], arg1->unk18.unkC[2]
    );
}

void func_802EFD7C(struct30s *this, struct43s* arg1){
    func_802EFED4(this, 
        arg1->unk0.unk0[0], arg1->unk0.unk0[1], 
        arg1->unk0.unk8[0], arg1->unk0.unk8[1], 
        arg1->unk0.unk10[0], arg1->unk0.unk10[1]
    );
    func_802EF9AC(this, 
        arg1->unk18.unk0[0], arg1->unk18.unk0[1], arg1->unk18.unk0[2], 
        arg1->unk18.unkC[0], arg1->unk18.unkC[1], arg1->unk18.unkC[2]
    );
    func_802EFB1C( this, 
        arg1->unk30.unk0[0], arg1->unk30.unk0[1], arg1->unk30.unk0[2], 
        arg1->unk30.unkC[0], arg1->unk30.unkC[1], arg1->unk30.unkC[2]
    );
}

void func_802EFE24(struct30s *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    this->unkBC[0] = arg1;
    this->unkBC[1] = arg2;
    this->unkBC[2] = arg3;
    this->unkC8[0] = arg4;
    this->unkC8[1] = arg5;
    this->unkC8[2] = arg6;
}

void func_802EFE5C(struct30s *this, f32 arg1, f32 arg2){
    this->unkD4 = arg1;
    this->unkD8 = arg2;
    if(0.0f == this->unk24 || arg2 < this->unk24)
        this->unk24 = randf2(this->unkD4, this->unkD8);
}

void func_802EFEC0(struct30s *this, f32 arg1, f32 arg2){
    this->unkDC[0] = arg1;
    this->unkDC[1] = arg2;
}

void func_802EFED4(struct30s *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    this->unk48 = FALSE;
    this->unkE4[0] = arg1;
    this->unkE4[1] = arg2;
    this->unkEC[0] = arg3;
    this->unkEC[1] = arg4;
    this->unkF4[0] = arg5;
    this->unkF4[1] = arg6;
}

void func_802EFF10(struct30s *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6){
    this->unk48 = TRUE;
    this->unkE4[0] = arg2;
    this->unkE4[1] = arg5;
    this->unkEC[0] = arg1;
    this->unkEC[1] = arg4;
    this->unkF4[0] = arg3;
    this->unkF4[1] = arg6;
}

void func_802EFF50(struct30s *this, f32 arg1){
    this->unkFC = arg1;
}

void func_802EFF5C(struct30s *this, f32 arg1, f32 arg2, f32 arg3){
    this->unk118[0] = arg1;
    this->unk118[1] = arg2;
    this->unk118[2] = arg3;
}

void func_802EFF7C(struct30s *this, f32 arg1, f32 arg2, f32 arg3){
    this->unk10C[0] = arg1;
    this->unk10C[1] = arg2;
    this->unk10C[2] = arg3;
}

void func_802EFF9C(struct30s *this, f32 arg1){
    this->unk108 = arg1;
}

void func_802EFFA8(struct30s *this, s32 (*arg1)[3]){
    this->unk3C[0] = (*arg1)[0];
    this->unk3C[1] = (*arg1)[1];
    this->unk3C[2] = (*arg1)[2];
}

void func_802EFFC4(struct30s *this, f32 arg1){
    this->unk0_23 = 0;
    this->unk38 = arg1;
}

void func_802EFFDC(struct30s *this){
    return;
}

void func_802EFFE4(struct30s *this){
    struct2Fs *iPtr;
    f32 tick = func_8033DD9C();
    f32 temp_f0;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp68;
    
    if(D_80380924){
        for(iPtr = this->unk124; iPtr < this->unk128;){//L802F005C
            iPtr->unk48 += tick;
            if(iPtr->unk4C <= iPtr->unk48){
                memcpy(iPtr, --this->unk128, sizeof(struct2Fs));
            }else{//L802F00A0
                temp_f0 = iPtr->unk48/iPtr->unk4C;
                if(temp_f0 < this->unk10)
                    iPtr->unkC = temp_f0/this->unk10;
                else if(temp_f0 <= this->unk14)
                    iPtr->unkC = 1.0f;
                else{
                    iPtr->unkC = 1.0f - ((temp_f0 - this->unk14)/(1.0f - this->unk14)); 
                }//L802F00F0
                iPtr->unk30 = iPtr->unk34 + temp_f0*iPtr->unk38;
                
                if(this->unk1C){
                    iPtr->unk10 += iPtr->unk14*tick;
                    if(!((s32)iPtr->unk10 < spriteGetFrameCount(this->unk1C))){
                        if(this->unk18 & 8){
                            iPtr->unk10 = spriteGetFrameCount(this->unk1C) - 1;
                        }else{
                            iPtr->unk10 = 0.0f;
                        }
                    }
                }//L802F0180

                iPtr->unk18[0] += iPtr->unk50[0]*tick;
                iPtr->unk18[1] += iPtr->unk50[1]*tick;
                iPtr->unk18[2] += iPtr->unk50[2]*tick;

                iPtr->unk24[0] += iPtr->unk3C[0]*tick;
                iPtr->unk24[1] += iPtr->unk3C[1]*tick;
                iPtr->unk24[2] += iPtr->unk3C[2]*tick;

                iPtr->unk50[0] = iPtr->unk50[0] + iPtr->unk0[0]*tick;
                iPtr->unk50[1] = iPtr->unk50[1] + iPtr->unk0[1]*tick;
                iPtr->unk50[2] = iPtr->unk50[2] + iPtr->unk0[2]*tick;

                if(this->unk100){
                    iPtr->unk18[1] = func_8034E698(this->unk100) + this->unk104;
                }//L802F0254

                if( 0.0f != this->unkFC 
                    && !func_8024DB50(&iPtr->unk18, this->unkFC)
                ){
                    memcpy(iPtr, --this->unk128, sizeof(struct2Fs));
                }
                else{//L802F029C
                    if(iPtr->unk5C > 0){
                        sp6C[0] = iPtr->unk18[0];
                        sp6C[1] = iPtr->unk18[1] + 50.0f;
                        sp6C[2] = iPtr->unk18[2];
                        if(func_802EE974(this, &sp6C, &iPtr->unk18, &sp78, 0)){
                            if(this->unk66){
                                sp68 = mlAbsF(iPtr->unk50[1])/10.0;
                                if(1.0f < sp68){
                                    sp68 = 1.0f;
                                }//L802F0324
                                if(D_80380920 == 0.0f){
                                    func_8030E6A4(this->unk66, randf2(this->unk6C, this->unk70), (s32)((f32)this->unk7C*sp68));
                                    D_80380920 = 0.25f;
                                }
                            }//L802F0384
                            iPtr->unk18[1] += 2.0f;
                            iPtr->unk50[1] = mlAbsF(iPtr->unk50[1]) * this->unk68;
                            if((this->unk18 & 0x2) == 0){
                                iPtr->unk34 *= this->unk68;
                                iPtr->unk38 *= this->unk68;
                            }//L802F03DC

                            iPtr->unk3C[0] *= this->unk68;
                            iPtr->unk3C[1] *= this->unk68;
                            iPtr->unk3C[2] *= this->unk68;
                            if(--iPtr->unk5C == 0){
                                if(this->unk80)
                                    this->unk80(this, &iPtr->unk18);
                                memcpy(iPtr, --this->unk128, sizeof(struct2Fs));
                                continue;
                            }
                        }
                    }
                    iPtr++;
                }
            }//L802F045C
        }//L802F0468
        if(0.0f < this->unk38){
            this->unk38 -= tick;
            if(this->unk38 <= 0.0f)
                this->unk0_23 = 1;
        }

        if(this->unk0_23 != 1){
            this->unk24 -= tick;
            if(this->unk24 <= 0.0f){
                this->unk24 = randf2(this->unkD4, this->unkD8);
                if(this->unk128 < this->unk12C)
                    func_802EEA9C(this, this->unk128++);
            }
        }
    }//L802F0514
}

void func_802F053C(struct30s *this, f32 (*arg1)[3]){
    func_802EF950(this, 0x70e);
    func_802EFFA8(this, &D_803689B8);
    func_802EFA5C(this, 0.0f, 0.1f);
    func_802EFA90(this, 0, 7);
    func_802EFB1C(this, -80.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    func_802EFB54(this, arg1);
    func_802EFB70(this, 1.0f, 1.0f);
    func_802EFB84(this, 2.0f, 3.0f);
    func_802EFE5C(this, 0.0f, 0.01f);
    func_802EFEC0(this, 3.0f, 4.0f);
    func_802EFED4(this, -200.0f, 0.0f, -200.0f, 200.0f, 100.0f, 200.0f);
}

void func_802F066C(struct30s *this, f32(*arg1)[3]){
    func_802EF9AC(this, 0.0f, -800.0f, 0.0f, 0.0f, -800.0f, 0.0f);
    func_802EF9F8(this, 0.6f);
    func_802EFA18(this, 3);
    func_802EFAC8(this, 0x896);
    func_802EFB1C(this,
        -120.0f, -60.0f, -120.0f,
        120.0f, 60.0f, 120.0f
    );
    func_802EFB54(this, arg1);
    func_802EFB70(this, 0.2f, 0.3f);
    func_802EFE24(this, 
        -300.0f, -300.0f, -300.0f,
        300.0f, 300.0f, 300.0f
    );
    func_802EFE5C(this, 0.0f, 0.01f);
    func_802EFEC0(this, 10.0f, 10.0f);
    func_802EFED4(this, 
        -500.0f, 150.0f, 
        -500.0f, 500.0f,
         400.0f, 500.0f
    );
}

void func_802F07D8(void){
    D_803689B0 = (struct30s **) malloc(0);
    D_803689B4 = 0;
}

void func_802F0804(void){
    int i;
    for(i = 0; i < D_803689B4; i++){
        func_802EF684(D_803689B0[i]);
    }
    free(D_803689B0);
    D_803689B0 = NULL;
    D_803689B4 = 0;
}

void func_802F0898(void){
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_67650/func_802F08A0.s")

void func_802F0A34(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < D_803689B4; i++){
        func_802EEE3C(D_803689B0[i], gdl, mptr, vptr, 4);
    }
}

void func_802F0AE8(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < D_803689B4; i++){
        func_802EEE3C(D_803689B0[i], gdl, mptr, vptr, 0);
    }
}

void func_802F0B98(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    func_802F0A34(gdl, mptr, vptr);
    func_802F0AE8(gdl, mptr, vptr);
}

struct30s *func_802F0BD0(u32 arg0){
    D_803689B0 = realloc(D_803689B0, (++D_803689B4)*4);
    D_803689B0[D_803689B4 - 1] = func_802EF6AC(arg0);
    D_803689B0[D_803689B4 - 1]->unk0_0 = TRUE;
    return D_803689B0[D_803689B4 - 1];
}


void func_802F0C78(struct30s *this){
    int i = 0;
    while(this != D_803689B0[i] && i < D_803689B4){i++;}
    if(i == D_803689B4)
        return;

    func_802EF684(this);
    D_803689B0[i] = D_803689B0[D_803689B4 - 1];
    D_803689B4--;
    D_803689B0 = realloc(D_803689B0, D_803689B4*sizeof(struct30s *));
}

void func_802F0D54(struct30s *this){
    this->unk0_0 = FALSE;
}

void func_802F0D64(struct30s *this){
    this->unk0_0 = TRUE;
}

struct30s * func_802F0D74(struct30s *this){
    int i;
    s32 a3;

    if(this){
        a3 = (s32)this;
        i = 0;
        while(D_803689B0[i] != this && i < D_803689B4){
            i++;
        }
        this = (struct30s *)func_802555DC(this);
        this->unk124 = (s32)this + (u32)((s32)this->unk124 - a3);
        this->unk128 = (s32)this + (u32)((s32)this->unk128 - a3);
        this->unk12C = (s32)this + (u32)((s32)this->unk12C - a3);
        if(i < D_803689B4){
            D_803689B0[i] = this;
        }

    }//L802F0E44
    return this;
}

void func_802F0E58(void){
    D_803689B0 = (struct30s **)func_802555DC(D_803689B0);
}

void func_802F0E80(void* arg0, s32 arg1){
    D_80380924 = (arg1 == 2) ? 1 : 0;
}

void func_802F0EAC(struct30s *this, f32 arg1){
    struct2Fs *iPtr;
    this->unk28[1] = arg1;
    for(iPtr = this->unk124; iPtr < this->unk128; iPtr++)
        iPtr->unk18[1] = arg1;
    
}
