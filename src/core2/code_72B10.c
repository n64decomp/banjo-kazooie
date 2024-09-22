#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 sfx_randf2(f32, f32);

/* .bss */
vector(struct4Es) *D_803810A0;

/* public */
void func_802F9D38(s32 arg0);
void func_802FA028(s32 arg0, s32 arg1);
void func_802FA0B0(s32 arg0, s32 arg1);

/*.code */
void func_802F9AA0(struct4Es *this, s32 arg1){
    this->unk3E = arg1;
}

s32 func_802F9AA8(enum sfx_e arg0){
    s32 indx;
    struct4Es *iPtr;
    struct4Es *endPtr;
    struct4Es *startPtr;
    

    endPtr = vector_getEnd(D_803810A0);
    startPtr = vector_getBegin(D_803810A0);

    for(iPtr = startPtr + 1; iPtr < endPtr && iPtr->unk0; iPtr++);
    if(iPtr == endPtr)
        iPtr = vector_pushBackNew(&D_803810A0);

    iPtr->unk0 = sfxsource_createSfxsourceAndReturnIndex();
    sfxsource_setSfxId(iPtr->unk0, arg0);
    func_8030DD14(iPtr->unk0, 3);
    sfxsource_setSampleRate(iPtr->unk0, 0x64);
    func_8030E2C4(iPtr->unk0);
    startPtr = vector_getBegin(D_803810A0);
    indx = iPtr - startPtr;
    iPtr->unk3C = 0;
    iPtr->unk3E = 0;
    iPtr->unk3F = 0;
    iPtr->unk4 = 0.0f;
    iPtr->unk8 = 0.0f;
    func_802F9DB8(indx, 1.0f, 1.0f, 0.0f);
    func_802F9F80(indx, 1.0f, 3.0f, 1.0f);
    func_802FA028(indx, 0);
    func_802FA060(indx, 30000, 30000, 0.0f);
    func_802FA0B0(indx, 0);
    return indx;
}

int func_802F9C0C(s32 arg0){
    struct4Es *ptr;
    ptr = vector_at(D_803810A0, arg0);
    return (ptr->unk0)? 1 : 0;
}

void func_802F9C48(void){
    struct4Es *iPtr;
    struct4Es *startPtr;
    struct4Es *endPtr;

    startPtr = vector_getBegin(D_803810A0);
    endPtr = vector_getEnd(D_803810A0);
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk0)
            func_802F9D38(iPtr - startPtr);
    }
    vector_free(D_803810A0);
}

void func_802F9CD8(void){
    int i;
    struct4Es *iPtr;
    D_803810A0 = (vector(struct4Es) *) vector_new(sizeof(struct4Es), 0x10);
    for(i = 0; i< 0x10; i++){
        iPtr = vector_pushBackNew(&D_803810A0);
        iPtr->unk0 = 0;
    }
}

void func_802F9D38(s32 arg0){
    struct4Es *ptr;
    ptr = vector_at(D_803810A0, arg0);
    if(ptr->unk0){
        func_8030E394(ptr->unk0);
        func_8030DA44(ptr->unk0);
        ptr->unk0 = 0;
    }
}

s32 func_802F9D8C(s32 arg0){
    struct4Es *ptr;
    ptr = vector_at(D_803810A0, arg0);
    return ptr->unk0;
}

void func_802F9DB8(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    struct4Es *ptr;
    ptr = vector_at(D_803810A0, arg0);
    func_802F9AA0(ptr, 1);
    ptr->unk18 = arg3;
    ptr->unk20 = arg1;
    ptr->unk1C = arg2;
    if(ptr->unk0){
        sfxsource_playSfxAtVolume(ptr->unk0, (arg1 + arg2)/2);
    }
}

void func_802F9E44(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4){
    struct4Es *ptr;
    ptr = vector_at(D_803810A0, arg0);
    func_802F9AA0(ptr, 2);
    ptr->unk24 = arg1;
    ptr->unk28 = arg2;
    ptr->unk2C = arg3;
    ptr->unk30 = arg4;
    if(ptr->unk0){
        sfxsource_playSfxAtVolume(ptr->unk0, arg3);
    }
}

void func_802F9EC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    struct4Es *iPtr;

    iPtr = vector_at(D_803810A0, arg0);
    if(iPtr->unk0){
        sfxsource_set_fade_distances(iPtr->unk0, (f32)arg2, (f32)arg3);
        sfxsource_set_position(iPtr->unk0, arg1);
    }
}

void func_802F9F48(s32 arg0, s32 arg1){
    struct4Es *iPtr;
    iPtr = vector_at(D_803810A0, arg0);
    iPtr->unk3F = arg1;
}

void func_802F9F80(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    struct4Es *iPtr;
    iPtr = vector_at(D_803810A0, arg0);
    iPtr->unkC = arg1;
    iPtr->unk10 = arg3;
    iPtr->unk14 = arg2;
}

