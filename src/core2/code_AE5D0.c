#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

extern void func_8033AA50(void *, f32, Struct_B1400_1 *);
extern void func_8033A750(s32, s32, Struct_B1400_1 *, f32);

/* .code */
void func_80335560(Struct80s *self){
    if(self->unk0 != NULL){
        func_8033A6F0(self->unk0);
        self->unk0 = NULL;
    }

    if(self->unk4 != NULL){
        assetcache_release(self->unk4);
        self->unk4 = NULL;
    }

    if(self->unk24 != NULL){
        func_8033A6F0(self->unk24);
        self->unk24 = NULL;
    }

    if(self->unk28 != NULL){
        func_8033A6F0(self->unk28);
        self->unk28 = NULL;
    }

    self->unk2C = 0.0f;
}

void func_803355F8(Struct7Fs* arg0){
    if(arg0->unk4 == 0){
        ((void(*)(void))(arg0->unk8))();
    }
    else if(arg0->unk4 == 1){
        ((void(*)(s32))(arg0->unk8))(arg0->unkC);
    }
}

void func_80335650(Struct80s *self){
    if(self->unk10 != NULL){
        vector_clear(self->unk10);
    }
}

enum asset_e func_8033567C(Struct80s *self){
    return self->unk16;
}

f32 func_80335684(Struct80s *self){
    return self->unk8;
}

void func_8033568C(Struct80s *self, f32 *arg1, f32 *arg2){
    *arg1 = self->unk1C;
    *arg2 = self->unk8;
}

s32 func_803356A0(Struct80s *self){
    self->unk14 = 0;
    if(self->unk0 == 0){
        self->unk0 = func_8033A710();
    }

    if(self->unk30 != 0){
        self->unk30 = 0;
        return self->unk0;
    }

    if(self->unk16 == 0){
        return self->unk0;
    }

    if(self->unk4 == NULL){
        self->unk4 = (AnimationFile *)assetcache_get(self->unk16);
    }

    if(0.0f == self->unk2C){
        func_8033AA50(self->unk4, self->unk8, self->unk0);
        return self->unk0;
    }

    if(self->unk28 == 0){
        self->unk28 = (Struct_B1400_1 *) func_8033A710();
    }
    func_8033AA50(self->unk4, self->unk8, self->unk28);
    func_8033A750(self->unk0, self->unk24, self->unk28, self->unk20);
    return self->unk0;
}

s32 func_80335794(Struct80s *self){
    return self->unk18;
}

void func_8033579C(Struct80s *self, f32 arg1, void(*arg2)(void)){
    Struct7Fs *ptr;
    if(self->unk10 == NULL){
        self->unk10 = vector_new(sizeof(Struct7Fs), 8);
    }
    ptr = (Struct7Fs *)vector_pushBackNew(&self->unk10);
    ptr->unk0 = arg1;
    ptr->unk4 = 0;
    ptr->unk8 = arg2;
    ptr->unkC = 0;
}

void func_80335800(Struct80s *self, f32 arg1, void(*arg2)(ActorMarker *), ActorMarker *arg3){
    Struct7Fs *ptr;
    if(self->unk10 == NULL){
        self->unk10 = vector_new(sizeof(Struct7Fs), 8);
    }
    ptr = (Struct7Fs *)vector_pushBackNew(&self->unk10);
    ptr->unk0 = arg1;
    ptr->unk4 = 1;
    ptr->unk8 = arg2;
    ptr->unkC = arg3;
}

void func_80335874(Struct80s *self){
    VLA * temp_a0;
    func_80335560(self);
    temp_a0 = self->unk10;
    if(temp_a0 != NULL){
        vector_free(temp_a0);
    }
    free(self);
}

