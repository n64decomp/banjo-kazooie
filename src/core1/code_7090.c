#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

s16 *D_802758E0 = NULL;

void core1_7090_alloc(void) {
    int i;

    if (D_802758E0)
        return;

    D_802758E0 = (s16 *) malloc(10 * sizeof(s16));

    for (i = 0; i < 10; i++) {
        D_802758E0[i] = 0;
    }
}

void core1_7090_release(void) {
    int i;

    if (!D_802758E0)
        return;

    for (i = 0; i < 10; i++) {
        if (D_802758E0[i])
            func_8030E394(D_802758E0[i]);
    }

    free(D_802758E0);
    D_802758E0 = NULL;
}

void core1_7090_initSfxSource(s32 idx, s32 lookup_idx, s32 sample_rate, f32 volume) {
    u8 sfx_source_index;

    if (func_8030ED70(lookup_getSfxId(lookup_idx))) {
        sfx_source_index = sfxsource_createSfxsourceAndReturnIndex();

        if (sfx_source_index) {
            sfxsource_setSfxId(sfx_source_index, lookup_getSfxId(lookup_idx));
            sfxsource_playSfxAtVolume(sfx_source_index, volume);
            sfxsource_setSampleRate(sfx_source_index, sample_rate);
            func_8030E2C4(sfx_source_index);
            core1_7090_freeSfxSource(idx);
            D_802758E0[idx] = sfx_source_index;
        }
    }
    else {
        func_8030E6A4(lookup_getSfxId(lookup_idx), volume, sample_rate);
    }
}

void core1_7090_freeSfxSource(int idx) {
    if (D_802758E0[idx]) {
        sfxsource_freeSfxsourceByIndex(D_802758E0[idx]);
    }

    D_802758E0[idx] = 0;
}
