#ifndef RAREZIP_H
#define RAREZIP_H
#include <ultra64.h>

extern struct huft *D_80007270;

extern u8 *inbuf; //inbuf
extern u8 *D_80007284; //slide
extern u32 inptr; //inptr
extern u32 wp; //wp
extern struct huft *D_80007290; //unk
extern u32 bb; //bb
extern u32 bk; //bk
extern u32 crc1; //crc1
extern u32 crc2; //crc2
extern u32 hufts; //hufts


#ifndef WSIZE
#  define WSIZE 0x8000     /* window size--must be a power of two, and */
#endif                     /*  at least 32K for zip's deflate method */

//#define get_byte()  (inptr < insize ? inbuf[inptr++] : fill_inbuf(0))
#define get_byte()  (inbuf[inptr++])

#ifdef CRYPT
  uch cc;
#  define NEXTBYTE() \
     (decrypt ? (cc = get_byte(), zdecode(cc), cc) : get_byte())
#else
#  define NEXTBYTE()  (u8)get_byte()
#endif
#define NEEDBITS(n) {while(k<(n)){b|=((u32)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

struct huft {
  u8 e;                /* number of extra bits or operation */
  u8 b;                /* number of bits in this code or subcode */
  union {
    u16 n;              /* literal, length base, or distance base */
    struct huft *t;     /* pointer to next level of table */
  } v;
};

/* If BMAX needs to be larger than 16, then h and x[] should be ulg. */
#define BMAX 16         /* maximum bit length of any code (16 for explode) */
#define N_MAX 288       /* maximum number of codes in any set */

int bkboot_inflate(void);

#endif
