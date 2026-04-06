#ifndef BANJO_KAZOOIE_BOOT_RAREZIP_H
#define BANJO_KAZOOIE_BOOT_RAREZIP_H

#include <ultra64.h>

struct huft_s {
    u8 e;                   /* number of extra bits or operation */
    u8 b;                   /* number of bits in this code or subcode */
    union {
        u16 n;              /* literal, length base, or distance base */
        struct huft_s *t;   /* pointer to next level of table */
    } v;
};

extern u8 *inflate_inbuf;
extern u8 *inflate_slide;
extern u32 inflate_inptr;
extern u32 inflate_wp;
extern struct huft_s *inflate_huft;
extern u32 inflate_crc1;
extern u32 inflate_crc2;

u32 rarezip_get_uncompressed_size(u8 *file);
void rarezip_init(void);
u32 rarezip_uncompress_file(u8 *in, u8 *out);
void rarezip_uncompress_file_and_update_pointers(u8 **in, u8 **out);
s32 inflate(void);

#endif
