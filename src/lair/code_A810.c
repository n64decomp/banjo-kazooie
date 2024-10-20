#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern func_80391EA8(ActorMarker *, ActorMarker *, f32 [3], f32, f32, s32);

typedef struct {
    f32 unk0[4][3];
}ActorLocal_lair_A810;


void func_80390E28(Actor *this);

/* .data */
ActorInfo D_80394A80 = { 0x1EC, 0x377, 0x0, 0x0, NULL, func_80390E28, actor_update_func_80326224, func_80325340, 3000, 0, 0.0f, 0};

/* .bss */
f32 D_80395370[0x14][3];
s32 D_80395460;

/* .code */
void func_80390C00(ActorMarker *marker)
{
    Actor *actor;
    Actor *newActor;
    s32    pad;

    actor    = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    newActor = spawn_child_actor(0x3BB, &actor);

    func_80391EA8(
        newActor->marker, actor->marker, actor->unk1C,
        randf2(1400, 1800),
        randf2(0.2f, 0.6f),
        randf() < 0.5 ? 1 : 0
    );
}

void func_80390CB4(ActorMarker *marker)
{
    Actor *actor;
    Actor *newActor;
    s32    pad;

    actor    = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    newActor = spawn_child_actor(0x3BB, &actor);

    func_80391EA8(
        newActor->marker, actor->marker, actor->unk1C,
        randf2(1200, 1400),
        randf2(0.8f, 1),
        -1
    );
}

void func_80390D3C(Actor *this, s32 val)
{
    ActorLocal_lair_A810 *local;

    local = (ActorLocal_lair_A810 *)&this->local;
    subaddie_set_state(this, val);

    switch (val)
    {
        case 2:
        {
            if (this->unk10_12 != 0)
            {
                s32 rand = randi2(0, this->unk10_12);
                this->unk1C[0] = local->unk0[rand][0];
                this->unk1C[1] = local->unk0[rand][1];
                this->unk1C[2] = local->unk0[rand][2];
            }
            else
            {
                this->unk1C[0] = this->position_x;
                this->unk1C[1] = this->position_y;
                this->unk1C[2] = this->position_z;
            }

            __spawnQueue_add_1((GenFunction_1)func_80390C00, reinterpret_cast(s32, this->marker));

            break;
        }
        case 1:
        {
            this->unk1C[0] = this->position_x;
            this->unk1C[1] = this->position_y;
            this->unk1C[2] = this->position_z;

            __spawnQueue_add_1((GenFunction_1)func_80390CB4, reinterpret_cast(s32, this->marker));

            break;
        }
        default:
            break;
    }
}

void func_80390E28(Actor *this) {
    ActorLocal_lair_A810 *local;
    bool sp38;
    s32 i;
    f32 temp_f0;

    local = (ActorLocal_lair_A810 *)&this->local;
    sp38 = mapSpecificFlags_getN(0, 2);
    if (!this->initialized) {
        if (D_80395460 == 0) {
            D_80395460 = func_8030508C(0x377, D_80395370[0], 0x14);
        }
        this->unk10_12 = 0;
        for(i = 0; (i < D_80395460) && (this->unk10_12 < 4); i++){
            temp_f0 = ml_vec3f_distance(this->position, D_80395370[i]);
            if ((temp_f0 > 400.0f) && (temp_f0 < 1200.0f)) {
                local->unk0[this->unk10_12][0] = D_80395370[i][0];
                local->unk0[this->unk10_12][1] = D_80395370[i][1];
                local->unk0[this->unk10_12][2] = D_80395370[i][2];
                this->unk10_12++;
            }
        }
        this->initialized = TRUE;
    }
    if (!this->volatile_initialized) {
        if (sp38 != 0) {
            mapSpecificFlags_setN(0, 0, 2);
        }
        this->volatile_initialized = TRUE;
        return;
    }

    switch (this->state) {
        case 0:
            if( gcquiz_isNotInInitialState() == FALSE && (sp38 < 2) && (randf() < 0.1) && !mapSpecificFlags_get(0xA) && !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) {
                sp38++;
                mapSpecificFlags_setN(0, sp38, 2);
                func_80390D3C(this, (randf() < 0.5) ? 2 :1);
            }
            break;
        case 1:
        case 2:
            if (this->unk38_0) {
                func_80390D3C(this, 0);
                this->unk38_0 = FALSE;
            }
            break;
    }
}
