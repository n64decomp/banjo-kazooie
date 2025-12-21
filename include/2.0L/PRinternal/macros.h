#ifndef __MACROS_H__
#define __MACROS_H__

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define STUBBED_PRINTF(x) ((void)(x))

#define UNUSED __attribute__((unused))

#ifndef __GNUC__
#define __attribute__(x)
#endif

#define ALIGN8(val) (((val) + 7) & ~7)

#define STACK(stack, size) \
    u64 stack[ALIGN8(size) / sizeof(u64)]

#define STACK_START(stack) \
    ((u8*)(stack) + sizeof(stack))

#endif
