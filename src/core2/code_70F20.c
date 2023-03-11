#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 func_8024DD34(f32,f32, f32);

/* .code */
void func_802F7EB0(struct3s *this){
    f32 plyrPos[3]; //sp74
    f32 camNorm[3]; //sp68
    f32 camRot[3]; //sp5C
    s32 i;
    f32 tmpf;
    struct4s * sp50;
    f32 sp4C[3];


    if(vector_size(this->unk20) >= this->unk24)
        return;

    player_getPosition(plyrPos);
    func_8024C5A8(camNorm);
    viewport_getRotation(camRot);
    sp50 = vector_pushBackNew(&this->unk20);
    tmpf = randf2(50.0f, 1100.0f);
    sp4C[0] = 0.0f;
    sp4C[1] = randf2(200.0f, 300.0f);
    sp4C[2] = -tmpf;

    if(gu_sqrtf(this->unk10[0]*this->unk10[0] + this->unk10[1]*this->unk10[1] + this->unk10[2]*this->unk10[2]) < 5.0f){
        ml_vec3f_yaw_rotate_copy(sp4C, sp4C, randf2(0.0f, 360.0f));
    }
    else{
        ml_vec3f_yaw_rotate_copy(sp4C, sp4C, camRot[1]+ randf2(-70.0f, 70.0f));
    }
    sp4C[0] = plyrPos[0] + sp4C[0];
    sp4C[1] = plyrPos[1] + sp4C[1];
    sp4C[2] = plyrPos[2] + sp4C[2];
    if(tmpf < 550.0)
        for(i = 0; (i < 0xa) && func_8024DD34(sp4C[0],sp4C[1]- 10.0f, sp4C[2]); i++){
            sp4C[1] += 100.0f;
        }

    sp50->unk0[0] = sp4C[0];
    sp50->unk0[1] = sp4C[1];
    sp50->unk0[2] = sp4C[2];
    sp50->unkC[0] = 0.0f;
    sp50->unkC[1] = randf2(-1600.0f, -1500.0f);
    sp50->unkC[2] = 0.0f;
}

void func_802F80E8(struct3s *this, u32 arg1){
    this->unk28 = arg1;
}

void func_802F80F0(struct3s *this){
    vector_clear(this->unk20);
}


void func_802F8110(struct3s *this, Gfx **gdl, Mtx **mptr, u32 arg3){
    struct4s * startPtr; //sp4c
    struct4s * endPtr;
    struct4s * iPtr;

    startPtr = vector_getBegin(this->unk20);
    endPtr = vector_getEnd(this->unk20);
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        modelRender_draw(gdl, mptr, iPtr, 0, 1.0f, 0, this->unk2C);
        iPtr->unk18 = func_8033A170();
    }
}

bool func_802F81D8(struct3s *this){
    return (this->unk28 != 1) && (vector_size(this->unk20) == 0);
}

void func_802F8214(struct3s * this){
    if(this->unk0)
        func_802F9D38(this->unk0);
    vector_free(this->unk20);
    func_8033BD20(&this->unk2C);
    free(this);

}

struct3s *func_802F8264(s32 arg0){
    struct3s * ptr = (struct3s *) malloc(sizeof(struct3s));
    ptr->unk0 = 0;
    ptr->unk1C = 0;
    ptr->unk34 = 0;
    ptr->unk4[0] = ptr->unk4[1] = ptr->unk4[2] =0.0f;
    ptr->unk10[0] = ptr->unk10[1] = ptr->unk10[2] =0.0f;
    ptr->unk20 = vector_new(sizeof(struct4s), arg0);
    ptr->unk24 = arg0;
    ptr->unk28 = 0;
    ptr->unk2C = assetcache_get(0x898); //rain
    ptr->unk30 = 0.1f;
    return ptr;
}

void func_802F82F4(struct3s *this, f32 arg1, f32 arg2, f32 arg3, f32 arg4){
    this->unk34 = 1;
    this->unk38 = 0.0f;
    this->unk3C = 0.1f;
    this->unk40[0] = arg1;
    this->unk40[1] = arg2;
    this->unk40[2] = arg3;
    this->unk40[3] = arg4;
}

