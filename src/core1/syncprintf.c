#include <stdarg.h>
#include <rmon.h>
#include <os.h>

void osSyncPrintf(const char *fmt, ...)
{
    int ans;
    va_list ap;
    // these functions intentionally left blank.  ifdeffed out in rom release
}
void rmonPrintf(const char *fmt, ...)
{
    int ans;
    va_list ap;
}
