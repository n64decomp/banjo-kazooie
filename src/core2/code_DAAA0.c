#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80288C7C(VLA**);
extern void func_80288D84(s32, f32, void (*)(s32,s32), s32, s32);
extern void func_80288DCC(s32 , f32, void (*)(s32, s32,s32), s32, s32, s32);

extern Struct62s D_803731E0[0x20];

/* .code */
void func_80361A30(f32 arg0[3], s32 arg1){
    if(func_8024DD0C(arg0)){
        func_8030E6A4(arg1 >> 16, ((arg1 >> 8) & 0xff)*0.0078125, (arg1 & 0xff)*128.0);
    }
}

void func_80361AB0(s32 marker, s32 arg1){
    Actor *actor;
    
    actor = marker_getActor(reinterpret_cast(ActorMarker *,marker));
    func_80361A30(actor->position, arg1);
}

void func_80361AE0(s32 arg0, s32 arg1, s32 arg2){
    Actor *this;
    f32 sp20[3];
    ActorMarker *marker;
    struct5Bs *tmp;

    marker = reinterpret_cast(ActorMarker *,arg0);
    this = marker_getActor(marker);
    tmp = this->marker->unk44;
    if(tmp){
        func_8034A174(tmp, arg1, sp20);
        if(func_802582EC(sp20)){
            ml_vec3f_copy(sp20, this->position);
        }
    } else {//L80361B44
        ml_vec3f_copy(sp20, this->position);
    }
    func_80361A30(sp20, arg2);
}

void func_80361B68(s32 arg0, s32 arg1){
    ActorMarker *marker;
    f32 arg1_f;
    Actor *actor;

    marker = reinterpret_cast(ActorMarker *,arg0);
    actor = marker_getActor(marker);
    func_803246F0(actor->unk160, arg1);
}

void func_80361B98(s32 arg0, s32 arg1, s32 arg2){
    ActorMarker *marker;
    f32 arg1_f;
    Actor *actor;

    marker = reinterpret_cast(ActorMarker *,arg0);
    actor = marker_getActor(marker);
    func_80324770(actor->unk160, arg1, arg2);
}

void func_80361BD0(s32 arg0, s32 arg1, s32 arg2){
    ActorMarker *marker;
    f32 arg1_f;
    Actor *actor;

    marker = reinterpret_cast(ActorMarker *,arg0);
    actor = marker_getActor(marker);
    arg1_f = reinterpret_cast(f32,arg1);

    actor->unk1C[0] = arg1_f;
    actor->unk1C[1] = 0.0f;
    actor->unk124_11 = arg2;
}

void func_80361C24(s32 arg0, f32 arg1, s32 arg2, f32 arg3){
    func_80288D84(arg0, arg1, func_80361B68, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3));
}

void func_80361C64(s32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4){
    func_80288DCC(arg0, arg1, func_80361B98, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3), arg4);
}

void func_80361CAC(s32 arg0, f32 arg1, s32 arg2, f32 arg3){
    func_80288DCC(arg0, arg1, func_80361BD0, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3), 1);
}

void func_80361CF4(s32 arg0, f32 arg1, s32 arg2, f32 arg3){
    func_80288DCC(arg0, arg1, func_80361BD0, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3), 2);
}

void func_80361D3C(s32 arg0, f32 arg1, s32 arg2, s32 arg3){
    func_80288D84(arg0, arg1, func_80361AB0, reinterpret_cast(s32, arg2), reinterpret_cast(s32, arg3));
}

void func_80361D7C(s32 arg0, f32 arg1, s32 arg2, s32 arg3, u32 arg4){
    func_80288DCC(arg0, arg1, func_80361AE0, reinterpret_cast(s32, arg2), arg3, arg4);
}

void func_80361DC4(Actor *this){
    if(this->unk134){
        func_802890D0(this->unk134);
    }
    this->unk134 = NULL;

    if(this->unk160){
        func_8032477C(this->unk160);
    }
}

void func_80361E10(Actor *this) {
    s32 phi_v0;

    for(phi_v0 = 0; phi_v0 < 0x20; phi_v0++){
        if(D_803731E0[phi_v0].unk0 == this->modelCacheIndex){
            this->unk108 = &D_803731E0[phi_v0];
            this->unk134 = func_802890FC();
            this->unk160 = func_8032479C();
            this->unk10C = 0;
            return;
        }
    }
    this->unk134 = 0;
    this->unk160 = 0;
}


void func_80361E9C(Actor *this){
    if( this->animctrl != NULL
        && this->unk134 != NULL
        && this->unk160 != NULL
    ){
      func_80324700(this->unk160);
    }
}

void func_80361EE0(Actor *this) {
    s32 i;
    s32 sp28;
    Struct62s *sp24;
    Struct63s *sp20;

    if (this->animctrl != NULL && this->unk134 != NULL) {
        sp24 = this->unk108;
        sp28 = animctrl_getIndex(this->animctrl);
        if (sp28 != this->unk10C) {
            this->unk10C = sp28;
            func_80288C7C(this->unk134);
            for(sp20 = sp24->unk4; sp20->unk4 != NULL; sp20++){
                if (sp28 == sp20->unk0) {
                    sp20->unk4(this->unk134, this->marker);
                    break;
                }
            }
        }
        func_8028914C(this->unk134, this->animctrl);
    }
}
