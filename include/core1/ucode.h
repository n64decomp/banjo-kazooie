#ifndef BANJO_KAZOOIE_CORE1_UCODE_H
#define BANJO_KAZOOIE_CORE1_UCODE_H

void ucode_load(void);
void ucode_stub1(void); // does nothing
void ucode_stub2(void); // performs dummy read on PI
s32 ucode_stub3(void); // returns always 0
void ucode_getPtrAndSize(void **ptr, u32 *size);

#endif
