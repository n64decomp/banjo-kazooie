#include <ultra64.h>

s32 stub_13640_get(void);
void stub_13640_init(void);
void stub_13640_set(s32 value);

static s32 sUnused;

s32 stubVar_13640_get(void) {
    return sUnused;
}

void stub_13640_init(void) {
    stub_13640_set(0);
}

void stub_13640_set(s32 arg0) {
    sUnused = arg0;
}
