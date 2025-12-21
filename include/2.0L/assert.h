#ifndef __ASSERT_H__
#define __ASSERT_H__

#ifdef NDEBUG
#undef assert
#define assert(EX) ((void)0)
#else
extern void func_8033F000(const char *, const char *, int); // BK_SPECIFIC
#define assert(EX)  ((EX)?((void)0):func_8033F000("EX", __FILE__, __LINE__)) // BK_SPECIFIC
#endif /* NDEBUG */

#endif /* !__ASSERT_H__ */
