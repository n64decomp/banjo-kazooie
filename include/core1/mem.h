#ifndef BANJO_KAZOOIE_CORE1_MEMORY_H
#define BANJO_KAZOOIE_CORE1_MEMORY_H

/**
* copy memory area
*/
void memcpy(void * dst, void *src, int size);

/**
* copy an array of wide_characters
*/
void wmemcpy(void * dst, void *src, int size); 


/**
 * copy memory area
*/
void memmove(u8* dst, u8* src, s32 n);
#endif
