#include "os.h"
#include "PRinternal/osint.h"
#include "osint_debug.h"

void __assertBreak(void);

#ifdef BKDIFFS
void __assert(const char* exp, const char* filename) { // For some reason, the third parameter "line" is missing in the implementation, but it's in the declaration
}
#else
void __assert(const char* exp, const char* filename, int line) {
#ifndef _FINALROM
    osSyncPrintf("\nASSERTION FAULT: %s, %d: \"%s\"\n", filename, line, exp);
    __assertBreak; // Doesn't actually do anything, but is needed for matching
#endif
}
#endif
