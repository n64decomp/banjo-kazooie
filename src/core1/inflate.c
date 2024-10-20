#include <ultra64.h>
#include "core1/core1.h"

/* static */ int huft_build(b, n, s, d, e, t, m)
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
        q = D_8027BF20 + D_8027BF34;
        
        D_8027BF34 += z + 1;         /* track memory usage */
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
  b = D_8027BF24;                       /* initialize bit buffer */
  k = D_8027BF28;
  w = D_8027BF1C;                       /* initialize window position */

  /* inflate the coded data */
  ml = D_80275740[bl];           /* precompute masks for speed */
  md = D_80275740[bd];

  for (;;)                      /* do until end of block */
  {//L80000D78
    NEEDBITS((unsigned)bl)
    if ((e = (t = tl + ((unsigned)b & ml))->e) > 16)
      do {
        DUMPBITS(t->b)
        e -= 16;
        NEEDBITS(e)
      } while ((e = (t = t->v.t + ((unsigned)b & D_80275740[e]))->e) > 16);
    DUMPBITS(t->b)
    if (e == 16)                /* then it's a literal */
    {

      tmp = (u8)t->v.n;
      D_8027BF14[w++] = tmp;
      D_8027BF2C += tmp;  
      D_8027BF30 ^= tmp << (D_8027BF2C & 0x17);
    }
    else                        /* it's an EOB or a length */
    {//L80000EAC
       /* exit if end of block */
      if (e == 15)
        break;

       /* get length of block to copy */
      NEEDBITS(e) //L80000EAC - L80000ED8 
      n = t->v.n + ((unsigned)b & D_80275740[e]);
      DUMPBITS(e);

       /* decode distance of block to copy */
      NEEDBITS((unsigned)bd)//L80000F04 - L80000F2C
      if ((e = (t = td + ((unsigned)b & md))->e) > 16)
        do {
          DUMPBITS(t->b)
          e -= 16;
          NEEDBITS(e)
        } while ((e = (t = t->v.t + ((unsigned)b & D_80275740[e]))->e) > 16);
      //L80000FC8
      DUMPBITS(t->b)
      NEEDBITS(e) //L80000FE0 - L80001008
      d = w - t->v.n - ((unsigned)b & D_80275740[e]);
      DUMPBITS(e)
      
       /* do the copy */
      do{
        tmp =  D_8027BF14[d++];
        D_8027BF14[w++] = tmp;
        D_8027BF2C += tmp;
        D_8027BF30 ^= tmp << (D_8027BF2C & 0x17);
      }while(--n);
    }
  }
  /* restore the globals from the locals */
  D_8027BF1C = w;                       /* restore global window pointer */
  D_8027BF24 = b;                       /* restore global bit buffer */
  D_8027BF28 = k;
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
  b = D_8027BF24;                       /* initialize bit buffer */
  k = D_8027BF28;
  w = D_8027BF1C;                       /* initialize window position */


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
     D_8027BF14[w++] = (u8) b;
     D_8027BF2C += b & 0xFF;
     D_8027BF30 ^= (b &0xFF) << (D_8027BF2C & 0x17);
     DUMPBITS(8)
   }

  /* restore the globals from the locals */
  D_8027BF1C = w;                       /* restore global window pointer */
  D_8027BF24 = b;                       /* restore global bit buffer */
  D_8027BF28 = k;
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
  huft_build(l, 288, 257, D_80275684, D_802756C4, &tl, &bl);

   /* set up distance table */
   for (i = 0; i < 30; i++)      /* make an incomplete code set */
     l[i] = 5;
   bd = 5;
   huft_build(l, 30, 0, D_802756E4, D_80275720, &td, &bd);

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
  b = D_8027BF24;
  k = D_8027BF28;


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
     ll[D_80275670[j]] = (unsigned)b & 7;
     DUMPBITS(3)
   }
   for (; j < 19; j++)
     ll[D_80275670[j]] = 0;


    /* build decoding table for trees--single level, 7 bit lookup */
    bl = 7;
    huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);


   /* read in literal and distance code lengths */
   n = nl + nd;
   m = D_80275740[bl];
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
   D_8027BF24 = b;
   D_8027BF28 = k;

   /* build the decoding tables for literal/length and distance codes */
   bl = D_80275764;
   huft_build(ll, nl, 257, D_80275684, D_802756C4, &tl, &bl);
   bd = D_80275768;
   huft_build(ll + nl, nd, 0, D_802756E4, D_80275720, &td, &bd);

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
  b = D_8027BF24;
  k = D_8027BF28;


  /* read in last block bit */
   NEEDBITS(1)
   *e = (int)b & 1;
   DUMPBITS(1)


  /* read in block type */
   NEEDBITS(2)
   t = (unsigned)b & 3;
   DUMPBITS(2)


  /* restore the global bit buffer */
   D_8027BF24 = b;
   D_8027BF28 = k;


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
int inflate(void) //int inflate()
{
  int e;                /* last block flag */
  int r;                /* result code */
  unsigned h;           /* maximum struct huft's malloc'ed */

  /* initialize window, bit buffer */
  D_8027BF1C = 0;
  D_8027BF28 = 0;
  D_8027BF24 = 0;

  D_8027BF2C = 0;
  D_8027BF30 = -1;

   /* decompress until the last block */
   h = 0;
   do {
     D_8027BF34 = 0;
     if ((r = inflate_block(&e)) != 0)
       return r;
     if (D_8027BF34 > h)
       h = D_8027BF34;
   } while (!e);

  /* Undo too much lookahead. The next read will be byte aligned so we
   * can discard unused bits in the last meaningful byte.
   */
   while (D_8027BF28 >= 8) {
     D_8027BF28 -= 8;
     D_8027BF18--;
   }

  /* return success */
    #ifdef DEBUG
    fprintf(stderr, "<%u> ", h);
    #endif /* DEBUG */
   return 0;
}
