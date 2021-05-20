#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "rarezip.h"

u8 border[] = {    /* Order of the bit length code lengths */
    16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
/*static*/ u16 cplens[] = {         /* Copy lengths for literal codes 257..285 */
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
        /* note: see note #13 above about the 258 in this list. */

/*static*/ u8 cplext[] = {         /* Extra bits for literal codes 257..285 */
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99}; /* 99==invalid */

/*static*/ u16 cpdist[] = {         /* Copy offsets for distance codes 0..29 */
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};

/*static*/ u8 cpdext[] = {         /* Extra bits for distance codes */
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

u16 mask_bits[] = {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
};

s32 lbits = 9;
s32 dbits = 6;

u8 *inbuf;
u8 *D_80007284;
u32 inptr;
u32 wp;
struct huft *D_80007290; //unk
u32 bb;
u32 bk;
u32 crc1;
u32 crc2;
u32 hufts;

int huft_build(b, n, s, d, e, t, m)
unsigned *b;            /* code lengths in bits (all assumed <= BMAX) */
unsigned n;             /* number of codes (assumed <= N_MAX) */
unsigned s;             /* number of simple-valued codes (0..s-1) */
u16 *d;                 /* list of base values for non-simple codes */
u16 *e;                 /* list of extra bits for non-simple codes */
struct huft **t;        /* result: starting table */
int *m;                 /* maximum lookup bits, returns actual */
/* Given a list of code lengths and a maximum table size, make a set of
   tables to decode that set of codes.  Return zero on success, one if
   the given code set is incomplete (the tables are still built in this
   case), two if the input is invalid (all zero length codes or an
   oversubscribed set of lengths), and three if not enough memory. */
{
  unsigned a;                   /* counter for codes of length k */
  unsigned c[BMAX+1];           /* bit length count table */
  unsigned f;                   /* i repeats in table every f entries */
  int g;                        /* maximum code length */
  int h;                        /* table level */
  register unsigned i;          /* counter, current code */
  register unsigned j;          /* counter */
  register int k;               /* number of bits in current code */
  int l;                        /* bits per table (returned in m) */
  register unsigned *p;         /* pointer into c[], b[], or v[] */
  register struct huft *q;      /* points to current table */
  struct huft r;                /* table entry for structure assignment */
  struct huft *u[BMAX];         /* table stack */
  unsigned v[N_MAX];            /* values in order of bit length */
  register int w;               /* bits before this table == (l * h) */
  unsigned x[BMAX+1];           /* bit offsets, then code stack */
  unsigned *xp;                 /* pointer into x */
  int y;                        /* number of dummy codes added */
  unsigned z;                   /* number of entries in current table */


   /* Generate counts for each bit length */
   bzero(c, sizeof(c));
   p = b;  i = n;
   do {
     c[*p]++;                    /* assume all entries <= BMAX */
     p++;                      /* Can't combine with above line (Solaris bug) */
   } while (--i);
   if (c[0] == n)                /* null input--all zero length codes */
   {
     *t = (struct huft *)NULL;
     *m = 0;
     return 0;
   }


   /* Find minimum and maximum length, bound *m by those */
   l = *m;
   for (j = 1; j <= BMAX; j++)
     if (c[j])
       break;
   k = j;                        /* minimum code length */
   if ((unsigned)l < j)
     l = j;
   for (i = BMAX; i; i--)
     if (c[i])
       break;
   g = i;                        /* maximum code length */
   if ((unsigned)l > i)
     l = i;
   *m = l;


  /* Adjust last length count to fill out codes, if needed */
  for (y = 1 << j; j < i; j++, y <<= 1){
    (y -= c[j]);
  }
  y -= c[i];
  c[i] += y;


  /* Generate starting offsets into the value table for each length */
  x[1] = j = 0;
  p = c + 1;  xp = x + 2;
  while (--i) {                 /* note that i == g from above */
    *xp++ = (j += *p++);
  }


  /* Make a table of values in order of bit lengths */
  p = b;  i = 0;
  do {
    if ((j = *p++) != 0)
      v[x[j]++] = i;
  } while (++i < n);


  /* Generate the Huffman codes and for each, make the table entries */
  x[0] = i = 0;                 /* first Huffman code is zero */
  p = v;                        /* grab values in bit order */
  h = -1;                       /* no tables yet--level -1 */
  w = -l;                       /* bits decoded == (l * h) */
  u[0] = (struct huft *)NULL;   /* just to keep compilers happy */
  q = (struct huft *)NULL;      /* ditto */
  z = 0;                        /* ditto */

  /* go through the bit lengths (k already is bits in shortest code) */
  for (; k <= g; k++)
  {
     a = c[k];
     while (a--)
     {
       /* here i is the Huffman code of length k bits for value *p */
       /* make tables up to required level */
       while (k > w + l)
       {
        h++;
        w += l;                 /* previous table always l bits */

        /* compute minimum size table less than or equal to l bits */
        z = (z = g - w) > (unsigned)l ? l : z;  /* upper limit on table size */
        if ((f = 1 << (j = k - w)) > a + 1)     /* try a k-w bit table */
        {                       /* too few codes for k-w bit table */
          f -= a + 1;           /* deduct codes from patterns left */
          xp = c + k;
          while (++j < z)       /* try smaller tables up to z bits */
          {
            if ((f <<= 1) <= *++xp)
              break;            /* enough codes to use up j bits */
            f -= *xp;           /* else deduct codes from patterns */
          }
        }
        z = 1 << j;             /* table entries for j-bit table */

         /* allocate and link in new table */
        q = D_80007290 + hufts;
        
        hufts += z + 1;         /* track memory usage */
        *t = q + 1;             /* link to list for huft_free() */
        *(t = &(q->v.t)) = (struct huft *)NULL;
        u[h] = ++q;             /* table starts after link */

        /* connect to last table, if there is one */
        if (h)
        {
          x[h] = i;             /* save pattern for backing up */
          r.b = (u8)l;         /* bits to dump before this table */
          r.e = (u8)(16 + j);  /* bits in this table */
          r.v.t = q;            /* pointer to this table */
          j = i >> (w - l);     /* (get around Turbo C bug) */
          u[h-1][j] = r;        /* connect to last table */
        }
       }

      /* set up table entry in r */
      r.b = (u8)(k - w);
      if (p >= v + n)
        r.e = 99;               /* out of values--invalid code */
      else if (*p < s)
      {
        r.e = (u8)(*p < 256 ? 16 : 15);    /* 256 is end-of-block code */
        r.v.n = *p;             /* simple code is just the value */
	      p++;                   /* one compiler does not like *p++ */
      }
      else
      {
        r.e = *((u8 *)e + (*p - s));   /* non-simple--look up in lists */
        r.v.n = d[*p++ - s];
      }

      /* fill code-like entries with r */
      f = 1 << (k - w);
      for (j = i >> w; j < z; j += f)
        q[j] = r;

      /* backwards increment the k-bit code i */
      for (j = 1 << (k - 1); i & j; j >>= 1)
        i ^= j;
      i ^= j;

      /* backup over finished tables */
      while ((i & ((1 << w) - 1)) != x[h])
      {
        h--;                    /* don't need to update q */
        w -= l;
      }
     }
   }


   /* Return true (1) if we were given an incomplete table */
   return y != 0 && g != 1;
}

//^inflate_codes
/* static */ int inflate_codes(struct huft *tl, struct huft *td, s32 bl, s32 bd)
{
  register unsigned e;  /* table entry flag/number of extra bits */
  unsigned n, d;        /* length and index for copy */
  unsigned w;           /* current window position */
  struct huft *t;       /* pointer to table entry */
  unsigned ml, md;      /* masks for bl and bd bits */
  register u32 b;       /* bit buffer */
  register unsigned k;  /* number of bits in bit buffer */
  register u8 tmp;

  /* make local copies of globals */
  b = bb;                       /* initialize bit buffer */
  k = bk;
  w = wp;                       /* initialize window position */

  /* inflate the coded data */
  ml = mask_bits[bl];           /* precompute masks for speed */
  md = mask_bits[bd];

  for (;;)                      /* do until end of block */
  {//L80000D78
    NEEDBITS((unsigned)bl)
    if ((e = (t = tl + ((unsigned)b & ml))->e) > 16)
      do {
        DUMPBITS(t->b)
        e -= 16;
        NEEDBITS(e)
      } while ((e = (t = t->v.t + ((unsigned)b & mask_bits[e]))->e) > 16);
    DUMPBITS(t->b)
    if (e == 16)                /* then it's a literal */
    {

      tmp = (u8)t->v.n;
      D_80007284[w++] = tmp;
      crc1 += tmp;  
      crc2 ^= tmp << (crc1 & 0x17);
    }
    else                        /* it's an EOB or a length */
    {//L80000EAC
       /* exit if end of block */
      if (e == 15)
        break;

       /* get length of block to copy */
      NEEDBITS(e) //L80000EAC - L80000ED8 
      n = t->v.n + ((unsigned)b & mask_bits[e]);
      DUMPBITS(e);

       /* decode distance of block to copy */
      NEEDBITS((unsigned)bd)//L80000F04 - L80000F2C
      if ((e = (t = td + ((unsigned)b & md))->e) > 16)
        do {
          DUMPBITS(t->b)
          e -= 16;
          NEEDBITS(e)
        } while ((e = (t = t->v.t + ((unsigned)b & mask_bits[e]))->e) > 16);
      //L80000FC8
      DUMPBITS(t->b)
      NEEDBITS(e) //L80000FE0 - L80001008
      d = w - t->v.n - ((unsigned)b & mask_bits[e]);
      DUMPBITS(e)
      
       /* do the copy */
      do{
        tmp =  D_80007284[d++];
        D_80007284[w++] = tmp;
        crc1 += tmp;
        crc2 ^= tmp << (crc1 & 0x17);
      }while(--n);
    }
  }
  /* restore the globals from the locals */
  wp = w;                       /* restore global window pointer */
  bb = b;                       /* restore global bit buffer */
  bk = k;
  /* done */
  return 0;
}

/* static */ int inflate_stored(void)
/* "decompress" an inflated type 0 (stored) block. */
{
  unsigned n;           /* number of bytes in block */
  unsigned w;           /* current window position */
  register u32 b;       /* bit buffer */
  register unsigned k;  /* number of bits in bit buffer */

  /* make local copies of globals */
  b = bb;                       /* initialize bit buffer */
  k = bk;
  w = wp;                       /* initialize window position */


  /* go to byte boundary */
  n = k & 7;
  DUMPBITS(n);


   /* get the length and its complement */
   NEEDBITS(16)
   n = ((unsigned)b & 0xffff);
   DUMPBITS(16)
   NEEDBITS(16)
   DUMPBITS(16)


   /* read and output the compressed data */
   while (n--)
   {
     NEEDBITS(8)
     D_80007284[w++] = (u8) b;
     crc1 += b & 0xFF;
     crc2 ^= (b &0xFF) << (crc1 & 0x17);
     DUMPBITS(8)
   }

  /* restore the globals from the locals */
  wp = w;                       /* restore global window pointer */
  bb = b;                       /* restore global bit buffer */
  bk = k;
  return 0;
}

/* static */ int inflate_fixed(void)
/* decompress an inflated type 1 (fixed Huffman codes) block.  We should
   either replace this with a custom decoder, or at least precompute the
   Huffman tables. */
{
  int i;                /* temporary variable */
  struct huft *tl;      /* literal/length code table */
  struct huft *td;      /* distance code table */
  int bl;               /* lookup bits for tl */
  int bd;               /* lookup bits for td */
  unsigned l[288];      /* length list for huft_build */


  /* set up literal table */
  for (i = 0; i < 144; i++)
    l[i] = 8;
  for (; i < 256; i++)
    l[i] = 9;
  for (; i < 280; i++)
    l[i] = 7;
  for (; i < 288; i++)          /* make a complete, but wrong code set */
    l[i] = 8;
  bl = 7;
  huft_build(l, 288, 257, cplens, cplext, &tl, &bl);

   /* set up distance table */
   for (i = 0; i < 30; i++)      /* make an incomplete code set */
     l[i] = 5;
   bd = 5;
   huft_build(l, 30, 0, cpdist, cpdext, &td, &bd);

   /* decompress until an end-of-block code */
    inflate_codes(tl, td, bl, bd);

  return 0;
}

/* static */ int inflate_dynamic(void)/* decompress an inflated type 2 (dynamic Huffman codes) block. */
{
  int i;                /* temporary variables */
  unsigned j;
  unsigned l;           /* last length */
  unsigned m;           /* mask for bit lengths table */
  unsigned n;           /* number of lengths to get */
  struct huft *tl;      /* literal/length code table */
  struct huft *td;      /* distance code table */
  int bl;               /* lookup bits for tl */
  int bd;               /* lookup bits for td */
  unsigned nb;          /* number of bit length codes */
  unsigned nl;          /* number of literal/length codes */
  unsigned nd;          /* number of distance codes */

  register unsigned k;  /* number of bits in bit buffer */

  register u32 b;       /* bit buffer */

  unsigned ll[286+30];  /* literal/length and distance code lengths */

  /* make local bit buffer */
  b = bb;
  k = bk;


   /* read in table lengths */
   NEEDBITS(5)
   nl = 257 + ((unsigned)b & 0x1f);      /* number of literal/length codes */
   DUMPBITS(5)
   NEEDBITS(5)
   nd = 1 + ((unsigned)b & 0x1f);        /* number of distance codes */
   DUMPBITS(5)
   NEEDBITS(4)
   nb = 4 + ((unsigned)b & 0xf);         /* number of bit length codes */
   DUMPBITS(4)

   /* read in bit-length-code lengths */
   for (j = 0; j < nb; j++)
   {
     NEEDBITS(3)
     ll[border[j]] = (unsigned)b & 7;
     DUMPBITS(3)
   }
   for (; j < 19; j++)
     ll[border[j]] = 0;


    /* build decoding table for trees--single level, 7 bit lookup */
    bl = 7;
    huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);


   /* read in literal and distance code lengths */
   n = nl + nd;
   m = mask_bits[bl];
   i = l = 0;
   while ((unsigned)i < n)
   {
      NEEDBITS((unsigned)bl)
     j = (td = tl + ((unsigned)b & m))->b;
     DUMPBITS(j)
     j = td->v.n;
     if (j < 16)                 /* length of code in bits (0..15) */
       ll[i++] = l = j;          /* save last length in l */
     else if (j == 16)           /* repeat last length 3 to 6 times */
     {
       NEEDBITS(2)
       j = 3 + ((unsigned)b & 3);
       DUMPBITS(2)
       while (j--)
         ll[i++] = l;
     }
     else if (j == 17)           /* 3 to 10 zero length codes */
     {
       NEEDBITS(3)
       j = 3 + ((unsigned)b & 7);
       DUMPBITS(3)
       while (j--)
         ll[i++] = 0;
       l = 0;
     }
     else                        /* j == 18: 11 to 138 zero length codes */
     {
       NEEDBITS(7)
       j = 11 + ((unsigned)b & 0x7f);
       DUMPBITS(7)
       while (j--)
         ll[i++] = 0;
       l = 0;
     }
    }

   /* restore the global bit buffer */
   bb = b;
   bk = k;

   /* build the decoding tables for literal/length and distance codes */
   bl = lbits;
   huft_build(ll, nl, 257, cplens, cplext, &tl, &bl);
   bd = dbits;
   huft_build(ll + nl, nd, 0, cpdist, cpdext, &td, &bd);

   /* decompress until an end-of-block code */
   inflate_codes(tl, td, bl, bd);

  return 0;
}

/* static */ int inflate_block(int *e)
/* decompress an inflated block */
{
  u32 t;           /* block type */
  register u32 b;       /* bit buffer */
  register unsigned k;  /* number of bits in bit buffer */


  /* make local bit buffer */
  b = bb;
  k = bk;


  /* read in last block bit */
   NEEDBITS(1)
   *e = (int)b & 1;
   DUMPBITS(1)


  /* read in block type */
   NEEDBITS(2)
   t = (unsigned)b & 3;
   DUMPBITS(2)


  /* restore the global bit buffer */
   bb = b;
   bk = k;


  /* inflate that block type */
   if (t == 2)
     return inflate_dynamic();
   if (t == 0)
     return inflate_stored();
   if (t == 1)
     return inflate_fixed();


  /* bad block type */
  return 2;
}

/* decompress an inflated entry */
int bkboot_inflate(void) //int inflate()
{
  int e;                /* last block flag */
  int r;                /* result code */
  unsigned h;           /* maximum struct huft's malloc'ed */

  /* initialize window, bit buffer */
  wp = 0;
  bk = 0;
  bb = 0;

  crc1 = 0;
  crc2 = -1;

   /* decompress until the last block */
   h = 0;
   do {
     hufts = 0;
     if ((r = inflate_block(&e)) != 0)
       return r;
     if (hufts > h)
       h = hufts;
   } while (!e);

  /* Undo too much lookahead. The next read will be byte aligned so we
   * can discard unused bits in the last meaningful byte.
   */
   while (bk >= 8) {
     bk -= 8;
     inptr--;
   }

  /* return success */
    #ifdef DEBUG
    fprintf(stderr, "<%u> ", h);
    #endif /* DEBUG */
   return 0;
}