void func_802F8338(struct3s *this){
    func_802F80E8(this, 1);
}

void func_802F8358(struct3s *this){
    void *tmp;
    func_802F80E8(this, 2);
    if(!(tmp = this->unk0))
        return;
    func_802F9FD0(tmp, 0.0f, 0.0f, 3.0f);
    this->unk0 = NULL;
}

void func_802F83AC(struct3s *arg0) {
    f32 sp3C[3];
    f32 temp_f20;
    struct4s *temp_v0;
    s32 phi_s0;

    temp_f20 = time_getDelta();
    player_getPosition(sp3C);
    arg0->unk10[0] = sp3C[0] - arg0->unk4[0];
    arg0->unk10[1] = sp3C[1] - arg0->unk4[1];
    arg0->unk10[2] = sp3C[2] - arg0->unk4[2];
    arg0->unk4[0] = sp3C[0];
    arg0->unk4[1] = sp3C[1];
    arg0->unk4[2] = sp3C[2];
    if (func_802BEF64()) {
        vector_clear(arg0->unk20);
    }
    if (vector_size(arg0->unk20) > 0) {
        if (arg0->unk0 == 0) {
            arg0->unk0 = func_802F9AA8(SFX_BE_WATERFALL);
            func_802F9DB8(arg0->unk0, 0.95f, 1.05f, 0.01f);
            func_802F9F80(arg0->unk0, 3.0f, 1.296e7f, 0.0f);
            func_802FA0B0(arg0->unk0, 2);
            func_802FA060(arg0->unk0, 5000, 6000, 5.0f);
        }
    } else {
        if (arg0->unk0 != 0) {
            func_802F9D38(arg0->unk0);
            arg0->unk0 = 0;
        }
    }
    for(phi_s0 = 0; phi_s0 < vector_size(arg0->unk20); phi_s0++){
        temp_v0 = (struct4s *)vector_at(arg0->unk20, phi_s0);
        temp_v0->unk0[0] += temp_v0->unkC[0] * temp_f20;
        temp_v0->unk0[1] += temp_v0->unkC[1] * temp_f20;
        temp_v0->unk0[2] += temp_v0->unkC[2] * temp_f20;
        if ((temp_v0->unk0[1] < (sp3C[1] - 500.0f)) && (temp_v0->unk18 == 0)) {
            vector_remove(arg0->unk20, phi_s0);
            phi_s0--;
        }
    }
    arg0->unk1C++;
    if (arg0->unk1C < vector_size(arg0->unk20)) {
        temp_v0 = (struct4s *)vector_at(arg0->unk20, arg0->unk1C);
        if (1210.0 < ml_distance_vec3f(temp_v0->unk0, sp3C)) {
            vector_remove(arg0->unk20, arg0->unk1C);
        }
    } else {
        arg0->unk1C = 0;
    }

    if (arg0->unk34 != 0) {
        arg0->unk38 += temp_f20;
        if (arg0->unk40[arg0->unk34 - 1] <= arg0->unk38) {
            arg0->unk34++;
            arg0->unk38 = 0.0f;
            if (arg0->unk34 > 4) {
                arg0->unk34 = 1;
            }
        }
        if (arg0->unk34 == 1) {
            arg0->unk3C = (1.0f - arg0->unk38/arg0->unk40[0]) * 0.1;
        } else if (arg0->unk34 == 2) {
            arg0->unk3C = 0.01f;
        } else if (arg0->unk34 == 3) {
            arg0->unk3C = (arg0->unk38 / arg0->unk40[2]) * 0.1;
        } else {
            arg0->unk3C = 0.01f;
        }
        if (arg0->unk3C <= 0.01) {
            arg0->unk3C = 0.01f;
        }
    }
    if (ml_timer_update(&arg0->unk30, temp_f20)) {
        if ((arg0->unk28 == 1) && !func_802BEF64() && (arg0->unk34 != 4)) {
            func_802F7EB0(arg0);
        }
        arg0->unk30 = (arg0->unk34 != 0) ? arg0->unk3C : 0.01;
    }
}
