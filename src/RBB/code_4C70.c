#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 unk0;
    f32 unk4[3];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8  pad16[2];
}Struct_RBB_4C70;

typedef struct {
    Struct_RBB_4C70 *unk0;
    f32 unk4[3];
}ActorLocal_RBB_4C70;

Actor *func_8038B230(ActorMarker *marker, Gfx** gdl, Mtx** mptr, s32 arg3);
void func_8038B340(Actor *this);

/* .data */
extern Struct_RBB_4C70 D_80390950[];
/* Struct_RBB_4C70 D_80390950[4] = {
    0000 A560: 01 C2 00 00 C5 68 80 00  44 48 00 00 C3 AF 00 00
    0000 A570: 00 01 01 36 03 FF 00 00  
                                        01 C3 00 00 C5 68 80 00
    0000 A580: 44 48 00 00 00 00 00 00  00 02 01 35 03 FE 00 00

    0000 A590: 01 C4 00 00 C5 68 80 00  44 48 00 00 43 AF 00 00
    0000 A5A0: 00 03 01 34 03 FD 00 00  
                                        00 00 00 00 00 00 00 00
    0000 A5B0: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
}; */

/* ActorInfo D_803909B0 = {
    0000 A5C0: 00 2A 01 C2 04 16 00 00  00 00 00 00 80 38 B3 40
    0000 A5D0: 00 00 00 00 80 38 B2 30  00 00 00 00 00 00 00 00
    0000 A5E0: 00 00 00 00
}; */

/* ActorInfo D_803909D4 = {
                           00 2B 01 C3  04 16 00 00 00 00 00 00
    0000 A5F0: 80 38 B3 40 00 00 00 00  80 38 B2 30 00 00 00 00
    0000 A600: 00 00 00 00 00 00 00 00  
}; */

/* ActorInfo D_803909F8 = {
                                        00 2C 01 C4 04 16 00 00
    0000 A610: 00 00 00 00 80 38 B3 40  00 00 00 00 80 38 B2 30
    0000 A620: 00 00 00 00 00 00 00 00  00 00 00 00 
}; */

extern f32 D_80390A1C[3] = {1.0f, 2.0f, 3.0f};

// 5.0f, 0.05f, 0.1f, 1.5f, 2.5f, 0.0f, 0.5f};
/* D_80390A1C = {
                                                    3F 80 00 00
    0000 A630: 40 00 00 00 40 40 00 00  40 A0 00 00 3D 4C CC CD
    0000 A640: 3D CC CC CD 3F C0 00 00  40 20 00 00 00 00 00 00
    0000 A650: 3F 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
}*/

/* .rodata */
extern f32 D_80390FC0;

/* .code */
Struct_RBB_4C70 *func_8038B060(Actor *this){
    Struct_RBB_4C70 * iPtr;
    for(iPtr = D_80390950; iPtr->unk0 != 0; iPtr++){
        if(iPtr->unk0 == this->modelCacheIndex)
            return iPtr;
    }
    return NULL;
}

void func_8038B0B8(Actor *this, s32 arg1){
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&this->local;
    Actor *other;

    this->state = arg1;

    if(this->state == 2){
        func_80335924(this->unk148, local->unk0->unk12, 0.0f, 0.5f);
        func_80335A8C(this->unk148, 2);
        func_80324C88(D_80390FC0, local->unk0->unk14, 1.0f, 0x7d00);
        other = func_802F0BD0(0xa);
        func_802EF950(other, 0x70e);
        func_802EF9AC(other, 
            0.0f, 100.0f, 0.0f,
            0.0f, 250.0f, 0.0f
        );
        func_802EFA90(other, 0, 7);
        func_802EFB1C(other, 
            -5.0f, -5.0f, 0.0f,
            5.0f, 5.0f, 0.0f
        );
        func_802EFB54(other, &local->unk4);
        func_802EFED4(other, 
            -400.0f, 0.0f, -30.0f,
            -800.0f, 0.0f, 30.0f
        );
        func_802EFB98(other, &D_80390A1C);
        func_802EFFC4(other, 0.5f);
    }
}

Actor *func_8038B230(ActorMarker *marker, Gfx** gdl, Mtx** mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&actor->local;
    f32 sp3C[3];

    if(actor->state == 0)
        return actor;

    if(actor->state == 2){
        func_8033A238(func_803356A0(actor->unk148));
    }

    sp3C[0] = actor->pitch;
    sp3C[1] = actor->yaw;
    sp3C[2] = actor->roll;
    func_8033A2D4(&func_803253A0, actor);
    func_8033A450(func_80329934());
    func_803391A4(gdl, mptr, &actor->position, &sp3C, actor->scale, NULL, func_80330B1C(marker));
    func_8034A174(func_80329934(), 5, &local->unk4);
    local->unk4[0] -= 60.0f;
    return actor;
}

void func_8038B340(Actor * this){
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&this->local;
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->unk16C_4 = 1;
        local->unk0 = func_8038B060(this);
        
        local->unk4[2] = 0.0f;
        local->unk4[1] = 0.0f;
        local->unk4[0] = 0.0f;

        this->position_x = local->unk0->unk4[0];
        this->position_y = local->unk0->unk4[1];
        this->position_z = local->unk0->unk4[2];

        this->yaw = -90.0f;
        this->scale = 0.25f;

        func_8038B0B8(this, 1);
    }//L8038B3E4

    if(this->state == 1){
        if(mapSpecificFlags_get(local->unk0->unk10))
            func_8038B0B8(this, 2);
    }

    if(this->state == 2){
        if( func_80335794(this->unk148) > 0 )
            func_8038B0B8(this, 1);
    }
}