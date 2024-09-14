#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>

#define _SQ3(x, y, z)  (((x) * (x)) + ((y) * (y)) + ((z) * (z)))
#define _SQ3v1(v)      (v[0] * v[0] + v[1] * v[1] + v[2] * v[2])

/*.code*/
void func_802F87B0(struct6s *this){
    f32 plyrPos[3]; //sp7C
    f32 camNorm[3]; //sp70
    f32 camRot[3]; //sp64
    struct5s * ptr;
    f32 f20;
    int i;
    f32 sp4C[3];

    if(vector_size(this->unk1C) >= this->unk20)
        return;
    
    player_getPosition(plyrPos);
    viewport_getLookVector(camNorm);
    viewport_getRotation_vec3f(camRot);
    ptr = vector_pushBackNew(&this->unk1C);
    f20 = randf2(50.0f, 1200.0f);
    sp4C[0] = 0.0f;
    sp4C[1] = randf2(200.0f, 500.0f);
    sp4C[2] = -f20;

    if(gu_sqrtf(_SQ3v1((&this->unkC))) < 5.0f)
    {
        ml_vec3f_yaw_rotate_copy(sp4C, sp4C, randf2(0.0f, 360.0f));
    }
    else{
        ml_vec3f_yaw_rotate_copy(sp4C, sp4C, camRot[1] + randf2(-70.0f, 70.0f));
    }//L802F88F0
    sp4C[0] += plyrPos[0];
    sp4C[1] += plyrPos[1];
    sp4C[2] += plyrPos[2];
    if(f20 < 600.0){
        for(i = 0; i <10 && viewport_isPointPlane_3f(sp4C[0], sp4C[1] - 10.0f, sp4C[2]); i++){
            sp4C[1] += 100.0f;
        }
    }
    ptr->unk4[0] = sp4C[0];
    ptr->unk4[1] = sp4C[1];
    ptr->unk4[2] = sp4C[2];
    
    ptr->unk10[0] = 0.0f;
    ptr->unk10[1] = randf2(-100.0f, -100.0f);
    ptr->unk10[2] = 0.0f;
    
    ptr->unk1C[0] = ptr->unk1C[1] = ptr->unk1C[2] = 0.0f;

    ptr->unk28[0] = randf2(-300.0f, 300.0f);
    ptr->unk28[1] = randf2(-300.0f, 300.0f);
    ptr->unk28[2] = randf2(-300.0f, 300.0f);

    this->unk34++;
    if(!(this->unk34 < 4))
        this->unk34 = 0;

    ptr->unk0 = this->unk24[this->unk34];
}

void func_802F8A68(struct6s *this, s32 arg1){
    this->unk22 = arg1;
}

void func_802F8A70(struct6s *this){
    vector_clear(this->unk1C);
}

void func_802F8A90(struct6s *this, Gfx **gdl, Mtx **mptr, Vtx **vptr){
    struct5s * startPtr = vector_getBegin(this->unk1C);
    struct5s * iPtr;
    struct5s * endPtr = vector_getEnd(this->unk1C);
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        modelRender_draw(gdl, mptr, iPtr->unk4, iPtr->unk1C, 1.0f, NULL, iPtr->unk0);
        iPtr->unk34 = func_8033A170();
    }
}

int func_802F8B50(struct6s *this){
    return this->unk22 != 1  &&  (u32)vector_size(this->unk1C) < 1;
}

void func_802F8B8C(struct6s *this){
    vector_free(this->unk1C);
    func_8033BD20(&this->unk24[0]);
    func_8033BD20(&this->unk24[1]);
    func_8033BD20(&this->unk24[2]);
    func_8033BD20(&this->unk24[3]);
    free(this);
}

struct6s * func_802F8BE0(s32 arg0){
    struct6s *this = (struct6s *) malloc(sizeof(struct6s));
    vector(struct5s) *vecPtr;
    this->unk18 = 0;
    this->unk8 = 0.0f;
    this->unk4 = 0.0f;
    this->unk0 = 0.0f;
    this->unk14 = 0.0f;
    this->unk10 = 0.0f;
    this->unkC = 0.0f;
    vecPtr = vector_new(sizeof(struct5s), arg0);
    this->unk1C = vecPtr;
    this->unk20 = arg0;
    this->unk22 = 0;
    this->unk24[0] = assetcache_get(0x899); //rain
    this->unk24[1] = assetcache_get(0x89A); //red_leaf
    this->unk24[2] = assetcache_get(0x89B); //brown_leaf
    this->unk24[3] = assetcache_get(0x89C); //green_leaf
    this->unk34 = 0;
    this->unk38 = 0.1f;
    return this;
}

void func_802F8C90(struct6s *this){
    func_802F8A68(this, 1);
}

void func_802F8CB0(struct6s *this){
    func_802F8A68(this, 2);
}

void func_802F8CD0(struct6s * this){
    f32 plyr_pos[3];//sp64
    f32 f20 = time_getDelta();
    int i;
    struct5s *iPtr;

    player_getPosition(plyr_pos);
    this->unkC = plyr_pos[0] - this->unk0;
    this->unk10 = plyr_pos[1] - this->unk4;
    this->unk14 = plyr_pos[2] - this->unk8;
    this->unk0 = plyr_pos[0];
    this->unk4 = plyr_pos[1];
    this->unk8 = plyr_pos[2];
    if(func_802BEF64()){
        vector_clear(this->unk1C);
    }

    for(i = 0; i < vector_size(this->unk1C); i++){
        iPtr;
        iPtr = vector_at(this->unk1C, i);
        iPtr->unk4[0] += iPtr->unk10[0]*f20;
        iPtr->unk4[1] += iPtr->unk10[1]*f20;
        iPtr->unk4[2] += iPtr->unk10[2]*f20;

        iPtr->unk10[0] += randf2(-400.0f, 400.0f)*f20;
        iPtr->unk10[2] += randf2(-400.0f, 400.0f)*f20;

        iPtr->unk1C[0] += iPtr->unk28[0]*f20;
        iPtr->unk1C[1] += iPtr->unk28[1]*f20;
        iPtr->unk1C[2] += iPtr->unk28[2]*f20;

        iPtr->unk28[0] += randf2(-300.0f, 300.0f)*f20;
        iPtr->unk28[1] += randf2(-300.0f, 300.0f)*f20;
        iPtr->unk28[2] += randf2(-300.0f, 300.0f)*f20;

        if(iPtr->unk4[1] < plyr_pos[1] - 500.0f && !iPtr->unk34){
            vector_remove(this->unk1C, i);
            i--;
        }
    }
    this->unk18++;
    if((s32)this->unk18 < vector_size(this->unk1C)){
        iPtr = vector_at(this->unk1C, this->unk18);
        if(1320.0 < ml_distance_vec3f(iPtr->unk4, plyr_pos)){
            vector_remove(this->unk1C, this->unk18);
        }
    }
    else{
        this->unk18 = 0;
    }
    
    if(ml_timer_update(&this->unk38, f20)){
        if(this->unk22 == 1 && !func_802BEF64())
            func_802F87B0(this);
        this->unk38 = 0.1f;
    }
}