void func_802F9FD0(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    struct4Es *iPtr;
    iPtr = vector_at(D_803810A0, arg0);
    iPtr->unkC = arg1;
    iPtr->unk10 = arg3;
    iPtr->unk14 = arg2;
    iPtr->unk4 = 0.0f;
}

void func_802FA028(s32 arg0, s32 arg1){
    struct4Es *iPtr;
    iPtr = vector_at(D_803810A0, arg0);
    iPtr->unk3D = arg1;
}

void func_802FA060(s32 arg0, s32 arg1, s32 arg2, f32 arg3){
    struct4Es *iPtr;
    iPtr = vector_at(D_803810A0, arg0);
    iPtr->unk3A = arg1;
    iPtr->unk38 = arg2;
    iPtr->unk34 = arg3;
}

void func_802FA0B0(s32 arg0, s32 arg1){
    struct4Es *iPtr;
    iPtr = vector_at(D_803810A0, arg0);
    if(iPtr->unk0){
        func_8030DD90(iPtr->unk0, arg1);
    }
}

void func_802FA0F8(void){
    f32 tick;
    struct4Es *startPtr;
    struct4Es *endPtr;
    f32 f20;
    struct4Es *iPtr;

    tick = time_getDelta();
    startPtr = vector_getBegin(D_803810A0);
    endPtr = vector_getEnd(D_803810A0);

    for(iPtr = startPtr; iPtr < endPtr; iPtr++){//L802FA178
        if(iPtr->unk0){
            iPtr->unk4 += tick;
            if( iPtr->unkC + iPtr->unk14 + iPtr->unk10 <= iPtr->unk4){
                func_802F9D38(iPtr - startPtr);
            }
            else{
                if(iPtr->unk3E == 1){
                    f20 = func_8030E200(iPtr->unk0);
                    f20 += sfx_randf2(-1.0f, 1.0f)*iPtr->unk18;
                    f20 = MIN(iPtr->unk1C, f20);
                    f20 = MAX(iPtr->unk20, f20);
                }
                else if(iPtr->unk3E == 2){//L802FA238
                    f20 = ml_map_f(iPtr->unk4, iPtr->unk24, iPtr->unk28, iPtr->unk2C, iPtr->unk30);
                }
                sfxsource_playSfxAtVolume(iPtr->unk0, f20);
                
                if(iPtr->unk3C){
                    if(0.0f == iPtr->unk10){
                        iPtr->unk8 = 0.0f;
                    }
                    else{
                        iPtr->unk8 -=  (f32)iPtr->unk38/iPtr->unk10 * tick;
                    }
                    if(iPtr->unk8 <= 0.0f){
                        func_802F9D38(iPtr - startPtr);
                        continue;
                    }
                }
                else if(iPtr->unk4 < iPtr->unkC){//L802FA2E4
                    iPtr->unk8 = ((iPtr->unk4/iPtr->unkC)*((f32)( iPtr->unk3A + iPtr->unk38 )))/2;
                }
                else if(iPtr->unk4 <= iPtr->unkC + iPtr->unk14){
                        if( iPtr->unk8 < iPtr->unk3A
                            || iPtr->unk38 < iPtr->unk8
                        ){
                            iPtr->unk8 = (iPtr->unk3A + iPtr->unk38)/2;
                        }
                        iPtr->unk8 += sfx_randf2(-1.0f, 1.0f) * iPtr->unk34;

                        iPtr->unk8 = MIN(iPtr->unk38, iPtr->unk8);
                        iPtr->unk8 = MAX(iPtr->unk3A, iPtr->unk8);
                }
                else{
                    iPtr->unk8 = (1.0f - ((iPtr->unk4 - iPtr->unkC) - iPtr->unk14)/iPtr->unk10) * (iPtr->unk3A + iPtr->unk38) / 2;
                }
                if(iPtr->unk3F && !func_8030E3FC(iPtr->unk0)){
                    func_8030E2C4(iPtr->unk0);
                }
                sfxsource_setSampleRate(iPtr->unk0, (s32)iPtr->unk8);
            }
        }//L802FA4A0
    }//L802FA4B4  
}

void func_802FA4E0(void){
    D_803810A0 = vector_defrag(D_803810A0);
}

void func_802FA508(void){
    struct4Es *startPtr;
    struct4Es *endPtr;
    struct4Es *iPtr;

    startPtr = vector_getBegin(D_803810A0);
    endPtr = vector_getEnd(D_803810A0);
    for(iPtr = startPtr; iPtr < endPtr; iPtr++){
        if(iPtr->unk0){
            if(iPtr->unk3D == 0){
                func_802F9D38(iPtr - startPtr);
            }
            else if(--iPtr->unk3D == 0){
                iPtr->unk3C = 1;
                iPtr->unk4 = 0.0f;
            }
        }
    }
}