Struct80s *func_803358B4(void){
    Struct80s *self;

    self = (Struct80s *)malloc(sizeof(Struct80s));
    self->unk0 = 0;
    self->unk4 = NULL;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk15 = 1;
    self->unk18 = 0;
    self->unk16 = 0;
    self->unk30 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk8 = 0.0f;
    self->unkC = 0.0f;
    self->unk1C = 0.0f;
    self->unk20 = 0.0f;
    self->unk2C = 0.0f;

    return self;
}

void func_80335918(Struct80s *self){
    self->unk30 = 1;
}

void func_80335924(Struct80s *self, enum asset_e anim_id, f32 arg2, f32 arg3){
    if(self->unk4 != NULL && anim_id != self->unk16){
        assetcache_release(self->unk4);
        self->unk4 = NULL;
    }

    if(self->unk10 != NULL && anim_id != self->unk16){
        vector_free(self->unk10);
        self->unk10 = NULL;
    }

    self->unk8 = 0.0f;
    self->unkC = arg3;
    self->unk18 = 0;
    self->unk16 = anim_id;
    self->unk1C = 0.0f;
    self->unk20 = 0.0f;
    self->unk2C = arg2;
    if(0.0f < arg2){
        if(self->unk0 != 0 ){
            s32 tmp;
            tmp = self->unk24;
            self->unk24 = self->unk0;
            self->unk0 = tmp;
            if(self->unk28 != 0){
                func_8033A510(self->unk28);
            }
        } else {
            self->unk2C = 0.0f;
        }
    }
}

void func_80335A24(Struct80s *self, enum asset_e anim_id, f32 arg2, f32 arg3){
    f32 sp1C;
    sp1C = func_80335684(self);
    func_80335924(self, anim_id, arg2, arg3);
    func_80335A74(self, sp1C);
}

void func_80335A74(Struct80s *self, f32 arg1){
    self->unk8 = arg1;
}

void func_80335A80(Struct80s *self, f32 arg1){
    self->unkC = arg1;
}

void func_80335A8C(Struct80s *self, s32 arg1){
    self->unk15 = arg1;
}

void func_80335A94(Struct80s *self, f32 arg1, s32 arg2) {
    f32 pad2C;
    Struct7Fs *begin_ptr;
    Struct7Fs *end_ptr;
    Struct7Fs *i_ptr;

    if (arg2 == 0) {
        if (self->unk14 < 10) {
            self->unk14++;
            if (self->unk14 == 0xA) {
                func_80335560(self);
            }
        }
    }
    if (self->unk16 != 0) {
        self->unk1C = self->unk8;
        if ( self->unkC > 0.0f) {
            if (self->unk15 == 1) {
                self->unk8 +=  arg1 /  self->unkC;
                while (self->unk8 >= 1.0f) {
                    self->unk8 -= 1.0f;
                    self->unk18++;
                }
            } else if ((self->unk15 == 2) && (self->unk18 == 0)) {
                self->unk8 += (arg1 /  self->unkC);
                if (self->unk8 >= 1.0f) {
                    self->unk8 = 0.99999f;
                    self->unk18++;
                }
            } else if ((self->unk15 == 3) && (self->unk8 > 0.0f)) {
                self->unk8 -=  (arg1 /  self->unkC);
                if (self->unk8 < 0.0f) {
                    self->unk8 = 0.0f;
                }
            }
        }

        if (self->unk10 != NULL) {
            begin_ptr = vector_getBegin(self->unk10);
            end_ptr = vector_getEnd(self->unk10);
            for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++) {
                if (((self->unk1C <  i_ptr->unk0) || (self->unk8 < self->unk1C)) && ( i_ptr->unk0 <= self->unk8)) {
                    func_803355F8(i_ptr);
                }
            }
        }
        if (self->unk2C > 0.0f) {
            if (self->unk20 < 1.0f) {
                self->unk20 += arg1 / self->unk2C;
                if (self->unk20 >= 1.0f) {
                    self->unk20 = 1.0f;
                }
            } else {
                self->unk2C = 0.0f;
                if (self->unk0 != 0) {
                    func_8033A510(self->unk0);
                }
            }
        }
    }
}
