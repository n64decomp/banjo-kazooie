#ifndef __MEM_H__
#define __MEM_H__

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
