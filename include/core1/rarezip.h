#ifndef RAREZIP_H
#define RAREZIP_H
#include <ultra64.h>


extern u8  D_80275670[]; 
//border[]= {    /* Order of the bit length code lengths */
    //16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
extern u16 D_80275684[]; 
// static ush cplens[] = {         /* Copy lengths for literal codes 257..285 */
//         3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
//         35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
//         /* note: see note #13 above about the 258 in this list. */

extern u16 D_802756C4[];
// static ush cplext[] = {         /* Extra bits for literal codes 257..285 */
//         0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
//         3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99}; /* 99==invalid */

extern u16 D_802756E4[];
// static ush cpdist[] = {         /* Copy offsets for distance codes 0..29 */
//         1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
//         257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
//         8193, 12289, 16385, 24577};

extern u16 D_80275720[];
// static ush cpdext[] = {         /* Extra bits for distance codes */
//         0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
//         7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
//         12, 12, 13, 13};

extern u16 D_80275740[];
/*ush mask_bits[] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};*/

extern s32 D_80275764; //lbits
extern s32 D_80275768; //dbits

extern struct huft *D_8027BF00;

extern u8 *D_8027BF10; //inbuf
extern u8 *D_8027BF14; //slide
extern u32 D_8027BF18; //inptr
extern u32 D_8027BF1C; //wp
extern struct huft *D_8027BF20; //unk
extern u32 D_8027BF24; //bb
extern u32 D_8027BF28; //bk
extern u32 D_8027BF2C; //crc1
extern u32 D_8027BF30; //crc2
extern u32 D_8027BF34; //hufts


#ifndef WSIZE
#  define WSIZE 0x8000     /* window size--must be a power of two, and */
#endif                     /*  at least 32K for zip's deflate method */

//#define get_byte()  (D_8027BF18 < insize ? inbuf[D_8027BF18++] : fill_inbuf(0))
#define get_byte()  (D_8027BF10[D_8027BF18++])

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
