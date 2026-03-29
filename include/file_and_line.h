#ifndef _FILE_AND_LINE_H_
#define _FILE_AND_LINE_H_
#include <assert.h>
extern void __assert(const char *, const char *, int);


#ifdef NONMATCHING
    #define LINE(line_num) __LINE__
    #define FILE(file_name) __FILE__
    #define matching_assert(EX, F, L) assert(EX)
#else
    #define LINE(line_num) line_num
    #ifdef __ANSI_CPP__
        #define FILE(file_name) # file_name
    #else
        #define FILE(file_name) "file_name"
    #endif

    #ifdef __ANSI_CPP__
        #define matching_assert(EX, F, L)  ((EX)?((void)0):__assert( # EX , # F, L))
    #else
        #define matching_assert(EX, F , L)  ((EX)?((void)0):__assert("EX", "F", L))
    #endif
#endif


#endif
